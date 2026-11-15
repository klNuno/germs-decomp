#include "common.h"

typedef struct { s16 unk0, unk2, unk4, unk6; } Unk_801DFD30;
Unk_801DFD30 *D_801DFD30;
typedef struct { s16 unk0[5]; s16 unkA; char *unkC; s16 unk10; s16 unk12; s32 unk14; s32 unk18; s32 unk1C; } Unk_801E0340;
extern Unk_801E0340 D_801E0340;
void func_801CD688(s32 a);
typedef struct { s16 unk0; s16 unk2; u16 unk4; } Unk_8018BD60_0;
typedef struct { Unk_8018BD60_0 *unk0; } Unk_8018BD60;
void func_8018BA48(u16 a);
typedef struct { s32 unk0; s16 unk4; s16 unk6; } Unk_801E056C;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; u16 unkA; s16 unkC; s16 unkE; u16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 *unk1C; } Unk_801E058C;
typedef struct {
    u16 unk0[0x60];
    s16 unkC0;
    u16 unkC2[0xF];
    u8 unkE0[0x11C];
    s16 unk1FC;
    s16 unk1FE;
    u16 unk200;
    u16 unk202;
    Unk_801E056C unk204[4];
    Unk_801E058C unk224;
    s32 unk244;
    u8 unk248[4];
    s16 unk24C;
    s16 unk24E;
    s16 unk250;
    s16 unk252;
    s16 unk254;
} Unk_801E0368;
extern Unk_801E0368 D_801E0368;
extern Unk_801E058C D_801E058C;
void func_80185A60(s32 a, u16 b, s32 c);
void func_801A4A68(s32 arg0, s32 arg1);
void func_8018CB70(Unk_801E058C *p, s32 b);
u16 *D_801DFD34;
s16 D_801DFF04;
s16 D_801DFF06;
extern char D_801DFD38[];
u16 *func_801A44B8(u16 arg0);
void *func_801CC898(u32 size);
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
void func_8018B564(Unk_801E0368 *a, s16 b);
void func_801A43F4(s32 arg0);
void free3(void *ptr);
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_80174F54;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s32 unk8; s32 unkC; s32 unk10; s16 unk14; s16 unk16; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; s32 unk3C; s32 unk40; s32 unk44; s32 unk48; } Unk_801762F4;
typedef struct { u16 unk0; s16 unk2; s32 unk4; s16 unk8; u16 unkA; u8 unkC[0xC0]; } Unk_801767D4;
typedef struct { u16 unk0; s16 unk2; s32 unk4[8]; } Unk_80176890;
typedef struct { u16 unk0; u8 unk2[0x19]; u8 unk1B; u8 unk1C[4]; } Unk_8018F590;
typedef struct { u16 unk0; u8 unk2[0x5E]; } Unk_80188FEC;
typedef struct { u8 unk0[0xC]; u16 unkC; s16 unkE; } Unk_8018BC50_8;
typedef struct { u16 unk0; s16 unk2; s32 unk4; Unk_8018BC50_8 *unk8; Unk_8018BC50_8 *unkC; } Unk_8018BC50;
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14;
    s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34;
    Unk_80174F54 *unk38; Unk_801762F4 *unk3C; Unk_801767D4 *unk40; Unk_80176890 *unk44;
    s32 unk48; Unk_8018BC50 *unk4C; Unk_8018F590 *unk50; s32 unk54; Unk_80188FEC *unk58;
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
u16 D_801DFF00;
u16 D_801DFF02;
void func_801A461C(s32 a, s32 b, s32 c);
typedef struct { s16 unk0; u8 unk2[0x2A]; s16 unk2C; s16 unk2E; s16 unk30; u8 unk32[6]; s16 unk38; u8 unk3A[0xA]; s16 unk44; u8 unk46[4]; s16 unk4A; } Unk_801E0710;
extern Unk_801E0710 D_801E0710;
void func_8017345C(void);
void func_801759B0(void);
void func_80184C6C(void);
void func_8018F234(void);
void func_801AC4A8(void);
void func_8018DE58(void);
void func_801A7560(void);
void func_801979B4(u16 a, s16 b, s16 c);
void func_80185E38(void);
void func_801865C0(void);
void func_80186010(void);
void func_801A0418(u16 a);
void func_8018CD4C(Unk_801E058C *p);
void func_801A2678(s32 a);
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    u8 unkC[0x8];
    s32 unk14;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
