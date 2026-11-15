#include "common.h"

typedef struct Unk_801A7AFC {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 unkA[0x2];
    s16 unkC;
    s16 unkE;
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
    s32 unk10;
} Unk_801A8EFC;
void func_801A2678(s32 arg0);
typedef struct Unk_801E1118 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    s16 unk14;
    s16 unk16;
    u8 unk18[0x4];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
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
typedef struct { void *unk0; s32 unk4; void *unk8; } Unk_80174B10;
Unk_80174B10 *func_80174CB8(s16 arg0);
Unk_80174B10 *func_80173DE0(Unk_80174B10 *arg0, s32 arg1, s32 arg2);
typedef struct { u8 unk0[0x42]; u16 unk42; u8 unk44[0x2]; u16 unk46; } Unk_801E076C;
extern Unk_801E076C *D_801E076C[];
extern s16 D_801D7FB0[];
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
typedef struct { u16 unk0; s16 unk2; s16 *unk4; s16 *unk8; s16 *unkC; } Unk_801E07C0;
extern Unk_801E07C0 D_801E07C0;
s16 D_801DFDA0;
void func_80183E88(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_80184094(void);
void func_801A3BCC(s16 arg0);
s16 func_801AB310(s16 arg0);
void func_801AC578(Unk_801E076C *arg0, s16 arg1, s32 arg2);
typedef struct { u8 unk0[0x5C]; Unk_801E076C *unk5C; } Unk_801E0710;
extern Unk_801E0710 D_801E0710;
typedef struct { s16 unk0[5]; s16 unkA; char *unkC; s16 unk10; s16 unk12; s32 unk14; s32 unk18; s32 unk1C; } Unk_801E0340;
extern Unk_801E0340 D_801E0340;
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
s32 func_801CD6B4(void);
s16 func_801ABC70(Unk_801E0710 *arg0, s32 arg1);
s16 func_8018898C(Unk_801E0710 *arg0, s32 arg1);
s32 func_8019A3E8(Unk_801E0710 *arg0);
void func_80199548(Unk_801E0710 *arg0, s32 arg1, s32 arg2);
void func_801A850C(Unk_801E076C *arg0);
extern s32 D_801DFED4;
extern s32 D_801DFED8;
extern s32 D_801DFEDC;
extern s32 D_801DFEE0;
extern s32 D_801DFEE4;
void func_801863B4(void);
void func_80174840(s16 arg0);
void func_801A4A68(s32 arg0, s32 arg1);
void func_801A3C58(void);
void func_801A252C(void);
void func_801AC278(void);
void func_8019A664(void);
void func_80174FA8(void);
void func_80174BC8(void);
void func_8017D1BC(void);
void func_801A7BA4(void);
void func_8018655C(void);
void func_80186718(void);
void func_801A3B5C(void);
void func_801A23B4(void);
void func_801A43F4(s32 arg0);
void func_801AC55C(void);
void func_801D1BAC(u8 arg0, u8 arg1, u8 arg2);
void func_8017D0E0(void);
void func_801A8000(s32 arg0, s32 arg1, s16 arg2);
void func_8017D3F0(void);

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

s32 func_801A7ED4(s32 arg0, s32 arg1, s16 arg2) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    Unk_801A7AFC *found;
    Unk_80174B10 *p;
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
    if (found == NULL || found->unk8 == 0) {
        return 0;
    }
    if (found->unk4 == 0 || (p = arg2 != 0 ? func_80174CB8(found->unkC) : func_80174CB8(found->unkE)) == NULL) {
        return 0;
    }
    while ((p = func_80173DE0(p, 0, 0)) != NULL) {
    }
    return 1;
}

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

