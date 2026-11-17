#ifndef GAME_ROADMAP_H
#define GAME_ROADMAP_H

#include "common.h"
#include "game/types.h"

typedef struct RoadMap {
    u16 mode;
    s16 zoomed;
    s16 *part0;
    s16 *part1;
    s16 *part2;
} RoadMap;

typedef struct {
    u8 unk0[8];
    s32 clut_rect[2];
    s16 u;
    u16 v;
    s16 u_shift;
    u8 unk16[2];
    u16 clut;
    u16 tpage;
    s32 clut_orig;
    s32 clut_work;
} RoadmapTim;

typedef struct RoadmapSprite {
    u16 id;
    u16 mode;
    s16 visible;
    s16 clut_dirty;
    s16 color;
    s16 x;
    s16 y;
    s16 depth;
    u16 cell_w;
    u16 cell_h;
    u8 unk14[4];
    u16 cell_col;
    u16 cell_row;
    RoadmapTim *tim;
} RoadmapSprite;

/* Functions of src/game/roadmap.c that other files call or a table names. */
void roadmap_init(void);
void roadmap_quit(void);
void *roadmap_add_sprite(RoadmapSprite *sprite, void *packet, u32 *ot_base);
void roadmap_init_draw(void);
void roadmap_draw_frame(u16 mode);
void roadmap_draw_sprite_frame(u16 id);
void roadmap_start_flash(s32 red, s32 green, s32 blue, s32 duration);

/* Declared in the calling files, each with the argument and return widths its code needs:
   roadmap_get_state. */

#endif
