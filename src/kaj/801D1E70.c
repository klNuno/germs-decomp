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
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    s16 unk1E;
    s16 unk20;
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
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 unk8;
    u8 unk9;
    s16 unkA;
    s16 unkC;
    u8 unkE[2];
    s32 unk10[20];
} Unk_801E7950;
u8 D_801DFE49;
extern Unk_801E7950 D_801E7950[];
Unk_801E7950 *func_801D7168(void);
typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
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
typedef struct {
    s16 unk0;
    s16 unk2;
    Unk_801E71A8 unk4[32];
} Unk_801E71C8;
void *func_801CC898(u32 size);
void func_801D3924(Unk_801D3924 *arg0, u8 *arg1, s32 arg2, s32 arg3);
void func_801D35EC(Unk_801D35EC *arg0);
s32 func_801D395C(Unk_801D3924 *arg0);
s32 func_801D39A0(Unk_801D3924 *arg0);
void func_801D2B60(s16 *arg0);
s32 func_801D31C8(s32 arg0);
s32 func_801D2F18(s32 arg0, u32 arg1, char *arg2);
typedef struct {
    u8 unk0[0x14];
    s32 unk14;
    s32 unk18;
    u8 unk1C[4];
} Unk_801D3E1C;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
    s16 unkE;
    u8 unk10[4];
    Unk_801D6DC8 *unk14;
    s32 unk18;
} Unk_801D6940;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C[4];
    s16 unk20[1];
} Unk_801D32F0;
s32 func_801D30E4(s32 arg0, s16 arg1, Unk_801D3060 *arg2);
s32 func_801D40F4(s16 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4, u8 *arg5);
extern char D_80172FF8[];
s32 D_801DFE44;
void func_801D6A58(void);
int sprintf(char *buf, const char *fmt, ...);
typedef struct {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    s32 unk14;
} Unk_801D2A48;
extern s16 D_801E7188[];
s32 func_801D3E1C(s16 arg0, s16 arg1);
void func_801D4D24(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);
s32 func_801D6120(s16 arg0, s16 arg1);
typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
} Unk_801D5BE4;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    Unk_801D6940 *unk10;
    Unk_801D5BE4 *unk14;
} Unk_801D6B58;
s32 func_801D36C4(s32 arg0);
extern char D_80173008[];
extern char D_80173018[];
void func_801D5BE4(void);
s32 CdReadSync(s32 mode, u8 *result);
void CdReadBreak(void);
s32 D_801DFE1C;
s32 D_801DFE20;
s32 D_801DFE24;
u8 D_801DFE28;
void func_8017C9F8(void *arg0, void *arg1);
void func_8018D6DC(s32 *arg0, s32 *arg1);
s32 func_801D3EEC(s16 arg0, s16 arg1, u8 arg2, u8 *arg3);
typedef struct {
    u8 unk0;
    u8 unk1;
} Unk_801D50F4;
s32 D_801DFFE0;
extern Unk_801D2A48 D_801E7650[];
s32 func_801D23FC(s32 arg0, Unk_801D2A48 *arg1, s32 *arg2, s32 arg3);
s16 func_801D254C(s32 *arg0, Unk_801D2A48 *arg1, s32 *arg2, s32 arg3, s16 *arg4);
s32 func_801D31B8(void);
void func_801D3724(void);
void func_801D50F4(Unk_801E7830 *arg0, u8 *arg1);
void func_801D5324(s32 arg0, Unk_801E7830 *arg1);
s32 func_801D2E48(s32 arg0);
s32 func_801D6DC8(Unk_801D6DC8 *arg0, Unk_801D6DC8 *arg1);
u8 func_801D42F4(s16 arg0, s16 arg1, u8 arg2, s16 *arg3, s16 *arg4, u8 *arg5);
void qsort(void *base, s32 n, s32 size, s32 (*cmp)());
/* best 99.90 % : code bytes identical; only reloc symbol differs, target D_801DFBEC (spurious data split inside D_801DFBE0[0].unkC) vs D_801DFBE0+0xc */
void func_801D3730(s32 arg0, s32 arg1);
void func_801D3A14(Unk_801D3924 *arg0, Unk_801D395C *arg1);
void func_801D5E28(Unk_801E7950 *arg0);

void func_801D1E70(void) {
    Unk_801DFBE0 *p = D_801DFBE0;
    Unk_801E71C8 *q;
    s32 i;

    for (i = 0; i < D_801DFE10; i++, p++) {
        if (p->unk8 == 0) {
            p->unk8 = (s32)func_801CC898(p->unk4);
            if (p == NULL) {
                printf(D_80172FD0, D_801DFE14, 168);
                exit(1);
            }
        }
        func_801D3924((Unk_801D3924 *)p->unkC, (u8 *)p->unk8, p->unk4, 2);
    }
    q = (Unk_801E71C8 *)D_801E71C8;
    q->unk0 = 0;
    q->unk2 = 0;
    for (i = 0; i < 32; i++) {
        q->unk4[i].unk8 = 0;
        q->unk4[i].unkC = 0;
        q->unk4[i].unk10 = 0;
        q->unk4[i].unk0 = 0;
        q->unk4[i].unk1E = 0;
        q->unk4[i].unk20 = 0;
        q->unk4[i].unk18 = 0;
        q->unk4[i].unk1C = 0;
    }
}

