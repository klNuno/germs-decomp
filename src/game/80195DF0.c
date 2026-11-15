#include "common.h"

typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; } Unk_80192E18;
typedef struct { s32 unk0; s32 unk4; Unk_80192E18 *unk8; void *unkC; } Unk_80192F20;
void free3(void *ptr);
typedef struct { s32 unk0; u16 unk4; s16 unk6; s32 unk8; s32 unkC; } Unk_801E0600;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0x26];
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    u16 unk42;
    u8 unk44[2];
    u16 unk46;
    s16 unk48;
    u8 unk4A[0xA];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0xC];
    s16 unk6C;
    s16 unk6E;
    s16 unk70;
    s16 unk72;
    s16 unk74;
    s16 unk76;
    s16 unk78;
    u8 pad7A[0x2];
    u8 unk7C[0x14];
    s32 unk90[3];
    s32 unk9C;
    u8 unkA0[0x50];
} Unk_801E0620;
s32 D_801DFF48;
extern Unk_801E0600 D_801E0600;
extern Unk_801E0600 D_801E0610;
extern Unk_801E0620 D_801E0620;
s16 func_80189054(s16 arg0, s16 arg1);
s16 func_801890C4(s16 arg0, s16 arg1);
void func_801875E4(s16 arg0);
s16 func_80188C24(s16 arg0, s16 arg1);
typedef struct { u8 unk0[0x16]; u16 unk16; } Unk_8018E56C;
typedef struct Unk_801E076C {
    u8 unk0[0x40];
    u16 unk40;
    u16 unk42;
    u8 unk44[0x10];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0xC];
    s16 unk6C;
    s16 unk6E;
    u8 unk70[8];
    s16 unk78;
} Unk_801E076C;
typedef struct { s16 unk0; s16 unk2; s16 unk4[2]; u8 unk8[0x28]; s16 unk30; s16 unk32[8]; s16 unk42; s16 unk44; s16 unk46; s16 unk48; u8 unk4A[2]; s32 unk4C; } Unk_801E0770;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; u8 unkA; u8 unkB; s16 unkC; u8 unkE; u8 unkF; s16 unk10; u16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s16 unk38; s16 unk3A; s16 unk3C; s16 unk3E; u16 unk40; s16 unk42; u8 unk44; u8 unk45; s16 unk46; s32 unk48; } Unk_801762F4;
typedef struct Unk_801E0710 {
    s16 unk0;
    s16 unk2;
    u8 unk4[4];
    s32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[2];
    s16 unk18;
    u8 unk1A[2];
    s16 unk1C;
    u8 unk1E[2];
    s16 unk20;
    u8 unk22[2];
    s16 unk24;
    u8 unk26[2];
    s16 unk28;
    u8 unk2A[2];
    s16 unk2C;
    u8 unk2E[6];
    s16 unk34;
    s16 unk36;
    u8 unk38[2];
    s16 unk3A[5];
    s16 unk44;
    s16 unk46;
    s16 unk48;
    s16 unk4A;
    Unk_801762F4 *unk4C;
    Unk_8018E56C *unk50;
    u8 unk54[4];
    Unk_801E0770 *unk58;
    Unk_801E076C *unk5C;
} Unk_801E0710;
extern Unk_801E0710 D_801E0710;
void func_8018A7C0(Unk_801E0710 *arg0);
typedef struct {
    s16 unk0[0x14];
    s16 unk28[0x1C];
    s16 unk60;
    s16 unk62[0xB];
    s16 unk78;
    u8 unk7A[2];
    s16 unk7C;
    u16 unk7E;
    u8 unk80[0x34];
    s16 unkB4[5];
    u8 padBE[0x22];
    u8 unkE0[0x16C];
    s16 unk24C;
} Unk_801E0368;
extern Unk_801E0368 D_801E0368;
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; } Unk_80192F60;
typedef struct { s16 unk0; s16 unk2; s16 unk4; } Unk_801DFF30;
Unk_801DFF30 D_801DFF30;
void func_80183E88(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
typedef struct { s16 unk0; s16 unk2; s16 unk4; } Unk_801DFF28;
Unk_801DFF28 D_801DFF28;
u16 D_801DFD58;
u16 D_801DFD5A;
extern char D_80170E18[];
void func_801A4A68(s32 arg0, s32 arg1);
void func_801A461C(s32 arg0, s32 arg1, s32 arg2);
void func_80184094(void);
void func_8018C1B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern Unk_801E076C *D_801E076C[];
Unk_8018E56C *func_8018E56C(u16 arg0);
void func_8018DA2C(void *arg0, s16 arg1, s16 arg2);
void func_80194F08(s16 arg0);
void func_801A25B4(s32 arg0);
void func_80186414(s32 arg0, s32 arg1, s32 arg2);
void func_80199C68(s16 arg0);
s16 D_801DFF38;
void func_80194780(void);
void func_80182300(void);
void func_801808F0(s32 arg0, s32 arg1);
void func_8018C414(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 unk10[2];
    u16 unk12;
} Unk_801DFFE8;
extern Unk_801DFFE8 D_801DFFE8;
typedef struct { void *unk0; s32 unk4; void *unk8; } Unk_80174B10;
extern void *D_801E0760[];
Unk_80174B10 *func_80174CB8(s16 arg0);
Unk_80174B10 *func_80173DE0(Unk_80174B10 *arg0, s32 arg1, s32 arg2);
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; } Unk_801CC1E8;
s16 D_801DFF4C;
void UnDeliverEvent(u32 ev, u32 spec);
Unk_801CC1E8 *func_801CC1E8(s32 arg0);
extern s16 D_801DFD64[];
void func_80189DE8(Unk_801E0710 *arg0);
void func_8018A968(s16 arg0, s16 arg1);
typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4[0x10];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 unk20[0x1C];
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
} Unk_8019A07C_3C;
typedef struct {
    u8 unk0[0x3C];
    Unk_8019A07C_3C *unk3C;
} Unk_8019A07C;
void func_80197688(void);
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    u8 unk38[4];
    Unk_801762F4 *unk3C;
    u8 unk40[0x1C];
    void *unk5C[1];
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
s16 D_801DFF18;
s32 D_801DFF1C;
extern u8 D_801DFF20[];
s32 CdPosToInt(void *p);
void *CdIntToPos(s32 i, void *p);
s32 CdControl(u8 com, u8 *param, u8 *result);
void func_801A2678(s32 arg0);
void func_8019555C(Unk_801E076C *arg0, s16 arg1);
void func_8018ABE8(s16 a, s16 b);
typedef struct { s32 unk0; u8 *unk4; u8 *unk8; s32 unkC; s32 unk10; s16 unk14; } Unk_801A3970;
extern Unk_801A3970 D_801E05C0;
s32 CdMode(void);
void *CdLastPos(void);
s32 CdRead(s32 sectors, u32 *buf, s32 mode);
s32 CdReadSync(s32 mode, u8 *result);
s32 VSync(s32 mode);
u32 *func_801A37E4(u8 *arg0, s32 arg1, Unk_801A3970 *arg2);
void func_801A3970(Unk_801A3970 *arg0);
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
s32 func_801CD6B4(void);
s16 func_80193880(void);
s16 func_8018898C(Unk_801E0710 *arg0, s32 arg1);
void func_80193DA8(Unk_801E0710 *arg0);
void func_80198CFC(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
void func_80199548(Unk_801E0710 *arg0, s32 arg1, s32 arg2);
s16 D_801DFD54;
extern s32 D_801DFF50;
extern s32 D_801DFED8;
extern s32 D_801DFEE4;
extern s32 D_801DFED4;
extern s32 D_801DFEE8;
void func_80174840(s16 arg0);
void func_80174BC8(void);
void func_80174FA8(void);
void func_80176780(void);
void func_8017D1BC(void);
void func_80185548(void);
void func_801863B4(void);
void func_8018E47C(void);
void func_80199E1C(s16 arg0, s16 arg1);
void func_801A23B4(void);
void func_801A252C(void);
void func_801A3B5C(void);
void func_801A3C58(void);
void func_801A43F4(s32 arg0);
void func_801A7BA4(void);
extern Unk_801E0770 D_801E0770;
void *memset(void *dst, s32 c, u32 n);
void RotMatrix(s16 *arg0, void *arg1);
void ApplyMatrixLV(void *arg0, void *arg1, void *arg2);
void func_801B25D0(void *arg0);
void GsInitCoordinate2(void *super, void *base);
typedef struct { s16 unk0[5]; s16 unkA; char *unkC; s16 unk10; s16 unk12; s32 unk14; s32 unk18; s32 unk1C; } Unk_801E0340;
extern Unk_801E0340 D_801E0340;
extern s32 D_801DFD60[];
void func_8018C554(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
extern s16 D_801DFC76;
void func_801A0690(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s16 D_801E1046[];
u16 func_8019A6A4(void);
s16 func_80179630(Unk_801762F4 *arg0, s32 arg1, s16 arg2);
extern char D_80170EDC[];
extern char D_80170EFC[];
extern char D_80170F14[];
s32 func_80199FA0(void);

INCLUDE_RODATA("asm/nonmatchings/game/80195DF0", D_80170EDC);

INCLUDE_RODATA("asm/nonmatchings/game/80195DF0", D_80170EFC);

INCLUDE_RODATA("asm/nonmatchings/game/80195DF0", D_80170F14);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80195DF0);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80196048);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80196454);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_801966B4);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80196AE0);

