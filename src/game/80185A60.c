#include "common.h"

typedef struct { s16 unk0[3]; s16 unk6; s16 unk8[3]; s16 unkE; } Unk_801E1040;
extern Unk_801E1040 D_801E1040;
typedef struct { s32 unk0; s16 unk4; s16 unk6; } Unk_801E056C;
typedef struct {
    u16 unk0[0x70];
    u8 unkE0[0x124];
    Unk_801E056C unk204[4];
    u8 unk224[0x20];
    s32 unk244;
    u8 unk248[4];
    s32 unk24C;
    s16 unk250;
    s16 unk252;
} Unk_801E0368;
extern Unk_801E0368 D_801E0368;
void func_801CC514(s32 a, s32 b);
extern Unk_801E056C D_801E056C[4];
s32 func_801CC3DC(s32 a, s32 b, s32 c);
void free3(void *ptr);
void *D_801DFCF0;
void *D_801DFCF4;
extern s16 D_801E05BA[];
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801DFEA0;
Unk_801DFEA0 D_801DFEA0;
extern u16 D_801E02A8[];
s32 LoadImage2(void *rect, void *p);
extern s16 D_801E05BC[];
s32 StoreImage2(void *rect, void *p);
void *D_801DFCF8;
void *D_801DFCFC;
extern s16 D_801E05B8[];
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801DFD00;
Unk_801DFD00 D_801DFD00;
typedef struct { u8 unk0[0xC]; s16 unkC; u8 unkE[4]; s16 unk12; } Unk_801867E8_0;
typedef struct { u8 unk0[0x24]; s16 unk24; u8 unk26[0x16]; Unk_801867E8_0 **unk3C; } Unk_801867E8;
s16 D_801DFE8A;
typedef struct { u8 unk0[4]; s16 unk4; u8 unk6[6]; s16 unkC; u8 unkE[4]; s16 unk12; } Unk_80186838_0;
typedef struct { u8 unk0[0x22]; s16 unk22; u8 unk24[0x18]; Unk_80186838_0 **unk3C; } Unk_80186838;
s16 D_801DFE88;
typedef struct {
    u8 unk0[4];
    s16 unk4;
    u8 unk6[6];
    s16 unkC;
    u8 unkE[4];
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
} Unk_80186884_0;
typedef struct {
    u8 unk0[0x22];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[2];
    s32 unk2C;
    void (*unk30)();
    void (*unk34)();
    u8 unk38[4];
    Unk_80186884_0 **unk3C;
} Unk_80186884;
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    s16 unk6;
} Unk_801DFEB8;
typedef struct { u16 unk0; u16 unk2; } Unk_801DFE68;
Unk_801DFEB8 D_801DFEB8;
extern Unk_801DFE68 D_801DFE68;
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
    s16 unk48;
    u8 unk4A[2];
    s32 unk4C;
} Unk_801E0768;
extern Unk_801E0768 *D_801E0768[];
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_80174F54;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s32 unk8; s32 unkC; s32 unk10; s16 unk14; s16 unk16; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; s32 unk3C; s32 unk40; s32 unk44; s32 unk48; } Unk_801762F4;
typedef struct { u16 unk0; s16 unk2; s32 unk4; s16 unk8; u16 unkA; u8 unkC[0xC0]; } Unk_801767D4;
typedef struct { u16 unk0; s16 unk2; s32 unk4[8]; } Unk_80176890;
typedef struct { u16 unk0; u8 unk2[0x19]; u8 unk1B; u8 unk1C[4]; } Unk_8018F590;
typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4[0x20];
    u16 unk24;
    u8 unk26[2];
    s16 unk28;
    u8 unk2A[6];
    u16 unk30;
    u8 unk32[2];
    s16 unk34;
    u8 unk36[2];
    u16 unk38;
    u8 unk3A[2];
    s16 unk3C;
    u8 unk3E[2];
    s16 unk40;
    u8 unk42[6];
    s16 unk48;
    u8 unk4A[2];
    u16 unk4C;
    u8 unk4E[2];
    u16 unk50;
    u16 unk52;
    u8 unk54[0xC];
} Unk_80188FEC;
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14;
    s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34;
    Unk_80174F54 *unk38; Unk_801762F4 *unk3C; Unk_801767D4 *unk40; Unk_80176890 *unk44;
    s32 unk48; s32 unk4C; Unk_8018F590 *unk50; s32 unk54; Unk_80188FEC *unk58;
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
typedef struct {
    u16 unk0;
    u16 unk2;
    char unk4[0x22];
    s16 unk26;
} Unk_801891A4;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801DFEB0;
Unk_801DFEB0 D_801DFEB0;
s16 D_801DFEA8;
int rand(void);
typedef struct {
    u8 unk0[0x22];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    u8 unk28[8];
    void (*unk30)();
    void (*unk34)();
    u8 unk38[4];
    s32 *unk3C;
} Unk_80185918;
void func_80185918(Unk_80185918 *arg0);
void *func_801D15C8(u32 arg0);
void func_801D1774(void *arg0, s32 arg1);
s32 func_801D14B8(void *arg0);
extern char D_80170544[];
extern char D_80170560[];
void func_80186884(Unk_80186884 *arg0);
Unk_80186884_0 *func_801A44B8(u16 arg0);
void func_801CD54C(s32 a, char *b, char *c, s32 d);
extern char D_8017056C[];
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801DFE90;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801DFE98;
Unk_801DFE90 D_801DFE90;
Unk_801DFE98 D_801DFE98;
s16 D_801DFE8C;
s16 D_801DFE8E;
void func_80185BE0(s16 arg0);
void *func_801CC898(s32 size);
extern s32 D_801DFED4;
void func_8018715C(void);
void func_801872D4(void);
void func_80186EF8(void);
s16 func_8018970C(s32 *arg0);
void func_80189970(s16 a);
void func_8018C2FC(s32 a, s32 b, s32 c);
s32 func_801CC378(s32 *arg0);
void func_801CC734(s32 *arg0);
void func_801D06C4(void);
typedef struct { s16 unk0[5]; s16 unkA; char *unkC; s16 unk10; s16 unk12; s32 unk14; s32 unk18; s32 unk1C; } Unk_801E0340;
extern Unk_801E0340 D_801E0340[];
typedef struct {
    u8 unk0[0x42];
    u16 unk42;
    u8 unk44[0x10];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0xC];
    s16 unk6C;
    s16 unk6E;
    s16 unk70;
    s16 unk72;
    s16 unk74;
    s16 unk76;
    s16 unk78;
    u8 unk7A[0x26];
    u8 unkA0[4];
} Unk_801E0710_5C;
typedef struct {
    s16 unk0;
    s16 unk2;
    u8 unk4[8];
    u16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    u16 unk14;
    u8 unk16[2];
    u16 unk18;
    u8 unk1A[2];
    u16 unk1C;
    u8 unk1E[2];
    u16 unk20;
    u8 unk22[2];
    u16 unk24;
    u8 unk26[6];
    s16 unk2C;
    u8 unk2E[0x1A];
    s16 unk48;
    u8 unk4A[2];
    s32 unk4C;
    u8 unk50[8];
    Unk_801E0768 *unk58;
    Unk_801E0710_5C *unk5C;
} Unk_801E0710;
extern Unk_801E0710 D_801E0710;
extern s16 D_801E02C8[];
s16 D_801DFEC0;
s16 D_801DFEC6;
s16 func_801882AC(Unk_801E0710 *a, s16 b, s16 c, s16 d, s16 e);
void *func_8018E56C(u16 a);
void func_8018D2DC(void *a, void *b, s32 c, s32 d);
void func_80187978(s32 arg0);
void func_8019290C(void);
void func_801A80CC(s32 a, s32 b, s32 c);
void func_801A8198(s32 a, s32 b, s32 c);
Unk_80188FEC *func_80188FEC(s16 arg0);
void func_80199A94(s16 a, s32 b);
extern Unk_801E0710_5C *D_801E076C[];
s32 func_80186910(s32 *arg0);
void func_801A4824(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_801A461C(s32 arg0, s32 arg1, s32 arg2);
void func_801D06B4(void);
void func_80198CFC(s16 a, u16 b, s32 c, s32 d, s32 e, s16 f, s16 g, s16 h, s32 i);
typedef struct {
    u8 unk0[0x22];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    u8 unk28[8];
    void (*unk30)();
    void (*unk34)();
    void (*unk38)();
    Unk_80186884_0 **unk3C;
} Unk_80185A60;
void func_801867E8(Unk_801867E8 *arg0);
void func_80186838(Unk_80186838 *arg0);
extern u8 D_801D76E4[][0x20];
typedef struct Unk_801854B8 {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s32 unk28;
    u8 unk2C[0x14];
    s32 unk40;
    s32 unk44;
    s32 unk48;
    u8 unk4C[0x2C];
    void *unk78;
    void *unk7C;
} Unk_801854B8;
Unk_801854B8 *func_801855C8(u16 arg0);
extern char D_80170590[];
void func_80183E88(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_801A4A68(s32 arg0, s32 arg1);
void func_801CD688(s32 a);
s32 rsin(s32 a);
s32 rcos(s32 a);
void func_8018E344(u16 a);
s32 func_801875E4(s16 arg0);
s16 D_801DFEC2;
s16 D_801DFEC4;
s32 func_8018D078(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i);
s32 func_8018D1A0(void);
void func_801A2678(s32 arg0);
typedef struct { u16 unk0; u16 unk2; u16 unk4; } Unk_801DFE6A;
extern Unk_801DFE6A D_801DFE6A;
void func_80184ECC(Unk_801854B8 *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_80185034(Unk_801854B8 *arg0, s16 arg1, s16 arg2);
void *memset(void *dst, s32 c, u32 n);
char *strncpy(char *dst, char *src, u32 n);
extern char D_801DFD08[];
extern char D_801DFD0C[];
extern char D_801DFD10[];
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} Unk_801E6DA0;
u16 D_801DFEBC;
extern Unk_801E6DA0 D_801E6DA0;
void func_80186AEC(void);
void func_80186C80(Unk_801DFEB8 *arg0, s16 arg1);
s32 func_801CD6B4(void);
void func_80184094(void);
void func_8018D8B8(void);
void func_801A4BC8(s32 arg0, s32 arg1, s32 arg2);
extern char D_80170618[];
extern char D_80170648[];
extern char D_80170678[];
extern char D_801706BC[];
extern char D_80170700[];
extern char D_8017073C[];
extern char D_80170778[];
extern char D_801707A4[];
extern char D_801707B8[];
extern char D_801707CC[];
extern char D_801707E0[];
extern char D_801707F4[];
/* refined: unk2 u16, unk4 text, unk26 s16 (was u8 unk2[0x26]) */
/* refined: unk26[0x22] split into unk26[6], s16 unk2C, unk2E[0x1A] */
int sprintf(char *buf, const char *fmt, ...);
void func_801831EC(s16 arg0, s16 arg1, char *arg2, s16 arg3, s32 arg4);
void func_80189DE8(Unk_801E0710 *arg0);
void func_8018ABE8(s16 a, s16 b);
void func_80199D68(s16 arg0, s16 arg1, s16 arg2);
void func_80199E1C(s16 arg0, s16 arg1);
s32 func_80199FA0(void);
extern s32 D_801E6DB4[];
void func_8017A86C(u16 arg0);
void func_801A25B4(s32 arg0);
void func_80187718(s16 arg0, s16 arg1);
void func_8018DA2C(void *arg0, s16 arg1, s16 arg2);
extern char D_8017080C[];
s16 func_8018884C(Unk_801E0710 *arg0, s16 arg1, s16 arg2);
s16 func_8018D1F0(void);
s16 func_8018CEA0(s16 a);
u16 func_8019A6A4(void);
s16 func_8018898C(Unk_801E0710 *arg0, s16 arg1);

void func_80185A60(s32 arg0, u16 arg1, s32 arg2) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_80186884_0 *spr;
    Unk_80185A60 *node;

    spr = func_801A44B8(arg1);
    if (spr == NULL) {
        func_801CD54C(5, D_80170544, D_80170560, 0x97);
    }
    D_801DFE88 = spr->unkC;
    D_801DFE8A = spr->unk12;
    node = func_801D15C8(4);
    arg2 *= 30;
    node->unk22 = arg0;
    if (arg0 == 2 || arg0 == 3) {
        node->unk24 = (arg0 == 2) ? 0xF0 : spr->unkC;
        node->unk26 = (arg0 == 2) ? spr->unkC : 0xF0;
    } else {
        node->unk24 = (arg0 == 0xB) ? 0xF0 : spr->unkC;
        node->unk26 = (arg0 == 0xB) ? spr->unkC : 0xF0;
    }
    func_801D1774(node, arg2);
    node->unk30 = func_801867E8;
    node->unk34 = func_80186838;
    node->unk38 = func_80186838;
    *node->unk3C = spr;
    if (arg0 == 2 || arg0 == 0xB) {
        spr->unk4 = 1;
        spr->unkC = 0xF0;
        spr->unk12 = 0;
    }
    g->unk244 = func_801D14B8(node);
}

void func_80185BE0(s16 arg0) {
    s16 r[4];
    u16 buf[0x100];
    s32 i;
    s32 v;

    r[1] = 0x1EE;
    r[2] = 0x100;
    r[3] = 1;
    r[0] = 0;
    switch (arg0) {
    case 0:
        for (i = 0; i < 0x40; i++) {
            buf[i] = ((i / 4) << 10) | 0x8000;
        }
        for (i = 0; i < 0x80; i++) {
            buf[i + 0x40] = ((i / 8) << 5) | 0xC000;
        }
        for (i = 0; i < 0x40; i++) {
            buf[i + 0xC0] = (i / 4) | 0xC200;
        }
        break;
    case 1:
        for (i = 0; i < 0x40; i++) {
            buf[i] = (i / 4) | ((i / 8) << 5) | 0x8000;
        }
        for (i = 0; i < 0x80; i++) {
            buf[i + 0x40] = ((i / 16 + 8) << 5) | 0x8010;
        }
        for (i = 0; i < 0x40; i++) {
            buf[i + 0xC0] = ((i / 4) << 10) | 0x8210;
        }
        break;
    case 2:
        for (i = 0; i < 0x100; i++) {
            v = i / 8;
            buf[i] = v | (v << 5) | (v << 10) | 0x8000;
        }
        break;
    }
    LoadImage2(r, buf);
}

void func_80185E38(void) {
    void **p = &D_801DFCF0;
    u8 *src = p[D_801DFE8E];
    s16 n = D_801DFE8E ^ 1;
    u8 *dst = p[n];
    u8 *pal;
    s32 i;
    s32 j;
    s32 v;
    s32 w;
    s32 k;

    if (src != 0 && dst != 0) {
        pal = 0;
        if (D_801DFE8C == 1) {
            pal = D_801D76E4[D_801DFE8E];
        }
        D_801DFE8E = n;
        v = 0;
        for (i = 0; i < 0x10; i++) {
            if (rand() % 100 < 50) {
                v = rand() % 2 * 255;
            }
            *(dst + i + 0x1E0) = v;
            *(dst + i + 0x1F0) = v;
        }
        for (i = 0x1E0; i >= 0x20; i -= 0x10) {
            for (j = 1; j < 0xF; j++) {
                k = i + j;
                w = *(src + k + 0x10);
                w += *(src + k + 1);
                w += *(src + k - 1);
                w += *(src + k - 0xF);
                w += *(src + k - 0x11);
                w /= 5;
                if (w >= 5) {
                    w -= 4;
                }
                *(dst + k - 0x10) = w;
            }
        }
        if (pal != 0) {
            LoadImage2(&D_801DFE98, pal);
        }
        LoadImage2(&D_801DFE90, dst);
    }
}

void func_80186010(void) {
    void **p = &D_801DFCF8;
    u8 *src = p[D_801DFEA8];
    s16 n = D_801DFEA8 ^ 1;
    u8 *dst = p[n];
    s32 i;
    s32 j;

    if (src != 0 && dst != 0) {
        D_801DFEA8 = n;
        for (i = 0; i < 0x20; i++) {
            *(dst + i + 0x3E0) = rand() % 256;
        }
        for (i = 0x3C0; i >= 0; i -= 0x20) {
            for (j = 1; j < 0x1F; j++) {
                dst[i + j] = (src[i + j] + src[i + j + 0x1F] * 2 + src[i + j + 0x20] * 3 + src[i + j + 0x21] * 2) >> 3;
            }
        }
        LoadImage2(&D_801DFEB0, dst);
    }
}

void func_80186128(s32 arg0, s32 arg1) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801E1040 *h = &D_801E1040;
    Unk_80185918 *node;

    node = func_801D15C8(4);
    arg1 *= 30;
    node->unk22 = arg0;
    switch (arg0) {
    case 0:
    case 9:
        node->unk24 = 0;
        node->unk26 = 0x1000;
        break;
    case 1:
    case 10:
        node->unk24 = 0x1000;
        node->unk26 = 0;
        break;
    }
    h->unkE = node->unk24;
    h->unk6 = 1;
    func_801D1774(node, arg1);
    node->unk30 = func_80185918;
    node->unk34 = func_80185918;
    *node->unk3C = arg0;
    g->unk244 = func_801D14B8(node);
}

