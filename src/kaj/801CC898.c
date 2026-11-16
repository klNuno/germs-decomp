#include "common.h"
#include "game/types.h"

void *malloc3(u32 size);
void *memset(void *dst, s32 c, u32 n);
extern KajSystem kaj_system;
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char kaj_str_file[];
void ResetCallback(void);
void InitHeap3(void *head, u32 size);
s32 VSync(s32 mode);
void SetDispMask(s32 mask);
void ResetGraph(s32 mode);
s32 ClearImage(Rect *rect, s32 r, s32 g, s32 b);
s32 DrawSync(s32 mode);
void PadInit(s32 mode);
s32 CdInit(void);
void MemCardInit(s32 val);
void kaj_event_init(void);
void kaj_timer_init(void);
void kaj_tss_init(void);
void kaj_sound_init(void);
void kaj_view_init(void);

void *kaj_malloc(u32 size) {
    void *ptr;

    if (size == 0) {
        return NULL;
    }
    ptr = malloc3(size);
    if (ptr == NULL) {
        return NULL;
    }
    memset(ptr, 0, size);
    return ptr;
}

void kaj_init(void) {
    Rect rect;

    ResetCallback();
    InitHeap3((void *)0x80010000, 0x160000);
    VSync(0);
    SetDispMask(0);
    ResetGraph(0);
    rect.w = 0x280;
    rect.x = 0;
    rect.y = 0;
    rect.h = 0x1FF;
    VSync(0);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    PadInit(0);
    if (CdInit() == 0) {
        kaj_abend(1, "can't initialize CD-ROM subsystem", kaj_str_file, 0x3B);
    }
    kaj_event_init();
    kaj_timer_init();
    kaj_tss_init();
    kaj_sound_init();
    kaj_view_init();
    MemCardInit(1);
    kaj_system.pad_now = 0;
    kaj_system.pad_prev = 0;
    kaj_system.pad_mode = 0;
    VSync(0);
    SetDispMask(1);
}
