#include "common.h"

void *malloc3(u32 size);
void *memset(void *dst, s32 c, u32 n);

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

INCLUDE_ASM("asm/nonmatchings/kaj/801CC898", func_801CC8F0);
