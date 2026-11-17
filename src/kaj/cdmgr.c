#include "common.h"
#include "kaj/cdmgr.h"
#include "game/block.h"
#include "game/mod.h"
#include "kaj/heap.h"
#include "kaj/kaj.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"

/*
 * The CD file manager: directory, loads, reference counts.
 *
 * File boundaries: guess (docs/layout.md): Sony code before; cdmgr.c asserts; its end is a guess.
 */

typedef struct {
    s16 id;
    s16 unk2;
    s32 size;
    s32 buffer;
    u8 heap[0x1C];
} CdmgrPool;
extern CdmgrPool kaj_cdmgr_pools[];
s16 kaj_cdmgr_pool_count;
extern s16 kaj_cdmgr_state[];
extern CdmgrSlot kaj_cdmgr_slots_1[];
extern CdmgrSlot kaj_cdmgr_slots[];
typedef struct {
    u8 unk0[0x1C];
    s32 *block;
    u8 unk20[4];
} CdmgrSlotView;
extern s32 kaj_cdmgr_old_addrs[];
s16 kaj_cdmgr_dirty;
extern char kaj_cdmgr_str_assert[];
extern char kaj_cdmgr_str_file[];
typedef struct {
    s16 phase;
    s16 cur_slot;
    CdmgrSlot slots[32];
} CdmgrState;
static void kaj_cdmgr_save_addrs(CdmgrSlotView *state);
static void kaj_cdmgr_relocate(s16 *state);
extern s16 kaj_cdmgr_refs[];
s32 kaj_cdmgr_read_left;
s32 kaj_cdmgr_stall_count;
s32 kaj_cdmgr_read_done;
u8 kaj_cdmgr_reloc_kind;
static void kaj_cdmgr_free_data(s32 type, s32 data);
extern s16 kaj_cdmgr_cur_slot[];

void kaj_cdmgr_init(void) {
    CdmgrPool *pool = kaj_cdmgr_pools;
    CdmgrState *state;
    s32 i;

    for (i = 0; i < kaj_cdmgr_pool_count; i++, pool++) {
        if (pool->buffer == 0) {
            pool->buffer = (s32)kaj_malloc(pool->size);
            if (pool == NULL) {
                printf(kaj_cdmgr_str_assert, kaj_cdmgr_str_file, 168);
                exit(1);
            }
        }
        kaj_heap_init((KajHeap *)pool->heap, (u8 *)pool->buffer, pool->size, 2);
    }
    state = (CdmgrState *)kaj_cdmgr_state;
    state->phase = 0;
    state->cur_slot = 0;
    for (i = 0; i < 32; i++) {
        state->slots[i].size = 0;
        state->slots[i].sectors = 0;
        state->slots[i].alloc_size = 0;
        state->slots[i].lba = 0;
        state->slots[i].next = 0;
        state->slots[i].refs = 0;
        state->slots[i].block = 0;
        state->slots[i].pool = 0;
    }
}

