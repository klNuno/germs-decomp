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
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; u16 unkA; s16 unkC; s16 unkE; u16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 *unk1C; } Unk_801E058C;
typedef struct {
    u16 unk0[0x5A];
    s16 unkB4[5];
    u8 unkBE[0x22];
    u8 unkE0[0x11C];
    s16 unk1FC;
    s16 unk1FE;
    u8 unk200[4];
    Unk_801E056C unk204[4];
    Unk_801E058C unk224;
    s32 unk244;
    u8 unk248[4];
    s16 unk24C;
} Unk_801E0368;
extern Unk_801E0368 D_801E0368;
typedef struct { s16 unk0[3]; s16 unk6; s16 unk8[3]; s16 unkE; } Unk_801E1040;
extern Unk_801E1040 D_801E1040;
void func_80189C3C(s32 a, s16 b);
void func_8018A3F8(s32 a);
void SetFarColor(s32 r, s32 g, s32 b);
typedef struct { u16 unk0; u8 unk2[0x22]; u16 unk24; u8 unk26[0x3A]; } Unk_80188FEC;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4[2];
    s16 unk8[2];
    s16 unkC[0x12];
    s16 unk30;
    s16 unk32[8];
    s16 unk42;
    s16 unk44;
    s16 unk46;
    u16 unk48;
    u8 unk4A[2];
    s32 unk4C;
} Unk_801E0768;
typedef struct { u8 unk0[0x42]; u16 unk42; u8 unk44[0x5C]; u8 unkA0[4]; } Unk_801E0710_5C;
typedef struct {
    s16 unk0;
    u8 unk2[0x2A];
    s16 unk2C;
    u8 unk2E[6];
    s16 unk34;
    s16 unk36;
    s16 unk38;
    s16 unk3A[5];
    s16 unk44;
    u8 unk46[4];
    s16 unk4A;
    s32 unk4C;
    u8 unk50[8];
    Unk_801E0768 *unk58;
    Unk_801E0710_5C *unk5C;
} Unk_801E0710;
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
s32 OpenEvent(u32 desc, s32 spec, s32 mode, s32 (*func)(void));
s32 EnableEvent(s32 event);
extern char D_801DFD14[];
void func_801CD54C(s32 a, char *b, char *c, s32 d);
s32 func_80194FAC(void);
s32 func_80199FD8(void);
s32 func_8018E7EC(void);
typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 unk10[2];
    u16 unk12;
} Unk_801DFFE8;
extern Unk_801DFFE8 D_801DFFE8;
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; void *unk10; } Unk_801895E0;
s16 (*D_801DFEE0)(Unk_801895E0 *a);
void func_80174840(s16 arg0);
void func_80184094(void);
s16 func_801752F4(u16 arg0, s16 arg1);
s16 func_801A7ED4(s32 a, s32 b, s32 c);
s16 func_80174E60(void *arg0);
extern Unk_801E0710_5C *D_801E076C[];
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; } Unk_8018970C;
s16 (*D_801DFED4)(Unk_8018970C *a);
void func_801D1300(s32 arg0);
void func_801CD688(s32 a);
void func_801D1BD4(void);
void func_8018CD4C(Unk_801E058C *p);
void func_80188760(void);
void func_801A3C58(void);
void func_8018A7C0(Unk_801E0710 *a);
extern u8 D_801D7724[];
typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 unk3; } Unk_801D7730;
extern Unk_801D7730 D_801D7730[];
void func_8018BB00(s16 a, s16 b);
void func_80189DE8(Unk_801E0710 *arg0);

void func_8018920C(void) {
    D_801DFEC8 = OpenEvent(0xF3000000, 2, 0x1000, func_80194FAC);
    D_801DFECC = OpenEvent(0xF3000001, 2, 0x1000, func_80199FD8);
    D_801DFED0 = OpenEvent(0xF3000002, 2, 0x1000, func_8018E7EC);
    if (D_801DFEC8 == -1 || D_801DFECC == -1 || D_801DFED0 == -1) {
        func_801CD54C(0xC, "Can not Create User Defined Event", D_801DFD14, 0x34);
    }
    if (EnableEvent(D_801DFEC8) == 0) {
        func_801CD54C(0xC, "Can not Enable to ENTER Event", D_801DFD14, 0x37);
    }
    if (EnableEvent(D_801DFECC) == 0) {
        func_801CD54C(0xC, "Can not Enable to LEAVE Event", D_801DFD14, 0x3A);
    }
    if (EnableEvent(D_801DFED0) == 0) {
        func_801CD54C(0xC, "Can not Enable to MOD Finish Event", D_801DFD14, 0x3D);
    }
    D_801DFF50 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189350);

