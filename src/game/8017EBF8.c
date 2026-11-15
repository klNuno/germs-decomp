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
extern s16 D_801E71C8;
typedef struct {
    s16 unk0[0x5F];
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
    u8 unk0[0x20];
} Unk_801D75F4;
typedef struct {
    s16 unk0;
    u8 pad2[0x2];
    char unk4[0x14];
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C[0x40];
    u8 unk5C[0x1C];
    Unk_801D75F4 unk78;
} Unk_801802A0_14;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 padA[0x2];
    s32 unkC;
    u32 unk10;
    Unk_801802A0_14 unk14[4];
} Unk_801802A0;
void func_801A4824(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Unk_80184230;
typedef struct {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x6];
    s16 unkC;
    u8 padE[0xA];
    s16 unk18;
    s16 unk1A;
    Unk_80184230 *unk1C;
} Unk_801A44B8;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    Unk_801A44B8 *unk8;
    Unk_801A44B8 *unkC;
} Unk_80181C10;
void func_801A43F4(s32 arg0);
void func_8018B924(void);
void func_8018BC50(void);
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
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 pad10[0x2];
    u16 unk12;
} Unk_801DFFE8;
typedef struct {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    u8 pad8[0x2];
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
void func_8017EBF8(Unk_801802A0 *arg0, s32 arg1);
void func_801A4BC8(s32 arg0, s32 arg1, s32 arg2);
s32 MemCardSync(s32 arg0, s32 *arg1, s32 *arg2);
void MemCardExist(s32 arg0);
s32 MemCardFormat(s32 arg0);
void MemCardAccept(s32 arg0);
void func_8017EE2C(Unk_801802A0 *arg0, s32 arg1);
s32 func_8017EFEC(Unk_801802A0 *arg0);
s32 func_8017F6F4(Unk_801802A0 *arg0, s32 arg1);
s32 func_8017FF0C(Unk_801802A0 *arg0);
extern Unk_801D75F4 D_801D75F4;
s32 LoadImage2(void *rect, void *p);
int sprintf(char *buf, const char *fmt, ...);
extern Unk_801802A0 D_801E0030;
void func_8018073C(Unk_801802A0 *arg0);
s16 func_801803BC(Unk_801802A0 *arg0);
s32 func_8018C170(void);
s16 func_8018970C(s32 *arg0);
s32 func_801CC378(s32 *arg0);
void func_801CC734(s32 *arg0);
void func_801CD688(s32 a);
void func_801D06B4(void);
void func_801D06C4(void);
void func_801A7560(void);
void func_801A0418(u16 a);
void MemCardStart(void);
void MemCardStop(void);
extern s16 D_801D7694[];
s32 MoveImage2(Unk_80184230 *rect, s32 x, s32 y);
Unk_801A44B8 *D_801DFC94;
s32 func_8018B69C(s16 a, s16 b);
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
void func_80181A64(Unk_80181C10 *arg0);
void func_80181C10(Unk_80181C10 *arg0);
void func_80181818(Unk_80181C10 *arg0, s16 arg1);
void func_8018C414(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 func_801CD6B4(void);
void func_8018B11C(s32 arg0);
void func_80181D2C(Unk_80181C10 *arg0);
void func_80181F9C(Unk_80181C10 *arg0);
void func_80189970(s16 a);
void func_801A3BCC(s32 arg0);
void func_801A3C58(void);
void func_80182518(s32 arg0, s16 arg1);
void func_8018C1B0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s16 D_801DFC80;
void func_80184814(Unk_80184814 *arg0);
void func_80184928(Unk_80184814 *arg0);
void func_80184A3C(Unk_80184814 *arg0);
void func_80184B50(Unk_80184814 *arg0);
void func_801802A0(Unk_801802A0 *arg0, s16 arg1);
extern s16 D_801E6DAA[];
u16 *Krom2RawAdd2(u16 sjis);
s32 StoreImage2(void *rect, void *p);
extern s32 D_801D76A4[];
void func_80182D34(char *arg0, s16 arg1);

void func_8017EBF8(Unk_801802A0 *arg0, s32 arg1) {
    Unk_80184230 rect;
    void *buf;
    Unk_801802A0_14 *p;
    s32 i;

    p = arg0->unk14;
    arg0->unk6 = 0;
    arg0->unk8 = -1;
    for (i = 0; i < 4; i++, p++) {
        memset(p->unk4, 0, 0x14);
        sprintf(p->unk4, "BISLPS-02107GERMS%d", i);
        p->unk0 = 0;
        p->unk18 = 'S';
        p->unk19 = 'C';
        p->unk1A = 0x11;
        p->unk1B = 1;
        memset(p->unk1C, 0, 0x40);
        memset(p->unk5C, 0, 0x1C);
        p->unk78 = D_801D75F4;
    }
    func_801A4824(0x200, 4, 7, 0xC252);
    func_801A4824(0x200, 9, 0xC, 0xC252);
    if ((s16)arg1 != 0) {
        buf = func_801CC898(0x80);
        if (buf != 0) {
            memset(buf, 0x22, 0x80);
            rect.unk2 = 0xF;
            rect.unk4 = 4;
            rect.unk0 = 0;
            rect.unk6 = 0x10;
            for (i = 0; i < 4; i++) {
                rect.unk0 = 0x3E8;
                LoadImage2(&rect, buf);
                rect.unk0 = 0x3F1;
                LoadImage2(&rect, buf);
                rect.unk0 = 0x3F8;
                LoadImage2(&rect, buf);
                rect.unk2 += 0x20;
            }
            free3(buf);
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8017EBF8", D_80170430);

void func_8017EE2C(Unk_801802A0 *arg0, s32 arg1) {
    s32 s;

    if (arg1 < 0x64) {
        switch (arg1) {
        case 0:
            return;
        case 1:
            func_8017EBF8(arg0, 1);
            arg0->unkC = 0x66;
            break;
        case 2:
            func_8017EBF8(arg0, 1);
            arg0->unkC = 0x67;
            break;
        case 3:
            arg0->unkC = -1;
            arg0->unk10 = 0;
            return;
        case 4:
            arg0->unkC = 0x69;
            break;
        case 5:
            if (arg0->unk0 != 0) {
                arg0->unkC = 0x66;
                arg0->unk10 = 0;
            } else {
                arg0->unkC = -1;
                arg0->unk10 = 0xD;
            }
            return;
        case 6:
            arg0->unkC = 0x6B;
            break;
        case 7:
            arg0->unkC = 0x6A;
            break;
        default:
            arg0->unkC = -1;
            return;
        }
    } else {
        arg0->unkC = arg1;
    }
    switch (arg0->unkC) {
    case 0x64:
        s = 1;
        break;
    case 0x65:
        s = 0;
        break;
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x6A:
        s = 2;
        func_801A2678(0xE);
        break;
    case 0x69:
        s = 3;
        if (arg0->unk0 == 0) {
            s = 1;
        }
        func_801A2678(0xE);
        break;
    case 0x6B:
        s = 1;
        func_801A2678(0xE);
        break;
    default:
        return;
    }
    func_801A4A68(0x202, 1);
    func_801A4A68(0x203, 1);
    func_801A4BC8(0x202, (s16)((arg0->unkC - 0x64) / 4), (s16)((arg0->unkC - 0x64) % 4));
    func_801A4BC8(0x203, 0, s);
}

INCLUDE_ASM("asm/nonmatchings/game/8017EBF8", func_8017EFEC);

INCLUDE_ASM("asm/nonmatchings/game/8017EBF8", func_8017F6F4);

INCLUDE_ASM("asm/nonmatchings/game/8017EBF8", func_8017FF0C);

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

s16 func_801803BC(Unk_801802A0 *arg0) {
    s32 cmd;
    s32 result;
    s32 ok;
    s32 ret;
    s32 snd;
    Unk_801E0340 *g;

    g = &D_801E0340;
    if (D_801E6DAA[0] != 1 || arg0->unkC == 0x65 || arg0->unkC == 0x6C) {
        return 0;
    }
    if (arg0->unkC == -1) {
        return 1;
    }
    if (arg0->unkC == 0x66 || arg0->unkC == 0x67) {
        ok = 1;
    } else {
        for (;;) {
            switch (MemCardSync(1, &cmd, &result)) {
            case 0:
                continue;
            case -1:
                MemCardExist(0);
                continue;
            case 1:
                if (cmd != 1) {
                    continue;
                }
                switch (result) {
                case 0:
                    ok = 1;
                    break;
                case 3:
                    arg0->unkC = -1;
                    arg0->unk10 = 0;
                case 1:
                case 2:
                    func_8017EE2C(arg0, result);
                    ok = 0;
                    break;
                default:
                    continue;
                }
                break;
            default:
                continue;
            }
            break;
        }
    }
    if (ok != 0) {
        ret = 0;
        func_801CD6B4();
        if (!(D_801E6DA0.unk4 & 0x20) && (D_801E6DA0.unk0 & 0x20)) {
            ret = 1;
            snd = 0x11;
            switch (arg0->unkC) {
            case 0x64:
            case 0x68:
                if (arg0->unk0 != 0) {
                    arg0->unk10 = 0xC;
                    snd = 2;
                } else {
                    arg0->unk10 = 0xD;
                }
                arg0->unkC = -1;
                break;
            case 0x69:
                if (arg0->unk0 != 0) {
                    break;
                }
                arg0->unk10 = 0xA;
                arg0->unkC = -1;
                break;
            case 0x66:
            case 0x67:
                arg0->unk10 = 0;
                arg0->unkC = -1;
                break;
            case 0x6A:
                if (arg0->unk0 != 0) {
                    arg0->unk10 = 0;
                }
                arg0->unkC = -1;
                break;
            case 0x6B:
                arg0->unk10 = 0xE;
                arg0->unkC = -1;
                break;
            default:
                ret = 0;
                break;
            }
        } else if (!(D_801E6DA0.unk4 & 0x40) && (D_801E6DA0.unk0 & 0x40)) {
            if (arg0->unkC == 0x6B || (arg0->unk0 == 0 && arg0->unkC == 0x6A)) {
                ret = 1;
                snd = 8;
                func_8017EE2C(arg0, 0x64);
            } else {
                func_801A2678(8);
                func_8018C1B0(3, 0, 0, 1);
                g->unkA = 1;
            }
        } else if (!(D_801E6DA0.unk4 & 0x1000) && (D_801E6DA0.unk0 & 0x1000)) {
            if (arg0->unkC == 0x64) {
                func_801802A0(arg0, 1);
            }
        } else if (!(D_801E6DA0.unk4 & 0x4000) && (D_801E6DA0.unk0 & 0x4000)) {
            if (arg0->unkC == 0x64) {
                func_801802A0(arg0, 0);
            }
        }
        ok = ret;
    }
    if (ok) {
        func_801A2678(snd);
    }
    return 0;
}

void func_8018073C(Unk_801802A0 *arg0) {
    s32 sp10;
    s32 sp14;
    s32 r;
    s32 a;

    switch (MemCardSync(1, &sp10, &sp14)) {
    case 0:
        break;
    case -1:
        switch (arg0->unk10) {
        case 0:
            MemCardExist(0);
            break;
        case 10:
            r = MemCardFormat(0);
            if (r == 0) {
                arg0->unk10 = 0xB;
                arg0->unkC = -1;
            } else {
                func_8017EE2C(arg0, r);
            }
            break;
        case 11:
            func_8017EE2C(arg0, func_8017FF0C(arg0));
            break;
        case 12:
            func_8017EE2C(arg0, func_8017EFEC(arg0));
            break;
        case 13:
            func_8017EE2C(arg0, func_8017F6F4(arg0, 0));
            break;
        case 14:
            func_8017EE2C(arg0, func_8017F6F4(arg0, 1));
            break;
        }
        break;
    case 1:
        a = sp10;
        switch (a) {
        case 1:
            if (sp14 == 0) {
                arg0->unk10 = 0xB;
                arg0->unk6 = a;
                arg0->unkC = -1;
            } else if (sp14 == 3) {
                arg0->unk6 = a;
                MemCardAccept(0);
            } else {
                func_8017EE2C(arg0, sp14);
            }
            break;
        case 2:
            if (sp14 == 0 || sp14 == 3) {
                arg0->unk10 = 0xB;
                arg0->unkC = -1;
            } else {
                func_8017EE2C(arg0, sp14);
            }
            break;
        }
        break;
    }
}

s16 func_801808F0(s16 arg0, s16 arg1) {
    s32 buf[6];
    Unk_801802A0 *p;
    s16 done = 0;
    s16 r;
    s32 i;

    p = &D_801E0030;
    if (arg0 != 0) {
        func_80192B8C(4, -1);
    } else {
        func_80192B8C(5, -1);
    }
    func_801A4A68(0x200, 1);
    func_801A4A68(0x202, 1);
    func_801A4A68(0x203, 1);
    p->unk0 = arg0;
    p->unk2 = 0;
    p->unk4 = arg1;
    p->unkC = -1;
    p->unk10 = 0;
    func_8017EBF8(p, 0);
    MemCardStart();
    func_801D06B4();
    func_801CD688(1);
    while (done == 0) {
        switch (func_801CC378(buf)) {
        case 0:
            r = func_801803BC(p);
            if ((s16)func_8018C170() != 0) {
                if (arg1 != 0 || (p->unk2 != 0 && arg0 != 0)) {
                    func_80186128(1, 3);
                } else {
                    func_801CD688(0);
                    done = 1;
                }
            }
            break;
        case 0x100:
            done = func_8018970C(buf);
            continue;
        default:
            func_801CC734(buf);
            continue;
        }
        if (r != 0) {
            func_8018073C(p);
        }
        func_801A7560();
        func_801A0418(3);
    }
    func_801D06C4();
    MemCardSync(0, 0, 0);
    MemCardStop();
    func_801A4A68(0x200, 0);
    func_801A4A68(0x202, 0);
    func_801A4A68(0x203, 0);
    for (i = 0x200; i < 0x205; i++) {
        func_801A43F4((u16)i);
    }
    return p->unk2;
}

void func_80180B04(Unk_80181C10 *arg0, s32 arg1, s32 arg2) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_80184230 rect;

    switch ((s16)arg1) {
    case 0:
        func_801A4A68(0x237, 1);
        func_801A4A68(0x238, 1);
        break;
    case 1:
        func_801A2678(0x11);
        func_801A4A68(0x239, 1);
        rect.unk0 = 0x3C0;
        rect.unk2 = arg0->unk6 * 0x40;
        rect.unk4 = 0x2C;
        rect.unk6 = 0x40;
        MoveImage2(&rect, 0x300, 0x100);
        func_801A4824(0x239, 2, 5, 0x421);
        switch (g->unk0[D_801D7694[arg0->unk6]]) {
        case 0:
            break;
        case 10:
            func_801A461C(0x239, 2, 0xB4);
            func_801A461C(0x239, 3, 0x28A);
            break;
        case 1000:
            func_801A461C(0x239, 2, 0xB4);
            func_801A461C(0x239, 3, 0x28A);
            func_801A461C(0x239, 4, 0x2A85);
            break;
        case 2000:
            func_801A461C(0x239, 2, 0xB4);
            func_801A461C(0x239, 3, 0x28A);
            func_801A461C(0x239, 4, 0x2A85);
            func_801A461C(0x239, 5, 0x3CAF);
            break;
        default:
            func_801A461C(0x239, 2, 0xB4);
            break;
        }
        return;
    case 2:
        func_801A2678(0xF);
        if ((s16)arg2 != 0) {
            if (--arg0->unk6 < 0) {
                arg0->unk6 = 7;
            }
        } else {
            if (++arg0->unk6 >= 8) {
                arg0->unk6 = 0;
            }
        }
        break;
    }
    func_801A4BC8(0x238, 0, arg0->unk6);
    func_801A4824(0x237, 1, 8, 0x10C);
    func_801A461C(0x237, arg0->unk6 + 1, 0x23F);
}

INCLUDE_ASM("asm/nonmatchings/game/8017EBF8", func_80180D8C);

void func_8018164C(Unk_80181C10 *arg0, s32 arg1, s16 arg2) {
    Unk_801E0368 *g = &D_801E0368;
    s16 s = 1;

    switch (arg1) {
    case 0:
        s = 0;
        func_801A4A68(0x23D, 1);
        break;
    case 1:
        arg0->unk6 = 1 - arg0->unk6;
        break;
    case 2:
        if (arg0->unk6 != 0) {
            if (arg2 != 0) {
                g->unk200--;
                if (g->unk200 < 0) {
                    g->unk200 = 2;
                }
            } else {
                g->unk200++;
                if (g->unk200 >= 3) {
                    g->unk200 = 0;
                }
            }
        } else {
            if (arg2 != 0) {
                g->unk202--;
                if (g->unk202 < 0) {
                    g->unk202 = 2;
                }
            } else {
                g->unk202++;
                if (g->unk202 >= 3) {
                    g->unk202 = 0;
                }
            }
        }
        break;
    }
    func_801A4824(0x23D, 7, 8, 0x4250);
    func_801A461C(0x23D, arg0->unk6 + 7, 0x5140);
    func_801A4824(0x23D, 9, 0xE, 0x421);
    func_801A461C(0x23D, g->unk202 + 9, 0x154);
    func_801A461C(0x23D, g->unk200 + 0xC, 0x154);
    if (s != 0) {
        func_801A2678(0xF);
    }
}

void func_80181818(Unk_80181C10 *arg0, s16 arg1) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801A44B8 *a;
    Unk_801A44B8 *b;
    Unk_801A44B8 *c;

    switch (arg0->unk2) {
    case 0:
        if (arg0->unk4 != 0) {
            break;
        }
        if (arg1 != 0) {
            if (--arg0->unk0 < 0) {
                arg0->unk0 = 4;
            }
        } else {
            if (++arg0->unk0 >= 5) {
                arg0->unk0 = 0;
            }
        }
        a = func_801A44B8(0x20B);
        b = func_801A44B8(0x211);
        if (a != 0) {
            a->unkC = (arg0->unk0 << 4) + 0x48;
        }
        if (b != 0 && b->unk4 != 0) {
            b->unk4 = 0;
        }
        if (D_801DFC94 != 0) {
            D_801DFC94->unk4 = 0;
        }
        if (arg0->unk0 == 0) {
            arg0->unk8 = 0;
            arg0->unkC = 0;
            D_801DFC94 = 0;
        } else {
            arg0->unkC = b;
            c = func_801A44B8(arg0->unk0 + 0x20C);
            if (c == 0) {
                arg0->unk8 = 0;
                if (b != 0) {
                    if (b->unk4 == 0) {
                        b->unk4 = 1;
                    }
                    b->unk18 = 0;
                    b->unk1A = arg0->unk0 - 1;
                }
            } else {
                arg0->unk8 = c;
                c->unk18 = 0;
                c->unk1A = 0;
                if (c->unk4 == 0) {
                    c->unk4 = 1;
                }
                arg0->unk4 = 1;
                D_801DFC94 = c;
            }
        }
        func_801A2678(0xF);
        break;
    case 1:
        if (arg0->unk0 == 1) {
            func_80180B04(arg0, 2, arg1);
        } else if (arg0->unk0 == 2 && g->unkBE != 0) {
            arg0->unk6 = func_8018B69C(arg1, arg0->unk6);
        } else if (arg0->unk0 == 3) {
            func_8018164C(arg0, 1, arg1);
        }
        break;
    }
}

void func_80181A64(Unk_80181C10 *arg0) {
    Unk_801E0368 *g = &D_801E0368;

    switch (arg0->unk2) {
    case 0:
        arg0->unk6 = 0;
        arg0->unk2 = 1;
        func_801A2678(0x11);
        if (arg0->unk0 == 1) {
            func_80192B8C(0xD, -1);
            func_80180B04(arg0, 0, 0);
        } else if (arg0->unk0 == 2) {
            if (g->unkBE != 0) {
                func_80192B8C(8, -1);
                func_8018B810();
            }
            func_801A4A68(0x20A, 1);
            func_801A4A68(0x212, 1);
            func_801A4A68(0x20C, 1);
        } else if (arg0->unk0 == 3) {
            func_8018164C(arg0, 0, 0);
        } else if (arg0->unk0 == 4) {
            func_80192B8C(0xE, -1);
            func_80180D8C(arg0, 0);
        }
        break;
    case 1:
        if (arg0->unk0 == 1) {
            func_80180B04(arg0, 1, 0);
            arg0->unk2 = 2;
        } else if (arg0->unk0 == 2 && g->unkBE != 0) {
            func_801A2678(0x11);
            func_80192A44(arg0->unk6);
            arg0->unk2 = 2;
        } else if (arg0->unk0 == 4) {
            func_80180D8C(arg0, 1);
        }
        break;
    }
}

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

void func_80181D2C(Unk_80181C10 *arg0) {
    s32 r;

    if (D_801E6DA0.unkA != 1 || arg0->unk4 != 0) {
        return;
    }
    r = func_801CD6B4();
    if (!(D_801E6DA0.unk4 & 0x1000) && (D_801E6DA0.unk0 & 0x1000)) {
        func_80181818(arg0, 1);
    } else if (!(D_801E6DA0.unk4 & 0x4000) && (D_801E6DA0.unk0 & 0x4000)) {
        func_80181818(arg0, 0);
    } else if (!(D_801E6DA0.unk4 & 0x8000) && (D_801E6DA0.unk0 & 0x8000)) {
        if (*(s32 *)arg0 == 0x10003) {
            func_8018164C(arg0, 2, 1);
        }
    } else if (!(D_801E6DA0.unk4 & 0x2000) && (D_801E6DA0.unk0 & 0x2000)) {
        if (*(s32 *)arg0 == 0x10003) {
            func_8018164C(arg0, 2, 0);
        }
    } else if (!(D_801E6DA0.unk4 & 0x40) && (D_801E6DA0.unk0 & 0x40)) {
        if (arg0->unk2 == 0) {
            func_801A2678(8);
            func_8018C414(1, 1, 0, 0);
            return;
        }
        func_80181C10(arg0);
    } else if (!(D_801E6DA0.unk4 & 0x20) && (D_801E6DA0.unk0 & 0x20) && arg0->unk0 != 0) {
        func_80181A64(arg0);
    }
    if (arg0->unk2 == 2 && arg0->unk0 == arg0->unk2) {
        if (r & 0x1000) {
            func_8018B11C(0);
        } else if (r & 0x4000) {
            func_8018B11C(1);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8017EBF8", func_80181F9C);

void func_80182300(void) {
    Unk_80181C10 st;
    Unk_80181C10 *p;
    s32 buf[6];
    s16 done = 0;
    u16 i;

    func_801A4A68(0x400, 0);
    func_801A4A68(0x409, 0);
    func_801A4A68(0x207, 1);
    func_801A4824(0x207, 0xF0, 0xFE, 0);
    func_80192B8C(6, 1);
    func_801A4A68(0x207, 0);
    func_801A4A68(0x208, 1);
    func_801A4A68(0x209, 1);
    func_801A4A68(0x20B, 1);
    func_801A4824(0x208, 0x90, 0x9F, 0x38A2);
    func_801A4824(0x208, 0xA0, 0xAF, 0x4D44);
    func_801A4824(0x208, 0xB0, 0xBF, 0x38A2);
    p = &st;
    p->unk0 = 0;
    p->unk2 = 0;
    p->unk4 = 0;
    p->unk6 = 0;
    p->unk8 = NULL;
    p->unkC = NULL;
    D_801DFC94 = NULL;
    func_801D06B4();
    func_80186128(0, 3);
    func_801A3BCC(2);
    do {
        switch (func_801CC378(buf)) {
        case 4:
            func_80189970(0);
            continue;
        case 0:
            func_80181D2C(&st);
            if ((s16)func_8018C170() != 0) {
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
        func_80181F9C(&st);
        func_801A0418(3);
    } while (done == 0);
    func_801D06C4();
    func_801A3C58();
    func_801A4A68(0x400, 1);
    func_801A4A68(0x409, 1);
    for (i = 0x207; i < 0x23E; i++) {
        func_801A43F4(i);
    }
    D_801DFC94 = NULL;
}

void func_80182518(s32 arg0, s16 arg1) {
    s16 r[4];
    u16 buf[0x40];
    Unk_801A44B8 *p;
    u16 *d;
    u16 *f;
    u8 *s;
    u8 c;
    s16 w;
    s32 row;
    s32 col;
    s32 i;
    s32 n;
    s32 j;

    p = func_801A44B8(D_801DFCB0);
    if (p == NULL) {
        return;
    }
    row = 0;
    col = 0;
    r[2] = 4;
    r[0] = 0;
    r[1] = 0;
    r[3] = 16;
    n = strlen((char *)arg0);
    for (i = 0; i < n; ) {
        if (row >= arg1) {
            return;
        }
        s = (u8 *)arg0 + i;
        c = s[0];
        if ((s8)s[0] >= 0) {
            i++;
            switch (c) {
            case ' ':
                col++;
                break;
            case ',':
                col = 0;
                row++;
                break;
            default:
                D_801DFE74 = c - '0';
                break;
            }
            continue;
        }
        d = buf;
        w = (s[0] << 8) | s[1];
        r[0] = p->unk1C->unk0 + col * 4;
        r[1] = p->unk1C->unk2 + row * 16;
        f = Krom2RawAdd2(w);
        memset(d, 0, 0x80);
        for (j = 0; j < 15; j++, f++) {
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 4;
                v = 0;
                for (k = 7, sh = 0; k >= m; k--, sh += 4) {
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = D_801DFE74;
                    }
                    v |= c << sh;
                }
                *d++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 0;
                v = 0;
                for (k = 3, sh = 0; k >= m; k--, sh += 4) {
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = D_801DFE74;
                    }
                    v |= c << sh;
                }
                *d++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 12;
                v = 0;
                for (k = 15, sh = 0; k >= m; k--, sh += 4) {
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = D_801DFE74;
                    }
                    v |= c << sh;
                }
                *d++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 8;
                v = 0;
                for (k = 11, sh = 0; k >= m; k--, sh += 4) {
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = D_801DFE74;
                    }
                    v |= c << sh;
                }
                *d++ = v;
            }
        }
        LoadImage2(r, buf);
        col++;
        if (col >= 16) {
            col = 0;
            row++;
        }
        i += 2;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8017EBF8", func_80182860);

void func_80182D34(char *arg0, s16 arg1) {
    s16 r[4];
    u16 buf[0x40];
    Unk_801A44B8 *p;
    u16 *d;
    u16 *f;
    u8 *s;
    s16 w;
    s16 line;
    s32 y;
    s32 col;
    s32 i;
    s32 n;
    s32 j;

    line = arg1;
    p = func_801A44B8(D_801DFCB0);
    if (p == NULL) {
        return;
    }
    n = strlen(arg0);
    y = D_801D76A4[arg1];
    if (arg1 < 2) {
        col = (32 - n) / 4;
    } else {
        col = 1;
    }
    i = 0;
    r[2] = 4;
    r[0] = 0;
    r[1] = 0;
    r[3] = 16;
    while (i < n) {
        s = (u8 *)arg0 + i;
        if ((s8)s[0] >= 0) {
            i++;
            if (s[0] == ' ') {
                col++;
            }
            continue;
        }
        d = buf;
        w = (s[0] << 8) | s[1];
        r[0] = p->unk1C->unk0 + col * 4;
        r[1] = p->unk1C->unk2 + y;
        f = Krom2RawAdd2(w);
        StoreImage2(r, d);
        for (j = 0; j < 15; j++, f++) {
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 4;
                v = 0;
                for (k = 7, sh = 0; k >= m; k--, sh += 4) {
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = D_801DFE74;
                    }
                    v |= c << sh;
                }
                *d++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 0;
                v = 0;
                for (k = 3, sh = 0; k >= m; k--, sh += 4) {
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = D_801DFE74;
                    }
                    v |= c << sh;
                }
                *d++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 12;
                v = 0;
                for (k = 15, sh = 0; k >= m; k--, sh += 4) {
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = D_801DFE74;
                    }
                    v |= c << sh;
                }
                *d++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 8;
                v = 0;
                for (k = 11, sh = 0; k >= m; k--, sh += 4) {
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = D_801DFE74;
                    }
                    v |= c << sh;
                }
                *d++ = v;
            }
        }
        LoadImage2(r, buf);
        col++;
        if (line >= 3 && col >= 15) {
            col = 1;
            line++;
            y = D_801D76A4[line];
        }
        i += 2;
    }
}

