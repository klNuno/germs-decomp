# Scenes and scripts

<sub>[germs-decomp](../../README.md) / [Engine](README.md) / Scenes and scripts</sub>

Every place in Germs (the office, the town, each building, shop and station) is a scene of the file `SCE.S`. It
brings its own script: action sets that the code queues and runs one command per frame, area triggers drawn into the
floor, scene objects and doors, and the people of the place. This page follows a scene from the request that asks
for it to the commands its scripts send. The people themselves are in [people and combat](people-and-combat.md), the
town and buildings in [town and vehicles](town-and-vehicles.md).

**On this page:** [The scene request](#the-scene-request) · [Loading a scene](#loading-a-scene) · [Action sets](#action-sets) · [The action queue](#the-action-queue) · [Area triggers](#area-triggers) · [Scene objects and doors](#scene-objects-and-doors) · [Game variables](#game-variables)

## The scene request

One `SceneRequest` at 0x801E0340, `main_scene_request`, says which scene runs next. Three functions of
[main.c](../../src/game/main.c) fill it:

| Function | Loop | Scene index | Variant |
| --- | --- | --- | --- |
| `main_goto_ofc` (0x8018C414) | 0, the office (`\S\OFC.S`) | 0 | 0, or 1 for the arrest version (below) |
| `main_goto_twn` (0x8018C50C) | 2, the town (`\S\TWN.S`) | 1 | 0 |
| `main_goto_building` (0x8018C554) | 1, a building | from the door command | from the building's game variable |

The halfwords at +0 to +8 are: the loop running, the loop asked for, the scene index in `SCE.S`, the variant, and a
flag that ends the game and goes back to the title. Every request raises +0xA (`change`), which each scene loop
polls through `main_take_scene_change` (0x8018C170). `main` (0x8018BDE8) calls `object_room_run` (0x80194E5C,
office), `building_main` (0x8017E544, building) or `town_game_loop` (0x801A9070, town) until the end flag.

`main_goto_building` turns the building's variable into a variant: 0 gives 0, 10 gives 2, 1000 gives 3, 2000 gives
4, anything else 1.  `main_goto_ofc` asks for variant 1 when the kill counters of `PlayerStatus` reach 3, then 5
([arrests](../discoveries.md#-three-civilian-kills-get-you-arrested-and-five-more-the-second-time)), unless game
variable 48 is set or the player is changed.

## Loading a scene

`object_load_scene` (0x801926B4, [object.c](../../src/game/object.c)) is called by the enter
functions of the three loops: `object_room_init` (0x8019430C), `building_load` (0x8017DFA4) and
`town_enter` (0x801A88B4). It opens `SCE.S` through `object_iff_open` (0x80192380) and reads the scene's
directory sector. Entry 0 holds the data common to all variants with four counts (bodies, people records, weapons,
items), entry variant + 1 the variant's data with its own (people, triggers, action sets, stats).

`object_read_chunks` (0x80191AB0) then reads the entry chunk by chunk. The tag of each chunk picks its loader:

| Tag | Loader | What it makes |
| --- | --- | --- |
| `ASET` | `object_load_aset` (0x8018FA18) | the variant's action sets, through `action_load_set` |
| `BLCK` | `object_load_blck` (0x8018FC90) | a block ([town and vehicles](town-and-vehicles.md#town-blocks)) |
| `DOOR`, `THNG` | `object_load_door` (0x8018FED4), `object_load_thng` (0x80190FD8) | a door, a scene object |
| `MOD `, `MOE ` | `object_load_mod` (0x801905A0) | a model; with filter 0x400 only the two carried weapons |
| `MAIL`, `TIM `, `SPRT`, `TEXT`, `MIDI`, `VABH`, `VABB`, `VECL` | their `object_load_` function | mails and images (only the id the filter asks for), sprites, text, music, sound banks, the vehicle |
| `AREA`, `ACTR`, `NPC `, `CHAR`, `ENMY`, `ITEM`, `TXT `, `WEPN` | `object_load_other` (0x801907C8) | one table each in `object_scene_tables` |

Any other tag is skipped. `object_scene_tables` (`SceneTables`) keeps the tables of the running scene. Loading
`ACTR` also places the people (`action_init_npcs`, 0x8017519C). The file layer under all this is in [files and the
CD](files-and-cd.md).

## Action sets

An `ASET` chunk is a run of action sets. `action_load_set` (0x80173A44,
[action.c](../../src/game/action.c)) copies each one into an `ActionSet` and appends it to `action_set_list`:

| Part | Size | Content |
| --- | --- | --- |
| header | 0x38 | +0 set id, +2 logic (0 any condition, else all), +4 next set, +6 next mode, then four 12-byte `ActionCond` |
| count | 4 | number of actions |
| each action | size word, then 12 | opcode, sub, target (an `ActionCmd`), argc, then argc strings separated by NUL bytes |

Arguments stay strings; every handler converts them with `atoi`. The four conditions test a game variable twice, one
of the four `stat` words of `PlayerStatus`, and the inventory; each has an invert flag, or is unused. The first
three compare the value with a range `low..high`. The inventory test (`action_test_inventory`, 0x80173954) with
index 0 is true when one of the eight item slots holds exactly the item `low`; otherwise its loop reads only weapon
slot 1 (`weapon_ids[1]`) and tests it against `low..high`.

`action_run_set` (0x80173DE0) evaluates the conditions. If they pass (all unused, any true with logic 0, every used
one true otherwise), the set's actions go into the queue; next mode 1 or 2 then returns the next set, next mode 0 or
2 returns it when they fail. Callers loop on the returned set, so a chain of sets reads as if, else if.


## The action queue

`action_queue` is a `kaj_ll` list of pending actions. `action_update` (0x8017345C) runs from `main_step_frame`
(0x8018C2FC) once a frame, before anything else moves, and acts on `event_state.state`: 0 idle, 1 run the head
action, 2 a prompt waits for CIRCLE or CROSS, 3 a text page is full and its arrow (sprite 0x40A) blinks every 8
frames, 4 wait until every bit of `wait_flags` is clear. An empty queue calls `action_reset(1)` (0x80174840), which
puts the state back to 0. The opcode of the popped action picks its handler:

| Op | Handler | What it does |
| --- | --- | --- |
| 0 | in `action_update` | trigger: sub 0 sets its enter or leave set, 1 `enabled`, 2 the walk flag `passable` |
| 1 | `actor_exec_command` (0x80175CD8) | a person ([commands to people](people-and-combat.md#commands-from-scripts)) |
| 2 | `thing_cmd_set_active` (0x801A8264) | shows or hides a scene object |
| 3 | `sound_bgm_play` (0x801A3BCC) or `sound_bgm_fade_out(3)` (0x801A3CC0) | music, see [sound and music](sound-and-music.md) |
| 4 | `door_exec_command` (0x8018519C) | opens or closes a door |
| 5 | `dialog_exec_command` (0x801837F0) | text, narration and timed lines ([menus, text and save](menus-text-and-save.md)) |
| 6 | `action_cmd_change_scene` (0x80173054) | sub 0 office, 1 and 3 building (`main_goto_building`), 2 town |
| 7 | `npc_rec_cmd` (0x8018EED4) | the scripted figures of the `NPC ` table: show, move, animate |
| 8 | `player_exec_command` (0x80199034) | sub 0 item, 1 walk to a point, 2 weapon, 3 player flag 0x100, 4 energy |
| 9 | `sound_exec_command` (0x801A324C) | a note through `sound_se_play_note` (0x801A2C60) |
| 10 | `action_cmd_var` (0x80173250) | game variable arithmetic (below) |
| 11 | in `action_update` | sub 0 wait (argument times 2 frames), 1 call a set at the queue head, 10 the same without text and waits, 2 push kaj event 0x400 |
| 12 | `sprite_exec_command` (0x801A417C) | sprites |
| 13 | `mail_cmd_receive` (0x8018BD60) | a mail arrives (`mail_receive`, 0x8018BA48) |
| 14 | `roadmap_start_flash` (0x801A0690) | a coloured screen flash |

Sub 1 of opcode 11 sets `action_queue_front_flag`, so the called set's first action goes to the head of the queue
and runs next. When a set runs with `skip_text_wait`, its text actions (opcode 5) and waits (opcode 11 sub 0) are
dropped. `action_reset(0)`, which `event_handle_leave` (0x801895E0) calls when the player walks out of a trigger,
removes the same kinds from the queue, as `action_flush_queue(0)` (0x80174A14) does without touching the state.

`event_state` (`EventState`, 0x801DFFE8) holds the trigger being answered, the queue state, a flags word and a set
for each of CIRCLE and CROSS, and the wait timer and bits. `dialog_show` (0x80183E88) and `dialog_exec_command` sub 1
store the two sets and set state 2. In a building, `building_update_input` (0x8017DD70) runs `building_on_action`
(0x8017DAE8) on CIRCLE, which runs `circle_set`, and runs `cross_set` itself on CROSS when `cross_flags` has bit 2;
the office and the town do the same in `object_room_update_input` (0x80194140) and `town_input` (0x801A8768).
The wait bits:

| Bit | Set by | Cleared by |
| --- | --- | --- |
| 1 | opcode 11 sub 0 | `action_update` when the timer runs out |
| 4 | `door_exec_command` (last argument 1) | the door movers (`door_move_x`, 0x80184814, and the others) at the end of the move |
| 8 | `npc_rec_cmd` sub 4, animate a figure (argument 1 at 1) | `mod_finish_handler` (0x8018E7EC), when animation 2 ends |
| 0x10 | `npc_rec_cmd` sub 3, move a figure (last argument 1) | `npc_rec_move_end` (0x8018F958) |
| 0x20 | `player_exec_command` sub 1 (last argument 1) | `player_move_to_done` (0x8019A07C) |

## Area triggers

Triggers are painted into the floor. `block_hit_tris` (0x8017B1E8) and `block_hit_quads` (0x8017B3E8) return the
colour of the floor polygon under a point as a 24-bit code (red, green, blue), and `player_check_ground`
(0x80195098) reads the high byte as the kind and the code as the trigger id. A change of code is stored in
`player_area_current` and sent as a BIOS event (`DeliverEvent`, 0xF3000000 enter or 0xF3000001 leave, opened by
`event_open`, 0x8018920C). Its handler, `player_deliver_area_events` (0x80194FAC), pushes kaj events 0x20 (leave the
old one) and 0x10 (enter); each scene loop passes them to `event_handle_enter` (0x80189350) and `event_handle_leave`
([event.c](../../src/game/event.c)):

| Kind | Enter does |
| --- | --- |
| 0xFC | `action_run_npc_event` (0x801752F4): the person's talk set; set 0x400 for a dead person |
| 0xFD | `thing_run_script` (0x801A7ED4): the scene object's script (type in the high nibble of the id, number in the low 12 bits) |
| 0xFE | a bus stop line; before 05:00 the opening hours |
| 0xFF | the phone box line |
| 0x80 | `block_enter_area` (0x8017D574) |
| any other | `action_run_trigger_enter` (0x80174D6C): the `SceneTrigger` of that id runs its enter set |

A `SceneTrigger` (AREA record, 12 bytes) is `id`, `enter_set`, `leave_set`, a walk flag at +8 and `enabled`;
`player_check_ground` stops the player like a wall when the walk flag is 0 and ignores a disabled trigger.

## Scene objects and doors

A `Thing` (THNG chunk, [thing.c](../../src/game/thing.c)) is a model with a type, an id, `active`
and `animate` flags, an enter set at +0xC, a leave set at +0xE and an optional hit model. `thing_hit_test`
(0x801A7CF0) returns `id + (type << 12)` for the object a point touches, the code a 0xFD trigger carries.

A door (`Door`, DOOR chunk, `door_create` (0x80185380) and its movers in [door.c](../../src/game/door.c)) slides along x, y or z or turns. Opcode 4 sub 0
calls `door_start_open(door, distance, speed, auto_return)` (0x80184ECC): for a slide the target is the position
plus distance times 10 and the step is speed times 10 (one stored unit is ten coordinate units); for a turn both are
degrees, unscaled; with `auto_return` the door jumps back when it arrives. Sub 1 calls `door_start_close`
(0x80185034). `door_update_all` (0x80184C6C) moves the doors in state 2 (closing) or 3 (opening). Both start
functions raise `ai_door_noise`, so enemies notice the player
([line of sight](people-and-combat.md#targets-and-line-of-sight)).

## Game variables

`action_vars` (`GameVars`, 0x801E0368) is the script memory: u16 variables numbered from 0, read by `ActionCond` and
written by opcode 10, `action_cmd_var`. Subs 0 to 5 set, subtract, add, multiply, divide or take the modulo of
variable `target` by the argument, subs 6 to 8 by another variable. Variables the code itself uses:

| Variable | Use in code |
| --- | --- |
| 6 | 1 while changed (`player_finish_death`, 0x80197688) |
| 9 to 27 | one per building or group, read by `main_goto_building`; 10, 11, 12, 13 and 27 start at 100 (`main`) |
| 17, 48 | 17 set to 100 by the second arrest; no arrest while 48 is set (`main_goto_ofc`) |
| 61 to 64 | day, hour, minute and day parity ([the clock](../discoveries.md#-the-clock-counts-minutes-and-stops-at-day-99)) |
| 95 | the mail arrival counter, 3 at a new game |
| 96 onward | one byte per mail: bit 7 received, bit 6 read ([mails](player-and-survival.md#the-clock-and-the-mails)) |

---

Previous: [Menus, text and the save](menus-text-and-save.md) · Next: [Town and vehicles](town-and-vehicles.md) · [Engine index](README.md)
