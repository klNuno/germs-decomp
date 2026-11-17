# Player and survival

The player is one `Player` record (`player_character`, the body in the world) and one `PlayerStatus`
(`player_status`, the numbers: energy, level, stats, hours awake). Most of the code that moves the body sits in one
file without an assert, [player.c](../../src/game/player.c), whose functions carry a `player_` label; the clock, the
gauges and the body parts are in event.c and the mails in mail.c. This page follows the body
from the pad to the floor, then the survival rules. The findings about each rule are in
[discoveries](../discoveries.md) and only linked here.

## The records

`player_init` (0x801971D4), called once by `main` (0x8018BDE8), clears the three records and sets the start: energy
201 (0xC9), level 1, next level at 324 experience, 2 hours awake, every stat and weapon class level at 1, eight
empty item slots and one empty weapon slot.

| Record | Fields used on this page |
| --- | --- |
| `Player` | position and cell, `pitch`, `yaw`, `roll`, `vehicle_mode` (+0x46: 0 on foot, 1 car, 2 train, 3 subway), `flags`, `speed_step` |
| `PlayerStatus` | `energy`, `level`, `exp`, `next_exp`, `stat0` to `stat3`, five weapon class levels, `defense_level`, `hours_awake`, `limb_state[5]`, `infected`, `mutant`, `drain_pending` |
| `GameVars` | `limb_damage[5]`, the clock (variables 61 to 64), the stat backup at +0x62, the mail bytes |

## Moving on foot

`player_update` (0x801979B4) runs from `mail_step_frame` (0x8018C2FC) each frame. It starts a death when energy is
0, clamps the pitch and wraps the yaw, then calls the mover for `vehicle_mode`. The pad is read before, by
`player_handle_pad` (0x80199548), from the scene loops' input functions:

| Input | Effect |
| --- | --- |
| forward (0x10) | step 4; in the town (mode 2) with bit 1 also held, the step rises by one per frame up to 11 (flag 0x1000 marks running); forward alone during a run lowers it by one per frame back to 4, as does releasing the pad |
| back (0x40) | step 4, or one step slower while running |
| 4, 8 | strafe, 6 per frame |
| 0x1000, 0x4000, 0x8000, 0x2000 | turn the view up, down and sideways; in the train they turn the view inside the carriage |