s32 func_801D1F70(void) {
    Unk_801E71C8 *q;
    Unk_801E71A8 *p;
    s32 n;
    s32 ret = 0;
    u32 *buf;
    s32 r;
    u8 pos[8];
    u8 param[8];

    n = D_801E71C8[1];
    p = (n >= 1 && n <= 32) ? &((Unk_801E71C8 *)D_801E71C8)->unk4[n - 1] : NULL;
    q = (Unk_801E71C8 *)D_801E71C8;
    switch (D_801E71C8[0]) {
    case 1:
        if (q->unk2 > 0 && p->unk18 != 0) {
            D_801DFE1C = 0;
            D_801DFE20 = 0;
            CdIntToPos(p->unk0, pos);
            while (CdControl(2, pos, NULL) == 0) {
            }
            D_801E71C8[0] = 3;
        } else {
            D_801E71C8[0] = -1;
        }
        break;
    case 3:
        if (q->unk2 > 0 && p->unk18 != 0) {
            buf = *(u32 **)p->unk18;
            param[0] = CdMode();
            if (!(param[0] & 0x80)) {
                param[0] = 0x80;
                while (CdControl(0xE, param, NULL) == 0) {
                }
                VSync(3);
            }
            if (CdRead(p->unkC, buf, 0x80) != 0) {
                D_801E71C8[0] = 4;
            } else {
                CdFlush();
                D_801E71C8[0] = 1;
            }
        } else {
            D_801E71C8[0] = -1;
        }
        break;
    case 4:
        r = CdReadSync(1, NULL);
        if (r == 0) {
            if (p->unk1E != 0) {
                D_801E71C8[0] = 1;
                q->unk2 = p->unk1E;
                p->unk1E = 0;
            } else {
                D_801E71C8[0] = 0;
                q->unk2 = 0;
                D_801DFE24 = 1;
                ret = 1;
            }
            p->unk22 = 1;
        } else {
            if (D_801DFE1C == r) {
                D_801DFE20++;
            } else {
                D_801DFE20 = 0;
            }
            D_801DFE1C = r;
            if (D_801DFE20 > 0x40000) {
                if (p->unkC - r >= 2) {
                    CdReadBreak();
                } else {
                    CdFlush();
                }
                D_801E71C8[0] = 1;
            }
        }
        break;
    case -1:
        CdFlush();
        D_801E71C8[0] = 0;
        break;
    }
    return ret;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D2210);

s32 func_801D23FC(s32 arg0, Unk_801D2A48 *arg1, s32 *arg2, s32 arg3) {
    Unk_801E71A8 *p;
    s32 i;
    s32 j;
    s32 k;

    if (D_801E71C8[0] != 0) {
        return 0;
    }
    for (i = 0; i < 32; i++) {
        D_801E7188[i] = ((Unk_801E71C8 *)D_801E71C8)->unk4[i].unk20;
    }
    k = 0;
    for (i = 0; i < arg0; i++, arg1++) {
        for (j = 0; j < 32; j++) {
            p = &D_801E71CC[j];
            if (p->unk0 == arg1->unk0 && p->unk1C == arg3 && p->unk1D == arg1->unk14) {
                D_801E7188[j]++;
                *arg2 = j + 1;
                break;
            }
        }
        if (j == 32) {
            for (; k < 32; k++) {
                p = &D_801E71CC[k];
                if (p->unk18 == 0) {
                    D_801E7188[k++]++;
                    break;
                }
            }
        }
        arg2++;
    }
    return 1;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D254C);

void func_801D28C0(s32 arg0) {
    Unk_801D3924 *h;
    Unk_801D395C *blk;
    s32 idx;
    s32 n;

    if (arg0 == 0) {
        return;
    }
    n = arg0 - 1;
    if (((Unk_801E71C8 *)D_801E71C8)->unk4[n].unk18 == 0) {
        return;
    }
    if (D_801E7188[n] <= 0) {
        return;
    }
    if (--D_801E7188[n] != 0) {
        return;
    }
    func_801D3730(((Unk_801E71C8 *)D_801E71C8)->unk4[n].unk1D, *(s32 *)((Unk_801E71C8 *)D_801E71C8)->unk4[n].unk18);
    if (D_801E71C8[0] != 0 && D_801E71C8[1] == arg0) {
        CdFlush();
        D_801E71C8[0] = 0;
    }
    idx = ((Unk_801E71C8 *)D_801E71C8)->unk4[n].unk1C;
    blk = (Unk_801D395C *)((Unk_801E71C8 *)D_801E71C8)->unk4[n].unk18;
    if (idx < 0 || idx >= D_801DFE10) {
        printf(D_80172FD0, D_801DFE14, 93);
        exit(1);
    }
    h = (Unk_801D3924 *)D_801DFBE0[idx].unkC;
    if (h != NULL && blk != NULL) {
        func_801D3A14(h, blk);
    }
    ((Unk_801E71C8 *)D_801E71C8)->unk4[n].unk18 = 0;
    ((Unk_801E71C8 *)D_801E71C8)->unk4[n].unk1C = 0;
    ((Unk_801E71C8 *)D_801E71C8)->unk4[n].unk1D = 0;
    D_801DFFD8 = 1;
}

s32 func_801D2A48(s32 arg0, s16 arg1, s16 *arg2, Unk_801D2A48 *arg3) {
    Unk_801E71A8 *p;
    s32 *ret;
    s32 *e;
    s16 i;
    s32 size;
    Unk_801D2A48 *d;

    p = (arg0 >= 1 && arg0 <= 32) ? &D_801E71A8[arg0] : NULL;
    if (p != NULL && p->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != arg0) {
            ret = (s32 *)p->unk18;
        } else {
            ret = NULL;
        }
    } else {
        ret = NULL;
    }
    if (ret != NULL) {
        for (i = 0; i < arg1; i++) {
            if (arg2[i] > 0) {
                e = &((s32 *)*ret)[arg2[i] * 2 - 2];
                d = &arg3[i];
                d->unk0 = e[0];
                size = e[1];
                d->unk8 = size;
                d->unkC = (size + 0x7FF) / 2048;
                d->unk10 = d->unkC << 11;
            }
        }
        return 0;
    }
    return -1;
}

