#include "common.h"

typedef struct Unk_801CFAE8 {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
    void *unk1C;
    void *unk20;
} Unk_801CFAE8;
void free3(void *ptr);
typedef struct Unk_801CFB4C {
    u32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u32 *unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    u32 *unk18;
} Unk_801CFB4C;
void GsGetTimInfo(u32 *im, Unk_801CFB4C *tim);
s32 LoadImage(void *rect, u32 *p);
s32 StoreImage(void *rect, u32 *p);
u16 GetTPage(s32 tp, s32 abr, s32 x, s32 y);
u16 GetClut(s32 x, s32 y);
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char D_801DFDE4[];

static inline void func_801CF790_inline(Unk_801CFB4C *tim, void **buf) {
    s32 size;
    if ((tim->unk0 >> 3) & 1) {
        switch (tim->unk0 & 7) {
        case 0:
            size = 0x20;
            break;
        case 1:
            size = 0x200;
            break;
        default:
            kaj_abend(9, "No CLUT in this TIM", D_801DFDE4, 28);
            break;
        }
        *buf = kaj_malloc(size);
        if (*buf == NULL) {
            kaj_abend(3, "Error Allocating CLUT Buffer", D_801DFDE4, 33);
        }
        StoreImage(&tim->unk10, *buf);
    }
}

void kaj_tim_load(Unk_801CFAE8 **arg0, u32 *arg1, u16 arg2, s16 arg3) {
    Unk_801CFB4C tim;
    s16 x;
    s16 y;

    *arg0 = kaj_malloc(0x24);
    if (*arg0 == NULL) {
        kaj_abend(3, "Error Allocating TIM Handle", D_801DFDE4, 47);
    }
    (*arg0)->unk1C = NULL;
    (*arg0)->unk20 = NULL;
    GsGetTimInfo(arg1 + 1, &tim);
    if (arg2 != 2) {
        LoadImage(&tim.unk4, tim.unkC);
    }
    x = tim.unk4 >> 6;
    y = tim.unk6 >> 8;
    (*arg0)->unk0 = tim.unk4;
    (*arg0)->unk2 = tim.unk6;
    (*arg0)->unk6 = tim.unkA;
    (*arg0)->unk4 = tim.unk8;
    (*arg0)->unk10 = tim.unk4 - (x << 6);
    (*arg0)->unk12 = tim.unk6 - (y << 8);
    (*arg0)->unk14 = 0;
    (*arg0)->unk18 = -1;
    (*arg0)->unk1A = GetTPage(tim.unk0 & 7, 0, x << 6, y << 8);
    if ((tim.unk0 >> 3) & 1) {
        if (arg2 != 2) {
            LoadImage(&tim.unk10, tim.unk18);
        }
        (*arg0)->unk18 = GetClut(tim.unk10, tim.unk12);
        (*arg0)->unk8 = tim.unk10;
        (*arg0)->unkA = tim.unk12;
        (*arg0)->unkC = tim.unk14;
        (*arg0)->unkE = tim.unk16;
        if (arg3 != 0) {
            func_801CF790_inline(&tim, &(*arg0)->unk1C);
            func_801CF790_inline(&tim, &(*arg0)->unk20);
        }
        switch (tim.unk0 & 7) {
        case 0:
            (*arg0)->unk14 = 2;
            break;
        case 1:
            (*arg0)->unk14 = 1;
            break;
        }
    }
}

void kaj_tim_free(Unk_801CFAE8 *arg0) {
    if (arg0 != NULL) {
        if (arg0->unk1C != NULL) {
            free3(arg0->unk1C);
            arg0->unk1C = NULL;
        }
        if (arg0->unk20 != NULL) {
            free3(arg0->unk20);
            arg0->unk20 = NULL;
        }
        free3(arg0);
    }
}

void kaj_tim_upload(u32 *arg0, s16 arg1) {
    Unk_801CFB4C tim;

    GsGetTimInfo(arg0 + 1, &tim);
    LoadImage(&tim.unk4, tim.unkC);
    if (arg1 != 0 && ((tim.unk0 >> 3) & 1)) {
        LoadImage(&tim.unk10, tim.unk18);
    }
}

void kaj_tim_upload_hdr(u16 *arg0) {
    Unk_801CFB4C tim;
    s16 v = arg0[1];

    GsGetTimInfo((u32 *)(arg0 + 4), &tim);
    LoadImage(&tim.unk4, tim.unkC);
    if (v != 0 && ((tim.unk0 >> 3) & 1)) {
        LoadImage(&tim.unk10, tim.unk18);
    }
}
