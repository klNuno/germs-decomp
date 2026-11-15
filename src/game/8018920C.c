#include "common.h"

s32 DisableEvent(s32 event);
s32 CloseEvent(s32 event);
s32 D_801DFEC8;
s32 D_801DFECC;
s32 D_801DFED0;
extern s32 D_801DFF50;
void func_8018AA00(s16 a);
void (*D_801DFEDC)(void);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018920C);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189350);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_801895E0);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018970C);

void func_801898C0(void) {
    D_801DFF50 = 0;
    DisableEvent(D_801DFEC8);
    DisableEvent(D_801DFECC);
    DisableEvent(D_801DFED0);
    CloseEvent(D_801DFEC8);
    CloseEvent(D_801DFECC);
    CloseEvent(D_801DFED0);
}

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189928);

void func_80189970(s16 a) {
    func_8018AA00(a);
    if (D_801DFEDC != NULL) {
        D_801DFEDC();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_801899AC);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189AC0);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189C3C);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189DE8);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_80189F50);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A24C);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A3F8);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A5F0);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A7C0);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A8CC);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018A968);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018AA00);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018AABC);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018AB48);

INCLUDE_ASM("asm/nonmatchings/game/8018920C", func_8018ABE8);
