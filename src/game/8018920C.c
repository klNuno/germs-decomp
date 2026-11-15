#include "common.h"

s32 DisableEvent(s32 event);
s32 CloseEvent(s32 event);
s32 D_801DFEC8;
s32 D_801DFECC;
s32 D_801DFED0;
extern s32 D_801DFF50;
void func_8018AA00(s16 a);
void (*D_801DFEDC)(void);
typedef struct { s32 unk0; s16 unk4; s16 unk6; } Unk_801E024C;
extern Unk_801E024C D_801E024C[];
void (*D_801DFED8)(s32 *a, Unk_801E024C *b);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8[1]; } Unk_8018A8CC_58;
typedef struct { u8 unk0[0x58]; Unk_8018A8CC_58 *unk58; } Unk_8018A8CC;
void func_801A4944(s32 a, s32 b, s32 c);
void func_801A461C(s32 a, s32 b, s32 c);
s16 D_801DFD1C;
s16 D_801DFD1E;
s16 D_801DFD20;
s16 D_801DFD22;
s16 D_801DFD24;
s16 D_801DFD26;
void func_801A4824(s32 a, s32 b, s32 c, s32 d);
typedef struct { s32 unk0; s16 unk4; s16 unk6; } Unk_801E056C;
typedef struct { u16 unk0[0x70]; u8 unkE0[0x124]; Unk_801E056C unk204[4]; } Unk_801E0368;
extern Unk_801E0368 D_801E0368;
typedef struct { s16 unk0[3]; s16 unk6; s16 unk8[3]; s16 unkE; } Unk_801E1040;
extern Unk_801E1040 D_801E1040;
void func_80189C3C(s32 a, s16 b);
void func_8018A3F8(s32 a);
void SetFarColor(s32 r, s32 g, s32 b);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018920C);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189350);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_801895E0);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018970C);

void func_801898C0(void) {
    D_801DFF50 = 0;
    DisableEvent(D_801DFEC8);
    DisableEvent(D_801DFECC);
    DisableEvent(D_801DFED0);
    CloseEvent(D_801DFEC8);
    CloseEvent(D_801DFECC);
    CloseEvent(D_801DFED0);
}

void func_80189928(s32 *a) {
    Unk_801E024C *p = &D_801E024C[a[2]];
    p->unk0 = -1;
    p->unk4 = 0;
    if (D_801DFED8 != NULL) {
        D_801DFED8(a, p);
    }
}

void func_80189970(s16 a) {
    func_8018AA00(a);
    if (D_801DFEDC != NULL) {
        D_801DFEDC();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_801899AC);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189AC0);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189C3C);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189DE8);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189F50);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A24C);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A3F8);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A5F0);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A7C0);

void func_8018A8CC(Unk_8018A8CC *a) {
    s32 i;
    s32 n;
    Unk_8018A8CC_58 *p = a->unk58;
    n = p->unk8[p->unk2] * 16 / 100;
    func_801A4944(0x400, 0x50, 0x5F);
    for (i = 0x50; i < n + 0x50; i++) {
        func_801A461C(0x400, i, 0x7E8A);
    }
}

void func_8018A968(s16 a, s16 b) {
    switch (a) {
    case 0:
        D_801DFD1C = b;
        D_801DFD22 = 0;
        break;
    case 1:
        D_801DFD1E = b;
        D_801DFD24 = 0;
        break;
    case 2:
        D_801DFD20 = b;
        D_801DFD26 = 0;
        break;
    }
    if (b == 0) {
        func_801A4824(0x400, 1, 3, 0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018AA00);

void func_8018AABC(s16 a) {
    Unk_801E0368 *p = &D_801E0368;
    func_80189C3C(0, p->unk0[0x3D] + 1);
    func_80189C3C(1, p->unk0[0x3E]);
    func_80189C3C(2, p->unk0[0x3F]);
    D_801E1040.unk0[0] = a;
    SetFarColor(0, 0, 0);
    if (a != 0) {
        func_8018A3F8(1);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018AB48);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018ABE8);
