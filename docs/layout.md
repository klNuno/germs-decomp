# Source file layout

The executable links the game's own source files first, then the Sony libraries with the developer's own small
library (the `kaj_` functions) placed between Sony objects. The code is split into the 36 source files the
original programmers most likely had: 24 in `src/game` and 12 in `src/kaj`, with 8 runs of Sony code between
them (asm, never decompiled). Each file holds its functions in address order; the files sit in link order. The
plan is `config/layout.tsv`; `tools/split_units.py docs` writes this page from it, and
`tools/split_units.py apply` replays the split from the address units of commit 4efff08.

Confidence, for the two ends of a file: **proven** means a Sony object sits on both sides, so no other cut is
possible; **likely** means each end rests on an assert, a jump-table alignment, a change in `gp` use, the .rodata
order or a deferred inline tail (below); **guess** means the binary allows another cut, and the row says which.

36 files: 5 proven, 23 likely, 8 guess.

## Files in link order

| File | Functions | Confidence | Evidence |
| --- | --- | --- | --- |
| [`game/action.c`](../src/game/action.c) | `action_cmd_change_scene..action_run_npc_event` @0x80173054 (19) | likely | start of .text; assert in action_load_set; npc jump tables sit at 4 mod 8 against action's at 0 mod 8, so a new object starts in (action_load_set, npc_update_anim]; action_flush_queue is inlined in action_reset and emitted after it, so action.c runs past it; cut at the prefix change (unit cut) |
| [`game/actor.c`](../src/game/actor.c) | `npc_update_anim..npc_find_stats` @0x8017546C (15) | likely | start: jtbl parity (action.c); end: ai_door_noise and ai_weapon_noise (initialized .sdata) are read with lui in npc_update_all and through gp in ai_find_target, so a file starts in (npc_update_all, ai_find_target]; cut at the prefix change (unit cut). Name: no assert; the NPC records (animation, commands, damage, bodies, stats); it must sort between action and ai, npc.c would not |
| [`game/ai.c`](../src/game/ai.c) | `ai_check_line..ai_in_aim_cone` @0x801768F8 (16) | likely | start: gp cut (actor.c); end: block's jump table at 0 mod 8 after ai's at 4 mod 8, so a new object starts in (ai_fire, block_setup]. Name: no assert; the NPC behaviour (targets, moves, fire); sorts between actor and block |
| [`game/block.c`](../src/game/block.c) | `block_setup..block_enter_area` @0x80179848 (33) | likely | assert from block_setup to block_create; block_arena_init, block_create, block_free, block_free_all and block_model_surface are inlined in earlier functions and emitted after them (deferred inline tail); end exact: block_area_flames (initialized .sdata) is read through gp in block_set_mode and block_enter_area, and block_on_effect_done's strings follow block.c's jump table |
| [`game/building.c`](../src/game/building.c) | `block_on_effect_done..block_bus_run` @0x8017D604 (9) | likely | start exact (block.c); end: the card strings at 4 mod 8 follow building's jump table (block_building_load) at 0 mod 8, so a new object starts in (block_building_load, menu_card_init_slots]; cut at the prefix change. Name: no assert; the building scene loop, its input and the elevator; sorts between block and card |
| [`game/card.c`](../src/game/card.c) | `menu_card_init_slots..menu_card_run` @0x8017EBF8 (9) | guess | start: building.c; end: text_show_profile's string follows card's jump tables, so a new object starts in (menu_card_process, text_show_profile]; the cut after menu_card_run is a guess, the pause menu may belong here. Name: no assert; the memory card screen (scan, load, save); sorts between building and door |
| [`game/dialog.c`](../src/game/dialog.c) | `menu_list_page..text_narration_cues` @0x80180B04 (27) | guess | start: card.c; end: text_wait_step is inlined in text_start_typing and text_exec_command and emitted after them (deferred inline tail), door_setup is not inlined anywhere and door_list is read through gp from door_refresh_all on, as in door.c. Name: no assert; the pause menu pages and the text windows; menu.c and text.c would sort after door, dialog.c sorts between card and door; the pause menu may be a file of its own |
| [`game/door.c`](../src/game/door.c) | `door_setup..door_fade_step` @0x801844D4 (19) | likely | start: dialog.c's deferred inline tail ends before door_setup; door_list through gp in door_refresh_all, door_update_all, door_exec_command and door_add..door_set_visible; assert in door_create (lines 35 and 54); end: effect_start_sprite_slide asserts effect.c |
| [`game/effect.c`](../src/game/effect.c) | `effect_start_sprite_slide..effect_item_find` @0x80185A60 (50) | likely | assert from effect_start_sprite_slide to effect_flame_large_init; effect_weapon_add is inlined in effect_weapon_swap_stock and emitted after it (deferred inline tail); end: event_open's strings follow effect.c's jump tables, so a new object starts in (effect_inventory_has_room, event_open]. The weapon and item part (effect_weapon_unequip on) could be a file of its own sorting between effect and event; no cut shows |
| [`game/event.c`](../src/game/event.c) | `event_open..event_advance_clock` @0x8018920C (22) | likely | assert in event_open (lines 52 to 61); the event hooks are reached through gp here and with lui in block.c, main.c and object.c; event_draw_gauge and event_draw_percent_gauge are inlined in event_update_hud and event_draw_hud (deferred inline tail); end: mail strings at 4 mod 8 follow event's jump tables at 0 mod 8, so a new object starts in (event_drain_gauge, mail_create]. The HUD part (event_drain_gauge on) could be a file of its own (hud.c sorts between event and mail); no cut shows |
| [`game/mail.c`](../src/game/mail.c) | `mail_create..mail_is_read` @0x8018ACAC (12) | guess | asserts in mail_create (line 59) and mail_list_open (line 362); end: main is a file of its own only by its name; mail_main_restarted, main's .sdata flag, sits after mail.c's file name string and before mod.c's |
| [`game/main.c`](../src/game/main.c) | `main..mail_exp_for_level` @0x8018BDE8 (11) | guess | start: main; the angle, wait and scene change helpers after it share one deferred inline tail (mail_wrap_angle is inlined in mail_angle_to_dir8 and mail_angle_to_dir4 and emitted between them); end: menu.c. Name: main sorts between mail and mod |
| [`game/menu.c`](../src/game/menu.c) | `mail_menu_draw_item_name..mail_menu_get_entry` @0x8018C864 (9) | likely | start: mail_menu_draw_item_name is a normal function (called by mail_menu_draw, not inlined) after main.c's deferred inline tail, so a file starts in (mail_angle_to_dir4, mail_menu_draw_item_name]; end: mod_setup asserts mod.c. Name: no assert; the list menu shared by items, weapons, the shop and storage; sorts between main and mod |
| [`game/mod.c`](../src/game/mod.c) | `mod_setup..mod_finish_handler` @0x8018D2DC (17) | likely | assert from mod_setup (lines 142 to 160) to mod_create; mod_alloc (line 86) and mod_free are inlined in earlier functions and emitted after mod_update_all: deferred inline tail from mod_alloc; end: npc.c |
| [`game/npc.c`](../src/game/npc.c) | `mod_place_npcrec..mod_npcrec_move_end` @0x8018E8B8 (13) | likely | start: mod_place_npcrec is a normal function (called by jal from the functions after it), so it cannot follow mod.c's deferred inline tail: a file starts in (mod_free, mod_place_npcrec]; cut at the prefix change; end: object_load_aset asserts object.c. Name: no assert; the NPC record table (place, move, command, draw); sorts between mod and object |
| [`game/object.c`](../src/game/object.c) | `object_load_aset..object_room_play_call` @0x8018FA18 (38) | likely | assert from object_load_aset (line 141) to object_iff_open (lines 682 to 693); end: player_pick_trigger_hook is read with lui in object_room_init and object_room_quit and through gp in player_check_ground; object_deliver_area_events reads player_area_leave_pending through gp and that flag sits in .sbss after player_slide_dx, so it goes with player.c. The office loop (object_room_*) could be a file of its own (office.c sorts between object and player); no cut shows |
| [`game/player.c`](../src/game/player.c) | `object_deliver_area_events..player_update_map` @0x80194FAC (38) | likely | start: object.c; player_blocked_by_area and player_blocked_by_trigger (initialized .sdata) are read through gp by player_check_ground and player_move_on_foot, so the unit cut at player_try_slide is not a file change, and player's jump tables at 4 mod 8 match its .rodata start; player_add_hp is inlined in player_exec_command (deferred inline tail); end: roadmap strings at 0 mod 8 follow player's jump tables at 4 mod 8, so a new object starts in (player_weapon_sound, roadmap_init]. Name: no assert; the controlled character; sorts between object and roadmap |
| [`game/roadmap.c`](../src/game/roadmap.c) | `roadmap_init..roadmap_add_flash_quad` @0x8019A5D4 (20) | likely | assert in roadmap_init (line 32); roadmap_add_flash_quad is inlined in roadmap_draw_flash and emitted after it (deferred inline tail); end exact: shop.c |
| [`game/shop.c`](../src/game/shop.c) | `roadmap_shop_pick_weapons..roadmap_cmp_weapon_level` @0x801A0820 (13) | likely | start exact: roadmap_shop_pick_weapons and the functions after it are normal functions (called by jal) after roadmap.c's deferred inline tail; roadmap_shop_topic is read through gp only here (lui in building.c); end: sound strings follow the shop jump table (roadmap_shop_open_menu), so a new object starts in (roadmap_shop_open_menu, sound_se_push]. Name: no assert; the weapon shop; sorts between roadmap and sound |
| [`game/sound.c`](../src/game/sound.c) | `sound_se_push..sound_footstep_reset` @0x801A217C (21) | likely | assert from sound_se_push (line 209) to sound_bgm_create; sound_se_alloc_header (line 153) is emitted after sound_se_push: deferred inline tail from it; end: sprite_create asserts sprite.c (line 34) |
| [`game/sprite.c`](../src/game/sprite.c) | `sprite_create..sprite_phone_save_exit` @0x801A3DD4 (37) | likely | assert in sprite_create (line 34); the strings of sprite_phone_on_effect_done and sprite_phone_on_enter come before those of sprite_phone_update, which is emitted first: deferred inline tail; end: thing_list is read through gp from sprite_thing_refresh_all on, as in thing.c. The title, station and phone parts could be files of their own (station.c would sort between sprite and thing, title.c and phone.c would not); no cut shows |
| [`game/thing.c`](../src/game/thing.c) | `sprite_thing_init..thing_cmd_set_active` @0x801A6C34 (18) | likely | start: sprite.c; thing_update_all's jump table follows thing_create's strings in .rodata, so thing_update_all is thing.c's (proven), and thing_create (lines 38 and 51) is emitted after it: deferred inline tail; the marker functions (sprite_thing_*) are thing.c's by thing_list; end: thing_field_task_hook's string follows thing.c's jump table, so a new object starts in (thing_create, thing_field_task_hook] |
| [`game/town.c`](../src/game/town.c) | `thing_field_task_hook..thing_game_loop` @0x801A8370 (11) | guess | start: thing.c; end: thing_car_exit_prompt_on and thing_car_speed_div (.sbss) are read through gp by thing_car_init and vehicle_car_drive, so the per-vehicle hooks after thing_game_loop go with vehicle.c, which calls them; the .rodata allows any cut up to vehicle_create. Name: no assert; the town field loop; field.c would break the order, town sorts between thing and vehicle |
| [`game/vehicle.c`](../src/game/vehicle.c) | `thing_train_calc_stops..vehicle_train_init_state` @0x801A910C (33) | guess | start: town.c; vehicle_create's strings (lines 100 and 108) come first in vehicle.c's .rodata but the function is emitted late: deferred inline tail from vehicle_create; end proven (Sony code after) |
| *psyq/801AC9D0* | `DeliverEvent.._ExitCard` | | Sony: LIBAPI, LIBC, LIBC2, LIBCARD, LIBCD, LIBETC, LIBGPU, LIBGS, LIBGTE, LIBMATH, LIBMCRD, LIBSN, LIBSND, LIBSPU |
| [`kaj/event.c`](../src/kaj/event.c) | `kaj_event_queue_grow..kaj_event_done` @0x801CBCE0 (11) | proven | Sony code on both sides; asserts in kaj_event_queue_grow and kaj_event_init |
| *psyq/801CC768* | `calloc3..malloc3` | | Sony: LIBAPI |
| [`kaj/kaj.c`](../src/kaj/kaj.c) | `kaj_malloc..kaj_init` @0x801CC898 (2) | proven | Sony code on both sides; assert in kaj_init |
| *psyq/801CC9F4* | `PadInit..MemCardEnd` | | Sony: LIBAPI, LIBETC, LIBMCRD |
| [`kaj/ll.c`](../src/kaj/ll.c) | `kaj_ll_create..kaj_ll_at_tail` @0x801CCAF4 (8) | likely | start proven (Sony code before); asserts of ll.c in kaj_ll_create, kaj_ll_insert_before and kaj_ll_insert_after; misc.c's strings follow, so the cut lies in (kaj_ll_insert_after, kaj_tmd_load], at the prefix change |
| [`kaj/misc.c`](../src/kaj/misc.c) | `kaj_tmd_load..kaj_srand_ticks` @0x801CD028 (9) | likely | asserts of misc.c in kaj_tmd_load and kaj_tmd_map; end proven (Sony code after) |
| *psyq/801CD850* | `exit..SpuSetCommonAttr` | | Sony: LIBAPI, LIBGS, LIBSND, LIBSPU |
| [`kaj/tim.c`](../src/kaj/tim.c) | `kaj_tim_load..kaj_tim_upload_hdr` @0x801CF790 (4) | proven | Sony code on both sides; assert in kaj_tim_load |
| *psyq/801CFC20* | `GetTPage..GsGetTimInfo` | | Sony: LIBGPU, LIBGS |
| [`kaj/timer.c`](../src/kaj/timer.c) | `kaj_timer_handler..kaj_timer_disable` @0x801CFD70 (9) | proven | Sony code on both sides; asserts in kaj_timer_add_alarm and kaj_timer_init |
| *psyq/801D06D0* | `realloc3.._memmove` | | Sony: LIBAPI |
| [`kaj/tod.c`](../src/kaj/tod.c) | `kaj_tod_set_packet..kaj_tod_set_frame` @0x801D0880 (7) | proven | Sony code on both sides; no assert. Name: plays TOD animation packets (PSY-Q TOD format); tod sorts between timer and tss |
| *psyq/801D1138* | `TransMatrix..ScaleMatrix` | | Sony: LIBGTE |
| [`kaj/tss.c`](../src/kaj/tss.c) | `kaj_tss_free..kaj_tss_set_steps` @0x801D12A8 (10) | likely | start proven (Sony code before); assert in kaj_tss_init; view.c's strings follow, so the cut lies in (kaj_tss_init, kaj_view_init], at the prefix change |
| [`kaj/view.c`](../src/kaj/view.c) | `kaj_view_init..kaj_view_clear_vram` @0x801D17F0 (7) | likely | assert in kaj_view_init; end proven (Sony code after) |
| *psyq/801D1C20* | `SetDefDrawEnv..SetGeomScreen` | | Sony: LIBGPU, LIBGS, LIBGTE |
| [`kaj/cdmgr.c`](../src/kaj/cdmgr.c) | `kaj_cdmgr_init..kaj_cdmgr_free_data` @0x801D1E70 (29) | guess | start proven (Sony code before); asserts of cdmgr.c up to kaj_cdmgr_pool_size, whose line 137 comes before kaj_cdmgr_init's 168: deferred inline tail; end: the .sdata of cdmgr, heap and map lie in that order and no gp symbol crosses; the heap functions may still be cdmgr.c's tail |
| [`kaj/heap.c`](../src/kaj/heap.c) | `kaj_heap_alloc..kaj_heap_free_all` @0x801D3764 (10) | guess | no assert; kaj_heap_unused_* (.sdata) are read only here; called only from cdmgr.c, may be part of it. Name: the pool heap; cdmgr.c already breaks the kaj alphabet, and cdmgr, heap, map sort in order as a second group |
| [`kaj/map.c`](../src/kaj/map.c) | `kaj_map_load_city_dir..kaj_map_cell_changed` @0x801D3B7C (39) | likely | start: kaj_map_cell_exists and the map functions after it are normal functions after cdmgr.c's deferred inline tail, so a file starts in (kaj_cdmgr_pool_size, kaj_map_cell_exists]; cut at the prefix change; map strings follow cdmgr.c's; end of .text after. Name: the city and place map streamer; sorts after heap |