void func_801D2B60(s16 *arg0) {
    u8 i;
    s32 *base;
    s32 *old;
    u8 *src;
    s32 diff;
    s32 diff3;
    s32 j;
    s32 j3;
    s32 k;
    s32 *e;
    s32 *e3;
    s32 *o;
    s32 **it;
    s32 n;

    for (i = 0; i < 32; i++) {
        if (((Unk_801E71C8 *)arg0)->unk4[i].unk18 != 0 && ((Unk_801E71C8 *)arg0)->unk4[i].unk22 != 0) {
            base = *(s32 **)((Unk_801E71C8 *)arg0)->unk4[i].unk18;
            old = (s32 *)D_801E7108[i];
            if (base < old) {
                switch (((Unk_801E71C8 *)arg0)->unk4[i].unk1D) {
                case 1:
                    e = base + 5;
                    diff = old - base;
                    for (j = 0; j < base[4]; j++, e += 2) {
                        o = (s32 *)((u8 *)base + e[1]);
                        if (o[0] == 0x41 && (o[1] & 1)) {
                            it = (s32 **)(o + 3);
                            n = o[2];
                            for (k = 0; k < n; k++, it += 7) {
                                it[0] -= diff;
                                it[2] -= diff;
                                it[4] -= diff;
                            }
                        }
                    }
                    D_801DFE28 = 1;
                    break;
                case 3:
                    e3 = base + 5;
                    src = (u8 *)old;
                    diff3 = old - base;
                    for (j3 = 0; j3 < ((s16 *)base)[9]; j3++, e3 += 2) {
                        if (e3[0] == 4) {
                            func_8017C9F8(src + e3[1], (u8 *)base + e3[1]);
                        } else {
                            o = (s32 *)((u8 *)base + e3[1]);
                            if (o[0] == 0x41 && (o[1] & 1)) {
                                it = (s32 **)(o + 3);
                                n = o[2];
                                for (k = 0; k < n; k++, it += 7) {
                                    it[0] -= diff3;
                                    it[2] -= diff3;
                                    it[4] -= diff3;
                                }
                            }
                        }
                    }
                    D_801DFE28 = 2;
                    break;
                case 5:
                    func_8018D6DC(old, base);
                    D_801DFE28 = 3;
                    break;
                }
            }
        }
    }
}

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

s32 func_801D2F18(s32 arg0, u32 arg1, char *arg2) {
    Unk_801D3060 info;
    struct {
        u8 unk0[4];
        u32 unk4;
        char unk8[16];
    } file;
    Unk_801D3060 *f = &info;
    Unk_801E71A8 *p;
    s32 *ret;
    s32 *e;
    s32 n;
    s32 i;
    s32 base;

    while ((u32)((s32)CdSearchFile(&file, arg2) + 1) < 2) {
    }
    f->unk0 = CdPosToInt(&file);
    f->unk4 = 0;
    f->unk8 = file.unk4;
    f->unkC = (file.unk4 + 0x7FF) >> 11;
    f->unk10 = f->unkC << 11;
    base = info.unk0;
    n = arg1 >> 3;
    p = (arg0 >= 1 && arg0 <= 32) ? &D_801E71A8[arg0] : NULL;
    if (p != NULL && p->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != arg0) {
            ret = (s32 *)p->unk18;
        } else {
            ret = NULL;
        }
    } else {
        ret = NULL;
    }
    if (ret != NULL) {
        for (i = 0; i < n; i++) {
            e = &((s32 *)*ret)[i * 2];
            *e += base - 150;
        }
    }
    return 0;
}

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

s32 func_801D30E4(s32 arg0, s16 arg1, Unk_801D3060 *arg2) {
    Unk_801E71A8 *p;
    s32 *ret;
    s32 size;

    p = (arg0 >= 1 && arg0 <= 32) ? &D_801E71A8[arg0] : NULL;
    if (p != NULL && p->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != arg0) {
            ret = (s32 *)p->unk18;
        } else {
            ret = NULL;
        }
    } else {
        ret = NULL;
    }
    if (ret != NULL && arg1 > 0) {
        ret = &((s32 *)*ret)[arg1 * 2 - 2];
        arg2->unk0 = ret[0];
        arg2->unk4 = arg1;
        size = ret[1];
        arg2->unk8 = size;
        arg2->unkC = (size + 0x7FF) / 2048;
        arg2->unk10 = arg2->unkC << 11;
        return 0;
    }
    return -1;
}

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

s32 func_801D323C(void) {
    Unk_801DFBE0 *p = D_801DFBE0;
    s32 i;
    s32 moved = 0;

    for (i = 0; i < D_801DFE10; i++, p++) {
        if (func_801D395C((Unk_801D3924 *)p->unkC) != 0) {
            func_801D35EC((Unk_801D35EC *)D_801E71C8);
            moved |= func_801D39A0((Unk_801D3924 *)p->unkC);
        }
    }
    if (moved != 0) {
        func_801D2B60(D_801E71C8);
    }
    return moved | D_801DFFD8;
}

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

void func_801D3A14(Unk_801D3924 *arg0, Unk_801D395C *arg1) {
    Unk_801D395C *p;
    Unk_801D395C *next;

    if (arg1 == NULL) {
        return;
    }
    if (arg1 == arg0->unk14) {
        arg0->unk14 = arg1->unk8;
        arg0->unkC--;
        arg0->unk10 -= arg1->unk4;
        free3(arg1);
        return;
    }
    for (p = arg0->unk14; p != NULL; p = next) {
        next = p->unk8;
        if (next == arg1) {
            arg0->unkC--;
            arg0->unk10 -= next->unk4;
            p->unk8 = next->unk8;
            free3(next);
            return;
        }
    }
}

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