void func_80186230(void) {
    Unk_801E1040 *p = &D_801E1040;
    if (p->unk6 != 0) {
        p->unkE = 0x1000;
        p->unk6 = 0;
    }
}

void func_80186258(void) {
    Unk_801E1040 *p = &D_801E1040;
    if (p->unk6 == 0) {
        p->unkE = 0;
        p->unk6 = 1;
    }
}

void func_80186280(void) {
    Unk_801E1040 *p = &D_801E1040;
    if (p->unk6 == 0) {
        p->unkE = 0x400;
        p->unk6 = 1;
    }
}

void func_801862AC(u16 arg0, s32 arg1) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_80186884_0 *spr;
    Unk_80186884 *node;

    spr = func_801A44B8(arg0);
    if (spr == NULL) {
        func_801CD54C(5, D_80170544, D_80170560, 0xCC);
    }
    node = func_801D15C8(4);
    node->unk22 = 6;
    node->unk24 = 1;
    node->unk26 = spr->unk14 * spr->unk16;
    node->unk28 = 1;
    node->unk30 = func_80186884;
    node->unk34 = func_80186884;
    arg1 *= 30;
    node->unk2C = arg1 / node->unk26;
    *node->unk3C = spr;
    spr->unk18 = 0;
    spr->unk1A = 0;
    spr->unk4 = 1;
    g->unk244 = func_801D14B8(node);
}

