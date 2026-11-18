#ifndef GAME_THING_H
#define GAME_THING_H

#include "common.h"
#include "game/types.h"
#include "kaj/view.h"

typedef struct Thing {
    u16 id;
    u16 type;
    s16 active;
    s16 animate;
    s16 script_enabled;
    s16 ot_layer;
    s16 enter_set;
    s16 leave_set;
    s16 block_fixed;
    u8 unk12[0x2];
    s32 block;
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 unk2A[0x2];
    s32 coord_flg;
    u8 coord_m[0x14];
    s32 coord_tx;
    s32 coord_ty;
    s32 coord_tz;
    u8 unk50[0x2C];
    void *tmd_objects;
    void *hit_model;
    void *record;
} Thing;

/* Functions of src/game/thing.c that other files call or a table names. */
void thing_init_from_record(Thing *thing);
void thing_refresh_all(void);
void thing_draw_all(ViewBuffer *view);
void thing_update_all(void);
void thing_create(Thing **out, u32 record_size);
void thing_list_add(s32 thing);
void thing_free_all(void);
Thing *thing_find(s32 type, s32 id);
u16 thing_hit_test(s32 x, s32 y, s32 z, u16 mode);
void thing_set_origin(s32 origin_x, s32 origin_y, s32 origin_z);
void thing_set_active(s32 type, s32 id, s16 active);
void thing_set_animate(s32 type, s32 id, s16 animate);
void thing_set_flag10(s32 type, s32 id, s16 block_fixed);
void thing_cmd_set_active(Action *action);

/* Declared in the calling files, each with the argument and return widths its code needs:
   thing_run_script. */

#endif
