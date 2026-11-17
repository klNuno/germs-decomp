#ifndef KAJ_KAJ_H
#define KAJ_KAJ_H

#include "common.h"
#include "game/types.h"

typedef struct KajSystem {
    s32 pad_now;
    s32 pad_prev;
    s16 timer_enabled;
    s16 pad_mode;
    s32 timer_ticks;
    s32 timer_period;
    s32 vsync_delta;
    s16 sep_volume;
    u8 unk1A[0x2];
} KajSystem;

/* Functions of src/kaj/kaj.c that other files call or a table names. */
void *kaj_malloc(u32 size);
void kaj_init(void);

#endif
