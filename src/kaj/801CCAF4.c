#include "common.h"
#include "game/types.h"

void *kaj_malloc(u32 size);
void kaj_abend(s32 code, char *msg, char *file, s32 line);
extern char kaj_ll_str_file[];
void free3(void *ptr);
extern KajSystem kaj_system;
u32 PadRead(s32 id);
void SsInit(void);
void SsSetTableSize(char *table, s16 s_max, s16 t_max);
void SsSetTickMode(s32 tick_mode);
void SsStart(void);
void SsSetMVol(s16 voll, s16 volr);
extern char kaj_sound_seq_table[];
extern s32 kaj_system_sep_volume[];
void SsEnd(void);
void SsQuit(void);
typedef struct TmdFileHeader {
    s32 id;
    s32 flags;
    s32 n_obj;
    s32 objects[1];
} TmdFileHeader;
void srand(u32 seed);
extern u32 kaj_timer_ticks[];
extern char kaj_ll_str_node_error[];
typedef struct KajErrorName {
    s32 code;
    char *name;
} KajErrorName;
extern KajErrorName kaj_error_names[];
extern char kaj_misc_str_null_file[];
extern char kaj_misc_str_undefined_error[];
extern char kaj_misc_str_error_code[];
extern char kaj_misc_str_file_label[];
extern char kaj_misc_str_line_label[];
extern char kaj_misc_str_message_label[];
extern char kaj_misc_str_bad_tmd[];
extern char kaj_misc_str_dash[];
extern char kaj_misc_str_fmt_s[];
extern char kaj_misc_str_newline[];
extern char kaj_misc_str_file[];
int printf(const char *fmt, ...);
void exit(s32 code);
void GsMapModelingData(u32 *p);
extern char kaj_misc_str_bad_line[];
typedef struct GsDobj2Handle {
    u32 attribute;
    void *coord2;
    void *tmd;
    u32 id;
} GsDobj2Handle;
void *memset(void *dst, s32 c, u32 n);
void GsLinkObject4(u32 *tmd, GsDobj2Handle *obj, s32 n);

void kaj_ll_create(LlList **list) {
    *list = kaj_malloc(0x10);
    if (*list == NULL) {
        kaj_abend(3, "Error Allocating LL Handle", kaj_ll_str_file, 0x15);
    }
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->cursor = NULL;
    (*list)->count = 0;
}

void kaj_ll_destroy(LlList *list) {
    LlNode *node;

    while (list->head != NULL) {
        node = list->head;
        list->head = node->next;
        if (node != NULL) {
            if (node->data != NULL) {
                free3(node->data);
            }
            free3(node);
        }
    }
    list->tail = NULL;
    list->cursor = NULL;
    list->count = 0;
    free3(list);
}

void kaj_ll_insert_before(LlList *list, void *data) {
    LlNode *node;

    node = kaj_malloc(0xC);
    if (node == NULL) {
        kaj_abend(3, kaj_ll_str_node_error, kaj_ll_str_file, 0x3C);
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        list->cursor = node;
        list->count = 1;
    } else {
        if (list->head == list->cursor) {
            node->next = list->cursor;
            list->head->prev = node;
            list->head = node;
            list->cursor = node;
            list->count++;
        } else {
            node->next = list->cursor;
            node->prev = list->cursor->prev;
            list->cursor->prev = node;
            list->cursor = node;
            node->prev->next = node;
            list->count++;
        }
    }
}

void kaj_ll_insert_after(LlList *list, void *data) {
    LlNode *node;

    node = kaj_malloc(0xC);
    if (node == NULL) {
        kaj_abend(3, kaj_ll_str_node_error, kaj_ll_str_file, 0x61);
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        list->cursor = node;
        list->count = 1;
    } else {
        if (list->tail == list->cursor) {
            node->prev = list->cursor;
            list->tail->next = node;
            list->tail = node;
            list->cursor = node;
            list->count++;
        } else {
            node->prev = list->cursor;
            node->next = list->cursor->next;
            list->cursor->next = node;
            list->cursor = node;
            node->next->prev = node;
            list->count++;
        }
    }
}

