#ifndef PSYQ_LIBMCRD_H
#define PSYQ_LIBMCRD_H

#include "types.h"

/* LIBMCRD functions the game calls. */

void MemCardAccept(s32 arg0);
void MemCardClose(void);
s32 MemCardCreateFile(s32 chan, char *file, s32 blocks);
void MemCardDeleteFile(s32 chan, char *file);
void MemCardExist(s32 arg0);
s32 MemCardFormat(s32 arg0);
s32 MemCardGetDirentry(s32 arg0, char *arg1, void *arg2, s32 *arg3, s32 arg4, s32 arg5);
void MemCardInit(s32 val);
s32 MemCardOpen(s32 chan, char *file, s32 flag);
s32 MemCardReadData(void *adrs, s32 ofs, s32 bytes);
s32 MemCardReadFile(s32 arg0, char *arg1, void *arg2, s32 arg3, s32 arg4);
void MemCardStart(void);
void MemCardStop(void);
s32 MemCardSync(s32 arg0, s32 *arg1, s32 *arg2);
s32 MemCardWriteData(void *adrs, s32 ofs, s32 bytes);

#endif
