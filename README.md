# UNP64

This repository is an official mirror of **UNP64**, a generic Commodore 64 (`.prg`) executable unpacker created by iAN CooG.

The official homepage can be found at http://iancoog.altervista.org/.

## Overview

UNP64 is designed to automatically unpack compressed Commodore 64 programs. It works by simulating a 6502 CPU and a minimal C64 memory environment:
1. Loads the packed `.prg` file into emulated memory.
2. Simulates execution through the unpacker routine.
3. Detects when unpacking is complete (when execution returns to normal memory space).
4. Saves the unpacked memory image as a decompressed `.prg` file.

It supports a wide range of C64 crunchers, packers, freezer cartridge dumps (Action Replay, Super Snapshot, Freeze Machine, etc.), and multi-layer compressed files.

## Documentation

For full details on usage, command-line options, supported unpackers, and historical notes, refer to [unp64.txt](unp64.txt).