s32 func_801D3B7C(void) {
    Unk_801D3060 file;

    if (D_801DFE38 == 1 && D_801DFE3C != 0 && (s16)func_801D31C8(D_801DFE3C)) {
        if (D_801DFE40 == 0) {
            if (func_801D3060(&file, "\\C\\CITY.F;1") == 0) {
                D_801DFE40 = func_801D2210(&file, 0, 0);
            }
        } else if (D_801DFE40 > 0 && (s16)func_801D31C8(D_801DFE40)) {
            func_801D3060(&file, "\\C\\CITY.F;1");
            if (func_801D2F18(D_801DFE40, file.unk8, "\\C\\CITY.BC;1") == 0) {
                return 1;
            }
        }
    }
    return 0;
}

static inline s32 func_801D3C50_inline(char *buf, s32 type) {
    Unk_801D32F0 **q = NULL;
    if (D_801DFE38 == 2 && D_801DFE3C > 0) {
        q = (Unk_801D32F0 **)func_801D32F0(D_801DFE3C);
    }
    if (q != NULL) {
        if (type != 0) {
            sprintf(buf, D_80173008, D_801DFE44, *q);
        } else {
            sprintf(buf, D_80173018, D_801DFE44, *q);
        }
        return 1;
    }
    return 0;
}

s32 func_801D3C50(void) {
    char name[32];
    Unk_801D3060 file;

    if (D_801DFE38 != 2 || D_801DFE3C == 0 || !(s16)func_801D31C8(D_801DFE3C)) {
        return 0;
    }
    if (D_801DFE40 == 0) {
        if (func_801D3C50_inline(name, 0) && func_801D3060(&file, name) == 0) {
            D_801DFE40 = func_801D2210(&file, 0, 0);
            return 0;
        }
    } else {
        if (D_801DFE40 <= 0) {
            return 1;
        }
        if (!(s16)func_801D31C8(D_801DFE40)) {
            return 0;
        }
        func_801D3C50_inline(name, 0);
        func_801D3060(&file, name);
        func_801D3C50_inline(name, 1);
        if (func_801D2F18(D_801DFE40, file.unk8, name) != 0) {
            return 0;
        }
        func_801D5BE4();
    }
    return 1;
}

s32 func_801D3E1C(s16 arg0, s16 arg1) {
    Unk_801D3E1C **p;
    s32 ret;

    ret = 0;
    if (D_801DFE38 != 1) {
        p = (Unk_801D3E1C **)ret;
    } else {
        if (D_801DFE3C > 0) {
            ret = func_801D32F0(D_801DFE3C);
        }
        p = (Unk_801D3E1C **)ret;
    }
    if (p != NULL) {
        if (arg0 >= 0 && arg0 < (*p)->unk14 && arg1 >= 0 && arg1 < (*p)->unk18) {
            if (((s16 *)(*p + 1))[(arg0 * (*p)->unk18 + arg1) * 2] != 0) {
                return 1;
            }
        }
    }
    return 0;
}

static inline s32 func_801D3EEC_inline(void) {
    s32 ret = 0;
    if (D_801DFE38 == 1 && D_801DFE3C > 0) {
        ret = func_801D32F0(D_801DFE3C);
    }
    return ret;
}

static inline u8 func_801D3EEC_inline2(s32 arg0, s32 arg1) {
    Unk_801D32F0 **q = (Unk_801D32F0 **)func_801D3EEC_inline();
    if (q == NULL) {
        return 0;
    }
    if (!(((*q)->unk4 <= arg0 && arg0 <= (*q)->unkC) || (arg0 <= (*q)->unk4 && (*q)->unkC <= arg0))) {
        return 0;
    }
    if (!(((*q)->unk8 <= arg1 && arg1 <= (*q)->unk10) || (arg1 <= (*q)->unk8 && (*q)->unk10 <= arg1))) {
        return 0;
    }
    return 1;
}

s32 func_801D3EEC(s16 arg0, s16 arg1, u8 arg2, u8 *arg3) {
    Unk_801D32F0 **q = (Unk_801D32F0 **)func_801D3EEC_inline();
    u8 *e;

    if (q != NULL && func_801D3EEC_inline2(arg0, arg1)) {
        e = (u8 *)&(*q)->unk20[(arg0 * (*q)->unk18 + arg1) * 2];
        if (((s16 *)e)[0] == -1) {
            e = (u8 *)&(*q)->unk20[(((s16 *)e)[1] + arg2) * 2];
        }
        if (arg2 == 0) {
            *arg3 = e[2];
        } else {
            *arg3 = e[3];
        }
        return 1;
    }
    return 0;
}

s32 func_801D40F4(s16 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4, u8 *arg5) {
    u8 flags;

    if ((u8)func_801D3EEC(arg0, arg1, arg2, &flags)) {
        if (arg3 == arg0 + 1 && arg4 == arg1) {
            if (flags & 4) {
                if (flags & 0x40) {
                    *arg5 = 1;
                } else {
                    *arg5 = 0;
                }
            }
        } else if (arg3 == arg0 && arg4 == arg1 + 1) {
            if (flags & 8) {
                if (flags & 0x80) {
                    *arg5 = 1;
                } else {
                    *arg5 = 0;
                }
            }
        } else if (arg3 == arg0 - 1 && arg4 == arg1) {
            if (flags & 1) {
                if (flags & 0x10) {
                    *arg5 = 1;
                } else {
                    *arg5 = 0;
                }
            }
        } else if (arg3 == arg0 && arg4 == arg1 - 1) {
            if (flags & 2) {
                if (flags & 0x20) {
                    *arg5 = 1;
                } else {
                    *arg5 = 0;
                }
            }
        } else {
            *arg5 = 0;
        }
        if ((u8)func_801D3E1C(arg3, arg4)) {
            return 1;
        }
    }
    *arg5 = 0;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D42F4);

