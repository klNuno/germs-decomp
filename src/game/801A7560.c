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
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
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
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    u8 unk32[0x2];
    s16 unk34;
    s16 unk36;
    s16 unk38;
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
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0x26];
    s16 unk3C;
    u8 unk3E[0x4];
    u16 unk42;
    u8 unk44[0x2];
    u16 unk46;
    u8 unk48[0xC];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0xC];
    u16 unk6C;
    u16 unk6E;
    u16 unk70;
    s16 unk72;
    s16 unk74;
    s16 unk76;
} Unk_801E076C;
extern Unk_801E076C *D_801E076C[];
extern s16 D_801D7FB0[];
typedef struct { s32 unk0; s16 unk4; s16 unk6; } Unk_801E056C;
typedef struct {
    u16 unk0[0x70];
    u8 unkE0[0x120];
    s16 unk200;
    u8 unk202[0x2];
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
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4[2];
    u8 unk8[4];
    s16 unkC[0x12];
    s16 unk30;
    s16 unk32[8];
    s16 unk42;
    s16 unk44;
    s16 unk46;
    u16 unk48;
    u8 unk4A[2];
    s32 unk4C;
} Unk_801E0768;
typedef struct {
    u8 unk0[0x4C];
    void *unk4C;
    u8 unk50[0x8];
    Unk_801E0768 *unk58;
    Unk_801E076C *unk5C;
} Unk_801E0710;
extern Unk_801E0710 D_801E0710;
typedef struct { s16 unk0[5]; s16 unkA; char *unkC; s16 unk10; s16 unk12; s32 unk14; s32 unk18; s32 unk1C; } Unk_801E0340;
extern Unk_801E0340 D_801E0340;
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    u8 unkC[0x8];
    s32 unk14;
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
typedef struct {
    u32 unk0;
    s16 unk4;
    s16 unk6;
    u16 unk8;
    s16 unkA;
    u16 unkC;
    s16 unkE;
    u8 pad10[0x2];
    u16 unk12;
} Unk_801DFFE8;
extern Unk_801DFFE8 D_801DFFE8;
void func_801A6B50();
s16 func_801AB1A0(s16 arg0);
s16 D_801DFFAC;
s16 D_801DFDA2;
void func_801A80CC(s32 arg0, s32 arg1, s16 arg2);
s32 func_801A8370(Unk_801A8EFC *arg0);
void func_801A8EFC(Unk_801A8EFC *arg0);
s32 func_801A8F2C(Unk_801A8EFC *arg0);
s32 func_801A8F8C(Unk_801A8EFC *arg0);
void func_801A8FF8(void);
void func_80197370(s32 arg0);
void func_8019A5D4(void);
void func_80187978(s32 arg0);
void func_801926B4(void);
void func_80192CD0(s16 arg0);
void func_8018647C(s16 arg0);
void func_80186630(void);
void func_80186680(void);
void func_8017A86C(u16 arg0);
void func_801AC500(void);
void func_801AC0E4(void);
void func_801A6EB4(void);
void func_8018AABC(s16 arg0);
void func_801A8768(void);
void func_801A88B4(void);
void func_801A8B38(void);
void func_801D06B4(void);
void func_801D06C4(void);
void func_80186128(s32 arg0, s32 arg1);
s32 func_801CC378(s32 *arg0);
void func_80189928(s32 *arg0);
void func_80189350(s32 *arg0);
void func_801895E0(s32 *arg0);
void func_80189970(s16 arg0);
s32 func_8018C170(void);
void func_801CD688(s32 arg0);
s16 func_8018970C(s32 *arg0);
void func_801CC734(s32 *arg0);
void func_80186414(s32 arg0, s32 arg1, s32 arg2);
void func_8018C2FC(u16 arg0, s16 arg1, s16 arg2);
s32 func_8017D564(void);
s32 rand(void);
typedef struct {
    u16 unk0;
    u8 unk2[0x16];
    s32 unk18;
    s32 unk1C;
} Unk_801A9BF4;
typedef struct {
    u16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0x2];
    s32 unk18;
    u8 unk1C[0x14];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    u8 unk3C[0x2C];
    s32 unk68;
    u8 unk6C[0x14];
    s32 unk80;
    s32 unk84;
    s32 unk88;
    u8 unk8C[0x2C];
    void *unkB8;
    void *unkBC;
    Unk_801A9BF4 *unkC0;
} Unk_801E032C;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_801A742C_10;
void func_801A910C(Unk_801E1118 *arg0);
void RotMatrix(Unk_801A742C_10 *arg0, void *arg1);
void GsInitCoordinate2(void *super, void *base);
void func_801CD028(void *arg0, void *arg1, void *arg2);
extern s16 D_801DFC80;
void RotMatrixZYX(Unk_801A742C_10 *arg0, void *arg1);
s32 func_8017CDA4(s32 a0, s32 a1, s32 a2);
void func_801A727C(Unk_801E076C *arg0, Unk_801A7AFC *arg1, void *arg2);
void func_801A742C(Unk_801A7AFC *arg0);
void func_801AACF4(Unk_801A7AFC *arg0);
void func_801AB4D4(Unk_801A7AFC *arg0, s32 arg1);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    Unk_801A742C_10 unk1C;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    Unk_801A742C_10 unk2C[4];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    u8 unk58[0x4];
    s32 unk5C;
    s32 unk60;
    s32 unk64;
} Unk_801E1158;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_801D7FB0;
extern Unk_801A7AFC *D_801E0764[];
extern Unk_801E1158 D_801E1158;
s16 D_801DFFB0;
s32 D_801DFFB4;
void RotTrans(void *v0, s32 *v1, s32 *flag);
void func_8019555C(Unk_801E076C *arg0, s16 arg1);
void func_801A25B4(s32 arg0);
void func_8018C50C(s32 a, s32 b, s32 c, s16 d, s16 e);
s32 rsin(s32 a);
s32 rcos(s32 a);
s32 func_8017CFE4(s32 arg0, s32 *arg1, s32 arg2);
extern Unk_801E032C *D_801E032C[];
extern s32 D_801E6DB4[];

