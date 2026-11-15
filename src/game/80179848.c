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
    u8 pad204[0x40];
    s32 unk244;
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
    s32 unk10;
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
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Unk_8017AC88;
typedef struct {
    u8 pad0[0x18];
    Unk_8017AC88 unk18[2];
    u8 pad38[0x8];
    s16 unk40;
    u16 unk42;
    u8 pad44[0x2];
    u16 unk46;
    u8 pad48[0xC];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    u8 pad64[0x4];
    s32 unk68;
    u8 pad6C[0x2];
    s16 unk6E;
    u8 pad70[0x2];
    s16 unk72;
    s16 unk74;
    s16 unk76;
    s16 unk78;
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
    s32 unk0;
    s16 unk4;
    s16 unk6;
    u16 unk8;
    s16 unkA;
    u16 unkC;
    s16 unkE;
    u8 pad10[0x2];
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
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 pad7[0x1];
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u16 unkE;
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
    u8 pad0[0x10];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 pad16[0x6];
    s16 unk1C[0x10];
    u8 pad3C[0x80];
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
typedef struct {
    s16 unk0[5];
    s16 unkA;
    char *unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    u16 unk18;
    u8 pad1A[0x2];
    s32 unk1C;
    u8 unk20[0x10];
} Unk_801E0340;
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
s32 func_801BDC30(double arg0, double arg1);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_8017AF18;
s16 func_8017AC88(Unk_8017AC88 *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_8017AF18(Unk_8017AC88 *arg0, Unk_8017AF18 *arg1, s32 arg2, s32 arg3, s32 arg4);
s32 abs(s32 x);
typedef struct {
    u8 pad0[0x36];
    s16 unk36;
    u8 pad38[0x24];
    Unk_801E076C *unk5C;
} Unk_801E0710;
typedef struct {
    u16 unk0;
    u16 unk2;
} Unk_801DFE68;
Unk_801DFE68 D_801DFE68;
void func_80184100(Unk_80184100 *arg0);
void func_80184094(void);
void func_80183618(s16 arg0);
void func_801A5B10(s16 arg0);
void func_80187560(s16 arg0);
void func_801A5CD4(void);
void func_801A1FD4(s16 arg0, s16 arg1);
void func_801A1AB8(s16 arg0, s32 arg1);
void func_80183E88(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void *func_80174CB8(s16 arg0);
void *func_80173DE0(void *arg0, s32 arg1, s32 arg2);
extern Unk_801E0710 D_801E0710;
typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
typedef struct {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s16 unk8;
    u8 padA[0x12];
    char **unk1C;
} Unk_801E1058;
extern Unk_801E1058 D_801E1058[];
s32 func_801CD6B4(void);
s16 func_8018898C(Unk_801E0710 *arg0, s32 arg1);
s16 func_801A14A0(Unk_801E0710 *arg0);
s16 func_80187E38(Unk_801E0710 *arg0);
void func_8017DAE8(Unk_801E0710 *arg0);
void func_80199548(Unk_801E0710 *arg0, s32 arg1, s32 arg2);
s16 D_801DFE62;
extern s32 (*D_801DFED4)(Unk_8017E504 *arg0);
extern s32 (*D_801DFEE4)(Unk_8017E504 *arg0);
s32 func_8017D604(Unk_8017E504 *arg0);
s32 func_8017E504(Unk_8017E504 *arg0);
void func_80174840(s16 arg0);
void func_8017A86C(u16 arg0);
int sprintf(char *buf, const char *fmt, ...);
void func_801926B4(void);
void func_80188CE4(void);
void func_801A8000(s32 arg0, s32 arg1, s16 arg2);
void func_801A80CC(s32 arg0, s32 arg1, s16 arg2);
void func_8018F428(u16 arg0, s16 arg1);
void func_8018647C(s16 arg0);
void func_80186680(void);
void func_801A5C34(void);
void func_801A1EC0(s16 arg0);
void func_8018AABC(s16 arg0);
extern void (*D_801DFEDC)(void);
extern s32 (*D_801DFEE0)();
void func_8017DFA4(void);
void func_8017DD70(void);
void func_801D06B4(void);
void func_801D06C4(void);
void func_801CD688(s32 arg0);
s32 func_801CC378(s32 *arg0);
void func_801CC734(s32 *arg0);
void func_80189350(s32 *arg0);
void func_801A20A8(void);
void func_801895E0(s32 *arg0);
void func_80189970(s16 arg0);
void func_801899AC(s32 *arg0);
s16 func_8018C170(void);
s16 func_8018970C(s32 *arg0);
void func_8018C2FC(u16 arg0, s16 arg1, s16 arg2);
void func_8017D3F0(void);
void func_801A3C58(void);
void func_801A252C(void);
void func_8018655C(void);
void func_80186718(void);
void func_80174FA8(void);
void func_801762A0(void);
void func_80176780(void);
void func_8017683C(void);
void func_80188DE8(void);
void func_80174BC8(void);
void func_8017D1BC(void);
void func_80185548(void);
void func_8018E47C(void);
void func_801A7BA4(void);
void func_801A3B5C(void);
void func_801A23B4(void);
void func_8017E594(s16 arg0, s16 arg1, s16 *arg2);
void func_80189970(s16 a);
void func_8018ABE8(s16 a, s16 b);
void func_8018C1B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_801A0418(u16 a);
extern char D_801702B0[];
extern char D_801702C8[];
s32 func_801D67E0(void);
s16 func_801D3B7C(void);
s16 func_801D6850(void);
s32 func_801D6894(s16 arg0, void *arg1);
s16 func_801D3C50(void);
void func_801D6940(u16 arg0, s32 *arg1, u8 *arg2);
void func_80197370(s32 arg0);
s32 func_801D6E1C(void);
void func_80184698(void);
void func_801A6EB4(void);
void RotTrans(void *v0, s32 *v1, s32 *flag);
void func_8018C50C(s32 a, s32 b, s32 c, s16 d, s16 e);
extern s32 D_801D74B0[];
typedef struct {
    s32 unk0;
    s32 unk4;
} Unk_80179848_14;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    union {
        struct {
            s32 unkC;
            s32 unk10;
        } s;
        struct {
            u16 unkC;
            u16 unkE;
            u16 unk10;
            s16 unk12;
        } h;
    } unkC;
    Unk_80179848_14 unk14[1];
} Unk_80179848;
void GsInitCoordinate2(void *super, void *base);
void func_801CD028(void *arg0, void *arg1, void *arg2);
typedef struct {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u16 unkE;
    s16 unk10;
    u16 unk12;
} Unk_801E1118;
extern Unk_801E1118 D_801E1118;
extern s16 D_801DFF78;
extern s32 D_801D7450[];
void func_801A3BCC(s32 arg0);
void func_801A2C60(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6);
void func_801A5650(s16 arg0);
s16 func_801A0EDC(s16 arg0);
void func_80199EB4(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
void func_80199370(s32 arg0, s32 arg1, s32 arg2, s16 arg3);
s32 SquareRoot0(s32 arg0);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_8017A108;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    u8 pad10[0x1C];
    Unk_8017AF18 unk2C[4];
} Unk_801E1158;
extern Unk_801E1158 D_801E1158;
s32 func_80179E50(Unk_801E076C *arg0, u16 arg1, Unk_8017CCE4 *arg2, s32 *arg3, s32 *arg4);
void GsSetLsMatrix(void *m);
s32 func_8018C0A0(s16 a);
s32 rsin(s32 a);
s32 rcos(s32 a);
s32 ratan2(s32 y, s32 x);

void func_80179848(Unk_8017CCE4 *arg0, u16 arg1) {
    s32 sp10[5];
    Unk_801E076C *m;
    Unk_80179848 *d;
    Unk_8017CAC8 *s;
    Unk_8017C9F8 **p;
    s32 i;

    m = D_801E076C[0];
    memset(sp10, 0, 0x14);
    if (arg1 == 2) {
        d = arg0->unk8C;
        arg0->unk10 = d->unk4 * 100;
        arg0->unk14 = 0;
        arg0->unk18 = d->unk0 * 100;
        arg0->unk1C = d->unkC.s.unkC * 100;
        arg0->unk20 = 0;
        arg0->unk24 = d->unk8 * 100;
        arg0->unkC = 1;
        for (i = 0; i < d->unkC.s.unk10; i++) {
            sp10[d->unk14[i].unk0] = d->unk14[i].unk4;
        }
    } else {
        d = arg0->unk8C;
        arg0->unk4 = 1;
        arg0->unk6 = 1;
        arg0->unk10 = d->unk0;
        arg0->unk14 = d->unk4;
        arg0->unk18 = d->unk8;
        arg0->unk1C = d->unkC.h.unkC;
        arg0->unk20 = d->unkC.h.unkE;
        arg0->unk24 = d->unkC.h.unk10;
        arg0->unkC = 0;
        for (i = 0; i < d->unkC.h.unk12; i++) {
            sp10[d->unk14[i].unk0] = d->unk14[i].unk4;
        }
    }
    arg0->unkE = 0;
    if (sp10[0] != 0) {
        func_801CD028(&arg0->unk84, (u8 *)arg0->unk8C + sp10[0], &arg0->unk28);
        arg0->unkE |= 1;
    }
    if (sp10[1] != 0) {
        func_801CD028(&arg0->unk80, (u8 *)arg0->unk8C + sp10[1], &arg0->unk28);
        arg0->unkE |= 2;
    }
    if (sp10[2] != 0) {
        func_801CD028(&arg0->unk7C, (u8 *)arg0->unk8C + sp10[2], &arg0->unk28);
        arg0->unkE |= 4;
    }
    if (sp10[3] != 0) {
        func_801CD028(&arg0->unk78, (u8 *)arg0->unk8C + sp10[3], &arg0->unk28);
        arg0->unkE |= 8;
    }
    if (sp10[4] != 0) {
        p = &arg0->unk88;
        s = (Unk_8017CAC8 *)((u8 *)arg0->unk8C + sp10[4]);
        if (*p == NULL) {
            *p = func_801CC898(0x10);
            if (*p == NULL) {
                func_801CD54C(3, "Error Allocating Arena Buffer", D_801DFC84, 0x49);
            }
        } else {
            memset(*p, 0, 0x10);
        }
        (*p)->unk0 = s->unk0;
        (*p)->unk2 = s->unk2;
        (*p)->unk4 = s->unk4;
        (*p)->unk6 = s->unk6;
        (*p)->unk8 = s + 1;
        (*p)->unkC = s;
        arg0->unkE |= 0x10;
    }
    GsInitCoordinate2(NULL, &arg0->unk28);
    arg0->unk40 = arg0->unk10 - m->unk72 * 12500;
    arg0->unk44 = arg0->unk14 + m->unk74 * 32000;
    arg0->unk48 = arg0->unk18 - m->unk76 * 12500;
    arg0->unk28 = 0;
    arg0->unk0 = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", func_80179C50);

s32 func_80179E50(Unk_801E076C *arg0, u16 arg1, Unk_8017CCE4 *arg2, s32 *arg3, s32 *arg4) {
    s32 a;
    s32 sp10[2];
    s32 b;
    s32 d;
    s32 f;
    s32 x;
    s32 z;
    s32 w;
    s32 h;
    Unk_8017C9F8 *p;
    s32 *v3 = arg3;

    v3[0] = arg2->unk40 - arg0->unk54;
    arg4[0] = arg2->unk1C + v3[0];
    v3[1] = arg0->unk58 - arg0->unk78 - arg2->unk44;
    arg4[1] = arg2->unk20 + v3[1];
    v3[2] = arg2->unk48 - arg0->unk5C;
    arg4[2] = arg2->unk24 + v3[2];
    if (arg1 == 2) {
        a = arg4[0] >> 1;
        b = arg4[2] >> 1;
        d = SquareRoot0(a * a + b * b);
        arg2->unkC = 1;
        if (arg2->unk1C < 5001 && arg2->unk24 < 5001) {
            f = d < 3537;
        } else {
            f = d < 7073;
        }
        if (f) {
            arg2->unkC = 0;
        }
    } else {
        arg2->unkC = 0;
    }
    if (arg2->unkE & 0x10) {
        p = arg2->unk88;
        x = arg0->unk54 + arg0->unk72 * 12500 - arg2->unk10;
        z = arg0->unk5C + arg0->unk76 * 12500 - arg2->unk18;
        h = x >> 8;
        w = p->unk0;
        x = (x & 0xFF) ? (f = w + 1, h + f) : h + w;
        h = z >> 8;
        w = p->unk2;
        z = (z & 0xFF) ? (f = w + 1, h + f) : h + w;
        if (x >= 0 && x < p->unk4 && z >= 0 && z < p->unk6) {
            arg2->unk8 = 1;
        }
    }
    if (v3[0] > 0 || arg4[0] <= 0 || v3[2] > 0 || arg4[2] <= 0) {
        return 0;
    }
    if (arg1 == 1 && (s16)arg0->unk40 != 0 && (v3[1] > 0 || arg4[1] < 0)) {
        return 0;
    }
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170270);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170290);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_801702B0);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_801702C8);

