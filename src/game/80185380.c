#include "common.h"

typedef struct Unk_801854B8 {
    u16 unk0;
    u8 unk2[0x76];
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

INCLUDE_ASM("asm/nonmatchings/game/80185380", func_80185380);

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

INCLUDE_ASM("asm/nonmatchings/game/80185380", func_80185794);

INCLUDE_ASM("asm/nonmatchings/game/80185380", func_80185858);

INCLUDE_ASM("asm/nonmatchings/game/80185380", func_80185918);
