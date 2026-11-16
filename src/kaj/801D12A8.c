#include "common.h"
#include "game/types.h"

extern TssTable kaj_tss_table;
void free3(void *ptr);
typedef struct {
    u8 unk0[0x20];
    s16 unk20;
} Unk_801D14B8;
s32 kaj_event_set_alarm(s32 a, s32 b, s32 c);
void *kaj_malloc(u32 size);
void kaj_tss_free(TssSlot *arg0);
typedef struct {
    u8 unk0[0x24];
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s32 unk2C;
} Unk_801D1774;
extern ViewBuffer kaj_view_buffers[2];
void SetDispMask(s32 mask);
ViewBuffer *kaj_view_current;
s32 GsGetWorkBase(void);
void GsSetWorkBase(s32 arg0);
void ClearOTagR(u32 *ot, s32 n);
s32 ClearImage(Rect *rect, s32 r, s32 g, s32 b);
s32 DrawSync(s32 mode);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char D_801DFDFC[];
extern KajSystem kaj_system;
s32 VSync(s32 mode);
void ResetGraph(s32 mode);
void PutDispEnv(void *env);
void PutDrawEnv(void *env);
void DrawOTag(u32 *ot);
extern s32 D_801E2D60;
extern s16 D_801E2D64;
s32 kaj_view_last_vsync;
KajEvent *kaj_event_push(s32 arg0);
void kaj_event_flush(s32 a, s32 b);
void EnterCriticalSection(void);
void ExitCriticalSection(void);
extern char D_801DFE04[];
extern s32 D_801E6DB4[];
void GsInitGraph(s32 w, s32 h, s32 intl, s32 dither, s32 vrammode);
void GsDefDispBuff(s32 x0, s32 y0, s32 x1, s32 y1);
void SetDefDispEnv(void *env, s32 x, s32 y, s32 w, s32 h);
void SetDefDrawEnv(void *env, s32 x, s32 y, s32 w, s32 h);
void GsInit3D(void);
void GsInitVcount(void);
void SetGeomOffset(s32 ofx, s32 ofy);
void GsSetProjection(s32 arg0);
void SetBackColor(s32 r, s32 g, s32 b);
void SetFarColor(s32 r, s32 g, s32 b);

void kaj_tss_free(TssSlot *slot) {
    TssTable *p = &kaj_tss_table;

    if (slot->data != slot) {
        free3(slot->data);
    }
    slot->data = 0;
    slot->next = p->free_list;
    p->free_list = slot;
}

void kaj_tss_release(s32 index) {
    TssTable *p = &kaj_tss_table;
    TssSlot *prev = 0;
    TssSlot *node = &p->slots[index];
    TssSlot *cur;

    for (cur = p->done_list; cur != 0; cur = cur->next) {
        if (cur == node) {
            if (prev == 0) {
                p->done_list = cur->next;
            } else {
                prev->next = cur->next;
            }
            node->next = p->free_list;
            p->free_list = node;
            return;
        }
        prev = cur;
    }
}

s32 kaj_tss_kill(s32 index) {
    TssTable *p = &kaj_tss_table;
    TssSlot *node = &p->slots[index];
    KajEvent *e;

    if (node->next == 0 || (node->next >= p->slots && node->next < &p->slots[p->count])) {
        return 0;
    }
    kaj_event_flush(2, index + 1);
    if (node->on_kill != 0) {
        node->on_kill(node);
    }
    EnterCriticalSection();
    e = kaj_event_push(0x100);
    if (e != 0) {
        e->unk8 = index;
        e->unkC = 1;
        e->unk10 = node->type;
        {
            TssTable *q = &kaj_tss_table;

            if (node->data != node) {
                free3(node->data);
            }
            node->data = 0;
            node->next = q->done_list;
            q->done_list = node;
        }
    } else {
        TssTable *q = &kaj_tss_table;

        if (node->data != node) {
            free3(node->data);
        }
        node->data = 0;
        node->next = q->free_list;
        q->free_list = node;
    }
    ExitCriticalSection();
    return 1;
}

s32 kaj_tss_start(Unk_801D14B8 *task) {
    kaj_event_set_alarm(1, task->unk20 + 1, 0);
    return task->unk20;
}

void kaj_tss_finish(TssSlot *slot) {
    TssTable *p = &kaj_tss_table;

    if (slot->data != slot) {
        free3(slot->data);
    }
    slot->data = 0;
    slot->next = p->done_list;
    p->done_list = slot;
}

void *kaj_tss_pool_create(s32 count, s32 size) {
    u8 *base;
    u8 *p;
    u8 *next;
    s32 i;

    base = kaj_malloc(count * size);
    if (base == 0) {
        return 0;
    }
    p = base;
    next = base + size;
    for (i = 1; i < count; i++) {
        *(u8 **)p = next;
        p = next;
        next = p + size;
    }
    *(u8 **)p = 0;
    return base;
}

TssSlot *kaj_tss_alloc(u32 size) {
    TssTable *p = &kaj_tss_table;
    TssSlot *node;

    if (p->free_list == 0) {
        return 0;
    }
    node = p->free_list;
    p->free_list = node->next;
    if (size > 0x20) {
        node->data = kaj_malloc(size);
        if (node->data == 0) {
            node->data = node;
            kaj_tss_free(node);
            return 0;
        }
    } else {
        node->data = node;
    }
    node->on_kill = 0;
    return node;
}

void kaj_tss_init(void) {
    TssTable *p = &kaj_tss_table;
    TssSlot *res;
    s32 i;

    p->count = 16;
    {
        s32 n = 16;
        TssSlot *base = kaj_malloc(n * sizeof(TssSlot));
        TssSlot *cur;
        TssSlot *next;

        if (base == 0) {
            res = 0;
        } else {
            cur = base;
            next = base + 1;
            for (i = 1; i < n; i++) {
                cur->next = next;
                cur = next;
                next = cur + 1;
            }
            cur->next = 0;
            res = base;
        }
    }
    p->slots = res;
    if (res == 0) {
        kaj_abend(3, "Error Allocating Sharing Table", D_801DFDFC, 0x78);
    }
    for (i = 0; i < p->count; i++) {
        p->slots[i].index = i;
    }
    p->free_list = p->slots;
    p->done_list = 0;
}

void kaj_tss_quit(void) {
    TssTable *p = &kaj_tss_table;

    if (p->slots != 0) {
        free3(p->slots);
        p->slots = 0;
    }
    p->free_list = 0;
    p->done_list = 0;
}

void kaj_tss_set_steps(Unk_801D1774 *task, s32 steps) {
    s32 dist = task->unk26 - task->unk24;
    s32 abs_dist;
    s32 step;

    if (steps == 0 || dist == 0) {
        task->unk28 = dist;
        task->unk2C = 0;
        return;
    }
    abs_dist = dist;
    if (dist < 0) {
        abs_dist = -dist;
    }
    step = (abs_dist + (steps >> 1)) / steps;
    if (dist < 0) {
        step = -step;
    }
    task->unk28 = step;
    task->unk2C = 2;
}

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
            kaj_abend(3, "Error Allocating VIEW Tag", D_801DFE04, 0x30);
        }
        p->packets = (s32)kaj_malloc(0x2C000);
        if (p->packets == 0) {
            kaj_abend(3, "Error Allocating VIEW Packet", D_801DFE04, 0x35);
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
    D_801E6DB4[0] = 0;
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
    frame = D_801E2D60 + 1;
    D_801E2D60 = frame;
    if (frame == 0) {
        frame = 1;
    }
    D_801E2D60 = frame;
    D_801E2D64 = D_801E2D64 == 0;
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
