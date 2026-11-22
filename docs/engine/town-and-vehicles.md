# Town and vehicles

<sub>[germs-decomp](../../README.md) / [Engine](README.md) / Town and vehicles</sub>

The world of Germs is built from blocks: pieces of map with a floor model, up to three other models and an optional
grid for the enemies. The town streams its blocks by cells around the player, a building loads its rooms. This page
covers the blocks of [block.c](../../src/game/block.c), how the code finds the ground under a
point, the buildings and their state ([building.c](../../src/game/building.c)), the town loop of
[town.c](../../src/game/town.c) with the car and the train of [vehicle.c](../../src/game/vehicle.c), and the shops of
[shop.c](../../src/game/shop.c). How a scene file is read is in [scenes and scripts](scenes-and-scripts.md).

**On this page:** [Town blocks](#town-blocks) · [Streaming](#streaming) · [Visibility](#visibility) · [Ground height and collision](#ground-height-and-collision) · [The arena](#the-arena) · [Buildings and their state](#buildings-and-their-state) · [The town loop](#the-town-loop) · [The car](#the-car) · [Car navigation](#car-navigation) · [The train](#the-train) · [Shops](#shops)

## Town blocks

`block_create_all` (0x8017A3E4) allocates twelve `Block` records of 0x90 bytes once and keeps them in `block_slots`.
`block_set_mode` (0x8017A86C) fills them for a mode: 2 opens the town map (`kaj_map_open_city`, 0x801D67E0), 1 opens
a building (`kaj_map_open_place`, 0x801D6894) and puts the player at the entry point the map gives
(`kaj_map_get_entry`, 0x801D6940). Both wait until the first resources are in, then call `block_load_all`
(0x8017A534), which runs `block_setup` (0x80179848) on up to twelve resources. A BLCK chunk of a scene loads one
block the same way (`object_load_blck`, 0x8018FC90, mode 3).

`block_setup` reads the block's header. In the town the position and size are stored in hundreds of units and the
block starts with `far` set; in a building they are raw. A table of offsets gives up to five parts, each marked in
`model_flags`:

| Offset slot | Field | Flag | Use |
| --- | --- | --- | --- |
| 0 | `floor_model` | 1 | the ground: height, triggers and walls ([ground](#ground-height-and-collision)) |
| 1 to 3 | `model1`, `model2`, `model3` | 2, 4, 8 | drawn by `block_draw_all` (0x80179C50, asm) |
| 4 | `arena` | 0x10 | the enemy grid ([the arena](#the-arena)) |

`block_set_origin` (0x8017CF10) shifts every block when the player crosses into a new cell: `player_wrap_cell`
(0x801958FC) keeps the player position inside cells of 12500 units on x and z and 32000 on y and moves the origin.

## Streaming

Each frame `block_stream_update` (0x8017AAB4) polls the map layer with the player position: `kaj_map_update_city`
(0x801D4FA0) in the town, `kaj_map_update_place` (0x801D5934) in a building. Status 3 means a new set of resources
is in: every slot is cleared and refilled through `block_setup`, and in a building `actor_update_blocks` (0x801765BC)
moves the people to their new blocks. Status 1, or a finished CD read, marks the cell ready and calls
`block_load_all` again. The map layer itself (the kaj cdmgr and map files) is described in [files and the
CD](files-and-cd.md).

In the town, `block_set_zone_flags` (0x8017A6E8) also tests the player position (in hundreds of units) against fixed
rectangles of the map and sets three effect switches in `GameVars`. A building sets the first two from the entry the
map gives instead. `main_step_frame` (0x8018C2FC) runs the effects while they are set:

| Field | Effect it turns on | Town area |
| --- | --- | --- |
| `flame_small_on` | `effect_flame_small_update` (0x80185E38) | one rectangle |
| `flame_large_on` | `effect_flame_large_update` (0x80186010) | the same rectangle |
| `clut_cycle_on` | `effect_clut_cycle_update` (0x801865C0) | that rectangle and nine more, and everything south of z -1225 |

## Visibility

`block_update_visibility` (0x8017A108) runs from the movement code and sets two flags on every block.
`player_inside` comes from `block_test_player_inside` (0x80179E50): the player's x and z lie inside the block's box
(and in a building, for a player on a floor, y too). `visible` is set when the player is inside, or when the block's
box lies in front along the view's eight-way direction. In the town, `block_test_player_inside` also clears `far`
when half the distance to the block's far corner is under 3537 (blocks up to 5000 a side) or 7073 (bigger ones).
`block_hide_all` (0x8017D0E0) clears every `visible` flag.

## Ground height and collision

The floor model is both the ground and the trigger map ([area triggers](scenes-and-scripts.md#area-triggers)):

| Function | What it does |
| --- | --- |
| `block_hit_tris` (0x8017B1E8), `block_hit_quads` (0x8017B3E8) | walk the TMD triangles or quads of a floor model, writing each tried polygon's `block_poly_height` to the height output; return the colour code of the first one under (x, z), or 0 when none is (the output then holds the 99999999 of the last try, and is not written at all for a model with no polygon) |
| `block_point_in_poly` (0x8017AC88) | point in polygon test, in software double floats |
| `block_poly_height` (0x8017AF18) | the y of a polygon's plane at (x, z), from its normal; 99999999 when (x, z) is outside the polygon or the normal's y is 0 |
| `block_find_surface` (0x8017BD24) | the first hit among the active blocks with a floor (optionally only those the player is in) |
| `block_find_surface_nearest` (0x8017BF50) | the hits of the active blocks the player is in (room for twelve): one hit is returned as it is; with several, the one whose height is closest to a given y wins, but only under a gap of 1600; when none is under 1600 it returns the `code` the last examined block left (that block's hit, or 0) and height 0 |
| `block_model_surface` (0x8017D414), `block_vehicle_surface` (0x8017BBB0) | the same on one model, or on the vehicle's model (the train floor) |
| `block_has_ground_at` (0x8017CFE4) | 1 when a code other than 0, 0xC8 or 0xFFxxxx lies under (x, z) |
| `block_find_at` (0x8017CDA4) | the active block whose box holds a point |

`player_check_ground` (0x80195098) uses these to keep the player on the floor and stop at walls; [player and
survival](player-and-survival.md) has the movement. For the car, `block_fit_ground_tilt` (0x8017C234) finds the
ground under four corners and the centre and turns the height differences into two tilt angles (`ratan2` over 300
and 508 units).

## The arena

A block whose flag 0x10 is set carries an `Arena`: an origin, a width and a depth in cells of 256 units, and the
cell data. `block_arena_init` (0x8017CAC8) copies it into a 16-byte buffer and `block_replace_arena` (0x8017C9F8)
repoints it when the map layer moves the data. `block_test_player_inside` sets `in_arena` when the player's cell
lies inside the grid. The people's AI walks this grid and only sees the player inside it ([people and
combat](people-and-combat.md#targets-and-line-of-sight)).

## Buildings and their state

`building_main` (0x8017E544) creates the slots and runs `building_run` (0x8017E25C):
`building_load` (0x8017DFA4), then a loop on kaj events (0x10 enter and 0x20 leave a trigger, 0x400 closes a
shop topic, and the other event handlers). `building_load` sets mode 1, builds the path `\S\<name>.S;1` from
the request, loads the scene, then sets the building up by its kind, `main_scene_request` +0x10, which
`main_goto_building` (0x8018C554) derives from the door's trigger code:

| Kind | Source | Setup in `building_load` |
| --- | --- | --- |
| 0 | a plain building | by room number: scene objects and figures shown (`npc_rec_show`, 0x8018F428), flames started (`effect_flame_small_init`, 0x8018647C) for some rooms |
| 1, 2 | trigger codes 0xF6xxxx and 0xF9xxxx | a station: `sprite_station_init` (0x801A5C34); kind 1 also sets `building_scene_daylight` for `event_show_clock` (0x8018AABC) |
| 3 and up | the trigger's middle byte plus 2 | a shop: `shop_init` (0x801A1EC0) |

The state of a building lives in its game variable (variables 9 to 27): its value picks the scene variant ([the
scene request](scenes-and-scripts.md#the-scene-request)). `main_goto_building` also raises `main_scene_request` +0x14
when the variable is one of 11 to 26 (not 13) and its value is 11 to 100; `building_load` then plays sound
effect 0x21 on arrival.

## The town loop

`town_game_loop` (0x801A9070), called once by `main` (0x8018BDE8), loops on `town_loop` (0x801A8CFC). That
runs `town_enter` (0x801A88B4), polls kaj events, calls `town_input` (0x801A8768) and
`main_step_frame` each frame, and ends with `town_leave` (0x801A8B38). The exit code it leaves decides what
comes next: 0 quit, 1 the phone (`sprite_phone_run`, 0x801A6AC4, after a 0xFF trigger), 2 the bus (below), 3 get
into the car, 4 get out. The vehicle mode the player is in is player `vehicle_mode`: 0 on foot, 1 the car, 2 the train, 3
the subway. `vehicle_update` (0x801AC4A8) runs `vehicle_car_drive` (0x801AA360) in mode 1 and `vehicle_train_drive`
(0x801A9EA4) in modes 2 and 3.

A 0xFE trigger (a bus stop) answered with CIRCLE in `town_do_action` (0x801A850C) leaves exit code 2 with the
trigger's two low bytes, and `town_game_loop` passes them to `block_elevator_run` (0x8017E99C). Despite its name,
this is reached only from the town: `block_elevator_input` (0x8017E594) moves a selection from 1 to 11 (1 to 5 when
the first byte is 3), recolours the sprite, and warps through `main_goto_twn` (0x8018C50C) to a town position stored
for each line and stop; the clock then advances 5 minutes per step moved (`event_advance_clock`, 0x8018ABE8).

## The car

`vehicle_car_input` (0x801ABC70) reads the pad: buttons 4 and 8 steer to plus or minus 45 degrees, 0x10 and 0x40
select forward or reverse and ramp two pedal counters up to 256; 0x1000 and 0x4000 tilt the view (`look_pitch`, -20
to 20) and 0x8000 and 0x2000 turn it (`look_yaw`, -65 to 65), one of the four per frame. `vehicle_car_drive`
computes:

| Step | Rule |
| --- | --- |
| revs, forward gear | 800 + 30 times the `brake` counter, at most 6500, minus 45 times the `throttle` counter, at least 800 |
| revs, reverse | the same with the two counters swapped |
| speed | (revs - 800) x 347436 / (divisor x 55086), or / (divisor x 72566) backward, then a quarter of it, times the frame time |
| divisor | `vehicle_car_speed_div`: 300, 400 or 500 from the car speed setting (`vehicle_car_init`, 0x801A923C); three times more while `vehicle_car_state.slowed` is set |

(The two counter names look swapped by their use.)  Sound effect 0x1B plays when speed is 25 or more with steering
40 or more. When the car stands, the prompt to get out shows and CIRCLE leaves (`vehicle_car_stopped_input`,
0x801ABA88); `vehicle_car_get_out` (0x801A968C) tries four spots around the car (245 to the sides, 490 ahead and
behind) with `block_has_ground_at`.

## Car navigation

START on the stopped car opens a destination menu (`vehicle_navi_open_menu`, 0x801AB9E0). `vehicle_navi_update`
(0x801AB774) then measures each frame the distance to the destination's x and z in `vehicle_navi_dest_xz`, fills a
gauge from the start distance, picks one of eight arrow frames with `ratan2`, and blinks the sprite under 25 units.

## The train

Two train codes exist. Thing (2, 0) is the train seen from a platform: `vehicle_train_arrive` (0x801AAA9C) sends it
in from z -16000 or 48000, `vehicle_train_update` (0x801AACF4) brakes it to z 16000 and opens its doors (sprite
0x408 frames, `vehicle_train_set_doors`, 0x801AC70C). The ride itself is `vehicle_train_drive`, in vehicle.c:
`TrainState` holds a direction, a station from 1 to 6 and four marks on z (`vehicle_train_calc_stops`, 0x801A910C,
100000 apart) for start, cruise, brake and stop. Speed grows with the distance from the start mark (/ 300 + 7),
holds while cruising and falls with the distance to the stop mark. At the stop, the doors open, `stop_timer` starts
at 2 and the player is carried by the car's matrix. Getting off (`vehicle_train_get_off`, 0x801AB1A0) goes to the
station scene `SB1` (subway) or `RW1` (train); at a line end `vehicle_train_end_of_line` (0x801AB310) does it alone.

## Shops

`shop_init` keeps the hour, hides the doors outside the shop and installs enter and leave hooks that mark
the player at the counter. `shop_open_menu` (0x801A1AB8) opens the first menu by kind. For the gun shop
(kind 7), `shop_pick_weapons` (0x801A0820) takes weapons 1 to 12 except 10, sorts them by required level
(`shop_cmp_weapon_level`, 0x801A216C; a missing record counts as 100) and keeps six: positions 0 to 5, 3 to 8 or
5 to 10 by the player's level band (level / 20, at most 2). `shop_finish` (0x801A0EDC) ends a deal: kind 7
gives level advice, kind 9 uses the bought item at once between screen fades (`effect_item_use`, 0x801882AC), and
the food shops either hand over up to three items or eat them at once with `effect_item_use` (a meal adds 1 to
`meal_count`, GameVars + 0x92). `shop_exit_to_town` (0x801A1FD4) puts the player back in the town at the shop's exit
point. What the food and the clinics do is in [player and survival](player-and-survival.md#food-and-healing).

---

Previous: [Scenes and scripts](scenes-and-scripts.md) · Next: [People and combat](people-and-combat.md) · [Engine index](README.md)
