#ifndef PSYQ_LIBCD_H
#define PSYQ_LIBCD_H

#include "types.h"

/* LIBCD functions the game calls; the record layouts carry our names. */

typedef struct CdLoc {
    u8 unk0[0x4];
} CdLoc;

s32 CdControl(u8 com, u8 *param, u8 *result);
void CdFlush(void);
s32 CdInit(void);
void *CdIntToPos(s32 i, void *p);
void *CdLastPos(void);
s32 CdMode(void);
s32 CdPosToInt(void *p);
s32 CdRead(s32 sectors, u32 *buf, s32 mode);
void CdReadBreak(void);
s32 CdReadSync(s32 mode, u8 *result);
void *CdSearchFile(void *fp, char *name);

#endif
