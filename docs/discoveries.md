# Discoveries

What reading the game's code taught us about Germs: Nerawareta Machi. Each finding below says in plain words what happens when you play, then keeps the proof (functions, addresses, how it was checked) folded under "Technical details". What players and earlier projects already knew is in [community-knowledge.md](community-knowledge.md); open questions live in [mysteries.md](mysteries.md).

Status of each finding:

- 🎮 Checked in the game: we ran the game in an emulator, changed or watched its memory, and saw the predicted result on screen or in memory.
- 🎮 Partly checked: part of it was seen in the emulator, the rest is read in the code.
- 📖 Read in the code only: the code says so, nobody has seen it happen yet.

What the mark before each title means:

- 🆕 New: nobody had written it down before us, not the wikis, not the translation projects, not the cheat makers.
- 🧩 Known in part: players had seen it or knew some of it; we add how it works, its exact conditions or its numbers.
- ✅ Confirmed: something players or earlier projects believed, now proven by the code or the emulator.
- 🔄 Corrected: a belief that was partly wrong; the finding gives the right version.
- ❌ Myth busted: a belief the code proves false.

Names in the technical details are the ones this project gave, each with its evidence in `config/symbol_addrs.txt` and the rules in [naming.md](naming.md); a name still of the form `func_XXXXXXXX`, `D_XXXXXXXX` or `unkXX` is not understood yet. Addresses are in the executable `SLPS_021.07` as loaded in memory. The source files named are in this repository's `src/`. Emulator runs used PCSX-Redux through `tools/emu/run.sh` with a Lua driver (pad input, memory writes, captures); each finding lists what was forced.

## The findings at a glance

