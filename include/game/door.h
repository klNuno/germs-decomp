#ifndef GAME_DOOR_H
#define GAME_DOOR_H

#include "common.h"
#include "game/types.h"
#include "kaj/tss.h"
#include "kaj/view.h"

typedef struct Door {
    u16 id;
    s16 axis;
    s16 active;
    s16 visible;
    s16 ot_layer;
    s16 state;
    s16 move_from;
    s16 move_to;
    s32 block;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s16 angle;
    s16 speed;
    s16 auto_return;
    s16 unk26;
    s32 coord_flg;
    u8 coord_m[0x14];
    s32 coord_tx;
    s32 coord_ty;
    s32 coord_tz;
    u8 unk4C[0x2C];
    void *tmd_objects;
    void *record;
} Door;

typedef struct DoorListNode {
    u8 unk0[0x4];
    struct DoorListNode *next;
    Door *data;
} DoorListNode;

typedef struct DoorList {
    DoorListNode *head;
    DoorListNode *tail;
    DoorListNode *cursor;
    s32 count;
} DoorList;

typedef struct DoorMove {
    u16 id;
    u16 axis;
    s16 active;
    s16 visible;
    u8 unk8[0x2];
    u16 state;
    s16 move_from;
    s16 move_to;
    s32 block;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s16 angle;
    s16 speed;
    s16 auto_return;
    u8 unk26[0x2];
    s32 coord_flg;
    u8 coord_m[0x14];
    s32 coord_tx;
    s32 coord_ty;
    s32 coord_tz;
} DoorMove;

/* Functions of src/game/door.c that other files call or a table names. */
void door_setup(Door *door);
void door_refresh_all(void);
void door_update_all(void);
void door_start_open(DoorMove *door, s16 dist, s16 speed, s16 auto_return);
void door_start_close(DoorMove *door, s16 dist, s16 speed);
void door_exec_command(Action *action, EventState *event);
void door_create(Door **out, u32 record_size);
void door_add(void *door);
void door_free_all(void);
Door *door_find(u16 id);
void door_draw_all(ViewBuffer *view);
void door_rebase_all(s32 origin_x, s32 origin_y, s32 origin_z);
void door_set_visible(u16 id, s16 visible);
void door_fade_step(TssSlot *task);

#endif
