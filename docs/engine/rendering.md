# Rendering

Every frame of the game is drawn by one function, `roadmap_draw_frame`, into one of two buffers
set up by the kaj view.c. The 3D parts (blocks, doors, people, things, the player, the car) go
through Sony's LIBGS sort routine with the game's own primitive handlers, which cut, light and fog
each polygon; sprites are added as plain SPRT packets. This page covers the buffers and the flip,
the ordering tables, the town renderer, models, sprites and their colour tables, the effects, the
fog by time of day and the functions kept in assembly. The frame loop that calls the drawing is on
[boot and loop](boot-and-loop.md#one-frame-of-the-game).

## Frame buffers and the flip

view.c sits in [kaj/view.c](../../src/kaj/view.c) after tss.c. `kaj_view_init`
(0x801D17F0) calls `GsInitGraph(320, 240, 4, 1, 0)` and builds two `ViewBuffer` records, each a
`DRAWENV` and a `DISPENV` (at +0x5C), an ordering table and a packet area:

| Buffer | Draws at | Shows | OT | Packets |
| --- | --- | --- | --- | --- |
| 0 | y 0 | y 240 | 0x8000 bytes, 0x2000 entries (`ot_length` 13) | 0x2C000 bytes |
| 1 | y 240 | y 0 | the same | the same |

Then `GsInit3D`, `GsInitVcount`, `SetGeomOffset(160, 120)`, `GsSetProjection(0xE4)`,
`SetBackColor(0, 0, 0)` and `SetFarColor(0, 0, 0)`.

`kaj_view_begin_frame` (0x801D1A58) switches to the other buffer, points `GsSetWorkBase` at its
packet area and clears its table with `ClearOTagR(tags, 0x2000)`. `kaj_view_flip` (0x801D1AAC)
has two paths: with the buffer's `dfe` flag clear it calls `DrawSync(0)`, `VSync(2)` and
`VSync(-1)`; with it set, `VSync(2)`, `VSync(-1)` and then `ResetGraph(1)`, with no `DrawSync`.
Both then put the two environments, count the frame and draw the table from its last entry with
`DrawOTag(tags + 0x1FFF)`. The refreshes since the previous flip go to `kaj_system.vsync_delta`
([frame timing](../discoveries.md#-the-game-times-every-frame-so-a-slow-machine-makes-it-choppy-not-slow)).
`kaj_view_set_bg_color` (0x801D1BAC) sets the clear colour of both buffers and
`kaj_view_clear_vram` (0x801D1BD4) clears 320 x 480.

## The town renderer

src/game/roadmap.c holds roadmap.c. `roadmap_draw_frame(mode)` (0x801A0418) copies the light
levels of `roadmap_screen_light` (0x801E1040) into `roadmap_brightness` and `roadmap_daylight_level`,
computes the textured colour (0x60 grey, or a tint from the daylight step when the light switch
and the dark flag are on) and the flag word that tells the handlers what to apply (dusk 1, depth cue 2, fade
4). Then it draws in this order:

| Step | Function | Draws |
| --- | --- | --- |
| 1 | `kaj_view_begin_frame` | the next buffer |
| 2 | `sprite_draw_all` (0x801A4554) | every visible sprite of `sprite_list` |
| 3 | `npc_rec_draw_all` (0x8018F6E8), `actor_draw_all` (0x80176370) | person models |
| 4 | `roadmap_draw_flash` (0x801A00EC) | a full-screen flash tile while one runs |
| 5 | `thing_draw_all` (0x801A7084), `door_draw_all` (0x80185664) | things and doors |
| 6 | `mod_draw_player` (0x8018DBA4) | the player model and, when drawn, the weapon |
| 7 | `vehicle_draw` (0x801AC30C) | the car or the train |
| 8 | `block_draw_all` (0x80179C50) | the town or building blocks |
| 9 | `kaj_view_flip` | flips; a pad mode of 2 becomes 1 |

Each 3D draw sets the matrices with `GsGetLs` and `GsSetLsMatrix` and calls `GsSortObject4J`
(0x801B34C0). That LIBGS routine calls a primitive handler from a table the program fills:
`roadmap_init_draw` (0x801A02C8) writes `roadmap_draw_f3`, `g3`, `ft3`, `gt3`, `f4`, `g4`, `ft4`
and `gt4` at +0x18 of the 8 entries of `roadmap_prim_handlers` (0x801E2DB0). The textured
handlers subdivide with `DivideFT3`, `DivideGT4` and the rest (3 divisions, 320 x 240); the flat
ones clip with `roadmap_add_clipped_f3` and `roadmap_add_clipped_g3` against the box set by
`InitClip`. The handlers apply daylight (`GPF`), depth cue (`DPCS`) and brightness by the flag
word.

`roadmap_add_sprite` (0x8019FDD8) builds one `SPRT` and a `DR_MODE`, coloured from the sprite's
colour index and scaled by the brightness, and reloads the palette first when it is marked dirty.
`roadmap_draw_sprite_frame` (0x801A05EC) draws one sprite alone in a full frame; the loader uses it
for its loading sprites ([the chunk walk](files-and-cd.md#the-chunk-walk)). `roadmap_start_flash`
(0x801A0690) starts a coloured flash, red when the player is hit; `shop_fade_screen_music`
(0x801A0D58) fades the screen and the music volume together frame by frame.

## Models and animation

src/game/mod.c holds mod.c. A model (`Model`, 0x94 bytes, made by `mod_alloc` or
`mod_create`) holds resident data with a header: TMD ids, the TMD itself and a TOD animation
table. `mod_setup` (0x8018D2DC) maps the TMD with `kaj_tmd_map`, loads the objects with
`kaj_tmd_load` and allocates the `GsOBJTABLE2`, `GsDOBJ2` and `GsCOORDINATE2` tables.
`mod_set_anim` (0x8018DA2C) starts an animation: the first frame's packets, the frame range, a
loop flag and a speed of 1 to 3 frames per draw by `vsync_delta`. Each frame `mod_update_all`
moves every playing model on with `kaj_tod_set_frame` ([TOD](files-and-cd.md#tim-tmd-and-tod)) and
delivers user event 0xF3000002 when one ends, which becomes event 0x200. `mod_find` (0x8018E56C)
finds a model by id; weapon models carry the weapon id plus 0x400. The "NPC " records of a scene
are models too (`npc_rec_` functions in npc.c; see [people and combat](people-and-combat.md)).

## Sprites and colour tables

src/game/sprite.c holds sprite.c. `sprite_create` (0x801A3DD4) makes a 0x20-byte sprite from a
`SPRT` chunk record: id, mode, position, depth and a grid of cells, with its TIM loaded by
`kaj_tim_load`, which keeps two copies of the palette when the record asks. `sprite_add` and
`sprite_find` (0x801A44B8) use `sprite_list`; `sprite_set_visible` (0x801A4A68) shows or hides by
id; `sprite_set_cell` (0x801A4BC8) picks the cell; `sprite_copy_cell` (0x801A3F90) copies a cell
in VRAM with `MoveImage`.

| Function | Palette work |
| --- | --- |
| `sprite_set_clut_entry` (0x801A461C) | one working entry; 39 callers |
| `sprite_fill_clut` (0x801A4824) | a range of working entries to one colour |
| `sprite_restore_clut` (0x801A4944) | a range back from the original copy |
| `sprite_reset_clut` (0x801A4708) | the whole original copy (+0x1C) over the working one (+0x20) |
| `sprite_exec_command` (0x801A417C) | action command 12: entry, range or reload from a script |

Each change sets the dirty flag that makes `roadmap_add_sprite` reload the palette. The clock on
the HUD is lit this way, by palette entries (credit: the hiddenblur/Germs-english project).

## Effects

src/game/effect.c holds effect.c. Its timed effects are kaj tasks
([tasks](boot-and-loop.md#tasks)) counted in 30ths of their length:

| Effect | Function | What it does |
| --- | --- | --- |
| slide | `effect_start_sprite_slide` (0x80185A60) | a sprite's y from 0xF0 to its place, or back; the mail menu |
| sprite animation | `effect_start_sprite_anim` (0x801862AC) | steps through a sprite's cells |
| fade | `effect_start_fade` (0x80186128) | level 0 to 0x1000 or back; `door_fade_step` (0x80185918) sets the screen level and `SsSepSetVol` |
| instant levels | `effect_fade_set_black` (0x80186258), `effect_fade_set_dim` (0x80186280) | level 0, or 0x400 |
| small flame | `effect_flame_small_update` (0x80185E38) | a fire filter on two 0x200-byte images (random bottom row, average of 5 neighbours minus 4), `LoadImage2` at (0x1B0, 0xE0) |
| large flame | `effect_flame_large_update` (0x80186010) | the same on two 0x400-byte images, weights 1, 2, 3, 2 |
| colour cycle | `effect_clut_cycle_update` (0x801865C0) | turns entries 1 to 14 of the palette at (0x60, 0x1E6) |

The flame and colour cycle updates run from `main_step_frame` while game variables at
`action_vars` +0x250, +0x252 and +0x254 are set. `effect_clut_rotate` (0x8018677C) turns a
16-colour palette for the loading sprite. effect.c also holds the elevator, weapon and item
screens ([player and survival](player-and-survival.md)).

## Fog and the time of day

`event_update_daylight` (0x8018A3F8, event.c) sets the far colour from the hour in
`action_vars.vars[0x3E]` when the light switch `roadmap_screen_light.daylight_on` is on:

| Hour | Far colour | Dark flag |
| --- | --- | --- |
| 5 | rising to 0x7A: `(s * 42 + s * 2 / 3 + 0x600) * 0x7A >> 12`, s = minute + 1 | set |
| 6 to 17 | 0x7A | clear |
| 18 | falling, s = 60 - minute | set |
| 19 to 4 | 0x2D | set |

Outside hours 5 and 18 the colour is only written on the hour (6:00, 19:00) or when forced.

`event_show_clock` (0x8018AABC) sets the switch for a scene, resets the far colour to black and
forces an update. `player_place_for_scene` (0x80197370) turns the depth cue on with
`SetFogNearFar(0x1388, 0x2710, 0xE4)` in the town and `SetFogNearFar(0x30D4, 0xFFFF, 0xE4)` in
some building arrivals. The same minute step drives
`roadmap_daylight_level`, the `GPF` scale of the handlers.

## Functions once kept in assembly

No function is left in assembly. Nineteen were set aside at first because they move the stack to
the scratchpad or drive the GTE: `roadmap_draw_f3`, `roadmap_draw_g3`, `roadmap_draw_ft3`,
`roadmap_draw_gt3`, `roadmap_draw_f4`, `roadmap_draw_g4`, `roadmap_draw_ft4`, `roadmap_draw_gt4`,
`roadmap_add_clipped_f3`, `roadmap_add_clipped_g3`, `roadmap_draw_flash`,
`roadmap_draw_sprite_frame`, `sprite_draw_all`, `thing_draw_all`, `door_draw_all`,
`mod_draw`, `mod_draw_player`, `vehicle_draw` and `block_draw_all`. They are C now, with the GTE
and scratchpad code in the PSY-Q style macros of `include/gte.h`. The twentieth, `player_set_view`
(0x8019555C), rebuilds the view matrix and is C too.

The four handlers that call the near-plane clipper (`roadmap_draw_f3`, `roadmap_draw_g3`,
`roadmap_draw_f4`, `roadmap_draw_g4`) hold one branch that never runs, `if ((nclip & 1) < 0)`,
right after the clip call. GCC 2.8.1 only gives the packet pointer `poly` a saved register when
`poly` lives across a call; that branch, which jumps to the code that reads `poly`, makes it live
across the clip call when the register allocator looks, and the combiner folds the test away
before any code is written. Without it, the closest C costs one extra register copy.
