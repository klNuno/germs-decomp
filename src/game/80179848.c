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
    s16 unk6;
    s16 unk8;
    u8 padA[0x2];
    s16 unkC;
    u16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
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
    u8 pad0[0xBE];
    s16 unkBE;
    u8 padC0[0x140];
    s16 unk200;
    s16 unk202;
    u8 pad204[0x44];
    s32 unk248;
    u8 pad24C[0x2];
    s16 unk24E;
    s16 unk250;
    s16 unk252;
    s16 unk254;
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
    u8 pad44[0x1C];
    s32 unk60;
    u8 pad64[0x4];
    s32 unk68;
    u8 pad6C[0x6];
    s16 unk72;
    s16 unk74;
    s16 unk76;
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
    s16 unk4;
    s16 unk6;
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
typedef struct Unk_80184338 {
    u8 pad0[0x22];
    s16 unk22;
    u16 unk24;
    s16 unk26;
    s16 unk28;
    u8 pad2A[0x2];
    s32 unk2C;
    void (*unk30)(struct Unk_80184338 *arg0);
    void (*unk34)(void);
    void (*unk38)(void);
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
    u16 unk0;
    u16 unk2;
    u8 pad4[0x6];
    u16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    u8 pad26[0x2];
    s32 unk28;
    u8 unk2C[0x14];
    s32 unk40;
    s32 unk44;
    s32 unk48;
} Unk_80184814;
extern Unk_801DFFE8 D_801DFFE8;
extern char D_80170270[];
extern Unk_8017CCE4 *D_801E0000[];
void func_801765BC(void);
void func_80179848(Unk_8017CCE4 *arg0, u16 arg1);
void func_8018D5F8(void *arg0);
void func_801CFBB4(void *arg0);
void **func_801D32F0(s32 arg0);
s32 func_801D3364(s32 arg0);
s32 func_801D33E4(s32 arg0);
void func_801D3468(s32 arg0);
void func_801D654C(s16 *arg0, s32 *arg1);
void func_801D6E60(s16 *arg0, s32 *arg1);
void func_801D70D0(s32 arg0);
u16 D_801DFE58;
void func_8017A534(u16 arg0);
void func_8017A6E8(s32 arg0, s32 arg1);
s32 func_801D1F70(void);
s32 func_801D4FA0(s32 arg0, s32 arg1);
s32 func_801D5934(u16 arg0, u8 *arg1);
void func_801D6674(s16 *arg0, s32 *arg1);
void func_801D6A04(void);
void func_801D6A2C(void);
void func_801D6F74(s16 *arg0, s32 *arg1);
typedef struct {
    u16 unk0;
    u8 unk2;
    u8 unk3;
} Unk_8017B1E8;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} Unk_8017B3E8;
typedef struct {
    s32 unk0;
    struct {
        u8 pad0[0x18];
        s32 unk18;
        s32 unk1C;
        s32 unk20;
    } *unk4;
    struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
        s32 unkC;
        Unk_8017B1E8 *unk10;
        s32 unk14;
    } *unk8;
} Unk_8017BBB0;
typedef struct {
    u8 pad0[0xBC];
    Unk_8017BBB0 *unkBC;
} Unk_801E032C;
extern Unk_801E032C *D_801E032C[];
s32 func_8017B1E8(Unk_8017B1E8 *arg0, s32 arg1, s32 arg2, Unk_8017B3E8 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
s32 func_8017B3E8(Unk_8017B1E8 *arg0, s32 arg1, s32 arg2, Unk_8017B3E8 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
char *strncpy(char *dst, char *src, u32 n);
extern char D_801DFCBC[];
extern s16 D_801DFC74;
s16 D_801DFE70;
s16 D_801DFE74;
s16 D_801DFE76;
s32 strlen(char *s);
typedef struct { s16 unk0[5]; s16 unkA; char *unkC; s16 unk10; s16 unk12; s32 unk14; s32 unk18; s32 unk1C; } Unk_801E0340;
extern Unk_801E0340 D_801E0340;
void func_80192B8C(s32 arg0, s32 arg1);
void func_8018B810(void);
void func_80180B04(Unk_80181C10 *arg0, s32 arg1, s32 arg2);
void func_80180D8C(Unk_80181C10 *arg0, s32 arg1);
void func_8018164C(Unk_80181C10 *arg0, s32 arg1, s16 arg2);
void func_80192A44(s16 arg0);
void func_80184338(Unk_80184338 *arg0);
void func_80184408(void);
void *func_801D15C8(u32 arg0);
s32 func_801D14B8(void *arg0);
typedef struct Unk_801854B8 {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s32 unk28;
    u8 unk2C[0x14];
    s32 unk40;
    s32 unk44;
    s32 unk48;
    u8 unk4C[0x2C];
    void *unk78;
    void *unk7C;
} Unk_801854B8;
typedef struct Unk_801855C8 {
    struct Unk_801855C8 *unk0;
    struct Unk_801855C8 *unk4;
    Unk_801854B8 *unk8;
} Unk_801855C8;
typedef struct Unk_801DFE80 {
    Unk_801855C8 *unk0;
    Unk_801855C8 *unk4;
    Unk_801855C8 *unk8;
    s32 unkC;
} Unk_801DFE80;
Unk_801DFE80 *D_801DFE80;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_80174FFC;
void RotMatrix(Unk_80174FFC *arg0, void *arg1);
Unk_8017CCE4 *func_8017CDA4(s32 arg0, s32 arg1, s32 arg2);
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} Unk_8018519C_0;
typedef struct {
    Unk_8018519C_0 *unk0;
    s32 unk4;
    char **unk8;
} Unk_8018519C;
s32 atoi(char *s);
void func_80184ECC(Unk_80184814 *arg0, s16 arg1, s16 arg2, s16 arg3);
void func_80185034(Unk_80184814 *arg0, s16 arg1, s16 arg2);
extern char D_80170290[];

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80179848);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80179C50);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80179E50);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170250);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170270);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170290);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_801702B0);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_801702C8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A108);

