#include "common.h"
#include "game/dialog.h"
#include "game/action.h"
#include "game/actor.h"
#include "game/card.h"
#include "game/effect.h"
#include "game/event.h"
#include "game/mail.h"
#include "game/main.h"
#include "game/object.h"
#include "game/roadmap.h"
#include "game/sound.h"
#include "game/sprite.h"
#include "kaj/event.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "kaj/timer.h"
#include "kaj/tss.h"
#include "psyq/libc.h"
#include "psyq/libgpu.h"

/*
 * The pause menu pages and the text window: typing, narration, numbers.
 *
 * File boundaries: guess (docs/layout.md): no assert: a string after card.c's jump tables; its start is a guess.
 */

typedef struct PauseMenu {
    s16 item;
    s16 page;
    s16 animating;
    s16 row;
    struct MenuSprite *item_sprite;
    struct MenuSprite *label_sprite;
} PauseMenu;

extern GameVars_u8017EBF8 action_vars;
TextCmd **dialog_cmd;
s16 dialog_window_sprite;
s16 dialog_wait;
extern s32 kaj_system_vsync_delta[];
extern s32 action_vars_narration_task[];
extern Player *player_status_player[];
typedef struct MenuSprite {
    u8 pad0[0x4];
    s16 visible;
    u8 pad6[0x6];
    s16 y;
    u8 padE[0x4];
    s16 cell_h;
    u8 pad14[0x4];
    s16 cell_col;
    s16 cell_row;
    Rect *tim;
} MenuSprite;
static s16 dialog_draw_next(s32 str, s32 prompt);
s16 dialog_row;
s16 dialog_narration_page_full;
s16 dialog_pos;
s16 dialog_cue_fade_done;
s16 dialog_cue_bgm_done;
extern EventState event_state;
extern char dialog_str_unknown[];
s16 dialog_col;
s16 dialog_color;
s16 dialog_len;
static void dialog_menu_list_page(PauseMenu *menu, s32 action, s32 up);
static void dialog_menu_status_page(PauseMenu *menu, s32 flip);
static void dialog_menu_options_page(PauseMenu *menu, s32 action, s16 decrease);
static void dialog_narration_step(TssSlot *task);
static void dialog_narration_end(void);
s32 main_take_scene_change(void);
extern s16 dialog_menu_list_vars[];
MenuSprite *dialog_menu_anim_sprite;
extern KajSystem kaj_system;
static void dialog_menu_confirm(PauseMenu *menu);
static void dialog_menu_back(PauseMenu *menu);
static void dialog_menu_move_cursor(PauseMenu *menu, s16 up);
static void dialog_menu_handle_input(PauseMenu *menu);
static void dialog_menu_animate(PauseMenu *menu);
static void dialog_draw_string(s32 str, s16 max_rows);
extern s32 dialog_line_y[];
static void dialog_draw_line(char *str, s16 line_idx);
extern PlayerStatus player_status;
void sprite_copy_cell(s32 src_id, s32 col, s32 row, s32 dst_id, s32 dst_x, s32 dst_y);
s32 dialog_menu_cycle_pos_a;
s32 dialog_menu_cycle_pos_b;
s32 dialog_menu_cycle_pos_c;
s16 dialog_menu_cycle_dir_a;
s16 dialog_menu_cycle_dir_b;
s16 dialog_menu_cycle_dir_c;
static void dialog_format_number(u8 *out, u16 n);
extern char *dialog_sex_names[];
extern char *dialog_blood_types[];
void dialog_show_timed(u16 mode, s16 big, s32 str, s16 se, s32 seconds);
static void dialog_start_typing(s32 str);
extern s16 actor_death_set_1000;

static void dialog_menu_list_page(PauseMenu *menu, s32 action, s32 up) {
    GameVars_u8017EBF8 *vars = &action_vars;
    Rect rect;

    switch ((s16)action) {
    case 0:
        sprite_set_visible(0x237, 1);
        sprite_set_visible(0x238, 1);
        break;
    case 1:
        sound_se_play(0x11);
        sprite_set_visible(0x239, 1);
        rect.x = 0x3C0;
        rect.y = menu->row * 0x40;
        rect.w = 0x2C;
        rect.h = 0x40;
        MoveImage2(&rect, 0x300, 0x100);
        sprite_fill_clut(0x239, 2, 5, 0x421);
        switch (vars->vars[dialog_menu_list_vars[menu->row]]) {
        case 0:
            break;
        case 10:
            sprite_set_clut_entry(0x239, 2, 0xB4);
            sprite_set_clut_entry(0x239, 3, 0x28A);
            break;
        case 1000:
            sprite_set_clut_entry(0x239, 2, 0xB4);
            sprite_set_clut_entry(0x239, 3, 0x28A);
            sprite_set_clut_entry(0x239, 4, 0x2A85);
            break;
        case 2000:
            sprite_set_clut_entry(0x239, 2, 0xB4);
            sprite_set_clut_entry(0x239, 3, 0x28A);
            sprite_set_clut_entry(0x239, 4, 0x2A85);
            sprite_set_clut_entry(0x239, 5, 0x3CAF);
            break;
        default:
            sprite_set_clut_entry(0x239, 2, 0xB4);
            break;
        }
        return;
    case 2:
        sound_se_play(0xF);
        if ((s16)up != 0) {
            if (--menu->row < 0) {
                menu->row = 7;
            }
        } else {
            if (++menu->row >= 8) {
                menu->row = 0;
            }
        }
        break;
    }
    sprite_set_cell(0x238, 0, menu->row);
    sprite_fill_clut(0x237, 1, 8, 0x10C);
    sprite_set_clut_entry(0x237, menu->row + 1, 0x23F);
}

