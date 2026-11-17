# Engine docs

How Germs: Nerawareta Machi works, for a programmer who opens the code for the first time. Each
page explains one system from the code: the functions that run it, the data it reads, and the
flow of a frame or an event, with links to the files and functions. For what a player sees,
follow the links to [the findings](../discoveries.md); for the names, see
[the glossary](../naming.md); for where each file sits in the executable, see
[the layout](../layout.md).

## Pages

Machinery:

- [Boot and the main loop](boot-and-loop.md): `main`, the kaj start-up, the event queue, the
  vertical blank timer and alarms, tasks, one frame of the game and the scene request.
- [Files and the CD](files-and-cd.md): SCE.S and RES.R with their offset tables, the chunk walk
  and its loaders, the CD manager and its pools, town cells and streamed places, TIM, TMD and TOD.
- [Rendering](rendering.md): the two buffers and the flip, ordering tables, the primitive
  handlers, models and animation, sprites and palettes, effects, fog by the hour, the functions
  kept in assembly.
- [Sound and music](sound-and-music.md): VAB banks and their stream, sound effects on eight
  voices, one SEP of music per scene, footsteps, and every LIBSND call.
- [Menus, text and the save](menus-text-and-save.md): the office menu and its status page, Kanji
  ROM text, narration and profiles, the memory card screen, the save, the pad.

The game:

- [Scenes and scripts](scenes-and-scripts.md): a scene from request to running, action sets and
  the action queue, things with scripts, area triggers, doors and the game variables.
- [Town and vehicles](town-and-vehicles.md): town blocks, streaming and collision, buildings, the
  car, the train, the car navigation and the shops.
- [People and combat](people-and-combat.md): people and enemies, their records, movement and
  attacks, the hit roll, weapons, damage, death and arrests.
- [Player and survival](player-and-survival.md): the player on foot and in vehicles, energy, hours
  awake, body parts, the changed state, food and healing, the clock and the mails.

## Where to start reading the code

Follow the calls from the entry point; each step names the function to open next.

1. [`main`](../../src/game/main.c): `kaj_init`, the seven lists, `event_open`, RES.R entry 1,
   then the endless loop over the title and the three scene loops
   ([boot and loop](boot-and-loop.md#from-main-to-the-scene-loop)).
2. [`kaj_init`](../../src/kaj/kaj.c) and the parts it starts:
   [event.c](../../src/kaj/event.c) for the queue, [timer.c](../../src/kaj/timer.c) for the
   clock events, [tss.c](../../src/kaj/tss.c) and [view.c](../../src/kaj/view.c) for tasks and the screen.
3. `object_room_main` in [object.c](../../src/game/object.c): the clearest scene loop, a switch
   over `kaj_event_get` that calls `mail_step_frame` on every empty event. `block_building_main`
   ([block.c](../../src/game/block.c)) and `thing_game_loop`
   ([thing.c](../../src/game/thing.c)) have the same shape.
4. `object_load_scene` and `object_read_chunks` in object.c: how a scene's chunks become sprites,
   models, sounds, scripts and tables ([files and CD](files-and-cd.md#the-chunk-walk)).
5. The handlers in [event.c](../../src/game/event.c): alarms, area enter and leave, the clock
   tick, finished tasks and animations, and the hooks each scene installs.
6. `mail_step_frame` in mail.c: the update order of one frame, then `action_update` in
   [action.c](../../src/game/action.c) for the scripts and `player_update` in
   [player.c](../../src/game/player.c).
7. `roadmap_draw_frame` in [roadmap.c](../../src/game/roadmap.c): the draw order, then
   [mod.c](../../src/game/mod.c) and [sprite.c](../../src/game/sprite.c).
8. Under all of it: [cdmgr.c](../../src/kaj/cdmgr.c) and [the map streamer](../../src/kaj/map.c) for the town,
   [sound.c](../../src/game/sound.c) for sound, and
   the menus and text windows of [card.c](../../src/game/card.c) and [dialog.c](../../src/game/dialog.c).

Five habits of the code help when reading any file:

- A source file is named by the file name its error messages carry ("object.c" passed to
  `kaj_abend`, "cdmgr.c" printed with a line number); a file with no such string is named after
  what it does ([layout](../layout.md)), and its functions carry the prefix of what they do
  (`player_`, `npc_`, `kaj_tod_`). Each page says which file holds which module the first time.
- Most allocations go through `kaj_malloc`, which returns NULL on failure, and most callers then
  stop in `kaj_abend` with a message such as "Error Allocating MOD Pointer": searching a message
  finds the code that owns the data. The exceptions are listed in
  [the kaj start-up](boot-and-loop.md#the-kaj-start-up): two queues use `calloc3` and `realloc3`
  directly, and `kaj_tmd_load` and the CD manager end in `exit` without `kaj_abend`.
- Everything that happens is an event. Scene loops, menus and waits all switch on
  `kaj_event_get`; type 0 means "run one frame", and the scene's own behaviour is plugged in
  through six hooks (`event_tick_hook` and the others) that scenes set when they start
  ([the event queue](boot-and-loop.md#the-event-queue)).
- Anything that moves over time is a task or a multiple of `kaj_system.vsync_delta`, the
  refreshes the last frame took ([tasks](boot-and-loop.md#tasks),
  [frame timing](../discoveries.md#-the-game-times-every-frame-so-a-slow-machine-makes-it-choppy-not-slow)).
- Objects are found by number in kaj lists: sprites by id (0x400 and 0x409 for the HUD, 0x403 and
  0x404 for the text windows), models by id (weapon models at their id plus 0x400), doors, blocks
  and things by the lists `main` creates.
