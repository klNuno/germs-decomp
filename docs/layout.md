# Source file layout

The executable links the game's own source files first, then the Sony libraries with the developer's own small
library (the `kaj_` functions) placed between Sony objects. The split in `config/splat.yaml` cuts the code into 26
units: 18 game units, 8 kaj units, and 8 runs of Sony code between them. A unit is named by its first address. Where
an assert string names a source file, the unit carries that name; elsewhere the name is still unknown. This page
lists every unit in link order with the evidence for each cut, then the files that likely hide inside units, and
what is left to settle.

Confidence, for the two ends of a unit: **proven** means a Sony object or the end of .text sits on both sides, so no
other cut is possible; **likely** means each end rests on an assert, a change in `gp` use or a jump-table alignment,
which puts a file change at the cut or a few functions before it; **guess** means the binary allows a clearly
different cut, and the row says which.

26 units: 8 proven, 15 likely, 3 guess.

The evidence words:

- **assert**: a function passes a source file name to `kaj_abend`, so it belongs to that file; the file names in the
  table come from these strings. A unit starts at its first such function unless the .rodata order forbids it.
- **jtbl**: GCC 2.8.1 aligns every jump table to 8 bytes inside its object and the link keeps 4-byte alignment, so a
  jump table at 4 mod 8 from its unit's .rodata start proves that a new object starts before it. The real file start
  may be a few functions earlier, where no function uses .rodata.
- **gp**: the same small global is read with `lui` before the cut and through `gp` after it, as the comments of
  `config/splat.yaml` record at both gp cuts (`ai_door_noise` at 0x801768F8, `player_pick_trigger_hook` at 0x80195098). That change is
  read as a likely file change, not a proven one; the file start may still be a few functions before the cut.
- **rodata**: each .rodata symbol is referenced by one unit only, and .rodata follows the unit order, so a cut can
  only fall where the .rodata order allows.

## Files in link order