s32 func_801CC378(s32 *arg0);
void func_801CC734(s32 *arg0);
void func_80189928(s32 *a);
void func_80189970(s16 a);
void func_801899AC(s32 *a);
s16 func_8018970C(s32 *arg0);
void func_8018C2FC(u16 a, s16 b, s16 c);
void func_801A4824(s32 a, s32 b, s32 c, s32 d);
void func_801A3F90(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void func_8018C864(s32 a, s32 b, s32 c);
typedef struct { u16 unk0; u16 unk2; u8 unk4[0x10]; s16 unk14; } Unk_8018CD4C_1C;
typedef struct { u8 unk0[0x10]; s16 unk10; u16 unk12; s16 unk14; u16 unk16; s32 unk18; Unk_8018CD4C_1C *unk1C; } Unk_8018CD4C;
void *memset(void *dst, s32 c, u32 n);
s32 LoadImage2(void *rect, void *p);
void func_801A2678(s32 arg0);
typedef struct { s16 unk0; s16 unk2; } Unk_8018C864_1C;
typedef struct { u8 unk0[0x1C]; Unk_8018C864_1C *unk1C; } Unk_8018C864;
typedef struct { u16 unk0; u8 unk2[2]; u8 unk4[0x24]; } Unk_801891A4;
Unk_801891A4 *func_801891A4(s16 arg0);
s32 strlen(char *s);
u16 *Krom2RawAdd2(u16 sjis);
typedef struct {
    s16 unk0[5];
    s16 unkA;
    char *unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    u8 unk1E[2];
    char unk20[4];
} Unk_8018C554;
char *strncpy(char *dst, char *src, u32 n);
typedef struct {
    s16 unk0;
    s16 unk2;
    u16 unk4;
    u16 unk6;
    u8 unk8[0xA];
    u16 unk12;
} Unk_801E0324_1C;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    u16 unkC;
    s16 unkE;
    s16 unk10;
    u16 unk12;
    s32 unk14;
    s32 unk18;
    Unk_801E0324_1C *unk1C;
} Unk_801E0324_10;
typedef struct {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u16 *unk8;
    u16 *unkC;
    Unk_801E0324_10 *unk10;
    Unk_801E0324_10 *unk14;
    Unk_801E0324_10 *unk18;
    Unk_801E0324_10 *unk1C;
} Unk_801E0324;
extern Unk_801E0324 *D_801E0324[];
s16 D_801DFEF0;
s16 D_801DFEF2;
s16 D_801DFEF4;
s16 D_801DFEF6;
s16 D_801DFEF8;
s16 D_801DFEFA;
s16 D_801DFEFC;
s16 D_801DFEFE;
typedef struct {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_8018ACAC;
void func_801A3DD4(Unk_801E0324_10 **arg0, void *arg1);
void func_801A43A8(s32 arg0);
s16 D_801DFD48;
extern s32 D_801DFED4;
extern s32 D_801DFED8;
extern s32 D_801DFEDC;
extern s32 D_801DFEE0;
extern s32 D_801DFEE4;
extern s32 D_801DFEE8;
extern void *D_801DFE50;
extern void *D_801DFE54;
extern void *D_801DFE5C;
extern void *D_801DFE80;
extern void *D_801DFF0C;
extern void *D_801DFF80;
extern void *D_801DFFA0;
void __main(void);
void func_801CC8F0(void);
void func_801CCAF4(void *arg0);
void func_8018920C(void);
void func_801A02C8(void);
void func_80192B8C(s32 arg0, s32 arg1);
void func_801971D4(void);
void func_801863B4(void);
void func_801AC9B4(void);
void func_801A5254(s32 arg0);
void func_801CD808(void);
void func_8018A24C(void);
void func_8017E544(void);
void func_80194E5C(void);
void func_801A9070(void);

void func_8018ACAC(Unk_801E0324 **arg0, Unk_8018ACAC *arg1, s16 arg2) {
    *arg0 = func_801CC898(0x20);
    if (*arg0 == NULL) {
        func_801CD54C(3, "Error Allocating MAIL Handler", D_801DFD38, 0x3B);
    }
    (*arg0)->unk0 = arg1->unk0;
    (*arg0)->unk2 = arg2;
    (*arg0)->unk4 = arg1->unk2;
    (*arg0)->unk6 = 0;

    func_801A3DD4(&(*arg0)->unk10, (u8 *)arg1 + arg1->unk4);
    func_801A43A8((s32)(*arg0)->unk10);
    (*arg0)->unk10->unk4 = 1;
    (*arg0)->unk10->unkC = 0x43;
    (*arg0)->unk10->unkE = 1;
    D_801DFEF0 = (*arg0)->unk10->unk1C->unk12;
    D_801DFEF8 = (*arg0)->unk10->unk12;

    if ((*arg0)->unk4 >= 2) {
        func_801A3DD4(&(*arg0)->unk14, (u8 *)arg1 + arg1->unk8);
        func_801A43A8((s32)(*arg0)->unk14);
        (*arg0)->unk14->unk4 = 0;
        (*arg0)->unk14->unkC = 0x43;
        (*arg0)->unk14->unkE = 1;
        D_801DFEF2 = (*arg0)->unk14->unk1C->unk12;
        D_801DFEFA = (*arg0)->unk14->unk12;
    }
    if ((*arg0)->unk4 >= 3) {
        func_801A3DD4(&(*arg0)->unk18, (u8 *)arg1 + arg1->unkC);
        func_801A43A8((s32)(*arg0)->unk18);
        (*arg0)->unk18->unk4 = 0;
        (*arg0)->unk18->unkC = 0x43;
        (*arg0)->unk18->unkE = 1;
        D_801DFEF4 = (*arg0)->unk18->unk1C->unk12;
        D_801DFEFC = (*arg0)->unk18->unk12;
    }
    if ((*arg0)->unk4 >= 4) {
        func_801A3DD4(&(*arg0)->unk1C, (u8 *)arg1 + arg1->unk10);
        func_801A43A8((s32)(*arg0)->unk1C);
        (*arg0)->unk1C->unk4 = 0;
        (*arg0)->unk1C->unkC = 0x43;
        (*arg0)->unk1C->unkE = 1;
        D_801DFEF6 = (*arg0)->unk1C->unk1C->unk12;
        D_801DFEFE = (*arg0)->unk1C->unk12;
    }

    (*arg0)->unk8 = func_801A44B8((*arg0)->unk0 + 0x217);
    if ((*arg0)->unk8 != NULL) {
        func_801A461C((u16)((*arg0)->unk0 + 0x217), 7, 0x4D44);
        func_801A461C((u16)((*arg0)->unk0 + 0x217), 9, 0x6358);
        D_801DFF00 = (*arg0)->unk8[6];
        (*arg0)->unk8[6] = 0x33;
        (*arg0)->unk8[7] = 1;
    }
    (*arg0)->unkC = func_801A44B8(0x20C);
    if (D_801DFD34 != NULL) {
        D_801DFF02 = D_801DFD34[6];
    }
    if ((*arg0)->unkC != NULL) {
        (*arg0)->unkC[6] = 0x29;
    }
}

void func_8018B11C(s16 arg0) {
    Unk_801E0324 *p = D_801E0324[0];
    s32 v;
    s32 n;
    s32 max;

    if (p == NULL || p->unk4 < 2) {
        return;
    }
    v = p->unk6;
    if (arg0 != 0) {
        v++;
    } else {
        v--;
    }
    n = p->unk4 - 1;
    max = n << 7;
    if (max < v) {
        v = max;
    }
    if (v < 0) {
        v = 0;
    }
    if (p->unkC != NULL) {
        p->unkC[6] = ((v * 114 / n) >> 7) + 41;
    }
    if (v == 0) {
        p->unk10->unk4 = 1;
        p->unk10->unkC = 0x43;
        p->unk10->unk12 = D_801DFEF8;
        p->unk10->unk1C->unk12 = D_801DFEF0;
        p->unk14->unk4 = 0;
        if (p->unk18 != NULL) {
            p->unk18->unk4 = 0;
        }
        if (p->unk1C != NULL) {
            p->unk1C->unk4 = 0;
        }
    } else if (v > 0 && v < 128) {
        p->unk10->unk4 = 1;
        p->unk10->unk12 = D_801DFEF8 - v;
        p->unk10->unk1C->unk12 = D_801DFEF0 + v;
        p->unk14->unk4 = 1;
        p->unk14->unkC = p->unk10->unkC + p->unk10->unk12 - 1;
        p->unk14->unk12 = v;
        if (p->unk18 != NULL) {
            p->unk18->unk4 = 0;
        }
        if (p->unk1C != NULL) {
            p->unk1C->unk4 = 0;
        }
    } else if (v == 128) {
        p->unk10->unk4 = 0;
        p->unk14->unk4 = 1;
        p->unk14->unkC = 0x43;
        p->unk14->unk12 = D_801DFEFA;
        p->unk14->unk1C->unk12 = D_801DFEF2;
        if (p->unk18 != NULL) {
            p->unk18->unk4 = 0;
        }
        if (p->unk1C != NULL) {
            p->unk1C->unk4 = 0;
        }
    } else if (v > 128 && v < 256) {
        p->unk10->unk4 = 0;
        p->unk14->unk4 = 1;
        p->unk14->unk12 = D_801DFEFA + 128 - v;
        p->unk14->unk1C->unk12 = D_801DFEF2 - 128 + v;
        p->unk18->unk4 = 1;
        p->unk18->unkC = p->unk14->unkC + p->unk14->unk12 - 1;
        p->unk18->unk12 = v - 128;
        if (p->unk1C != NULL) {
            p->unk1C->unk4 = 0;
        }
    } else if (v == 256) {
        p->unk10->unk4 = 0;
        p->unk14->unk4 = 0;
        p->unk18->unk4 = 1;
        p->unk18->unkC = 0x43;
        p->unk18->unk12 = D_801DFEFC;
        p->unk18->unk1C->unk12 = D_801DFEF4;
    } else if (v > 256 && v < 384) {
        p->unk10->unk4 = 0;
        p->unk14->unk4 = 0;
        p->unk18->unk4 = 1;
        p->unk18->unk12 = D_801DFEFC + 256 - v;
        p->unk18->unk1C->unk12 = D_801DFEF4 - 256 + v;
        p->unk1C->unk4 = 1;
        p->unk1C->unkC = p->unk18->unkC + p->unk18->unk12 - 1;
        p->unk1C->unk12 = v - 256;
    } else if (v == 384) {
        p->unk10->unk4 = 0;
        p->unk14->unk4 = 0;
        p->unk18->unk4 = 0;
        p->unk1C->unk4 = 1;
        p->unk1C->unkC = 0x43;
        p->unk1C->unk12 = D_801DFEFE;
        p->unk1C->unk1C->unk12 = D_801DFEF6;
    }
    p->unk6 = v;
}

void func_8018B564(Unk_801E0368 *a, s16 b) {
    s32 i;
    s32 n;
    u16 *q;
    Unk_801DFD30 *e;

    n = 0;
    e = D_801DFD30;
    for (i = 0; i < (s16)a->unk0[0x5F]; i++, e++) {
        q = func_801A44B8(e->unk0 + 0x217);
        if (q != NULL) {
            if (i >= D_801DFF04 && i < D_801DFF04 + 9) {
                q[2] = 1;
                q[5] = 0x30;
                q[6] = n * 16 + 0x33;
                n++;
                if (i == b) {
                    func_801A461C((u16)(e->unk0 + 0x217), 9, 0x1F);
                } else {
                    func_801A461C((u16)(e->unk0 + 0x217), 9, 0x6358);
                }
                if (e->unk4 != 0) {
                    func_801A461C((u16)(e->unk0 + 0x217), 7, 0x2C1F);
                } else {
                    func_801A461C((u16)(e->unk0 + 0x217), 7, 0x4D44);
                }
            } else {
                q[2] = 0;
            }
        }
    }
}

s32 func_8018B69C(s16 a, s16 b) {
    Unk_801E0368 *p = &D_801E0368;
    if ((s16)p->unk0[0x5F] == 0) {
        return -1;
    }
    if (a != 0) {
        b--;
        if (b < 0) {
            return 0;
        }
        D_801DFF06--;
        if (D_801DFF06 < 0) {
            D_801DFF06 = 0;
            if (D_801DFF04 > 0) {
                D_801DFF04--;
            }
        }
    } else {
        b++;
        if (b >= (s16)p->unk0[0x5F]) {
            return (s16)(p->unk0[0x5F] - 1);
        }
        D_801DFF06++;
        if (D_801DFF06 >= 9) {
            D_801DFF06 = 8;
            if (D_801DFF04 != b - 8) {
                D_801DFF04 = b - 8;
            }
        }
    }
    func_8018B564(p, b);
    if (D_801DFD34 != NULL) {
        D_801DFD34[6] = b * 114 / ((s16)p->unk0[0x5F] - 1) + 0x29;
    }
    func_801A2678(0xF);
    return b;
}

void func_8018B810(void) {
    s32 i;
    s32 j;
    u16 v;
    Unk_801DFD30 *e;
    Unk_801E0368 *p = &D_801E0368;
    if ((s16)p->unk0[0x5F] != 0) {
        D_801DFF06 = 0;
        D_801DFF04 = 0;
        D_801DFD34 = func_801A44B8(0x20C);
        if (D_801DFD34 != NULL) {
            D_801DFD34[6] = 0x29;
        }
        D_801DFD30 = func_801CC898((s16)p->unk0[0x5F] * 8);
        if (D_801DFD30 == NULL) {
            func_801CD54C(3, "Error Allocating Mail List", D_801DFD38, 0x16A);
        }
        for (i = 0; i < 0x20; i++) {
            j = i / 2 + 0x60;
            if (i & 1) {
                v = (u8)*(p->unk0 + j);
            } else {
                v = *(p->unk0 + j) >> 8;
            }
            if (v & 0x80) {
                e = &D_801DFD30[v & 0x3F];
                e->unk0 = i;
                e->unk2 = v;
                e->unk4 = (v & 0x40) >> 6;
            }
        }
        func_8018B564(p, 0);
    }
}

void func_8018B924(void) {
    s32 i;
    s32 j;
    s32 v;
    s32 t;
    Unk_801DFD30 *e;
    Unk_801E0368 *p = &D_801E0368;
    if ((s16)p->unk0[0x5F] != 0) {
        if (D_801DFD34 != NULL) {
            D_801DFD34[6] = 0x29;
            D_801DFD34 = NULL;
        }
        e = D_801DFD30;
        for (i = 0; i < (s16)p->unk0[0x5F]; i++, e++) {
            v = 0x80;
            if (e->unk4 != 0) {
                v = 0xC0;
            }
            v += i & 0x3F;
            j = e->unk0 / 2 + 0x60;
            if (e->unk0 % 2) {
                t = *(p->unk0 + j);
                *(p->unk0 + j) = v | (t & ~0xFF);
            } else {
                *(p->unk0 + j) = (u8)*(p->unk0 + j) | (v << 8);
            }
        }
        free3(D_801DFD30);
        D_801DFD30 = NULL;
        for (i = 0; i < 0x20; i++) {
            func_801A43F4((u16)(i + 0x217));
        }
    }
}

void func_8018BA48(u16 a) {
    s32 v;
    s32 i;
    s16 odd;
    u16 n;
    Unk_801E0368 *p = &D_801E0368;
    if (a < 0x20) {
        i = a / 2 + 0x60;
        odd = a % 2;
        if (odd) {
            v = (u8)*(p->unk0 + i) & 0x80;
        } else {
            v = (*(p->unk0 + i) >> 8) & 0x80;
        }
        if (v == 0) {
            n = p->unk0[0x5F]++ | 0x80;
            if (odd) {
                *(p->unk0 + i) = n | (*(p->unk0 + i) & 0xFF00);
            } else {
                *(p->unk0 + i) = (u8)*(p->unk0 + i) | (n << 8);
            }
        }
    }
}

void func_8018BB00(s32 a, s32 b) {
    Unk_801E0368 *p = &D_801E0368;
    if ((s16)p->unk0[0x30] == 0) {
        if (a == 0) {
            if (b == 10) {
                func_8018BA48(0xE);
            } else if (b == 0x11) {
                func_8018BA48(8);
            } else if (b == 0x15) {
                func_8018BA48(0x17);
            }
        } else if (a == 1) {
            if (b == 10) {
                func_8018BA48(0xF);
            } else if (b == 0x10) {
                func_8018BA48(0x1C);
            }
        } else if (a == 2) {
            if (b == 10) {
                if ((s16)p->unk0[0xB] == 100 && (s16)p->unk0[1] == 0) {
                    func_8018BA48(2);
                }
                func_8018BA48(0x11);
                if ((s16)p->unk0[0x13] == 100) {
                    func_8018BA48(0x14);
                }
            } else if (b == 0xE) {
                if ((s16)p->unk0[0x11] == 10) {
                    func_8018BA48(0x15);
                }
                func_8018BA48(0x1A);
            }
        } else if (a == 3) {
            if (b == 0xC) {
                func_8018BA48(0x1D);
                if ((s16)p->unk0[0x4D] == 0) {
                    func_8018BA48(0x1F);
                }
            }
        }
    }
}

void func_8018BC50(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_8018BC50 *e = p->unk4C;
    if (e != NULL) {
        D_801DFD30[e->unk2].unk4 = 1;
        if (e->unk8 != NULL) {
            func_801A461C((u16)(e->unk0 + 0x217), 7, 0x2C1F);
            func_801A461C((u16)(e->unk0 + 0x217), 9, 0x1F);
            e->unk8->unkC = D_801DFF00;
            e->unk8->unkE = 2;
        }
        if (e->unkC != NULL) {
            e->unkC->unkC = D_801DFF02;
        }
        func_801A43F4(0x213);
        func_801A43F4(0x214);
        func_801A43F4(0x215);
        func_801A43F4(0x216);
        free3(e);
        p->unk4C = NULL;
    }
}

s16 func_8018BD44(s16 i) { return D_801DFD30[i].unk0; }

void func_8018BD60(Unk_8018BD60 *a) {
    func_8018BA48(a->unk0->unk4);
}

s32 func_8018BD8C(s16 a) {
    s32 v;
    Unk_801E0368 *p = &D_801E0368;
    s32 i = a / 2 + 0x60;
    if (a & 1) {
        v = (u8)p->unk0[i] & 0x40;
    } else {
        v = (p->unk0[i] >> 8) & 0x40;
    }
    return v != 0;
}

void func_8018BDE8(void) {
    Unk_801E0340 *p;
    Unk_801E0340 *q;
    Unk_801E0368 *r;
    s16 f;
    u16 a;
    u16 b;

    __main();
    func_801CC8F0();
    memset(&D_801E02D8, 0, 0x64);
    D_801DFED8 = 0;
    D_801DFEE4 = 0;
    D_801DFEE0 = 0;
    D_801DFEDC = 0;
    D_801DFED4 = 0;
    D_801DFEE8 = 0;
    func_801CCAF4(&D_801DFE50);
    func_801CCAF4(&D_801DFE54);
    func_801CCAF4(&D_801DFE5C);
    func_801CCAF4(&D_801DFE80);
    func_801CCAF4(&D_801DFF0C);
    func_801CCAF4(&D_801DFF80);
    func_801CCAF4(&D_801DFFA0);
    func_8018920C();
    func_801A02C8();
    func_80192B8C(1, 0);
    r = &D_801E0368;
    while (1) {
        q = &D_801E0340;
        f = D_801DFD48;
        if (f != 0) {
            a = r->unk200;
            b = r->unk202;
        }
        memset(r, 0, sizeof(D_801E0368));
        memset(q, 0, 0x24);
        if (f != 0) {
            r->unk200 = a;
            r->unk202 = b;
        } else {
            r->unk200 = 1;
            r->unk202 = 1;
        }
        q->unk0[0] = -1;
        q->unk0[1] = -1;
        func_801971D4();
        r->unk0[0x5F] = 3;
        r->unkC0 = -0x7E80;
        r->unkC2[4] = 0x82;
        r->unk0[0xA] = 100;
        r->unk0[0xB] = 100;
        r->unk0[0xC] = 100;
        r->unk0[0xD] = 100;
        r->unk0[0x1B] = 100;
        r->unk0[0x3E] = 5;
        r->unk0[0x3F] = 0;
        r->unk0[0x30] = 0;
        r->unk1FE = 0;
        r->unk1FC = 0;
        func_801863B4();
        p = &D_801E0340;
        func_801AC9B4();
        func_801A5254(D_801DFD48);
        func_801CD808();
        func_801A4A68(0x400, 1);
        func_801A4A68(0x409, 1);
        func_8018A24C();
        while (p->unk0[4] == 0) {
            if (p->unk0[0] != p->unk0[1]) {
                p->unk0[0] = p->unk0[1];
            }
            switch (p->unk0[0]) {
            case 1:
                func_8017E544();
                break;
            case 0:
                func_80194E5C();
                break;
            case 2:
                func_801A9070();
                break;
            }
        }
        p->unk0[4] = 0;
        func_801A4A68(0x400, 0);
        func_801A4A68(0x409, 0);
        if (D_801DFD48 == 0) {
            D_801DFD48 = 1;
        }
    }
}

s32 func_8018C0A0(s16 a) {
    s32 b;

loop:
    if (a < 0) a += 360;
    if (a >= 360) a -= 360;
    if ((u16)a >= 360) goto loop;
    b = a;
    if (b >= 23 && b < 68) return 1;
    if (b >= 68 && b < 113) return 0;
    if (b >= 113 && b < 158) return 7;
    if (b >= 158 && b < 203) return 6;
    if (b >= 203 && b < 248) return 5;
    if (b >= 248 && b < 293) return 4;
    if (b >= 293 && b < 338) return 3;
    return 2;
}

s32 func_8018C170(void) {
    Unk_801E0340 *p = &D_801E0340;
    if (p->unkA == 0) {
        return 0;
    }
    p->unkA = 0;
    func_801CD688(0);
    return 1;
}

void func_8018C1B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 buf[6];
    s32 n;
    for (n = arg3 * 30; n > 0;) {
            switch (func_801CC378(buf)) {
            case 2:
                func_80189928(buf);
                continue;
            case 4:
                func_80189970(0);
                continue;
            case 0x200:
                func_801899AC(buf);
                continue;
            case 0:
                n -= D_801E6DA0.unk14;
                break;
            case 0x100:
                func_8018970C(buf);
                continue;
            default:
                func_801CC734(buf);
                continue;
            }
            if ((u16)arg0 == 3) {
                func_801A7560();
                func_801A0418(3);
            } else {
                do { func_8018C2FC(arg0, arg1, arg2); } while (0);
            }
    }
}