static void dialog_menu_status_page(PauseMenu *menu, s32 flip) {
    PlayerStatus *status = &player_status;
    GameVars_u8017EBF8 *vars = &action_vars;
    Inventory *inventory = status->inventory;
    WeaponRecord *weapon;
    s32 len;
    s32 j;
    s32 i;
    s32 id;
    s32 col;
    s32 k;
    s32 m;
    s32 len2;

    if ((s16)flip != 0) {
        sound_se_play(0x11);
        menu->row = 1 - menu->row;
        if (menu->row != 0) {
            sprite_set_visible(0x23A, 0);
            sprite_set_visible(0x23B, 1);
        } else {
            sprite_set_visible(0x23A, 1);
            sprite_set_visible(0x23B, 0);
        }
        return;
    }
    sprite_set_visible(0x23A, 1);
    sprite_set_visible(0x23B, 0);
    sprite_fill_clut(0x23A, 0x10, 0xEF, 0x421);
    sprite_fill_clut(0x23B, 0x10, 0xDF, 0x421);
    sprite_fill_clut(0x23B, 0x60, 0x64, 0x14C6);
    sprite_fill_clut(0x23B, 0x70, 0x74, 0x14C6);
    col = 0x3D40;
    len = status->exp / 6329;
    if (len == 0 && status->exp != 0) {
        len = 1;
    }
    if (len > 32) {
        len = 32;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x10, (u16)col);
        }
    }
    len = (status->level << 5) / 50 + 1;
    if (len > 32) {
        len = 32;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x30, (u16)col);
        }
    }
    len = (status->exp << 4) / status->next_exp;
    if (len == 0 && status->exp != 0) {
        len = 1;
    }
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x50, (u16)col);
        }
    }
    col = 0xB4;
    len = status->humans_killed > 16 ? 16 : status->humans_killed;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x60, (u16)col);
        }
    }
    col = 0x3D40;
    len = status->hours_awake > 32 ? 32 : status->hours_awake;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x70, (u16)col);
        }
    }
    len = (status->defense_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x90, (u16)col);
        }
    }
    len = (vars->vars[0x5A] + 15) / 16;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0xA0, (u16)col);
        }
    }
    len = (vars->vars[0x5D] + 15) / 16;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0xB0, (u16)col);
        }
    }
    len = (vars->vars[0x5B] + 15) / 16;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0xC0, (u16)col);
        }
    }
    len = (vars->vars[0x5C] + 15) / 16;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0xD0, (u16)col);
        }
    }
    len2 = (vars->vars[0x5E] + 15) / 16;
    if (len2 != 0) {
        for (j = 0; j < len2; j++) {
            sprite_set_clut_entry(0x23A, j + 0xE0, (u16)col);
        }
    }
    col = 0x3D40;
    len = (status->weapon0_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23B, j + 0x10, (u16)col);
        }
    }
    len = (status->weapon1_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23B, j + 0x20, (u16)col);
        }
    }
    len = (status->weapon2_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23B, j + 0x30, (u16)col);
        }
    }
    len = (status->weapon3_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23B, j + 0x40, (u16)col);
        }
    }
    len = (status->weapon4_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23B, j + 0x50, (u16)col);
        }
    }
    for (i = 0; i < 2; i++) {
        id = inventory->weapon_ids[i];
        if (id >= 0) {
            weapon = effect_weapon_find(id);
            if (weapon != NULL) {
                sprite_set_clut_entry(0x23B, (i * 16 + 0x60) + weapon->weapon_class, 0x154);
                len = ((s16)weapon->req_level << 5) / 50 + 1; /* lh: this unit reads req_level signed */
                if (len > 32) {
                    len = 32;
                }
                k = i * 32 + 0x80;
                if (len != 0) {
                    for (j = 0; j < len; j++) {
                        sprite_set_clut_entry(0x23B, k + j, (u16)col);
                    }
                }
                len = (weapon->accuracy << 12) / 25600;
                m = i * 16 + 0xC0;
                if (len != 0) {
                    for (j = 0; j < len; j++) {
                        sprite_set_clut_entry(0x23B, m + j, (u16)col);
                    }
                }
                sprite_copy_cell(0x23C, (u16)(id / 9), (u16)(id % 9), 0x23B, 0x21, (u16)(i * 42 + 0x53));
            }
        }
    }
}

static void dialog_menu_options_page(PauseMenu *menu, s32 action, s16 decrease) {
    GameVars_u8017EBF8 *vars = &action_vars;
    s16 play_se = 1;

    switch (action) {
    case 0:
        play_se = 0;
        sprite_set_visible(0x23D, 1);
        break;
    case 1:
        menu->row = 1 - menu->row;
        break;
    case 2:
        if (menu->row != 0) {
            if (decrease != 0) {
                vars->car_speed_setting--;
                if (vars->car_speed_setting < 0) {
                    vars->car_speed_setting = 2;
                }
            } else {
                vars->car_speed_setting++;
                if (vars->car_speed_setting >= 3) {
                    vars->car_speed_setting = 0;
                }
            }
        } else {
            if (decrease != 0) {
                vars->text_speed_setting--;
                if (vars->text_speed_setting < 0) {
                    vars->text_speed_setting = 2;
                }
            } else {
                vars->text_speed_setting++;
                if (vars->text_speed_setting >= 3) {
                    vars->text_speed_setting = 0;
                }
            }
        }
        break;
    }
    sprite_fill_clut(0x23D, 7, 8, 0x4250);
    sprite_set_clut_entry(0x23D, menu->row + 7, 0x5140);
    sprite_fill_clut(0x23D, 9, 0xE, 0x421);
    sprite_set_clut_entry(0x23D, vars->text_speed_setting + 9, 0x154);
    sprite_set_clut_entry(0x23D, vars->car_speed_setting + 0xC, 0x154);
    if (play_se != 0) {
        sound_se_play(0xF);
    }
}

