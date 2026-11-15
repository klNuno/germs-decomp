#include "common.h"

typedef struct {
    s32 unk0;
    void *unk4;
    s32 unk8;
    s32 unkC;
} Unk_801D05F8;
typedef struct {
    Unk_801D05F8 *unk0;
    s32 unk4;
    s32 unk8;
} Unk_801DFBB8;
typedef struct {
    u8 unk0[0x44];
    void *unk44;
    void *unk48;
    void *unk4C;
} Unk_801D0E58;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC[1][7];
} Unk_801D1044;

INCLUDE_ASM("asm/nonmatchings/kaj/801D0880", func_801D0880);

void func_801D0E58(Unk_801DFBB8 *arg0, Unk_801D05F8 *arg1, Unk_801D0E58 *arg2, u8 *arg3, s32 arg4) {
    s32 i;

    arg0->unk4 = 0;
    arg0->unk0 = arg1;
    arg0->unk8 = arg4;
    for (i = 0; i < arg4;) {
        i++;
        arg1->unk0 = 0x80000000;
        arg1->unkC = -1;
        arg1->unk4 = arg2;
        arg2->unk44 = arg3;
        arg1->unk8 = 0;
        arg1++;
        arg2++;
        arg3 += 0x28;
    }
}

Unk_801D05F8 *func_801D0EB8(Unk_801DFBB8 *arg0, s32 arg1) {
    Unk_801D05F8 *p;
    s32 i;

    p = arg0->unk0;
    for (i = 0; i < arg0->unk4; i++, p++) {
        if (arg1 == p->unkC) {
            break;
        }
    }
    if (i == arg0->unk4) {
        return NULL;
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D0880", func_801D0F04);

Unk_801D05F8 *func_801D0FB8(Unk_801DFBB8 *arg0, s32 arg1) {
    Unk_801D05F8 *p;
    s32 i;

    p = arg0->unk0;
    for (i = 0; i < arg0->unk4; i++, p++) {
        if (p->unkC == arg1) {
            break;
        }
    }
    if (i < arg0->unk4) {
        p->unkC = -1;
        if (i == arg0->unk4 - 1) {
            do {
                p--;
                arg0->unk4--;
            } while (p->unkC == -1);
        }
        return p;
    }
    return NULL;
}

s32 *func_801D1044(Unk_801D1044 *arg0, s32 *arg1, s32 arg2) {
    s32 *p;
    s32 n;

    p = arg0->unkC[0];
    for (n = arg0->unk8; n > 0; n--) {
        if (arg2 == *arg1) {
            break;
        }
        p += 7;
        arg1++;
    }
    if (n == 0) {
        return NULL;
    }
    return p;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D0880", func_801D1088);
