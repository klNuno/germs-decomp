# Open questions

What this project wants to learn about Germs: Nerawareta Machi from its code. Each question says why it is still open and where in the code the answer should be. A question is ticked only when the code already answers it, with a link to the entry in [discoveries.md](discoveries.md) that cites the functions and addresses. What players and earlier projects already know: [community-knowledge.md](community-knowledge.md).

36 questions: 7 answered, 29 open, 3 of them partly answered.

## Time and days

- [x] 1. What does the "time control" cheat value at `0x801E6DB0` (600 normally) count? Answered: the number of screen refreshes per game minute, which gives the 6x speed players measured ([the clock](discoveries.md#-the-clock-counts-minutes-and-stops-at-day-99)).
- [ ] 2. What decides when each of the 32 emails arrives? Partly answered: the timed ones are a list in `mail_check_schedule`, twelve mails at eight times on days 1 to 4, four of them under story conditions ([the timed mails](discoveries.md#-the-timed-mails-are-written-in-the-code-for-days-1-to-4)). Open: the story-driven mails and the per-minute hook in `D_801DFEDC`.
- [ ] 3. Does the invasion move on by itself with time, or only through your actions? Players say there is no fixed order, but nobody says whether a building falls if you wait. The hourly call `mail_check_schedule` and whatever sets the per-building state (question 18) would show any timed step.
- [ ] 4. Where are opening hours stored? The hospital keeps short hours and the chiropractor never closes, known from play only. Some code must compare the hour at `0x801E03E4` with a table per building; finding the readers of that halfword would locate it.
- [x] 5. What is the day parity flag for? Answered: its only reader swaps the two menus of one shop between odd and even days ([the shop](discoveries.md#-one-shop-swaps-its-two-menus-on-even-days)). Which shop it is stays to check.

## Survival

- [ ] 6. Where are HP, fatigue and stamina? The emulator shows one energy value at `0x801E0710` that is your life ([energy at 0](discoveries.md#-energy-at-0-is-death-and-only-a-hit-to-the-head-makes-you-wake-up-changed)), drained faster by hours awake (`0x801E0746`, the fatigue players describe) and by torso damage ([energy](discoveries.md#-energy-drains-faster-the-longer-you-stay-awake)). Whether the status screen shows three values built from these needs the status screen code, and the food handler.
- [x] 7. What is the flag at `0x801E073C`? Answered: the "changed" (mutant) state, set when you wake up in the mine and cleared by the cure; it also sets every stat to 100 ([being changed](discoveries.md#-being-changed-is-one-flag-a-pink-body-fast-healing-and-no-fatigue)).
- [ ] 8. Which body part is which, and what does each level do? Partly answered: the order is head, arm, arm, torso, legs, checked on the HUD figure, and the torso multiplies the energy drain ([body parts](discoveries.md#-body-part-damage-heals-by-the-hour-unless-it-is-at-the-worst-level)). Open: what the head, arm and leg levels change; players say leg damage slows you, so the movement code (speed step at `0x801E066A`) and the aiming code should read them.
- [ ] 9. How much food is too much? Players say overeating makes you sick and hurts you. The eating handler, which must raise energy at `0x801E0710`, should hold the limit and the penalty.
- [x] 10. What happens at energy 0? Answered: you fall; it is game over, unless an enemy hit your head since the last energy tick, which wakes you changed in the mine ([energy at 0](discoveries.md#-energy-at-0-is-death-and-only-a-hit-to-the-head-makes-you-wake-up-changed)).
- [ ] 11. What do the chiropractor and the hospital heal? Players say the chiropractor heals limbs; the code shows a part at the worst level never heals by itself. The two places' handlers would show which values they reset and whether a cure costs time.

## Combat

- [ ] 12. How does the accuracy roll work? Players describe a marker and a hit chance that grows with use, with no hitbox. The attack handler, the random number calls near it and the class experience at `0x801E0724` would give the formula.
- [ ] 13. What do the five weapon class values hold? A cheat sets each to `0x3B2A005D`, "one point below the maximum", an odd number for experience. The code that fills the blue wheel would say whether the 32 bits are one counter or two packed halves, and which weapons share a class.
- [ ] 14. How does the gun shop pick its six weapons? The fandom wiki gives three level bands. The shop's handler would show which value is "level", whether a fourth band exists and whether any special weapon can be sold, which settles the "unobtainable weapons" rumour.
- [ ] 15. What are the fields of the 18 `WEPN` records after offset 0x24? Damage, range and accuracy are expected there; the attack code that indexes the table at `RES.R` offset 0x76000 would name them.

## People, police and mutation

- [ ] 16. How many civilian kills get you arrested? Players know two arrests turn the police station hostile but give no count. A kill counter must be incremented in the death handler for people; its reader starts the arrest scene.
- [ ] 17. Which people come back, and when? Important people and most hospital enemies return when you re-enter, and one worker returns every time. The spawn code for a scene's `ENMY` and `ACTR` chunks should hold a "respawn" flag per person.
- [ ] 18. Where is each building's invasion state (0 to 4 on the office computer) stored, and what moves it? Players read it from the computer screen only. The code drawing that screen and the writers of the same values would answer.
- [ ] 19. Is mutant play a dead end? A 2008 player says the story stops while you are changed, and that the gun shop sells better weapons then. The event triggers that test the state from question 7 would show which events are blocked and whether the shop has a second list.

## The ending

- [ ] 20. What happens after the ending narration? Sources disagree between "no ending" and a narration followed by free play in a half-closed town where Naomi leaves and the assistant asks about empty mail. Scene 2 at `0x801E0356` is the ending per hiddenblur; the code that runs after it, and the flags it sets, would settle what changes and whether anything is left to do.

## Hidden and cut content

- [x] 21. Can the movie in `M.STR` and `D.STR` be played from the game? Answered: no, no code opens it and the game has no video decoder ([the movie](discoveries.md#-the-movie-on-the-disc-can-never-play)). What it was made for stays open.
- [x] 22. Does the game read the `\S\%s.S`, `\S\OFC.S` and `\S\TWN.S` files it names? Answered: no, the loader opens `SCE.S` and seeks through an offset table ([scene files](discoveries.md#-the-game-still-names-scene-files-the-disc-does-not-have)).
- [ ] 23. Were City Hall, the Yamasaki mansion and two South End buildings meant to be entered? The bus map marks them as buildings and City Hall has a door texture behind its arches. A door record, a scene or a bus stop entry for them in `SCE.S`, the `B`, `F` and `M` area files or `C/CITY.*` would show planned interiors.
- [ ] 24. Can Naomi be hurt? She cannot be targeted, yet her profile text and a hit animation exist. The target selection code would show whether she is excluded by a flag that some event could clear.
- [ ] 25. Were faces planned for everyone? Most people have no face texture. The people models in the area files and the code that applies their textures would show empty face slots or a shared blank.
- [ ] 26. Was the town once in colour? The rumour has no source. The clock code shades the outdoor fog through `SetFarColor` by time of day; any unused colour path in the town renderer, or colour data in `C/CITY.*`, would support it.
- [x] 27. What opens the profiles panel at `0x80182D34`? Answered: it is the lingering-thoughts card, opened by confirming the prompt of a dead person ([the profile panel](discoveries.md#-the-profile-panel-is-the-lingering-thoughts-of-the-dead)).
- [ ] 28. How does the Kouda reward get skipped? A player found that clearing the hospital sends you one way to mine level 2 and loses the M47 event. The flag the morgue exit sets and the Kouda event's conditions would show the exact rule.

## Bugs

- [ ] 29. Why can boss music start after the boss is dead? Players tie it to the dialogue radius. The boss trigger in the `AREA` chunks and the code that starts the music would show the order of checks.
- [ ] 30. Why does the mine music keep playing during the Komuro fight? The music switch for that fight probably skips the stop call that other bosses use; comparing the two would show it.
- [ ] 31. Why does the game need a faster CPU in emulators? Partly answered: the game measures each frame's real length and scales movement by it, 30 frames a second at best ([frame timing](discoveries.md#-the-game-times-every-frame-so-a-slow-machine-makes-it-choppy-not-slow)), so a slow emulator makes it choppy. Open: a run at another emulated CPU speed, and why 190 % helps.
- [ ] 32. Why does the car snag on kerbs and tunnel edges? The car physics at `0x801AA360` and the collision reader at `0x8017A29C` hold the step height and the stop rule.
- [ ] 33. Does the analog pad bug come from the game or only from the BIOS routine? hiddenblur reads it as the BIOS pad routine leaving the button word empty for analog pads. Our own reading of the pad handler at `0x801E6DA0` would confirm whether the game checks the pad type.

## Data and formats

- [ ] 34. How big is the town? Sources say 2.5 or 3 km square. The block grid in `C/CITY.MP`, with the 50 m block size, would give the real size.
- [ ] 35. What are the `SCE.S` DIR fields a to d, the 12-byte `AREA` triggers, `ENMY` and `ACTR`? The scene loader `object_load_scene` copies four DIR fields into `object_scene_tables`; the readers of those fields and of each chunk would name them.
- [ ] 36. What is in the save? One memory card block, undocumented. The save routine that writes it would list the fields, and so map most of the game state above.
