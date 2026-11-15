#include "common.h"

typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; } Unk_80192E18;
typedef struct { s32 unk0; s32 unk4; Unk_80192E18 *unk8; void *unkC; } Unk_80192F20;
void free3(void *ptr);
typedef struct { s32 unk0; u16 unk4; s16 unk6; s32 unk8; s32 unkC; } Unk_801E0600;
typedef struct {
    u8 unk0[0x3C];
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    u16 unk42;
    u8 unk44[4];
    s16 unk48;
    u8 unk4A[0xA];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0xC];
    s16 unk6C;
    s16 unk6E;
    s16 unk70;
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
typedef struct {
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
typedef struct {
    s16 unk0;
    u8 unk2[0x34];
    s16 unk36;
    u8 unk38[0x12];
    s16 unk4A;
    u8 unk4C[4];
    Unk_8018E56C *unk50;
    u8 unk54[8];
    Unk_801E076C *unk5C;
} Unk_801E0710;
extern Unk_801E0710 D_801E0710;
void func_8018A7C0(Unk_801E0710 *arg0);
typedef struct { u8 unk0[0x7C]; s16 unk7C; u16 unk7E; u8 unk80[0x34]; s16 unkB4[5]; } Unk_801E0368;
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

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_8018FA18);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_8018FC90);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_8018FED4);

INCLUDE_RODATA("asm/nonmatchings/game/8018FA18", D_80170B7C);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80190108);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80190378);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_801905A0);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_801907C8);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80190B2C);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80190D8C);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80190FD8);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_8019120C);

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

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_8019159C);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80191888);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80191AB0);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80192380);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_801926B4);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_8019290C);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80192A44);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80192B8C);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80192CD0);

void func_80192E18(Unk_80192F20 *arg0, u16 arg1) {
    Unk_80192E18 *e;
    s32 pos;
    u8 *p;

    arg0->unk4 = 0;
    e = arg0->unk8 + arg1 + 1;
    pos = arg0->unk8[arg1 + 1].unk0;
    arg0->unk0 = e->unk4;
    D_801E02D8.unk1C = e->unk8;
    D_801E02D8.unk18 = e->unkC;
    D_801DFF1C = e->unk10;
    D_801E02D8.unk28 = e->unk14;
    if (D_801DFF18 != 0) {
        p = CdIntToPos(CdPosToInt(D_801DFF20) + ((pos - 0x800) >> 11), D_801DFF20);
        while (CdControl(2, p, NULL) == 0) {
        }
    } else {
        p = CdIntToPos(CdPosToInt(D_801DFF20) + (pos >> 11), D_801DFF20);
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

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80193068);

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

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_8019430C);

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

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80194780);

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

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_801958FC);

INCLUDE_ASM("asm/nonmatchings/game/8018FA18", func_80195BC8);