void func_8017A3E4(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        D_801E0000[i] = func_801CC898(0x90);
        if (D_801E0000[i] == NULL) {
            func_801CD54C(3, D_80170270, D_801DFC84, 0x5D);
        }
        D_801E0000[i]->unk0 = 0;
        D_801E0000[i]->unk2 = 0;
        D_801E0000[i]->unk4 = 0;
        D_801E0000[i]->unk6 = 0;
        D_801E0000[i]->unk8 = 0;
        D_801E0000[i]->unkC = 1;
        D_801E0000[i]->unkE = 0;
        D_801E0000[i]->unk78 = NULL;
        D_801E0000[i]->unk7C = NULL;
        D_801E0000[i]->unk80 = NULL;
        D_801E0000[i]->unk84 = NULL;
        D_801E0000[i]->unk88 = NULL;
        D_801E0000[i]->unk8C = NULL;
        D_801E0000[i]->unk0 = 0;
        D_801E0000[i]->unkE = 0;
        {
            Unk_8017CCE4 *e = D_801E0000[i];

            if (D_801DFE5C->unkC == 0) {
                func_801CCBF4(D_801DFE5C, (s32)e);
            } else {
                D_801DFE5C->unk8 = D_801DFE5C->unk4;
                func_801CCCF4(D_801DFE5C, (s32)e);
            }
        }
    }
}

void func_8017A534(u16 arg0) {
    s32 sp10[12];
    s16 sp40;
    s32 i;
    Unk_8017CCE4 *e;
    s32 r;
    s32 t;
    void **p;

    D_801DFC80 = 1;
    sp40 = 12;
    if (arg0 == 2) {
        func_801D654C(&sp40, sp10);
    } else {
        func_801D6E60(&sp40, sp10);
    }
    for (i = 0; i < 12; i++) {
        e = D_801E0000[i];
        e->unk0 = 0;
        e->unk8C = NULL;
        if (i < sp40) {
            r = (s16)func_801D33E4(sp10[i]);
            t = func_801D3364(sp10[i]);
            p = func_801D32F0(sp10[i]);
            if (t == 5) {
                if (p != NULL && r != 0) {
                    func_8018D5F8(*p);
                    func_801D3468(sp10[i]);
                    continue;
                }
            } else if (t == 6) {
                if (p != NULL && r != 0) {
                    func_801CFBB4(*p);
                    func_801D3468(sp10[i]);
                    func_801D70D0(sp10[i]);
                    continue;
                }
            } else if (p != NULL) {
                e->unk8C = *p;
                func_80179848(e, arg0);
            }
        }
    }
    if (arg0 == 1) {
        func_801765BC();
    }
}

