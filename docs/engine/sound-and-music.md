# Sound and music

All sound goes through Sony's LIBSND. The kaj library starts and stops it; the game's sound.c
keeps a stack of VAB banks, plays sound effects on eight voices of its own and plays one SEP of
up to three sequences per scene as music. Banks and music arrive as chunks of the scene or
resource files ([the chunk walk](files-and-cd.md#the-chunk-walk)). The game has no streamed audio
and no movie player ([the movie](../discoveries.md#-the-movie-on-the-disc-is-a-silent-82-second-reel-the-game-can-never-play)).

## Start-up

Two functions of [misc.c](../../src/kaj/misc.c) form the kaj sound part:

| Function | Calls |
| --- | --- |
| `kaj_sound_init` (0x801CD70C) | `SsInit`, `SsSetTableSize(kaj_sound_seq_table, 1, 3)`, `SsSetTickMode(1)`, `SsStart`, `SsSetMVol(0x7F, 0x7F)`; sets the music volume `kaj_system.sep_volume` to 0x7F |
| `kaj_sound_quit` (0x801CD764) | `SsEnd`, `SsQuit`; nothing in the game calls it |

`SsSetTableSize` with 1 and 3 leaves room for one SEP of three sequences, which is the limit
`sound_bgm_open` enforces. `kaj_init` calls `kaj_sound_init` once at boot
([the kaj start-up](boot-and-loop.md#the-kaj-start-up)).

## Sound banks

src/game/sound.c holds sound.c. A bank is a VAB that the scene loader receives in two chunks,
`VABH` (the header) then `VABB` (the body). The stack of banks lives in `object_scene_tables`:
`se_banks[4]` and `se_bank_count`.

1. `object_load_vabh` (0x80191450) calls `sound_se_alloc_header` (0x801A37E4), which takes the
   bank id and a flag from the first two halfwords (4 bytes), allocates the chunk size minus those
   4 bytes and copies the 0x7F4 header bytes left in the chunk's first sector ("Error sound stack
   overflow" beyond 4 banks); `object_load_vabh` reads the rest of the header from the CD after
   them, then calls `sound_vab_open_head` (0x801A3970), which calls `SsVabOpenHead` ("Can not
   Open VAB Header").
2. `object_load_vabb` (0x8019159C) sends the body to the SPU in pieces through `sound_vab_stream`
   (0x801E05C0): the 0x7F8 bytes left in the chunk's first sector, then 0x2000-byte reads into a
   buffer it allocates ("Error Allocating vab_trans_buffer"), each passed to
   `sound_vab_transfer` (0x801A39F0), which calls `SsVabTransBodyPartly` and waits with
   `SsVabTransCompleted` ("VAB Data Transfer Error").
3. `sound_se_push` (0x801A217C) records the bank (VAB id, bank id, flag, header) on the stack;
   the first bank also clears the voice table.

`sound_se_pop` (0x801A2288) keys off the top bank's voices, closes it with `SsVabClose` and frees
it. `sound_se_pop_scene` (0x801A23B4) pops while the top bank's flag is above 0; the three scene
loops call it with `sound_bgm_close` when they end: `object_room_quit`, `building_run` and
`town_leave` (0x801A8B38). `sound_se_pop_all` (0x801A3A54) has no caller.

## Sound effects

`sound_se_play(id)` (0x801A2678) plays entry `id` of `sound_se_table` (0x801D7B58), whose records
name a bank id, a program, a tone, a note, two volumes and a hold flag. It finds the bank on the
stack, scales the volume by the VAB's master volume and pan, then the program's and the tone's,
and picks a voice in `sound_voice_table` (0x801E1078, 8 slots):

| Case | Voice |
| --- | --- |
| the same effect is already playing | the same voice, keyed off and on again |
| a slot is free | that slot |
| all 8 busy | the one with the lowest age; held effects get age 0x7FFF and are taken last |

The key on is `SsUtKeyOnV`, the key off `SsUtKeyOffV`. `sound_se_play` has 55 callers; the most
called ids are 0x11 (21 calls), 0xF (17) and 8 (14). `sound_se_play_note` (0x801A2C60) does the
same with every value given as arguments; it serves `sound_exec_command` (0x801A324C), the handler
of action command 9, which reads 5, 7 or 8 numbers from the script ([scenes and
scripts](scenes-and-scripts.md)). `sound_se_stop` (0x801A25B4) keys off one effect,
`sound_se_stop_all` (0x801A252C) all of them.

## Music

Each scene's common part carries one `MIDI` chunk. `object_load_midi` (0x80190378) allocates a
handle with `sound_bgm_create` (0x801A3AA0) and reads the chunk into it, then `sound_bgm_open`
(0x801A33E8) opens it: the first word is the number of sequences ("Too Many SEQ in This SEP" from
4 up), the rest is a SEP opened with `SsSepOpen` on the bank whose id is 2 ("VAB is not Ready"
when there is none). It closes the previous SEP, if any (`sound_bgm_close`), before `SsSepOpen`,
then sets each sequence to the music volume with `SsSepSetVol` and keeps the new one in
`object_scene_tables.bgm`.

| Function | Calls | Used by |
| --- | --- | --- |
| `sound_bgm_play(seq)` (0x801A3BCC) | `sound_bgm_stop` for the old, `SsSepPlay` of the new when it differs | scripts (command 3), the scene loops after the first fade, `dialog_menu_run` |
| `sound_bgm_stop` (0x801A3C58) | `SsSepStop`, `SsSepSetVol` back to the music volume | |
| `sound_bgm_fade_out(n)` (0x801A3CC0) | task 0xD from the volume to 0 over n x 30, `sound_bgm_fade_step` (0x801A3D74) sets `SsSepSetVol` | command 3 with a sub-op, `dialog_narration_cues` |
| `sound_bgm_close` (0x801A3B5C) | `SsSepClose` | the scene loops when they end |

Which sequence plays is chosen per place in the code:

| Where | Sequence |
| --- | --- |
| a room (`object_room_on_effect_done`, after the fade in) | 0; 1 when the room starts with narration (`object_room_main`) |
| a building (`building_on_effect_done`) | 0 in building 5, none in building 7, else 1 |
| the town (`town_task_hook`) | 0 |
| the pause menu (`dialog_menu_run`, 0x80182300) | 2 |
| a script (`action_update`, command 3) | the number in its argument |

Two other places set the music volume with `SsSepSetVol`: `door_fade_step` (0x80185918), at the
end of every screen fade ([effects](rendering.md#effects)), and `shop_fade_screen_music`
(0x801A0D58).

## Footsteps

`player_update` calls `sound_footstep_update(player)` (0x801A358C) every frame. It adds
`vsync_delta` to a clock and reads the player's move state: walking (states 1 and 3) plays effect
3 every 30 units, running (state 2) every 15, and state 4 plays effect 0xE. It also sets a head
bob of 0 to 50 from `rsin` of the step phase. A change between walking and running restarts the
counters, and `sound_footstep_reset` (0x801A3DBC) clears them. Because the clock adds
`vsync_delta`, steps keep their pace when frames run slow
([frame timing](../discoveries.md#-the-game-times-every-frame-so-a-slow-machine-makes-it-choppy-not-slow)).
Player movement is on [player and survival](player-and-survival.md).

## LIBSND calls

| Call | Made by |
| --- | --- |
| `SsInit`, `SsSetTableSize`, `SsSetTickMode`, `SsStart`, `SsSetMVol` | `kaj_sound_init` |
| `SsEnd`, `SsQuit` | `kaj_sound_quit` |
| `SsVabOpenHead` | `sound_vab_open_head` |
| `SsVabTransBodyPartly`, `SsVabTransCompleted` | `sound_vab_transfer` |
| `SsVabClose` | `sound_se_pop`, `sound_se_pop_scene` |
| `SsUtKeyOnV` | `sound_se_play`, `sound_se_play_note` |
| `SsUtKeyOffV` | `sound_se_play`, `sound_se_play_note`, `sound_se_stop`, `sound_se_stop_all`, `sound_se_pop`, `sound_se_pop_scene` |
| `SsSepOpen`, `SsSepClose`, `SsSepPlay`, `SsSepStop` | `sound_bgm_open`, `sound_bgm_close`, `sound_bgm_play`, `sound_bgm_stop` (one each) |
| `SsSepSetVol` | `sound_bgm_open`, `sound_bgm_stop`, `sound_bgm_fade_step`, `door_fade_step`, `shop_fade_screen_music` |
