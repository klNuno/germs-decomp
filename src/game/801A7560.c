#include "common.h"

typedef struct Unk_801A7AFC {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 unkA[0x6];
    s16 unk10;
    u8 unk12[0x2];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 unk24[0x8];
    s32 unk2C;
    u8 unk30[0x14];
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    u8 unk50[0x2C];
    void *unk7C;
    void *unk80;
    void *unk84;
} Unk_801A7AFC;
void free3(void *ptr);
typedef struct Unk_801A7BA4 {
    struct Unk_801A7BA4 *unk0;
    struct Unk_801A7BA4 *unk4;
    Unk_801A7AFC *unk8;
} Unk_801A7BA4;
typedef struct Unk_801DFFA0 {
    Unk_801A7BA4 *unk0;
    Unk_801A7BA4 *unk4;
    Unk_801A7BA4 *unk8;
    s32 unkC;
} Unk_801DFFA0;
void func_801CCBF4(Unk_801DFFA0 *arg0, s32 arg1);
void func_801CCCF4(Unk_801DFFA0 *arg0, s32 arg1);
Unk_801DFFA0 *D_801DFFA0;
void func_801CCDF8(Unk_801DFFA0 *arg0);
typedef struct Unk_801A8EFC {
    u8 unk0[0xC];
    s32 unkC;
} Unk_801A8EFC;
void func_801A2678(s32 arg0);
typedef struct Unk_801E1118 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    u16 unkE;
    s16 unk10;
    u16 unk12;
    s16 unk14;
    s16 unk16;
} Unk_801E1118;
void func_801AB040(s32 arg0);
extern Unk_801E1118 D_801E1118;
void func_801AC70C(s32 arg0);
void func_8017A3E4(void);
void func_801A8CFC(void);
void func_801A6AC4(void);
void func_8017E99C(s32 arg0, s32 arg1);
s16 D_801DFFA8;
s16 D_801DFFAA;
s16 D_801DFFAE;
s16 func_801CD000(Unk_801DFFA0 *arg0);
void GsSetLsMatrix(void *m);
s16 func_8017B7CC(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4);
typedef struct Unk_801A8264_0 {
    u8 unk0[0x2];
    u16 unk2;
    u8 unk4;
    u8 unk5;
} Unk_801A8264_0;
typedef struct Unk_801A8264 {
    Unk_801A8264_0 *unk0;
    u8 unk4[0x4];
    char **unk8;
} Unk_801A8264;
s32 atoi(char *s);
extern char D_801719BC[];
extern char D_801719DC[];
void *func_801CC898(u32 size);
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char D_801DFD98[];

INCLUDE_RODATA("asm/nonmatchings/game/801A7560", D_801719BC);

INCLUDE_RODATA("asm/nonmatchings/game/801A7560", D_801719DC);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A7560);

void func_801A7A04(Unk_801A7AFC **arg0, u32 arg1) {
    *arg0 = func_801CC898(0x88);
    if (*arg0 == NULL) {
        func_801CD54C(3, D_801719BC, D_801DFD98, 0x26);
    }
    (*arg0)->unk4 = 0;
    (*arg0)->unk6 = 0;
    (*arg0)->unk8 = 0;
    (*arg0)->unk10 = 0;
    (*arg0)->unk14 = 0;
    (*arg0)->unk7C = NULL;
    (*arg0)->unk80 = NULL;
    (*arg0)->unk84 = NULL;
    (*arg0)->unk84 = func_801CC898(arg1);
    if ((*arg0)->unk84 == NULL) {
        func_801CD54C(3, D_801719DC, D_801DFD98, 0x33);
    }
}

void func_801A7AFC(Unk_801A7AFC *arg0) {
    if (arg0 != NULL) {
        free3(arg0->unk7C);
        if (arg0->unk80 != NULL) {
            free3(arg0->unk80);
        }
        free3(arg0->unk84);
        free3(arg0);
    }
}

void func_801A7B58(s32 arg0) {
    if (D_801DFFA0->unkC == 0) {
        func_801CCBF4(D_801DFFA0, arg0);
    } else {
        D_801DFFA0->unk8 = D_801DFFA0->unk4;
        func_801CCCF4(D_801DFFA0, arg0);
    }
}

void func_801A7BA4(void) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;

    while (1) {
        if (list->unkC == 0) {
            break;
        }
        item = list->unk8->unk8;
        if (item != NULL) {
            free3(item->unk7C);
            if (item->unk80 != NULL) {
                free3(item->unk80);
            }
            free3(item->unk84);
            free3(item);
        }
        func_801CCDF8(list);
    }
}

