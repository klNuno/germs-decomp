#ifndef PSYQ_LIBGS_H
#define PSYQ_LIBGS_H

#include "types.h"

/* LIBGS functions the game calls; the record layouts carry our names. */

typedef struct GsCoordinate2 {
    s32 flg;
    s16 coord_m[0xA];
    s32 coord_tx;
    s32 coord_ty;
    s32 coord_tz;
    u8 unk24[0x2C];
} GsCoordinate2;

void GsDefDispBuff(s32 x0, s32 y0, s32 x1, s32 y1);
void GsGetLs(void *coord, void *m);
void GsGetTimInfo(u32 *im, void *tim);
s32 GsGetWorkBase(void);
void GsInit3D(void);
void GsInitCoordinate2(void *super, void *base);
void GsInitGraph(s32 w, s32 h, s32 intl, s32 dither, s32 vrammode);
void GsInitVcount(void);
void GsLinkObject4(u32 *tmd, void *obj, s32 n);
void GsMapModelingData(u32 *p);
void GsSetLsMatrix(void *m);
void GsSetProjection(s32 arg0);
void GsSetView2(void *arg0);
void GsSetWorkBase(s32 arg0);
void GsSortObject4J(void *obj, void *ot, s32 shift, void *scratch);

#endif
