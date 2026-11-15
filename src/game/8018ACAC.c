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
typedef struct { u16 unk0[0x70]; u8 unkE0[0x124]; Unk_801E056C unk204[4]; } Unk_801E0368;
extern Unk_801E0368 D_801E0368;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; u16 unkA; u8 unkC[4]; u16 unk10; u8 unk12[6]; s16 unk18; s16 unk1A; s16 *unk1C; } Unk_801E058C;
extern Unk_801E058C D_801E058C;
void func_80185A60(s32 a, u16 b, s32 c);
void func_801A4A68(s32 arg0, s32 arg1);
void func_8018CB70(Unk_801E058C *p, s32 b);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018ACAC);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B11C);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B564);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B69C);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B810);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B924);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018BA48);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018BB00);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018BC50);

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

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018C0A0);

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

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018C2FC);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018C414);

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

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018D078);

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