void func_801863B4(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_801E0368.unk204[i].unk4 = 0;
        D_801E0368.unk204[i].unk0 = -1;
        func_801CC514(2, i + 0x64);
    }
}

void func_80186414(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801E056C *p = &D_801E056C[arg0];

    if (p->unk4 == 0) {
        p->unk0 = func_801CC3DC(arg2 * 60, arg0 + 0x64, arg1);
        if (p->unk0 >= 0) {
            p->unk4 = 1;
        }
    }
}

void func_8018647C(s16 arg0) {
    void *a;
    void *b;
    Unk_801DFE90 *r = &D_801DFE90;
    Unk_801DFE98 *t;

    r->unk0 = 0x1B0;
    r->unk2 = 0xE0;
    r->unk4 = 8;
    r->unk6 = 0x20;
    t = &D_801DFE98;
    t->unk0 = 0x100;
    t->unk2 = 0x1ED;
    t->unk4 = 0x10;
    t->unk6 = 1;
    func_80185BE0(arg0);
    a = func_801CC898(0x200);
    b = func_801CC898(0x200);
    if (a == 0 || b == 0) {
        func_801CD54C(3, D_8017056C, D_80170560, 0x16E);
    }
    D_801DFE8C = arg0;
    D_801DFCF0 = a;
    D_801DFCF4 = b;
    D_801DFE8E = 0;
}

void func_8018655C(void) {
    s32 i;
    void **p = &D_801DFCF0;

    D_801E05BA[0] = 0;
    for (i = 0; i < 2; i++) {
        if (p[i] != 0) {
            free3(p[i]);
            p[i] = 0;
        }
    }
}

void func_801865C0(void) {
    s32 i;
    u16 t = D_801E02A8[1];

    for (i = 1; i < 14; i++) {
        D_801E02A8[i] = D_801E02A8[i + 1];
    }
    D_801E02A8[14] = t;
    LoadImage2(&D_801DFEA0, D_801E02A8);
}

void func_80186630(void) {
    Unk_801DFEA0 *r = &D_801DFEA0;

    r->unk0 = 0x60;
    r->unk2 = 0x1E6;
    r->unk4 = 0x10;
    r->unk6 = 1;
    StoreImage2(r, D_801E02A8);
    D_801E05BC[0] = 0;
}

