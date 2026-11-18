#ifndef GAME_MENU_H
#define GAME_MENU_H

#include "common.h"
#include "game/types.h"

/* Functions of src/game/menu.c that other files call or a table names. */
void menu_clear_rows(ListMenu *menu);
s16 menu_move(s16 up);
s32 menu_open(s16 reset, s16 sprite, s16 icon_sprite, s16 count, s16 rows, s16 *list, s16 first_entry,
                   s16 color, s16 cursor_color);
s32 menu_close(void);
s16 menu_get_state(void);
s32 menu_set_list(u16 sprite, s16 *list);
s16 menu_get_entry(s16 i);

#endif
