#include "common.h"

s32 func_801CC02C(s32 *arg0);
void func_801CBDF0(s32 *arg0);
typedef struct Unk_801DFAD4 {
    void *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_801DFAD4;
void *calloc3(s32 n, s32 size);
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern Unk_801DFAD4 D_801DFAD4;
extern char D_801DFDB4[];
s32 D_801DFFC0;
s32 D_801DFFC4;
void free3(void *ptr);
void func_801D1300(s32 arg0);
typedef struct Unk_801CC1E8 {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_801CC1E8;
void *func_801CC898(u32 size);
void *memcpy(void *dst, void *src, u32 n);
s32 D_801DFFC8;
void EnterCriticalSection(void);
void ExitCriticalSection(void);
extern u32 D_801E6DAC[];
void func_801CBCE0(void);
void func_801CFEB0(s32 arg0, s32 arg1, s32 arg2);
void func_801D0414(s32 arg0);
s32 func_801CC3DC(s32 arg0, s32 arg1, s32 arg2);
typedef struct Unk_801D12A8 {
    struct Unk_801D12A8 *unk0;
    u8 unk4[0x1C];
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    s32 unk2C;
    void (*unk30)(struct Unk_801D12A8 *);
    void (*unk34)(struct Unk_801D12A8 *);
    void (*unk38)(struct Unk_801D12A8 *);
    void *unk3C;
} Unk_801D12A8;
typedef struct {
    s32 unk0;
    Unk_801D12A8 *unk4;
    Unk_801D12A8 *unk8;
    Unk_801D12A8 *unkC;
} Unk_801DFBD0;
extern Unk_801DFBD0 D_801DFBD0;
void func_801D12A8(Unk_801D12A8 *arg0);
void func_801D14F0(Unk_801D12A8 *arg0);
extern s32 D_801E6DB4[];

void func_801CBCE0(void) {
    u32 q;
    s32 n;

    n = D_801DFAD4.unk10 << 1;
    q = (u32)func_801CC898(n * sizeof(Unk_801CC1E8));
    if (q == 0) {
        func_801CD54C(3, "Error Reallocating EVENT Queue", D_801DFDB4, 0x27);
    }
    if (D_801DFAD4.unk4 != 0) {
        memcpy((void *)((D_801DFAD4.unk10 - D_801DFAD4.unk8) * sizeof(Unk_801CC1E8) + q), D_801DFAD4.unk0, D_801DFAD4.unk4 * sizeof(Unk_801CC1E8));
    }
    memcpy((void *)q, (void *)(D_801DFAD4.unk4 * sizeof(Unk_801CC1E8) + (u32)D_801DFAD4.unk0), (D_801DFAD4.unk10 - D_801DFAD4.unk8) * sizeof(Unk_801CC1E8));
    D_801DFAD4.unk8 = 0;
    D_801DFAD4.unk4 = D_801DFAD4.unk10;
    free3(D_801DFAD4.unk0);
    D_801DFAD4.unk0 = (void *)q;
    D_801DFAD4.unk10 = n;
}

void func_801CBDF0(s32 *arg0) {
    Unk_801DFAD4 *q;
    Unk_801CC1E8 *e;
    Unk_801D12A8 *t;
    Unk_801DFBD0 *p = &D_801DFBD0;
    s32 n = arg0[2];
    s32 i;
    s32 ok;

    if (n > 0 && n < p->unk0 + 1) {
        t = &p->unk4[n - 1];
        if ((t->unk28 > 0 && t->unk24 >= t->unk26) || (t->unk28 < 0 && t->unk24 <= t->unk26)) {
            t->unk24 = t->unk26;
            t->unk34(t);
            EnterCriticalSection();
            q = &D_801DFAD4;
            ok = 0;
            if (q->unk10 == q->unkC) {
                func_801CBCE0();
            }
            i = q->unk4;
            q->unkC++;
            q->unk4 = (i + 1) % q->unk10;
            e = &((Unk_801CC1E8 *)D_801DFAD4.unk0)[i];
            e->unk0 = 0x100;
            e->unk4 = D_801E6DAC[0];
            if (e != NULL) {
                e->unk8 = n - 1;
                e->unkC = 0;
                e->unk10 = t->unk22;
                ok = 1;
            }
            ExitCriticalSection();
            if (ok) {
                func_801D14F0(t);
            } else {
                func_801D12A8(t);
            }
        } else {
            t->unk30(t);
            if (t->unk2C == 2 && D_801E6DB4[0] < 11) {
                t->unk24 += t->unk28 * D_801E6DB4[0];
            } else {
                t->unk24 += t->unk28;
            }
            func_801CC3DC(t->unk2C, n, 0);
        }
        arg0[0] = 0;
    }
}

s32 func_801CC02C(s32 *arg0) {
    Unk_801CC1E8 *e;
    Unk_801CC1E8 *p;
    Unk_801DFAD4 *q;

    EnterCriticalSection();
    if (D_801DFFC4 == 1) {
        arg0[1] = D_801DFFC8;
        arg0[0] = D_801DFFC4;
        D_801DFFC4 = 0;
        ExitCriticalSection();
        return 1;
    }
loop:
    q = &D_801DFAD4;
    while (q->unkC != 0) {
        p = (Unk_801CC1E8 *)(q->unk8 * sizeof(Unk_801CC1E8) + (u32)q->unk0);
        if (p->unk0 != 0) {
            e = p;
            goto found;
        }
        q->unk8 = (q->unk8 + 1) % q->unk10;
        q->unkC--;
    }
    e = NULL;
found:
    if (e != NULL) {
        *(Unk_801CC1E8 *)arg0 = *e;
        if (e == &((Unk_801CC1E8 *)D_801DFAD4.unk0)[D_801DFAD4.unk8]) {
            D_801DFAD4.unk8 = (D_801DFAD4.unk8 + 1) % D_801DFAD4.unk10;
            D_801DFAD4.unkC--;
        } else {
            e->unk0 = 0;
        }
        if (arg0[0] == 0) {
            goto loop;
        }
    } else {
        arg0[0] = 0;
    }
    ExitCriticalSection();
    return arg0[0];
}

INCLUDE_ASM("asm/nonmatchings/kaj/801CBCE0", func_801CC1E8);

INCLUDE_ASM("asm/nonmatchings/kaj/801CBCE0", func_801CC2AC);

s32 func_801CC378(s32 *arg0) {
    if (func_801CC02C(arg0) == 0) {
        return 0;
    }
    if (*arg0 == 2) {
        func_801CBDF0(arg0);
        if (*arg0 == 0) {
            return func_801CC378(arg0);
        }
    }
    return *arg0;
}

s32 func_801CC3DC(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFAD4 *q;
    Unk_801CC1E8 *e;
    s32 i;

    EnterCriticalSection();
    if (arg1 == 0) {
        arg1 = D_801DFFC0--;
        if (D_801DFFC0 < 0) {
            D_801DFFC0 = 0x3E9;
        }
    }
    if (arg0 == 0) {
        q = &D_801DFAD4;
        if (q->unk10 == q->unkC) {
            func_801CBCE0();
        }
        i = q->unk4;
        q->unkC++;
        q->unk4 = (i + 1) % q->unk10;
        e = &((Unk_801CC1E8 *)D_801DFAD4.unk0)[i];
        e->unk0 = 2;
        e->unk4 = D_801E6DAC[0];
        if (e != NULL) {
            e->unk8 = arg1;
            e->unkC = arg2;
        } else {
            arg1 = -1;
        }
    } else {
        func_801CFEB0(arg0, arg1, arg2);
    }
    ExitCriticalSection();
    return arg1;
}

void func_801CC514(s32 arg0, s32 arg1) {
    Unk_801DFAD4 *q;
    s32 n;
    s32 i;
    s32 t;

    q = &D_801DFAD4;
    if (arg0 & 1) {
        D_801DFFC4 = 0;
    }
    n = 0;
    EnterCriticalSection();
    i = q->unk8;
    for (; n < q->unkC; n++) {
        t = ((Unk_801CC1E8 *)q->unk0)[i].unk0;
        if (t & arg0) {
            if (t == 0x100) {
                func_801D1300(((Unk_801CC1E8 *)q->unk0)[arg1].unk8);
            }
            if (t != 2 || arg1 == 0 || ((Unk_801CC1E8 *)q->unk0)[i].unk8 == arg1) {
                ((Unk_801CC1E8 *)q->unk0)[i].unk0 = 0;
            }
        }
        i = (i + 1) % q->unk10;
    }
    ExitCriticalSection();
    if (arg0 & 2) {
        func_801D0414(arg1);
    }
}

void func_801CC68C(void) {
    D_801DFAD4.unk10 = 0x40;
    D_801DFAD4.unk0 = calloc3(0x40, 0x14);
    if (D_801DFAD4.unk0 == NULL) {
        func_801CD54C(3, "Error Allocating EVENT Queue", D_801DFDB4, 0xED);
    }
    D_801DFAD4.unk4 = 0;
    D_801DFAD4.unk8 = 0;
    D_801DFAD4.unkC = 0;
    D_801DFFC0 = 0x3E9;
    D_801DFFC4 = 0;
}

void func_801CC708(void) {
    if (D_801DFAD4.unk0 != NULL) {
        free3(D_801DFAD4.unk0);
    }
}

void func_801CC734(s32 *arg0) {
    if (arg0[0] == 0x100) {
        func_801D1300(arg0[2]);
    }
}
