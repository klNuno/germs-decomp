#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include "common.h"
#include "game/types.h"
#include "kaj/view.h"

typedef struct Sprite {
    u16 id;
    u16 mode;
    s16 visible;
    s16 clut_dirty;
    s16 color;
    s16 x;
    s16 y;
    s16 depth;
    s16 cell_w;
    u16 cell_h;
    s16 columns;
    s16 rows;
    s16 cell_col;
    s16 cell_row;
    s32 tim;
} Sprite;

typedef struct SpriteRecord {
    u16 id;
    u16 mode;
    u16 x;
    u16 y;
    u16 depth;
    u8 unkA[0x2];
    u16 columns;
    u16 rows;
    u8 unk10[0x2];
    s16 keep_clut;
    u8 tim[4];
} SpriteRecord;

typedef struct SpriteListNode {
    s32 unk0;
    struct SpriteListNode *next;
    u16 *data;
} SpriteListNode;

typedef struct {
    SpriteListNode *head;
    SpriteListNode *tail;
    SpriteListNode *cursor;
    s32 count;
} SpriteList;

/* Functions of src/game/sprite.c that other files call or a table names. */
void sprite_create(Sprite **out, SpriteRecord *rec);
void sprite_exec_command(Action *cmd);
void sprite_add(s32 sprite);
void sprite_delete(s32 id);
u16 *sprite_find(u16 id);
void sprite_draw_all(ViewBuffer *view);
void sprite_set_clut_entry(u16 id, s32 index, u16 color);
void sprite_fill_clut(u16 id, s32 first, s32 last, u16 color);
void sprite_restore_clut(u16 id, s32 first, s32 last);
void sprite_set_visible(s32 id, s32 visible);
void sprite_set_cell(s32 id, s32 col, s32 row);
void sprite_title_run(s32 restarted);
void sprite_station_show_prompt(s16 show);
void sprite_station_board_train(s16 direction);
void sprite_station_init(void);
void sprite_station_exit_to_town(void);
void sprite_phone_run(void);

/* Declared in the calling files, each with the argument and return widths its code needs:
   sprite_copy_cell, sprite_phone_save_exit. */

#endif
