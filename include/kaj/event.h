#ifndef KAJ_EVENT_H
#define KAJ_EVENT_H

#include "common.h"
#include "game/types.h"

typedef struct KajEvent {
    s32 type;
    u32 ticks;
    s32 param0;
    s32 param1;
    s32 param2;
} KajEvent;

/* Functions of src/kaj/event.c that other files call or a table names. */
KajEvent *kaj_event_push(s32 type);
KajEvent *kaj_event_push_front(s32 type);
s32 kaj_event_get(s32 *event);
s32 kaj_event_set_alarm(s32 delay, s32 id, s32 data);
void kaj_event_flush(s32 type_mask, s32 id);
void kaj_event_init(void);
void kaj_event_done(s32 *event);

#endif