void func_8018C2FC(u16 a, s16 b, s16 c) {
    Unk_801E0368 *p = &D_801E0368;
    func_8017345C();
    if (a < 2) {
        func_801759B0();
        func_80184C6C();
        func_8018F234();
    } else if (a == 2) {
        func_801AC4A8();
    }
    func_8018DE58();
    func_801A7560();
    func_801979B4(a, b, c);
    if ((u16)(a - 1) < 2) {
        if (p->unk252 != 0) {
            func_80185E38();
        }
        if (p->unk254 != 0) {
            func_801865C0();
        }
        if (p->unk250 != 0) {
            func_80186010();
        }
    }
    func_801A0418(a);
}

void func_8018C414(s16 a, s16 b, s16 c, s16 d) {
    Unk_801E0340 *p = &D_801E0340;
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0368 *q = &D_801E0368;
    p->unk12 = b;
    ((s16 *)&p->unk14)[0] = c;
    ((s16 *)&p->unk14)[1] = d;
    p->unk0[1] = 0;
    p->unkA = 1;
    p->unkC = "\\S\\OFC.S;1";
    p->unk0[3] = 0;
    p->unk0[2] = 0;
    p->unk10 = a;
    if (d == 2) {
        return;
    }
    if ((s16)q->unk0[0x30] != 0 || g->unk2C != 0) {
        return;
    }
    switch (g->unk30) {
    case 0:
        if (g->unk2E >= 3) {
            p->unk0[3] = 1;
            g->unk30 = 1;
            g->unk2E = 0;
        }
        break;
    case 1:
        if (g->unk2E >= 5 && (s16)q->unk0[0x11] != 100) {
            q->unk0[0x11] = 100;
            p->unk0[3] = 1;
            g->unk30 = 2;
            g->unk2E = 0;
        }
        break;
    }
}

