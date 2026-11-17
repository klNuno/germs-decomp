#include "common.h"
#include "game/roadmap.h"
#include "game/actor.h"
#include "game/block.h"
#include "game/door.h"
#include "game/mod.h"
#include "game/npc.h"
#include "game/sprite.h"
#include "game/thing.h"
#include "game/vehicle.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "kaj/view.h"
#include "psyq/libgpu.h"
#include "psyq/libgte.h"
#include "gte.h"

/*
 * The road map: clipped polygons, sprites and the flash.
 *
 * File boundaries: likely (docs/layout.md): roadmap.c asserts.
 */

extern RoadMap roadmap_state;
typedef struct { s16 active; s16 frames_left; u8 red; u8 green; u8 blue; u8 unk7; } RoadmapFlash;
RoadmapFlash roadmap_flash;
extern ScreenLight screen_light;
typedef struct { u8 unk0[0x18]; void (*handler)(); s32 unk1C; } RoadmapPrimHandler;
extern RoadmapPrimHandler roadmap_prim_handlers[8];
typedef struct { s32 ndiv; s32 pih; s32 piv; u16 clut; u16 tpage; } DivPolygon;
extern DivPolygon roadmap_divpoly3;
extern DivPolygon roadmap_divpoly4;
typedef struct { u8 unk0[0x10]; } ClipVector;
extern ClipVector roadmap_clip_buf;
u8 roadmap_ft_color_r;
u8 roadmap_ft_color_g;
u8 roadmap_ft_color_b;
static void roadmap_draw_f3();
static void roadmap_draw_g3();
typedef struct {
    u8 olen;
    u8 ilen;
    u8 flag;
    u8 mode;
    u8 u0;
    u8 v0;
    u16 clut;
    u8 u1;
    u8 v1;
    u16 tpage;
    u8 u2;
    u8 v2;
    u16 pad;
    u8 r;
    u8 g;
    u8 b;
    u8 pad2;
    u16 vert0;
    u16 vert1;
    u16 vert2;
    u16 pad3;
} RoadmapPrimFT3;
typedef struct { u32 length; u32 *org; u32 offset; u32 point; u32 *tag; } GsOT;
static void *roadmap_draw_ft3(RoadmapPrimFT3 *op, SVector *vp, void *packet, s32 count, s32 shift, GsOT *ot);
typedef struct {
    u8 olen;
    u8 ilen;
    u8 flag;
    u8 mode;
    u8 u0;
    u8 v0;
    u16 clut;
    u8 u1;
    u8 v1;
    u16 tpage;
    u8 u2;
    u8 v2;
    u16 pad;
    u8 r0;
    u8 g0;
    u8 b0;
    u8 pad0;
    u8 r1;
    u8 g1;
    u8 b1;
    u8 pad1;
    u8 r2;
    u8 g2;
    u8 b2;
    u8 pad2;
    u16 vert0;
    u16 vert1;
    u16 vert2;
    u16 pad3;
} RoadmapPrimGT3;
static void *roadmap_draw_gt3(RoadmapPrimGT3 *op, SVector *vp, void *packet, s32 count, s32 shift, GsOT *ot);
static void roadmap_draw_f4();
static void roadmap_draw_g4();
typedef struct {
    u8 olen;
    u8 ilen;
    u8 flag;
    u8 mode;
    u8 u0;
    u8 v0;
    u16 clut;
    u8 u1;
    u8 v1;
    u16 tpage;
    u8 u2;
    u8 v2;
    u16 pad;
    u8 u3;
    u8 v3;
    u16 pad1;
    u8 r;
    u8 g;
    u8 b;
    u8 pad2;
    u16 vert0;
    u16 vert1;
    u16 vert2;
    u16 vert3;
} RoadmapPrimFT4;
static void *roadmap_draw_ft4(RoadmapPrimFT4 *op, SVector *vp, void *packet, s32 count, s32 shift, GsOT *ot);
typedef struct {
    u8 olen;
    u8 ilen;
    u8 flag;
    u8 mode;
    u8 u0;
    u8 v0;
    u16 clut;
    u8 u1;
    u8 v1;
    u16 tpage;
    u8 u2;
    u8 v2;
    u16 pad;
    u8 u3;
    u8 v3;
    u16 pad4;
    u8 r0;
    u8 g0;
    u8 b0;
    u8 pad0;
    u8 r1;
    u8 g1;
    u8 b1;
    u8 pad1;
    u8 r2;
    u8 g2;
    u8 b2;
    u8 pad2;
    u8 r3;
    u8 g3;
    u8 b3;
    u8 pad3;
    u16 vert0;
    u16 vert1;
    u16 vert2;
    u16 vert3;
} RoadmapPrimGT4;
static void *roadmap_draw_gt4(RoadmapPrimGT4 *op, SVector *vp, void *packet, s32 count, s32 shift, GsOT *ot);
extern KajSystem kaj_system;
u16 roadmap_frame_mode;
s32 roadmap_daylight_level;
s32 roadmap_brightness;
u16 roadmap_draw_flags;
static void roadmap_draw_flash(ViewBuffer *view);
extern Player *player_status_player[];
typedef struct { u8 r; u8 g; u8 b; u8 unk3; } SpriteColor;
extern SpriteColor roadmap_sprite_colors[2];
typedef struct {
    u32 tag;
    u8 r0;
    u8 g0;
    volatile u8 b0;
    u8 code;
    s16 x0;
    s16 y0;
    u8 u0;
    u8 v0;
    u16 clut;
    s16 w;
    s16 h;
} SprtPacket;
typedef struct {
    u32 tag;
    u8 r0;
    u8 g0;
    volatile u8 b0;
    u8 code;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    s16 x3;
    s16 y3;
} PolyF4Packet;
typedef struct { u8 r; u8 g; u8 b; u8 code; } RoadmapRgb;
/* one vertex of the near-plane clipper output (PSY-Q EVECTOR layout, 0x2C bytes) */
typedef struct {
    SVector v;
    s32 sx3;
    s32 sy3;
    s32 sz3;
    s32 pad3;
    s16 sx;
    s16 sy;
    RoadmapRgb rgb;
    s16 txuv;
    s16 pad;
    s32 chx;
    s32 chy;
} ClipVertex;
typedef struct {
    u32 tag;
    u8 r0;
    u8 g0;
    u8 b0;
    u8 code;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
} PolyF3Packet;
/* LIBGS GsOT: the ordering table header the packet builders link into */
/* screen and depth extent of one projected triangle */
typedef struct {
    s32 xmin;
    s32 xmax;
    s32 ymin;
    s32 ymax;
    s32 zmin;
    s32 zmax;
    s32 sz[4];
} RoadmapBounds;
/* the draw handler's per-primitive locals: the bounds, then abe and tge */
typedef struct {
    RoadmapBounds bounds;
    s16 tex_mode[2];
} RoadmapPrimWork;
typedef struct {
    u32 tag;
    u8 r0;
    u8 g0;
    u8 b0;
    u8 code;
    s16 x0;
    s16 y0;
    u8 r1;
    u8 g1;
    u8 b1;
    u8 pad1;
    s16 x1;
    s16 y1;
    u8 r2;
    u8 g2;
    u8 b2;
    u8 pad2;
    s16 x2;
    s16 y2;
} PolyG3Packet;
void SetShadeTex(void *p, s32 tge);
/* one textured flat triangle of the roadmap model (TMD primitive layout, 0x1C bytes) */
typedef struct {
    u32 tag;
    u8 r0;
    u8 g0;
    volatile u8 b0;
    u8 code;
    volatile s16 x0;
    volatile s16 y0;
    u8 u0;
    u8 v0;
    u16 clut;
    volatile s16 x1;
    volatile s16 y1;
    u8 u1;
    u8 v1;
    u16 tpage;
    volatile s16 x2;
    volatile s16 y2;
    u8 u2;
    u8 v2;
    u16 pad;
} PolyFT3Packet;
void *DivideFT3(SVector *v0, SVector *v1, SVector *v2, u32 *uv0, u32 *uv1, u32 *uv2,
                RoadmapRgb *rgbc, void *packet, u32 *ot, DivPolygon *divp);