static inline s32 func_8017A108_1(Unk_801E076C *o, s32 *lo, s32 *hi) {
    Unk_801E1158 *q = &D_801E1158;
    s32 sp38[4];
    s32 sp48;
    s32 i;
    GsSetLsMatrix(D_801E032C[0]->unk1C);
    for (i = 0; i < 4; i++) {
        RotTrans(&q->unk2C[i], sp38, &sp48);
        sp38[0] -= o->unk54;
        sp38[2] -= o->unk5C;
        if (sp38[0] >= lo[0] && sp38[0] < hi[0] && sp38[2] >= lo[2] && sp38[2] < hi[2]) {
            return 1;
        }
    }
    return 0;
}

static inline s16 func_8017A108_2(s32 dir, s32 *lo, s32 *hi) {
    switch (dir) {
    case 2:
        if (hi[2] >= 0) {
            break;
        }
        return 0;
    case 0:
        if (hi[0] >= 0) {
            break;
        }
        return 0;
    case 6:
        if (lo[2] > 0) {
            return 0;
        }
        break;
    case 4:
        if (lo[0] > 0) {
            return 0;
        }
        break;
    case 1:
        if (lo[0] >= 0 || lo[2] >= 0) {
            break;
        }
        return 0;
    case 3:
        if (hi[0] <= 0 || lo[2] >= 0) {
            break;
        }
        return 0;
    case 5:
        if (hi[0] <= 0 || hi[2] <= 0) {
            break;
        }
        return 0;
    case 7:
        if (lo[0] >= 0 || hi[2] <= 0) {
            break;
        }
        return 0;
    }
    return 1;
}

