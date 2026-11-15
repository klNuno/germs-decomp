#include "common.h"

typedef struct {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
} Unk_801D05F8;
typedef struct {
    Unk_801D05F8 *unk0;
    s32 unk4;
    s32 unk8;
} Unk_801DFBB8;
extern Unk_801DFBB8 D_801DFBB8;
void free3(void *ptr);
s32 StopRCnt(s32 spec);
s32 DisableEvent(s32 event);
s32 CloseEvent(s32 event);
s32 D_801DFDEC;
extern s16 D_801E6DA8[];

INCLUDE_ASM("asm/nonmatchings/kaj/801CFD70", func_801CFD70);

INCLUDE_ASM("asm/nonmatchings/kaj/801CFD70", func_801CFEB0);

INCLUDE_ASM("asm/nonmatchings/kaj/801CFD70", func_801D0134);

INCLUDE_ASM("asm/nonmatchings/kaj/801CFD70", func_801D0300);

INCLUDE_ASM("asm/nonmatchings/kaj/801CFD70", func_801D0414);

void func_801D05F8(void) {
    Unk_801DFBB8 *p = &D_801DFBB8;
    s32 i;

    for (i = 1; i <= p->unk8; i++) {
        if (p->unk0[i].unkC != 0) {
            p->unk0[i].unkC = 0;
        }
    }
}

void func_801D064C(void) {
    if (D_801DFBB8.unk0 != NULL) {
        free3(D_801DFBB8.unk0);
        D_801DFBB8.unk0 = NULL;
    }
    StopRCnt(0xF2000003);
    if (D_801DFDEC != -1) {
        DisableEvent(D_801DFDEC);
        CloseEvent(D_801DFDEC);
    }
}

void func_801D06B4(void) {
    D_801E6DA8[0] = 1;
}

void func_801D06C4(void) {
    D_801E6DA8[0] = 0;
}
