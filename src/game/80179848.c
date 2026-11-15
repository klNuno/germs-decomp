#include "common.h"

typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Unk_8017CAC8;
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    void *unk8;
    Unk_8017CAC8 *unkC;
} Unk_8017C9F8;
typedef struct Unk_8017CCE4 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u8 pad6[0x8];
    u16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 pad1C[0xC];
    s32 unk28;
    u8 pad2C[0x14];
    s32 unk40;
    s32 unk44;
    s32 unk48;
    u8 pad4C[0x2C];
    void *unk78;
    void *unk7C;
    void *unk80;
    void *unk84;
    Unk_8017C9F8 *unk88;
    void *unk8C;
} Unk_8017CCE4;
typedef struct Unk_8017D0E0 {
    s32 unk0;
    struct Unk_8017D0E0 *unk4;
    Unk_8017CCE4 *unk8;
} Unk_8017D0E0;
typedef struct {
    Unk_8017D0E0 *unk0;
    Unk_8017D0E0 *unk4;
    Unk_8017D0E0 *unk8;
    s32 unkC;
} Unk_801DFE5C;
s16 func_801CD000(Unk_801DFE5C *arg0);
Unk_801DFE5C *D_801DFE5C;
void func_801CCBF4(Unk_801DFE5C *arg0, s32 arg1);
void func_801CCCF4(Unk_801DFE5C *arg0, s32 arg1);
void func_801D3650(void);
s16 D_801DFC80;
extern s16 D_801E71C8;
typedef struct {
    u8 pad0[0x24E];
    s16 unk24E;
    s16 unk250;
    s16 unk252;
} Unk_801E0368;
u8 D_801DFC8C;
u8 D_801DFC8D[1];
u8 D_801DFC8E;
extern Unk_801E0368 D_801E0368;
typedef struct {
    u8 pad0[0xC];
    s32 unkC;
} Unk_8017E504;
s16 D_801DFE64;
void func_8017A3E4(void);
void func_8017E25C(void);
void func_8018748C(void);
u16 D_801DFE60;
void func_80184160(void);
void func_801A4A68(s32 arg0, s32 arg1);
typedef struct {
    u8 pad0[0x6];
    s16 unk6;
    u16 unk8;
} Unk_80184100;
void func_801A461C(s32 arg0, s32 arg1, s32 arg2);
void func_801A2678(s32 arg0);
typedef struct {
    u16 unk0;
    u16 unk2;
} Unk_801DFCAC;
Unk_801DFCAC **D_801DFCAC;
s16 D_801DFCB0;
void func_801749E8(Unk_801DFCAC **arg0);
s16 D_801DFE7A;
extern s32 D_801E6DB4[];
typedef struct {
    u8 pad0[0x42];
    u16 unk42;
} Unk_801E076C;
extern s32 D_801E05B0[];
extern Unk_801E076C *D_801E076C[];
extern char D_80170250[];
void *func_801CC898(u32 size);
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
void *memset(void *dst, s32 c, u32 n);
extern char D_801DFC84[];
void free3(void *ptr);
typedef struct {
    s16 unk0;
    u8 pad2[0x6];
    s16 unk8;
    u8 padA[0xA];
    struct {
        s16 unk0;
        u8 pad2[0x96];
    } unk14[4];
} Unk_801802A0;
void func_801A4824(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
typedef struct {
    s16 unk0;
    s16 unk2;
} Unk_80181C10;
void func_801A43F4(s32 arg0);
void func_8018B924(void);
void func_8018BC50(void);
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Unk_80184230;
typedef struct {
    u8 pad0[0x1C];
    Unk_80184230 *unk1C;
} Unk_801A44B8;
Unk_801A44B8 *func_801A44B8(u16 arg0);
s32 ClearImage2(Unk_80184230 *rect, s32 r, s32 g, s32 b);
s16 func_80182860(s32 arg0, s32 arg1);
s16 D_801DFE72;
typedef struct {
    u8 pad0[0x24];
    u16 unk24;
    u8 pad26[0x16];
    s32 *unk3C;
} Unk_80184338;
s16 D_801DFCE6;
s16 D_801DFE78;
s32 func_8017D414(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_801CCDF8(Unk_801DFE5C *arg0);
s16 D_801DFE7C;
s16 D_801DFE7E;
void func_801A3CC0(s32 arg0);
void func_80186128(s32 arg0, s32 arg1);
typedef struct {
    u8 pad0[0x6];
    s16 unk6;
    u8 pad8[0xA];
    u16 unk12;
} Unk_801DFFE8;
typedef struct {
    u8 pad0[0xA];
    u16 unkA;
    s16 unkC;
    s16 unkE;
    u8 pad10[0x4];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
} Unk_80184814;
extern Unk_801DFFE8 D_801DFFE8;

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80179848);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80179C50);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80179E50);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170250);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170270);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170290);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_801702B0);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_801702C8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A108);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A3E4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A534);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A6E8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A86C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017AAB4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017AC88);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017AF18);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017B1E8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017B3E8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017B7CC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017BBB0);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017BD24);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017BF50);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017C234);

