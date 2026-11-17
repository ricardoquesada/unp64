#!/usr/bin/env python3
"""Verify UNP64 mirror portability patches and C build-graph integrity.

This repository mirrors iAN CooG's upstream UNP64 sources (`src/**` and
`unp64.txt`) while carrying three surgical build-portability fixes and
cross-platform CI workflows:

1. `src/Makefile` pins `-std=gnu17` in every `CFLAGS` block because GCC 15+
   defaults to `-std=gnu23`, where `int bool` in `src/6502emu.c` is a syntax
   error (a regression Apple Clang on macOS cannot catch locally).
2. `src/Makefile` declares `$(SRC_OBJS): | directories` and uses `mkdir -p`
   so parallel builds (`make -j`) never race on output directory creation.
3. `src/log.c` guards `#define vsnprintf _vsnprintf` behind
   `#if defined(_MSC_VER) && _MSC_VER < 1900` instead of `#ifdef WIN32`, which
   otherwise breaks MSYS2/MinGW64 builds on Windows CI.

In addition, upstream scanner drops can add or remove files under
`src/scanners/*.c`. This checker verifies three-way synchronization across:
- Tracked Git C translation units (`src/*.c`, `src/scanners/*.c`)
- `SRC_OBJS` and explicit object rules in `src/Makefile`
- Visual Studio project entries in `src/unp64.VCproj`
"""

from __future__ import annotations

from collections import Counter
from pathlib import Path, PurePosixPath, PureWindowsPath
import re
import subprocess
import sys
import xml.etree.ElementTree as ET

CORE_UNIT_DIRS = frozenset({PurePosixPath("src"), PurePosixPath("src/scanners")})
CFLAGS_RE = re.compile(r"^[ \t]*CFLAGS[ \t]*=(.*)$", re.MULTILINE)
STD_GNU17_RE = re.compile(r"(?:^|\s)-std=gnu17(?:\s|$)")
ORDER_ONLY_DIRS_RE = re.compile(
    r"^\$\(SRC_OBJS\)[ \t]*:[ \t]*\|[ \t]*directories\b", re.MULTILINE
)
DIRECTORIES_RECIPE_RE = re.compile(
    r"^directories:[ \t]*\n((?:\t[^\n]*(?:\n|$))+)", re.MULTILINE
)
MSC_VSNPRINTF_GUARD_RE = re.compile(
    r"^[ \t]*#[ \t]*if[ \t]+defined\(_MSC_VER\)[ \t]*&&[ \t]*_MSC_VER[ \t]*<[ \t]*1900\b",
    re.MULTILINE,
)
BARE_WIN32_VSNPRINTF_RE = re.compile(
    r"^[ \t]*#[ \t]*(?:ifdef[ \t]+_?WIN32|if[ \t]+defined\(_?WIN32\))[^\n]*\n"
    r"[ \t]*#[ \t]*define[ \t]+vsnprintf[ \t]+_vsnprintf\b",
    re.MULTILINE,
)
OBJ_ENTRY_RE = re.compile(r"\$\(OBJ_DIR\)/([A-Za-z0-9_]+)\.o")
RULE_TARGET_RE = re.compile(r"^\$\(OBJ_DIR\)/([A-Za-z0-9_]+)\.o:", re.MULTILINE)


def resolve_repo_root() -> Path:
    """Return the repository root directory containing `src/`.

    Example:
        `.../unp64/tools/check_mirror_invariants.py` -> `.../unp64`
    """
    return Path(__file__).resolve().parent.parent


def _find_duplicates(items: list[str]) -> list[str]:
    """Return sorted item names appearing more than once.

    Example:
        `["a", "b", "a"]` -> `["a"]`
    """
    counts = Counter(items)
    return sorted(name for name, count in counts.items() if count > 1)


def _diff_unit_sets(
    source_name: str,
    target_name: str,
    source_stems: set[str],
    target_stems: set[str],
) -> list[str]:
    """Compare two sets of C unit stems and format bidirectional mismatches.

    Example:
        `source_stems={"a", "b"}`, `target_stems={"a"}` ->
        `["missing from <target_name> (present in <source_name>): b"]`
    """
    errors: list[str] = []
    missing = sorted(source_stems - target_stems)
    if missing:
        errors.append(
            f"C units in {source_name} missing from {target_name}: "
            f"{', '.join(missing)}"
        )

    extra = sorted(target_stems - source_stems)
    if extra:
        errors.append(
            f"C units in {target_name} absent from {source_name}: "
            f"{', '.join(extra)}"
        )
    return errors


