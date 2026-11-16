#include "common.h"

typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x1C];
} Unk_801DFBE0;
extern Unk_801DFBE0 kaj_cdmgr_pools[];
s16 kaj_cdmgr_pool_count;
typedef struct Unk_801D395C {
    u8 *unk0;
    s32 unk4;
    struct Unk_801D395C *unk8;
} Unk_801D395C;
typedef struct {
    s32 unk0;
    u8 *unk4;
    u8 *unk8;
    s32 unkC;
    s32 unk10;
    Unk_801D395C *unk14;
    s32 unk18;
} Unk_801D3924;
s32 kaj_heap_free_space(Unk_801D3924 *arg0);
typedef struct {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
} Unk_801D3060;
void *CdSearchFile(void *fp, char *name);
s32 CdPosToInt(void *p);
extern s16 D_801E71C8[];
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C;
    u8 unk1D;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
} Unk_801E71A8;
extern Unk_801E71A8 kaj_cdmgr_slots_1[];
void *CdIntToPos(s32 i, void *p);
s32 CdControl(u8 com, u8 *param, u8 *result);
s32 CdMode(void);
s32 VSync(s32 mode);
s32 CdRead(s32 sectors, u32 *buf, s32 mode);
extern Unk_801E71A8 kaj_cdmgr_slots[];
typedef struct {
    u8 unk0[0x1C];
    s32 *unk1C;
    u8 unk20[4];
} Unk_801D35EC;
extern s32 kaj_cdmgr_old_addrs[];
void CdFlush(void);
void kaj_heap_free_all(Unk_801D3924 *arg0);
s16 kaj_cdmgr_dirty;
void mod_on_data_free(s32 arg0);
s32 D_801DFE2C;
s32 D_801DFE30;
s32 D_801DFE34;
void *memmove(void *dst, const void *src, u32 n);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u8 unk8;
    u8 unk9;
    s16 unkA;
    s16 unkC;
    u8 unkE[2];
    s32 unk10[20];
} Unk_801E7950;
u8 kaj_map_cell_cur;
extern Unk_801E7950 kaj_map_cells[];
Unk_801E7950 *kaj_map_get_cell_state(void);
typedef struct {
    u8 unk0;
    u8 unk1;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    u8 unkC[4];
    s32 unk10[0x20];
} Unk_801E7830;
u8 kaj_map_room_cur;
extern Unk_801E7830 kaj_map_rooms[];
s32 kaj_map_mode;
s32 kaj_map_slot;
s32 kaj_cdmgr_get(s32 arg0);
s32 kaj_map_dir_slot;
typedef struct {
    s32 unk0;
    s32 unk4;
} Unk_801D6DC8;
s16 D_801DFFE4;
void kaj_cdmgr_release(s32 arg0);
extern char D_80172FD0[];
extern char D_801DFE14[];
int printf(const char *fmt, ...);
void exit(s32 code);
extern char kaj_map_str_city_mp[];
void kaj_cdmgr_init(void);
s32 kaj_cdmgr_load(Unk_801D3060 *arg0, s32 arg1, s32 arg2);
s32 kaj_cdmgr_find_file(Unk_801D3060 *arg0, char *arg1);
void kaj_map_reset_cells(void);
void free3(void *ptr);
typedef struct {
    s16 unk0;
    s16 unk2;
    Unk_801E71A8 unk4[32];
} Unk_801E71C8;
void *kaj_malloc(u32 size);
void kaj_heap_init(Unk_801D3924 *arg0, u8 *arg1, s32 arg2, s32 arg3);
void kaj_cdmgr_save_addrs(Unk_801D35EC *arg0);
s32 kaj_heap_has_gaps(Unk_801D3924 *arg0);
s32 kaj_heap_compact(Unk_801D3924 *arg0);
void kaj_cdmgr_relocate(s16 *arg0);
s32 kaj_cdmgr_is_ready(s32 arg0);
s32 kaj_cdmgr_rebase_dir(s32 arg0, u32 arg1, char *arg2);
typedef struct {
    u8 unk0[0x14];
    s32 unk14;
    s32 unk18;
    u8 unk1C[4];
} Unk_801D3E1C;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC;
    u8 unkD;
    s16 unkE;
    s16 unk10;
    u8 unk12[2];
    Unk_801D6DC8 *unk14;
    s32 unk18;
} Unk_801D6940;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C[4];
    s16 unk20[1];
} Unk_801D32F0;
s32 kaj_cdmgr_dir_entry(s32 arg0, s16 arg1, Unk_801D3060 *arg2);
s32 kaj_map_cell_link(s16 arg0, s16 arg1, u8 arg2, s16 arg3, s16 arg4, u8 *arg5);
extern char kaj_map_str_place_b[];
s32 kaj_map_letter;
void kaj_map_reset_rooms(void);
int sprintf(char *buf, const char *fmt, ...);
typedef struct {
    s32 unk0;
    s32 unk4;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    s32 unk14;
} Unk_801D2A48;
extern s16 kaj_cdmgr_refs[];
s32 kaj_map_cell_exists(s16 arg0, s16 arg1);
void kaj_map_world_to_cell(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);
s32 kaj_map_stream_cell(s16 arg0, s16 arg1);
typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
} Unk_801D5BE4;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    Unk_801D6940 *unk10;
    Unk_801D5BE4 *unk14;
} Unk_801D6B58;
s32 kaj_cdmgr_is_loaded(s32 arg0);
extern char kaj_map_str_place_rm[];
extern char kaj_map_str_place_f[];
void kaj_map_fix_place(void);
s32 CdReadSync(s32 mode, u8 *result);
void CdReadBreak(void);
s32 D_801DFE1C;
s32 D_801DFE20;
s32 D_801DFE24;
u8 D_801DFE28;
void block_replace_arena(void *arg0, void *arg1);
void mod_relocate(s32 *arg0, s32 *arg1);
s32 kaj_map_cell_flags(s16 arg0, s16 arg1, u8 arg2, u8 *arg3);
typedef struct {
    u8 unk0;
    u8 unk1;
} Unk_801D50F4;
s32 kaj_map_file_count;
extern Unk_801D2A48 kaj_map_file_list[];
s32 kaj_cdmgr_count_refs(s32 arg0, Unk_801D2A48 *arg1, s32 *arg2, s32 arg3);
s16 kaj_cdmgr_load_list(s32 *arg0, Unk_801D2A48 *arg1, s32 *arg2, s32 arg3, s16 *arg4);
s32 kaj_cdmgr_is_idle(void);
void kaj_cdmgr_clear_dirty(void);
void kaj_map_set_room(Unk_801E7830 *arg0, u8 *arg1);
void kaj_map_list_room_files(s32 arg0, Unk_801E7830 *arg1);
s32 kaj_cdmgr_pool_size(s32 arg0);
s32 kaj_map_cmp_index(Unk_801D6DC8 *arg0, Unk_801D6DC8 *arg1);
u8 kaj_map_next_neighbor(s16 arg0, s16 arg1, u8 arg2, s16 *arg3, s16 *arg4, u8 *arg5);
void qsort(void *base, s32 n, s32 size, s32 (*cmp)());
void kaj_cdmgr_free_data(s32 arg0, s32 arg1);
void kaj_heap_free(Unk_801D3924 *arg0, Unk_801D395C *arg1);
void kaj_map_list_cell_files(Unk_801E7950 *arg0);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 *unk4;
} Unk_801D5324;
Unk_801E71A8 *kaj_cdmgr_find_slot(s32 arg0, s32 arg1);
Unk_801D395C *kaj_heap_alloc(Unk_801D3924 *arg0, u32 arg1);
extern s16 kaj_cdmgr_cur_slot[];

void kaj_cdmgr_init(void) {
    Unk_801DFBE0 *pool = kaj_cdmgr_pools;
    Unk_801E71C8 *state;
    s32 i;

    for (i = 0; i < kaj_cdmgr_pool_count; i++, pool++) {
        if (pool->unk8 == 0) {
            pool->unk8 = (s32)kaj_malloc(pool->unk4);
            if (pool == NULL) {
                printf(D_80172FD0, D_801DFE14, 168);
                exit(1);
            }
        }
        kaj_heap_init((Unk_801D3924 *)pool->unkC, (u8 *)pool->unk8, pool->unk4, 2);
    }
    state = (Unk_801E71C8 *)D_801E71C8;
    state->unk0 = 0;
    state->unk2 = 0;
    for (i = 0; i < 32; i++) {
        state->unk4[i].unk8 = 0;
        state->unk4[i].unkC = 0;
        state->unk4[i].unk10 = 0;
        state->unk4[i].unk0 = 0;
        state->unk4[i].unk1E = 0;
        state->unk4[i].unk20 = 0;
        state->unk4[i].unk18 = 0;
        state->unk4[i].unk1C = 0;
    }
}

