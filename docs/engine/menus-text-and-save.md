# Menus, text and the save

Two files with no assert hold this part: src/game/card.c, the memory card screen, and
src/game/dialog.c, the menu opened in the office and the text window that draws Shift-JIS strings
with the BIOS Kanji ROM; door.c follows them. This page covers the menus and the status page, text
drawing, narration and profiles, the memory card screen and the save, and the pad. Each menu is
a modal loop over `kaj_event_get` like the scene loops ([one frame](boot-and-loop.md#one-frame-of-the-game))
and draws only sprites ([sprites](rendering.md#sprites-and-colour-tables)).

## The office menu

`menu_run` (0x80182300) is the menu of four items with its status page. Only the room loop opens
it: in `object_room_do_action`, the action button on the office trigger 0xFA0001 walks the player
to a spot and sets exit action 1, which ends the room so that `object_room_run` (0x80194E5C) calls
`menu_run` and then enters the room again. Trigger 0xFA0002 sets exit action 2: the card screen
in save mode, then `mail_goto_ofc` to restart the office.

`menu_run` hides the HUD sprites 0x400 and 0x409, loads RES.R entry 6 with progress 1
([RES.R](files-and-cd.md#resr)), shows sprites 0x208, 0x209 and 0x20B, fades in, plays sequence 2 of the
scene's music ([music](sound-and-music.md#music)) and loops: each frame `menu_handle_input`
(0x80181D2C) and `menu_animate` (0x80181F9C), which cycles three palette ranges of sprite 0x208
with random turns. At the end it stops the music and frees sprites 0x207 to 0x23D.

| Pad | Handler | Effect |
| --- | --- | --- |
| up, down (0x1000, 0x4000) | `menu_move_cursor` (0x80181818) | item cursor 0 to 4, or the row inside a page |
| left, right (0x8000, 0x2000) | `menu_options_page` | changes a setting |
| circle (0x20) | `menu_confirm` (0x80181A64) | opens an item or acts in it |
| cross (0x40) | `menu_back` (0x80181C10), or `mail_goto_ofc` at the top level | closes a page, or leaves the menu |

| Item | Page | What it shows |
| --- | --- | --- |
| 1 | `menu_list_page` (0x80180B04), RES.R 0xD | 8 entries; entries 2 to 5 lit by game variables at 10, 1000 or 2000 (`menu_list_vars`) |
| 2 | `mail_list_open` (0x8018B810), RES.R 8 | the received mails, when `action_vars` +0xBE is set ([timed mails](../discoveries.md#-the-timed-mails-are-written-in-the-code-for-days-1-to-4)) |
| 3 | `menu_options_page` (0x8018164C) | text speed (+0x202) and car speed (+0x200), three values each |
| 4 | `menu_status_page` (0x80180D8C), RES.R 0xE | the status page |

The status page fills the bar sprites 0x23A and 0x23B from `player_status` and game variables
0x5A to 0x5E, and shows the two equipped weapons found with `effect_weapon_find` (0x80188FEC),
with their ammunition; its argument flips between two pages. What the values mean is on
[player and survival](player-and-survival.md).

## Text drawing with the Kanji ROM

The game has no font of its own. `text_draw_string(str, rows)` (0x80182518) writes into the VRAM
of the open window sprite (`text_window_sprite`: 0x403 small, 0x404 large, 0x40D profile):

| Byte | Meaning |
| --- | --- |
| first byte with the high bit set | a Shift-JIS character: `Krom2RawAdd2` gives its 16 x 15 glyph from the BIOS Kanji ROM, turned into 4-bit pixels in a buffer first cleared to 0 (`memset`), set pixels taking the current colour, and the whole cell uploaded with `LoadImage2` as a 4 x 16 rectangle, replacing what the window held there |
| space | skips a cell |
| comma | new line |
| any other ASCII byte | sets the colour to its value minus '0' |

`text_show` (0x80183E88, 27 callers) opens window 0x403 or 0x404, keeps up to two answer ids for
a prompt, clears the window with `ClearImage2`, draws the string and plays an effect;
`text_close` (0x80184094, 31 callers) hides the windows. Scripts type text with action command 5,
`text_exec_command` (0x801837F0): `text_start_typing` (0x801834AC) clears the large window and
`text_draw_next` (0x80182860) draws one character per step at `text_col` and `text_row`, 16 cells
by 3 rows; a full page shows the prompt sprite 0x40A and waits for `text_next_page`. The wait
after a page is 20, 10 or 5 by the text speed of the options page. `text_format_number`
(0x801830A0) writes a number as full-width digits.

## Narration and profiles

`text_start_narration` (0x80183CFC) types a long text in window 0x404 as a kaj task
([tasks](boot-and-loop.md#tasks)) and blocks the player: `text_narration_step` draws a character
on every other step, `text_narration_end` frees the player. `object_room_main` starts it when the
room starts in narration mode 1 or 2, with text 0 or 1 of the scene, and `sprite_title_loop`
for the title. `text_narration_cues` (0x80184434) watches the typed position: in mode 1 it starts
the fade in at 0x1AA and fades the music out at 0x21A, in mode 2 it fades in at 0x182.

`text_show_profile` (0x80183618) draws the card of a dead person on sprite 0x40D from
`object_scene_tables.npc_bodies`: age and height through `text_format_number`, sex, blood type
and the lines through `text_draw_line` (0x80182D34)
([the profile panel](../discoveries.md#-the-profile-panel-is-the-lingering-thoughts-of-the-dead)).

## The memory card

`menu_card_run(load_mode, in_office)` (0x801808F0) is the card screen: `MemCardStart`, sprites 0x200 to
0x203, then each frame `menu_card_handle_input` (0x801803BC) and `menu_card_process` (0x8018073C),
and `MemCardStop`. It returns whether a game was loaded. Three callers: `sprite_title_run` (load),
`object_room_run` (save at the office) and `sprite_phone_run` (save at a phone).

| Function | Role |
| --- | --- |
| `menu_card_init_slots` (0x8017EBF8) | four slots named "BISLPS-02107GERMS%d" with the icon palette |
| `menu_card_process` | one `MemCardSync` step: `MemCardExist`, `MemCardFormat`, then scan, load or save by state; `MemCardAccept` on a new card |
| `menu_card_scan` (0x8017FF0C) | `MemCardGetDirentry`, matches the slot names, reads each header for its day and time |
| `menu_card_move_cursor` (0x801802A0) | the slot cursor over 4 slots, skipping empty ones when loading |
| `menu_card_set_message` (0x8017EE2C) | a card result 1 to 7 turned into a message on sprites 0x202 and 0x203 |
| `menu_card_save` (0x8017F6F4) | creates the file, writes header, icon and the state |
| `menu_card_load` (0x8017EFEC) | reads and checks the state, then `mail_goto_ofc` or `mail_goto_twn` |

What a save holds, its four checksummed pieces written twice and how loading falls back on the
copy are in [the save finding](../discoveries.md#-a-save-holds-464-bytes-of-game-state-stored-twice-with-checksums).

## The pad

The pad words live in `kaj_system`. `kaj_pad_read` (0x801CD6B4) reads only while `pad_mode` is 1:
`PadRead(1)`, the old word into `pad_prev`, the new one into `pad_now`. `kaj_pad_reset`
(0x801CD688) clears both and sets the mode to 2 (argument 1) or 0. A scene change turns the pad
off with 0 (`mail_take_scene_change`); the end of the fade in turns it back with 1
(`event_handle_effect_done`), and `roadmap_draw_frame` makes 2 into 1 after the next frame, so
nothing pressed during a change or a fade is read. Nine input functions read the pad: the room,
building, town, two elevator, phone, title, card screen and menu ones. A press is an edge: the bit set in
`pad_now` and clear in `pad_prev`.

| Bit | Button | Used for |
| --- | --- | --- |
| 0x20 | circle | confirm, the action button |
| 0x40 | cross | cancel; walking back |
| 0x10 | triangle | walking forward |
| 0x4, 0x8 | L1, R1 | side steps |
| 0x1000, 0x4000 | up, down | cursors; looking up and down |
| 0x8000, 0x2000 | left, right | settings; turning |
| 0x100 | select | the weapon panel (`effect_weapon_input`) and the map (`player_update_map`) |
| 0x800 | start | the item menu (`effect_item_input`), the title, the car navigation menu |

On foot, `player_handle_pad` (0x80199548) turns the bits into motion: pitch, yaw (or the camera
in the car and the train), forward and back with a run ramp, and side steps slowed by a hurt leg
([hurt legs](../discoveries.md#-hurt-legs-slow-you-down-and-one-hurt-arm-spoils-your-aim)).