void func_801830A0(u8 *arg0, u16 arg1) {
    u16 a;
    u16 b;
    u16 c;

    memset(arg0, 0, 8);
    if (arg1 == 0) {
        strncpy(arg0, D_801DFCBC, 2);
        return;
    }
    arg1 %= 1000;
    a = arg1 / 100;
    arg1 %= 100;
    b = arg1 / 10;
    c = arg1 % 10;
    if (a == 0) {
        if (b == 0) {
            arg0[0] = 0x82;
            arg0[1] = c + 0x4F;
        } else {
            arg0[0] = 0x82;
            arg0[1] = b + 0x4F;
            arg0[2] = 0x82;
            arg0[3] = c + 0x4F;
        }
    } else {
        arg0[0] = 0x82;
        arg0[1] = a + 0x4F;
        arg0[2] = 0x82;
        arg0[3] = b + 0x4F;
        arg0[4] = 0x82;
        arg0[5] = c + 0x4F;
    }
}

void func_801831EC(u16 arg0, s16 arg1, s32 arg2, s16 arg3, s32 arg4) {
    Unk_80184230 rect;
    Unk_801A44B8 *p;
    s16 b;

    b = (arg0 == 1 || arg0 == 2);
    if (arg1 != 0) {
        Unk_801E0368 *g = &D_801E0368;
        Unk_801DFFE8 *d = &D_801DFFE8;
        s16 m = 3;

        if (m == 1) {
            D_801DFCB0 = 0x403;
            func_801A4A68(0x403, 1);
            func_801A4A68(0x404, 0);
            func_801A461C(0x403, 3, 0x14BF);
        } else if (m == 3) {
            D_801DFCB0 = 0x404;
            func_801A4A68(0x403, 0);
            func_801A4A68(0x404, 1);
            func_801A461C(0x404, 3, 0x14BF);
        }
        D_801DFE74 = 1;
        d->unk8 = 0;
        d->unkA = -1;
        d->unkC = 0;
        d->unkE = -1;
        p = func_801A44B8(D_801DFCB0);
        if (p != NULL) {
            rect.unk0 = p->unk1C->unk0;
            rect.unk2 = p->unk1C->unk2;
            rect.unk4 = p->unk1C->unk4;
            rect.unk6 = p->unk1C->unk6;
            ClearImage2(&rect, 0, 0, 0);
        }
        func_80182518(arg2, m);
        if (arg3 == 1) {
            func_801A2678(0xF);
        } else if (arg3 == 2) {
            func_801A2678(6);
        } else if (arg3 == 3) {
            func_801A2678(5);
        } else if (arg3 == 4) {
            func_801A2678(0xE);
        }
        if (g->unk24E == 0) {
            g->unk24E = 1;
        }
    } else {
        Unk_801E0368 *g = &D_801E0368;
        Unk_801DFFE8 *d = &D_801DFFE8;
        s16 m = 1;

        if (m == 1) {
            D_801DFCB0 = 0x403;
            func_801A4A68(0x403, 1);
            func_801A4A68(0x404, 0);
            func_801A461C(0x403, 3, 0x14BF);
        } else if (m == 3) {
            D_801DFCB0 = 0x404;
            func_801A4A68(0x403, 0);
            func_801A4A68(0x404, 1);
            func_801A461C(0x404, 3, 0x14BF);
        }
        D_801DFE74 = 1;
        d->unk8 = 0;
        d->unkA = -1;
        d->unkC = 0;
        d->unkE = -1;
        p = func_801A44B8(D_801DFCB0);
        if (p != NULL) {
            rect.unk0 = p->unk1C->unk0;
            rect.unk2 = p->unk1C->unk2;
            rect.unk4 = p->unk1C->unk4;
            rect.unk6 = p->unk1C->unk6;
            ClearImage2(&rect, 0, 0, 0);
        }
        func_80182518(arg2, m);
        if (arg3 == 1) {
            func_801A2678(0xF);
        } else if (arg3 == 2) {
            func_801A2678(6);
        } else if (arg3 == 3) {
            func_801A2678(5);
        } else if (arg3 == 4) {
            func_801A2678(0xE);
        }
        if (g->unk24E == 0) {
            g->unk24E = 1;
        }
    }
    func_8018C1B0(arg0, b, b, arg4);
}

