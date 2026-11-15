#include "common.h"

typedef struct Unk_801CFAE8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
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

INCLUDE_ASM("asm/nonmatchings/kaj/801CF790", func_801CF790);

void func_801CFAE8(Unk_801CFAE8 *arg0) {
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

void func_801CFB4C(u32 *arg0, s16 arg1) {
    Unk_801CFB4C tim;

    GsGetTimInfo(arg0 + 1, &tim);
    LoadImage(&tim.unk4, tim.unkC);
    if (arg1 != 0 && ((tim.unk0 >> 3) & 1)) {
        LoadImage(&tim.unk10, tim.unk18);
    }
}

void func_801CFBB4(u16 *arg0) {
    Unk_801CFB4C tim;
    s16 v = arg0[1];

    GsGetTimInfo((u32 *)(arg0 + 4), &tim);
    LoadImage(&tim.unk4, tim.unkC);
    if (v != 0 && ((tim.unk0 >> 3) & 1)) {
        LoadImage(&tim.unk10, tim.unk18);
    }
}