## Rodata

A C file emits its strings and constants first and its jump tables after the function bodies;
`INCLUDE_RODATA` lines place the symbols that are not migrated into a function. Each `.rodata` entry of
`config/splat.yaml` starts at the first symbol the file's code uses and names that file. menu.c, npc.c and
heap.c have none.

| ROM offset | Address | File |
| --- | --- | --- |
| 0x800 | 0x80170000 | `game/action.c` |
| 0x93C | 0x8017013C | `game/actor.c` |
| 0x9F4 | 0x801701F4 | `game/ai.c` |
| 0xA50 | 0x80170250 | `game/block.c` |
| 0xB08 | 0x80170308 | `game/building.c` |
| 0xC1C | 0x8017041C | `game/card.c` |
| 0xCF0 | 0x801704F0 | `game/dialog.c` |
| 0xD04 | 0x80170504 | `game/door.c` |
| 0xD44 | 0x80170544 | `game/effect.c` |
| 0x1080 | 0x80170880 | `game/event.c` |
| 0x122C | 0x80170A2C | `game/mail.c` |
| 0x1268 | 0x80170A68 | `game/main.c` |
| 0x1280 | 0x80170A80 | `game/mod.c` |
| 0x1358 | 0x80170B58 | `game/object.c` |
| 0x16DC | 0x80170EDC | `game/player.c` |
| 0x1820 | 0x80171020 | `game/roadmap.c` |
| 0x1848 | 0x80171048 | `game/shop.c` |
| 0x1EEC | 0x801716EC | `game/sound.c` |
| 0x1FF4 | 0x801717F4 | `game/sprite.c` |
| 0x21BC | 0x801719BC | `game/thing.c` |
| 0x2228 | 0x80171A28 | `game/town.c` |
| 0x2278 | 0x80171A78 | `game/vehicle.c` |
| 0x3334 | 0x80172B34 | `kaj/event.c` |
| 0x3374 | 0x80172B74 | `kaj/kaj.c` |
| 0x3398 | 0x80172B98 | `kaj/ll.c` |
| 0x34A8 | 0x80172CA8 | `kaj/misc.c` |
| 0x3688 | 0x80172E88 | `kaj/tim.c` |
| 0x36D8 | 0x80172ED8 | `kaj/timer.c` |
| 0x3750 | 0x80172F50 | `kaj/tod.c` |
| 0x3774 | 0x80172F74 | `kaj/tss.c` |
| 0x3794 | 0x80172F94 | `kaj/view.c` |
| 0x37D0 | 0x80172FD0 | `kaj/cdmgr.c` |
| 0x37F8 | 0x80172FF8 | `kaj/map.c` |