/* inside the InitClip box of roadmap_init_draw (0x150 x 0x100, near 0x6E, far 0xFFFF) */
/* an edge crosses the near plane, or the triangle is too large on screen: subdivide it */
/* one textured gouraud triangle of the roadmap model (TMD primitive layout, 0x24 bytes) */
typedef struct {
    u32 tag;
    u8 r0;
    u8 g0;
    u8 b0;
    u8 code;
    volatile s16 x0;
    volatile s16 y0;
    u8 u0;
    u8 v0;
    u16 clut;
    u8 r1;
    u8 g1;
    u8 b1;
    u8 pad1;
    volatile s16 x1;
    volatile s16 y1;
    u8 u1;
    u8 v1;
    u16 tpage;
    u8 r2;
    u8 g2;
    u8 b2;
    u8 pad2;
    volatile s16 x2;
    volatile s16 y2;
    u8 u2;
    u8 v2;
    u16 pad;
} PolyGT3Packet;
void *DivideGT3(SVector *v0, SVector *v1, SVector *v2, u32 *uv0, u32 *uv1, u32 *uv2, RoadmapRgb *rgb0,
                RoadmapRgb *rgb1, RoadmapRgb *rgb2, void *packet, u32 *ot, DivPolygon *divp);
/* one textured flat quad of the roadmap model (TMD primitive layout, 0x20 bytes) */
typedef struct {
    u32 tag;
    u8 r0;
    u8 g0;
    volatile u8 b0;
    u8 code;
    volatile s16 x0;
    volatile s16 y0;
    u8 u0;
    u8 v0;
    u16 clut;
    volatile s16 x1;
    volatile s16 y1;
    u8 u1;
    u8 v1;
    u16 tpage;
    volatile s16 x2;
    volatile s16 y2;
    u8 u2;
    u8 v2;
    u16 pad;
    volatile s16 x3;
    volatile s16 y3;
    u8 u3;
    u8 v3;
    u16 pad1;
} PolyFT4Packet;
void *DivideFT4(SVector *v0, SVector *v1, SVector *v2, SVector *v3, u32 *uv0, u32 *uv1, u32 *uv2, u32 *uv3,
                RoadmapRgb *rgbc, void *packet, u32 *ot, DivPolygon *divp);
/* one textured gouraud quad of the roadmap model (TMD primitive layout, 0x2C bytes) */
typedef struct {
    u32 tag;
    u8 r0;
    u8 g0;
    u8 b0;
    u8 code;
    volatile s16 x0;
    volatile s16 y0;
    u8 u0;
    u8 v0;
    u16 clut;
    u8 r1;
    u8 g1;
    u8 b1;
    u8 pad1;
    volatile s16 x1;
    volatile s16 y1;
    u8 u1;
    u8 v1;
    u16 tpage;
    u8 r2;
    u8 g2;
    u8 b2;
    u8 pad2;
    volatile s16 x2;
    volatile s16 y2;
    u8 u2;
    u8 v2;
    u16 pad;
    u8 r3;
    u8 g3;
    u8 b3;
    u8 pad3;
    volatile s16 x3;
    volatile s16 y3;
    u8 u3;
    u8 v3;
    u16 pad4;
} PolyGT4Packet;
void *DivideGT4(SVector *v0, SVector *v1, SVector *v2, SVector *v3, u32 *uv0, u32 *uv1, u32 *uv2, u32 *uv3,
                RoadmapRgb *rgb0, RoadmapRgb *rgb1, RoadmapRgb *rgb2, RoadmapRgb *rgb3, void *packet, u32 *ot,
                DivPolygon *divp);
extern s32 kaj_system_vsync_delta[];
extern void *GsOUT_PACKET_P;

void roadmap_init(void) {
    RoadMap *map = &roadmap_state;

    roadmap_state.mode = 0;
    map->zoomed = 0;
    map->part0 = sprite_find(0x405);
    map->part1 = sprite_find(0x406);
    map->part2 = sprite_find(0x407);
    if (map->part0 == NULL || map->part1 == NULL || map->part2 == NULL) {
        kaj_abend(5, "Road Map Parts not Found", "roadmap.c", 0x20);
    }
}

void roadmap_quit(void) {
    RoadMap *map = &roadmap_state;

    roadmap_state.mode = 0;
    map->zoomed = 0;
    map->part0[2] = 0;
    map->part1[2] = 0;
    map->part2[2] = 0;
    map->part0 = NULL;
    map->part1 = NULL;
    map->part2 = NULL;
}

u16 roadmap_get_state(void) {
    return roadmap_state.mode;
}

static void *roadmap_add_clipped_f3(ClipVertex *v0, ClipVertex *v1, ClipVertex *v2, RoadmapRgb *rgb, void *packet,
                             GsOT *ot, ScreenLight *light, RoadmapPrimWork *work) {
    PolyF3Packet *poly;
    RoadmapRgb *color;
    RoadmapRgb *rgbc;
    u32 *tag;
    s32 dp;
    s32 otz;
    s32 depth;
    s32 level;
    s32 fog;

    ((u8 *)packet)[3] = 4;
    ((u8 *)packet)[7] = 0x20;
    poly = packet;
    SetSemiTrans(packet, work->tex_mode[0]);
    *(u32 *)&poly->x0 = *(u32 *)&v0->sx;
    *(u32 *)&poly->x1 = *(u32 *)&v1->sx;
    *(u32 *)&poly->x2 = *(u32 *)&v2->sx;
    poly->r0 = rgb->r;
    poly->g0 = rgb->g;
    poly->b0 = rgb->b;
    gte_stdp(&dp);
    gte_avsz3();
    gte_stotz(&otz);
    if (roadmap_draw_flags != 0) {
        level = 0x1000;
        fog = 0;
        color = (RoadmapRgb *)&poly->r0;
        depth = dp;
        if (roadmap_draw_flags & 1) {
            level = roadmap_daylight_level;
        }
        if (roadmap_draw_flags & 2) {
            fog = depth;
        }
        gte_lddp(level);
        gte_ldcv(color);
        gte_gpf12();
        gte_lddp(0);
        gte_gpl12();
        gte_stcv(color);
        gte_ldrgb(color);
        gte_lddp(fog);
        gte_dpcs();
        gte_strgb(color);
        if (roadmap_draw_flags & 4) {
            gte_lddp(roadmap_brightness);
            gte_ldcv(color);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(color);
        }
    }
    if (light->bg_color_pending != 0) {
        light->bg_color_pending = 0;
        rgbc = (RoadmapRgb *)&poly->r0;
        kaj_view_set_bg_color(rgbc->r, rgbc->g, rgbc->b);
    }
    tag = ot->org + (otz / 4 + light->ot_bias);
    poly->tag = (*tag & 0xFFFFFF) | 0x04000000;
    *tag = (u32)poly & 0xFFFFFF;
    return (PolyF3Packet *)packet + 1;
}

