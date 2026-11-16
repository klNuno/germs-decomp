# Files and the CD

The game reads the disc in two ways. Scenes and resources come from two packed files, SCE.S and
RES.R, read straight through LIBCD by object.c and cut into tagged chunks, one loader per tag.
The town and the buildings stream their blocks while the player moves, through the kaj CD
manager, which caches files in memory pools and moves them when it compacts a pool. This page
covers both paths and the TIM, TMD and TOD formats. What a scene does with its chunks is on
[scenes and scripts](scenes-and-scripts.md); the blocks the stream feeds are on
[town and vehicles](town-and-vehicles.md).

## SCE.S

src/game/8018FA18.c holds object.c. `object_load_scene` (0x801926B4) loads the scene of
`scene_request` ([changing place](boot-and-loop.md#changing-place)) by calling
`object_iff_open(&ctx, 0, scene)` (0x80192380). That function searches "\SCE.S;1" with
`CdSearchFile` (retrying until found), seeks to `object_sce_offsets[scene]` (0x801D7780, 24
entries, byte offsets turned into sectors with `>> 11`) and reads one 0x800 sector of
`IffEntry` records of 0x18 bytes: offset, size and four counts. Its context of 0x10 bytes holds
the header, a chunk buffer of 0x800, the size and the position ("Error Allocation IFF Context",
"Error Allocating IFF Header", "Error Allocating IFF Chunk Header" when memory runs out).

| Entry | Counts it gives | Read when |
| --- | --- | --- |
| 0 | npc bodies, npc records, weapons, items (each only when not 0) | always: the common part of the scene |
| variant + 1 | npcs, area triggers, action sets (`object_aset_count`), enemy stats | the variant in `scene_request.variant` |

Each entry is read with `object_read_chunks(ctx, request, 2, 0)`. The path the request carries
("\S\OFC.S;1" and others) is never opened
([scene files](../discoveries.md#-the-game-still-names-scene-files-the-disc-does-not-have)).

## The chunk walk

`object_read_chunks` (0x80191AB0) reads the first sector of each chunk: the tag at +0, the size
at +4, an id at +8, the body after 8 bytes. A chunk larger than 0x7F8 bytes is read whole into
the loader's buffer. Unknown tags are skipped by seeking. After each chunk the progress argument
draws a loading sprite with `roadmap_draw_sprite_frame`: 0 a bar on sprite 0x40F, one step per
6 chunks; 1 a palette entry of sprite 0x207 per chunk; 2 sprite 0x410 with its colours rotated;
-1 nothing. Loaders that run out of memory stop in `kaj_abend` ("Error Allocating IFF_ID_SPRT
Buffer" and the like).

| Tag | Loader | Where the data goes |
| --- | --- | --- |
| `ASET` | `object_load_aset` (0x8018FA18) | `action_load_set` per action set |
| `BLCK` | `object_load_blck` (0x8018FC90) | `block_setup` and the block list |
| `DOOR` | `object_load_door` (0x8018FED4) | `door_create`, `door_setup`, `door_add` |
| `MAIL` | `object_load_mail` (0x80190108) | the mail whose id is asked for |
| `MIDI` | `object_load_midi` (0x80190378) | `sound_bgm_create`, `sound_bgm_open` ([music](sound-and-music.md#music)) |
| `MOD`, `MOE` | `object_load_mod` (0x801905A0) | `mod_alloc`, `mod_list_add`; filter 0x400 keeps only the equipped weapons |
| `SPRT` | `object_load_sprt` (0x80190B2C) | `sprite_create`, `sprite_add` |
| `TEXT` | `object_load_text` (0x80190D8C) | a picture uploaded with `kaj_tim_upload_hdr` |
| `THNG` | `object_load_thng` (0x80190FD8) | `thing_create`, `sprite_thing_init`, `thing_list_add` |
| `TIM` | `object_load_tim` (0x8019120C) | the TIM whose id is asked for, `kaj_tim_upload` |
| `VABH` | `object_load_vabh` (0x80191450) | `sound_se_alloc_header`, `sound_vab_open_head` |
| `VABB` | `object_load_vabb` (0x8019159C) | streamed to the SPU, `sound_se_push` ([banks](sound-and-music.md#sound-banks)) |
| `VECL` | `object_load_vecl` (0x80191888) | `vehicle_create` |

`object_load_other` (0x801907C8) keeps the table chunks in `object_scene_tables` (0x801E02D8, type
`SceneTables`):

| Tag | Field | Holds |
| --- | --- | --- |
| `AREA` | `triggers` | the area triggers of the variant |
| `ACTR` | `npcs` | the people of the variant, then `action_init_npcs` |
| `NPC` | `npc_records` | person records |
| `CHAR` | `npc_bodies` | person bodies |
| `ENMY` | `npc_stats` | enemy stats |
| `ITEM` | `items` | item records |
| `WEPN` | `weapons` | weapon records ([the weapon record](../discoveries.md#-the-weapon-record-three-requirements-accuracy-damage-and-three-ranges)) |
| `TXT` | `texts[text_count++]` | strings for narration and messages |

`SceneTables` also holds the music handle `bgm`, the sound bank stack `se_banks[4]`, the `mail`
pointer and the `vehicle`. Some requests skip `BLCK`, `VABH` and `VABB`.

## RES.R

`object_load_res(entry, progress)` (0x80192B8C) reads one RES.R entry with `object_iff_open(ctx,
1, entry)`, through `object_res_offsets` (0x801D7744, 15 entries). Each entry belongs to one
caller in the code. The contents column comes from reading the disc's RES.R with the loader's
rules above.

| Entry | Caller | Chunks |
| --- | --- | --- |
| 0 | `sprite_title_init` (0x801A4E04), the title | VAB, THNG, SPRT, TEXT, TXT |
| 1 | `main` at boot | SPRT, VAB, NPC, WEPN (18 weapons), TEXT, ITEM (74 items) |
| 2 | `object_load_weapon_mods` (0x8019290C) | THNG, 18 MOD: the weapon models |
| 3, 0xB, 0xA | `vehicle_load_data`, vehicle modes 1, 2 and 3 | VAB, VECL (3 adds SPRT and TEXT) |
| 4, 5 | `menu_card_run`: load, save | SPRT |
| 6 | `menu_run`, the pause menu | 12 SPRT |
| 7 | `object_load_mail_by_id` (0x80192A44) | 32 MAIL |
| 8 | `menu_confirm`, the mail list | 32 SPRT |
| 9 | `sprite_phone_loop`, the phone | VAB, BLCK, SPRT, TEXT, MOD |
| 0xC | `object_load_res12_by_id` (0x80192CD0), for thing.c | 13 TIM |
| 0xD, 0xE | `menu_confirm`, the list page and the status page | SPRT, TEXT |

## The CD manager

[kaj/801D1E70.c](../../src/kaj/801D1E70.c) holds cdmgr.c, then a heap with no assert
(`kaj_heap_`) and the map streamer (`kaj_map_`). Only block.c uses them. `kaj_cdmgr_init`
(0x801D1E70) allocates each pool of `kaj_cdmgr_pools` (0x801DFBE0, {id, size, buffer, heap}, 3
pools) and makes its heap with `kaj_heap_init` (0x801D3924); a heap is a list of {addr, size,
next} blocks that `kaj_heap_compact` closes up with `memmove`. There are 32 cache slots of 0x24.

| Function | Role |
| --- | --- |
| `kaj_cdmgr_load` (0x801D2210) | file, pool, type to a slot 1..32; a cached file gets its refcount raised |
| `kaj_cdmgr_load_list` (0x801D254C) | compacts the pools, gives slots to the listed files and chains their reads |
| `kaj_cdmgr_poll` (0x801D1F70) | the read machine: seek (`CdControl`), double speed and `CdRead`, `CdReadSync` with a retry after a stall, `CdFlush` |
| `kaj_cdmgr_release` (0x801D28C0) | refcount down; at 0 `kaj_cdmgr_free_data` (0x801D3730) |
| `kaj_cdmgr_relocate` (0x801D2B60) | fixes pointers in data that compaction moved, from `kaj_cdmgr_save_addrs` (0x801D35EC) |
| `kaj_cdmgr_rebase_dir` (0x801D2F18) | adds a file's sector (LBA - 150) to every {offset, size} of a directory |
| `kaj_cdmgr_get` (0x801D32F0), `kaj_cdmgr_get_type` (0x801D3364) | data and type of a slot |
| `kaj_cdmgr_free_all` (0x801D3650) | flushes the CD and empties the cache |

The type of a cached file says how to fix and free it. Types 1 and 3 hold a table of entries
with TMD data: `kaj_cdmgr_relocate` itself subtracts the move from three pointers of each object
of every mapped TMD (0x41 with bit 0 of its flags set), and in type 3 hands an entry of kind 4,
an arena, to `block_replace_arena` (0x8017C9F8). Type 5 is a model, moved by `mod_relocate`
(0x8018D6DC), which shifts its TMD with `kaj_tmd_unmap`, and released by `mod_on_data_free`
(0x8018E1F0); type 2 is CITY.MP and type 4 a place's .B file.

## Town cells and streamed places

The map streamer has two modes. Mode 1, the town: `kaj_map_open_city` (0x801D67E0) caches
"\C\CITY.MP;1" in pool 0, `kaj_map_load_city_dir` (0x801D3B7C) loads the directory "\C\CITY.F;1"
and rebases it on "\C\CITY.BC;1". `kaj_map_update_city(x, y)` (0x801D4FA0) turns the player
position into a cell and, when the cell changes, `kaj_map_stream_cell` (0x801D6120) loads the
files of the cell and its neighbours into the other half of a double buffer. Mode 2, a building:
`kaj_map_open_place(letter, name)` (0x801D6894) caches "\B\%c\%s.B;1" and the directory
"\F\%c\%s.F;1" is rebased on "\M\%c\%s.RM;1"; `kaj_map_update_place` (0x801D5934) loads a room's
files of types 3, 5 and 6 the same way.

block.c polls the streamer every frame in `block_stream_update` (0x8017AAB4): result 3 refills
the blocks with `block_setup`, result 1 reloads them all. `block_load_all` sends type 5 files to
`mod_create`, type 6 to `kaj_tim_upload_hdr` and the rest to `block_setup`.
`block_stream_stop` (0x8017D3F0) ends streaming with `kaj_cdmgr_free_all`.

## TIM, TMD and TOD

[kaj/801CF790.c](../../src/kaj/801CF790.c) holds tim.c. `kaj_tim_load` (0x801CF790) reads a TIM
with `GsGetTimInfo`, uploads pixels and palette with `LoadImage` (not in mode 2) and fills a
0x24-byte handle: position, size, texture page, CLUT and, on request, two copies of the palette
("No CLUT in this TIM" when a palette is asked of a TIM without one). `kaj_tim_upload`
(0x801CFB4C) only uploads; `kaj_tim_upload_hdr` (0x801CFBB4) does the same after an 8-byte header
whose second halfword says whether to load the palette. `kaj_tim_free` (0x801CFAE8) frees all.

TMD models go through misc.c in kaj/801CCAF4.c: `kaj_tmd_map` (0x801CD3F0) and `kaj_tmd_load`
(0x801CD028) call `GsMapModelingData` ("Crashed TMD or Illegal Data"); `kaj_tmd_load` also
allocates the `GsDOBJ2` array ("Too Many Objects in TMD") and links each object with
`GsLinkObject4`. `kaj_tmd_unmap` (0x801CD78C), despite its name, does not undo the mapping: it
subtracts a word delta from three pointers of each object of a mapped TMD, so a mapped TMD stays
valid after its data moved.

kaj/801D0880.c has no assert; its `kaj_tod_` functions play TOD animation. `kaj_tod_set_frame`
(0x801D1088) runs the packets of a frame through `kaj_tod_set_packet` (0x801D0880):

| Packet type | Effect |
| --- | --- |
| 0 | attribute |
| 1 | coordinate: rotation, scale, translation, relative when flag bit 0 is set |
| 2 | TMD id, linked with `GsLinkObject4` |
| 3 | parent object |
| 8 | create or kill an object (`kaj_tod_create_obj`, `kaj_tod_remove_obj`) |

Models and their frames are on [rendering](rendering.md#models-and-animation).
