#include "common.h"
#include "kaj/misc.h"
#include "kaj/kaj.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libetc.h"
#include "psyq/libgs.h"
#include "psyq/libsnd.h"

/*
 * TMD mapping and loading, the pad, sound init, the abend handler.
 *
 * File boundaries: likely (docs/layout.md): misc.c asserts; Sony code after.
 */

extern KajSystem kaj_system;
extern char kaj_sound_seq_table[];
extern s32 kaj_system_sep_volume[];
extern u32 kaj_timer_ticks[];
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
extern char kaj_misc_str_bad_line[];

INCLUDE_RODATA("asm/nonmatchings/kaj/misc", kaj_misc_str_null_file);

INCLUDE_RODATA("asm/nonmatchings/kaj/misc", kaj_misc_str_bad_line);

INCLUDE_RODATA("asm/nonmatchings/kaj/misc", kaj_misc_str_undefined_error);

INCLUDE_RODATA("asm/nonmatchings/kaj/misc", kaj_misc_str_error_code);

INCLUDE_RODATA("asm/nonmatchings/kaj/misc", kaj_misc_str_file_label);

INCLUDE_RODATA("asm/nonmatchings/kaj/misc", kaj_misc_str_line_label);

INCLUDE_RODATA("asm/nonmatchings/kaj/misc", kaj_misc_str_message_label);

INCLUDE_RODATA("asm/nonmatchings/kaj/misc", kaj_misc_str_bad_tmd);

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
