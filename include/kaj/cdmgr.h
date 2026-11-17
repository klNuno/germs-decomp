#ifndef KAJ_CDMGR_H
#define KAJ_CDMGR_H

#include "common.h"
#include "game/types.h"

typedef struct {
    s32 lba;
    s32 index;
    u32 size;
    u32 sectors;
    u32 alloc_size;
} CdmgrFile;

typedef struct {
    s32 lba;
    s32 index;
    u32 size;
    u32 sectors;
    u32 alloc_size;
    s32 type;
} CdmgrFileEntry;

typedef struct {
    s32 lba;
    s32 index;
    s32 size;
    s32 sectors;
    s32 alloc_size;
    s32 unk14;
    s32 block;
    u8 pool;
    u8 type;
    s16 next;
    s16 refs;
    s16 load_state;
} CdmgrSlot;

/* Functions of src/kaj/cdmgr.c that other files call or a table names. */
void kaj_cdmgr_init(void);
s32 kaj_cdmgr_poll(void);
s32 kaj_cdmgr_load(CdmgrFile *file, s32 pool, s32 type);
s32 kaj_cdmgr_count_refs(s32 count, CdmgrFileEntry *files, s32 *handles, s32 pool);
s16 kaj_cdmgr_load_list(s32 *count, CdmgrFileEntry *files, s32 *handles, s32 pool, s16 *moved_out);
void kaj_cdmgr_release(s32 handle);
s32 kaj_cdmgr_pool_size(s32 pool);
s32 kaj_cdmgr_rebase_dir(s32 handle, u32 dir_size, char *name);
s32 kaj_cdmgr_find_file(CdmgrFile *info, char *name);
s32 kaj_cdmgr_dir_entry(s32 handle, s16 index, CdmgrFile *info);
s32 kaj_cdmgr_is_idle(void);
s32 kaj_cdmgr_is_ready(s32 handle);
s32 kaj_cdmgr_get(s32 handle);
s32 kaj_cdmgr_get_type(s32 handle);
s32 kaj_cdmgr_is_fresh(s32 handle);
void kaj_cdmgr_mark_used(s32 handle);
CdmgrSlot *kaj_cdmgr_find_slot(s32 pool, s32 index);
void kaj_cdmgr_free_all(void);
s32 kaj_cdmgr_is_loaded(s32 handle);
void kaj_cdmgr_clear_dirty(void);

#endif
