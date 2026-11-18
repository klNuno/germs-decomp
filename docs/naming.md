# Naming guide

How names are given in this project: the placeholder names a symbol keeps until it is understood, the form of our own names, the evidence a name needs, the tools that apply a name, and the glossary of the module words used in the code and the docs. A wrong name costs more than no name: a name goes in only with evidence, and the evidence is written next to it.

## Placeholder names

- Functions: `func_801XXXXX` (splat's), data `D_801XXXXX`, jump tables `jtbl_801XXXXX`.
- Struct types: `Unk_801XXXXX`, after the address of a global of that type or of the function that first needed it. Fields: `unkXX` with the hex offset (`unk3C`); padding is an `unkXX[N]` byte array.
- Parameters and locals: `arg0`, `var_s0`, `temp_v0`, `sp10`, the names m2c gave; some functions written by hand use short letters (`a`, `b`, `i`).
- Sony library functions carry their PSY-Q names (`CdRead`, `LoadImage`, `PadRead`). The internals the signature match left unnamed carry their real PSY-Q name too, once its signature, callers and library prove it; never an invented one.

## Our names

- Functions: snake_case, `<module>_<verb>_<object>` (`event_clock_add_minute`, `door_find`, `mail_check_schedule`). The module is the source file the function lives in, read from the file name the game's own assert messages print (`event.c`, `mail.c`). The developer's library, linked among Sony's objects, uses `kaj_<module>_...` (`kaj_timer_init`, `kaj_cdmgr_read`), plain `kaj_` for its `kaj.c` and `misc.c`.
- Eleven game files have no assert to name them. Their names (`actor`, `ai`, `building`, `card`, `dialog`, `main`, `menu`, `npc`, `player`, `shop`, `town`) are ours: they say what the code does and sort where the alphabetical link order puts them, but they are not the lost file names ([layout.md](layout.md) gives the evidence for each cut). `main.c` is named after the entry function, whose name is proven (below), not the file's. Every game function and global carries the prefix of the file that defines or owns it; a global used by several files takes the prefix of the file that writes or sets it up.
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

- `tools/xref.py NAME|ADDR`: one card per symbol, from the split assembly: unit, size, the strings it reaches, callees, callers, data and users. `--unit game/event` prints a whole file, `--unnamed` lists what still has a placeholder name, `--json build/xref.json` writes the index the renamer reads.
- `tools/rename.py NAMES.txt [--check]`: one `OLD NEW` per line under `#` evidence lines. Functions and globals go to `config/symbol_addrs.txt` with their evidence; every use in `src/`, `include/` and the docs follows. A struct type is written `type:Unk_X NewName`. A rename with no evidence is refused, and `--check` rebuilds and compares the executable.
- `tools/field_rename.py FIELDS.tsv`: renames a struct member in its definition, then every access the compiler reports, line by line. `--units src/game/X.c` compiles only the units given, for a struct local to one source file, so edits in progress in other units do not break it.
- `tools/local_rename.py LOCALS.tsv`: renames a parameter or local inside one function.
- `tools/unit_check.sh src/game/X.c`: builds one source file alone and compares its bytes and relocations with the last good build. Names never change code, so any difference is a mistake. `make check` stays the final judge.

## Glossary of modules

Game code, in link order. The module word is the source file name: the one the asserts print, or ours for a file with no assert (in italics).

| Module | Covers |
|---|---|
| `action` | The action queue and the scene's action sets (`ASET` records): load, run, flush, test the inventory, change scene |
| *`actor`* | People and enemies as records: animation, the commands scenes send them, damage, bodies, stats |
| *`ai`* | Their behaviour: targets, line of sight, moves, aim and fire |
| `block` | Town blocks (`BLCK`): loading, streaming, visibility, ground height and collision triangles |
| *`building`* | The building scene loop, its input, the elevator ride, the bus |
| *`card`* | The memory card screen: scan, load, save |
| *`dialog`* | The pause menu pages (`dialog_menu_`) and the text windows: drawing with the BIOS Kanji ROM, narration, profiles |
| `door` | Doors and their fades (`DOOR`) |
| `effect` | Sprite slides and animations, flames, colour-table cycling, fades, alarms, the elevator, and the weapon and item inventories |
| `event` | The event loop answers: clock tick, energy drain, body-part status, the HUD clock and gauges |
| `mail` | The office computer's mails (`MAIL`): arrival schedule, list, reading |
| *`main`* | `main`, the frame wait and the scene changes (office, town, building), angle helpers |
| *`menu`* | The list menu shared by items, weapons, the shop and storage |
| `mod` | Models (TMD) and their animations, the player's model |
| *`npc`* | The person record table of a scene: place, move, command, draw |
| `object` | Scene loading: one loader per `SCE.S` chunk tag, and the office loop |
| *`player`* | The player's movement on foot, in the car and on the train, area triggers, and the view |
| `roadmap` | The town renderer's primitive lists (flat, Gouraud and textured triangles and quads, clipped) |
| *`shop`* | The shop counters, the gun shop and the food shops: menus by hour and by state, topics, replies |
| `sound` | Sound effects and music (`MIDI`, `VABH`), footsteps |
| `sprite` | 2D sprites (`SPRT`) and their colour tables; the title, station and phone screens |
| `thing` | Scene objects (`THNG`) with scripts and hit tests: loading, drawing, the target marker over a person, the title's fly-in |
| *`town`* | The town field loop: input, actions, entering and leaving, the train hooks |
| `vehicle` | The car, the train and the car navigation menu |

The developer's library (`kaj_`). Files its asserts name: `event.c` (the event queue), `kaj.c` and `misc.c` (start-up, errors), `ll.c` (linked lists), `tim.c` (TIM pictures), `timer.c` (the root-counter clock and alarms), `tss.c` (tasks), `view.c` (frame buffers and the frame flip), `cdmgr.c` (CD reads, the file table and its memory pools). Other prefixes name a topic, not a file: `kaj_map_` (the town and place map cells and the files streamed for them), `kaj_heap_`, `kaj_tmd_` and `kaj_tod_` (models and their animation frames), `kaj_pad_`, `kaj_sound_`.