void func_8018C50C(s32 a, s32 b, s32 c, s16 d, s16 e) {
    Unk_801E0340 *p = &D_801E0340;
    p->unkA = 1;
    p->unk0[1] = 2;
    p->unk0[3] = 0;
    p->unk0[2] = 1;
    p->unkC = "\\S\\TWN.S;1";
    p->unk14 = a;
    p->unk18 = b;
    p->unk1C = c;
    p->unk12 = d;
    p->unk10 = e;
}

void func_8018C554(u16 arg0, char *arg1, s16 arg2, s16 arg3, u16 arg4, u16 arg5, u16 arg6, u32 arg7, u16 arg8) {
    Unk_8018C554 *p = (Unk_8018C554 *)&D_801E0340;
    Unk_801E0368 *g = &D_801E0368;

    p->unkA = 1;
    switch ((s16)g->unk0[arg2]) {
    case 0:
        p->unk0[3] = 0;
        break;
    case 10:
        p->unk0[3] = 2;
        break;
    case 1000:
        p->unk0[3] = 3;
        break;
    case 2000:
        p->unk0[3] = 4;
        break;
    default:
        p->unk0[3] = 1;
        break;
    }
    p->unk0[1] = 1;
    p->unkC = NULL;
    p->unk0[2] = arg6;
    memset(p->unk20, 0, 4);
    strncpy(p->unk20, arg1, 3);
    p->unk16 = arg3;
    p->unk18 = arg4;
    p->unk1A = arg5;
    p->unk14 = 0;
    p->unk1C = arg8;
    if (arg2 != 13 && (u16)(arg2 - 11) < 16 && (u32)(*(g->unk0 + arg2) - 11) < 90) {
        p->unk14 = 1;
    }
    if (arg0 == 1) {
        switch ((arg7 >> 16) & 0xFF) {
        case 0xF6:
            p->unk10 = 1;
            p->unk12 = arg7 & 0xFF;
            break;
        case 0xF9:
            p->unk10 = 2;
            p->unk12 = arg7 & 0xFF;
            break;
        default:
            p->unk10 = 0;
            p->unk12 = (s8)(arg7 >> 8);
            break;
        }
    } else {
        p->unk10 = ((arg7 & 0xFF00) >> 8) + 2;
        p->unk12 = arg7 & 0xFF;
    }
}

