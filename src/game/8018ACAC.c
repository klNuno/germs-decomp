#include "common.h"
#include "game/types.h"

typedef struct { s16 unk0, unk2, unk4, unk6; } Unk_801DFD30;
Unk_801DFD30 *mail_list;
extern SceneRequest scene_request;
void kaj_pad_reset(s32 a);
typedef struct { s16 unk0; s16 unk2; u16 unk4; } Unk_8018BD60_0;
typedef struct { Unk_8018BD60_0 *unk0; } Unk_8018BD60;
void mail_receive(u16 a);
extern GameVars action_vars;
extern MailMenu mail_menu;
void effect_start_sprite_slide(s32 a, u16 b, s32 c);
void sprite_set_visible(s32 arg0, s32 arg1);
void mail_menu_draw(MailMenu *p, s32 b);
u16 *mail_scrollbar;
s16 mail_list_top;
s16 mail_list_row;
extern char mail_str_file[];
u16 *sprite_find(u16 arg0);
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
void mail_list_refresh(GameVars *a, s16 b);
void sprite_delete(s32 arg0);
void free3(void *ptr);
typedef struct { u8 unk0[0xC]; u16 unkC; s16 unkE; } Unk_8018BC50_8;
typedef struct Unk_8018BC50 { u16 unk0; s16 unk2; s32 unk4; Unk_8018BC50_8 *unk8; Unk_8018BC50_8 *unkC; } Unk_8018BC50;
extern SceneTables object_scene_tables;
u16 mail_entry_saved_y;
u16 mail_scrollbar_saved_y;
void sprite_set_clut_entry(s32 a, s32 b, s32 c);
extern PlayerStatus player_status;
void action_update(void);
void npc_update_all(void);
void door_update_all(void);
void mod_npcrec_update_all(void);
void vehicle_update(void);
void mod_update_all(void);
void thing_update_all(void);
void player_update(u16 a, s16 b, s16 c);
void effect_flame_small_update(void);
void effect_clut_cycle_update(void);
void effect_flame_large_update(void);
void roadmap_draw_frame(u16 a);
void mail_menu_clear_rows(MailMenu *p);
void sound_se_play(s32 a);
extern KajSystem kaj_system;
s32 kaj_event_get(s32 *arg0);
void kaj_event_done(s32 *arg0);
void event_handle_alarm(s32 *a);
void event_handle_tick(s16 a);
void event_handle_mod_finish(s32 *a);
s16 event_handle_effect_done(s32 *arg0);
void mail_step_frame(u16 a, s16 b, s16 c);
void sprite_fill_clut(s32 a, s32 b, s32 c, s32 d);
void sprite_copy_cell(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void mail_menu_draw_item_name(s32 a, s32 b, s32 c);
typedef struct { u16 unk0; u16 unk2; u8 unk4[0x10]; s16 unk14; } Unk_8018CD4C_1C;
typedef struct { u8 unk0[0x10]; s16 unk10; u16 unk12; s16 unk14; u16 unk16; s32 unk18; Unk_8018CD4C_1C *unk1C; } Unk_8018CD4C;
void *memset(void *dst, s32 c, u32 n);
s32 LoadImage2(void *rect, void *p);
void sound_se_play(s32 arg0);
typedef struct { s16 unk0; s16 unk2; } Unk_8018C864_1C;
typedef struct { u8 unk0[0x1C]; Unk_8018C864_1C *unk1C; } Unk_8018C864;
ItemRecord *effect_item_find(s16 arg0);
s32 strlen(char *s);
u16 *Krom2RawAdd2(u16 sjis);
typedef struct {
    s16 unk0[5];
    s16 unkA;
    char *unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    u8 unk1E[2];
    char unk20[4];
} Unk_8018C554;
char *strncpy(char *dst, char *src, u32 n);
typedef struct {
    s16 unk0;
    s16 unk2;
    u16 unk4;
    u16 unk6;
    u8 unk8[0xA];
    u16 unk12;
} Unk_801E0324_1C;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    u16 unkC;
    s16 unkE;
    s16 unk10;
    u16 unk12;
    s32 unk14;
    s32 unk18;
    Unk_801E0324_1C *unk1C;
} Unk_801E0324_10;
typedef struct {
    u16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    u16 *unk8;
    u16 *unkC;
    Unk_801E0324_10 *unk10;
    Unk_801E0324_10 *unk14;
    Unk_801E0324_10 *unk18;
    Unk_801E0324_10 *unk1C;
} Unk_801E0324;
extern Unk_801E0324 *D_801E0324[];
s16 mail_page_tex_v_0;
s16 mail_page_tex_v_1;
s16 mail_page_tex_v_2;
s16 mail_page_tex_v_3;
s16 mail_page_height_0;
s16 mail_page_height_1;
s16 mail_page_height_2;
s16 mail_page_height_3;
typedef struct {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_8018ACAC;
void sprite_create(Unk_801E0324_10 **arg0, void *arg1);
void sprite_add(s32 arg0);
s16 mail_main_restarted;
extern s32 event_effect_done_hook;
extern s32 event_alarm_hook;
extern s32 event_tick_hook;
extern s32 event_leave_hook;
extern s32 event_enter_hook;
extern s32 event_mod_finish_hook;
extern void *action_set_list;
extern void *action_queue;
extern void *block_list;
extern void *door_list;
extern void *mod_list;
extern void *sprite_list;
extern void *thing_list;
void kaj_init(void);
void kaj_ll_create(void *arg0);
void event_open(void);
void roadmap_init_draw(void);
void object_load_res(s32 arg0, s32 arg1);
void player_init(void);
void effect_clear_alarms(void);
void vehicle_train_init_state(void);
void sprite_title_run(s32 arg0);
void kaj_srand_ticks(void);
void event_draw_hud(void);
void block_building_main(void);
void object_room_run(void);
void thing_game_loop(void);

void mail_create(Unk_801E0324 **out, Unk_8018ACAC *rec, s16 list_index) {
    *out = kaj_malloc(0x20);
    if (*out == NULL) {
        kaj_abend(3, "Error Allocating MAIL Handler", mail_str_file, 0x3B);
    }
    (*out)->unk0 = rec->unk0;
    (*out)->unk2 = list_index;
    (*out)->unk4 = rec->unk2;
    (*out)->unk6 = 0;

    sprite_create(&(*out)->unk10, (u8 *)rec + rec->unk4);
    sprite_add((s32)(*out)->unk10);
    (*out)->unk10->unk4 = 1;
    (*out)->unk10->unkC = 0x43;
    (*out)->unk10->unkE = 1;
    mail_page_tex_v_0 = (*out)->unk10->unk1C->unk12;
    mail_page_height_0 = (*out)->unk10->unk12;

    if ((*out)->unk4 >= 2) {
        sprite_create(&(*out)->unk14, (u8 *)rec + rec->unk8);
        sprite_add((s32)(*out)->unk14);
        (*out)->unk14->unk4 = 0;
        (*out)->unk14->unkC = 0x43;
        (*out)->unk14->unkE = 1;
        mail_page_tex_v_1 = (*out)->unk14->unk1C->unk12;
        mail_page_height_1 = (*out)->unk14->unk12;
    }
    if ((*out)->unk4 >= 3) {
        sprite_create(&(*out)->unk18, (u8 *)rec + rec->unkC);
        sprite_add((s32)(*out)->unk18);
        (*out)->unk18->unk4 = 0;
        (*out)->unk18->unkC = 0x43;
        (*out)->unk18->unkE = 1;
        mail_page_tex_v_2 = (*out)->unk18->unk1C->unk12;
        mail_page_height_2 = (*out)->unk18->unk12;
    }
    if ((*out)->unk4 >= 4) {
        sprite_create(&(*out)->unk1C, (u8 *)rec + rec->unk10);
        sprite_add((s32)(*out)->unk1C);
        (*out)->unk1C->unk4 = 0;
        (*out)->unk1C->unkC = 0x43;
        (*out)->unk1C->unkE = 1;
        mail_page_tex_v_3 = (*out)->unk1C->unk1C->unk12;
        mail_page_height_3 = (*out)->unk1C->unk12;
    }

    (*out)->unk8 = sprite_find((*out)->unk0 + 0x217);
    if ((*out)->unk8 != NULL) {
        sprite_set_clut_entry((u16)((*out)->unk0 + 0x217), 7, 0x4D44);
        sprite_set_clut_entry((u16)((*out)->unk0 + 0x217), 9, 0x6358);
        mail_entry_saved_y = (*out)->unk8[6];
        (*out)->unk8[6] = 0x33;
        (*out)->unk8[7] = 1;
    }
    (*out)->unkC = sprite_find(0x20C);
    if (mail_scrollbar != NULL) {
        mail_scrollbar_saved_y = mail_scrollbar[6];
    }
    if ((*out)->unkC != NULL) {
        (*out)->unkC[6] = 0x29;
    }
}

void mail_scroll(s16 forward) {
    Unk_801E0324 *mail = D_801E0324[0];
    s32 offset;
    s32 last_page;
    s32 max;

    if (mail == NULL || mail->unk4 < 2) {
        return;
    }
    offset = mail->unk6;
    if (forward != 0) {
        offset++;
    } else {
        offset--;
    }
    last_page = mail->unk4 - 1;
    max = last_page << 7;
    if (max < offset) {
        offset = max;
    }
    if (offset < 0) {
        offset = 0;
    }
    if (mail->unkC != NULL) {
        mail->unkC[6] = ((offset * 114 / last_page) >> 7) + 41;
    }
    if (offset == 0) {
        mail->unk10->unk4 = 1;
        mail->unk10->unkC = 0x43;
        mail->unk10->unk12 = mail_page_height_0;
        mail->unk10->unk1C->unk12 = mail_page_tex_v_0;
        mail->unk14->unk4 = 0;
        if (mail->unk18 != NULL) {
            mail->unk18->unk4 = 0;
        }
        if (mail->unk1C != NULL) {
            mail->unk1C->unk4 = 0;
        }
    } else if (offset > 0 && offset < 128) {
        mail->unk10->unk4 = 1;
        mail->unk10->unk12 = mail_page_height_0 - offset;
        mail->unk10->unk1C->unk12 = mail_page_tex_v_0 + offset;
        mail->unk14->unk4 = 1;
        mail->unk14->unkC = mail->unk10->unkC + mail->unk10->unk12 - 1;
        mail->unk14->unk12 = offset;
        if (mail->unk18 != NULL) {
            mail->unk18->unk4 = 0;
        }
        if (mail->unk1C != NULL) {
            mail->unk1C->unk4 = 0;
        }
    } else if (offset == 128) {
        mail->unk10->unk4 = 0;
        mail->unk14->unk4 = 1;
        mail->unk14->unkC = 0x43;
        mail->unk14->unk12 = mail_page_height_1;
        mail->unk14->unk1C->unk12 = mail_page_tex_v_1;
        if (mail->unk18 != NULL) {
            mail->unk18->unk4 = 0;
        }
        if (mail->unk1C != NULL) {
            mail->unk1C->unk4 = 0;
        }
    } else if (offset > 128 && offset < 256) {
        mail->unk10->unk4 = 0;
        mail->unk14->unk4 = 1;
        mail->unk14->unk12 = mail_page_height_1 + 128 - offset;
        mail->unk14->unk1C->unk12 = mail_page_tex_v_1 - 128 + offset;
        mail->unk18->unk4 = 1;
        mail->unk18->unkC = mail->unk14->unkC + mail->unk14->unk12 - 1;
        mail->unk18->unk12 = offset - 128;
        if (mail->unk1C != NULL) {
            mail->unk1C->unk4 = 0;
        }
    } else if (offset == 256) {
        mail->unk10->unk4 = 0;
        mail->unk14->unk4 = 0;
        mail->unk18->unk4 = 1;
        mail->unk18->unkC = 0x43;
        mail->unk18->unk12 = mail_page_height_2;
        mail->unk18->unk1C->unk12 = mail_page_tex_v_2;
    } else if (offset > 256 && offset < 384) {
        mail->unk10->unk4 = 0;
        mail->unk14->unk4 = 0;
        mail->unk18->unk4 = 1;
        mail->unk18->unk12 = mail_page_height_2 + 256 - offset;
        mail->unk18->unk1C->unk12 = mail_page_tex_v_2 - 256 + offset;
        mail->unk1C->unk4 = 1;
        mail->unk1C->unkC = mail->unk18->unkC + mail->unk18->unk12 - 1;
        mail->unk1C->unk12 = offset - 256;
    } else if (offset == 384) {
        mail->unk10->unk4 = 0;
        mail->unk14->unk4 = 0;
        mail->unk18->unk4 = 0;
        mail->unk1C->unk4 = 1;
        mail->unk1C->unkC = 0x43;
        mail->unk1C->unk12 = mail_page_height_3;
        mail->unk1C->unk1C->unk12 = mail_page_tex_v_3;
    }
    mail->unk6 = offset;
}

void mail_list_refresh(GameVars *game, s16 selected) {
    s32 i;
    s32 row;
    u16 *sprite;
    Unk_801DFD30 *entry;

    row = 0;
    entry = mail_list;
    for (i = 0; i < (s16)game->vars[0x5F]; i++, entry++) {
        sprite = sprite_find(entry->unk0 + 0x217);
        if (sprite != NULL) {
            if (i >= mail_list_top && i < mail_list_top + 9) {
                sprite[2] = 1;
                sprite[5] = 0x30;
                sprite[6] = row * 16 + 0x33;
                row++;
                if (i == selected) {
                    sprite_set_clut_entry((u16)(entry->unk0 + 0x217), 9, 0x1F);
                } else {
                    sprite_set_clut_entry((u16)(entry->unk0 + 0x217), 9, 0x6358);
                }
                if (entry->unk4 != 0) {
                    sprite_set_clut_entry((u16)(entry->unk0 + 0x217), 7, 0x2C1F);
                } else {
                    sprite_set_clut_entry((u16)(entry->unk0 + 0x217), 7, 0x4D44);
                }
            } else {
                sprite[2] = 0;
            }
        }
    }
}

s32 mail_list_move(s16 up, s16 index) {
    GameVars *game = &action_vars;
    if ((s16)game->vars[0x5F] == 0) {
        return -1;
    }
    if (up != 0) {
        index--;
        if (index < 0) {
            return 0;
        }
        mail_list_row--;
        if (mail_list_row < 0) {
            mail_list_row = 0;
            if (mail_list_top > 0) {
                mail_list_top--;
            }
        }
    } else {
        index++;
        if (index >= (s16)game->vars[0x5F]) {
            return (s16)(game->vars[0x5F] - 1);
        }
        mail_list_row++;
        if (mail_list_row >= 9) {
            mail_list_row = 8;
            if (mail_list_top != index - 8) {
                mail_list_top = index - 8;
            }
        }
    }
    mail_list_refresh(game, index);
    if (mail_scrollbar != NULL) {
        mail_scrollbar[6] = index * 114 / ((s16)game->vars[0x5F] - 1) + 0x29;
    }
    sound_se_play(0xF);
    return index;
}

void mail_list_open(void) {
    s32 id;
    s32 word;
    u16 code;
    Unk_801DFD30 *entry;
    GameVars *game = &action_vars;
    if ((s16)game->vars[0x5F] != 0) {
        mail_list_row = 0;
        mail_list_top = 0;
        mail_scrollbar = sprite_find(0x20C);
        if (mail_scrollbar != NULL) {
            mail_scrollbar[6] = 0x29;
        }
        mail_list = kaj_malloc((s16)game->vars[0x5F] * 8);
        if (mail_list == NULL) {
            kaj_abend(3, "Error Allocating Mail List", mail_str_file, 0x16A);
        }
        for (id = 0; id < 0x20; id++) {
            word = id / 2 + 0x60;
            if (id & 1) {
                code = (u8)*(game->vars + word);
            } else {
                code = *(game->vars + word) >> 8;
            }
            if (code & 0x80) {
                entry = &mail_list[code & 0x3F];
                entry->unk0 = id;
                entry->unk2 = code;
                entry->unk4 = (code & 0x40) >> 6;
            }
        }
        mail_list_refresh(game, 0);
    }
}

void mail_list_close(void) {
    s32 i;
    s32 word;
    s32 code;
    s32 old;
    Unk_801DFD30 *entry;
    GameVars *game = &action_vars;
    if ((s16)game->vars[0x5F] != 0) {
        if (mail_scrollbar != NULL) {
            mail_scrollbar[6] = 0x29;
            mail_scrollbar = NULL;
        }
        entry = mail_list;
        for (i = 0; i < (s16)game->vars[0x5F]; i++, entry++) {
            code = 0x80;
            if (entry->unk4 != 0) {
                code = 0xC0;
            }
            code += i & 0x3F;
            word = entry->unk0 / 2 + 0x60;
            if (entry->unk0 % 2) {
                old = *(game->vars + word);
                *(game->vars + word) = code | (old & ~0xFF);
            } else {
                *(game->vars + word) = (u8)*(game->vars + word) | (code << 8);
            }
        }
        free3(mail_list);
        mail_list = NULL;
        for (i = 0; i < 0x20; i++) {
            sprite_delete((u16)(i + 0x217));
        }
    }
}

void mail_receive(u16 id) {
    s32 received;
    s32 word;
    s16 odd;
    u16 code;
    GameVars *game = &action_vars;
    if (id < 0x20) {
        word = id / 2 + 0x60;
        odd = id % 2;
        if (odd) {
            received = (u8)*(game->vars + word) & 0x80;
        } else {
            received = (*(game->vars + word) >> 8) & 0x80;
        }
        if (received == 0) {
            code = game->vars[0x5F]++ | 0x80;
            if (odd) {
                *(game->vars + word) = code | (*(game->vars + word) & 0xFF00);
            } else {
                *(game->vars + word) = (u8)*(game->vars + word) | (code << 8);
            }
        }
    }
}

void mail_check_schedule(s32 day, s32 hour) {
    GameVars *game = &action_vars;
    if ((s16)game->vars[0x30] == 0) {
        if (day == 0) {
            if (hour == 10) {
                mail_receive(0xE);
            } else if (hour == 0x11) {
                mail_receive(8);
            } else if (hour == 0x15) {
                mail_receive(0x17);
            }
        } else if (day == 1) {
            if (hour == 10) {
                mail_receive(0xF);
            } else if (hour == 0x10) {
                mail_receive(0x1C);
            }
        } else if (day == 2) {
            if (hour == 10) {
                if ((s16)game->vars[0xB] == 100 && (s16)game->vars[1] == 0) {
                    mail_receive(2);
                }
                mail_receive(0x11);
                if ((s16)game->vars[0x13] == 100) {
                    mail_receive(0x14);
                }
            } else if (hour == 0xE) {
                if ((s16)game->vars[0x11] == 10) {
                    mail_receive(0x15);
                }
                mail_receive(0x1A);
            }
        } else if (day == 3) {
            if (hour == 0xC) {
                mail_receive(0x1D);
                if ((s16)game->vars[0x4D] == 0) {
                    mail_receive(0x1F);
                }
            }
        }
    }
}

void mail_free(void) {
    SceneTables *tables = &object_scene_tables;
    Unk_8018BC50 *mail = tables->mail;
    if (mail != NULL) {
        mail_list[mail->unk2].unk4 = 1;
        if (mail->unk8 != NULL) {
            sprite_set_clut_entry((u16)(mail->unk0 + 0x217), 7, 0x2C1F);
            sprite_set_clut_entry((u16)(mail->unk0 + 0x217), 9, 0x1F);
            mail->unk8->unkC = mail_entry_saved_y;
            mail->unk8->unkE = 2;
        }
        if (mail->unkC != NULL) {
            mail->unkC->unkC = mail_scrollbar_saved_y;
        }
        sprite_delete(0x213);
        sprite_delete(0x214);
        sprite_delete(0x215);
        sprite_delete(0x216);
        free3(mail);
        tables->mail = NULL;
    }
}

s16 mail_list_get_id(s16 i) { return mail_list[i].unk0; }

void mail_cmd_receive(Unk_8018BD60 *cmd) {
    mail_receive(cmd->unk0->unk4);
}

s32 mail_is_read(s16 id) {
    s32 v;
    GameVars *game = &action_vars;
    s32 word = id / 2 + 0x60;
    if (id & 1) {
        v = (u8)game->vars[word] & 0x40;
    } else {
        v = (game->vars[word] >> 8) & 0x40;
    }
    return v != 0;
}

void main(void) {
    SceneRequest *request;
    SceneRequest *request_init;
    GameVars *game;
    s16 restarted;
    u16 car_speed;
    u16 text_speed;

    kaj_init();
    memset(&object_scene_tables, 0, 0x64);
    event_alarm_hook = 0;
    event_enter_hook = 0;
    event_leave_hook = 0;
    event_tick_hook = 0;
    event_effect_done_hook = 0;
    event_mod_finish_hook = 0;
    kaj_ll_create(&action_set_list);
    kaj_ll_create(&action_queue);
    kaj_ll_create(&block_list);
    kaj_ll_create(&door_list);
    kaj_ll_create(&mod_list);
    kaj_ll_create(&sprite_list);
    kaj_ll_create(&thing_list);
    event_open();
    roadmap_init_draw();
    object_load_res(1, 0);
    game = &action_vars;
    while (1) {
        request_init = &scene_request;
        restarted = mail_main_restarted;
        if (restarted != 0) {
            car_speed = game->car_speed_setting;
            text_speed = game->text_speed_setting;
        }
        memset(game, 0, sizeof(action_vars));
        memset(request_init, 0, 0x24);
        if (restarted != 0) {
            game->car_speed_setting = car_speed;
            game->text_speed_setting = text_speed;
        } else {
            game->car_speed_setting = 1;
            game->text_speed_setting = 1;
        }
        request_init->unk0[0] = -1;
        request_init->unk0[1] = -1;
        player_init();
        game->vars[0x5F] = 3;
        game->unkC0 = -0x7E80;
        game->unkC2[4] = 0x82;
        game->vars[0xA] = 100;
        game->vars[0xB] = 100;
        game->vars[0xC] = 100;
        game->vars[0xD] = 100;
        game->vars[0x1B] = 100;
        game->vars[0x3E] = 5;
        game->vars[0x3F] = 0;
        game->vars[0x30] = 0;
        game->drain_minute = 0;
        game->drain_count = 0;
        effect_clear_alarms();
        request = &scene_request;
        vehicle_train_init_state();
        sprite_title_run(mail_main_restarted);
        kaj_srand_ticks();
        sprite_set_visible(0x400, 1);
        sprite_set_visible(0x409, 1);
        event_draw_hud();
        while (request->unk0[4] == 0) {
            if (request->unk0[0] != request->unk0[1]) {
                request->unk0[0] = request->unk0[1];
            }
            switch (request->unk0[0]) {
            case 1:
                block_building_main();
                break;
            case 0:
                object_room_run();
                break;
            case 2:
                thing_game_loop();
                break;
            }
        }
        request->unk0[4] = 0;
        sprite_set_visible(0x400, 0);
        sprite_set_visible(0x409, 0);
        if (mail_main_restarted == 0) {
            mail_main_restarted = 1;
        }
    }
}

s32 mail_angle_to_dir8(s16 angle) {
    s32 b;

loop:
    if (angle < 0) angle += 360;
    if (angle >= 360) angle -= 360;
    if ((u16)angle >= 360) goto loop;
    b = angle;
    if (b >= 23 && b < 68) return 1;
    if (b >= 68 && b < 113) return 0;
    if (b >= 113 && b < 158) return 7;
    if (b >= 158 && b < 203) return 6;
    if (b >= 203 && b < 248) return 5;
    if (b >= 248 && b < 293) return 4;
    if (b >= 293 && b < 338) return 3;
    return 2;
}

s32 mail_take_scene_change(void) {
    SceneRequest *p = &scene_request;
    if (p->change == 0) {
        return 0;
    }
    p->change = 0;
    kaj_pad_reset(0);
    return 1;
}

void mail_wait(s32 mode, s32 arg1, s32 arg2, s32 seconds) {
    s32 buf[6];
    s32 frames;
    for (frames = seconds * 30; frames > 0;) {
            switch (kaj_event_get(buf)) {
            case 2:
                event_handle_alarm(buf);
                continue;
            case 4:
                event_handle_tick(0);
                continue;
            case 0x200:
                event_handle_mod_finish(buf);
                continue;
            case 0:
                frames -= kaj_system.vsync_delta;
                break;
            case 0x100:
                event_handle_effect_done(buf);
                continue;
            default:
                kaj_event_done(buf);
                continue;
            }
            if ((u16)mode == 3) {
                thing_update_all();
                roadmap_draw_frame(3);
            } else {
                do { mail_step_frame(mode, arg1, arg2); } while (0);
            }
    }
}

void mail_step_frame(u16 mode, s16 b, s16 c) {
    GameVars *game = &action_vars;
    action_update();
    if (mode < 2) {
        npc_update_all();
        door_update_all();
        mod_npcrec_update_all();
    } else if (mode == 2) {
        vehicle_update();
    }
    mod_update_all();
    thing_update_all();
    player_update(mode, b, c);
    if ((u16)(mode - 1) < 2) {
        if (game->unk252 != 0) {
            effect_flame_small_update();
        }
        if (game->unk254 != 0) {
            effect_clut_cycle_update();
        }
        if (game->unk250 != 0) {
            effect_flame_large_update();
        }
    }
    roadmap_draw_frame(mode);
}

void mail_goto_ofc(s16 a, s16 yaw, s16 c, s16 d) {
    SceneRequest *request = &scene_request;
    PlayerStatus *status = &player_status;
    GameVars *game = &action_vars;
    request->yaw = yaw;
    ((s16 *)&request->pos_x)[0] = c;
    ((s16 *)&request->pos_x)[1] = d;
    request->unk0[1] = 0;
    request->change = 1;
    request->path = "\\S\\OFC.S;1";
    request->unk0[3] = 0;
    request->unk0[2] = 0;
    request->unk10 = a;
    if (d == 2) {
        return;
    }
    if ((s16)game->vars[0x30] != 0 || status->mutant != 0) {
        return;
    }
    switch (status->unk30) {
    case 0:
        if (status->unk2E >= 3) {
            request->unk0[3] = 1;
            status->unk30 = 1;
            status->unk2E = 0;
        }
        break;
    case 1:
        if (status->unk2E >= 5 && (s16)game->vars[0x11] != 100) {
            game->vars[0x11] = 100;
            request->unk0[3] = 1;
            status->unk30 = 2;
            status->unk2E = 0;
        }
        break;
    }
}

void mail_goto_twn(s32 x, s32 y, s32 z, s16 yaw, s16 e) {
    SceneRequest *request = &scene_request;
    request->change = 1;
    request->unk0[1] = 2;
    request->unk0[3] = 0;
    request->unk0[2] = 1;
    request->path = "\\S\\TWN.S;1";
    request->pos_x = x;
    request->pos_y = y;
    request->pos_z = z;
    request->yaw = yaw;
    request->unk10 = e;
}

void mail_goto_building(u16 arg0, char *name, s16 var, s16 arg3, u16 arg4, u16 arg5, u16 arg6, u32 arg7, u16 arg8) {
    Unk_8018C554 *request = (Unk_8018C554 *)&scene_request;
    GameVars *game = &action_vars;

    request->unkA = 1;
    switch ((s16)game->vars[var]) {
    case 0:
        request->unk0[3] = 0;
        break;
    case 10:
        request->unk0[3] = 2;
        break;
    case 1000:
        request->unk0[3] = 3;
        break;
    case 2000:
        request->unk0[3] = 4;
        break;
    default:
        request->unk0[3] = 1;
        break;
    }
    request->unk0[1] = 1;
    request->unkC = NULL;
    request->unk0[2] = arg6;
    memset(request->unk20, 0, 4);
    strncpy(request->unk20, name, 3);
    request->unk16 = arg3;
    request->unk18 = arg4;
    request->unk1A = arg5;
    request->unk14 = 0;
    request->unk1C = arg8;
    if (var != 13 && (u16)(var - 11) < 16 && (u32)(*(game->vars + var) - 11) < 90) {
        request->unk14 = 1;
    }
    if (arg0 == 1) {
        switch ((arg7 >> 16) & 0xFF) {
        case 0xF6:
            request->unk10 = 1;
            request->unk12 = arg7 & 0xFF;
            break;
        case 0xF9:
            request->unk10 = 2;
            request->unk12 = arg7 & 0xFF;
            break;
        default:
            request->unk10 = 0;
            request->unk12 = (s8)(arg7 >> 8);
            break;
        }
    } else {
        request->unk10 = ((arg7 & 0xFF00) >> 8) + 2;
        request->unk12 = arg7 & 0xFF;
    }
}

s16 mail_wrap_angle(s16 angle) {
    do {
        if (angle < 0) angle += 360;
        if (angle >= 360) angle -= 360;
    } while ((u16)angle >= 360);
    return angle;
}

s32 mail_angle_to_dir4(s16 angle) {
    s32 b;

loop:
    if (angle < 0) angle += 360;
    if (angle >= 360) angle -= 360;
    if ((u16)angle >= 360) goto loop;
    b = angle;
    if (b >= 45 && b < 135) return 0;
    if (b >= 135 && b < 225) return 6;
    if (b >= 225 && b < 315) return 4;
    return 2;
}

s32 mail_exp_for_level(s32 level) {
    s32 i;
    s32 exp;
    if (level == 1) return 0;
    if (level == 2) return 0x144;
    exp = 0x144;
    for (i = 3; i <= level; i++) {
        exp += 0x195 + (i - 3) * 0xA2;
    }
    return exp;
}

void mail_menu_draw_item_name(s32 sprite_id, s32 y, s32 item_id) {
    s16 rect[4];
    u16 buf[0x20];
    Unk_8018C864 *sprite;
    ItemRecord *item;
    u16 *dst;
    u16 *glyph;
    s32 i;
    s32 t;
    s32 line;
    s32 len;
    s32 x;

    sprite = (Unk_8018C864 *)sprite_find(sprite_id);
    item = effect_item_find(item_id);
    if (sprite == NULL || item == NULL) {
        return;
    }
    x = sprite->unk1C->unk0;
    y += sprite->unk1C->unk2;
    rect[2] = 2;
    rect[3] = 15;
    rect[0] = x;
    rect[1] = y;
    len = strlen((char *)item->name);
    for (i = 0; i < 24; i += 2) {
        dst = buf;
        if (i < len) {
            glyph = Krom2RawAdd2((item->name[i] << 8) | item->name[i + 1]);
            for (line = 0; line < 15; line++, glyph++) {
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 4;
                    v = 0;
                    k = 7;
                    sh = 0;
                    do {
                        c1 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    dst[0] = v;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 0;
                    v = 0;
                    k = 3;
                    sh = 0;
                    do {
                        c1 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    t = dst[0];
                    t |= (u16)(v << 8);
                    dst[0] = t;
                    dst++;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 12;
                    v = 0;
                    k = 15;
                    sh = 0;
                    do {
                        c1 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    dst[0] = v;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 8;
                    v = 0;
                    k = 11;
                    sh = 0;
                    do {
                        c1 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    t = dst[0];
                    t |= (u16)(v << 8);
                    dst[0] = t;
                    dst++;
                }
            }
        } else {
            memset(dst, 0xEE, 0x40);
        }
        LoadImage2(rect, buf);
        rect[0] += 2;
    }
}

void mail_menu_draw(MailMenu *menu, s32 draw_icons) {
    s32 i;
    s16 start;
    s16 end;
    s32 line;
    u16 col;
    u16 row;

    sprite_fill_clut(menu->sprite, menu->first_entry, menu->first_entry + menu->rows - 1, menu->color);
    sprite_set_clut_entry(menu->sprite, menu->cursor_entry, (u16)menu->cursor_color);
    start = menu->scroll;
    if (menu->rows < menu->count) {
        end = start + menu->rows;
    } else {
        end = start + menu->count;
    }
    if ((s16)draw_icons != 0 && menu->draw_rows != 0) {
        for (i = start, line = 0; i < end; i++, line++) {
            if (menu->icon_sprite >= 0) {
                if (menu->list == NULL) {
                    col = i / menu->icon_rows;
                    row = i % menu->icon_rows;
                } else {
                    col = menu->list[i] / menu->icon_rows;
                    row = menu->list[i] % menu->icon_rows;
                }
                sprite_copy_cell((u16)menu->icon_sprite, col, row, menu->sprite, 0x10, (u16)(line * 0x11 + 0xC));
            } else if (menu->icon_sprite == -2) {
                mail_menu_draw_item_name((s16)menu->sprite, line * 0x11 + 0xC, menu->list[i]);
            }
        }
    }
}

void mail_menu_clear_rows(MailMenu *menu) {
    s16 rect[4];
    Unk_8018CD4C *sprite;
    Unk_8018CD4C *icons;
    u8 *buf;
    s32 size;
    s32 i;

    sprite = (Unk_8018CD4C *)sprite_find(menu->sprite);
    icons = (Unk_8018CD4C *)sprite_find(menu->icon_sprite);
    if (sprite != NULL) {
        rect[0] = sprite->unk1C->unk0;
        rect[1] = sprite->unk1C->unk2 + 0xC;
        rect[2] = 0x18;
        rect[3] = 0x10;
        if (icons != NULL) {
            rect[0] = sprite->unk1C->unk0 + (0x10 >> sprite->unk1C->unk14);
            rect[1] = sprite->unk1C->unk2 + 0xC;
            rect[2] = icons->unk10 >> icons->unk1C->unk14;
            rect[3] = icons->unk12;
            menu->icon_rows = icons->unk16;
        }
        size = rect[2] * rect[3] * 2;
        buf = kaj_malloc(size);
        if (buf != NULL) {
            memset(buf, 0xEE, size);
            for (i = 0; i < 6; i++) {
                LoadImage2(rect, buf);
                rect[1] += 0x11;
            }
            free3(buf);
        }
    }
}

s16 mail_menu_move(s16 up) {
    s16 snd = 1;
    s32 scrolled = 0;
    MailMenu *menu = &mail_menu;

    if (up != 0) {
        menu->index--;
        if (menu->wrap != 0) {
            menu->cursor_entry--;
            if (menu->index < 0) {
                menu->index = menu->count - 1;
                menu->cursor_entry = menu->first_entry + menu->index;
            }
        } else {
            if (menu->index < 0) {
                menu->index = 0;
            }
            menu->cursor_entry--;
            if (menu->cursor_entry < menu->first_entry) {
                menu->cursor_entry = menu->first_entry;
                snd = 0;
                if (menu->scroll > 0) {
                    menu->scroll--;
                    scrolled = 1;
                    snd = 1;
                }
            }
        }
    } else {
        menu->index++;
        if (menu->wrap != 0) {
            menu->cursor_entry++;
            if (menu->index >= menu->count) {
                menu->index = 0;
                menu->cursor_entry = menu->first_entry;
            }
        } else {
            if (menu->index >= menu->count) {
                menu->index = menu->count - 1;
            }
            menu->cursor_entry++;
            if (menu->cursor_entry >= menu->first_entry + menu->rows) {
                menu->cursor_entry = menu->first_entry + menu->rows - 1;
                snd = 0;
                if (menu->scroll != menu->index - menu->rows + 1) {
                    menu->scroll = menu->index - menu->rows + 1;
                    scrolled = 1;
                    snd = 1;
                }
            }
        }
    }
    if (snd) {
        sound_se_play(0xF);
    }
    mail_menu_draw(menu, scrolled);
    return menu->index;
}

s32 mail_menu_open(s16 reset, s16 sprite, s16 icon_sprite, s16 count, s16 rows, s16 *list, s16 first_entry, s16 color, s16 cursor_color) {
    GameVars *game = &action_vars;
    MailMenu *menu = &game->mail_menu;
    if (game->mail_menu.state != 0) {
        return 0;
    }
    game->menu_busy = 1;
    game->mail_menu.state = 2;
    if (reset != 0) {
        menu->index = 0;
        menu->cursor_entry = first_entry;
        menu->scroll = 0;
    }
    menu->first_entry = first_entry;
    menu->sprite = sprite;
    menu->icon_sprite = icon_sprite;
    menu->color = color;
    menu->cursor_color = cursor_color;
    menu->wrap = 1;
    if (rows < count) {
        menu->wrap = 0;
    }
    menu->draw_rows = 1;
    if (icon_sprite == -1) {
        menu->draw_rows = 0;
    }
    menu->rows = rows;
    menu->count = count;
    menu->list = list;
    if ((icon_sprite == 0x40C || icon_sprite == 0x402 || icon_sprite == -2) && sprite == 0x40B) {
        mail_menu_clear_rows(menu);
    }
    mail_menu_draw(menu, 1);
    effect_start_sprite_slide(0xB, sprite, 2);
    return 1;
}

s32 mail_menu_close(void) {
    MailMenu *menu = &mail_menu;
    if (menu->state != 1) {
        return 0;
    }
    menu->state = 2;
    effect_start_sprite_slide(0xC, menu->sprite, 2);
    return 1;
}

s16 mail_menu_get_state(void) { return mail_menu.state; }

s32 mail_menu_set_list(u16 sprite, s16 *list) {
    MailMenu *menu = &mail_menu;
    if (menu->state == 2) {
        return 0;
    }
    menu->index = 0;
    menu->scroll = 0;
    menu->list = list;
    menu->cursor_entry = menu->first_entry;
    sprite_set_visible(menu->sprite, 0);
    sprite_set_visible(sprite, 1);
    menu->sprite = sprite;
    mail_menu_draw(menu, 0);
    return 1;
}

s16 mail_menu_get_entry(s16 i) {
    MailMenu *menu = &mail_menu;
    if (i < 0 || menu->count < i) {
        return -1;
    }
    return menu->list[i];
}
