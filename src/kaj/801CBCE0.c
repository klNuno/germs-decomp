#include "common.h"
#include "game/types.h"

s32 kaj_event_pop(s32 *arg0);
void kaj_event_run_tss(s32 *arg0);
typedef struct Unk_801DFAD4 {
    void *unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_801DFAD4;
void *calloc3(s32 n, s32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern Unk_801DFAD4 kaj_event_queue;
extern char D_801DFDB4[];
s32 kaj_event_alarm_id;
s32 kaj_event_pending;
void free3(void *ptr);
void kaj_tss_release(s32 arg0);
void *kaj_malloc(u32 size);
void *memcpy(void *dst, void *src, u32 n);
s32 kaj_event_pending_data;
void EnterCriticalSection(void);
void ExitCriticalSection(void);
extern u32 kaj_timer_ticks[];
void kaj_event_queue_grow(void);
void kaj_timer_add_alarm(s32 arg0, s32 arg1, s32 arg2);
void kaj_timer_cancel(s32 arg0);
s32 kaj_event_set_alarm(s32 arg0, s32 arg1, s32 arg2);
extern TssTable kaj_tss_table;
void kaj_tss_free(TssSlot *arg0);
void kaj_tss_finish(TssSlot *arg0);
extern s32 D_801E6DB4[];

void kaj_event_queue_grow(void) {
    u32 q;
    s32 n;

    n = kaj_event_queue.unk10 << 1;
    q = (u32)kaj_malloc(n * sizeof(KajEvent));
    if (q == 0) {
        kaj_abend(3, "Error Reallocating EVENT Queue", D_801DFDB4, 0x27);
    }
    if (kaj_event_queue.unk4 != 0) {
        memcpy((void *)((kaj_event_queue.unk10 - kaj_event_queue.unk8) * sizeof(KajEvent) + q), kaj_event_queue.unk0, kaj_event_queue.unk4 * sizeof(KajEvent));
    }
    memcpy((void *)q, (void *)(kaj_event_queue.unk4 * sizeof(KajEvent) + (u32)kaj_event_queue.unk0), (kaj_event_queue.unk10 - kaj_event_queue.unk8) * sizeof(KajEvent));
    kaj_event_queue.unk8 = 0;
    kaj_event_queue.unk4 = kaj_event_queue.unk10;
    free3(kaj_event_queue.unk0);
    kaj_event_queue.unk0 = (void *)q;
    kaj_event_queue.unk10 = n;
}

void kaj_event_run_tss(s32 *arg0) {
    Unk_801DFAD4 *q;
    KajEvent *e;
    TssSlot *t;
    TssTable *p = &kaj_tss_table;
    s32 n = arg0[2];
    s32 i;
    s32 ok;

    if (n > 0 && n < p->count + 1) {
        t = &p->slots[n - 1];
        if ((t->step > 0 && t->cur >= t->target) || (t->step < 0 && t->cur <= t->target)) {
            t->cur = t->target;
            t->on_end(t);
            EnterCriticalSection();
            q = &kaj_event_queue;
            ok = 0;
            if (q->unk10 == q->unkC) {
                kaj_event_queue_grow();
            }
            i = q->unk4;
            q->unkC++;
            q->unk4 = (i + 1) % q->unk10;
            e = &((KajEvent *)kaj_event_queue.unk0)[i];
            e->type = 0x100;
            e->ticks = kaj_timer_ticks[0];
            if (e != NULL) {
                e->unk8 = n - 1;
                e->unkC = 0;
                e->unk10 = t->type;
                ok = 1;
            }
            ExitCriticalSection();
            if (ok) {
                kaj_tss_finish(t);
            } else {
                kaj_tss_free(t);
            }
        } else {
            t->on_step(t);
            if (t->delay == 2 && D_801E6DB4[0] < 11) {
                t->cur += t->step * D_801E6DB4[0];
            } else {
                t->cur += t->step;
            }
            kaj_event_set_alarm(t->delay, n, 0);
        }
        arg0[0] = 0;
    }
}

s32 kaj_event_pop(s32 *arg0) {
    KajEvent *e;
    KajEvent *p;
    Unk_801DFAD4 *q;

    EnterCriticalSection();
    if (kaj_event_pending == 1) {
        arg0[1] = kaj_event_pending_data;
        arg0[0] = kaj_event_pending;
        kaj_event_pending = 0;
        ExitCriticalSection();
        return 1;
    }
loop:
    q = &kaj_event_queue;
    while (q->unkC != 0) {
        p = (KajEvent *)(q->unk8 * sizeof(KajEvent) + (u32)q->unk0);
        if (p->type != 0) {
            e = p;
            goto found;
        }
        q->unk8 = (q->unk8 + 1) % q->unk10;
        q->unkC--;
    }
    e = NULL;
found:
    if (e != NULL) {
        *(KajEvent *)arg0 = *e;
        if (e == &((KajEvent *)kaj_event_queue.unk0)[kaj_event_queue.unk8]) {
            kaj_event_queue.unk8 = (kaj_event_queue.unk8 + 1) % kaj_event_queue.unk10;
            kaj_event_queue.unkC--;
        } else {
            e->type = 0;
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

KajEvent *kaj_event_push(s32 arg0) {
    KajEvent *e;
    s32 i;

    if (kaj_event_queue.unk10 == kaj_event_queue.unkC) {
        kaj_event_queue_grow();
    }
    i = kaj_event_queue.unk4;
    kaj_event_queue.unkC++;
    kaj_event_queue.unk4 = (i + 1) % kaj_event_queue.unk10;
    e = &((KajEvent *)kaj_event_queue.unk0)[i];
    e->type = arg0;
    e->ticks = kaj_timer_ticks[0];
    return e;
}

KajEvent *kaj_event_push_front(s32 arg0) {
    KajEvent *e;
    s32 i;

    if (kaj_event_queue.unk10 == kaj_event_queue.unkC) {
        kaj_event_queue_grow();
    }
    i = (kaj_event_queue.unk8 + kaj_event_queue.unk10 - 1) % kaj_event_queue.unk10;
    kaj_event_queue.unkC++;
    kaj_event_queue.unk8 = i;
    e = &((KajEvent *)kaj_event_queue.unk0)[i];
    e->type = arg0;
    e->ticks = kaj_timer_ticks[0];
    return e;
}

s32 kaj_event_get(s32 *arg0) {
    if (kaj_event_pop(arg0) == 0) {
        return 0;
    }
    if (*arg0 == 2) {
        kaj_event_run_tss(arg0);
        if (*arg0 == 0) {
            return kaj_event_get(arg0);
        }
    }
    return *arg0;
}

s32 kaj_event_set_alarm(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFAD4 *q;
    KajEvent *e;
    s32 i;

    EnterCriticalSection();
    if (arg1 == 0) {
        arg1 = kaj_event_alarm_id--;
        if (kaj_event_alarm_id < 0) {
            kaj_event_alarm_id = 0x3E9;
        }
    }
    if (arg0 == 0) {
        q = &kaj_event_queue;
        if (q->unk10 == q->unkC) {
            kaj_event_queue_grow();
        }
        i = q->unk4;
        q->unkC++;
        q->unk4 = (i + 1) % q->unk10;
        e = &((KajEvent *)kaj_event_queue.unk0)[i];
        e->type = 2;
        e->ticks = kaj_timer_ticks[0];
        if (e != NULL) {
            e->unk8 = arg1;
            e->unkC = arg2;
        } else {
            arg1 = -1;
        }
    } else {
        kaj_timer_add_alarm(arg0, arg1, arg2);
    }
    ExitCriticalSection();
    return arg1;
}

void kaj_event_flush(s32 arg0, s32 arg1) {
    Unk_801DFAD4 *q;
    s32 n;
    s32 i;
    s32 t;

    q = &kaj_event_queue;
    if (arg0 & 1) {
        kaj_event_pending = 0;
    }
    n = 0;
    EnterCriticalSection();
    i = q->unk8;
    for (; n < q->unkC; n++) {
        t = ((KajEvent *)q->unk0)[i].type;
        if (t & arg0) {
            if (t == 0x100) {
                kaj_tss_release(((KajEvent *)q->unk0)[arg1].unk8);
            }
            if (t != 2 || arg1 == 0 || ((KajEvent *)q->unk0)[i].unk8 == arg1) {
                ((KajEvent *)q->unk0)[i].type = 0;
            }
        }
        i = (i + 1) % q->unk10;
    }
    ExitCriticalSection();
    if (arg0 & 2) {
        kaj_timer_cancel(arg1);
    }
}

void kaj_event_init(void) {
    kaj_event_queue.unk10 = 0x40;
    kaj_event_queue.unk0 = calloc3(0x40, 0x14);
    if (kaj_event_queue.unk0 == NULL) {
        kaj_abend(3, "Error Allocating EVENT Queue", D_801DFDB4, 0xED);
    }
    kaj_event_queue.unk4 = 0;
    kaj_event_queue.unk8 = 0;
    kaj_event_queue.unkC = 0;
    kaj_event_alarm_id = 0x3E9;
    kaj_event_pending = 0;
}

void kaj_event_quit(void) {
    if (kaj_event_queue.unk0 != NULL) {
        free3(kaj_event_queue.unk0);
    }
}

void kaj_event_done(s32 *arg0) {
    if (arg0[0] == 0x100) {
        kaj_tss_release(arg0[2]);
    }
}