void kaj_ll_remove_to_prev(LlList *list) {
    LlNode *node;

    node = list->cursor;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
        list->cursor = NULL;
        list->count = 0;
    } else {
        if (list->head == node) {
            list->cursor = node->next;
            list->cursor->prev = NULL;
        } else {
            list->cursor = node->prev;
            list->cursor->next = node->next;
            if (node->next != NULL) {
                node->next->prev = node->prev;
            }
        }
        list->count--;
    }
    node->prev = NULL;
    node->next = NULL;
    node->data = NULL;
    if (list->head == node) {
        list->head = list->cursor;
    }
    if (list->tail == node) {
        list->tail = list->cursor;
    }
    free3(node);
}

void kaj_ll_remove_to_next(LlList *list) {
    LlNode *node;

    node = list->cursor;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
        list->cursor = NULL;
        list->count = 0;
    } else {
        if (list->tail == node) {
            list->cursor = node->prev;
            list->cursor->next = NULL;
        } else {
            list->cursor = node->next;
            list->cursor->prev = node->prev;
            if (node->prev != NULL) {
                node->prev->next = node->next;
            }
        }
        list->count--;
    }
    node->prev = NULL;
    node->next = NULL;
    node->data = NULL;
    if (list->head == node) {
        list->head = list->cursor;
    }
    if (list->tail == node) {
        list->tail = list->cursor;
    }
    free3(node);
}

s32 kaj_ll_at_head(LlList *list) {
    if (list == NULL) {
        return 0;
    }
    return list->head == list->cursor;
}

s32 kaj_ll_at_tail(LlList *list) {
    if (list == NULL) {
        return 0;
    }
    return list->tail == list->cursor;
}

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", kaj_ll_str_node_error);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", kaj_misc_str_null_file);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", kaj_misc_str_bad_line);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", kaj_misc_str_undefined_error);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", kaj_misc_str_error_code);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", kaj_misc_str_file_label);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", kaj_misc_str_line_label);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", kaj_misc_str_message_label);

INCLUDE_RODATA("asm/nonmatchings/kaj/801CCAF4", kaj_misc_str_bad_tmd);

void kaj_tmd_load(GsDobj2Handle **obj, u32 *tmd_file, void *coord) {
    u32 *tmd;

    if (tmd_file[0] != 0x41) {
        char *msg;
        char *file;
        char *s;
        s32 code;
        s32 i;

        msg = kaj_misc_str_bad_tmd;
        file = kaj_misc_str_file;
        code = 10;
        if (file == NULL) {
            printf(kaj_misc_str_null_file);
        }
        s = kaj_misc_str_undefined_error;
        for (i = 0; kaj_error_names[i].code != 15; i++) {
            if (kaj_error_names[i].code == code) {
                s = kaj_error_names[i].name;
                break;
            }
        }
        printf(kaj_misc_str_error_code, 10);
        if (*s != 0) {
            printf(kaj_misc_str_dash);
            printf(kaj_misc_str_fmt_s, s);
        }
        printf(kaj_misc_str_file_label);
        printf(file);
        printf(kaj_misc_str_line_label, 0x8A);
        if (msg != NULL) {
            printf(kaj_misc_str_message_label);
            printf(kaj_misc_str_fmt_s, msg);
        }
        printf(kaj_misc_str_newline);
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
            file = kaj_misc_str_file;
            code = 3;
            if (file == NULL) {
                printf(kaj_misc_str_null_file);
            }
            s = kaj_misc_str_undefined_error;
            for (i = 0; kaj_error_names[i].code != 15; i++) {
                if (kaj_error_names[i].code == code) {
                    s = kaj_error_names[i].name;
                    break;
                }
            }
            printf(kaj_misc_str_error_code, 3);
            if (*s != 0) {
                printf(kaj_misc_str_dash);
                printf(kaj_misc_str_fmt_s, s);
            }
            printf(kaj_misc_str_file_label);
            printf(file);
            printf(kaj_misc_str_line_label, 0x8F);
            if (msg != NULL) {
                printf(kaj_misc_str_message_label);
                printf(kaj_misc_str_fmt_s, msg);
            }
            printf(kaj_misc_str_newline);
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
        file = kaj_misc_str_file;
        code = 10;
        if (file == NULL) {
            printf(kaj_misc_str_null_file);
        }
        s = kaj_misc_str_undefined_error;
        for (i = 0; kaj_error_names[i].code != 15; i++) {
            if (kaj_error_names[i].code == code) {
                s = kaj_error_names[i].name;
                break;
            }
        }
        printf(kaj_misc_str_error_code, 10);
        if (*s != 0) {
            printf(kaj_misc_str_dash);
            printf(kaj_misc_str_fmt_s, s);
        }
        printf(kaj_misc_str_file_label);
        printf(file);
        printf(kaj_misc_str_line_label, 0x99);
        if (msg != NULL) {
            printf(kaj_misc_str_message_label);
            printf(kaj_misc_str_fmt_s, msg);
        }
        printf(kaj_misc_str_newline);
        exit(10);
    }
    GsLinkObject4(tmd, *obj, 0);
    (*obj)->coord2 = coord;
}

