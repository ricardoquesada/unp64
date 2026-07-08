# UNP64

[![CI](https://github.com/ricardoquesada/unp64/actions/workflows/ci.yml/badge.svg)](https://github.com/ricardoquesada/unp64/actions/workflows/ci.yml)

This repository is an official mirror of **UNP64**, a generic Commodore 64 (`.prg`) executable unpacker created by iAN CooG.

The official homepage can be found at http://iancoog.altervista.org/.

Pre-built binaries for Linux, macOS, and Windows are available on the [Releases](https://github.com/ricardoquesada/unp64/releases) page.

## Overview

UNP64 is designed to automatically unpack compressed Commodore 64 programs. It works by simulating a 6502 CPU and a minimal C64 memory environment:

1. Loads the packed `.prg` file into emulated memory.
2. Simulates execution through the unpacker routine.
3. Detects when unpacking is complete (when execution returns to normal memory space).
4. Saves the unpacked memory image as a decompressed `.prg` file.

It supports a wide range of C64 crunchers, packers, freezer cartridge dumps (Action Replay, Super Snapshot, Freeze Machine, etc.), and multi-layer compressed files.

## Building from Source

### Linux / macOS
To build the Release binary using `make`:
```bash
make -C src CFG=Release
```
The compiled executable will be placed in `src/Release/unp64`.

To build a Debug version:
```bash
make -C src CFG=Debug
```

### Windows
- **MinGW / MSYS2**:
  ```bash
  mingw32-make -C src CFG=Release
  ```
- **Visual Studio**:
  Open `src/unp64.VCproj` in Visual Studio and build the solution.

## Quick Usage

```bash
unp64 <packed.prg>{[,|@]Addr} [-parameters]
```

### Examples

- **Unpack a file:**
  ```bash
  unp64 packed.prg
  ```
- **Unpack all compression layers recursively:**
  ```bash
  unp64 packed.prg -c
  ```
- **Verbose output (show scanner & vector info):**
  ```bash
  unp64 packed.prg -v
  ```
- **Specify entry point if SYS detection fails:**
  ```bash
  unp64 packed.prg -e$080d
  ```

## Documentation

For full details on usage, command-line flags, supported unpackers, and historical notes, refer to [unp64.txt](unp64.txt).
