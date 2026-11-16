#include "common.h"
#include "game/types.h"

extern Unk_801DFBD0 kaj_tss_table;
void free3(void *ptr);
typedef struct {
    u8 unk0[0x20];
    s16 unk20;
} Unk_801D14B8;
s32 kaj_event_set_alarm(s32 a, s32 b, s32 c);
void *kaj_malloc(u32 size);
void kaj_tss_free(Unk_801D12A8 *arg0);
typedef struct {
    u8 unk0[0x24];
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s32 unk2C;
} Unk_801D1774;
extern Unk_801E6FF0 kaj_view_buffers[2];
void SetDispMask(s32 mask);
Unk_801E6FF0 *kaj_view_current;
s32 GsGetWorkBase(void);
void GsSetWorkBase(s32 arg0);
void ClearOTagR(u32 *ot, s32 n);
s32 ClearImage(Unk_801D1BD4 *rect, s32 r, s32 g, s32 b);
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
Unk_801CC1E8 *kaj_event_push(s32 arg0);
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

void kaj_tss_free(Unk_801D12A8 *arg0) {
    Unk_801DFBD0 *p = &kaj_tss_table;

    if (arg0->unk3C != arg0) {
        free3(arg0->unk3C);
    }
    arg0->unk3C = 0;
    arg0->unk0 = p->unk8;
    p->unk8 = arg0;
}

void kaj_tss_release(s32 arg0) {
    Unk_801DFBD0 *p = &kaj_tss_table;
    Unk_801D12A8 *prev = 0;
    Unk_801D12A8 *node = &p->unk4[arg0];
    Unk_801D12A8 *cur;

    for (cur = p->unkC; cur != 0; cur = cur->unk0) {
        if (cur == node) {
            if (prev == 0) {
                p->unkC = cur->unk0;
            } else {
                prev->unk0 = cur->unk0;
            }
            node->unk0 = p->unk8;
            p->unk8 = node;
            return;
        }
        prev = cur;
    }
}

s32 kaj_tss_kill(s32 arg0) {
    Unk_801DFBD0 *p = &kaj_tss_table;
    Unk_801D12A8 *node = &p->unk4[arg0];
    Unk_801CC1E8 *e;

    if (node->unk0 == 0 || (node->unk0 >= p->unk4 && node->unk0 < &p->unk4[p->unk0])) {
        return 0;
    }
    kaj_event_flush(2, arg0 + 1);
    if (node->unk38 != 0) {
        node->unk38(node);
    }
    EnterCriticalSection();
    e = kaj_event_push(0x100);
    if (e != 0) {
        e->unk8 = arg0;
        e->unkC = 1;
        e->unk10 = node->unk22;
        {
            Unk_801DFBD0 *q = &kaj_tss_table;

            if (node->unk3C != node) {
                free3(node->unk3C);
            }
            node->unk3C = 0;
            node->unk0 = q->unkC;
            q->unkC = node;
        }
    } else {
        Unk_801DFBD0 *q = &kaj_tss_table;

        if (node->unk3C != node) {
            free3(node->unk3C);
        }
        node->unk3C = 0;
        node->unk0 = q->unk8;
        q->unk8 = node;
    }
    ExitCriticalSection();
    return 1;
}

s32 kaj_tss_start(Unk_801D14B8 *arg0) {
    kaj_event_set_alarm(1, arg0->unk20 + 1, 0);
    return arg0->unk20;
}

void kaj_tss_finish(Unk_801D12A8 *arg0) {
    Unk_801DFBD0 *p = &kaj_tss_table;

    if (arg0->unk3C != arg0) {
        free3(arg0->unk3C);
    }
    arg0->unk3C = 0;
    arg0->unk0 = p->unkC;
    p->unkC = arg0;
}

void *kaj_tss_pool_create(s32 arg0, s32 arg1) {
    u8 *base;
    u8 *p;
    u8 *next;
    s32 i;

    base = kaj_malloc(arg0 * arg1);
    if (base == 0) {
        return 0;
    }
    p = base;
    next = base + arg1;
    for (i = 1; i < arg0; i++) {
        *(u8 **)p = next;
        p = next;
        next = p + arg1;
    }
    *(u8 **)p = 0;
    return base;
}

Unk_801D12A8 *kaj_tss_alloc(u32 arg0) {
    Unk_801DFBD0 *p = &kaj_tss_table;
    Unk_801D12A8 *node;

    if (p->unk8 == 0) {
        return 0;
    }
    node = p->unk8;
    p->unk8 = node->unk0;
    if (arg0 > 0x20) {
        node->unk3C = kaj_malloc(arg0);
        if (node->unk3C == 0) {
            node->unk3C = node;
            kaj_tss_free(node);
            return 0;
        }
    } else {
        node->unk3C = node;
    }
    node->unk38 = 0;
    return node;
}

