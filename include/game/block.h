#ifndef GAME_BLOCK_H
#define GAME_BLOCK_H

#include "common.h"
#include "game/types.h"
#include "kaj/view.h"

typedef struct BlockListNode {
    u8 unk0[0x4];
    struct BlockListNode *next;
    Block *data;
} BlockListNode;

typedef struct BlockList {
    BlockListNode *head;
    BlockListNode *tail;
    BlockListNode *cursor;
    s32 count;
} BlockList;

typedef struct TmdTri {
    u16 run_count;
    u8 unk2[0x1];
    u8 mode;
    u8 code_r;
    u8 code_g;
    u8 code_b;
    u8 unk7[0x1];
    u16 normal;
    u16 vert0;
    u16 vert1;
    u16 vert2;
} TmdTri;

/* TMD object table entry: vertex, normal and primitive tops and counts (block_hit_tris walks the primitives). */
typedef struct TmdObject {
    s32 vert_top;
    s32 unk4;
    s32 normal_top;
    s32 unkC;
    TmdTri *primitive_top;
    s32 n_primitive;
} TmdObject;

/* Functions of src/game/block.c that other files call or a table names. */
void block_setup(Block *block, u16 mode);
void block_draw_all(ViewBuffer *view, u16 mode);
void block_update_visibility(u16 mode);
void block_create_all(void);
void block_set_mode(u16 mode);
void block_stream_update(u16 mode);
s16 block_point_on_model(void *obj, s32 x, s32 y, s32 z, u16 mode);
s32 block_vehicle_surface(s32 x, s32 z, s32 height_out);
s32 block_find_surface(s32 x, s32 z, s32 *height_out, s16 all);
s32 block_find_surface_nearest(s32 x, s32 y, s32 z, s32 *height_out);
s32 block_fit_ground_tilt(s32 *height_out, s16 all);
void block_replace_arena(ArenaHeader *old_header, ArenaHeader *new_header);
void block_create(Block **block_p, s32 size);
Block *block_find_at(s32 x, s32 y, s32 z);
void block_set_origin(s32 x, s32 y, s32 z);
s32 block_has_ground_at(s32 x, s32 height_out, s32 z);
void block_hide_all(void);
void block_list_add(s32 block);
void block_free_all(void);
void block_free_owned(void);
void block_stream_stop(void);
s32 block_model_surface(void *obj, s32 x, s32 z, s32 height_out);
s32 block_cd_idle(void);
void block_enter_area(u32 code);

#endif
