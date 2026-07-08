# Contributing to UNP64 (Mirror)

This repository is an **official mirror** of UNP64. The primary author and maintainer of UNP64 is **iAN CooG**, and the official upstream project can be found at [http://iancoog.altervista.org/](http://iancoog.altervista.org/).

## Core Code & Feature Requests

Because this repository is a mirror:
* **Core UNP64 code changes, new unpacker/scanner routines, and 6502 emulation bug fixes** are maintained upstream by iAN CooG.
* If you have suggestions or bug reports regarding UNP64's depacking logic or missing cruncher support, please reach out via the official homepage.

## Accepted Contributions

We welcome Pull Requests for **repository, build system, and CI infrastructure**, including:
* **Build system fixes:** `Makefile`, Visual Studio project files, or compiler compatibility.
* **CI/CD & Release Automation:** GitHub Actions workflows (`ci.yml`, `release.yml`).
* **Documentation & Packaging:** `README.md`, build guides, or distribution scripts.

## Pull Request Guidelines

1. Ensure existing build workflows pass (`make -C src CFG=Release`).
2. Keep changes focused on repository / build infrastructure.
3. Submit PRs against the `main` branch.