void kaj_tss_init(void) {
    Unk_801DFBD0 *p = &kaj_tss_table;
    Unk_801D12A8 *res;
    s32 i;

    p->unk0 = 16;
    {
        s32 n = 16;
        Unk_801D12A8 *base = kaj_malloc(n * sizeof(Unk_801D12A8));
        Unk_801D12A8 *cur;
        Unk_801D12A8 *next;

        if (base == 0) {
            res = 0;
        } else {
            cur = base;
            next = base + 1;
            for (i = 1; i < n; i++) {
                cur->unk0 = next;
                cur = next;
                next = cur + 1;
            }
            cur->unk0 = 0;
            res = base;
        }
    }
    p->unk4 = res;
    if (res == 0) {
        kaj_abend(3, "Error Allocating Sharing Table", D_801DFDFC, 0x78);
    }
    for (i = 0; i < p->unk0; i++) {
        p->unk4[i].unk20 = i;
    }
    p->unk8 = p->unk4;
    p->unkC = 0;
}

void kaj_tss_quit(void) {
    Unk_801DFBD0 *p = &kaj_tss_table;

    if (p->unk4 != 0) {
        free3(p->unk4);
        p->unk4 = 0;
    }
    p->unk8 = 0;
    p->unkC = 0;
}

void kaj_tss_set_steps(Unk_801D1774 *arg0, s32 arg1) {
    s32 d = arg0->unk26 - arg0->unk24;
    s32 t;
    s32 q;

    if (arg1 == 0 || d == 0) {
        arg0->unk28 = d;
        arg0->unk2C = 0;
        return;
    }
    t = d;
    if (d < 0) {
        t = -d;
    }
    q = (t + (arg1 >> 1)) / arg1;
    if (d < 0) {
        q = -q;
    }
    arg0->unk28 = q;
    arg0->unk2C = 2;
}

void kaj_view_init(void) {
    Unk_801E6FF0 *p;
    s32 i;

    VSync(0);
    GsInitGraph(0x140, 0xF0, 4, 1, 0);
    VSync(0);
    GsDefDispBuff(0, 0, 0, 0xF0);
    SetDefDispEnv(kaj_view_buffers[0].unk5C, 0, 0xF0, 0x140, 0xF0);
    SetDefDispEnv(kaj_view_buffers[1].unk5C, 0, 0, 0x140, 0xF0);
    SetDefDrawEnv(&kaj_view_buffers[0], 0, 0, 0x140, 0xF0);
    SetDefDrawEnv(&kaj_view_buffers[1], 0, 0xF0, 0x140, 0xF0);
    for (i = 0; i < 2; i++) {
        p = &kaj_view_buffers[i];
        p->unk18 = 1;
        p->unk17 = 0;
        p->unk19 = 0;
        p->unk1A = 0;
        p->unk1B = 0;
        p->unk84 = kaj_malloc(0x8000);
        if (p->unk84 == 0) {
            kaj_abend(3, "Error Allocating VIEW Tag", D_801DFE04, 0x30);
        }
        p->unk88 = (s32)kaj_malloc(0x2C000);
        if (p->unk88 == 0) {
            kaj_abend(3, "Error Allocating VIEW Packet", D_801DFE04, 0x35);
        }
        p->unk70 = 13;
        p->unk74 = p->unk84;
        p->unk7C = 0;
        p->unk78 = 0;
        p->unk80 = p->unk84 + 0x1FFF;
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
    free3(kaj_view_buffers[0].unk84);
    free3(kaj_view_buffers[1].unk84);
    free3((void *)kaj_view_buffers[0].unk88);
    free3((void *)kaj_view_buffers[1].unk88);
    SetDispMask(0);
}

s32 kaj_view_packet_used(void) {
    return GsGetWorkBase() - kaj_view_current->unk88;
}

Unk_801E6FF0 *kaj_view_begin_frame(void) {
    Unk_801E6FF0 *p = kaj_view_buffers;

    if (kaj_view_current == p) {
        p = &kaj_view_buffers[1];
    }
    kaj_view_current = p;
    GsSetWorkBase(p->unk88);
    ClearOTagR(kaj_view_current->unk84, 0x2000);
    return kaj_view_current;
}

void kaj_view_flip(Unk_801E6FF0 *arg0) {
    s32 t;
    s32 d;
    s32 v;

    if (arg0->unk17 == 0) {
        DrawSync(0);
        VSync(2);
        t = VSync(-1);
    } else {
        VSync(2);
        t = VSync(-1);
        ResetGraph(1);
    }
    PutDispEnv(arg0->unk5C);
    PutDrawEnv(arg0);
    v = D_801E2D60 + 1;
    D_801E2D60 = v;
    if (v == 0) {
        v = 1;
    }
    D_801E2D60 = v;
    D_801E2D64 = D_801E2D64 == 0;
    DrawOTag(arg0->unk84 + 0x1FFF);
    {
        KajSystem *p = &kaj_system;
        s32 last = kaj_view_last_vsync;

        kaj_view_last_vsync = t;
        d = t - last;
        p->vsync_delta = d;
        if (d < 0) {
            p->vsync_delta = d + 0x7FFFFFFF;
        }
    }
}

void kaj_view_set_bg_color(u8 arg0, u8 arg1, u8 arg2) {
    Unk_801E6FF0 *p = kaj_view_buffers;

    p->unk19 = arg0;
    p->unk1A = arg1;
    p->unk1B = arg2;
    p++;
    p->unk19 = arg0;
    p->unk1A = arg1;
    p->unk1B = arg2;
}

void kaj_view_clear_vram(void) {
    Unk_801D1BD4 rect;

    rect.unk0 = 0;
    rect.unk2 = 0;
    rect.unk4 = 0x140;
    rect.unk6 = 0x1E0;
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
}