static void *roadmap_add_clipped_g3(ClipVertex *v0, ClipVertex *v1, ClipVertex *v2, void *packet, GsOT *ot,
                             ScreenLight *light, RoadmapPrimWork *work) {
    PolyG3Packet *poly;
    RoadmapRgb *rgb0;
    RoadmapRgb *rgb1;
    RoadmapRgb *rgb2;
    RoadmapRgb *rgbc;
    u32 *tag;
    s32 dp;
    s32 otz;
    s32 depth;
    s32 level;
    s32 fog;

    ((u8 *)packet)[3] = 6;
    ((u8 *)packet)[7] = 0x30;
    poly = packet;
    SetSemiTrans(packet, work->tex_mode[0]);
    *(u32 *)&poly->x0 = *(u32 *)&v0->sx;
    *(u32 *)&poly->x1 = *(u32 *)&v1->sx;
    *(u32 *)&poly->x2 = *(u32 *)&v2->sx;
    poly->r0 = v0->rgb.r;
    poly->g0 = v0->rgb.g;
    poly->b0 = v0->rgb.b;
    poly->r1 = v1->rgb.r;
    poly->g1 = v1->rgb.g;
    poly->b1 = v1->rgb.b;
    poly->r2 = v2->rgb.r;
    poly->g2 = v2->rgb.g;
    poly->b2 = v2->rgb.b;
    gte_stdp(&dp);
    gte_avsz3();
    gte_stotz(&otz);
    if (roadmap_draw_flags != 0) {
        level = 0x1000;
        fog = 0;
        rgb0 = (RoadmapRgb *)&poly->r0;
        rgb1 = (RoadmapRgb *)&poly->r1;
        rgb2 = (RoadmapRgb *)&poly->r2;
        depth = dp;
        if (roadmap_draw_flags & 1) {
            level = roadmap_daylight_level;
        }
        if (roadmap_draw_flags & 2) {
            fog = depth;
        }
        gte_lddp(level);
        gte_ldcv(rgb0);
        gte_gpf12();
        gte_lddp(0);
        gte_gpl12();
        gte_stcv(rgb0);
        gte_ldrgb(rgb0);
        gte_lddp(fog);
        gte_dpcs();
        gte_strgb(rgb0);
        gte_lddp(level);
        gte_ldcv(rgb1);
        gte_gpf12();
        gte_lddp(0);
        gte_gpl12();
        gte_stcv(rgb1);
        gte_ldrgb(rgb1);
        gte_lddp(fog);
        gte_dpcs();
        gte_strgb(rgb1);
        gte_lddp(level);
        gte_ldcv(rgb2);
        gte_gpf12();
        gte_lddp(0);
        gte_gpl12();
        gte_stcv(rgb2);
        gte_ldrgb(rgb2);
        gte_lddp(fog);
        gte_dpcs();
        gte_strgb(rgb2);
        if (roadmap_draw_flags & 4) {
            gte_lddp(roadmap_brightness);
            gte_ldcv(rgb0);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb0);
            gte_lddp(roadmap_brightness);
            gte_ldcv(rgb1);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb1);
            gte_lddp(roadmap_brightness);
            gte_ldcv(rgb2);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb2);
        }
    }
    if (light->bg_color_pending != 0) {
        light->bg_color_pending = 0;
        rgbc = (RoadmapRgb *)&poly->r0;
        kaj_view_set_bg_color(rgbc->r, rgbc->g, rgbc->b);
    }
    tag = ot->org + (otz / 4 + light->ot_bias);
    poly->tag = (*tag & 0xFFFFFF) | 0x06000000;
    *tag = (u32)poly & 0xFFFFFF;
    return (PolyG3Packet *)packet + 1;
}

INCLUDE_ASM("asm/nonmatchings/game/roadmap", roadmap_draw_f3);

INCLUDE_ASM("asm/nonmatchings/game/roadmap", roadmap_draw_g3);

static inline s32 roadmap_bounds_visible(RoadmapBounds *b) {
    if (b->xmax < -16 || b->xmin >= 0x150 || b->ymax < -16 || b->ymin >= 0x100 || b->zmax < 0x6E ||
        b->zmin > 0xFFFF) {
        return 0;
    }
    return 1;
}

static inline s32 roadmap_bounds_need_divide(RoadmapBounds *b, s32 n) {
    s32 i;
    s32 prev;
    for (prev = n - 1, i = 0; i < n; prev = i, i++) {
        if (b->sz[prev] >= 0x6E && b->sz[i] < 0x6E) {
            return 1;
        }
        if (b->sz[i] >= 0x6E && b->sz[prev] < 0x6E) {
            return 1;
        }
    }
    if (b->xmax - b->xmin >= 0x100 || b->ymax - b->ymin >= 0x80) {
        return 1;
    }
    return 0;
}

