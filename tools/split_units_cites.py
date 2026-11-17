"""Citations of old address units that tools/split_units.py cite cannot settle from the line alone:
(path, old unit, words of the line) -> the file (dir/name) or files (a tuple) that hold what the line
cites. For the split of commit 4efff08 (paths and names are those of that commit). Prose that named
a whole unit ("the 8017EBF8 unit", "holds cdmgr.c, then a heap") was rewritten by hand instead."""

CITE_OVERRIDES = {
    ('docs/discoveries.md', 'game/8018FA18', 'in office mode 2, src/game/8018FA18.c'): 'game/object',
}
