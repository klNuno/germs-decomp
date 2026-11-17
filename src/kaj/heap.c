#include "common.h"
#include "kaj/heap.h"
#include "kaj/kaj.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"

/*
 * The CD data heap: alloc, compact, free.
 *
 * File boundaries: guess (docs/layout.md): no assert: kaj_heap_unused_* are read only here.
 */

s32 kaj_heap_unused_value;
s32 kaj_heap_unused_a;
s32 kaj_heap_unused_b;

KajHeapBlock *kaj_heap_alloc(KajHeap *heap, u32 bytes) {
    KajHeapBlock *blk;
    KajHeapBlock *last;
    KajHeapBlock *cur;
    u8 *addr;
    u32 size;
    u32 free;

    size = ((bytes + 3) >> 2) << 2;
    blk = kaj_malloc(sizeof(KajHeapBlock));
    if (blk == NULL) {
        return NULL;
    }
    if (heap->blocks == NULL) {
        if ((u32)heap->size >= size) {
            heap->blocks = blk;
            blk->addr = heap->base;
            blk->size = size;
            heap->block_count++;
            heap->used += size;
            return blk;
        }
    } else {
        last = heap->blocks;
        while (last->next != NULL) {
            last = last->next;
        }
        free = heap->end - (last->addr + last->size);
        if (heap->mode == 0 || (heap->mode == 1 && free < size)) {
            cur = heap->blocks;
            addr = heap->base;
            while (cur != NULL) {
                if (cur->addr != addr) {
                    memmove(addr, cur->addr, cur->size);
                    cur->addr = addr;
                }
                addr = cur->addr + cur->size;
                cur = cur->next;
            }
        }
        free = heap->end - (last->addr + last->size);
        if (free >= size) {
            last->next = NULL;
            blk->addr = last->addr + last->size;
            blk->size = size;
            last->next = blk;
            heap->block_count++;
            heap->used += size;
            return blk;
        }
    }
    free3(blk);
    return NULL;
}

void kaj_heap_set_unused(s32 unused, s32 value) {
    kaj_heap_unused_value = value;
    kaj_heap_unused_a = 0;
    kaj_heap_unused_b = 0;
}

void kaj_heap_init(KajHeap *heap, u8 *base, s32 size, s32 mode) {
    heap->base = base;
    heap->end = base + size;
    heap->size = size;
    heap->block_count = 0;
    heap->used = 0;
    heap->blocks = 0;
    heap->mode = mode;
}

void kaj_heap_set_mode(KajHeap *heap, s32 mode) {
    heap->mode = mode;
}

s32 kaj_heap_get_mode(KajHeap *heap) {
    return heap->mode;
}

s32 kaj_heap_has_gaps(KajHeap *heap) {
    KajHeapBlock *p = heap->blocks;
    u8 *addr = heap->base;

    while (p != NULL) {
        if (p->addr != addr) {
            return 1;
        }
        addr += p->size;
        p = p->next;
    }
    return 0;
}

s32 kaj_heap_compact(KajHeap *heap) {
    KajHeapBlock *p = heap->blocks;
    u8 *addr = heap->base;
    s32 moved = 0;

    while (p != NULL) {
        if (p->addr != addr) {
            memmove(addr, p->addr, p->size);
            moved = 1;
            p->addr = addr;
        }
        addr = p->addr + p->size;
        p = p->next;
    }
    return moved;
}

void kaj_heap_free(KajHeap *heap, KajHeapBlock *blk) {
    KajHeapBlock *p;
    KajHeapBlock *next;

    if (blk == NULL) {
        return;
    }
    if (blk == heap->blocks) {
        heap->blocks = blk->next;
        heap->block_count--;
        heap->used -= blk->size;
        free3(blk);
        return;
    }
    for (p = heap->blocks; p != NULL; p = next) {
        next = p->next;
        if (next == blk) {
            heap->block_count--;
            heap->used -= next->size;
            p->next = next->next;
            free3(next);
            return;
        }
    }
}

s32 kaj_heap_free_space(KajHeap *heap) {
    KajHeapBlock *p;

    if (heap->blocks == NULL) {
        return heap->size;
    }
    for (p = heap->blocks; p->next != NULL; p = p->next) {
    }
    return heap->end - (p->addr + p->size);
}

void kaj_heap_free_all(KajHeap *heap) {
    KajHeapBlock *p = heap->blocks;
    KajHeapBlock *next;

    while (p != NULL) {
        next = p->next;
        if (p != NULL) {
            free3(p);
        }
        p = next;
    }
}
