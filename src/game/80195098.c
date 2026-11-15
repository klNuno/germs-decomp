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
    u8 unk0[8];
    s16 unk8;
    u8 unkA[0xC];
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
    u8 unk2[0x2A];
    s16 unk2C;
    u8 unk2E[2];
    s16 unk30;
    s16 unk32;
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
    u8 unk80[0x18];
    s16 unk98;
    u8 unk9A[0x18];
    u16 unkB2;
    s16 unkB4[5];
    u8 unkBE[0x186];
    s32 unk244;
} Unk_801E0368;
extern Unk_801E0368 D_801E0368;
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; } Unk_80192F60;
typedef struct { s16 unk0; s16 unk2; s16 unk4; } Unk_801DFF30;
Unk_801DFF30 D_801DFF30;
void func_80183E88(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_801DFF28;
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
    void *unk38;
    void *unk3C;
    void *unk40;
    void *unk44;
    void *unk48;
    void *unk4C;
    void *unk50;
    void *unk54;
    void *unk58;
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
s16 func_8018898C(Unk_801E0710 *arg0, s16 arg1);
void func_80193DA8(Unk_801E0710 *arg0);
void func_80198CFC(s16 a, u16 b, s32 c, s32 d, s32 e, s16 f, s16 g, s16 h, s32 i);
void func_80199548(Unk_801E0710 *arg0, s32 arg1, s32 arg2);
s16 D_801DFD54;
s32 D_801DFF50;
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
void func_80191AB0(Unk_80192F20 *arg0, s32 arg1, s32 arg2, s32 arg3);
void func_8017519C(void);
typedef struct { u8 unk0[4]; } Unk_801DFF20;
void *CdSearchFile(void *fp, char *name);
extern s32 D_801D7744[];
extern s32 D_801D7780[];
void func_80184100(Unk_801DFFE8 *arg0);
typedef struct { s32 unk0; s32 unk4; s16 unk8; } Unk_80191AB0_C;
typedef struct {
    s16 unk0;
    u8 unk2[0xE];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[6];
    s16 unk1C;
} Unk_80191AB0;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4[2];
    s16 unk8[2];
    s16 unkC[0x12];
    s16 unk30;
    s16 unk32[8];
    s16 unk42;
    s16 unk44;
    s16 unk46;
    s16 unk48;
    u8 unk4A[2];
    s32 unk4C;
} Unk_801E0768;
extern Unk_801E0768 *D_801E0768[];
s32 D_801DFF10;
s32 D_801DFF14;
void func_801A05EC(s32 arg0);
void func_8018677C(void);
s16 func_8018BD44(s16 i);
void func_8018FA18(Unk_80192F20 *arg0, s32 arg1);
void func_8018FC90(Unk_80192F20 *arg0, u16 arg1, s32 arg2);
void func_8018FED4(Unk_80192F20 *arg0, s32 arg1);
void func_80190108(Unk_80192F20 *arg0, s32 arg1, s32 arg2);
void func_80190378(Unk_80192F20 *arg0, s32 arg1);
void func_801905A0(Unk_80192F20 *arg0, s32 arg1);
void func_801907C8(Unk_80192F20 *arg0, s32 arg1, s32 arg2);
void func_80190B2C(Unk_80192F20 *arg0, s32 arg1);
void func_80190D8C(Unk_80192F20 *arg0, s32 arg1);
void func_80190FD8(Unk_80192F20 *arg0, s32 arg1);
void func_8019120C(Unk_80192F20 *arg0, s32 arg1);
void func_80191450(Unk_80192F20 *arg0, s32 arg1);
void func_8019159C(Unk_80192F20 *arg0, s32 arg1);
void func_80191888(Unk_80192F20 *arg0, s32 arg1);
s32 func_8018BD8C(s16 a);
extern s16 D_801E05E0[];
void func_80187BE4(s16 arg0, s16 arg1);
s32 func_80188EB8(s16 arg0, s16 *arg1, s16 *arg2);
s16 func_8018CEA0(s16 a);
s32 func_8018D078(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i);
s32 func_8018D1A0(void);
s16 func_8018D1F0(void);
typedef struct { s32 unk0; s16 unk4; s16 unk6; s16 unk8; s16 unkA; } Unk_80174F54;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s32 unk8; u8 unkC; u8 unkD; u8 unkE; u8 unkF; s32 unk10; s16 unk14; s16 unk16; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; s32 unk3C; s32 unk40; s32 unk44; s32 unk48; } Unk_801762F4;
s16 D_801DFD5C;
s16 D_801DFD5E;
Unk_80174F54 *func_80174F54(s32 arg0);
Unk_801762F4 *func_801762F4(s16 arg0, u16 arg1);
void EnterCriticalSection(void);
void ExitCriticalSection(void);
void DeliverEvent(u32 ev, u32 spec);

