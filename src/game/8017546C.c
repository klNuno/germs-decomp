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

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_8017546C);

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_801759B0);

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_80175CD8);

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_80175FA8);

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

s16 func_80176464(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801762F4 *e = p->unk3C;
    Unk_8018E56C *o;
    s32 i;

    if (p->unk1C == 0) {
        return -2;
    }
    for (i = 0; i < p->unk1C; i++, e++) {
        if (e->unk4 != 0 && e->unk6 != 0) {
            o = func_8018E56C(e->unk16);
            if (arg0 != e->unk0 && o != NULL && o->unk4 != 0 && o->unk30 != NULL) {
                GsSetLsMatrix(o->unk40);
                if (func_8017B7CC(o->unk30, arg1, arg2, arg3, 1) != 0) {
                    return e->unk0;
                }
            }
        }
    }
    return -2;
}

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

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_801768F8);

void func_80176E2C(Unk_801762F4 *arg0) {
    Unk_80174FFC sv;
    s16 d;
    s16 diff;
    s16 step;

    if (arg0->unk3A != arg0->unk3E) {
        diff = arg0->unk3E - arg0->unk3A;
        step = D_801E6DB4[0] * 2;
        d = diff;
        if (arg0->unk3A < arg0->unk3E) {
            if (diff >= 180) {
                d = diff - 360;
            }
        } else {
            if (diff < -179) {
                d = diff + 360;
            }
        }
        if (d > 0) {
            if (step < d) {
                d = step;
            }
        } else {
            if (d < -step) {
                d = -step;
            }
        }
        arg0->unk3A = func_8018C750(arg0->unk3A + d);
        if (D_801DFC68 != NULL && D_801DFC68->unk4 != 0) {
            sv.unk0 = (arg0->unk38 << 12) / 360;
            sv.unk2 = (arg0->unk3A << 12) / 360;
            sv.unk4 = (arg0->unk3C << 12) / 360;
            RotMatrix(&sv, D_801DFC68->unk40);
            D_801DFC68->unk3C = 0;
        }
    }
}

s16 func_80176FBC(Unk_801762F4 *arg0, s16 arg1) {
    Unk_801E076C *p = D_801E076C[0];
    Unk_801762F4 *t;
    s32 dx;
    s32 dz;

    if (arg1 == -2) {
        if (!(arg0->unk12 & 0x100)) {
            return 0;
        }
        dx = arg0->unk2C - arg0->unk20;
        dz = arg0->unk34 - arg0->unk28;
    } else if (arg1 == -1) {
        dx = p->unk54 + p->unk72 * 12500 - arg0->unk20;
        dz = p->unk5C + p->unk76 * 12500 - arg0->unk28;
    } else {
        t = func_801762F4(0, arg1);
        if (t == 0) {
            return 0;
        }
        dx = t->unk20 - arg0->unk20;
        dz = t->unk28 - arg0->unk28;
    }
    return func_8018C750((ratan2(dx, dz) * 360 >> 12) - 180);
}

s32 func_80177110(Unk_801762F4 *arg0) {
    Unk_801E076C *p = D_801E076C[0];
    s32 dx;
    s32 dz;

    dx = p->unk54 + p->unk72 * 12500 - arg0->unk20;
    dz = p->unk5C + p->unk76 * 12500 - arg0->unk28;
    if (dx >= -9999 && dx < 10000 && dz >= -9999 && dz < 10000) {
        return 1;
    }
    switch ((s16)func_8018C790(arg0->unk3A - 180)) {
    case 0:
        if (dx < 0) {
            return 0;
        }
        break;
    case 4:
        if (dx >= 0) {
            return 0;
        }
        break;
    case 6:
        if (dz >= 0) {
            return 0;
        }
        break;
    case 2:
        if (dz < 0) {
            return 0;
        }
        break;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_8017726C);

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_80177608);

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_801779B8);

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_80178494);

s32 func_801786A0(Unk_801762F4 *arg0, s32 arg1) {
    Unk_80174F54 v;
    s32 i;
    s32 n;
    s16 a;
    s16 r;

    i = 0;
    n = -arg1;
    for (; i < 7; i++) {
        a = (func_8018C750(arg0->unk3E + D_801D7440[i] - 180) << 12) / 360;
        v.unk0 = n * rsin(a) >> 12;
        v.unk4 = 0;
        v.unk8 = n * rcos(a) >> 12;
        if (func_801768F8(arg0, &v, 0)) {
            r = func_80177608(arg0, &v, a);
        } else {
            r = 0;
        }
        if (r) {
            return 1;
        }
    }
    return 0;
}

s32 func_801787CC(Unk_801762F4 *arg0, s32 arg1) {
    Unk_80174F54 v;
    s32 i;
    s16 a;
    s16 r;

    for (i = 4; i > 0; i--) {
        a = (func_8018C750(arg0->unk3E + D_801D7440[i] - 180) << 12) / 360;
        v.unk0 = arg1 * rsin(a) >> 12;
        v.unk4 = 0;
        v.unk8 = arg1 * rcos(a) >> 12;
        if (func_801768F8(arg0, &v, 0)) {
            r = func_80177608(arg0, &v, a);
        } else {
            r = 0;
        }
        if (r) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_801788F8);

void func_80178B84(Unk_801762F4 *arg0) {
    Unk_801E076C *p = D_801E076C[0];
    Unk_80174FFC sv;

    if (D_801DFC68 != 0 && D_801DFC68->unk4 != 0) {
        arg0->unk3A = func_8018C750((ratan2(p->unk54 + p->unk72 * 12500 - arg0->unk20, p->unk5C + p->unk76 * 12500 - arg0->unk28) * 360 >> 12) - 180);
        sv.unk0 = (arg0->unk38 << 12) / 360;
        sv.unk2 = (arg0->unk3A << 12) / 360;
        sv.unk4 = (arg0->unk3C << 12) / 360;
        RotMatrix(&sv, D_801DFC68->unk40);
        D_801DFC68->unk3C = 0;
    }
}

void func_80178D04(Unk_801762F4 *arg0) {
    s16 f;

    D_801DFC64 = 0;
    D_801DFC6C = 0;
    D_801DFC70 = 0;
    D_801DFC60 = (Unk_801DFC60 *)arg0->unk48;
    D_801DFC68 = func_8018E56C(arg0->unk16);
    D_801DFC6C = func_80176890(arg0->unk18);
    if (D_801DFC6C == 0) {
        D_801DFC6C = &D_801D7328;
    }
    D_801DFC70 = func_801767D4(arg0->unk14);
    if (D_801DFC70 == 0) {
        D_801DFC70 = &D_801D734C;
    }
    f = 0;
    if (D_801DFC60 != 0) {
        f = 1;
        if (D_801DFC60->unk88 == 0) {
            f = 0;
        } else {
            D_801DFC64 = D_801DFC60->unk88;
        }
    }
    if (arg0->unk12 & 1) {
        arg0->unk12 &= ~1;
        func_80178B84(arg0);
    } else if (f != 0) {
        if (func_8017726C(arg0, 1) && arg0->unkE == 1 && func_801788F8(arg0)) {
            if (!(arg0->unk12 & 0x400)) {
                arg0->unk12 |= 0x400;
            }
        }
    } else {
        func_80178B84(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_80178E38);

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_8017917C);

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_80179630);