s32 kaj_cdmgr_poll(void) {
    Unk_801E71C8 *state;
    Unk_801E71A8 *slot;
    s32 cur;
    s32 ret = 0;
    u32 *buf;
    s32 left;
    u8 pos[8];
    u8 param[8];

    cur = D_801E71C8[1];
    slot = (cur >= 1 && cur <= 32) ? &((Unk_801E71C8 *)D_801E71C8)->unk4[cur - 1] : NULL;
    state = (Unk_801E71C8 *)D_801E71C8;
    switch (D_801E71C8[0]) {
    case 1:
        if (state->unk2 > 0 && slot->unk18 != 0) {
            D_801DFE1C = 0;
            D_801DFE20 = 0;
            CdIntToPos(slot->unk0, pos);
            while (CdControl(2, pos, NULL) == 0) {
            }
            D_801E71C8[0] = 3;
        } else {
            D_801E71C8[0] = -1;
        }
        break;
    case 3:
        if (state->unk2 > 0 && slot->unk18 != 0) {
            buf = *(u32 **)slot->unk18;
            param[0] = CdMode();
            if (!(param[0] & 0x80)) {
                param[0] = 0x80;
                while (CdControl(0xE, param, NULL) == 0) {
                }
                VSync(3);
            }
            if (CdRead(slot->unkC, buf, 0x80) != 0) {
                D_801E71C8[0] = 4;
            } else {
                CdFlush();
                D_801E71C8[0] = 1;
            }
        } else {
            D_801E71C8[0] = -1;
        }
        break;
    case 4:
        left = CdReadSync(1, NULL);
        if (left == 0) {
            if (slot->unk1E != 0) {
                D_801E71C8[0] = 1;
                state->unk2 = slot->unk1E;
                slot->unk1E = 0;
            } else {
                D_801E71C8[0] = 0;
                state->unk2 = 0;
                D_801DFE24 = 1;
                ret = 1;
            }
            slot->unk22 = 1;
        } else {
            if (D_801DFE1C == left) {
                D_801DFE20++;
            } else {
                D_801DFE20 = 0;
            }
            D_801DFE1C = left;
            if (D_801DFE20 > 0x40000) {
                if (slot->unkC - left >= 2) {
                    CdReadBreak();
                } else {
                    CdFlush();
                }
                D_801E71C8[0] = 1;
            }
        }
        break;
    case -1:
        CdFlush();
        D_801E71C8[0] = 0;
        break;
    }
    return ret;
}

s32 kaj_cdmgr_load(Unk_801D3060 *file, s32 pool, s32 type) {
    Unk_801E71A8 *slot;
    Unk_801D3924 *heap;
    Unk_801D395C *blk;
    u32 size;
    s32 i;

    for (i = 0; i < 32; i++) {
        slot = &((Unk_801E71C8 *)D_801E71C8)->unk4[i];
        if (slot->unk18 != 0 && slot->unk0 == file->unk0 && slot->unk1C == pool && slot->unk1D == type) {
            ((Unk_801E71C8 *)D_801E71C8)->unk4[i].unk20++;
            return i + 1;
        }
    }
    if (D_801E71C8[0] == 0) {
        for (i = 0; i < 32; i++) {
            if (((Unk_801E71C8 *)D_801E71C8)->unk4[i].unk18 == 0) {
                slot = &((Unk_801E71C8 *)D_801E71C8)->unk4[i];
                slot->unk0 = file->unk0;
                slot->unk8 = file->unk8;
                slot->unkC = file->unkC;
                slot->unk10 = file->unk10;
                size = file->unk10;
                blk = NULL;
                if (pool < 0 || pool >= kaj_cdmgr_pool_count) {
                    printf(D_80172FD0, D_801DFE14, 93);
                    exit(1);
                }
                heap = (Unk_801D3924 *)kaj_cdmgr_pools[pool].unkC;
                if (heap != NULL) {
                    blk = kaj_heap_alloc(heap, size);
                }
                slot->unk18 = (s32)blk;
                if (blk == NULL) {
                    break;
                }
                D_801E71C8[0] = 1;
                D_801E71C8[1] = i + 1;
                slot->unk1C = pool;
                slot->unk1D = type;
                slot->unk1E = 0;
                slot->unk20++;
                return i + 1;
            }
        }
    }
    return 0;
}

s32 kaj_cdmgr_count_refs(s32 count, Unk_801D2A48 *files, s32 *handles, s32 pool) {
    Unk_801E71A8 *slot;
    s32 i;
    s32 j;
    s32 k;

    if (D_801E71C8[0] != 0) {
        return 0;
    }
    for (i = 0; i < 32; i++) {
        kaj_cdmgr_refs[i] = ((Unk_801E71C8 *)D_801E71C8)->unk4[i].unk20;
    }
    k = 0;
    for (i = 0; i < count; i++, files++) {
        for (j = 0; j < 32; j++) {
            slot = &kaj_cdmgr_slots[j];
            if (slot->unk0 == files->unk0 && slot->unk1C == pool && slot->unk1D == files->unk14) {
                kaj_cdmgr_refs[j]++;
                *handles = j + 1;
                break;
            }
        }
        if (j == 32) {
            for (; k < 32; k++) {
                slot = &kaj_cdmgr_slots[k];
                if (slot->unk18 == 0) {
                    kaj_cdmgr_refs[k++]++;
                    break;
                }
            }
        }
        handles++;
    }
    return 1;
}

static inline Unk_801D395C *func_801D254C_alloc(s32 pool, u32 size) {
    Unk_801D395C *blk = NULL;
    Unk_801D3924 *heap;
    if (pool < 0 || pool >= kaj_cdmgr_pool_count) {
        printf(D_80172FD0, D_801DFE14, 93);
        exit(1);
    }
    heap = (Unk_801D3924 *)kaj_cdmgr_pools[pool].unkC;
    if (heap != NULL) {
        blk = kaj_heap_alloc(heap, size);
    }
    return blk;
}

s16 kaj_cdmgr_load_list(s32 *count, Unk_801D2A48 *files, s32 *handles, s32 pool, s16 *moved_out) {
    Unk_801DFBE0 *pool_desc;
    Unk_801D2A48 *file;
    Unk_801E71A8 *slot;
    Unk_801D395C *blk;
    s32 moved;
    s32 r;
    s32 i;
    s32 j;
    s32 k;
    s32 m;
    s32 n;
    s32 first;
    s32 last;

    if (D_801E71C8[0] != 0) {
        return 0;
    }
    pool_desc = kaj_cdmgr_pools;
    moved = 0;
    for (i = 0; i < kaj_cdmgr_pool_count; i++, pool_desc++) {
        if (kaj_heap_has_gaps((Unk_801D3924 *)pool_desc->unkC) != 0) {
            kaj_cdmgr_save_addrs((Unk_801D35EC *)D_801E71C8);
            moved |= kaj_heap_compact((Unk_801D3924 *)pool_desc->unkC);
        }
    }
    if (moved != 0) {
        kaj_cdmgr_relocate(D_801E71C8);
    }
    r = moved | kaj_cdmgr_dirty;
    *moved_out = r;
    for (k = 0; k < 32; k++) {
        ((Unk_801E71C8 *)D_801E71C8)->unk4[k].unk20 = kaj_cdmgr_refs[k];
    }
    j = 0;
    last = -1;
    first = -1;
    n = 0;
    for (k = 0; k < *count; k++) {
        file = &files[k];
        for (m = 0; m < 32; m++) {
            slot = &kaj_cdmgr_slots[m];
            if (slot->unk0 == file->unk0 && slot->unk1C == pool && slot->unk1D == file->unk14) {
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
            if (slot->unk18 == 0 && (u16)slot->unk20 != 0) {
                blk = func_801D254C_alloc(pool, file->unk10);
                slot->unk18 = (s32)blk;
                if (blk == NULL) {
                    break;
                }
                slot->unk4 = file->unk4;
                slot->unk0 = file->unk0;
                slot->unk8 = file->unk8;
                slot->unkC = file->unkC;
                slot->unk10 = file->unk10;
                slot->unk22 = 0;
                ((s16 *)kaj_cdmgr_slots)[-2] = 1;
                if (first < 0) {
                    first = j;
                }
                if (last >= 0) {
                    ((Unk_801E71C8 *)D_801E71C8)->unk4[last].unk1E = j + 1;
                }
                last = j;
                slot->unk1C = pool;
                slot->unk1D = file->unk14;
                slot->unk1E = 0;
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
    Unk_801D3924 *heap;
    Unk_801D395C *blk;
    s32 pool;
    s32 slot;

    if (handle == 0) {
        return;
    }
    slot = handle - 1;
    if (((Unk_801E71C8 *)D_801E71C8)->unk4[slot].unk18 == 0) {
        return;
    }
    if (kaj_cdmgr_refs[slot] <= 0) {
        return;
    }
    if (--kaj_cdmgr_refs[slot] != 0) {
        return;
    }
    kaj_cdmgr_free_data(((Unk_801E71C8 *)D_801E71C8)->unk4[slot].unk1D, *(s32 *)((Unk_801E71C8 *)D_801E71C8)->unk4[slot].unk18);
    if (D_801E71C8[0] != 0 && D_801E71C8[1] == handle) {
        CdFlush();
        D_801E71C8[0] = 0;
    }
    pool = ((Unk_801E71C8 *)D_801E71C8)->unk4[slot].unk1C;
    blk = (Unk_801D395C *)((Unk_801E71C8 *)D_801E71C8)->unk4[slot].unk18;
    if (pool < 0 || pool >= kaj_cdmgr_pool_count) {
        printf(D_80172FD0, D_801DFE14, 93);
        exit(1);
    }
    heap = (Unk_801D3924 *)kaj_cdmgr_pools[pool].unkC;
    if (heap != NULL && blk != NULL) {
        kaj_heap_free(heap, blk);
    }
    ((Unk_801E71C8 *)D_801E71C8)->unk4[slot].unk18 = 0;
    ((Unk_801E71C8 *)D_801E71C8)->unk4[slot].unk1C = 0;
    ((Unk_801E71C8 *)D_801E71C8)->unk4[slot].unk1D = 0;
    kaj_cdmgr_dirty = 1;
}

s32 kaj_cdmgr_dir_entries(s32 handle, s16 count, s16 *indices, Unk_801D2A48 *files) {
    Unk_801E71A8 *slot;
    s32 *dir;
    s32 *entry;
    s16 i;
    s32 size;
    Unk_801D2A48 *file;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != handle) {
            dir = (s32 *)slot->unk18;
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
                file->unk0 = entry[0];
                size = entry[1];
                file->unk8 = size;
                file->unkC = (size + 0x7FF) / 2048;
                file->unk10 = file->unkC << 11;
            }
        }
        return 0;
    }
    return -1;
}

void kaj_cdmgr_relocate(s16 *state) {
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
        if (((Unk_801E71C8 *)state)->unk4[i].unk18 != 0 && ((Unk_801E71C8 *)state)->unk4[i].unk22 != 0) {
            new_addr = *(s32 **)((Unk_801E71C8 *)state)->unk4[i].unk18;
            old_addr = (s32 *)kaj_cdmgr_old_addrs[i];
            if (new_addr < old_addr) {
                switch (((Unk_801E71C8 *)state)->unk4[i].unk1D) {
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
                    D_801DFE28 = 1;
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
                    D_801DFE28 = 2;
                    break;
                case 5:
                    mod_relocate(old_addr, new_addr);
                    D_801DFE28 = 3;
                    break;
                }
            }
        }
    }
}

