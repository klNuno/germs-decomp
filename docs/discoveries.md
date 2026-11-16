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

Function and variable names below are the decompilation's placeholder names (`func_XXXXXXXX`, `D_XXXXXXXX`, `unkXX` fields), since a real name needs evidence first. Addresses are in the executable `SLPS_021.07` as loaded in memory. The source files named are in this repository's `src/`.

## The findings at a glance

Every finding here comes from reading the decompiled code in `src/` and the symbol list in `config/`; none has been checked in an emulator yet.

Time
- 🧩 [The clock counts minutes and stops at day 99](#-the-clock-counts-minutes-and-stops-at-day-99): one game minute every 600 screen refreshes, 10 seconds, which is the 6x speed players measured.

Survival
- 🧩 [Energy drains faster the longer you stay awake](#-energy-drains-faster-the-longer-you-stay-awake): the drain doubles after 16 hours awake and reaches 32 times after 96; damage to the fourth body part multiplies it again.
- 🧩 [Body part damage heals by the hour, unless it is at the worst level](#-body-part-damage-heals-by-the-hour-unless-it-is-at-the-worst-level): a part in the worst state never heals by itself.

The disc
- ✅ [The movie on the disc can never play](#-the-movie-on-the-disc-can-never-play): no code opens it and no video decoder is in the game.
- 🆕 [The game still names scene files the disc does not have](#-the-game-still-names-scene-files-the-disc-does-not-have): the game still builds paths to files the disc does not have, then ignores them.

## Time

### 🧩 The clock counts minutes and stops at day 99

📖 Read in the code only.

The game clock moves one minute at a time. A timer counts screen refreshes and, every 600 of them, sends a "clock" event; at 60 refreshes a second that is one game minute every 10 seconds, so six game minutes per real minute, which matches the 6x speed players report. The number 600 is the value a known cheat writes to stop or speed up time: it is the period itself, so 2 makes a minute pass every two refreshes and 0xFFFF makes one pass about every 18 real minutes. At 60 minutes the hour goes up, at 24 hours the day goes up, and the day counter stops at day 99 (it shows day 99 forever after). Once per game hour, body part damage heals a little (see below) and, unless the hours were skipped by sleeping, an "hours awake" counter goes up.

<details><summary>Technical details</summary>

- Proof: `kaj_timer_init` (0x801D0300, src/kaj/801CFD70.c) opens an event on root counter 3 (`0xF2000003`, the vertical blank counter) with `kaj_timer_handler` as handler and sets `D_801E6DA0.unk10`, which is `0x801E6DB0`, to `0x258` (600). `kaj_timer_handler` increments a tick count and, when it is a multiple of `kaj_timer_period`, posts event 4 with `kaj_event_push(4)`. The game's event loops (src/game/801A3DD4.c, 8018FA18.c, 801A7560.c) answer event 4 with `event_handle_tick`, which calls `event_clock_tick` and then `event_clock_add_minute` (src/game/8018920C.c). `event_clock_add_minute` adds one to the minute (`D_801E0368` halfword 0x3F, address `0x801E03E6`), carries into the hour (0x3E, `0x801E03E4`) at 60 and into the day (0x3D, `0x801E03E2`) at 24, clamps the day to 98, and stores the parity of the zero-based day counter in halfword 0x40 before that clamp: 1 when the displayed day is even. Once the counter sits at 98, every midnight raises it to 99 (parity 1) and clamps it back, so the flag stays 1. The on-screen digits are drawn by `event_draw_clock_digits`, which shows the stored day plus one. Time skips (sleep, naps, other calls) go through `event_advance_clock`, which runs `event_clock_add_minute` once per skipped minute.
- In game: not checked. The cheat values come from the DuckStation cheat file listed in community-knowledge.md.
- Question: [1, 2 and 5](mysteries.md#time-and-days). Found 2026-11-16.
- Before us: the 6x speed (Japanese Wikipedia, GameFAQs) and the address with its 600, 2 and 0xFFFF values (DuckStation cheat file). New here: what the 600 counts, the one-minute step and the day 99 limit.

</details>

## Survival

### 🧩 Energy drains faster the longer you stay awake

📖 Read in the code only.

The energy bar is one number from 0 to 255. Every 10 game minutes it loses 1 point, more if you have been awake for long: 2 after 16 hours awake, 3 after 32, 4 after 48, 8 after 64, 16 after 80 and 32 after 96 hours. Damage to one body part multiplies the drain again, by 1.5 (rounded down, so a base drain of 1 stays 1), 2 or 4 depending on how hurt it is. That is the fourth of the five body part slots; which part of the body it is has not been confirmed. Every sixth drain also takes an extra amount read from a record the game picks from the player's current state. A nap of one hour takes 4 hours off the awake count; a full sleep resets it and lasts 7 hours, or until 08:00 when you go to bed from 21:00 to 02:59. When the bar falls below a quarter, the game starts a warning effect, and stops it when the bar rises again; players describe a heartbeat at low energy.

<details><summary>Technical details</summary>

- Proof: `event_clock_tick` sets the flag `D_801E0710.unk44` when the minute modulo 10 equals `D_801E0368.unk1FE`; `event_update_hud` sees the flag and calls `event_drain_gauge` (src/game/8018920C.c). `event_drain_gauge` starts from 1, replaces it by 2, 3, 4, 8, 16 or 32 according to `D_801E0710.unk36 >> 4` (hours awake, `0x801E0746`) unless `D_801E0710.unk2C` (`0x801E073C`) is set, multiplies by 3/2 rounded down (`(n * 3) >> 1`), 2 or 4 for level 1, 2 or 3 of `D_801E0710.unk3A[3]`, adds `unk24` of the record `effect_weapon_find` returns every sixth call (counter `D_801E0368.unk1FC`), and subtracts the result from `D_801E0710.unk0` (`0x801E0710`). `event_draw_gauge` clamps it at 0, draws the bar (`unk0 * 36 / 255` cells), calls `sound_se_play(4)` when `(unk0 << 12) / 255` falls under `0x400` and `sound_se_stop(4)` when it rises again or hits 0. `event_clock_add_minute` increments `unk36` each game hour unless its fourth argument is set, which the time-skip function `event_advance_clock` passes as 1 from the sleep code. `player_rest` (src/game/80195DF0.c) skips 60 minutes and takes 4 off `unk36` for one kind of rest; for the other it clears `unk36` and skips 420 minutes, or, when the hour is above 20 or below 3, the minutes left until 08:00 (660 at 21:00, 480 at 00:00). `player_finish_death` refills `unk0` to `0xFF` and clears `unk36`.
- In game: not checked. Which rest is the nap and which the night's sleep is read from the durations only.
- Question: [6, 7 and 10](mysteries.md#survival). Found 2026-11-16.
- Before us: players knew the bar drains, that sleep and food matter and that fatigue speeds up the loss (Japanese Wikipedia, GameFAQs); GLADIATOR's infinite energy code already wrote 200 to `0x801E0710`. New here: the drain step, the awake-time table and the body part multiplier.

</details>

### 🧩 Body part damage heals by the hour, unless it is at the worst level

📖 Read in the code only.

Each of the five body parts holds a damage value. Below 16 it is undamaged, from 16 it is level 1, from 166 level 2, and from 240 level 3, the worst; the value never goes above 240. Every game hour, each part that is not at level 3 heals 4 points. A part at level 3 does not heal by itself; it needs treatment. When the flag that also cancels the awake-time drain is set, every part heals 16 points an hour, level 3 included, and undamaged parts take a different colour on the body display.

<details><summary>Technical details</summary>

- Proof: the five damage values are `D_801E0368.unkB4[0..4]`, addresses `0x801E041C` to `0x801E0424`, the halfwords the "InfLimbHealth" cheat zeroes. `event_draw_limb_status` (src/game/8018920C.c) turns each into a level in `D_801E0710.unk3A[i]` (thresholds `0x10`, `0xA6`, `0xF0`, clamping at `0xF0`) and colours palette entry `0x40 + i` from the table `event_limb_colors`, using colour 4 for level 0 when `D_801E0710.unk2C` is set. The hourly branch of `event_clock_add_minute` subtracts 4 from each part whose level is not 3, or 16 from every part when `unk2C` is set.
- In game: not checked. The order of the five parts is not read from the code; the cheat author's list is the only source.
- Question: [7, 8 and 11](mysteries.md#survival). Found 2026-11-16.
- Before us: the five parts, their colours and the chiropractor (fandom wiki, manual). New here: the thresholds, the hourly healing and the level at which it stops.

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