INCLUDE_RODATA("asm/nonmatchings/game/801A7560", D_801719BC);

INCLUDE_RODATA("asm/nonmatchings/game/801A7560", D_801719DC);

void func_801A7560(void) {
    Unk_801A742C_10 sv;
    Unk_801DFFA0 *p = D_801DFFA0;
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0768 *a = g->unk58;
    Unk_801E076C *e = g->unk5C;
    Unk_801A7AFC *o;

    if (p->unkC == 0) {
        return;
    }
    p->unk8 = p->unk0;
    while (1) {
        o = p->unk8->unk8;
        if (o != NULL && o->unk2 != 4) {
            if (*(s32 *)o == 0x30007) {
                if (g->unk4C != 0 && a->unk48 >= 3) {
                    if (o->unk4 == 0) {
                        o->unk4 = 1;
                    }
                } else if (o->unk4 != 0) {
                    o->unk4 = 0;
                }
            }
            if (o->unk4 == 0) {
                o->unk14 = 0;
            } else {
                if (o->unk6 != 0) {
                    switch (o->unk2) {
                    case 2:
                        if (o->unk0 == 0) {
                            func_801AACF4(o);
                        }
                        break;
                    case 3:
                        switch (o->unk0) {
                        case 0:
                        case 2:
                        case 6:
                            o->unk26 = -D_801E6DA0.unk14 + o->unk26;
                            if (o->unk26 < 0) {
                                o->unk26 += 360;
                            } else if (o->unk26 > 360) {
                                o->unk26 -= 360;
                            }
                            sv.unk0 = (o->unk24 << 12) / 360;
                            sv.unk2 = (o->unk26 << 12) / 360;
                            sv.unk4 = (o->unk28 << 12) / 360;
                            RotMatrix(&sv, o->unk30);
                            o->unk2C = 0;
                            break;
                        case 1:
                            o->unk26 -= -D_801E6DA0.unk14;
                            if (o->unk26 < 0) {
                                o->unk26 += 360;
                            } else if (o->unk26 > 360) {
                                o->unk26 -= 360;
                            }
                            sv.unk0 = (o->unk24 << 12) / 360;
                            sv.unk2 = (o->unk26 << 12) / 360;
                            sv.unk4 = (o->unk28 << 12) / 360;
                            RotMatrixZYX(&sv, o->unk30);
                            o->unk2C = 0;
                            break;
                        case 3:
                        case 4:
                        case 5:
                            o->unk26 += ~(D_801E6DA0.unk14 / 4);
                            if (o->unk26 < 0) {
                                o->unk26 += 360;
                            } else if (o->unk26 > 360) {
                                o->unk26 -= 360;
                            }
                            sv.unk0 = (o->unk24 << 12) / 360;
                            sv.unk2 = (o->unk26 << 12) / 360;
                            sv.unk4 = (o->unk28 << 12) / 360;
                            RotMatrix(&sv, o->unk30);
                            o->unk2C = 0;
                            break;
                        case 7:
                            func_801A727C(e, o, g->unk4C);
                            break;
                        case 8:
                            o->unk26 += D_801E6DA0.unk14 * 5 / 2;
                            if (o->unk26 < 0) {
                                o->unk26 += 360;
                            } else if (o->unk26 > 360) {
                                o->unk26 -= 360;
                            }
                            sv.unk0 = (o->unk24 << 12) / 360;
                            sv.unk2 = (o->unk26 << 12) / 360;
                            sv.unk4 = (o->unk28 << 12) / 360;
                            RotMatrix(&sv, o->unk30);
                            o->unk2C = 0;
                            break;
                        case 9:
                            o->unk26 -= D_801E6DA0.unk14 * 5;
                            if (o->unk26 < 0) {
                                o->unk26 += 360;
                            } else if (o->unk26 > 360) {
                                o->unk26 -= 360;
                            }
                            sv.unk0 = (o->unk24 << 12) / 360;
                            sv.unk2 = (o->unk26 << 12) / 360;
                            sv.unk4 = (o->unk28 << 12) / 360;
                            RotMatrix(&sv, o->unk30);
                            o->unk2C = 0;
                            break;
                        case 10:
                            func_801A742C(o);
                            break;
                        }
                        break;
                    }
                }
                if (o->unk10 == 0 && D_801DFC80 != 0) {
                    o->unk14 = func_8017CDA4(o->unk18, o->unk1C, o->unk20);
                    if (*(s32 *)o == 0) {
                        func_801AB4D4(o, 0);
                    }
                }
            }
        }
        if (func_801CD000(p) != 0) {
            break;
        }
        p->unk8 = p->unk8->unk4;
    }
}

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