void func_801895E0(Unk_801895E0 *a) {
    Unk_801DFFE8 *p = &D_801DFFE8;

    p->unk0 = a->unkC;
    p->unk4 = a->unk8;
    if (p->unk4 != 0x40) {
        func_80174840(0);
        func_80184094();
    }
    if (D_801DFEE0 != NULL && D_801DFEE0(a) != 0) {
        return;
    }
    switch (a->unk8) {
    case 0xFC:
        if (func_801752F4(a->unkC, 0) == 0) {
            func_80174840(0);
        } else {
            p->unk6 = 1;
        }
        break;
    case 0xFD:
        if (func_801A7ED4(((u8 *)&a->unkC)[1] >> 4, (u16)a->unkC & 0xFFF, 0) == 0) {
            func_80174840(0);
        } else {
            p->unk6 = 1;
        }
        break;
    default:
        if (func_80174E60(a->unk10) == 0) {
            func_80174840(0);
            break;
        }
    case 0xF7:
        p->unk6 = 1;
        break;
    }
}

s16 func_8018970C(Unk_8018970C *a) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801E0710_5C *q = D_801E076C[0];
    Unk_801E058C *p = &g->unk224;
    s16 r = 0;

    func_801D1300(a->unk8);
    switch (a->unk10) {
    case 0:
        if (a->unkC == 0) {
            g->unk244 = -1;
        }
        func_801CD688(1);
        break;
    case 1:
        if (a->unkC == 0) {
            g->unk244 = -1;
        }
        r = 1;
        func_801D1BD4();
        break;
    case 11:
        if (a->unkC == 0) {
            g->unk244 = -1;
        }
        p->unk0 = 1;
        break;
    case 12:
        if (a->unkC == 0) {
            g->unk244 = -1;
        }
        p->unk0 = 0;
        g->unk24C = 0;
        if (p->unkC == -2) {
            func_8018CD4C(p);
        }
        if (q->unk42 & 0x4000) {
            a->unk8 = 999999;
            q->unk42 &= 0xBFFF;
            func_80188760();
        }
        break;
    case 13:
        if (a->unkC == 0) {
            g->unk244 = -1;
        }
        func_801A3C58();
        break;
    }
    if (r == 0 && D_801DFED4 != NULL) {
        r = D_801DFED4(a);
    }
    return r;
}

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

void func_80189AC0(Unk_801E0710 *a) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801E0768 *p = a->unk58;
    Unk_80188FEC *e;
    s32 n = 1;

    if (a->unk2C == 0 && a->unk36 >= 0x10) {
        switch (a->unk36 >> 4) {
        case 1:
            n = 2;
            break;
        case 2:
            n = 3;
            break;
        case 3:
            n = 4;
            break;
        case 4:
            n = 8;
            break;
        case 5:
            n = 0x10;
            break;
        default:
            n = 0x20;
            break;
        }
    }
    switch (a->unk3A[3]) {
    case 1:
        n = (n * 3) >> 1;
        break;
    case 2:
        n *= 2;
        break;
    case 3:
        n *= 4;
        break;
    }
    g->unk1FC++;
    e = func_80188FEC(p->unk4[p->unk2]);
    if (e != NULL && g->unk1FC == 6) {
        n += e->unk24;
        g->unk1FC = 0;
    }
    a->unk4A = 0;
    a->unk0 -= n;
    func_8018A7C0(a);
}

void func_80189C3C(s32 a, s16 b) {
    s16 i;
    s16 y;
    s16 d;
    s32 t = a * 2;
    d = b / 10;
    y = (s16)t * 7 + 8;
    for (i = 0; i < 7; i++) {
        if ((D_801D7724[d] >> i) & 1) {
            func_801A461C(0x409, y - i, 0x7FFF);
        } else {
            func_801A461C(0x409, y - i, 0);
        }
    }
    d = b % 10;
    y = (s16)(t + 1) * 7 + 8;
    for (i = 0; i < 7; i++) {
        if ((D_801D7724[d] >> i) & 1) {
            func_801A461C(0x409, y - i, 0x7FFF);
        } else {
            func_801A461C(0x409, y - i, 0);
        }
    }
}