s16 func_8018C750(s16 a) {
    do {
        if (a < 0) a += 360;
        if (a >= 360) a -= 360;
    } while ((u16)a >= 360);
    return a;
}

s32 func_8018C790(s16 a) {
    s32 b;

loop:
    if (a < 0) a += 360;
    if (a >= 360) a -= 360;
    if ((u16)a >= 360) goto loop;
    b = a;
    if (b >= 45 && b < 135) return 0;
    if (b >= 135 && b < 225) return 6;
    if (b >= 225 && b < 315) return 4;
    return 2;
}

s32 func_8018C810(s32 a) {
    s32 i;
    s32 r;
    if (a == 1) return 0;
    if (a == 2) return 0x144;
    r = 0x144;
    for (i = 3; i <= a; i++) {
        r += 0x195 + (i - 3) * 0xA2;
    }
    return r;
}

void func_8018C864(s32 a, s32 b, s32 c) {
    s16 r[4];
    u16 buf[0x20];
    Unk_8018C864 *p;
    Unk_801891A4 *e;
    u16 *d;
    u16 *f;
    s32 i;
    s32 t;
    s32 j;
    s32 n;
    s32 x;

    p = (Unk_8018C864 *)func_801A44B8(a);
    e = func_801891A4(c);
    if (p == NULL || e == NULL) {
        return;
    }
    x = p->unk1C->unk0;
    b += p->unk1C->unk2;
    r[2] = 2;
    r[3] = 15;
    r[0] = x;
    r[1] = b;
    n = strlen((char *)e->unk4);
    for (i = 0; i < 24; i += 2) {
        d = buf;
        if (i < n) {
            f = Krom2RawAdd2((e->unk4[i] << 8) | e->unk4[i + 1]);
            for (j = 0; j < 15; j++, f++) {
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 4;
                    v = 0;
                    k = 7;
                    sh = 0;
                    do {
                        c1 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    d[0] = v;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 0;
                    v = 0;
                    k = 3;
                    sh = 0;
                    do {
                        c1 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    t = d[0];
                    t |= (u16)(v << 8);
                    d[0] = t;
                    d++;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 12;
                    v = 0;
                    k = 15;
                    sh = 0;
                    do {
                        c1 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    d[0] = v;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 8;
                    v = 0;
                    k = 11;
                    sh = 0;
                    do {
                        c1 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*f >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    t = d[0];
                    t |= (u16)(v << 8);
                    d[0] = t;
                    d++;
                }
            }
        } else {
            memset(d, 0xEE, 0x40);
        }
        LoadImage2(r, buf);
        r[0] += 2;
    }
}

void func_8018CB70(Unk_801E058C *p, s32 b) {
    s32 i;
    s16 start;
    s16 end;
    s32 j;
    u16 col;
    u16 row;

    func_801A4824(p->unkA, p->unk8, p->unk8 + p->unk18 - 1, p->unk10);
    func_801A461C(p->unkA, p->unk4, (u16)p->unk12);
    start = p->unk6;
    if (p->unk18 < p->unk1A) {
        end = start + p->unk18;
    } else {
        end = start + p->unk1A;
    }
    if ((s16)b != 0 && p->unk16 != 0) {
        for (i = start, j = 0; i < end; i++, j++) {
            if (p->unkC >= 0) {
                if (p->unk1C == NULL) {
                    col = i / p->unkE;
                    row = i % p->unkE;
                } else {
                    col = p->unk1C[i] / p->unkE;
                    row = p->unk1C[i] % p->unkE;
                }
                func_801A3F90((u16)p->unkC, col, row, p->unkA, 0x10, (u16)(j * 0x11 + 0xC));
            } else if (p->unkC == -2) {
                func_8018C864((s16)p->unkA, j * 0x11 + 0xC, p->unk1C[i]);
            }
        }
    }
}

void func_8018CD4C(Unk_801E058C *p) {
    s16 r[4];
    Unk_8018CD4C *a;
    Unk_8018CD4C *b;
    u8 *buf;
    s32 n;
    s32 i;

    a = (Unk_8018CD4C *)func_801A44B8(p->unkA);
    b = (Unk_8018CD4C *)func_801A44B8(p->unkC);
    if (a != NULL) {
        r[0] = a->unk1C->unk0;
        r[1] = a->unk1C->unk2 + 0xC;
        r[2] = 0x18;
        r[3] = 0x10;
        if (b != NULL) {
            r[0] = a->unk1C->unk0 + (0x10 >> a->unk1C->unk14);
            r[1] = a->unk1C->unk2 + 0xC;
            r[2] = b->unk10 >> b->unk1C->unk14;
            r[3] = b->unk12;
            p->unkE = b->unk16;
        }
        n = r[2] * r[3] * 2;
        buf = func_801CC898(n);
        if (buf != NULL) {
            memset(buf, 0xEE, n);
            for (i = 0; i < 6; i++) {
                LoadImage2(r, buf);
                r[1] += 0x11;
            }
            free3(buf);
        }
    }
}

s16 func_8018CEA0(s16 a) {
    s16 snd = 1;
    s32 flag = 0;
    Unk_801E058C *p = &D_801E058C;

    if (a != 0) {
        p->unk2--;
        if (p->unk14 != 0) {
            p->unk4--;
            if (p->unk2 < 0) {
                p->unk2 = p->unk1A - 1;
                p->unk4 = p->unk8 + p->unk2;
            }
        } else {
            if (p->unk2 < 0) {
                p->unk2 = 0;
            }
            p->unk4--;
            if (p->unk4 < p->unk8) {
                p->unk4 = p->unk8;
                snd = 0;
                if (p->unk6 > 0) {
                    p->unk6--;
                    flag = 1;
                    snd = 1;
                }
            }
        }
    } else {
        p->unk2++;
        if (p->unk14 != 0) {
            p->unk4++;
            if (p->unk2 >= p->unk1A) {
                p->unk2 = 0;
                p->unk4 = p->unk8;
            }
        } else {
            if (p->unk2 >= p->unk1A) {
                p->unk2 = p->unk1A - 1;
            }
            p->unk4++;
            if (p->unk4 >= p->unk8 + p->unk18) {
                p->unk4 = p->unk8 + p->unk18 - 1;
                snd = 0;
                if (p->unk6 != p->unk2 - p->unk18 + 1) {
                    p->unk6 = p->unk2 - p->unk18 + 1;
                    flag = 1;
                    snd = 1;
                }
            }
        }
    }
    if (snd) {
        func_801A2678(0xF);
    }
    func_8018CB70(p, flag);
    return p->unk2;
}

s32 func_8018D078(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i) {
    Unk_801E0368 *p = &D_801E0368;
    Unk_801E058C *q = &p->unk224;
    if (p->unk224.unk0 != 0) {
        return 0;
    }
    p->unk24C = 1;
    p->unk224.unk0 = 2;
    if (a != 0) {
        q->unk2 = 0;
        q->unk4 = g;
        q->unk6 = 0;
    }
    q->unk8 = g;
    q->unkA = b;
    q->unkC = c;
    q->unk10 = h;
    q->unk12 = i;
    q->unk14 = 1;
    if (e < d) {
        q->unk14 = 0;
    }
    q->unk16 = 1;
    if (c == -1) {
        q->unk16 = 0;
    }
    q->unk18 = e;
    q->unk1A = d;
    q->unk1C = f;
    if ((c == 0x40C || c == 0x402 || c == -2) && b == 0x40B) {
        func_8018CD4C(q);
    }
    func_8018CB70(q, 1);
    func_80185A60(0xB, b, 2);
    return 1;
}

s32 func_8018D1A0(void) {
    Unk_801E058C *p = &D_801E058C;
    if (p->unk0 != 1) {
        return 0;
    }
    p->unk0 = 2;
    func_80185A60(0xC, p->unkA, 2);
    return 1;
}

s16 func_8018D1F0(void) { return D_801E058C.unk0; }

s32 func_8018D200(u16 a, s16 *b) {
    Unk_801E058C *p = &D_801E058C;
    if (p->unk0 == 2) {
        return 0;
    }
    p->unk2 = 0;
    p->unk6 = 0;
    p->unk1C = b;
    p->unk4 = p->unk8;
    func_801A4A68(p->unkA, 0);
    func_801A4A68(a, 1);
    p->unkA = a;
    func_8018CB70(p, 0);
    return 1;
}

s16 func_8018D294(s16 i) {
    Unk_801E058C *p = &D_801E058C;
    if (i < 0 || p->unk1A < i) {
        return -1;
    }
    return p->unk1C[i];
}
