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
    s16 unkC;
} Unk_801DFBB8;
extern Unk_801DFBB8 D_801DFBB8;
void free3(void *ptr);
s32 StopRCnt(s32 spec);
s32 DisableEvent(s32 event);
s32 CloseEvent(s32 event);
s32 D_801DFDEC;
extern s16 D_801E6DA8[];
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
extern char D_801DFDF4[];
void *calloc3(s32 n, s32 size);
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
s32 func_801CFD70(void);
s32 OpenEvent(u32 desc, s32 spec, s32 mode, s32 (*func)(void));
s32 EnableEvent(s32 event);
s32 SetRCnt(u32 spec, u16 target, s32 mode);
s32 StartRCnt(u32 spec);

INCLUDE_ASM("asm/nonmatchings/kaj/801CFD70", func_801CFD70);

INCLUDE_ASM("asm/nonmatchings/kaj/801CFD70", func_801CFEB0);

INCLUDE_ASM("asm/nonmatchings/kaj/801CFD70", func_801D0134);

void func_801D0300(void) {
    D_801DFBB8.unk4 = 8;
    D_801DFBB8.unk0 = calloc3(9, 0x10);
    if (D_801DFBB8.unk0 == NULL) {
        func_801CD54C(3, "Error Allocating TIMER Queue", D_801DFDF4, 0xB4);
    }
    D_801DFBB8.unk8 = 0;
    D_801DFBB8.unkC = 0;
    D_801E6DA0.unkC = 0;
    D_801E6DA0.unk8 = 0;
    D_801E6DA0.unk10 = 0x258;
    D_801DFDEC = OpenEvent(0xF2000003, 2, 0x1000, func_801CFD70);
    if (D_801DFDEC == -1) {
        func_801CD54C(2, "Can not Create TIMER Event", D_801DFDF4, 0xBF);
    }
    if (EnableEvent(D_801DFDEC) == 0) {
        func_801CD54C(2, "Can not Enable TIMER Event", D_801DFDF4, 0xC2);
    }
    SetRCnt(0xF2000003, 1, 0x1000);
    StartRCnt(0xF2000003);
}

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