static void *roadmap_draw_ft3(RoadmapPrimFT3 *op, SVector *vp, void *packet, s32 count, s32 shift, GsOT *ot) {
    DivPolygon *divp = &roadmap_divpoly3;
    ScreenLight *light = &screen_light;
    RoadmapBounds b;
    s16 tex_mode[2];
    s32 flag;
    s32 opz;
    s32 dp;
    s32 otz;
    PolyFT3Packet *poly;
    RoadmapRgb *rgb;
    RoadmapRgb *rgbc;
    u32 *tag;
    s32 color_kind;
    s32 divide;
    s32 depth;
    s32 level;
    s32 fog;
    s32 ndiv;
    s32 z;
    s32 i;

    for (i = 0; i < count; i++, op++) {
        if ((u32)kaj_view_packet_used() > 0xAE00) {
            return packet;
        }
        ((u8 *)packet)[3] = 7;
        ((u8 *)packet)[7] = 0x24;
        tex_mode[0] = (op->mode >> 1) & 1;
        SetSemiTrans(packet, tex_mode[0]);
        tex_mode[1] = !(op->mode & 1);
        SetShadeTex(packet, tex_mode[1]);
        poly = packet;
        gte_ldv3(&vp[op->vert0], &vp[op->vert1], &vp[op->vert2]);
        gte_rtpt();
        gte_stflg(&flag);
        if (light->clip_mode == 1 && flag < 0) {
            continue;
        }
        gte_nclip();
        gte_stopz(&opz);
        if (opz <= 0) {
            continue;
        }
        gte_stsxy3_ft3(poly);
        gte_stsz3(&b.sz[0], &b.sz[1], &b.sz[2]);
        if (poly->x0 > poly->x1) {
            b.xmax = poly->x0;
            b.xmin = poly->x1;
        } else {
            b.xmin = poly->x0;
            b.xmax = poly->x1;
        }
        if (poly->x2 > b.xmax) {
            b.xmax = poly->x2;
        } else if (poly->x2 < b.xmin) {
            b.xmin = poly->x2;
        }
        if (poly->y0 > poly->y1) {
            b.ymax = poly->y0;
            b.ymin = poly->y1;
        } else {
            b.ymin = poly->y0;
            b.ymax = poly->y1;
        }
        if (poly->y2 > b.ymax) {
            b.ymax = poly->y2;
        } else if (poly->y2 < b.ymin) {
            b.ymin = poly->y2;
        }
        if (b.sz[0] > b.sz[1]) {
            b.zmax = b.sz[0];
            b.zmin = b.sz[1];
        } else {
            b.zmin = b.sz[0];
            b.zmax = b.sz[1];
        }
        if (b.sz[2] > b.zmax) {
            b.zmax = b.sz[2];
        } else if (b.sz[2] < b.zmin) {
            b.zmin = b.sz[2];
        }
        if (!roadmap_bounds_visible(&b)) {
            continue;
        }
        gte_stdp(&dp);
        gte_avsz3();
        gte_stotz(&otz);
        if (*(u16 *)&op->r == 0xFFFF && op->b == 0xFF) {
            poly->r0 = roadmap_ft_color_r;
            poly->g0 = roadmap_ft_color_g;
            poly->b0 = roadmap_ft_color_b;
            color_kind = 1;
        } else if (*(u16 *)&op->r == 0xFEFE && op->b == 0xFE) {
            if (light->dark != 1) {
                continue;
            }
            poly->r0 = 0x40 - light->daylight_step;
            poly->g0 = 0x40 - light->daylight_step;
            poly->b0 = 0x40 - light->daylight_step;
            color_kind = 2;
        } else {
            poly->r0 = op->r;
            poly->g0 = op->g;
            poly->b0 = op->b;
            color_kind = 0;
        }
        if (roadmap_draw_flags != 0) {
            level = 0x1000;
            fog = 0;
            depth = dp;
            rgb = (RoadmapRgb *)&poly->r0;
            if ((roadmap_draw_flags & 1) && color_kind == 0) {
                level = roadmap_daylight_level;
            }
            if ((roadmap_draw_flags & 2) && color_kind != 2) {
                fog = depth;
            }
            gte_lddp(level);
            gte_ldcv(rgb);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb);
            gte_ldrgb(rgb);
            gte_lddp(fog);
            gte_dpcs();
            gte_strgb(rgb);
            if (roadmap_draw_flags & 4) {
                gte_lddp(roadmap_brightness);
                gte_ldcv(rgb);
                gte_gpf12();
                gte_lddp(0);
                gte_gpl12();
                gte_stcv(rgb);
            }
        }
        tag = ot->org + (otz / 4 + light->ot_bias);
        if (flag < 0 || (light->clip_mode == 0 && (divide = roadmap_bounds_need_divide(&b, 3)) != 0)) {
            z = otz;
            if (z < 0) {
                z = 0;
            }
            if (roadmap_frame_mode == 2) {
                ndiv = 3 - z / 110;
            } else {
                ndiv = 3 - z / 228;
            }
            if (ndiv <= 0) {
                ndiv = 1;
            }
            divp->ndiv = ndiv;
            divp->clut = op->clut;
            divp->tpage = op->tpage;
            rgbc = (RoadmapRgb *)&poly->r0;
            packet = DivideFT3(&vp[op->vert0], &vp[op->vert1], &vp[op->vert2], (u32 *)&op->u0, (u32 *)&op->u1,
                               (u32 *)&op->u2, rgbc, packet, tag, divp);
            if (light->bg_color_pending != 0) {
                light->bg_color_pending = 0;
                kaj_view_set_bg_color(rgbc->r * 0x333 >> 10, rgbc->g * 0x333 >> 10, rgbc->b * 0x333 >> 10);
            }
        } else {
            *(u32 *)&poly->u0 = *(u32 *)&op->u0;
            *(u32 *)&poly->u1 = *(u32 *)&op->u1;
            *(u32 *)&poly->u2 = *(u32 *)&op->u2;
            poly->tag = (*tag & 0xFFFFFF) | 0x07000000;
            *tag = (u32)poly & 0xFFFFFF;
            packet = (PolyFT3Packet *)packet + 1;
        }
    }
    return packet;
}

static void *roadmap_draw_gt3(RoadmapPrimGT3 *op, SVector *vp, void *packet, s32 count, s32 shift, GsOT *ot) {
    DivPolygon *divp = &roadmap_divpoly3;
    ScreenLight *light = &screen_light;
    RoadmapBounds b;
    s16 tex_mode[2];
    s32 flag;
    s32 opz;
    s32 dp;
    s32 otz;
    PolyGT3Packet *poly;
    RoadmapRgb *rgb0;
    RoadmapRgb *rgb1;
    RoadmapRgb *rgb2;
    RoadmapRgb *rgbc;
    u32 *tag;
    s32 divide;
    s32 depth;
    s32 level;
    s32 fog;
    s32 ndiv;
    s32 z;
    s32 i;

    for (i = 0; i < count; i++, op++) {
        if ((u32)kaj_view_packet_used() > 0xAD80) {
            return packet;
        }
        ((u8 *)packet)[3] = 9;
        ((u8 *)packet)[7] = 0x34;
        tex_mode[0] = (op->mode >> 1) & 1;
        SetSemiTrans(packet, tex_mode[0]);
        tex_mode[1] = !(op->mode & 1);
        SetShadeTex(packet, tex_mode[1]);
        poly = packet;
        gte_ldv3(&vp[op->vert0], &vp[op->vert1], &vp[op->vert2]);
        gte_rtpt();
        gte_stflg(&flag);
        if (light->clip_mode == 1 && flag < 0) {
            continue;
        }
        gte_nclip();
        gte_stopz(&opz);
        if (opz <= 0) {
            continue;
        }
        gte_stsxy3_gt3(poly);
        gte_stsz3(&b.sz[0], &b.sz[1], &b.sz[2]);
        if (poly->x0 > poly->x1) {
            b.xmax = poly->x0;
            b.xmin = poly->x1;
        } else {
            b.xmin = poly->x0;
            b.xmax = poly->x1;
        }
        if (poly->x2 > b.xmax) {
            b.xmax = poly->x2;
        } else if (poly->x2 < b.xmin) {
            b.xmin = poly->x2;
        }
        if (poly->y0 > poly->y1) {
            b.ymax = poly->y0;
            b.ymin = poly->y1;
        } else {
            b.ymin = poly->y0;
            b.ymax = poly->y1;
        }
        if (poly->y2 > b.ymax) {
            b.ymax = poly->y2;
        } else if (poly->y2 < b.ymin) {
            b.ymin = poly->y2;
        }
        if (b.sz[0] > b.sz[1]) {
            b.zmax = b.sz[0];
            b.zmin = b.sz[1];
        } else {
            b.zmin = b.sz[0];
            b.zmax = b.sz[1];
        }
        if (b.sz[2] > b.zmax) {
            b.zmax = b.sz[2];
        } else if (b.sz[2] < b.zmin) {
            b.zmin = b.sz[2];
        }
        if (!roadmap_bounds_visible(&b)) {
            continue;
        }
        gte_stdp(&dp);
        gte_avsz3();
        gte_stotz(&otz);
        poly->r0 = op->r0;
        poly->g0 = op->g0;
        poly->b0 = op->b0;
        poly->r1 = op->r1;
        poly->g1 = op->g1;
        poly->b1 = op->b1;
        poly->r2 = op->r2;
        poly->g2 = op->g2;
        poly->b2 = op->b2;
        if (roadmap_draw_flags != 0) {
            level = 0x1000;
            fog = 0;
            rgb0 = (RoadmapRgb *)&poly->r0;
            rgb1 = (RoadmapRgb *)&poly->r1;
            depth = dp;
            rgb2 = (RoadmapRgb *)&poly->r2;
            if (roadmap_draw_flags & 1) {
                level = roadmap_daylight_level;
            }
            if (roadmap_draw_flags & 2) {
                fog = depth;
            }
            gte_lddp(level);
            gte_ldcv(rgb0);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb0);
            gte_ldrgb(rgb0);
            gte_lddp(fog);
            gte_dpcs();
            gte_strgb(rgb0);
            gte_lddp(level);
            gte_ldcv(rgb1);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb1);
            gte_ldrgb(rgb1);
            gte_lddp(fog);
            gte_dpcs();
            gte_strgb(rgb1);
            gte_lddp(level);
            gte_ldcv(rgb2);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb2);
            gte_ldrgb(rgb2);
            gte_lddp(fog);
            gte_dpcs();
            gte_strgb(rgb2);
            if (roadmap_draw_flags & 4) {
                gte_lddp(roadmap_brightness);
                gte_ldcv(rgb0);
                gte_gpf12();
                gte_lddp(0);
                gte_gpl12();
                gte_stcv(rgb0);
                gte_lddp(roadmap_brightness);
                gte_ldcv(rgb1);
                gte_gpf12();
                gte_lddp(0);
                gte_gpl12();
                gte_stcv(rgb1);
                gte_lddp(roadmap_brightness);
                gte_ldcv(rgb2);
                gte_gpf12();
                gte_lddp(0);
                gte_gpl12();
                gte_stcv(rgb2);
            }
        }
        tag = ot->org + (otz / 4 + light->ot_bias);
        if (flag < 0 || (light->clip_mode == 0 && (divide = roadmap_bounds_need_divide(&b, 3)) != 0)) {
            z = otz;
            if (z < 0) {
                z = 0;
            }
            if (roadmap_frame_mode == 2) {
                ndiv = 3 - z / 110;
            } else {
                ndiv = 3 - z / 228;
            }
            if (ndiv <= 0) {
                ndiv = 1;
            }
            divp->ndiv = ndiv;
            divp->clut = op->clut;
            divp->tpage = op->tpage;
            rgbc = (RoadmapRgb *)&poly->r0;
            packet = DivideGT3(&vp[op->vert0], &vp[op->vert1], &vp[op->vert2], (u32 *)&op->u0, (u32 *)&op->u1,
                               (u32 *)&op->u2, rgbc, (RoadmapRgb *)&poly->r1, (RoadmapRgb *)&poly->r2, packet, tag,
                               divp);
            if (light->bg_color_pending != 0) {
                light->bg_color_pending = 0;
                kaj_view_set_bg_color(rgbc->r * 0x333 >> 10, rgbc->g * 0x333 >> 10, rgbc->b * 0x333 >> 10);
            }
        } else {
            *(u32 *)&poly->u0 = *(u32 *)&op->u0;
            *(u32 *)&poly->u1 = *(u32 *)&op->u1;
            *(u32 *)&poly->u2 = *(u32 *)&op->u2;
            poly->tag = (*tag & 0xFFFFFF) | 0x09000000;
            *tag = (u32)poly & 0xFFFFFF;
            packet = (PolyGT3Packet *)packet + 1;
        }
    }
    return packet;
}