void func_80189DE8(Unk_801E0710 *a) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801D7730 *c;
    s16 f = 0;
    s32 i;
    s32 n;
    s32 v;

    for (i = 0; i < 5; i++) {
        v = g->unkB4[i];
        if (v < 0x10) {
            a->unk3A[i] = 0;
        } else if (v >= 0x10 && v < 0xA6) {
            a->unk3A[i] = 1;
        } else if (v >= 0xA6 && v < 0xF0) {
            a->unk3A[i] = 2;
        } else {
            a->unk3A[i] = 3;
            g->unkB4[i] = 0xF0;
        }
        n = a->unk3A[i];
        if (a->unk2C != 0) {
            if (n == 0) {
                n = 4;
            }
            if (i == 0) {
                f = 1;
            }
        }
        c = &D_801D7730[n];
        func_801A461C(0x400, i + 0x40, (c->unk0 | (c->unk1 << 5) | (c->unk2 << 10)) & 0xFFFF);
        if (f != 0) {
            func_801A461C(0x400, 0x45, (c->unk0 | (c->unk1 << 5) | (c->unk2 << 10)) & 0xFFFF);
            f = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189F50);

void func_8018A24C(void) {
    Unk_801E0710 *q = &D_801E0710;
    s32 i;
    s32 n;
    s32 v;
    s32 m;

    func_801A4824(0x400, 0x40, 0x45, 0);
    if (q->unk0 <= 0) {
        q->unk0 = 0;
        n = 0;
        func_801A25B4(4);
    } else {
        n = q->unk0 * 0x24 / 255 + 0x10;
        v = (q->unk0 << 12) / 255;
        if (q->unk38 != 0) {
            if (v >= 0x400) {
                q->unk38 = 0;
                func_801A25B4(4);
            }
        } else if (v < 0x400) {
            q->unk38 = 1;
            func_801A2678(4);
        }
    }
    func_801A4944(0x400, 0x10, 0x33);
    for (i = 0x10; i < 0x34; i++) {
        if (n < i) {
            func_801A461C(0x400, i, 0x1421);
        }
    }
    func_80189DE8(q);
    m = q->unk58->unk8[q->unk58->unk2] * 0x10 / 100;
    func_801A4944(0x400, 0x50, 0x5F);
    for (n = 0x50; n < m + 0x50; n++) {
        func_801A461C(0x400, n, 0x7E8A);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A3F8);

void func_8018A5F0(Unk_801E0710 *a, Unk_801E0368 *b, s32 c, s32 d) {
    s32 i;
    s16 e = c;

    b->unk0[0x3F]++;
    if ((s16)b->unk0[0x3F] >= 60) {
        b->unk0[0x3F] -= 60;
        b->unk0[0x3E]++;
        if ((s16)d == 0) {
            a->unk36++;
        }
        if ((s16)b->unk0[0x3E] >= 24) {
            a->unk34 = 0;
            b->unk0[0x3E] -= 24;
            b->unk0[0x3D]++;
            b->unk0[0x40] = (s16)b->unk0[0x3D] % 2;
            if ((s16)b->unk0[0x3D] >= 99) {
                b->unk0[0x3D] = 98;
            }
            if (e == 0) {
                func_80189C3C(0, b->unk0[0x3D] + 1);
            }
        }
        if (e == 0) {
            func_80189C3C(1, (s16)b->unk0[0x3E]);
        }
        func_8018BB00(b->unk0[0x3D], b->unk0[0x3E]);
        for (i = 0; i < 5; i++) {
            if (a->unk2C != 0) {
                if (b->unkB4[i] > 0) {
                    b->unkB4[i] -= 0x10;
                    if (b->unkB4[i] < 0) {
                        b->unkB4[i] = 0;
                    }
                }
            } else if (a->unk3A[i] != 3) {
                if (b->unkB4[i] > 0) {
                    b->unkB4[i] -= 4;
                    if (b->unkB4[i] < 0) {
                        b->unkB4[i] = 0;
                    }
                }
            }
        }
    }
    if (e == 0) {
        func_80189C3C(2, (s16)b->unk0[0x3F]);
    }
}

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
