#include "common.h"

typedef struct {
    u16 unk0;
    u16 unk2;
} Unk_80174A14;
typedef struct {
    void *unk0;
} Unk_80174BC8;
typedef struct {
    void *unk0;
    s32 unk4;
    Unk_80174BC8 *unk8;
} Unk_80174CB8;
typedef struct {
    Unk_80174A14 *unk0;
    s32 unk4;
    Unk_80174CB8 *unk8;
} Unk_80174B10;
typedef struct Unk_801CCB70 {
    void *unk0;
    struct Unk_801CCB70 *unk4;
    Unk_80174B10 *unk8;
} Unk_801CCB70;
typedef struct { Unk_801CCB70 *unk0; Unk_801CCB70 *unk4; Unk_801CCB70 *unk8; s32 unkC; } Unk_801DFE54;
Unk_801DFE54 *D_801DFE54;
void func_801CCBF4(Unk_801DFE54 *a0, s32 a1);
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_80174F54;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; u8 unkA; u8 unkB; s32 unkC; s32 unk10; s16 unk14; s16 unk16; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; s32 unk3C; s32 unk40; s32 unk44; s32 unk48; } Unk_801762F4;
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
typedef struct { s16 unk0; s16 unk2; s16 unk4[2]; u8 unk8[0x28]; s16 unk30; s16 unk32[8]; s16 unk42; s16 unk44; s16 unk46; s16 unk48; u8 unk4A[2]; s32 unk4C; } Unk_801E0768;
extern Unk_801E0768 *D_801E0768[];
typedef struct {
    s16 unk0;
    s16 unk2;
    u16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Unk_80173954;
typedef struct {
    u8 unk0[4];
    s16 unk4;
    u8 unk6[0x36];
    s32 unk3C;
    u8 unk40[0x14];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
} Unk_8018E56C;
typedef struct {
    u8 unk0[4];
    s16 unk4;
} Unk_80176370;
Unk_8018E56C *func_8018E56C(u16 arg0);
void func_8018E6D8(s32 arg0, Unk_8018E56C *arg1, u16 arg2);
void func_801CCDF8(Unk_801DFE54 *arg0);
s16 func_801CD000(Unk_801DFE54 *arg0);
Unk_801DFE54 *D_801DFE50;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Unk_80174D6C;
Unk_80174B10 *func_80173DE0(Unk_80174B10 *arg0, s32 arg1, s32 arg2);

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

s16 func_80173954(Unk_80173954 *arg0) {
    Unk_801E0768 *p = D_801E0768[0];
    s16 ret;
    s32 n;
    s32 i;

    if (arg0->unk0 == 0) {
        return 2;
    }
    if (arg0->unk6 == 0) {
        if (arg0->unk4 != 0) {
            ret = 1;
            for (i = 1, n = 0; i < 2; i++) {
                if (p->unk4[i] < arg0->unk8 || arg0->unkA < p->unk4[i]) {
                    n++;
                }
            }
            if (n != 0) {
                ret = 0;
            }
        } else {
            ret = 0;
            for (i = 0; i < 8; i++) {
                if (p->unk32[i] == arg0->unk8) {
                    ret = 1;
                    break;
                }
            }
        }
    }
    if (arg0->unk2 != 0) {
        ret = 1 - ret;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80173A44);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80173DE0);

INCLUDE_ASM("asm/nonmatchings/game/80173054", func_80174840);

void func_801749E8(s32 arg0) {
    D_801DFE54->unk8 = D_801DFE54->unk0;
    func_801CCBF4(D_801DFE54, arg0);
}

void func_80174A14(s16 arg0) {
    Unk_801DFE54 *list = D_801DFE54;
    Unk_80174A14 *item;

    if (list->unkC == 0) {
        return;
    }
    if (arg0 != 0) {
        while (1) {
            if (list->unkC == 0) {
                break;
            }
            func_801CCDF8(list);
        }
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        if (list->unk8->unk8 != NULL) {
            item = list->unk8->unk8->unk0;
            if (item->unk0 == 5 || *(s32 *)item == 0xB) {
                func_801CCDF8(list);
            }
            if (*(s32 *)item == 0x1000B) {
                item->unk2 = 10;
            }
        }
        if (func_801CD000(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

void func_80174B10(Unk_80174B10 *arg0) {
    Unk_80174CB8 *e = arg0->unk8;
    s32 i;

    for (i = 0; i < arg0->unk4; i++, e++) {
        if (e->unk8 != NULL) {
            free3(e->unk8->unk0);
            free3(e->unk8);
        }
        free3(e->unk0);
    }
    free3(arg0->unk8);
    free3(arg0->unk0);
    free3(arg0);
}

void func_80174BC8(void) {
    Unk_801DFE54 *list = D_801DFE50;
    Unk_80174B10 *item;
    Unk_80174CB8 *e;
    s32 i;

    while (1) {
        if (list->unkC == 0) {
            break;
        }
        item = list->unk8->unk8;
        e = item->unk8;
        for (i = 0; i < item->unk4; i++, e++) {
            if (e->unk8 != NULL) {
                free3(e->unk8->unk0);
                free3(e->unk8);
            }
            free3(e->unk0);
        }
        free3(item->unk8);
        free3(item->unk0);
        free3(item);
        func_801CCDF8(list);
    }
}

Unk_80174B10 *func_80174CB8(s16 arg0) {
    Unk_801DFE54 *list = D_801DFE50;
    Unk_80174B10 *item;

    if (list->unkC == 0) {
        return NULL;
    }
    if (arg0 < 0) {
        return NULL;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && item->unk0->unk0 == arg0) {
            return item;
        }
        if (func_801CD000(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return NULL;
}

s32 func_80174D6C(Unk_80174D6C *arg0) {
    Unk_801DFE54 *list;
    Unk_80174B10 *item;
    Unk_80174B10 *p;
    s16 id;

    if (arg0 == NULL || arg0->unkA == 0) {
        return 0;
    }
    list = D_801DFE50;
    id = arg0->unk4;
    if (list->unkC == 0) {
        item = NULL;
    } else if (id < 0) {
        item = NULL;
    } else {
        list->unk8 = list->unk0;
        while (1) {
            p = list->unk8->unk8;
            if (p != NULL && p->unk0->unk0 == id) {
                item = p;
                break;
            }
            if (func_801CD000(list) != 0) {
                item = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (item == NULL) {
        return 0;
    }
    while ((item = func_80173DE0(item, 0, 0)) != NULL) {
    }
    return 1;
}

s32 func_80174E60(Unk_80174D6C *arg0) {
    Unk_801DFE54 *list;
    Unk_80174B10 *item;
    Unk_80174B10 *p;
    s16 id;

    if (arg0 == NULL || arg0->unkA == 0) {
        return 0;
    }
    list = D_801DFE50;
    id = arg0->unk6;
    if (list->unkC == 0) {
        item = NULL;
    } else if (id < 0) {
        item = NULL;
    } else {
        list->unk8 = list->unk0;
        while (1) {
            p = list->unk8->unk8;
            if (p != NULL && p->unk0->unk0 == id) {
                item = p;
                break;
            }
            if (func_801CD000(list) != 0) {
                item = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (item == NULL) {
        return 0;
    }
    while ((item = func_80173DE0(item, 0, 0)) != NULL) {
    }
    return 1;
}

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

void func_80176370(s32 arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801762F4 *e = p->unk3C;
    Unk_80176370 *x;
    Unk_8018E56C *o;
    s32 i;

    if (p->unk1C == 0) {
        return;
    }
    for (i = 0; i < p->unk1C; i++, e++) {
        x = (Unk_80176370 *)e->unk48;
        if (e != NULL && e->unk4 != 0 && e->unk6 != 0 && x != NULL && x->unk4 != 0) {
            o = func_8018E56C(e->unk16);
            if (o != NULL && o->unk4 != 0) {
                func_8018E6D8(arg0, o, e->unkA);
            }
        }
    }
}

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

void func_80176654(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801762F4 *e = p->unk3C;
    Unk_8018E56C *o;
    s32 i;

    if (p->unk1C == 0) {
        return;
    }
    for (i = 0; i < p->unk1C; i++, e++) {
        if (e->unk4 != 0) {
            o = func_8018E56C(e->unk16);
            if (o != NULL) {
                o->unk54 = e->unk20 - arg0;
                o->unk58 = e->unk24 - arg1;
                o->unk5C = e->unk28 - arg2;
                o->unk3C = 0;
            }
        }
    }
}

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
