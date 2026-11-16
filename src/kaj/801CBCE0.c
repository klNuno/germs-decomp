#include "common.h"
#include "game/types.h"

s32 kaj_event_pop(s32 *event);
void kaj_event_run_tss(s32 *event);
typedef struct KajEventQueue {
    void *events;
    s32 tail;
    s32 head;
    s32 count;
    s32 capacity;
} KajEventQueue;
void *calloc3(s32 n, s32 size);
void kaj_abend(s32 code, char *msg, char *file, s32 line);
extern KajEventQueue kaj_event_queue;
extern char kaj_event_str_file[];
s32 kaj_event_alarm_id;
s32 kaj_event_pending;
void free3(void *ptr);
void kaj_tss_release(s32 index);
void *kaj_malloc(u32 size);
void *memcpy(void *dst, void *src, u32 n);
s32 kaj_event_pending_data;
void EnterCriticalSection(void);
void ExitCriticalSection(void);
extern u32 kaj_timer_ticks[];
void kaj_event_queue_grow(void);
void kaj_timer_add_alarm(s32 delay, s32 id, s32 data);
void kaj_timer_cancel(s32 id);
s32 kaj_event_set_alarm(s32 delay, s32 id, s32 data);
extern TssTable kaj_tss_table;
void kaj_tss_free(TssSlot *slot);
void kaj_tss_finish(TssSlot *slot);
extern s32 kaj_system_vsync_delta[];

void kaj_event_queue_grow(void) {
    u32 buf;
    s32 capacity;

    capacity = kaj_event_queue.capacity << 1;
    buf = (u32)kaj_malloc(capacity * sizeof(KajEvent));
    if (buf == 0) {
        kaj_abend(3, "Error Reallocating EVENT Queue", kaj_event_str_file, 0x27);
    }
    if (kaj_event_queue.tail != 0) {
        memcpy((void *)((kaj_event_queue.capacity - kaj_event_queue.head) * sizeof(KajEvent) + buf), kaj_event_queue.events, kaj_event_queue.tail * sizeof(KajEvent));
    }
    memcpy((void *)buf, (void *)(kaj_event_queue.tail * sizeof(KajEvent) + (u32)kaj_event_queue.events), (kaj_event_queue.capacity - kaj_event_queue.head) * sizeof(KajEvent));
    kaj_event_queue.head = 0;
    kaj_event_queue.tail = kaj_event_queue.capacity;
    free3(kaj_event_queue.events);
    kaj_event_queue.events = (void *)buf;
    kaj_event_queue.capacity = capacity;
}