## How the boundaries were found

| Source | What it shows | Strength |
| --- | --- | --- |
| Sony objects between kaj code in .text | A file boundary on each side | Proven |
| Asserts | A function passes its source file name to `kaj_abend` (with a line number), so it belongs to that file. The 13 asserted game names and the 9 asserted kaj names are kept. | Proven for the function, not for the file's ends |
| Jump-table parity | GCC 2.8.1 aligns every jump table to 8 bytes inside its object and the link keeps 4-byte alignment, so a jump table at 4 mod 8 from its file's .rodata start proves that a new object starts before it. | Proven where it applies |
| Rodata order | Within a file, strings come before jump tables, so a string after a jump table starts a new file. | Proven where it applies |
| gp access | maspsx reaches through gp only the small globals a file defines. An initialized .sdata symbol is reached through gp only in its one defining file, and a file never mixes gp and `lui` access to the same symbol. | Proven for .sdata; for .sbss it assumes no shared `.comm` |
| Deferred inline tails | GCC 2.8.1 emits a non-static inline function at the end of its file, so a normal function after a deferred one starts a new file. | Proven where it applies |
| Equal literals | cc1 merges identical string literals in one file: two stored copies mean two files. | Proven |
| Names | The asserted names run in alphabetical order (action, block, door, effect, event, mail, mod, object, roadmap, sound, sprite, thing, vehicle; event, kaj, ll, misc, tim, timer, tss, view, then cdmgr), so a file without an assert gets a name that sorts between its neighbours'. | Convention |

