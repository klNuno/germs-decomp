#ifndef PSYQ_LIBGPU_H
#define PSYQ_LIBGPU_H

#include "types.h"

/* LIBGPU functions the game calls; the record layouts carry our names. */

typedef struct Rect {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
} Rect;

s32 ClearImage(Rect *rect, s32 r, s32 g, s32 b);
s32 ClearImage2(Rect *rect, s32 r, s32 g, s32 b);
void ClearOTagR(u32 *ot, s32 n);
void DrawOTag(u32 *ot);
s32 DrawSync(s32 mode);
u16 GetClut(s32 x, s32 y);
u16 GetTPage(s32 tp, s32 abr, s32 x, s32 y);
u16 *Krom2RawAdd2(u16 sjis);
s32 LoadImage(void *rect, u32 *p);
s32 LoadImage2(void *rect, void *p);
s32 MoveImage(Rect *rect, s32 x, s32 y);
s32 MoveImage2(Rect *rect, s32 x, s32 y);
void PutDispEnv(void *env);
void PutDrawEnv(void *env);
void ResetGraph(s32 mode);
void SetDefDispEnv(void *env, s32 x, s32 y, s32 w, s32 h);
void SetDefDrawEnv(void *env, s32 x, s32 y, s32 w, s32 h);
void SetDispMask(s32 mask);
void SetDrawMode(void *p, s32 dfe, s32 dtd, s32 tpage, void *tw);
void SetSemiTrans(void *p, s32 abe);
s32 StoreImage(void *rect, u32 *p);
s32 StoreImage2(void *rect, void *p);

#endif
