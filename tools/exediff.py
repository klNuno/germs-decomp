#!/usr/bin/env python3
"""Where the built exe differs from the original: the first differing words, by function.

  tools/exediff.py [N] [--text]   (N differing runs to print, default 5)

Jump tables hold code addresses, so a function whose size changed shows first as .rodata
differences: --text starts at the first function and points at the code that moved.
"""
import bisect
import os
import re
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def main():
    args = [a for a in sys.argv[1:] if a != "--text"]
    limit = int(args[0]) if args else 5
    orig = open(f"{ROOT}/extract/SLPS_021.07", "rb").read()
    built = open(f"{ROOT}/build/SLPS_021.07", "rb").read()
    base = struct.unpack("<I", orig[0x18:0x1C])[0] - 0x800
    syms = []
    for line in open(f"{ROOT}/build/germs.map", encoding="utf-8"):
        m = re.match(r"^\s+0x([0-9a-f]{8})([0-9a-f]{8})?\s+(\w+)\s*$", line)
        if m and not m.group(2):
            syms.append((int(m.group(1), 16), m.group(3)))
    syms.sort()
    addrs = [a for a, _ in syms]
    if len(orig) != len(built):
        print(f"size: original {len(orig):#x}, built {len(built):#x}")
    shown, i, n = 0, 0x800, min(len(orig), len(built))
    if "--text" in sys.argv:
        i = min(a for a, name in syms if name.startswith("func_")) - base
    while i < n and shown < limit:
        if orig[i] == built[i]:
            i += 1
            continue
        j = i
        while j < n and orig[j] != built[j]:
            j += 1
        addr = base + i
        k = bisect.bisect_right(addrs, addr) - 1
        name = f"{syms[k][1]}+{addr - syms[k][0]:#x}" if k >= 0 else "?"
        print(f"{addr:#010x} {name}: {j - i} bytes differ")
        shown += 1
        i = j
    if not shown and len(orig) == len(built):
        print("identical")


if __name__ == "__main__":
    main()