void func_8017A108(u16 arg0) {
    Unk_801DFE5C *list = D_801DFE5C;
    Unk_801E076C *o = D_801E076C[0];
    Unk_8017CCE4 *e;
    s32 sp18[4];
    s32 sp28[4];

    if (list->unkC == 0) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        e = list->unk8->unk8;
        if (e != NULL && e->unk0 != 0) {
            e->unk8 = 0;
            e->unk6 = func_80179E50(o, arg0, e, sp18, sp28);
            if (e->unk6 != 0) {
                e->unk4 = 1;
            } else if (arg0 == 2) {
                if (o->unk46 == 1 && func_8017A108_1(o, sp18, sp28) && e->unk6 == 0) {
                    e->unk6 = 1;
                    e->unk4 = 1;
                } else {
                    e->unk4 = func_8017A108_2((s16)func_8018C0A0(o->unk6E), sp18, sp28);
                }
            }
        }
        if (func_801CD000(list) != 0) {
            return;
        }
        list->unk8 = list->unk8->unk4;
    }
}

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

void func_8017A86C(u16 arg0) {
    s32 sp10[4];
    Unk_801E0340 *g = &D_801E0340;
    Unk_801E076C *o = D_801E076C[0];
    Unk_801E0368 *p;

    if (arg0 == 2) {
        if (func_801D67E0() != 0) {
            func_801CD54C(4, D_801702B0, D_801DFC84, 0x2EC);
        }
        while (func_801D3B7C() == 0) {
            func_801D1F70();
        }
        while (func_801D6850() == 0) {
            func_801D4FA0(o->unk68, o->unk60);
            if (func_801D1F70() != 0) {
                func_801D6A04();
            }
        }
        func_8017A6E8(o->unk60, o->unk68);
    } else {
        if (func_801D6894(g->unk16, g->unk20) != 0) {
            func_801CD54C(4, D_801702C8, D_801DFC84, 0x2F8);
        }
        while (func_801D3C50() == 0) {
            func_801D1F70();
        }
        D_801DFE58 = g->unk18;
        func_801D6940(D_801DFE58, sp10, &D_801DFC8C);
        p = &D_801E0368;
        p->unk252 = 0;
        p->unk250 = 0;
        switch (D_801DFC8D[0]) {
        case 1:
            p->unk252 = 1;
            break;
        case 2:
            p->unk250 = 1;
            break;
        case 3:
            p->unk252 = 1;
            p->unk250 = 1;
            break;
        }
        o->unk54 = sp10[0];
        o->unk58 = sp10[1];
        o->unk5C = sp10[2];
        func_80197370(1);
        while (func_801D6E1C() == 0) {
            func_801D5934(D_801DFE58, &D_801DFC8C);
            if (func_801D1F70() != 0) {
                func_801D6A2C();
            }
        }
    }
    func_8017A534(arg0);
    func_80184698();
    func_801A6EB4();
    D_801DFC80 = 0;
}

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

s16 func_8017AC88(Unk_8017AC88 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    double sp10[2];
    double x0;
    double z0;
    double x1;
    double z1;
    double px;
    double pz;
    double t;
    s32 i;
    s32 j;
    s32 n;

    px = arg2;
    pz = arg3;
    n = 0;
    for (i = 0; i < arg1; i++) {
        j = (i + 1) % arg1;
        x0 = arg0[i].unk0;
        z0 = arg0[i].unk8;
        x1 = arg0[j].unk0;
        z1 = arg0[j].unk8;
        if (func_801BDC30(z0, z1)) {
            t = (pz - z0) / (z1 - z0);
            if (!(t < 0.0) && !(t > 1.0)) {
                sp10[n] = (x1 - x0) * t + x0;
                if (n != 1 || func_801BDC30(sp10[0], sp10[1])) {
                    if (px < sp10[n]) {
                        n++;
                    }
                    if (n == 2) {
                        break;
                    }
                }
            }
        }
    }
    return n % 2;
}

s32 func_8017AF18(Unk_8017AC88 *arg0, Unk_8017AF18 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 maxx;
    s32 minx;
    s32 maxz;
    s32 minz;

    if (arg2 == 4) {
        if (arg0[0].unk0 > arg0[1].unk0) {
            maxx = arg0[0].unk0;
            minx = arg0[1].unk0;
        } else {
            minx = arg0[0].unk0;
            maxx = arg0[1].unk0;
        }
        if (maxx < arg0[2].unk0) {
            maxx = arg0[2].unk0;
        } else if (arg0[2].unk0 < minx) {
            minx = arg0[2].unk0;
        }
        if (maxx < arg0[3].unk0) {
            maxx = arg0[3].unk0;
        } else if (arg0[3].unk0 < minx) {
            minx = arg0[3].unk0;
        }
        if (arg0[0].unk8 > arg0[1].unk8) {
            maxz = arg0[0].unk8;
            minz = arg0[1].unk8;
        } else {
            minz = arg0[0].unk8;
            maxz = arg0[1].unk8;
        }
        if (maxz < arg0[2].unk8) {
            maxz = arg0[2].unk8;
        } else if (arg0[2].unk8 < minz) {
            minz = arg0[2].unk8;
        }
        if (maxz < arg0[3].unk8) {
            maxz = arg0[3].unk8;
        } else if (arg0[3].unk8 < minz) {
            minz = arg0[3].unk8;
        }
    } else {
        if (arg0[0].unk0 > arg0[1].unk0) {
            maxx = arg0[0].unk0;
            minx = arg0[1].unk0;
        } else {
            minx = arg0[0].unk0;
            maxx = arg0[1].unk0;
        }
        if (maxx < arg0[2].unk0) {
            maxx = arg0[2].unk0;
        } else if (arg0[2].unk0 < minx) {
            minx = arg0[2].unk0;
        }
        if (arg0[0].unk8 > arg0[1].unk8) {
            maxz = arg0[0].unk8;
            minz = arg0[1].unk8;
        } else {
            minz = arg0[0].unk8;
            maxz = arg0[1].unk8;
        }
        if (maxz < arg0[2].unk8) {
            maxz = arg0[2].unk8;
        } else if (arg0[2].unk8 < minz) {
            minz = arg0[2].unk8;
        }
    }
    if (arg3 < minx || maxx < arg3 || arg4 < minz || maxz < arg4) {
        return 99999999;
    }
    if (func_8017AC88(arg0, arg2, arg3, arg4) == 0) {
        return 99999999;
    }
    if (arg1->unk2 == 0) {
        return 99999999;
    }
    return (arg0[2].unk0 * arg1->unk0 + arg0[2].unk4 * arg1->unk2 + arg0[2].unk8 * arg1->unk4
            - (arg1->unk0 * arg3 + arg1->unk4 * arg4)) / arg1->unk2;
}