void func_801A850C(Unk_801E076C *arg0) {
    Unk_801E0340 *s = &D_801E0340;
    Unk_801DFFE8 *d = &D_801DFFE8;
    Unk_80174B10 *p;
    s32 hi;
    s32 lo;

    if (d->unk6 == 2 && (d->unk8 & 8)) {
        func_80184094();
        switch (d->unk4) {
        case 0xFD:
            hi = d->unk0 & 0xF000;
            lo = (u16)d->unk0 & 0xFFF;
            if (hi == 0 && lo == 0) {
                func_801A2678(0x16);
                s->unkA = 1;
                s->unk14 = arg0->unk54 + arg0->unk72 * 12500;
                s->unk18 = 0;
                s->unk1C = arg0->unk5C + arg0->unk76 * 12500;
                D_801DFFAE = 3;
                D_801DFDA0 = 1;
                s->unk12 = arg0->unk6E;
                s->unk10 = 0;
            } else {
                func_801A2678(0x11);
                for (p = func_80174CB8(d->unkA); p != 0; p = func_80173DE0(p, 0, 0)) {
                }
            }
            break;
        case 0xFE:
            func_801A2678(0xD);
            s->unkA = 1;
            D_801DFFAE = 2;
            D_801DFFA8 = (d->unk0 & 0xFF00) >> 8;
            D_801DFFAA = d->unk0 & 0xFF;
            break;
        case 0xFF:
            func_801A2678(0xD);
            D_801DFFAE = 1;
            s->unkA = 1;
            func_801A6B50(d->unk0);
            break;
        case 0x20:
            func_801A2678(0x11);
            D_801DFDA0 = func_801AB1A0(D_801DFDA0);
            break;
        default:
            for (p = func_80174CB8(d->unkA); p != 0; p = func_80173DE0(p, 0, 0)) {
            }
            break;
        }
        d->unk6 = 1;
        d->unk8 &= ~8;
    }
}

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

