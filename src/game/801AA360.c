#include "common.h"

typedef struct { u8 pad0[0x46]; u16 unk46; } Unk_801E076C;
extern Unk_801E076C *D_801E076C[];
void func_80192B8C(s32 arg0, s32 arg1);
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; } Unk_801E032C;
extern Unk_801E032C *D_801E032C[];
void func_801A923C(Unk_801E032C *arg0, Unk_801E076C *arg1);
void func_801A9BF4(Unk_801E032C *arg0, Unk_801E076C *arg1);
typedef struct { u16 unk0; u8 pad2[0xB6]; void *unkB8; void *unkBC; void *unkC0; } Unk_801AC278;
typedef struct { u8 pad0[0x54]; Unk_801AC278 *unk54; } Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
void func_801A968C(Unk_801AC278 *arg0);
void free3(void *ptr);
void func_801A2288(void);
void func_801AA360(Unk_801E076C *arg0);
void func_801A9EA4(Unk_801E076C *arg0);
typedef struct { s32 unk0; s16 unk4; } Unk_801AC55C;
typedef struct { u8 pad0[0x54]; Unk_801AC55C *unk54; } Unk_801E0710;
extern Unk_801E0710 D_801E0710;
extern s16 D_801D7FB0[];
void func_801A2678(s32 arg0);
s32 func_8018D1A0(void);
typedef struct { s32 unk0; s16 unk4; s16 unk6; } Unk_801A7C3C;
typedef struct { s32 unk0; s32 unk4; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; } Unk_801E1118;
extern Unk_801E1118 D_801E1118;
Unk_801A7C3C *func_801A7C3C(s32 arg0, s32 arg1);
extern char D_80171A9C[];
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
void func_801AB4D4(Unk_801A7C3C *arg0, s32 arg1);
typedef struct { s16 unk0; s16 unk2; u8 unk4[0x8]; Unk_801AC55C *unkC; Unk_801AC55C *unk10; } Unk_801D7FB0;
s32 func_8018D078(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i);
extern char D_80171A78[];
extern char D_80171AA8[];
void *func_801CC898(u32 size);

INCLUDE_RODATA("asm/nonmatchings/game/801AA360", D_80171A78);

INCLUDE_RODATA("asm/nonmatchings/game/801AA360", D_80171A9C);

INCLUDE_RODATA("asm/nonmatchings/game/801AA360", D_80171AA8);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AA360);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AA8DC);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AAA9C);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AACF4);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AB040);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AB1A0);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AB310);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AB4D4);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AB774);

void func_801AB9E0(void) {
    Unk_801D7FB0 *p = (Unk_801D7FB0 *)D_801D7FB0;

    func_801A2678(0x13);
    if (p->unk10 != NULL) {
        p->unk10->unk4 = 0;
        p->unk10 = NULL;
    }
    if (p->unkC != NULL) {
        p->unkC->unk4 = 0;
        p->unkC = NULL;
    }
    func_8018D078(p->unk2, 0x40B, 0x40C, 0xF, 6, NULL, 4, 0x2969, 0x2BFF);
    if (p->unk2 != 0) {
        p->unk2 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801ABA88);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801ABC70);

void func_801AC0E4(void) {
    switch (D_801E076C[0]->unk46) {
    case 1:
        func_80192B8C(3, -1);
        break;
    case 2:
        func_80192B8C(0xB, 2);
        break;
    case 3:
        func_80192B8C(0xA, 2);
        break;
    }
}

void func_801AC158(Unk_801AC278 **arg0, u32 arg1) {
    *arg0 = func_801CC898(0xC4);
    if (*arg0 == NULL) {
        func_801CD54C(3, D_80171A78, D_80171A9C, 0x64);
    }
    (*arg0)->unkB8 = NULL;
    (*arg0)->unkBC = NULL;
    (*arg0)->unkC0 = NULL;
    (*arg0)->unkC0 = func_801CC898(arg1);
    if ((*arg0)->unkC0 == NULL) {
        func_801CD54C(3, D_80171AA8, D_80171A9C, 0x6C);
    }
}

void func_801AC214(Unk_801E032C *arg0) {
    switch (D_801E076C[0]->unk46) {
    case 1:
        func_801A923C(arg0, D_801E076C[0]);
        break;
    case 2:
    case 3:
        func_801A9BF4(arg0, D_801E076C[0]);
        break;
    }
    D_801E032C[0] = arg0;
}

void func_801AC278(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801AC278 *e = p->unk54;
    if (e != NULL) {
        if (e->unk0 == 1) {
            func_801A968C(e);
        }
        free3(e->unkB8);
        if (e->unkBC != NULL) {
            free3(e->unkBC);
        }
        free3(e->unkC0);
        free3(e);
        p->unk54 = NULL;
        func_801A2288();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AC30C);

void func_801AC464(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801E032C *p = D_801E032C[0];
    if (p != NULL) {
        p->unk18 = 0;
        p->unk30 = p->unk4 - arg0;
        p->unk34 = p->unk8 - arg1;
        p->unk38 = p->unkC - arg2;
    }
}

void func_801AC4A8(void) {
    s32 v = D_801E076C[0]->unk46;
    if (v == 1) {
        func_801AA360(D_801E076C[0]);
    } else if (v >= 2) {
        if (v < 4) {
            func_801A9EA4(D_801E076C[0]);
        }
    }
}

void func_801AC500(void) {
    Unk_801A7C3C *p = func_801A7C3C(0, 0);
    if (p == NULL) {
        func_801CD54C(5, "My Car Object not Found", D_80171A9C, 0x421);
    }
    func_801AB4D4(p, 1);
}

void func_801AC55C(void) {
    Unk_801E0710 *p = &D_801E0710;
    p->unk54->unk4 = 0;
    p->unk54 = NULL;
}

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AC578);

void func_801AC6C8(s16 arg0) {
    D_801D7FB0[0] = arg0;
    if (arg0 != 0) {
        func_801A2678(0x11);
    } else {
        func_801A2678(8);
    }
    func_8018D1A0();
}

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AC70C);

void func_801AC844(void) {
    Unk_801E1118 *q = &D_801E1118;
    Unk_801A7C3C *p = func_801A7C3C(2, 0);
    if (p != NULL) {
        p->unk6 = 0;
        p->unk4 = 0;
    }
    q->unk16 = -1;
}

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AC88C);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AC91C);

void func_801AC9B4(void) {
    Unk_801E1118 *p = &D_801E1118;
    p->unk18 = 2;
    p->unk1A = 7;
}