| Unit | File | Functions | Confidence | Evidence |
| --- | --- | --- | --- | --- |
| [game/80173054](../src/game/80173054.c) | action.c | `action_cmd_change_scene..action_run_npc_event` @0x801752F4 (19) | likely | start of .text; assert in `action_load_set` (0x80173A44) |
| [game/8017546C](../src/game/8017546C.c) | unknown | `npc_update_anim..npc_find_stats` @0x80176890 (15) | likely | jtbl cut |
| [game/801768F8](../src/game/801768F8.c) | unknown | `ai_check_line..ai_in_aim_cone` @0x80179630 (16) | likely | gp cut: `ai_door_noise` is read with `lui` before, through `gp` from here |
| [game/80179848](../src/game/80179848.c) | block.c | `block_setup..block_bus_run` @0x8017E99C (42) | likely | assert from `block_setup` to `block_create` (0x8017CB98) |
| [game/8017EBF8](../src/game/8017EBF8.c) | unknown | `menu_card_init_slots..door_exec_command` @0x8018519C (46) | likely | jtbl cut |
| [game/80185380](../src/game/80185380.c) | door.c | `door_create..door_fade_step` @0x80185918 (9) | guess | assert in `door_create`; the file may start at `door_setup` (0x801844D4) or before (below) |
| [game/80185A60](../src/game/80185A60.c) | effect.c | `effect_start_sprite_slide..effect_item_find` @0x801891A4 (50) | likely | assert from the first function to `effect_weapon_unequip` (0x801875E4) |
| [game/8018920C](../src/game/8018920C.c) | event.c | `event_open..event_advance_clock` @0x8018ABE8 (22) | likely | assert in `event_open` |
| [game/8018ACAC](../src/game/8018ACAC.c) | mail.c | `mail_create..mail_menu_get_entry` @0x8018D294 (32) | likely | assert in `mail_create` and `mail_list_open` (0x8018B810) |
| [game/8018D2DC](../src/game/8018D2DC.c) | mod.c | `mod_setup..mod_npcrec_move_end` @0x8018F958 (30) | likely | assert from `mod_setup` to `mod_create` (0x8018D5F8) |
| [game/8018FA18](../src/game/8018FA18.c) | object.c | `object_load_aset..object_deliver_area_events` @0x80194FAC (39) | likely | assert from `object_load_aset` to `object_iff_open` (0x80192380) |
| [game/80195098](../src/game/80195098.c) | unknown | `player_check_ground..player_update_view` @0x80195BC8 (4) | likely | gp cut: `player_pick_trigger_hook` is read with `lui` before, through `gp` from here |
| [game/80195DF0](../src/game/80195DF0.c) | unknown | `player_try_slide..player_update_map` @0x8019A3E8 (33) | likely | jtbl cut |
| [game/8019A5D4](../src/game/8019A5D4.c) | roadmap.c | `roadmap_init..roadmap_cmp_weapon_level` @0x801A216C (33) | likely | assert in `roadmap_init` |
| [game/801A217C](../src/game/801A217C.c) | sound.c | `sound_se_push..sound_footstep_reset` @0x801A3DBC (21) | likely | assert from `sound_se_push` to `sound_bgm_create` (0x801A3AA0) |
| [game/801A3DD4](../src/game/801A3DD4.c) | sprite.c | `sprite_create..sprite_thing_update_fly_in` @0x801A742C (42) | likely | assert in `sprite_create` |
| [game/801A7560](../src/game/801A7560.c) | thing.c | `thing_update_all..thing_train_update` @0x801A9EA4 (29) | guess | first assert in `thing_create` (0x801A7A04); the cut is the first one the rodata allows before it, so `thing_update_all` may still be sprite.c's |
| [game/801AA360](../src/game/801AA360.c) | vehicle.c | `vehicle_car_drive..vehicle_train_init_state` @0x801AC9B4 (28) | guess | end proven (Sony code after); first assert in `vehicle_create` (0x801AC158), the cut is the last one the rodata allows before it |
| *psyq/801AC9D0* | Sony: LIBAPI, LIBC, LIBC2, LIBCARD, LIBCD, LIBETC, LIBGPU, LIBGS, LIBGTE, LIBMATH, LIBMCRD, LIBSN, LIBSND, LIBSPU | `DeliverEvent.._ExitCard` | | |
| [kaj/801CBCE0](../src/kaj/801CBCE0.c) | event.c | `kaj_event_queue_grow..kaj_event_done` @0x801CC734 (11) | proven | Sony code on both sides; assert in `kaj_event_queue_grow` and `kaj_event_init` (0x801CC68C) |
| *psyq/801CC768* | Sony: LIBAPI | `calloc3..malloc3` | | |
| [kaj/801CC898](../src/kaj/801CC898.c) | kaj.c | `kaj_malloc..kaj_init` @0x801CC8F0 (2) | proven | Sony code on both sides; assert in `kaj_init` |
| *psyq/801CC9F4* | Sony: LIBAPI, LIBETC, LIBMCRD | `PadInit..MemCardEnd` | | |
| [kaj/801CCAF4](../src/kaj/801CCAF4.c) | ll.c, misc.c | `kaj_ll_create..kaj_srand_ticks` @0x801CD808 (17) | proven | Sony code on both sides; asserts of ll.c in `kaj_ll_*`, of misc.c in `kaj_tmd_load` (0x801CD028) and `kaj_tmd_map` |
| *psyq/801CD850* | Sony: LIBAPI, LIBGS, LIBSND, LIBSPU | `exit..SpuSetCommonAttr` | | |
| [kaj/801CF790](../src/kaj/801CF790.c) | tim.c | `kaj_tim_load..kaj_tim_upload_hdr` @0x801CFBB4 (4) | proven | Sony code on both sides; assert in `kaj_tim_load` |
| *psyq/801CFC20* | Sony: LIBGPU, LIBGS | `GetTPage..GsGetTimInfo` | | |
| [kaj/801CFD70](../src/kaj/801CFD70.c) | timer.c | `kaj_timer_handler..kaj_timer_disable` @0x801D06C4 (9) | proven | Sony code on both sides; assert in `kaj_timer_add_alarm` (0x801CFEB0) and `kaj_timer_init` |
| *psyq/801D06D0* | Sony: LIBAPI | `realloc3.._memmove` | | |
| [kaj/801D0880](../src/kaj/801D0880.c) | unknown | `kaj_tod_set_packet..kaj_tod_set_frame` @0x801D1088 (7) | proven | Sony code on both sides; no assert |
| *psyq/801D1138* | Sony: LIBGTE | `TransMatrix..ScaleMatrix` | | |
| [kaj/801D12A8](../src/kaj/801D12A8.c) | tss.c, view.c | `kaj_tss_free..kaj_view_clear_vram` @0x801D1BD4 (17) | proven | Sony code on both sides; assert in `kaj_tss_init` (0x801D164C) and `kaj_view_init` (0x801D17F0) |
| *psyq/801D1C20* | Sony: LIBGPU, LIBGS, LIBGTE | `SetDefDrawEnv..SetGeomScreen` | | |
| [kaj/801D1E70](../src/kaj/801D1E70.c) | cdmgr.c and more | `kaj_cdmgr_init..kaj_map_cell_changed` @0x801D72F4 (78) | proven | Sony code before, end of .text after; cdmgr.c asserts up to `kaj_cdmgr_pool_size` (0x801D2E48) |