void func_801A88B4(void) {
    Unk_801E0768 *p;
    Unk_801E076C *o;
    Unk_801E1118 *q;

    D_801DFDA0 = -1;
    D_801DFFAC = 1;
    p = D_801E0710.unk58;
    o = D_801E0710.unk5C;
    q = &D_801E1118;
    func_801A4A68(0x410, 1);
    func_80174840(1);
    if (D_801DFFAE != 3) {
        func_80197370(2);
    }
    func_8019A5D4();
    func_80187978(0);
    func_80187978(1);
    switch (D_801DFFAE) {
    case 0:
        func_801926B4();
        if (D_801DFDA2 != p->unk42) {
            func_80192CD0(p->unk42);
            D_801DFDA2 = p->unk42;
        }
        func_8018647C(2);
        func_80186630();
        func_80186680();
    case 1:
    case 2:
    case 3:
    case 4:
        func_8017A86C(2);
        break;
    }
    switch (o->unk46) {
    case 0:
        func_801AC500();
        func_801A2678(0x15);
    case 1:
        func_801AC0E4();
        D_801DFED8 = (s32)func_801A8EFC;
        func_801A8000(3, 3, 1);
        func_801A8000(3, 4, 1);
        func_801A80CC(3, 3, 1);
        func_801A80CC(3, 4, 1);
        func_801A4A68(0x40E, 1);
        if (o->unk46 == 1) {
            func_801A2678(0x19);
            func_801A2678(0x1A);
        }
        break;
    case 3:
        D_801DFFAC = 0;
        func_801A8000(4, 0, 0);
    case 2:
        func_801AC0E4();
        D_801DFEE4 = (s32)func_801A8F2C;
        D_801DFEE0 = (s32)func_801A8F8C;
        D_801DFEDC = (s32)func_801A8FF8;
        q->unkC = 0;
        q->unk4 = 0;
        q->unk16 = 0;
        break;
    }
    if (D_801DFFAE != 0) {
        func_801A6EB4();
    }
    D_801DFED4 = (s32)func_801A8370;
    D_801DFFAE = 0;
    func_8018AABC(D_801DFFAC);
    func_801A4A68(0x410, 0);
}

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

void func_801A8CFC(void) {
    s32 sp10[6];
    s16 flag;
    s16 done;

    flag = 0;
    done = 0;
    func_801A88B4();
    func_801D06B4();
    func_80186128(0, 3);
    while (done == 0) {
        switch (func_801CC378(sp10)) {
        case 2:
            func_80189928(sp10);
            continue;
        case 0x10:
            func_80189350(sp10);
            continue;
        case 0x20:
            func_801895E0(sp10);
            continue;
        case 4:
            func_80189970(D_801DFFAC);
            continue;
        case 0:
            func_801A8768();
            if ((s16)func_8018C170() != 0) {
                if (D_801DFFAE == 2) {
                    func_801CD688(0);
                    flag = 1;
                } else {
                    func_80186128(1, 3);
                }
            }
            break;
        case 0x100:
            done = func_8018970C(sp10);
            continue;
        default:
            func_801CC734(sp10);
            continue;
        }
        func_80186414(0, 0x404, rand() % 30 + 30);
        func_8018C2FC(2, 1, 1);
        if (flag != 0 && func_8017D564() != 0) {
            done = 1;
        }
    }
    func_801D06C4();
    func_801A8B38();
}

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