void func_801971D4(void) {
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E0770 *q = &D_801E0770;
    Unk_801E0620 *r = &D_801E0620;
    Unk_801E0368 *o;
    s16 sv[3];
    s32 i;

    memset(p, 0, 0x60);
    p->unk0 = 0xC9;
    p->unk2 = 1;
    p->unk8 = 0x144;
    p->unk36 = 2;
    p->unkC = 1;
    p->unkE = 1;
    p->unk10 = 1;
    p->unk12 = 1;
    p->unk14 = 1;
    p->unk18 = 1;
    p->unk1C = 1;
    p->unk20 = 1;
    p->unk24 = 1;
    p->unk28 = 1;
    p->unk44 = 1;
    p->unk46 = 1;
    p->unk48 = 1;
    p->unk4A = 0;
    o = &D_801E0368;
    memset(q, 0, 0x50);
    for (i = 0; i < 8; i++) {
        q->unk32[i] = -1;
    }
    o->unk78 = 1;
    q->unk4[1] = -1;
    q->unk42 = 0xF;
    memset(r, 0, 0xF0);
    r->unk0 = 0x5C30;
    r->unk8 = -0x1004;
    r->unk4 = 0;
    r->unk10 = 0;
    r->unk12 = 0xB4;
    r->unk14 = 0;
    r->unk3E = 1;
    r->unk40 = 1;
    r->unk48 = -1;
    sv[0] = 0;
    sv[1] = 0;
    sv[2] = 0;
    RotMatrix(sv, r->unk7C);
    ApplyMatrixLV(r->unk7C, r->unk90, r->unk90);
    r->unk9C = 0;
    func_801B25D0(r->unk7C);
    GsInitCoordinate2(NULL, r->unkA0);
    p->unk58 = q;
    p->unk5C = (Unk_801E076C *)r;
}

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80197370);

