#include "common.h"

typedef struct {
    u16 unk0;
    u8 unk2[2];
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 unkA[0xE];
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
} Unk_801A4370;
void func_801CFAE8(s32 arg0);
void free3(void *ptr);
typedef struct Unk_801A44B8 {
    s32 unk0;
    struct Unk_801A44B8 *unk4;
    u16 *unk8;
} Unk_801A44B8;
typedef struct {
    Unk_801A44B8 *unk0;
    Unk_801A44B8 *unk4;
    Unk_801A44B8 *unk8;
    s32 unkC;
} Unk_801DFF80;
void func_801CCBF4(Unk_801DFF80 *arg0, s32 arg1);
void func_801CCCF4(Unk_801DFF80 *arg0, s32 arg1);
Unk_801DFF80 *D_801DFF80;
s16 func_801CD000(Unk_801DFF80 *arg0);
typedef struct {
    u8 unk0[0x10];
    s32 unk10;
} Unk_801A533C;
void func_801A536C(s16 arg0);
typedef struct {
    u8 unk0[0xC];
    s32 unkC;
} Unk_801A5DA0;
typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u16 unkE;
    s16 unk10;
    u16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
} Unk_801E1118;
void func_801A5650(s16 arg0);
extern Unk_801E1118 D_801E1118;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10[0xC];
    s16 unk1C;
    s16 unk1E;
    u16 unk20;
} Unk_801E076C_18;
typedef struct {
    u8 unk0[0x18];
    Unk_801E076C_18 unk18;
    u8 unk3C[0x6];
    u16 unk42;
    u8 unk44[0x2];
    s16 unk46;
    u8 unk48[0xC];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0xC];
    u16 unk6C;
    u16 unk6E;
    u8 unk70[0x2];
    s16 unk72;
    s16 unk74;
    s16 unk76;
    s16 unk78;
} Unk_801E076C;
extern Unk_801E076C *D_801E076C[];
typedef struct {
    u8 unk0[0xC];
    s32 unkC;
} Unk_801A6968;
void func_80183E88(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
typedef struct {
    u8 unk0[0xC];
    s32 unkC;
} Unk_801A69E0;
void func_801A25B4(s32 arg0);
void func_801862AC(s32 arg0, s32 arg1);
extern char D_8017196C[];
s16 D_801DFF98;
void func_801A6528(void);
s16 func_801808F0(s32 arg0, s32 arg1);
void func_801A4A68(s32 arg0, s32 arg1);
u16 *func_801A44B8(u16 arg0);
void func_801CCDF8(Unk_801DFF80 *arg0);
void func_801A43F4(s32 arg0);
typedef struct {
    u8 unk0[0xC];
    s16 unkC;
    u8 unkE[0xE];
    u16 *unk1C;
    u16 *unk20;
} Unk_801A461C;
void func_801A4B18(s32 arg0, s32 arg1);
void func_801A4BC8(s32 arg0, s32 arg1, s32 arg2);
void func_8018C1B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80184094(void);
void func_801A8000(s32 arg0, s32 arg1, s32 arg2);
s16 D_801DFF8A;
s16 D_801DFF8C;
s16 D_801DFF8E;
s16 D_801DFF90;
typedef struct { u16 unk0; u16 unk2; } Unk_801DFE68;
extern Unk_801DFE68 D_801DFE68;
extern u16 D_801E03E6[];
void func_801AAA9C(s16 arg0, s16 arg1);
void func_801AC70C(s32 arg0);
s32 func_801A5DA0(Unk_801A5DA0 *arg0);
void func_801A8198(s32 a, s32 b, s32 c);
void func_801AA8DC(void);
void func_801A59B0(Unk_801E1118 *arg0, Unk_801DFE68 *arg1);
s32 func_801A540C();
void func_801A5554(void);
extern s32 (*D_801DFEE4)();
extern s32 (*D_801DFEE0)(Unk_801A5DA0 *arg0);
extern void (*D_801DFEDC)(void);
extern s32 D_801D7F68[];
extern s32 D_801DFD94[];
void func_8018C50C(s32 a, s32 b, s32 c, s16 d, s16 e);
void func_8018C554(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
extern u16 D_801E1126[];
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14;
    s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34;
    u8 unk38[0x24];
    void *unk5C[1];
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
extern s32 D_801DFED4;
s16 D_801DFF88;
void func_801A4FA4(s16 arg0);
void func_801A7BA4(void);
void func_801A252C(void);
void func_801A2288(void);
extern char D_8017186C[];
typedef struct {
    u8 unk0[0xC];
    s32 unkC;
    s32 unk10;
} Unk_801A6A1C;
typedef struct {
    u8 unk0[0x244];
    s32 unk244;
} Unk_801E0368;
extern Unk_801E0368 D_801E0368;
void func_801A461C(u16 arg0, s32 arg1, u16 arg2);
void func_801A4824(u16 arg0, s32 arg1, s32 arg2, u16 arg3);
s16 D_801DFF9C;
s16 D_801DFF9E;

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A3DD4);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A3F90);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A417C);

