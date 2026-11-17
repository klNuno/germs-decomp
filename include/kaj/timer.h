#ifndef KAJ_TIMER_H
#define KAJ_TIMER_H

#include "common.h"
#include "game/types.h"

/* Functions of src/kaj/timer.c that other files call or a table names. */
void kaj_timer_add_alarm(s32 delay, s32 id, s32 data);
void kaj_timer_init(void);
void kaj_timer_cancel(s32 id);
void kaj_timer_enable(void);
void kaj_timer_disable(void);

#endif
