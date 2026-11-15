#include "common.h"

typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; s16 unkA; s16 unkC; s16 unkE; s16 unk10; s16 unk12; } Unk_801E1078;
extern Unk_801E1078 D_801E1078[8];
void SsUtKeyOffV(s16 voice);
typedef struct { s16 unk0; s16 unk2; s32 unk4; void *unk8; } Unk_801A3B5C;
typedef struct {
    s16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
} Unk_801E02DC;
typedef struct { Unk_801A3B5C *unk0; Unk_801E02DC *unk4[4]; s32 unk14; } Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
void func_801A2288(void);
void SsSepClose(s16 access_num);
void free3(void *ptr);
void func_801A3C58(void);
void SsSepPlay(s16 access_num, s16 seq_num, u8 play_mode, s16 l_count);
extern s16 D_801E6DB8[];
void SsSepStop(s16 access_num, s16 seq_num);
void SsSepSetVol(s16 access_num, s16 seq_num, s16 voll, s16 volr);
typedef struct {
    u8 unk0[0x22];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    u8 unk28[8];
    void (*unk30)();
    void (*unk34)();
    u8 unk38[4];
    s32 *unk3C;
} Unk_801A3D74;
typedef struct { u8 unk0[0x4C]; s16 unk4C; } Unk_801A3DBC;
s32 D_801DFD84;
s32 D_801DFD88;
s32 D_801DFD8C;
extern char D_80171724[];
extern char D_801716EC[];
typedef struct { s32 unk0; u8 *unk4; u8 *unk8; s32 unkC; s32 unk10; s16 unk14; } Unk_801A3970;
extern s32 D_801E02EC[];
s16 SsVabOpenHead(u8 *addr, s16 vabid);
extern char D_801DFD7C[];
void func_801CD54C(s32 a, char *b, char *c, s32 d);
extern char D_8017173C[];
s16 SsVabTransBodyPartly(u8 *addr, u32 bufsize, s16 vabid);
s16 SsVabTransCompleted(s16 immediateFlag);
typedef struct { s32 unk0; s16 unk4; s16 unk6; } Unk_801E056C;
typedef struct {
    u16 unk0[0x70];
    u8 unkE0[0x124];
    Unk_801E056C unk204[4];
    u8 unk224[0x20];
    s32 unk244;
} Unk_801E0368;
extern Unk_801E0368 D_801E0368;
void *func_801D15C8(u32 arg0);
void func_801D1774(void *arg0, s32 arg1);
s32 func_801D14B8(void *arg0);
void func_801A3D74(Unk_801A3D74 *arg0);
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
void *func_801CC898(u32 size);
extern char D_80171770[];
extern char D_8017178C[];
void SsVabClose(s16 vabid);
typedef struct { s32 unk0; s32 unk4; char **unk8; } Unk_801A324C;
s32 atoi(char *s);
void func_801A2C60(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6);
void func_801A3B5C(void);
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s16 unk18;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
s16 SsSepOpen(u32 *addr, s16 vab_id, s16 seq_num);
extern char D_80171708[];
typedef struct { u16 unk0[0xA]; u16 unk14; u8 unk16[0x7DE]; } Unk_801A37E4;
void *memset(void *dst, s32 c, u32 n);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_801716EC);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_80171708);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_80171724);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_8017173C);

void func_801A217C(Unk_801A217C *arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801E02DC *se;
    s32 i;

    se = func_801CC898(0xC);
    if (se == NULL) {
        func_801CD54C(3, "Error Allocating SE Pointer", D_801DFD7C, 0xD1);
    }
    se->unk0 = arg0->unk14;
    se->unk2 = arg0->unk16;
    se->unk4 = arg0->unk18;
    se->unk6 = arg0->unk1A;
    se->unk8 = arg0->unk4;
    if (p->unk14 == 0) {
        for (i = 0; i < 8; i++) {
            D_801E1078[i].unk2 = -1;
            D_801E1078[i].unk4 = -1;
            D_801E1078[i].unk6 = -1;
            D_801E1078[i].unk8 = -1;
            D_801E1078[i].unkA = -1;
            D_801E1078[i].unkC = -1;
            D_801E1078[i].unkE = 0;
            D_801E1078[i].unk12 = 0;
            D_801E1078[i].unk10 = 0;
        }
    }
    p->unk4[p->unk14++] = se;
}