void func_8017C9F8(Unk_8017CAC8 *arg0, Unk_8017CAC8 *arg1) {
    Unk_801DFE5C *p = D_801DFE5C;
    Unk_8017C9F8 *q;

    if (p->unkC != 0) {
        p->unk8 = p->unk0;
        while (1) {
            Unk_8017CCE4 *e = p->unk8->unk8;
            if (e != NULL && (e->unkE & 0x10)) {
                q = e->unk88;
                if (q->unkC == arg0) {
                    break;
                }
            }
            if (func_801CD000(p) != 0) {
                q = NULL;
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    } else {
        q = NULL;
    }
    if (q != NULL) {
        q->unkC = arg1;
        q->unk8 = arg1 + 1;
    }
}

void func_8017CAC8(Unk_8017C9F8 **arg0, Unk_8017CAC8 *arg1) {
    if (*arg0 == NULL) {
        *arg0 = func_801CC898(0x10);
        if (*arg0 == NULL) {
            func_801CD54C(3, D_80170250, D_801DFC84, 0x49);
        }
    } else {
        memset(*arg0, 0, 0x10);
    }
    (*arg0)->unk0 = arg1->unk0;
    (*arg0)->unk2 = arg1->unk2;
    (*arg0)->unk4 = arg1->unk4;
    (*arg0)->unk6 = arg1->unk6;
    (*arg0)->unk8 = arg1 + 1;
    (*arg0)->unkC = arg1;
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017CB98);

void func_8017CCE4(Unk_8017CCE4 *arg0) {
    if (arg0 != NULL) {
        if (arg0->unk78 != NULL) {
            free3(arg0->unk78);
        }
        if (arg0->unk7C != NULL) {
            free3(arg0->unk7C);
        }
        if (arg0->unk80 != NULL) {
            free3(arg0->unk80);
        }
        if (arg0->unk84 != NULL) {
            free3(arg0->unk84);
        }
        if (arg0->unk88 != NULL) {
            free3(arg0->unk88);
        }
        if (arg0->unk2 != 0) {
            free3(arg0->unk8C);
        }
        free3(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017CDA4);

void func_8017CF10(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFE5C *p = D_801DFE5C;

    if (p->unkC != 0) {
        p->unk8 = p->unk0;
        while (1) {
            Unk_8017CCE4 *e = p->unk8->unk8;
            if (e != NULL && e->unk0 != 0) {
                e->unk28 = 0;
                e->unk40 = e->unk10 - arg0;
                e->unk44 = e->unk14 - arg1;
                e->unk48 = e->unk18 - arg2;
            }
            if (func_801CD000(p) != 0) {
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    }
}

s32 func_8017CFE4(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFE5C *p = D_801DFE5C;
    s32 r;
    s32 ret;

    if (p->unk8 == NULL) {
        return 0;
    }
    p->unk8 = p->unk0;
    while (1) {
        Unk_8017CCE4 *e = p->unk8->unk8;
        if (e != NULL && e->unk0 != 0 && (e->unkE & 1)) {
            r = func_8017D414(e->unk84, arg0, arg2, arg1);
            if (r != 0 && r != 0xC8 && (r & 0xFF0000) != 0xFF0000) {
                ret = 1;
                break;
            }
        }
        if (func_801CD000(p) != 0) {
            ret = 0;
            break;
        }
        p->unk8 = p->unk8->unk4;
    }
    return ret;
}

void func_8017D0E0(void) {
    Unk_801DFE5C *p = D_801DFE5C;

    if (p->unkC != 0) {
        p->unk8 = p->unk0;
        while (1) {
            if (p->unk8->unk8 != NULL && p->unk8->unk8->unk0 != 0) {
                p->unk8->unk8->unk4 = 0;
            }
            if (func_801CD000(p) != 0) {
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    }
}

void func_8017D170(s32 arg0) {
    if (D_801DFE5C->unkC == 0) {
        func_801CCBF4(D_801DFE5C, arg0);
    } else {
        D_801DFE5C->unk8 = D_801DFE5C->unk4;
        func_801CCCF4(D_801DFE5C, arg0);
    }
}

void func_8017D1BC(void) {
    Unk_801DFE5C *p = D_801DFE5C;
    Unk_8017CCE4 *e;

    while (1) {
        if (p->unkC == 0) {
            break;
        }
        e = p->unk8->unk8;
        if (e != NULL) {
            if (e->unk78 != NULL) {
                free3(e->unk78);
            }
            if (e->unk7C != NULL) {
                free3(e->unk7C);
            }
            if (e->unk80 != NULL) {
                free3(e->unk80);
            }
            if (e->unk84 != NULL) {
                free3(e->unk84);
            }
            if (e->unk88 != NULL) {
                free3(e->unk88);
            }
            if (e->unk2 != 0) {
                free3(e->unk8C);
            }
            free3(e);
        }
        func_801CCDF8(p);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017D2B8);

void func_8017D3F0(void) {
    D_801DFC80 = 0;
    func_801D3650();
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017D414);

s32 func_8017D564(void) {
    return D_801E71C8 == 0;
}

void func_8017D574(u32 arg0) {
    s32 t = (arg0 >> 16) & 0xFF;

    D_801DFC8C = t;
    if (t != 0x80) {
        return;
    }
    D_801DFC8D[0] = arg0 >> 8;
    D_801DFC8E = arg0;
    D_801E0368.unk252 = 0;
    D_801E0368.unk250 = 0;
    switch (D_801DFC8D[0]) {
    case 1:
        D_801E0368.unk252 = 1;
        break;
    case 2:
        D_801E0368.unk250 = 1;
        break;
    case 3:
        D_801E0368.unk252 = 1;
        D_801E0368.unk250 = 1;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017D604);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017DAE8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017DD70);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017DFA4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017E25C);

s32 func_8017E504(Unk_8017E504 *arg0) {
    s32 v = arg0->unkC;

    if (v == 0xF0233C) {
        D_801DFE64 = 5;
    } else if (v == 0xF02350) {
        D_801DFE64 = 6;
    } else if (v == 0xF0235A) {
        D_801DFE64 = 7;
    }
    return 0;
}

void func_8017E544(void) {
    D_801DFE60 = 0;
    func_8017A3E4();
    while (1) {
        func_8017E25C();
        if (D_801DFE60 != 1) {
            break;
        }
        func_8018748C();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017E594);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017E99C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017EBF8);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170430);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017EE2C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017EFEC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017F6F4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017FF0C);

void func_801802A0(Unk_801802A0 *arg0, s16 arg1) {
    s32 i;
    s32 a;

    if (arg1 != 0) {
        i = arg0->unk8 - 1;
        if (i < 0) {
            i = 3;
        }
    } else {
        i = arg0->unk8 + 1;
        if (i >= 4) {
            i = 0;
        }
    }
    if (arg0->unk0 != 0) {
loop:
        if (arg0->unk14[i].unk0 == 0) {
            if (arg1 != 0) {
                i--;
                if (i < 0) {
                    i = 3;
                }
            } else {
                i++;
                if (i >= 4) {
                    i = 0;
                }
            }
            goto loop;
        }
    }
    arg0->unk8 = i;
    func_801A4824(0x200, 9, 0xC, 0xC252);
    func_801A461C(0x200, i + 9, 0x3FF);
    a = 1;
    if (arg0->unk0 == 0) {
        a = 0xF;
    }
    func_801A2678(a);
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801803BC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8018073C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801808F0);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80180B04);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80180D8C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8018164C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80181818);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80181A64);

void func_80181C10(Unk_80181C10 *arg0) {
    func_801A2678(8);
    switch (arg0->unk2) {
    case 1:
        arg0->unk2 = 0;
        if (arg0->unk0 == 1) {
            func_801A43F4(0x237);
            func_801A43F4(0x238);
            func_801A43F4(0x239);
        } else if (arg0->unk0 == 2) {
            func_8018B924();
            func_801A4A68(0x20A, 0);
            func_801A4A68(0x20C, 0);
            func_801A4A68(0x212, 0);
        } else if (arg0->unk0 == 3) {
            func_801A4A68(0x23D, 0);
        } else if (arg0->unk0 == 4) {
            func_801A43F4(0x23A);
            func_801A43F4(0x23B);
            func_801A43F4(0x23C);
        }
        break;
    case 2:
        if (arg0->unk0 == 1) {
            arg0->unk2 = 1;
            func_801A4A68(0x239, 0);
        } else if (arg0->unk0 == 2) {
            arg0->unk2 = 1;
            func_8018BC50();
        }
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80181D2C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80181F9C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80182300);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80182518);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80182860);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80182D34);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801830A0);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801831EC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801834AC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80183618);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801837F0);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80183CFC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80183E88);

