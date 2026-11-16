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
extern char kaj_tim_str_file[];

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
            kaj_abend(9, "No CLUT in this TIM", kaj_tim_str_file, 28);
            break;
        }
        *buf = kaj_malloc(size);
        if (*buf == NULL) {
            kaj_abend(3, "Error Allocating CLUT Buffer", kaj_tim_str_file, 33);
        }
        StoreImage(&tim->unk10, *buf);
    }
}

void kaj_tim_load(Unk_801CFAE8 **handle, u32 *tim_file, u16 mode, s16 keep_clut) {
    Unk_801CFB4C tim;
    s16 x;
    s16 y;

    *handle = kaj_malloc(0x24);
    if (*handle == NULL) {
        kaj_abend(3, "Error Allocating TIM Handle", kaj_tim_str_file, 47);
    }
    (*handle)->unk1C = NULL;
    (*handle)->unk20 = NULL;
    GsGetTimInfo(tim_file + 1, &tim);
    if (mode != 2) {
        LoadImage(&tim.unk4, tim.unkC);
    }
    x = tim.unk4 >> 6;
    y = tim.unk6 >> 8;
    (*handle)->unk0 = tim.unk4;
    (*handle)->unk2 = tim.unk6;
    (*handle)->unk6 = tim.unkA;
    (*handle)->unk4 = tim.unk8;
    (*handle)->unk10 = tim.unk4 - (x << 6);
    (*handle)->unk12 = tim.unk6 - (y << 8);
    (*handle)->unk14 = 0;
    (*handle)->unk18 = -1;
    (*handle)->unk1A = GetTPage(tim.unk0 & 7, 0, x << 6, y << 8);
    if ((tim.unk0 >> 3) & 1) {
        if (mode != 2) {
            LoadImage(&tim.unk10, tim.unk18);
        }
        (*handle)->unk18 = GetClut(tim.unk10, tim.unk12);
        (*handle)->unk8 = tim.unk10;
        (*handle)->unkA = tim.unk12;
        (*handle)->unkC = tim.unk14;
        (*handle)->unkE = tim.unk16;
        if (keep_clut != 0) {
            func_801CF790_inline(&tim, &(*handle)->unk1C);
            func_801CF790_inline(&tim, &(*handle)->unk20);
        }
        switch (tim.unk0 & 7) {
        case 0:
            (*handle)->unk14 = 2;
            break;
        case 1:
            (*handle)->unk14 = 1;
            break;
        }
    }
}

void kaj_tim_free(Unk_801CFAE8 *handle) {
    if (handle != NULL) {
        if (handle->unk1C != NULL) {
            free3(handle->unk1C);
            handle->unk1C = NULL;
        }
        if (handle->unk20 != NULL) {
            free3(handle->unk20);
            handle->unk20 = NULL;
        }
        free3(handle);
    }
}

void kaj_tim_upload(u32 *tim_file, s16 with_clut) {
    Unk_801CFB4C tim;

    GsGetTimInfo(tim_file + 1, &tim);
    LoadImage(&tim.unk4, tim.unkC);
    if (with_clut != 0 && ((tim.unk0 >> 3) & 1)) {
        LoadImage(&tim.unk10, tim.unk18);
    }
}

void kaj_tim_upload_hdr(u16 *hdr) {
    Unk_801CFB4C tim;
    s16 with_clut = hdr[1];

    GsGetTimInfo((u32 *)(hdr + 4), &tim);
    LoadImage(&tim.unk4, tim.unkC);
    if (with_clut != 0 && ((tim.unk0 >> 3) & 1)) {
        LoadImage(&tim.unk10, tim.unk18);
    }
}