void kaj_event_run_tss(s32 *event) {
    KajEventQueue *q;
    KajEvent *e;
    TssSlot *t;
    TssTable *p = &kaj_tss_table;
    s32 tss_id = event[2];
    s32 i;
    s32 ok;

    if (tss_id > 0 && tss_id < p->count + 1) {
        t = &p->slots[tss_id - 1];
        if ((t->step > 0 && t->cur >= t->target) || (t->step < 0 && t->cur <= t->target)) {
            t->cur = t->target;
            t->on_end(t);
            EnterCriticalSection();
            q = &kaj_event_queue;
            ok = 0;
            if (q->capacity == q->count) {
                kaj_event_queue_grow();
            }
            i = q->tail;
            q->count++;
            q->tail = (i + 1) % q->capacity;
            e = &((KajEvent *)kaj_event_queue.events)[i];
            e->type = 0x100;
            e->ticks = kaj_timer_ticks[0];
            if (e != NULL) {
                e->param0 = tss_id - 1;
                e->param1 = 0;
                e->param2 = t->type;
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
            if (t->delay == 2 && kaj_system_vsync_delta[0] < 11) {
                t->cur += t->step * kaj_system_vsync_delta[0];
            } else {
                t->cur += t->step;
            }
            kaj_event_set_alarm(t->delay, tss_id, 0);
        }
        event[0] = 0;
    }
}

s32 kaj_event_pop(s32 *event) {
    KajEvent *e;
    KajEvent *p;
    KajEventQueue *q;

    EnterCriticalSection();
    if (kaj_event_pending == 1) {
        event[1] = kaj_event_pending_data;
        event[0] = kaj_event_pending;
        kaj_event_pending = 0;
        ExitCriticalSection();
        return 1;
    }
loop:
    q = &kaj_event_queue;
    while (q->count != 0) {
        p = (KajEvent *)(q->head * sizeof(KajEvent) + (u32)q->events);
        if (p->type != 0) {
            e = p;
            goto found;
        }
        q->head = (q->head + 1) % q->capacity;
        q->count--;
    }
    e = NULL;
found:
    if (e != NULL) {
        *(KajEvent *)event = *e;
        if (e == &((KajEvent *)kaj_event_queue.events)[kaj_event_queue.head]) {
            kaj_event_queue.head = (kaj_event_queue.head + 1) % kaj_event_queue.capacity;
            kaj_event_queue.count--;
        } else {
            e->type = 0;
        }
        if (event[0] == 0) {
            goto loop;
        }
    } else {
        event[0] = 0;
    }
    ExitCriticalSection();
    return event[0];
}

KajEvent *kaj_event_push(s32 type) {
    KajEvent *e;
    s32 i;

    if (kaj_event_queue.capacity == kaj_event_queue.count) {
        kaj_event_queue_grow();
    }
    i = kaj_event_queue.tail;
    kaj_event_queue.count++;
    kaj_event_queue.tail = (i + 1) % kaj_event_queue.capacity;
    e = &((KajEvent *)kaj_event_queue.events)[i];
    e->type = type;
    e->ticks = kaj_timer_ticks[0];
    return e;
}

KajEvent *kaj_event_push_front(s32 type) {
    KajEvent *e;
    s32 i;

    if (kaj_event_queue.capacity == kaj_event_queue.count) {
        kaj_event_queue_grow();
    }
    i = (kaj_event_queue.head + kaj_event_queue.capacity - 1) % kaj_event_queue.capacity;
    kaj_event_queue.count++;
    kaj_event_queue.head = i;
    e = &((KajEvent *)kaj_event_queue.events)[i];
    e->type = type;
    e->ticks = kaj_timer_ticks[0];
    return e;
}

s32 kaj_event_get(s32 *event) {
    if (kaj_event_pop(event) == 0) {
        return 0;
    }
    if (*event == 2) {
        kaj_event_run_tss(event);
        if (*event == 0) {
            return kaj_event_get(event);
        }
    }
    return *event;
}

s32 kaj_event_set_alarm(s32 delay, s32 id, s32 data) {
    KajEventQueue *q;
    KajEvent *e;
    s32 i;

    EnterCriticalSection();
    if (id == 0) {
        id = kaj_event_alarm_id--;
        if (kaj_event_alarm_id < 0) {
            kaj_event_alarm_id = 0x3E9;
        }
    }
    if (delay == 0) {
        q = &kaj_event_queue;
        if (q->capacity == q->count) {
            kaj_event_queue_grow();
        }
        i = q->tail;
        q->count++;
        q->tail = (i + 1) % q->capacity;
        e = &((KajEvent *)kaj_event_queue.events)[i];
        e->type = 2;
        e->ticks = kaj_timer_ticks[0];
        if (e != NULL) {
            e->param0 = id;
            e->param1 = data;
        } else {
            id = -1;
        }
    } else {
        kaj_timer_add_alarm(delay, id, data);
    }
    ExitCriticalSection();
    return id;
}

void kaj_event_flush(s32 type_mask, s32 id) {
    KajEventQueue *q;
    s32 n;
    s32 i;
    s32 type;

    q = &kaj_event_queue;
    if (type_mask & 1) {
        kaj_event_pending = 0;
    }
    n = 0;
    EnterCriticalSection();
    i = q->head;
    for (; n < q->count; n++) {
        type = ((KajEvent *)q->events)[i].type;
        if (type & type_mask) {
            if (type == 0x100) {
                kaj_tss_release(((KajEvent *)q->events)[id].param0);
            }
            if (type != 2 || id == 0 || ((KajEvent *)q->events)[i].param0 == id) {
                ((KajEvent *)q->events)[i].type = 0;
            }
        }
        i = (i + 1) % q->capacity;
    }
    ExitCriticalSection();
    if (type_mask & 2) {
        kaj_timer_cancel(id);
    }
}

void kaj_event_init(void) {
    kaj_event_queue.capacity = 0x40;
    kaj_event_queue.events = calloc3(0x40, 0x14);
    if (kaj_event_queue.events == NULL) {
        kaj_abend(3, "Error Allocating EVENT Queue", kaj_event_str_file, 0xED);
    }
    kaj_event_queue.tail = 0;
    kaj_event_queue.head = 0;
    kaj_event_queue.count = 0;
    kaj_event_alarm_id = 0x3E9;
    kaj_event_pending = 0;
}

void kaj_event_quit(void) {
    if (kaj_event_queue.events != NULL) {
        free3(kaj_event_queue.events);
    }
}

void kaj_event_done(s32 *event) {
    if (event[0] == 0x100) {
        kaj_tss_release(event[2]);
    }
}