void func_801834AC(s32 arg0) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_80184230 rect;
    Unk_801A44B8 *p;

    D_801DFCB0 = 0x404;
    func_801A4A68(0x403, 0);
    func_801A4A68(0x404, 1);
    func_801A461C(0x40A, 3, 0x14BF);
    D_801DFE74 = 2;
    D_801DFE70 = 0;
    D_801DFE72 = 0;
    p = func_801A44B8(D_801DFCB0);
    if (p != NULL) {
        rect.unk0 = p->unk1C->unk0;
        rect.unk2 = p->unk1C->unk2;
        rect.unk4 = p->unk1C->unk4;
        rect.unk6 = p->unk1C->unk6;
        ClearImage2(&rect, 0, 0, 0);
    }
    D_801DFE78 = 0;
    D_801DFE76 = strlen((char *)arg0);
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
    if (g->unk24E == 0) {
        g->unk24E = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8017EBF8", func_80183618);

INCLUDE_ASM("asm/nonmatchings/game/8017EBF8", func_801837F0);

void func_80183CFC(s32 arg0) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801E076C *q = D_801E076C[0];
    Unk_80184230 rect;
    Unk_80184338 *e;
    Unk_801A44B8 *p;

    e = func_801D15C8(4);
    e->unk22 = 8;
    e->unk24 = 0;
    e->unk26 = strlen((char *)arg0);
    e->unk28 = 1;
    e->unk2C = 0xA;
    e->unk30 = func_80184338;
    e->unk34 = func_80184408;
    e->unk38 = func_80184408;
    func_801A4A68(0x403, 0);
    func_801A4A68(0x404, 1);
    func_801A461C(0x40A, 3, 0x14BF);
    D_801DFCB0 = 0x404;
    D_801DFE74 = 1;
    D_801DFE70 = 0;
    D_801DFE72 = 0;
    D_801DFE78 = 0;
    D_801DFE76 = strlen((char *)arg0);
    p = func_801A44B8(D_801DFCB0);
    if (p != NULL) {
        rect.unk0 = p->unk1C->unk0;
        rect.unk2 = p->unk1C->unk2;
        rect.unk4 = p->unk1C->unk4;
        rect.unk6 = p->unk1C->unk6;
        ClearImage2(&rect, 0, 0, 0);
    }
    *e->unk3C = arg0;
    func_80182860(arg0, 0);
    D_801DFE7C = 0;
    D_801DFE7E = 0;
    q->unk42 |= 0x100;
    g->unk248 = func_801D14B8(e);
}