static void dialog_menu_move_cursor(PauseMenu *menu, s16 up) {
    GameVars_u8017EBF8 *vars = &action_vars;
    MenuSprite *cursor;
    MenuSprite *label;
    MenuSprite *item_sprite;

    switch (menu->page) {
    case 0:
        if (menu->animating != 0) {
            break;
        }
        if (up != 0) {
            if (--menu->item < 0) {
                menu->item = 4;
            }
        } else {
            if (++menu->item >= 5) {
                menu->item = 0;
            }
        }
        cursor = sprite_find(0x20B);
        label = sprite_find(0x211);
        if (cursor != 0) {
            cursor->y = (menu->item << 4) + 0x48;
        }
        if (label != 0 && label->visible != 0) {
            label->visible = 0;
        }
        if (dialog_menu_anim_sprite != 0) {
            dialog_menu_anim_sprite->visible = 0;
        }
        if (menu->item == 0) {
            menu->item_sprite = 0;
            menu->label_sprite = 0;
            dialog_menu_anim_sprite = 0;
        } else {
            menu->label_sprite = label;
            item_sprite = sprite_find(menu->item + 0x20C);
            if (item_sprite == 0) {
                menu->item_sprite = 0;
                if (label != 0) {
                    if (label->visible == 0) {
                        label->visible = 1;
                    }
                    label->cell_col = 0;
                    label->cell_row = menu->item - 1;
                }
            } else {
                menu->item_sprite = item_sprite;
                item_sprite->cell_col = 0;
                item_sprite->cell_row = 0;
                if (item_sprite->visible == 0) {
                    item_sprite->visible = 1;
                }
                menu->animating = 1;
                dialog_menu_anim_sprite = item_sprite;
            }
        }
        sound_se_play(0xF);
        break;
    case 1:
        if (menu->item == 1) {
            dialog_menu_list_page(menu, 2, up);
        } else if (menu->item == 2 && vars->mail_count != 0) {
            menu->row = mail_list_move(up, menu->row);
        } else if (menu->item == 3) {
            dialog_menu_options_page(menu, 1, up);
        }
        break;
    }
}

static void dialog_menu_confirm(PauseMenu *menu) {
    GameVars_u8017EBF8 *vars = &action_vars;

    switch (menu->page) {
    case 0:
        menu->row = 0;
        menu->page = 1;
        sound_se_play(0x11);
        if (menu->item == 1) {
            object_load_res(0xD, -1);
            dialog_menu_list_page(menu, 0, 0);
        } else if (menu->item == 2) {
            if (vars->mail_count != 0) {
                object_load_res(8, -1);
                mail_list_open();
            }
            sprite_set_visible(0x20A, 1);
            sprite_set_visible(0x212, 1);
            sprite_set_visible(0x20C, 1);
        } else if (menu->item == 3) {
            dialog_menu_options_page(menu, 0, 0);
        } else if (menu->item == 4) {
            object_load_res(0xE, -1);
            dialog_menu_status_page(menu, 0);
        }
        break;
    case 1:
        if (menu->item == 1) {
            dialog_menu_list_page(menu, 1, 0);
            menu->page = 2;
        } else if (menu->item == 2 && vars->mail_count != 0) {
            sound_se_play(0x11);
            object_load_mail_by_id(menu->row);
            menu->page = 2;
        } else if (menu->item == 4) {
            dialog_menu_status_page(menu, 1);
        }
        break;
    }
}

static void dialog_menu_back(PauseMenu *menu) {
    sound_se_play(8);
    switch (menu->page) {
    case 1:
        menu->page = 0;
        if (menu->item == 1) {
            sprite_delete(0x237);
            sprite_delete(0x238);
            sprite_delete(0x239);
        } else if (menu->item == 2) {
            mail_list_close();
            sprite_set_visible(0x20A, 0);
            sprite_set_visible(0x20C, 0);
            sprite_set_visible(0x212, 0);
        } else if (menu->item == 3) {
            sprite_set_visible(0x23D, 0);
        } else if (menu->item == 4) {
            sprite_delete(0x23A);
            sprite_delete(0x23B);
            sprite_delete(0x23C);
        }
        break;
    case 2:
        if (menu->item == 1) {
            menu->page = 1;
            sprite_set_visible(0x239, 0);
        } else if (menu->item == 2) {
            menu->page = 1;
            mail_free();
        }
        break;
    }
}

static void dialog_menu_handle_input(PauseMenu *menu) {
    s32 pad;

    if (kaj_system.pad_mode != 1 || menu->animating != 0) {
        return;
    }
    pad = kaj_pad_read();
    if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
        dialog_menu_move_cursor(menu, 1);
    } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
        dialog_menu_move_cursor(menu, 0);
    } else if (!(kaj_system.pad_prev & 0x8000) && (kaj_system.pad_now & 0x8000)) {
        if (*(s32 *)menu == 0x10003) {
            dialog_menu_options_page(menu, 2, 1);
        }
    } else if (!(kaj_system.pad_prev & 0x2000) && (kaj_system.pad_now & 0x2000)) {
        if (*(s32 *)menu == 0x10003) {
            dialog_menu_options_page(menu, 2, 0);
        }
    } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
        if (menu->page == 0) {
            sound_se_play(8);
            main_goto_ofc(1, 1, 0, 0);
            return;
        }
        dialog_menu_back(menu);
    } else if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20) && menu->item != 0) {
        dialog_menu_confirm(menu);
    }
    if (menu->page == 2 && menu->item == menu->page) {
        if (pad & 0x1000) {
            mail_scroll(0);
        } else if (pad & 0x4000) {
            mail_scroll(1);
        }
    }
}