s32 kaj_cdmgr_pool_size(s32 pool) {
    if (pool < 0 || pool >= kaj_cdmgr_pool_count) {
        printf(D_80172FD0, D_801DFE14, 137);
        exit(1);
    }
    return kaj_cdmgr_pools[pool].unk4;
}

s32 kaj_cdmgr_pool_free(s32 pool_id) {
    Unk_801DFBE0 *pool = kaj_cdmgr_pools;
    s32 i;

    for (i = 0; i < kaj_cdmgr_pool_count; i++, pool++) {
        if (pool->unk0 == pool_id) {
            return kaj_heap_free_space(pool->unkC);
        }
    }
    return 0;
}

s32 kaj_cdmgr_rebase_dir(s32 handle, u32 dir_size, char *name) {
    Unk_801D3060 info;
    struct {
        u8 unk0[4];
        u32 unk4;
        char unk8[16];
    } file;
    Unk_801D3060 *f = &info;
    Unk_801E71A8 *slot;
    s32 *dir;
    s32 *entry;
    s32 n;
    s32 i;
    s32 base;

    while ((u32)((s32)CdSearchFile(&file, name) + 1) < 2) {
    }
    f->unk0 = CdPosToInt(&file);
    f->unk4 = 0;
    f->unk8 = file.unk4;
    f->unkC = (file.unk4 + 0x7FF) >> 11;
    f->unk10 = f->unkC << 11;
    base = info.unk0;
    n = dir_size >> 3;
    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != handle) {
            dir = (s32 *)slot->unk18;
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

s32 kaj_cdmgr_find_file(Unk_801D3060 *info, char *name) {
    struct {
        u8 unk0[4];
        u32 unk4;
        char unk8[16];
    } file;

    while ((u32)((s32)CdSearchFile(&file, name) + 1) < 2) {
    }
    info->unk0 = CdPosToInt(&file);
    info->unk4 = 0;
    info->unk8 = file.unk4;
    info->unkC = (file.unk4 + 0x7FF) >> 11;
    info->unk10 = info->unkC << 11;
    return 0;
}

s32 kaj_cdmgr_dir_entry(s32 handle, s16 index, Unk_801D3060 *info) {
    Unk_801E71A8 *slot;
    s32 *dir;
    s32 size;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != handle) {
            dir = (s32 *)slot->unk18;
        } else {
            dir = NULL;
        }
    } else {
        dir = NULL;
    }
    if (dir != NULL && index > 0) {
        dir = &((s32 *)*dir)[index * 2 - 2];
        info->unk0 = dir[0];
        info->unk4 = index;
        size = dir[1];
        info->unk8 = size;
        info->unkC = (size + 0x7FF) / 2048;
        info->unk10 = info->unkC << 11;
        return 0;
    }
    return -1;
}

s32 kaj_cdmgr_is_idle(void) {
    return D_801E71C8[0] == 0;
}

s32 kaj_cdmgr_is_ready(s32 handle) {
    Unk_801E71A8 *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != handle) {
            return 1;
        }
    }
    return 0;
}

s32 kaj_cdmgr_compact(void) {
    Unk_801DFBE0 *pool = kaj_cdmgr_pools;
    s32 i;
    s32 moved = 0;

    for (i = 0; i < kaj_cdmgr_pool_count; i++, pool++) {
        if (kaj_heap_has_gaps((Unk_801D3924 *)pool->unkC) != 0) {
            kaj_cdmgr_save_addrs((Unk_801D35EC *)D_801E71C8);
            moved |= kaj_heap_compact((Unk_801D3924 *)pool->unkC);
        }
    }
    if (moved != 0) {
        kaj_cdmgr_relocate(D_801E71C8);
    }
    return moved | kaj_cdmgr_dirty;
}

s32 kaj_cdmgr_get(s32 handle) {
    Unk_801E71A8 *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != handle) {
            return slot->unk18;
        }
    }
    return 0;
}

s32 kaj_cdmgr_get_type(s32 handle) {
    Unk_801E71A8 *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot == NULL) {
        return -1;
    }
    return slot->unk1D;
}

s32 kaj_cdmgr_get_size(s32 handle) {
    Unk_801E71A8 *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot == NULL) {
        return 0;
    }
    return slot->unk8;
}

s32 kaj_cdmgr_is_fresh(s32 handle) {
    Unk_801E71A8 *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->unk18 != 0 && slot->unk22 == 1) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != handle) {
            return 1;
        }
    }
    return 0;
}

void kaj_cdmgr_mark_used(s32 handle) {
    Unk_801E71A8 *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->unk18 != 0) {
        if (D_801E71C8[0] == 0 || D_801E71C8[1] != handle) {
            slot->unk22 = 2;
        }
    }
}

void kaj_cdmgr_seek(Unk_801D3060 *info) {
    u8 pos[4];

    CdIntToPos(info->unk0, pos);
    while (CdControl(2, pos, NULL) == 0) {
    }
}

void kaj_cdmgr_read(Unk_801D3060 *info, u32 *buf) {
    u8 mode[4];

    mode[0] = CdMode();
    if (!(mode[0] & 0x80)) {
        mode[0] = 0x80;
        while (CdControl(0xE, mode, NULL) == 0) {
        }
        VSync(3);
    }
    CdRead(info->unkC, buf, 0x80);
}

Unk_801E71A8 *kaj_cdmgr_find_slot(s32 pool, s32 index) {
    Unk_801E71A8 *slot;
    s32 i;

    for (i = 0; i < 32; i++) {
        slot = &kaj_cdmgr_slots[i];
        if (slot->unk18 != 0 && slot->unk4 == index && slot->unk1C == pool) {
            return slot;
        }
    }
    return NULL;
}

void kaj_cdmgr_save_addrs(Unk_801D35EC *state) {
    u8 i;
    Unk_801D35EC *slot;

    for (i = 0; i < 32; i++) {
        slot = &state[i];
        if (slot->unk1C != NULL) {
            kaj_cdmgr_old_addrs[i] = *slot->unk1C;
        } else {
            kaj_cdmgr_old_addrs[i] = 0;
        }
    }
}

void kaj_cdmgr_free_all(void) {
    Unk_801DFBE0 *pool = kaj_cdmgr_pools;
    s32 i;

    CdFlush();
    for (i = 0; i < kaj_cdmgr_pool_count; i++, pool++) {
        if (pool->unk8 != 0) {
            kaj_heap_free_all(pool->unkC);
        }
    }
}

s32 kaj_cdmgr_is_loaded(s32 handle) {
    Unk_801E71A8 *slot;

    slot = (handle >= 1 && handle <= 32) ? &kaj_cdmgr_slots_1[handle] : NULL;
    if (slot != NULL && slot->unk18 != 0 && slot->unk22 != 0) {
        return 1;
    }
    return 0;
}

void kaj_cdmgr_clear_dirty(void) {
    kaj_cdmgr_dirty = 0;
}