void func_80197688(void) {
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E0340 *q = &D_801E0340;
    Unk_801E0368 *o = &D_801E0368;
    s32 i;
    s16 v;

    if (o->unk60 == 0 && p->unk4A != 0) {
        p->unk0 = 0xFF;
        p->unk36 = 0;
        p->unk34 = 0;
        if (p->unk2C == 0) {
            p->unk2C = 1;
            o->unk0[6] = 1;
            o->unk62[0] = p->unk2;
            o->unk62[1] = p->unkC;
            o->unk62[2] = p->unkE;
            o->unk62[3] = p->unk10;
            o->unk62[4] = p->unk12;
            o->unk62[5] = p->unk14;
            o->unk62[6] = p->unk18;
            o->unk62[7] = p->unk1C;
            o->unk62[8] = p->unk20;
            o->unk62[9] = p->unk24;
            o->unk62[10] = p->unk28;
            for (i = 9; i < 0x1C; i++) {
                v = o->unk0[i];
                o->unk0[i] = 2000;
                o->unk28[i] = v;
            }
        }
        p->unk2 = 100;
        p->unkC = 100;
        p->unkE = 100;
        p->unk10 = 100;
        p->unk12 = 100;
        p->unk14 = 100;
        p->unk18 = 100;
        p->unk1C = 100;
        p->unk20 = 100;
        p->unk24 = 100;
        p->unk28 = 100;
        for (i = 0; i < 5; i++) {
            p->unk3A[i] = 0;
            o->unkB4[i] = 0;
        }
        func_8018C554(1, D_801DFD60, 0x18, 0x41, 7, 0xB4, 0x15, 0x500F07, 1);
        func_8018A7C0(p);
        func_80189DE8(p);
    } else {
        q->unk0[4] = 1;
        q->unkA = 1;
    }
}

