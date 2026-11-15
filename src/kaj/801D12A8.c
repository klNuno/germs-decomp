#include "common.h"

typedef struct Unk_801D12A8 {
    struct Unk_801D12A8 *unk0;
    u8 unk4[0x34];
    s32 unk38;
    void *unk3C;
} Unk_801D12A8;
typedef struct {
    s32 unk0;
    Unk_801D12A8 *unk4;
    Unk_801D12A8 *unk8;
    Unk_801D12A8 *unkC;
} Unk_801DFBD0;
extern Unk_801DFBD0 D_801DFBD0;
void free3(void *ptr);
typedef struct {
    u8 unk0[0x20];
    s16 unk20;
} Unk_801D14B8;
s32 func_801CC3DC(s32 a, s32 b, s32 c);
void *func_801CC898(u32 size);
void func_801D12A8(Unk_801D12A8 *arg0);
typedef struct {
    u8 unk0[0x24];
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s32 unk2C;
} Unk_801D1774;
typedef struct {
    u8 unk0[0x19];
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C[0x68];
    u32 *unk84;
    s32 unk88;
} Unk_801E6FF0;
extern Unk_801E6FF0 D_801E6FF0[2];
void SetDispMask(s32 mask);
Unk_801E6FF0 *D_801DFFD0;
s32 func_801D1E30(void);
void func_801D1E20(s32 arg0);
void ClearOTagR(u32 *ot, s32 n);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_801D1BD4;
s32 ClearImage(Unk_801D1BD4 *rect, s32 r, s32 g, s32 b);
s32 DrawSync(s32 mode);

void func_801D12A8(Unk_801D12A8 *arg0) {
    Unk_801DFBD0 *p = &D_801DFBD0;

    if (arg0->unk3C != arg0) {
        free3(arg0->unk3C);
    }
    arg0->unk3C = 0;
    arg0->unk0 = p->unk8;
    p->unk8 = arg0;
}

void func_801D1300(s32 arg0) {
    Unk_801DFBD0 *p = &D_801DFBD0;
    Unk_801D12A8 *prev = 0;
    Unk_801D12A8 *node = &p->unk4[arg0];
    Unk_801D12A8 *cur;

    for (cur = p->unkC; cur != 0; cur = cur->unk0) {
        if (cur == node) {
            if (prev == 0) {
                p->unkC = cur->unk0;
            } else {
                prev->unk0 = cur->unk0;
            }
            node->unk0 = p->unk8;
            p->unk8 = node;
            return;
        }
        prev = cur;
    }
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D12A8", func_801D137C);

s32 func_801D14B8(Unk_801D14B8 *arg0) {
    func_801CC3DC(1, arg0->unk20 + 1, 0);
    return arg0->unk20;
}

void func_801D14F0(Unk_801D12A8 *arg0) {
    Unk_801DFBD0 *p = &D_801DFBD0;

    if (arg0->unk3C != arg0) {
        free3(arg0->unk3C);
    }
    arg0->unk3C = 0;
    arg0->unk0 = p->unkC;
    p->unkC = arg0;
}

void *func_801D1548(s32 arg0, s32 arg1) {
    u8 *base;
    u8 *p;
    u8 *next;
    s32 i;

    base = func_801CC898(arg0 * arg1);
    if (base == 0) {
        return 0;
    }
    p = base;
    next = base + arg1;
    for (i = 1; i < arg0; i++) {
        *(u8 **)p = next;
        p = next;
        next = p + arg1;
    }
    *(u8 **)p = 0;
    return base;
}

Unk_801D12A8 *func_801D15C8(u32 arg0) {
    Unk_801DFBD0 *p = &D_801DFBD0;
    Unk_801D12A8 *node;

    if (p->unk8 == 0) {
        return 0;
    }
    node = p->unk8;
    p->unk8 = node->unk0;
    if (arg0 > 0x20) {
        node->unk3C = func_801CC898(arg0);
        if (node->unk3C == 0) {
            node->unk3C = node;
            func_801D12A8(node);
            return 0;
        }
    } else {
        node->unk3C = node;
    }
    node->unk38 = 0;
    return node;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D12A8", func_801D164C);

void func_801D172C(void) {
    Unk_801DFBD0 *p = &D_801DFBD0;

    if (p->unk4 != 0) {
        free3(p->unk4);
        p->unk4 = 0;
    }
    p->unk8 = 0;
    p->unkC = 0;
}

void func_801D1774(Unk_801D1774 *arg0, s32 arg1) {
    s32 d = arg0->unk26 - arg0->unk24;
    s32 t;
    s32 q;

    if (arg1 == 0 || d == 0) {
        arg0->unk28 = d;
        arg0->unk2C = 0;
        return;
    }
    t = d;
    if (d < 0) {
        t = -d;
    }
    q = (t + (arg1 >> 1)) / arg1;
    if (d < 0) {
        q = -q;
    }
    arg0->unk28 = q;
    arg0->unk2C = 2;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D12A8", func_801D17F0);

void func_801D19D0(void) {
    free3(D_801E6FF0[0].unk84);
    free3(D_801E6FF0[1].unk84);
    free3((void *)D_801E6FF0[0].unk88);
    free3((void *)D_801E6FF0[1].unk88);
    SetDispMask(0);
}

s32 func_801D1A2C(void) {
    return func_801D1E30() - D_801DFFD0->unk88;
}

Unk_801E6FF0 *func_801D1A58(void) {
    Unk_801E6FF0 *p = D_801E6FF0;

    if (D_801DFFD0 == p) {
        p = &D_801E6FF0[1];
    }
    D_801DFFD0 = p;
    func_801D1E20(p->unk88);
    ClearOTagR(D_801DFFD0->unk84, 0x2000);
    return D_801DFFD0;
}

INCLUDE_ASM("asm/nonmatchings/kaj/801D12A8", func_801D1AAC);

void func_801D1BAC(u8 arg0, u8 arg1, u8 arg2) {
    Unk_801E6FF0 *p = D_801E6FF0;

    p->unk19 = arg0;
    p->unk1A = arg1;
    p->unk1B = arg2;
    p++;
    p->unk19 = arg0;
    p->unk1A = arg1;
    p->unk1B = arg2;
}

void func_801D1BD4(void) {
    Unk_801D1BD4 rect;

    rect.unk0 = 0;
    rect.unk2 = 0;
    rect.unk4 = 0x140;
    rect.unk6 = 0x1E0;
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
}
