#include "common.h"

typedef struct { s16 unk0, unk2, unk4, unk6; } Unk_801DFD30;
Unk_801DFD30 *D_801DFD30;
typedef struct { s16 unk0[5]; s16 unkA; char *unkC; s16 unk10; s16 unk12; s32 unk14; s32 unk18; s32 unk1C; } Unk_801E0340;
extern Unk_801E0340 D_801E0340;
void func_801CD688(s32 a);
typedef struct { s16 unk0; s16 unk2; u16 unk4; } Unk_8018BD60_0;
typedef struct { Unk_8018BD60_0 *unk0; } Unk_8018BD60;
void func_8018BA48(u16 a);
typedef struct { s32 unk0; s16 unk4; s16 unk6; } Unk_801E056C;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; u16 unkA; s16 unkC; s16 unkE; u16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 *unk1C; } Unk_801E058C;
typedef struct {
    u16 unk0[0x70];
    u8 unkE0[0x124];
    Unk_801E056C unk204[4];
    Unk_801E058C unk224;
    s32 unk244;
    u8 unk248[4];
    s16 unk24C;
    s16 unk24E;
    s16 unk250;
    s16 unk252;
    s16 unk254;
} Unk_801E0368;
extern Unk_801E0368 D_801E0368;
extern Unk_801E058C D_801E058C;
void func_80185A60(s32 a, u16 b, s32 c);
void func_801A4A68(s32 arg0, s32 arg1);
void func_8018CB70(Unk_801E058C *p, s32 b);
u16 *D_801DFD34;
s16 D_801DFF04;
s16 D_801DFF06;
extern char D_801DFD38[];
u16 *func_801A44B8(u16 arg0);
void *func_801CC898(u32 size);
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
void func_8018B564(Unk_801E0368 *a, s16 b);
void func_801A43F4(s32 arg0);
void free3(void *ptr);
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_80174F54;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s32 unk8; s32 unkC; s32 unk10; s16 unk14; s16 unk16; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; s32 unk3C; s32 unk40; s32 unk44; s32 unk48; } Unk_801762F4;
typedef struct { u16 unk0; s16 unk2; s32 unk4; s16 unk8; u16 unkA; u8 unkC[0xC0]; } Unk_801767D4;
typedef struct { u16 unk0; s16 unk2; s32 unk4[8]; } Unk_80176890;
typedef struct { u16 unk0; u8 unk2[0x19]; u8 unk1B; u8 unk1C[4]; } Unk_8018F590;
typedef struct { u16 unk0; u8 unk2[0x5E]; } Unk_80188FEC;
typedef struct { u8 unk0[0xC]; u16 unkC; s16 unkE; } Unk_8018BC50_8;
typedef struct { u16 unk0; s16 unk2; s32 unk4; Unk_8018BC50_8 *unk8; Unk_8018BC50_8 *unkC; } Unk_8018BC50;
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14;
    s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34;
    Unk_80174F54 *unk38; Unk_801762F4 *unk3C; Unk_801767D4 *unk40; Unk_80176890 *unk44;
    s32 unk48; Unk_8018BC50 *unk4C; Unk_8018F590 *unk50; s32 unk54; Unk_80188FEC *unk58;
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
u16 D_801DFF00;
u16 D_801DFF02;
void func_801A461C(s32 a, s32 b, s32 c);
typedef struct { s16 unk0; u8 unk2[0x2A]; s16 unk2C; s16 unk2E; s16 unk30; u8 unk32[6]; s16 unk38; u8 unk3A[0xA]; s16 unk44; u8 unk46[4]; s16 unk4A; } Unk_801E0710;
extern Unk_801E0710 D_801E0710;
void func_8017345C(void);
void func_801759B0(void);
void func_80184C6C(void);
void func_8018F234(void);
void func_801AC4A8(void);
void func_8018DE58(void);
void func_801A7560(void);
void func_801979B4(u16 a, s16 b, s16 c);
void func_80185E38(void);
void func_801865C0(void);
void func_80186010(void);
void func_801A0418(u16 a);
void func_8018CD4C(Unk_801E058C *p);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018ACAC);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B11C);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B564);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B69C);

void func_8018B810(void) {
    s32 i;
    s32 j;
    u16 v;
    Unk_801DFD30 *e;
    Unk_801E0368 *p = &D_801E0368;
    if ((s16)p->unk0[0x5F] != 0) {
        D_801DFF06 = 0;
        D_801DFF04 = 0;
        D_801DFD34 = func_801A44B8(0x20C);
        if (D_801DFD34 != NULL) {
            D_801DFD34[6] = 0x29;
        }
        D_801DFD30 = func_801CC898((s16)p->unk0[0x5F] * 8);
        if (D_801DFD30 == NULL) {
            func_801CD54C(3, "Error Allocating Mail List", D_801DFD38, 0x16A);
        }
        for (i = 0; i < 0x20; i++) {
            j = i / 2 + 0x60;
            if (i & 1) {
                v = (u8)*(p->unk0 + j);
            } else {
                v = *(p->unk0 + j) >> 8;
            }
            if (v & 0x80) {
                e = &D_801DFD30[v & 0x3F];
                e->unk0 = i;
                e->unk2 = v;
                e->unk4 = (v & 0x40) >> 6;
            }
        }
        func_8018B564(p, 0);
    }
}

