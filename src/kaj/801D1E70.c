#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x1C];
} Unk_801DFBE0;
extern Unk_801DFBE0 D_801DFBE0[];
s16 D_801DFE10;
typedef struct Unk_801D395C {
    u8 *unk0;
    s32 unk4;
    struct Unk_801D395C *unk8;
} Unk_801D395C;
typedef struct {
    s32 unk0;
    u8 *unk4;
    u8 *unk8;
    s32 unkC;
    s32 unk10;
    Unk_801D395C *unk14;
    s32 unk18;
} Unk_801D3924;
s32 func_801D3AD4(Unk_801D3924 *arg0);
typedef struct {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
} Unk_801D3060;
void *CdSearchFile(void *fp, char *name);
s32 CdPosToInt(void *p);
extern s16 D_801E71C8[];
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[0xC];
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    u8 unk1E[4];
    s16 unk22;
} Unk_801E71A8;
extern Unk_801E71A8 D_801E71A8[];
void *CdIntToPos(s32 i, void *p);
s32 CdControl(u8 com, u8 *param, u8 *result);
s32 CdMode(void);
s32 VSync(s32 mode);
s32 CdRead(s32 sectors, u32 *buf, s32 mode);
extern Unk_801E71A8 D_801E71CC[];
typedef struct {
    u8 unk0[0x1C];
    s32 *unk1C;
    u8 unk20[4];
} Unk_801D35EC;
extern s32 D_801E7108[];
void CdFlush(void);
void func_801D3B30(Unk_801D3924 *arg0);
s16 D_801DFFD8;
void func_8018E1F0(s32 arg0);
s32 D_801DFE2C;
s32 D_801DFE30;
s32 D_801DFE34;
void *memmove(void *dst, const void *src, u32 n);
typedef struct {
    u8 unk0[0xA];
    s16 unkA;
    s16 unkC;
    u8 unkE[0x52];
} Unk_801E7950;
u8 D_801DFE49;
extern Unk_801E7950 D_801E7950[];
Unk_801E7950 *func_801D7168(void);
typedef struct {
    u8 unk0[6];
    s16 unk6;
    u8 unk8[2];
    s16 unkA;
    u8 unkC[4];
    s32 unk10[0x20];
} Unk_801E7830;
u8 D_801DFE48;
extern Unk_801E7830 D_801E7830[];
s32 D_801DFE38;
s32 D_801DFE3C;
s32 func_801D32F0(s32 arg0);
s32 D_801DFE40;
typedef struct {
    s32 unk0;
    s32 unk4;
} Unk_801D6DC8;
s16 D_801DFFE4;
void func_801D28C0(s32 arg0);
extern char D_80172FD0[];
extern char D_801DFE14[];
int printf(const char *fmt, ...);
void exit(s32 code);
extern char D_80173028[];
void func_801D1E70(void);
s32 func_801D2210(Unk_801D3060 *arg0, s32 arg1, s32 arg2);
s32 func_801D3060(Unk_801D3060 *arg0, char *arg1);
void func_801D5D5C(void);
void free3(void *ptr);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D1E70);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D1F70);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D2210);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D23FC);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D254C);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D28C0);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D2A48);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D2B60);

s32 func_801D2E48(s32 arg0) {
    if (arg0 < 0 || arg0 >= D_801DFE10) {
        printf(D_80172FD0, D_801DFE14, 137);
        exit(1);
    }
    return D_801DFBE0[arg0].unk4;
}

s32 func_801D2EB0(s32 arg0) {
    Unk_801DFBE0 *p = D_801DFBE0;
    s32 i;

    for (i = 0; i < D_801DFE10; i++, p++) {
        if (p->unk0 == arg0) {
            return func_801D3AD4(p->unkC);
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D2F18);

s32 func_801D3060(Unk_801D3060 *arg0, char *arg1) {
    struct {
        u8 unk0[4];
        u32 unk4;
        char unk8[16];
    } file;

    while ((u32)((s32)CdSearchFile(&file, arg1) + 1) < 2) {
    }
    arg0->unk0 = CdPosToInt(&file);
    arg0->unk4 = 0;
    arg0->unk8 = file.unk4;
    arg0->unkC = (file.unk4 + 0x7FF) >> 11;
    arg0->unk10 = arg0->unkC << 11;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D30E4);

s32 func_801D31B8(void) {
    return D_801E71C8[0] == 0;
}

s32 func_801D31C8(s32 arg0) {
    Unk_801E71A8 *p;

    p = (arg0 >= 1 && arg0 <= 32) ? &D_801E71A8[arg0] : NULL;
    if (p != NULL && p->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != arg0) {
            return 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D323C);

s32 func_801D32F0(s32 arg0) {
    Unk_801E71A8 *p;

    p = (arg0 >= 1 && arg0 <= 32) ? &D_801E71A8[arg0] : NULL;
    if (p != NULL && p->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != arg0) {
            return p->unk18;
        }
    }
    return 0;
}

s32 func_801D3364(s32 arg0) {
    Unk_801E71A8 *p;

    p = (arg0 >= 1 && arg0 <= 32) ? &D_801E71A8[arg0] : NULL;
    if (p == NULL) {
        return -1;
    }
    return p->unk1D;
}

s32 func_801D33A4(s32 arg0) {
    Unk_801E71A8 *p;

    p = (arg0 >= 1 && arg0 <= 32) ? &D_801E71A8[arg0] : NULL;
    if (p == NULL) {
        return 0;
    }
    return p->unk8;
}

s32 func_801D33E4(s32 arg0) {
    Unk_801E71A8 *p;

    p = (arg0 >= 1 && arg0 <= 32) ? &D_801E71A8[arg0] : NULL;
    if (p != NULL && p->unk18 != 0 && p->unk22 == 1) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != arg0) {
            return 1;
        }
    }
    return 0;
}

