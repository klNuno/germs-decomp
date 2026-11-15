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
    u8 unk248[6];
    s16 unk24E;
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
typedef struct { u8 unk0[0x16]; s16 unk16; s16 unk18; s16 unk1A; } Unk_80186884_0;
typedef struct { u8 unk0[0x24]; s16 unk24; u8 unk26[0x16]; Unk_80186884_0 **unk3C; } Unk_80186884;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801DFEB8;
typedef struct { u16 unk0; u16 unk2; } Unk_801DFE68;
Unk_801DFEB8 D_801DFEB8;
extern Unk_801DFE68 D_801DFE68;
typedef struct { s16 unk0; u8 unk2[0x2E]; s16 unk30; s16 unk32[8]; s16 unk42; s16 unk44; s16 unk46; s16 unk48; u8 unk4A[2]; s32 unk4C; } Unk_801E0768;
extern Unk_801E0768 *D_801E0768[];
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_80174F54;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s32 unk8; s32 unkC; s32 unk10; s16 unk14; s16 unk16; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; s32 unk3C; s32 unk40; s32 unk44; s32 unk48; } Unk_801762F4;
typedef struct { u16 unk0; s16 unk2; s32 unk4; s16 unk8; u16 unkA; u8 unkC[0xC0]; } Unk_801767D4;
typedef struct { u16 unk0; s16 unk2; s32 unk4[8]; } Unk_80176890;
typedef struct { u16 unk0; u8 unk2[0x19]; u8 unk1B; u8 unk1C[4]; } Unk_8018F590;
typedef struct { u16 unk0; u8 unk2[0x5E]; } Unk_80188FEC;
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14;
    s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34;
    Unk_80174F54 *unk38; Unk_801762F4 *unk3C; Unk_801767D4 *unk40; Unk_80176890 *unk44;
    s32 unk48; s32 unk4C; Unk_8018F590 *unk50; s32 unk54; Unk_80188FEC *unk58;
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
typedef struct { u16 unk0; u8 unk2[0x26]; } Unk_801891A4;

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80185A60);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80185BE0);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80185E38);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80186010);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80186128);

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

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_801862AC);

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

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_8018647C);

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

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80186680);

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

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80186910);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80186AEC);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80186C80);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80186EF8);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_8018715C);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_801872D4);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_8018748C);

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

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_801875E4);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170544);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170560);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_8017056C);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170590);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80187718);

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

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80187978);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80187BE4);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80187D24);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80187E38);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_801882AC);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80188760);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_8018884C);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_8018898C);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80188C24);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80188CE4);

void func_80188DE8(void) {
    Unk_801E0768 *p = D_801E0768[0];

    p->unk44 = 0;
    p->unk48 = 0;
    p->unk0 = 0;
    p->unk4C = 0;
    p->unk46 = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80188E0C);

INCLUDE_ASM("asm/nonmatchings/game/80185A60", func_80188EB8);

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
