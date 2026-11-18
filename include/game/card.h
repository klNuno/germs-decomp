#ifndef GAME_CARD_H
#define GAME_CARD_H

#include "common.h"
#include "game/types.h"

/* Local view of GameVars: this unit reads 0x0-0xBE as one s16 array (lh), the shared type has a u16 array. */
typedef struct {
    s16 vars[0x5F];
    s16 mail_count;
    u8 padC0[0x13C];
    s16 drain_count;
    s16 drain_minute;
    s16 car_speed_setting;
    s16 text_speed_setting;
    u8 pad204[0x44];
    s32 narration_task;
    u8 pad24C[0x2];
    s16 text_open;
    s16 unk250;
    s16 unk252;
    s16 unk254;
} GameVars_u8017EBF8;

/* Functions of src/game/card.c that other files call or a table names. */
s16 card_run(s16 load_mode, s16 in_office);

#endif