INCLUDE_ASM("asm/nonmatchings/game/roadmap", roadmap_draw_f4);

INCLUDE_ASM("asm/nonmatchings/game/roadmap", roadmap_draw_g4);

static void *roadmap_draw_ft4(RoadmapPrimFT4 *op, SVector *vp, void *packet, s32 count, s32 shift, GsOT *ot) {
    DivPolygon *divp = &roadmap_divpoly4;
    ScreenLight *light = &screen_light;
    RoadmapBounds b;
    s16 tex_mode[2];
    s32 flag;
    s32 opz;
    s32 flag3;
    s32 dp;
    s32 otz;
    PolyFT4Packet *poly;
    RoadmapRgb *rgb;
    RoadmapRgb *rgbc;
    u32 *tag;
    s32 color_kind;
    s32 divide;
    s32 depth;
    s32 level;
    s32 fog;
    s32 ndiv;
    s32 z;
    s32 i;

    for (i = 0; i < count; i++, op++) {
        if ((u32)kaj_view_packet_used() > 0xAD80) {
            return packet;
        }
        ((u8 *)packet)[3] = 9;
        ((u8 *)packet)[7] = 0x2C;
        tex_mode[0] = (op->mode >> 1) & 1;
        SetSemiTrans(packet, tex_mode[0]);
        tex_mode[1] = !(op->mode & 1);
        SetShadeTex(packet, tex_mode[1]);
        poly = packet;
        gte_ldv3(&vp[op->vert0], &vp[op->vert1], &vp[op->vert2]);
        gte_rtpt();
        gte_stflg(&flag);
        if (light->clip_mode == 1 && flag < 0) {
            continue;
        }
        gte_nclip();
        gte_stopz(&opz);
        if (opz <= 0) {
            continue;
        }
        gte_stsxy3_ft4(poly);
        gte_ldv0(&vp[op->vert3]);
        gte_rtps();
        gte_stflg(&flag3);
        flag |= flag3;
        gte_stsxy(&poly->x3);
        gte_stsz4(&b.sz[0], &b.sz[1], &b.sz[2], &b.sz[3]);
        if (poly->x0 > poly->x1) {
            b.xmax = poly->x0;
            b.xmin = poly->x1;
        } else {
            b.xmin = poly->x0;
            b.xmax = poly->x1;
        }
        if (poly->x2 > b.xmax) {
            b.xmax = poly->x2;
        } else if (poly->x2 < b.xmin) {
            b.xmin = poly->x2;
        }
        if (poly->x3 > b.xmax) {
            b.xmax = poly->x3;
        } else if (poly->x3 < b.xmin) {
            b.xmin = poly->x3;
        }
        if (poly->y0 > poly->y1) {
            b.ymax = poly->y0;
            b.ymin = poly->y1;
        } else {
            b.ymin = poly->y0;
            b.ymax = poly->y1;
        }
        if (poly->y2 > b.ymax) {
            b.ymax = poly->y2;
        } else if (poly->y2 < b.ymin) {
            b.ymin = poly->y2;
        }
        if (poly->y3 > b.ymax) {
            b.ymax = poly->y3;
        } else if (poly->y3 < b.ymin) {
            b.ymin = poly->y3;
        }
        if (b.sz[0] > b.sz[1]) {
            b.zmax = b.sz[0];
            b.zmin = b.sz[1];
        } else {
            b.zmin = b.sz[0];
            b.zmax = b.sz[1];
        }
        if (b.sz[2] > b.zmax) {
            b.zmax = b.sz[2];
        } else if (b.sz[2] < b.zmin) {
            b.zmin = b.sz[2];
        }
        if (b.sz[3] > b.zmax) {
            b.zmax = b.sz[3];
        } else if (b.sz[3] < b.zmin) {
            b.zmin = b.sz[3];
        }
        if (!roadmap_bounds_visible(&b)) {
            continue;
        }
        gte_stdp(&dp);
        gte_avsz4();
        gte_stotz(&otz);
        if (*(u16 *)&op->r == 0xFFFF && op->b == 0xFF) {
            poly->r0 = roadmap_ft_color_r;
            poly->g0 = roadmap_ft_color_g;
            poly->b0 = roadmap_ft_color_b;
            color_kind = 1;
        } else if (*(u16 *)&op->r == 0xFEFE && op->b == 0xFE) {
            if (light->dark != 1) {
                continue;
            }
            poly->r0 = 0x40 - light->daylight_step;
            poly->g0 = 0x40 - light->daylight_step;
            poly->b0 = 0x40 - light->daylight_step;
            color_kind = 2;
        } else {
            poly->r0 = op->r;
            poly->g0 = op->g;
            poly->b0 = op->b;
            color_kind = 0;
        }
        if (roadmap_draw_flags != 0) {
            level = 0x1000;
            fog = 0;
            depth = dp;
            rgb = (RoadmapRgb *)&poly->r0;
            if ((roadmap_draw_flags & 1) && color_kind == 0) {
                level = roadmap_daylight_level;
            }
            if ((roadmap_draw_flags & 2) && color_kind != 2) {
                fog = depth;
            }
            gte_lddp(level);
            gte_ldcv(rgb);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb);
            gte_ldrgb(rgb);
            gte_lddp(fog);
            gte_dpcs();
            gte_strgb(rgb);
            if (roadmap_draw_flags & 4) {
                gte_lddp(roadmap_brightness);
                gte_ldcv(rgb);
                gte_gpf12();
                gte_lddp(0);
                gte_gpl12();
                gte_stcv(rgb);
            }
        }
        tag = ot->org + (otz / 4 + light->ot_bias);
        if (flag < 0 || (light->clip_mode == 0 && (divide = roadmap_bounds_need_divide(&b, 4)) != 0)) {
            z = otz;
            if (z < 0) {
                z = 0;
            }
            if (roadmap_frame_mode == 2) {
                ndiv = 3 - z / 110;
            } else {
                ndiv = 3 - z / 228;
            }
            if (ndiv <= 0) {
                ndiv = 1;
            }
            divp->ndiv = ndiv;
            divp->clut = op->clut;
            divp->tpage = op->tpage;
            rgbc = (RoadmapRgb *)&poly->r0;
            packet = DivideFT4(&vp[op->vert0], &vp[op->vert1], &vp[op->vert2], &vp[op->vert3], (u32 *)&op->u0,
                               (u32 *)&op->u1, (u32 *)&op->u2, (u32 *)&op->u3, rgbc, packet, tag, divp);
            if (light->bg_color_pending != 0) {
                light->bg_color_pending = 0;
                kaj_view_set_bg_color(rgbc->r * 0x333 >> 10, rgbc->g * 0x333 >> 10, rgbc->b * 0x333 >> 10);
            }
        } else {
            *(u32 *)&poly->u0 = *(u32 *)&op->u0;
            *(u32 *)&poly->u1 = *(u32 *)&op->u1;
            *(u32 *)&poly->u2 = *(u32 *)&op->u2;
            *(u32 *)&poly->u3 = *(u32 *)&op->u3;
            poly->tag = (*tag & 0xFFFFFF) | 0x09000000;
            *tag = (u32)poly & 0xFFFFFF;
            packet = (PolyFT4Packet *)packet + 1;
        }
    }
    return packet;
}