s32 func_8017B1E8(Unk_8017B1E8 *arg0, s32 arg1, s32 arg2, Unk_8017B3E8 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    Unk_8017AC88 sp18[3];
    s32 i;
    Unk_8017B1E8 *e;
    s32 r;

    e = arg0;
    for (i = 0; i < arg4; i++, e++) {
        sp18[0].unk0 = ((Unk_8017AF18 *)arg1)[e->unkA].unk0 + arg3->unk0;
        sp18[0].unk4 = ((Unk_8017AF18 *)arg1)[e->unkA].unk2 + arg3->unk4;
        sp18[0].unk8 = ((Unk_8017AF18 *)arg1)[e->unkA].unk4 + arg3->unk8;
        sp18[1].unk0 = ((Unk_8017AF18 *)arg1)[e->unkC].unk0 + arg3->unk0;
        sp18[1].unk4 = ((Unk_8017AF18 *)arg1)[e->unkC].unk2 + arg3->unk4;
        sp18[1].unk8 = ((Unk_8017AF18 *)arg1)[e->unkC].unk4 + arg3->unk8;
        sp18[2].unk0 = ((Unk_8017AF18 *)arg1)[e->unkE].unk0 + arg3->unk0;
        sp18[2].unk4 = ((Unk_8017AF18 *)arg1)[e->unkE].unk2 + arg3->unk4;
        sp18[2].unk8 = ((Unk_8017AF18 *)arg1)[e->unkE].unk4 + arg3->unk8;
        r = func_8017AF18(sp18, (Unk_8017AF18 *)arg2 + e->unk8, 3, arg5, arg6);
        *(s32 *)arg7 = r;
        if (r != 99999999) {
            return (e->unk4 << 16) | (e->unk5 << 8) | e->unk6;
        }
    }
    return 0;
}

s32 func_8017B3E8(Unk_8017B1E8 *arg0, s32 arg1, s32 arg2, Unk_8017B3E8 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    Unk_8017AC88 sp18[4];
    struct {
        u16 unk0;
        u8 unk2;
        u8 unk3;
        u8 unk4;
        u8 unk5;
        u8 unk6;
        u8 pad7[0x1];
        u16 unk8;
        u16 unkA;
        u16 unkC;
        u16 unkE;
        u16 unk10;
        u8 pad12[0x2];
    } *e;
    s32 i;
    s32 r;
    s32 ret;
    s32 minx;
    s32 maxx;
    s32 minz;
    s32 maxz;
    Unk_801E076C *m;
    Unk_8017AC88 *p;

    e = (void *)arg0;
    for (i = 0; i < arg4; i++, e++) {
        sp18[0].unk0 = ((Unk_8017AF18 *)arg1)[e->unkA].unk0 + arg3->unk0;
        sp18[0].unk4 = ((Unk_8017AF18 *)arg1)[e->unkA].unk2 + arg3->unk4;
        sp18[0].unk8 = ((Unk_8017AF18 *)arg1)[e->unkA].unk4 + arg3->unk8;
        sp18[1].unk0 = ((Unk_8017AF18 *)arg1)[e->unkC].unk0 + arg3->unk0;
        sp18[1].unk4 = ((Unk_8017AF18 *)arg1)[e->unkC].unk2 + arg3->unk4;
        sp18[1].unk8 = ((Unk_8017AF18 *)arg1)[e->unkC].unk4 + arg3->unk8;
        sp18[3].unk0 = ((Unk_8017AF18 *)arg1)[e->unkE].unk0 + arg3->unk0;
        sp18[3].unk4 = ((Unk_8017AF18 *)arg1)[e->unkE].unk2 + arg3->unk4;
        sp18[3].unk8 = ((Unk_8017AF18 *)arg1)[e->unkE].unk4 + arg3->unk8;
        sp18[2].unk0 = ((Unk_8017AF18 *)arg1)[e->unk10].unk0 + arg3->unk0;
        sp18[2].unk4 = ((Unk_8017AF18 *)arg1)[e->unk10].unk2 + arg3->unk4;
        sp18[2].unk8 = ((Unk_8017AF18 *)arg1)[e->unk10].unk4 + arg3->unk8;
        r = func_8017AF18(sp18, (Unk_8017AF18 *)arg2 + e->unk8, 4, arg5, arg6);
        *(s32 *)arg7 = r;
        if (r != 99999999) {
            ret = (e->unk4 << 16) | (e->unk5 << 8) | e->unk6;
            if (e->unk4 == 0xFF) {
                m = D_801E076C[0];
                p = m->unk18;
                if (sp18[0].unk0 > sp18[1].unk0) {
                    maxx = sp18[0].unk0;
                    minx = sp18[1].unk0;
                } else {
                    minx = sp18[0].unk0;
                    maxx = sp18[1].unk0;
                }
                if (maxx < sp18[2].unk0) {
                    maxx = sp18[2].unk0;
                } else if (sp18[2].unk0 < minx) {
                    minx = sp18[2].unk0;
                }
                if (maxx < sp18[3].unk0) {
                    maxx = sp18[3].unk0;
                } else if (sp18[3].unk0 < minx) {
                    minx = sp18[3].unk0;
                }
                if (sp18[0].unk8 > sp18[1].unk8) {
                    maxz = sp18[0].unk8;
                    minz = sp18[1].unk8;
                } else {
                    minz = sp18[0].unk8;
                    maxz = sp18[1].unk8;
                }
                if (maxz < sp18[2].unk8) {
                    maxz = sp18[2].unk8;
                } else if (sp18[2].unk8 < minz) {
                    minz = sp18[2].unk8;
                }
                if (maxz < sp18[3].unk8) {
                    maxz = sp18[3].unk8;
                } else if (sp18[3].unk8 < minz) {
                    minz = sp18[3].unk8;
                }
                p[1].unk0 = m->unk72 * 12500 + ((minx + maxx) >> 1);
                p[1].unk8 = m->unk76 * 12500 + ((minz + maxz) >> 1);
            }
            return ret;
        }
    }
    return 0;
}

