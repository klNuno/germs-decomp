#ifndef GAME_SHOP_H
#define GAME_SHOP_H

#include "common.h"
#include "game/types.h"

typedef struct ShopState {
    s16 active;
    s16 menu_stage;
    s16 to_inventory;
    s16 alt_speaker;
    s16 at_counter;
    s16 has_second_menu;
    s16 has_third_menu;
    s16 deal_level;
    s16 cursor;
    s16 picks[3];
    s16 *list;
    s16 *texts;
} ShopState;

/* Functions of src/game/shop.c that other files call or a table names. */
s16 shop_finish(s16 building);
s16 shop_update_input(PlayerStatus *status);
s16 shop_open_menu(s16 building, s32 trigger);
void shop_init(s16 building);
void shop_exit_to_town(s16 building, s16 exit_no);
void shop_open_topic_list(void);

#endif