void func_8017A6E8(s32 arg0, s32 arg1) {
    Unk_801E0368 *p = &D_801E0368;

    p->unk252 = 0;
    p->unk250 = 0;
    p->unk254 = 0;
    if (arg0 >= 0x3CF && arg0 < 0x433 && arg1 > 0x8B0 && arg1 < 0xA0F) {
        p->unk252 = 1;
        p->unk250 = 1;
        p->unk254 = 1;
        return;
    }
    if ((arg0 >= 0x3CF && arg0 < 0x4C9 && arg1 >= -0x19 && arg1 < 0x8B1) ||
        (arg0 >= 0x36B && arg0 < 0x3CF && arg1 >= 0x23F && arg1 < 0x307) ||
        (arg0 >= 0x433 && arg0 < 0x497 && arg1 >= -0x1A9 && arg1 < -0xE1) ||
        (arg0 >= 0x81B && arg0 < 0x9AB && arg1 >= 0x1A9 && arg1 < 0x401) ||
        (arg0 >= -0x4FB && arg0 < -0x401 && arg1 >= 0x5F5 && arg1 < 0x9DD) ||
        (arg0 >= -0x591 && arg0 < -0x4C9 && arg1 >= -0x4B && arg1 < 0x1A9) ||
        (arg0 >= -0x591 && arg0 < -0x497 && arg1 >= -0x4C9 && arg1 < -0x23F) ||
        (arg0 >= 0x2D5 && arg0 < 0x433 && arg1 < -0x4C9) ||
        (arg0 >= 0x2D5 && arg0 < 0x433 && arg1 < -0x23F) ||
        arg1 < -0x4C9) {
        p->unk254 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017A86C);

void func_8017AAB4(u16 arg0) {
    s32 sp10[12];
    s16 sp40;
    Unk_801E076C *o = D_801E076C[0];
    s32 r;
    s32 i;
    Unk_8017CCE4 *e;
    void **p;

    D_801DFC80 = 0;
    if (arg0 == 2) {
        r = func_801D4FA0(o->unk68, o->unk60);
        func_8017A6E8(o->unk60, o->unk68);
    } else {
        r = func_801D5934(D_801DFE58, &D_801DFC8C);
    }
    if (r == 3) {
        D_801DFC80 = 1;
        sp40 = 12;
        if (arg0 == 2) {
            func_801D6674(&sp40, sp10);
        } else {
            func_801D6F74(&sp40, sp10);
        }
        for (i = 0; i < 12; i++) {
            e = D_801E0000[i];
            e->unk0 = 0;
            e->unk8C = NULL;
            if (i < sp40) {
                s32 t = func_801D3364(sp10[i]);
                if (t != 5 && t != 6) {
                    p = func_801D32F0(sp10[i]);
                    if (p != NULL) {
                        e->unk8C = *p;
                        func_80179848(e, arg0);
                    }
                }
            }
        }
        if (arg0 == 1) {
            func_801765BC();
        }
        func_801D1F70();
    } else if (r == 1 || func_801D1F70() != 0) {
        if (arg0 == 2) {
            func_801D6A04();
        } else {
            func_801D6A2C();
        }
        func_8017A534(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017AC88);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017AF18);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017B1E8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017B3E8);

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_8017B7CC);

s32 func_8017BBB0(s32 arg0, s32 arg1, s32 arg2) {
    Unk_8017B3E8 sp20;
    Unk_8017B1E8 *e;
    s32 n;
    s32 a;
    s32 b;
    s32 cnt;
    s32 r;
    s32 t;
    Unk_8017BBB0 *q;

    q = D_801E032C[0]->unkBC;
    sp20.unk0 = q->unk4->unk18;
    sp20.unk4 = q->unk4->unk1C;
    sp20.unk8 = q->unk4->unk20;
    e = q->unk8->unk10;
    n = q->unk8->unk14;
    a = q->unk8->unk0;
    b = q->unk8->unk8;
    while (n != 0) {
        cnt = e->unk0;
        switch (e->unk3 & 0xFD) {
        case 0x20:
            t = func_8017B1E8(e, a, b, &sp20, cnt, arg0, arg1, arg2);
            if (t != 0) {
                r = t;
                goto end;
            }
            n -= cnt;
            e = (Unk_8017B1E8 *)((u8 *)e + cnt * 0x10);
            break;
        case 0x28:
            t = func_8017B3E8(e, a, b, &sp20, cnt, arg0, arg1, arg2);
            if (t != 0) {
                r = t;
                goto end;
            }
            n -= cnt;
            e = (Unk_8017B1E8 *)((u8 *)e + cnt * 0x14);
            break;
        default:
            r = 0;
            goto end;
        }
    }
    r = 0;
end:
    if (r != 0) {
        return r;
    }
    return 0;
}

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