void func_801A4370(Unk_801A4370 *arg0) {
    if (arg0 != NULL) {
        func_801CFAE8(arg0->unk1C);
        free3(arg0);
    }
}

void func_801A43A8(s32 arg0) {
    if (D_801DFF80->unkC == 0) {
        func_801CCBF4(D_801DFF80, arg0);
    } else {
        D_801DFF80->unk8 = D_801DFF80->unk4;
        func_801CCCF4(D_801DFF80, arg0);
    }
}

void func_801A43F4(s32 arg0) {
    Unk_801DFF80 *p = D_801DFF80;
    u16 *q;

    if (p->unkC == 0) {
        return;
    }
    q = func_801A44B8((u16)arg0);
    if (q == NULL) {
        return;
    }
    p->unk8 = p->unk0;
    while (1) {
        if (q == p->unk8->unk8) {
            if (q != NULL) {
                func_801CFAE8(((Unk_801A4370 *)q)->unk1C);
                free3(q);
            }
            func_801CCDF8(p);
            return;
        }
        if (func_801CD000(p) != 0) {
            return;
        }
        p->unk8 = p->unk8->unk4;
    }
}

u16 *func_801A44B8(u16 arg0) {
    Unk_801DFF80 *p = D_801DFF80;
    u16 *q;

    if (p->unkC == 0) {
        return NULL;
    }
    p->unk8 = p->unk0;
    while (1) {
        q = p->unk8->unk8;
        if (q != NULL && *q == arg0) {
            break;
        }
        if (func_801CD000(p) != 0) {
            return NULL;
        }
        p->unk8 = p->unk8->unk4;
    }
    return q;
}

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A4554);