s32 func_801A8370(Unk_801A8EFC *arg0) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801E076C *o = D_801E076C[0];
    Unk_801E1118 *p = &D_801E1118;
    Unk_801E07C0 *c = &D_801E07C0;
    s16 *q = D_801D7FB0;
    s32 v = arg0->unk10;

    if (v == 2) {
        if (arg0->unkC == 0) {
            g->unk244 = -1;
        }
        c->unk0 = 1;
    } else if (v == 3) {
        if (arg0->unkC == 0) {
            g->unk244 = -1;
        }
        c->unk0 = 0;
        if (q[0] != 0) {
            func_801AC578(o, 1, 0);
        }
    } else if (v == 11) {
        /* " 8カーナビ1の3目的地1を, 方向キー上下で選んで下さい,      設定 3○ 1解除 4×" */
        func_80183E88(" 8\203J\201[\203i\203r1\202\3143\226\332\223I\222n1\202\360, \225\373\214\374\203L\201[\217\343\211\272\202\305\221I\202\361\202\305\211\272\202\263\202\242,      \220\335\222\350 3\201\233 1\211\360\217\234 4\201~", 3, -1, 0, -1, 0, 1);
    } else if (v == 12) {
        func_80184094();
        func_801AC578(o, q[0], 1);
    } else if (v == 7) {
        if (p->unkE == 3) {
            p->unkE = 1;
            D_801DFDA0 = func_801AB310(D_801DFDA0);
            if (D_801DFDA0 != 0) {
                func_801AB040(1);
            }
        } else if (p->unkE == 2) {
            p->unkE = 0;
            p->unk12 = 1;
            func_801A2678(0x1F);
        }
    } else if (v == 0) {
        func_801A3BCC(0);
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A850C);

void func_801A8768(void) {
    Unk_801E0340 *s = &D_801E0340;
    Unk_801E0710 *m = &D_801E0710;
    Unk_801E6DA0 *pad = &D_801E6DA0;
    s16 mode = pad->unkA;
    Unk_801E076C *o = m->unk5C;
    s32 id;
    s32 t;

    if (mode == 1 && !(o->unk42 & 2)) {
        t = func_801CD6B4();
        id = o->unk46;
        if (id == mode) {
            if (func_801ABC70(m, t) != 0) {
                D_801DFFAE = 4;
                D_801DFDA0 = 0;
                s->unkA = id;
            }
        } else if (func_8018898C(m, 2) == 0) {
            func_8019A3E8(m);
            if ((o->unk42 & 4) && !(pad->unk4 & 0x20) && (pad->unk0 & 0x20)) {
                func_801A850C(o);
                return;
            }
            func_80199548(m, 2, t);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A88B4);

void func_801A8B38(void) {
    Unk_801E076C *o = D_801E076C[0];
    s32 i;

    func_801863B4();
    func_80174840(1);
    func_801A4A68(0x40E, 0);
    func_801A3C58();
    func_801A252C();
    D_801DFED8 = 0;
    D_801DFED4 = 0;
    D_801DFEE4 = 0;
    D_801DFEE0 = 0;
    D_801DFEDC = 0;
    func_80184094();
    func_801AC278();
    func_8019A664();
    switch (D_801DFFAE) {
    case 0:
        func_80174FA8();
        func_80174BC8();
        func_8017D1BC();
        func_801A7BA4();
        func_8018655C();
        func_80186718();
        func_801A3B5C();
        func_801A23B4();
        for (i = 0; i < 4; i++) {
            func_801A43F4((u16)i);
        }
        func_801A43F4(0x1FF);
        func_801AC55C();
        func_801D1BAC(0, 0, 0);
        break;
    case 3:
        func_801A8000(0, 0, 0);
        break;
    case 1:
        func_8017D0E0();
        func_8018655C();
        func_80186718();
        func_801D1BAC(0, 0, 0);
    case 2:
        func_801A8000(3, 3, 0);
        func_801A8000(3, 4, 0);
        break;
    }
    func_8017D3F0();
    if (D_801DFDA0 != -1) {
        o->unk46 = D_801DFDA0;
    }
}

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

void func_801A910C(Unk_801E1118 *arg0) {
    arg0->unkA = 0;
    if (arg0->unk8 != 0) {
        arg0->unk1C = (arg0->unk10 - 1) * 100000 - 195000;
        arg0->unk20 = (arg0->unk10 - 1) * 100000 - 175000;
        arg0->unk24 = (arg0->unk10 - 1) * 100000 - 115000;
        arg0->unk28 = (arg0->unk10 - 1) * 100000 - 95000;
    } else {
        arg0->unk1C = (arg0->unk10 - 1) * 100000 - 200000;
        arg0->unk20 = (arg0->unk10 - 1) * 100000 - 220000;
        arg0->unk24 = (arg0->unk10 - 1) * 100000 - 280000;
        arg0->unk28 = (arg0->unk10 - 1) * 100000 - 300000;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A923C);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A968C);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A9BF4);

INCLUDE_ASM("asm/nonmatchings/game/801A7560", func_801A9EA4);
