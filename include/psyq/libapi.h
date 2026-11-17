#ifndef PSYQ_LIBAPI_H
#define PSYQ_LIBAPI_H

#include "types.h"

/* LIBAPI functions the game calls. */

s32 CloseEvent(s32 event);
void DeliverEvent(u32 ev, u32 spec);
s32 DisableEvent(s32 event);
s32 EnableEvent(s32 event);
void EnterCriticalSection(void);
void ExitCriticalSection(void);
void InitHeap3(void *head, u32 size);
s32 OpenEvent(u32 desc, s32 spec, s32 mode, s32 (*func)(void));
s32 SetRCnt(u32 spec, u16 target, s32 mode);
s32 StartRCnt(u32 spec);
s32 StopRCnt(s32 spec);
void UnDeliverEvent(u32 ev, u32 spec);
void *calloc3(s32 n, s32 size);
void exit(s32 code);
void free3(void *ptr);
void *malloc3(u32 size);
void *realloc3(void *ptr, s32 size);

#endif
