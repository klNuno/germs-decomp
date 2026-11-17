#ifndef PSYQ_LIBETC_H
#define PSYQ_LIBETC_H

#include "types.h"

/* LIBETC functions the game calls. */

void PadInit(s32 mode);
u32 PadRead(s32 id);
void ResetCallback(void);
s32 VSync(s32 mode);

#endif
