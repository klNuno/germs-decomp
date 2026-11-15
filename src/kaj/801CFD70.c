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
    s16 unkC;
    u8 padE[0x2];
    s32 unk10;
    s32 unk14;
} Unk_801DFBB8;
extern Unk_801DFBB8 D_801DFBB8;
void free3(void *ptr);
s32 StopRCnt(s32 spec);
s32 DisableEvent(s32 event);
s32 CloseEvent(s32 event);
s32 D_801DFDEC;
extern s16 D_801E6DA8[];
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    s32 unk10;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
extern char D_801DFDF4[];
void *calloc3(s32 n, s32 size);
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
s32 func_801CFD70(void);
s32 OpenEvent(u32 desc, s32 spec, s32 mode, s32 (*func)(void));
s32 EnableEvent(s32 event);
s32 SetRCnt(u32 spec, u16 target, s32 mode);
s32 StartRCnt(u32 spec);
typedef struct Unk_801CC1E8 {
    s32 unk0;
    u32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_801CC1E8;
s32 D_801DFDF0;
extern s32 D_801E6DB0[];
s16 func_801D0134(void);
void func_801D05F8(void);
Unk_801CC1E8 *func_801CC1E8(s32 arg0);
Unk_801CC1E8 *func_801CC2AC(s32 arg0);
extern u32 D_801E6DAC[];
void EnterCriticalSection(void);
void ExitCriticalSection(void);
void func_801D0414(s32 arg0);
void *realloc3(void *ptr, s32 size);
void func_801CFEB0(s32 arg0, s32 arg1, s32 arg2);

s32 func_801CFD70(void) {
    Unk_801DFBB8 *q;
    Unk_801CC1E8 *e;

    q = &D_801DFBB8;
    if (D_801E6DA0.unk8 == 0) {
        return 0;
    }
    D_801DFDF0 = D_801E6DA0.unkC++;
    while (func_801D0134()) {
        if (q->unk10 < 0x50) {
            e = func_801CC2AC(2);
        } else {
            e = func_801CC1E8(2);
        }
        if (e != NULL) {
            e->unk8 = q->unk10;
            e->unkC = q->unk14;
        }
    }
    if (D_801DFDF0 != 0 && D_801DFDF0 % D_801E6DB0[0] == 0) {
        func_801CC1E8(4);
    }
    if ((D_801DFDF0 ^ D_801E6DA0.unkC) < 0) {
        func_801D05F8();
        D_801DFDF0 = 0;
        D_801E6DA0.unkC = 1;
    }
    return 0;
}

void func_801CFEB0(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFBB8 *q;
    Unk_801DFBB8 *p;
    Unk_801D05F8 *e;
    Unk_801D05F8 tmp;
    s32 n;
    s32 t;
    s32 i;
    s32 j;

    EnterCriticalSection();
    q = &D_801DFBB8;
    if (q->unkC != 0) {
        n = q->unk4 << 1;
        e = realloc3(D_801DFBB8.unk0, (n + 1) * sizeof(Unk_801D05F8));
        if (e == NULL) {
            ExitCriticalSection();
            func_801CD54C(3, "Error Reallocating TIMER Queue", D_801DFDF4, 0x80);
        }
        D_801DFBB8.unk0 = e;
        q->unk4 = n;
        q->unkC = 0;
    }
    q->unk0[++q->unk8].unk4 = (void *)arg1;
    q->unk0[q->unk8].unk8 = arg2;
    t = arg0 + D_801E6DAC[0];
    if (t < 0) {
        q->unk0[q->unk8].unk0 = t + 0x80000001;
        q->unk0[q->unk8].unkC = 1;
    } else {
        q->unk0[q->unk8].unk0 = t;
        q->unk0[q->unk8].unkC = 0;
    }
    if (q->unk8 == q->unk4) {
        q->unkC = 1;
    }
    p = &D_801DFBB8;
    i = q->unk8;
    if (i != 1) {
        j = i >> 1;
        tmp = p->unk0[i];
        while (p->unk0[j].unk0 - tmp.unk0 > 0) {
            p->unk0[i] = p->unk0[j];
            i = j;
            if (i < 2) {
                break;
            }
            j = i >> 1;
        }
        p->unk0[i] = tmp;
    }
    ExitCriticalSection();
}

s16 func_801D0134(void) {
    Unk_801DFBB8 *q;
    Unk_801DFBB8 *p;
    Unk_801D05F8 tmp;
    s32 i;
    s32 j;
    s32 n;

    q = &D_801DFBB8;
    if (q->unk8 == 0) {
        return 0;
    }
    if (q->unk0[1].unkC != 0) {
        if ((s32)(D_801E6DAC[0] - q->unk0[1].unk0) > 0) {
            return 0;
        }
    } else if ((s32)(D_801E6DAC[0] - q->unk0[1].unk0) < 0) {
        return 0;
    }
    q->unk10 = (s32)q->unk0[1].unk4;
    q->unk14 = q->unk0[1].unk8;
    q->unk0[1] = q->unk0[q->unk8--];
    p = &D_801DFBB8;
    i = 1;
    n = p->unk8 >> i;
    if (i <= n) {
        tmp = p->unk0[i];
        while (i <= n) {
            j = i * 2;
            if (j + 1 <= p->unk4 && p->unk0[i * 2].unk0 - p->unk0[i * 2 + 1].unk0 > 0) {
                j++;
            }
            if (tmp.unk0 - p->unk0[j].unk0 <= 0) {
                break;
            }
            p->unk0[i] = p->unk0[j];
            i = j;
        }
        p->unk0[i] = tmp;
    }
    q->unkC = 0;
    return 1;
}

void func_801D0300(void) {
    D_801DFBB8.unk4 = 8;
    D_801DFBB8.unk0 = calloc3(9, 0x10);
    if (D_801DFBB8.unk0 == NULL) {
        func_801CD54C(3, "Error Allocating TIMER Queue", D_801DFDF4, 0xB4);
    }
    D_801DFBB8.unk8 = 0;
    D_801DFBB8.unkC = 0;
    D_801E6DA0.unkC = 0;
    D_801E6DA0.unk8 = 0;
    D_801E6DA0.unk10 = 0x258;
    D_801DFDEC = OpenEvent(0xF2000003, 2, 0x1000, func_801CFD70);
    if (D_801DFDEC == -1) {
        func_801CD54C(2, "Can not Create TIMER Event", D_801DFDF4, 0xBF);
    }
    if (EnableEvent(D_801DFDEC) == 0) {
        func_801CD54C(2, "Can not Enable TIMER Event", D_801DFDF4, 0xC2);
    }
    SetRCnt(0xF2000003, 1, 0x1000);
    StartRCnt(0xF2000003);
}

void func_801D0414(s32 arg0) {
    Unk_801DFBB8 *q;
    Unk_801DFBB8 *p;
    Unk_801D05F8 tmp;
    s32 k;
    s32 i;
    s32 j;
    s32 n;

    q = &D_801DFBB8;
    EnterCriticalSection();
    for (k = 1; k <= q->unk8; k++) {
        if (arg0 == 0 || (s32)q->unk0[k].unk4 == arg0) {
            q->unk0[k] = q->unk0[q->unk8--];
            p = &D_801DFBB8;
            i = k;
            n = p->unk8 >> 1;
            if (i <= n) {
                tmp = p->unk0[i];
                while (i <= n) {
                    j = i * 2;
                    if (j + 1 <= p->unk4 && p->unk0[i * 2].unk0 - p->unk0[i * 2 + 1].unk0 > 0) {
                        j++;
                    }
                    if (tmp.unk0 - p->unk0[j].unk0 <= 0) {
                        break;
                    }
                    p->unk0[i] = p->unk0[j];
                    i = j;
                }
                p->unk0[i] = tmp;
            }
            q->unkC = 0;
            k--;
        }
    }
    ExitCriticalSection();
}

void func_801D05F8(void) {
    Unk_801DFBB8 *p = &D_801DFBB8;
    s32 i;

    for (i = 1; i <= p->unk8; i++) {
        if (p->unk0[i].unkC != 0) {
            p->unk0[i].unkC = 0;
        }
    }
}

void func_801D064C(void) {
    if (D_801DFBB8.unk0 != NULL) {
        free3(D_801DFBB8.unk0);
        D_801DFBB8.unk0 = NULL;
    }
    StopRCnt(0xF2000003);
    if (D_801DFDEC != -1) {
        DisableEvent(D_801DFDEC);
        CloseEvent(D_801DFDEC);
    }
}

void func_801D06B4(void) {
    D_801E6DA8[0] = 1;
}

void func_801D06C4(void) {
    D_801E6DA8[0] = 0;
}