void func_8018B924(void) {
    s32 i;
    s32 j;
    s32 v;
    s32 t;
    Unk_801DFD30 *e;
    Unk_801E0368 *p = &D_801E0368;
    if ((s16)p->unk0[0x5F] != 0) {
        if (D_801DFD34 != NULL) {
            D_801DFD34[6] = 0x29;
            D_801DFD34 = NULL;
        }
        e = D_801DFD30;
        for (i = 0; i < (s16)p->unk0[0x5F]; i++, e++) {
            v = 0x80;
            if (e->unk4 != 0) {
                v = 0xC0;
            }
            v += i & 0x3F;
            j = e->unk0 / 2 + 0x60;
            if (e->unk0 % 2) {
                t = *(p->unk0 + j);
                *(p->unk0 + j) = v | (t & ~0xFF);
            } else {
                *(p->unk0 + j) = (u8)*(p->unk0 + j) | (v << 8);
            }
        }
        free3(D_801DFD30);
        D_801DFD30 = NULL;
        for (i = 0; i < 0x20; i++) {
            func_801A43F4((u16)(i + 0x217));
        }
    }
}

void func_8018BA48(u16 a) {
    s32 v;
    s32 i;
    s16 odd;
    u16 n;
    Unk_801E0368 *p = &D_801E0368;
    if (a < 0x20) {
        i = a / 2 + 0x60;
        odd = a % 2;
        if (odd) {
            v = (u8)*(p->unk0 + i) & 0x80;
        } else {
            v = (*(p->unk0 + i) >> 8) & 0x80;
        }
        if (v == 0) {
            n = p->unk0[0x5F]++ | 0x80;
            if (odd) {
                *(p->unk0 + i) = n | (*(p->unk0 + i) & 0xFF00);
            } else {
                *(p->unk0 + i) = (u8)*(p->unk0 + i) | (n << 8);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018BB00);

void func_8018BC50(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_8018BC50 *e = p->unk4C;
    if (e != NULL) {
        D_801DFD30[e->unk2].unk4 = 1;
        if (e->unk8 != NULL) {
            func_801A461C((u16)(e->unk0 + 0x217), 7, 0x2C1F);
            func_801A461C((u16)(e->unk0 + 0x217), 9, 0x1F);
            e->unk8->unkC = D_801DFF00;
            e->unk8->unkE = 2;
        }
        if (e->unkC != NULL) {
            e->unkC->unkC = D_801DFF02;
        }
        func_801A43F4(0x213);
        func_801A43F4(0x214);
        func_801A43F4(0x215);
        func_801A43F4(0x216);
        free3(e);
        p->unk4C = NULL;
    }
}

s16 func_8018BD44(s16 i) { return D_801DFD30[i].unk0; }

void func_8018BD60(Unk_8018BD60 *a) {
    func_8018BA48(a->unk0->unk4);
}

s32 func_8018BD8C(s16 a) {
    s32 v;
    Unk_801E0368 *p = &D_801E0368;
    s32 i = a / 2 + 0x60;
    if (a & 1) {
        v = (u8)p->unk0[i] & 0x40;
    } else {
        v = (p->unk0[i] >> 8) & 0x40;
    }
    return v != 0;
}

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018BDE8);

s32 func_8018C0A0(s16 a) {
    s32 b;

loop:
    if (a < 0) a += 360;
    if (a >= 360) a -= 360;
    if ((u16)a >= 360) goto loop;
    b = a;
    if (b >= 23 && b < 68) return 1;
    if (b >= 68 && b < 113) return 0;
    if (b >= 113 && b < 158) return 7;
    if (b >= 158 && b < 203) return 6;
    if (b >= 203 && b < 248) return 5;
    if (b >= 248 && b < 293) return 4;
    if (b >= 293 && b < 338) return 3;
    return 2;
}

s32 func_8018C170(void) {
    Unk_801E0340 *p = &D_801E0340;
    if (p->unkA == 0) {
        return 0;
    }
    p->unkA = 0;
    func_801CD688(0);
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018C1B0);

void func_8018C2FC(u16 a, s16 b, s16 c) {
    Unk_801E0368 *p = &D_801E0368;
    func_8017345C();
    if (a < 2) {
        func_801759B0();
        func_80184C6C();
        func_8018F234();
    } else if (a == 2) {
        func_801AC4A8();
    }
    func_8018DE58();
    func_801A7560();
    func_801979B4(a, b, c);
    if ((u16)(a - 1) < 2) {
        if (p->unk252 != 0) {
            func_80185E38();
        }
        if (p->unk254 != 0) {
            func_801865C0();
        }
        if (p->unk250 != 0) {
            func_80186010();
        }
    }
    func_801A0418(a);
}

void func_8018C414(s16 a, s16 b, s16 c, s16 d) {
    Unk_801E0340 *p = &D_801E0340;
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0368 *q = &D_801E0368;
    p->unk12 = b;
    ((s16 *)&p->unk14)[0] = c;
    ((s16 *)&p->unk14)[1] = d;
    p->unk0[1] = 0;
    p->unkA = 1;
    p->unkC = "\\S\\OFC.S;1";
    p->unk0[3] = 0;
    p->unk0[2] = 0;
    p->unk10 = a;
    if (d == 2) {
        return;
    }
    if ((s16)q->unk0[0x30] != 0 || g->unk2C != 0) {
        return;
    }
    switch (g->unk30) {
    case 0:
        if (g->unk2E >= 3) {
            p->unk0[3] = 1;
            g->unk30 = 1;
            g->unk2E = 0;
        }
        break;
    case 1:
        if (g->unk2E >= 5 && (s16)q->unk0[0x11] != 100) {
            q->unk0[0x11] = 100;
            p->unk0[3] = 1;
            g->unk30 = 2;
            g->unk2E = 0;
        }
        break;
    }
}

void func_8018C50C(s32 a, s32 b, s32 c, s16 d, s16 e) {
    Unk_801E0340 *p = &D_801E0340;
    p->unkA = 1;
    p->unk0[1] = 2;
    p->unk0[3] = 0;
    p->unk0[2] = 1;
    p->unkC = "\\S\\TWN.S;1";
    p->unk14 = a;
    p->unk18 = b;
    p->unk1C = c;
    p->unk12 = d;
    p->unk10 = e;
}

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018C554);

s16 func_8018C750(s16 a) {
    do {
        if (a < 0) a += 360;
        if (a >= 360) a -= 360;
    } while ((u16)a >= 360);
    return a;
}

s32 func_8018C790(s16 a) {
    s32 b;

loop:
    if (a < 0) a += 360;
    if (a >= 360) a -= 360;
    if ((u16)a >= 360) goto loop;
    b = a;
    if (b >= 45 && b < 135) return 0;
    if (b >= 135 && b < 225) return 6;
    if (b >= 225 && b < 315) return 4;
    return 2;
}

s32 func_8018C810(s32 a) {
    s32 i;
    s32 r;
    if (a == 1) return 0;
    if (a == 2) return 0x144;
    r = 0x144;
    for (i = 3; i <= a; i++) {
        r += 0x195 + (i - 3) * 0xA2;
    }
    return r;
}

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018C864);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018CB70);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018CD4C);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018CEA0);