The step is multiplied by the frame time, then by 10 in the office and buildings and by 4 in a train; on foot in the
town it stays as it is. Player flag 0x100 (opcode 8 sub 3 of a script) stops the walk. Hurt legs slow the walk
([wounds](../discoveries.md#-hurt-legs-slow-you-down-and-one-hurt-arm-spoils-your-aim)).

`player_move_on_foot` (0x80196AE0) turns the step into x and z with `rsin` and `rcos` of the yaw, moves the body,
then looks for what it meets. Only the first two tests probe 600 units ahead of the moved position (behind when
backing up): a scripted figure (code 0xF7, `mod_npcrec_find_at_point`, 0x8018F7D0) and a person (0xFC,
`npc_find_at_point`, 0x80176464). The others use the moved position itself: a scene object (0xFD, `thing_hit_test`,
0x801A7CF0), or else the floor (`block_find_surface`, 0x8017BD24, or `block_find_surface_nearest` in mode 1).
`player_check_ground` (0x80195098) takes the code: it refuses the move on a trigger whose walk flag is 0 and sends
trigger events when the code changes ([area triggers](scenes-and-scripts.md#area-triggers)); when it accepts,
`player_move_on_foot` sets the height from the floor it found. A move refused by a figure, a person, an object or a
trigger is undone; one with no floor under it falls back on `player_try_slide` (0x80195DF0), which nudges x and z by
2 in a few directions to slide along the wall.

`player_wrap_cell` (0x801958FC) keeps the position inside a cell (12500 on x and z, 32000 on y) and moves the blocks
and the people with it ([town blocks](town-and-vehicles.md#town-blocks)). In its matching C the map position `world_z`
adds the x cell shift to z; `player_update_view` (0x80195BC8) recomputes it with the z cell at the end of every mover, so the
slip likely lasts one step.

## In the car and on the train

`player_move_in_car` (0x801966B4) moves the car from the speed and steering of `vehicle_car_drive` (0x801AA360, [the
car](town-and-vehicles.md#the-car)), seats the player with `player_place_in_car` (0x80196454), tests the ground
under the car (`block_fit_ground_tilt`, 0x8017C234) and undoes the move when the test fails. `player_move_in_train`
(0x80196048) moves an offset inside the carriage, carries it with the carriage's matrix, and tests the carriage
floor (`block_vehicle_surface`, 0x8017BBB0) the same way as the ground ([the
train](town-and-vehicles.md#the-train)).

## The view

`player_update_view` ends every mover: it recomputes the map position in hundreds, rebuilds the view
matrix from the three angles and, in a building, the player model's coordinate. `player_set_view` (0x8019555C, asm)
does the same after a warp (rest, recovery, a new scene), folding the cell into the position. The drawing side is in
[rendering](rendering.md).

## Energy and hours awake

`event_clock_tick` (0x8018AA00) runs on each clock message of the scene loops and adds one minute
(`event_clock_add_minute`, 0x8018A5F0). When the minute ends in the digit `drain_minute`, it raises `drain_pending`,
and the HUD update (`event_update_hud`, 0x80189F50) takes energy with `event_drain_gauge` (0x80189AC0):

| Input | Drain |
| --- | --- |
| hours awake under 16, or changed | 1 |
| hours awake 16, 32, 48, 64, 80, 96 and up (by sixteens) | 2, 3, 4, 8, 16, 32 |
| `limb_state[3]` at 1, 2, 3 | times 1.5, 2, 4 |
| the carried weapon, every sixth drain | plus its `drain_extra` |

Every drain also clears `infected`. Each new hour adds 1 to `hours_awake` unless the caller asks for no fatigue.
`player_rest` (0x80199EB4) takes 4 hours off for a 60-minute nap or sets them to 0 for a sleep of 7 hours (until
08:00 when it starts after 20:59 or before 03:00)
([energy](../discoveries.md#-energy-drains-faster-the-longer-you-stay-awake)).

## Body parts

Five damage values (`limb_damage`, where game variables 90 to 94 would be) belong to five parts.
`player_pick_hit_part` (0x80197F34) picks the part a hit lands on: part 0 in 15 percent of hits, else one of 1 to 4
by the direction of the shot. `event_draw_limb_status` (0x80189DE8) maps each value to `limb_state` 0 to 3 (under
0x10, under 0xA6, under 0xF0, above) and colours the body panel. Each hour heals 4 points per part unless the part
is at state 3, or 16 points of every part while changed
([healing](../discoveries.md#-body-part-damage-heals-by-the-hour-unless-it-is-at-the-worst-level)).

## Death and the changed state

At energy 0, `player_start_death` (0x80197838) sets flag 0x800 and plays a fall (`player_start_move_to`, 0x80198CFC), whose end
calls `player_finish_death` (0x80197688); in a train it finishes at once, and in the car it does not start. If game
variable 48 is 0 and `infected` is set, the player is changed: energy back to 255, hours awake 0, the level, stats
and class levels saved at `GameVars` +0x62 and set to 100, building variables 9 to 27 saved and set to 2000 (the
variant 4 of every building), game variable 6 set to 1, and the scene `CMN` loads. Otherwise the game ends
([death](../discoveries.md#-energy-at-0-is-death-and-only-a-hit-to-the-head-makes-you-wake-up-changed), [the changed
state](../discoveries.md#-being-changed-is-one-flag-a-pink-body-fast-healing-and-no-fatigue)).

## Food and healing

| Function | Effect |
| --- | --- |
| `effect_item_use` (0x801882AC) | an item record: kind 0 food or drink adds energy (`player_add_hp`, 0x80199E1C, which clears `infected` on a loss), kind 3 lowers the five part values |
| `player_heal_part` (0x80199D68) | subtracts `amount` from one part's `limb_damage`: a positive amount heals, never under 0; a negative one adds damage, capped at `player_part_damage_caps[cap_kind]` (0x801DFD64) |
| `player_recover` (0x80199370) | clears every part; with `wake` 1 it also cures the changed state (stats and building variables restored, variable 6 cleared) and costs no time, with `wake` 0 it costs 60 minutes |
| `player_rest` | a nap or a sleep, above |

Where the shops and clinics call these:
[food](../discoveries.md#-food-adds-a-fixed-amount-of-energy-and-eating-on-a-full-bar-hurts-your-torso), [the burger
shop](../discoveries.md#-the-burger-shop-secretly-serves-changed-food-and-even-days-swap-its-hours), [the
hospital](../discoveries.md#-the-hospital-heals-every-wound-at-once-for-free-and-without-losing-time), [the
chiropractor](../discoveries.md#-the-chiropractor-sells-time-1-3-or-6-hours-that-heal-as-much).

## Experience and levels

`player_add_exp` (0x80197D64) adds experience and, while it reaches `next_exp`, raises the level, adds 0 to 2 to
each of the four stats (each capped at 100) and recomputes the weapon rates. The level has no cap inside the loop:
only the entry returns at level 100, and a step that reaches 100 leaves `next_exp` unchanged, so the final test can
run the loop again. The next threshold is `mail_exp_for_level(level)` (0x8018C810): 0 for level 1, 324 for 2, then
steps of 405, 567, 729 and on, each 162 more than the last. It is called with the new level, so the threshold just
reached is stored again and the loop runs once more: in the matching C, the first 324 points give level 3 at once.
Class experience goes through `player_add_skill_exp` (0x80197BB0).

## The clock and the mails

The clock is four game variables: day (61), hour (62), minute (63) and day parity (64). `event_clock_add_minute`
carries minutes into hours and hours into days and stops the day at 98 ([the
clock](../discoveries.md#-the-clock-counts-minutes-and-stops-at-day-99)); `event_advance_clock` (0x8018ABE8) adds
many minutes at once, and `event_update_daylight` (0x8018A3F8) sets the far colour by the hour. On every new hour it
calls `mail_check_schedule` (0x8018BB00) with the day and hour, which hands the mails due to `mail_receive`
(0x8018BA48) under game variable conditions ([timed
mails](../discoveries.md#-the-timed-mails-are-written-in-the-code-for-days-1-to-4)). A script can also deliver one
(opcode 13, `mail_cmd_receive`, 0x8018BD60).

There are 32 mails, one byte each from game variable 96: bit 7 received, bit 6 read, the low six bits the arrival
order taken from the counter (variable 95). `mail_receive` ignores a mail already received. `mail_create`
(0x8018ACAC) builds a mail from its `MAIL` chunk (up to four page sprites) and `mail_list_open` (0x8018B810) lists
the received ones in order. The menus that show them are in [menus, text and save](menus-text-and-save.md).
