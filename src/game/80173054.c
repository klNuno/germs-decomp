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
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; u8 unkA; u8 unkB; s16 unkC; u8 unkE; u8 unkF; s16 unk10; u16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s16 unk38; s16 unk3A; s16 unk3C; s16 unk3E; s16 unk40; s16 unk42; u8 unk44; u8 unk45; s16 unk46; s32 unk48; } Unk_801762F4;
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
    u8 unk6[0x2A];
    void *unk30;
    u8 unk34[0x8];
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
typedef struct {
    u8 unk0[0x6];
    s16 unk6;
    u8 unk8[0x2];
    s16 unkA;
    u8 unkC[0x2];
    s16 unkE;
    u16 unk10;
    u16 unk12;
} Unk_801DFFE8;
extern Unk_801DFFE8 D_801DFFE8;
void func_80184160(void);
void *memset(void *dst, s32 c, u32 n);
typedef struct {
    u8 unk0[0x54];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0x12];
    s16 unk72;
    s16 unk74;
    s16 unk76;
} Unk_801E076C;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_80174FFC;
extern Unk_801E076C *D_801E076C[];
void func_8018D2DC(Unk_8018E56C *arg0, s32 arg1, s32 arg2, s32 arg3);
void RotMatrix(Unk_80174FFC *arg0, void *arg1);
void func_80174FFC(Unk_801762F4 *arg0, Unk_8018E56C *arg1);
Unk_80174B10 *func_80174CB8(s16 arg0);
void func_80184094(void);
void GsSetLsMatrix(void *m);
s16 func_8017B7CC(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4);
Unk_801762F4 *func_801762F4(s16 arg0, u16 arg1);
s16 func_8018C750(s16 a);
s32 ratan2(s32 y, s32 x);
s32 func_8018C790(s16 a);
extern s16 D_801D7440[];
s32 rsin(s32 a);
s32 rcos(s32 a);
s16 func_801768F8(Unk_801762F4 *arg0, Unk_80174F54 *arg1, s32 arg2);
s16 func_80177608(Unk_801762F4 *arg0, Unk_80174F54 *arg1, s16 arg2);
extern s32 D_801E6DB4[];
Unk_8018E56C *D_801DFC68;
typedef struct {
    u8 unk0[0x88];
    s32 unk88;
} Unk_801DFC60;
Unk_80176890 *func_80176890(s16 arg0);
s16 func_8017726C(Unk_801762F4 *arg0, s32 arg1);
s16 func_801788F8(Unk_801762F4 *arg0);
void func_80178B84(Unk_801762F4 *arg0);
extern Unk_80176890 D_801D7328;
extern Unk_801767D4 D_801D734C;
Unk_801DFC60 *D_801DFC60;
s32 D_801DFC64;
Unk_80176890 *D_801DFC6C;
Unk_801767D4 *D_801DFC70;

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

void func_80174840(s16 arg0) {
    Unk_801DFFE8 *s = &D_801DFFE8;
    u16 a = s->unk6;
    u16 b = s->unk12;
    u16 c = s->unk10;
    Unk_801DFE54 *list;
    Unk_80174A14 *item;

    func_80184160();
    memset(s, 0, 0x14);
    s->unkA = -1;
    s->unkE = -1;
    s->unk6 = 0;
    if (arg0 == 0) {
        if (a == 1 || a == 4) {
            s->unk6 = a;
        }
        if (b & 1) {
            s->unk12 = b & ~1;
            if (s->unk12 == 0) {
                s->unk6 = 1;
            }
            s->unk10 = 0;
        } else {
            s->unk12 = b;
            s->unk10 = c;
        }
    }
    list = D_801DFE54;
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

void func_80174FFC(Unk_801762F4 *arg0, Unk_8018E56C *arg1) {
    Unk_801E076C *p = D_801E076C[0];
    Unk_80174FFC sv;

    if (arg1->unk4 == 0) {
        if (arg0->unkF == 6) {
            arg0->unkE = 2;
            func_8018D2DC(arg1, 0, 0, 8);
        } else {
            func_8018D2DC(arg1, 0, 0, 0);
        }
    }
    arg1->unk54 = arg0->unk20 - p->unk72 * 12500;
    arg1->unk58 = arg0->unk24 + p->unk74 * 32000;
    arg1->unk5C = arg0->unk28 - p->unk76 * 12500;
    sv.unk0 = (arg0->unk38 << 12) / 360;
    sv.unk2 = (arg0->unk3A << 12) / 360;
    sv.unk4 = (arg0->unk3C << 12) / 360;
    RotMatrix(&sv, arg1->unk40);
    arg1->unk3C = 0;
}

void func_8017519C(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801762F4 *e = p->unk3C;
    Unk_8018E56C *o;
    s32 i;

    if (p->unk1C == 0) {
        return;
    }
    for (i = 0; i < p->unk1C; i++, e++) {
        e->unk4 = 0;
        e->unk20 *= 10;
        e->unk24 *= 10;
        e->unk28 *= 10;
        e->unk2C *= 10;
        e->unk30 *= 10;
        e->unk34 *= 10;
        o = func_8018E56C(e->unk16);
        if (o != NULL) {
            func_80174FFC(e, o);
        e->unk48 = func_8017CDA4(e->unk20, e->unk24, e->unk28);
        e->unk10 = -2;
        e->unk40 = 0;
        e->unkB = 0;
        e->unk44 = 0;
        e->unk45 = 0;
        e->unk46 = 0;
        e->unk12 |= 1;
        e->unk3E = e->unk3A;
        e->unk4 = 1;
        }
    }
}

s32 func_801752F4(u16 arg0, s16 arg1) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_80174B10 *item = NULL;
    s32 n = p->unk1C;
    Unk_801762F4 *q = p->unk3C;
    Unk_801762F4 *e;
    s32 i;

    if (n == 0) {
        e = NULL;
    } else {
        for (i = 0; i < n; i++, q++) {
            if (q->unk0 == arg0) {
                e = q;
                goto found;
            }
        }
        e = NULL;
    }
found:
    if (e == NULL || e->unk4 == 0) {
        return 0;
    }
    if (e->unk8 == 0) {
        return 0;
    }
    if (e->unkF == 6) {
        if (arg1 != 0) {
            item = func_80174CB8(0x400);
        } else {
            func_80184094();
        }
    } else if (e->unkE == 1) {
        if (e->unk12 & 0x20) {
            e->unk12 &= ~0x20;
        }
        return 0;
    } else {
        if (arg1 != 0) {
            item = func_80174CB8(e->unk1A);
            e->unk12 |= 0x20;
        } else {
            item = func_80174CB8(e->unk1C);
            e->unk12 &= ~0x20;
        }
    }
    if (item == NULL) {
        return 0;
    }
    while ((item = func_80173DE0(item, 0, 0)) != NULL) {
    }
    return 1;
}
