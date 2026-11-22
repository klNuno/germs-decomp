#!/usr/bin/env python3
# Licence: MIT for klNuno's own code only; game-derived data and Sony names in it are excluded (LICENSING.md).
"""After `make split`: write the PS-X EXE header's addresses as symbols.

    python3 tools/postsplit.py

splat writes asm/header.s with numbers: the initial pc (0x801C8840) and the .text size (0x70000).
Both stay the same when code is added before them, so a shifted build would start at the old entry
point and load too few bytes. This rewrites, in place:
  - asm/header.s: initial pc -> __SN_ENTRY_POINT, .text size -> germs_exe_text_size;
  - linker/germs.ld: defines germs_exe_text_size after main_VRAM_END (the file size after the
    header, rounded to a 0x800 sector like the Makefile's `truncate -s %2048`).
Sony's startup (__SN_ENTRY_POINT) needs nothing here: spimdisasm writes it as instructions with
%hi/%lo symbols (the end of .bss is main_BSS_END through config/symbol_addrs.psyq.txt).
Only the address-bearing words change: the bytes of the retail build stay the same (make check).
Running it twice is safe.
"""
import re
import sys

HEADER = "asm/header.s"
LD = "linker/germs.ld"
SIZE = "germs_exe_text_size"


def main():
    s = open(HEADER).read()
    s2 = re.sub(r"\.word 0x[0-9A-Fa-f]{8}(\s*)/\* Initial PC \*/", r".word __SN_ENTRY_POINT\1/* Initial PC */", s)
    s2 = re.sub(r"\.word 0x[0-9A-Fa-f]{8}(\s*)/\* \.text size \*/", r".word %s\1/* .text size */" % SIZE, s2)
    if s2 != s:
        open(HEADER, "w").write(s2)
    ld = open(LD).read()
    if SIZE not in ld:
        ld = re.sub(r"^(\s*)main_VRAM_END = \.;$",
                    r"\g<0>\n\1%s = ALIGN(main_ROM_END, 0x800) - main_ROM_START;" % SIZE, ld, count=1, flags=re.M)
        open(LD, "w").write(ld)
    ok = ("__SN_ENTRY_POINT" in s2 and "/* Initial PC */" in s2 and ".word %s" % SIZE in s2
          and "%s = " % SIZE in ld)
    print("postsplit: header and linker script %s" % ("done" if ok else "INCOMPLETE"))
    if not ok:
        sys.exit(1)


if __name__ == "__main__":
    main()