static void *roadmap_draw_gt4(RoadmapPrimGT4 *op, SVector *vp, void *packet, s32 count, s32 shift, GsOT *ot) {
    DivPolygon *divp = &roadmap_divpoly4;
    ScreenLight *light = &screen_light;
    RoadmapBounds b;
    s16 tex_mode[2];
    s32 flag;
    s32 opz;
    s32 flag3;
    s32 dp;
    s32 otz;
    PolyGT4Packet *poly;
    RoadmapRgb *rgb0;
    RoadmapRgb *rgb1;
    RoadmapRgb *rgb2;
    RoadmapRgb *rgb3;
    RoadmapRgb *rgbc;
    u32 *tag;
    s32 divide;
    s32 depth;
    s32 level;
    s32 fog;
    s32 ndiv;
    s32 z;
    s32 i;

    for (i = 0; i < count; i++, op++) {
        if ((u32)kaj_view_packet_used() > 0xACC0) {
            return packet;
        }
        ((u8 *)packet)[3] = 0xC;
        ((u8 *)packet)[7] = 0x3C;
        tex_mode[0] = (op->mode >> 1) & 1;
        SetSemiTrans(packet, tex_mode[0]);
        tex_mode[1] = !(op->mode & 1);
        SetShadeTex(packet, tex_mode[1]);
        poly = packet;
        gte_ldv3(&vp[op->vert0], &vp[op->vert1], &vp[op->vert2]);
        gte_rtpt();
        gte_stflg(&flag);
        if (light->clip_mode == 1 && flag < 0) {
            continue;
        }
        gte_nclip();
        gte_stopz(&opz);
        if (opz <= 0) {
            continue;
        }
        gte_stsxy3_gt4(poly);
        gte_ldv0(&vp[op->vert3]);
        gte_rtps();
        gte_stflg(&flag3);
        flag |= flag3;
        gte_stsxy(&poly->x3);
        gte_stsz4(&b.sz[0], &b.sz[1], &b.sz[2], &b.sz[3]);
        if (poly->x0 > poly->x1) {
            b.xmax = poly->x0;
            b.xmin = poly->x1;
        } else {
            b.xmin = poly->x0;
            b.xmax = poly->x1;
        }
        if (poly->x2 > b.xmax) {
            b.xmax = poly->x2;
        } else if (poly->x2 < b.xmin) {
            b.xmin = poly->x2;
        }
        if (poly->x3 > b.xmax) {
            b.xmax = poly->x3;
        } else if (poly->x3 < b.xmin) {
            b.xmin = poly->x3;
        }
        if (poly->y0 > poly->y1) {
            b.ymax = poly->y0;
            b.ymin = poly->y1;
        } else {
            b.ymin = poly->y0;
            b.ymax = poly->y1;
        }
        if (poly->y2 > b.ymax) {
            b.ymax = poly->y2;
        } else if (poly->y2 < b.ymin) {
            b.ymin = poly->y2;
        }
        if (poly->y3 > b.ymax) {
            b.ymax = poly->y3;
        } else if (poly->y3 < b.ymin) {
            b.ymin = poly->y3;
        }
        if (b.sz[0] > b.sz[1]) {
            b.zmax = b.sz[0];
            b.zmin = b.sz[1];
        } else {
            b.zmin = b.sz[0];
            b.zmax = b.sz[1];
        }
        if (b.sz[2] > b.zmax) {
            b.zmax = b.sz[2];
        } else if (b.sz[2] < b.zmin) {
            b.zmin = b.sz[2];
        }
        if (b.sz[3] > b.zmax) {
            b.zmax = b.sz[3];
        } else if (b.sz[3] < b.zmin) {
            b.zmin = b.sz[3];
        }
        if (!roadmap_bounds_visible(&b)) {
            continue;
        }
        gte_stdp(&dp);
        gte_avsz4();
        gte_stotz(&otz);
        poly->r0 = op->r0;
        poly->g0 = op->g0;
        poly->b0 = op->b0;
        poly->r1 = op->r1;
        poly->g1 = op->g1;
        poly->b1 = op->b1;
        poly->r2 = op->r2;
        poly->g2 = op->g2;
        poly->b2 = op->b2;
        poly->r3 = op->r3;
        poly->g3 = op->g3;
        poly->b3 = op->b3;
        if (roadmap_draw_flags != 0) {
            level = 0x1000;
            fog = 0;
            rgb0 = (RoadmapRgb *)&poly->r0;
            rgb1 = (RoadmapRgb *)&poly->r1;
            rgb2 = (RoadmapRgb *)&poly->r2;
            depth = dp;
            rgb3 = (RoadmapRgb *)&poly->r3;
            if (roadmap_draw_flags & 1) {
                level = roadmap_daylight_level;
            }
            if (roadmap_draw_flags & 2) {
                fog = depth;
            }
            gte_lddp(level);
            gte_ldcv(rgb0);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb0);
            gte_ldrgb(rgb0);
            gte_lddp(fog);
            gte_dpcs();
            gte_strgb(rgb0);
            gte_lddp(level);
            gte_ldcv(rgb1);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb1);
            gte_ldrgb(rgb1);
            gte_lddp(fog);
            gte_dpcs();
            gte_strgb(rgb1);
            gte_lddp(level);
            gte_ldcv(rgb2);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb2);
            gte_ldrgb(rgb2);
            gte_lddp(fog);
            gte_dpcs();
            gte_strgb(rgb2);
            gte_lddp(level);
            gte_ldcv(rgb3);
            gte_gpf12();
            gte_lddp(0);
            gte_gpl12();
            gte_stcv(rgb3);
            gte_ldrgb(rgb3);
            gte_lddp(fog);
            gte_dpcs();
            gte_strgb(rgb3);
            if (roadmap_draw_flags & 4) {
                gte_lddp(roadmap_brightness);
                gte_ldcv(rgb0);
                gte_gpf12();
                gte_lddp(0);
                gte_gpl12();
                gte_stcv(rgb0);
                gte_lddp(roadmap_brightness);
                gte_ldcv(rgb1);
                gte_gpf12();
                gte_lddp(0);
                gte_gpl12();
                gte_stcv(rgb1);
                gte_lddp(roadmap_brightness);
                gte_ldcv(rgb2);
                gte_gpf12();
                gte_lddp(0);
                gte_gpl12();
                gte_stcv(rgb2);
                gte_lddp(roadmap_brightness);
                gte_ldcv(rgb3);
                gte_gpf12();
                gte_lddp(0);
                gte_gpl12();
                gte_stcv(rgb3);
            }
        }
        tag = ot->org + (otz / 4 + light->ot_bias);
        if (flag < 0 || (light->clip_mode == 0 && (divide = roadmap_bounds_need_divide(&b, 4)) != 0)) {
            z = otz;
            if (z < 0) {
                z = 0;
            }
            if (roadmap_frame_mode == 2) {
                ndiv = 3 - z / 110;
            } else {
                ndiv = 3 - z / 228;
            }
            if (ndiv <= 0) {
                ndiv = 1;
            }
            divp->ndiv = ndiv;
            divp->clut = op->clut;
            divp->tpage = op->tpage;
            rgbc = (RoadmapRgb *)&poly->r0;
            packet = DivideGT4(&vp[op->vert0], &vp[op->vert1], &vp[op->vert2], &vp[op->vert3], (u32 *)&op->u0,
                               (u32 *)&op->u1, (u32 *)&op->u2, (u32 *)&op->u3, rgbc, (RoadmapRgb *)&poly->r1,
                               (RoadmapRgb *)&poly->r2, (RoadmapRgb *)&poly->r3, packet, tag, divp);
            if (light->bg_color_pending != 0) {
                light->bg_color_pending = 0;
                kaj_view_set_bg_color(rgbc->r * 0x333 >> 10, rgbc->g * 0x333 >> 10, rgbc->b * 0x333 >> 10);
            }
        } else {
            *(u32 *)&poly->u0 = *(u32 *)&op->u0;
            *(u32 *)&poly->u1 = *(u32 *)&op->u1;
            *(u32 *)&poly->u2 = *(u32 *)&op->u2;
            *(u32 *)&poly->u3 = *(u32 *)&op->u3;
            poly->tag = (*tag & 0xFFFFFF) | 0x0C000000;
            *tag = (u32)poly & 0xFFFFFF;
            packet = (PolyGT4Packet *)packet + 1;
        }
    }
    return packet;
}