s32 func_8018D078(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i) {
    Unk_801E0368 *p = &D_801E0368;
    Unk_801E058C *q = &p->unk224;
    if (p->unk224.unk0 != 0) {
        return 0;
    }
    p->unk24C = 1;
    p->unk224.unk0 = 2;
    if (a != 0) {
        q->unk2 = 0;
        q->unk4 = g;
        q->unk6 = 0;
    }
    q->unk8 = g;
    q->unkA = b;
    q->unkC = c;
    q->unk10 = h;
    q->unk12 = i;
    q->unk14 = 1;
    if (e < d) {
        q->unk14 = 0;
    }
    q->unk16 = 1;
    if (c == -1) {
        q->unk16 = 0;
    }
    q->unk18 = e;
    q->unk1A = d;
    q->unk1C = f;
    if ((c == 0x40C || c == 0x402 || c == -2) && b == 0x40B) {
        func_8018CD4C(q);
    }
    func_8018CB70(q, 1);
    func_80185A60(0xB, b, 2);
    return 1;
}

s32 func_8018D1A0(void) {
    Unk_801E058C *p = &D_801E058C;
    if (p->unk0 != 1) {
        return 0;
    }
    p->unk0 = 2;
    func_80185A60(0xC, p->unkA, 2);
    return 1;
}

s16 func_8018D1F0(void) { return D_801E058C.unk0; }

s32 func_8018D200(u16 a, s16 *b) {
    Unk_801E058C *p = &D_801E058C;
    if (p->unk0 == 2) {
        return 0;
    }
    p->unk2 = 0;
    p->unk6 = 0;
    p->unk1C = b;
    p->unk4 = p->unk8;
    func_801A4A68(p->unkA, 0);
    func_801A4A68(a, 1);
    p->unkA = a;
    func_8018CB70(p, 0);
    return 1;
}

s16 func_8018D294(s16 i) {
    Unk_801E058C *p = &D_801E058C;
    if (i < 0 || p->unk1A < i) {
        return -1;
    }
    return p->unk1C[i];
}
