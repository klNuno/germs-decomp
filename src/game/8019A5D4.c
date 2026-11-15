#include "common.h"

typedef struct { u16 unk0; s16 unk2; s16 *unk4; s16 *unk8; s16 *unkC; } Unk_801E07C0;
extern Unk_801E07C0 D_801E07C0;
typedef struct { s16 unk0; s16 unk2; u8 unk4; u8 unk5; u8 unk6; u8 unk7; } Unk_801DFF68;
Unk_801DFF68 D_801DFF68;
void func_801A0978(s32 arg0, s32 arg1);
typedef struct { u16 unk0; u16 unk2; } Unk_801DFE68;
typedef struct { s32 unk0; s32 unk4; s32 unk8; u8 unkC; } Unk_801A20CC;
typedef struct { s32 unk0; s32 unk4; s16 unk8; } Unk_801E1058;
extern Unk_801DFE68 D_801DFE68;
extern Unk_801E1058 D_801E1058;
typedef struct { s16 unk0; s16 unk2; } Unk_801A216C;

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019A5D4);

void func_8019A664(void) {
    Unk_801E07C0 *p = &D_801E07C0;

    D_801E07C0.unk0 = 0;
    p->unk2 = 0;
    p->unk4[2] = 0;
    p->unk8[2] = 0;
    p->unkC[2] = 0;
    p->unk4 = NULL;
    p->unk8 = NULL;
    p->unkC = NULL;
}

u16 func_8019A6A4(void) {
    return D_801E07C0.unk0;
}

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019A6B4);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019A930);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019AD78);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019B4FC);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019BE6C);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019C78C);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019D1D0);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019DABC);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019E688);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019F124);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_8019FDD8);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A00EC);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A02C8);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A0418);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A05EC);

void func_801A0690(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Unk_801DFF68 *p = &D_801DFF68;

    if (D_801DFF68.unk0 == 0) {
        D_801DFF68.unk0 = 1;
        p->unk2 = arg3;
        p->unk4 = arg0;
        p->unk5 = arg1;
        p->unk6 = arg2;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A06C0);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A0820);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A0978);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A0B48);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A0D58);

INCLUDE_RODATA("asm/nonmatchings/game/8019A5D4", D_801715C4);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A0EDC);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A14A0);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A1AB8);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A1EC0);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A1FD4);

void func_801A20A8(void) {
    func_801A0978(0, 1);
}

s32 func_801A20CC(Unk_801A20CC *arg0) {
    Unk_801E1058 *p = &D_801E1058;

    if (arg0->unk8 == 0x30) {
        u32 c = arg0->unkC;

        if (D_801DFE68.unk0 == 3) {
            if (c < 11) {
                p->unk8 = 1;
            }
        } else if (D_801DFE68.unk0 == 6) {
            if (c < 6) {
                p->unk8 = 1;
            }
        }
    }
    return 0;
}

s32 func_801A211C(Unk_801A20CC *arg0) {
    Unk_801E1058 *p = &D_801E1058;

    if (arg0->unk8 == 0x30) {
        u32 c = arg0->unkC;

        if (D_801DFE68.unk0 == 3) {
            if (c < 11) {
                p->unk8 = 0;
            }
        } else if (D_801DFE68.unk0 == 6) {
            if (c < 6) {
                p->unk8 = 0;
            }
        }
    }
    return 0;
}

s32 func_801A216C(Unk_801A216C *arg0, Unk_801A216C *arg1) {
    return arg0->unk2 - arg1->unk2;
}