s32 kaj_cdmgr_poll(void) {
    CdmgrState *state;
    CdmgrSlot *slot;
    s32 cur;
    s32 ret = 0;
    u32 *buf;
    s32 left;
    u8 pos[8];
    u8 param[8];

    cur = kaj_cdmgr_state[1];
    slot = (cur >= 1 && cur <= 32) ? &((CdmgrState *)kaj_cdmgr_state)->slots[cur - 1] : NULL;
    state = (CdmgrState *)kaj_cdmgr_state;
    switch (kaj_cdmgr_state[0]) {
    case 1:
        if (state->cur_slot > 0 && slot->block != 0) {
            kaj_cdmgr_read_left = 0;
            kaj_cdmgr_stall_count = 0;
            CdIntToPos(slot->lba, pos);
            while (CdControl(2, pos, NULL) == 0) {
            }
            kaj_cdmgr_state[0] = 3;
        } else {
            kaj_cdmgr_state[0] = -1;
        }
        break;
    case 3:
        if (state->cur_slot > 0 && slot->block != 0) {
            buf = *(u32 **)slot->block;
            param[0] = CdMode();
            if (!(param[0] & 0x80)) {
                param[0] = 0x80;
                while (CdControl(0xE, param, NULL) == 0) {
                }
                VSync(3);
            }
            if (CdRead(slot->sectors, buf, 0x80) != 0) {
                kaj_cdmgr_state[0] = 4;
            } else {
                CdFlush();
                kaj_cdmgr_state[0] = 1;
            }
        } else {
            kaj_cdmgr_state[0] = -1;
        }
        break;
    case 4:
        left = CdReadSync(1, NULL);
        if (left == 0) {
            if (slot->next != 0) {
                kaj_cdmgr_state[0] = 1;
                state->cur_slot = slot->next;
                slot->next = 0;
            } else {
                kaj_cdmgr_state[0] = 0;
                state->cur_slot = 0;
                kaj_cdmgr_read_done = 1;
                ret = 1;
            }
            slot->load_state = 1;
        } else {
            if (kaj_cdmgr_read_left == left) {
                kaj_cdmgr_stall_count++;
            } else {
                kaj_cdmgr_stall_count = 0;
            }
            kaj_cdmgr_read_left = left;
            if (kaj_cdmgr_stall_count > 0x40000) {
                if (slot->sectors - left >= 2) {
                    CdReadBreak();
                } else {
                    CdFlush();
                }
                kaj_cdmgr_state[0] = 1;
            }
        }
        break;
    case -1:
        CdFlush();
        kaj_cdmgr_state[0] = 0;
        break;
    }
    return ret;
}

s32 kaj_cdmgr_load(CdmgrFile *file, s32 pool, s32 type) {
    CdmgrSlot *slot;
    KajHeap *heap;
    KajHeapBlock *blk;
    u32 size;
    s32 i;

    for (i = 0; i < 32; i++) {
        slot = &((CdmgrState *)kaj_cdmgr_state)->slots[i];
        if (slot->block != 0 && slot->lba == file->lba && slot->pool == pool && slot->type == type) {
            ((CdmgrState *)kaj_cdmgr_state)->slots[i].refs++;
            return i + 1;
        }
    }
    if (kaj_cdmgr_state[0] == 0) {
        for (i = 0; i < 32; i++) {
            if (((CdmgrState *)kaj_cdmgr_state)->slots[i].block == 0) {
                slot = &((CdmgrState *)kaj_cdmgr_state)->slots[i];
                slot->lba = file->lba;
                slot->size = file->size;
                slot->sectors = file->sectors;
                slot->alloc_size = file->alloc_size;
                size = file->alloc_size;
                blk = NULL;
                if (pool < 0 || pool >= kaj_cdmgr_pool_count) {
                    printf(kaj_cdmgr_str_assert, kaj_cdmgr_str_file, 93);
                    exit(1);
                }
                heap = (KajHeap *)kaj_cdmgr_pools[pool].heap;
                if (heap != NULL) {
                    blk = kaj_heap_alloc(heap, size);
                }
                slot->block = (s32)blk;
                if (blk == NULL) {
                    break;
                }
                kaj_cdmgr_state[0] = 1;
                kaj_cdmgr_state[1] = i + 1;
                slot->pool = pool;
                slot->type = type;
                slot->next = 0;
                slot->refs++;
                return i + 1;
            }
        }
    }
    return 0;
}

s32 kaj_cdmgr_count_refs(s32 count, CdmgrFileEntry *files, s32 *handles, s32 pool) {
    CdmgrSlot *slot;
    s32 i;
    s32 j;
    s32 k;

    if (kaj_cdmgr_state[0] != 0) {
        return 0;
    }
    for (i = 0; i < 32; i++) {
        kaj_cdmgr_refs[i] = ((CdmgrState *)kaj_cdmgr_state)->slots[i].refs;
    }
    k = 0;
    for (i = 0; i < count; i++, files++) {
        for (j = 0; j < 32; j++) {
            slot = &kaj_cdmgr_slots[j];
            if (slot->lba == files->lba && slot->pool == pool && slot->type == files->type) {
                kaj_cdmgr_refs[j]++;
                *handles = j + 1;
                break;
            }
        }
        if (j == 32) {
            for (; k < 32; k++) {
                slot = &kaj_cdmgr_slots[k];
                if (slot->block == 0) {
                    kaj_cdmgr_refs[k++]++;
                    break;
                }
            }
        }
        handles++;
    }
    return 1;
}