void func_80186680(void) {
    void *a;
    void *b;
    Unk_801DFEB0 *r = &D_801DFEB0;

    r->unk0 = 0x1B0;
    r->unk2 = 0xC0;
    r->unk4 = 0x10;
    r->unk6 = 0x20;
    a = func_801CC898(0x400);
    b = func_801CC898(0x400);
    if (a == 0 || b == 0) {
        func_801CD54C(3, D_8017056C, D_80170560, 0x1CA);
    }
    D_801DFCF8 = a;
    D_801DFCFC = b;
    D_801DFEA8 = 0;
}

void func_80186718(void) {
    s32 i;
    void **p = &D_801DFCF8;

    D_801E05B8[0] = 0;
    for (i = 0; i < 2; i++) {
        if (p[i] != 0) {
            free3(p[i]);
            p[i] = 0;
        }
    }
}

void func_8018677C(void) {
    u16 buf[16];
    s32 i;
    u16 t;

    StoreImage2(&D_801DFD00, buf);
    t = buf[15];
    for (i = 15; i > 0; i--) {
        buf[i] = buf[i - 1];
    }
    buf[0] = t;
    LoadImage2(&D_801DFD00, buf);
}

void func_801867E8(Unk_801867E8 *arg0) {
    Unk_801867E8_0 *p = *arg0->unk3C;
    s16 v;

    p->unkC = arg0->unk24;
    v = 0xF0 - arg0->unk24;
    p->unk12 = v;
    if (D_801DFE8A < v) {
        p->unk12 = D_801DFE8A;
    }
}

void func_80186838(Unk_80186838 *arg0) {
    Unk_80186838_0 *p = *arg0->unk3C;
    Unk_801E0368 *q = &D_801E0368;

    p->unkC = D_801DFE88;
    p->unk12 = D_801DFE8A;
    if (arg0->unk22 == 3 || arg0->unk22 == 0xC) {
        p->unk4 = 0;
    }
    q->unk244 = -1;
}

void func_80186884(Unk_80186884 *arg0) {
    Unk_80186884_0 *p = *arg0->unk3C;

    p->unk18 = (arg0->unk24 - 1) / p->unk16;
    p->unk1A = (arg0->unk24 - 1) % p->unk16;
}

s32 func_80186910(s32 *arg0) {
    Unk_801E0710_5C *p = D_801E076C[0];
    Unk_801DFEB8 *q = &D_801DFEB8;
    Unk_801854B8 *e;
    s32 i;

    if (arg0[4] != 4) {
        return 0;
    }
    if (p->unk42 & 0x80) {
        func_801CD688(1);
        func_801A4A68(2, 1);
        func_80183E88(D_80170590, 3, -1, 0, -1, 0, 1);
        return 0;
    }
    for (i = 0; i < 2; i++) {
        e = func_801855C8(((u16)q->unk2 - 1) * 2 + i);
        if (e != NULL) {
            e->unkA = 0;
            switch ((u16)e->unk2) {
            case 1:
                e->unk14 = e->unkC;
                break;
            case 2:
                e->unk18 = e->unkC;
                break;
            case 3:
                e->unk1C = e->unkC;
                break;
            }
            e->unk40 = e->unk14 - p->unk72 * 0x30D4;
            e->unk44 = e->unk18 + p->unk74 * 0x7D00;
            e->unk48 = e->unk1C - p->unk76 * 0x30D4;
            e->unk28 = 0;
        }
    }
    return 1;
}

void func_80186AEC(void) {
    Unk_801E0710_5C *p = D_801E076C[0];
    s32 x;
    s32 z;

    func_801A4A68(2, 0);
    func_801CD688(0);
    x = rsin((p->unk6E << 12) / 360) * 0x1194 >> 12;
    z = rcos((p->unk6E << 12) / 360) * 0x1194 >> 12;
    x += p->unk54 + p->unk72 * 0x30D4;
    z += p->unk5C + p->unk76 * 0x30D4;
    func_80198CFC(2, 0x80, x, p->unk58 - p->unk74 * 0x7D00 - p->unk78, z, p->unk6C, p->unk6E, p->unk70, 2);
}

void func_80186C80(Unk_801DFEB8 *arg0, s16 arg1) {
    Unk_801E0340 *p = D_801E0340;
    Unk_801854B8 *e;
    s16 v;
    s32 i;

    func_801CD688(0);
    for (i = 0; i < 2; i++) {
        e = func_801855C8((arg0->unk2 - 1) * 2 + i);
        if (e == NULL) {
            continue;
        }
        if (arg1 != 0) {
            if (D_801DFE68.unk0 == 0) {
                switch (D_801DFE6A.unk0) {
                case 28:
                    v = i * 0x140 - 0xA0;
                    break;
                case 7:
                    v = i * 0xB4 - 0x5A;
                    break;
                case 15:
                    v = i * 0xF0 - 0x78;
                    break;
                }
            }
            func_80184ECC(e, v, 3, 0);
            arg0->unk6 = 2;
        } else {
            memset(&p[1], 0, 4);
            ((s16 *)&p->unk14)[1] = 0x41;
            ((s16 *)&p->unk18)[0] = arg0->unk0;
            if (D_801DFE68.unk0 == 0) {
                switch (D_801DFE6A.unk0) {
                case 28:
                    strncpy((char *)&p[1], D_801DFD08, 3);
                    ((s16 *)&p->unk18)[1] = 0xB4;
                    v = (e->unkC - e->unk14) / 10;
                    break;
                case 7:
                    strncpy((char *)&p[1], D_801DFD0C, 3);
                    ((s16 *)&p->unk18)[1] = 0x5A;
                    v = (e->unkC - e->unk1C) / 10;
                    break;
                case 15:
                    strncpy((char *)&p[1], D_801DFD10, 3);
                    ((s16 *)&p->unk18)[1] = 0xB4;
                    v = (e->unkC - e->unk14) / 10;
                    break;
                }
            }
            func_80185034(e, v, 3);
            arg0->unk6 = 1;
        }
    }
    func_801A2678(0xB);
}

void func_80186EF8(void) {
    Unk_801DFEB8 *p = &D_801DFEB8;

    if (D_801E6DA0.unkA != 1) {
        return;
    }
    func_801CD6B4();
    if (!(D_801E6DA0.unk4 & 0x1000) && (D_801E6DA0.unk0 & 0x1000)) {
        func_801A2678(0xF);
        D_801DFEB8.unk0++;
        if (D_801DFEBC < D_801DFEB8.unk0) {
            D_801DFEB8.unk0 = 1;
        }
        func_801A4824(2, 1, 8, 0x421);
        if (p->unk2 == D_801DFEB8.unk0) {
            func_801A461C(2, D_801DFEB8.unk0, 0x16BF);
        } else {
            func_801A461C(2, D_801DFEB8.unk0, 0x17FF);
            func_801A461C(2, p->unk2, 0x14BF);
        }
    } else if (!(D_801E6DA0.unk4 & 0x4000) && (D_801E6DA0.unk0 & 0x4000)) {
        Unk_801DFEB8 *q = &D_801DFEB8;

        func_801A2678(0xF);
        D_801DFEB8.unk0--;
        if (D_801DFEB8.unk0 == 0) {
            D_801DFEB8.unk0 = q->unk4;
        }
        func_801A4824(2, 1, 8, 0x421);
        if (q->unk2 == D_801DFEB8.unk0) {
            func_801A461C(2, D_801DFEB8.unk0, 0x16BF);
        } else {
            func_801A461C(2, D_801DFEB8.unk0, 0x17FF);
            func_801A461C(2, q->unk2, 0x14BF);
        }
    } else if (!(D_801E6DA0.unk4 & 0x40) && (D_801E6DA0.unk0 & 0x40)) {
        func_801A2678(8);
        func_80184094();
        func_80186AEC();
    } else if (!(D_801E6DA0.unk4 & 0x20) && (D_801E6DA0.unk0 & 0x20)) {
        if (p->unk2 != p->unk0) {
            func_8018D8B8();
            func_801A2678(0x11);
            func_80184094();
            func_80186C80(p, 0);
        }
    }
}

