# What the code tells us about what the creators meant

This page reads the whole game as a design. It is written for a player, not a programmer. Every part keeps the code, the creators' words and our reading apart, and says how sure the reading is:

- **The code says**: a fact read in the game's program, with a link to the finding that proves it.
- **The creators said**: a close paraphrase of material that comes from the people who made the game (the manual, the box, the disc), with its source key.
- **Our reading**: what we think the choice means. A reading is an argument, never a fact.
- **How sure**: how much weight the reading can bear.

The proof of every code fact (function name, address, whether it was checked in the emulator) is in [the findings](discoveries.md) and in [the engine pages](engine/README.md). No interview with the developers is known, in Japanese or in English, so this page has far less of the creators' voice than a page like it could have for another game. Where the developers' material says nothing on a theme, the part says so instead of filling the gap. Nothing here is quoted: the developers' material is paraphrased as [community-knowledge.md](community-knowledge.md) reports it, with the same source keys.

## Summary in ten lines

1. Germs looks like a simulated town, but the town itself is mostly scripts: opening hours, the invasion and the memory of the dead all sit in door and scene scripts. The player's body is the one part that is truly simulated.
2. The clock runs six times faster than real time, counts minutes and stops at day 99. It drives hunger, healing, three shop doors and twelve mails on days 1 to 4. It never moves the invasion.
3. The invasion is a chain of doors and days: five buildings fall from a set day and hour, but only when you pass a door; the others fall when you free another building. The manual's "no fixed order" holds at the start and loosens later.
4. Your life is one energy value. Staying awake multiplies its drain up to 32 times, so sleep is the main way to survive, more than any fight.
5. Nothing costs money. Food is free, the chiropractor charges hours, the hospital charges nothing. Time is the only price.
6. Combat is a die roll from 0 to 99 and levels up to 100 per weapon class. The gun shop sells by level from three fixed lists, and seven weapons are never sold.
7. Death has two outcomes chosen by one flag: an enemy's recent hit to the head makes you "changed", anything else is game over. Being changed feels strong but leads nowhere, and the cure puts every building back as it was.
8. Every dead person, mutants included, keeps a card with a name, a blood type and a last thought, yet nearly everyone comes back when you return; only 55 of 412 people records have a death script that writes a story value.
9. The game has an ending: a quiet narration, then free play in a town set "at peace" where several doors stay shut. No developer material explains it.
10. The disc keeps a movie from 1995 that the game cannot play and the names of scene files it does not have. Our reading is that these are traces of a long development, not hidden content.

## Who said what, and where

The developers' material used on this page is what [community-knowledge.md](community-knowledge.md) lists with a source. This page did not reopen it; full URLs are in [its Sources](community-knowledge.md#sources).

| Short name | What it is | Where community-knowledge.md cites it |
| --- | --- | --- |
| manual | The game's manual, as transcribed on the fandom wiki's Manual page; scans of the disc and the manual are on archive.org. Page numbers (p.2, p.7) are the ones the rows give | Game rules, World and places |
| back insert | The box's back insert, with the town size | World and places, Where sources disagree |
| KAJ brochure | The developer's own company brochure (kaj.co.jp), with the town size | World and places, Sources |
| disc | The disc label, which names KAJ, and the disc's own file dates | Staff and development, Technical |
| credits | The staff list of the game, as transcribed by fans (fandom, GameFAQs credits, atwiki); spellings may be off | Staff and development |
| splume history | The company history page of splume, KAJ's later 3D community, cited with Japanese Wikipedia | Staff and development |

Three claims on the atwiki page are said to come from the developers but give no source: a print run of about 4,000 copies, a town made black and white "to look like old SF dramas", and a missing ending that was deliberate. This page treats them as rumours, not as the creators' voice.

## The big picture

**The creators said.** The disc label names KAJ as the developer, and the credits list six people (credits). The developers' own material dwells on the town: the back insert and the KAJ brochure give its size as 2.5 km square, the manual as 3 km square (back insert, KAJ brochure, manual). Japanese Wikipedia, citing two news sites, and the splume history page tie the town's block streaming to KAJ's later 3D community, splume (splume history). The manual describes each building's states and the people you can kill and read about (manual p.2).

