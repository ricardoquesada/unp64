#!/usr/bin/env bash
# Build and smoke-test UNP64 (Release configuration) for pre-commit verification.
#
# Resolves a portable parallel job count and Make binary across macOS, Linux,
# and MSYS2/Windows, builds `src/Release/unp64(.exe)`, and verifies that
# invoking the binary prints the UNP64 usage banner.

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# Detect CPU core count portably (macOS -> Linux/MSYS2 -> safe fallback).
if command -v sysctl >/dev/null 2>&1; then
  JOBS="$(sysctl -n hw.ncpu 2>/dev/null || echo 4)"
elif command -v nproc >/dev/null 2>&1; then
  JOBS="$(nproc 2>/dev/null || echo 4)"
else
  JOBS=4
fi

# Prefer POSIX `make`; fall back to `mingw32-make` on Windows/MinGW setups.
if command -v make >/dev/null 2>&1; then
  MAKE_CMD="make"
elif command -v mingw32-make >/dev/null 2>&1; then
  MAKE_CMD="mingw32-make"
else
  echo "Error: neither 'make' nor 'mingw32-make' was found in PATH." >&2
  exit 1
fi

# Suppress verbose per-file progress on stdout while keeping compiler warnings/errors on stderr.
"$MAKE_CMD" -C "$REPO_ROOT/src" -j"$JOBS" CFG=Release >/dev/null

if [[ -x "$REPO_ROOT/src/Release/unp64" ]]; then
  BIN_PATH="$REPO_ROOT/src/Release/unp64"
elif [[ -x "$REPO_ROOT/src/Release/unp64.exe" ]]; then
  BIN_PATH="$REPO_ROOT/src/Release/unp64.exe"
else
  echo "Error: Release binary not found in $REPO_ROOT/src/Release/." >&2
  exit 1
fi

# UNP64 exits non-zero when run with no arguments, so capture output before
# grepping to avoid tripping `set -o pipefail`.
banner="$("$BIN_PATH" 2>&1 || true)"
if ! printf '%s\n' "$banner" | grep -qi "UNP64"; then
  echo "Error: $BIN_PATH did not emit expected UNP64 usage banner." >&2
  printf '%s\n' "$banner" >&2
  exit 1
fi