void func_80183E88(s32 arg0, s16 arg1, s16 arg2, u16 arg3, s16 arg4, u16 arg5, s16 arg6) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801DFFE8 *d = &D_801DFFE8;
    Unk_80184230 rect;
    Unk_801A44B8 *p;

    if (arg1 == 1) {
        D_801DFCB0 = 0x403;
        func_801A4A68(0x403, 1);
        func_801A4A68(0x404, 0);
        func_801A461C(0x403, 3, 0x14BF);
    } else if (arg1 == 3) {
        D_801DFCB0 = 0x404;
        func_801A4A68(0x403, 0);
        func_801A4A68(0x404, 1);
        func_801A461C(0x404, 3, 0x14BF);
    }
    D_801DFE74 = 1;
    d->unk8 = arg3;
    d->unkA = arg2;
    d->unkC = arg5;
    d->unkE = arg4;
    if (arg3 != 0 || arg5 != 0) {
        d->unk6 = 2;
    }
    p = func_801A44B8(D_801DFCB0);
    if (p != NULL) {
        rect.unk0 = p->unk1C->unk0;
        rect.unk2 = p->unk1C->unk2;
        rect.unk4 = p->unk1C->unk4;
        rect.unk6 = p->unk1C->unk6;
        ClearImage2(&rect, 0, 0, 0);
    }
    func_80182518(arg0, arg1);
    if (arg6 == 1) {
        func_801A2678(0xF);
    } else if (arg6 == 2) {
        func_801A2678(6);
    } else if (arg6 == 3) {
        func_801A2678(5);
    } else if (arg6 == 4) {
        func_801A2678(0xE);
    }
    if (g->unk24E == 0) {
        g->unk24E = 1;
    }
}

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

