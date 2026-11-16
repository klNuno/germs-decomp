# Naming guide

How names are given in this project: the placeholder names a symbol keeps until it is understood, the form of our own names, the evidence a name needs, the tools that apply a name, and the glossary of the module words used in the code and the docs. A wrong name costs more than no name: a name goes in only with evidence, and the evidence is written next to it.

## Placeholder names

- Functions: `func_801XXXXX` (splat's), data `D_801XXXXX`, jump tables `jtbl_801XXXXX`.
- Struct types: `Unk_801XXXXX`, after the address of a global of that type or of the function that first needed it. Fields: `unkXX` with the hex offset (`unk3C`); padding is an `unkXX[N]` byte array.
- Parameters and locals: `arg0`, `var_s0`, `temp_v0`, `sp10`, the names m2c gave; some functions written by hand use short letters (`a`, `b`, `i`).
- Sony library functions carry their PSY-Q names (`CdRead`, `LoadImage`, `PadRead`). Since naming wave 1, the internals the signature match left unnamed carry their real PSY-Q name too, once its signature, callers and library prove it; never an invented one.

## Our names

- Functions: snake_case, `<module>_<verb>_<object>` (`event_clock_add_minute`, `door_find`, `mail_check_schedule`). The module is the source file the function lives in, read from the file name the game's own assert messages print (`event.c`, `mail.c`). The developer's library, linked among Sony's objects, uses `kaj_<module>_...` (`kaj_timer_init`, `kaj_cdmgr_read`), plain `kaj_` for its `kaj.c` and `misc.c`.
- Five stretches of code have no assert to name their file. Their prefixes (`npc_`, `ai_`, `menu_`, `text_`, `player_`) say what the code does; they are not the lost file names. The link order is alphabetical, which bounds those names: see the glossary.
- The entry function is `main`: naming it so makes GCC add the implicit `__main()` call the original already had, which proves the original was called `main` too.
- Globals: `<module>_<noun>` (`kaj_timer_period`, `action_queue`).
- Struct types: PascalCase (`ClockTime`). Fields, parameters and locals: snake_case.
- A field keeps its offset name (`unk3C`) until a reader or writer with a known role, a RAM address players know, a string or a Sony library argument proves what it holds. A type keeps `Unk_X` until two of its fields or its owner prove what it is.

## Evidence

A name is backed by at least one of:

- a string the function prints or passes (assert file names, debug messages, file paths);
- a Sony library call whose meaning is fixed (`CdRead`, `LoadImage`, `SsUtKeyOn`), and the arguments it receives;
- the data it loads: `SCE.S` chunk tags (`ASET`, `BLCK`, `DOOR`, `MAIL`, `MIDI`, `TEXT`, `THNG`), `RES.R` blocks;
- callers and callees already named with evidence, and the role the call pattern gives (an allocator pair, a list walk, an event handler table);
- a RAM address the community documented (cheat codes, the translation project's notes, see [community-knowledge.md](community-knowledge.md)) once the code agrees with it;
- an emulator run that showed the effect (the findings in [discoveries.md](discoveries.md)).

Every function and global name sits in `config/symbol_addrs.txt` with its evidence on the `//` line just above it. Names the evidence does not reach stay placeholders.

## Tools

- `tools/xref.py NAME|ADDR`: one card per symbol, from the split assembly: unit, size, the strings it reaches, callees, callers, data and users. `--unit game/8018920C` prints a whole unit, `--unnamed` lists what still has a placeholder name, `--json build/xref.json` writes the index the renamer reads.
- `tools/rename.py NAMES.txt [--check]`: one `OLD NEW` per line under `#` evidence lines. Functions and globals go to `config/symbol_addrs.txt` with their evidence; every use in `src/`, `include/` and the docs follows. A struct type is written `type:Unk_X NewName`. A rename with no evidence is refused, and `--check` rebuilds and compares the executable.
- `tools/field_rename.py FIELDS.tsv`: renames a struct member in its definition, then every access the compiler reports, line by line.
- `tools/local_rename.py LOCALS.tsv`: renames a parameter or local inside one function.
- `tools/unit_check.sh src/game/X.c`: builds one source file alone and compares its bytes and relocations with the last good build. Names never change code, so any difference is a mistake. `make check` stays the final judge.

## Glossary of modules

Game code, in link order. The module word is the source file name the asserts print, or a label for a stretch with no assert (in italics).

| Module | Covers |
|---|---|
| `action` | The action queue and the scene's action sets (`ASET` records): load, run, flush, test the inventory, change scene |
| *`npc`*, *`ai`* | No assert, between `action.c` and `block.c`. People and enemies: animation, damage, the commands scenes send them; their movement and attack decisions |
| `block` | Town blocks (`BLCK`): loading, streaming, visibility, ground height and collision triangles |
| *`menu`*, *`text`* | No assert, between `block.c` and `door.c`. Pause menus, status and memory card pages; text drawing with the BIOS Kanji ROM, narration and profiles |
| `door` | Doors and their fades (`DOOR`); `door.c` starts inside the stretch before it, where its first functions sit |
| `effect` | Sprite slides and animations, flames, colour-table cycling, fades, alarms, the elevator, and the weapon and item inventories |
| `event` | The event loop answers: clock tick, energy drain, body-part status, the HUD clock and gauges |
| `mail` | The office computer's mails (`MAIL`): arrival schedule, list, reading |
| `mod` | Models (TMD) and their animations, the player's model |
| `object` | Scene loading: one loader per `SCE.S` chunk tag |
| *`player`* | No assert, between `object.c` and `roadmap.c`. The player's movement on foot, in the car and on the train, and the view |
| `roadmap` | The town renderer's primitive lists (flat, Gouraud and textured triangles and quads, clipped) |
| `sound` | Sound effects and music (`MIDI`, `VABH`), footsteps |
| `sprite` | 2D sprites (`SPRT`) and their colour tables |
| `thing` | Scene objects (`THNG`) with scripts and hit tests |
| `vehicle` | The car, the train and the car navigation menu |

The developer's library (`kaj_`). Files its asserts name: `event.c` (the event queue), `kaj.c` and `misc.c` (start-up, errors), `ll.c` (linked lists), `tim.c` (TIM pictures), `timer.c` (the root-counter clock and alarms), `tss.c` (tasks), `view.c` (frame buffers and the frame flip), `cdmgr.c` (CD reads, the file table and its memory pools). Other prefixes name a topic, not a file: `kaj_map_` (the town and place map cells and the files streamed for them), `kaj_heap_`, `kaj_tmd_` and `kaj_tod_` (models and their animation frames), `kaj_pad_`, `kaj_sound_`.
