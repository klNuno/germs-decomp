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
typedef struct { u16 unk0[0x70]; u8 unkE0[0x11E]; s16 unk1FE; Unk_801E056C unk204[4]; } Unk_801E0368;
extern Unk_801E0368 D_801E0368;
typedef struct { s16 unk0[3]; s16 unk6; s16 unk8[3]; s16 unkE; } Unk_801E1040;
extern Unk_801E1040 D_801E1040;
void func_80189C3C(s32 a, s16 b);
void func_8018A3F8(s32 a);
void SetFarColor(s32 r, s32 g, s32 b);
typedef struct { u16 unk0; u8 unk2[0x5E]; } Unk_80188FEC;
typedef struct { s16 unk0; s16 unk2; s16 unk4[2]; u8 unk8[4]; s16 unkC[0x12]; s16 unk30; s16 unk32[8]; s16 unk42; s16 unk44; s16 unk46; u16 unk48; u8 unk4A[2]; s32 unk4C; } Unk_801E0768;
typedef struct { u8 unk0[0x42]; u16 unk42; u8 unk44[0x5C]; u8 unkA0[4]; } Unk_801E0710_5C;
typedef struct { s16 unk0; u8 unk2[0x36]; s16 unk38; u8 unk3A[0xA]; s16 unk44; u8 unk46[4]; s16 unk4A; s32 unk4C; u8 unk50[8]; Unk_801E0768 *unk58; Unk_801E0710_5C *unk5C; } Unk_801E0710;
extern Unk_801E0710 D_801E0710;
void (*D_801DFEE8)(s32 *a);
Unk_80188FEC *func_80188FEC(s16 arg0);
void func_80199A94(s16 a, s32 b);
void func_8018DA2C(s32 a, s32 b, s32 c);
void func_801A25B4(s32 a);
void func_801A2678(s32 arg0);
void func_8018A5F0(Unk_801E0710 *a, Unk_801E0368 *b, s32 c, s32 d);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_8018AB48_10;
typedef struct { s16 unk0; s16 unk2; } Unk_8018AB48_1C;
typedef struct { u8 unk0[0x1C]; Unk_8018AB48_1C *unk1C; } Unk_8018AB48_r;
typedef struct { u8 unk0[0x6E]; s16 unk6E; } Unk_8018AB48;
u16 *func_801A44B8(u16 arg0);
s32 MoveImage(void *rect, s32 x, s32 y);

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

void func_801899AC(s32 *a) {
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0710_5C *q = g->unk5C;
    Unk_801E0768 *p = g->unk58;
    Unk_80188FEC *e;

    if (a[3] == 1) {
        switch (p->unk48) {
        case 0:
            p->unk48 = 2;
            break;
        case 1:
            q->unk42 &= 0x7FFF;
            p->unk48 = 0;
            p->unk44 = 0;
            break;
        case 4:
            p->unk48 = 5;
            break;
        case 6:
            p->unk48 = 7;
            e = func_80188FEC(p->unk4[p->unk2]);
            if (e != NULL) {
                func_80199A94(e->unk0, 0);
            }
            func_8018DA2C(p->unk4C, 3, 0);
            break;
        case 7:
            p->unk48 = 3;
            break;
        }
    } else if (D_801DFEE8 != NULL) {
        D_801DFEE8(a);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189AC0);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189C3C);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189DE8);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189F50);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A24C);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A3F8);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A5F0);

void func_8018A7C0(Unk_801E0710 *a) {
    s32 n;
    s32 t;
    s32 i;
    if (a->unk0 <= 0) {
        a->unk0 = 0;
        n = 0;
        func_801A25B4(4);
    } else {
        n = a->unk0 * 36 / 255 + 0x10;
        t = (a->unk0 << 12) / 255;
        if (a->unk38 != 0) {
            if (t >= 0x400) {
                a->unk38 = 0;
                func_801A25B4(4);
            }
        } else if (t < 0x400) {
            a->unk38 = 1;
            func_801A2678(4);
        }
    }
    func_801A4944(0x400, 0x10, 0x33);
    for (i = 0x10; i < 0x34; i++) {
        if (n < i) {
            func_801A461C(0x400, i, 0x1421);
        }
    }
}

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

void func_8018AA00(s16 a) {
    Unk_801E0710 *q = &D_801E0710;
    Unk_801E0368 *p = &D_801E0368;
    func_8018A5F0(q, p, 0, 0);
    if ((s16)((s16)p->unk0[0x3F] % 10) == p->unk1FE) {
        q->unk44 = 1;
    }
    if (a != 0) {
        func_8018A3F8(0);
    }
}

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

void func_8018AB48(Unk_8018AB48 *a) {
    Unk_8018AB48_10 rect;
    Unk_8018AB48_r *p = (Unk_8018AB48_r *)func_801A44B8(0x40E);
    if (p != NULL) {
        rect.unk0 = ((a->unk6E * 0xC0000 / 360) >> 14) + 0x140;
        rect.unk2 = 0x160;
        rect.unk4 = 0xC;
        rect.unk6 = 0x10;
        MoveImage(&rect, p->unk1C->unk0, p->unk1C->unk2);
    }
}

void func_8018ABE8(s16 a, s16 b) {
    s16 i;
    Unk_801E0710 *q = &D_801E0710;
    Unk_801E0368 *p = &D_801E0368;
    for (i = 0; i < a; i++) {
        func_8018A5F0(q, p, 1, b);
    }
    func_80189C3C(0, p->unk0[0x3D] + 1);
    func_80189C3C(1, p->unk0[0x3E]);
    func_80189C3C(2, p->unk0[0x3F]);
}