static inline u8 func_801D4FA0_inline(s32 x, s32 y) {
    Unk_801D32F0 **p;
    s32 ret = 0;
    if (D_801DFE38 == 1 && D_801DFE3C > 0) {
        ret = func_801D32F0(D_801DFE3C);
    }
    p = (Unk_801D32F0 **)ret;
    if (p == NULL) {
        return 0;
    }
    if (!((x >= (*p)->unk4 && x <= (*p)->unkC) || (x <= (*p)->unk4 && x >= (*p)->unkC))) {
        return 0;
    }
    if (!((y >= (*p)->unk8 && y <= (*p)->unk10) || (y <= (*p)->unk8 && y >= (*p)->unk10))) {
        return 0;
    }
    return 1;
}

void func_801D4D24(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3) {
    Unk_801D32F0 **p;
    s32 ret = 0;
    s32 w;
    s32 h;

    *arg2 = -1;
    *arg3 = -1;
    if (D_801DFE38 == 1 && D_801DFE3C > 0) {
        ret = func_801D32F0(D_801DFE3C);
    }
    p = (Unk_801D32F0 **)ret;
    if (p != NULL && func_801D4FA0_inline(arg0, arg1)) {
        w = ((*p)->unkC - (*p)->unk4) / (*p)->unk14;
        h = ((*p)->unk10 - (*p)->unk8) / (*p)->unk18;
        if (w != 0 && h != 0) {
            *arg2 = (arg0 - (*p)->unk4) / w;
            *arg3 = (arg1 - (*p)->unk8) / h;
        }
    }
}

s32 func_801D4FA0(s32 arg0, s32 arg1) {
    s32 x;
    s32 y;

    if (func_801D4FA0_inline(arg0, arg1)) {
        func_801D4D24(arg0, arg1, &x, &y);
        if ((u8)func_801D3E1C(x, y)) {
            return func_801D6120(x, y);
        }
        return 0;
    }
    return 0;
}