`work/layout/check.py` tests the plan against these rules (gp users, gp and `lui` mixes, .rodata ownership and
order, pointer-table users, strings after jump tables, .data and .sdata order, duplicate literals, jump-table
parity) and reports no violation over 206 rodata symbols. `make check` cannot judge a layout by itself: any cut
matches as long as each file declares the gp symbols it uses (rule 1 below).

## Open doubts

1. card/dialog: the cut after `menu_card_run` is a guess, and the pause menu (`menu_list_page` on) might be
   card.c's tail or a file of its own. menu.c and text.c would sort after door, so the text windows were named
   dialog.c to keep the order.
2. mail/main: main.c is a file only because of its name. `mail_main_restarted`, main's .sdata flag, sits after
   mail.c's file name string, which fits but does not prove it.
3. effect.c is large (50 functions): the weapon and item part (`effect_weapon_unequip` on) could be a file of its
   own sorting between effect and event; no cut shows it.
4. event.c's HUD part (`event_drain_gauge` on) could be hud.c, between event and mail; no cut shows it.
5. object.c's office loop (`object_room_*`) could be office.c, between object and player; no cut shows it.
6. sprite.c holds the title, station and phone screens. station.c would sort between sprite and thing; title.c
   and phone.c would break the order.
7. town/vehicle: the .rodata allows any cut up to `vehicle_create`. The cut at `thing_train_calc_stops` follows
   the gp users of `thing_car_exit_prompt_on` and `thing_car_speed_div`, which are .sbss and so not proof.