void func_8018715C(void) {
    Unk_801E0710_5C *p;
    Unk_801DFEB8 *q;
    s32 x;
    s32 y;
    s32 z;

    D_801DFED4 = (s32)func_80186910;
    p = D_801E076C[0];
    func_801A4824(2, 1, 8, 0x421);
    q = &D_801DFEB8;
    if ((u16)q->unk2 == (u16)D_801DFEB8.unk0) {
        func_801A461C(2, (u16)D_801DFEB8.unk0, 0x16BF);
    } else {
        func_801A461C(2, (u16)D_801DFEB8.unk0, 0x17FF);
        func_801A461C(2, (u16)q->unk2, 0x14BF);
    }
    x = p->unk54 + p->unk72 * 0x30D4;
    y = p->unk58 - p->unk74 * 0x7D00 - p->unk78;
    z = p->unk5C + p->unk76 * 0x30D4;
    func_801D06B4();
    func_80198CFC(0, 0, x, y, z, p->unk6C, (s16)(p->unk6E + 0xB4), p->unk70, 2);
}

static inline u16 func_801872D4_inl(s32 a) {
    Unk_801854B8 *e = func_801855C8(((a - 1) * 2) | 1);
    if (e == NULL) {
        return 5;
    }
    return e->unkA;
}

void func_801872D4(void) {
    Unk_801E0710_5C *p = D_801E076C[0];
    Unk_801DFEB8 *q = &D_801DFEB8;
    u16 v;

    switch ((u16)q->unk6) {
    case 0:
        break;
    case 3:
        func_8017A86C(1);
        p->unk42 |= 0x80;
        q->unk6 = 4;
        break;
    case 4:
        func_801A25B4(0x12);
        func_80186C80(q, 1);
        D_801E6DB4[0] = 0;
        break;
    default:
        v = func_801872D4_inl((u16)q->unk2);
        if ((u16)v == 1 && (u16)q->unk6 == 2) {
            q->unk6 = 0;
            func_801CD688(1);
            func_80183E88(D_80170590, 3, -1, 0, -1, 0, (u16)v);
        }
        if ((u16)v == 0 && (u16)q->unk6 == 1) {
            q->unk2 = q->unk0;
            func_801A4824(2, 1, 8, 0x421);
            if ((u16)q->unk2 == (u16)q->unk0) {
                func_801A461C(2, (u16)q->unk0, 0x16BF);
            } else {
                func_801A461C(2, (u16)q->unk0, 0x17FF);
                func_801A461C(2, (u16)q->unk2, 0x14BF);
            }
            q->unk6 = 3;
            func_801A2678(0x12);
        }
        break;
    }
}

void func_8018748C(void) {
    s32 buf[6];
    s16 done = 0;

    func_8018715C();
    do {
        switch (func_801CC378(buf)) {
        case 4:
            func_80189970(0);
            continue;
        case 0:
            func_801872D4();
            func_80186EF8();
            break;
        case 0x100:
            done = func_8018970C(buf);
            continue;
        default:
            func_801CC734(buf);
            continue;
        }
        func_8018C2FC(1, 1, 1);
    } while (done == 0);
    func_801D06C4();
    D_801DFED4 = 0;
}

void func_80187560(s16 arg0) {
    Unk_801DFEB8 *p = &D_801DFEB8;
    Unk_801DFE68 *q;

    p->unk0 = arg0;
    p->unk2 = arg0;
    p->unk6 = 0;
    if (D_801DFE68.unk0 == 0) {
        q = &D_801DFE68;
        switch (q->unk2) {
        case 28:
            p->unk4 = 3;
            break;
        case 7:
            p->unk4 = 4;
            break;
        case 15:
            p->unk4 = 3;
            break;
        }
    }
}

s32 func_801875E4(s16 arg0) {
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0768 *p = g->unk58;
    Unk_801E0710_5C *q = g->unk5C;
    void *r;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (p->unk4[i] == arg0) {
            func_8018E344(arg0 + 0x400);
            p->unk0--;
            p->unk4[i] = -1;
            p->unk8[i] = 0;
            if (p->unk2 == 0 && i == 0) {
                p->unk2 = 1;
            } else if (p->unk2 == 1 && i == 1) {
                p->unk2 = 0;
            } else {
                return 1;
            }
            r = func_8018E56C(p->unk4[p->unk2] + 0x400);
            p->unk4C = (s32)r;
            if (r != 0) {
                func_8018D2DC(r, q->unkA0, 1, 0);
            }
            func_80187978(p->unk2);
            return 1;
        }
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170544);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170560);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_8017056C);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170590);

void func_80187718(s16 arg0, s16 arg1) {
    Unk_801E0768 *p = D_801E0768[0];
    Unk_80188FEC *e;
    s16 id;
    s16 v;

    if (arg1 != 0) {
        func_801A4A68(0x401, arg0);
        func_801A4A68(0x402, arg0);
    }
    if (arg0 != 0) {
        id = p->unk4[p->unk2];
        e = func_80188FEC(id);
        if (e != NULL) {
            v = (s16)e->unk30 >> 3;
            func_801A4824(0x401, 0x10, v + 0x10, 0x67FF);
            func_801A4824(0x401, v + 0x11, 0x2F, 0x3D40);
            v = e->unk52 >> 3;
            func_801A4824(0x401, 0x40, v + 0x40, 0x67FF);
            func_801A4824(0x401, v + 0x41, 0x5F, 0x3D40);
            v = e->unk50 / 3 - 1;
            if (v < 0) {
                v = 0;
            }
            func_801A4824(0x401, 0x70, v + 0x70, 0x67FF);
            func_801A4824(0x401, v + 0x71, 0x8F, 0x3D40);
            func_801A4824(0x401, 0xC, 0xE, 0xD20);
            switch (e->unk2) {
            case 0:
                func_801A461C(0x401, 0xC, 0xD3F);
                break;
            case 1:
            case 2:
                func_801A461C(0x401, 0xD, 0xD3F);
                break;
            case 3:
                func_801A461C(0x401, 0xE, 0xD3F);
                break;
            }
            func_801A4BC8(0x402, (s16)(id / 9), (s16)(id % 9));
            if (arg1 != 0) {
                /* "  8武器1を方向キー上下で,  選んで下さい,    武装 3○ 1武装解除 4×" */
                func_80183E88("  8\225\220\212\3551\202\360\225\373\214\374\203L\201[\217\343\211\272\202\305,  \221I\202\361\202\305\211\272\202\263\202\242,    \225\220\221\225 3\201\233 1\225\220\221\225\211\360\217\234 4\201~", 3, -1, 0, -1, 0, 1);
            }
        }
    } else {
        func_80184094();
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170618);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170648);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170678);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801706BC);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170700);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_8017073C);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170778);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801707A4);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801707B8);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801707CC);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801707E0);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801707F4);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_8017080C);

