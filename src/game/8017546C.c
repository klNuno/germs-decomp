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
typedef struct {
    u16 unk0;
    s16 unk2;
    u16 unk4;
    s16 unk6;
    s16 unk8;
    u16 unkA;
    s16 unkC;
    u16 unkE;
    s16 unk10;
    u16 unk12;
    u16 unk14;
    s16 unk16;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} Unk_80176890;
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
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u16 unk16;
    u8 unk18[0x18];
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
    u8 unk0[0x40];
    s32 unk40;
    u8 unk44[0x10];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0xC];
    s16 unk6C;
    s16 unk6E;
    u8 unk70[0x2];
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
    u8 unk0[0x8];
    s16 unk8;
    u8 unkA[0x4];
    u16 unkE;
    u8 unk10[0x74];
    void *unk84;
    s32 unk88;
} Unk_801DFC60;
Unk_80176890 *func_80176890(s16 arg0);
s16 func_8017726C(Unk_801762F4 *arg0, s16 arg1);
s16 func_801788F8(Unk_801762F4 *arg0);
void func_80178B84(Unk_801762F4 *arg0);
extern Unk_80176890 D_801D7328;
extern Unk_801767D4 D_801D734C;
Unk_801DFC60 *D_801DFC60;
s32 D_801DFC64;
Unk_80176890 *D_801DFC6C;
Unk_801767D4 *D_801DFC70;
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} Unk_80173250;
typedef struct {
    Unk_80173250 *unk0;
    s32 unk4;
    char **unk8;
} Unk_80173054;
s32 atoi(char *s);
typedef struct {
    u8 unk0[0x2E];
    s16 unk2E;
    u8 unk30[2];
    s16 unk32;
    u8 unk34[0x18];
    Unk_801762F4 *unk4C;
    u8 unk50[8];
    Unk_801E0768 *unk58;
} Unk_801E0710;
extern Unk_801E0710 D_801E0710;
s32 rand(void);
void func_80197BB0(s16 arg0, s16 arg1);
void func_80197D64(s32 arg0);
void func_8018A968(s16 arg0, s16 arg1);
extern s16 D_801D742C[];
s16 func_8018C0A0(s16 a);
void func_80176E2C(Unk_801762F4 *arg0);
void func_801779B8(Unk_801762F4 *arg0, s16 arg1, s32 arg2, s32 arg3);
s16 func_80179630(Unk_801762F4 *arg0, s16 arg1, s16 arg2);
s16 func_80176FBC(Unk_801762F4 *arg0, s16 arg1);
s32 func_80177110(Unk_801762F4 *arg0);
s16 D_801DFC74;
s16 D_801DFC76;
void func_80178494(Unk_801762F4 *arg0, s16 arg1, s32 arg2);
s32 func_801786A0(Unk_801762F4 *arg0, s32 arg1);
s32 func_801787CC(Unk_801762F4 *arg0, s32 arg1);
void func_8018DA2C(void *arg0, s16 arg1, s16 arg2);
void func_801A25B4(s32 arg0);
u16 func_80176734(Unk_801762F4 *arg0);
extern s16 D_801D7418[];
extern s16 D_801DFC78[4];
extern u16 D_801E03E6[];
s32 abs(s32 x);
void func_801981D0(Unk_801762F4 *arg0, u16 arg1, s32 arg2);
void func_801A2678(s32 arg0);

