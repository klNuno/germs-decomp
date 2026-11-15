# germs-decomp

A matching decompilation of **Germs: Nerawareta Machi** (PlayStation, KAJ, 1999), retail release SLPS-02107.

The goal is C that rebuilds the retail executable byte for byte, and through it an understanding of how the
game works: the city, the scenes, the weapons, the per-limb damage and what the disc holds that the game
never shows.

## Status

[![Progress map: one rectangle per function, sized by its code bytes](docs/progress/treemap.svg)](docs/progress/treemap.svg)

- The executable splits and links back to the retail `SLPS_021.07` (`make check` compares the sha1).
- 635 of the 655 functions to decompile (510 of the game, 145 of the developer's own library) are matching C:
  245,568 of 272,276 code bytes (90.2 %). The rest is still assembly, 19 functions of it on purpose: they move
  the stack to the scratchpad or drive the GTE in ways plain C cannot express. Sony's PSY-Q 4.4 libraries (138,048
  bytes) stay as Sony shipped them.
- The map is regenerated after each wave with `tools/progress_map.py` (after `make check`); open it to hover
  each function, `docs/progress/progress.json` holds the same data. No function is fully named yet: every C
  body still carries address names.
- Compiler: GCC 2.8.1 with ASPSX 2.56, `-O2 -G8 -funsigned-char`, found by compiling small functions until
  they matched.

## Building

You need Linux x86-64 with `make`, `git`, `curl`, a C compiler (`gcc`), Python 3.12 (through `uv` or
`venv`) and stable Rust (for `mipsmatch`), plus your own dump of the game disc. No game or BIOS file is
provided here.

```sh
git config core.hooksPath tools/hooks
tools/setup.sh                  # pinned toolchain into tools/ and .venv/
# put your disc in disks/ (see disks/README.md)
make check-disk                 # extracts the disc, checks SLPS_021.07
make split && make check        # splits the executable, builds it from src/, compares the sha1
```

`make check-disk` must print `extract/SLPS_021.07: OK` and `make check` must print
`build/SLPS_021.07: OK`.

## Legal

Fan project, not affiliated with KAJ or its successors. It ships no game asset: no executable, no disc
data, no audio, no dump of the game's text or images, and you need your own copy of the game to build
anything. A takedown request from the rights holder will be honored.

## Credits

The disc survey and the decompilation notes of the Germs English translation project (MIT) were read as
leads; no code or name was taken from them.

Built with splat, spimdisasm, maspsx, m2c, decomp-permuter, asm-differ, mipsmatch, objdiff, mkpsxiso,
old-gcc and PCSX-Redux; Sony's library functions were identified with lab313ru's psx_psyq_signatures.
`include/include_asm.h`, `macro.inc`, `labels.inc` and `gte_macros.inc` are splat's generated files (MIT,
Copyright (c) 2021 Ethan Roseman).
