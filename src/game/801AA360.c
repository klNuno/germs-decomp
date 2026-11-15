#include "common.h"

typedef struct {
    u8 pad0[0x42];
    u16 unk42;
    u8 pad44[0x2];
    u16 unk46;
    u8 pad48[0x2A];
    s16 unk72;
    s16 unk74;
    s16 unk76;
} Unk_801E076C;
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
typedef struct {
    s32 unk0;
    s16 unk4;
    u8 pad6[0x4];
    s16 unkA;
    s16 unkC;
    u8 padE[0x6];
    u16 unk14;
    u16 unk16;
    s16 unk18;
    s16 unk1A;
} Unk_801AC55C;
typedef struct { u8 pad0[0x54]; Unk_801AC55C *unk54; } Unk_801E0710;
extern Unk_801E0710 D_801E0710;
extern s16 D_801D7FB0[];
void func_801A2678(s32 arg0);
s32 func_8018D1A0(void);
typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    u8 pad8[0x10];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 pad2A[0x2];
    s32 unk2C;
    u8 unk30[0x14];
    s32 unk44;
    s32 unk48;
    s32 unk4C;
} Unk_801A7C3C;
typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
} Unk_801E1118;
extern Unk_801E1118 D_801E1118;
Unk_801A7C3C *func_801A7C3C(s32 arg0, s32 arg1);
extern char D_80171A9C[];
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
void func_801AB4D4(Unk_801A7C3C *arg0, s32 arg1);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    Unk_801AC55C *unkC;
    Unk_801AC55C *unk10;
} Unk_801D7FB0;
s32 func_8018D078(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i);
extern char D_80171A78[];
extern char D_80171AA8[];
void *func_801CC898(u32 size);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801AA8DC_10;
void RotMatrix(Unk_801AA8DC_10 *arg0, void *arg1);
typedef struct { s32 unk0; s16 unk4; s16 unk6; u8 pad8[0xA]; u16 unk12; } Unk_801DFFE8;
extern Unk_801DFFE8 D_801DFFE8;
void func_80183E88(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_80184094(void);
void func_80174840(s16 arg0);
extern s32 D_801DFDA8[];
extern s32 D_801DFDAC[];
void func_8018C554(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
typedef struct { s16 unk0[5]; s16 unkA; char *unkC; s16 unk10; s16 unk12; s32 unk14; s32 unk18; s32 unk1C; } Unk_801E0340;
extern Unk_801E0340 D_801E0340;
typedef struct { s32 unk0; s32 unk4; s16 unk8; s16 unkA; u8 unkC[0x8]; s32 unk14; } Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
typedef struct { u16 unk0; s16 unk2; s16 *unk4; s16 *unk8; s16 *unkC; } Unk_801E07C0;
extern Unk_801E07C0 D_801E07C0;
s16 func_8018D1F0(void);
s16 func_8018CEA0(s16 a);
void func_801AB9E0(void);
extern s16 D_801D7FC4[];
typedef struct { u8 pad0[0x60]; s32 unk60; s32 unk64; s32 unk68; } Unk_801AC578;
Unk_801AC55C *func_801A44B8(u16 arg0);
s32 SquareRoot0(s32 arg0);
typedef struct { u8 pad0[0x22]; s16 unk22; s16 unk24; s16 unk26; s16 unk28; u8 pad2A[0x2]; s32 unk2C; void *unk30; void *unk34; void *unk38; Unk_801AC55C **unk3C; } Unk_801AC70C;
void func_801A80CC(s32 a, s32 b, s32 c);
void *func_801D15C8(u32 arg0);
s32 func_801D14B8(void *arg0);
void func_801AC88C();
void func_801AC91C();

INCLUDE_RODATA("asm/nonmatchings/game/801AA360", D_80171A78);

INCLUDE_RODATA("asm/nonmatchings/game/801AA360", D_80171A9C);

INCLUDE_RODATA("asm/nonmatchings/game/801AA360", D_80171AA8);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AA360);

void func_801AA8DC(void) {
    Unk_801AA8DC_10 sv;
    Unk_801E076C *q = D_801E076C[0];
    Unk_801E1118 *g = &D_801E1118;
    Unk_801A7C3C *p = func_801A7C3C(2, 0);

    if (p != NULL) {
        p->unk4 = 1;
        p->unk18 = 0xF0A;
        p->unk6 = 0;
        p->unk1C = 0;
        p->unk20 = 0x3E80;
        p->unk24 = 0;
        p->unk26 = 0;
        p->unk28 = 0;
        if (g->unk8 == 0) {
            p->unk18 = -0xF0A;
            p->unk26 = 180;
        }
        p->unk44 = p->unk18 - q->unk72 * 12500;
        p->unk48 = p->unk1C + q->unk74 * 32000;
        p->unk4C = p->unk20 - q->unk76 * 12500;
        sv.unk0 = (p->unk24 << 12) / 360;
        sv.unk2 = (p->unk26 << 12) / 360;
        sv.unk4 = (p->unk28 << 12) / 360;
        RotMatrix(&sv, p->unk30);
        p->unk2C = 0;
    }
    g->unkA = 1;
    g->unk12 = 0;
    g->unkE = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AAA9C);

INCLUDE_ASM("asm/nonmatchings/game/801AA360", func_801AACF4);

void func_801AB040(s16 arg0) {
    Unk_801E076C *q = D_801E076C[0];
    Unk_801DFFE8 *d = &D_801DFFE8;
    Unk_801E1118 *p = &D_801E1118;

    if (arg0 != 0) {
        if (p->unkC == 0) {
            if ((p->unk8 != 0 && p->unk4 == 0x200010) || (p->unk8 == 0 && p->unk4 == 0x200020)) {
                p->unkC = 1;
                d->unk0 = p->unk4;
                d->unk4 = (u8)(p->unk4 >> 16);
                if (d->unk6 != 2) {
                    d->unk6 = 2;
                }
                if (!(q->unk42 & 4)) {
                    q->unk42 |= 4;
                }
                if (q->unk46 == 2) {
                    /* " 7電車1から降りる      3○" */
                    func_80183E88(" 7\223d\216\3241\202\251\202\347\215~\202\350\202\351      3\201\233", 1, -1, 8, -1, 0, 1);
                } else if (q->unk46 == 3) {
                    /* " 7地下鉄1から降りる     3○" */
                    func_80183E88(" 7\222n\211\272\223S1\202\251\202\347\215~\202\350\202\351     3\201\233", 1, -1, 8, -1, 0, 1);
                }
            }
        }
    } else if (p->unkC != 0) {
        func_80184094();
        func_80174840(1);
        p->unkC = 0;
        if (q->unk42 & 4) {
            q->unk42 &= ~4;
        }
    }
}

s16 func_801AB1A0(s16 arg0) {
    Unk_801E1118 *p;
    u16 v = D_801E076C[0]->unk46;

    p = &D_801E1118;

    if (v == 3) {
        arg0 = 0;
        if (p->unk8 != 0) {
            func_8018C554(1, D_801DFDA8, 9, 0x41, 1, 0x5A, 6, p->unk10 + 0xF90000, 0);
        } else {
            func_8018C554(1, D_801DFDA8, 9, 0x41, 2, -0x5A, 6, p->unk10 + 0xF90000, 0);
        }
    } else if (v == 2) {
        arg0 = 0;
        if (p->unk8 != 0) {
            func_8018C554(1, D_801DFDAC, 9, 0x41, (s16)(p->unk10 * 2 - 1), 0x5A, 0x11, p->unk10 + 0xF60000, 0);
        } else {
            func_8018C554(1, D_801DFDAC, 9, 0x41, (s16)(p->unk10 * 2), -0x5A, 0x11, p->unk10 + 0xF60000, 0);
        }
    }
    return arg0;
}

s16 func_801AB310(s16 arg0) {
    Unk_801E0340 *r = &D_801E0340;
    Unk_801E1118 *p;
    u16 v = D_801E076C[0]->unk46;

    p = &D_801E1118;
    if (v == 3) {
        if (p->unk8 != 0) {
            if (p->unk10 == 6) {
                func_8018C554(1, D_801DFDA8, 9, 0x41, 1, 0x5A, 6, p->unk10 + 0xF90000, 0);
                arg0 = 0;
                r->unkA = 1;
            }
        } else {
            if (p->unk10 == 1) {
                func_8018C554(1, D_801DFDA8, 9, 0x41, 2, -0x5A, 6, p->unk10 + 0xF90000, 0);
                arg0 = 0;
                r->unkA = 1;
            }
        }
    } else if (v == 2) {
        if (p->unk8 != 0) {
            if (p->unk10 == 3) {
                func_8018C554(1, D_801DFDAC, 9, 0x41, 5, 0x5A, 0x11, p->unk10 + 0xF60000, 0);
                arg0 = 0;
                r->unkA = 1;
            }
        } else {
            if (p->unk10 == 1) {
                func_8018C554(1, D_801DFDAC, 9, 0x41, 2, -0x5A, 0x11, p->unk10 + 0xF60000, 0);
                arg0 = 0;
                r->unkA = 1;
            }
        }
    }
    return arg0;
}

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

s16 func_801ABA88(void) {
    Unk_801E07C0 *q = &D_801E07C0;
    Unk_801D7FB0 *p = (Unk_801D7FB0 *)D_801D7FB0;
    s16 r = func_8018D1F0();

    if (r == 1) {
        if (!(D_801E6DA0.unk4 & 0x20) && (D_801E6DA0.unk0 & 0x20)) {
            D_801D7FB0[0] = 1;
            func_801A2678(0x11);
            func_8018D1A0();
        } else if (!(D_801E6DA0.unk4 & 0x40) && (D_801E6DA0.unk0 & 0x40)) {
            D_801D7FB0[0] = 0;
            func_801A2678(8);
            func_8018D1A0();
        } else if (!(D_801E6DA0.unk4 & 0x1000) && (D_801E6DA0.unk0 & 0x1000)) {
            p->unk4 = func_8018CEA0(1);
        } else if (!(D_801E6DA0.unk4 & 0x4000) && (D_801E6DA0.unk0 & 0x4000)) {
            p->unk4 = func_8018CEA0(0);
        }
        return 0;
    }
    if (r == 0) {
        if (!(D_801E6DA0.unk4 & 0x20) && (D_801E6DA0.unk0 & 0x20)) {
            func_801A2678(0x11);
            return 1;
        }
        if (q->unk0 == 0 && !(D_801E6DA0.unk4 & 0x800) && (D_801E6DA0.unk0 & 0x800)) {
            func_80184094();
            func_801AB9E0();
        }
        return -1;
    }
    return 0;
}

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

void func_801AC578(Unk_801AC578 *arg0, s16 arg1, s16 arg2) {
    Unk_801D7FB0 *p = (Unk_801D7FB0 *)D_801D7FB0;
    s32 dx;
    s32 dz;

    if (arg1 != 0) {
        p->unkC = func_801A44B8(4);
        p->unk10 = func_801A44B8(0x406);
        if (p->unk10 != NULL) {
            p->unk10->unkA = 0x90;
            p->unk10->unkC = 0x68;
            p->unk10->unk4 = 1;
        }
        if (p->unkC != NULL) {
            p->unkC->unk4 = 1;
            p->unkC->unk18 = 0;
            p->unkC->unk1A = p->unk4;
        }
        dx = D_801D7FC4[p->unk4 * 2] - arg0->unk60;
        dz = D_801D7FC4[p->unk4 * 2 + 1] - arg0->unk68;
        if (arg2 != 0) {
            p->unk8 = SquareRoot0(dx * dx + dz * dz);
        }
    } else {
        if (p->unk10 != NULL) {
            p->unk10->unk4 = 0;
            p->unk10 = NULL;
        }
        if (p->unkC != NULL) {
            p->unkC->unk4 = 0;
            p->unkC = NULL;
        }
    }
}

void func_801AC6C8(s16 arg0) {
    D_801D7FB0[0] = arg0;
    if (arg0 != 0) {
        func_801A2678(0x11);
    } else {
        func_801A2678(8);
    }
    func_8018D1A0();
}

void func_801AC70C(s16 arg0) {
    Unk_801E1118 *g = &D_801E1118;
    Unk_801AC55C *p;
    Unk_801AC70C *e;
    s32 n;

    p = func_801A44B8(0x408);
    if (p == NULL) {
        if (arg0 != 0) {
            g->unkE = 1;
        } else {
            g->unkE = 0;
            g->unk12 = 1;
            func_801A80CC(2, 0, 1);
        }
        return;
    }
    e = func_801D15C8(4);
    e->unk22 = 7;
    if (arg0 != 0) {
        e->unk24 = 0;
        n = p->unk14 * p->unk16;
        e->unk28 = 1;
        e->unk26 = n - 1;
        g->unkE = 3;
    } else {
        n = p->unk14 * p->unk16;
        e->unk26 = 0;
        e->unk28 = -1;
        e->unk24 = n - 1;
        g->unkE = 2;
    }
    e->unk2C = 0x19;
    e->unk30 = func_801AC88C;
    e->unk34 = func_801AC91C;
    e->unk38 = func_801AC91C;
    *e->unk3C = p;
    g->unk0 = func_801D14B8(e);
    func_801A2678(0xB);
}

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
