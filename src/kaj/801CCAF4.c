#include "common.h"
#include "game/types.h"

typedef struct Unk_801CCAF4 {
    LlNode *unk0;
    LlNode *unk4;
    LlNode *unk8;
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

void kaj_ll_create(Unk_801CCAF4 **list) {
    *list = kaj_malloc(0x10);
    if (*list == NULL) {
        kaj_abend(3, "Error Allocating LL Handle", D_801DFDC4, 0x15);
    }
    (*list)->unk0 = NULL;
    (*list)->unk4 = NULL;
    (*list)->unk8 = NULL;
    (*list)->unkC = 0;
}

void kaj_ll_destroy(Unk_801CCAF4 *list) {
    LlNode *node;

    while (list->unk0 != NULL) {
        node = list->unk0;
        list->unk0 = node->next;
        if (node != NULL) {
            if (node->data != NULL) {
                free3(node->data);
            }
            free3(node);
        }
    }
    list->unk4 = NULL;
    list->unk8 = NULL;
    list->unkC = 0;
    free3(list);
}

void kaj_ll_insert_before(Unk_801CCAF4 *list, void *data) {
    LlNode *node;

    node = kaj_malloc(0xC);
    if (node == NULL) {
        kaj_abend(3, D_80172BB4, D_801DFDC4, 0x3C);
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    if (list->unk0 == NULL) {
        list->unk0 = node;
        list->unk4 = node;
        list->unk8 = node;
        list->unkC = 1;
    } else {
        if (list->unk0 == list->unk8) {
            node->next = list->unk8;
            list->unk0->prev = node;
            list->unk0 = node;
            list->unk8 = node;
            list->unkC++;
        } else {
            node->next = list->unk8;
            node->prev = list->unk8->prev;
            list->unk8->prev = node;
            list->unk8 = node;
            node->prev->next = node;
            list->unkC++;
        }
    }
}

void kaj_ll_insert_after(Unk_801CCAF4 *list, void *data) {
    LlNode *node;

    node = kaj_malloc(0xC);
    if (node == NULL) {
        kaj_abend(3, D_80172BB4, D_801DFDC4, 0x61);
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    if (list->unk0 == NULL) {
        list->unk0 = node;
        list->unk4 = node;
        list->unk8 = node;
        list->unkC = 1;
    } else {
        if (list->unk4 == list->unk8) {
            node->prev = list->unk8;
            list->unk4->next = node;
            list->unk4 = node;
            list->unk8 = node;
            list->unkC++;
        } else {
            node->prev = list->unk8;
            node->next = list->unk8->next;
            list->unk8->next = node;
            list->unk8 = node;
            node->next->prev = node;
            list->unkC++;
        }
    }
}

void kaj_ll_remove_to_prev(Unk_801CCAF4 *list) {
    LlNode *node;

    node = list->unk8;
    if (list->unk0 == list->unk4) {
        list->unk0 = NULL;
        list->unk4 = NULL;
        list->unk8 = NULL;
        list->unkC = 0;
    } else {
        if (list->unk0 == node) {
            list->unk8 = node->next;
            list->unk8->prev = NULL;
        } else {
            list->unk8 = node->prev;
            list->unk8->next = node->next;
            if (node->next != NULL) {
                node->next->prev = node->prev;
            }
        }
        list->unkC--;
    }
    node->prev = NULL;
    node->next = NULL;
    node->data = NULL;
    if (list->unk0 == node) {
        list->unk0 = list->unk8;
    }
    if (list->unk4 == node) {
        list->unk4 = list->unk8;
    }
    free3(node);
}

void kaj_ll_remove_to_next(Unk_801CCAF4 *list) {
    LlNode *node;

    node = list->unk8;
    if (list->unk0 == list->unk4) {
        list->unk0 = NULL;
        list->unk4 = NULL;
        list->unk8 = NULL;
        list->unkC = 0;
    } else {
        if (list->unk4 == node) {
            list->unk8 = node->prev;
            list->unk8->next = NULL;
        } else {
            list->unk8 = node->next;
            list->unk8->prev = node->prev;
            if (node->prev != NULL) {
                node->prev->next = node->next;
            }
        }
        list->unkC--;
    }
    node->prev = NULL;
    node->next = NULL;
    node->data = NULL;
    if (list->unk0 == node) {
        list->unk0 = list->unk8;
    }
    if (list->unk4 == node) {
        list->unk4 = list->unk8;
    }
    free3(node);
}

s32 kaj_ll_at_head(Unk_801CCAF4 *list) {
    if (list == NULL) {
        return 0;
    }
    return list->unk0 == list->unk8;
}

s32 kaj_ll_at_tail(Unk_801CCAF4 *list) {
    if (list == NULL) {
        return 0;
    }
    return list->unk4 == list->unk8;
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

void kaj_tmd_load(Unk_801CD028 **obj, u32 *tmd_file, void *coord) {
    u32 *tmd;

    if (tmd_file[0] != 0x41) {
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
    if (*obj == NULL) {
        *obj = kaj_malloc(0x10);
        if (*obj == NULL) {
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
        memset(*obj, 0, 0x10);
    }
    GsMapModelingData(tmd_file + 1);
    tmd = tmd_file + 3;
    if (tmd_file[2] != 1) {
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
    GsLinkObject4(tmd, *obj, 0);
    (*obj)->unk4 = coord;
}

s32 kaj_tmd_map(u32 *tmd_file) {
    char *msg;
    char *file;
    char *s;
    s32 code;
    s32 i;

    if (tmd_file[0] != 0x41) {
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
    GsMapModelingData(tmd_file + 1);
    return tmd_file[2];
}

void kaj_abend(s32 code, char *msg, char *file, s32 line) {
    char *s;
    s32 i;

    if (file == NULL) {
        printf(D_80172CA8);
    }
    if (line < 0) {
        printf(D_80172CC8, line);
    }
    s = D_80172CF0;
    for (i = 0; kaj_error_names[i].unk0 != 15; i++) {
        if (kaj_error_names[i].unk0 == code) {
            s = kaj_error_names[i].unk4;
            break;
        }
    }
    printf(D_80172D00, code);
    if (*s != 0) {
        printf(D_801DFDD0);
        printf(D_801DFDD4, s);
    }
    printf(D_80172D10);
    printf(file);
    printf(D_80172D1C, line);
    if (msg != NULL) {
        printf(D_80172D28);
        printf(D_801DFDD4, msg);
    }
    printf(D_801DFDD8);
    exit(code);
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
    s32 buttons;

    if (kaj_system.pad_mode != 1) {
        return 0;
    }
    buttons = PadRead(1);
    kaj_system.pad_prev = kaj_system.pad_now;
    kaj_system.pad_now = buttons;
    return buttons;
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

void kaj_tmd_unmap(Unk_801CD78C *tmd, s32 base) {
    s32 *obj;
    s32 n;
    s32 i;

    if (tmd->unk0 == 0x41 && (tmd->unk4 & 1)) {
        obj = tmd->unkC;
        n = tmd->unk8;
        for (i = 0; i < n; i++) {
            obj[0] -= base * 4;
            obj[2] -= base * 4;
            obj[4] -= base * 4;
            obj += 7;
        }
    }
}

void kaj_srand_ticks(void) {
    srand(((kaj_timer_ticks[0] & 0xF0F0F0F0) >> 4) | ((kaj_timer_ticks[0] & 0x0F0F0F0F) << 4));
}