def check_makefile_portability(makefile_path: Path) -> list[str]:
    """Verify `-std=gnu17` and parallel `directories` rules in `src/Makefile`.

    Example:
        Passing `src/Makefile` with `CFLAGS = -std=gnu17 ...` in both `Debug`
        and `Release`, `$(SRC_OBJS): | directories`, and `mkdir -p` returns `[]`.
    """
    if not makefile_path.is_file():
        return [f"Missing required build file: {makefile_path}"]

    content = makefile_path.read_text(encoding="utf-8")
    errors: list[str] = []

    cflag_matches = list(CFLAGS_RE.finditer(content))
    if len(cflag_matches) < 2:
        errors.append(
            f"src/Makefile: expected at least 2 CFLAGS definitions (Debug and "
            f"Release), found {len(cflag_matches)}."
        )

    for match in cflag_matches:
        rhs = match.group(1).strip()
        if not STD_GNU17_RE.search(rhs):
            line_no = content.count("\n", 0, match.start()) + 1
            errors.append(
                f"src/Makefile:{line_no}: CFLAGS missing `-std=gnu17` "
                f"(required by GCC 15+ because src/6502emu.c uses `int bool`)."
            )

    if not ORDER_ONLY_DIRS_RE.search(content):
        errors.append(
            "src/Makefile: missing `$(SRC_OBJS): | directories` order-only "
            "prerequisite (required for race-free `make -j` clean builds)."
        )

    dir_recipe = DIRECTORIES_RECIPE_RE.search(content)
    if dir_recipe is None:
        errors.append("src/Makefile: missing `directories:` recipe.")
        return errors

    recipe_text = dir_recipe.group(1)
    for var_name in ("OUTPUT_DIR", "OBJ_DIR"):
        if f'mkdir -p "$({var_name})"' not in recipe_text:
            errors.append(
                f'src/Makefile: `directories:` recipe must create "$({var_name})" '
                f"using `mkdir -p` for parallel and POSIX compatibility."
            )

    return errors


def check_log_c_portability(log_c_path: Path) -> list[str]:
    """Verify `src/log.c` guards `vsnprintf` compatibility only for old MSVC.

    Example:
        Returns `[]` when `#if defined(_MSC_VER) && _MSC_VER < 1900` is present
        and no `#ifdef WIN32` precedes `#define vsnprintf _vsnprintf`.
    """
    if not log_c_path.is_file():
        return [f"Missing required source file: {log_c_path}"]

    content = log_c_path.read_text(encoding="utf-8")
    errors: list[str] = []

    if BARE_WIN32_VSNPRINTF_RE.search(content):
        errors.append(
            "src/log.c: `#define vsnprintf _vsnprintf` must not be guarded by "
            "`#ifdef WIN32` (breaks MSYS2/MinGW64 CI)."
        )

    if not MSC_VSNPRINTF_GUARD_RE.search(content):
        errors.append(
            "src/log.c: missing `#if defined(_MSC_VER) && _MSC_VER < 1900` "
            "guard for legacy MSVC `_vsnprintf` fallback."
        )

    return errors


def _run_git_ls_files(repo_root: Path, *extra_args: str) -> list[str]:
    """Run `git ls-files` inside `repo_root` and return non-empty path lines."""
    result = subprocess.run(
        ["git", "-C", str(repo_root), "ls-files", *extra_args, "--", "src/"],
        capture_output=True,
        text=True,
        check=True,
    )
    return [line for line in result.stdout.splitlines() if line]


def collect_git_c_units(repo_root: Path) -> tuple[set[str], list[str]]:
    """Collect tracked C unit stems and untracked C files in `src/` & `src/scanners/`.

    Excludes `src/findsys/` (Windows-only helper tool with its own Makefile).

    Example:
        Returns `({"6502emu", "unp64", "ZX02", ...}, [])` when all C units are
        staged/tracked in Git.
    """
    tracked_paths = _run_git_ls_files(repo_root, "--cached")
    untracked_paths = _run_git_ls_files(repo_root, "--others", "--exclude-standard")

    tracked_stems: set[str] = set()
    for relpath in tracked_paths:
        posix_path = PurePosixPath(relpath)
        if posix_path.suffix == ".c" and posix_path.parent in CORE_UNIT_DIRS:
            tracked_stems.add(posix_path.stem)

    untracked_relpaths = sorted(
        relpath
        for relpath in untracked_paths
        if (posix_path := PurePosixPath(relpath)).suffix == ".c"
        and posix_path.parent in CORE_UNIT_DIRS
    )
    return tracked_stems, untracked_relpaths