void *roadmap_add_sprite(RoadmapSprite *sprite, void *packet, u32 *ot_base) {
    ScreenLight *light = &screen_light;
    u8 *pkt;
    SprtPacket *sp;
    u32 *ot;
    u8 rgb[3];
    u8 u;
    s32 v;

    if ((u32)kaj_view_packet_used() > 0xAFF8) {
        return packet;
    }
    pkt = packet;
    sp = (SprtPacket *)pkt;
    ((u8 *)sp)[3] = 4;
    sp->code = 0x64;
    SetSemiTrans(sp, 1);
    sp->clut = sprite->tim->clut;
    if (light->fade_active != 0) {
        if ((player_status_player[0]->flags & 0x100) && sprite->id == 0x404) {
            sp->r0 = roadmap_sprite_colors[sprite->color].r;
            sp->g0 = roadmap_sprite_colors[sprite->color].g;
            sp->b0 = roadmap_sprite_colors[sprite->color].b;
        } else {
            rgb[0] = roadmap_sprite_colors[sprite->color].r * light->fade_level >> 12;
            rgb[1] = roadmap_sprite_colors[sprite->color].g * light->fade_level >> 12;
            rgb[2] = roadmap_sprite_colors[sprite->color].b * light->fade_level >> 12;
            sp->r0 = rgb[0];
            sp->g0 = rgb[1];
            sp->b0 = rgb[2];
        }
    } else {
        sp->r0 = roadmap_sprite_colors[sprite->color].r;
        sp->g0 = roadmap_sprite_colors[sprite->color].g;
        sp->b0 = roadmap_sprite_colors[sprite->color].b;
    }
    u = sprite->tim->u << sprite->tim->u_shift;
    v = sprite->tim->v;
    if (sprite->mode == 1) {
        u += sprite->cell_col * sprite->cell_w;
        v += sprite->cell_row * sprite->cell_h;
    }
    sp->u0 = u;
    sp->v0 = v;
    sp->x0 = sprite->x;
    sp->y0 = sprite->y;
    sp->w = sprite->cell_w;
    sp->h = sprite->cell_h;
    ot = ot_base + sprite->depth;
    *(u32 *)pkt = (*ot & 0xFFFFFF) | 0x04000000;
    *ot = (u32)pkt & 0xFFFFFF;
    pkt += 0x14;
    SetDrawMode(pkt, 0, 0, sprite->tim->tpage, 0);
    ot = ot_base + sprite->depth;
    *(u32 *)pkt = (*ot & 0xFFFFFF) | 0x02000000;
    *ot = (u32)pkt & 0xFFFFFF;
    pkt += 0xC;
    if (sprite->clut_dirty != 0) {
        LoadImage(sprite->tim->clut_rect, sprite->tim->clut_work);
        sprite->clut_dirty = 0;
    }
    return pkt;
}

/* Inline copy of roadmap_add_flash_quad (defined further down in the unit): the draw call below
 * keeps its body, including the missing return when the packet buffer is full. */