s16 func_8017B7CC(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    Unk_8017AC88 sp18[4];
    s32 flag;
    Unk_8017BBB0 *q;
    struct {
        u16 unk0;
        u8 unk2;
        u8 unk3;
        u8 unk4;
        u8 unk5;
        u8 unk6;
        u8 pad7[0x1];
        u16 unk8;
        u16 unkA;
        u16 unkC;
        u16 unkE;
        u16 unk10;
        u8 pad12[0x2];
    } *e;
    Unk_801E076C *m;
    Unk_8017AF18 *v;
    Unk_8017AF18 *b;
    s32 n;
    s32 cnt;
    s32 i;
    s32 min;
    s32 max;

    q = arg0;
    e = (void *)q->unk8->unk10;
    n = q->unk8->unk14;
    m = D_801E076C[0];
    v = (Unk_8017AF18 *)q->unk8->unk0;
    b = (Unk_8017AF18 *)q->unk8->unk8;
    while (n != 0) {
        cnt = e->unk0;
        if ((e->unk3 & 0xFD) == 0x20) {
            for (i = 0; i < cnt; e = (void *)((Unk_8017B1E8 *)e + 1), i++) {
                RotTrans(&v[e->unkA], &sp18[0].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&v[e->unkC], &sp18[1].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&v[e->unkE], &sp18[2].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                if (func_8017AF18(sp18, &b[e->unk8], 3, arg1, arg3) != 99999999) {
                    if (arg4 != 1) {
                        return 1;
                    }
                    if (sp18[0].unk4 > sp18[1].unk4) {
                        max = sp18[0].unk4;
                        min = sp18[1].unk4;
                    } else {
                        min = sp18[0].unk4;
                        max = sp18[1].unk4;
                    }
                    if (max < sp18[2].unk4) {
                        max = sp18[2].unk4;
                    } else if (sp18[2].unk4 < min) {
                        min = sp18[2].unk4;
                    }
                    if (min == max) {
                        if (arg2 >= max + m->unk78 && arg2 <= max - m->unk78) {
                            return 1;
                        }
                    } else if (arg2 >= min && arg2 <= max) {
                        return 1;
                    }
                }
            }
            n -= cnt;
        } else if ((e->unk3 & 0xFD) == 0x28) {
            for (i = 0; i < cnt; e++, i++) {
                RotTrans(&v[e->unkA], &sp18[0].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&v[e->unkC], &sp18[1].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&v[e->unkE], &sp18[3].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&v[e->unk10], &sp18[2].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                if (func_8017AF18(sp18, &b[e->unk8], 4, arg1, arg3) != 99999999) {
                    if (arg4 != 1) {
                        return 1;
                    }
                    if (sp18[0].unk4 > sp18[1].unk4) {
                        max = sp18[0].unk4;
                        min = sp18[1].unk4;
                    } else {
                        min = sp18[0].unk4;
                        max = sp18[1].unk4;
                    }
                    if (max < sp18[2].unk4) {
                        max = sp18[2].unk4;
                    } else if (sp18[2].unk4 < min) {
                        min = sp18[2].unk4;
                    }
                    if (max < sp18[3].unk4) {
                        max = sp18[3].unk4;
                    } else if (sp18[3].unk4 < min) {
                        min = sp18[3].unk4;
                    }
                    if (min == max) {
                        if (arg2 >= max + m->unk78 && arg2 <= max - m->unk78) {
                            return 1;
                        }
                    } else if (arg2 >= min && arg2 <= max) {
                        return 1;
                    }
                }
            }
            n -= cnt;
        } else {
            return 0;
        }
    }
    return 0;
}

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

s32 func_8017BD24(s32 arg0, s32 arg1, s32 *arg2, s16 arg3) {
    Unk_801DFE5C *p = D_801DFE5C;
    Unk_8017B3E8 sp20;
    Unk_8017B1E8 *e;
    s32 n;
    s32 a;
    s32 b;
    s32 cnt;
    s32 r;
    s32 t;
    s32 f;
    Unk_8017BBB0 *q;

    if (p->unkC == 0) {
        return 0;
    }
    *arg2 = 0;
    f = arg3;
    p->unk8 = p->unk0;
    while (1) {
        Unk_8017CCE4 *o = p->unk8->unk8;
        if (o != NULL && o->unk0 != 0 && (o->unkE & 1) && (f != 0 || o->unk6 != 0)) {
            q = o->unk84;
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
                    t = func_8017B1E8(e, a, b, &sp20, cnt, arg0, arg1, (s32)arg2);
                    if (t != 0) {
                        r = t;
                        goto found;
                    }
                    n -= cnt;
                    e = (Unk_8017B1E8 *)((u8 *)e + cnt * 0x10);
                    break;
                case 0x28:
                    t = func_8017B3E8(e, a, b, &sp20, cnt, arg0, arg1, (s32)arg2);
                    if (t != 0) {
                        r = t;
                        goto found;
                    }
                    n -= cnt;
                    e = (Unk_8017B1E8 *)((u8 *)e + cnt * 0x14);
                    break;
                default:
                    r = 0;
                    goto found;
                }
            }
            r = 0;
        found:
            if (r != 0) {
                return r;
            }
        }
        if (func_801CD000(p) != 0) {
            return 0;
        }
        p->unk8 = p->unk8->unk4;
    }
}

s32 func_8017BF50(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    Unk_801DFE5C *p = D_801DFE5C;
    Unk_8017B3E8 hits[12];
    Unk_8017B3E8 sp20;
    s32 h;
    s32 *hp;
    Unk_8017B1E8 *e;
    s32 n;
    s32 a;
    s32 b;
    s32 cnt;
    s32 r;
    s32 t;
    s32 k;
    s32 i;
    s32 best;
    Unk_8017BBB0 *q;

    if (p->unkC == 0) {
        return 0;
    }
    *arg3 = 0;
    k = 0;
    p->unk8 = p->unk0;
    while (1) {
        Unk_8017CCE4 *o = p->unk8->unk8;
        if (o != NULL && o->unk0 != 0 && o->unk6 != 0 && (o->unkE & 1)) {
            q = o->unk84;
            sp20.unk0 = q->unk4->unk18;
            sp20.unk4 = q->unk4->unk1C;
            sp20.unk8 = q->unk4->unk20;
            e = q->unk8->unk10;
            n = q->unk8->unk14;
            a = q->unk8->unk0;
            b = q->unk8->unk8;
            hp = &h;
            while (n != 0) {
                cnt = e->unk0;
                switch (e->unk3 & 0xFD) {
                case 0x20:
                    t = func_8017B1E8(e, a, b, &sp20, cnt, arg0, arg2, (s32)hp);
                    if (t != 0) {
                        r = t;
                        goto found;
                    }
                    n -= cnt;
                    e = (Unk_8017B1E8 *)((u8 *)e + cnt * 0x10);
                    break;
                case 0x28:
                    t = func_8017B3E8(e, a, b, &sp20, cnt, arg0, arg2, (s32)hp);
                    if (t != 0) {
                        r = t;
                        goto found;
                    }
                    n -= cnt;
                    e = (Unk_8017B1E8 *)((u8 *)e + cnt * 0x14);
                    break;
                default:
                    r = 0;
                    goto found;
                }
            }
            r = 0;
        found:
            if (r != 0) {
                hits[k].unk0 = r;
                hits[k].unk4 = h;
                hits[k].unk8 = abs(arg1 - h);
                k++;
            }
        }
        if (func_801CD000(p) != 0) {
            break;
        }
        p->unk8 = p->unk8->unk4;
    }
    if (k == 0) {
        return 0;
    }
    if (k == 1) {
        *arg3 = hits[0].unk4;
        return hits[0].unk0;
    }
    if (k != 0) {
        best = 1600;
        for (i = 0; i < k; i++) {
            if (hits[i].unk8 < best) {
                r = hits[i].unk0;
                *arg3 = hits[i].unk4;
                best = hits[i].unk8;
            }
        }
        return r;
    }
    return 0;
}

