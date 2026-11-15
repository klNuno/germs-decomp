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
void func_801CCBF4(Unk_801DFE5C *arg0, s32 arg1);
void func_801CCCF4(Unk_801DFE5C *arg0, s32 arg1);
Unk_801DFE5C *D_801DFF0C;
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_80174F54;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s32 unk8; s32 unkC; s32 unk10; s16 unk14; s16 unk16; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; s32 unk3C; s32 unk40; s32 unk44; s32 unk48; } Unk_801762F4;
typedef struct { u16 unk0; s16 unk2; s32 unk4; s16 unk8; u16 unkA; u8 unkC[0xC0]; } Unk_801767D4;
typedef struct { u16 unk0; s16 unk2; s32 unk4[8]; } Unk_80176890;
typedef struct { u16 unk0; u8 unk2[0x19]; u8 unk1B; u8 unk1C[4]; } Unk_8018F590;
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14;
    s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34;
    Unk_80174F54 *unk38; Unk_801762F4 *unk3C; Unk_801767D4 *unk40; Unk_80176890 *unk44;
    s32 unk48; s32 unk4C; Unk_8018F590 *unk50;
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
void free3(void *ptr);

INCLUDE_RODATA("asm/nonmatchings/game/8018D2DC", D_80170A80);

INCLUDE_RODATA("asm/nonmatchings/game/8018D2DC", D_80170AA0);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018D2DC);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018D5F8);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018D6DC);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018D8B8);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018DA2C);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018DBA4);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018DE58);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018E03C);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018E144);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018E1F0);

void func_8018E2F8(s32 arg0) {
    if (D_801DFF0C->unkC == 0) {
        func_801CCBF4(D_801DFF0C, arg0);
    } else {
        D_801DFF0C->unk8 = D_801DFF0C->unk4;
        func_801CCCF4(D_801DFF0C, arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018E344);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018E47C);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018E56C);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018E610);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018E6D8);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018E7EC);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018E8B8);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018EA00);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018EC44);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018EED4);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018F234);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018F428);

void func_8018F53C(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    if (p->unk20 != 0) {
        if (p->unk50 != NULL) {
            free3(p->unk50);
        }
        p->unk20 = 0;
        p->unk50 = NULL;
    }
}

Unk_8018F590 *func_8018F590(u16 arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    s32 n = p->unk20;
    Unk_8018F590 *e = p->unk50;
    s32 i;

    if (n == 0) {
        return NULL;
    }
    for (i = 0; i < n; i++, e++) {
        if (e->unk0 == arg0) {
            return e;
        }
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018F5E8);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018F6E8);

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018F7D0);

void func_8018F91C(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_8018F590 *e = p->unk50;
    s32 i;

    for (i = 0; i < p->unk20; i++, e++) {
        e->unk1B = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", func_8018F958);
