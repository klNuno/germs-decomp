#include "common.h"

typedef struct { u16 unk0; s16 unk2; s16 *unk4; s16 *unk8; s16 *unkC; } Unk_801E07C0;
extern Unk_801E07C0 D_801E07C0;
typedef struct { s16 unk0; s16 unk2; u8 unk4; u8 unk5; u8 unk6; u8 unk7; } Unk_801DFF68;
Unk_801DFF68 D_801DFF68;
void func_801A0978(s16 arg0, s16 arg1);
typedef struct { u16 unk0; u16 unk2; } Unk_801DFE68;
typedef struct { s32 unk0; s32 unk4; s32 unk8; u8 unkC; } Unk_801A20CC;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12[3];
    s16 *unk18;
    s16 *unk1C;
} Unk_801E1058;
extern Unk_801DFE68 D_801DFE68;
extern Unk_801E1058 D_801E1058;
typedef struct { s16 unk0; s16 unk2; } Unk_801A216C;
extern s32 D_801D77E0[];
void func_8018C50C(s32 a, s32 b, s32 c, s16 d, s16 e);
typedef struct { s16 unk0[3]; s16 unk6; s16 unk8[3]; s16 unkE; s16 unk10; } Unk_801E1040;
extern Unk_801E1040 D_801E1040;
typedef struct { u8 unk0[0x18]; void (*unk18)(); s32 unk1C; } Unk_801E2DB0;
extern Unk_801E2DB0 D_801E2DB0[8];
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_801E07D0;
extern Unk_801E07D0 D_801E07D0;
extern Unk_801E07D0 D_801E09F0;
typedef struct { u8 unk0[0x10]; } Unk_801E0D30;
extern Unk_801E0D30 D_801E0D30;
u8 D_801DFF70;
u8 D_801DFF71;
u8 D_801DFF72;
void func_8019AD78();
void func_8019B4FC();
void func_8019BE6C();
void func_8019C78C();
void func_8019D1D0();
void func_8019DABC();
void func_8019E688();
void func_8019F124();
void func_801D1BD4(void);
void func_801D1BAC(u8 arg0, u8 arg1, u8 arg2);
void InitClip(Unk_801E0D30 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
typedef struct {
    u8 unk0[0x17];
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C[0x40];
    u8 unk5C[0x28];
    u32 *unk84;
    s32 unk88;
} Unk_801E6FF0;
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    u8 unkC[8];
    s32 unk14;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
s16 D_801DFF5C;
s32 D_801DFF60;
s32 D_801DFF64;
s16 D_801DFF74;
Unk_801E6FF0 *func_801D1A58(void);
void func_801A4554(Unk_801E6FF0 *arg0);
void func_8018F6E8(s32 arg0);
void func_80176370(s32 arg0);
void func_801A00EC(Unk_801E6FF0 *arg0);
void func_801A7084(Unk_801E6FF0 *arg0);
void func_80185664(Unk_801E6FF0 *arg0);
void func_8018DBA4(Unk_801E6FF0 *arg0, s32 arg1);
void func_801AC30C(Unk_801E6FF0 *arg0);
void func_80179C50(Unk_801E6FF0 *arg0, s32 arg1);
void func_801D1AAC(Unk_801E6FF0 *arg0);
typedef struct {
    u16 unk0;
    u8 unk2[2];
    char unk4[0x2C];
    u16 unk30;
    u8 unk32[0x2E];
} Unk_80188FEC;
typedef struct { u8 unk0[0xE]; s16 unkE; } Unk_801A0820;
Unk_80188FEC *func_80188FEC(s16 arg0);
s32 func_801A216C(Unk_801A216C *arg0, Unk_801A216C *arg1);
void qsort(void *base, s32 nel, s32 width, s32 (*cmp)());
extern s16 D_801E0712[];
extern s16 D_801D7A68[];
typedef struct { s16 unk0; s16 unk2; s32 unk4; void *unk8; } Unk_801A3B5C;
typedef struct { Unk_801A3B5C *unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; } Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8[];
void SsSepSetVol(s16 access_num, s16 seq_num, s16 voll, s16 volr);
void func_8018C2FC(u16 a, s16 b, s16 c);
typedef struct { u8 unk0[0x42]; u16 unk42; } Unk_801E076C;
extern Unk_801E076C *D_801E076C[];
s16 D_801DFF78;
extern char D_801715C4[];
s16 func_8018D1F0(void);
s32 func_8018D1A0(void);
void func_80183E88(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_80184094(void);
typedef struct {
    u8 unk0[0x14];
    s16 unk14;
    u8 unk16[0x4A];
    s16 unk60;
    u8 unk62[0x1A];
    u16 unk7C;
    u8 unk7E[2];
    s16 unk80;
    u8 unk82[0x10];
    u16 unk92;
    u8 unk94[0x164];
    u16 unk1F8;
} Unk_801E0368;
void func_801A0820(Unk_801A0820 *arg0);
extern Unk_801E0368 D_801E0368;
s32 func_8018D078(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i);
extern s16 D_801D79F0[];
extern s16 D_801D79F8[];
extern s16 D_801D7A00[];
extern s16 D_801D7A08[];
extern s16 D_801D7A10[];
extern s16 D_801D7A22[];
extern s16 D_801D7A34[];
extern s16 D_801D7A48[];
extern s16 D_801D7A50[];
extern s16 D_801D7A58[];
extern s16 D_801D7A60[];
extern s16 D_801D7A74[];
extern s16 D_801D7AEC[];
extern s16 D_801D7AF8[];
extern s16 D_801D7B04[];
extern s16 D_801D7B10[];
extern s16 D_801D7B1C[];
extern s16 D_801D7B28[];
extern s16 D_801DFD74[];
typedef struct {
    s16 unk0;
    s16 unk2;
    u8 unk4[0x58];
    Unk_801E076C *unk5C;
} Unk_801E0710;
typedef struct { u16 unk0; u8 unk2[2]; char unk4[0x24]; } Unk_801891A4;
typedef struct { char *unk0; char *unk4; char *unk8; } Unk_801D7B34;
void func_801A0D58(s16 arg0);
extern Unk_801E0710 D_801E0710;
extern Unk_801D7B34 D_801D7B34[];
Unk_801891A4 *func_801891A4(s16 arg0);
void func_801831EC(s16 arg0, s16 arg1, char *arg2, s16 arg3, s32 arg4);
s16 func_801882AC(Unk_801E0710 *a, s16 b, s16 c, s16 d, s16 e);
void func_8018C1B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80199C68(s16 arg0);
void *memset(void *dst, s32 c, u32 n);
int sprintf(char *buf, const char *fmt, ...);
/* best 100.00 % : code 100 %, RODATA MISMATCH only: the target label D_8017103C ("roadmap.c") also holds the 18 dialogue strings 0x80171048..0x801714EC, which the main.data table at 0x801D7AEC points to; one function cannot emit them */
s16 *func_801A44B8(s32 arg0);
void func_801CD54C(s32 a, char *b, char *c, s32 d);
extern s16 D_801D7A92[];
extern s16 D_801D7AB0[];
extern s16 D_801D7ACE[];
extern s16 D_801D7B20[];
extern char *D_801D7B24[];
void func_801A4A68(s32 arg0, s32 arg1);
void func_801A4824(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_801A461C(s32 arg0, s32 arg1, s32 arg2);
void func_801A0B48(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s16 func_8018CEA0(s16 a);
void func_801A2678(s32 arg0);
s16 func_80187D24(s32 arg0);
void func_8018D200(s32 arg0, s16 *arg1);
s16 func_8018D294(s16 arg0);
s16 func_80199CC0(s16 arg0, s32 arg1, s32 arg2);
s16 func_80199D18(s16 arg0, s32 arg1, s32 arg2);
extern s32 (*D_801DFEE4)(Unk_801A20CC *arg0);
extern s32 (*D_801DFEE0)(Unk_801A20CC *arg0);
void func_80185858(u16 arg0, s16 arg1);
s32 func_801A20CC(Unk_801A20CC *arg0);
s32 func_801A211C(Unk_801A20CC *arg0);

void func_8019A5D4(void) {
    Unk_801E07C0 *p = &D_801E07C0;

    D_801E07C0.unk0 = 0;
    p->unk2 = 0;
    p->unk4 = func_801A44B8(0x405);
    p->unk8 = func_801A44B8(0x406);
    p->unkC = func_801A44B8(0x407);
    if (p->unk4 == NULL || p->unk8 == NULL || p->unkC == NULL) {
        func_801CD54C(5, "Road Map Parts not Found", "roadmap.c", 0x20);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8019A5D4", D_80171048);

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

void func_801A02C8(void) {
    Unk_801DFF68 *p;

    D_801E2DB0[0].unk18 = func_8019AD78;
    D_801E2DB0[1].unk18 = func_8019B4FC;
    D_801E2DB0[2].unk18 = func_8019BE6C;
    D_801E2DB0[3].unk18 = func_8019C78C;
    D_801E2DB0[4].unk18 = func_8019D1D0;
    D_801E2DB0[5].unk18 = func_8019DABC;
    D_801E2DB0[6].unk18 = func_8019E688;
    D_801E2DB0[7].unk18 = func_8019F124;
    D_801E09F0.unk0 = 3;
    D_801E07D0.unk0 = 3;
    D_801E09F0.unk4 = 0x140;
    D_801E07D0.unk4 = 0x140;
    D_801E09F0.unk8 = 0xF0;
    D_801E07D0.unk8 = 0xF0;
    D_801E1040.unkE = 0x1000;
    D_801E1040.unk0[0] = 0;
    D_801E1040.unk0[2] = 0;
    D_801E1040.unk6 = 0;
    D_801E1040.unk8[1] = 0;
    D_801E1040.unk8[2] = 3;
    D_801E1040.unk0[1] = 0;
    D_801E1040.unk8[0] = 0;
    D_801E1040.unk10 = 0;
    p = &D_801DFF68;
    D_801DFF68.unk0 = 0;
    p->unk2 = 0;
    func_801D1BD4();
    func_801D1BAC(0, 0, 0);
    p->unk4 = 0;
    p->unk5 = 0;
    p->unk6 = 0;
    D_801DFF70 = 0x60;
    D_801DFF71 = 0x60;
    D_801DFF72 = 0x60;
    InitClip(&D_801E0D30, 0x150, 0x100, 0xE4, 0x6E, 0xFFFF);
}

void func_801A0418(u16 arg0) {
    Unk_801E1040 *p = &D_801E1040;
    Unk_801E6FF0 *e;
    s32 n;

    D_801DFF64 = p->unkE;
    D_801DFF60 = p->unk8[0] * 42 + p->unk8[0] * 2 / 3 + 0x600;
    D_801DFF5C = arg0;
    D_801DFF74 = 0;
    if (D_801E1040.unk0[0] != 0 && p->unk10 == 1) {
        n = 0x3D - p->unk8[0];
        D_801DFF70 = (n * 0x1334 >> 12) - 0x80;
        D_801DFF71 = (n * 0x1334 >> 12) - 0x80;
        D_801DFF72 = (n * 0x2CD >> 10) - 0x80;
        D_801DFF74 = 1;
    } else {
        D_801DFF70 = 0x60;
        D_801DFF71 = 0x60;
        D_801DFF72 = 0x60;
    }
    if (p->unk0[2] != 0) {
        D_801DFF74 += 2;
    }
    if (p->unk6 != 0) {
        D_801DFF74 += 4;
    }
    e = func_801D1A58();
    func_801A4554(e);
    func_8018F6E8((s32)e);
    func_80176370((s32)e);
    func_801A00EC(e);
    func_801A7084(e);
    func_80185664(e);
    func_8018DBA4(e, arg0);
    func_801AC30C(e);
    func_80179C50(e, arg0);
    func_801D1AAC(e);
    if (D_801E6DA0.unkA == 2) {
        D_801E6DA0.unkA = 1;
    }
}

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

void func_801A0820(Unk_801A0820 *arg0) {
    Unk_801A216C tab[12];
    Unk_80188FEC *e;
    s32 i;
    s32 j;
    s32 end;
    s32 start;

    arg0->unkE = D_801E0712[0] / 20;
    if (arg0->unkE > 2) {
        arg0->unkE = 2;
    }
    j = 0;
    for (i = 1; i < 13; i++) {
        if (i != 10) {
            e = func_80188FEC(i);
            if (e != NULL) {
                tab[j].unk0 = i;
                tab[j].unk2 = e->unk30;
            } else {
                tab[j].unk0 = i;
                tab[j].unk2 = 100;
            }
            j++;
        }
    }
    qsort(tab, 11, 4, func_801A216C);
    switch (arg0->unkE) {
    case 1:
        start = 3;
        end = 8;
        break;
    case 2:
        start = 5;
        end = 10;
        break;
    default:
        start = 0;
        end = 5;
        break;
    }
    for (i = start, j = 0; i <= end; i++, j++) {
        D_801D7A68[j] = tab[i].unk0;
    }
}

void func_801A0978(s16 arg0, s16 arg1) {
    Unk_801E1058 *p = &D_801E1058;
    s32 b;
    s16 c;
    s16 d;
    s32 e;
    s16 g;
    s16 h;
    s16 i;

    if (arg0 != 0) {
        D_801DFF78 = 0;
        p->unk2 = 3;
        func_801A4A68(3, 1);
        func_801A4824(3, 4, 6, 0x2969);
        func_801A461C(3, 4, 0x2BFF);
        func_80183E88(D_801D7B24[0], 3, -1, 0, -1, 0, 1);
    } else {
        func_801A4A68(3, 0);
        func_80184094();
        if (arg1 == 0) {
            D_801E1058.unk0 = 0;
            p->unk2 = -1;
        } else {
            if (D_801E1058.unk0 == 0) {
                D_801E1058.unk0 = 1;
            }
            b = 0x40B;
            c = 0x40C;
            e = 6;
            g = 4;
            h = 0x2969;
            i = 0x2BFF;
            p->unk1C = D_801D7B20;
            p->unk2 = 0;
            switch (D_801DFF78) {
            case 0:
                d = 0xE;
                p->unk18 = D_801D7A92;
                break;
            case 1:
                d = 0xF;
                p->unk18 = D_801D7AB0;
                break;
            case 2:
                b = 4;
                c = -1;
                d = 4;
                e = 4;
                p->unk18 = D_801D7ACE;
                break;
            }
            func_8018D078(1, b, c, d, e, p->unk18, g, h, i);
        }
    }
}

void func_801A0B48(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    Unk_801E076C *p = D_801E076C[0];
    s16 r = func_8018D1F0();
    s16 v;

    if (r == 1) {
        if (arg3 == 0) {
            if (arg1 != 0) {
                if (arg0 == 4) {
                    if (arg2 != 0) {
                        /* " 6どうぞ、楽しんで食べてね" */
                        func_80183E88(" 6\202\307\202\244\202\274\201\101\212\171\202\265\202\361\202\305\220\110\202\327\202\304\202\313", 3, -1, 0, -1, 0, r);
                    } else {
                        /* " 2どうぞ、こちらになります" */
                        func_80183E88(" 2\202\307\202\244\202\274\201\101\202\261\202\277\202\347\202\311\202\310\202\350\202\334\202\267", 3, -1, 0, -1, 0, r);
                    }
                } else if (arg0 == 5) {
                    /* " 2早めに食べてくださいね" */
                    func_80183E88(" 2\221\201\202\337\202\311\220\110\202\327\202\304\202\255\202\276\202\263\202\242\202\313", 3, -1, 0, -1, 0, r);
                }
            } else {
                if (arg0 == 4) {
                    if (arg2 != 0) {
                        /* " 6どうぞ、楽しんで食べてね" */
                        func_80183E88(" 6\202\307\202\244\202\274\201\101\212\171\202\265\202\361\202\305\220\110\202\327\202\304\202\313", 3, -1, 0, -1, 0, r);
                    } else {
                        /* " 2どうぞ、こちらになります" */
                        func_80183E88(" 2\202\307\202\244\202\274\201\101\202\261\202\277\202\347\202\311\202\310\202\350\202\334\202\267", 3, -1, 0, -1, 0, r);
                    }
                } else if (arg0 == 5) {
                    /* " 2どうぞ、おいしいですよ" */
                    func_80183E88(" 2\202\307\202\244\202\274\201\101\202\250\202\242\202\265\202\242\202\305\202\267\202\346", 3, -1, 0, -1, 0, r);
                }
            }
        } else if (arg3 == 2) {
            if (arg2 != 0) {
                /* " 6これ以上持てないわよ" */
                func_80183E88(" 6\202\261\202\352\210\310\217\343\216\235\202\304\202\310\202\242\202\355\202\346", 3, -1, 0, -1, 0, 4);
            } else {
                /* " 2これ以上, お持ちになれないようですよ" */
                func_80183E88(" 2\202\261\202\352\210\310\217\343, \202\250\216\235\202\277\202\311\202\310\202\352\202\310\202\242\202\346\202\244\202\305\202\267\202\346", 3, -1, 0, -1, 0, 4);
            }
        } else if (arg3 == r) {
            if (arg0 == 8) {
                v = D_801DFF78;
                if (v == -1) {
                    if (p->unk42 & 0x100) {
                        p->unk42 &= 0xFEFF;
                    }
                    func_80183E88(D_801715C4, 3, -1, 0, v, 0, arg3);
                }
            } else {
                if (p->unk42 & 0x100) {
                    p->unk42 &= 0xFEFF;
                }
                func_80184094();
            }
        }
        func_8018D1A0();
    }
}

void func_801A0D58(s16 arg0) {
    Unk_801A3B5C *q = D_801E02D8[0].unk0;
    Unk_801E1040 *p = &D_801E1040;
    s32 t;
    s32 v;

    if (arg0 != 0) {
        p->unkE = 0x80;
    } else {
        p->unk6 = 1;
        p->unkE = 0x1000;
    }
    while (1) {
        if (arg0 != 0) {
            p->unkE += D_801E6DA0.unk14 * 0x85;
            if (p->unkE >= 0x1000) {
                p->unkE = 0x1000;
                break;
            }
        } else {
            p->unkE -= D_801E6DA0.unk14 * 0x85;
            if (p->unkE <= 0x80) {
                p->unkE = 0x80;
                break;
            }
        }
        if (q != NULL && q->unk2 >= 0) {
            t = p->unkE >> 5;
            if (t < 0x80) {
                v = (s16)t;
                if (t < 0) {
                    v = 0;
                }
            } else {
                v = 0x7F;
            }
            SsSepSetVol(q->unk0, q->unk2, v, v);
        }
        func_8018C2FC(1, 1, 1);
    }
    if (arg0 != 0) {
        p->unk6 = 0;
        p->unkE = 0x1000;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8019A5D4", D_801715C4);

s16 func_801A0EDC(s16 arg0) {
    Unk_801E0710 *q = &D_801E0710;
    Unk_801E1058 *p = &D_801E1058;
    Unk_801E0368 *r = &D_801E0368;
    Unk_801E076C *e = q->unk5C;
    char buf[0x80];
    Unk_801D7B34 *t;
    Unk_80188FEC *a;
    Unk_801891A4 *b;
    char *s;
    s32 i;
    s16 found = 0;
    s16 ret;
    s16 v;
    s32 j;
    s16 m;
    Unk_801E1058 *p2;

    switch (arg0) {
    case 7:
        if (p->unk12[0] >= 0) {
            t = &D_801D7B34[p->unkE];
            a = func_80188FEC(p->unk12[0]);
            if (a != NULL) {
                if ((s16)a->unk30 == q->unk2) {
                    s = t->unk4;
                } else if ((s16)a->unk30 < q->unk2) {
                    s = t->unk8;
                } else {
                    s = t->unk0;
                }
                func_801831EC(1, 1, s, 1, 2);
                memset(buf, 0, 0x80);
                sprintf(buf, " 8%s1, \202\360\216\363\202\257\216\346\202\301\202\275", a->unk4);
                func_801831EC(1, 1, buf, 2, 2);
            }
        }
        break;
    case 8:
        ret = -1;
        if (p->unk4 != 0) {
            if (p->unk12[0] >= 0) {
                b = func_801891A4(p->unk12[0] + 100);
                if (b != NULL) {
                    memset(buf, 0, 0x80);
                    sprintf(buf, " 8%s2\202\314\222n\220\175\202\313", b->unk4);
                    func_801831EC(1, 1, buf, 2, 2);
                    func_80183E88(D_801715C4, 3, -1, 0, -1, 0, 1);
                    if (e->unk42 & 0x100) {
                        e->unk42 &= 0xFEFF;
                    }
                }
            }
        } else if (p->unk12[0] >= 0) {
            ret = p->unk12[0];
            if (D_801DFF78 == 0) {
                ret += 10;
            } else if (D_801DFF78 == 1) {
                ret += 30;
            }
        }
        break;
    case 9:
        if (p->unk12[0] >= 0) {
            b = func_801891A4(p->unk12[0]);
            if (b != NULL) {
                memset(buf, 0, 0x80);
                sprintf(buf, " 8%s1\202\360\221I\221\360\202\265\202\275", b->unk4);
                func_801831EC(1, 1, buf, 2, 1);
                func_801A0D58(0);
                func_801882AC(q, 1, p->unk12[0], 0, 0);
                func_8018C1B0(1, 1, 1, 2);
                func_801A0D58(1);
                func_8018C1B0(1, 1, 1, 2);
                func_80183E88(" 2\202\250\224\346\202\352\227l\202\305\202\265\202\275", 3, -1, 0, -1, 0, 1);
            }
        }
        break;
    default:
        if (p->unk4 != 0) {
            for (i = 0; i < 3; i++) {
                if (p->unk12[i] >= 0) {
                    b = func_801891A4(p->unk12[i]);
                    if (b != NULL) {
                        memset(buf, 0, 0x80);
                        sprintf(buf, " 8%s1, \202\360\216\363\202\257\216\346\202\301\202\275", b->unk4);
                        func_801831EC(1, 1, buf, 2, 2);
                    }
                }
            }
            if (arg0 == 4) {
                if (p->unk6 != 0) {
                    func_80183E88(" 6\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275, \203N\203b\203N\203b\203N", 3, -1, 0, -1, 0, 1);
                } else {
                    func_80183E88(" 2\202\307\202\244\202\340\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275", 3, -1, 0, -1, 0, 1);
                }
            } else if (arg0 == 5) {
                func_80183E88(" 2\202\334\202\275\201A\202\346\202\353\202\265\202\255\202\250\212\350\202\242\202\265\202\334\202\267", 3, -1, 0, -1, 0, 1);
            }
        } else {
            if (q->unk0 == 0xFF && p->unkE == 0) {
                p->unkE = 1;
            }
            for (i = 0; i < 3; i++) {
                if (p->unk12[i] >= 0) {
                    if (!found) {
                        found = 1;
                    }
                    v = func_801882AC(q, 1, p->unk12[i], p->unkE, 0);
                    if (v >= 0) if (v != 0) {
                        p->unkE = 1;
                    }
                }
            }
            if (found) {
                r->unk92++;
            }
            if (arg0 == 4) {
                if (p->unk6 != 0) {
                    func_80183E88(" 6\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275, \203N\203b\203N\203b\203N", 3, -1, 0, -1, 0, 1);
                } else {
                    func_80183E88(" 2\202\307\202\244\202\340\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275", 3, -1, 0, -1, 0, 1);
                }
            } else if (arg0 == 5) {
                func_80183E88(" 2\202\334\202\275\201A\202\346\202\353\202\265\202\255\202\250\212\350\202\242\202\265\202\334\202\267", 3, -1, 0, -1, 0, 1);
            }
        }
        break;
    }
    p2 = &D_801E1058;
    D_801E1058.unk0 = 0;
    p2->unk2 = -1;
    p2->unk4 = 0;
    p2->unk6 = 0;
    p2->unk8 = 0;
    p2->unkA = 0;
    p2->unkC = 0;
    p2->unkE = 0;
    p2->unk10 = 0;
    m = -1;
    for (j = 2; j >= 0; j--) {
        p2->unk12[j] = m;
    }
    p2->unk18 = NULL;
    p2->unk1C = NULL;
    if (arg0 == 3 || arg0 == 6) {
        func_80199C68(2);
    }
    return ret;
}

s16 func_801A14A0(Unk_801E0710 *arg0) {
    Unk_801E1058 *p = &D_801E1058;
    Unk_801DFE68 *q = &D_801DFE68;
    Unk_801E076C *e = arg0->unk5C;
    s16 sel;

    if (D_801E1058.unk0 == 0) {
        return 0;
    }
    sel = func_8018D1F0();
    if (!(D_801E6DA0.unk4 & 0x20) && (D_801E6DA0.unk0 & 0x20)) {
        if (p->unk2 == 3 && sel == 0) {
            func_801A2678(0x11);
            func_801A0978(0, 1);
            return 1;
        } else if (p->unk2 == 0 && sel == 1) {
            func_801A2678(0x11);
            sel = func_8018D294(p->unk10);
            if (p->unk4 != 0) {
                switch (q->unk0) {
                case 7:
                    if (func_80187D24(4) != 0) {
                        if (func_80199D18(sel, 1, 0) != 0) {
                            p->unk12[0] = sel;
                        }
                    } else {
                        func_801A0B48(q->unk0, p->unk4, p->unk6, 2);
                        return 1;
                    }
                    break;
                case 8:
                    p->unk12[0] = sel;
                    func_80199CC0(sel + 100, 2, 1);
                    func_801A0B48(q->unk0, p->unk4, p->unk6, 0);
                    return 1;
                default:
                    if (func_80187D24(0) != 0) {
                        if (func_80199CC0(sel, 0, 1) != 0) {
                            p->unk12[0] = sel;
                        }
                    } else {
                        func_801A0B48(q->unk0, p->unk4, p->unk6, 2);
                        return 1;
                    }
                    break;
                }
            } else {
                p->unk12[0] = sel;
            }
            if (p->unkA != 0) {
                p->unk2 = 1;
                p->unk10 = 0;
                func_80183E88(((char **)p->unk1C)[1], 3, -1, 0, -1, 0, 1);
                func_8018D200(4, p->unk18 + 4);
                return 1;
            }
        } else if (p->unk2 == 1 && sel == 1) {
            func_801A2678(0x11);
            sel = func_8018D294(p->unk10);
            if (p->unk4 != 0) {
                if (func_80187D24(0) != 0) {
                    if (func_80199CC0(sel, 0, 1) != 0) {
                        p->unk12[1] = sel;
                    }
                } else {
                    func_801A0B48(q->unk0, p->unk4, p->unk6, 2);
                    return 1;
                }
            } else {
                p->unk12[1] = sel;
            }
            if (p->unkC != 0) {
                p->unk2 = 2;
                func_80183E88(((char **)p->unk1C)[2], 3, -1, 0, -1, 0, 1);
                return 1;
            }
        } else if (p->unk2 == 2 && sel == 1) {
            func_801A2678(0x11);
            sel = p->unk18[8];
            if (p->unk4 != 0) {
                if (func_80187D24(0) != 0) {
                    if (func_80199CC0(sel, 0, 1) != 0) {
                        p->unk12[2] = sel;
                    }
                } else {
                    func_801A0B48(q->unk0, p->unk4, p->unk6, 2);
                    return 1;
                }
            } else {
                p->unk12[2] = sel;
            }
        } else {
            return 1;
        }
        func_801A0B48(q->unk0, p->unk4, p->unk6, 0);
    } else if (!(D_801E6DA0.unk4 & 0x40) && (D_801E6DA0.unk0 & 0x40)) {
        func_801A2678(8);
        if (p->unk2 == 3 && sel == 0) {
            func_801A0978(0, 0);
            /* " 2話が聞きたくなったら, いつでもおいで" */
            func_801831EC(1, 1, " 2\230b\202\252\225\267\202\253\202\275\202\255\202\310\202\301\202\275\202\347, \202\242\202\302\202\305\202\340\202\250\202\242\202\305", 1, 1);
            if (e->unk42 & 0x100) {
                e->unk42 &= 0xFEFF;
            }
        } else if (p->unk2 == 0 && sel == 1) {
            func_801A0B48(q->unk0, p->unk4, p->unk6, 1);
            return 1;
        } else if (p->unk2 == 1 && sel == 1 && p->unkC != 0) {
            p->unk2 = 2;
            func_80183E88(((char **)p->unk1C)[2], 3, -1, 0, -1, 0, sel);
        } else {
            func_801A0B48(q->unk0, p->unk4, p->unk6, 0);
            return 1;
        }
    } else if (!(D_801E6DA0.unk4 & 0x1000) && (D_801E6DA0.unk0 & 0x1000)) {
        if (sel == 0) {
            if (p->unk2 == 3) {
                func_801A2678(0xF);
                if (--D_801DFF78 < 0) {
                    D_801DFF78 = 2;
                }
                func_801A4824(3, 4, 6, 0x2969);
                func_801A461C(3, D_801DFF78 + 4, 0x2BFF);
            }
        } else if (sel == 1) {
            if (p->unk2 != 2) {
                p->unk10 = func_8018CEA0(1);
            }
        }
    } else if (!(D_801E6DA0.unk4 & 0x4000) && (D_801E6DA0.unk0 & 0x4000)) {
        if (sel == 0) {
            if (p->unk2 == 3) {
                func_801A2678(0xF);
                if (++D_801DFF78 >= 3) {
                    D_801DFF78 = 0;
                }
                func_801A4824(3, 4, 6, 0x2969);
                func_801A461C(3, D_801DFF78 + 4, 0x2BFF);
            }
        } else if (sel == 1) {
            if (p->unk2 != 2) {
                p->unk10 = func_8018CEA0(0);
            }
        }
        return 1;
    }
    return 1;
}

s16 func_801A1AB8(s16 arg0, s32 arg1) {
    Unk_801E076C *e = D_801E076C[0];
    Unk_801E0368 *q = &D_801E0368;
    Unk_801E1058 *p = &D_801E1058;
    s32 j;
    s16 m;
    s16 b;
    s16 c;
    s16 d;
    s16 n;
    s16 g;
    s16 h;
    s16 i;

    if (func_8018D1F0() != 0) {
        return 0;
    }
    D_801E1058.unk0 = 1;
    p->unk2 = 0;
    p->unk6 = 0;
    p->unkA = 0;
    p->unkC = 0;
    p->unkE = 0;
    p->unk10 = 0;
    m = -1;
    for (j = 2; j >= 0; j--) {
        p->unk12[j] = m;
    }
    b = 3;
    c = -1;
    d = 4;
    n = d;
    g = 1;
    h = 0x14E7;
    i = 0x14FF;
    switch (arg0) {
    case 3:
        if (q->unk14 == 2000) {
            p->unk6 = 1;
            p->unk18 = D_801D7A08;
        } else if (q->unk1F8 >= 8 && q->unk1F8 < 10) {
            p->unk18 = D_801D79F0;
        } else if (q->unk1F8 >= 10 && q->unk1F8 < 14) {
            p->unk18 = D_801D79F8;
        } else {
            p->unk18 = D_801D7A00;
        }
        p->unk1C = D_801D7AEC;
        break;
    case 4:
        if (q->unk14 == 1000) {
            p->unk18 = D_801D7A10;
            p->unk1C = D_801D7AF8;
        } else if (q->unk14 == 2000) {
            p->unk6 = 1;
            p->unk18 = D_801D7A22;
            p->unk1C = D_801D7B04;
        } else if (q->unk80 != 0) {
            if (q->unk60 != 0 || !(q->unk1F8 >= 8 && q->unk1F8 < 14)) {
                p->unk18 = D_801D7A10;
                p->unk1C = D_801D7AF8;
            } else {
                p->unk6 = 1;
                p->unk18 = D_801D7A22;
                p->unk1C = D_801D7B04;
            }
        } else {
            if (q->unk60 != 0 || (q->unk1F8 >= 8 && q->unk1F8 < 14)) {
                p->unk18 = D_801D7A10;
                p->unk1C = D_801D7AF8;
            } else {
                p->unk6 = 1;
                p->unk18 = D_801D7A22;
                p->unk1C = D_801D7B04;
            }
        }
        p->unkA = 1;
        p->unkC = 1;
        break;
    case 5:
        p->unk1C = D_801D7B10;
        p->unk18 = D_801D7A34;
        p->unkA = 1;
        p->unkC = 1;
        break;
    case 6:
        p->unk1C = D_801D7AEC;
        if (q->unk14 == 2000) {
            p->unk6 = 1;
            p->unk18 = D_801D7A60;
        } else if (q->unk1F8 >= 11 && q->unk1F8 < 14) {
            p->unk18 = D_801D7A48;
        } else if (q->unk1F8 >= 14 && q->unk1F8 < 17) {
            p->unk18 = D_801D7A50;
        } else {
            p->unk18 = D_801D7A58;
        }
        break;
    case 7:
        func_801A0820((Unk_801A0820 *)p);
        b = 0x40B;
        c = 0x402;
        d = 6;
        n = d;
        g = 4;
        h = 0x2969;
        i = 0x2BFF;
        p->unk4 = 1;
        p->unk1C = D_801D7AEC;
        p->unk18 = D_801D7A68;
        break;
    case 8:
        e->unk42 |= 0x100;
        if (arg1 != 0x300600) {
            goto fail;
        }
        b = 0x40B;
        c = 0x40C;
        d = 0xD;
        n = 6;
        g = 4;
        h = 0x2969;
        i = 0x2BFF;
        D_801DFF78 = -1;
        p->unk1C = D_801D7B1C;
        p->unk4 = 1;
        p->unk18 = D_801D7A74;
        break;
    case 9:
        d = 3;
        n = d;
        p->unk1C = D_801D7B28;
        p->unk18 = D_801DFD74;
        break;
    }
    return func_8018D078(1, b, c, d, n, p->unk18, g, h, i);
fail:
    func_801A0978(1, 0);
    return 1;
}

void func_801A1EC0(s16 arg0) {
    Unk_801E0368 *q = &D_801E0368;
    Unk_801E1058 *p = &D_801E1058;
    s32 i;
    s32 j;

    D_801E1058.unk0 = 0;
    p->unk2 = -1;
    p->unk4 = 0;
    p->unk6 = 0;
    p->unk8 = 0;
    p->unkA = 0;
    p->unkC = 0;
    p->unkE = 0;
    p->unk10 = 0;
    for (j = 0; j < 3; j++) {
        p->unk12[j] = -1;
    }
    p->unk18 = 0;
    p->unk1C = 0;
    q->unk1F8 = q->unk7C;
    switch (arg0) {
    case 8:
    case 9:
        break;
    default:
        for (i = 0; i < 40; i++) {
            if (i < (arg0 - 3) * 10 || i >= (arg0 - 3) * 10 + 10) {
                func_80185858(i, 0);
            }
        }
        break;
    }
    D_801DFEE4 = func_801A20CC;
    D_801DFEE0 = func_801A211C;
}

void func_801A1FD4(s16 arg0, s16 arg1) {
    s32 i = (arg1 - 1) * 3;

    switch (arg0) {
    case 4:
        i += 0x27;
        break;
    case 5:
        i += 0x39;
        break;
    case 6:
        i += 0x57;
        break;
    case 7:
        i += 0x69;
        break;
    }
    func_8018C50C(D_801D77E0[i], 0, D_801D77E0[i + 1], D_801D77E0[i + 2], 1);
}

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
