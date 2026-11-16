#include "common.h"
#include "game/types.h"

typedef struct Unk_801CCAF4 {
    Unk_801CCB70 *unk0;
    Unk_801CCB70 *unk4;
    Unk_801CCB70 *unk8;
    s32 unkC;
} Unk_801CCAF4;
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char D_801DFDC4[];
void free3(void *ptr);
extern KajSystem kaj_system;
u32 PadRead(s32 id);
void SsInit(void);
void SsSetTableSize(char *table, s16 s_max, s16 t_max);
void SsSetTickMode(s32 tick_mode);
void SsStart(void);
void SsSetMVol(s16 voll, s16 volr);
extern char kaj_sound_seq_table[];
extern s32 D_801E6DB8[];
void SsEnd(void);
void SsQuit(void);
typedef struct Unk_801CD78C {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC[1];
} Unk_801CD78C;
void srand(u32 seed);
extern u32 kaj_timer_ticks[];
extern char D_80172BB4[];
typedef struct Unk_801DFAF8 {
    s32 unk0;
    char *unk4;
} Unk_801DFAF8;
extern Unk_801DFAF8 kaj_error_names[];
extern char D_80172CA8[];
extern char D_80172CF0[];
extern char D_80172D00[];
extern char D_80172D10[];
extern char D_80172D1C[];
extern char D_80172D28[];
extern char D_80172D34[];
extern char D_801DFDD0[];
extern char D_801DFDD4[];
extern char D_801DFDD8[];
extern char D_801DFDDC[];
int printf(const char *fmt, ...);
void exit(s32 code);
void GsMapModelingData(u32 *p);
extern char D_80172CC8[];
typedef struct Unk_801CD028 {
    u32 unk0;
    void *unk4;
    void *unk8;
    u32 unkC;
} Unk_801CD028;
void *memset(void *dst, s32 c, u32 n);
void GsLinkObject4(u32 *tmd, Unk_801CD028 *obj, s32 n);

void kaj_ll_create(Unk_801CCAF4 **arg0) {
    *arg0 = kaj_malloc(0x10);
    if (*arg0 == NULL) {
        kaj_abend(3, "Error Allocating LL Handle", D_801DFDC4, 0x15);
    }
    (*arg0)->unk0 = NULL;
    (*arg0)->unk4 = NULL;
    (*arg0)->unk8 = NULL;
    (*arg0)->unkC = 0;
}

void kaj_ll_destroy(Unk_801CCAF4 *arg0) {
    Unk_801CCB70 *node;

    while (arg0->unk0 != NULL) {
        node = arg0->unk0;
        arg0->unk0 = node->unk4;
        if (node != NULL) {
            if (node->unk8 != NULL) {
                free3(node->unk8);
            }
            free3(node);
        }
    }
    arg0->unk4 = NULL;
    arg0->unk8 = NULL;
    arg0->unkC = 0;
    free3(arg0);
}

void kaj_ll_insert_before(Unk_801CCAF4 *arg0, void *arg1) {
    Unk_801CCB70 *node;

    node = kaj_malloc(0xC);
    if (node == NULL) {
        kaj_abend(3, D_80172BB4, D_801DFDC4, 0x3C);
    }
    node->unk8 = arg1;
    node->unk0 = NULL;
    node->unk4 = NULL;
    if (arg0->unk0 == NULL) {
        arg0->unk0 = node;
        arg0->unk4 = node;
        arg0->unk8 = node;
        arg0->unkC = 1;
    } else {
        if (arg0->unk0 == arg0->unk8) {
            node->unk4 = arg0->unk8;
            arg0->unk0->unk0 = node;
            arg0->unk0 = node;
            arg0->unk8 = node;
            arg0->unkC++;
        } else {
            node->unk4 = arg0->unk8;
            node->unk0 = arg0->unk8->unk0;
            arg0->unk8->unk0 = node;
            arg0->unk8 = node;
            node->unk0->unk4 = node;
            arg0->unkC++;
        }
    }
}

void kaj_ll_insert_after(Unk_801CCAF4 *arg0, void *arg1) {
    Unk_801CCB70 *node;

    node = kaj_malloc(0xC);
    if (node == NULL) {
        kaj_abend(3, D_80172BB4, D_801DFDC4, 0x61);
    }
    node->unk8 = arg1;
    node->unk0 = NULL;
    node->unk4 = NULL;
    if (arg0->unk0 == NULL) {
        arg0->unk0 = node;
        arg0->unk4 = node;
        arg0->unk8 = node;
        arg0->unkC = 1;
    } else {
        if (arg0->unk4 == arg0->unk8) {
            node->unk0 = arg0->unk8;
            arg0->unk4->unk4 = node;
            arg0->unk4 = node;
            arg0->unk8 = node;
            arg0->unkC++;
        } else {
            node->unk0 = arg0->unk8;
            node->unk4 = arg0->unk8->unk4;
            arg0->unk8->unk4 = node;
            arg0->unk8 = node;
            node->unk4->unk0 = node;
            arg0->unkC++;
        }
    }
}