void kaj_cdmgr_free_data(s32 type, s32 data) {
    switch (type) {
    case 3:
        break;
    case 5:
        mod_on_data_free(data);
        break;
    }
}

Unk_801D395C *kaj_heap_alloc(Unk_801D3924 *heap, u32 bytes) {
    Unk_801D395C *blk;
    Unk_801D395C *last;
    Unk_801D395C *cur;
    u8 *addr;
    u32 size;
    u32 free;

    size = ((bytes + 3) >> 2) << 2;
    blk = kaj_malloc(sizeof(Unk_801D395C));
    if (blk == NULL) {
        return NULL;
    }
    if (heap->unk14 == NULL) {
        if ((u32)heap->unk0 >= size) {
            heap->unk14 = blk;
            blk->unk0 = heap->unk4;
            blk->unk4 = size;
            heap->unkC++;
            heap->unk10 += size;
            return blk;
        }
    } else {
        last = heap->unk14;
        while (last->unk8 != NULL) {
            last = last->unk8;
        }
        free = heap->unk8 - (last->unk0 + last->unk4);
        if (heap->unk18 == 0 || (heap->unk18 == 1 && free < size)) {
            cur = heap->unk14;
            addr = heap->unk4;
            while (cur != NULL) {
                if (cur->unk0 != addr) {
                    memmove(addr, cur->unk0, cur->unk4);
                    cur->unk0 = addr;
                }
                addr = cur->unk0 + cur->unk4;
                cur = cur->unk8;
            }
        }
        free = heap->unk8 - (last->unk0 + last->unk4);
        if (free >= size) {
            last->unk8 = NULL;
            blk->unk0 = last->unk0 + last->unk4;
            blk->unk4 = size;
            last->unk8 = blk;
            heap->unkC++;
            heap->unk10 += size;
            return blk;
        }
    }
    free3(blk);
    return NULL;
}

void func_801D3910(s32 arg0, s32 arg1) {
    D_801DFE2C = arg1;
    D_801DFE30 = 0;
    D_801DFE34 = 0;
}

void kaj_heap_init(Unk_801D3924 *heap, u8 *base, s32 size, s32 mode) {
    heap->unk4 = base;
    heap->unk8 = base + size;
    heap->unk0 = size;
    heap->unkC = 0;
    heap->unk10 = 0;
    heap->unk14 = 0;
    heap->unk18 = mode;
}

void kaj_heap_set_mode(Unk_801D3924 *heap, s32 mode) {
    heap->unk18 = mode;
}

s32 kaj_heap_get_mode(Unk_801D3924 *heap) {
    return heap->unk18;
}

s32 kaj_heap_has_gaps(Unk_801D3924 *heap) {
    Unk_801D395C *p = heap->unk14;
    u8 *addr = heap->unk4;

    while (p != NULL) {
        if (p->unk0 != addr) {
            return 1;
        }
        addr += p->unk4;
        p = p->unk8;
    }
    return 0;
}

s32 kaj_heap_compact(Unk_801D3924 *heap) {
    Unk_801D395C *p = heap->unk14;
    u8 *addr = heap->unk4;
    s32 moved = 0;

    while (p != NULL) {
        if (p->unk0 != addr) {
            memmove(addr, p->unk0, p->unk4);
            moved = 1;
            p->unk0 = addr;
        }
        addr = p->unk0 + p->unk4;
        p = p->unk8;
    }
    return moved;
}

void kaj_heap_free(Unk_801D3924 *heap, Unk_801D395C *blk) {
    Unk_801D395C *p;
    Unk_801D395C *next;

    if (blk == NULL) {
        return;
    }
    if (blk == heap->unk14) {
        heap->unk14 = blk->unk8;
        heap->unkC--;
        heap->unk10 -= blk->unk4;
        free3(blk);
        return;
    }
    for (p = heap->unk14; p != NULL; p = next) {
        next = p->unk8;
        if (next == blk) {
            heap->unkC--;
            heap->unk10 -= next->unk4;
            p->unk8 = next->unk8;
            free3(next);
            return;
        }
    }
}

s32 kaj_heap_free_space(Unk_801D3924 *heap) {
    Unk_801D395C *p;

    if (heap->unk14 == NULL) {
        return heap->unk0;
    }
    for (p = heap->unk14; p->unk8 != NULL; p = p->unk8) {
    }
    return heap->unk8 - (p->unk0 + p->unk4);
}

void kaj_heap_free_all(Unk_801D3924 *heap) {
    Unk_801D395C *p = heap->unk14;
    Unk_801D395C *next;

    while (p != NULL) {
        next = p->unk8;
        if (p != NULL) {
            free3(p);
        }
        p = next;
    }
}

INCLUDE_RODATA("asm/nonmatchings/kaj/801D1E70", D_80172FD0);

INCLUDE_RODATA("asm/nonmatchings/kaj/801D1E70", kaj_map_str_place_b);

INCLUDE_RODATA("asm/nonmatchings/kaj/801D1E70", kaj_map_str_place_rm);

INCLUDE_RODATA("asm/nonmatchings/kaj/801D1E70", kaj_map_str_place_f);

INCLUDE_RODATA("asm/nonmatchings/kaj/801D1E70", kaj_map_str_city_mp);

s32 kaj_map_load_city_dir(void) {
    Unk_801D3060 file;

    if (kaj_map_mode == 1 && kaj_map_slot != 0 && (s16)kaj_cdmgr_is_ready(kaj_map_slot)) {
        if (kaj_map_dir_slot == 0) {
            if (kaj_cdmgr_find_file(&file, "\\C\\CITY.F;1") == 0) {
                kaj_map_dir_slot = kaj_cdmgr_load(&file, 0, 0);
            }
        } else if (kaj_map_dir_slot > 0 && (s16)kaj_cdmgr_is_ready(kaj_map_dir_slot)) {
            kaj_cdmgr_find_file(&file, "\\C\\CITY.F;1");
            if (kaj_cdmgr_rebase_dir(kaj_map_dir_slot, file.unk8, "\\C\\CITY.BC;1") == 0) {
                return 1;
            }
        }
    }
    return 0;
}

static inline s32 func_801D3C50_inline(char *buf, s32 type) {
    Unk_801D32F0 **q = NULL;
    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        q = (Unk_801D32F0 **)kaj_cdmgr_get(kaj_map_slot);
    }
    if (q != NULL) {
        if (type != 0) {
            sprintf(buf, kaj_map_str_place_rm, kaj_map_letter, *q);
        } else {
            sprintf(buf, kaj_map_str_place_f, kaj_map_letter, *q);
        }
        return 1;
    }
    return 0;
}

s32 kaj_map_load_place_dir(void) {
    char name[32];
    Unk_801D3060 file;

    if (kaj_map_mode != 2 || kaj_map_slot == 0 || !(s16)kaj_cdmgr_is_ready(kaj_map_slot)) {
        return 0;
    }
    if (kaj_map_dir_slot == 0) {
        if (func_801D3C50_inline(name, 0) && kaj_cdmgr_find_file(&file, name) == 0) {
            kaj_map_dir_slot = kaj_cdmgr_load(&file, 0, 0);
            return 0;
        }
    } else {
        if (kaj_map_dir_slot <= 0) {
            return 1;
        }
        if (!(s16)kaj_cdmgr_is_ready(kaj_map_dir_slot)) {
            return 0;
        }
        func_801D3C50_inline(name, 0);
        kaj_cdmgr_find_file(&file, name);
        func_801D3C50_inline(name, 1);
        if (kaj_cdmgr_rebase_dir(kaj_map_dir_slot, file.unk8, name) != 0) {
            return 0;
        }
        kaj_map_fix_place();
    }
    return 1;
}

s32 kaj_map_cell_exists(s16 cx, s16 cy) {
    Unk_801D3E1C **city;
    s32 ret;

    ret = 0;
    if (kaj_map_mode != 1) {
        city = (Unk_801D3E1C **)ret;
    } else {
        if (kaj_map_slot > 0) {
            ret = kaj_cdmgr_get(kaj_map_slot);
        }
        city = (Unk_801D3E1C **)ret;
    }
    if (city != NULL) {
        if (cx >= 0 && cx < (*city)->unk14 && cy >= 0 && cy < (*city)->unk18) {
            if (((s16 *)(*city + 1))[(cx * (*city)->unk18 + cy) * 2] != 0) {
                return 1;
            }
        }
    }
    return 0;
}

static inline s32 func_801D3EEC_inline(void) {
    s32 ret = 0;
    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    return ret;
}

static inline u8 func_801D3EEC_inline2(s32 cx, s32 cy) {
    Unk_801D32F0 **city = (Unk_801D32F0 **)func_801D3EEC_inline();
    if (city == NULL) {
        return 0;
    }
    if (!(((*city)->unk4 <= cx && cx <= (*city)->unkC) || (cx <= (*city)->unk4 && (*city)->unkC <= cx))) {
        return 0;
    }
    if (!(((*city)->unk8 <= cy && cy <= (*city)->unk10) || (cy <= (*city)->unk8 && (*city)->unk10 <= cy))) {
        return 0;
    }
    return 1;
}