void func_80184094(void) {
    Unk_801E0368 *p = &D_801E0368;

    func_80184160();
    func_801A4A68(0x403, 0);
    func_801A4A68(0x404, 0);
    func_801A4A68(0x40A, 0);
    func_801A4A68(0x40D, 0);
    if (p->unk24E != 0) {
        p->unk24E = 0;
    }
}

void func_80184100(Unk_80184100 *arg0) {
    if (arg0->unk8 & 8) {
        arg0->unk8 &= ~8;
        arg0->unk6 = 1;
        func_801A4A68(0x40A, 0);
        func_801A461C(0x40A, 3, 0x14BF);
        func_801A2678(0x11);
    }
}

void func_80184160(void) {
    Unk_801DFCAC *p;

    if (D_801DFCAC != NULL) {
        p = *D_801DFCAC;
        if (p->unk0 == 5 && (u16)(p->unk2 - 3) < 2) {
            p->unk2 = 0;
        }
        D_801DFCAC = NULL;
    }
    if (D_801DFCB0 >= 0) {
        D_801DFCB0 = -1;
    }
}

void func_801841C4(void) {
    D_801DFE7A -= D_801E6DB4[0];
    if (D_801DFE7A > 0) {
        (*D_801DFCAC)->unk2 = 4;
    } else {
        D_801DFE7A = 0;
        (*D_801DFCAC)->unk2 = 3;
    }
    func_801749E8(D_801DFCAC);
}