8. heap.c may be cdmgr.c's tail: its functions are called only from cdmgr.c, and its .sdata is read only by itself.
9. actor.c against npc.c: both hold NPC code. The first must sort between action and ai, so it cannot be npc.c.
10. `text_type_step` has no visible reference (no caller, no table); its file follows only from its position.

## Headers

- Every file has a header, `include/game/<file>.h` or `include/kaj/<file>.h`, that declares what other files call
  or a data table names. A prototype is the definition line of its function, parameter names included.
- A type used by five files or fewer lives in the header of the file that owns its records, or in the one `.c`
  file that uses it. `include/game/types.h` keeps the 29 types used by six files or more. `GsDobj2` stays in
  src/game/block.c, the only file that reads it, because its `tmd` field is the game's `TmdObject` view.
  `TmdObject` and `TmdTri` sit in include/game/block.h because mod.c reads `TmdObject` too.
- Sony functions are declared in `include/psyq/<lib>.h`: libapi, libc (LIBC2 and LIBC), libcd, libetc, libgpu,
  libgs, libgte, libmcrd and libsnd. The Sony layouts the game reads keep our names there: `GsCoordinate2` in
  libgs.h, `SVector` in libgte.h, `Rect` in libgpu.h and `CdLoc` in libcd.h. A parameter that only a game view
  describes is `void *`. block.c declares `__nedf2` itself because it calls it by hand.