void func_801D50F4(Unk_801E7830 *arg0, u8 *arg1) {
    s32 ret;
    Unk_801D6B58 **q = NULL;
    Unk_801D5BE4 *e;
    s16 i;
    s16 j;

    if (arg1[1] == arg0->unk0 && arg1[2] == arg0->unk1) {
        return;
    }
    for (i = 0; i < arg0->unkA; i++) {
        if (arg0->unk10[i] != 0) {
            func_801D28C0(arg0->unk10[i]);
            arg0->unk10[i] = 0;
        }
    }
    arg0->unk0 = arg1[1];
    arg0->unk1 = arg1[2];
    arg0->unkA = 0;
    arg0->unk6 = 0;
    arg0->unk4 = 0;
    for (i = 0; i < 32; i++) {
        arg0->unk10[i] = 0;
    }
    ret = 0;
    if (D_801DFE38 == 2 && D_801DFE3C > 0) {
        ret = func_801D32F0(D_801DFE3C);
    }
    q = (Unk_801D6B58 **)ret;
    if (q != NULL) {
        for (arg0->unk2 = 0; arg0->unk2 < (*q)->unkE; arg0->unk2++) {
            e = &(*q)->unk14[arg0->unk2];
            for (j = 0; j < e->unk2; j++) {
                if (((Unk_801D50F4 *)e->unk8)[j].unk0 == arg0->unk0 && ((Unk_801D50F4 *)e->unk8)[j].unk1 == arg0->unk1) {
                    return;
                }
            }
        }
    } else {
        arg0->unk2 = (*q)->unkE;
    }
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D1E70", func_801D5324);

static inline u8 func_801D5934_inline(Unk_801E7830 *p, u8 *arg1) {
    if (arg1[1] != p->unk0 || arg1[2] != p->unk1) {
        return 1;
    }
    return 0;
}

static inline s32 func_801D5934_inline2(void) {
    Unk_801E7830 *p = &D_801E7830[D_801DFE48];
    if (p->unk6 > 0) {
        return p->unkA;
    }
    return 0;
}

static inline s32 func_801D5934_inline3(Unk_801E7830 *q, u8 *arg1, s32 prev) {
    s16 sp18 = 0;
    s32 *buf = q->unk10;
    if (func_801D23FC(D_801DFFE0, D_801E7650, buf, 1) == 0) {
        q->unk6 = 1;
    }
    D_801DFFE4 = 0;
    D_801DFE48 = D_801DFE48 == 0;
    func_801D50F4(&D_801E7830[1 - D_801DFE48], arg1);
    if (func_801D254C(&D_801DFFE0, D_801E7650, buf, 1, &sp18) == 0) {
        q->unk6 = 1;
    }
    q->unkA = D_801DFFE0;
    if (q->unk6 == 1) {
        return prev != D_801DFFE0;
    }
    if (sp18 != 0) {
        return 3;
    }
    return 2;
}

s32 func_801D5934(s32 arg0, u8 *arg1) {
    s16 sp18 = 0;
    s32 ret = 0;
    s32 prev;
    s32 *buf;
    Unk_801E7830 *q;
    Unk_801E7830 *r;

    if (!func_801D5934_inline(&D_801E7830[D_801DFE48], arg1)) {
        if (D_801DFFE4 != 0) {
            D_801DFFE4 = 0;
            ret = 1;
        }
        return ret;
    }
    if (!func_801D5934_inline(&D_801E7830[1 - D_801DFE48], arg1)) {
        return ret;
    }
    if ((s16)func_801D31B8() == 0) {
        return ret;
    }
    prev = func_801D5934_inline2();
    func_801D3724();
    func_801D50F4(&D_801E7830[1 - D_801DFE48], arg1);
    func_801D5324(arg0, &D_801E7830[1 - D_801DFE48]);
    q = &D_801E7830[1 - D_801DFE48];
    r = q;
    buf = q->unk10;
    if (func_801D23FC(D_801DFFE0, D_801E7650, buf, 1) == 0) {
        q->unk6 = 1;
    }
    D_801DFFE4 = 0;
    D_801DFE48 = D_801DFE48 == 0;
    func_801D50F4(&D_801E7830[1 - D_801DFE48], arg1);
    if (func_801D254C(&D_801DFFE0, D_801E7650, buf, 1, &sp18) == 0) {
        q->unk6 = 1;
    }
    r->unkA = D_801DFFE0;
    if (r->unk6 == 1) {
        ret = prev != D_801DFFE0;
    } else if (sp18 != 0) {
        ret = 3;
    } else {
        ret = 2;
    }
    return ret;
}

void func_801D5BE4(void) {
    s32 ret = 0;
    Unk_801D6B58 **q;
    Unk_801D6940 *p;
    Unk_801D6DC8 *r;
    Unk_801D5BE4 *e;
    s32 i;
    s32 j;

    if (D_801DFE38 == 2 && D_801DFE3C > 0) {
        ret = func_801D32F0(D_801DFE3C);
    }
    q = (Unk_801D6B58 **)ret;
    if (q != NULL) {
        (*q)->unk10 = (Unk_801D6940 *)((s32)*q + (s32)(*q)->unk10);
        p = (*q)->unk10;
        for (i = 0; i < (*q)->unkC; i++, p++) {
            r = p->unk14 = (void *)((s32)*q + (s32)p->unk14);
            for (j = 0; j < p->unkE; j++, r++) {
                r->unk4 = (s32)*q + r->unk4;
            }
            p->unk18 = (s32)*q + p->unk18;
        }
        (*q)->unk14 = (void *)((s32)*q + (s32)(*q)->unk14);
        for (i = 0; i < (*q)->unkE; i++) {
            e = &(*q)->unk14[i];
            e->unk4 = (s32)*q + e->unk4;
            e->unk8 = (s32)*q + e->unk8;
        }
    }
}

void func_801D5D5C(void) {
    Unk_801E7950 *p;
    s32 i;

    p = &D_801E7950[D_801DFE49];
    if (p != NULL) {
        p->unk0 = -1;
        p->unk2 = -1;
        p->unk4 = -1;
        p->unk6 = -1;
        p->unkC = 0;
        p->unk8 = 0;
        p->unk9 = 0;
        p->unkA = -1;
        for (i = 19; i >= 0; i--) {
            p->unk10[i] = 0;
        }
    }
    p = &D_801E7950[1 - D_801DFE49];
    if (p != NULL) {
        p->unk0 = -1;
        p->unk2 = -1;
        p->unk4 = -1;
        p->unk6 = -1;
        p->unkC = 0;
        p->unk8 = 0;
        p->unk9 = 0;
        p->unkA = -1;
        for (i = 19; i >= 0; i--) {
            p->unk10[i] = 0;
        }
    }
}

static inline u8 func_801D5E28_inline(s16 cx, s16 cy, u8 cd, Unk_801D2A48 *e) {
    Unk_801D32F0 **p = NULL;
    s16 *s;
    s32 ret = 0;
    if (D_801DFE38 == 1 && D_801DFE3C > 0) {
        ret = func_801D32F0(D_801DFE3C);
    }
    p = (Unk_801D32F0 **)ret;
    if (p == NULL) {
        return 0;
    }
    if (cx < 0 || cx >= (*p)->unk14) {
        return 0;
    }
    if (cy < 0 || cy >= (*p)->unk18) {
        return 0;
    }
    s = &(*p)->unk20[(cx * (*p)->unk18 + cy) * 2];
    if (s[0] == -1) {
        s = &(*p)->unk20[(s[1] + cd) * 2];
    }
    if (func_801D30E4(D_801DFE40, s[0], (Unk_801D3060 *)e) == 0) {
        return 1;
    }
    return 0;
}

void func_801D5E28(Unk_801E7950 *arg0) {
    Unk_801D2A48 e;
    s16 cx;
    s16 cy;
    u8 cd;
    s16 x;
    s16 y;
    u8 d;
    s32 max;
    s32 total;
    s32 i;
    s32 j;

    x = cx = arg0->unk0;
    y = cy = arg0->unk2;
    d = arg0->unk8;
    cd = arg0->unk9;
    max = func_801D2E48(1);
    total = 0;
    D_801DFFE0 = 0;
    for (i = 0; i < 20; i++) {
        if (!func_801D5E28_inline(cx, cy, cd, &e)) {
            if (!func_801D42F4(x, y, d, &cx, &cy, &cd)) {
                break;
            }
        } else {
            for (j = 0; j < D_801DFFE0; j++) {
                if (D_801E7650[j].unk4 == e.unk4) {
                    break;
                }
            }
            if (j < D_801DFFE0) {
                if (!func_801D42F4(x, y, d, &cx, &cy, &cd)) {
                    break;
                }
            } else {
                total += e.unk10;
                if (total >= max) {
                    break;
                }
                e.unk14 = 1;
                D_801E7650[D_801DFFE0] = e;
                D_801DFFE0++;
                if (!func_801D42F4(x, y, d, &cx, &cy, &cd)) {
                    break;
                }
            }
        }
    }
    qsort(D_801E7650, D_801DFFE0, sizeof(Unk_801D2A48), func_801D6DC8);
    i = 0;
    while (i < D_801DFFE0) {
        i++;
    }
}

static inline s32 func_801D6120_inline(Unk_801E7950 *p, s16 x, s16 y) {
    if (p->unk0 != x || p->unk2 != y) {
        return 1;
    }
    return 0;
}

static inline s32 func_801D6120_inline2(void) {
    Unk_801E7950 *p = &D_801E7950[D_801DFE49];
    return p->unkA > 0 ? p->unkC : 0;
}

static inline void func_801D6120_inline3(Unk_801E7950 *p, s16 x, s16 y) {
    s32 i;
    u8 d;
    if (p->unk0 == x && p->unk2 == y) {
        return;
    }
    for (i = 0; i < p->unkC; i++) {
        if (p->unk10[i] != 0) {
            func_801D28C0(p->unk10[i]);
            p->unk10[i] = 0;
        }
    }
    p->unkC = 0;
    p->unkA = 0;
    if (p->unk0 >= 0 && p->unk2 >= 0) {
        d = 0;
        func_801D40F4(p->unk0, p->unk2, p->unk8, x, y, &d);
        p->unk8 = d;
    } else {
        p->unk8 = 0;
    }
    p->unk0 = x;
    p->unk2 = y;
    p->unk4 = x;
    p->unk6 = y;
    p->unk9 = p->unk8;
}

s32 func_801D6120(s16 arg0, s16 arg1) {
    s16 sp1A;
    s32 ret = 0;
    s32 prev;
    Unk_801E7950 *q;

    if (!func_801D6120_inline(&D_801E7950[D_801DFE49], arg0, arg1)) {
        return ret;
    }
    if (!func_801D6120_inline(&D_801E7950[1 - D_801DFE49], arg0, arg1)) {
        return ret;
    }
    if ((s16)func_801D31B8() == 0) {
        return ret;
    }
    prev = func_801D6120_inline2();
    func_801D3724();
    func_801D6120_inline3(&D_801E7950[1 - D_801DFE49], arg0, arg1);
    func_801D5E28(&D_801E7950[1 - D_801DFE49]);
    q = &D_801E7950[1 - D_801DFE49];
    if (func_801D23FC(D_801DFFE0, D_801E7650, q->unk10, 1) == 0) {
        q->unkA = 1;
    }
    D_801DFE49 = D_801DFE49 == 0;
    func_801D6120_inline3(&D_801E7950[1 - D_801DFE49], arg0, arg1);
    if (func_801D254C(&D_801DFFE0, D_801E7650, q->unk10, 1, &sp1A) == 0) {
        q->unkA = 1;
    }
    q->unkC = D_801DFFE0;
    if (q->unkA == 1) {
        ret = prev != D_801DFFE0;
    } else if (sp1A != 0) {
        ret = 3;
    } else {
        ret = 2;
    }
    return ret;
}

void func_801D654C(s16 *arg0, s32 *arg1) {
    Unk_801E7950 *p;
    s16 n;
    s16 i;
    s16 j;
    u8 found;
    s16 max;

    max = *arg0;
    *arg0 = 0;
    p = &D_801E7950[D_801DFE49];
    if (p->unkA > 0) {
        n = 0;
        for (i = 0; i < p->unkC; i++) {
            found = 0;
            for (j = 0; j < n; j++) {
                if (arg1[j] == p->unk10[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                arg1[n] = p->unk10[i];
                n++;
                if (n == max) {
                    break;
                }
            }
        }
        *arg0 = n;
    }
}

void func_801D6674(s16 *arg0, s32 *arg1) {
    s16 max = *arg0;
    Unk_801E7950 *p;
    s16 n;
    s16 i;
    s16 j;
    u8 found;

    *arg0 = 0;
    n = 0;
    p = &D_801E7950[D_801DFE49];
    for (i = 0; i < p->unkC; i++) {
        found = 0;
        for (j = 0; j < n; j++) {
            if (arg1[j] == p->unk10[i]) {
                found = 1;
                break;
            }
        }
        if (!found && func_801D36C4(p->unk10[i])) {
            arg1[n] = p->unk10[i];
            n++;
            if (n == max) {
                break;
            }
        }
    }
    *arg0 = n;
}

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

s32 func_801D6894(s32 arg0, char *arg1) {
    char name[32];
    Unk_801D3060 file;
    s32 ret;
    char *p = name;
    Unk_801D3060 *f = &file;

    func_801D1E70();
    D_801DFE38 = 2;
    D_801DFE3C = 0;
    D_801DFE40 = 0;
    D_801DFE44 = arg0;
    sprintf(p, D_80172FF8, arg0, arg1);
    ret = func_801D3060(f, p);
    if (ret == 0) {
        D_801DFE3C = func_801D2210(f, 0, 4);
        if (D_801DFE3C == 0) {
            ret = -1;
        }
    } else {
        ret = -1;
    }
    func_801D6A58();
    return ret;
}

void func_801D6940(s32 arg0, s32 *arg1, u8 *arg2) {
    s32 ret = 0;
    Unk_801D32F0 **q = NULL;
    Unk_801D6940 *p;

    if (D_801DFE38 == 2 && D_801DFE3C > 0) {
        ret = func_801D32F0(D_801DFE3C);
    }
    q = (Unk_801D32F0 **)ret;
    if (q != NULL) {
        p = &((Unk_801D6940 *)(*q)->unk10)[arg0];
        arg1[0] = p->unk0;
        arg1[1] = p->unk4;
        arg1[2] = p->unk8;
        arg2[0] = 0;
        arg2[1] = p->unkC;
        arg2[2] = p->unkD;
    }
}

void func_801D6A04(void) {
    func_801D7168()->unkA = 1;
}

void func_801D6A2C(void) {
    Unk_801E7830 *p = &D_801E7830[D_801DFE48];

    p->unk6 = 1;
}

void func_801D6A58(void) {
    Unk_801E7830 *p;
    s32 i;

    p = &D_801E7830[D_801DFE48];
    if (p != NULL) {
        p->unk0 = 0;
        p->unk1 = 0;
        p->unk2 = 0;
        p->unk4 = 0;
        p->unk8 = 0;
        p->unkA = 0;
        p->unk6 = 0;
        for (i = 31; i >= 0; i--) {
            p->unk10[i] = 0;
        }
    }
    p = &D_801E7830[1 - D_801DFE48];
    if (p != NULL) {
        p->unk0 = 0;
        p->unk1 = 0;
        p->unk2 = 0;
        p->unk4 = 0;
        p->unk8 = 0;
        p->unkA = 0;
        p->unk6 = 0;
        for (i = 31; i >= 0; i--) {
            p->unk10[i] = 0;
        }
    }
}

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

s32 func_801D6BA8(s32 arg0, s32 arg1) {
    s32 ret = 0;
    Unk_801D32F0 **q = NULL;

    if (D_801DFE38 == 1 && D_801DFE3C > 0) {
        ret = func_801D32F0(D_801DFE3C);
    }
    q = (Unk_801D32F0 **)ret;
    if (q == NULL) {
        return 0;
    }
    if (!(((*q)->unk4 <= arg0 && arg0 <= (*q)->unkC) || (arg0 <= (*q)->unk4 && (*q)->unkC <= arg0))) {
        return 0;
    }
    if (!(((*q)->unk8 <= arg1 && arg1 <= (*q)->unk10) || (arg1 <= (*q)->unk8 && (*q)->unk10 <= arg1))) {
        return 0;
    }
    return 1;
}

s32 func_801D6CA8(s16 arg0, s16 arg1, u8 arg2, Unk_801D3060 *arg3) {
    s32 ret = 0;
    Unk_801D32F0 **q = NULL;
    s16 *e;

    if (D_801DFE38 == 1 && D_801DFE3C > 0) {
        ret = func_801D32F0(D_801DFE3C);
    }
    q = (Unk_801D32F0 **)ret;
    if (q != NULL && arg0 >= 0 && arg0 < (*q)->unk14 && arg1 >= 0 && arg1 < (*q)->unk18) {
        e = &(*q)->unk20[(arg0 * (*q)->unk18 + arg1) * 2];
        if (e[0] == -1) {
            e = &(*q)->unk20[(e[1] + arg2) * 2];
        }
        if (func_801D30E4(D_801DFE40, e[0], arg3) == 0) {
            return 1;
        }
    }
    return 0;
}

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

void func_801D6E60(s16 *arg0, s32 *arg1) {
    s16 max = *arg0;
    Unk_801E7830 *p;
    s16 n;
    s16 i;
    s16 j;
    u8 found;
    s32 v;

    *arg0 = 0;
    p = &D_801E7830[D_801DFE48];
    n = 0;
    if (p->unk6 > 0) {
        for (i = 0; i < p->unkA; i++) {
            found = 0;
            v = p->unk10[i];
            for (j = 0; j < n; j++) {
                if (arg1[j] == v) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                arg1[n] = v;
                n++;
                if (n == max) {
                    break;
                }
            }
        }
        *arg0 = n;
    }
}

void func_801D6F74(s16 *arg0, s32 *arg1) {
    s16 max = *arg0;
    Unk_801E7830 *p;
    s16 n;
    s16 i;
    s16 j;
    u8 found;
    s32 v;

    *arg0 = 0;
    n = 0;
    p = &D_801E7830[D_801DFE48];
    for (i = 0; i < p->unkA; i++) {
        found = 0;
        v = p->unk10[i];
        for (j = 0; j < n; j++) {
            if (arg1[j] == v) {
                found = 1;
                break;
            }
        }
        if (!found && func_801D36C4(v)) {
            arg1[n] = v;
            n++;
            if (n == max) {
                break;
            }
        }
    }
    *arg0 = n;
}

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

void func_801D71D0(Unk_801E7950 *arg0, s16 arg1, s16 arg2) {
    s32 i;
    u8 out;

    if (arg0->unk0 != arg1 || arg0->unk2 != arg2) {
        for (i = 0; i < arg0->unkC; i++) {
            if (arg0->unk10[i] != 0) {
                func_801D28C0(arg0->unk10[i]);
                arg0->unk10[i] = 0;
            }
        }
        arg0->unkC = 0;
        arg0->unkA = 0;
        if (arg0->unk0 >= 0 && arg0->unk2 >= 0) {
            out = 0;
            func_801D40F4(arg0->unk0, arg0->unk2, arg0->unk8, arg1, arg2, &out);
            arg0->unk8 = out;
        } else {
            arg0->unk8 = 0;
        }
        arg0->unk0 = arg1;
        arg0->unk2 = arg2;
        arg0->unk4 = arg1;
        arg0->unk6 = arg2;
        arg0->unk9 = arg0->unk8;
    }
}

s32 func_801D72F4(s16 *arg0, s16 arg1, s16 arg2) {
    if (arg0[0] != arg1 || arg0[1] != arg2) {
        return 1;
    }
    return 0;
}
