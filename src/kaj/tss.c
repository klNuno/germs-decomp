#include "common.h"
#include "kaj/tss.h"
#include "kaj/event.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "psyq/libapi.h"

/*
 * The task slots (TSS).
 *
 * File boundaries: likely (docs/layout.md): Sony code before; tss.c asserts.
 */

extern TssTable kaj_tss_table;
extern char kaj_tss_str_file[];

void kaj_tss_free(TssSlot *slot) {
    TssTable *p = &kaj_tss_table;

    if (slot->data != slot) {
        free3(slot->data);
    }
    slot->data = 0;
    slot->next = p->free_list;
    p->free_list = slot;
}

void kaj_tss_release(s32 index) {
    TssTable *p = &kaj_tss_table;
    TssSlot *prev = 0;
    TssSlot *node = &p->slots[index];
    TssSlot *cur;

    for (cur = p->done_list; cur != 0; cur = cur->next) {
        if (cur == node) {
            if (prev == 0) {
                p->done_list = cur->next;
            } else {
                prev->next = cur->next;
            }
            node->next = p->free_list;
            p->free_list = node;
            return;
        }
        prev = cur;
    }
}

s32 kaj_tss_kill(s32 index) {
    TssTable *p = &kaj_tss_table;
    TssSlot *node = &p->slots[index];
    KajEvent *e;

    if (node->next == 0 || (node->next >= p->slots && node->next < &p->slots[p->count])) {
        return 0;
    }
    kaj_event_flush(2, index + 1);
    if (node->on_kill != 0) {
        node->on_kill(node);
    }
    EnterCriticalSection();
    e = kaj_event_push(0x100);
    if (e != 0) {
        e->param0 = index;
        e->param1 = 1;
        e->param2 = node->type;
        {
            TssTable *q = &kaj_tss_table;

            if (node->data != node) {
                free3(node->data);
            }
            node->data = 0;
            node->next = q->done_list;
            q->done_list = node;
        }
    } else {
        TssTable *q = &kaj_tss_table;

        if (node->data != node) {
            free3(node->data);
        }
        node->data = 0;
        node->next = q->free_list;
        q->free_list = node;
    }
    ExitCriticalSection();
    return 1;
}

s32 kaj_tss_start(TssSlot *task) {
    kaj_event_set_alarm(1, task->index + 1, 0);
    return task->index;
}

void kaj_tss_finish(TssSlot *slot) {
    TssTable *p = &kaj_tss_table;

    if (slot->data != slot) {
        free3(slot->data);
    }
    slot->data = 0;
    slot->next = p->done_list;
    p->done_list = slot;
}

void *kaj_tss_pool_create(s32 count, s32 size) {
    u8 *base;
    u8 *p;
    u8 *next;
    s32 i;

    base = kaj_malloc(count * size);
    if (base == 0) {
        return 0;
    }
    p = base;
    next = base + size;
    for (i = 1; i < count; i++) {
        *(u8 **)p = next;
        p = next;
        next = p + size;
    }
    *(u8 **)p = 0;
    return base;
}

TssSlot *kaj_tss_alloc(u32 size) {
    TssTable *p = &kaj_tss_table;
    TssSlot *node;

    if (p->free_list == 0) {
        return 0;
    }
    node = p->free_list;
    p->free_list = node->next;
    if (size > 0x20) {
        node->data = kaj_malloc(size);
        if (node->data == 0) {
            node->data = node;
            kaj_tss_free(node);
            return 0;
        }
    } else {
        node->data = node;
    }
    node->on_kill = 0;
    return node;
}

void kaj_tss_init(void) {
    TssTable *p = &kaj_tss_table;
    TssSlot *res;
    s32 i;

    p->count = 16;
    {
        s32 n = 16;
        TssSlot *base = kaj_malloc(n * sizeof(TssSlot));
        TssSlot *cur;
        TssSlot *next;

        if (base == 0) {
            res = 0;
        } else {
            cur = base;
            next = base + 1;
            for (i = 1; i < n; i++) {
                cur->next = next;
                cur = next;
                next = cur + 1;
            }
            cur->next = 0;
            res = base;
        }
    }
    p->slots = res;
    if (res == 0) {
        kaj_abend(3, "Error Allocating Sharing Table", kaj_tss_str_file, 0x78);
    }
    for (i = 0; i < p->count; i++) {
        p->slots[i].index = i;
    }
    p->free_list = p->slots;
    p->done_list = 0;
}

void kaj_tss_quit(void) {
    TssTable *p = &kaj_tss_table;

    if (p->slots != 0) {
        free3(p->slots);
        p->slots = 0;
    }
    p->free_list = 0;
    p->done_list = 0;
}

void kaj_tss_set_steps(TssSlot *task, s32 steps) {
    s32 dist = task->target - task->cur;
    s32 abs_dist;
    s32 step;

    if (steps == 0 || dist == 0) {
        task->step = dist;
        task->delay = 0;
        return;
    }
    abs_dist = dist;
    if (dist < 0) {
        abs_dist = -dist;
    }
    step = (abs_dist + (steps >> 1)) / steps;
    if (dist < 0) {
        step = -step;
    }
    task->step = step;
    task->delay = 2;
}