void kaj_ll_remove_to_prev(Unk_801CCAF4 *arg0) {
    Unk_801CCB70 *node;

    node = arg0->unk8;
    if (arg0->unk0 == arg0->unk4) {
        arg0->unk0 = NULL;
        arg0->unk4 = NULL;
        arg0->unk8 = NULL;
        arg0->unkC = 0;
    } else {
        if (arg0->unk0 == node) {
            arg0->unk8 = node->unk4;
            arg0->unk8->unk0 = NULL;
        } else {
            arg0->unk8 = node->unk0;
            arg0->unk8->unk4 = node->unk4;
            if (node->unk4 != NULL) {
                node->unk4->unk0 = node->unk0;
            }
        }
        arg0->unkC--;
    }
    node->unk0 = NULL;
    node->unk4 = NULL;
    node->unk8 = NULL;
    if (arg0->unk0 == node) {
        arg0->unk0 = arg0->unk8;
    }
    if (arg0->unk4 == node) {
        arg0->unk4 = arg0->unk8;
    }
    free3(node);
}

void kaj_ll_remove_to_next(Unk_801CCAF4 *arg0) {
    Unk_801CCB70 *node;

    node = arg0->unk8;
    if (arg0->unk0 == arg0->unk4) {
        arg0->unk0 = NULL;
        arg0->unk4 = NULL;
        arg0->unk8 = NULL;
        arg0->unkC = 0;
    } else {
        if (arg0->unk4 == node) {
            arg0->unk8 = node->unk0;
            arg0->unk8->unk4 = NULL;
        } else {
            arg0->unk8 = node->unk4;
            arg0->unk8->unk0 = node->unk0;
            if (node->unk0 != NULL) {
                node->unk0->unk4 = node->unk4;
            }
        }
        arg0->unkC--;
    }
    node->unk0 = NULL;
    node->unk4 = NULL;
    node->unk8 = NULL;
    if (arg0->unk0 == node) {
        arg0->unk0 = arg0->unk8;
    }
    if (arg0->unk4 == node) {
        arg0->unk4 = arg0->unk8;
    }
    free3(node);
}

s32 kaj_ll_at_head(Unk_801CCAF4 *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return arg0->unk0 == arg0->unk8;
}

s32 kaj_ll_at_tail(Unk_801CCAF4 *arg0) {
    if (arg0 == NULL) {
        return 0;
    }
    return arg0->unk4 == arg0->unk8;
}

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", D_80172BB4);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", D_80172CA8);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", D_80172CC8);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", D_80172CF0);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", D_80172D00);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", D_80172D10);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", D_80172D1C);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", D_80172D28);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", D_80172D34);

void kaj_tmd_load(Unk_801CD028 **arg0, u32 *arg1, void *arg2) {
    u32 *tmd;

    if (arg1[0] != 0x41) {
        char *msg;
        char *file;
        char *s;
        s32 code;
        s32 i;

        msg = D_80172D34;
        file = D_801DFDDC;
        code = 10;
        if (file == NULL) {
            printf(D_80172CA8);
        }
        s = D_80172CF0;
        for (i = 0; kaj_error_names[i].unk0 != 15; i++) {
            if (kaj_error_names[i].unk0 == code) {
                s = kaj_error_names[i].unk4;
                break;
            }
        }
        printf(D_80172D00, 10);
        if (*s != 0) {
            printf(D_801DFDD0);
            printf(D_801DFDD4, s);
        }
        printf(D_80172D10);
        printf(file);
        printf(D_80172D1C, 0x8A);
        if (msg != NULL) {
            printf(D_80172D28);
            printf(D_801DFDD4, msg);
        }
        printf(D_801DFDD8);
        exit(10);
    }
    if (*arg0 == NULL) {
        *arg0 = kaj_malloc(0x10);
        if (*arg0 == NULL) {
            char *msg;
            char *file;
            char *s;
            s32 code;
            s32 i;

            msg = "Error Allocating GsDOBJ2 Handle";
            file = D_801DFDDC;
            code = 3;
            if (file == NULL) {
                printf(D_80172CA8);
            }
            s = D_80172CF0;
            for (i = 0; kaj_error_names[i].unk0 != 15; i++) {
                if (kaj_error_names[i].unk0 == code) {
                    s = kaj_error_names[i].unk4;
                    break;
                }
            }
            printf(D_80172D00, 3);
            if (*s != 0) {
                printf(D_801DFDD0);
                printf(D_801DFDD4, s);
            }
            printf(D_80172D10);
            printf(file);
            printf(D_80172D1C, 0x8F);
            if (msg != NULL) {
                printf(D_80172D28);
                printf(D_801DFDD4, msg);
            }
            printf(D_801DFDD8);
            exit(3);
        }
    } else {
        memset(*arg0, 0, 0x10);
    }
    GsMapModelingData(arg1 + 1);
    tmd = arg1 + 3;
    if (arg1[2] != 1) {
        char *msg;
        char *file;
        char *s;
        s32 code;
        s32 i;

        msg = "Too Many Objects in TMD";
        file = D_801DFDDC;
        code = 10;
        if (file == NULL) {
            printf(D_80172CA8);
        }
        s = D_80172CF0;
        for (i = 0; kaj_error_names[i].unk0 != 15; i++) {
            if (kaj_error_names[i].unk0 == code) {
                s = kaj_error_names[i].unk4;
                break;
            }
        }
        printf(D_80172D00, 10);
        if (*s != 0) {
            printf(D_801DFDD0);
            printf(D_801DFDD4, s);
        }
        printf(D_80172D10);
        printf(file);
        printf(D_80172D1C, 0x99);
        if (msg != NULL) {
            printf(D_80172D28);
            printf(D_801DFDD4, msg);
        }
        printf(D_801DFDD8);
        exit(10);
    }
    GsLinkObject4(tmd, *arg0, 0);
    (*arg0)->unk4 = arg2;
}