void func_80197838(u16 arg0, Unk_801E0710 *arg1, Unk_801E0620 *arg2) {
    Unk_801E0368 *o = &D_801E0368;
    s32 v;

    if (D_801E1046[0] == 0 && o->unk24C == 0 && func_8019A6A4() == 0
        && arg2->unk46 != 1 && !(arg2->unk42 & 0x8000) && !(arg2->unk42 & 0x4802)) {
        arg2->unk42 |= 0x800;
        if (arg2->unk46 != 0) {
            func_80197688();
            return;
        }
        v = 0x514;
        if (arg0 == 2) {
            v = 0x82;
        }
        func_80198CFC(0, 0, arg2->unk54 + arg2->unk72 * 0x30D4,
                      arg2->unk58 - arg2->unk74 * 0x7D00 - arg2->unk78 + v,
                      arg2->unk5C + arg2->unk76 * 0x30D4, -0x4B, arg2->unk6E, arg2->unk70, 4);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_801979B4);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80197BB0);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80197D64);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80197F34);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_801981D0);

void func_801985AC(void) {
    Unk_801E02D8 *g = &D_801E02D8;
    Unk_801762F4 *e = g->unk3C;
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E0770 *q;
    s16 v;
    s32 i;

    p->unk4C = NULL;
    q = p->unk58;
    if (g->unk1C != 0) {
        v = q->unk4[q->unk2];
        for (i = 0; i < g->unk1C; i++, e++) {
            if (e->unk4 != 0 && e->unk6 != 0 && e->unkE != 2 && !(e->unk12 & 0x200) && (e->unk12 & 2)
                && e->unk40 != 0 && func_80179630(e, 0, v) != 0) {
                if (p->unk4C == NULL || e->unk40 < p->unk4C->unk40) {
                    p->unk4C = e;
                }
            }
        }
        if (p->unk4C != NULL) {
            return;
        }
    }
    if (q->unk46 == 0) {
        q->unk46 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80198720);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80198ADC);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80198CFC);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80199034);

