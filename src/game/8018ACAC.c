#include "common.h"

typedef struct { s16 a, b, c, d; } S8;
S8 *D_801DFD30;
typedef struct { s16 unk0[5]; s16 unkA; } Unk_801E0340;
extern Unk_801E0340 D_801E0340;
void func_801CD688(s32 a);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018ACAC);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B11C);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B564);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B69C);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B810);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018B924);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018BA48);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018BB00);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018BC50);

s16 func_8018BD44(s16 i) { return D_801DFD30[i].a; }

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018BD60);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018BD8C);

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

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018C50C);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018C554);

s16 func_8018C750(s16 a) {
    do {
        if (a < 0) a += 360;
        if (a >= 360) a -= 360;
    } while ((u16)a >= 360);
    return a;
}

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018C790);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018C810);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018C864);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018CB70);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018CD4C);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018CEA0);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018D078);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018D1A0);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018D1F0);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018D200);

INCLUDE_ASM("asm/nonmatchings/game/8018ACAC", func_8018D294);