s32 kaj_tmd_map(u32 *arg0) {
    char *msg;
    char *file;
    char *s;
    s32 code;
    s32 i;

    if (arg0[0] != 0x41) {
        msg = D_80172D34;
        file = D_801DFDDC;
        code = 10;
        if (file == NULL) {
            printf(D_80172CA8);
        }
        s = D_80172CF0;
        for (i = 0; kaj_error_names[i].unk0 != 15; i++) {
            if (kaj_error_names[i].unk0 == code) {
                s = kaj_error_names[i].unk4;
                break;
            }
        }
        printf(D_80172D00, 10);
        if (*s != 0) {
            printf(D_801DFDD0);
            printf(D_801DFDD4, s);
        }
        printf(D_80172D10);
        printf(file);
        printf(D_80172D1C, 0xA6);
        if (msg != NULL) {
            printf(D_80172D28);
            printf(D_801DFDD4, msg);
        }
        printf(D_801DFDD8);
        exit(10);
    }
    GsMapModelingData(arg0 + 1);
    return arg0[2];
}

void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3) {
    char *s;
    s32 i;

    if (arg2 == NULL) {
        printf(D_80172CA8);
    }
    if (arg3 < 0) {
        printf(D_80172CC8, arg3);
    }
    s = D_80172CF0;
    for (i = 0; kaj_error_names[i].unk0 != 15; i++) {
        if (kaj_error_names[i].unk0 == arg0) {
            s = kaj_error_names[i].unk4;
            break;
        }
    }
    printf(D_80172D00, arg0);
    if (*s != 0) {
        printf(D_801DFDD0);
        printf(D_801DFDD4, s);
    }
    printf(D_80172D10);
    printf(arg2);
    printf(D_80172D1C, arg3);
    if (arg1 != NULL) {
        printf(D_80172D28);
        printf(D_801DFDD4, arg1);
    }
    printf(D_801DFDD8);
    exit(arg0);
}

void kaj_pad_reset(s16 arg0) {
    kaj_system.pad_now = 0;
    kaj_system.pad_prev = 0;
    if (arg0 != 0) {
        kaj_system.pad_mode = 2;
    } else {
        kaj_system.pad_mode = 0;
    }
}

s32 kaj_pad_read(void) {
    s32 v;

    if (kaj_system.pad_mode != 1) {
        return 0;
    }
    v = PadRead(1);
    kaj_system.pad_prev = kaj_system.pad_now;
    kaj_system.pad_now = v;
    return v;
}

void kaj_sound_init(void) {
    SsInit();
    SsSetTableSize(kaj_sound_seq_table, 1, 3);
    SsSetTickMode(1);
    SsStart();
    SsSetMVol(0x7F, 0x7F);
    D_801E6DB8[0] = 0x7F;
}

void kaj_sound_quit(void) {
    SsEnd();
    SsQuit();
}

void kaj_tmd_unmap(Unk_801CD78C *arg0, s32 arg1) {
    s32 *p;
    s32 n;
    s32 i;

    if (arg0->unk0 == 0x41 && (arg0->unk4 & 1)) {
        p = arg0->unkC;
        n = arg0->unk8;
        for (i = 0; i < n; i++) {
            p[0] -= arg1 * 4;
            p[2] -= arg1 * 4;
            p[4] -= arg1 * 4;
            p += 7;
        }
    }
}

void kaj_srand_ticks(void) {
    srand(((kaj_timer_ticks[0] & 0xF0F0F0F0) >> 4) | ((kaj_timer_ticks[0] & 0x0F0F0F0F) << 4));
}