static inline KajHeapBlock *kaj_cdmgr_load_list_alloc(s32 pool, u32 size) {
    KajHeapBlock *blk = NULL;
    KajHeap *heap;
    if (pool < 0 || pool >= kaj_cdmgr_pool_count) {
        printf(kaj_cdmgr_str_assert, kaj_cdmgr_str_file, 93);
        exit(1);
    }
    heap = (KajHeap *)kaj_cdmgr_pools[pool].heap;
    if (heap != NULL) {
        blk = kaj_heap_alloc(heap, size);
    }
    return blk;
}

s16 kaj_cdmgr_load_list(s32 *count, CdmgrFileEntry *files, s32 *handles, s32 pool, s16 *moved_out) {
    CdmgrPool *pool_desc;
    CdmgrFileEntry *file;
    CdmgrSlot *slot;
    KajHeapBlock *blk;
    s32 moved;
    s32 r;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    s32 first;
    s32 last;

    if (kaj_cdmgr_state[0] != 0) {
        return 0;
    }
    pool_desc = kaj_cdmgr_pools;
    moved = 0;
    for (i = 0; i < kaj_cdmgr_pool_count; i++, pool_desc++) {
        if (kaj_heap_has_gaps((KajHeap *)pool_desc->heap) != 0) {
            kaj_cdmgr_save_addrs((CdmgrSlotView *)kaj_cdmgr_state);
            moved |= kaj_heap_compact((KajHeap *)pool_desc->heap);
        }
    }
    if (moved != 0) {
        kaj_cdmgr_relocate(kaj_cdmgr_state);
    }
    r = moved | kaj_cdmgr_dirty;
    *moved_out = r;
    for (k = 0; k < 32; k++) {
        ((CdmgrState *)kaj_cdmgr_state)->slots[k].refs = kaj_cdmgr_refs[k];
    }
    j = 0;
    last = -1;
    first = -1;
    n = 0;
    for (k = 0; k < *count; k++) {
        file = &files[k];
        for (m = 0; m < 32; m++) {
            slot = &kaj_cdmgr_slots[m];
            if (slot->lba == file->lba && slot->pool == pool && slot->type == file->type) {
                handles[k] = m + 1;
                break;
            }
        }
        if (m != 32) {
            n++;
            continue;
        }
        for (; j < 32; j++) {
            slot = &kaj_cdmgr_slots[j];
            if (slot->block == 0 && (u16)slot->refs != 0) {
                blk = kaj_cdmgr_load_list_alloc(pool, file->alloc_size);
                slot->block = (s32)blk;
                if (blk == NULL) {
                    break;
                }
                slot->index = file->index;
                slot->lba = file->lba;
                slot->size = file->size;
                slot->sectors = file->sectors;
                slot->alloc_size = file->alloc_size;
                slot->load_state = 0;
                ((s16 *)kaj_cdmgr_slots)[-2] = 1;
                if (first < 0) {
                    first = j;
                }
                if (last >= 0) {
                    ((CdmgrState *)kaj_cdmgr_state)->slots[last].next = j + 1;
                }
                last = j;
                slot->pool = pool;
                slot->type = file->type;
                slot->next = 0;
                handles[k] = last + 1;
                j = last + 1;
                n++;
                break;
            }
        }
    }
    *count = n;
    if (first >= 0) {
        kaj_cdmgr_cur_slot[0] = first + 1;
        return 1;
    }
    return 0;
}

