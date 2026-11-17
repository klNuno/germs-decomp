#ifndef KAJ_MISC_H
#define KAJ_MISC_H

#include "common.h"
#include "game/types.h"

typedef struct GsDobj2Handle {
    u32 attribute;
    void *coord2;
    void *tmd;
    u32 id;
} GsDobj2Handle;

typedef struct TmdFileHeader {
    s32 id;
    s32 flags;
    s32 n_obj;
    s32 objects[1];
} TmdFileHeader;

/* Functions of src/kaj/misc.c that other files call or a table names. */
void kaj_tmd_load(GsDobj2Handle **obj, u32 *tmd_file, void *coord);
s32 kaj_tmd_map(u32 *tmd_file);
void kaj_abend(s32 code, char *msg, char *file, s32 line);
void kaj_pad_reset(s16 enable);
s32 kaj_pad_read(void);
void kaj_sound_init(void);
void kaj_tmd_unmap(TmdFileHeader *tmd, s32 base);
void kaj_srand_ticks(void);

#endif