s16 func_8017546C(Unk_801762F4 *arg0, s16 arg1) {
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0768 *s = g->unk58;
    Unk_8018E56C *o;
    Unk_80176890 *k;
    u16 lo;
    u16 hi;
    u16 t;
    s32 d;
    s32 n;

    o = func_8018E56C(arg0->unk16);
    if (o == NULL) {
        return 0;
    }
    switch (arg1) {
    case 0:
        if (arg0 == g->unk4C) {
            s->unk46 = 1;
        }
        if (arg0->unkE == 1) {
            if (o->unk16 != 3) {
                func_8018DA2C(o, 3, 0);
                break;
            }
        } else {
            if (o->unk16 != 0) {
                func_8018DA2C(o, 0, 0);
                break;
            }
        }
        break;
    case 1:
        if (arg0 == g->unk4C) {
            s->unk46 = 1;
        }
        if (arg0->unkE == 1) {
            if (o->unk16 != 4) {
                func_8018DA2C(o, 4, 0);
                break;
            } else if (o->unk8 == 0) {
                func_8018DA2C(o, 4, 0);
                break;
            }
        } else {
            if (o->unk16 != 2) {
                func_8018DA2C(o, 2, 0);
                break;
            } else if (o->unk8 == 0) {
                func_8018DA2C(o, 2, 0);
                break;
            }
        }
        break;
    case 2:
        if (arg0 == g->unk4C) {
            s->unk46 = 0;
        }
        if (o->unk16 != 1) {
            func_8018DA2C(o, 1, 0);
            break;
        } else if (o->unk8 == 0) {
            func_8018DA2C(o, 1, 0);
            break;
        }
        break;
    case 3:
        if (arg0 == g->unk4C) {
            s->unk46 = 1;
        }
        if (o->unk16 != 9) {
            if (arg0->unk12 & 0x400) {
                arg0->unk12 &= ~0x1000;
            } else {
                func_8018DA2C(o, 9, 0);
                break;
            }
        } else if (o->unk8 == 0) {
            arg0->unk12 &= ~0x1000;
        }
        break;
    case 4:
        if (arg0 == g->unk4C) {
            s->unk46 = 1;
        }
        if (o->unk16 != 7) {
            if (arg0->unk12 & 0x400) {
                arg0->unk12 &= ~0x400;
                arg0->unk46 = 0;
            }
            func_8018DA2C(o, 7, 5);
            break;
        } else if (o->unk8 == 0) {
            arg0->unk12 &= ~0x800;
        }
        break;
    case 5:
        if (arg0 == g->unk4C) {
            s->unk46 = 1;
        }
        k = func_80176890(arg0->unk18);
        if (k == NULL) {
            return 0;
        }
        switch (o->unk16) {
        case 1:
            if (arg0->unk12 & 0x200) {
                arg0->unk12 &= ~0x200;
            }
        case 3:
        case 4:
            func_8018DA2C(o, 5, 0);
            break;
        case 5:
            if (o->unk8 == 0) {
                if (arg0->unk46 != 0) {
                    arg0->unk46 -= D_801E6DB4[0];
                    if (arg0->unk46 <= 0) {
                        arg0->unk46 = 0;
                        func_8018DA2C(o, 6, 0);
                        if ((u16)k->unk16 < 0x100 && (u16)k->unk16 >= o->unkE) {
                            k->unk16 = o->unkE - 1;
                        }
                    }
                } else if (k == NULL) {
                    arg0->unk46 = 30;
                } else {
                    if (k->unkE == 0) {
                        k->unkE = 1;
                    }
                    arg0->unk46 = k->unkE;
                }
            }
            break;
        case 6:
            if (o->unk8 == 0) {
                arg0->unk12 &= ~0x400;
                if ((u16)k->unk2 == 4) {
                    func_801A25B4(0x27);
                }
            } else {
                d = o->unk12;
                n = (u16)k->unk16;
                lo = n / d;
                t = o->unkC / d;
                hi = 0xFFFF;
                if ((u16)n > 0x100) {
                    lo = (n & 0xFF) / d;
                    hi = ((n & 0xFF00) >> 8) / d;
                }
                if (lo == t || hi == t) {
                    return 1;
                }
            }
            break;
        }
        break;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_801759B0);

void func_80175CD8(Unk_80173054 *arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801762F4 *e = p->unk3C;
    Unk_80173250 *cmd = arg0->unk0;
    u16 id = cmd->unk4;
    Unk_801762F4 *t;
    s32 i;

    if (p->unk1C == 0) {
        t = NULL;
    } else {
        for (i = 0; i < p->unk1C; i++, e++) {
            if (e->unk0 == id) {
                t = e;
                goto done;
            }
        }
        t = NULL;
    }
done:
    if (t == NULL) {
        return;
    }
    switch (cmd->unk2) {
    case 0:
        if (atoi(arg0->unk8[0]) != 0) {
            if (atoi(arg0->unk8[1]) != 0) {
                t->unk1C = atoi(arg0->unk8[2]);
            } else {
                t->unk1A = atoi(arg0->unk8[2]);
            }
        } else {
            if (atoi(arg0->unk8[1]) != 0) {
                t->unk1E = atoi(arg0->unk8[2]);
            }
        }
        break;
    case 1:
        t->unk8 = atoi(arg0->unk8[0]);
        break;
    case 2:
        t->unk6 = atoi(arg0->unk8[0]);
        break;
    case 3:
        if (t->unkE != 2 && t->unkF != 6) {
            t->unkF = atoi(arg0->unk8[0]);
        }
        break;
    case 5:
        if (t->unkE != 2 && t->unkF != 6) {
            t->unkE = atoi(arg0->unk8[0]);
            if (t->unkE == 2) {
                t->unk12 = 0;
            }
        }
        break;
    case 7:
        if (t->unkE != 2 && t->unkF != 6) {
            switch (atoi(arg0->unk8[0])) {
            case 0:
                t->unk12 &= 0x1FF;
                break;
            case 1:
                t->unk12 |= 0x100;
                break;
            case 3:
                t->unk12 = (t->unk12 & 0x1FF) | 0x200;
                break;
            }
        }
        break;
    }
}

void func_80175FA8(Unk_801762F4 *arg0, s32 arg1, s32 arg2, s16 arg3) {
    Unk_801E0710 *g = &D_801E0710;
    Unk_80176890 *k;
    s32 v;
    s16 f;
    s32 n;

    if (arg0->unkC <= 0) {
        return;
    }
    k = func_80176890(arg0->unk18);
    if (k == NULL) {
        return;
    }
    if (k->unk4 == 1) {
        if (arg0->unkE != 1) {
            arg0->unkE = 1;
            if (arg0->unk12 & 0x100) {
                arg0->unk12 &= ~0x100;
            }
        }
    } else if (k->unk4 == 2) {
        if (arg0->unkE != 1) {
            arg0->unkE = 1;
            if (arg0->unkF == 0) {
                arg0->unkF = 1;
            }
        }
    }
    if (arg3 != 0) {
        if (!(arg0->unk12 & 0x1000)) {
            arg0->unk12 |= 0x1000;
        }
        func_8018A968(1, 1);
        return;
    }
    if (k->unkA == 0x7FFF) {
        v = 0x7FFF;
    } else {
        v = rand() % k->unkA;
    }
    f = 0;
    switch (arg1) {
    case 0:
        if (k->unk12 & 1) {
            f = 1;
        }
        break;
    case 1:
        if (k->unk12 & 2) {
            f = 1;
        }
        break;
    case 2:
        if (k->unk12 & 4) {
            f = 1;
        }
        break;
    case 3:
        if (k->unk12 & 8) {
            f = 1;
        }
        break;
    case 4:
        if (k->unk12 & 0x10) {
            f = 1;
        }
        break;
    }
    if (!f) {
        v = v * 2 / 3;
    }
    arg2 -= v;
    if (arg2 <= 0) {
        func_8018A968(1, 1);
        return;
    }
    func_80197BB0(arg1, arg2 * 2);
    arg0->unkC -= arg2;
    if (arg0->unkC <= 0) {
        if (arg0->unkE != 2) {
            arg0->unkE = 2;
            arg0->unk12 = 0;
            n = arg0->unk42;
            switch ((u16)arg0->unk2) {
            case 0:
                g->unk32++;
                g->unk2E++;
                break;
            case 1:
            case 2:
                n *= 2;
                break;
            case 3:
            case 4:
            case 5:
                n *= 3;
                break;
            case 16:
            case 17:
            case 18:
                n *= 4;
                break;
            case 19:
                n *= 6;
                break;
            }
            func_80197D64(n);
        }
    } else {
        if (!(arg0->unk12 & 0x800)) {
            arg0->unk12 |= 0x800;
        }
    }
    func_8018A968(0, 1);
}

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

s16 func_8017726C(Unk_801762F4 *arg0, s16 arg1) {
    Unk_80174F54 v;
    s16 found;
    u16 min;
    u16 saved;
    s32 best;
    s16 a;
    s16 b;
    s32 i;
    u16 d;
    s16 r;
    Unk_801762F4 *e;
    Unk_801E076C *cam;
    Unk_801E02D8 *g = &D_801E02D8;

    min = 0xFFFF;
    saved = 0;
    found = 0;
    e = g->unk3C;
    cam = D_801E076C[0];
    arg0->unk10 = -2;
    best = -2;
    b = -1;
    arg0->unk40 = 0;
    arg0->unk12 &= ~6;
    a = b;
    if (D_801DFC60->unk8 != 0
        && (D_801DFC74 != 0 || D_801DFC76 != 0 || (s16)func_80177110(arg0) != 0)) {
        v.unk0 = cam->unk54 + cam->unk72 * 12500;
        v.unk4 = cam->unk58 - cam->unk74 * 32000 + 1600;
        v.unk8 = cam->unk5C + cam->unk76 * 12500;
        if (func_801768F8(arg0, &v, 15) != 0) {
            saved = arg0->unk40;
            min = saved;
            arg0->unk12 |= 2;
            a = func_80176FBC(arg0, -1);
            found = 1;
        }
    }
    if (arg1 == 2) {
        arg0->unk3E = func_80176FBC(arg0, -2);
        func_80176E2C(arg0);
        return 0;
    }
    if (g->unk1C > 0) {
        for (i = 0; i < g->unk1C; i++, e++) {
            if (e->unk4 != 0 && e->unk6 != 0 && e->unk0 != arg0->unk0 && e->unkE != 2 && e->unkF != 6
                && e->unk24 == arg0->unk24) {
                v.unk0 = e->unk20;
                v.unk4 = e->unk24;
                v.unk8 = e->unk28;
                if (func_801768F8(arg0, &v, 6) != 0) {
                    d = arg0->unk40;
                    if (d != 0 && d < min) {
                        min = d;
                        best = e->unk0;
                    }
                }
            }
        }
        b = func_80176FBC(arg0, best);
    }
    if (found == 0 && best < 0) {
        return 0;
    }
    if (found != 0) {
        if (best >= 0) {
            r = func_8018C750(a - b);
            if (r < 10 || r > 350) {
                arg0->unk12 |= 4;
            }
        }
        if (arg1 == 1) {
            arg0->unk3E = a;
            func_80176E2C(arg0);
        }
        arg0->unk10 = -1;
        arg0->unk40 = saved;
    } else {
        arg0->unk10 = best;
        arg0->unk40 = 0;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/game/8017546C", func_80177608);

static inline s32 func_801779B8_inline(Unk_801762F4 *arg0, s16 n, s32 arg2, s16 arg3) {
    Unk_80174F54 v;
    s16 a;
    arg0->unk3E = D_801D742C[n];
    func_80176E2C(arg0);
    a = (func_8018C750(arg0->unk3E - 180) << 12) / 360;
    v.unk0 = arg2 * rsin(a) >> 12;
    v.unk4 = 0;
    v.unk8 = arg2 * rcos(a) >> 12;
    if (!func_801768F8(arg0, &v, (arg3 != 0) * 16) || !func_80177608(arg0, &v, a)) {
        return 0;
    }
    return 1;
}

void func_801779B8(Unk_801762F4 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 f = arg3;
    Unk_801E076C *p = D_801E076C[0];
    s16 d[2];
    s16 cur;
    s16 back;
    s32 dx;
    s32 dz;
    Unk_801762F4 *t;
    s16 n;
    s16 a;
    s16 j;
    s32 k;

    cur = func_8018C0A0(arg0->unk3A - 180);
    back = D_801D7418[cur];
    d[1] = 8;
    d[0] = 8;
    if (arg1 == 0) {
        goto fallback;
    }
    if (arg1 == 1) {
        if (arg0->unk10 == -2) {
            goto fallback;
        }
        if (arg0->unk10 == -1) {
            dx = p->unk54 + p->unk72 * 12500 - arg0->unk20;
            dz = p->unk5C + p->unk76 * 12500 - arg0->unk28;
        } else {
            t = func_801762F4(0, arg0->unk10);
            if (t == 0 || t->unk10 != -1) {
                goto fallback;
            }
            n = func_80176734(t) + D_801DFC70->unkA * 10;
            a = (func_8018C750(t->unk3A - 270) << 12) / 360;
            if (t->unk0 & 1) {
                n = -n;
            }
            dx = t->unk20 + (n * rsin(a) >> 12) - arg0->unk20;
            dz = t->unk28 + (n * rcos(a) >> 12) - arg0->unk28;
        }
    } else {
        dx = arg0->unk2C - arg0->unk20;
        dz = arg0->unk34 - arg0->unk28;
    }
    if (dx >= 2) {
        d[0] = 0;
    } else if (dx < -1) {
        d[0] = 4;
    }
    if (dz < -1) {
        d[1] = 6;
    } else if (dz >= 2) {
        d[1] = 2;
    }
    if (d[0] != 8 && d[1] != 8) {
        j = D_801DFC78[((dz < 0) ? 2 : 0) + (dx > 0)];
        if (j != back && func_801779B8_inline(arg0, j, arg2, f)) {
            return;
        }
    }
    if ((rand() & 1) || abs(dz) > abs(dx)) {
        j = d[0];
        d[0] = d[1];
        d[1] = j;
    }
    if (d[0] != 8 && d[0] != back && func_801779B8_inline(arg0, d[0], arg2, f)) {
        return;
    }
    if (d[1] != 8 && d[1] != back && func_801779B8_inline(arg0, d[1], arg2, f)) {
        return;
    }
fallback:
    if (cur != 8 && func_801779B8_inline(arg0, cur, arg2, f)) {
        return;
    }
    if (D_801E03E6[0] & 1) {
        j = cur + 1;
        if (j >= 8 || cur == 8) {
            j = 0;
        }
        for (k = 0; k < 8; k++, j++) {
            if (j >= 8) {
                j = 0;
            }
            if (j != back && func_801779B8_inline(arg0, j, arg2, f)) {
                return;
            }
        }
    } else {
        j = cur - 1;
        if (j < 0 || cur == 8) {
            j = 7;
        }
        for (k = 0; k < 8; k++, j--) {
            if (j < 0) {
                j = 7;
            }
            if (j != back && func_801779B8_inline(arg0, j, arg2, f)) {
                return;
            }
        }
    }
    if (back != 8 && func_801779B8_inline(arg0, back, arg2, f)) {
        return;
    }
    arg0->unk3E = D_801D742C[cur];
    func_80176E2C(arg0);
}

void func_80178494(Unk_801762F4 *arg0, s16 arg1, s32 arg2) {
    Unk_80174F54 v;
    s32 f;
    s16 d;
    s16 a;
    s32 r;

    f = 0;
    if (arg1 == 2) {
        f = 1;
        if (arg0->unk2C / 256 == arg0->unk20 / 256 && arg0->unk34 / 256 == arg0->unk28 / 256) {
            if (arg0->unk12 & 0x100) {
                arg0->unk12 &= ~0x100;
            }
            r = 1;
        } else {
            r = 0;
        }
        if (r) {
            return;
        }
    }
    d = func_8018C0A0(arg0->unk3E - 180);
    if ((rand() & 3) != 1) {
        arg0->unk3E = D_801D742C[d];
        func_80176E2C(arg0);
        a = (func_8018C750(arg0->unk3E - 180) << 12) / 360;
        v.unk0 = arg2 * rsin(a) >> 12;
        v.unk4 = 0;
        v.unk8 = arg2 * rcos(a) >> 12;
        if (!func_801768F8(arg0, &v, f * 16) || !func_80177608(arg0, &v, a)) {
            r = 0;
        } else {
            r = 1;
        }
        if (r) {
            return;
        }
    }
    func_801779B8(arg0, arg1, arg2, f);
}

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

s16 func_801788F8(Unk_801762F4 *arg0) {
    Unk_801E076C *p = D_801E076C[0];
    s32 c;
    s32 *pc;
    s32 t;
    s32 a;
    s32 b;
    s32 d;
    s32 m;
    s16 f;

    arg0->unkB = 0;
    if (arg0->unk10 != -1) {
        return 0;
    }
    if (p->unk40 & 0xC9000000) {
        return 0;
    }
    if (!func_80179630(arg0, 1, 0)) {
        return 0;
    }
    if (arg0->unk12 & 4) {
        arg0->unkB = 2;
        return 0;
    }
    if (arg0->unk12 & 0x10) {
        if (arg0->unkB != 3) {
            arg0->unkB = 3;
        }
    }
    pc = &c;
    t = -(D_801DFC70->unkA + 600) + (u16)arg0->unk40;
    c = D_801DFC6C->unk14;
    if (t < 0) {
        t = 0;
    }
    a = D_801DFC6C->unk18 * 10;
    b = D_801DFC6C->unk1C * 10;
    d = D_801DFC6C->unk20 * 10;
    if (t < a) {
        c = 10;
        f = 0;
    } else {
        if (t < b) {
            m = ((b - t) << 12) / (b - a);
        } else if (t < d) {
            m = ((d - t) << 12) / (d - a);
        } else {
            m = rand() % 411;
        }
        *pc = *pc * m >> 12;
        f = 1;
    }
    if (!f) {
        if (arg0->unkB != 3) {
            arg0->unkB = 3;
        }
    }
    if (c < rand() % 100) {
        return 0;
    }
    arg0->unkB = 1;
    return 1;
}

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

void func_80178E38(Unk_801762F4 *arg0, s16 arg1) {
    s32 f;
    s32 n;
    s32 m;
    s32 d;
    s32 x;

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
    if (D_801DFC60 == 0 || D_801DFC60->unk88 == 0) {
        f = 0;
    } else {
        D_801DFC64 = D_801DFC60->unk88;
        f = 1;
    }
    if (f == 0 || (arg0->unk12 & 0x20)) {
        return;
    }
    if (arg0->unk12 & 1) {
        arg0->unk12 &= ~1;
        if (arg1 != 0) {
            func_8017726C(arg0, arg1);
            return;
        }
    }
    if (arg0->unk12 & 8) {
        arg0->unk12 &= ~8;
        if (arg1 == 1) {
            arg1 = 0;
        }
    }
    switch (arg1) {
    case 0:
        n = 4;
        break;
    case 1:
        n = 10;
        break;
    default:
        n = 6;
        break;
    }
    d = D_801E6DB4[0];
    if ((u16)D_801DFC6C->unk10 != 0) {
        x = d * (u16)D_801DFC6C->unk10;
    } else {
        x = d * 3;
    }
    m = x * n;
    if (arg0->unkE == 1 && arg0->unkB == 2) {
        if (!(s16)func_801787CC(arg0, m)) {
            func_801786A0(arg0, m);
        }
    } else if (arg0->unkE == 1 && arg0->unkB == 3) {
        if (!(s16)func_801786A0(arg0, m)) {
            func_801787CC(arg0, m);
        }
    } else {
        func_80178494(arg0, arg1, m);
    }
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
    if (D_801DFC60 == 0 || D_801DFC60->unk88 == 0) {
        f = 0;
    } else {
        D_801DFC64 = D_801DFC60->unk88;
        f = 1;
    }
    if (f != 0) {
        if (func_8017726C(arg0, arg1)) {
            if (arg0->unkE == 1 && func_801788F8(arg0)) {
                if (!(arg0->unk12 & 0x400)) {
                    arg0->unk12 |= 0x400;
                }
            }
        } else if (arg0->unkE == 1) {
            if (!(arg0->unk12 & 8)) {
                arg0->unk12 |= 8;
            }
        }
    }
}

void func_8017917C(Unk_801762F4 *arg0) {
    Unk_801E076C *p;
    s32 f;
    s32 t;
    s32 a;
    s32 b;
    s32 d;
    s32 c;
    s32 m;
    s32 r;
    s32 x;

    D_801DFC64 = 0;
    D_801DFC6C = 0;
    D_801DFC70 = 0;
    D_801DFC60 = (Unk_801DFC60 *)arg0->unk48;
    p = D_801E076C[0];
    D_801DFC68 = func_8018E56C(arg0->unk16);
    D_801DFC6C = func_80176890(arg0->unk18);
    if (D_801DFC6C == 0) {
        D_801DFC6C = &D_801D7328;
    }
    D_801DFC70 = func_801767D4(arg0->unk14);
    if (D_801DFC70 == 0) {
        D_801DFC70 = &D_801D734C;
    }
    if (D_801DFC60 == 0 || D_801DFC60->unk88 == 0) {
        f = 0;
    } else {
        D_801DFC64 = D_801DFC60->unk88;
        f = 1;
    }
    if (f == 0) {
        if ((arg0->unk2 & 0xFF) == 2 || (arg0->unk2 & 0xFF) == 3) {
            func_801A2678(0x28);
        } else {
            switch ((u16)D_801DFC6C->unk2) {
            case 0:
                func_801A2678(0x23);
                break;
            case 1:
                func_801A2678(0x24);
                break;
            case 2:
                func_801A2678(0x25);
                break;
            case 3:
                func_801A2678(0x26);
                break;
            case 4:
                func_801A2678(0x27);
                break;
            }
        }
        return;
    }
    if (!func_8017726C(arg0, 1) || arg0->unk10 != -1 || (arg0->unk12 & 4) || !func_80179630(arg0, 1, 0)) {
        if ((arg0->unk2 & 0xFF) == 2 || (arg0->unk2 & 0xFF) == 3) {
            func_801A2678(0x28);
        } else {
            switch ((u16)D_801DFC6C->unk2) {
            case 0:
                func_801A2678(0x23);
                break;
            case 1:
                func_801A2678(0x24);
                break;
            case 2:
                func_801A2678(0x25);
                break;
            case 3:
                func_801A2678(0x26);
                break;
            case 4:
                func_801A2678(0x27);
                break;
            }
        }
        return;
    }
    t = -(D_801DFC70->unkA + 600) + (u16)arg0->unk40;
    if (t < 0) {
        t = 0;
    }
    m = 0;
    a = D_801DFC6C->unk18 * 10;
    b = D_801DFC6C->unk1C * 10;
    c = (u16)D_801DFC6C->unkC;
    d = D_801DFC6C->unk20 * 10;
    r = 0;
    if (t < a) {
        r = -1;
    } else if (t < b) {
        m = 0x1000;
    } else if (t < d) {
        m = ((d - t) << 12) / (d - b);
    }
    if (!(t < a)) {
        r = c * m >> 12;
    }
    if ((u16)D_801DFC6C->unk2 == 0) {
        x = p->unk58 - p->unk74 * 32000 - arg0->unk24 + 1600;
        if (x > 0) {
            x = -x;
        }
        if (x < -1600 || m == 0) {
            if ((arg0->unk2 & 0xFF) == 2 || (arg0->unk2 & 0xFF) == 3) {
                func_801A2678(0x28);
            } else {
                switch ((u16)D_801DFC6C->unk2) {
                case 0:
                    func_801A2678(0x23);
                    break;
                case 1:
                    func_801A2678(0x24);
                    break;
                case 2:
                    func_801A2678(0x25);
                    break;
                case 3:
                    func_801A2678(0x26);
                    break;
                case 4:
                    func_801A2678(0x27);
                    break;
                }
            }
            return;
        }
    }
    if (r < 20) {
        if (r < 0) {
            m = 0x1000;
        }
        r = 20;
    }
    if (rand() % 100 < r) {
        if (m < 410) {
            m = 410;
        }
        func_801981D0(arg0, D_801DFC6C->unk2, (u16)D_801DFC6C->unk8 * m >> 12);
    }
    if ((arg0->unk2 & 0xFF) == 2 || (arg0->unk2 & 0xFF) == 3) {
        func_801A2678(0x28);
    } else {
        switch ((u16)D_801DFC6C->unk2) {
        case 0:
            func_801A2678(0x23);
            break;
        case 1:
            func_801A2678(0x24);
            break;
        case 2:
            func_801A2678(0x25);
            break;
        case 3:
            func_801A2678(0x26);
            break;
        case 4:
            func_801A2678(0x27);
            break;
        }
    }
}

s16 func_80179630(Unk_801762F4 *arg0, s16 arg1, s16 arg2) {
    Unk_801E076C *p = D_801E076C[0];
    s32 dx;
    s32 dz;
    s16 lim;
    s32 t;
    s32 a;

    if (arg1 != 0) {
        lim = 10;
        dx = p->unk54 + p->unk72 * 12500 - arg0->unk20;
        dz = p->unk5C + p->unk76 * 12500 - arg0->unk28;
    } else {
        dx = arg0->unk20 - p->unk54 - p->unk72 * 12500;
        dz = arg0->unk28 - p->unk5C - p->unk76 * 12500;
        lim = 15;
        if (arg2 == 10 || arg2 >= 14) {
            lim = 25;
        }
    }
    t = ratan2(dx, dz) * 360 >> 12;
    if (arg1 != 0) {
        a = func_8018C750(t - arg0->unk3A + 180);
    } else {
        a = func_8018C750(t - p->unk6E);
    }
    if (a <= lim || a >= 360 - lim) {
        if (arg1 != 0) {
            if (arg0->unk45 > 50) {
                return 0;
            }
        } else if (arg0->unk44 > lim) {
            return 0;
        }
        return 1;
    }
    return 0;
}