void kaj_cdmgr_release(s32 handle) {
    KajHeap *heap;
    KajHeapBlock *blk;
    s32 pool;
    s32 slot;

    if (handle == 0) {
        return;
    }
    slot = handle - 1;
    if (((CdmgrState *)kaj_cdmgr_state)->slots[slot].block == 0) {
        return;
    }
    if (kaj_cdmgr_refs[slot] <= 0) {
        return;
    }
    if (--kaj_cdmgr_refs[slot] != 0) {
        return;
    }
    kaj_cdmgr_free_data(((CdmgrState *)kaj_cdmgr_state)->slots[slot].type, *(s32 *)((CdmgrState *)kaj_cdmgr_state)->slots[slot].block);
    if (kaj_cdmgr_state[0] != 0 && kaj_cdmgr_state[1] == handle) {
        CdFlush();
        kaj_cdmgr_state[0] = 0;
    }
    pool = ((CdmgrState *)kaj_cdmgr_state)->slots[slot].pool;
    blk = (KajHeapBlock *)((CdmgrState *)kaj_cdmgr_state)->slots[slot].block;
    if (pool < 0 || pool >= kaj_cdmgr_pool_count) {
        printf(kaj_cdmgr_str_assert, kaj_cdmgr_str_file, 93);
        exit(1);
    }
    heap = (KajHeap *)kaj_cdmgr_pools[pool].heap;
    if (heap != NULL && blk != NULL) {
        kaj_heap_free(heap, blk);
    }
    ((CdmgrState *)kaj_cdmgr_state)->slots[slot].block = 0;
    ((CdmgrState *)kaj_cdmgr_state)->slots[slot].pool = 0;
    ((CdmgrState *)kaj_cdmgr_state)->slots[slot].type = 0;
    kaj_cdmgr_dirty = 1;
}

s32 kaj_cdmgr_dir_entries(s32 handle, s16 count, s16 *indices, CdmgrFileEntry *files) {
    CdmgrSlot *slot;
    s32 *dir;
    s32 *entry;
    s16 i;
    s32 size;
    CdmgrFileEntry *file;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->block != 0) {
        if (kaj_cdmgr_state[0] == 0 || kaj_cdmgr_state[1] != handle) {
            dir = (s32 *)slot->block;
        } else {
            dir = NULL;
        }
    } else {
        dir = NULL;
    }
    if (dir != NULL) {
        for (i = 0; i < count; i++) {
            if (indices[i] > 0) {
                entry = &((s32 *)*dir)[indices[i] * 2 - 2];
                file = &files[i];
                file->lba = entry[0];
                size = entry[1];
                file->size = size;
                file->sectors = (size + 0x7FF) / 2048;
                file->alloc_size = file->sectors << 11;
            }
        }
        return 0;
    }
    return -1;
}

static void kaj_cdmgr_relocate(s16 *state) {
    u8 i;
    s32 *new_addr;
    s32 *old_addr;
    u8 *src;
    s32 diff;
    s32 diff3;
    s32 j;
    s32 j3;
    s32 k;
    s32 *e;
    s32 *e3;
    s32 *tmd;
    s32 **obj;
    s32 n;

    for (i = 0; i < 32; i++) {
        if (((CdmgrState *)state)->slots[i].block != 0 && ((CdmgrState *)state)->slots[i].load_state != 0) {
            new_addr = *(s32 **)((CdmgrState *)state)->slots[i].block;
            old_addr = (s32 *)kaj_cdmgr_old_addrs[i];
            if (new_addr < old_addr) {
                switch (((CdmgrState *)state)->slots[i].type) {
                case 1:
                    e = new_addr + 5;
                    diff = old_addr - new_addr;
                    for (j = 0; j < new_addr[4]; j++, e += 2) {
                        tmd = (s32 *)((u8 *)new_addr + e[1]);
                        if (tmd[0] == 0x41 && (tmd[1] & 1)) {
                            obj = (s32 **)(tmd + 3);
                            n = tmd[2];
                            for (k = 0; k < n; k++, obj += 7) {
                                obj[0] -= diff;
                                obj[2] -= diff;
                                obj[4] -= diff;
                            }
                        }
                    }
                    kaj_cdmgr_reloc_kind = 1;
                    break;
                case 3:
                    e3 = new_addr + 5;
                    src = (u8 *)old_addr;
                    diff3 = old_addr - new_addr;
                    for (j3 = 0; j3 < ((s16 *)new_addr)[9]; j3++, e3 += 2) {
                        if (e3[0] == 4) {
                            block_replace_arena(src + e3[1], (u8 *)new_addr + e3[1]);
                        } else {
                            tmd = (s32 *)((u8 *)new_addr + e3[1]);
                            if (tmd[0] == 0x41 && (tmd[1] & 1)) {
                                obj = (s32 **)(tmd + 3);
                                n = tmd[2];
                                for (k = 0; k < n; k++, obj += 7) {
                                    obj[0] -= diff3;
                                    obj[2] -= diff3;
                                    obj[4] -= diff3;
                                }
                            }
                        }
                    }
                    kaj_cdmgr_reloc_kind = 2;
                    break;
                case 5:
                    mod_relocate(old_addr, new_addr);
                    kaj_cdmgr_reloc_kind = 3;
                    break;
                }
            }
        }
    }
}

