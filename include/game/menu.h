#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "common.h"
#include "game/types.h"

/* Functions of src/game/menu.c that other files call or a table names. */
void mail_menu_clear_rows(MailMenu *menu);
s16 mail_menu_move(s16 up);
s32 mail_menu_open(s16 reset, s16 sprite, s16 icon_sprite, s16 count, s16 rows, s16 *list, s16 first_entry,
                   s16 color, s16 cursor_color);
s32 mail_menu_close(void);
s16 mail_menu_get_state(void);
s32 mail_menu_set_list(u16 sprite, s16 *list);
s16 mail_menu_get_entry(s16 i);

#endif