def parse_makefile_units(
    makefile_path: Path,
) -> tuple[set[str], set[str], list[str]]:
    """Extract `SRC_OBJS` stems and explicit rule target stems from `src/Makefile`.

    Example:
        Returns `(src_objs_stems, rule_target_stems, [])` when `SRC_OBJS` and
        explicit `$(OBJ_DIR)/*.o:` target rules are well-formed and unique.
    """
    content = makefile_path.read_text(encoding="utf-8")
    errors: list[str] = []

    if "SRC_OBJS =" not in content or "define build_target" not in content:
        return (
            set(),
            set(),
            ["src/Makefile: missing `SRC_OBJS =` or `define build_target` marker."],
        )

    src_objs_block = content.split("SRC_OBJS =", maxsplit=1)[1].split(
        "define build_target", maxsplit=1
    )[0]
    src_objs_list = OBJ_ENTRY_RE.findall(src_objs_block)
    rule_targets_list = RULE_TARGET_RE.findall(content)

    dup_objs = _find_duplicates(src_objs_list)
    if dup_objs:
        errors.append(
            f"src/Makefile: duplicate entries in SRC_OBJS: {', '.join(dup_objs)}"
        )

    dup_rules = _find_duplicates(rule_targets_list)
    if dup_rules:
        errors.append(
            f"src/Makefile: duplicate explicit target rules: {', '.join(dup_rules)}"
        )

    return set(src_objs_list), set(rule_targets_list), errors


def parse_vcproj_units(vcproj_path: Path) -> set[str]:
    """Extract C source unit stems listed in `src/unp64.VCproj`.

    Example:
        `<File RelativePath=".\\scanners\\ZX02.c" />` yields `"ZX02"`.
    """
    root = ET.parse(vcproj_path).getroot()
    stems: set[str] = set()
    for element in root.iter("File"):
        rel_path = element.attrib.get("RelativePath")
        if not rel_path:
            continue
        win_path = PureWindowsPath(rel_path)
        if win_path.suffix.lower() == ".c":
            stems.add(win_path.stem)
    return stems


def check_build_graph_sync(repo_root: Path) -> list[str]:
    """Verify Git tracked C units, `src/Makefile`, and `src/unp64.VCproj` match.

    Catches forgotten `git add src/scanners/<New>.c` or stale `SRC_OBJS` /
    `VCproj` entries after upstream CSDb release imports.
    """
    makefile_path = repo_root / "src" / "Makefile"
    vcproj_path = repo_root / "src" / "unp64.VCproj"
    if not makefile_path.is_file() or not vcproj_path.is_file():
        return [
            f"Missing build manifest(s): expected {makefile_path} and {vcproj_path}"
        ]

    errors: list[str] = []

    try:
        tracked_stems, untracked_relpaths = collect_git_c_units(repo_root)
    except subprocess.CalledProcessError as exc:
        return [f"Failed to query Git index (`git ls-files`): {exc.stderr.strip()}"]

    if untracked_relpaths:
        errors.append(
            "Untracked C files in src/ (stage with `git add` before committing): "
            f"{', '.join(untracked_relpaths)}"
        )

    src_objs_stems, rule_target_stems, parse_errors = parse_makefile_units(
        makefile_path
    )
    errors.extend(parse_errors)

    try:
        vcproj_stems = parse_vcproj_units(vcproj_path)
    except ET.ParseError as exc:
        errors.append(f"src/unp64.VCproj: invalid XML ({exc})")
        return errors

    errors.extend(
        _diff_unit_sets(
            "Git index (src/*.c, src/scanners/*.c)",
            "src/Makefile SRC_OBJS",
            tracked_stems,
            src_objs_stems,
        )
    )
    errors.extend(
        _diff_unit_sets(
            "src/Makefile SRC_OBJS",
            "src/Makefile target rules",
            src_objs_stems,
            rule_target_stems,
        )
    )
    errors.extend(
        _diff_unit_sets(
            "Git index (src/*.c, src/scanners/*.c)",
            "src/unp64.VCproj",
            tracked_stems,
            vcproj_stems,
        )
    )
    return errors


def main() -> int:
    """Run all mirror invariant checks and return POSIX exit status."""
    repo_root = resolve_repo_root()
    errors: list[str] = []
    errors.extend(check_makefile_portability(repo_root / "src" / "Makefile"))
    errors.extend(check_log_c_portability(repo_root / "src" / "log.c"))
    errors.extend(check_build_graph_sync(repo_root))

    if not errors:
        return 0

    for err in errors:
        print(f"[FAIL] {err}", file=sys.stderr)
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
