# Boot and the main loop

When the console starts the game, `main` sets up the developer's own library (the kaj library),
creates the lists every scene fills, then loops over three kinds of scene: a room, a building and
the town. Each scene runs an event loop on one event queue, fed by a vertical blank timer, by tasks
and by the game's user events. How a scene loads is on [scenes and scripts](scenes-and-scripts.md);
the drawing of a frame is on [rendering](rendering.md).

## From main to the scene loop

[`main`](../../src/game/main.c) (0x8018BDE8, in src/game/main.c) runs:

1. `kaj_init` (0x801CC8F0, [kaj/kaj.c](../../src/kaj/kaj.c): kaj.c and misc.c).
2. Clears `object_scene_tables` (0x64 bytes) and the six event hooks: `event_alarm_hook`,
   `event_enter_hook`, `event_leave_hook`, `event_tick_hook`, `event_effect_done_hook` and
   `event_mod_finish_hook`.
3. Creates seven lists with `kaj_ll_create` (0x801CCAF4): `action_set_list`, `action_queue`,
   `block_list`, `door_list`, `mod_list`, `sprite_list` and `thing_list`.
4. `event_open` (0x8018920C) opens the game's user events, `roadmap_init_draw` (0x801A02C8)
   installs the primitive handlers ([rendering](rendering.md#the-town-renderer)) and
   `object_load_res(1, 0)` (0x80192B8C) loads RES.R entry 1, the common resources
   ([files and CD](files-and-cd.md#resr)).

Then an endless loop starts a new game each time round:

| Step | What it does |
| --- | --- |
| `action_vars` cleared | car speed and text speed kept when `mail_main_restarted` is set, else both set to 1 |
| `scene_request` cleared | 0x24 bytes; current and requested loop set to -1 |
| `player_init` (0x801971D4) | the player's status |
| start values | `vars[0x5F]` = 3; `vars[0xA..0xD]` and `vars[0x1B]` = 100; hour `vars[0x3E]` = 5, minute 0; the drain minute and count 0 |
| `effect_clear_alarms`, `vehicle_train_init_state` | the alarm slots and the train |
| `sprite_title_run` (0x801A5254) | the title screen, given `mail_main_restarted` |
| `kaj_srand_ticks` (0x801CD808) | seeds `rand` from the timer ticks; then the HUD: sprites 0x400 and 0x409, `event_draw_hud` (0x8018A24C) |

The inner loop runs while the back-to-title flag `scene_request.quit` is 0. It copies the
requested loop into the current one and calls one of three scene loops:

| Loop | Function | Place |
| --- | --- | --- |
| 0 | `object_room_run` (0x80194E5C, object.c) | a single scene such as the office (OFC.S) |
| 1 | `block_building_main` (0x8017E544, block.c) | a building made of blocks, with elevator rides between floors |
| 2 | `thing_game_loop` (0x801A9070, thing.c) | the town, on foot, in the car or on the train |

When the inner loop ends, `main` sets `mail_main_restarted` to 1 and goes round again to the
title. `player_finish_death` (0x80197688) sets the back-to-title flag when the dead player is not
infected; an infected player wakes up changed instead
([energy at 0](../discoveries.md#-energy-at-0-is-death-and-only-a-hit-to-the-head-makes-you-wake-up-changed)).

## The kaj start-up

`kaj_init` runs `ResetCallback`, `InitHeap3(0x80010000, 0x160000)`, `ResetGraph`, `ClearImage`
over 640 x 511, `PadInit` and `CdInit`; a failed `CdInit` ends in `kaj_abend` (0x801CD54C) with
"can't initialize CD-ROM subsystem". Then it starts the library's parts in this order:
`kaj_event_init`, `kaj_timer_init`, `kaj_tss_init`, `kaj_sound_init`, `kaj_view_init`, then
`MemCardInit(1)`, clears the pad words and turns the display on (`SetDispMask(1)`). `kaj_malloc`
(0x801CC898) is `malloc3` plus a clear to 0, NULL on failure. Most allocations use it and most
callers then stop in `kaj_abend` ("Error Allocating BLOCK Pointer"). Not all: `kaj_event_init` and
`kaj_timer_init` use `calloc3` (alarms grow with `realloc3`), `kaj_tmd_load` (0x801CD028) inlines
the report and `exit`, `kaj_cdmgr_init` (0x801D1E70) prints a line number and calls `exit(1)`.

The library keeps its state in `kaj_system` (0x801E6DA0, type `KajSystem`): the pad words
`pad_now` and `pad_prev`, `pad_mode` ([the pad](menus-text-and-save.md#the-pad)),
`timer_enabled`, `timer_ticks`, `timer_period` (600), `vsync_delta` (refreshes the last frame
took) and at +0x18 the music volume, 0x7F at start.

## The event queue

The kaj event queue is in [kaj/event.c](../../src/kaj/event.c). The queue is a ring of
`KajEvent` records of 0x14 bytes (type, tick stamp, three parameters), 0x40 at start, doubled by
`kaj_event_queue_grow` (0x801CBCE0) when full. `kaj_event_push` (0x801CC1E8) adds at the tail,
`kaj_event_push_front` (0x801CC2AC) at the head; both stamp the event with `timer_ticks`.
`kaj_event_get` (0x801CC378) pops the next event and runs task alarms itself (next section).
`kaj_event_set_alarm` (0x801CC3DC) takes a delay in ticks, an id and a data word: id 0 takes a
new id counting down from 0x3E9, delay 0 pushes the alarm at once, any other delay goes to the
timer. `kaj_event_flush` (0x801CC514) drops queued events by type mask and id, and
`kaj_event_done` (0x801CC734) releases the task of a finished-task event.

| Type | Event | Pushed by |
| --- | --- | --- |
| 0 | no event: run one frame | `kaj_event_get` when the queue is empty |
| 2 | alarm | `kaj_timer_handler` when an alarm is due |
| 4 | clock tick | `kaj_timer_handler` every `timer_period` ticks |
| 0x10 | enter an area | `object_deliver_area_events` (0x80194FAC) |
| 0x20 | leave an area | `object_deliver_area_events`, `player_leave_trigger` (0x80199FD8) |
| 0x100 | task finished | `kaj_event_run_tss`, `kaj_tss_kill` |
| 0x200 | model animation finished | `mod_finish_handler` (0x8018E7EC) |

Enter, leave and animation events start as user events opened by `event_open`: 0xF3000000 runs
`object_deliver_area_events`, 0xF3000001 `player_leave_trigger`, 0xF3000002 `mod_finish_handler`.
`player_check_ground` (0x80195098) delivers the first two, `mod_update_all` (0x8018DE58) the third.

## The timer and alarms

The timer is [kaj/timer.c](../../src/kaj/timer.c). `kaj_timer_init` (0x801D0300) opens
an event on root counter 3 (0xF2000003, the vertical blank counter) with `kaj_timer_handler`
(0x801CFD70), starts the counter and sets the period to 600. The handler counts one tick per
refresh, pushes every due alarm of its binary heap (capacity 8 at start, filled by
`kaj_timer_add_alarm`, 0x801CFEB0) as a type 2 event, at the front of the queue when the alarm id
is below 0x50, and pushes a type 4 every 600 ticks: one game minute every 10 seconds
([the clock](../discoveries.md#-the-clock-counts-minutes-and-stops-at-day-99)). Every scene loop
calls `kaj_timer_enable` (0x801D06B4) when it starts and `kaj_timer_disable` (0x801D06C4) when it
ends, so the clock stands still during loading.

## Tasks

Tasks are in [kaj/tss.c](../../src/kaj/tss.c), the screen in [kaj/view.c](../../src/kaj/view.c). A task is one of 16 `TssSlot`
records of 0x48 bytes that moves a value `cur` toward `target` by `step`, calling `on_step` each
time and `on_end` at the target. `kaj_tss_init` (0x801D164C) allocates the 16 slots ("Error
Allocating Sharing Table" on failure); `kaj_tss_alloc` (0x801D15C8) takes a free slot (0 when none
is left) with a data area, the slot itself up to 0x20 bytes or else a `kaj_malloc` block;
`kaj_tss_set_steps` (0x801D1774) computes `step` from a distance and a step count; `kaj_tss_start`
(0x801D14B8) arms alarm `index + 1` with a delay of 1 tick.

The task runs through the alarm: `kaj_event_get` hands every type 2 event whose id is 1 to 16
to `kaj_event_run_tss` (0x801CBDF0), which steps the task (by `step * vsync_delta` when the task's
delay is 2 and the delta below 11) and re-arms the alarm, or at the target calls `on_end`, moves
the slot to the done list and pushes a 0x100 event with the slot index and the task type.
`kaj_tss_kill` (0x801D137C) pushes the same event with a kill flag. Fades, slides, the music
fade and narration are tasks ([effects](rendering.md#effects)).

## One frame of the game

The scene loops share one shape, best read in `object_room_main` (0x80194780, object.c):
`object_room_init` installs the hooks, `kaj_timer_enable`, then a loop over `kaj_event_get`:

| Event | Answer |
| --- | --- |
| 2 | `event_handle_alarm` (0x80189928): the alarm slots, then `event_alarm_hook` |
| 0x10, 0x20 | `event_handle_enter` (0x80189350), `event_handle_leave` (0x801895E0) |
| 4 | `event_handle_tick` (0x80189970): `event_clock_tick`, then `event_tick_hook` |
| 0x200 | `event_handle_mod_finish` (0x801899AC): weapon states, then the hook |
| 0x100 | `event_handle_effect_done` (0x8018970C): its result ends the loop |
| 0 | input, scene change check, `object_room_check_calls`, one frame |

The clock is in src/game/event.c. `event_clock_tick` (0x8018AA00) adds a minute
(`event_clock_add_minute`), marks an energy drain when the minute modulo 10 equals the drain
minute ([energy](../discoveries.md#-energy-drains-faster-the-longer-you-stay-awake)) and updates
the daylight when its loop asks, as the building, station and town loops do
([fog](rendering.md#fog-and-the-time-of-day)). Scenes add handling through the hooks: the
station sets `event_tick_hook` to `sprite_station_update`, the train to `thing_train_tick_hook`.

`mail_step_frame(mode, a, b)` (0x8018C2FC) is one frame. It calls `action_update`; in modes 0 and
1 `npc_update_all`, `door_update_all` and `mod_npcrec_update_all`, in mode 2 `vehicle_update`;
then `mod_update_all`, `thing_update_all` and `player_update`; in modes 1 and 2 the flame and
colour cycle effects; and last `roadmap_draw_frame(mode)` (0x801A0418), which draws and flips.
`kaj_view_flip` (0x801D1AAC) waits with `VSync(2)` and stores the refreshes the frame took in
`vsync_delta`, which movement, turning and timers multiply by
([frame timing](../discoveries.md#-the-game-times-every-frame-so-a-slow-machine-makes-it-choppy-not-slow)).
`mail_wait` (0x8018C1B0) runs frames until the `vsync_delta` values add up to its last argument
times 30, answering events meanwhile.

## Changing place

A place change is a request in `scene_request` (0x801E0340):

| Field | Meaning |
| --- | --- |
| `loop`, `next_loop` | current and requested scene loop (0, 1, 2) |
| `scene_index` | scene index in SCE.S ([files and CD](files-and-cd.md#sces)) |
| `variant` | variant of the scene |
| `quit` | back to the title |
| `change` | set by a request, cleared when taken |
| `path`, `yaw`, `pos_x`, `pos_y`, `pos_z` | a scene file path the loader never opens ([scene files](../discoveries.md#-the-game-still-names-scene-files-the-disc-does-not-have)), arrival angle and position |

`mail_goto_ofc` (0x8018C414) asks for loop 0 and "\S\OFC.S;1", `mail_goto_twn` (0x8018C50C) for
loop 2 and "\S\TWN.S;1" with a position, `mail_goto_building` (0x8018C554) for loop 1 with a
three-letter name at +0x20 (`block_building_load` makes "\S\%s.S;1" of it) and a variant from a
game variable (0, 10, 1000, 2000 give 0, 2, 3, 4, other values 1). Scripts call them through
`action_cmd_change_scene` (0x80173054). `mail_take_scene_change` (0x8018C170) takes the `change`
flag each frame and resets the pad; the loop fades out, the finished fade (a 0x100 event) ends
the loop, and `main` reads the new requested loop.