static void dialog_menu_animate(PauseMenu *menu) {
    if (dialog_menu_cycle_pos_a >= 0xA0) {
        dialog_menu_cycle_pos_a = 0x9F;
        dialog_menu_cycle_dir_a = 1 - dialog_menu_cycle_dir_a;
    } else if (dialog_menu_cycle_pos_a < 0x90) {
        dialog_menu_cycle_pos_a = 0x90;
        dialog_menu_cycle_dir_a = 1 - dialog_menu_cycle_dir_a;
    }
    if (dialog_menu_cycle_dir_a != 0) {
        sprite_set_clut_entry(0x208, dialog_menu_cycle_pos_a, 0x67B5);
        dialog_menu_cycle_pos_a++;
    } else {
        sprite_set_clut_entry(0x208, dialog_menu_cycle_pos_a, 0x38A2);
        dialog_menu_cycle_pos_a--;
    }
    if (rand() % 100 < 10) {
        dialog_menu_cycle_dir_a = 1 - dialog_menu_cycle_dir_a;
    }

    if (dialog_menu_cycle_pos_b >= 0xB0) {
        dialog_menu_cycle_pos_b = 0xAF;
        dialog_menu_cycle_dir_b = 1 - dialog_menu_cycle_dir_b;
    } else if (dialog_menu_cycle_pos_b < 0xA0) {
        dialog_menu_cycle_pos_b = 0xA0;
        dialog_menu_cycle_dir_b = 1 - dialog_menu_cycle_dir_b;
    }
    if (dialog_menu_cycle_dir_b != 0) {
        sprite_set_clut_entry(0x208, dialog_menu_cycle_pos_b, 0x2533);
        dialog_menu_cycle_pos_b++;
    } else {
        sprite_set_clut_entry(0x208, dialog_menu_cycle_pos_b, 0x4D44);
        dialog_menu_cycle_pos_b--;
    }
    if (rand() % 100 < 5) {
        dialog_menu_cycle_dir_b = 1 - dialog_menu_cycle_dir_b;
    }

    if (dialog_menu_cycle_pos_c >= 0xC0) {
        dialog_menu_cycle_pos_c = 0xBF;
        dialog_menu_cycle_dir_c = 1 - dialog_menu_cycle_dir_c;
    } else if (dialog_menu_cycle_pos_c < 0xB0) {
        dialog_menu_cycle_pos_c = 0xB0;
        dialog_menu_cycle_dir_c = 1 - dialog_menu_cycle_dir_c;
    }
    if (dialog_menu_cycle_dir_c != 0) {
        sprite_set_clut_entry(0x208, dialog_menu_cycle_pos_c, 0x67B5);
        dialog_menu_cycle_pos_c++;
    } else {
        sprite_set_clut_entry(0x208, dialog_menu_cycle_pos_c, 0x38A2);
        dialog_menu_cycle_pos_c--;
    }
    if (rand() % 100 < 15) {
        dialog_menu_cycle_dir_c = 1 - dialog_menu_cycle_dir_c;
    }

    if (menu->page == 0 && menu->item_sprite != NULL && menu->animating != 0) {
        menu->item_sprite->cell_row++;
        if (menu->item_sprite->cell_row >= 4) {
            menu->item_sprite->cell_row = 3;
            menu->animating = 0;
            if (menu->label_sprite != NULL) {
                if (menu->label_sprite->visible == 0) {
                    menu->label_sprite->visible = 1;
                }
                menu->label_sprite->cell_col = 0;
                menu->label_sprite->cell_row = menu->item - 1;
                menu->label_sprite->y = menu->item * menu->label_sprite->cell_h + 0x48;
            }
        }
    }
}

void dialog_menu_run(void) {
    PauseMenu state;
    PauseMenu *menu;
    s32 ev[6];
    s16 done = 0;
    u16 i;

    sprite_set_visible(0x400, 0);
    sprite_set_visible(0x409, 0);
    sprite_set_visible(0x207, 1);
    sprite_fill_clut(0x207, 0xF0, 0xFE, 0);
    object_load_res(6, 1);
    sprite_set_visible(0x207, 0);
    sprite_set_visible(0x208, 1);
    sprite_set_visible(0x209, 1);
    sprite_set_visible(0x20B, 1);
    sprite_fill_clut(0x208, 0x90, 0x9F, 0x38A2);
    sprite_fill_clut(0x208, 0xA0, 0xAF, 0x4D44);
    sprite_fill_clut(0x208, 0xB0, 0xBF, 0x38A2);
    menu = &state;
    menu->item = 0;
    menu->page = 0;
    menu->animating = 0;
    menu->row = 0;
    menu->item_sprite = NULL;
    menu->label_sprite = NULL;
    dialog_menu_anim_sprite = NULL;
    kaj_timer_enable();
    effect_start_fade(0, 3);
    sound_bgm_play(2);
    do {
        switch (kaj_event_get(ev)) {
        case 4:
            event_handle_tick(0);
            continue;
        case 0:
            dialog_menu_handle_input(&state);
            if ((s16)main_take_scene_change() != 0) {
                effect_start_fade(1, 3);
            }
            break;
        case 0x100:
            done = event_handle_effect_done(ev);
            continue;
        default:
            kaj_event_done(ev);
            continue;
        }
        dialog_menu_animate(&state);
        roadmap_draw_frame(3);
    } while (done == 0);
    kaj_timer_disable();
    sound_bgm_stop();
    sprite_set_visible(0x400, 1);
    sprite_set_visible(0x409, 1);
    for (i = 0x207; i < 0x23E; i++) {
        sprite_delete(i);
    }
    dialog_menu_anim_sprite = NULL;
}

