#ifndef PSYQ_LIBSND_H
#define PSYQ_LIBSND_H

#include "types.h"

/* LIBSND functions the game calls. */

void SsEnd(void);
void SsInit(void);
void SsQuit(void);
void SsSepClose(s16 access_num);
s16 SsSepOpen(u32 *addr, s16 vab_id, s16 seq_num);
void SsSepPlay(s16 access_num, s16 seq_num, u8 play_mode, s16 l_count);
void SsSepSetVol(s16 access_num, s16 seq_num, s16 voll, s16 volr);
void SsSepStop(s16 access_num, s16 seq_num);
void SsSetMVol(s16 voll, s16 volr);
void SsSetTableSize(char *table, s16 s_max, s16 t_max);
void SsSetTickMode(s32 tick_mode);
void SsStart(void);
void SsUtKeyOffV(s16 voice);
s16 SsUtKeyOnV(s16 voice, s16 vabId, s16 prog, s16 tone, s16 note, s16 fine, s16 voll, s16 volr);
void SsVabClose(s16 vabid);
s16 SsVabOpenHead(u8 *addr, s16 vabid);
s16 SsVabTransBodyPartly(u8 *addr, u32 bufsize, s16 vabid);
s16 SsVabTransCompleted(s16 immediateFlag);

#endif