void func_801D3468(s32 arg0) {
    Unk_801E71A8 *p;

    p = (arg0 >= 1 && arg0 <= 32) ? &D_801E71A8[arg0] : NULL;
    if (p != NULL && p->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != arg0) {
            p->unk22 = 2;
        }
    }
}

void func_801D34DC(Unk_801D3060 *arg0) {
    u8 pos[4];

    CdIntToPos(arg0->unk0, pos);
    while (CdControl(2, pos, NULL) == 0) {
    }
}

void func_801D3518(Unk_801D3060 *arg0, u32 *arg1) {
    u8 mode[4];

    mode[0] = CdMode();
    if (!(mode[0] & 0x80)) {
        mode[0] = 0x80;
        while (CdControl(0xE, mode, NULL) == 0) {
        }
        VSync(3);
    }
    CdRead(arg0->unkC, arg1, 0x80);
}

Unk_801E71A8 *func_801D3590(s32 arg0, s32 arg1) {
    Unk_801E71A8 *p;
    s32 i;

    for (i = 0; i < 32; i++) {
        p = &D_801E71CC[i];
        if (p->unk18 != 0 && p->unk4 == arg1 && p->unk1C == arg0) {
            return p;
        }
    }
    return NULL;
}

void func_801D35EC(Unk_801D35EC *arg0) {
    u8 i;
    Unk_801D35EC *p;

    for (i = 0; i < 32; i++) {
        p = &arg0[i];
        if (p->unk1C != NULL) {
            D_801E7108[i] = *p->unk1C;
        } else {
            D_801E7108[i] = 0;
        }
    }
}

void func_801D3650(void) {
    Unk_801DFBE0 *p = D_801DFBE0;
    s32 i;

    CdFlush();
    for (i = 0; i < D_801DFE10; i++, p++) {
        if (p->unk8 != 0) {
            func_801D3B30(p->unkC);
        }
    }
}

s32 func_801D36C4(s32 arg0) {
    Unk_801E71A8 *p;

    p = (arg0 >= 1 && arg0 <= 32) ? &D_801E71A8[arg0] : NULL;
    if (p != NULL && p->unk18 != 0 && p->unk22 != 0) {
        return 1;
    }
    return 0;
}

void func_801D3724(void) {
    D_801DFFD8 = 0;
}