void func_80199370(s32 arg0, s32 arg1, s32 arg2, s16 arg3) {
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E0368 *o = &D_801E0368;
    Unk_801E076C *e = p->unk5C;
    s16 r;
    s32 i;

    if (p->unk2C != 0 && arg3 != 0) {
        p->unk2C = 0;
        o->unk0[6] = 0;
        p->unk2 = o->unk62[0];
        p->unkC = o->unk62[1];
        p->unkE = o->unk62[2];
        p->unk10 = o->unk62[3];
        p->unk12 = o->unk62[4];
        p->unk14 = o->unk62[5];
        p->unk18 = o->unk62[6];
        p->unk1C = o->unk62[7];
        p->unk20 = o->unk62[8];
        p->unk24 = o->unk62[9];
        p->unk28 = o->unk62[10];
        for (i = 9; i < 0x1C; i++) {
            o->unk0[i] = o->unk28[i];
        }
        func_801A461C(0x400, 0x45, 0);
        /* " ミュータント状態から回復した" */
        func_80183E88(D_80170EDC, 1, -1, 0, -1, 0, 0);
    } else {
        r = func_80199FA0();
        if (r == 0 && arg3 == 0) {
            /* " 全身がとても軽くなった" */
            func_80183E88(D_80170EFC, 1, -1, 0, -1, 0, 0);
        } else {
            /* " 傷が完全に回復した" */
            func_80183E88(D_80170F14, 1, -1, 0, -1, 0, 0);
        }
    }
    for (i = 0; i < 5; i++) {
        p->unk3A[i] = 0;
        o->unkB4[i] = 0;
    }
    if (arg3 == 0) {
        func_8018ABE8(0x3C, 1);
    }
    func_8018A7C0(p);
    func_80189DE8(p);
    e->unk54 = arg0;
    e->unk5C = arg2;
    e->unk58 = arg1 + e->unk78;
    func_8019555C(e, 1);
}

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_80199548);

void func_80199A94(s16 arg0, s16 arg1) {
    if (arg1 != 0) {
        D_801DFC76 = 1;
        switch (arg0) {
        case 0:
        case 2:
            func_801A2678(0x23);
            break;
        case 1:
            func_801A2678(0x29);
            break;
        case 3:
        case 4:
            func_801A2678(0x2A);
            break;
        case 6:
        case 12:
            func_801A2678(0x24);
            break;
        case 5:
            func_801A2678(0x25);
            break;
        case 7:
            func_801A2678(0x2B);
            break;
        case 8:
            func_801A2678(0x2C);
            break;
        case 9:
        case 11:
            func_801A2678(0x26);
            break;
        case 10:
            func_801A2678(0x2D);
            break;
        case 14:
            func_801A0690(0xFF, 0xFF, 0xFF, 1);
            func_801A2678(0x27);
            break;
        case 13:
            func_801A0690(0xFF, 0xC0, 0, 1);
        case 15:
            func_801A2678(0x2E);
            break;
        case 16:
            func_801A0690(0x60, 0xFF, 0xFF, 1);
            func_801A2678(0x30);
            break;
        case 17:
            func_801A0690(0xFF, 0x60, 0xFF, 1);
            func_801A2678(0x2F);
            break;
        }
    } else {
        switch (arg0) {
        case 14:
            func_801A25B4(0x27);
            break;
        case 13:
        case 15:
            func_801A25B4(0x2E);
            break;
        case 17:
            func_801A25B4(0x2F);
            break;
        case 16:
            func_801A25B4(0x30);
            break;
        }
    }
}

void func_80199C68(s16 arg0) {
    D_801DFF48 = 0xFFFFFF;
    D_801E0610.unk4 = 0;
    D_801E0600.unk4 = 0;
    D_801E0610.unk0 = 0xFFFFFF;
    D_801E0600.unk0 = 0xFFFFFF;
    D_801E0610.unk8 = 0;
    D_801E0600.unk8 = 0;
    D_801E0620.unk3E = arg0;
    D_801E0620.unk3C = 1;
    D_801E0620.unk42 &= ~4;
}

s32 func_80199CC0(s16 arg0, s16 arg1, s16 arg2) {
    s32 ret;

    if (arg2 == 0) {
        ret = func_801890C4(arg0, arg1);
    } else {
        ret = func_80189054(arg0, arg1);
    }
    return ret;
}

s32 func_80199D18(s16 arg0, s16 arg1, s16 arg2) {
    s32 ret;

    if (arg1 == 0) {
        func_801875E4(arg0);
        ret = 1;
    } else {
        ret = func_80188C24(arg0, arg2);
    }
    return ret;
}