void func_80187978(s32 arg0) {
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0768 *p = g->unk58;
    Unk_80188FEC *e = func_80188FEC(p->unk4[arg0]);
    s32 a, b, c, v;
    s32 val;

    if (e == NULL) {
        return;
    }
    a = 0x2000;
    if (e->unk28 != 0 && g->unk2 < (s16)e->unk30) {
        a = (g->unk2 << 13) / (s16)e->unk30;
    }
    b = 0x1000;
    if (e->unk34 != 0) {
        switch (e->unk38) {
        case 0:
            val = g->unkC;
            break;
        case 1:
            val = g->unkE;
            break;
        case 2:
            val = g->unk10;
            break;
        case 3:
            val = g->unk12;
            break;
        }
        if (val < e->unk3C) {
            b = (val << 12) / e->unk3C;
        }
    }
    c = 0x1000;
    if (e->unk40 != 0) {
        switch (e->unk2) {
        case 0:
            val = g->unk14;
            break;
        case 1:
            val = g->unk18;
            break;
        case 2:
            val = g->unk1C;
            break;
        case 3:
            val = g->unk20;
            break;
        case 4:
            val = g->unk24;
            break;
        }
        if (val < e->unk48) {
            c = (val << 12) / e->unk48;
        }
    }
    val = (e->unk50 * (a + b + c)) >> 14;
    v = (val < 20) ? 20 : (val > 100) ? 100 : val;
    p->unk8[arg0] = v;
    g->unk48 = 1;
}

void func_80187BE4(s16 arg0, s16 arg1) {
    Unk_801E0768 *p = D_801E0768[0];
    Unk_801E0710 *g;
    Unk_801E0768 *e;
    Unk_801E0710_5C *q;
    void *r;
    s32 i;
    s32 j;

    p->unk0 = 0;
    for (j = 0; j < 2; j++) {
        if (p->unk4[j] >= 0) {
            p->unk0++;
        }
    }
    if (arg0 != 0) {
        func_801875E4(arg1);
        p->unkC[arg1]++;
    } else {
        g = &D_801E0710;
        e = g->unk58;
        q = g->unk5C;
        for (i = 0; i < 2; i++) {
            if (e->unk4[i] < 0) {
                e->unk4[i] = arg1;
                r = func_8018E56C(arg1 + 0x400);
                if (r != 0) {
                    func_8018D2DC(r, q->unkA0, 1, 0);
                }
                func_80187978(i);
                break;
            }
        }
        p->unkC[arg1]--;
    }
    p->unk0 = 0;
}

s32 func_80187D24(s16 arg0) {
    Unk_801E0768 *p = D_801E0768[0];
    s32 i;
    s16 n;

    switch (arg0) {
    case 0:
        for (i = 0, n = 0; i < 8; i++) {
            if ((u16)p->unk32[i] < 100) {
                n++;
            }
        }
        if (n >= 5) {
            break;
        }
        for (i = 0; i < 8; i++) {
            if (p->unk32[i] < 0) {
                return 1;
            }
        }
        break;
    case 1:
    case 3:
        for (i = 0; i < 8; i++) {
            if (p->unk32[i] < 0) {
                return 1;
            }
        }
        return 0;
    case 4:
        for (i = 0; i < 2; i++) {
            if (p->unk4[i] < 0) {
                return 1;
            }
        }
        return 0;
    case 2:
        return 1;
    }
    return 0;
}

static inline void func_80187E38_inl(s32 d) {
    Unk_801E0768 *g;
    s32 k;
    void *r;
    s32 id;
    g = D_801E0768[0];
    if (g->unk0 != 2) {
        return;
    }
    func_801A2678(0xF);
    k = g->unk2;
    k += d;
    if (k >= 2) {
        k = 0;
    } else if (k < 0) {
        k = 1;
    }
    g->unk2 = k;
    id = g->unk4[k];
    r = func_8018E56C(id + 0x400);
    func_80187718(1, 0);
    func_80187978(k);
    if (r == NULL) {
        return;
    }
    g->unk4C = (s32)r;
    func_8018DA2C(r, 5, 0);
}

s32 func_80187E38(Unk_801E0710 *arg0) {
    Unk_801E0368 *q = &D_801E0368;
    Unk_801E0710_5C *b = arg0->unk5C;
    Unk_801E0768 *a = arg0->unk58;

    if (b->unk42 & 0x8000) {
        if (a->unk44 == 0) {
            b->unk42 &= 0x7FFF;
            a->unk48 = 0;
        }
        if ((u16)a->unk48 != 2) {
            return 1;
        }
        if (!(D_801E6DA0.unk4 & 0x1000) && (D_801E6DA0.unk0 & 0x1000)) {
            func_80187E38_inl(1);
        } else if (!(D_801E6DA0.unk4 & 0x4000) && (D_801E6DA0.unk0 & 0x4000)) {
            func_80187E38_inl(-1);
        } else if (!(D_801E6DA0.unk4 & 0x40) && (D_801E6DA0.unk0 & 0x40)) {
            func_801A2678(8);
            func_80187718(0, 1);
            a->unk48 = 1;
            func_8018DA2C((void *)a->unk4C, 6, 0);
        } else if ((!(D_801E6DA0.unk4 & 0x100) && (D_801E6DA0.unk0 & 0x100)) ||
                   (!(D_801E6DA0.unk4 & 0x20) && (D_801E6DA0.unk0 & 0x20))) {
            func_801A2678(0x11);
            func_80187718(0, 1);
            b->unk42 &= 0x7FFF;
            a->unk48 = 3;
            func_8018DA2C((void *)a->unk4C, 0, 0);
        }
        return 1;
    }
    if ((u16)a->unk48 == 2 && a->unk44 == 0) {
        a->unk48 = 0;
    }
    if (!(D_801E6DA0.unk4 & 0x100) && (D_801E6DA0.unk0 & 0x100)) {
        if (q->unk24C != 0) {
            return 0;
        }
        if ((u16)a->unk48 == 0) {
            func_801A2678(0x13);
            b->unk42 |= 0x8000;
            func_80187718(1, 1);
            a->unk44 = 1;
            func_8018DA2C((void *)a->unk4C, 4, 0);
        } else if ((u16)a->unk48 == 3) {
            func_801A2678(0x13);
            b->unk42 |= 0x8000;
            func_80187718(1, 1);
            a->unk48 = 2;
        }
    } else if ((!(D_801E6DA0.unk4 & 2) && (D_801E6DA0.unk0 & 2)) ||
               (!(D_801E6DA0.unk4 & 1) && (D_801E6DA0.unk0 & 1))) {
        if (a->unk46 != 0) {
            if ((u16)a->unk48 == 3) {
                a->unk48 = 4;
                func_8018DA2C((void *)a->unk4C, 1, 0);
            } else if ((u16)a->unk48 == 5) {
                a->unk48 = 6;
                func_8018DA2C((void *)a->unk4C, 2, 0);
            }
        }
    }
    return 0;
}

