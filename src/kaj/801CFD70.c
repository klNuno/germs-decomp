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
extern Unk_801DFBB8 kaj_timer_queue;
void free3(void *ptr);
s32 StopRCnt(s32 spec);
s32 DisableEvent(s32 event);
s32 CloseEvent(s32 event);
s32 kaj_timer_event;
extern s16 kaj_timer_enabled[];
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
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
s32 kaj_timer_handler(void);
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
s32 kaj_timer_last_tick;
extern s32 kaj_timer_period[];
s16 kaj_timer_pop_due(void);
void kaj_timer_clear_wrap(void);
Unk_801CC1E8 *kaj_event_push(s32 arg0);
Unk_801CC1E8 *kaj_event_push_front(s32 arg0);
extern u32 kaj_timer_ticks[];
void EnterCriticalSection(void);
void ExitCriticalSection(void);
void kaj_timer_cancel(s32 arg0);
void *realloc3(void *ptr, s32 size);
void kaj_timer_add_alarm(s32 arg0, s32 arg1, s32 arg2);

s32 kaj_timer_handler(void) {
    Unk_801DFBB8 *q;
    Unk_801CC1E8 *e;

    q = &kaj_timer_queue;
    if (D_801E6DA0.unk8 == 0) {
        return 0;
    }
    kaj_timer_last_tick = D_801E6DA0.unkC++;
    while (kaj_timer_pop_due()) {
        if (q->unk10 < 0x50) {
            e = kaj_event_push_front(2);
        } else {
            e = kaj_event_push(2);
        }
        if (e != NULL) {
            e->unk8 = q->unk10;
            e->unkC = q->unk14;
        }
    }
    if (kaj_timer_last_tick != 0 && kaj_timer_last_tick % kaj_timer_period[0] == 0) {
        kaj_event_push(4);
    }
    if ((kaj_timer_last_tick ^ D_801E6DA0.unkC) < 0) {
        kaj_timer_clear_wrap();
        kaj_timer_last_tick = 0;
        D_801E6DA0.unkC = 1;
    }
    return 0;
}

void kaj_timer_add_alarm(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFBB8 *q;
    Unk_801DFBB8 *p;
    Unk_801D05F8 *e;
    Unk_801D05F8 tmp;
    s32 n;
    s32 t;
    s32 i;
    s32 j;

    EnterCriticalSection();
    q = &kaj_timer_queue;
    if (q->unkC != 0) {
        n = q->unk4 << 1;
        e = realloc3(kaj_timer_queue.unk0, (n + 1) * sizeof(Unk_801D05F8));
        if (e == NULL) {
            ExitCriticalSection();
            kaj_abend(3, "Error Reallocating TIMER Queue", D_801DFDF4, 0x80);
        }
        kaj_timer_queue.unk0 = e;
        q->unk4 = n;
        q->unkC = 0;
    }
    q->unk0[++q->unk8].unk4 = (void *)arg1;
    q->unk0[q->unk8].unk8 = arg2;
    t = arg0 + kaj_timer_ticks[0];
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
    p = &kaj_timer_queue;
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

s16 kaj_timer_pop_due(void) {
    Unk_801DFBB8 *q;
    Unk_801DFBB8 *p;
    Unk_801D05F8 tmp;
    s32 i;
    s32 j;
    s32 n;

    q = &kaj_timer_queue;
    if (q->unk8 == 0) {
        return 0;
    }
    if (q->unk0[1].unkC != 0) {
        if ((s32)(kaj_timer_ticks[0] - q->unk0[1].unk0) > 0) {
            return 0;
        }
    } else if ((s32)(kaj_timer_ticks[0] - q->unk0[1].unk0) < 0) {
        return 0;
    }
    q->unk10 = (s32)q->unk0[1].unk4;
    q->unk14 = q->unk0[1].unk8;
    q->unk0[1] = q->unk0[q->unk8--];
    p = &kaj_timer_queue;
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

void kaj_timer_init(void) {
    kaj_timer_queue.unk4 = 8;
    kaj_timer_queue.unk0 = calloc3(9, 0x10);
    if (kaj_timer_queue.unk0 == NULL) {
        kaj_abend(3, "Error Allocating TIMER Queue", D_801DFDF4, 0xB4);
    }
    kaj_timer_queue.unk8 = 0;
    kaj_timer_queue.unkC = 0;
    D_801E6DA0.unkC = 0;
    D_801E6DA0.unk8 = 0;
    D_801E6DA0.unk10 = 0x258;
    kaj_timer_event = OpenEvent(0xF2000003, 2, 0x1000, kaj_timer_handler);
    if (kaj_timer_event == -1) {
        kaj_abend(2, "Can not Create TIMER Event", D_801DFDF4, 0xBF);
    }
    if (EnableEvent(kaj_timer_event) == 0) {
        kaj_abend(2, "Can not Enable TIMER Event", D_801DFDF4, 0xC2);
    }
    SetRCnt(0xF2000003, 1, 0x1000);
    StartRCnt(0xF2000003);
}

void kaj_timer_cancel(s32 arg0) {
    Unk_801DFBB8 *q;
    Unk_801DFBB8 *p;
    Unk_801D05F8 tmp;
    s32 k;
    s32 i;
    s32 j;
    s32 n;

    q = &kaj_timer_queue;
    EnterCriticalSection();
    for (k = 1; k <= q->unk8; k++) {
        if (arg0 == 0 || (s32)q->unk0[k].unk4 == arg0) {
            q->unk0[k] = q->unk0[q->unk8--];
            p = &kaj_timer_queue;
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

void kaj_timer_clear_wrap(void) {
    Unk_801DFBB8 *p = &kaj_timer_queue;
    s32 i;

    for (i = 1; i <= p->unk8; i++) {
        if (p->unk0[i].unkC != 0) {
            p->unk0[i].unkC = 0;
        }
    }
}

void kaj_timer_quit(void) {
    if (kaj_timer_queue.unk0 != NULL) {
        free3(kaj_timer_queue.unk0);
        kaj_timer_queue.unk0 = NULL;
    }
    StopRCnt(0xF2000003);
    if (kaj_timer_event != -1) {
        DisableEvent(kaj_timer_event);
        CloseEvent(kaj_timer_event);
    }
}

void kaj_timer_enable(void) {
    kaj_timer_enabled[0] = 1;
}

void kaj_timer_disable(void) {
    kaj_timer_enabled[0] = 0;
}
