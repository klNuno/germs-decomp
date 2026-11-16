# What the community already knows

What players, wikis and earlier projects knew about Germs: Nerawareta Machi (SLPS-02107, KAJ, 1999-07-22) when this project started, gathered on 2026-11-16. "Code" means read in the game's code or data by an earlier project; "observed" means seen by players; "rumour" means said without evidence anyone can check. Nothing here is trusted until this project's own code reading confirms it; where the code already answers, the row says "Our check" and links to [discoveries.md](discoveries.md). Open questions are in [mysteries.md](mysteries.md).

Source keys used in the tables (full URLs in [Sources](#sources)): **fandom** (the Germs fandom wiki, page named after it), **jawiki** (Japanese Wikipedia), **atwiki** (Game Catalog @Wiki), **HG101** (Hardcore Gaming 101), **GameFAQs** (the FAQ by whowasphone404, v2 of 2025-01-07), **hiddenblur** (the Germs-english translation project's docs), **pastebin** (DuckStation cheat file linked from Romhack Plaza), **nico** (niconico video descriptions, by video id), **manual** (as transcribed on the fandom Manual page).

## Game rules

| Topic | Known | Status | Source |
|---|---|---|---|
| Clock | Game time runs 6 times faster than real time; the clock (day, hour, minute) is always on screen | observed | jawiki, GameFAQs how-to-play |
| Clock period | A cheat writes 0x0258 (600) to 0x801E6DB0 as "normal" time, 2 as fast, 0xFFFF as stopped. Our check: 600 is the number of vertical blanks between two clock events, one game minute; the day counter stops at day 99. Both seen in the emulator ([the clock](discoveries.md#-the-clock-counts-minutes-and-stops-at-day-99)) | code | pastebin TimeControl |
| Time skips | The 24-hour chiropractor can pass time until the next event; the office sofa allows a nap up to twice a day; the hotel lets you sleep. Our check: the chiropractor sells three courses of 1, 3 and 6 hours that take 60, 180 or 360 points of damage off every body part; with no wound they only pass the time, seen in the emulator ([the chiropractor](discoveries.md#-the-chiropractor-sells-time-1-3-or-6-hours-that-heal-as-much)) | observed | jawiki, GameFAQs buildings |
| Invasion progress | Each building has its own timeline: before invasion, invaded, freed, and "whole city at peace"; the office computer's city overview shows a state 0 to 4 per building (4 if you have "changed") | observed | manual p.2, fandom Indenco |
| No fixed order | No set order of play; an action in one building can set a flag that changes another building's story | observed | manual p.2, jawiki |
| Emails | 32 emails; some arrive at fixed times (Naomi day 1 21:00, Sakaguchi day 1 17:00, Indenco days 1 to 3 at 10:00, a mine email day 4 12:00), others after quest steps. Our check: the timed ones are a list in the code; it confirms these four times and adds day 2 at 16:00 and day 3 at 14:00 ([the timed mails](discoveries.md#-the-timed-mails-are-written-in-the-code-for-days-1-to-4)) | observed | fandom Emails |
| Stats | HP (healed at the hospital or the chiropractor), fatigue (sleep or nap), stamina (food); stamina at 0 kills you; high fatigue makes stamina fall faster; being hit lowers stamina. Our check: stamina is one energy value that is your life; fatigue is an hours-awake counter that multiplies its drain; only head hits take energy ([energy](discoveries.md#-energy-drains-faster-the-longer-you-stay-awake), [energy at 0](discoveries.md#-energy-at-0-is-death-and-only-a-hit-to-the-head-makes-you-wake-up-changed)). The hospital and the chiropractor heal the body parts, never the energy bar ([the hospital](discoveries.md#-the-hospital-heals-every-wound-at-once-for-free-and-without-losing-time), [the chiropractor](discoveries.md#-the-chiropractor-sells-time-1-3-or-6-hours-that-heal-as-much)) | observed | jawiki, GameFAQs how-to-play |
| Energy bar | The fandom wiki describes one "health" bar that drains slowly and is refilled by eating; a heartbeat plays when it is low. GLADIATOR's infinite energy code writes 200 to 0x801E0710. Our check: one energy value at 0x801E0710 drains a little each tick, faster the longer you stay awake, and a low-energy warning starts below about a quarter ([energy](discoveries.md#-energy-drains-faster-the-longer-you-stay-awake)) | observed | fandom Player, psxdatacenter |
| Body parts | Five body parts take damage separately (colour green, red, then blue); the chiropractor heals them; leg damage slows walking and running. The cheat "InfLimbHealth" zeroes five halfwords at 0x801E041C to 0x801E0424 (left arm, torso, legs, right arm, head, per its author). Our check: the order is head, arm, arm, torso, legs (not the cheat author's), with a yellow level between green and red; parts heal 4 points a game hour except at the worst level, seen in the emulator ([body parts](discoveries.md#-body-part-damage-heals-by-the-hour-unless-it-is-at-the-worst-level)). Leg damage slows walking to 90 % at red and 70 % at blue, measured in the emulator; the arm on the left of the figure also lowers the hit chance ([hurt legs and arm](discoveries.md#-hurt-legs-slow-you-down-and-one-hurt-arm-spoils-your-aim)) | observed | fandom Player, manual, pastebin |
| Food | No money: every restaurant, deli and fast-food place is free; eating too much makes you sick and hurts you; take-away food can be eaten anywhere indoors. Our check: confirmed, the shop code reads no money; the sickness comes from eating on a full bar, costs half the dish's value and puts its whole value on the torso, seen in the emulator ([food](discoveries.md#-food-adds-a-fixed-amount-of-energy-and-eating-on-a-full-bar-hurts-your-torso)) | observed | atwiki, GameFAQs how-to-play, fandom Player |
| Combat | No hitbox: a marker appears over a target in range, and pressing attack rolls against the weapon's accuracy; each hit raises that weapon's accuracy. Our check: a roll of 0 to 99 against the hit chance, cut by range; each hit raises the class level, which raises the rate only up to what the weapon asks for, seen in the emulator ([the hit roll](discoveries.md#-every-shot-is-a-roll-against-the-hit-chance-and-range-cuts-both-chance-and-damage)) | observed | jawiki, atwiki, GameFAQs |
| Weapon experience | Each weapon class has experience shown on a blue wheel; two weapons of one type share it. A cheat sets five 32-bit class values at 0x801E0724 to 0x801E0737 to 0x3B2A005D, which it calls one point below the maximum. Our check: corrected; the blue wheel is the current weapon's hit rate, each class value is a level (1 to 100) and the experience toward the next, `0x3B2A005D` is level 93, and a class holds one to five weapons ([the blue wheel](discoveries.md#-the-blue-wheel-is-the-weapons-hit-rate-and-the-five-classes-are-levels-up-to-100)) | observed | fandom Weapons, pastebin |
| Weapons carried | Two at a time; the rest are left with the assistant at the office | observed | jawiki, fandom Weapons |
| Weapon list | 18 weapons: 13 ordinary (Baton to Boomerang) and 5 specials (Cloud Buster, Electromagnetic Wave gun, Gravity Field weapon, Crystal, Hieronymus Machine) | observed | fandom Weapons |
| Gun shop WILD ARMS | Sells six weapons at a time, chosen by your level (0 to 19, 20 to 39, 40 and up); one purchase at a time | observed | fandom Weapons, atwiki, manual |
| Unobtainable weapons | "A normal player would never see some of the weapons" because of how the shop works; a cheat scrolls weapon slots 0x00 to 0x11 at 0x801E0774 and 0x801E0776 | rumour | Romhack Plaza comment of 2025-04-05, pastebin |
| Minimum weapons | The Self Defense Pistol and the Electromagnetic Wave weapon are the minimum to finish the game | observed | fandom Weapons |
| Killing civilians | Anyone can be killed, shop staff included; important NPCs come back; too many kills gets you arrested. Our check: 3 civilian kills give the first arrest, the next time the office loads; mutants never count ([arrests](discoveries.md#-three-civilian-kills-get-you-arrested-and-five-more-the-second-time)) | observed | manual p.2, GameFAQs, jawiki |
| Arrests | Two arrests turn the police station into an enemy building. Our check: the second arrest comes after 5 more kills and sets one story flag; that this flag is the police station's state is not checked ([arrests](discoveries.md#-three-civilian-kills-get-you-arrested-and-five-more-the-second-time)) | observed | jawiki, GameFAQs buildings |
| Respawning enemies | Most "changed" people in the hospital come back when you leave and re-enter; one hospital worker comes back however often you kill him | observed | jawiki, nico sm1144846 |
| Lingering thoughts | Killing anyone shows a profile: name, job, age, sex, height, blood type and a short text. Our check: confirmed: the four-line panel the translation project found is this card, opened by walking into the body and pressing CIRCLE, seen in the emulator ([the profile panel](discoveries.md#-the-profile-panel-is-the-lingering-thoughts-of-the-dead)) | observed | manual p.2, jawiki |
| Text colour | Changed people's lines are shown in yellow; the manual tells you to watch the line colour | observed | fandom Mutation, manual p.2 |
| Death and mutation | Killed by an enemy, you wake up "changed" on the first level of the Yamasaki coal mine; enemies become friends and humans attack you. Our check: only when an enemy hit your head since the last energy tick; otherwise death is game over ([energy at 0](discoveries.md#-energy-at-0-is-death-and-only-a-hit-to-the-head-makes-you-wake-up-changed)). The changed state is the flag at 0x801E073C ([being changed](discoveries.md#-being-changed-is-one-flag-a-pink-body-fast-healing-and-no-fatigue)) | observed | jawiki, fandom Mutation, GameFAQs |
| Cure | The hospital cures the mutation at any time; afterwards people act as if nothing happened. Our check: confirmed in the emulator: the cure is the injection on the exam bed; it gives back your real level and stats, heals every part and costs no time ([being changed](discoveries.md#-being-changed-is-one-flag-a-pink-body-fast-healing-and-no-fatigue)) | observed | fandom Mutation, nico sm1144846 |
| Mutant play is a dead end | As a mutant the story does not advance; the gun shop sells better weapons | observed | nico sm986645 |
| Death by stamina | Stamina at 0 kills outright. Our check: confirmed, and starving is always game over, never the mine ([energy at 0](discoveries.md#-energy-at-0-is-death-and-only-a-hit-to-the-head-makes-you-wake-up-changed)) | observed | jawiki |
| Saving | In the office diary or at a public phone, one memory card block. Our check: the block holds a 508-byte buffer, 464 bytes of game state and 44 left zero, each quarter written twice with a checksum ([the save](discoveries.md#-a-save-holds-464-bytes-of-game-state-stored-twice-with-checksums)) | observed | manual p.7, jawiki |
| Car | Called to any public phone by the assistant; gets stuck on kerbs and in tunnels, then must be called again; you can look around while driving | observed | atwiki, GameFAQs how-to-play |
| Bus | Three lines (C101, C102, C103); choosing a stop moves you there at once | observed | fandom Bus Lines, atwiki |
| Subway and mine railway | Both run, empty | observed | atwiki, jawiki |
| Loading | No loading inside the city or inside a building; long loads when entering the car, a building or the street | observed | atwiki, GameFAQs |
| NPC warping | Companions warp into event rooms instead of walking; Fujita does it most | observed | atwiki, GameFAQs, HG101 |
| Final boss reveal | The last mutant says it is the "changed" other you | observed | fandom Final Mutants, atwiki, nico sm1122301 |
| After the final boss | The assistant comes to the mine to help you | observed | nico sm1122301 |
| Ending | Sources disagree: atwiki and nico sm1123083 say there is no ending, HG101 says "no real ending"; fandom, GameFAQs and a 2025 essay say an ending narration plays, then you are back in the office and free to roam with buildings closed | observed | atwiki, HG101, fandom, GameFAQs, Big Picture Mode |
| No ending, on purpose | The developers called the missing ending deliberate | rumour | atwiki (no source given) |
| Hidden Kouda reward | Clearing the hospital sends you one way from the morgue to mine level 2, which skips the Kouda reward (M47 Dragon); go back after meeting the third agent, or leave Naomi on mine level 2 and return | observed | nico sm1148359 |
| Fujita's two weapons | If Fujita comes along when a building is freed, he builds the laser and the gravity weapons from parts found there | observed | jawiki |
| Power plant without Fujita | Going alone means you do not learn what the basement device is; Fujita then asks by email to see it | observed | fandom Hiroshi Fujita, fandom Emails |
| Speedrun | Any% on speedrun.com, timed from the first input after the opening narration to the first letter of the ending narration; best time 28:23 (2025-07-13); a 2026 run blames "mines RNG" | observed | speedrun.com |

## World and places

| Topic | Known | Status | Source |
|---|---|---|---|
| Town | An unnamed former coal town in rural America with many residents of Japanese descent, sea to the south and mountains on three sides; GameFAQs calls it "Newtown" after the hospital's name | observed | jawiki, fandom City, GameFAQs |
| Size | 2.5 km square on the back insert and the KAJ brochure; 3 km square in the manual, jawiki and GameFAQs; fandom says "about 3 square kilometers" | observed | earlier survey links, jawiki, fandom City |
| Streaming | The town is cut into 50 m square blocks loaded around the player; the idea led KAJ to splume | observed | jawiki, GameFAQs |
| Grey exteriors | Outdoors is grey, with brightness changing by time of day; interiors are in colour; red arrows mark enterable buildings | observed | jawiki, fandom, HG101 |
| Colour early on | The town was in colour early in development and was made black and white "to look like old SF dramas" | rumour | atwiki (no source given) |
| Empty streets | No pedestrians and no traffic outside | observed | jawiki, atwiki |
| Faceless people | Most people have no face texture; a few key ones have photo faces. A 2011 player guessed that every face was planned at first | observed / rumour | atwiki, HG101, nico sm15696464 |
| Buildings you can enter | Office, power plant, cathedral, station, Hotel Seasons, hospital, warehouses, Indenco, Temple of the Universe, underground waterway, Yamasaki mine, police station, Fujita's and Fukada's houses, restaurants, deli, chiropractor, map shop, gun shop | observed | jawiki, GameFAQs buildings |
| City Hall | Cannot be entered, but a blue door texture sits behind its arches, and the bus map marks it as a building, like the Yamasaki mansion and two South End buildings | observed | fandom City Hall |
| Warehouse layout | Two exits shown far apart on the map are a few steps apart inside | observed | fandom Seaside Warehouse |
| Maps | The map shop sells six maps that add a compass marker for one building | observed | fandom Map Shop |
| Underground waterway | Links the Temple, the cathedral, the hospital and the mine | observed | jawiki, GameFAQs buildings |
| Music | Only indoors, short MIDI loops of about 14 seconds; no music outside or during the closing narration; the hotel track is noise | observed | fandom Soundtrack, atwiki |

## Bugs and oddities

| Topic | Known | Status | Source |
|---|---|---|---|
| Boss music | Killing a boss before entering its dialogue radius skips the boss music, which can then start after the boss is dead | observed | fandom Soundtrack |
| Komuro fight | The coal mine music keeps playing under the boss music | observed | fandom Soundtrack |
| Car stuck | The car catches on kerbs and tunnel edges; only a phone call frees it | observed | atwiki |
| Analog pad | With the pad in analog mode no button works, because the BIOS pad routine the game uses only fills its button word for digital pads and neGcon | code | hiddenblur controls.md |
| Opening fade | The office fades in at an exact narration index (426 bytes for the opening, 386 for the ending); a text that steps over or stops short of it leaves the screen black | code | hiddenblur disc-survey.md |
| Slowdown | Players advise running DuckStation's CPU at 190 %. Our check: the game measures each frame and scales movement by it, 30 frames a second at best, so a slow emulator makes it choppy ([frame timing](discoveries.md#-the-game-times-every-frame-so-a-slow-machine-makes-it-choppy-not-slow)) | observed | Romhack Plaza comment |
| Misspelling | The game spells the Hieronymus machine "ヒエロニスム" | observed | jawiki, nico sm1148359 |
| Naomi | She cannot be targeted, yet she has a profile text and a hit animation in the data. Our check, in part: the target picker skips anyone with one flag a scene script can set and clear; whether that is what keeps Naomi out is open ([the hit roll](discoveries.md#-every-shot-is-a-roll-against-the-hit-chance-and-range-cuts-both-chance-and-damage)) | code | fandom Naomi Scully (model viewed in PSXPrev) |

## Hidden and cut content

| Topic | Known | Status | Source |
|---|---|---|---|
| Hidden movie | A movie of two craft flying through a canyon and into space (atwiki), alien craft over another planet (HG101), two fighters flying through structures (GameFAQs); no way to see it in the game. A niconico uploader called it the opening, but it does not play at boot. Our check: the game has no way to open it ([the movie](discoveries.md#-the-movie-on-the-disc-can-never-play)) | observed | atwiki, HG101, GameFAQs |
| Movie origin | Guesses: a test of video playback, or footage from another KAJ project | rumour | GameFAQs |
| Separate scene files | The exe names `\S\%s.S;1`, `\S\OFC.S;1` and `\S\TWN.S;1`, files the disc does not have. Our check: leftovers, the loader only opens `SCE.S` and `RES.R` ([scene files](discoveries.md#-the-game-still-names-scene-files-the-disc-does-not-have)) | code | this project |
| Beta | A 2008 psxplanet post titled the image "Beta"; later posts show it is the retail disc | observed | psxplanet thread |
| Profiles panel | A four-line profile renderer exists in the exe; hiddenblur never saw its screen in game | code | hiddenblur disc-survey.md |

## Technical

- The game is one PS-X EXE, `SLPS_021.07`: loaded at 0x80170000, 0x70000 bytes, entry 0x801C8840, `SYSTEM.CNF` with TCB 4, EVENT 16, STACK 0x801FFF00 (hiddenblur disc-survey.md). It links Psy-Q libraries (LoadImage, StoreImage, Krom2RawAdd, PadRead are named there).
- Disc: one Mode 2 data track, 80,788 sectors, 75 files, volume `GERMS001`, no XA audio, no LibCrypt (Redump, hiddenblur). Files: `SCE.S` (7.0 MB, 24 scenes of script and sound), `RES.R` (3.8 MB, 15 blocks, 209 TIMs, a `WEPN` table of 18 records of 0x60 bytes), `C/CITY.*` (27 MB of town), per-place `B`, `F`, `M` files, and `M.STR` and `D.STR` (48 MB each, byte-identical).
- Text: no font of its own; the game draws the BIOS Kanji ROM glyphs through four routines (hiddenblur). Office computer mails are pictures (240x128 4bpp TIMs in `RES.R`), not text.
- Script: `SCE.S` commands are size-prefixed with string arguments; opcode 0x05 carries text; `AREA` chunks hold 12-byte triggers, `ASET` event records, `ENMY` and `ACTR` chunks (hiddenblur, partly decoded).
- Controls: digital pad only; d-pad turns and looks, Triangle and Cross move, L1 and R1 strafe, L2 or R2 attack, Select opens status and map (hiddenblur controls.md). GameFAQs writes "D-pad: Move" and "Triangle: Advance".
- HUD clock: one 96x32 picture whose seven-segment digits are lit by rewriting palette entries (hiddenblur).
- RAM addresses known from cheats and the translation project:

| Address | What | Source |
|---|---|---|
| 0x801E0710 | Energy (infinite energy writes 200). Also the base of the structure the movement code receives | psxdatacenter (GLADIATOR), hiddenblur controls.md |
| 0x801E041C to 0x801E0424 | Five body-part values | pastebin |
| 0x801E0620 | Player structure (pointer at +0x5C of 0x801E0710) | hiddenblur controls.md |
| 0x801E066A | Speed step (4 to 11 while moving) | pastebin, hiddenblur |
| 0x801E068C, 0x801E068E | Pitch and yaw | pastebin, hiddenblur |
| 0x801E0724 to 0x801E0737 | Weapon class experience, five 32-bit values. Our check: each is a 16-bit level and a 16-bit experience, and a sixth pair at 0x801E0738 is the evasion skill ([the blue wheel](discoveries.md#-the-blue-wheel-is-the-weapons-hit-rate-and-the-five-classes-are-levels-up-to-100)) | pastebin |
| 0x801E0774, 0x801E0776 | The two carried weapon ids (0x00 to 0x11) | pastebin |
| 0x800EB228, 0x800EB22A | Weapon name display | pastebin |
| 0x801E6DA0 | Held pad buttons; previous frame at +4 | hiddenblur controls.md |
| 0x801E6DB0 | Clock period, 600 normally | pastebin |
| 0x801E6DB4 | Frame time step (3 normally) | hiddenblur controls.md |
| 0x801E1158 | Car state (wheel, gear, pedals, speed) | hiddenblur controls.md |
| 0x801E0356 | Scene id (1 opening, 2 ending) | hiddenblur disc-survey.md |
| 0x801D7780, 0x801D7744 | Offset tables of the 24 `SCE.S` scenes and 15 `RES.R` blocks | hiddenblur disc-survey.md |

| Format | Content | Decoded by | State |
|---|---|---|---|
| SCE.S | Scenes: DIR sector, MIDI or VAB, AREA chunks with ASET, ENMY, ACTR | hiddenblur | Container and text complete (rebuilds byte for byte); DIR fields a to d, AREA triggers, ENMY, ACTR unknown |
| RES.R | 15 blocks, TIMs, item and food names, `WEPN` | hiddenblur | Names and pictures read; weapon stats after +0x24 unknown. Our check: every field after +0x24 named from its readers ([the weapon record](discoveries.md#-the-weapon-record-three-requirements-accuracy-damage-and-three-ranges)) |
| C/CITY.MP, .F, .BC | Town map | nobody | Unknown |
| B, F, M (.RM) | Per-place data, three-letter codes (CDL, HTL, PSN) | nobody | Unknown |
| M.STR, D.STR | MDEC video stored as Form 1 data | standard tools | Plays in standard STR tools |
| Memory card save | One block | nobody | Undocumented. Our check: the layout, read in the code ([the save](discoveries.md#-a-save-holds-464-bytes-of-game-state-stored-twice-with-checksums)) |

## Earlier projects

- hiddenblur/Germs-english (MIT, 2026): English translation and analog controls, Python tools, and the docs cited above. It carried a matching decompilation from 2026-10-25 and removed it on 2026-11-10 (commit `fe1de2ff`), reporting 161 matched functions and gcc 2.8.1; that C was never published.
- grundo1561's English patch (v1.2 2024-02-05, v1.8 beta 2026-10-08 with a hacked text routine), built on Mr.Nobody's Spanish patch of 2021-10-10. Its romhacking.net entry was taken down.
- PSXCraver's variable-width English, about 70 % in mid 2026; an earlier team (Dropfeeling, EsperKnight, Kitria40, Plissken___, PSXCraver) shown on the fandom Translations page.
- A Korean patch, v1.0 of 2026-11-09 (Simon-nhelix/nethelix).
- Not found: a TCRF page (unreadable from here), a Data Crystal RAM map, debug codes, a decompilation or disassembly besides the above, any developer interview.

## Staff and development

| Topic | Known | Status | Source |
|---|---|---|---|
| Developer | KAJ (株式会社ケー・エー・ジェー), a CG house founded 1992; "KEJ" on some databases is a misreading | observed | disc label, psxdatacenter, jawiki |
| First game | KAJ's first game, after CG work for NHK | observed | GameFAQs, atwiki |
| Team | Six developers: Masaharu Endo, Chiharu Kajizuka, Izumi Matsumoto, Misako Saito, Masato Hara, Hiroko Ebihara (credits as transcribed, spelling may be off) | observed | fandom, GameFAQs credits, atwiki |
| Print run | About 4,000 copies, "according to the developers" | rumour | atwiki |
| splume | The game's commercial failure and its block streaming led to KAJ's 3D community splume | observed | jawiki (citing ITmedia and Impress Watch), splume history page |
| Influences | Title from Ultraseven episode 8 and the Japanese title of The Body Snatchers; Wilhelm Reich, Tesla's World System, the Hieronymus machine, crop circles; Tetsuo: The Iron Man | observed | fandom, atwiki, GameFAQs, nico sm1144846 |

## Where sources disagree

- Town size: 2.5 km square on the back insert and in the KAJ brochure, 3 km square in the manual, Japanese Wikipedia and GameFAQs, "about 3 square kilometers" on the fandom wiki.
- The ending: "no ending" (atwiki, the uploader of nico sm1123083) or "no real ending" (HG101), against a closing narration followed by free play in a half-closed town (fandom, GameFAQs, the 2025 Big Picture Mode essay). The scene id 2 that hiddenblur reads as the ending suggests the narration exists; what follows it is open.
- The movie: two craft through a canyon and into space (atwiki), an alien spacecraft over another planet (HG101), two fighter planes through structures (GameFAQs). All agree it cannot be seen in the game.
- Controls: GameFAQs lists "D-pad: Move" and "Triangle: Advance"; hiddenblur's reading of the movement code says the d-pad turns and looks while Triangle and Cross move forward and back.
- The energy bar: the fandom wiki calls it health refilled by eating; Japanese Wikipedia and GameFAQs separate HP, fatigue and stamina, with stamina falling faster when fatigue is high. The code has one energy value drained by time awake and body damage ([energy](discoveries.md#-energy-drains-faster-the-longer-you-stay-awake)); fatigue is the hours-awake counter; whether the status screen shows HP as a separate value is open.
- `0x801E0710`: GLADIATOR's code treats it as energy; hiddenblur's controls doc names it the structure the movement code receives. Both hold: energy is the first field of that structure.
- Years away: the protagonist comes back after 20 years (Japanese Wikipedia) or 12 years (fandom Naomi Scully page).
- Death: you wake up as a mutant in the mine (fandom, GameFAQs), while stamina at 0 kills outright (Japanese Wikipedia); whether the second also leads to the mine is not said. Settled by the code and the emulator: both hold, and only a recent head hit from an enemy leads to the mine ([energy at 0](discoveries.md#-energy-at-0-is-death-and-only-a-hit-to-the-head-makes-you-wake-up-changed)).
- Developer: KAJ on the disc and in Japanese sources, "KEJ" on psxdatacenter.

## Sources

Read on 2026-11-16 unless marked.

- Germs fandom wiki, all 117 pages read through its MediaWiki API: https://germs-nerawareta-machi.fandom.com/api.php (pages cited: https://germs-nerawareta-machi.fandom.com/wiki/Germs_Nerawareta_Machi, /wiki/Weapons, /wiki/Final_Mutants, /wiki/Player, /wiki/Mutation, /wiki/Hospital, /wiki/Coal_Mine, /wiki/Soundtrack, /wiki/Robots, /wiki/Bus_Lines, /wiki/Emails, /wiki/Manual, /wiki/Indenco, /wiki/City, /wiki/City_Hall, /wiki/Seaside_Warehouse, /wiki/Map_Shop, /wiki/Hiroshi_Fujita, /wiki/Naomi_Scully, /wiki/Translations, /wiki/Dogs, /wiki/Hotel_Seasons)
- Japanese Wikipedia: https://ja.wikipedia.org/wiki/GERMS_%E7%8B%99%E3%82%8F%E3%82%8C%E3%81%9F%E8%A1%97
- Game Catalog @Wiki (updated 2023-08-29): https://w.atwiki.jp/gcmatome/pages/1521.html
- Hardcore Gaming 101, Kurt Kalata, 2018-01-20 (Wayback copy): https://web.archive.org/web/2025/https://www.hardcoregaming101.net/germs-nerawareta-machi/
- GameFAQs FAQ by whowasphone404: https://gamefaqs.gamespot.com/ps/575588-germs-nerawareta-machi/faqs/80574/introduction, .../faqs/80574/how-to-play, .../faqs/80574/buildings, .../faqs/80574/credits (credits read 2026-11-14)
- hiddenblur/Germs-english: https://github.com/hiddenblur/Germs-english, docs https://github.com/hiddenblur/Germs-english/blob/HEAD/docs/disc-survey.md and https://github.com/hiddenblur/Germs-english/blob/HEAD/docs/controls.md
- DuckStation cheat file: https://pastebin.com/raw/qb9afALA
- psxdatacenter: https://psxdatacenter.com/games/J/G/SLPS-02107.html
- Romhack Plaza, English translation page and comments: https://romhackplaza.org/translations/germs-nerawareta-machi-english-translation-playstation
- speedrun.com: https://www.speedrun.com/germs (read through https://www.speedrun.com/api/v1/runs?game=3698nr3d)
- niconico, read through the snapshot search API (79 videos for "GERMS 狙われた街"): https://www.nicovideo.jp/watch/sm1148359, https://www.nicovideo.jp/watch/sm1144846, https://www.nicovideo.jp/watch/sm986645, https://www.nicovideo.jp/watch/sm1122301, https://www.nicovideo.jp/watch/sm1123083, https://www.nicovideo.jp/watch/sm15696464, https://www.nicovideo.jp/watch/sm3738554
- Big Picture Mode, "Navigating the Nightmare", 2025-06-06: https://bigpicturemode.substack.com/p/navigating-the-nightmare-germs-nerawareta
- Redump disc 45725 (Wayback, read 2026-11-14): https://web.archive.org/web/20260616074933/http://redump.org/disc/45725/
- Disc and manual scans (read 2026-11-14): https://archive.org/details/germs-nerawareta-machi-ps1-hiresscans
- psxplanet thread (Wayback, read 2026-11-14): https://web.archive.org/web/20201112012251/http://psxplanet.ru/forum/showthread.php?t=1408
- KAJ company brochure (read 2026-11-14): https://www.kaj.co.jp/pdf/aboutkaj.pdf
- splume company history (read 2026-11-14): https://www.splume.co.jp/corp_history.html
- Spanish patch on Vimm (read 2026-11-14): https://vimm.net/romhacking/translations/6321
- RetroGameTalk translation thread (read 2026-11-14; unreadable on 2026-11-16): https://retrogametalk.com/threads/germs-nerawareta-machi-ongoing-translation.25432/
- RetroAchievements forum, romhacking.net takedown note (read 2026-11-14): https://retroachievements.org/forums/topic/22355
- Korean patch (read 2026-11-14): https://github.com/Simon-nhelix/nethelix/releases/tag/germs-ps1-v1.0