void func_801A461C(u16 arg0, s32 arg1, u16 arg2) {
    Unk_801DFF80 *p = D_801DFF80;
    u16 *q;
    Unk_801A461C *r;

    if (p->unkC == 0) {
        q = NULL;
    } else {
        p->unk8 = p->unk0;
        while (1) {
            q = p->unk8->unk8;
            if (q != NULL && *q == arg0) {
                break;
            }
            if (func_801CD000(p) != 0) {
                q = NULL;
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    }
    if (q != NULL) {
        r = (Unk_801A461C *)((Unk_801A4370 *)q)->unk1C;
        if (r->unk1C != NULL && r->unk20 != NULL) {
            r->unk20[arg1] = arg2;
            ((Unk_801A4370 *)q)->unk6 = 1;
        }
    }
}

void func_801A4708(u16 arg0) {
    Unk_801DFF80 *p = D_801DFF80;
    u16 *q;
    u16 *t;
    Unk_801A461C *r;
    s32 i;

    if (p->unkC == 0) {
        q = NULL;
    } else {
        p->unk8 = p->unk0;
        while (1) {
            t = p->unk8->unk8;
            if (t != NULL && *t == arg0) {
                q = t;
                break;
            }
            if (func_801CD000(p) != 0) {
                q = NULL;
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    }
    if (q != NULL) {
        r = (Unk_801A461C *)((Unk_801A4370 *)q)->unk1C;
        if (r->unk1C != NULL && r->unk20 != NULL) {
            for (i = 0; i < r->unkC; i++) {
                r->unk20[i] = r->unk1C[i];
                r = (Unk_801A461C *)((Unk_801A4370 *)q)->unk1C;
            }
            ((Unk_801A4370 *)q)->unk6 = 1;
        }
    }
}

void func_801A4824(u16 arg0, s32 arg1, s32 arg2, u16 arg3) {
    Unk_801DFF80 *p = D_801DFF80;
    u16 *q;
    u16 *t;
    Unk_801A461C *r;
    s32 i;

    if (p->unkC == 0) {
        q = NULL;
    } else {
        p->unk8 = p->unk0;
        while (1) {
            t = p->unk8->unk8;
            if (t != NULL && *t == arg0) {
                q = t;
                break;
            }
            if (func_801CD000(p) != 0) {
                q = NULL;
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    }
    if (q != NULL) {
        r = (Unk_801A461C *)((Unk_801A4370 *)q)->unk1C;
        if (r->unk1C != NULL && r->unk20 != NULL) {
            for (i = arg1; i <= arg2; i++) {
                ((Unk_801A461C *)((Unk_801A4370 *)q)->unk1C)->unk20[i] = arg3;
            }
            ((Unk_801A4370 *)q)->unk6 = 1;
        }
    }
}

void func_801A4944(u16 arg0, s32 arg1, s32 arg2) {
    Unk_801DFF80 *p = D_801DFF80;
    u16 *q;
    u16 *t;
    Unk_801A461C *r;
    s32 i;

    if (p->unkC == 0) {
        q = NULL;
    } else {
        p->unk8 = p->unk0;
        while (1) {
            t = p->unk8->unk8;
            if (t != NULL && *t == arg0) {
                q = t;
                break;
            }
            if (func_801CD000(p) != 0) {
                q = NULL;
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    }
    if (q != NULL) {
        r = (Unk_801A461C *)((Unk_801A4370 *)q)->unk1C;
        if (r->unk1C != NULL && r->unk20 != NULL) {
            for (i = arg1; i <= arg2; i++) {
                ((Unk_801A461C *)((Unk_801A4370 *)q)->unk1C)->unk20[i] = ((Unk_801A461C *)((Unk_801A4370 *)q)->unk1C)->unk1C[i];
            }
            ((Unk_801A4370 *)q)->unk6 = 1;
        }
    }
}

void func_801A4A68(s32 arg0, s32 arg1) {
    Unk_801DFF80 *p = D_801DFF80;
    u16 *q;
    u16 *t;

    if (p->unkC == 0) {
        q = NULL;
    } else {
        p->unk8 = p->unk0;
        while (1) {
            t = p->unk8->unk8;
            if (t != NULL && *t == (u16)arg0) {
                q = t;
                break;
            }
            if (func_801CD000(p) != 0) {
                q = NULL;
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    }
    if (q != NULL) {
        ((Unk_801A4370 *)q)->unk4 = arg1;
    }
}

void func_801A4B18(s32 arg0, s32 arg1) {
    Unk_801DFF80 *p = D_801DFF80;
    u16 *q;
    u16 *t;

    if (p->unkC == 0) {
        q = NULL;
    } else {
        p->unk8 = p->unk0;
        while (1) {
            t = p->unk8->unk8;
            if (t != NULL && *t == (u16)arg0) {
                q = t;
                break;
            }
            if (func_801CD000(p) != 0) {
                q = NULL;
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    }
    if (q != NULL) {
        ((Unk_801A4370 *)q)->unk8 = arg1;
    }
}

void func_801A4BC8(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFF80 *p = D_801DFF80;
    u16 *q;
    u16 *t;

    if (p->unkC == 0) {
        q = NULL;
    } else {
        p->unk8 = p->unk0;
        while (1) {
            t = p->unk8->unk8;
            if (t != NULL && *t == (u16)arg0) {
                q = t;
                break;
            }
            if (func_801CD000(p) != 0) {
                q = NULL;
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    }
    if (q != NULL) {
        ((Unk_801A4370 *)q)->unk18 = arg1;
        ((Unk_801A4370 *)q)->unk1A = arg2;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A4C88);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A4E04);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A4FA4);

void func_801A5254(s32 arg0) {
    Unk_801E02D8 *p;
    s32 i;

    D_801DFF88 = 0;
loop:
    func_801A4FA4(arg0);
    if (D_801DFF88 != 1) {
        return;
    }
    if (func_801808F0(1, 0) == 0) {
        goto loop;
    }
    D_801DFF88 = 0;
    D_801DFED4 = 0;
    p = &D_801E02D8;
    func_801A7BA4();
    func_801A252C();
    func_801A2288();
    for (i = 0; i < 3; i++) {
        func_801A43F4((u16)i);
    }
    for (i = 0; i < p->unk34; i++) {
        if (p->unk5C[i] != NULL) {
            free3(p->unk5C[i]);
            p->unk5C[i] = NULL;
        }
    }
    p->unk34 = 0;
}

s32 func_801A533C(Unk_801A533C *arg0) {
    if (arg0->unk10 == 8) {
        func_801A536C(1);
    }
    return 0;
}

void func_801A536C(s16 arg0) {
    if (arg0 != 0) {
        func_8018C1B0(3, 0, 0, 2);
    }
    func_80184094();
    func_801A4A68(0, 1);
    func_801A4A68(1, 1);
    func_801A4A68(2, 1);
    func_801A4BC8(1, 0, 0);
    func_801A4BC8(2, 0, 3);
    func_801A8000(3, 10, 0);
    D_801DFF8C = 1;
    D_801DFF8A = 1;
    D_801DFF90 = 0;
    D_801DFF8E = 0;
}

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A540C);

void func_801A5554(void) {
    Unk_801DFE68 *q = &D_801DFE68;
    Unk_801E1118 *p = &D_801E1118;
    s16 r = (s16)D_801E03E6[0] % 10;

    if (r == p->unk18) {
        func_801AAA9C(1, q->unk2);
    } else if (r == p->unk1A) {
        func_801AAA9C(0, q->unk2);
    }
    if (p->unk12 == 0 && p->unkE == 1) {
        if (p->unk16 > 0) {
            p->unk16--;
        }
        if (p->unk16 == 0) {
            p->unk16 = -1;
            func_801AC70C(0);
            func_801A5650(0);
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_80171820);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A5650);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A59B0);

void func_801A5B10(s16 arg0) {
    Unk_801E076C *p = D_801E076C[0];
    u16 v = D_801E1126[0];
    Unk_801DFE68 *q = &D_801DFE68;

    if (v == 1) {
        if (arg0 != 0) {
            if (D_801DFE68.unk0 == 1) {
                p->unk46 = 2;
                func_8018C50C(0x4CA2C, 0, (q->unk2 - 1) * 100000 - 195000, 270, 0);
            } else {
                p->unk46 = 3;
                func_8018C50C(0x4A31C, 0, (q->unk2 - 1) * 100000 - 195000, 270, 0);
            }
        } else {
            if (D_801DFE68.unk0 == 1) {
                p->unk46 = 2;
                func_8018C50C(0x4BF3C, 0, (q->unk2 - 1) * 100000 - 200000, 90, 0);
            } else {
                p->unk46 = 3;
                func_8018C50C(0x4982C, 0, (q->unk2 - 1) * 100000 - 200000, 90, 0);
            }
        }
    }
}

void func_801A5C34(void) {
    Unk_801E1118 *p = &D_801E1118;

    func_801A8198(2, 0, 1);
    if (p->unkA != 0) {
        p->unk12 = 2;
        p->unk18 = 2;
        p->unk1A = 7;
    } else {
        func_801AA8DC();
    }
    func_801A59B0(p, &D_801DFE68);
    D_801DFEE4 = func_801A540C;
    D_801DFEE0 = func_801A5DA0;
    D_801DFEDC = func_801A5554;
}

void func_801A5CD4(void) {
    Unk_801DFE68 *p = &D_801DFE68;
    s32 i;

    if (D_801DFE68.unk0 == 2) {
        if (p->unk2 == D_801DFE68.unk0) {
            func_8018C554(1, D_801DFD94, 0x13, 0x41, 3, 0x5A, 7, 0, 0);
        } else {
            i = (p->unk2 - 1) * 3;
            func_8018C50C(D_801D7F68[i], 0, D_801D7F68[i + 1], D_801D7F68[i + 2], 1);
        }
    }
}

s32 func_801A5DA0(Unk_801A5DA0 *arg0) {
    Unk_801E1118 *p = &D_801E1118;

    if (arg0->unkC == 0x100010 || arg0->unkC == 0x100020) {
        p->unk4 = 0;
        func_801A5650(0);
        return 1;
    }
    if (p->unkC != 0) {
        p->unkC = 0;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_8017186C);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A5E0C);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A6528);

void func_801A68F0(s32 *arg0) {
    Unk_801E076C *p = D_801E076C[0];

    if (p->unk42 & 0x40) {
        *arg0 = 0xFFFFFF;
        return;
    }
    *arg0 = 0xFB0000;
    if ((u16)(p->unk6C + 14) >= 30 || (u16)(p->unk6E - 31) < 300) {
        *arg0 = 0xFB0001;
    }
}

s32 func_801A6968(Unk_801A6968 *arg0) {
    switch (arg0->unkC) {
    case 0xFB0000:
        /* " 8電話1をかける       3○" */
        func_80183E88(" 8\223d\230b1\202\360\202\251\202\257\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFB0001:
        /* " 外に出る         3○" */
        func_80183E88(" \212O\202\311\217o\202\351         3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    default:
        return 0;
    }
    return 1;
}

void func_801A69E0(Unk_801A69E0 *arg0) {
    if (arg0->unkC == 0x405) {
        func_801A25B4(0x1C);
        func_801862AC(0x205, 2);
    }
}

s32 func_801A6A1C(Unk_801A6A1C *arg0) {
    Unk_801E0368 *p = &D_801E0368;

    if (arg0->unk10 == 6) {
        if (arg0->unkC == 0) {
            p->unk244 = -1;
        }
        /* D_8017186C */
        func_80183E88(D_8017186C, 3, -1, 0, -1, 0, 0);
        func_801A4A68(0x206, 1);
        func_801A4824(0x206, 5, 7, 0x24C6);
        func_801A461C(0x206, 4, 0x24DF);
        D_801DFF9C = 1;
        D_801DFF9E = 0;
    }
    return 0;
}

void func_801A6AC4(void) {
    D_801DFF98 = 0;
    while (1) {
        func_801A6528();
        if (D_801DFF98 != 1) {
            break;
        }
        func_801808F0(0, 0);
        /* " 2ほかにご用はありますか？, 方向キー上下で選んで下さい,      決定 3○ 2切る 4×" */
        func_80183E88(D_8017196C, 3, -1, 0, -1, 0, 0);
        func_801A4A68(0x206, 1);
        func_801A4A68(0x205, 1);
    }
}

void func_801A6B50(u16 arg0) {
    Unk_801E076C *p = D_801E076C[0];
    Unk_801E076C_18 *q = &p->unk18;

    q->unk1C = (arg0 & 0xF000) >> 12;
    q->unk1E = (arg0 & 0xF00) >> 8;
    q->unk0 = (arg0 & 0xFF) * 100;
    q->unk4 = p->unk54 + p->unk72 * 12500;
    q->unk8 = p->unk58 - p->unk74 * 32000 - p->unk78;
    q->unkC = p->unk5C + p->unk76 * 12500;
    q->unk20 = p->unk6E;
}

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A6C34);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A6EB4);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A7084);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A727C);

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", func_801A742C);

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_80171900);

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_80171938);

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_8017196C);