- A file includes `common.h`, then its own header, then the headers of the files it uses. The prototypes left in
  a `.c` file are forward declarations of its own helpers, plus the exceptions below. The `extern` declarations
  of data stay in each file that reads them, because the data lives in asm.
- 29 functions are not in their header and stay declared in each calling file. For 27 of them the callers
  declare other argument or return widths, and one shared prototype changed their bytes. Each function was tried
  on its own with `tools/unit_check.sh`. Those 27 are action_run_npc_event, action_run_trigger_enter,
  action_run_trigger_leave, effect_inventory_has_room, effect_item_add, effect_item_remove, effect_weapon_add,
  effect_weapon_input, kaj_ll_at_tail, kaj_map_city_ready, kaj_map_load_city_dir, kaj_map_load_place_dir,
  mail_angle_to_dir8, mail_check_schedule, mail_goto_building, mail_take_scene_change, mod_set_anim_by_id,
  player_set_item, player_set_weapon, player_take_hit, roadmap_get_state, sprite_copy_cell,
  sprite_phone_save_exit, text_show, text_show_profile, text_show_timed and thing_run_script. The other two,
  kaj_tim_load and kaj_tim_free, name a `TimHandle` that two files define differently. Each header lists its own
  exceptions in a closing comment.
- A function that no other file references by symbol is `static` (205 of them). That includes the eight
  primitive handlers roadmap_draw_f3 to roadmap_draw_gt4: roadmap_init_draw stores them in
  `roadmap_prim_handlers` at run time, and Sony's `GsSortObject4J` calls them through that table, never by
  name. A function that nothing references stays global too: cc1 could drop a
  `static` copy of an inline function.
