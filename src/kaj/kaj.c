#include "common.h"
#include "kaj/kaj.h"
#include "kaj/event.h"
#include "kaj/misc.h"
#include "kaj/timer.h"
#include "kaj/tss.h"
#include "kaj/view.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libcd.h"
#include "psyq/libetc.h"
#include "psyq/libgpu.h"
#include "psyq/libmcrd.h"

/*
 * The developer library init and kaj_malloc.
 *
 * File boundaries: proven (docs/layout.md): Sony code on both sides; kaj.c asserts.
 */

extern KajSystem kaj_system;
extern char kaj_str_file[];

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
