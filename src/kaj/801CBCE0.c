#include "common.h"

s32 func_801CC02C(s32 *arg0);
void func_801CBDF0(s32 *arg0);
typedef struct Unk_801DFAD4 {
    void *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_801DFAD4;
void *calloc3(s32 n, s32 size);
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern Unk_801DFAD4 D_801DFAD4;
extern char D_801DFDB4[];
s32 D_801DFFC0;
s32 D_801DFFC4;
void free3(void *ptr);
void func_801D1300(s32 arg0);

INCLUDE_ASM("asm/nonmatchings/kaj/801CBCE0", func_801CBCE0);

INCLUDE_ASM("asm/nonmatchings/kaj/801CBCE0", func_801CBDF0);

INCLUDE_ASM("asm/nonmatchings/kaj/801CBCE0", func_801CC02C);

INCLUDE_ASM("asm/nonmatchings/kaj/801CBCE0", func_801CC1E8);

INCLUDE_ASM("asm/nonmatchings/kaj/801CBCE0", func_801CC2AC);

s32 func_801CC378(s32 *arg0) {
    if (func_801CC02C(arg0) == 0) {
        return 0;
    }
    if (*arg0 == 2) {
        func_801CBDF0(arg0);
        if (*arg0 == 0) {
            return func_801CC378(arg0);
        }
    }
    return *arg0;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801CBCE0", func_801CC3DC);

INCLUDE_ASM("asm/nonmatchings/kaj/801CBCE0", func_801CC514);

void func_801CC68C(void) {
    D_801DFAD4.unk10 = 0x40;
    D_801DFAD4.unk0 = calloc3(0x40, 0x14);
    if (D_801DFAD4.unk0 == NULL) {
        func_801CD54C(3, "Error Allocating EVENT Queue", D_801DFDB4, 0xED);
    }
    D_801DFAD4.unk4 = 0;
    D_801DFAD4.unk8 = 0;
    D_801DFAD4.unkC = 0;
    D_801DFFC0 = 0x3E9;
    D_801DFFC4 = 0;
}

void func_801CC708(void) {
    if (D_801DFAD4.unk0 != NULL) {
        free3(D_801DFAD4.unk0);
    }
}

void func_801CC734(s32 *arg0) {
    if (arg0[0] == 0x100) {
        func_801D1300(arg0[2]);
    }
}