static inline s32 func_8017C234_inl(Unk_8017BBB0 *q, Unk_8017B3E8 *sp, s32 x, s32 z, s32 w) {
    Unk_8017B1E8 *e;
    s32 n;
    s32 a;
    s32 b;
    s32 cnt;
    s32 t;
    sp->unk0 = q->unk4->unk18;
    sp->unk4 = q->unk4->unk1C;
    sp->unk8 = q->unk4->unk20;
    e = q->unk8->unk10;
    n = q->unk8->unk14;
    a = q->unk8->unk0;
    b = q->unk8->unk8;
    while (n != 0) {
        cnt = e->unk0;
        switch (e->unk3 & 0xFD) {
        case 0x20:
            t = func_8017B1E8(e, a, b, sp, cnt, x, z, w);
            if (t != 0) {
                return t;
            }
            n -= cnt;
            e = (Unk_8017B1E8 *)((u8 *)e + cnt * 0x10);
            break;
        case 0x28:
            t = func_8017B3E8(e, a, b, sp, cnt, x, z, w);
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

s32 func_8017C234(s32 *arg0, s16 arg1) {
    Unk_8017AC88 sp20[4];
    Unk_8017AC88 sp60;
    Unk_8017AF18 sp70;
    s32 res[5];
    Unk_8017B3E8 sp90;
    s32 flag;
    Unk_801DFE5C *p = D_801DFE5C;
    Unk_801E032C *m = D_801E032C[0];
    Unk_801E1158 *g = &D_801E1158;
    Unk_8017BBB0 *q;
    Unk_8017CCE4 *o;
    s32 i;
    s16 c1;
    s16 c2;
    s32 dx1;
    s32 dx2;
    s32 dz1;
    s32 dz2;
    s32 sn;
    s32 cs;
    s32 ax;
    s32 az;

    if (p->unkC == 0) {
        return 0;
    }
    GsSetLsMatrix(&m->unk1C);
    for (i = 0; i < 4; i++) {
        res[i] = 0;
        RotTrans(&g->unk2C[i], &sp20[i].unk0, &flag);
        if (flag >= 0) {
            p->unk8 = p->unk0;
            while (1) {
                o = p->unk8->unk8;
                if (o != NULL && o->unk0 != 0 && (q = o->unk84) != NULL && (arg1 != 0 || o->unk6 != 0)) {
                    res[i] = func_8017C234_inl(q, &sp90, sp20[i].unk0, sp20[i].unk8, (s32)&sp20[i].unk4);
                    if (res[i] != 0) {
                        break;
                    }
                }
                if (func_801CD000(p) != 0) {
                    break;
                }
                p->unk8 = p->unk8->unk4;
            }
        }
    }
    if (res[0] == 0 || res[1] == 0 || res[2] == 0 || res[3] == 0) {
        return 0;
    }
    c2 = c1 = 0;
    for (i = 0; i < 4; i++) {
        switch (res[i]) {
        case 0xFFFF:
            c1++;
            break;
        case 0xFF00:
            if (g->unk2 == 0) {
                g->unk2 = 1;
            }
            break;
        default:
            continue;
        }
        c2++;
    }
    if (c1 == 4 && g->unk2 != 0) {
        g->unk2 = 0;
        g->unkC /= 4;
        g->unk8 /= 4;
    }
    if (c2 == 0) {
        return 0;
    }
    p->unk8 = p->unk0;
    sp70.unk0 = 0;
    sp70.unk2 = 0;
    sp70.unk4 = 0;
    RotTrans(&sp70, &sp60.unk0, &flag);
    if (flag < 0) {
        return 0;
    }
    while (1) {
        o = p->unk8->unk8;
        if (o != NULL && o->unk0 != 0 && (q = o->unk84) != NULL && (arg1 != 0 || o->unk6 != 0)) {
            res[4] = func_8017C234_inl(q, &sp90, sp60.unk0, sp60.unk8, (s32)arg0);
            if (res[4] != 0) {
                m->unk14 = 0;
                m->unk10 = 0;
                dx1 = sp20[1].unk4 - sp20[0].unk4;
                dx2 = sp20[3].unk4 - sp20[2].unk4;
                dz1 = sp20[2].unk4 - sp20[0].unk4;
                dz2 = sp20[3].unk4 - sp20[1].unk4;
                if (dx1 != 0 || dx2 != 0 || dz1 != 0 || dz2 != 0) {
                    sn = rsin((m->unk12 << 12) / 360);
                    cs = rcos((m->unk12 << 12) / 360);
                    ax = 0;
                    az = 0;
                    if (dx1 != 0) {
                        ax = ratan2(dx1, 300);
                    }
                    if (abs(dz1) >= abs(dz2)) {
                        if (dz1 != 0) {
                            az = ratan2(dz1, 508);
                        }
                    } else if (dz2 != 0) {
                        az = ratan2(dz2, 508);
                    }
                    {
                        s32 t0 = ax * cs;
                        s32 t1 = ax * sn;
                        s32 t2 = az * cs;
                        s32 t3 = az * sn;
                        m->unk10 = ((t1 + t2) >> 12) * 45 >> 9;
                        m->unk14 = ((t0 - t3) >> 12) * 45 >> 9;
                    }
                }
                *arg0 += 370;
                return res[4];
            }
        }
        if (func_801CD000(p) != 0) {
            break;
        }
        p->unk8 = p->unk8->unk4;
    }
    return 0;
}

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
            func_801CD54C(3, "Error Allocating Arena Buffer", D_801DFC84, 0x49);
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

s32 func_8017D604(Unk_8017E504 *arg0) {
    Unk_801E0368 *a = &D_801E0368;
    Unk_801E0340 *b = &D_801E0340;
    Unk_801E076C *m = D_801E076C[0];
    Unk_801E1118 *c = &D_801E1118;
    Unk_801E1058 *d = D_801E1058;
    Unk_801DFFE8 *e = &D_801DFFE8;
    s32 k = arg0->unk10;
    s16 r;
    void *p;
    u16 f;

    if (k == 0) {
        switch (D_801DFE68.unk0) {
        case 7:
            break;
        case 5:
            func_801A3BCC(0);
            break;
        default:
            func_801A3BCC(1);
            break;
        }
        if (D_801DFE68.unk0 == 1 || D_801DFE68.unk0 == 2) {
            func_801A2678(0x1D);
        } else {
            func_801A2C60(10, 0x29, 0, 0x3C, 0x7F, 0x7F, 1);
        }
    } else if (k == 7) {
        if (arg0->unkC == 0) {
            a->unk244 = -1;
        }
        if (c->unkE == 3) {
            c->unkE = 1;
            func_801A5650(1);
        } else if (c->unkE == 2) {
            c->unkE = 0;
            c->unk12 = 1;
            func_801A80CC(2, 0, 1);
        }
    } else if (k == 11) {
        if (!(m->unk42 & 0x4000)) {
            func_80183E88(*d->unk1C, 3, -1, 0, -1, 0, 1);
        }
    } else if (k == 12) {
        if (!(m->unk42 & 0x4000)) {
            r = func_801A0EDC(D_801DFE68.unk0);
            if (D_801DFE68.unk0 == 8 && D_801DFF78 >= 0) {
                if (r >= 0) {
                    p = func_80174CB8(r);
                    if (p != NULL) {
                        e->unk4 = 0;
                        e->unk0 = 0;
                        e->unkE = -1;
                        e->unkA = -1;
                        e->unkC = 0;
                        e->unk8 = 0;
                        e->unk6 = 1;
                        do {
                            p = func_80173DE0(p, 0, 0);
                        } while (p != NULL);
                    }
                } else {
                    func_801A1AB8(D_801DFE68.unk0, 0);
                }
            }
        }
    } else if (k == 4) {
        f = m->unk42;
        if (f & 0x80) {
            m->unk42 = f & ~4;
            b->unkA = 1;
        } else if (f & 0x20) {
            /*  横になると、深い眠りについた */
            func_80183E88(" \211\241\202\311\202\310\202\351\202\306\201\101\220\133\202\242\226\260\202\350\202\311\202\302\202\242\202\275", 1, -1, 0, -1, 0, 0);
            func_80186128(10, 3);
        } else if (f & 8) {
            if (D_801DFE68.unk0 == 9) {
                /*  6目を閉じて・・・ */
                func_80183E88(" 6\226\332\202\360\225\302\202\266\202\304\201\105\201\105\201\105", 1, -1, 0, -1, 0, 0);
            } else {
                /*  意識が遠ざかっていく */
                func_80183E88(" \210\323\216\257\202\252\211\223\202\264\202\251\202\301\202\304\202\242\202\255", 1, -1, 0, -1, 0, 0);
            }
            func_80186128(10, 3);
        } else if ((D_801DFE68.unk0 == 3 || D_801DFE68.unk0 == 6) && d->unk8 != 0) {
            func_801A1AB8(D_801DFE68.unk0, 0);
        }
    } else if (k == 10) {
        if (arg0->unkC == 0) {
            a->unk244 = -1;
        }
        f = m->unk42;
        if (f & 0x20) {
            func_80199EB4(1, D_801D7450[D_801DFE64 * 3], D_801D7450[D_801DFE64 * 3 + 1], D_801D7450[D_801DFE64 * 3 + 2]);
            func_80184094();
        } else if (f & 8) {
            if (D_801DFE68.unk0 == 9) {
                func_80199370(500, 0, 0x3390, 0);
            } else {
                func_80199370(D_801D7450[D_801DFE64 * 3], D_801D7450[D_801DFE64 * 3 + 1], D_801D7450[D_801DFE64 * 3 + 2], 1);
            }
        }
        func_8018C1B0(1, 1, 1, 4);
        func_80186128(9, 3);
    } else if (k == 9) {
        if (arg0->unkC == 0) {
            a->unk244 = -1;
        }
        f = m->unk42;
        if (f & 0x20) {
            m->unk42 = f & ~0x20;
        } else if (f & 8) {
            m->unk42 = f & ~8;
        }
    } else if (k == 13) {
        if (D_801DFE68.unk0 == 0) {
            func_801A3BCC(1);
        }
    }
    return 0;
}

void func_8017DAE8(Unk_801E0710 *arg0) {
    Unk_801DFFE8 *q = &D_801DFFE8;
    Unk_801DFE68 *r;
    void *item;
    s16 m = q->unk6;

    if (m == 3) {
        func_80184100((Unk_80184100 *)q);
        return;
    }
    if (m != 2) {
        return;
    }
    D_801DFE60 = 0;
    if (!(q->unk8 & 8)) {
        return;
    }
    func_801A2678(0x11);
    func_80184094();
    switch (q->unk4) {
    case 0xFC:
        func_80183618(D_801DFFE8.unk0);
        break;
    case 0x10:
        switch (D_801DFFE8.unk0) {
        case 0x100010:
            func_801A5B10(1);
            break;
        case 0x100020:
            func_801A5B10(0);
            break;
        default:
            if ((q->unk0 & 0xFFFF00) == 0x104000) {
                D_801DFE60 = 1;
                func_80187560((u8)q->unk0);
                goto loop;
            }
            break;
        }
        break;
    case 0x60:
        if (D_801DFE68.unk0 == 2) {
            func_801A5CD4();
        } else if (D_801DFE68.unk0 >= 3 && D_801DFE68.unk0 < 8) {
            r = &D_801DFE68;
            func_801A1FD4(D_801DFE68.unk0, r->unk2);
        } else {
            goto loop;
        }
        break;
    case 0x30:
        if (D_801DFE68.unk0 != 3 && D_801DFE68.unk0 != 6) {
            func_801A1AB8(D_801DFE68.unk0, D_801DFFE8.unk0);
            break;
        }
    default:
        if (q->unk0 >= 0xF02150 && q->unk0 < 0xF02155) {
            if (arg0->unk36 < 6) {
                func_80183E88(" \202\275\202\301\202\325\202\350\202\306\201A\220\207\226\260\202\315\202\306\202\352\202\304\202\242\202\351", 1, -1, 0, -1, 0, 4);
                break;
            }
            D_801DFE64 = q->unk0 & 0xF;
        }
    loop:
        item = func_80174CB8(q->unkA);
        if (item != NULL) {
            while ((item = func_80173DE0(item, 0, 0)) != NULL) {
            }
        }
        break;
    }
    q->unk6 = 1;
    q->unk8 &= ~8;
}

void func_8017DD70(void) {
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E076C *o = p->unk5C;
    s32 t;

    if (D_801E6DA0.unkA != 1) {
        return;
    }
    if (*(u32 *)&o->unk40 & 0x2A0000) {
        return;
    }
    t = func_801CD6B4();
    if (D_801DFE68.unk0 < 3 && func_8018898C(p, 1) != 0) {
        return;
    }
    if (func_801A14A0(p) != 0) {
        return;
    }
    if (func_80187E38(p) != 0) {
        return;
    }
    if (o->unk42 & 4) {
        if (!(D_801E6DA0.unk4 & 0x20) && (D_801E6DA0.unk0 & 0x20)) {
            func_8017DAE8(p);
            return;
        }
        if (!(D_801E6DA0.unk4 & 0x40) && (D_801E6DA0.unk0 & 0x40)) {
            Unk_801DFFE8 *q = &D_801DFFE8;
            Unk_801E1058 *r = D_801E1058;
            void *item;

            if (q->unk6 == 2 && (q->unkC & 2)) {
                func_801A2678(8);
                func_80184094();
                if (q->unk4 == 0x30) {
                    switch (D_801DFE68.unk0) {
                    case 4:
                    case 5:
                        r->unk4 = 1;
                        func_801A1AB8(D_801DFE68.unk0, D_801DFFE8.unk0);
                        break;
                    }
                } else {
                    item = func_80174CB8(q->unkE);
                    if (item != NULL) {
                        func_801A2678(8);
                        while ((item = func_80173DE0(item, 0, 0)) != NULL) {
                        }
                    }
                }
                q->unk6 = 1;
                q->unkC &= ~2;
            }
            return;
        }
    }
    func_80199548(p, 1, t);
}

void func_8017DFA4(void) {
    char sp10[16];
    Unk_801E0340 *g = &D_801E0340;
    Unk_801DFE68 *p;

    func_80174840(1);
    D_801DFED4 = func_8017D604;
    p = &D_801DFE68;
    p->unk2 = g->unk12;
    D_801DFE62 = 0;
    D_801DFE68.unk0 = g->unk10;
    if (D_801DFE60 == 1) {
        return;
    }
    func_801A4A68(0x410, 1);
    func_8017A86C(1);
    memset(sp10, 0, 0x10);
    sprintf(sp10, "\\S\\%s.S;1", g->unk20);
    g->unkC = sp10;
    func_801926B4();
    func_80188CE4();
    switch (D_801DFE68.unk0) {
    case 0:
        switch (p->unk2) {
        case 4:
            func_801A8000(3, 8, 1);
            func_801A80CC(3, 8, 1);
            func_801A8000(3, 9, 1);
            func_801A80CC(3, 9, 1);
            break;
        case 22:
            func_8018F428(5, 1);
            func_801A8000(3, 6, 1);
            func_801A80CC(3, 6, 1);
            break;
        case 23:
            func_8018F428(2, 0);
            D_801DFEE4 = func_8017E504;
            break;
        case 28:
            func_801A8000(3, 5, 1);
            func_801A80CC(3, 5, 1);
            break;
        case 30:
            func_8018F428(1, 1);
            func_8018647C(0);
            break;
        case 7:
            func_8018F428(2, 0);
        case 9:
            func_8018647C(1);
            func_80186680();
            break;
        case 33:
            func_801A8000(0, 1, 1);
            func_8018647C(0);
        case 31:
        case 32:
        case 34:
            func_8018F428(1, 1);
            break;
        case 39:
            func_8018F428(3, 0);
        case 1:
        case 15:
            func_8018F428(2, 0);
            break;
        }
        break;
    case 1:
        D_801DFE62 = D_801DFE68.unk0;
    case 2:
        func_801A5C34();
        break;
    default:
        func_801A1EC0(p->unk0);
        break;
    }
    if (g->unk14 != 0) {
        func_801A2678(0x21);
    }
    func_8018AABC(D_801DFE62);
    func_801A4A68(0x410, 0);
}

void func_8017E25C(void) {
    s32 sp10[6];
    s16 done;

    func_8017DFA4();
    done = 0;
    func_801D06B4();
    if (D_801DFE60 == 0) {
        func_80186128(0, 3);
    } else {
        D_801DFE60 = 0;
        func_801CD688(1);
    }
    while (done == 0) {
        switch (func_801CC378(sp10)) {
        case 0x10:
            func_80189350(sp10);
            continue;
        case 0x400:
            func_801A20A8();
            continue;
        case 0x20:
            func_801895E0(sp10);
            continue;
        case 0x4:
            func_80189970(D_801DFE62);
            continue;
        case 0x200:
            func_801899AC(sp10);
            continue;
        case 0x0:
            func_8017DD70();
            if (func_8018C170() != 0) {
                if (D_801DFE60 == 0) {
                    func_80186128(1, 3);
                } else {
                    func_801CD688(0);
                    done = 1;
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
        func_8018C2FC(1, 1, 1);
    }
    func_801D06C4();
    D_801DFEE4 = 0;
    D_801DFEE0 = 0;
    D_801DFED4 = 0;
    D_801DFEDC = 0;
    func_80174840(1);
    func_80184094();
    if (D_801DFE60 != 1) {
        func_8017D3F0();
        func_801A3C58();
        func_801A252C();
        func_8018655C();
        func_80186718();
        func_80174FA8();
        func_801762A0();
        func_80176780();
        func_8017683C();
        func_80188DE8();
        func_80174BC8();
        func_8017D1BC();
        func_80185548();
        func_8018E47C();
        func_801A7BA4();
        func_801A3B5C();
        func_801A23B4();
        func_801A43F4(2);
        func_801A43F4(3);
        func_801A43F4(4);
    }
}

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

void func_8017E594(s16 arg0, s16 arg1, s16 *arg2) {
    s32 snd;
    s16 played;
    s32 i;
    s32 idx;

    if (D_801E6DA0.unkA == 1) {
        played = 0;
        func_801CD6B4();
        if (!(D_801E6DA0.unk4 & 0x20) && (D_801E6DA0.unk0 & 0x20)) {
            played = 1;
            snd = 0x18;
            if (*arg2 == arg1) {
                snd = 0x11;
            }
            idx = (arg0 * 11 + *arg2 - 12) * 3;
            func_8018C50C(D_801D74B0[idx] * 10, 0, D_801D74B0[idx + 1] * 10, D_801D74B0[idx + 2], 0);
        } else if (!(D_801E6DA0.unk4 & 0x40) && (D_801E6DA0.unk0 & 0x40)) {
            played = 1;
            snd = 8;
            *arg2 = arg1;
            idx = (arg0 * 11 + arg1 - 12) * 3;
            func_8018C50C(D_801D74B0[idx] * 10, 0, D_801D74B0[idx + 1] * 10, D_801D74B0[idx + 2], 0);
        } else if (!(D_801E6DA0.unk4 & 0x1000) && (D_801E6DA0.unk0 & 0x1000)) {
            played = 1;
            snd = 0xF;
            (*arg2)--;
            if (arg0 != 3) {
                if (*arg2 >= 12) {
                    *arg2 = 1;
                }
                if (*arg2 <= 0) {
                    *arg2 = 11;
                }
            } else {
                if (*arg2 >= 6) {
                    *arg2 = 1;
                }
                if (*arg2 <= 0) {
                    *arg2 = 5;
                }
            }
            for (i = 1; i < 12; i++) {
                func_801A461C(0, (arg0 << 4) + i, 0x5BBD);
                func_801A461C(0, i, 0x1D40);
            }
            func_801A461C(0, (arg0 << 4) + *arg2, 0x29F);
            func_801A461C(0, *arg2, 0x1D5F);
        } else if (!(D_801E6DA0.unk4 & 0x4000) && (D_801E6DA0.unk0 & 0x4000)) {
            played = 1;
            snd = 0xF;
            (*arg2)++;
            if (arg0 != 3) {
                if (*arg2 >= 12) {
                    *arg2 = 1;
                }
                if (*arg2 <= 0) {
                    *arg2 = 11;
                }
            } else {
                if (*arg2 >= 6) {
                    *arg2 = 1;
                }
                if (*arg2 <= 0) {
                    *arg2 = 5;
                }
            }
            for (i = 1; i < 12; i++) {
                func_801A461C(0, (arg0 << 4) + i, 0x5BBD);
                func_801A461C(0, i, 0x1D40);
            }
            func_801A461C(0, (arg0 << 4) + *arg2, 0x29F);
            func_801A461C(0, *arg2, 0x1D5F);
        }
        if (played) {
            func_801A2678(snd);
        }
    }
}

void func_8017E99C(s16 arg0, s16 arg1) {
    s32 sp10[6];
    s16 sp28;
    s16 done;
    s32 i;
    s32 d;
    s16 v;

    done = 0;
    sp28 = arg1;
    D_801DFED4 = 0;
    func_801A4A68(0x400, 0);
    func_801A4A68(0x409, 0);
    func_801A4A68(0x40E, 0);
    func_801A4A68(0, 1);
    func_801A4A68((u16)arg0, 1);
    func_801A461C(0, (arg0 << 4) + arg1, 0x29F);
    func_801A461C(0, arg1, 0x1D5F);
    func_8018C1B0(3, 0, 0, 2);
    func_801CD688(1);
    func_801D06B4();
    do {
        switch (func_801CC378(sp10)) {
        case 0x4:
            func_80189970(1);
            continue;
        case 0x0:
            func_8017E594(arg0, arg1, &sp28);
            if (func_8018C170() != 0) {
                func_80186128(1, 3);
            }
            break;
        case 0x100:
            done = func_8018970C(sp10);
            continue;
        default:
            func_801CC734(sp10);
            continue;
        }
        func_801A0418(2);
    } while (done == 0);
    func_801D06C4();
    v = sp28;
    for (i = 1; i < 12; i++) {
        func_801A461C(0, (arg0 << 4) + i, 0x5BBD);
        func_801A461C(0, i, 0x1D40);
    }
    func_801A4A68(0x400, 1);
    func_801A4A68(0x409, 1);
    func_801A4A68(0x40E, 1);
    func_801A4A68(0, 0);
    func_801A4A68((u16)arg0, 0);
    d = v - arg1;
    func_8018ABE8((d < 0 ? -d : d) * 5, 0);
}