Time
- 🧩 [The clock counts minutes and stops at day 99](#-the-clock-counts-minutes-and-stops-at-day-99): one game minute every 600 screen refreshes, 10 seconds, which is the 6x speed players measured. 🎮
- 🧩 [The timed mails are written in the code, for days 1 to 4](#-the-timed-mails-are-written-in-the-code-for-days-1-to-4): twelve mails at eight fixed times, four of them under story conditions, two of the times nobody listed. 🎮
- 🆕 [One shop swaps its two menus on even days](#-one-shop-swaps-its-two-menus-on-even-days): the only use of the day's parity. 📖

Survival
- 🧩 [Energy drains faster the longer you stay awake](#-energy-drains-faster-the-longer-you-stay-awake): 1 point every 10 game minutes, up to 32 after 96 hours awake, and a hurt torso multiplies it. 🎮
- 🔄 [Body part damage heals by the hour, unless it is at the worst level](#-body-part-damage-heals-by-the-hour-unless-it-is-at-the-worst-level): the parts are head, two arms, torso and legs, not the cheat author's order, and there are four colours, not three. 🎮
- 🔄 [Energy at 0 is death, and only a hit to the head makes you wake up changed](#-energy-at-0-is-death-and-only-a-hit-to-the-head-makes-you-wake-up-changed): starving is always game over. 🎮
- 🧩 [Being changed is one flag: a pink body, fast healing and no fatigue](#-being-changed-is-one-flag-a-pink-body-fast-healing-and-no-fatigue): wounds heal four times faster, even the worst ones, and every stat is set to 100. 🎮

People
- ✅ [The profile panel is the lingering thoughts of the dead](#-the-profile-panel-is-the-lingering-thoughts-of-the-dead): the four-line card an earlier project found but never saw in play. 🎮 partly

Performance
- 🧩 [The game times every frame, so a slow machine makes it choppy, not slow](#-the-game-times-every-frame-so-a-slow-machine-makes-it-choppy-not-slow): 30 frames a second at best, movement scaled by the real frame time. 🎮 partly

The disc
- ✅ [The movie on the disc can never play](#-the-movie-on-the-disc-can-never-play): no code opens it and no video decoder is in the game. 📖
- 🆕 [The game still names scene files the disc does not have](#-the-game-still-names-scene-files-the-disc-does-not-have): the game still builds paths to files the disc does not have, then ignores them. 📖

## Time

### 🧩 The clock counts minutes and stops at day 99

🎮 Checked in the game.

<img src="img/game/clock-day99.png" alt="The office at night: the HUD clock reads day 99, 00:02, after two midnights forced past day 98" width="49%">

The game clock moves one minute at a time. A timer counts screen refreshes and, every 600 of them, sends a "clock" event; at 60 refreshes a second that is one game minute every 10 seconds, so six game minutes per real minute, which matches the 6x speed players report. The number 600 is the value a known cheat writes to stop or speed up time: it is the period itself, so 2 makes a minute pass every two refreshes and 0xFFFF makes one pass about every 18 real minutes. At 60 minutes the hour goes up, at 24 hours the day goes up, and the calendar stops at day 99: every later midnight leaves the clock on day 99. Because the clock counts refreshes in an interrupt, it keeps the same pace however slowly the game draws.

<details><summary>Technical details</summary>

- Proof: `kaj_timer_init` (0x801D0300, src/kaj/801CFD70.c) opens an event on root counter 3 (`0xF2000003`, the vertical blank counter) with `kaj_timer_handler` as handler and sets `kaj_system.timer_period` (`0x801E6DB0`) to `0x258` (600). `kaj_timer_handler` counts ticks and posts event 4 with `kaj_event_push(4)` every period. The game's event loops answer event 4 with `event_handle_tick`, which calls `event_clock_tick` and then `event_clock_add_minute` (src/game/8018920C.c). That adds one to the minute (`action_vars.vars[0x3F]`, `0x801E03E6`), carries into the hour (`vars[0x3E]`, `0x801E03E4`) at 60 and into the zero-based day counter (`vars[0x3D]`, `0x801E03E2`) at 24, stores the counter's parity in `vars[0x40]` (`0x801E03E8`), then clamps the counter to 98. `event_draw_clock_digits` shows the counter plus one. Time skips (sleep, naps) go through `event_advance_clock`, which runs `event_clock_add_minute` once per skipped minute.
- In game: with the period untouched the minute changed at vsyncs 407, 1007 and 1607, 600 apart; after writing 60 to `0x801E6DB0` it changed every 60 vsyncs. Forced day counter 97, 23:58: at midnight the counter went to 98 and the HUD showed day 99, 00:01. Forced 23:58 again: at the second midnight the counter stayed 98, the parity went from 0 to 1, and the HUD still showed day 99 (picture).
- Question: [1](mysteries.md#time-and-days). Found and checked 2026-11-16.
- Before us: the 6x speed (Japanese Wikipedia, GameFAQs) and the address with its 600, 2 and 0xFFFF values (DuckStation cheat file). New here: what the 600 counts, the one-minute step and the day 99 limit.

</details>

### 🧩 The timed mails are written in the code, for days 1 to 4

🎮 Checked in the game (memory).

Some mails reach the office computer at fixed hours. They are not read from a data file: the code that runs every game hour holds the whole list. Before the ending, twelve mails can come on the clock, at eight times: day 1 at 10:00, 17:00 and 21:00; day 2 at 10:00 and 16:00; day 3 at 10:00 (up to three mails) and 14:00 (up to two); day 4 at 12:00 (up to two). Four of them only come if a story step is done (or not done). After the ending, no mail arrives by time.

<details><summary>Technical details</summary>

- Proof: `mail_check_schedule` (0x8018BB00, src/game/8018ACAC.c), called every game hour, tests the day counter and the hour directly, only while game variable 0x30 (`0x801E03C8`, set after the ending) is 0. Day counter 0: mail 0x0E at 10:00, 0x08 at 17:00, 0x17 at 21:00. Counter 1: 0x0F at 10:00, 0x1C at 16:00. Counter 2 at 10:00: 0x02 if variable 0x0B is 100 and variable 1 is 0, then 0x11, then 0x14 if variable 0x13 is 100; at 14:00: 0x15 if variable 0x11 is 10, then 0x1A. Counter 3 at 12:00: 0x1D, then 0x1F if variable 0x4D is 0. Each goes through `mail_receive` (0x8018BA48).
- In game: with a breakpoint on `mail_receive` and the clock forced to two minutes before each hour on days 1 to 5, the game called it with 0x0E (day 1 10:00), 0x1C (day 2 16:00), 0x02 and 0x11 (day 3 10:00), 0x1A (day 3 14:00), 0x1D and 0x1F (day 4 12:00) and nothing on day 5; the received count at `0x801E0426` went from 3 to 10. The mail screen was not opened.
- Question: [2](mysteries.md#time-and-days), partly: the per-minute hook in `D_801DFEDC` and the story-driven mails are still open. Found and checked 2026-11-16.
- Before us: the fandom wiki's Emails page lists Naomi on day 1 at 21:00, Sakaguchi on day 1 at 17:00, Indenco on days 1 to 3 at 10:00 and a mine mail on day 4 at 12:00. New here: day 2 at 16:00, day 3 at 14:00, the conditions and the end of the schedule after the ending.

</details>

### 🆕 One shop swaps its two menus on even days

📖 Read in the code only.

Every midnight the clock stores whether the day number is even. Only one thing in the whole game reads it: one of the four shops that share a building scene. It has two menus. On odd days it serves the first one from 08:00 to 13:59 and the second the rest of the day; on even days it is the other way round. After the ending it always serves the first menu, and while you are changed it always serves the second. Which shop this is has not been checked yet.

<details><summary>Technical details</summary>

- Proof: the only reader of `0x801E03E8` (`action_vars.vars[0x40]`) is `roadmap_shop_open_menu` (0x801A1AB8, src/game/8019A5D4.c), case 4. With game variable 10 (`0x801E037C`) at neither 1000 nor 2000 and variable 0x30 at 0: parity 0 (odd displayed day) gives the list at `0x801D7A10` (items 0x23 to 0x2A and 0x33) when the hour of entry (`0x801E0560`) is 8 to 13, else the list at `0x801D7A22` (items 0x2B to 0x32 and 0x33); parity 1 swaps them. Variable 10 at 1000 (after the ending) or variable 0x30 set gives the first list, variable 10 at 2000 (changed) the second. `roadmap_shop_init` sets up shop types 3 to 6 in one scene with 10 doors each; type 7 is the gun shop.
- In game: not checked. Which building is shop type 4 and the names of items 0x23 to 0x33 (in `RES.R`) are not looked up.
- Question: [5](mysteries.md#time-and-days). Found 2026-11-16.
- Before us: nobody has reported anything that changes on alternate days.

</details>

## Survival

### 🧩 Energy drains faster the longer you stay awake

🎮 Checked in the game (memory).

The energy bar is your life, one number from 0 to 255. Every 10 game minutes it loses 1 point, more if you have been awake for long: 2 after 16 hours awake, 3 after 32, 4 after 48, 8 after 64, 16 after 80 and 32 after 96 hours. A hurt torso multiplies the loss by 1.5 (rounded down, so a loss of 1 stays 1), 2 or 4 depending on how bad it is. Every sixth drain also takes an extra amount set by the weapon in your hand (0 for the starting one). A nap of one hour takes 4 hours off the awake count; a full sleep resets it and lasts 7 hours, or until 08:00 when you go to bed from 21:00 to 02:59. Below a quarter of the bar, a warning sound starts, and stops when the bar rises again. Being changed cancels the awake-time part (see [being changed](#-being-changed-is-one-flag-a-pink-body-fast-healing-and-no-fatigue)).

<details><summary>Technical details</summary>

- Proof: `event_clock_tick` sets `player_status.drain_pending` when the minute modulo 10 equals `action_vars.drain_minute`; `event_update_hud` sees it and calls `event_drain_gauge` (0x80189AC0, src/game/8018920C.c). That starts from 1 and replaces it by 2, 3, 4, 8, 16 or 32 according to `player_status.hours_awake >> 4` (`0x801E0746`) unless `player_status.mutant` is set, multiplies by 3/2 rounded down, 2 or 4 for level 1, 2 or 3 of `limb_state[3]` (the torso), adds `unk24` of the record `effect_weapon_find` returns for the weapon in the current slot every sixth call (counter `action_vars.drain_count`), clears `player_status.infected` and subtracts the total from `player_status.energy` (`0x801E0710`). `event_draw_gauge` clamps it at 0, draws the bar, calls `sound_se_play(4)` under a quarter and `sound_se_stop(4)` above it or at 0. `event_clock_add_minute` adds one to `hours_awake` each game hour unless its fourth argument is set, as it is for sleep. `player_rest` (src/game/80195DF0.c) skips 60 minutes and takes 4 off `hours_awake` for one kind of rest; for the other it clears it and skips 420 minutes, or the minutes left until 08:00 when the hour is above 20 or below 3.
- In game: with the clock period forced to 6 (10 game minutes in 60 vsyncs) and energy forced to 250, the drop per drain was 1, 2, 3, 4, 8, 16 and 32 for hours awake 0, 0x18, 0x28, 0x38, 0x48, 0x58 and 0x68, five drains each. With hours awake 0x38 (base 4) and torso damage forced to levels 1, 2 and 3, the drops were 6, 8 and 16. The sixth-drain extra was 0 with the starting equipment. Which rest is the nap and which the night's sleep is read from the durations only.
- Question: [6 and 10](mysteries.md#survival). Found 2026-11-16, checked the same day.
- Before us: players knew the bar drains, that sleep and food matter and that fatigue speeds up the loss (Japanese Wikipedia, GameFAQs); GLADIATOR's infinite energy code already wrote 200 to `0x801E0710`. New here: the drain step, the awake-time table, the torso multiplier and the weapon's share.

</details>

### 🔄 Body part damage heals by the hour, unless it is at the worst level

🎮 Checked in the game.

<img src="img/game/limbs-order.png" alt="The HUD body figure, enlarged: red head, yellow arm on the screen's left, blue arm on the screen's right, green torso and legs" width="24%"> <img src="img/game/limbs-levels.png" alt="The HUD body figure with yellow head and legs, red left arm, blue right arm and green torso" width="24%">

The five body part values are, in order: the head, the arm on the left of the screen, the arm on the right of the screen, the torso and the legs. Each holds damage. Below 16 the part is fine (green), from 16 it is yellow, from 166 red, and from 240 blue, the worst; the value never goes above 240. Every game hour, each part that is not blue heals 4 points. A blue part never heals by itself; it needs treatment. One oddity: the figure and the stored levels only change when something redraws them (a hit, an item, a cure), not when a part heals by the hour. While you are changed, when every part heals fast, a part keeps its old colour, and a part marked blue keeps the blue mark, until the next redraw.

<details><summary>Technical details</summary>

- Proof: the five damage values are `action_vars.limb_damage[0..4]`, `0x801E041C` to `0x801E0424`, the halfwords the "InfLimbHealth" cheat zeroes. `event_draw_limb_status` (0x80189DE8, src/game/8018920C.c) turns each into a level in `player_status.limb_state[i]` (thresholds `0x10`, `0xA6`, `0xF0`, clamping at `0xF0`) and writes palette entry `0x40 + i` from `event_limb_colors` (0x801D7730): green (10,31,0), yellow (31,31,0), red (31,0,0), blue (0,0,31), and pink (31,10,31) for an undamaged part while `player_status.mutant` is set. The hourly branch of `event_clock_add_minute` subtracts 4 from each part whose stored level is not 3, or 16 from every part when `mutant` is set. It never calls `event_draw_limb_status`; `event_update_hud` does when `player_status.limb_redraw` is set.
- In game: damage forced to 0xB0, 0x20, 0xF0, 0, 0 with `limb_redraw` (`0x801E0756`) set: red head, yellow arm on the screen's left, blue arm on the screen's right, green torso and legs (first picture). With 0x20, 0xB0, 0xF0, 0x08, 0x60, torso green and legs yellow tell the last two apart (second picture). Over two game hours every part lost 4 per hour except the one at 0xF0: the values went from 32, 176, 240, 8, 96 to 24, 168, 240, 0, 88. The changed flag was then forced with a redraw, and over two more hours every part lost 16 per hour, the one at 0xF0 included, down to 0, 136, 208, 0, 56, while the stored levels stayed 1, 2, 3, 0, 1 and the figure kept its colours.
- Question: [8](mysteries.md#survival), partly: what each part does besides the torso's drain multiplier is open. Found 2026-11-16, checked the same day.
- Before us: the five parts, green, red and blue, and the chiropractor (fandom wiki, manual); the cheat author's order was left arm, torso, legs, right arm, head. Corrected here: the order is head, arm, arm, torso, legs, and there is a yellow step between green and red. New: the thresholds, the hourly healing and the stale level.

</details>

### 🔄 Energy at 0 is death, and only a hit to the head makes you wake up changed

🎮 Checked in the game (energy and flag forced).

<img src="img/game/energy0-fall.png" alt="The view dropped to the floor of the office after energy reached 0" width="32%"> <img src="img/game/energy0-game-over.png" alt="The GAME OVER screen with its closing narration" width="32%"> <img src="img/game/mutant-wakes-in-mine.png" alt="The player awake in the coal mine among mutants, the body figure pink" width="32%">

When energy reaches 0 you fall to the ground. What comes next depends on one flag: if an enemy hit you on the head since the last 10-minute energy tick, you wake up changed in the coal mine with a full bar. Otherwise it is GAME OVER, a short closing narration, and back to the title screen. Starving to 0 always goes through an energy tick, which clears that flag first, so starving is always game over. Only hits to the head take energy at all; hits elsewhere damage the body part. After the ending, every death is game over.

<details><summary>Technical details</summary>

- Proof: `player_update` (0x801979B4, src/game/80195DF0.c) calls `player_start_death` when `player_status.energy` is 0 or less. After the fall, `player_finish_death` (0x80197688) checks game variable 0x30 (`0x801E03C8`, set after the ending by `object_room_init`) and `player_status.infected` (`0x801E075A`). With 0x30 clear and `infected` set, it refills energy to 255, clears `hours_awake`, sets `mutant` and loads the mine scene through `mail_goto_building(1, "CMN", ...)`; otherwise it sets `0x801E0348`, which ends the game loop in `main`, and `main` starts again at the title. `infected` is set only by `player_take_hit` (0x801981D0) when the hit lands on part 0 (the head) and the attacking person's field +2 (`Npc.unk2`, read as `arg0->unk2`) is non-zero (all 11 people of the mine scene had 1). It is cleared by every energy tick (`event_drain_gauge`), by `player_add_hp` with a negative amount and on every scene entry (`player_place_for_scene`). Only part 0 subtracts the hit from energy.
- In game: energy forced to 0 in the office: the dying flag 0x800 appeared on `player_character.flags`, the view dropped to the floor, then GAME OVER with the narration and the title screen, with the game state reset to day 1 05:00. Energy 0 with `infected` forced to 1: the same fall, then energy 255, `mutant` 1, level and stats 100, and the player awake in the coal mine among mutants with a pink figure.
- Question: [10](mysteries.md#survival). Found and checked 2026-11-16. Not played: a real death in a fight.
- Before us: "stamina at 0 kills outright" (Japanese Wikipedia) and "killed by an enemy, you wake up changed in the mine" (fandom Mutation, GameFAQs), which seemed to disagree. Both hold, and the rule between them is new: a recent head hit from an enemy. Corrected: "being hit lowers stamina" holds for the head only.

</details>

### 🧩 Being changed is one flag: a pink body, fast healing and no fatigue

🎮 Checked in the game (set by the game in one run, forced in others).

<img src="img/game/mutant-figure.png" alt="The HUD body figure with the changed flag: torso and legs pink, a red shape around the head" width="24%">

Being "changed" is one flag in memory, at `0x801E073C`. The game sets it when you wake up in the mine (see above) and clears it when the hospital cures you. While it is set, the undamaged parts of the body figure turn pink and a shape appears around the head; every body part heals 16 points an hour, even the worst ones; lack of sleep no longer speeds up the energy drain; and your level and ten stats are set to 100, while the game keeps your real ones and puts them back after the cure.

<details><summary>Technical details</summary>

- Proof: `player_status.mutant` (`0x801E073C`) is written only by `player_finish_death` (sets 1), `player_recover` (0x80199370, clears it when its fourth argument is non-zero; its only caller is `block_on_effect_done`) and `menu_card_load` (restores it from the save). On setting it, `player_finish_death` also sets game variable 6 (`0x801E0374`) to 1, saves the level and ten stats into `0x801E03CA` and sets them to 100, and saves game variables 9 to 27 before setting them to 2000; `player_recover` puts everything back and clears palette entry 0x45, the head shape. Readers: `event_drain_gauge` (no awake-time step), `event_draw_limb_status` (pink), `event_clock_add_minute` (16 an hour), `menu_card_save`, `mail_goto_ofc`, `object_room_check_calls`.
- In game: in the death run above, the game set the flag itself, with the pink figure, energy 255 and level and stats 100. Forced on another state: the undamaged torso and legs turned pink and the head shape appeared (picture); with hours awake at 0x68, the drain stayed 1 per 10 minutes instead of 32, and every part lost 16 an hour, the one at 240 included. The cure by the hospital is read in the code only.
- Question: [7](mysteries.md#survival). Found and checked 2026-11-16.
- Before us: the changed state, enemies turning friendly and the hospital cure (Japanese Wikipedia, fandom Mutation, GameFAQs). New here: its address, the fast healing, the end of fatigue and the stats at 100, which explain why a changed player is so strong.

</details>

## People

### ✅ The profile panel is the lingering thoughts of the dead

🎮 Partly checked: the panel was drawn by a forced call; the way to it in play is read in the code.

<img src="img/game/profile-panel.png" alt="A person's profile panel over the mine: name, job, age, sex, height 260 cm, blood type and lines of text" width="49%">

When you kill someone, walking up to the body and confirming its prompt shows a card: the person's name, job, age, sex, height and blood type, and a few lines of what they were thinking. The translation project had found the code that draws this four-line panel but never saw it in play; it is this card. Mutants have cards too: the mine's twenty people include heights of 250 to 320 cm.

<details><summary>Technical details</summary>

- Proof: `text_draw_line` (0x80182D34) has one caller, `text_show_profile` (0x80183618, src/game/8017EBF8.c), which has one caller, `block_on_action` (case 0xFC, the person trigger), reached on the action button when the current prompt (state 2 of `D_801DFFE8`) has its flag 8. For a dead person (`Npc` byte +0xF equal to 6), `action_run_npc_event` runs the scene's action set 0x400 instead of the person's own. `text_show_profile` finds the person in `object_scene_tables.npc_bodies` (0xCC bytes each: id, height, sex, age, blood type, three 32-byte lines), formats "age, sex, height cm, blood type", draws four lines on sprite 0x40D and sets `0x801E05B6` the first time.
- In game: from a saved state in the mine, the call was forced at the start of `event_update_hud` (a0 = 0x0F, the id of the nearest mutant; pc = `text_show_profile`): the panel appeared with a name, a job, "53, male, 260 cm, AB" and its lines. The real path (kill, walk to the body, confirm) was not played.
- Question: [27](mysteries.md#hidden-and-cut-content). Found 2026-11-16.
- Before us: the manual and Japanese Wikipedia describe the "lingering thoughts" profile; the translation project's disc survey asked what opens the panel. Confirmed: it is that screen, not unused code.

</details>

## Performance

### 🧩 The game times every frame, so a slow machine makes it choppy, not slow

🎮 Partly checked: the frame times were seen in memory.

The game draws at most 30 frames a second. After each frame it measures how many screen refreshes the frame really took and moves doors, text, turning, enemies and timers by that much, and skips animation frames when it runs late. So when the console, or an emulator, cannot keep up, the game gets choppy rather than slower. The clock does not depend on it at all. In the emulator used here the office runs at full speed (30 frames a second) and the coal mine at 12 to 15.

<details><summary>Technical details</summary>

- Proof: `kaj_view_flip` (0x801D1AAC, src/kaj/801D12A8.c) waits with `VSync(2)` (never faster than every second refresh), reads `VSync(-1)` and stores the refreshes since the previous frame in `kaj_system.vsync_delta` (`0x801E6DB4`). Doors, texts, turning, enemy AI and timers add `step * speed`; `mod_set_anim` (0x8018DA2C) moves model animations 1 frame per draw for a step up to 3, 2 for 4 or 5, 3 for 6 or more. The clock counts vertical blanks in an interrupt ([the clock](#-the-clock-counts-minutes-and-stops-at-day-99)).
- In game: `0x801E6DB4` read 2 in the office, 4 to 5 in the mine and 9 on the title screen (PCSX-Redux, dynamic recompiler).
- Question: [31](mysteries.md#bugs), partly: why players still need 190 % CPU is read in the code only; no run with another emulated CPU speed. Found 2026-11-16.
- Before us: the advice to run DuckStation at 190 % CPU (Romhack Plaza) and the translation project's "frame step, 3 normally". New here: the step is measured each frame, 2 at full speed, and what it drives.

</details>

## The disc

### ✅ The movie on the disc can never play

📖 Read in the code only.

The disc carries two identical 50 MB video files, `M.STR` and `D.STR`, dated 1995-10-20, four years before the rest of the disc. Players who extracted them describe spacecraft flying through a canyon and into space, and say the game never shows it. The code agrees: the executable never names either file and has no code that drives the PlayStation's video decoder, so the movie cannot play.

<details><summary>Technical details</summary>

- Proof: the executable's strings name `\RES.R;1`, `\SCE.S;1`, `\S\%s.S;1`, `\S\OFC.S;1`, `\S\TWN.S;1`, `\B\%c\%s.B;1`, `\M\%c\%s.RM;1`, `\F\%c\%s.F;1` and the three `\C\CITY.*` files, and no string containing `STR`. Nothing in `src/` touches the decoder registers at `0x1F801820`, and no streaming or decoder library function (`StSetStream`, `StGetNext`, `DecDCT*`) appears in `config/` (which lists the linked Psy-Q functions in `symbol_addrs.psyq.txt`) or `src/`. `cmp` finds the two files identical; their ISO dates are 1995-10-20 against 1999-06-14 for `RES.R`.
- In game: nothing to check; the files play in standard STR players.
- Question: [21](mysteries.md#hidden-and-cut-content). Found 2026-11-16.
- Before us: players already said there is no way to see the movie (atwiki, GameFAQs). New here: the proof that no code can open it.

</details>

### 🆕 The game still names scene files the disc does not have

📖 Read in the code only.

All 24 scenes live in one big file, `SCE.S`. Yet the game still writes the path of a separate file for each scene, such as `\S\OFC.S` for the office and `\S\TWN.S` for the town, and these files are not on the disc. The loader ignores those paths: it opens `SCE.S` and jumps to the scene through a table of offsets. One guess is that the scenes were separate files earlier in development and were packed together late; the code does not prove it.

<details><summary>Technical details</summary>

- Proof: two functions in src/game/8018ACAC.c store `"\\S\\OFC.S;1"` and `"\\S\\TWN.S;1"` in a scene descriptor's `unkC`, and src/game/80179848.c builds `"\\S\\%s.S;1"` with `sprintf` before calling `object_load_scene`. `object_load_scene` (src/game/8018FA18.c) calls `object_iff_open(&ctx, 0, scene)`, which only ever calls `CdSearchFile` on `"\\SCE.S;1"` (or `"\\RES.R;1"` for resources) and seeks by the offset in `object_sce_offsets[scene]` (`object_res_offsets` for `RES.R`). The other `CdSearchFile` calls, in src/kaj/801D1E70.c, take their path from their caller.
- In game: not checked.
- Question: [22](mysteries.md#hidden-and-cut-content). Found 2026-11-16.
- Before us: nobody had written about these paths.

</details>
