# People and combat

<sub>[germs-decomp](../../README.md) / [Engine](README.md) / People and combat</sub>

The people of a scene (passers-by, shop staff, the infected) are `Npc` records loaded from the scene file. Two files
move them: [actor.c](../../src/game/actor.c) holds the table, the animation, the script commands and the damage, and
[ai.c](../../src/game/ai.c) holds the AI: line of sight, target choice, walking and firing. Neither file has an
assert string, so both names are ours ([layout](../layout.md)). This page also follows a shot from the player to a person and back,
down to death and arrest. The scripts that drive people are in [scenes and scripts](scenes-and-scripts.md).

**On this page:** [Records from the scene](#records-from-the-scene) · [The person table](#the-person-table) · [Animation and the frame](#animation-and-the-frame) · [Commands from scripts](#commands-from-scripts) · [Targets and line of sight](#targets-and-line-of-sight) · [Movement and attack decisions](#movement-and-attack-decisions) · [The enemy's hit roll](#the-enemys-hit-roll) · [The player's shot](#the-players-shot) · [Weapons and their records](#weapons-and-their-records) · [Damage and death](#damage-and-death) · [Arrests](#arrests)

## Records from the scene

A scene brings five tables, loaded by `object_load_other` (0x801907C8) into `object_scene_tables`:

| Chunk | Record | Found by | Holds |
| --- | --- | --- | --- |
| `ACTR` | `Npc`, 0x4C bytes | `actor_find` (0x801762F4) | the people of the variant (below) |
| `CHAR` | `NpcBody` | `actor_find_body` (0x801767D4) | a body: an id, `radius` at +0xA, three 0x20-byte strings |
| `ENMY` | `NpcStats` | `actor_find_stats` (0x80176890) | fighting values (below) |
| `NPC ` | `NpcRecord` | `npc_rec_cmd` (0x8018EED4) | scripted figures with a model, a pose, `shown` and a move task |
| `WEPN` | `WeaponRecord` | `effect_weapon_find` (0x80188FEC) | the weapons (below) |

`action_init_npcs` (0x8017519C) runs when `ACTR` loads: it multiplies the two stored positions by 10, places each
person on its model (`action_place_npc`, 0x80174FFC) and in its block (`block_find_at`, 0x8017CDA4), sets "no
target" and asks the person to face the player first. A person without a stats or body record uses
`ai_default_stats` and `ai_default_body`.

## The person table

The `Npc` fields keep placeholder names in the code; their roles, read from the two units:

| Offset | Role |
| --- | --- |
| +0x0, +0x2 | id; kind: 0 a human; other values are likely the infected, since a hit from any of them infects the player (`player_take_hit`, 0x801981D0) |
| +0x4, +0x6, +0x8 | placed, active, talkable |
| +0xC | hit points |
| +0xE | mode: 0 friendly, 1 hostile, 2 dying |
| +0xF | state: 0 stand, 1 walk, 6 dead |
| +0x10 | target: -1 the player, -2 none, else another person's id |
| +0x12 | flags: 1 face the player, 2 sees the player, 4 another person in the line of fire, 0x20 talking, 0x100 scripted walk, 0x200 scripted pose, 0x400 firing, 0x800 hit, 0x1000 missed |
| +0x14, +0x16, +0x18 | body, model and stats ids |
| +0x1A, +0x1C, +0x1E | talk set, leave set, death set |
| +0x20 to +0x28, +0x2C to +0x34 | position, and a second point, both times 10 |
| +0x3A, +0x3E | heading, wanted heading |
| +0x40 | distance to the target, written by `ai_check_line` (0x801768F8) |
| +0x42 | experience on death |

## Animation and the frame

`actor_update_all` (0x801759B0) runs from `main_step_frame` (0x8018C2FC) in the office and buildings. It first
resolves the player's shot (`player_shoot_target`, 0x80198720), then for each active person:

| Condition | Animation (`actor_update_anim`, 0x8017546C) | Then |
| --- | --- | --- |
| mode 2, not yet dead | 7 | state 6, runs the death set, sound 0x14 |
| state 0 | 0 | `ai_update_stand` (0x80178D04) |
| state 1, mode 0 or 1 | 1 | `ai_update_move` (0x80178E38) with mode 0 or 1 |
| flag 0x800 / 0x1000 | 4 / 3 | the hit or miss reaction |
| flag 0x400 | 5 | `ai_fire` (0x8017917C) when the animation reaches its fire frame |
| flag 0x200 / 0x100 | 2 / 1 | stand, or `ai_update_move` with mode 2 |

The flags at 0x100 and above win over the state. A death set numbered 1000 raises `actor_death_set_1000` while it runs. At the
end the frame picks the player's next target (`player_pick_target`, 0x801985AC) and clears the two alert flags
(below). Talking to a person (trigger kind 0xFC) goes through `action_run_npc_event` (0x801752F4): a dead person
runs set 0x400, a hostile one never talks, others run the talk set on enter and the leave set on leave.

## Commands from scripts

Opcode 1 of an action calls `actor_exec_command` (0x80175CD8) on the person whose id is the target:

| Sub | Effect |
| --- | --- |
| 0 | sets the talk, leave or death set from the arguments |
| 1, 2 | talkable, active |
| 3 | the state (not on a dying or dead person) |
| 5 | the mode; mode 2 also clears every flag |
| 7 | 0 keeps flags `& 0x1FF` (clears 0x200 and up; the scripted walk 0x100 stays), 1 sets the scripted walk (0x100), 3 clears 0x200 and up then sets the scripted pose (0x200) |

## Targets and line of sight

`ai_find_target` (0x8017726C) is the eyes. A person sees the player only if the player is inside its block's arena
([town and vehicles](town-and-vehicles.md#the-arena)) and one of three things holds: a door started moving this
frame (`ai_door_noise`), the player made a weapon sound (`ai_weapon_noise`, set by `player_weapon_sound`, 0x80199A94), or
the player is in front of it (`ai_player_in_front`, 0x80177110). Then `ai_check_line` tests the line to the player's
position 1600 units up. It also looks at the other living people on the same height. With the player seen, flag 4 is
set when another person stands within 10 degrees of the player's direction; in turn mode 1 the person turns toward
the player (`ai_turn_step`, 0x80176E2C). Without the player, the nearest seen person becomes the target. Both alert
flags are cleared at the end of every frame, so a sound or a door alerts for one frame only.

## Movement and attack decisions

Without an arena under it, a person only faces the player (`ai_face_player`, 0x80178B84). Standing hostile people
call `ai_decide_fire` (0x801788F8) and set flag 0x400 when it agrees. `ai_update_move` walks a distance of frame
time times the stats `speed` (3 when 0) times 4 (friendly), 10 (hostile) or 6 (scripted). The result byte at +0xB of
the last fire decision steers it: 2 (flag 4, someone in the way) tries `ai_sidestep` (0x801787CC) then
`ai_step_back` (0x801786A0), 3 (too close, or flag 0x10) the other order; otherwise `ai_walk` (0x80178494).

`ai_decide_fire` refuses unless the target is the player, the player is inside the person's 10 degree aim cone
(`ai_in_aim_cone`, 0x80179630) and flag 4 is clear. The range is the distance minus the body radius minus 600. The
chance starts at stats `fire_chance` and is scaled by the three ranges of the stats (`range_min`, `range_mid`, `range_max`, times 10):
between the first two it falls from full to nothing, between the second and the third it is (third minus range)
divided by (third minus first), beyond the third a random scale below 411/4096 applies, and under the first the
chance is 10. It fires when the chance is at least a roll of 100.

## The enemy's hit roll

`ai_fire` checks the same conditions again, then sets a damage scale from the range: full between the first and the
second band, falling to nothing at the third, 0 beyond it and, at first, 0 under the first band. The hit chance is
the accuracy (stats +0xC) times that scale. A melee person (weapon kind 0) then stops with no roll when the height
test fails (player y minus its y plus 1600 outside -1600..1600) or when the scale is 0, so it never hits under the
first band or beyond the third. Otherwise, under the first band (a ranged person only) the chance becomes 20 and the
scale full, and any lower chance is raised to 20. It hits when `rand() % 100` is under the chance, and calls
`player_take_hit` with the stats damage times the scale (at least 410/4096). Every path ends with a sound: 0x28 when
the low byte of the person's kind (+0x2) is 2 or 3, else one per stats weapon kind 0 to 4 (0x23 to 0x27).
`player_take_hit` rolls the player's defence from the stats, picks a body part (`player_pick_hit_part`, 0x80197F34)
by the direction of the shot, and does 1.5 times damage from straight behind; damage to part 0 also comes off energy
and infects the player when the attacker is not human
([wounds](../discoveries.md#-hurt-legs-slow-you-down-and-one-hurt-arm-spoils-your-aim),
[death](../discoveries.md#-energy-at-0-is-death-and-only-a-hit-to-the-head-makes-you-wake-up-changed)).

## The player's shot

`player_pick_target` chooses the nearest placed, living person who has seen the player (flag 2), is not in a
scripted pose, and lies inside the player's aim cone: 15 degrees, 25 for weapon 10 and those from 14 up.
`player_shoot_target` resolves a shot when the player's flag 0x400 is set, with the weapon's rate, three ranges and
class ([the
roll](../discoveries.md#-every-shot-is-a-roll-against-the-hit-chance-and-range-cuts-both-chance-and-damage)).
Walking or running takes a tenth off the chance.

## Weapons and their records

A `WeaponRecord` holds an id, a class (0 to 4), a name, three optional requirements (level, a stat, a class level),
the frame of the animation that fires, the accuracy, the damage and the three ranges, stored in units of ten
coordinate units (`player_shoot_target`, 0x80198720, multiplies each by 10 before comparing)
([the record](../discoveries.md#-the-weapon-record-three-requirements-accuracy-damage-and-three-ranges),
[classes](../discoveries.md#-the-blue-wheel-is-the-weapons-hit-rate-and-the-five-classes-are-levels-up-to-100)).
`effect_weapon_calc_rate` (0x80187978) turns a record and the player into the hit rate, and
`effect_weapon_check_fire_frame` (0x80188E0C) tells the animation when to shoot.

## Damage and death

`actor_apply_damage` (0x80175FA8) takes a class, a damage and a miss flag. Stats `on_hit` 1 makes the person hostile and
drops a scripted walk, 2 makes it hostile and walking. A miss sets flag 0x1000. Otherwise the defence roll is a
random number below stats `defence` (0x7FFF means immune), cut to two thirds unless the stats `resist_types` bit for
the weapon class (1 << class) is set. What is left comes off the hit points and gives twice its value as class
experience (`player_add_skill_exp`, 0x80197BB0). At 0 the person goes to mode 2 and the player gains its experience:
times 1 for kind 0, 2 for kinds 1 and 2, 3 for 3 to 5, 4 for 16 to 18, 6 for 19.

## Arrests

Killing a human (kind 0) adds 1 to two counters of `PlayerStatus`, +0x32 (never reset here) and +0x2E.
`main_goto_ofc` (0x8018C414) checks +0x2E when the player next goes to the office, with +0x30 counting the arrests.
The first comes at 3 kills, the second at 5 more (unless game variable 17 is already 100, which it then sets); each
loads the office's arrest variant and resets the counter, and there is no third
([arrests](../discoveries.md#-three-civilian-kills-get-you-arrested-and-five-more-the-second-time)). Game variable
48 or the changed state (`mutant`) skips the check.

---

Previous: [Town and vehicles](town-and-vehicles.md) · Next: [Player and survival](player-and-survival.md) · [Engine index](README.md)