INCLUDE_ASM("asm/nonmatchings/game/8017EBF8", func_801844D4);

void func_80184698(void) {
    Unk_801DFE80 *list = D_801DFE80;
    Unk_801E076C *q = D_801E076C[0];
    Unk_801854B8 *item;
    Unk_80174FFC rot;

    if (list->unkC == 0) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL) {
            item->unk40 = item->unk14 - q->unk72 * 12500;
            item->unk44 = item->unk18 + q->unk74 * 32000;
            item->unk48 = item->unk1C - q->unk76 * 12500;
            rot.unk0 = 0;
            rot.unk2 = (item->unk20 << 12) / 360;
            rot.unk4 = 0;
            RotMatrix(&rot, item->unk2C);
            item->unk28 = 0;
            item->unk10 = (s32)func_8017CDA4(item->unk14, item->unk18, item->unk1C);
        }
        if (func_801CD000((Unk_801DFE5C *)list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

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

void func_80184C6C(void) {
    Unk_801DFE80 *list = D_801DFE80;
    Unk_801E076C *q = D_801E076C[0];
    Unk_80184814 *item;
    Unk_80174FFC rot;

    if (list->unkC == 0) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = (Unk_80184814 *)list->unk8->unk8;
        if (item != NULL && item->unk4 != 0 && item->unk6 != 0
            && (u16)(item->unkA - 2) < 2) {
            switch (item->unk2) {
            case 1:
                func_80184814(item);
                break;
            case 2:
                func_80184928(item);
                break;
            case 3:
                func_80184A3C(item);
                break;
            default:
                func_80184B50(item);
                break;
            }
            item->unk40 = item->unk14 - q->unk72 * 12500;
            item->unk44 = item->unk18 + q->unk74 * 32000;
            item->unk48 = item->unk1C - q->unk76 * 12500;
            rot.unk0 = 0;
            rot.unk2 = (item->unk20 << 12) / 360;
            rot.unk4 = 0;
            RotMatrix(&rot, item->unk2C);
            item->unk28 = 0;
        }
        if (item->unk4 != 0 && item->unk6 != 0 && D_801DFC80 != 0) {
            item->unk10 = (s32)func_8017CDA4(item->unk14, item->unk18, item->unk1C);
        }
        if (func_801CD000((Unk_801DFE5C *)list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

void func_80184ECC(Unk_80184814 *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 v = arg2;
    s32 w;
    s16 d;

    D_801DFC74 = 1;
    arg0->unkA = 3;
    arg0->unk24 = arg3;
    switch (arg0->unk2) {
    case 1:
        v = arg2 * 10;
        arg0->unkC = arg0->unk14;
        arg0->unkE = arg0->unk14 + arg1 * 10;
        break;
    case 2:
        v = arg2 * 10;
        arg0->unkC = arg0->unk18;
        arg0->unkE = arg0->unk18 + arg1 * 10;
        break;
    case 3:
        v = arg2 * 10;
        arg0->unkC = arg0->unk1C;
        arg0->unkE = arg0->unk1C + arg1 * 10;
        break;
    default:
        arg0->unkC = arg0->unk20;
        arg0->unkE = arg0->unk20 + arg1;
        break;
    }
    d = arg0->unkE - arg0->unkC;
    w = v;
    if (d >= 0) {
        if (d <= 0) {
            arg0->unk22 = 0;
        } else {
            arg0->unk22 = w;
        }
    } else {
        arg0->unk22 = -w;
    }
}

void func_80185034(Unk_80184814 *arg0, s16 arg1, s16 arg2) {
    s16 v = arg2;
    s32 w;
    s16 d;

    D_801DFC74 = 1;
    arg0->unkA = 2;
    arg0->unk24 = 0;
    switch (arg0->unk2) {
    case 1:
        v = arg2 * 10;
        arg0->unkC = arg0->unk14;
        arg0->unkE = arg0->unk14 + arg1 * 10;
        break;
    case 2:
        v = arg2 * 10;
        arg0->unkC = arg0->unk18;
        arg0->unkE = arg0->unk18 + arg1 * 10;
        break;
    case 3:
        v = arg2 * 10;
        arg0->unkC = arg0->unk1C;
        arg0->unkE = arg0->unk1C + arg1 * 10;
        break;
    default:
        arg0->unkC = arg0->unk20;
        arg0->unkE = arg0->unk20 + arg1;
        break;
    }
    d = arg0->unkE - arg0->unkC;
    w = v;
    if (d >= 0) {
        if (d <= 0) {
            arg0->unk22 = 0;
        } else {
            arg0->unk22 = w;
        }
    } else {
        arg0->unk22 = -w;
    }
}

void func_8018519C(Unk_8018519C *arg0, Unk_801DFFE8 *arg1) {
    Unk_801DFE80 *list = D_801DFE80;
    Unk_8018519C_0 *p = arg0->unk0;
    Unk_80184814 *item;
    Unk_80184814 *found;
    u16 a = p->unk4;
    s32 x;
    s32 y;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        list->unk8 = list->unk0;
        while (1) {
            item = (Unk_80184814 *)list->unk8->unk8;
            if (item != NULL && item->unk0 == a) {
                found = item;
                break;
            }
            if (func_801CD000((Unk_801DFE5C *)list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL) {
        if (p->unk2 == 0) {
            if (found->unkA != 1) {
                x = (s16)atoi(arg0->unk8[0]);
                y = (s16)atoi(arg0->unk8[1]);
                func_80184ECC(found, x, y, atoi(arg0->unk8[2]));
                if (atoi(arg0->unk8[3]) == 1) {
                    arg1->unk6 = 4;
                    arg1->unk12 |= 4;
                }
            }
        } else {
            if (found->unkA != 0) {
                s32 z = (s16)atoi(arg0->unk8[0]);
                func_80185034(found, z, atoi(arg0->unk8[1]));
                if (atoi(arg0->unk8[2]) == 1) {
                    arg1->unk6 = 4;
                    arg1->unk12 |= 4;
                }
            }
        }
    }
}