**The code says.** The game runs on one table of game variables, read and written by scene scripts. The hours of the shops are tests in the town's door scripts ([opening hours](discoveries.md#-only-three-shops-close-at-night-the-opening-hours-sit-in-the-towns-door-scripts)), the invasion is script writes at doors ([the invasion schedule](discoveries.md#-time-alone-never-spreads-the-invasion-buildings-fall-on-a-schedule-when-you-pass-a-door)), and a death can only be remembered through a value its death script writes ([the dead come back](discoveries.md#-the-dead-come-back-when-you-return-unless-their-death-script-records-the-kill)). Each building is a set of whole versions on the disc, one per invasion state ([the scene data](discoveries.md#-the-scene-data-four-counts-per-place-door-triggers-and-people-records)). By contrast the player's body runs on general rules: energy, hours awake and five body parts, updated by the clock ([energy](discoveries.md#-energy-drains-faster-the-longer-you-stay-awake)).

**Our reading.** Germs is built like a stage play more than a simulation. The town does nothing on its own; it changes at the moments the player walks through a door, and each change swaps in a version of a building written by hand. The only thing that keeps living between doors is the player's body. That fits what the developers chose to advertise: the size of the town and the streaming that carries it, both technical feats of a computer graphics house, rather than a world that runs by itself.

**How sure.** High on the facts, medium on the intent.

## The clock and the calendar

**The code says.** One game minute passes every 600 screen refreshes, 10 real seconds, which is the 6x speed players measured. The calendar stops at day 99: every later midnight leaves it there ([the clock](discoveries.md#-the-clock-counts-minutes-and-stops-at-day-99)). The clock counts refreshes in an interrupt, so it keeps its pace however slowly the game draws ([frame timing](discoveries.md#-the-game-times-every-frame-so-a-slow-machine-makes-it-choppy-not-slow)). A nap of one hour takes 4 hours off your hours awake; a full sleep lasts 7 hours, or until 08:00 when you go to bed late ([energy](discoveries.md#-energy-drains-faster-the-longer-you-stay-awake)). Every midnight the clock stores whether the day is odd or even. The burger shop's code reads it to choose what it serves ([the burger shop](discoveries.md#-the-burger-shop-secretly-serves-changed-food-and-even-days-swap-its-hours)), and the town's door scripts also test it to pick which room of the chain restaurant `FMR` and of the Italian restaurant you enter (scripts read after the finding was written, being added to it).

**The creators said.** Nothing. None of the developers' material that community-knowledge.md lists describes the clock; the 6x speed is a players' measurement (jawiki, GameFAQs).

**Our reading.** The clock is not a countdown. No rule we found reads day 99, so the limit looks like a guard on a counter rather than an end the creators planned. Ten seconds a minute makes a game day last four real hours, long enough that a player feels hunger and fatigue within one sitting, short enough that a night's sleep is a real choice. The day's parity is read only by three eating places, and only the burger shop changes what you eat with it; it reads as a small device for varying meals and rooms from day to day (and for the burger shop's joke, see below) rather than a system that was meant to grow.

**How sure.** High on the facts, low on why 99, medium on the parity.

## What the clock is allowed to touch

**The code says.** The clock writes the day, the hour, the minute and the parity, and nothing else of the story. On the hour it may send mail: twelve mails at eight fixed times, all on days 1 to 4, four of them under story conditions, and none after the ending; the other mails come from story scenes, never from the clock ([the timed mails](discoveries.md#-the-timed-mails-are-written-in-the-code-for-days-1-to-4)). Three shops close at night (the burger shop 08:00 to 21:59, the Italian restaurant 11:00 to 21:59, a shop the code calls `MPS` 05:00 to 23:59); the chiropractor and the other big buildings never shut; the hospital has one door for humans that keeps 07:00 to 19:59 and one that does not, and its desk and one of its exam rooms keep the same hours ([opening hours](discoveries.md#-only-three-shops-close-at-night-the-opening-hours-sit-in-the-towns-door-scripts)). The five scheduled falls of the invasion also sit on days 1 to 4: the cathedral on day 1 at 17:00, Indenco on day 1 at 20:00, `STH` on day 2 at 12:00, Hotel Seasons on day 3 at 14:00 and the coal mine on day 4 at 12:00 ([the invasion schedule](discoveries.md#-time-alone-never-spreads-the-invasion-buildings-fall-on-a-schedule-when-you-pass-a-door)).

**The creators said.** Nothing on the hours or the mails. The mail times players listed come from the fandom wiki, not from the developers.

**Our reading.** Everything the clock does to the plot happens in the first four days. Three of the five scheduled falls share their hour with a timed mail (day 1 at 17:00, day 3 at 14:00, day 4 at 12:00), which suggests each mail was meant to tell the player about the fall it accompanies. After day 4 the town waits for the player. We read this as a scripted opening week that pushes the story forward, followed by a pace the player sets.

**How sure.** High that the timing is confined to days 1 to 4. Low on the mails announcing the falls: the mails are pictures and we did not compare what they say with the buildings.

## The invasion: a chain of doors and days

**The code says.** Each building keeps one number: 0 not yet invaded, 10 freed, 1000 at peace after the ending, 2000 while you are changed, any other value invaded. The office computer's five dots show it, and the same number picks which version of the building loads ([invasion state](discoveries.md#-each-buildings-invasion-state-is-one-number-and-the-computers-dots-show-it)). A new game starts with four places already invaded. The clock never moves the numbers: the five dated buildings fall only when you step out of the office into the town or reach their own door, and only from "not yet invaded". The rest is a chain: leaving the office for the first time invades Grand Station, freeing the cathedral invades the Temple of the Universe and the waterway, freeing the mine invades the hospital, beating the hospital's boss frees three places at once ([the invasion schedule](discoveries.md#-time-alone-never-spreads-the-invasion-buildings-fall-on-a-schedule-when-you-pass-a-door)).

**The creators said.** The manual (p.2, with the fandom Indenco page) describes a timeline per building: before the invasion, invaded, freed, and the whole city at peace, with a state from 0 to 4 on the office computer and 4 when you have changed. It says there is no set order of play and that an action in one building can change the story of another (manual p.2, with jawiki).

**Our reading.** Here the code and the manual agree closely: the five states are the five values, and the chain is the "action in one building changes another". Applying the schedule at doors is the cheapest way to make a timed invasion look real. Since a building is a whole version loaded from the disc, it can only change when it loads, so the change waits for the moment the player is about to see it. From the player's seat the effect is almost the same as a clock. "No fixed order" is true of the opening; the chain then imposes a partial order (the hospital falls only after the mine is freed).

**How sure.** High on the agreement with the manual, medium on the door being a cost choice rather than a story choice.

## Energy, sleep and the body

**The code says.** Your life is one energy value from 0 to 255. It loses 1 point every 10 game minutes, and the loss grows with hours awake: 2 after 16 hours, up to 32 after 96. A hurt torso multiplies it; the weapon in hand adds its own cost every sixth drain; a warning sounds below a quarter ([energy](discoveries.md#-energy-drains-faster-the-longer-you-stay-awake)). The five body parts are the head, two arms, the torso and the legs, each with four levels; they heal 4 points an hour unless at the worst level ([body parts](discoveries.md#-body-part-damage-heals-by-the-hour-unless-it-is-at-the-worst-level)). Only three parts change a rule: the legs slow you to 90 % or 70 % and weaken your guard, the arm on the left of the figure lowers your aim, the torso speeds hunger. The head's colour and the other arm's change nothing, though a hit to the head is the only hit that takes energy ([hurt legs and arm](discoveries.md#-hurt-legs-slow-you-down-and-one-hurt-arm-spoils-your-aim)).

**The creators said.** The manual is cited, with the fandom wiki, for five body parts that take damage separately, shown in colours, healed by the chiropractor, and for leg damage slowing walking and running (manual). The energy bar and fatigue are described by players, not by the developers' material (jawiki, GameFAQs, fandom).

**Our reading.** By our arithmetic from the table, a full bar lasts about 29 game hours without food or sleep, under 5 real hours, and about 80 game minutes after four days awake. Sleep is therefore the main survival act of the game, ahead of any fight. The legs and the leg slowdown match the manual exactly. The body figure shows five parts but the rules use three; either effects for the head and the second arm were planned and dropped, or the figure was drawn for the look of a full body. The head's role is carried by energy instead, which may be why its colour needs no rule of its own.

**How sure.** High on sleep (the numbers), low on the two silent parts.

## Food and healing without money

**The code says.** Each dish adds a fixed amount of energy, 5 to 80 points; eating on a full bar costs half the dish's value and puts its whole value on the torso; "changed" dishes with a negative value hurt a human and feed a changed player. The shop code reads no money ([food](discoveries.md#-food-adds-a-fixed-amount-of-energy-and-eating-on-a-full-bar-hurts-your-torso)). The chiropractor sells courses of 1, 3 or 6 hours that take 60, 180 or 360 points of damage off every part; the hours are the price ([the chiropractor](discoveries.md#-the-chiropractor-sells-time-1-3-or-6-hours-that-heal-as-much)). The hospital's injection heals every part at once, free and without losing time, but its doctor treats you only if you come in wounded ([the hospital](discoveries.md#-the-hospital-heals-every-wound-at-once-for-free-and-without-losing-time)). Neither refills the energy bar. The burger shop's menu never changes, yet at some hours it serves the changed version of what you order, and the hours swap on even days; only the staff's goodbye line hints at it ([the burger shop](discoveries.md#-the-burger-shop-secretly-serves-changed-food-and-even-days-swap-its-hours)).

**The creators said.** Nothing on money or food. The manual is cited only for the chiropractor healing the body parts (manual).

**Our reading.** With no money, the clock is the currency: sleep costs hours, the chiropractor sells hours, and the free hospital is guarded by its own hours and turns away the unhurt. That is consistent with the clock being the pressure on the body. The burger shop is a planted horror detail: an ordinary menu in an invaded town that sometimes feeds you something else, with a snigger as the only clue. Since the shop's own code tests the hour of entry and the parity for this alone, someone wrote this joke on purpose.

**How sure.** High on time as the price, medium on the burger shop as a deliberate joke.

## Combat: dice and levels

**The code says.** A shot is a roll from 0 to 99 against the hit chance. Each weapon has three distances: too close gives 20 %, the middle band gives the weapon's hit rate, the far band lowers chance and damage together. Within range the chance has a 20 % floor, but the movement and arm penalties come after it, and a shot at the very edge of the far band can round to 0 and only alert the target ([the hit roll](discoveries.md#-every-shot-is-a-roll-against-the-hit-chance-and-range-cuts-both-chance-and-damage)). Each of five weapon classes has a level from 1 to 100; a hit adds twice the damage done, and level 100 takes 810,000 points. The blue wheel on the HUD shows the weapon's hit rate, and levels above a weapon's requirements add nothing ([the blue wheel](discoveries.md#-the-blue-wheel-is-the-weapons-hit-rate-and-the-five-classes-are-levels-up-to-100)). The gun shop shows one of three fixed lists of six, by your level divided by 20; seven weapons are on no list ([the gun shop](discoveries.md#-the-gun-shop-has-three-fixed-lists-of-six-and-every-weapon-it-never-sells-has-one-giver)). Three fields of the weapon record are never read ([the weapon record](discoveries.md#-the-weapon-record-three-requirements-accuracy-damage-and-three-ranges)).

**The creators said.** The manual is cited, with the fandom wiki and atwiki, for the gun shop selling six weapons by level band, 0 to 19, 20 to 39, and 40 and up (manual). Nothing from the developers on the roll or the levels.

**Our reading.** Combat is a role-playing system inside a first-person view: your aim matters less than the die, and the wheel tells you the odds. Because levels beyond a weapon's needs are wasted, the design pushes the player to move up to stronger weapons rather than master one. Level 100 looks out of reach in normal play, given the 810,000 points it takes; whether that was meant, no source says. The game does use 100 as the strength it gives a changed player (see below). The shop's bands match the manual. The weapons never sold come from the story instead (Kouda gives the M47 Dragon), so part of the arsenal is a reward for following it.

**How sure.** High on the system, medium on the intent behind the requirements.

## Death and being changed

**The code says.** When energy reaches 0 you fall. If an enemy hit your head since the last 10-minute energy tick, you wake up changed in the coal mine with a full bar; otherwise it is game over. Starving is therefore always game over, and after the ending every death is ([energy at 0](discoveries.md#-energy-at-0-is-death-and-only-a-hit-to-the-head-makes-you-wake-up-changed)). Being changed is one flag: a pink body, wounds healing four times faster, no fatigue, and your level and ten stats set to 100 while the real ones are kept. Every building is set to its changed version; those versions send no mail, never lead to the ending and write almost no story value, and four places shut. The hospital's injection cures you and puts back your stats and every building as they were ([being changed](discoveries.md#-being-changed-is-one-flag-a-pink-body-fast-healing-and-no-fatigue)).

**The creators said.** The manual (p.2, with the fandom Mutation page) says changed people's lines are shown in yellow and tells players to watch the colour of the lines. The changed state also appears in the manual's building states, as the fifth state on the office computer (manual p.2). Nothing from the developers on how the change happens.

**Our reading.** The change is something done to you by the enemy, through the head, never the result of neglect: hunger alone ends the game. Being changed is a full parallel game, a fifth version of most buildings, built at real cost, and yet it is designed as a detour: strong, safe from fatigue, and frozen. Since the cure puts every building back as it was before the change (only a few other story values written meanwhile stay), we read it as a temptation and a warning, not as a second route. The manual's advice to watch line colours shows the creators expected players to read small signs to tell humans from the changed.

**How sure.** High that changed play is a dead end by design (every version shares the same limits), medium on the meaning of the head rule.

## The police and civilian kills

**The code says.** The game counts civilians you kill, and only them: mutants never count. With 3 kills you are arrested the next time the office loads; 5 more give the second arrest, which turns the police station into its invaded version and puts you in its cell. Nobody arrests a changed player or after the ending. The office computer shows your total as red figures, and after an arrest leaving the office refills your energy ([arrests](discoveries.md#-three-civilian-kills-get-you-arrested-and-five-more-the-second-time)).

**The creators said.** The manual (p.2, with GameFAQs and jawiki) says anyone can be killed, shop staff included, that important people come back, and that too many kills lead to arrest.

**Our reading.** Killing is allowed and counted rather than forbidden, and the count sits in plain view on the computer. The arrest does not happen in the street, which has no police and no passers-by; it waits for the office, the one place the story keeps returning to. The first arrest costs little (it even refills your energy), so it works as a warning; the second has a story consequence. The line the game draws is between humans and the changed, the same line the manual's yellow text draws.

**How sure.** High on the rules (they match the manual), medium on the arrest as a warning.

## The dead and their lingering thoughts

**The code says.** You can walk into a dead body; pressing CIRCLE there opens a card with the person's name, job, age, sex, height, blood type and a few lines of what they were thinking. Mutants have cards too, with heights of 250 to 320 cm ([the profile panel](discoveries.md#-the-profile-panel-is-the-lingering-thoughts-of-the-dead)). People are read again from the disc each time a place loads, so the dead come back unless a script remembers them through a story value. Only 55 of the 412 people records (each version of a place counted apart) have a death script that writes one, and such a write does not always hide the person, some only change what others say; 225 records have no death script at all ([the dead come back](discoveries.md#-the-dead-come-back-when-you-return-unless-their-death-script-records-the-kill)).

**The creators said.** The manual describes the "lingering thoughts" profile of the dead (manual p.2, with jawiki), and says that important people come back (manual p.2).

**Our reading.** Giving every dead person a name, a blood type and a last thought is a deliberate cost on killing: the game invites you to read who you killed. That the mutants get the same card says the creatures were people once, which fits a story about people being changed. The return of the dead is not a rule about respawning; it is the absence of one. The manual's "important people come back" is true but understates it: almost everyone does, and the scripts remember only the deaths the story needs.

**How sure.** High that the card is designed content (the manual describes it), medium on its moral purpose.

## Naomi as scenery

**The code says.** Naomi can never be aimed at, and no flag protects her: she is not a person to the game. She is one of six stage models that the scene scripts place, show, animate and hide like scenery. Her profile card (height 167, age 31) sits in the shared data of seven places, but a card only opens from a person, so hers never shows ([the hit roll](discoveries.md#-every-shot-is-a-roll-against-the-hit-chance-and-range-cuts-both-chance-and-damage)).

**The creators said.** Nothing. None of the developers' material that community-knowledge.md lists mentions her.

**Our reading.** The team made her untouchable by building her as part of the set, not by guarding a person. That is the simplest way to keep a story character safe in a game where anyone else can be killed. Her unused card suggests that cards were written for every named character before the team decided how each would be built, or that she was once a person; the code cannot tell which.

**How sure.** High that she is scenery by construction, low on the history of her card.

## The town's size and what can be entered

**The code says.** The town is a grid of 50 m blocks that stream around you. It spans about 4.75 by 4.9 km, with about 6 km² in use, the area of a 2.5 km square; a separate strip of 316 blocks lies 500 m beyond its edge. One unit of the world is one centimetre: your eyes are 1.70 m above the street and you walk at 2.4 m a second ([the town's size](discoveries.md#-the-town-is-a-grid-of-50-m-blocks-about-48-km-across)). The disc holds 24 scenes, the office, the town, the waterway, mine level 2 and the 20 places the town's doors lead to; none is left over for City Hall or the Yamasaki mansion. The street has door spots for 17 buildings that have nothing else behind them ([dead door spots](discoveries.md#-seventeen-buildings-have-a-door-spot-on-the-street-and-nothing-behind-it)).

**The creators said.** The back insert and the KAJ brochure give 2.5 km square; the manual gives 3 km square (back insert, KAJ brochure, manual). The block streaming is said to have led to KAJ's later product splume (splume history, with jawiki).

**Our reading.** The box and the brochure are right if "2.5 km square" means area; the town is not a square, and the manual's 3 km matches neither shape nor area. Two figures from the same developers disagreeing suggests both were approximations for print. The real scale of the world (a centimetre unit, human eye height, walking pace) fits a computer graphics house proud of a town built to measure, and the brochure and splume show the team saw the streaming town as the game's main achievement. Every scene is a place the story uses, and some buildings outside the story, such as City Hall, were left as fronts.

**How sure.** High on the size, medium on the town as the team's showcase, low on why some buildings were left shut.

## The ending and free play after it

**The code says.** When the last boss on mine level 2 dies, its exit leads to the office, where a narration plays on a black screen with no music. Then every building is set to "at peace", your wounds are healed, the clock moves to 05:00 (of the next morning if it was already 05:00 or later) and you play on: no arrests, every death is game over, the burger shop serves normal food, no mail comes by time. Indenco, `OMH`, `STH`, the coal mine, the waterway and mine level 2 have no "at peace" version, so their doors stay shut ([the ending](discoveries.md#-the-game-has-an-ending-a-narration-in-the-office-then-a-town-at-peace)), with one exception: the hospital's basement script still opens, into an empty waterway with no way out ([the empty waterway](discoveries.md#-after-the-ending-the-hospitals-basement-door-leads-into-an-empty-waterway-with-no-way-out)). Kouda's reward, before the ending, tests only that the agents' tally is exactly 7; the normal path reaches it as 1 + 2 + 4, one talk with each agent, but the warehouse agent adds its 1 with no "already met" test, so repeated talks there change the total ([Kouda's reward](discoveries.md#-koudas-reward-needs-an-agent-tally-of-exactly-7-before-the-ending)).

**The creators said.** The manual lists "the whole city at peace" among the states of each building (manual p.2), so the end state is in the manual. Nothing else: the claim that the developers called the ending missing on purpose has no source (atwiki).

**Our reading.** The ending is a state of the town more than a scene: one value written into every building. After it arrests stop, the burger shop serves normal food and no mail comes by time, while the clock, hunger and fatigue go on and death becomes final; the open buildings hold 37 calm people, and only one infected hotel guest, who only talks. The places that stay shut are places of the conspiracy (Indenco, the mine), and the waterway, still reached from the hospital, is empty with no exit; either the story is meant to be over there, or no one built a peaceful version, and the code cannot tell which. A narration without music followed by ordinary play is easy to miss as an ending, which may be why several players reported none. A tally that tests only the sum, with one agent left unguarded, reads as a slip, not a puzzle, since the other two agents guard their count.

**How sure.** High that the ending exists and what it resets, medium on the slip, low on why the shut places have no peaceful version.

## Cut and unreachable content

**The code says.**

- The disc carries two identical 50 MB video files dated 1995-10-20, four years before the rest of the disc. The executable never names them and has no code for the video decoder ([the movie](discoveries.md#-the-movie-on-the-disc-is-a-silent-82-second-reel-the-game-can-never-play)).
- The game still builds paths to separate scene files, such as one for the office and one for the town, that the disc does not have; the loader ignores them and reads one packed file ([scene files](discoveries.md#-the-game-still-names-scene-files-the-disc-does-not-have)).
- Seven weapons are never sold, but none is cut: the baton is the weapon you start with and the other six are each given by one story scene. Three fields of the weapon record are never read, one of them holding values from 3 to 60 ([the gun shop](discoveries.md#-the-gun-shop-has-three-fixed-lists-of-six-and-every-weapon-it-never-sells-has-one-giver), [the weapon record](discoveries.md#-the-weapon-record-three-requirements-accuracy-damage-and-three-ranges)).
- A save leaves its last 44 bytes zero ([the save](discoveries.md#-a-save-holds-464-bytes-of-game-state-stored-twice-with-checksums)).
- Naomi's profile card can never open, and some buildings have no version for the ending or for a changed player (above).

**The creators said.** Nothing. The only developer material here is the disc itself, whose file dates set the movie apart. Its origin is guessed by players only (GameFAQs: a playback test or footage from another KAJ project).

**Our reading.** The movie is four years older than the game and KAJ worked in computer graphics before this game, so footage from earlier work or an early test is the likeliest story; the code cannot choose between them, and nothing suggests it was meant to play in the finished game. The scene paths may mean the scenes were once separate files, packed together later; the unread weapon fields may be left from earlier weapon rules, or reserved and never used. Both are guesses the code cannot settle. Together these are traces of a long development, the kind most games leave, not a hidden second game.

**How sure.** High on the facts, low on every reason.

## Where the code contradicts what people say

| Claim | Who | What the code says |
| --- | --- | --- |
| The town is 3 km square | Manual | About 4.75 by 4.9 km, about 6 km² in use |
| The town is 2.5 km square | Back insert, KAJ brochure | Right for the area; the town is not a square |
| There is no ending | atwiki, HG101, a niconico uploader | A narration in the office, then free play in a town at peace |
| The developers left out the ending on purpose | atwiki, no source | There is an ending |
| HP, fatigue and stamina are three values | jawiki, GameFAQs | Three things, but not three bars: stamina is the energy, fatigue the hours awake that multiply its drain, HP the five body parts; the status page never shows the energy |
| Being hit lowers stamina | jawiki | Only a hit to the head takes energy |
| The blue wheel shows weapon experience | fandom Weapons | It shows the hit rate; experience is a class level |
| The cheat value is one point below the maximum | DuckStation cheat file | Level 93 of 100 |
| The way to mine level 2 is one way | niconico player | Its door back to level 1 works |
| The hospital keeps short hours | GameFAQs | In part: one of its two town doors and its desk keep 07:00 to 19:59, the other door opens at any hour |
| A changed player gets a better gun shop | niconico player | No second list; a level of 100 picks the top list |

Where the code agrees with the creators, it agrees well: the five states of each building and the computer's dots, an action in one building changing another, the lingering-thoughts card, arrests for too many kills, the gun shop's three level bands, five body parts with legs that slow you, and the chiropractor healing them.

## What we still do not understand

- **Day 99.** Why the calendar stops there, when nothing reads that day.
- **The mails and the falls.** Whether the three mails that share an hour with a scheduled fall announce it; the mails are pictures and were not compared.
- **The strip beyond the town.** 316 blocks 500 m past the edge, not visited.
- **The shut buildings.** Whether City Hall and the Yamasaki mansion are among the 17 door spots with nothing behind them, and which; no data names them ([dead door spots](discoveries.md#-seventeen-buildings-have-a-door-spot-on-the-street-and-nothing-behind-it)).
- **Colour.** Whether an earlier build of the town was in colour; the disc has no trace of one ([the town's colour](discoveries.md#-no-colour-version-of-the-town-is-left-on-the-disc)).
- **The movie.** What it was made for.
- **The weapon field from 3 to 60.** What it was for, if it was ever read.

Open questions on the code side are tracked in [the mysteries page](mysteries.md).