s16 func_801882AC(Unk_801E0710 *a, s16 b, s16 c, s16 d, s16 e) {
    char buf[0x80];
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801E0368 *q = &D_801E0368;
    Unk_801891A4 *ent;
    Unk_801891A4 *e2;
    s32 n;
    s32 i;
    s32 j;
    s16 ret;
    s16 flag;
    s16 kind;
    s16 v;
    s32 r;

    n = p->unk2C;
    e2 = (Unk_801891A4 *)p->unk48;
    if (n != 0) {
        if (c < 0) {
            ent = NULL;
            goto done;
        }
        for (j = 0; j < n; j++, e2++) {
            if (e2->unk0 == c) {
                ent = e2;
                goto done;
            }
        }
    }
    ent = NULL;
done:
    if (ent == NULL) {
        return -1;
    }
    memset(buf, 0, 0x80);
    ret = 0;
    kind = 3;
    flag = 0;
    if ((u16)(c - 0x27) < 4 || (u16)(c - 0x2F) < 4) {
        flag = 1;
    }
    switch (ent->unk2) {
    case 0:
        v = ent->unk26;
        if (v < 0) {
            if (a->unk2C != 0) {
                func_80199E1C(-v, 0);
                if (flag) {
                    /* " 8%s, 1を飲んで、8Ｖｉｔａｌｉｔｙ1が, 回復した" */
                    sprintf(buf, D_80170618, ent->unk4);
                } else {
                    /* " 8%s, 1を食べて、8Ｖｉｔａｌｉｔｙ1が, 回復した" */
                    sprintf(buf, D_80170648, ent->unk4);
                }
            } else {
                kind = 4;
                func_80199E1C(v, 0);
                func_80199D68(3, 2, ent->unk26);
                if (flag) {
                    /* " 8%s, 1を飲んで、8Ｖｉｔａｌｉｔｙ1が, 減少し猛烈な腹痛が襲ってきた" */
                    sprintf(buf, D_80170678, ent->unk4);
                } else {
                    /* " 8%s, 1を食べて、8Ｖｉｔａｌｉｔｙ1が, 減少し猛烈な腹痛が襲ってきた" */
                    sprintf(buf, D_801706BC, ent->unk4);
                }
            }
        } else if (d != 0) {
            kind = 4;
            func_80199E1C(-(v / 2), 0);
            func_80199D68(3, 2, -ent->unk26);
            if (flag) {
                /* " 1飲み過ぎ、ハラをこわして, 8Ｖｉｔａｌｉｔｙ1が減少した" */
                strncpy(buf, D_80170700, 0x38);
            } else {
                /* " 1食べ過ぎ、ハラをこわして, 8Ｖｉｔａｌｉｔｙ1が減少した" */
                strncpy(buf, D_8017073C, 0x38);
            }
        } else {
            func_80199E1C(v, 0);
            if (flag) {
                /* " 8%s, 1を飲んで、8Ｖｉｔａｌｉｔｙ1が, 回復した" */
                sprintf(buf, D_80170618, ent->unk4);
            } else {
                /* " 8%s, 1を食べて、8Ｖｉｔａｌｉｔｙ1が, 回復した" */
                sprintf(buf, D_80170648, ent->unk4);
            }
            if (a->unk0 == 0xFF && d == 0) {
                ret = 1;
                func_801831EC(b, 1, buf, kind, 2);
                memset(buf, 0, 0x80);
                /* " 8Ｖｉｔａｌｉｔｙ1がフルの, 状態に戻った" */
                strncpy(buf, D_80170778, 0x29);
            }
        }
        func_801831EC(b, 1, buf, kind, 2);
        break;
    case 3:
        r = func_80199FA0();
        if ((s16)r != 0) {
            for (i = 0; i < 5; i++) {
                (q->unk0 + 0x5A)[i] -= ent->unk26;
                if ((s16)(q->unk0 + 0x5A)[i] < 0) {
                    (q->unk0 + 0x5A)[i] = 0;
                }
            }
            func_80189DE8(a);
        }
        memset(buf, 0, 0x80);
        switch (ent->unk26) {
        case 60:
            if ((s16)r != 0) {
                /* " 傷が多少回復した" */
                strncpy(buf, D_801707A4, 0x11);
            } else {
                /* " 全身が軽くなった" */
                strncpy(buf, D_801707B8, 0x11);
            }
            break;
        case 180:
            if ((s16)r != 0) {
                /* " 傷がかなり回復した" */
                strncpy(buf, D_801707CC, 0x13);
            } else {
                /* " 全身が軽くなった" */
                strncpy(buf, D_801707B8, 0x11);
            }
            break;
        case 360:
            if ((s16)r != 0) {
                /* " 傷が完全に回復した" */
                strncpy(buf, D_801707E0, 0x13);
            } else {
                /* " 全身がとても軽くなった" */
                strncpy(buf, D_801707F4, 0x17);
            }
            break;
        }
        func_8018ABE8(ent->unk26, 1);
        func_80183E88(buf, 1, -1, 0, -1, 0, kind);
        break;
    case 1:
        break;
    default:
        return -1;
    }
    if (e != 0) {
        func_80184094();
    }
    return ret;
}

void func_80188760(void) {
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0768 *p;
    s16 id;
    s16 r;
    s32 i;

    if (D_801DFEC0 >= 0) {
        id = D_801E02C8[D_801DFEC0];
        r = func_801882AC(g, D_801E0340[0].unk0[0], id, D_801DFEC6, 1);
        if (r >= 0) {
            if (r != 0) {
                D_801DFEC6 = 1;
            }
            p = g->unk58;
            if (p->unk30 != 0) {
                for (i = 0; i < 8; i++) {
                    if (p->unk32[i] == id) {
                        p->unk32[i] = -1;
                        p->unk30--;
                        return;
                    }
                }
            }
        }
    }
}

s16 func_8018884C(Unk_801E0710 *arg0, s16 arg1, s16 arg2) {
    Unk_801E0768 *p = arg0->unk58;
    s32 i;
    s32 n;

    if (arg2 != 0) {
        func_801A2678(0x13);
        D_801DFEC0 = -1;
        D_801DFEC4 = 0;
        D_801DFEC2 = arg1;
        D_801DFEC6 = 0;
        if (arg0->unk0 == 0xFF) {
            D_801DFEC6 = 1;
        }
        for (i = 0; i < 8; i++) {
            D_801E02C8[i] = -1;
        }
        for (i = 0, n = 0; i < 8; i++) {
            if (p->unk32[i] >= 0) {
                D_801E02C8[n++] = p->unk32[i];
            }
        }
        return func_8018D078(1, 0x40B, -2, p->unk30, 6, D_801E02C8, 4, 0x2969, 0x2BFF);
    }
    func_801A2678(D_801DFEC0 < 0 ? 8 : 0x11);
    return func_8018D1A0();
}

