#include "common.h"

typedef struct TimHandle {
    u16 x;
    u16 y;
    u16 w;
    u16 h;
    u16 clut_x;
    u16 clut_y;
    u16 clut_w;
    u16 clut_h;
    u16 u;
    u16 v;
    u16 pixel_shift;
    u16 unk16;
    u16 clut;
    u16 tpage;
    void *clut_orig;
    void *clut_work;
} TimHandle;
void free3(void *ptr);
typedef struct GsImage {
    u32 pmode;
    s16 px;
    s16 py;
    s16 pw;
    s16 ph;
    u32 *pixel;
    s16 cx;
    s16 cy;
    s16 cw;
    s16 ch;
    u32 *clut;
} GsImage;
void GsGetTimInfo(u32 *im, GsImage *tim);
s32 LoadImage(void *rect, u32 *p);
s32 StoreImage(void *rect, u32 *p);
u16 GetTPage(s32 tp, s32 abr, s32 x, s32 y);
u16 GetClut(s32 x, s32 y);
void *kaj_malloc(u32 size);
void kaj_abend(s32 code, char *msg, char *file, s32 line);
extern char kaj_tim_str_file[];

static inline void kaj_tim_save_clut(GsImage *tim, void **buf) {
    s32 size;
    if ((tim->pmode >> 3) & 1) {
        switch (tim->pmode & 7) {
        case 0:
            size = 0x20;
            break;
        case 1:
            size = 0x200;
            break;
        default:
            kaj_abend(9, "No CLUT in this TIM", kaj_tim_str_file, 28);
            break;
        }
        *buf = kaj_malloc(size);
        if (*buf == NULL) {
            kaj_abend(3, "Error Allocating CLUT Buffer", kaj_tim_str_file, 33);
        }
        StoreImage(&tim->cx, *buf);
    }
}

void kaj_tim_load(TimHandle **handle, u32 *tim_file, u16 mode, s16 keep_clut) {
    GsImage tim;
    s16 x;
    s16 y;

    *handle = kaj_malloc(0x24);
    if (*handle == NULL) {
        kaj_abend(3, "Error Allocating TIM Handle", kaj_tim_str_file, 47);
    }
    (*handle)->clut_orig = NULL;
    (*handle)->clut_work = NULL;
    GsGetTimInfo(tim_file + 1, &tim);
    if (mode != 2) {
        LoadImage(&tim.px, tim.pixel);
    }
    x = tim.px >> 6;
    y = tim.py >> 8;
    (*handle)->x = tim.px;
    (*handle)->y = tim.py;
    (*handle)->h = tim.ph;
    (*handle)->w = tim.pw;
    (*handle)->u = tim.px - (x << 6);
    (*handle)->v = tim.py - (y << 8);
    (*handle)->pixel_shift = 0;
    (*handle)->clut = -1;
    (*handle)->tpage = GetTPage(tim.pmode & 7, 0, x << 6, y << 8);
    if ((tim.pmode >> 3) & 1) {
        if (mode != 2) {
            LoadImage(&tim.cx, tim.clut);
        }
        (*handle)->clut = GetClut(tim.cx, tim.cy);
        (*handle)->clut_x = tim.cx;
        (*handle)->clut_y = tim.cy;
        (*handle)->clut_w = tim.cw;
        (*handle)->clut_h = tim.ch;
        if (keep_clut != 0) {
            kaj_tim_save_clut(&tim, &(*handle)->clut_orig);
            kaj_tim_save_clut(&tim, &(*handle)->clut_work);
        }
        switch (tim.pmode & 7) {
        case 0:
            (*handle)->pixel_shift = 2;
            break;
        case 1:
            (*handle)->pixel_shift = 1;
            break;
        }
    }
}

void kaj_tim_free(TimHandle *handle) {
    if (handle != NULL) {
        if (handle->clut_orig != NULL) {
            free3(handle->clut_orig);
            handle->clut_orig = NULL;
        }
        if (handle->clut_work != NULL) {
            free3(handle->clut_work);
            handle->clut_work = NULL;
        }
        free3(handle);
    }
}

void kaj_tim_upload(u32 *tim_file, s16 with_clut) {
    GsImage tim;

    GsGetTimInfo(tim_file + 1, &tim);
    LoadImage(&tim.px, tim.pixel);
    if (with_clut != 0 && ((tim.pmode >> 3) & 1)) {
        LoadImage(&tim.cx, tim.clut);
    }
}

void kaj_tim_upload_hdr(u16 *hdr) {
    GsImage tim;
    s16 with_clut = hdr[1];

    GsGetTimInfo((u32 *)(hdr + 4), &tim);
    LoadImage(&tim.px, tim.pixel);
    if (with_clut != 0 && ((tim.pmode >> 3) & 1)) {
        LoadImage(&tim.cx, tim.clut);
    }
}
