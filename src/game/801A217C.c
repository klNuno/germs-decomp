#include "common.h"

typedef struct { s32 unk0; s32 unk4; s32 unk8; s16 unkC; s16 unkE; s16 unk10; s16 unk12; } Unk_801E1078;
extern Unk_801E1078 D_801E1078[8];
void SsUtKeyOffV(s16 voice);
typedef struct { s16 unk0; s16 unk2; s32 unk4; void *unk8; } Unk_801A3B5C;
typedef struct { Unk_801A3B5C *unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; } Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
void func_801A2288(void);
void SsSepClose(s16 access_num);
void free3(void *ptr);
void func_801A3C58(void);
void SsSepPlay(s16 access_num, s16 seq_num, u8 play_mode, s16 l_count);
extern s16 D_801E6DB8[];
void SsSepStop(s16 access_num, s16 seq_num);
void SsSepSetVol(s16 access_num, s16 seq_num, s16 voll, s16 volr);
typedef struct { u8 unk0[0x24]; s16 unk24; s16 unk26; } Unk_801A3D74;
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

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_801716EC);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_80171708);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_80171724);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_8017173C);

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A217C);

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A2288);

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A23B4);

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

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A25B4);

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A2678);

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A2C60);

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A324C);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_80171770);

INCLUDE_RODATA("asm/nonmatchings/game/801A217C", D_8017178C);

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A33E8);

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A358C);

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A37E4);

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

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A3AA0);

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

INCLUDE_ASM("asm/nonmatchings/game/801A217C", func_801A3CC0);

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