s16 func_8018898C(Unk_801E0710 *arg0, s16 arg1) {
    s16 n = arg1;
    Unk_801E0710_5C *q = arg0->unk5C;
    Unk_801E0368 *g = &D_801E0368;
    Unk_801E0768 *p = arg0->unk58;

    if (q->unk42 & 0x4000) {
        if (func_8018D1F0() == 1) {
            if (D_801DFEC4 == 0) {
                D_801DFEC4 = 1;
                /* "  8アイテム1を方向キー上下で,  選んで下さい,     決定 3○1 やめる4 ×" */
                func_80183E88(D_8017080C, 3, -1, 0, -1, 0, 1);
            }
            if (!(D_801E6DA0.unk4 & 0x20) && (D_801E6DA0.unk0 & 0x20)) {
                if (D_801DFEC0 < 0) {
                    D_801DFEC0 = 0;
                }
                func_8018884C(arg0, n, 0);
            } else if (!(D_801E6DA0.unk4 & 0x40) && (D_801E6DA0.unk0 & 0x40)) {
                if (D_801DFEC0 >= 0) {
                    D_801DFEC0 = -1;
                }
                func_8018884C(arg0, n, 0);
            } else if (!(D_801E6DA0.unk4 & 0x1000) && (D_801E6DA0.unk0 & 0x1000)) {
                D_801DFEC0 = func_8018CEA0(1);
            } else if (!(D_801E6DA0.unk4 & 0x4000) && (D_801E6DA0.unk0 & 0x4000)) {
                D_801DFEC0 = func_8018CEA0(0);
            }
        }
        return 1;
    }
    if (p->unk30 == 0) {
        return 0;
    }
    if (func_8019A6A4() != 0) {
        return 0;
    }
    if (!(D_801E6DA0.unk4 & 0x800) && (D_801E6DA0.unk0 & 0x800)) {
        if (g->unk24C != 0) {
            return 0;
        }
        if (func_8018884C(arg0, n, 1) != 0) {
            q->unk42 |= 0x4000;
        }
    }
    if (D_801DFEC4 != 0 && func_8018D1F0() == 0) {
        D_801DFEC4 = 0;
        func_80184094();
    }
    return 0;
}

s32 func_80188C24(s16 arg0, s16 arg1) {
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0768 *p = g->unk58;
    Unk_801E0710_5C *q = g->unk5C;
    void *r;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (p->unk4[i] < 0) {
            p->unk4[i] = arg0;
            r = func_8018E56C(arg0 + 0x400);
            if (r != 0) {
                func_8018D2DC(r, q->unkA0, 1, 0);
            }
            func_80187978(i);
            return 1;
        }
    }
    if (arg1 != 0) {
        p->unkC[arg0]++;
    }
    return 0;
}

void func_80188CE4(void) {
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0768 *p = g->unk58;
    Unk_801E0710_5C *q = g->unk5C;
    Unk_801E0368 *s = &D_801E0368;
    void *r;
    s32 i;
    u16 id;

    p->unk46 = 1;
    func_8019290C();
    s->unk0[0x3C] = 2;
    for (i = 0; i < 2; i++) {
        if (p->unk4[i] >= 0) {
            id = p->unk4[i] + 0x400;
            s->unk0[0x3C]--;
            r = func_8018E56C(id);
            if (r != 0) {
                func_8018D2DC(r, q->unkA0, 1, 0);
                if (p->unk2 == i) {
                    p->unk4C = (s32)r;
                }
            }
            func_80187978(i);
        }
    }
    func_801A80CC(3, 7, 1);
    func_801A8198(3, 7, 1);
}

void func_80188DE8(void) {
    Unk_801E0768 *p = D_801E0768[0];

    p->unk44 = 0;
    p->unk48 = 0;
    p->unk0 = 0;
    p->unk4C = 0;
    p->unk46 = 0;
}

void func_80188E0C(s32 arg0) {
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0768 *p = g->unk58;
    Unk_801E0710_5C *q = g->unk5C;
    Unk_80188FEC *e = func_80188FEC(p->unk4[p->unk2]);

    if (e != NULL && e->unk4C == arg0) {
        if (g->unk4C != 0) {
            if (!(q->unk42 & 0x400)) {
                q->unk42 |= 0x400;
            }
        }
        func_80199A94(e->unk0, 1);
    }
}

s32 func_80188EB8(s16 arg0, s16 *arg1, s16 *arg2) {
    Unk_801E0768 *p = D_801E0768[0];
    s32 i;
    s32 n;
    s32 m;

    for (i = 0, n = 0; i < 2; i++) {
        if (p->unk4[i] >= 0) {
            if (arg0 != 0) {
                arg2[n] = p->unk4[i];
            }
            n++;
        }
    }
    for (i = 0, m = 0; i < 0x12; i++) {
        if (p->unkC[i] != 0) {
            if (arg0 == 0) {
                arg2[m] = i;
            }
            m++;
        }
    }
    if (arg0 != 0) {
        if (n != 2) {
            return 0;
        }
        *arg1 = n;
        return 1;
    }
    *arg1 = m;
    if (n < 2 && m != 0) {
        return 1;
    }
    return 0;
}

void func_80188F98(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    if (p->unk30 != 0) {
        if (p->unk58 != NULL) {
            free3(p->unk58);
        }
        p->unk30 = 0;
        p->unk58 = NULL;
    }
}

Unk_80188FEC *func_80188FEC(s16 arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    s32 n = p->unk30;
    Unk_80188FEC *e = p->unk58;
    s32 i;
    if (n == 0 || arg0 < 0) {
        return NULL;
    }
    for (i = 0; i < p->unk30; i++, e++) {
        if (e->unk0 == arg0) {
            return e;
        }
    }
    return NULL;
}

s32 func_80189054(s16 arg0, s16 arg1) {
    Unk_801E0768 *p = D_801E0768[0];
    s32 i;

    if (arg1 == 2) {
        p->unk42 = arg0 - 0x64;
        return 1;
    }
    for (i = 0; i < 8; i++) {
        if (p->unk32[i] < 0) {
            p->unk32[i] = arg0;
            p->unk30++;
            return 1;
        }
    }
    return 0;
}

s32 func_801890C4(s16 arg0, s16 arg1) {
    Unk_801E0768 *p = D_801E0768[0];
    s32 i;

    if (arg1 == 2) {
        p->unk42 = 0xF;
        return 1;
    }
    if (p->unk30 == 0) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (p->unk32[i] == arg0) {
            p->unk32[i] = -1;
            p->unk30--;
            return 1;
        }
    }
    return 0;
}

void func_80189150(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    if (p->unk2C != 0) {
        if (p->unk48 != 0) {
            free3((void *)p->unk48);
        }
        p->unk2C = 0;
        p->unk48 = 0;
    }
}

Unk_801891A4 *func_801891A4(s16 arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    s32 n = p->unk2C;
    Unk_801891A4 *e = (Unk_801891A4 *)p->unk48;
    s32 i;
    if (n == 0 || arg0 < 0) {
        return NULL;
    }
    for (i = 0; i < p->unk2C; i++, e++) {
        if (e->unk0 == arg0) {
            return e;
        }
    }
    return NULL;
}