void func_801D3730(s32 arg0, s32 arg1) {
    switch (arg0) {
    case 3:
        break;
    case 5:
        func_8018E1F0(arg1);
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D3764);

void func_801D3910(s32 arg0, s32 arg1) {
    D_801DFE2C = arg1;
    D_801DFE30 = 0;
    D_801DFE34 = 0;
}

void func_801D3924(Unk_801D3924 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    arg0->unk4 = arg1;
    arg0->unk8 = arg1 + arg2;
    arg0->unk0 = arg2;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = arg3;
}

void func_801D3948(Unk_801D3924 *arg0, s32 arg1) {
    arg0->unk18 = arg1;
}

s32 func_801D3950(Unk_801D3924 *arg0) {
    return arg0->unk18;
}

s32 func_801D395C(Unk_801D3924 *arg0) {
    Unk_801D395C *p = arg0->unk14;
    u8 *addr = arg0->unk4;

    while (p != NULL) {
        if (p->unk0 != addr) {
            return 1;
        }
        addr += p->unk4;
        p = p->unk8;
    }
    return 0;
}

s32 func_801D39A0(Unk_801D3924 *arg0) {
    Unk_801D395C *p = arg0->unk14;
    u8 *addr = arg0->unk4;
    s32 moved = 0;

    while (p != NULL) {
        if (p->unk0 != addr) {
            memmove(addr, p->unk0, p->unk4);
            moved = 1;
            p->unk0 = addr;
        }
        addr = p->unk0 + p->unk4;
        p = p->unk8;
    }
    return moved;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D3A14);

s32 func_801D3AD4(Unk_801D3924 *arg0) {
    Unk_801D395C *p;

    if (arg0->unk14 == NULL) {
        return arg0->unk0;
    }
    for (p = arg0->unk14; p->unk8 != NULL; p = p->unk8) {
    }
    return arg0->unk8 - (p->unk0 + p->unk4);
}

void func_801D3B30(Unk_801D3924 *arg0) {
    Unk_801D395C *p = arg0->unk14;
    Unk_801D395C *next;

    while (p != NULL) {
        next = p->unk8;
        if (p != NULL) {
            free3(p);
        }
        p = next;
    }
}

INCLUDE_RODATA("asm/nonmatchings/kaj/801D1E70", D_80172FD0);

INCLUDE_RODATA("asm/nonmatchings/kaj/801D1E70", D_80172FF8);

INCLUDE_RODATA("asm/nonmatchings/kaj/801D1E70", D_80173008);

INCLUDE_RODATA("asm/nonmatchings/kaj/801D1E70", D_80173018);

INCLUDE_RODATA("asm/nonmatchings/kaj/801D1E70", D_80173028);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D3B7C);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D3C50);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D3E1C);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D3EEC);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D40F4);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D42F4);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D4D24);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D4FA0);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D50F4);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D5324);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D5934);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D5BE4);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D5D5C);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D5E28);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D6120);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D654C);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D6674);

s32 func_801D67E0(void) {
    Unk_801D3060 file;
    s32 ret;

    func_801D1E70();
    D_801DFE38 = 1;
    D_801DFE40 = 0;
    ret = func_801D3060(&file, D_80173028);
    if (ret == 0) {
        D_801DFE3C = func_801D2210(&file, 0, 2);
        if (D_801DFE3C == 0) {
            ret = -1;
        }
    }
    func_801D5D5C();
    return ret;
}

s32 func_801D6850(void) {
    Unk_801E7950 *p = &D_801E7950[D_801DFE49];

    if (p != NULL && p->unkA > 0) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D6894);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D6940);

void func_801D6A04(void) {
    func_801D7168()->unkA = 1;
}

void func_801D6A2C(void) {
    Unk_801E7830 *p = &D_801E7830[D_801DFE48];

    p->unk6 = 1;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D6A58);

s32 func_801D6B14(void) {
    s32 ret = 0;

    if (D_801DFE38 == 1 && D_801DFE3C > 0) {
        ret = func_801D32F0(D_801DFE3C);
    }
    return ret;
}

s32 func_801D6B58(void) {
    s32 ret = 0;

    if (D_801DFE38 == 2 && D_801DFE3C > 0) {
        ret = func_801D32F0(D_801DFE3C);
    }
    return ret;
}

s32 func_801D6B9C(void) {
    return D_801DFE40;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D6BA8);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D6CA8);

s32 func_801D6DC8(Unk_801D6DC8 *arg0, Unk_801D6DC8 *arg1) {
    return arg0->unk4 - arg1->unk4;
}

s16 func_801D6DD8(void) {
    Unk_801E7830 *p = &D_801E7830[D_801DFE48];

    if (p->unk6 <= 0) {
        return 0;
    }
    return p->unkA;
}

s32 func_801D6E1C(void) {
    Unk_801E7830 *p = &D_801E7830[D_801DFE48];

    if (p != NULL && p->unk6 > 0) {
        return 1;
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D6E60);

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D6F74);

void func_801D70D0(s32 arg0) {
    Unk_801E7830 *p = &D_801E7830[D_801DFE48];
    s32 i;

    for (i = 0; i < p->unkA; i++) {
        if (p->unk10[i] == arg0) {
            func_801D28C0(p->unk10[i]);
            p->unk10[i] = 0;
            D_801DFFE4 = 1;
            return;
        }
    }
}

Unk_801E7950 *func_801D7168(void) {
    return &D_801E7950[D_801DFE49];
}

s16 func_801D718C(void) {
    Unk_801E7950 *p = &D_801E7950[D_801DFE49];
    if (p->unkA <= 0) {
        return 0;
    }
    return p->unkC;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D71D0);

s32 func_801D72F4(s16 *arg0, s16 arg1, s16 arg2) {
    if (arg0[0] != arg1 || arg0[1] != arg2) {
        return 1;
    }
    return 0;
}
