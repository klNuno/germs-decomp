#ifndef KAJ_TSS_H
#define KAJ_TSS_H

#include "common.h"
#include "game/types.h"

typedef struct TssSlot {
    struct TssSlot *next;
    u8 unk4[0x1C];
    s16 index;
    s16 type;
    s16 cur;
    s16 target;
    s16 step;
    u8 unk2A[0x2];
    s32 delay;
    void (*on_step)(struct TssSlot *);
    void (*on_end)(struct TssSlot *);
    void (*on_kill)(struct TssSlot *);
    void *data;
} TssSlot;

typedef struct TssTable {
    s32 count;
    TssSlot *slots;
    TssSlot *free_list;
    TssSlot *done_list;
} TssTable;

/* Functions of src/kaj/tss.c that other files call or a table names. */
void kaj_tss_free(TssSlot *slot);
void kaj_tss_release(s32 index);
s32 kaj_tss_start(TssSlot *task);
void kaj_tss_finish(TssSlot *slot);
TssSlot *kaj_tss_alloc(u32 size);
void kaj_tss_init(void);
void kaj_tss_set_steps(TssSlot *task, s32 steps);

#endif