void func_801A923C(Unk_801E032C *arg0, Unk_801E076C *arg1) {
    s32 v[3];
    Unk_801A742C_10 sv;
    s32 flag;
    Unk_801A9BF4 *h = arg0->unkC0;
    Unk_801A7AFC *o = D_801E0764[0];
    Unk_801E1158 *q = &D_801E1158;
    Unk_801D7FB0 *r = (Unk_801D7FB0 *)D_801D7FB0;
    Unk_801E0368 *g = &D_801E0368;

    arg0->unk0 = h->unk0;
    arg0->unk2 = 0;
    GsSetLsMatrix(o->unk30);
    q->unk1C.unk0 = -180;
    q->unk1C.unk2 = -120;
    q->unk24 = 0;
    q->unk26 = 0;
    q->unk28 = 0;
    q->unk1C.unk4 = 200;
    RotTrans(&q->unk1C, v, &flag);
    if (h->unk18 != 0) {
        func_801CD028(&arg0->unkB8, (u8 *)arg0->unkC0 + h->unk18, &arg0->unk18);
    }
    GsInitCoordinate2(NULL, &arg0->unk18);
    arg0->unk4 = o->unk18;
    arg0->unk8 = o->unk1C + 370;
    arg0->unkC = o->unk20;
    arg0->unk10 = o->unk24;
    arg0->unk12 = o->unk26;
    arg0->unk14 = o->unk28;
    arg0->unk30 = arg0->unk4 - arg1->unk72 * 12500;
    arg0->unk34 = arg0->unk8 + arg1->unk74 * 32000;
    arg0->unk38 = arg0->unkC - arg1->unk76 * 12500;
    sv.unk0 = (arg0->unk10 << 12) / 360;
    sv.unk2 = (arg0->unk12 << 12) / 360;
    sv.unk4 = (arg0->unk14 << 12) / 360;
    RotMatrix(&sv, arg0->unk1C);
    if (h->unk1C != 0) {
        func_801CD028(&arg0->unkBC, (u8 *)arg0->unkC0 + h->unk1C, &arg0->unk68);
    }
    GsInitCoordinate2(&arg0->unk18, &arg0->unk68);
    arg0->unk80 = -180;
    arg0->unk84 = -360;
    arg0->unk88 = 412;
    sv.unk0 = 56;
    sv.unk2 = 0;
    sv.unk4 = 0;
    RotMatrix(&sv, arg0->unk6C);
    arg1->unk54 = v[0] + arg1->unk72 * 12500;
    arg1->unk58 = v[1] - arg1->unk74 * 32000;
    arg1->unk5C = v[2] + arg1->unk76 * 12500;
    arg1->unk6C = 0;
    arg1->unk6E = arg0->unk12;
    arg1->unk70 = 0;
    func_8019555C(arg1, 1);
    q->unk0 = 0;
    q->unk2 = 0;
    D_801DFFB0 = 0;
    q->unk4 = 0;
    q->unk8 = 0;
    q->unkC = 0;
    q->unk6 = 0;
    q->unk10 = 0;
    q->unk14 = 0;
    q->unk18 = 0;
    q->unk2C[0].unk0 = -75;
    q->unk2C[0].unk2 = 0;
    q->unk2C[0].unk4 = 102;
    q->unk2C[1].unk0 = 75;
    q->unk2C[1].unk2 = 0;
    q->unk2C[1].unk4 = 102;
    q->unk2C[2].unk0 = -75;
    q->unk2C[2].unk2 = 0;
    q->unk2C[2].unk4 = -152;
    q->unk2C[3].unk0 = 75;
    q->unk2C[3].unk2 = 0;
    q->unk2C[3].unk4 = -152;
    q->unk4C = 0;
    q->unk50 = 0;
    q->unk54 = 0;
    q->unk5C = 0;
    q->unk60 = 0;
    q->unk64 = 0;
    arg0->unk18 = 0;
    arg0->unk68 = 0;
    r->unk0 = 0;
    r->unk2 = 1;
    r->unk4 = 0;
    r->unk8 = 0;
    r->unkC = 0;
    r->unk10 = 0;
    switch (g->unk200) {
    case 2:
        D_801DFFB4 = 500;
        break;
    case 1:
        D_801DFFB4 = 400;
        break;
    case 0:
        D_801DFFB4 = 300;
        break;
    }
}