Unk_801A7AFC *func_801A7C3C(s32 arg0, s32 arg1) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    s32 a;
    s32 b;

    if (list->unkC == 0) {
        return NULL;
    }
    a = arg0 & 0xFFFF;
    b = arg1 & 0xFFFF;
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && item->unk2 == a && item->unk0 == b) {
            return item;
        }
        if (func_801CD000(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return NULL;
}

u16 func_801A7CF0(s32 arg0, s32 arg1, s32 arg2, u16 arg3) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;

    if (list->unkC == 0) {
        return 0xFFFF;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && item->unk4 != 0 && item->unk80 != NULL) {
            GsSetLsMatrix(item->unk30);
            if (func_8017B7CC(item->unk80, arg0, arg1, arg2, arg3) != 0) {
                return item->unk0 + (item->unk2 << 12);
            }
        }
        if (func_801CD000(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return 0xFFFF;
}

void func_801A7E10(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;

    if (list->unkC == 0) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL) {
            item->unk2C = 0;
            item->unk44 = item->unk18 - arg0;
            item->unk48 = item->unk1C - arg1;
            item->unk4C = item->unk20 - arg2;
        }
        if (func_801CD000(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A7ED4);

void func_801A8000(s32 arg0, s32 arg1, s16 arg2) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    Unk_801A7AFC *found;
    s32 a;
    s32 b;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        a = arg0 & 0xFFFF;
        b = arg1 & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->unk2 == a && item->unk0 == b) {
                found = item;
                break;
            }
            if (func_801CD000(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL) {
        found->unk4 = arg2;
    }
}

void func_801A80CC(s32 arg0, s32 arg1, s16 arg2) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    Unk_801A7AFC *found;
    s32 a;
    s32 b;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        a = arg0 & 0xFFFF;
        b = arg1 & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->unk2 == a && item->unk0 == b) {
                found = item;
                break;
            }
            if (func_801CD000(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL) {
        found->unk6 = arg2;
    }
}

void func_801A8198(s32 arg0, s32 arg1, s16 arg2) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    Unk_801A7AFC *found;
    s32 a;
    s32 b;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        a = arg0 & 0xFFFF;
        b = arg1 & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->unk2 == a && item->unk0 == b) {
                found = item;
                break;
            }
            if (func_801CD000(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL) {
        found->unk10 = arg2;
    }
}

void func_801A8264(Unk_801A8264 *arg0) {
    Unk_801A8264_0 *p = arg0->unk0;
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    Unk_801A7AFC *found;
    s32 x = p->unk5;
    s32 y = p->unk4;
    s32 a;
    s32 b;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        a = x & 0xFFFF;
        b = y & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->unk2 == a && item->unk0 == b) {
                found = item;
                break;
            }
            if (func_801CD000(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL && p->unk2 == 2) {
        found->unk4 = atoi(arg0->unk8[0]);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A8370);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A850C);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A8768);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A88B4);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A8B38);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A8CFC);

void func_801A8EFC(Unk_801A8EFC *arg0) {
    if (arg0->unkC == 0x404) {
        func_801A2678(0x17);
    }
}

s32 func_801A8F2C(Unk_801A8EFC *arg0) {
    Unk_801E1118 *p = &D_801E1118;
    s32 v = arg0->unkC;

    if (v == 0x200010 || v == 0x200020) {
        p->unk4 = v;
        if (p->unkE == 1) {
            func_801AB040(1);
        }
        return 1;
    }
    return 0;
}

s32 func_801A8F8C(Unk_801A8EFC *arg0) {
    Unk_801E1118 *p = &D_801E1118;
    s32 v = arg0->unkC;

    if (v == 0x200010 || v == 0x200020) {
        p->unk4 = 0;
        func_801AB040(0);
        return 1;
    }
    if (p->unkC != 0) {
        p->unkC = 0;
    }
    return 0;
}

void func_801A8FF8(void) {
    if (D_801E1118.unk12 == 0 && D_801E1118.unkE == 1) {
        if (D_801E1118.unk16 > 0) {
            D_801E1118.unk16--;
        }
        if (D_801E1118.unk16 == 0) {
            D_801E1118.unk16 = -1;
            func_801AC70C(0);
            func_801AB040(0);
        }
    }
}

void func_801A9070(void) {
    D_801DFFAE = 0;
    func_8017A3E4();
    while (1) {
        func_801A8CFC();
        switch (D_801DFFAE) {
        case 0:
            return;
        case 1:
            func_801A6AC4();
            break;
        case 2:
            func_8017E99C(D_801DFFA8, D_801DFFAA);
            break;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A910C);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A923C);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A968C);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A9BF4);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A9EA4);
