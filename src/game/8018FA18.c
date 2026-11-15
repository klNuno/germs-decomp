#include "common.h"

typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; } Unk_80192E18;
typedef struct { s32 unk0; s32 unk4; Unk_80192E18 *unk8; void *unkC; } Unk_80192F20;
void free3(void *ptr);
typedef struct { s32 unk0; u16 unk4; s16 unk6; s32 unk8; s32 unkC; } Unk_801E0600;
typedef struct {
    s32 unk0;
    s16 unk4[10];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 unk24[0x2C];
} Unk_801E0620_A0;
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
    s16 unk44;
    u16 unk46;
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    u8 unk52[2];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
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
    Unk_801E0620_A0 unkA0[1];
} Unk_801E0620;
s32 D_801DFF48;
extern Unk_801E0600 D_801E0600;
extern Unk_801E0600 D_801E0610;
extern Unk_801E0620 D_801E0620;
s16 func_80189054(s16 arg0, s16 arg1);
s16 func_801890C4(s16 arg0, s16 arg1);
void func_801875E4(s16 arg0);
s16 func_80188C24(s16 arg0, s16 arg1);
typedef struct {
    u8 unk0[0x16];
    u16 unk16;
    u8 unk18[0x24];
    s32 unk3C;
    u8 unk40[0x14];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 pad60[0x30];
    s16 *unk90;
} Unk_8018E56C;
typedef struct {
    u8 unk0[0x3C];
    s16 unk3C;
    u8 unk3E[2];
    u16 unk40;
    u16 unk42;
    u8 unk44[0x10];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0xC];
    s16 unk6C;
    s16 unk6E;
    u8 unk70[2];
    s16 unk72;
    u8 unk74[2];
    s16 unk76;
    s16 unk78;
} Unk_801E076C;
typedef struct {
    s16 unk0;
    u8 unk2[0x32];
    s16 unk34;
    s16 unk36;
    u8 unk38[2];
    s16 unk3A[5];
    u8 unk44[6];
    s16 unk4A;
    u8 unk4C[4];
    Unk_8018E56C *unk50;
    u8 unk54[8];
    Unk_801E076C *unk5C;
} Unk_801E0710;
extern Unk_801E0710 D_801E0710;
void func_8018A7C0(Unk_801E0710 *arg0);
typedef struct {
    s16 unk0[0x3D];
    s16 unk7A;
    s16 unk7C;
    u16 unk7E;
    u8 unk80[0x34];
    s16 unkB4[5];
    u8 unkBE[0x186];
    s32 unk244;
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
    s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14;
    s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28;
    s32 unk2C; s32 unk30; s32 unk34;
    u8 unk38[0x24];
    void *unk5C[1];
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
s16 D_801DFF18;
s32 D_801DFF1C;
extern u8 D_801DFF20[4];
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
typedef struct { u8 unk0[0x7F8]; } Unk_8018FA18;
void *func_801CC898(u32 size);
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
void *func_80173A44(void *arg0);
extern char D_80170B7C[];
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
void func_8017CB98(Unk_8017CCE4 **arg0, s32 arg1);
void func_80179848(Unk_8017CCE4 *arg0, u16 arg1);
void func_8017D170(s32 arg0);
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
void func_80185380(Unk_801854B8 **arg0, u32 arg1);
void func_801844D4(Unk_8017CCE4 *arg0);
void func_801854FC(void *arg0);
void func_8018ACAC(s32 *arg0, void *arg1, s16 arg2);
extern s32 D_801E0324[];
typedef struct { s16 unk0; s16 unk2; s32 unk4; void *unk8; } Unk_801A3B5C;
void func_801A3AA0(Unk_801A3B5C **arg0, u32 arg1);
void func_801A33E8(Unk_801A3B5C *arg0);
void func_8018E03C(Unk_8018E56C **arg0, u32 arg1);
void func_8018E2F8(s32 arg0);
typedef struct {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    u16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s32 unk1C;
} Unk_801A4370;
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u8 unkA[0x2];
    u16 unkC;
    u16 unkE;
    u8 unk10[0x2];
    s16 unk12;
    u8 unk14[0x4];
} Unk_801A3DD4;
void func_801A3DD4(Unk_801A4370 **arg0, Unk_801A3DD4 *arg1);
void func_801A43A8(s32 arg0);
void func_801CFBB4(void *arg0);
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
    u8 unk24[0x8];
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
void func_801A7A04(Unk_801A7AFC **arg0, u32 arg1);
void func_801A6C34(Unk_801A7AFC *arg0);
void func_801A7B58(s32 arg0);
typedef struct { u8 unk0[0x7F4]; } Unk_8019120C;
void func_801CFB4C(u32 *arg0, s16 arg1);
extern u8 *D_801E05C8[];
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    u16 unk14;
    u16 unk16;
    u16 unk18;
    u16 unk1A;
} Unk_801A217C;
void func_801A39F0(Unk_801A3970 *arg0);
void func_801A217C(Unk_801A217C *arg0);
typedef struct { u16 unk0; u8 pad2[0xB6]; void *unkB8; void *unkBC; void *unkC0; } Unk_801AC278;
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; } Unk_801E032C;
void func_801AC158(Unk_801AC278 **arg0, u32 arg1);
void func_801AC214(Unk_801E032C *arg0);
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; } Unk_80193068;
void func_80194A2C(s16 arg0, char *arg1);
void func_80186128(s32 arg0, s32 arg1);
void func_801D1BAC(u8 arg0, u8 arg1, u8 arg2);
void func_80199EB4(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_801A3BCC(s16 arg0);
s16 D_801DFD56;
extern u16 D_801E0356[];
typedef struct { s16 unk0[5]; s16 unkA; char *unkC; s16 unk10; s16 unk12; s32 unk14; s32 unk18; s32 unk1C; } Unk_801E0340;
extern Unk_801E0340 D_801E0340;
s32 func_80192F60(Unk_80192F60 *arg0);
s32 func_80193068(Unk_80193068 *arg0);
void func_80194B50(s32 *arg0);
void func_80194C24(Unk_80192F60 *arg0);
void func_80194D4C(Unk_80192F60 *arg0);
void func_80197370(s32 arg0);
void func_801926B4(void);
void func_8018F428(s32 arg0, s32 arg1);
void func_801A8000(s32 arg0, s32 arg1, s32 arg2);
void func_801A80CC(s32 arg0, s32 arg1, s32 arg2);
void func_801A8198(s32 arg0, s32 arg1, s32 arg2);
void func_80187978(s32 arg0);
void func_8018D2DC(Unk_8018E56C *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8018AABC(s32 arg0);
void func_80194140(void);
void func_801945E0(void);
void func_8019430C(void);
void func_801D06B4(void);
void func_801D06C4(void);
void func_80186258(void);
void func_80183CFC(s32 arg0);
s32 func_801CC378(s32 *arg0);
void func_80189928(s32 *arg0);
void func_80189350(s32 *arg0);
void func_801895E0(s32 *arg0);
void func_80189970(s16 arg0);
void func_801899AC(s32 *arg0);
s16 func_8018970C(s32 *arg0);
void func_801CC734(s32 *arg0);
s32 func_8018C170(void);
void func_80184434(s16 arg0);
void func_801932F8(void);
s32 rand(void);
void func_8018C2FC(u16 a, s16 b, s16 c);
void func_80176654(s32 arg0, s32 arg1, s32 arg2);
void func_8017CF10(s32 arg0, s32 arg1, s32 arg2);
void func_80185794(s32 arg0, s32 arg1, s32 arg2);
void func_8018F5E8(s32 arg0, s32 arg1, s32 arg2);
void func_801A7E10(s32 arg0, s32 arg1, s32 arg2);
void func_801AC464(s32 arg0, s32 arg1, s32 arg2);
void MatrixNormal(void *m, void *n);
void RotMatrix(s16 *r, void *m);
void ApplyMatrixLV(void *arg0, void *arg1, void *arg2);
void func_801B25D0(void *arg0);
void RotMatrixZYX(s16 *r, void *m);
void func_80192380(Unk_80192F20 **arg0, s32 arg1, s32 arg2);
void func_80191AB0(Unk_80192F20 *arg0, s32 arg1, s32 arg2, s16 arg3);

void func_8018FA18(Unk_80192F20 *arg0, s32 arg1) {
    u8 sp10;
    void *buf;
    void *o;
    s32 n;
    s32 i;
    u8 *p;
    u32 *dst;

    buf = func_801CC898(arg1);
    if (buf == NULL) {
        func_801CD54C(3, "Error Allocating IFF_ID_ASET Buffer", D_80170B7C, 0x8D);
    }
    *(Unk_8018FA18 *)buf = *(Unk_8018FA18 *)((u8 *)arg0->unkC + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = arg1 - 0x7F8;
    retry:
        sp10 = CdMode();
        if (!(sp10 & 0x80)) {
            sp10 = 0x80;
            while (CdControl(0xE, &sp10, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(n >> 11, dst, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) == -1) {
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
            goto retry;
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += arg1 - 0x7F8;
    }
    o = buf;
    for (i = 0; i < D_801DFF1C; i++) {
        o = func_80173A44(o);
    }
    free3(buf);
}

void func_8018FC90(Unk_80192F20 *arg0, u16 arg1, s32 arg2) {
    Unk_8017CCE4 *o;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    o = NULL;
    func_8017CB98(&o, arg2);
    *(Unk_8018FA18 *)o->unk8C = *(Unk_8018FA18 *)((u8 *)arg0->unkC + 8);
    if (arg2 > 0x7F8) {
        dst = (u32 *)((u8 *)o->unk8C + 0x7F8);
        n = arg2 - 0x7F8;
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += arg2 - 0x7F8;
    }
    func_80179848(o, arg1);
    func_8017D170((s32)o);
}

void func_8018FED4(Unk_80192F20 *arg0, s32 arg1) {
    Unk_801854B8 *o;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    o = NULL;
    func_80185380(&o, arg1);
    *(Unk_8018FA18 *)o->unk7C = *(Unk_8018FA18 *)((u8 *)arg0->unkC + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)o->unk7C + 0x7F8);
        n = arg1 - 0x7F8;
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += arg1 - 0x7F8;
    }
    func_801844D4((Unk_8017CCE4 *)o);
    func_801854FC(o);
}

INCLUDE_RODATA("asm/nonmatchings/game/8018FA18", D_80170B7C);

void func_80190108(Unk_80192F20 *arg0, s32 arg1, s32 arg2) {
    u8 sp10;
    s32 sp14;
    void *buf;
    s32 n;
    u8 *p;
    u32 *dst;

    buf = func_801CC898(arg1);
    if (buf == NULL) {
        func_801CD54C(3, "Error Allocating IFF_ID_MAIL Buffer", D_80170B7C, 0xC6);
    }
    *(Unk_8018FA18 *)buf = *(Unk_8018FA18 *)((u8 *)arg0->unkC + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = arg1 - 0x7F8;
    retry:
        sp10 = CdMode();
        if (!(sp10 & 0x80)) {
            sp10 = 0x80;
            while (CdControl(0xE, &sp10, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(n >> 11, dst, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) == -1) {
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
            goto retry;
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += arg1 - 0x7F8;
    }
    func_8018ACAC(&sp14, buf, arg2);
    free3(buf);
    D_801E0324[0] = sp14;
}

void func_80190378(Unk_80192F20 *arg0, s32 arg1) {
    Unk_801A3B5C *o;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    o = NULL;
    func_801A3AA0(&o, arg1);
    *(Unk_8018FA18 *)o->unk8 = *(Unk_8018FA18 *)((u8 *)arg0->unkC + 8);
    if (arg1 > 0x7F8) {
        n = arg1 - 0x7F8;
        dst = (u32 *)((u8 *)o->unk8 + 0x7F8);
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += arg1 - 0x7F8;
    }
    func_801A33E8(o);
}

void func_801905A0(Unk_80192F20 *arg0, s32 arg1) {
    Unk_8018E56C *o;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    o = NULL;
    func_8018E03C(&o, arg1);
    *(Unk_8018FA18 *)o->unk90 = *(Unk_8018FA18 *)((u8 *)arg0->unkC + 8);
    if (arg1 > 0x7F8) {
        n = arg1 - 0x7F8;
        dst = (u32 *)((u8 *)o->unk90 + 0x7F8);
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += arg1 - 0x7F8;
    }
    func_8018E2F8((s32)o);
}

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_801907C8);

void func_80190B2C(Unk_80192F20 *arg0, s32 arg1) {
    Unk_801A4370 *o;
    u8 sp10;
    Unk_801A3DD4 *buf;
    s32 n;
    u32 *dst;
    u8 *p;

    o = NULL;
    buf = func_801CC898(arg1);
    if (buf == NULL) {
        func_801CD54C(3, "Error Allocating IFF_ID_SPRT Buffer", D_80170B7C, 0x12B);
    }
    *(Unk_8018FA18 *)buf = *(Unk_8018FA18 *)((u8 *)arg0->unkC + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = arg1 - 0x7F8;
    retry:
            sp10 = CdMode();
            if (!(sp10 & 0x80)) {
                sp10 = 0x80;
                while (CdControl(0xE, &sp10, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) == -1) {
                p = CdLastPos();
                while (CdControl(2, p, NULL) == 0) {
                }
                goto retry;
            }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += arg1 - 0x7F8;
    }
    func_801A3DD4(&o, buf);
    func_801A43A8((s32)o);
    free3(buf);
}

void func_80190D8C(Unk_80192F20 *arg0, s32 arg1) {
    u8 sp10;
    void *buf;
    s32 n;
    u32 *dst;
    u8 *p;

    buf = func_801CC898(arg1);
    if (buf == NULL) {
        func_801CD54C(3, "Error Allocating IFF_ID_TEXT Buffer", D_80170B7C, 0x140);
    }
    *(Unk_8018FA18 *)buf = *(Unk_8018FA18 *)((u8 *)arg0->unkC + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = arg1 - 0x7F8;
    retry:
            sp10 = CdMode();
            if (!(sp10 & 0x80)) {
                sp10 = 0x80;
                while (CdControl(0xE, &sp10, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) == -1) {
                p = CdLastPos();
                while (CdControl(2, p, NULL) == 0) {
                }
                goto retry;
            }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += arg1 - 0x7F8;
    }
    func_801CFBB4(buf);
    free3(buf);
}

void func_80190FD8(Unk_80192F20 *arg0, s32 arg1) {
    Unk_801A7AFC *sp10;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    sp10 = NULL;
    func_801A7A04(&sp10, arg1);
    *(Unk_8018FA18 *)sp10->unk84 = *(Unk_8018FA18 *)((u8 *)arg0->unkC + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)sp10->unk84 + 0x7F8);
        n = arg1 - 0x7F8;
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += arg1 - 0x7F8;
    }
    func_801A6C34(sp10);
    func_801A7B58((s32)sp10);
}

void func_8019120C(Unk_80192F20 *arg0, s32 arg1) {
    u8 sp10;
    void *buf;
    s32 n;
    u32 *dst;
    u8 *p;

    buf = func_801CC898(arg1);
    if (buf == NULL) {
        func_801CD54C(3, "Error Allocating IFF_ID_TIM Buffer", D_80170B7C, 0x165);
    }
    *(Unk_8019120C *)buf = *(Unk_8019120C *)((u8 *)arg0->unkC + 0xC);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F4);
        n = arg1 - 0x7F8;
    retry:
        sp10 = CdMode();
        if (!(sp10 & 0x80)) {
            sp10 = 0x80;
            while (CdControl(0xE, &sp10, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(n >> 11, dst, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) == -1) {
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
            goto retry;
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += arg1 - 0x7F8;
    }
    func_801CFB4C(buf, 0);
    free3(buf);
}

void func_80191450(Unk_80192F20 *arg0, s32 arg1) {
    u8 sp10;
    s32 n;
    u32 *buf;
    u8 *p;

    buf = func_801A37E4((u8 *)arg0->unkC + 8, arg1, &D_801E05C0);
    n = arg1 - 0x7F8;
    while (1) {
        sp10 = CdMode();
        if (!(sp10 & 0x80)) {
            sp10 = 0x80;
            while (CdControl(0xE, &sp10, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(n >> 11, buf, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) != -1) {
            break;
        }
        p = CdLastPos();
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    p = CdLastPos();
    p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
    while (CdControl(2, p, NULL) == 0) {
    }
    arg0->unk4 += n;
    func_801A3970(&D_801E05C0);
}

void func_8019159C(Unk_80192F20 *arg0, s32 arg1) {
    u8 sp10;
    u8 sp11;
    u8 *buf;
    s32 n;
    u8 *buf2;
    u8 *p;

    D_801E05C0.unk8 = (u8 *)arg0->unkC + 8;
    D_801E05C0.unk10 = 0x7F8;
    func_801A39F0(&D_801E05C0);
    arg1 -= D_801E05C0.unk10;
    D_801E05C0.unk10 = 0x2000;
    D_801E05C0.unk8 = func_801CC898(0x2000);
    if (D_801E05C0.unk8 == NULL) {
        func_801CD54C(3, "Error Allocating vab_trans_buffer", D_80170B7C, 0x191);
    }
    while (D_801E05C0.unk10 < arg1) {
        buf = D_801E05C0.unk8;
        n = D_801E05C0.unk10;
    retry:
        sp10 = CdMode();
        if (!(sp10 & 0x80)) {
            sp10 = 0x80;
            while (CdControl(0xE, &sp10, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(n >> 11, (u32 *)buf, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) == -1) {
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
            goto retry;
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += D_801E05C0.unk10;
        func_801A39F0(&D_801E05C0);
        arg1 -= D_801E05C0.unk10;
    }
    buf2 = D_801E05C8[0];
retry2:
    sp11 = CdMode();
    if (!(sp11 & 0x80)) {
        sp11 = 0x80;
        while (CdControl(0xE, &sp11, NULL) == 0) {
        }
        VSync(3);
    }
    while (CdRead(arg1 >> 11, (u32 *)buf2, 0x80) == 0) {
    }
    if (CdReadSync(0, NULL) == -1) {
        p = CdLastPos();
        while (CdControl(2, p, NULL) == 0) {
        }
        goto retry2;
    }
    p = CdLastPos();
    p = CdIntToPos(CdPosToInt(p) + (arg1 >> 11), p);
    while (CdControl(2, p, NULL) == 0) {
    }
    arg0->unk4 += arg1;
    D_801E05C0.unk10 = arg1;
    func_801A39F0(&D_801E05C0);
    func_801A217C((Unk_801A217C *)&D_801E05C0);
    free3(D_801E05C0.unk8);
}

void func_80191888(Unk_80192F20 *arg0, s32 arg1) {
    Unk_801AC278 *sp10;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    sp10 = NULL;
    func_801AC158(&sp10, arg1);
    *(Unk_8018FA18 *)sp10->unkC0 = *(Unk_8018FA18 *)((u8 *)arg0->unkC + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)sp10->unkC0 + 0x7F8);
        n = arg1 - 0x7F8;
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        arg0->unk4 += arg1 - 0x7F8;
    }
    func_801AC214((Unk_801E032C *)sp10);
}

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80191AB0);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80192380);

void func_801926B4(void) {
    Unk_80192F20 *sp10;
    Unk_80192F20 *q;
    Unk_80192F20 *q2;
    Unk_80192F20 *q3;
    Unk_80192E18 *e;
    Unk_801E02D8 *g;
    Unk_801E0340 *s;
    s32 pos;
    s32 a, b, c, d;
    u16 idx;
    u8 *p;
    u8 *loc;
    Unk_80192E18 *e2;
    s32 pos2;
    u8 *p2;
    u8 *loc2;

    s = &D_801E0340;
    func_80192380(&sp10, 0, s->unk0[2]);
    q = sp10;
    q->unk4 = 0;
    e = q->unk8;
    pos = e->unk0;
    q->unk0 = e->unk4;
    g = &D_801E02D8;
    a = e->unk8;
    b = e->unkC;
    c = e->unk10;
    d = e->unk14;
    if (a != 0) {
        g->unk24 = a;
    }
    if (b != 0) {
        g->unk20 = b;
    }
    if (c != 0) {
        g->unk30 = c;
    }
    if (d != 0) {
        g->unk2C = d;
    }
    if (q->unk0 == 0) {
        D_801DFF18 = 0;
    } else {
        loc = D_801DFF20;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    if (sp10->unk0 > 0) {
        func_80191AB0(sp10, (s32)s, 2, 0);
    }
    q2 = sp10;
    idx = s->unk0[3];
    q2->unk4 = 0;
    e2 = q2->unk8 + idx + 1;
    pos2 = q2->unk8[idx + 1].unk0;
    q2->unk0 = e2->unk4;
    D_801E02D8.unk1C = e2->unk8;
    D_801E02D8.unk18 = e2->unkC;
    D_801DFF1C = e2->unk10;
    D_801E02D8.unk28 = e2->unk14;
    if (D_801DFF18 != 0) {
        loc2 = D_801DFF20;
        p2 = CdIntToPos(CdPosToInt(loc2) + ((pos2 - 0x800) >> 11), loc2);
        while (CdControl(2, p2, NULL) == 0) {
        }
    } else {
        loc2 = D_801DFF20;
        p2 = CdIntToPos(CdPosToInt(loc2) + (pos2 >> 11), loc2);
        while (CdControl(2, p2, NULL) == 0) {
        }
    }
    if (sp10->unk0 > 0) {
        func_80191AB0(sp10, (s32)s, 2, 0);
    }
    q3 = sp10;
    free3(q3->unk8);
    free3(q3->unkC);
    free3(q3);
}

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_8019290C);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80192A44);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80192B8C);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80192CD0);

void func_80192E18(Unk_80192F20 *arg0, u16 arg1) {
    Unk_80192E18 *e;
    s32 pos;
    u8 *p;
    u8 *loc;

    arg0->unk4 = 0;
    e = arg0->unk8 + arg1 + 1;
    pos = arg0->unk8[arg1 + 1].unk0;
    arg0->unk0 = e->unk4;
    D_801E02D8.unk1C = e->unk8;
    D_801E02D8.unk18 = e->unkC;
    D_801DFF1C = e->unk10;
    D_801E02D8.unk28 = e->unk14;
    if (D_801DFF18 != 0) {
        loc = D_801DFF20;
        p = CdIntToPos(CdPosToInt(loc) + ((pos - 0x800) >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    } else {
        loc = D_801DFF20;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
}

void func_80192F20(Unk_80192F20 *arg0) {
    free3(arg0->unk8);
    free3(arg0->unkC);
    free3(arg0);
}

s32 func_80192F60(Unk_80192F60 *arg0) {
    Unk_801DFF30 *p = &D_801DFF30;

    switch (arg0->unkC) {
    case 0xFA0000:
        /* " 8机1から離れる       3○" */
        func_80183E88(" 8\212\3671\202\251\202\347\227\243\202\352\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFA0001:
        /* " 8コンピュータ1を起動する  3○" */
        func_80183E88(" 8\203R\203\223\203s\203\205\201[\203^1\202\360\213N\223\256\202\267\202\351  3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFA0002:
        /* " 8日記1をつける       3○" */
        func_80183E88(" 8\223\372\213L1\202\360\202\302\202\257\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFA0003:
        if (p->unk2 == 1) {
            /* " 8電話1をとる        3○" */
            func_80183E88(" 8\223d\230b1\202\360\202\306\202\351        3\201\233", 1, -1, 8, -1, 0, 1);
        } else if (p->unk2 == 2) {
            /* " 8電話1をかける       3○" */
            func_80183E88(" 8\223d\230b1\202\360\202\251\202\257\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

s32 func_80193068(Unk_80193068 *arg0) {
    Unk_801E0368 *g;
    Unk_801E076C *o;
    u16 v;
    s32 t;
    Unk_801DFF28 *f;

    g = &D_801E0368;
    f = &D_801DFF28;
    o = D_801E076C[0];
    t = arg0->unk10;
    v = D_801E0356[0];
    if (t == 4) {
        if (D_801DFD56 != 0) {
            D_801DFD56 = 0;
            return 1;
        }
        if (o->unk42 & 0x10) {
            /* " なんだか、うとうとしてきた" */
            func_80183E88(" \202\310\202\361\202\276\202\251\201A\202\244\202\306\202\244\202\306\202\265\202\304\202\253\202\275", 1, -1, 0, -1, 0, 0);
            func_801D1BAC(0, 0, 0);
            func_80186128(10, 3);
        }
    } else if (t == 10) {
        if (arg0->unkC == 0) {
            g->unk244 = -1;
        }
        func_80199EB4(0, 0xDAC, 0, 0xC80);
        func_80184094();
        func_8018C1B0(0, 0, 0, 4);
        func_80186128(9, 3);
    } else if (t == 9) {
        if (arg0->unkC == 0) {
            g->unk244 = -1;
        }
        o->unk42 &= ~0x10;
        func_801D1BAC(0x30, 0x30, 0x10);
    } else if (t == 0) {
        func_801D1BAC(0x30, 0x30, 0x10);
        if ((s16)v != 1) {
            func_801A3BCC(0);
        }
    } else if (t == 11) {
        if (!(o->unk42 & 0x4000)) {
            if (f->unk2 != 0) {
                /* " 1預ける8武器1を方向キー上下で, 選んで下さい,      決定 3○ 1戻る 4×" */
                func_80183E88(" 1\227a\202\257\202\3518\225\220\212\3551\202\360\225\373\214\374\203L\201[\217\343\211\272\202\305, \221I\202\361\202\305\211\272\202\263\202\242,      \214\210\222\350 3\201\233 1\226\337\202\351 4\201~", 3, -1, 0, -1, 0, 1);
            } else {
                /* " 1受け取る8武器1を方向キー上下で, 選んで下さい,      決定 3○ 1戻る 4×" */
                func_80183E88(" 1\216\363\202\257\216\346\202\3518\225\220\212\3551\202\360\225\373\214\374\203L\201[\217\343\211\272\202\305, \221I\202\361\202\305\211\272\202\263\202\242,      \214\210\222\350 3\201\233 1\226\337\202\351 4\201~", 3, -1, 0, -1, 0, 1);
            }
        }
    } else if (t == 12) {
        if (arg0->unk8 != 999999) {
            func_80194A2C(1, 0);
        }
    } else if (t == 13) {
        if ((s16)v == 1) {
            func_801A3BCC(0);
        }
    } else if (t == 8) {
        func_8018C1B0(0, 0, 0, 2);
        if (o->unk3C == 0) {
            o->unk3C = 1;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_801932F8);

INCLUDE_RODATA("asm/nonmatchings/game/8018FA18", D_80170E18);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80193880);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80193DA8);

void func_80194140(void) {
    Unk_801E076C *s0;
    s32 s3;
    Unk_801E0710 *p = &D_801E0710;

    s0 = p->unk5C;
    if (D_801E6DA0.unkA != 1) {
        return;
    }
    if ((s0->unk42 & 2) || (s0->unk42 & 0x10)) {
        return;
    }
    s3 = func_801CD6B4();
    if (func_80193880() != 0) {
        return;
    }
    if (!(s0->unk42 & 1) && func_8018898C(p, 0) != 0) {
        return;
    }
    if (s0->unk42 & 4) {
        if (!(D_801E6DA0.unk4 & 0x20) && (D_801E6DA0.unk0 & 0x20)) {
            func_80193DA8(p);
            return;
        }
        if (!(D_801E6DA0.unk4 & 0x40) && (D_801E6DA0.unk0 & 0x40)) {
            Unk_801DFFE8 *q = &D_801DFFE8;
            if (!(p->unk5C->unk42 & 0x40)) {
                s16 t = q->unk6;
                if (t == 2 && (p->unk5C->unk42 & 1)) {
                    func_80184094();
                    func_801A2678(0xE);
                    func_80198CFC(2, 1, 0x76C, 0, 0x19C8, 0, 0xB4, 0, t);
                    q->unk6 = 0;
                }
            }
            return;
        }
    }
    if (!(s0->unk42 & 0x40)) {
        func_80199548(p, 0, s3);
    }
}

void func_8019430C(void) {
    Unk_801E0710 *p;
    Unk_801E076C *o;
    Unk_801DFF30 *q;
    Unk_801E0340 *r;
    Unk_8018E56C *m;
    Unk_801E0368 *g;
    s32 i;
    s32 k;

    p = &D_801E0710;
    r = &D_801E0340;
    o = p->unk5C;
    D_801DFD56 = 0;
    func_801A4A68(0x410, 1);
    func_80197370(0);
    func_801926B4();
    func_80174840(1);
    func_8018F428(0, 1);
    func_801A8000(3, 2, 1);
    func_801A80CC(3, 2, 1);
    func_801A8198(3, 2, 1);
    func_80187978(0);
    func_80187978(1);
    m = func_8018E56C(0x40);
    q = &D_801DFF30;
    p->unk50 = m;
    if (m != NULL) {
        func_8018D2DC(m, 0, 3, 0);
        p->unk50->unk54 = 0xDAC - o->unk72 * 12500;
        p->unk50->unk58 = 0;
        p->unk50->unk5C = 0x1A2C - o->unk76 * 12500;
        p->unk50->unk3C = 0;
    }
    D_801DFF50 = (s32)func_80194B50;
    D_801DFED8 = (s32)func_80194C24;
    D_801DFEE4 = (s32)func_80192F60;
    D_801DFED4 = (s32)func_80193068;
    D_801DFEE8 = (s32)func_80194D4C;
    q->unk0 = 0;
    q->unk2 = 0;
    q->unk4 = -1;
    D_801DFD54 = 0;
    if (r->unk0[3] == 1) {
        D_801DFD54 = 1;
    }
    k = ((s16 *)&r->unk14)[1];
    if (k == 2) {
        g = &D_801E0368;
        D_801E0710.unk0 = 0xC9;
        p->unk36 = k;
        p->unk34 = 0;
        g->unk0[0x30] = 1;
        for (i = 9; i < 0x1C; i++) {
            g->unk0[i] = 1000;
        }
        for (i = 0; i < 5; i++) {
            p->unk3A[i] = 0;
            g->unkB4[i] = 0;
        }
        if (g->unk7C >= 5) {
            g->unk7A++;
            if (g->unk7A >= 99) {
                g->unk7A = 98;
            }
        }
        g->unk7C = 5;
        g->unk7E = 0;
        func_8018A7C0(p);
        func_80189DE8(p);
    }
    func_8018AABC(0);
    func_801A4A68(0x410, 0);
}

void func_801945E0(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801E0710 *q = &D_801E0710;
    s32 i;

    func_801863B4();
    func_801A3C58();
    func_801A252C();
    D_801DFF50 = 0;
    D_801DFED8 = 0;
    D_801DFEE4 = 0;
    D_801DFED4 = 0;
    D_801DFEE8 = 0;
    q->unk50 = 0;
    func_80184094();
    func_80174840(1);
    func_80174FA8();
    func_80174BC8();
    func_80176780();
    func_80185548();
    func_8018E47C();
    func_801A43F4(0);
    func_801A7BA4();
    for (i = 0; i < p->unk34; i++) {
        if (p->unk5C[i] != 0) {
            free3(p->unk5C[i]);
            p->unk5C[i] = 0;
        }
    }
    p->unk34 = 0;
    switch (D_801DFF38) {
    case 0:
        func_8017D1BC();
        func_801A3B5C();
        func_801A23B4();
        func_801A43F4(0x207);
        if (D_801DFD54 != 0) {
            func_80199E1C(0xFF, 0);
        }
        break;
    case 1:
        func_8017D1BC();
        break;
    case 2:
        func_801A43F4(0x207);
        break;
    }
}

void func_80194780(void) {
    s32 buf[6];
    u16 mode;
    s16 done;
    s16 m;

    mode = D_801E0356[0];
    done = 0;
    func_8019430C();
    func_801D06B4();
    switch ((s16)mode) {
    case 0:
        func_80186128(0, 3);
        break;
    case 1:
        func_801A3BCC(1);
    case 2:
        func_80186258();
        func_80183CFC((s32)D_801E02D8.unk5C[(s16)mode - 1]);
        break;
    }
    m = mode;
    while (done == 0) {
        switch (func_801CC378(buf)) {
        case 2:
            func_80189928(buf);
            continue;
        case 0x10:
            func_80189350(buf);
            continue;
        case 0x20:
            func_801895E0(buf);
            continue;
        case 4:
            func_80189970(0);
            continue;
        case 0x200:
            func_801899AC(buf);
            continue;
        case 0:
            func_80194140();
            if ((s16)func_8018C170() != 0 && D_801DFF38 != 2) {
                func_801D1BAC(0, 0, 0);
                func_80186128(1, 3);
            }
            break;
        case 0x100:
            done = func_8018970C(buf);
            continue;
        default:
            func_801CC734(buf);
            continue;
        }
        if (m != 0) {
            func_80184434(m - 1);
        }
        func_801932F8();
        func_80186414(0, 0x400, rand() % 10 + 10);
        func_8018C2FC(0, 0, 0);
    }
    func_801D06C4();
    func_801945E0();
}

void func_80194A2C(s16 arg0, char *arg1) {
    Unk_801DFF28 *p = &D_801DFF28;

    if (arg0 == 0) {
        func_801A4A68(0, 0);
        if (arg1 != NULL) {
            func_80183E88(arg1, 1, -1, 0, -1, 0, 4);
        } else {
            p->unk0 = 0;
            p->unk4 = 0;
            p->unk2 = 1;
            func_80184094();
        }
        if (arg1 == NULL) {
            func_8018C1B0(0, 0, 0, 1);
            return;
        }
        func_8018C1B0(0, 0, 0, 3);
    }
    p->unk0 = 1;
    p->unk4 = 0;
    p->unk2 = 1;
    func_801A4A68(0, 1);
    func_801A461C(0, 4, D_801DFD5A);
    func_801A461C(0, 5, D_801DFD58);
    func_80183E88(D_80170E18, 3, -1, 0, -1, 0, 1);
}

void func_80194B50(s32 *arg0) {
    Unk_801E076C *p = D_801E076C[0];
    Unk_801DFF30 *q = &D_801DFF30;
    s16 v;

    if ((*(u32 *)&p->unk40 & 0x1010000) == 0x10000) {
        *arg0 = 0xFA0000;
        if (p->unk6C >= -20 && p->unk6C <= 10) {
            v = p->unk6E;
            if (v >= 130 && v <= 170) {
                *arg0 = 0xFA0001;
            } else if (v >= 180 && v < 220) {
                *arg0 = 0xFA0002;
            } else if (v >= 220 && v <= 250) {
                if (q->unk0 != 0 && q->unk2 != 3) {
                    *arg0 = 0xFA0003;
                }
            }
        }
    }
}

void func_80194C24(Unk_80192F60 *arg0) {
    Unk_801E076C *p = D_801E076C[0];
    Unk_801DFF30 *q = &D_801DFF30;
    Unk_8018E56C *o;

    if (arg0->unkC == 0x400) {
        o = func_8018E56C(0x440);
        if (o != NULL && o->unk16 == 0) {
            func_8018DA2C(o, 1, 0);
        }
    } else if (arg0->unkC == 0x401) {
        q->unk2 = 4;
        func_80194F08(q->unk4);
        func_801A25B4(0x33);
    } else if (arg0->unkC == 0x402) {
        if (!(p->unk42 & 0x40) && q->unk2 != 4) {
            q->unk2 = 3;
            func_801A25B4(0x33);
            func_80186414(3, 0x403, 10);
            if (p->unk42 & 1) {
                func_80199C68(0);
            }
        }
    } else if (arg0->unkC == 0x403) {
        if (q->unk2 == 3) {
            q->unk0 = 0;
            q->unk2 = 0;
            q->unk4 = -1;
        }
    }
}

void func_80194D4C(Unk_80192F60 *arg0) {
    Unk_801E0710 *r = &D_801E0710;
    Unk_801E076C *p = r->unk5C;
    Unk_8018E56C *o = r->unk50;
    Unk_801DFF30 *q = &D_801DFF30;

    if (arg0->unkC == 3 && arg0->unk8 == 0x40) {
        if (o->unk16 == 1) {
            if (q->unk2 == 2) {
                func_801A2678(0x33);
                func_80186414(1, 0x401, 5);
            } else if (q->unk2 == 1) {
                q->unk2 = 4;
                func_80194F08(q->unk4);
                func_801A25B4(0x33);
            }
        } else if (o->unk16 == 2) {
            func_80184094();
            p->unk42 &= ~0x40;
            q->unk0 = 0;
            q->unk2 = 0;
            q->unk4 = -1;
            if (p->unk42 & 1) {
                func_80199C68(0);
            }
        }
    }
}

void func_80194E5C(void) {
    D_801DFF38 = 0;
    while (1) {
        func_80194780();
        switch (D_801DFF38) {
        case 1:
            func_80182300();
            D_801DFF38 = 0;
            break;
        case 2:
            func_801A4A68(0x400, 0);
            func_801A4A68(0x409, 0);
            func_801808F0(0, 1);
            func_8018C414(0, 1, 0, 0);
            D_801DFF38 = 0;
            func_801A4A68(0x400, 1);
            func_801A4A68(0x409, 1);
            break;
        default:
            return;
        }
    }
}

void func_80194F08(s16 arg0) {
    void *o = D_801E0760[0];
    Unk_801DFFE8 *p = &D_801DFFE8;
    Unk_80174B10 *item;

    item = func_80174CB8(arg0);
    if (item != NULL) {
        p->unk0 = 0;
        p->unkA = -1;
        p->unkE = -1;
        p->unk4 = 0;
        p->unk8 = 0;
        p->unkC = 0;
        p->unk6 = 1;
        while ((item = func_80173DE0(item, 0, 0)) != NULL) {
        }
    } else {
        func_8018DA2C(o, 2, 0);
    }
}

s32 func_80194FAC(void) {
    Unk_801E0620 *p = &D_801E0620;
    Unk_801CC1E8 *o;

    UnDeliverEvent(0xF3000000, 2);
    if (D_801DFF4C != 0) {
        D_801DFF4C = 0;
        o = func_801CC1E8(0x20);
        if (o != NULL) {
            o->unkC = D_801E0610.unk0;
            o->unk8 = D_801E0610.unk4;
            o->unk10 = D_801E0610.unk8;
        }
    }
    o = func_801CC1E8(0x10);
    if (o != NULL) {
        o->unkC = D_801E0600.unk0;
        o->unk8 = D_801E0600.unk4;
        o->unk10 = D_801E0600.unk8;
    }
    D_801E0610.unk4 = D_801E0600.unk4;
    D_801E0610.unk0 = D_801E0600.unk0;
    D_801E0610.unk8 = D_801E0600.unk8;
    p->unk42 |= 4;
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80195098);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_8019555C);

void func_801958FC(Unk_801E0620 *arg0) {
    s32 x;
    s32 y;
    s32 z;

    if (arg0->unk54 >= -12500 && arg0->unk54 <= 12500 && arg0->unk58 <= 32000 && arg0->unk58 >= -32000
        && arg0->unk5C <= 12500 && arg0->unk5C >= -12500) {
        return;
    }
    if (arg0->unk54 > 12500) {
        arg0->unk72++;
        arg0->unk54 -= 12500;
    }
    if (arg0->unk54 < -12500) {
        arg0->unk72--;
        arg0->unk54 += 12500;
    }
    if (arg0->unk58 < -32000) {
        arg0->unk74++;
        arg0->unk58 += 32000;
    }
    if (arg0->unk58 > 32000) {
        arg0->unk74--;
        arg0->unk58 -= 32000;
    }
    if (arg0->unk5C > 12500) {
        arg0->unk76++;
        arg0->unk5C -= 12500;
    }
    if (arg0->unk5C < -12500) {
        arg0->unk76--;
        arg0->unk5C += 12500;
    }
    x = arg0->unk72 * 12500;
    y = -(arg0->unk74 * 32000);
    z = arg0->unk76 * 12500;
    arg0->unk60 = (arg0->unk54 + x) / 100;
    arg0->unk64 = (arg0->unk58 + y) / 100;
    arg0->unk68 = (arg0->unk5C + x) / 100;
    func_80176654(x, y, z);
    func_8017CF10(x, y, z);
    func_80185794(x, y, z);
    func_8018F5E8(x, y, z);
    func_801A7E10(x, y, z);
    if (arg0->unk46 != 0) {
        func_801AC464(x, y, z);
    }
}

void func_80195BC8(Unk_801E0620 *arg0, s16 *arg1, u16 arg2) {
    s16 rot[3];

    arg0->unk90[0] = -arg0->unk54;
    arg0->unk60 = (arg0->unk54 + arg0->unk72 * 12500) / 100;
    arg0->unk64 = (arg0->unk58 - arg0->unk74 * 32000) / 100;
    arg0->unk68 = (arg0->unk5C + arg0->unk76 * 12500) / 100;
    arg0->unk90[1] = -arg0->unk58;
    arg0->unk90[2] = -arg0->unk5C;
    MatrixNormal(arg0->unk7C, arg0->unk7C);
    RotMatrix(arg1, arg0->unk7C);
    ApplyMatrixLV(arg0->unk7C, arg0->unk90, arg0->unk90);
    func_801B25D0(arg0->unk7C);
    if (arg2 == 1) {
        arg0->unkA0[0].unk18 = arg0->unk54;
        arg0->unkA0[0].unk1C = arg0->unk58 - arg0->unk4C + 320;
        arg0->unkA0[0].unk20 = arg0->unk5C;
        rot[0] = (arg0->unk6C << 12) / 360;
        rot[1] = (arg0->unk6E << 12) / 360;
        rot[2] = (arg0->unk70 << 12) / 360;
        RotMatrixZYX(rot, arg0->unkA0[0].unk4);
        arg0->unkA0[0].unk0 = 0;
    }
    arg0->unk3C = 0;
}