void func_8017CB98(Unk_8017CCE4 **arg0, s32 arg1) {
    *arg0 = func_801CC898(0x90);
    if (*arg0 == NULL) {
        func_801CD54C(3, D_80170270, D_801DFC84, 0x5D);
    }
    (*arg0)->unk0 = 0;
    (*arg0)->unk2 = 0;
    (*arg0)->unk4 = 0;
    (*arg0)->unk6 = 0;
    (*arg0)->unk8 = 0;
    (*arg0)->unkC = 1;
    (*arg0)->unkE = 0;
    (*arg0)->unk78 = NULL;
    (*arg0)->unk7C = NULL;
    (*arg0)->unk80 = NULL;
    (*arg0)->unk84 = NULL;
    (*arg0)->unk88 = NULL;
    (*arg0)->unk8C = NULL;
    if (arg1 != 0) {
        (*arg0)->unk8C = func_801CC898(arg1);
        if ((*arg0)->unk8C == NULL) {
            func_801CD54C(3, D_80170290, D_801DFC84, 0x70);
        }
        (*arg0)->unk2 = 1;
    }
}

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

Unk_8017CCE4 *func_8017CDA4(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFE5C *p = D_801DFE5C;
    Unk_801E0340 *g = &D_801E0340;

    if (p->unkC == 0) {
        return NULL;
    }
    p->unk8 = p->unk0;
    while (1) {
        Unk_8017CCE4 *e = p->unk8->unk8;
        if (e != NULL && e->unk0 != 0 && arg0 >= e->unk10 && arg0 < e->unk10 + e->unk1C && arg2 >= e->unk18 && arg2 < e->unk18 + e->unk24) {
            if (g->unk0[0] != 1) {
                return e;
            }
            if (e->unk20 == 0) {
                if (arg1 == e->unk14) {
                    return e;
                }
            } else if (e->unk14 >= arg1 && arg1 >= e->unk14 - e->unk20) {
                return e;
            }
        }
        if (func_801CD000(p) != 0) {
            return NULL;
        }
        p->unk8 = p->unk8->unk4;
    }
}

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

void func_8017D2B8(void) {
    Unk_801DFE5C *p = D_801DFE5C;

    if (p->unkC != 0) {
        p->unk8 = p->unk0;
        while (1) {
            Unk_8017CCE4 *e = p->unk8->unk8;
            if (e != NULL && e->unk2 != 0) {
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
                func_801CCDF8(p);
            }
            if (func_801CD000(p) != 0) {
                break;
            }
            p->unk8 = p->unk8->unk4;
        }
    }
}

void func_8017D3F0(void) {
    D_801DFC80 = 0;
    func_801D3650();
}

s32 func_8017D414(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Unk_8017B3E8 sp20;
    Unk_8017B1E8 *e;
    s32 n;
    s32 a;
    s32 b;
    s32 cnt;
    s32 t;
    Unk_8017BBB0 *q = arg0;

    sp20.unk0 = q->unk4->unk18;
    sp20.unk4 = q->unk4->unk1C;
    sp20.unk8 = q->unk4->unk20;
    e = q->unk8->unk10;
    n = q->unk8->unk14;
    a = q->unk8->unk0;
    b = q->unk8->unk8;
    while (n != 0) {
        cnt = e->unk0;
        switch (e->unk3 & 0xFD) {
        case 0x20:
            t = func_8017B1E8(e, a, b, &sp20, cnt, arg1, arg2, arg3);
            if (t != 0) {
                return t;
            }
            n -= cnt;
            e = (Unk_8017B1E8 *)((u8 *)e + cnt * 0x10);
            break;
        case 0x28:
            t = func_8017B3E8(e, a, b, &sp20, cnt, arg1, arg2, arg3);
            if (t != 0) {
                return t;
            }
            n -= cnt;
            e = (Unk_8017B1E8 *)((u8 *)e + cnt * 0x14);
            break;
        default:
            return 0;
        }
    }
    return 0;
}

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
