#include "common.h"

typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_801DFE54;
Unk_801DFE54 *D_801DFE54;
void func_801CCBF4(Unk_801DFE54 *a0, s32 a1);
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_80174F54;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s32 unk8; s32 unkC; s32 unk10; s16 unk14; s16 unk16; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; s32 unk3C; s32 unk40; s32 unk44; s32 unk48; } Unk_801762F4;
typedef struct { u16 unk0; s16 unk2; s32 unk4; s16 unk8; u16 unkA; u8 unkC[0xC0]; } Unk_801767D4;
typedef struct { u16 unk0; s16 unk2; s32 unk4[8]; } Unk_80176890;
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14;
    s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34;
    Unk_80174F54 *unk38; Unk_801762F4 *unk3C; Unk_801767D4 *unk40; Unk_80176890 *unk44;
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
void free3(void *ptr);
s32 func_8017CDA4(s32 a0, s32 a1, s32 a2);
Unk_801767D4 *func_801767D4(s16 arg0);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80173054);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_80170000);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_8017001C);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_80170028);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_80170050);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_80170068);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_8017008C);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_801700B0);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80173250);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_8017345C);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80173954);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80173A44);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80173DE0);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80174840);

void func_801749E8(s32 arg0) {
    D_801DFE54->unk8 = D_801DFE54->unk0;
    func_801CCBF4(D_801DFE54, arg0);
}

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80174A14);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80174B10);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80174BC8);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80174CB8);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80174D6C);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80174E60);

Unk_80174F54 *func_80174F54(s32 arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    s32 n = p->unk18;
    Unk_80174F54 *e = p->unk38;
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

void func_80174FA8(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    if (p->unk18 != 0) {
        if (p->unk38 != NULL) {
            free3(p->unk38);
        }
        p->unk18 = 0;
        p->unk38 = NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80174FFC);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_8017519C);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_801752F4);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_8017546C);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_801759B0);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80175CD8);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80175FA8);

void func_801762A0(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    if (p->unk1C != 0) {
        if (p->unk3C != NULL) {
            free3(p->unk3C);
        }
        p->unk1C = 0;
        p->unk3C = NULL;
    }
}

Unk_801762F4 *func_801762F4(s16 arg0, u16 arg1) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801762F4 *e = p->unk3C;
    s32 i;
    if (p->unk1C == 0) {
        return NULL;
    }
    for (i = 0; i < p->unk1C; i++, e++) {
        if (arg0 == 0) {
            if (e->unk0 == arg1) {
                return e;
            }
        } else {
            if (e->unk16 == arg1) {
                return e;
            }
        }
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80176370);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80176464);

void func_801765BC(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801762F4 *e = p->unk3C;
    s32 i;
    for (i = 0; i < p->unk1C; i++, e++) {
        if (e->unk4 != 0 && e->unk6 != 0) {
            e->unk48 = func_8017CDA4(e->unk20, e->unk24, e->unk28);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80176654);

u16 func_80176734(Unk_801762F4 *arg0) {
    Unk_801767D4 *e = func_801767D4(arg0->unk14);
    if (e == NULL) {
        return 600;
    }
    return e->unkA * 10;
}

void func_80176780(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    if (p->unk24 != 0) {
        if (p->unk40 != NULL) {
            free3(p->unk40);
        }
        p->unk24 = 0;
        p->unk40 = NULL;
    }
}

Unk_801767D4 *func_801767D4(s16 arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801767D4 *e = p->unk40;
    s32 i;
    if (p->unk24 == 0 || arg0 < 0) {
        return NULL;
    }
    for (i = 0; i < p->unk24; i++, e++) {
        if (e->unk0 == arg0) {
            return e;
        }
    }
    return NULL;
}

void func_8017683C(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    if (p->unk28 != 0) {
        if (p->unk44 != NULL) {
            free3(p->unk44);
        }
        p->unk28 = 0;
        p->unk44 = NULL;
    }
}

Unk_80176890 *func_80176890(s16 arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_80176890 *e = p->unk44;
    s32 i;
    if (p->unk28 == 0 || arg0 < 0) {
        return NULL;
    }
    for (i = 0; i < p->unk28; i++, e++) {
        if (e->unk0 == arg0) {
            return e;
        }
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_801768F8);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80176E2C);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80176FBC);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80177110);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_8017726C);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80177608);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_801779B8);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80178494);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_801786A0);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_801787CC);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_801788F8);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80178B84);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80178D04);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80178E38);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_8017917C);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80179630);