s32 kaj_cdmgr_pool_size(s32 pool) {
    if (pool < 0 || pool >= kaj_cdmgr_pool_count) {
        printf(kaj_cdmgr_str_assert, kaj_cdmgr_str_file, 137);
        exit(1);
    }
    return kaj_cdmgr_pools[pool].size;
}

s32 kaj_cdmgr_pool_free(s32 pool_id) {
    CdmgrPool *pool = kaj_cdmgr_pools;
    s32 i;

    for (i = 0; i < kaj_cdmgr_pool_count; i++, pool++) {
        if (pool->id == pool_id) {
            return kaj_heap_free_space(pool->heap);
        }
    }
    return 0;
}

s32 kaj_cdmgr_rebase_dir(s32 handle, u32 dir_size, char *name) {
    CdmgrFile info;
    struct {
        u8 pos[4];
        u32 size;
        char name[16];
    } file;
    CdmgrFile *f = &info;
    CdmgrSlot *slot;
    s32 *dir;
    s32 *entry;
    s32 n;
    s32 i;
    s32 base;

    while ((u32)((s32)CdSearchFile(&file, name) + 1) < 2) {
    }
    f->lba = CdPosToInt(&file);
    f->index = 0;
    f->size = file.size;
    f->sectors = (file.size + 0x7FF) >> 11;
    f->alloc_size = f->sectors << 11;
    base = info.lba;
    n = dir_size >> 3;
    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->block != 0) {
        if (kaj_cdmgr_state[0] == 0 || kaj_cdmgr_state[1] != handle) {
            dir = (s32 *)slot->block;
        } else {
            dir = NULL;
        }
    } else {
        dir = NULL;
    }
    if (dir != NULL) {
        for (i = 0; i < n; i++) {
            entry = &((s32 *)*dir)[i * 2];
            *entry += base - 150;
        }
    }
    return 0;
}

s32 kaj_cdmgr_find_file(CdmgrFile *info, char *name) {
    struct {
        u8 pos[4];
        u32 size;
        char name[16];
    } file;

    while ((u32)((s32)CdSearchFile(&file, name) + 1) < 2) {
    }
    info->lba = CdPosToInt(&file);
    info->index = 0;
    info->size = file.size;
    info->sectors = (file.size + 0x7FF) >> 11;
    info->alloc_size = info->sectors << 11;
    return 0;
}

s32 kaj_cdmgr_dir_entry(s32 handle, s16 index, CdmgrFile *info) {
    CdmgrSlot *slot;
    s32 *dir;
    s32 size;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->block != 0) {
        if (kaj_cdmgr_state[0] == 0 || kaj_cdmgr_state[1] != handle) {
            dir = (s32 *)slot->block;
        } else {
            dir = NULL;
        }
    } else {
        dir = NULL;
    }
    if (dir != NULL && index > 0) {
        dir = &((s32 *)*dir)[index * 2 - 2];
        info->lba = dir[0];
        info->index = index;
        size = dir[1];
        info->size = size;
        info->sectors = (size + 0x7FF) / 2048;
        info->alloc_size = info->sectors << 11;
        return 0;
    }
    return -1;
}

s32 kaj_cdmgr_is_idle(void) {
    return kaj_cdmgr_state[0] == 0;
}

s32 kaj_cdmgr_is_ready(s32 handle) {
    CdmgrSlot *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->block != 0) {
        if (kaj_cdmgr_state[0] == 0 || kaj_cdmgr_state[1] != handle) {
            return 1;
        }
    }
    return 0;
}