The asserted names run in alphabetical order: action, block, door, effect, event, mail, mod, object, roadmap, sound,
sprite, thing, vehicle in the game, and event, kaj, ll, misc, tim, timer, tss, view in the kaj units, with cdmgr.c
last. The kaj file-name strings also sit in .sdata in that order. A unit without an assert therefore most likely
holds a file whose name sorts between its neighbours'. The `npc_`, `ai_`, `menu_`, `text_` and `player_` prefixes
are labels for what the code does, not file names: `menu_` and `text_` do not sort between block and door.

## Files without an assert inside units

| Unit | Functions | What points to another file |
| --- | --- | --- |
| game/80179848 | `block_free` (0x8017CCE4) to `block_bus_run` | no assert after `block_create`, a long run of town and building loop code |
| game/8017EBF8 | `door_setup` (0x801844D4) to `door_exec_command` | they set up, move and command the `Door` records that door.c creates and keeps in `door_list`; door.c may start here |
| game/80185A60 | `effect_weapon_draw_panel` (0x80187718) to `effect_item_find` | the weapon and item inventories, no assert; a name between effect and event would fit |
| game/8018ACAC | `main` (0x8018BDE8) to `mail_menu_get_entry` | the entry point and the scene loop step; `main` sorts after `mail` and before `mod`, so a main.c here fits the alphabet |
| game/8018FA18 | `object_load_scene` (0x801926B4) to `object_deliver_area_events` | no assert after `object_iff_open`; the office scene loop (`object_room_*`) |
| kaj/801CCAF4 | `kaj_ll_*` then `kaj_tmd_load` | ll.c ends and misc.c starts between `kaj_ll_at_tail` (0x801CD000) and `kaj_tmd_load` |
| kaj/801D12A8 | `kaj_tss_*` then `kaj_view_*` | tss.c ends and view.c starts between `kaj_tss_set_steps` (0x801D1774) and `kaj_view_init` |
| kaj/801D1E70 | `kaj_heap_*` (0x801D3764) and `kaj_map_*` (0x801D3B7C to the end) | no assert after cdmgr.c's functions; two prefixes, and heap and map both sort after cdmgr |

The unit kaj/801D0880 sits between timer.c and tss.c, so its file name sorts between those two; its functions carry
a `kaj_tod_` label.

## What the layout study still has to settle

- The names of the five game units without an assert, and of kaj/801D0880.
- The real start of each assert file: an assert proves a function belongs to its file, not that the file starts
  there. door.c, thing.c and vehicle.c are the open cases above.
- Whether the runs without an assert listed above are files of their own, and where each one starts.
- How .data, .sdata and .bss are shared between the units: the split keeps each as one block (`main`).