s32 kaj_map_cell_flags(s16 cx, s16 cy, u8 layer, u8 *flags) {
    Unk_801D32F0 **city = (Unk_801D32F0 **)func_801D3EEC_inline();
    u8 *entry;

    if (city != NULL && func_801D3EEC_inline2(cx, cy)) {
        entry = (u8 *)&(*city)->unk20[(cx * (*city)->unk18 + cy) * 2];
        if (((s16 *)entry)[0] == -1) {
            entry = (u8 *)&(*city)->unk20[(((s16 *)entry)[1] + layer) * 2];
        }
        if (layer == 0) {
            *flags = entry[2];
        } else {
            *flags = entry[3];
        }
        return 1;
    }
    return 0;
}

s32 kaj_map_cell_link(s16 cx, s16 cy, u8 layer, s16 nx, s16 ny, u8 *next_layer) {
    u8 flags;

    if ((u8)kaj_map_cell_flags(cx, cy, layer, &flags)) {
        if (nx == cx + 1 && ny == cy) {
            if (flags & 4) {
                if (flags & 0x40) {
                    *next_layer = 1;
                } else {
                    *next_layer = 0;
                }
            }
        } else if (nx == cx && ny == cy + 1) {
            if (flags & 8) {
                if (flags & 0x80) {
                    *next_layer = 1;
                } else {
                    *next_layer = 0;
                }
            }
        } else if (nx == cx - 1 && ny == cy) {
            if (flags & 1) {
                if (flags & 0x10) {
                    *next_layer = 1;
                } else {
                    *next_layer = 0;
                }
            }
        } else if (nx == cx && ny == cy - 1) {
            if (flags & 2) {
                if (flags & 0x20) {
                    *next_layer = 1;
                } else {
                    *next_layer = 0;
                }
            }
        } else {
            *next_layer = 0;
        }
        if ((u8)kaj_map_cell_exists(nx, ny)) {
            return 1;
        }
    }
    *next_layer = 0;
    return 0;
}