void func_80199D68(s16 arg0, s16 arg1, s16 arg2) {
    Unk_801E0368 *p = &D_801E0368;
    Unk_801E0710 *q = &D_801E0710;
    s16 v = p->unkB4[arg0];

    v -= arg2;
    if (arg2 < 0) {
        s16 *m = &D_801DFD64[arg1];

        if (v > *m) {
            v = *m;
        }
    } else if (v < 0) {
        v = 0;
    }
    *(p->unkB4 + arg0) = v;
    func_80189DE8(q);
    func_8018A968(2, 1);
}

void func_80199E1C(s16 arg0, s16 arg1) {
    Unk_801E0710 *p = &D_801E0710;
    s16 v;

    if (arg0 < 0) {
        p->unk4A = 0;
    }
    v = p->unk0 + arg0;
    p->unk0 = v;
    if (v >= 0x100) {
        p->unk0 = 0xFF;
    } else if (v < 0) {
        p->unk0 = 0;
        if (arg1 != 0) {
            p->unk0 = arg1;
        }
    } else if (v > 0 && v < 0xFF) {
        if (v < arg1) {
            p->unk0 = arg1;
        }
    }
    func_8018A7C0(p);
}

void func_80199EB4(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E076C *o = p->unk5C;
    Unk_801E0368 *q = &D_801E0368;
    s16 v;

    if (arg0 == 0) {
        v = 0x3C;
        p->unk36 -= 4;
        if (p->unk36 < 0) {
            p->unk36 = 0;
        }
    } else {
        v = 0x1A4;
        p->unk36 = 0;
        if (q->unk7C > 0x14) {
            v = (0x17 - q->unk7C) * 0x3C - (q->unk7E - 0x21C);
        } else if (q->unk7C < 3) {
            v = 0x1E0 - q->unk7E - q->unk7C * 0x3C;
        }
    }
    o->unk54 = arg1;
    o->unk5C = arg3;
    o->unk58 = arg2 + o->unk78;
    func_8019555C(o, 1);
    func_8018ABE8(v, 1);
}

s32 func_80199FA0(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_801E0368.unkB4[i] > 0) {
            return 1;
        }
    }
    return 0;
}

s32 func_80199FD8(void) {
    Unk_801E0620 *p = &D_801E0620;
    Unk_801CC1E8 *o;

    UnDeliverEvent(0xF3000001, 2);
    o = func_801CC1E8(0x20);
    if (o != NULL) {
        o->unkC = D_801E0600.unk0;
        o->unk8 = D_801E0600.unk4;
        o->unk10 = D_801E0600.unk8;
    }
    D_801E0610.unk4 = D_801E0600.unk4;
    D_801E0610.unk0 = D_801E0600.unk0;
    D_801E0610.unk8 = D_801E0600.unk8;
    p->unk42 &= ~4;
    return 0;
}

void func_8019A07C(Unk_8019A07C *arg0) {
    Unk_8019A07C_3C *e = arg0->unk3C;
    Unk_801E0620 *p = &D_801E0620;
    Unk_801DFFE8 *s = &D_801DFFE8;

    p->unk54 = e->unk14;
    p->unk58 = e->unk18;
    p->unk5C = e->unk1C;
    p->unk6C = e->unk3C;
    p->unk6E = e->unk3E;
    p->unk70 = e->unk40;
    p->unk42 &= ~2;
    p->unk3C = 1;
    switch (e->unk0) {
    case 0:
        p->unk42 |= e->unk2;
        break;
    case 1:
        p->unk42 &= e->unk2;
        break;
    case 2:
        p->unk42 &= ~e->unk2;
        break;
    }
    if (s->unk12 & 0x20) {
        s->unk12 &= ~0x20;
        if (s->unk12 == 0) {
            s->unk6 = 1;
        }
    }
    p->unk48 = -1;
    if (p->unk42 & 0x800) {
        func_80197688();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_8019A1A4);

INCLUDE_ASM("asm/nonmatchings/game/80195DF0", func_8019A3E8);