static inline s32 func_801A968C_inline(Unk_801E032C *arg0, Unk_801E076C *o, s32 *px, s32 *py, s32 *pz, s32 ang) {
    s32 x;
    s32 z;
    x = arg0->unk4 + ((*px * rcos(ang) + *pz * rsin(ang)) >> 12);
    z = arg0->unkC + ((*pz * rcos(ang) - *px * rsin(ang)) >> 12);
    *px = x - o->unk72 * 12500;
    *pz = z - o->unk76 * 12500;
    if ((s16)func_8017CFE4(*px, py, *pz)) {
        *px = x;
        *pz = z;
        return 1;
    }
    return 0;
}

void func_801A968C(Unk_801E032C *arg0) {
    s32 x;
    s32 y;
    s32 z;
    s32 ang;
    Unk_801E076C *o = D_801E076C[0];

    o->unk0 = arg0->unk4;
    o->unk4 = arg0->unk8 - 370;
    o->unk8 = arg0->unkC;
    o->unk10 = arg0->unk10;
    o->unk12 = arg0->unk12;
    o->unk14 = arg0->unk14;
    ang = (arg0->unk12 << 12) / 360;
    x = -245;
    z = 0;
    if (!func_801A968C_inline(arg0, o, &x, &y, &z, ang)) {
        x = 245;
        z = 0;
        if (!func_801A968C_inline(arg0, o, &x, &y, &z, ang)) {
            x = 0;
            z = -490;
            if (!func_801A968C_inline(arg0, o, &x, &y, &z, ang)) {
                x = 0;
                z = 490;
                if (!func_801A968C_inline(arg0, o, &x, &y, &z, ang)) {
                    z = 0;
                    y = 0;
                    x = 0;
                }
            }
        }
    }
    func_801A25B4(0x1A);
    func_801AC578(NULL, 0, 1);
    func_801A43F4(4);
    D_801D7FB0[0] = 0;
    func_8018C50C(x, y, z, arg0->unk12, 0);
}

void func_801A9BF4(Unk_801E032C *arg0, Unk_801E076C *arg1) {
    Unk_801A742C_10 sv;
    Unk_801A9BF4 *h = arg0->unkC0;
    Unk_801E1118 *q = &D_801E1118;

    arg0->unk0 = h->unk0;
    arg0->unk2 = 0;
    func_801A910C(q);
    if (h->unk18 != 0) {
        func_801CD028(&arg0->unkB8, (u8 *)arg0->unkC0 + h->unk18, &arg0->unk18);
    }
    if (h->unk1C != 0) {
        func_801CD028(&arg0->unkBC, (u8 *)arg0->unkC0 + h->unk1C, &arg0->unk18);
    }
    GsInitCoordinate2(NULL, &arg0->unk18);
    arg0->unk4 = arg1->unk72 * 12500 + arg1->unk54;
    arg0->unk8 = -(arg1->unk74 * 32000) + 75;
    arg0->unkC = arg1->unk76 * 12500 + arg1->unk5C;
    arg0->unk10 = 0;
    arg0->unk12 = 0;
    arg0->unk14 = 0;
    if (q->unk8 == 0) {
        arg0->unk12 = 180;
        arg1->unk6E -= 180;
    }
    q->unk2C = 0;
    q->unk2E = 0;
    q->unk30 = 0;
    q->unk34 = arg1->unk6C;
    q->unk36 = arg1->unk6E;
    q->unk38 = arg1->unk70;
    arg0->unk30 = arg0->unk4 - arg1->unk72 * 12500;
    arg0->unk34 = arg0->unk8 + arg1->unk74 * 32000;
    arg0->unk38 = arg0->unkC - arg1->unk76 * 12500;
    sv.unk0 = (arg0->unk10 << 12) / 360;
    sv.unk2 = (arg0->unk12 << 12) / 360;
    sv.unk4 = (arg0->unk14 << 12) / 360;
    RotMatrix(&sv, arg0->unk1C);
    arg0->unk18 = 0;
}