u8 kaj_map_next_neighbor(s16 cx, s16 cy, u8 layer, s16 *nx, s16 *ny, u8 *next_layer) {
    u8 flags;
    u8 flags2;

    if (*nx == -1 && *ny == -1) {
        return 0;
    }
    if (!(u8)kaj_map_cell_flags(cx, cy, layer, &flags)) {
        return 0;
    }
    if (*nx == cx && *ny == cy) {
        *nx = cx + 1;
        *ny = cy;
        if (flags & 4) {
            if (flags & 0x40) {
                *next_layer = 1;
            } else {
                *next_layer = 0;
            }
            if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                return 1;
            }
        }
    }
    if (*nx == cx + 1 && *ny == cy) {
        *nx = cx;
        *ny = cy + 1;
        if (flags & 8) {
            if (flags & 0x80) {
                *next_layer = 1;
            } else {
                *next_layer = 0;
            }
            if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                return 1;
            }
        }
    }
    if (*nx == cx && *ny == cy + 1) {
        *nx = cx - 1;
        *ny = cy;
        if (flags & 1) {
            if (flags & 0x10) {
                *next_layer = 1;
            } else {
                *next_layer = 0;
            }
            if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                return 1;
            }
        }
    }
    if (*nx == cx - 1 && *ny == cy) {
        *nx = cx;
        *ny = cy - 1;
        if (flags & 2) {
            if (flags & 0x20) {
                *next_layer = 1;
            } else {
                *next_layer = 0;
            }
            if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                return 1;
            }
        }
    }
    if (*nx == cx && *ny == cy - 1) {
        *nx = cx + 2;
        *ny = cy;
        if (flags & 4) {
            if ((u8)kaj_map_cell_flags(cx + 1, cy, (flags >> 6) & 1, &flags2)) {
                if (flags2 & 4) {
                    if (flags2 & 0x40) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx + 2 && *ny == cy) {
        *nx = cx;
        *ny = cy + 2;
        if (flags & 8) {
            if ((u8)kaj_map_cell_flags(cx, cy + 1, flags >> 7, &flags2)) {
                if (flags2 & 8) {
                    if (flags2 & 0x80) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx && *ny == cy + 2) {
        *nx = cx - 2;
        *ny = cy;
        if (flags & 1) {
            if ((u8)kaj_map_cell_flags(cx - 1, cy, (flags >> 4) & 1, &flags2)) {
                if (flags2 & 1) {
                    if (flags2 & 0x10) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx - 2 && *ny == cy) {
        *nx = cx;
        *ny = cy - 2;
        if (flags & 2) {
            if ((u8)kaj_map_cell_flags(cx, cy - 1, (flags >> 5) & 1, &flags2)) {
                if (flags2 & 2) {
                    if (flags2 & 0x20) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx && *ny == cy - 2) {
        *nx = cx + 1;
        *ny = cy + 1;
        if (flags & 4) {
            if ((u8)kaj_map_cell_flags(cx + 1, cy, (flags >> 6) & 1, &flags2)) {
                if (flags2 & 8) {
                    if (flags2 & 0x80) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
        if (flags & 8) {
            if ((u8)kaj_map_cell_flags(cx, cy + 1, flags >> 7, &flags2)) {
                if (flags2 & 4) {
                    if (flags2 & 0x40) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx + 1 && *ny == cy + 1) {
        *nx = cx - 1;
        *ny = cy + 1;
        if (flags & 8) {
            if ((u8)kaj_map_cell_flags(cx, cy + 1, flags >> 7, &flags2)) {
                if (flags2 & 1) {
                    if (flags2 & 0x10) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
        if (flags & 1) {
            if ((u8)kaj_map_cell_flags(cx - 1, cy, (flags >> 4) & 1, &flags2)) {
                if (flags2 & 8) {
                    if (flags2 & 0x80) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx - 1 && *ny == cy + 1) {
        *nx = cx - 1;
        *ny = cy - 1;
        if (flags & 1) {
            if ((u8)kaj_map_cell_flags(cx - 1, cy, (flags >> 4) & 1, &flags2)) {
                if (flags2 & 2) {
                    if (flags2 & 0x20) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
        if (flags & 2) {
            if ((u8)kaj_map_cell_flags(cx, cy - 1, (flags >> 5) & 1, &flags2)) {
                if (flags2 & 1) {
                    if (flags2 & 0x10) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx - 1 && *ny == cy - 1) {
        *nx = cx + 1;
        *ny = cy - 1;
        if (flags & 2) {
            if ((u8)kaj_map_cell_flags(cx, cy - 1, (flags >> 5) & 1, &flags2)) {
                if (flags2 & 4) {
                    if (flags2 & 0x40) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
        if (flags & 4) {
            if ((u8)kaj_map_cell_flags(cx + 1, cy, (flags >> 6) & 1, &flags2)) {
                if (flags2 & 2) {
                    if (flags2 & 0x20) {
                        *next_layer = 1;
                    } else {
                        *next_layer = 0;
                    }
                    if ((u8)kaj_map_cell_exists(*nx, *ny)) {
                        return 1;
                    }
                }
            }
        }
    }
    if (*nx == cx + 1 && *ny == cy - 1) {
        *nx = -1;
        *ny = -1;
    }
    return 0;
}

static inline u8 func_801D4FA0_inline(s32 x, s32 y) {
    Unk_801D32F0 **city;
    s32 ret = 0;
    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    city = (Unk_801D32F0 **)ret;
    if (city == NULL) {
        return 0;
    }
    if (!((x >= (*city)->unk4 && x <= (*city)->unkC) || (x <= (*city)->unk4 && x >= (*city)->unkC))) {
        return 0;
    }
    if (!((y >= (*city)->unk8 && y <= (*city)->unk10) || (y <= (*city)->unk8 && y >= (*city)->unk10))) {
        return 0;
    }
    return 1;
}

void kaj_map_world_to_cell(s32 x, s32 y, s32 *cx, s32 *cy) {
    Unk_801D32F0 **city;
    s32 ret = 0;
    s32 w;
    s32 h;

    *cx = -1;
    *cy = -1;
    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    city = (Unk_801D32F0 **)ret;
    if (city != NULL && func_801D4FA0_inline(x, y)) {
        w = ((*city)->unkC - (*city)->unk4) / (*city)->unk14;
        h = ((*city)->unk10 - (*city)->unk8) / (*city)->unk18;
        if (w != 0 && h != 0) {
            *cx = (x - (*city)->unk4) / w;
            *cy = (y - (*city)->unk8) / h;
        }
    }
}

s32 kaj_map_update_city(s32 x, s32 y) {
    s32 cx;
    s32 cy;

    if (func_801D4FA0_inline(x, y)) {
        kaj_map_world_to_cell(x, y, &cx, &cy);
        if ((u8)kaj_map_cell_exists(cx, cy)) {
            return kaj_map_stream_cell(cx, cy);
        }
        return 0;
    }
    return 0;
}

void kaj_map_set_room(Unk_801E7830 *room, u8 *entry) {
    s32 ret;
    Unk_801D6B58 **place = NULL;
    Unk_801D5BE4 *group;
    s16 i;
    s16 j;

    if (entry[1] == room->unk0 && entry[2] == room->unk1) {
        return;
    }
    for (i = 0; i < room->unkA; i++) {
        if (room->unk10[i] != 0) {
            kaj_cdmgr_release(room->unk10[i]);
            room->unk10[i] = 0;
        }
    }
    room->unk0 = entry[1];
    room->unk1 = entry[2];
    room->unkA = 0;
    room->unk6 = 0;
    room->unk4 = 0;
    for (i = 0; i < 32; i++) {
        room->unk10[i] = 0;
    }
    ret = 0;
    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (Unk_801D6B58 **)ret;
    if (place != NULL) {
        for (room->unk2 = 0; room->unk2 < (*place)->unkE; room->unk2++) {
            group = &(*place)->unk14[room->unk2];
            for (j = 0; j < group->unk2; j++) {
                if (((Unk_801D50F4 *)group->unk8)[j].unk0 == room->unk0 && ((Unk_801D50F4 *)group->unk8)[j].unk1 == room->unk1) {
                    return;
                }
            }
        }
    } else {
        room->unk2 = (*place)->unkE;
    }
}

static inline s16 func_801D5324_first(Unk_801E7830 *room, s16 *out) {
    Unk_801D6B58 **place = NULL;
    Unk_801D5BE4 *group;
    s32 ret = 0;
    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (Unk_801D6B58 **)ret;
    if (place != NULL && room->unk2 < (*place)->unkE) {
        group = &(*place)->unk14[room->unk2];
        if (room->unk4 < group->unk0) {
            *out = ((s16 *)group->unk4)[room->unk4];
            if (*out != 0) {
                return 1;
            }
        }
    }
    return 0;
}

static inline s16 func_801D5324_next(Unk_801E7830 *room, s16 *out) {
    Unk_801D6B58 **place = NULL;
    Unk_801D5BE4 *group;
    s32 ret = 0;
    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (Unk_801D6B58 **)ret;
    if (place != NULL && room->unk2 < (*place)->unkE) {
        group = &(*place)->unk14[room->unk2];
        if (room->unk4 < group->unk0 - 1) {
            room->unk4++;
            *out = ((s16 *)group->unk4)[room->unk4];
            return 1;
        }
    }
    return 0;
}

static inline s16 func_801D5324_get(s16 id, Unk_801D2A48 *file) {
    if (kaj_cdmgr_dir_entry(kaj_map_dir_slot, id, (Unk_801D3060 *)file) == 0) {
        return 1;
    }
    return 0;
}

void kaj_map_list_room_files(s32 area, Unk_801E7830 *room) {
    Unk_801D2A48 file;
    s16 id;
    s32 ret;
    Unk_801D6B58 **place;
    Unk_801D6940 *area_desc;
    Unk_801D5324 *r;
    s32 max;
    s32 total;
    s32 i;
    s32 j;
    s32 k;
    s32 ok;

    if (room->unk6 != 0) {
        return;
    }
    max = kaj_cdmgr_pool_size(1);
    total = 0;
    kaj_map_file_count = 0;
    for (i = 0; i < 20; i++) {
        if (i == 0) {
            ok = func_801D5324_first(room, &id);
        } else {
            ok = func_801D5324_next(room, &id);
        }
        if (!ok) {
            break;
        }
        if (func_801D5324_get(id, &file)) {
            for (j = 0; j < kaj_map_file_count; j++) {
                if (kaj_map_file_list[j].unk4 == file.unk4) {
                    break;
                }
            }
            if (j >= kaj_map_file_count) {
                total += file.unk10;
                if (total >= max) {
                    break;
                }
                file.unk14 = 3;
                kaj_map_file_list[kaj_map_file_count] = file;
                kaj_map_file_count++;
            }
        }
    }
    ret = 0;
    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (Unk_801D6B58 **)ret;
    if (place != NULL) {
        area_desc = &(*place)->unk10[area];
        r = (Unk_801D5324 *)area_desc->unk14;
        for (i = 0; i < area_desc->unkE; i++, r++) {
            if (kaj_cdmgr_find_slot(1, r->unk0) == NULL) {
                for (j = 0; j < kaj_map_file_count; j++) {
                    if (kaj_map_file_list[j].unk4 == r->unk0) {
                        break;
                    }
                }
                if (j == kaj_map_file_count) {
                    continue;
                }
            }
            for (j = 0; j < r->unk2; j++) {
                for (k = 0; k < kaj_map_file_count; k++) {
                    if (kaj_map_file_list[k].unk4 == r->unk4[j]) {
                        break;
                    }
                }
                if (k < kaj_map_file_count) {
                    continue;
                }
                if (func_801D5324_get(r->unk4[j], &file)) {
                    total += file.unk10;
                    if (total >= max) {
                        break;
                    }
                    file.unk14 = 5;
                    kaj_map_file_list[kaj_map_file_count] = file;
                    kaj_map_file_count++;
                }
            }
            if (j < r->unk2) {
                break;
            }
        }
        for (i = 0; i < area_desc->unk10; i++) {
            for (j = 0; j < kaj_map_file_count; j++) {
                if (kaj_map_file_list[j].unk4 == ((s16 *)area_desc->unk18)[i]) {
                    break;
                }
            }
            if (j < kaj_map_file_count) {
                continue;
            }
            if (func_801D5324_get(((s16 *)area_desc->unk18)[i], &file)) {
                total += file.unk10;
                if (total >= max) {
                    break;
                }
                file.unk14 = 6;
                kaj_map_file_list[kaj_map_file_count] = file;
                kaj_map_file_count++;
            }
        }
    }
    qsort(kaj_map_file_list, kaj_map_file_count, sizeof(Unk_801D2A48), kaj_map_cmp_index);
}

static inline u8 func_801D5934_inline(Unk_801E7830 *room, u8 *entry) {
    if (entry[1] != room->unk0 || entry[2] != room->unk1) {
        return 1;
    }
    return 0;
}

static inline s32 func_801D5934_inline2(void) {
    Unk_801E7830 *room = &kaj_map_rooms[kaj_map_room_cur];
    if (room->unk6 > 0) {
        return room->unkA;
    }
    return 0;
}

static inline s32 func_801D5934_inline3(Unk_801E7830 *room, u8 *entry, s32 prev) {
    s16 moved = 0;
    s32 *buf = room->unk10;
    if (kaj_cdmgr_count_refs(kaj_map_file_count, kaj_map_file_list, buf, 1) == 0) {
        room->unk6 = 1;
    }
    D_801DFFE4 = 0;
    kaj_map_room_cur = kaj_map_room_cur == 0;
    kaj_map_set_room(&kaj_map_rooms[1 - kaj_map_room_cur], entry);
    if (kaj_cdmgr_load_list(&kaj_map_file_count, kaj_map_file_list, buf, 1, &moved) == 0) {
        room->unk6 = 1;
    }
    room->unkA = kaj_map_file_count;
    if (room->unk6 == 1) {
        return prev != kaj_map_file_count;
    }
    if (moved != 0) {
        return 3;
    }
    return 2;
}

s32 kaj_map_update_place(s32 area, u8 *entry) {
    s16 moved = 0;
    s32 ret = 0;
    s32 prev;
    s32 *buf;
    Unk_801E7830 *room;
    Unk_801E7830 *r;

    if (!func_801D5934_inline(&kaj_map_rooms[kaj_map_room_cur], entry)) {
        if (D_801DFFE4 != 0) {
            D_801DFFE4 = 0;
            ret = 1;
        }
        return ret;
    }
    if (!func_801D5934_inline(&kaj_map_rooms[1 - kaj_map_room_cur], entry)) {
        return ret;
    }
    if ((s16)kaj_cdmgr_is_idle() == 0) {
        return ret;
    }
    prev = func_801D5934_inline2();
    kaj_cdmgr_clear_dirty();
    kaj_map_set_room(&kaj_map_rooms[1 - kaj_map_room_cur], entry);
    kaj_map_list_room_files(area, &kaj_map_rooms[1 - kaj_map_room_cur]);
    room = &kaj_map_rooms[1 - kaj_map_room_cur];
    r = room;
    buf = room->unk10;
    if (kaj_cdmgr_count_refs(kaj_map_file_count, kaj_map_file_list, buf, 1) == 0) {
        room->unk6 = 1;
    }
    D_801DFFE4 = 0;
    kaj_map_room_cur = kaj_map_room_cur == 0;
    kaj_map_set_room(&kaj_map_rooms[1 - kaj_map_room_cur], entry);
    if (kaj_cdmgr_load_list(&kaj_map_file_count, kaj_map_file_list, buf, 1, &moved) == 0) {
        room->unk6 = 1;
    }
    r->unkA = kaj_map_file_count;
    if (r->unk6 == 1) {
        ret = prev != kaj_map_file_count;
    } else if (moved != 0) {
        ret = 3;
    } else {
        ret = 2;
    }
    return ret;
}

void kaj_map_fix_place(void) {
    s32 ret = 0;
    Unk_801D6B58 **place;
    Unk_801D6940 *area_desc;
    Unk_801D6DC8 *r;
    Unk_801D5BE4 *group;
    s32 i;
    s32 j;

    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (Unk_801D6B58 **)ret;
    if (place != NULL) {
        (*place)->unk10 = (Unk_801D6940 *)((s32)*place + (s32)(*place)->unk10);
        area_desc = (*place)->unk10;
        for (i = 0; i < (*place)->unkC; i++, area_desc++) {
            r = area_desc->unk14 = (void *)((s32)*place + (s32)area_desc->unk14);
            for (j = 0; j < area_desc->unkE; j++, r++) {
                r->unk4 = (s32)*place + r->unk4;
            }
            area_desc->unk18 = (s32)*place + area_desc->unk18;
        }
        (*place)->unk14 = (void *)((s32)*place + (s32)(*place)->unk14);
        for (i = 0; i < (*place)->unkE; i++) {
            group = &(*place)->unk14[i];
            group->unk4 = (s32)*place + group->unk4;
            group->unk8 = (s32)*place + group->unk8;
        }
    }
}

void kaj_map_reset_cells(void) {
    Unk_801E7950 *cell;
    s32 i;

    cell = &kaj_map_cells[kaj_map_cell_cur];
    if (cell != NULL) {
        cell->unk0 = -1;
        cell->unk2 = -1;
        cell->unk4 = -1;
        cell->unk6 = -1;
        cell->unkC = 0;
        cell->unk8 = 0;
        cell->unk9 = 0;
        cell->unkA = -1;
        for (i = 19; i >= 0; i--) {
            cell->unk10[i] = 0;
        }
    }
    cell = &kaj_map_cells[1 - kaj_map_cell_cur];
    if (cell != NULL) {
        cell->unk0 = -1;
        cell->unk2 = -1;
        cell->unk4 = -1;
        cell->unk6 = -1;
        cell->unkC = 0;
        cell->unk8 = 0;
        cell->unk9 = 0;
        cell->unkA = -1;
        for (i = 19; i >= 0; i--) {
            cell->unk10[i] = 0;
        }
    }
}

static inline u8 func_801D5E28_inline(s16 cx, s16 cy, u8 layer, Unk_801D2A48 *file) {
    Unk_801D32F0 **city = NULL;
    s16 *entry;
    s32 ret = 0;
    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    city = (Unk_801D32F0 **)ret;
    if (city == NULL) {
        return 0;
    }
    if (cx < 0 || cx >= (*city)->unk14) {
        return 0;
    }
    if (cy < 0 || cy >= (*city)->unk18) {
        return 0;
    }
    entry = &(*city)->unk20[(cx * (*city)->unk18 + cy) * 2];
    if (entry[0] == -1) {
        entry = &(*city)->unk20[(entry[1] + layer) * 2];
    }
    if (kaj_cdmgr_dir_entry(kaj_map_dir_slot, entry[0], (Unk_801D3060 *)file) == 0) {
        return 1;
    }
    return 0;
}

void kaj_map_list_cell_files(Unk_801E7950 *cell) {
    Unk_801D2A48 file;
    s16 cx;
    s16 cy;
    u8 cd;
    s16 x;
    s16 y;
    u8 layer;
    s32 max;
    s32 total;
    s32 i;
    s32 j;

    x = cx = cell->unk0;
    y = cy = cell->unk2;
    layer = cell->unk8;
    cd = cell->unk9;
    max = kaj_cdmgr_pool_size(1);
    total = 0;
    kaj_map_file_count = 0;
    for (i = 0; i < 20; i++) {
        if (!func_801D5E28_inline(cx, cy, cd, &file)) {
            if (!kaj_map_next_neighbor(x, y, layer, &cx, &cy, &cd)) {
                break;
            }
        } else {
            for (j = 0; j < kaj_map_file_count; j++) {
                if (kaj_map_file_list[j].unk4 == file.unk4) {
                    break;
                }
            }
            if (j < kaj_map_file_count) {
                if (!kaj_map_next_neighbor(x, y, layer, &cx, &cy, &cd)) {
                    break;
                }
            } else {
                total += file.unk10;
                if (total >= max) {
                    break;
                }
                file.unk14 = 1;
                kaj_map_file_list[kaj_map_file_count] = file;
                kaj_map_file_count++;
                if (!kaj_map_next_neighbor(x, y, layer, &cx, &cy, &cd)) {
                    break;
                }
            }
        }
    }
    qsort(kaj_map_file_list, kaj_map_file_count, sizeof(Unk_801D2A48), kaj_map_cmp_index);
    i = 0;
    while (i < kaj_map_file_count) {
        i++;
    }
}

static inline s32 func_801D6120_inline(Unk_801E7950 *cell, s16 x, s16 y) {
    if (cell->unk0 != x || cell->unk2 != y) {
        return 1;
    }
    return 0;
}

static inline s32 func_801D6120_inline2(void) {
    Unk_801E7950 *cell = &kaj_map_cells[kaj_map_cell_cur];
    return cell->unkA > 0 ? cell->unkC : 0;
}

static inline void func_801D6120_inline3(Unk_801E7950 *cell, s16 x, s16 y) {
    s32 i;
    u8 next_layer;
    if (cell->unk0 == x && cell->unk2 == y) {
        return;
    }
    for (i = 0; i < cell->unkC; i++) {
        if (cell->unk10[i] != 0) {
            kaj_cdmgr_release(cell->unk10[i]);
            cell->unk10[i] = 0;
        }
    }
    cell->unkC = 0;
    cell->unkA = 0;
    if (cell->unk0 >= 0 && cell->unk2 >= 0) {
        next_layer = 0;
        kaj_map_cell_link(cell->unk0, cell->unk2, cell->unk8, x, y, &next_layer);
        cell->unk8 = next_layer;
    } else {
        cell->unk8 = 0;
    }
    cell->unk0 = x;
    cell->unk2 = y;
    cell->unk4 = x;
    cell->unk6 = y;
    cell->unk9 = cell->unk8;
}

s32 kaj_map_stream_cell(s16 cx, s16 cy) {
    s16 moved;
    s32 ret = 0;
    s32 prev;
    Unk_801E7950 *cell;

    if (!func_801D6120_inline(&kaj_map_cells[kaj_map_cell_cur], cx, cy)) {
        return ret;
    }
    if (!func_801D6120_inline(&kaj_map_cells[1 - kaj_map_cell_cur], cx, cy)) {
        return ret;
    }
    if ((s16)kaj_cdmgr_is_idle() == 0) {
        return ret;
    }
    prev = func_801D6120_inline2();
    kaj_cdmgr_clear_dirty();
    func_801D6120_inline3(&kaj_map_cells[1 - kaj_map_cell_cur], cx, cy);
    kaj_map_list_cell_files(&kaj_map_cells[1 - kaj_map_cell_cur]);
    cell = &kaj_map_cells[1 - kaj_map_cell_cur];
    if (kaj_cdmgr_count_refs(kaj_map_file_count, kaj_map_file_list, cell->unk10, 1) == 0) {
        cell->unkA = 1;
    }
    kaj_map_cell_cur = kaj_map_cell_cur == 0;
    func_801D6120_inline3(&kaj_map_cells[1 - kaj_map_cell_cur], cx, cy);
    if (kaj_cdmgr_load_list(&kaj_map_file_count, kaj_map_file_list, cell->unk10, 1, &moved) == 0) {
        cell->unkA = 1;
    }
    cell->unkC = kaj_map_file_count;
    if (cell->unkA == 1) {
        ret = prev != kaj_map_file_count;
    } else if (moved != 0) {
        ret = 3;
    } else {
        ret = 2;
    }
    return ret;
}

void kaj_map_cell_slots(s16 *count, s32 *handles) {
    Unk_801E7950 *cell;
    s16 n;
    s16 i;
    s16 j;
    u8 found;
    s16 max;

    max = *count;
    *count = 0;
    cell = &kaj_map_cells[kaj_map_cell_cur];
    if (cell->unkA > 0) {
        n = 0;
        for (i = 0; i < cell->unkC; i++) {
            found = 0;
            for (j = 0; j < n; j++) {
                if (handles[j] == cell->unk10[i]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                handles[n] = cell->unk10[i];
                n++;
                if (n == max) {
                    break;
                }
            }
        }
        *count = n;
    }
}

void kaj_map_cell_loaded_slots(s16 *count, s32 *handles) {
    s16 max = *count;
    Unk_801E7950 *cell;
    s16 n;
    s16 i;
    s16 j;
    u8 found;

    *count = 0;
    n = 0;
    cell = &kaj_map_cells[kaj_map_cell_cur];
    for (i = 0; i < cell->unkC; i++) {
        found = 0;
        for (j = 0; j < n; j++) {
            if (handles[j] == cell->unk10[i]) {
                found = 1;
                break;
            }
        }
        if (!found && kaj_cdmgr_is_loaded(cell->unk10[i])) {
            handles[n] = cell->unk10[i];
            n++;
            if (n == max) {
                break;
            }
        }
    }
    *count = n;
}

s32 kaj_map_open_city(void) {
    Unk_801D3060 file;
    s32 ret;

    kaj_cdmgr_init();
    kaj_map_mode = 1;
    kaj_map_dir_slot = 0;
    ret = kaj_cdmgr_find_file(&file, kaj_map_str_city_mp);
    if (ret == 0) {
        kaj_map_slot = kaj_cdmgr_load(&file, 0, 2);
        if (kaj_map_slot == 0) {
            ret = -1;
        }
    }
    kaj_map_reset_cells();
    return ret;
}

s32 kaj_map_city_ready(void) {
    Unk_801E7950 *cell = &kaj_map_cells[kaj_map_cell_cur];

    if (cell != NULL && cell->unkA > 0) {
        return 1;
    }
    return 0;
}

s32 kaj_map_open_place(s32 letter, char *place_name) {
    char name[32];
    Unk_801D3060 file;
    s32 ret;
    char *p = name;
    Unk_801D3060 *f = &file;

    kaj_cdmgr_init();
    kaj_map_mode = 2;
    kaj_map_slot = 0;
    kaj_map_dir_slot = 0;
    kaj_map_letter = letter;
    sprintf(p, kaj_map_str_place_b, letter, place_name);
    ret = kaj_cdmgr_find_file(f, p);
    if (ret == 0) {
        kaj_map_slot = kaj_cdmgr_load(f, 0, 4);
        if (kaj_map_slot == 0) {
            ret = -1;
        }
    } else {
        ret = -1;
    }
    kaj_map_reset_rooms();
    return ret;
}

void kaj_map_get_entry(s32 area, s32 *pos, u8 *entry) {
    s32 ret = 0;
    Unk_801D32F0 **place = NULL;
    Unk_801D6940 *area_desc;

    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    place = (Unk_801D32F0 **)ret;
    if (place != NULL) {
        area_desc = &((Unk_801D6940 *)(*place)->unk10)[area];
        pos[0] = area_desc->unk0;
        pos[1] = area_desc->unk4;
        pos[2] = area_desc->unk8;
        entry[0] = 0;
        entry[1] = area_desc->unkC;
        entry[2] = area_desc->unkD;
    }
}

void kaj_map_set_cell_ready(void) {
    kaj_map_get_cell_state()->unkA = 1;
}

void kaj_map_set_room_ready(void) {
    Unk_801E7830 *room = &kaj_map_rooms[kaj_map_room_cur];

    room->unk6 = 1;
}

void kaj_map_reset_rooms(void) {
    Unk_801E7830 *room;
    s32 i;

    room = &kaj_map_rooms[kaj_map_room_cur];
    if (room != NULL) {
        room->unk0 = 0;
        room->unk1 = 0;
        room->unk2 = 0;
        room->unk4 = 0;
        room->unk8 = 0;
        room->unkA = 0;
        room->unk6 = 0;
        for (i = 31; i >= 0; i--) {
            room->unk10[i] = 0;
        }
    }
    room = &kaj_map_rooms[1 - kaj_map_room_cur];
    if (room != NULL) {
        room->unk0 = 0;
        room->unk1 = 0;
        room->unk2 = 0;
        room->unk4 = 0;
        room->unk8 = 0;
        room->unkA = 0;
        room->unk6 = 0;
        for (i = 31; i >= 0; i--) {
            room->unk10[i] = 0;
        }
    }
}

s32 kaj_map_get_city(void) {
    s32 ret = 0;

    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    return ret;
}

s32 kaj_map_get_place(void) {
    s32 ret = 0;

    if (kaj_map_mode == 2 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    return ret;
}

s32 kaj_map_get_dir_slot(void) {
    return kaj_map_dir_slot;
}

s32 kaj_map_in_bounds(s32 x, s32 y) {
    s32 ret = 0;
    Unk_801D32F0 **city = NULL;

    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    city = (Unk_801D32F0 **)ret;
    if (city == NULL) {
        return 0;
    }
    if (!(((*city)->unk4 <= x && x <= (*city)->unkC) || (x <= (*city)->unk4 && (*city)->unkC <= x))) {
        return 0;
    }
    if (!(((*city)->unk8 <= y && y <= (*city)->unk10) || (y <= (*city)->unk8 && (*city)->unk10 <= y))) {
        return 0;
    }
    return 1;
}

s32 kaj_map_cell_file(s16 cx, s16 cy, u8 layer, Unk_801D3060 *info) {
    s32 ret = 0;
    Unk_801D32F0 **city = NULL;
    s16 *entry;

    if (kaj_map_mode == 1 && kaj_map_slot > 0) {
        ret = kaj_cdmgr_get(kaj_map_slot);
    }
    city = (Unk_801D32F0 **)ret;
    if (city != NULL && cx >= 0 && cx < (*city)->unk14 && cy >= 0 && cy < (*city)->unk18) {
        entry = &(*city)->unk20[(cx * (*city)->unk18 + cy) * 2];
        if (entry[0] == -1) {
            entry = &(*city)->unk20[(entry[1] + layer) * 2];
        }
        if (kaj_cdmgr_dir_entry(kaj_map_dir_slot, entry[0], info) == 0) {
            return 1;
        }
    }
    return 0;
}

s32 kaj_map_cmp_index(Unk_801D6DC8 *a, Unk_801D6DC8 *b) {
    return a->unk4 - b->unk4;
}

s16 kaj_map_room_slot_count(void) {
    Unk_801E7830 *room = &kaj_map_rooms[kaj_map_room_cur];

    if (room->unk6 <= 0) {
        return 0;
    }
    return room->unkA;
}

s32 kaj_map_place_ready(void) {
    Unk_801E7830 *room = &kaj_map_rooms[kaj_map_room_cur];

    if (room != NULL && room->unk6 > 0) {
        return 1;
    }
    return 0;
}

void kaj_map_room_slots(s16 *count, s32 *handles) {
    s16 max = *count;
    Unk_801E7830 *room;
    s16 n;
    s16 i;
    s16 j;
    u8 found;
    s32 handle;

    *count = 0;
    room = &kaj_map_rooms[kaj_map_room_cur];
    n = 0;
    if (room->unk6 > 0) {
        for (i = 0; i < room->unkA; i++) {
            found = 0;
            handle = room->unk10[i];
            for (j = 0; j < n; j++) {
                if (handles[j] == handle) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                handles[n] = handle;
                n++;
                if (n == max) {
                    break;
                }
            }
        }
        *count = n;
    }
}

void kaj_map_room_loaded_slots(s16 *count, s32 *handles) {
    s16 max = *count;
    Unk_801E7830 *room;
    s16 n;
    s16 i;
    s16 j;
    u8 found;
    s32 handle;

    *count = 0;
    n = 0;
    room = &kaj_map_rooms[kaj_map_room_cur];
    for (i = 0; i < room->unkA; i++) {
        found = 0;
        handle = room->unk10[i];
        for (j = 0; j < n; j++) {
            if (handles[j] == handle) {
                found = 1;
                break;
            }
        }
        if (!found && kaj_cdmgr_is_loaded(handle)) {
            handles[n] = handle;
            n++;
            if (n == max) {
                break;
            }
        }
    }
    *count = n;
}

void kaj_map_room_release(s32 handle) {
    Unk_801E7830 *room = &kaj_map_rooms[kaj_map_room_cur];
    s32 i;

    for (i = 0; i < room->unkA; i++) {
        if (room->unk10[i] == handle) {
            kaj_cdmgr_release(room->unk10[i]);
            room->unk10[i] = 0;
            D_801DFFE4 = 1;
            return;
        }
    }
}

Unk_801E7950 *kaj_map_get_cell_state(void) {
    return &kaj_map_cells[kaj_map_cell_cur];
}

s16 kaj_map_cell_slot_count(void) {
    Unk_801E7950 *cell = &kaj_map_cells[kaj_map_cell_cur];
    if (cell->unkA <= 0) {
        return 0;
    }
    return cell->unkC;
}

void kaj_map_set_cell(Unk_801E7950 *cell, s16 cx, s16 cy) {
    s32 i;
    u8 next_layer;

    if (cell->unk0 != cx || cell->unk2 != cy) {
        for (i = 0; i < cell->unkC; i++) {
            if (cell->unk10[i] != 0) {
                kaj_cdmgr_release(cell->unk10[i]);
                cell->unk10[i] = 0;
            }
        }
        cell->unkC = 0;
        cell->unkA = 0;
        if (cell->unk0 >= 0 && cell->unk2 >= 0) {
            next_layer = 0;
            kaj_map_cell_link(cell->unk0, cell->unk2, cell->unk8, cx, cy, &next_layer);
            cell->unk8 = next_layer;
        } else {
            cell->unk8 = 0;
        }
        cell->unk0 = cx;
        cell->unk2 = cy;
        cell->unk4 = cx;
        cell->unk6 = cy;
        cell->unk9 = cell->unk8;
    }
}

s32 kaj_map_cell_changed(s16 *cell, s16 cx, s16 cy) {
    if (cell[0] != cx || cell[1] != cy) {
        return 1;
    }
    return 0;
}