void func_801A2288(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801E02DC *se;
    s32 i;

    if (p->unk14 != 0) {
        se = p->unk4[--p->unk14];
        if (se != NULL) {
            for (i = 0; i < 8; i++) {
                if (D_801E1078[i].unkA == se->unk4 && D_801E1078[i].unkC >= 0) {
                    if (D_801E1078[i].unkE != 0) {
                        SsUtKeyOffV(D_801E1078[i].unkC);
                    }
                    D_801E1078[i].unk2 = -1;
                    D_801E1078[i].unk4 = -1;
                    D_801E1078[i].unk6 = -1;
                    D_801E1078[i].unk8 = -1;
                    D_801E1078[i].unkA = -1;
                    D_801E1078[i].unkC = -1;
                    D_801E1078[i].unkE = 0;
                    D_801E1078[i].unk12 = 0;
                    D_801E1078[i].unk10 = 0;
                }
            }
            if (se->unk0 >= 0) {
                SsVabClose(se->unk0);
            }
            free3((void *)se->unk8);
            free3(se);
            p->unk4[p->unk14] = NULL;
        }
    }
}

void func_801A23B4(void) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801E02DC *se;
    s32 i;

    if (p->unk14 != 0) {
        se = p->unk4[p->unk14 - 1];
        while (se->unk6 > 0) {
            if (se != NULL) {
                for (i = 0; i < 8; i++) {
                    if (D_801E1078[i].unkA == se->unk4 && D_801E1078[i].unkC >= 0) {
                        if (D_801E1078[i].unkE != 0) {
                            SsUtKeyOffV(D_801E1078[i].unkC);
                        }
                        D_801E1078[i].unk2 = -1;
                        D_801E1078[i].unk4 = -1;
                        D_801E1078[i].unk6 = -1;
                        D_801E1078[i].unk8 = -1;
                        D_801E1078[i].unkA = -1;
                        D_801E1078[i].unkC = -1;
                        D_801E1078[i].unkE = 0;
                        D_801E1078[i].unk12 = 0;
                        D_801E1078[i].unk10 = 0;
                    }
                }
                if (se->unk0 >= 0) {
                    SsVabClose(se->unk0);
                }
                free3((void *)se->unk8);
                free3(se);
                p->unk4[--p->unk14] = NULL;
                se = p->unk4[p->unk14 - 1];
            }
        }
    }
}

void func_801A252C(void) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (D_801E1078[i].unkE != 0) {
            D_801E1078[i].unkE = 0;
            if (D_801E1078[i].unk12 != 0) {
                D_801E1078[i].unk10 = 0;
            } else {
                D_801E1078[i].unk10--;
            }
            SsUtKeyOffV(D_801E1078[i].unkC);
        }
    }
}

void func_801A25B4(s32 arg0) {
    s32 i;

    for (i = 0; i < 8; i++) {
        if (D_801E1078[i].unk0 == 1 && D_801E1078[i].unk2 == arg0) {
            break;
        }
    }
    if (i != 8) {
        D_801E1078[i].unkE = 0;
        if (D_801E1078[i].unk12 != 0) {
            D_801E1078[i].unk10 = 0;
        } else {
            D_801E1078[i].unk10--;
        }
        SsUtKeyOffV(D_801E1078[i].unkC);
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A2678);

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A2C60);

void func_801A324C(Unk_801A324C *arg0) {
    s32 a, b, c, d, e, f, g, h;

    if (arg0->unk4 >= 5) {
        a = atoi(arg0->unk8[0]);
        b = atoi(arg0->unk8[1]);
        c = atoi(arg0->unk8[2]);
        d = atoi(arg0->unk8[3]);
        e = atoi(arg0->unk8[4]);
        if (arg0->unk4 == 8) {
            f = atoi(arg0->unk8[5]);
            g = atoi(arg0->unk8[6]);
            h = atoi(arg0->unk8[7]);
        } else if (arg0->unk4 == 7) {
            f = atoi(arg0->unk8[5]);
            g = atoi(arg0->unk8[6]);
            h = 0;
        } else {
            f = 0x7F;
            g = 0x7F;
            h = 0;
        }
        func_801A2C60(a, b, c, d, f, g, h);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_80171770);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_8017178C);

void func_801A33E8(Unk_801A3B5C *arg0) {
    Unk_801E02D8 *p = &D_801E02D8;
    Unk_801E02DC *se = NULL;
    s32 i;

    if (p->unk14 == 0) {
        func_801CD54C(8, "VAB is not Ready", D_801DFD7C, 0x253);
    }
    for (i = 0; i < p->unk14; i++) {
        se = p->unk4[i];
        if (se->unk4 == 2) {
            break;
        }
        se = NULL;
    }
    if (se == NULL) {
        func_801CD54C(8, "VAB is not Ready", D_801DFD7C, 0x25C);
    }
    arg0->unk4 = *(s32 *)arg0->unk8;
    if (arg0->unk4 >= 4) {
        func_801CD54C(8, "Too Many SEQ in This SEP", D_801DFD7C, 0x260);
    }
    if (p->unk0 != NULL) {
        func_801A3B5C();
    }
    arg0->unk0 = SsSepOpen((u32 *)arg0->unk8 + 1, se->unk0, arg0->unk4);
    if (arg0->unk0 < 0) {
        func_801CD54C(8, "Can not Open Specified SEP", D_801DFD7C, 0x268);
    }
    for (i = 0; i < arg0->unk4; i++) {
        SsSepSetVol(arg0->unk0, i, D_801E6DA0.unk18, D_801E6DA0.unk18);
    }
    p->unk0 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A358C);

