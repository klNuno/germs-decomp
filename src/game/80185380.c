#include "common.h"

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
void free3(void *ptr);
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
void func_801CCBF4(Unk_801DFE80 *arg0, void *arg1);
void func_801CCCF4(Unk_801DFE80 *arg0, void *arg1);
Unk_801DFE80 *D_801DFE80;
void func_801CCDF8(Unk_801DFE80 *arg0);
s16 func_801CD000(Unk_801DFE80 *arg0);
void *func_801CC898(u32 size);
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char D_801DFCE8[];
typedef struct { s16 unk0; s16 unk2; s32 unk4; void *unk8; } Unk_801A3B5C;
typedef struct { Unk_801A3B5C *unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; } Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8[];
typedef struct { s16 unk0[3]; s16 unk6; s16 unk8[3]; s16 unkE; } Unk_801E1040;
extern Unk_801E1040 D_801E1040;
void SsSepSetVol(s16 access_num, s16 seq_num, s16 voll, s16 volr);

void func_80185380(Unk_801854B8 **arg0, u32 arg1) {
    *arg0 = func_801CC898(0x80);
    if (*arg0 == NULL) {
        func_801CD54C(3, "Error Allocating DOOR Pointer", D_801DFCE8, 0x23);
    }
    (*arg0)->unk4 = 0;
    (*arg0)->unk2 = 0;
    (*arg0)->unk6 = 1;
    (*arg0)->unk22 = 0;
    (*arg0)->unk8 = 2;
    (*arg0)->unkA = 0;
    (*arg0)->unkC = 0;
    (*arg0)->unkE = 0;
    (*arg0)->unk22 = 0;
    (*arg0)->unk24 = 0;
    (*arg0)->unk10 = 0;
    (*arg0)->unk78 = NULL;
    (*arg0)->unk7C = NULL;
    if (arg1 != 0) {
        (*arg0)->unk7C = func_801CC898(arg1);
        if ((*arg0)->unk7C == NULL) {
            func_801CD54C(3, "Error Allocating DOOR Buffer", D_801DFCE8, 0x36);
        }
    }
}

void func_801854B8(Unk_801854B8 *arg0) {
    if (arg0 != NULL) {
        free3(arg0->unk78);
        free3(arg0->unk7C);
        free3(arg0);
    }
}

void func_801854FC(void *arg0) {
    if (D_801DFE80->unkC == 0) {
        func_801CCBF4(D_801DFE80, arg0);
    } else {
        D_801DFE80->unk8 = D_801DFE80->unk4;
        func_801CCCF4(D_801DFE80, arg0);
    }
}

void func_80185548(void) {
    Unk_801DFE80 *list = D_801DFE80;
    Unk_801854B8 *item;

    while (1) {
        if (list->unkC == 0) {
            break;
        }
        item = list->unk8->unk8;
        if (item != NULL) {
            free3(item->unk78);
            free3(item->unk7C);
            free3(item);
        }
        func_801CCDF8(list);
    }
}

Unk_801854B8 *func_801855C8(u16 arg0) {
    Unk_801DFE80 *list = D_801DFE80;
    Unk_801854B8 *item;

    if (list->unkC == 0) {
        return NULL;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && item->unk0 == arg0) {
            return item;
        }
        if (func_801CD000(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/game/80185380", func_80185664);

void func_80185794(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFE80 *list = D_801DFE80;
    Unk_801854B8 *item;

    if (list->unkC == 0) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL) {
            item->unk28 = 0;
            item->unk40 = item->unk14 - arg0;
            item->unk44 = item->unk18 - arg1;
            item->unk48 = item->unk1C - arg2;
        }
        if (func_801CD000(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

void func_80185858(u16 arg0, s16 arg1) {
    Unk_801DFE80 *list = D_801DFE80;
    Unk_801854B8 *item;
    Unk_801854B8 *found;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->unk0 == arg0) {
                found = item;
                break;
            }
            if (func_801CD000(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL && found->unk6 != arg1) {
        found->unk6 = arg1;
    }
}

void func_80185918(Unk_801854B8 *arg0) {
    Unk_801E1040 *p = &D_801E1040;
    Unk_801A3B5C *q = D_801E02D8[0].unk0;
    s32 v;
    s32 t;

    p->unkE = arg0->unk24;
    if (arg0->unk22 < 2) {
        if (p->unkE < 0) {
            p->unkE = 0;
        }
    } else if (p->unkE < 0x80) {
        p->unkE = 0x80;
    }
    if (p->unkE > 0x1000) {
        p->unkE = 0x1000;
    }
    if (((s16)arg0->unk28 > 0 && arg0->unk24 >= arg0->unk26) ||
        ((s16)arg0->unk28 < 0 && arg0->unk24 <= arg0->unk26)) {
        if (arg0->unk22 != 0 && q != NULL && q->unk2 >= 0) {
            t = arg0->unk24 >> 5;
            v = 0x7F;
            if (t < 0x80) {
                v = (s16)t;
                if (t < 0) {
                    v = 0;
                }
            }
            SsSepSetVol(q->unk0, q->unk2, v, v);
        }
        if (arg0->unk22 != 10) {
            p->unk6 = 0;
        }
    }
}
