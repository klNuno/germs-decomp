#ifndef KAJ_HEAP_H
#define KAJ_HEAP_H

#include "common.h"
#include "game/types.h"

typedef struct KajHeapBlock {
    u8 *addr;
    s32 size;
    struct KajHeapBlock *next;
} KajHeapBlock;

typedef struct {
    s32 size;
    u8 *base;
    u8 *end;
    s32 block_count;
    s32 used;
    KajHeapBlock *blocks;
    s32 mode;
} KajHeap;

/* Functions of src/kaj/heap.c that other files call or a table names. */
KajHeapBlock *kaj_heap_alloc(KajHeap *heap, u32 bytes);
void kaj_heap_init(KajHeap *heap, u8 *base, s32 size, s32 mode);
s32 kaj_heap_has_gaps(KajHeap *heap);
s32 kaj_heap_compact(KajHeap *heap);
void kaj_heap_free(KajHeap *heap, KajHeapBlock *blk);
s32 kaj_heap_free_space(KajHeap *heap);
void kaj_heap_free_all(KajHeap *heap);

#endif
