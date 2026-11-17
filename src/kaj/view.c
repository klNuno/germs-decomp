#include "common.h"
#include "kaj/view.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "psyq/libapi.h"
#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#include "psyq/libgs.h"
#include "psyq/libgte.h"

/*
 * The double buffered view: packets, flip, clear.
 *
 * File boundaries: likely (docs/layout.md): view.c asserts; Sony code after.
 */

extern ViewBuffer kaj_view_buffers[2];
ViewBuffer *kaj_view_current;
extern KajSystem kaj_system;
extern s32 PSDCNT;
extern s16 PSDIDX;
s32 kaj_view_last_vsync;
extern char kaj_view_str_file[];
extern s32 kaj_system_vsync_delta[];

void kaj_view_init(void) {
    ViewBuffer *p;
    s32 i;

    VSync(0);
    GsInitGraph(0x140, 0xF0, 4, 1, 0);
    VSync(0);
    GsDefDispBuff(0, 0, 0, 0xF0);
    SetDefDispEnv(kaj_view_buffers[0].disp_env, 0, 0xF0, 0x140, 0xF0);
    SetDefDispEnv(kaj_view_buffers[1].disp_env, 0, 0, 0x140, 0xF0);
    SetDefDrawEnv(&kaj_view_buffers[0], 0, 0, 0x140, 0xF0);
    SetDefDrawEnv(&kaj_view_buffers[1], 0, 0xF0, 0x140, 0xF0);
    for (i = 0; i < 2; i++) {
        p = &kaj_view_buffers[i];
        p->isbg = 1;
        p->dfe = 0;
        p->bg_r = 0;
        p->bg_g = 0;
        p->bg_b = 0;
        p->ot_tags = kaj_malloc(0x8000);
        if (p->ot_tags == 0) {
            kaj_abend(3, "Error Allocating VIEW Tag", kaj_view_str_file, 0x30);
        }
        p->packets = (s32)kaj_malloc(0x2C000);
        if (p->packets == 0) {
            kaj_abend(3, "Error Allocating VIEW Packet", kaj_view_str_file, 0x35);
        }
        p->ot_length = 13;
        p->ot_org = p->ot_tags;
        p->ot_point = 0;
        p->ot_offset = 0;
        p->ot_tag = p->ot_tags + 0x1FFF;
    }
    VSync(0);
    GsInit3D();
    GsInitVcount();
    SetGeomOffset(0xA0, 0x78);
    GsSetProjection(0xE4);
    SetBackColor(0, 0, 0);
    SetFarColor(0, 0, 0);
    kaj_view_current = kaj_view_buffers;
    kaj_system_vsync_delta[0] = 0;
}

void kaj_view_quit(void) {
    free3(kaj_view_buffers[0].ot_tags);
    free3(kaj_view_buffers[1].ot_tags);
    free3((void *)kaj_view_buffers[0].packets);
    free3((void *)kaj_view_buffers[1].packets);
    SetDispMask(0);
}

s32 kaj_view_packet_used(void) {
    return GsGetWorkBase() - kaj_view_current->packets;
}

ViewBuffer *kaj_view_begin_frame(void) {
    ViewBuffer *p = kaj_view_buffers;

    if (kaj_view_current == p) {
        p = &kaj_view_buffers[1];
    }
    kaj_view_current = p;
    GsSetWorkBase(p->packets);
    ClearOTagR(kaj_view_current->ot_tags, 0x2000);
    return kaj_view_current;
}

void kaj_view_flip(ViewBuffer *buf) {
    s32 vsync;
    s32 delta;
    s32 frame;

    if (buf->dfe == 0) {
        DrawSync(0);
        VSync(2);
        vsync = VSync(-1);
    } else {
        VSync(2);
        vsync = VSync(-1);
        ResetGraph(1);
    }
    PutDispEnv(buf->disp_env);
    PutDrawEnv(buf);
    frame = PSDCNT + 1;
    PSDCNT = frame;
    if (frame == 0) {
        frame = 1;
    }
    PSDCNT = frame;
    PSDIDX = PSDIDX == 0;
    DrawOTag(buf->ot_tags + 0x1FFF);
    {
        KajSystem *p = &kaj_system;
        s32 last = kaj_view_last_vsync;

        kaj_view_last_vsync = vsync;
        delta = vsync - last;
        p->vsync_delta = delta;
        if (delta < 0) {
            p->vsync_delta = delta + 0x7FFFFFFF;
        }
    }
}

void kaj_view_set_bg_color(u8 r, u8 g, u8 b) {
    ViewBuffer *p = kaj_view_buffers;

    p->bg_r = r;
    p->bg_g = g;
    p->bg_b = b;
    p++;
    p->bg_r = r;
    p->bg_g = g;
    p->bg_b = b;
}

void kaj_view_clear_vram(void) {
    Rect rect;

    rect.x = 0;
    rect.y = 0;
    rect.w = 0x140;
    rect.h = 0x1E0;
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
}