static void dialog_draw_string(s32 str, s16 max_rows) {
    s16 rect[4];
    u16 buf[0x40];
    MenuSprite *window;
    u16 *dst;
    u16 *glyph;
    u8 *s;
    u8 c;
    s16 sjis;
    s32 row;
    s32 col;
    s32 i;
    s32 n;
    s32 j;

    window = sprite_find(dialog_window_sprite);
    if (window == NULL) {
        return;
    }
    row = 0;
    col = 0;
    rect[2] = 4;
    rect[0] = 0;
    rect[1] = 0;
    rect[3] = 16;
    n = strlen((char *)str);
    for (i = 0; i < n; ) {
        if (row >= max_rows) {
            return;
        }
        s = (u8 *)str + i;
        c = s[0];
        if ((s8)s[0] >= 0) {
            i++;
            switch (c) {
            case ' ':
                col++;
                break;
            case ',':
                col = 0;
                row++;
                break;
            default:
                dialog_color = c - '0';
                break;
            }
            continue;
        }
        dst = buf;
        sjis = (s[0] << 8) | s[1];
        rect[0] = window->tim->x + col * 4;
        rect[1] = window->tim->y + row * 16;
        glyph = Krom2RawAdd2(sjis);
        memset(dst, 0, 0x80);
        for (j = 0; j < 15; j++, glyph++) {
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 4;
                v = 0;
                for (k = 7, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = dialog_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 0;
                v = 0;
                for (k = 3, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = dialog_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 12;
                v = 0;
                for (k = 15, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = dialog_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 8;
                v = 0;
                for (k = 11, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = dialog_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
        }
        LoadImage2(rect, buf);
        col++;
        if (col >= 16) {
            col = 0;
            row++;
        }
        i += 2;
    }
}

static inline s16 dialog_draw_next_check_page(s16 flag) {
    EventState *event = &event_state;
    if (dialog_pos >= dialog_len) {
        if (flag) {
            dialog_release_cmd();
        }
        return -1;
    }
    if (dialog_col >= 16) {
        dialog_col = 0;
        dialog_row++;
    }
    if (dialog_row >= 3) {
        dialog_col = 0;
        if (flag) {
            event->state = 3;
            event->circle_flags = 8;
            sprite_set_visible(0x40A, 1);
        }
        return 1;
    }
    return 0;
}

static s16 dialog_draw_next(s32 str, s32 prompt) {
    s16 rect[4];
    u16 buf[0x40];
    MenuSprite *window;
    u16 *dst;
    u16 *glyph;
    u8 *s;
    u8 c;
    s16 status;
    s32 j;

    window = sprite_find(dialog_window_sprite);
    if (window == NULL) {
        return 0;
    }
    rect[2] = 4;
    rect[0] = 0;
    rect[1] = 0;
    rect[3] = 16;
loop:
    status = dialog_draw_next_check_page(prompt);
    if (status < 0) {
        return 0;
    }
    if (status == 1) {
        return 1;
    }
    s = (u8 *)str + dialog_pos;
    c = s[0];
    if ((s8)s[0] >= 0) {
        dialog_pos++;
        switch (c) {
        case ' ':
            dialog_col++;
            break;
        case ',':
            dialog_col = 0;
            dialog_row++;
            break;
        default:
            dialog_color = c - '0';
            break;
        }
        goto loop;
    }
    dst = buf;
    glyph = Krom2RawAdd2((s[0] << 8) | s[1]);
    memset(dst, 0, 0x80);
    for (j = 0; j < 15; j++, glyph++) {
        {
            u16 v;
            u16 c;
            s32 k;
            s32 sh;
            s32 m;

            m = 4;
            v = 0;
            for (k = 7, sh = 0; k >= m; k--, sh += 4) {
                c = (dst[0] & (0xF << sh)) >> sh;
                if ((*glyph >> k) & 1) {
                    c = dialog_color;
                }
                v |= c << sh;
            }
            *dst++ = v;
        }
        {
            u16 v;
            u16 c;
            s32 k;
            s32 sh;
            s32 m;

            m = 0;
            v = 0;
            for (k = 3, sh = 0; k >= m; k--, sh += 4) {
                c = (dst[0] & (0xF << sh)) >> sh;
                if ((*glyph >> k) & 1) {
                    c = dialog_color;
                }
                v |= c << sh;
            }
            *dst++ = v;
        }
        {
            u16 v;
            u16 c;
            s32 k;
            s32 sh;
            s32 m;

            m = 12;
            v = 0;
            for (k = 15, sh = 0; k >= m; k--, sh += 4) {
                c = (dst[0] & (0xF << sh)) >> sh;
                if ((*glyph >> k) & 1) {
                    c = dialog_color;
                }
                v |= c << sh;
            }
            *dst++ = v;
        }
        {
            u16 v;
            u16 c;
            s32 k;
            s32 sh;
            s32 m;

            m = 8;
            v = 0;
            for (k = 11, sh = 0; k >= m; k--, sh += 4) {
                c = (dst[0] & (0xF << sh)) >> sh;
                if ((*glyph >> k) & 1) {
                    c = dialog_color;
                }
                v |= c << sh;
            }
            *dst++ = v;
        }
    }
    rect[0] = window->tim->x + dialog_col * 4;
    rect[1] = window->tim->y + dialog_row * 16;
    LoadImage2(rect, buf);
    dialog_col++;
    dialog_pos += 2;
    if ((s16)prompt) {
        if (dialog_draw_next_check_page(1) < 0) {
            return 0;
        }
    } else {
        if (dialog_draw_next_check_page(0) <= 0) {
            return 0;
        }
    }
    return 1;
}

static void dialog_draw_line(char *str, s16 line_idx) {
    s16 rect[4];
    u16 buf[0x40];
    MenuSprite *window;
    u16 *dst;
    u16 *glyph;
    u8 *s;
    s16 sjis;
    s16 line;
    s32 y;
    s32 col;
    s32 i;
    s32 n;
    s32 j;

    line = line_idx;
    window = sprite_find(dialog_window_sprite);
    if (window == NULL) {
        return;
    }
    n = strlen(str);
    y = dialog_line_y[line_idx];
    if (line_idx < 2) {
        col = (32 - n) / 4;
    } else {
        col = 1;
    }
    i = 0;
    rect[2] = 4;
    rect[0] = 0;
    rect[1] = 0;
    rect[3] = 16;
    while (i < n) {
        s = (u8 *)str + i;
        if ((s8)s[0] >= 0) {
            i++;
            if (s[0] == ' ') {
                col++;
            }
            continue;
        }
        dst = buf;
        sjis = (s[0] << 8) | s[1];
        rect[0] = window->tim->x + col * 4;
        rect[1] = window->tim->y + y;
        glyph = Krom2RawAdd2(sjis);
        StoreImage2(rect, dst);
        for (j = 0; j < 15; j++, glyph++) {
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 4;
                v = 0;
                for (k = 7, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = dialog_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 0;
                v = 0;
                for (k = 3, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = dialog_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 12;
                v = 0;
                for (k = 15, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = dialog_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 8;
                v = 0;
                for (k = 11, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = dialog_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
        }
        LoadImage2(rect, buf);
        col++;
        if (line >= 3 && col >= 15) {
            col = 1;
            line++;
            y = dialog_line_y[line];
        }
        i += 2;
    }
}

static void dialog_format_number(u8 *out, u16 n) {
    u16 hundreds;
    u16 tens;
    u16 ones;

    memset(out, 0, 8);
    if (n == 0) {
        strncpy(out, dialog_str_unknown, 2);
        return;
    }
    n %= 1000;
    hundreds = n / 100;
    n %= 100;
    tens = n / 10;
    ones = n % 10;
    if (hundreds == 0) {
        if (tens == 0) {
            out[0] = 0x82;
            out[1] = ones + 0x4F;
        } else {
            out[0] = 0x82;
            out[1] = tens + 0x4F;
            out[2] = 0x82;
            out[3] = ones + 0x4F;
        }
    } else {
        out[0] = 0x82;
        out[1] = hundreds + 0x4F;
        out[2] = 0x82;
        out[3] = tens + 0x4F;
        out[4] = 0x82;
        out[5] = ones + 0x4F;
    }
}

void dialog_show_timed(u16 mode, s16 big, s32 str, s16 se, s32 seconds) {
    Rect rect;
    MenuSprite *window;
    s16 b;

    b = (mode == 1 || mode == 2);
    if (big != 0) {
        GameVars_u8017EBF8 *g = &action_vars;
        EventState *d = &event_state;
        s16 m = 3;

        if (m == 1) {
            dialog_window_sprite = 0x403;
            sprite_set_visible(0x403, 1);
            sprite_set_visible(0x404, 0);
            sprite_set_clut_entry(0x403, 3, 0x14BF);
        } else if (m == 3) {
            dialog_window_sprite = 0x404;
            sprite_set_visible(0x403, 0);
            sprite_set_visible(0x404, 1);
            sprite_set_clut_entry(0x404, 3, 0x14BF);
        }
        dialog_color = 1;
        d->circle_flags = 0;
        d->circle_set = -1;
        d->cross_flags = 0;
        d->cross_set = -1;
        window = sprite_find(dialog_window_sprite);
        if (window != NULL) {
            rect.x = window->tim->x;
            rect.y = window->tim->y;
            rect.w = window->tim->w;
            rect.h = window->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
        dialog_draw_string(str, m);
        if (se == 1) {
            sound_se_play(0xF);
        } else if (se == 2) {
            sound_se_play(6);
        } else if (se == 3) {
            sound_se_play(5);
        } else if (se == 4) {
            sound_se_play(0xE);
        }
        if (g->text_open == 0) {
            g->text_open = 1;
        }
    } else {
        GameVars_u8017EBF8 *g = &action_vars;
        EventState *d = &event_state;
        s16 m = 1;

        if (m == 1) {
            dialog_window_sprite = 0x403;
            sprite_set_visible(0x403, 1);
            sprite_set_visible(0x404, 0);
            sprite_set_clut_entry(0x403, 3, 0x14BF);
        } else if (m == 3) {
            dialog_window_sprite = 0x404;
            sprite_set_visible(0x403, 0);
            sprite_set_visible(0x404, 1);
            sprite_set_clut_entry(0x404, 3, 0x14BF);
        }
        dialog_color = 1;
        d->circle_flags = 0;
        d->circle_set = -1;
        d->cross_flags = 0;
        d->cross_set = -1;
        window = sprite_find(dialog_window_sprite);
        if (window != NULL) {
            rect.x = window->tim->x;
            rect.y = window->tim->y;
            rect.w = window->tim->w;
            rect.h = window->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
        dialog_draw_string(str, m);
        if (se == 1) {
            sound_se_play(0xF);
        } else if (se == 2) {
            sound_se_play(6);
        } else if (se == 3) {
            sound_se_play(5);
        } else if (se == 4) {
            sound_se_play(0xE);
        }
        if (g->text_open == 0) {
            g->text_open = 1;
        }
    }
    main_wait(mode, b, b, seconds);
}

static void dialog_start_typing(s32 str) {
    GameVars_u8017EBF8 *vars = &action_vars;
    Rect rect;
    MenuSprite *window;

    dialog_window_sprite = 0x404;
    sprite_set_visible(0x403, 0);
    sprite_set_visible(0x404, 1);
    sprite_set_clut_entry(0x40A, 3, 0x14BF);
    dialog_color = 2;
    dialog_col = 0;
    dialog_row = 0;
    window = sprite_find(dialog_window_sprite);
    if (window != NULL) {
        rect.x = window->tim->x;
        rect.y = window->tim->y;
        rect.w = window->tim->w;
        rect.h = window->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    dialog_pos = 0;
    dialog_len = strlen((char *)str);
    if (dialog_draw_next(str, 1) != 0) {
        dialog_wait -= kaj_system_vsync_delta[0];
        if (dialog_wait > 0) {
            (*dialog_cmd)->state = 4;
        } else {
            dialog_wait = 0;
            (*dialog_cmd)->state = 3;
        }
        action_push_front(dialog_cmd);
    }
    if (vars->text_open == 0) {
        vars->text_open = 1;
    }
}

void dialog_show_profile(u16 npc_id) {
    GameVars_u8017EBF8 *vars = &action_vars;
    char buf[0x20];
    Rect rect;
    u8 height_str[8];
    u8 age_str[8];
    Npc *npc;
    NpcBody *body;
    MenuSprite *window;
    Rect *r;
    char *pb;
    s32 i;

    npc = actor_find(0, npc_id);
    if (npc == NULL) {
        return;
    }
    body = actor_find_body(npc->body_id);
    if (body == NULL) {
        return;
    }
    dialog_color = 9;
    dialog_window_sprite = 0x40D;
    r = &rect;
    window = sprite_find(0x40D);
    if (window != NULL) {
        rect.x = 0x300;
        r->y = 0x100;
        r->w = 0x40;
        r->h = 0x10;
        for (i = 0; i < 8; i++) {
            rect.y = 0x100 + i * 0x10;
            MoveImage2(&rect, (s16)window->tim->x, (s16)window->tim->y + dialog_line_y[i]);
        }
    }

    dialog_format_number(height_str, body->height);
    pb = (char *)age_str;
    dialog_format_number((u8 *)pb, body->age);
    pb = buf;
    memset(pb, 0, 0x20);
    /* profile line format: age, sex, height, blood type */
    sprintf(pb, "%s\215\313 %s %s\202\203\202\215 %s", age_str, dialog_sex_names[body->sex], height_str, dialog_blood_types[body->blood_type]);
    dialog_draw_line(body->line0, 0);
    dialog_draw_line(body->line1, 1);
    dialog_draw_line(pb, 2);
    dialog_draw_line(body->line2, 3);
    sprite_set_visible(0x40D, 1);
    if (vars->text_open == 0) {
        vars->text_open = 1;
    }
}

static inline void dialog_exec_command_show(s32 str, s16 mode, s16 circle_set, u16 circle_flags, s16 cross_set, u16 cross_flags, s16 se) {
    Rect rect;
    MenuSprite *window;
    GameVars_u8017EBF8 *g2 = &action_vars;
    EventState *event = &event_state;
    if (mode == 1) {
        dialog_window_sprite = 0x403;
        sprite_set_visible(0x403, 1);
        sprite_set_visible(0x404, 0);
        sprite_set_clut_entry(0x403, 3, 0x14BF);
    } else if (mode == 3) {
        dialog_window_sprite = 0x404;
        sprite_set_visible(0x403, 0);
        sprite_set_visible(0x404, 1);
        sprite_set_clut_entry(0x404, 3, 0x14BF);
    }
    dialog_color = 1;
    event->circle_flags = circle_flags;
    event->circle_set = circle_set;
    event->cross_flags = cross_flags;
    event->cross_set = cross_set;
    if (circle_flags != 0 || cross_flags != 0) {
        event->state = 2;
    }
    window = sprite_find(dialog_window_sprite);
    if (window != NULL) {
        rect.x = window->tim->x;
        rect.y = window->tim->y;
        rect.w = window->tim->w;
        rect.h = window->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    dialog_draw_string(str, mode);
    if (se == 1) {
        sound_se_play(0xF);
    } else if (se == 2) {
        sound_se_play(6);
    } else if (se == 3) {
        sound_se_play(5);
    } else if (se == 4) {
        sound_se_play(0xE);
    }
    if (g2->text_open == 0) {
        g2->text_open = 1;
    }
}

void dialog_exec_command(Action *action) {
    GameVars_u8017EBF8 *vars = &action_vars;
    Player *player = player_status_player[0];
    u16 state = action->cmd->sub;
    MenuSprite *window;
    char **args;
    s16 circle_set;
    u16 circle_flags;
    s16 cross_set;
    u16 cross_flags;
    s16 se;
    s32 str;

    switch (state) {
    case 0:
        switch (vars->text_speed_setting) {
        case 2:
            dialog_wait = 20;
            break;
        case 1:
            dialog_wait = 10;
            break;
        case 0:
            dialog_wait = 5;
            break;
        }
        dialog_cmd = (TextCmd **)action;
        dialog_start_typing((s32)action->args[0]);
        break;
    case 1:
        if (actor_death_set_1000 != 0) {
            player->flags |= 0x100;
            actor_death_set_1000 = 0;
            dialog_show_timed(1, 0, (s32)action->args[0], atoi(action->args[5]), 2);
            player->flags &= 0xFEFF;
            dialog_release_cmd();
            sprite_set_visible(0x403, 0);
            sprite_set_visible(0x404, 0);
            sprite_set_visible(0x40A, 0);
            sprite_set_visible(0x40D, 0);
            if (vars->text_open != 0) {
                vars->text_open = 0;
            }
        } else {
            args = action->args;
            circle_set = atoi(args[1]);
            circle_flags = atoi(action->args[2]);
            cross_set = atoi(action->args[3]);
            cross_flags = atoi(action->args[4]);
            se = atoi(action->args[5]);
            dialog_exec_command_show((s32)args[0], 1, circle_set, circle_flags, cross_set, cross_flags, se);
        }
        break;
    case 3:
        switch (vars->text_speed_setting) {
        case 2:
            dialog_wait = 20;
            break;
        case 1:
            dialog_wait = 10;
            break;
        case 0:
            dialog_wait = 5;
            break;
        }
        str = (s32)action->args[0];
        if (dialog_row == 3) {
            dialog_row = 0;
            window = sprite_find(dialog_window_sprite);
            if (window != NULL) {
                Rect rect;

                rect.x = window->tim->x;
                rect.y = window->tim->y;
                rect.w = window->tim->w;
                rect.h = window->tim->h;
                ClearImage2(&rect, 0, 0, 0);
            }
        }
        if (dialog_draw_next(str, 1) != 0) {
            dialog_wait -= kaj_system_vsync_delta[0];
            if (dialog_wait > 0) {
                (*dialog_cmd)->state = 4;
            } else {
                dialog_wait = 0;
                (*dialog_cmd)->state = 3;
            }
            action_push_front(dialog_cmd);
        }
        break;
    case 4:
        dialog_wait -= kaj_system_vsync_delta[0];
        if (dialog_wait > 0) {
            (*dialog_cmd)->state = 4;
        } else {
            (*dialog_cmd)->state = 3;
            dialog_wait = 0;
        }
        action_push_front(dialog_cmd);
        break;
    }
}

void dialog_start_narration(s32 str) {
    GameVars_u8017EBF8 *vars = &action_vars;
    Player *player = player_status_player[0];
    Rect rect;
    TssSlot *task;
    MenuSprite *window;

    task = kaj_tss_alloc(4);
    task->type = 8;
    task->cur = 0;
    task->target = strlen((char *)str);
    task->step = 1;
    task->delay = 0xA;
    task->on_step = dialog_narration_step;
    task->on_end = dialog_narration_end;
    task->on_kill = dialog_narration_end;
    sprite_set_visible(0x403, 0);
    sprite_set_visible(0x404, 1);
    sprite_set_clut_entry(0x40A, 3, 0x14BF);
    dialog_window_sprite = 0x404;
    dialog_color = 1;
    dialog_col = 0;
    dialog_row = 0;
    dialog_pos = 0;
    dialog_len = strlen((char *)str);
    window = sprite_find(dialog_window_sprite);
    if (window != NULL) {
        rect.x = window->tim->x;
        rect.y = window->tim->y;
        rect.w = window->tim->w;
        rect.h = window->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    *(s32 *)task->data = str;
    dialog_draw_next(str, 0);
    dialog_cue_fade_done = 0;
    dialog_cue_bgm_done = 0;
    player->flags |= 0x100;
    vars->narration_task = kaj_tss_start(task);
}

void dialog_show(s32 str, s16 mode, s16 circle_set, u16 circle_flags, s16 cross_set, u16 cross_flags, s16 se) {
    GameVars_u8017EBF8 *vars = &action_vars;
    EventState *event = &event_state;
    Rect rect;
    MenuSprite *window;

    if (mode == 1) {
        dialog_window_sprite = 0x403;
        sprite_set_visible(0x403, 1);
        sprite_set_visible(0x404, 0);
        sprite_set_clut_entry(0x403, 3, 0x14BF);
    } else if (mode == 3) {
        dialog_window_sprite = 0x404;
        sprite_set_visible(0x403, 0);
        sprite_set_visible(0x404, 1);
        sprite_set_clut_entry(0x404, 3, 0x14BF);
    }
    dialog_color = 1;
    event->circle_flags = circle_flags;
    event->circle_set = circle_set;
    event->cross_flags = cross_flags;
    event->cross_set = cross_set;
    if (circle_flags != 0 || cross_flags != 0) {
        event->state = 2;
    }
    window = sprite_find(dialog_window_sprite);
    if (window != NULL) {
        rect.x = window->tim->x;
        rect.y = window->tim->y;
        rect.w = window->tim->w;
        rect.h = window->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    dialog_draw_string(str, mode);
    if (se == 1) {
        sound_se_play(0xF);
    } else if (se == 2) {
        sound_se_play(6);
    } else if (se == 3) {
        sound_se_play(5);
    } else if (se == 4) {
        sound_se_play(0xE);
    }
    if (vars->text_open == 0) {
        vars->text_open = 1;
    }
}

void dialog_close(void) {
    GameVars_u8017EBF8 *vars = &action_vars;

    dialog_release_cmd();
    sprite_set_visible(0x403, 0);
    sprite_set_visible(0x404, 0);
    sprite_set_visible(0x40A, 0);
    sprite_set_visible(0x40D, 0);
    if (vars->text_open != 0) {
        vars->text_open = 0;
    }
}

void dialog_next_page(EventState *event) {
    if (event->circle_flags & 8) {
        event->circle_flags &= ~8;
        event->state = 1;
        sprite_set_visible(0x40A, 0);
        sprite_set_clut_entry(0x40A, 3, 0x14BF);
        sound_se_play(0x11);
    }
}

void dialog_release_cmd(void) {
    TextCmd *cmd;

    if (dialog_cmd != NULL) {
        cmd = *dialog_cmd;
        if (cmd->opcode == 5 && (u16)(cmd->state - 3) < 2) {
            cmd->state = 0;
        }
        dialog_cmd = NULL;
    }
    if (dialog_window_sprite >= 0) {
        dialog_window_sprite = -1;
    }
}

void dialog_wait_step(void) {
    dialog_wait -= kaj_system_vsync_delta[0];
    if (dialog_wait > 0) {
        (*dialog_cmd)->state = 4;
    } else {
        dialog_wait = 0;
        (*dialog_cmd)->state = 3;
    }
    action_push_front(dialog_cmd);
}

void dialog_type_step(s32 str) {
    Rect rect;
    MenuSprite *window;

    if (dialog_row == 3) {
        dialog_row = 0;
        window = sprite_find(dialog_window_sprite);
        if (window != NULL) {
            rect.x = window->tim->x;
            rect.y = window->tim->y;
            rect.w = window->tim->w;
            rect.h = window->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
    }
    if (dialog_draw_next(str, 1) != 0) {
        dialog_wait -= kaj_system_vsync_delta[0];
        if (dialog_wait > 0) {
            (*dialog_cmd)->state = 4;
        } else {
            dialog_wait = 0;
            (*dialog_cmd)->state = 3;
        }
        action_push_front(dialog_cmd);
    }
}

static void dialog_narration_step(TssSlot *task) {
    Rect rect;
    MenuSprite *window;
    s32 str;

    if (dialog_narration_page_full != 0) {
        dialog_narration_page_full = 0;
        return;
    }
    str = *(s32 *)task->data;
    task->cur = dialog_pos;
    if (dialog_row == 3) {
        dialog_row = 0;
        window = sprite_find(dialog_window_sprite);
        if (window != NULL) {
            rect.x = window->tim->x;
            rect.y = window->tim->y;
            rect.w = window->tim->w;
            rect.h = window->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
    }
    dialog_narration_page_full = dialog_draw_next(str, 0);
}

static void dialog_narration_end(void) {
    s32 v = -1;
    dialog_window_sprite = v;
    player_status_player[0]->flags &= 0xFEFF;
    action_vars_narration_task[0] = v;
}

void dialog_narration_cues(s16 ending) {
    if (action_vars_narration_task[0] < 0) {
        return;
    }
    if (ending == 0) {
        if (dialog_pos != 0x1AA) {
            if (dialog_pos != 0x21A) {
                return;
            }
            if (dialog_cue_bgm_done == 0) {
                sound_bgm_fade_out(3);
                dialog_cue_bgm_done = 1;
            }
            return;
        }
    } else if (dialog_pos != 0x182) {
        return;
    }
    if (dialog_cue_fade_done == 0) {
        effect_start_fade(0, 3);
        dialog_cue_fade_done = 1;
    }
}