Unk_801A37E4 *func_801A37E4(u16 *arg0, s32 arg1, Unk_801A217C *arg2) {
    Unk_801E02D8 *p = &D_801E02D8;

    memset(arg2, 0, 0x1C);
    if (p->unk14 == 4) {
        func_801CD54C(0xD, D_801716EC, D_801DFD7C, 0x99);
    }
    arg2->unk18 = arg0[0];
    arg2->unk1A = arg0[1];
    arg0 += 2;
    arg2->unkC = arg1 - 4;
    arg2->unk4 = (s32)func_801CC898(arg1 - 4);
    if (arg2->unk4 == 0) {
        func_801CD54C(3, D_80171708, D_801DFD7C, 0xA2);
    }
    *(Unk_801A37E4 *)arg2->unk4 = *(Unk_801A37E4 *)arg0;
    arg2->unk16 = ((Unk_801A37E4 *)arg2->unk4)->unk14;
    return (Unk_801A37E4 *)arg2->unk4 + 1;
}

void func_801A3970(Unk_801A3970 *arg0) {
    if (D_801E02EC[0] == 4) {
        func_801CD54C(0xD, D_801716EC, D_801DFD7C, 0xB5);
    }
    arg0->unk14 = SsVabOpenHead(arg0->unk4, -1);
    if (arg0->unk14 < 0) {
        func_801CD54C(8, D_80171724, D_801DFD7C, 0xB9);
    }
}

void func_801A39F0(Unk_801A3970 *arg0) {
    if (SsVabTransBodyPartly(arg0->unk8, arg0->unk10, arg0->unk14) == -1) {
        func_801CD54C(8, D_8017173C, D_801DFD7C, 0xC4);
    }
    SsVabTransCompleted(1);
}

void func_801A3A54(void) {
    Unk_801E02D8 *p = &D_801E02D8;

    while (p->unk14 > 0) {
        func_801A2288();
    }
}

void func_801A3AA0(Unk_801A3B5C **arg0, u32 arg1) {
    *arg0 = func_801CC898(0xC);
    if (*arg0 == NULL) {
        func_801CD54C(3, D_80171770, D_801DFD7C, 0x241);
    }
    (*arg0)->unk0 = -1;
    (*arg0)->unk2 = -1;
    (*arg0)->unk4 = 0;
    (*arg0)->unk8 = func_801CC898(arg1);
    if ((*arg0)->unk8 == NULL) {
        func_801CD54C(3, D_8017178C, D_801DFD7C, 0x249);
    }
}

void func_801A3B5C(void) {
    Unk_801A3B5C *p = D_801E02D8.unk0;

    if (p != NULL) {
        if (p->unk0 >= 0) {
            SsSepClose(p->unk0);
        }
        if (p->unk8 != NULL) {
            free3(p->unk8);
        }
        free3(p);
        D_801E02D8.unk0 = NULL;
    }
}

void func_801A3BCC(s16 arg0) {
    Unk_801A3B5C *p = D_801E02D8.unk0;

    if (p != NULL && p->unk2 != arg0 && arg0 < p->unk4) {
        if (p->unk2 != -1) {
            func_801A3C58();
        }
        p->unk2 = arg0;
        SsSepPlay(p->unk0, arg0, 1, 0);
    }
}

void func_801A3C58(void) {
    Unk_801A3B5C *p = D_801E02D8.unk0;

    if (p != NULL && p->unk2 >= 0) {
        SsSepStop(p->unk0, p->unk2);
        SsSepSetVol(p->unk0, p->unk2, D_801E6DB8[0], D_801E6DB8[0]);
        p->unk2 = -1;
    }
}

void func_801A3CC0(s32 arg0) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801A3B5C *p = D_801E02D8.unk0;
    Unk_801A3D74 *node;

    if (p != NULL && p->unk2 >= 0) {
        node = func_801D15C8(4);
        node->unk22 = 0xD;
        node->unk24 = D_801E6DB8[0];
        node->unk26 = 0;
        func_801D1774(node, arg0 * 30);
        node->unk30 = func_801A3D74;
        node->unk34 = func_801A3D74;
        *node->unk3C = node->unk22;
        g->unk244 = func_801D14B8(node);
    }
}

void func_801A3D74(Unk_801A3D74 *arg0) {
    Unk_801A3B5C *p = D_801E02D8.unk0;
    s32 v = (arg0->unk24 < arg0->unk26) ? arg0->unk26 : arg0->unk24;

    SsSepSetVol(p->unk0, p->unk2, v, v);
}

void func_801A3DBC(Unk_801A3DBC *arg0) {
    arg0->unk4C = 0;
    D_801DFD84 = 0;
    D_801DFD88 = 0;
    D_801DFD8C = 0;
}