void func_80184230(s32 arg0) {
    Unk_80184230 rect;
    Unk_801A44B8 *p;

    if (D_801DFE72 == 3) {
        D_801DFE72 = 0;
        p = func_801A44B8(D_801DFCB0);
        if (p != NULL) {
            rect.unk0 = p->unk1C->unk0;
            rect.unk2 = p->unk1C->unk2;
            rect.unk4 = p->unk1C->unk4;
            rect.unk6 = p->unk1C->unk6;
            ClearImage2(&rect, 0, 0, 0);
        }
    }
    if (func_80182860(arg0, 1) != 0) {
        D_801DFE7A -= D_801E6DB4[0];
        if (D_801DFE7A > 0) {
            (*D_801DFCAC)->unk2 = 4;
        } else {
            D_801DFE7A = 0;
            (*D_801DFCAC)->unk2 = 3;
        }
        func_801749E8(D_801DFCAC);
    }
}

void func_80184338(Unk_80184338 *arg0) {
    Unk_80184230 rect;
    Unk_801A44B8 *p;
    s32 v;

    if (D_801DFCE6 != 0) {
        D_801DFCE6 = 0;
        return;
    }
    v = *arg0->unk3C;
    arg0->unk24 = D_801DFE78;
    if (D_801DFE72 == 3) {
        D_801DFE72 = 0;
        p = func_801A44B8(D_801DFCB0);
        if (p != NULL) {
            rect.unk0 = p->unk1C->unk0;
            rect.unk2 = p->unk1C->unk2;
            rect.unk4 = p->unk1C->unk4;
            rect.unk6 = p->unk1C->unk6;
            ClearImage2(&rect, 0, 0, 0);
        }
    }
    D_801DFCE6 = func_80182860(v, 0);
}

