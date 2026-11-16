#include "common.h"
#include "game/types.h"

extern TimerHeap kaj_timer_queue;
void free3(void *ptr);
s32 StopRCnt(s32 spec);
s32 DisableEvent(s32 event);
s32 CloseEvent(s32 event);
s32 kaj_timer_event;
extern s16 kaj_timer_enabled[];
extern KajSystem kaj_system;
extern char D_801DFDF4[];
void *calloc3(s32 n, s32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
s32 kaj_timer_handler(void);
s32 OpenEvent(u32 desc, s32 spec, s32 mode, s32 (*func)(void));
s32 EnableEvent(s32 event);
s32 SetRCnt(u32 spec, u16 target, s32 mode);
s32 StartRCnt(u32 spec);
s32 kaj_timer_last_tick;
extern s32 kaj_timer_period[];
s16 kaj_timer_pop_due(void);
void kaj_timer_clear_wrap(void);
KajEvent *kaj_event_push(s32 arg0);
KajEvent *kaj_event_push_front(s32 arg0);
extern u32 kaj_timer_ticks[];
void EnterCriticalSection(void);
void ExitCriticalSection(void);
void kaj_timer_cancel(s32 arg0);
void *realloc3(void *ptr, s32 size);
void kaj_timer_add_alarm(s32 arg0, s32 arg1, s32 arg2);

s32 kaj_timer_handler(void) {
    TimerHeap *q;
    KajEvent *e;

    q = &kaj_timer_queue;
    if (kaj_system.timer_enabled == 0) {
        return 0;
    }
    kaj_timer_last_tick = kaj_system.timer_ticks++;
    while (kaj_timer_pop_due()) {
        if (q->popped_id < 0x50) {
            e = kaj_event_push_front(2);
        } else {
            e = kaj_event_push(2);
        }
        if (e != NULL) {
            e->unk8 = q->popped_id;
            e->unkC = q->popped_data;
        }
    }
    if (kaj_timer_last_tick != 0 && kaj_timer_last_tick % kaj_timer_period[0] == 0) {
        kaj_event_push(4);
    }
    if ((kaj_timer_last_tick ^ kaj_system.timer_ticks) < 0) {
        kaj_timer_clear_wrap();
        kaj_timer_last_tick = 0;
        kaj_system.timer_ticks = 1;
    }
    return 0;
}

void kaj_timer_add_alarm(s32 arg0, s32 arg1, s32 arg2) {
    TimerHeap *q;
    TimerHeap *p;
    TimerAlarm *e;
    TimerAlarm tmp;
    s32 n;
    s32 t;
    s32 i;
    s32 j;

    EnterCriticalSection();
    q = &kaj_timer_queue;
    if (q->full != 0) {
        n = q->capacity << 1;
        e = realloc3(kaj_timer_queue.entries, (n + 1) * sizeof(TimerAlarm));
        if (e == NULL) {
            ExitCriticalSection();
            kaj_abend(3, "Error Reallocating TIMER Queue", D_801DFDF4, 0x80);
        }
        kaj_timer_queue.entries = e;
        q->capacity = n;
        q->full = 0;
    }
    q->entries[++q->count].id = (void *)arg1;
    q->entries[q->count].data = arg2;
    t = arg0 + kaj_timer_ticks[0];
    if (t < 0) {
        q->entries[q->count].due = t + 0x80000001;
        q->entries[q->count].wrap = 1;
    } else {
        q->entries[q->count].due = t;
        q->entries[q->count].wrap = 0;
    }
    if (q->count == q->capacity) {
        q->full = 1;
    }
    p = &kaj_timer_queue;
    i = q->count;
    if (i != 1) {
        j = i >> 1;
        tmp = p->entries[i];
        while (p->entries[j].due - tmp.due > 0) {
            p->entries[i] = p->entries[j];
            i = j;
            if (i < 2) {
                break;
            }
            j = i >> 1;
        }
        p->entries[i] = tmp;
    }
    ExitCriticalSection();
}

s16 kaj_timer_pop_due(void) {
    TimerHeap *q;
    TimerHeap *p;
    TimerAlarm tmp;
    s32 i;
    s32 j;
    s32 n;

    q = &kaj_timer_queue;
    if (q->count == 0) {
        return 0;
    }
    if (q->entries[1].wrap != 0) {
        if ((s32)(kaj_timer_ticks[0] - q->entries[1].due) > 0) {
            return 0;
        }
    } else if ((s32)(kaj_timer_ticks[0] - q->entries[1].due) < 0) {
        return 0;
    }
    q->popped_id = (s32)q->entries[1].id;
    q->popped_data = q->entries[1].data;
    q->entries[1] = q->entries[q->count--];
    p = &kaj_timer_queue;
    i = 1;
    n = p->count >> i;
    if (i <= n) {
        tmp = p->entries[i];
        while (i <= n) {
            j = i * 2;
            if (j + 1 <= p->capacity && p->entries[i * 2].due - p->entries[i * 2 + 1].due > 0) {
                j++;
            }
            if (tmp.due - p->entries[j].due <= 0) {
                break;
            }
            p->entries[i] = p->entries[j];
            i = j;
        }
        p->entries[i] = tmp;
    }
    q->full = 0;
    return 1;
}

void kaj_timer_init(void) {
    kaj_timer_queue.capacity = 8;
    kaj_timer_queue.entries = calloc3(9, 0x10);
    if (kaj_timer_queue.entries == NULL) {
        kaj_abend(3, "Error Allocating TIMER Queue", D_801DFDF4, 0xB4);
    }
    kaj_timer_queue.count = 0;
    kaj_timer_queue.full = 0;
    kaj_system.timer_ticks = 0;
    kaj_system.timer_enabled = 0;
    kaj_system.timer_period = 0x258;
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
    TimerHeap *q;
    TimerHeap *p;
    TimerAlarm tmp;
    s32 k;
    s32 i;
    s32 j;
    s32 n;

    q = &kaj_timer_queue;
    EnterCriticalSection();
    for (k = 1; k <= q->count; k++) {
        if (arg0 == 0 || (s32)q->entries[k].id == arg0) {
            q->entries[k] = q->entries[q->count--];
            p = &kaj_timer_queue;
            i = k;
            n = p->count >> 1;
            if (i <= n) {
                tmp = p->entries[i];
                while (i <= n) {
                    j = i * 2;
                    if (j + 1 <= p->capacity && p->entries[i * 2].due - p->entries[i * 2 + 1].due > 0) {
                        j++;
                    }
                    if (tmp.due - p->entries[j].due <= 0) {
                        break;
                    }
                    p->entries[i] = p->entries[j];
                    i = j;
                }
                p->entries[i] = tmp;
            }
            q->full = 0;
            k--;
        }
    }
    ExitCriticalSection();
}

void kaj_timer_clear_wrap(void) {
    TimerHeap *p = &kaj_timer_queue;
    s32 i;

    for (i = 1; i <= p->count; i++) {
        if (p->entries[i].wrap != 0) {
            p->entries[i].wrap = 0;
        }
    }
}

void kaj_timer_quit(void) {
    if (kaj_timer_queue.entries != NULL) {
        free3(kaj_timer_queue.entries);
        kaj_timer_queue.entries = NULL;
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