s32 kaj_cdmgr_compact(void) {
    CdmgrPool *pool = kaj_cdmgr_pools;
    s32 i;
    s32 moved = 0;

    for (i = 0; i < kaj_cdmgr_pool_count; i++, pool++) {
        if (kaj_heap_has_gaps((KajHeap *)pool->heap) != 0) {
            kaj_cdmgr_save_addrs((CdmgrSlotView *)kaj_cdmgr_state);
            moved |= kaj_heap_compact((KajHeap *)pool->heap);
        }
    }
    if (moved != 0) {
        kaj_cdmgr_relocate(kaj_cdmgr_state);
    }
    return moved | kaj_cdmgr_dirty;
}

s32 kaj_cdmgr_get(s32 handle) {
    CdmgrSlot *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->block != 0) {
        if (kaj_cdmgr_state[0] == 0 || kaj_cdmgr_state[1] != handle) {
            return slot->block;
        }
    }
    return 0;
}

s32 kaj_cdmgr_get_type(s32 handle) {
    CdmgrSlot *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot == NULL) {
        return -1;
    }
    return slot->type;
}

s32 kaj_cdmgr_get_size(s32 handle) {
    CdmgrSlot *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot == NULL) {
        return 0;
    }
    return slot->size;
}

s32 kaj_cdmgr_is_fresh(s32 handle) {
    CdmgrSlot *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->block != 0 && slot->load_state == 1) {
        if (kaj_cdmgr_state[0] == 0 || kaj_cdmgr_state[1] != handle) {
            return 1;
        }
    }
    return 0;
}

void kaj_cdmgr_mark_used(s32 handle) {
    CdmgrSlot *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->block != 0) {
        if (kaj_cdmgr_state[0] == 0 || kaj_cdmgr_state[1] != handle) {
            slot->load_state = 2;
        }
    }
}

void kaj_cdmgr_seek(CdmgrFile *info) {
    u8 pos[4];

    CdIntToPos(info->lba, pos);
    while (CdControl(2, pos, NULL) == 0) {
    }
}

void kaj_cdmgr_read(CdmgrFile *info, u32 *buf) {
    u8 mode[4];

    mode[0] = CdMode();
    if (!(mode[0] & 0x80)) {
        mode[0] = 0x80;
        while (CdControl(0xE, mode, NULL) == 0) {
        }
        VSync(3);
    }
    CdRead(info->sectors, buf, 0x80);
}

CdmgrSlot *kaj_cdmgr_find_slot(s32 pool, s32 index) {
    CdmgrSlot *slot;
    s32 i;

    for (i = 0; i < 32; i++) {
        slot = &kaj_cdmgr_slots[i];
        if (slot->block != 0 && slot->index == index && slot->pool == pool) {
            return slot;
        }
    }
    return NULL;
}

static void kaj_cdmgr_save_addrs(CdmgrSlotView *state) {
    u8 i;
    CdmgrSlotView *slot;

    for (i = 0; i < 32; i++) {
        slot = &state[i];
        if (slot->block != NULL) {
            kaj_cdmgr_old_addrs[i] = *slot->block;
        } else {
            kaj_cdmgr_old_addrs[i] = 0;
        }
    }
}

void kaj_cdmgr_free_all(void) {
    CdmgrPool *pool = kaj_cdmgr_pools;
    s32 i;

    CdFlush();
    for (i = 0; i < kaj_cdmgr_pool_count; i++, pool++) {
        if (pool->buffer != 0) {
            kaj_heap_free_all(pool->heap);
        }
    }
}

s32 kaj_cdmgr_is_loaded(s32 handle) {
    CdmgrSlot *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->block != 0 && slot->load_state != 0) {
        return 1;
    }
    return 0;
}

void kaj_cdmgr_clear_dirty(void) {
    kaj_cdmgr_dirty = 0;
}

static void kaj_cdmgr_free_data(s32 type, s32 data) {
    switch (type) {
    case 3:
        break;
    case 5:
        mod_on_data_free(data);
        break;
    }
}

INCLUDE_RODATA("asm/nonmatchings/kaj/cdmgr", kaj_cdmgr_str_assert);