s16 func_80195098(Unk_801E0620 *arg0, s32 arg1, s16 arg2, s16 arg3) {
    s32 sp10;
    u16 s1;
    Unk_80174F54 *s3;
    s16 s2;
    s16 s6;
    s32 t;
    s32 v;
    Unk_801762F4 *p;

    v = 0xFFFFFF;
    s1 = 0;
    s3 = NULL;
    s6 = 0;
    s2 = 1;
    sp10 = v;
    D_801DFD5C = 0;
    D_801DFD5E = 0;
    switch ((u32)arg1) {
    case 0x1000000:
    case 0x2000000:
        if (D_801DFF50 != 0) {
            ((void (*)(s32 *))D_801DFF50)(&sp10);
        }
        s6 = 1;
        s1 = ((u8 *)&sp10)[2];
        s2 = 0;
        arg0->unk44 = 0;
        sp10 &= v;
        break;
    case 0xFFFF:
    case 0x9600:
    case 0xFF00:
        if (arg3 == 0) {
            if (arg2 != 0) {
                arg0->unk44 = 3;
            } else if (arg0->unk42 & 0x1000) {
                arg0->unk44 = 2;
            } else {
                arg0->unk44 = 1;
            }
        } else {
            arg0->unk44 = 5;
            if (arg0->unk42 & 0x1000) {
                arg0->unk42 &= ~0x1000;
                arg0->unk4A = 4;
            }
        }
        break;
    default:
        t = arg1 & 0xFF0000;
        if (t == 0xFC0000) {
            s1 = 0xFC;
            sp10 = arg1 & 0xFFFFFF;
            p = func_801762F4(0, arg1);
            if (p != NULL && p->unkF == 6) {
                if (arg2 != 0) {
                    arg0->unk44 = 3;
                } else if (arg0->unk42 & 0x1000) {
                    arg0->unk44 = 2;
                } else {
                    arg0->unk44 = 1;
                }
            } else {
                arg0->unk44 = 0;
                if (arg0->unk42 & 0x1000) {
                    arg0->unk42 &= ~0x1000;
                    arg0->unk4A = 4;
                }
                s2 = 0;
            }
        } else if (t == 0xF70000) {
            s1 = 0xF7;
            sp10 = arg1 & 0xFFFFFF;
            arg0->unk44 = 0;
            if (arg0->unk42 & 0x1000) {
                arg0->unk42 &= ~0x1000;
                arg0->unk4A = 4;
            }
            s2 = 0;
        } else if (t == 0xFD0000) {
            s1 = 0xFD;
            sp10 = arg1 & 0xFFFFFF;
            arg0->unk44 = 0;
            if (arg0->unk42 & 0x1000) {
                arg0->unk42 &= ~0x1000;
                arg0->unk4A = 4;
            }
            s2 = 0;
        } else if (t != 0) {
            if (arg3 == 0) {
                if (arg0->unk42 & 0x1000) {
                    arg0->unk44 = 2;
                } else {
                    arg0->unk44 = 1;
                }
            } else {
                arg0->unk44 = 5;
                if (arg0->unk42 & 0x1000) {
                    arg0->unk42 &= ~0x1000;
                    arg0->unk4A = 4;
                }
            }
            s1 = ((u32)arg1 >> 16) & 0xFF;
            sp10 = arg1;
            s3 = func_80174F54(arg1);
            if (s3 == NULL) {
                if (s1 == 0xFF) {
                    D_801DFD5C = 1;
                    arg0->unk44 = 0;
                    if (arg0->unk42 & 0x1000) {
                        arg0->unk42 &= ~0x1000;
                        arg0->unk4A = 4;
                    }
                    s2 = 0;
                }
            } else {
                if (s3->unk8 == 0) {
                    D_801DFD5E = 1;
                    arg0->unk44 = 0;
                    if (arg0->unk42 & 0x1000) {
                        arg0->unk42 &= ~0x1000;
                        arg0->unk4A = 4;
                    }
                    s2 = 0;
                }
                if (s3->unkA == 0) {
                    s1 = 0;
                    sp10 = 0xFFFFFF;
                    s3 = NULL;
                }
            }
        } else {
            arg0->unk44 = 4;
            if (arg0->unk42 & 0x1000) {
                arg0->unk42 &= ~0x1000;
                arg0->unk4A = 4;
            }
            s6 = 1;
            s2 = 0;
        }
        break;
    }
    if (s6 != 0) {
        if (sp10 != D_801DFF48 && sp10 != 0xFFFFFF) {
            EnterCriticalSection();
            D_801E0600.unk4 = s1;
            D_801E0600.unk8 = (s32)s3;
            D_801E0600.unk0 = sp10;
            DeliverEvent(0xF3000000, 2);
            D_801DFF48 = sp10;
            ExitCriticalSection();
        }
    } else if (sp10 != D_801DFF48) {
        EnterCriticalSection();
        if (D_801DFF48 != 0xFFFFFF) {
            if (sp10 != 0xFFFFFF) {
                D_801DFF4C = 1;
                D_801E0600.unk4 = s1;
                D_801E0600.unk0 = sp10;
                D_801E0600.unk8 = (s32)s3;
                DeliverEvent(0xF3000000, 2);
            } else {
                D_801E0600.unk4 = D_801E0610.unk4;
                D_801E0600.unk0 = D_801E0610.unk0;
                D_801E0600.unk8 = D_801E0610.unk8;
                DeliverEvent(0xF3000001, 2);
            }
        } else {
            D_801E0600.unk4 = s1;
            D_801E0600.unk8 = (s32)s3;
            D_801E0600.unk0 = sp10;
            DeliverEvent(0xF3000000, 2);
        }
        D_801DFF48 = sp10;
        ExitCriticalSection();
    }
    return s2;
}

INCLUDE_ASM("asm/nonmatchings/game/80195098", func_8019555C);

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
