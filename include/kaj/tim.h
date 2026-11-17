#ifndef KAJ_TIM_H
#define KAJ_TIM_H

#include "common.h"
#include "game/types.h"

/* Functions of src/kaj/tim.c that other files call or a table names. */
void kaj_tim_upload(u32 *tim_file, s16 with_clut);
void kaj_tim_upload_hdr(u16 *hdr);

/* Declared in the calling files, which read the handle through their own TimHandle view:
   kaj_tim_free, kaj_tim_load. */

#endif