void func_80184408(void) {
    s32 v = -1;
    D_801DFCB0 = v;
    D_801E076C[0]->unk42 &= 0xFEFF;
    D_801E05B0[0] = v;
}

void func_80184434(s16 arg0) {
    if (D_801E05B0[0] < 0) {
        return;
    }
    if (arg0 == 0) {
        if (D_801DFE78 != 0x1AA) {
            if (D_801DFE78 != 0x21A) {
                return;
            }
            if (D_801DFE7E == 0) {
                func_801A3CC0(3);
                D_801DFE7E = 1;
            }
            return;
        }
    } else if (D_801DFE78 != 0x182) {
        return;
    }
    if (D_801DFE7C == 0) {
        func_80186128(0, 3);
        D_801DFE7C = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_801844D4);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184698);

void func_80184814(Unk_80184814 *arg0) {
    Unk_801DFFE8 *s;

    arg0->unk14 += D_801E6DB4[0] * arg0->unk22;
    if (arg0->unk22 > 0) {
        if (arg0->unk14 >= arg0->unkE) {
            s = &D_801DFFE8;
            if (arg0->unkA == 3) {
                if (arg0->unk24 != 0) {
                    arg0->unkA = 0;
                    arg0->unk24 = 0;
                    arg0->unkE = arg0->unkC;
                    arg0->unk14 = arg0->unkC;
                } else {
                    arg0->unkA = 1;
                    arg0->unk24 = 0;
                    arg0->unk14 = arg0->unkE;
                }
            } else if (arg0->unkA == 2) {
                arg0->unkA = 0;
                arg0->unk14 = arg0->unkE;
            }
            if (s->unk12 & 4) {
                s->unk12 &= ~4;
                if (s->unk12 == 0) {
                    s->unk6 = 1;
                }
            }
        }
    } else {
        if (arg0->unkE >= arg0->unk14) {
            s = &D_801DFFE8;
            if (arg0->unkA == 3) {
                if (arg0->unk24 != 0) {
                    arg0->unkA = 0;
                    arg0->unk24 = 0;
                    arg0->unkE = arg0->unkC;
                    arg0->unk14 = arg0->unkC;
                } else {
                    arg0->unkA = 1;
                    arg0->unk24 = 0;
                    arg0->unk14 = arg0->unkE;
                }
            } else if (arg0->unkA == 2) {
                arg0->unkA = 0;
                arg0->unk14 = arg0->unkE;
            }
            if (s->unk12 & 4) {
                s->unk12 &= ~4;
                if (s->unk12 == 0) {
                    s->unk6 = 1;
                }
            }
        }
    }
}

void func_80184928(Unk_80184814 *arg0) {
    Unk_801DFFE8 *s;

    arg0->unk18 += D_801E6DB4[0] * arg0->unk22;
    if (arg0->unk22 > 0) {
        if (arg0->unk18 >= arg0->unkE) {
            s = &D_801DFFE8;
            if (arg0->unkA == 3) {
                if (arg0->unk24 != 0) {
                    arg0->unkA = 0;
                    arg0->unk24 = 0;
                    arg0->unkE = arg0->unkC;
                    arg0->unk18 = arg0->unkC;
                } else {
                    arg0->unkA = 1;
                    arg0->unk24 = 0;
                    arg0->unk18 = arg0->unkE;
                }
            } else if (arg0->unkA == 2) {
                arg0->unkA = 0;
                arg0->unk18 = arg0->unkE;
            }
            if (s->unk12 & 4) {
                s->unk12 &= ~4;
                if (s->unk12 == 0) {
                    s->unk6 = 1;
                }
            }
        }
    } else {
        if (arg0->unkE >= arg0->unk18) {
            s = &D_801DFFE8;
            if (arg0->unkA == 3) {
                if (arg0->unk24 != 0) {
                    arg0->unkA = 0;
                    arg0->unk24 = 0;
                    arg0->unkE = arg0->unkC;
                    arg0->unk18 = arg0->unkC;
                } else {
                    arg0->unkA = 1;
                    arg0->unk24 = 0;
                    arg0->unk18 = arg0->unkE;
                }
            } else if (arg0->unkA == 2) {
                arg0->unkA = 0;
                arg0->unk18 = arg0->unkE;
            }
            if (s->unk12 & 4) {
                s->unk12 &= ~4;
                if (s->unk12 == 0) {
                    s->unk6 = 1;
                }
            }
        }
    }
}