static inline PolyF4Packet *roadmap_add_flash_quad_inline(RoadmapFlash *flash, PolyF4Packet *tile, u32 *ot) {
    ScreenLight *light = &screen_light;
    u8 rgb[3];
    if ((u32)kaj_view_packet_used() <= 0xAFFA) {
        ((u8 *)tile)[3] = 5;
        tile->code = 0x28;
        SetSemiTrans(tile, 1);
        tile->x0 = 0;
        tile->y0 = 0;
        tile->x1 = 0x13F;
        tile->y1 = 0;
        tile->x2 = 0;
        tile->y2 = 0xEF;
        tile->x3 = 0x13F;
        tile->y3 = 0xEF;
        if (light->fade_active != 0) {
            rgb[0] = flash->red * light->fade_level >> 12;
            rgb[1] = flash->green * light->fade_level >> 12;
            rgb[2] = flash->blue * light->fade_level >> 12;
            tile->r0 = rgb[0];
            tile->g0 = rgb[1];
            tile->b0 = rgb[2];
        } else {
            tile->r0 = flash->red;
            tile->g0 = flash->green;
            tile->b0 = flash->blue;
        }
        tile->tag = (ot[0x10] & 0xFFFFFF) | 0x05000000;
        ot[0x10] = (u32)tile & 0xFFFFFF;
        return tile + 1;
    }
}

static void roadmap_draw_flash(ViewBuffer *view) {
    RoadmapFlash *flash = &roadmap_flash;

    if (roadmap_flash.active != 0) {
        if (flash->frames_left != 0) {
            flash->frames_left -= kaj_system_vsync_delta[0];
            if (flash->frames_left <= 0) {
                roadmap_flash.active = 0;
                flash->frames_left = 0;
            }
            SetSpadStack(0x1F8003FC);
            GsOUT_PACKET_P = roadmap_add_flash_quad_inline(flash, GsOUT_PACKET_P, view->ot_tags);
            ResetSpadStack();
        } else {
            roadmap_flash.active = 0;
        }
    }
}

void roadmap_init_draw(void) {
    RoadmapFlash *flash;

    roadmap_prim_handlers[0].handler = roadmap_draw_f3;
    roadmap_prim_handlers[1].handler = roadmap_draw_g3;
    roadmap_prim_handlers[2].handler = roadmap_draw_ft3;
    roadmap_prim_handlers[3].handler = roadmap_draw_gt3;
    roadmap_prim_handlers[4].handler = roadmap_draw_f4;
    roadmap_prim_handlers[5].handler = roadmap_draw_g4;
    roadmap_prim_handlers[6].handler = roadmap_draw_ft4;
    roadmap_prim_handlers[7].handler = roadmap_draw_gt4;
    roadmap_divpoly4.ndiv = 3;
    roadmap_divpoly3.ndiv = 3;
    roadmap_divpoly4.pih = 0x140;
    roadmap_divpoly3.pih = 0x140;
    roadmap_divpoly4.piv = 0xF0;
    roadmap_divpoly3.piv = 0xF0;
    screen_light.fade_level = 0x1000;
    screen_light.daylight_on = 0;
    screen_light.fog_on = 0;
    screen_light.fade_active = 0;
    screen_light.clip_mode = 0;
    screen_light.ot_bias = 3;
    screen_light.bg_color_pending = 0;
    screen_light.daylight_step = 0;
    screen_light.dark = 0;
    flash = &roadmap_flash;
    roadmap_flash.active = 0;
    flash->frames_left = 0;
    kaj_view_clear_vram();
    kaj_view_set_bg_color(0, 0, 0);
    flash->red = 0;
    flash->green = 0;
    flash->blue = 0;
    roadmap_ft_color_r = 0x60;
    roadmap_ft_color_g = 0x60;
    roadmap_ft_color_b = 0x60;
    InitClip(&roadmap_clip_buf, 0x150, 0x100, 0xE4, 0x6E, 0xFFFF);
}

void roadmap_draw_frame(u16 mode) {
    ScreenLight *light = &screen_light;
    ViewBuffer *view;
    s32 dusk;

    roadmap_brightness = light->fade_level;
    roadmap_daylight_level = light->daylight_step * 42 + light->daylight_step * 2 / 3 + 0x600;
    roadmap_frame_mode = mode;
    roadmap_draw_flags = 0;
    if (screen_light.daylight_on != 0 && light->dark == 1) {
        dusk = 0x3D - light->daylight_step;
        roadmap_ft_color_r = (dusk * 0x1334 >> 12) - 0x80;
        roadmap_ft_color_g = (dusk * 0x1334 >> 12) - 0x80;
        roadmap_ft_color_b = (dusk * 0x2CD >> 10) - 0x80;
        roadmap_draw_flags = 1;
    } else {
        roadmap_ft_color_r = 0x60;
        roadmap_ft_color_g = 0x60;
        roadmap_ft_color_b = 0x60;
    }
    if (light->fog_on != 0) {
        roadmap_draw_flags += 2;
    }
    if (light->fade_active != 0) {
        roadmap_draw_flags += 4;
    }
    view = kaj_view_begin_frame();
    sprite_draw_all(view);
    mod_npcrec_draw_all((s32)view);
    npc_draw_all((s32)view);
    roadmap_draw_flash(view);
    sprite_thing_draw_all(view);
    door_draw_all(view);
    mod_draw_player(view, mode);
    vehicle_draw(view);
    block_draw_all(view, mode);
    kaj_view_flip(view);
    if (kaj_system.pad_mode == 2) {
        kaj_system.pad_mode = 1;
    }
}

void roadmap_draw_sprite_frame(u16 id) {
    RoadmapSprite *sprite;
    ViewBuffer *view;

    roadmap_frame_mode = 3;
    roadmap_draw_flags = 0;
    sprite = (RoadmapSprite *)sprite_find(id);
    if (sprite != NULL && sprite->visible != 0) {
        view = kaj_view_begin_frame();
        SetSpadStack(0x1F8003FC);
        GsOUT_PACKET_P = roadmap_add_sprite(sprite, GsOUT_PACKET_P, view->ot_tags);
        ResetSpadStack();
        kaj_view_flip(view);
    }
}

void roadmap_start_flash(s32 red, s32 green, s32 blue, s32 duration) {
    RoadmapFlash *flash = &roadmap_flash;

    if (roadmap_flash.active == 0) {
        roadmap_flash.active = 1;
        flash->frames_left = duration;
        flash->red = red;
        flash->green = green;
        flash->blue = blue;
    }
}

PolyF4Packet *roadmap_add_flash_quad(RoadmapFlash *flash, PolyF4Packet *tile, u32 *ot) {
    ScreenLight *light = &screen_light;
    u8 rgb[3];

    if ((u32)kaj_view_packet_used() <= 0xAFFA) {
        ((u8 *)tile)[3] = 5;
        tile->code = 0x28;
        SetSemiTrans(tile, 1);
        tile->x0 = 0;
        tile->y0 = 0;
        tile->x1 = 0x13F;
        tile->y1 = 0;
        tile->x2 = 0;
        tile->y2 = 0xEF;
        tile->x3 = 0x13F;
        tile->y3 = 0xEF;
        if (light->fade_active != 0) {
            rgb[0] = flash->red * light->fade_level >> 12;
            rgb[1] = flash->green * light->fade_level >> 12;
            rgb[2] = flash->blue * light->fade_level >> 12;
            tile->r0 = rgb[0];
            tile->g0 = rgb[1];
            tile->b0 = rgb[2];
        } else {
            tile->r0 = flash->red;
            tile->g0 = flash->green;
            tile->b0 = flash->blue;
        }
        tile->tag = (ot[0x10] & 0xFFFFFF) | 0x05000000;
        ot[0x10] = (u32)tile & 0xFFFFFF;
        return tile + 1;
    }
}