void func_801A9EA4(Unk_801E076C *arg0) {
    s32 v[4];
    s32 flag;
    Unk_801E032C *p = D_801E032C[0];
    Unk_801E1118 *q = &D_801E1118;
    Unk_801E0368 *g = &D_801E0368;

    if (q->unk12 != 0) {
        arg0->unk3C = 1;
    }
    if (q->unk8 != 0) {
        if (q->unk12 == 3) {
            q->unk14 = (q->unk28 - p->unkC) / 300 + 7;
            p->unkC += q->unk14 * D_801E6DB4[0];
            if (p->unkC >= q->unk28) {
                func_801A25B4(0x1F);
                q->unk14 = 0;
                p->unkC = q->unk28;
                q->unk12 = 0;
                q->unk16 = 2;
                if (++q->unk10 >= 7) {
                    q->unk10 = 6;
                }
                func_801A910C(q);
                func_801AC70C(1);
                q->unk18 = (s16)g->unk0[0x3F] % 10;
                if (q->unk18 >= 5) {
                    q->unk1A = q->unk18 - 5;
                } else {
                    q->unk1A = q->unk18 + 5;
                }
            }
        } else if (q->unk12 == 1) {
            q->unk14 = (p->unkC - q->unk1C) / 300 + 7;
            p->unkC += q->unk14 * D_801E6DB4[0];
            if (p->unkC >= q->unk20) {
                q->unk12 = 2;
            }
        } else if (q->unk12 == 2) {
            p->unkC += q->unk14 * D_801E6DB4[0];
            if (p->unkC >= q->unk24) {
                q->unk12 = 3;
            }
        }
    } else {
        if (q->unk12 == 3) {
            q->unk14 = (p->unkC - q->unk28) / 300 + 7;
            p->unkC -= q->unk14 * D_801E6DB4[0];
            if (p->unkC <= q->unk28) {
                func_801A25B4(0x1F);
                q->unk14 = 0;
                p->unkC = q->unk28;
                q->unk12 = 0;
                q->unk16 = 2;
                if (--q->unk10 == 0) {
                    q->unk10 = 1;
                }
                func_801A910C(q);
                func_801AC70C(1);
                q->unk1A = (s16)g->unk0[0x3F] % 10;
                if (q->unk1A >= 5) {
                    q->unk18 = q->unk1A - 5;
                } else {
                    q->unk18 = q->unk1A + 5;
                }
            }
        } else if (q->unk12 == 1) {
            q->unk14 = (q->unk1C - p->unkC) / 300 + 7;
            p->unkC -= q->unk14 * D_801E6DB4[0];
            if (p->unkC <= q->unk20) {
                q->unk12 = 2;
            }
        } else if (q->unk12 == 2) {
            p->unkC -= q->unk14 * D_801E6DB4[0];
            if (p->unkC <= q->unk24) {
                q->unk12 = 3;
            }
        }
    }
    p->unk38 = p->unkC - arg0->unk76 * 12500;
    p->unk18 = 0;
    GsSetLsMatrix(p->unk1C);
    RotTrans(&q->unk2C, v, &flag);
    arg0->unk54 = v[0];
    arg0->unk5C = v[2];
    arg0->unk6C = q->unk34 + p->unk10;
    arg0->unk6E = q->unk36 + p->unk12;
    arg0->unk70 = q->unk38 + p->unk14;
}