- The Makefile does not track headers. After editing one, run `rm -rf build/src` and then `make check`.

## Rules for contributors

1. **A small global (8 bytes or less) reached through gp is declared without `extern` in every file that uses
   it**, as a tentative definition (`s16 action_blink_count;`). cc1 emits `.comm`, maspsx reaches it through gp,
   and the linker merges it with the asm data. An `extern` gives `lui` accesses and shifts the whole executable.
   Never move such a declaration into a header with `extern`.
2. **No `static` variable while the data lives in asm**: it would allocate bytes in the C object and duplicate
   the data. A function is `static` when no other file names it and no data points to it. `static` keeps the
   bytes but changes the relocations, so `tools/unit_check.sh --save` must run again after one is added or
   removed.
3. A file with rodata keeps its `.rodata` entry in `config/splat.yaml` (dot form, same name); an
   `INCLUDE_RODATA` or `INCLUDE_ASM` path names `asm/nonmatchings/<dir>/<file>`. After renaming a file, run
   `make split` twice: splat writes the `.s` only once the C file names it.
4. Keep functions in address order inside a file: cc1 emits in source order, apart from the deferred inline
   tails.
5. Two files may declare the same function with different parameter types on purpose (a caller that needs
   promoted arguments): a shared prototype must keep each caller's code, and `make check` decides (Headers).
6. **The build stays shiftable**: after `make check`, `.venv/bin/python -I tools/rawscan.py --max 0` must print
   `# 0 raw words`.
