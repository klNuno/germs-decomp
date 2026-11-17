#ifndef KAJ_VIEW_H
#define KAJ_VIEW_H

#include "common.h"
#include "game/types.h"

typedef struct ViewBuffer {
    u8 unk0[0x17];
    u8 dfe;
    u8 isbg;
    u8 bg_r;
    u8 bg_g;
    u8 bg_b;
    u8 unk1C[0x40];
    u8 disp_env[0x14];
    s32 ot_length;
    u32 *ot_org;
    s32 ot_offset;
    s32 ot_point;
    u32 *ot_tag;
    u32 *ot_tags;
    s32 packets;
} ViewBuffer;

/* Functions of src/kaj/view.c that other files call or a table names. */
void kaj_view_init(void);
s32 kaj_view_packet_used(void);
ViewBuffer *kaj_view_begin_frame(void);
void kaj_view_flip(ViewBuffer *buf);
void kaj_view_set_bg_color(u8 r, u8 g, u8 b);
void kaj_view_clear_vram(void);

#endif