void func_80184A3C(Unk_80184814 *arg0) {
    Unk_801DFFE8 *s;

    arg0->unk1C += D_801E6DB4[0] * arg0->unk22;
    if (arg0->unk22 > 0) {
        if (arg0->unk1C >= arg0->unkE) {
            s = &D_801DFFE8;
            if (arg0->unkA == 3) {
                if (arg0->unk24 != 0) {
                    arg0->unkA = 0;
                    arg0->unk24 = 0;
                    arg0->unkE = arg0->unkC;
                    arg0->unk1C = arg0->unkC;
                } else {
                    arg0->unkA = 1;
                    arg0->unk24 = 0;
                    arg0->unk1C = arg0->unkE;
                }
            } else if (arg0->unkA == 2) {
                arg0->unkA = 0;
                arg0->unk1C = arg0->unkE;
            }
            if (s->unk12 & 4) {
                s->unk12 &= ~4;
                if (s->unk12 == 0) {
                    s->unk6 = 1;
                }
            }
        }
    } else {
        if (arg0->unkE >= arg0->unk1C) {
            s = &D_801DFFE8;
            if (arg0->unkA == 3) {
                if (arg0->unk24 != 0) {
                    arg0->unkA = 0;
                    arg0->unk24 = 0;
                    arg0->unkE = arg0->unkC;
                    arg0->unk1C = arg0->unkC;
                } else {
                    arg0->unkA = 1;
                    arg0->unk24 = 0;
                    arg0->unk1C = arg0->unkE;
                }
            } else if (arg0->unkA == 2) {
                arg0->unkA = 0;
                arg0->unk1C = arg0->unkE;
            }
            if (s->unk12 & 4) {
                s->unk12 &= ~4;
                if (s->unk12 == 0) {
                    s->unk6 = 1;
                }
            }
        }
    }
}

void func_80184B50(Unk_80184814 *arg0) {
    Unk_801DFFE8 *s;

    arg0->unk20 += D_801E6DB4[0] * arg0->unk22;
    if (arg0->unk22 > 0) {
        if (arg0->unk20 >= arg0->unkE) {
            s = &D_801DFFE8;
            if (arg0->unkA == 3) {
                if (arg0->unk24 != 0) {
                    arg0->unkA = 0;
                    arg0->unk24 = 0;
                    arg0->unkE = arg0->unkC;
                    *(s32 *)&arg0->unk20 = arg0->unkC;
                } else {
                    arg0->unkA = 1;
                    arg0->unk24 = 0;
                    *(s32 *)&arg0->unk20 = arg0->unkE;
                }
            } else if (arg0->unkA == 2) {
                arg0->unkA = 0;
                *(s32 *)&arg0->unk20 = arg0->unkE;
            }
            if (s->unk12 & 4) {
                s->unk12 &= ~4;
                if (s->unk12 == 0) {
                    s->unk6 = 1;
                }
            }
        }
    } else {
        if (arg0->unk20 <= arg0->unkE) {
            s = &D_801DFFE8;
            if (arg0->unkA == 3) {
                if (arg0->unk24 != 0) {
                    arg0->unkA = 0;
                    arg0->unk24 = 0;
                    arg0->unkE = arg0->unkC;
                    *(s32 *)&arg0->unk20 = arg0->unkC;
                } else {
                    arg0->unkA = 1;
                    arg0->unk24 = 0;
                    *(s32 *)&arg0->unk20 = arg0->unkE;
                }
            } else if (arg0->unkA == 2) {
                arg0->unkA = 0;
                *(s32 *)&arg0->unk20 = arg0->unkE;
            }
            if (s->unk12 & 4) {
                s->unk12 &= ~4;
                if (s->unk12 == 0) {
                    s->unk6 = 1;
                }
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184C6C);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80184ECC);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80185034);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8018519C);
