#include "common.h"

void *malloc3(u32 size);
void *memset(void *dst, s32 c, u32 n);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_801D1BD4;
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
void func_801CD54C(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char D_801DFDBC[];
void ResetCallback(void);
void InitHeap3(void *head, u32 size);
s32 VSync(s32 mode);
void SetDispMask(s32 mask);
void ResetGraph(s32 mode);
s32 ClearImage(Unk_801D1BD4 *rect, s32 r, s32 g, s32 b);
s32 DrawSync(s32 mode);
void PadInit(s32 mode);
s32 CdInit(void);
void MemCardInit(s32 val);
void func_801CC68C(void);
void func_801D0300(void);
void func_801D164C(void);
void func_801CD70C(void);
void func_801D17F0(void);

void *func_801CC898(u32 size) {
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

void func_801CC8F0(void) {
    Unk_801D1BD4 rect;

    ResetCallback();
    InitHeap3((void *)0x80010000, 0x160000);
    VSync(0);
    SetDispMask(0);
    ResetGraph(0);
    rect.unk4 = 0x280;
    rect.unk0 = 0;
    rect.unk2 = 0;
    rect.unk6 = 0x1FF;
    VSync(0);
    ClearImage(&rect, 0, 0, 0);
    DrawSync(0);
    PadInit(0);
    if (CdInit() == 0) {
        func_801CD54C(1, "can't initialize CD-ROM subsystem", D_801DFDBC, 0x3B);
    }
    func_801CC68C();
    func_801D0300();
    func_801D164C();
    func_801CD70C();
    func_801D17F0();
    MemCardInit(1);
    D_801E6DA0.unk0 = 0;
    D_801E6DA0.unk4 = 0;
    D_801E6DA0.unkA = 0;
    VSync(0);
    SetDispMask(1);
}