s32 kaj_tmd_map(u32 *tmd_file) {
    char *msg;
    char *file;
    char *s;
    s32 code;
    s32 i;

    if (tmd_file[0] != 0x41) {
        msg = kaj_misc_str_bad_tmd;
        file = kaj_misc_str_file;
        code = 10;
        if (file == NULL) {
            printf(kaj_misc_str_null_file);
        }
        s = kaj_misc_str_undefined_error;
        for (i = 0; kaj_error_names[i].code != 15; i++) {
            if (kaj_error_names[i].code == code) {
                s = kaj_error_names[i].name;
                break;
            }
        }
        printf(kaj_misc_str_error_code, 10);
        if (*s != 0) {
            printf(kaj_misc_str_dash);
            printf(kaj_misc_str_fmt_s, s);
        }
        printf(kaj_misc_str_file_label);
        printf(file);
        printf(kaj_misc_str_line_label, 0xA6);
        if (msg != NULL) {
            printf(kaj_misc_str_message_label);
            printf(kaj_misc_str_fmt_s, msg);
        }
        printf(kaj_misc_str_newline);
        exit(10);
    }
    GsMapModelingData(tmd_file + 1);
    return tmd_file[2];
}

void kaj_abend(s32 code, char *msg, char *file, s32 line) {
    char *s;
    s32 i;

    if (file == NULL) {
        printf(kaj_misc_str_null_file);
    }
    if (line < 0) {
        printf(kaj_misc_str_bad_line, line);
    }
    s = kaj_misc_str_undefined_error;
    for (i = 0; kaj_error_names[i].code != 15; i++) {
        if (kaj_error_names[i].code == code) {
            s = kaj_error_names[i].name;
            break;
        }
    }
    printf(kaj_misc_str_error_code, code);
    if (*s != 0) {
        printf(kaj_misc_str_dash);
        printf(kaj_misc_str_fmt_s, s);
    }
    printf(kaj_misc_str_file_label);
    printf(file);
    printf(kaj_misc_str_line_label, line);
    if (msg != NULL) {
        printf(kaj_misc_str_message_label);
        printf(kaj_misc_str_fmt_s, msg);
    }
    printf(kaj_misc_str_newline);
    exit(code);
}

void kaj_pad_reset(s16 enable) {
    kaj_system.pad_now = 0;
    kaj_system.pad_prev = 0;
    if (enable != 0) {
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
    kaj_system_sep_volume[0] = 0x7F;
}

void kaj_sound_quit(void) {
    SsEnd();
    SsQuit();
}

void kaj_tmd_unmap(TmdFileHeader *tmd, s32 base) {
    s32 *obj;
    s32 n;
    s32 i;

    if (tmd->id == 0x41 && (tmd->flags & 1)) {
        obj = tmd->objects;
        n = tmd->n_obj;
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
