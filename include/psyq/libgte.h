#ifndef PSYQ_LIBGTE_H
#define PSYQ_LIBGTE_H

#include "types.h"

/* LIBGTE functions the game calls; the record layouts carry our names. */

typedef struct SVector {
    s16 vx;
    s16 vy;
    s16 vz;
    u8 unk6[0x2];
} SVector;

void ApplyMatrixLV(void *arg0, void *arg1, void *arg2);
void InitClip(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
void MatrixNormal(void *m, void *n);
void *RotMatrix(s16 *r, void *m);
void RotMatrixZXY(SVector *arg0, void *arg1);
void RotMatrixZYX(SVector *arg0, void *arg1);
void RotTrans(void *v0, s32 *v1, s32 *flag);
void ScaleMatrix(void *m, void *v);
void SetBackColor(s32 r, s32 g, s32 b);
void SetFarColor(s32 r, s32 g, s32 b);
void SetFogNearFar(s32 a, s32 b, s32 h);
void SetGeomOffset(s32 ofx, s32 ofy);
s32 SquareRoot0(s32 a);
void TransMatrix(void *m, s32 *v);
s32 ratan2(s32 y, s32 x);
s32 rcos(s32 a);
s32 rsin(s32 a);

#endif
