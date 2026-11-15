#include "common.h"

typedef struct { u16 unk0; s16 unk2; s16 *unk4; s16 *unk8; s16 *unkC; } Unk_801E07C0;
extern Unk_801E07C0 D_801E07C0;
typedef struct { s16 unk0; s16 unk2; u8 unk4; u8 unk5; u8 unk6; u8 unk7; } Unk_801DFF68;
Unk_801DFF68 D_801DFF68;
void func_801A0978(s32 arg0, s32 arg1);
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
typedef struct { u16 unk0; u8 unk2[0x2E]; u16 unk30; u8 unk32[0x2E]; } Unk_80188FEC;
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
    u8 unk62[0x1E];
    s16 unk80;
    u8 unk82[0x176];
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

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A0978);

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

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A0EDC);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A14A0);

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

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", func_801A1EC0);

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
