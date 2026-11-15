#include "common.h"

typedef struct Unk_8017D0E0 {
    s32 unk0;
    struct Unk_8017D0E0 *unk4;
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
    } *unk8;
} Unk_8017D0E0;
typedef struct {
    Unk_8017D0E0 *unk0;
    Unk_8017D0E0 *unk4;
    Unk_8017D0E0 *unk8;
    s32 unkC;
} Unk_801DFE5C;
s16 func_801CD000(Unk_801DFE5C *arg0);
Unk_801DFE5C *D_801DFE5C;
void func_801CCBF4(Unk_801DFE5C *arg0, s32 arg1);
void func_801CCCF4(Unk_801DFE5C *arg0, s32 arg1);
void func_801D3650(void);
s16 D_801DFC80;
extern s16 D_801E71C8;
typedef struct {
    u8 pad0[0x24E];
    s16 unk24E;
    s16 unk250;
    s16 unk252;
} Unk_801E0368;
u8 D_801DFC8C;
u8 D_801DFC8D[1];
u8 D_801DFC8E;
extern Unk_801E0368 D_801E0368;
typedef struct {
    u8 pad0[0xC];
    s32 unkC;
} Unk_8017E504;
s16 D_801DFE64;
void func_8017A3E4(void);
void func_8017E25C(void);
void func_8018748C(void);
u16 D_801DFE60;
void func_80184160(void);
void func_801A4A68(s32 arg0, s32 arg1);
typedef struct {
    u8 pad0[0x6];
    s16 unk6;
    u16 unk8;
} Unk_80184100;
void func_801A461C(s32 arg0, s32 arg1, s32 arg2);
void func_801A2678(s32 arg0);
typedef struct {
    u16 unk0;
    u16 unk2;
} Unk_801DFCAC;
Unk_801DFCAC **D_801DFCAC;
s16 D_801DFCB0;
void func_801749E8(Unk_801DFCAC **arg0);
s16 D_801DFE7A;
extern s16 D_801E6DB4[];
typedef struct {
    u8 pad0[0x42];
    u16 unk42;
} Unk_801E076C;
extern s32 D_801E05B0[];
extern Unk_801E076C *D_801E076C[];

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80179848);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80179C50);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80179E50);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170250);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170270);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170290);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_801702B0);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_801702C8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A108);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A3E4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A534);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A6E8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A86C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017AAB4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017AC88);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017AF18);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017B1E8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017B3E8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017B7CC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017BBB0);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017BD24);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017BF50);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017C234);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017C9F8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017CAC8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017CB98);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017CCE4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017CDA4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017CF10);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017CFE4);

void func_8017D0E0(void) {
    Unk_801DFE5C *p = D_801DFE5C;

    if (p->unkC != 0) {
        p->unk8 = p->unk0;
        while (1) {
            if (p->unk8->unk8 != NULL && p->unk8->unk8->unk0 != 0) {
                p->unk8->unk8->unk4 = 0;
            }
            if (func_801CD000(p) != 0) {
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    }
}

void func_8017D170(s32 arg0) {
    if (D_801DFE5C->unkC == 0) {
        func_801CCBF4(D_801DFE5C, arg0);
    } else {
        D_801DFE5C->unk8 = D_801DFE5C->unk4;
        func_801CCCF4(D_801DFE5C, arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017D1BC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017D2B8);

void func_8017D3F0(void) {
    D_801DFC80 = 0;
    func_801D3650();
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017D414);

s32 func_8017D564(void) {
    return D_801E71C8 == 0;
}

void func_8017D574(u32 arg0) {
    s32 t = (arg0 >> 16) & 0xFF;

    D_801DFC8C = t;
    if (t != 0x80) {
        return;
    }
    D_801DFC8D[0] = arg0 >> 8;
    D_801DFC8E = arg0;
    D_801E0368.unk252 = 0;
    D_801E0368.unk250 = 0;
    switch (D_801DFC8D[0]) {
    case 1:
        D_801E0368.unk252 = 1;
        break;
    case 2:
        D_801E0368.unk250 = 1;
        break;
    case 3:
        D_801E0368.unk252 = 1;
        D_801E0368.unk250 = 1;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017D604);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017DAE8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017DD70);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017DFA4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017E25C);

s32 func_8017E504(Unk_8017E504 *arg0) {
    s32 v = arg0->unkC;

    if (v == 0xF0233C) {
        D_801DFE64 = 5;
    } else if (v == 0xF02350) {
        D_801DFE64 = 6;
    } else if (v == 0xF0235A) {
        D_801DFE64 = 7;
    }
    return 0;
}

void func_8017E544(void) {
    D_801DFE60 = 0;
    func_8017A3E4();
    while (1) {
        func_8017E25C();
        if (D_801DFE60 != 1) {
            break;
        }
        func_8018748C();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017E594);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017E99C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017EBF8);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170430);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017EE2C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017EFEC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017F6F4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017FF0C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801802A0);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801803BC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8018073C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801808F0);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80180B04);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80180D8C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8018164C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80181818);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80181A64);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80181C10);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80181D2C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80181F9C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80182300);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80182518);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80182860);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80182D34);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801830A0);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801831EC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801834AC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80183618);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801837F0);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80183CFC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80183E88);

void func_80184094(void) {
    Unk_801E0368 *p = &D_801E0368;

    func_80184160();
    func_801A4A68(0x403, 0);
    func_801A4A68(0x404, 0);
    func_801A4A68(0x40A, 0);
    func_801A4A68(0x40D, 0);
    if (p->unk24E != 0) {
        p->unk24E = 0;
    }
}

void func_80184100(Unk_80184100 *arg0) {
    if (arg0->unk8 & 8) {
        arg0->unk8 &= ~8;
        arg0->unk6 = 1;
        func_801A4A68(0x40A, 0);
        func_801A461C(0x40A, 3, 0x14BF);
        func_801A2678(0x11);
    }
}

void func_80184160(void) {
    Unk_801DFCAC *p;

    if (D_801DFCAC != NULL) {
        p = *D_801DFCAC;
        if (p->unk0 == 5 && (u16)(p->unk2 - 3) < 2) {
            p->unk2 = 0;
        }
        D_801DFCAC = NULL;
    }
    if (D_801DFCB0 >= 0) {
        D_801DFCB0 = -1;
    }
}

void func_801841C4(void) {
    D_801DFE7A -= D_801E6DB4[0];
    if (D_801DFE7A > 0) {
        (*D_801DFCAC)->unk2 = 4;
    } else {
        D_801DFE7A = 0;
        (*D_801DFCAC)->unk2 = 3;
    }
    func_801749E8(D_801DFCAC);
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184230);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184338);

void func_80184408(void) {
    s32 v = -1;
    D_801DFCB0 = v;
    D_801E076C[0]->unk42 &= 0xFEFF;
    D_801E05B0[0] = v;
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184434);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801844D4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184698);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184814);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184928);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184A3C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184B50);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184C6C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184ECC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80185034);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8018519C);
