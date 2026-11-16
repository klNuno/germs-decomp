#include "common.h"
#include "game/types.h"

typedef struct { s16 id, code, read, unk6; } MailListEntry;
MailListEntry *mail_list;
extern SceneRequest scene_request;
void kaj_pad_reset(s32 enable);
void mail_receive(u16 id);
extern GameVars action_vars;
extern MailMenu mail_menu;
void effect_start_sprite_slide(s32 kind, u16 sprite_id, s32 seconds);
void sprite_set_visible(s32 id, s32 visible);
void mail_menu_draw(MailMenu *menu, s32 draw_icons);
u16 *mail_scrollbar;
s16 mail_list_top;
s16 mail_list_row;
extern char mail_str_file[];
u16 *sprite_find(u16 id);
void *kaj_malloc(u32 size);
void kaj_abend(s32 code, char *msg, char *file, s32 line);
void mail_list_refresh(GameVars *game, s16 selected);
void sprite_delete(s32 id);
void free3(void *ptr);
typedef struct MailHandlerView { u16 id; s16 list_index; s32 unk4; Sprite *entry_sprite; Sprite *scrollbar; } MailHandlerView;
extern SceneTables object_scene_tables;
u16 mail_entry_saved_y;
u16 mail_scrollbar_saved_y;
void sprite_set_clut_entry(s32 id, s32 index, s32 color);
extern PlayerStatus player_status;
void action_update(void);
void npc_update_all(void);
void door_update_all(void);
void mod_npcrec_update_all(void);
void vehicle_update(void);
void mod_update_all(void);
void thing_update_all(void);
void player_update(u16 mode, s16 stream, s16 visibility);
void effect_flame_small_update(void);
void effect_clut_cycle_update(void);
void effect_flame_large_update(void);
void roadmap_draw_frame(u16 mode);
void mail_menu_clear_rows(MailMenu *menu);
void sound_se_play(s32 id);
extern KajSystem kaj_system;
s32 kaj_event_get(s32 *event);
void kaj_event_done(s32 *event);
void event_handle_alarm(s32 *ev);
void event_handle_tick(s16 daylight);
void event_handle_mod_finish(s32 *ev);
s16 event_handle_effect_done(s32 *ev);
void mail_step_frame(u16 mode, s16 b, s16 c);
void sprite_fill_clut(s32 id, s32 first, s32 last, s32 color);
void sprite_copy_cell(s32 src_id, s32 col, s32 row, s32 dst_id, s32 dst_x, s32 dst_y);
void mail_menu_draw_item_name(s32 sprite_id, s32 y, s32 item_id);
typedef struct { u16 img_x; u16 img_y; u8 unk4[0x10]; s16 u_shift; } MenuTimView;
typedef struct { u8 unk0[0x10]; s16 cell_w; u16 cell_h; s16 columns; u16 rows; s32 unk18; MenuTimView *tim; } MenuSpriteView;
void *memset(void *dst, s32 c, u32 n);
s32 LoadImage2(void *rect, void *p);
void sound_se_play(s32 id);
typedef struct { s16 img_x; s16 img_y; } ItemNameTim;
typedef struct { u8 unk0[0x1C]; ItemNameTim *tim; } ItemNameSprite;
ItemRecord *effect_item_find(s16 id);
s32 strlen(char *s);
u16 *Krom2RawAdd2(u16 sjis);
typedef struct {
    s16 loop;
    s16 next_loop;
    s16 scene_index;
    s16 variant;
    s16 quit;
    s16 change;
    char *path;
    s16 building;
    s16 building_room;
    s16 entry_sound;
    s16 map_letter;
    s16 map_entry;
    s16 yaw;
    s16 script_entry;
    u8 unk1E[2];
    char scene_name[4];
} BuildingRequest;
char *strncpy(char *dst, char *src, u32 n);
typedef struct {
    s16 img_x;
    s16 img_y;
    u16 img_w;
    u16 img_h;
    u8 unk8[0xA];
    u16 v;
} MailPageTim;
typedef struct {
    s16 id;
    s16 mode;
    s16 visible;
    s16 clut_dirty;
    s32 unk8;
    u16 y;
    s16 depth;
    s16 cell_w;
    u16 cell_h;
    s32 unk14;
    s32 unk18;
    MailPageTim *tim;
} MailPageSprite;
typedef struct MailHandler {
    u16 id;
    s16 list_index;
    s16 page_count;
    s16 scroll;
    u16 *entry_sprite;
    u16 *scrollbar;
    MailPageSprite *page0;
    MailPageSprite *page1;
    MailPageSprite *page2;
    MailPageSprite *page3;
} MailHandler;
extern MailHandler *object_scene_mail[];
s16 mail_page_tex_v_0;
s16 mail_page_tex_v_1;
s16 mail_page_tex_v_2;
s16 mail_page_tex_v_3;
s16 mail_page_height_0;
s16 mail_page_height_1;
s16 mail_page_height_2;
s16 mail_page_height_3;
typedef struct {
    u16 id;
    u16 page_count;
    s32 page0_offset;
    s32 page1_offset;
    s32 page2_offset;
    s32 page3_offset;
} MailRecord;
void sprite_create(MailPageSprite **out, void *rec);
void sprite_add(s32 sprite);
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
void kaj_ll_create(void *list);
void event_open(void);
void roadmap_init_draw(void);
void object_load_res(s32 index, s32 progress);
void player_init(void);
void effect_clear_alarms(void);
void vehicle_train_init_state(void);
void sprite_title_run(s32 restarted);
void kaj_srand_ticks(void);
void event_draw_hud(void);
void block_building_main(void);
void object_room_run(void);
void thing_game_loop(void);

void mail_create(MailHandler **out, MailRecord *rec, s16 list_index) {
    *out = kaj_malloc(0x20);
    if (*out == NULL) {
        kaj_abend(3, "Error Allocating MAIL Handler", mail_str_file, 0x3B);
    }
    (*out)->id = rec->id;
    (*out)->list_index = list_index;
    (*out)->page_count = rec->page_count;
    (*out)->scroll = 0;

    sprite_create(&(*out)->page0, (u8 *)rec + rec->page0_offset);
    sprite_add((s32)(*out)->page0);
    (*out)->page0->visible = 1;
    (*out)->page0->y = 0x43;
    (*out)->page0->depth = 1;
    mail_page_tex_v_0 = (*out)->page0->tim->v;
    mail_page_height_0 = (*out)->page0->cell_h;

    if ((*out)->page_count >= 2) {
        sprite_create(&(*out)->page1, (u8 *)rec + rec->page1_offset);
        sprite_add((s32)(*out)->page1);
        (*out)->page1->visible = 0;
        (*out)->page1->y = 0x43;
        (*out)->page1->depth = 1;
        mail_page_tex_v_1 = (*out)->page1->tim->v;
        mail_page_height_1 = (*out)->page1->cell_h;
    }
    if ((*out)->page_count >= 3) {
        sprite_create(&(*out)->page2, (u8 *)rec + rec->page2_offset);
        sprite_add((s32)(*out)->page2);
        (*out)->page2->visible = 0;
        (*out)->page2->y = 0x43;
        (*out)->page2->depth = 1;
        mail_page_tex_v_2 = (*out)->page2->tim->v;
        mail_page_height_2 = (*out)->page2->cell_h;
    }
    if ((*out)->page_count >= 4) {
        sprite_create(&(*out)->page3, (u8 *)rec + rec->page3_offset);
        sprite_add((s32)(*out)->page3);
        (*out)->page3->visible = 0;
        (*out)->page3->y = 0x43;
        (*out)->page3->depth = 1;
        mail_page_tex_v_3 = (*out)->page3->tim->v;
        mail_page_height_3 = (*out)->page3->cell_h;
    }

    (*out)->entry_sprite = sprite_find((*out)->id + 0x217);
    if ((*out)->entry_sprite != NULL) {
        sprite_set_clut_entry((u16)((*out)->id + 0x217), 7, 0x4D44);
        sprite_set_clut_entry((u16)((*out)->id + 0x217), 9, 0x6358);
        mail_entry_saved_y = (*out)->entry_sprite[6];
        (*out)->entry_sprite[6] = 0x33;
        (*out)->entry_sprite[7] = 1;
    }
    (*out)->scrollbar = sprite_find(0x20C);
    if (mail_scrollbar != NULL) {
        mail_scrollbar_saved_y = mail_scrollbar[6];
    }
    if ((*out)->scrollbar != NULL) {
        (*out)->scrollbar[6] = 0x29;
    }
}

void mail_scroll(s16 forward) {
    MailHandler *mail = object_scene_mail[0];
    s32 offset;
    s32 last_page;
    s32 max;

    if (mail == NULL || mail->page_count < 2) {
        return;
    }
    offset = mail->scroll;
    if (forward != 0) {
        offset++;
    } else {
        offset--;
    }
    last_page = mail->page_count - 1;
    max = last_page << 7;
    if (max < offset) {
        offset = max;
    }
    if (offset < 0) {
        offset = 0;
    }
    if (mail->scrollbar != NULL) {
        mail->scrollbar[6] = ((offset * 114 / last_page) >> 7) + 41;
    }
    if (offset == 0) {
        mail->page0->visible = 1;
        mail->page0->y = 0x43;
        mail->page0->cell_h = mail_page_height_0;
        mail->page0->tim->v = mail_page_tex_v_0;
        mail->page1->visible = 0;
        if (mail->page2 != NULL) {
            mail->page2->visible = 0;
        }
        if (mail->page3 != NULL) {
            mail->page3->visible = 0;
        }
    } else if (offset > 0 && offset < 128) {
        mail->page0->visible = 1;
        mail->page0->cell_h = mail_page_height_0 - offset;
        mail->page0->tim->v = mail_page_tex_v_0 + offset;
        mail->page1->visible = 1;
        mail->page1->y = mail->page0->y + mail->page0->cell_h - 1;
        mail->page1->cell_h = offset;
        if (mail->page2 != NULL) {
            mail->page2->visible = 0;
        }
        if (mail->page3 != NULL) {
            mail->page3->visible = 0;
        }
    } else if (offset == 128) {
        mail->page0->visible = 0;
        mail->page1->visible = 1;
        mail->page1->y = 0x43;
        mail->page1->cell_h = mail_page_height_1;
        mail->page1->tim->v = mail_page_tex_v_1;
        if (mail->page2 != NULL) {
            mail->page2->visible = 0;
        }
        if (mail->page3 != NULL) {
            mail->page3->visible = 0;
        }
    } else if (offset > 128 && offset < 256) {
        mail->page0->visible = 0;
        mail->page1->visible = 1;
        mail->page1->cell_h = mail_page_height_1 + 128 - offset;
        mail->page1->tim->v = mail_page_tex_v_1 - 128 + offset;
        mail->page2->visible = 1;
        mail->page2->y = mail->page1->y + mail->page1->cell_h - 1;
        mail->page2->cell_h = offset - 128;
        if (mail->page3 != NULL) {
            mail->page3->visible = 0;
        }
    } else if (offset == 256) {
        mail->page0->visible = 0;
        mail->page1->visible = 0;
        mail->page2->visible = 1;
        mail->page2->y = 0x43;
        mail->page2->cell_h = mail_page_height_2;
        mail->page2->tim->v = mail_page_tex_v_2;
    } else if (offset > 256 && offset < 384) {
        mail->page0->visible = 0;
        mail->page1->visible = 0;
        mail->page2->visible = 1;
        mail->page2->cell_h = mail_page_height_2 + 256 - offset;
        mail->page2->tim->v = mail_page_tex_v_2 - 256 + offset;
        mail->page3->visible = 1;
        mail->page3->y = mail->page2->y + mail->page2->cell_h - 1;
        mail->page3->cell_h = offset - 256;
    } else if (offset == 384) {
        mail->page0->visible = 0;
        mail->page1->visible = 0;
        mail->page2->visible = 0;
        mail->page3->visible = 1;
        mail->page3->y = 0x43;
        mail->page3->cell_h = mail_page_height_3;
        mail->page3->tim->v = mail_page_tex_v_3;
    }
    mail->scroll = offset;
}

void mail_list_refresh(GameVars *game, s16 selected) {
    s32 i;
    s32 row;
    u16 *sprite;
    MailListEntry *entry;

    row = 0;
    entry = mail_list;
    for (i = 0; i < (s16)game->vars[0x5F]; i++, entry++) {
        sprite = sprite_find(entry->id + 0x217);
        if (sprite != NULL) {
            if (i >= mail_list_top && i < mail_list_top + 9) {
                sprite[2] = 1;
                sprite[5] = 0x30;
                sprite[6] = row * 16 + 0x33;
                row++;
                if (i == selected) {
                    sprite_set_clut_entry((u16)(entry->id + 0x217), 9, 0x1F);
                } else {
                    sprite_set_clut_entry((u16)(entry->id + 0x217), 9, 0x6358);
                }
                if (entry->read != 0) {
                    sprite_set_clut_entry((u16)(entry->id + 0x217), 7, 0x2C1F);
                } else {
                    sprite_set_clut_entry((u16)(entry->id + 0x217), 7, 0x4D44);
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
    MailListEntry *entry;
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
                entry->id = id;
                entry->code = code;
                entry->read = (code & 0x40) >> 6;
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
    MailListEntry *entry;
    GameVars *game = &action_vars;
    if ((s16)game->vars[0x5F] != 0) {
        if (mail_scrollbar != NULL) {
            mail_scrollbar[6] = 0x29;
            mail_scrollbar = NULL;
        }
        entry = mail_list;
        for (i = 0; i < (s16)game->vars[0x5F]; i++, entry++) {
            code = 0x80;
            if (entry->read != 0) {
                code = 0xC0;
            }
            code += i & 0x3F;
            word = entry->id / 2 + 0x60;
            if (entry->id % 2) {
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
    MailHandlerView *mail = tables->mail;
    if (mail != NULL) {
        mail_list[mail->list_index].read = 1;
        if (mail->entry_sprite != NULL) {
            sprite_set_clut_entry((u16)(mail->id + 0x217), 7, 0x2C1F);
            sprite_set_clut_entry((u16)(mail->id + 0x217), 9, 0x1F);
            mail->entry_sprite->y = mail_entry_saved_y;
            mail->entry_sprite->depth = 2;
        }
        if (mail->scrollbar != NULL) {
            mail->scrollbar->y = mail_scrollbar_saved_y;
        }
        sprite_delete(0x213);
        sprite_delete(0x214);
        sprite_delete(0x215);
        sprite_delete(0x216);
        free3(mail);
        tables->mail = NULL;
    }
}

s16 mail_list_get_id(s16 i) { return mail_list[i].id; }

void mail_cmd_receive(Action *action) {
    mail_receive(((ActionCmdShort *)action->cmd)->target);
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
        request_init->loop = -1;
        request_init->next_loop = -1;
        player_init();
        game->vars[0x5F] = 3;
        game->mail_codes[0] = -0x7E80;
        game->mail_codes[5] = 0x82;
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
        while (request->quit == 0) {
            if (request->loop != request->next_loop) {
                request->loop = request->next_loop;
            }
            switch (request->loop) {
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
        request->quit = 0;
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

void mail_wait(s32 mode, s32 stream, s32 visibility, s32 seconds) {
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
                do { mail_step_frame(mode, stream, visibility); } while (0);
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
        if (game->flame_small_on != 0) {
            effect_flame_small_update();
        }
        if (game->clut_cycle_on != 0) {
            effect_clut_cycle_update();
        }
        if (game->flame_large_on != 0) {
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
    request->next_loop = 0;
    request->change = 1;
    request->path = "\\S\\OFC.S;1";
    request->variant = 0;
    request->scene_index = 0;
    request->loop_param = a;
    if (d == 2) {
        return;
    }
    if ((s16)game->vars[0x30] != 0 || status->mutant != 0) {
        return;
    }
    switch (status->arrests) {
    case 0:
        if (status->kills_since_arrest >= 3) {
            request->variant = 1;
            status->arrests = 1;
            status->kills_since_arrest = 0;
        }
        break;
    case 1:
        if (status->kills_since_arrest >= 5 && (s16)game->vars[0x11] != 100) {
            game->vars[0x11] = 100;
            request->variant = 1;
            status->arrests = 2;
            status->kills_since_arrest = 0;
        }
        break;
    }
}

void mail_goto_twn(s32 x, s32 y, s32 z, s16 yaw, s16 e) {
    SceneRequest *request = &scene_request;
    request->change = 1;
    request->next_loop = 2;
    request->variant = 0;
    request->scene_index = 1;
    request->path = "\\S\\TWN.S;1";
    request->pos_x = x;
    request->pos_y = y;
    request->pos_z = z;
    request->yaw = yaw;
    request->loop_param = e;
}

void mail_goto_building(u16 form, char *name, s16 var, s16 map_letter, u16 map_entry, u16 yaw, u16 scene_index, u32 trigger, u16 script_entry) {
    BuildingRequest *request = (BuildingRequest *)&scene_request;
    GameVars *game = &action_vars;

    request->change = 1;
    switch ((s16)game->vars[var]) {
    case 0:
        request->variant = 0;
        break;
    case 10:
        request->variant = 2;
        break;
    case 1000:
        request->variant = 3;
        break;
    case 2000:
        request->variant = 4;
        break;
    default:
        request->variant = 1;
        break;
    }
    request->next_loop = 1;
    request->path = NULL;
    request->scene_index = scene_index;
    memset(request->scene_name, 0, 4);
    strncpy(request->scene_name, name, 3);
    request->map_letter = map_letter;
    request->map_entry = map_entry;
    request->yaw = yaw;
    request->entry_sound = 0;
    request->script_entry = script_entry;
    if (var != 13 && (u16)(var - 11) < 16 && (u32)(*(game->vars + var) - 11) < 90) {
        request->entry_sound = 1;
    }
    if (form == 1) {
        switch ((trigger >> 16) & 0xFF) {
        case 0xF6:
            request->building = 1;
            request->building_room = trigger & 0xFF;
            break;
        case 0xF9:
            request->building = 2;
            request->building_room = trigger & 0xFF;
            break;
        default:
            request->building = 0;
            request->building_room = (s8)(trigger >> 8);
            break;
        }
    } else {
        request->building = ((trigger & 0xFF00) >> 8) + 2;
        request->building_room = trigger & 0xFF;
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
    ItemNameSprite *sprite;
    ItemRecord *item;
    u16 *dst;
    u16 *glyph;
    s32 i;
    s32 t;
    s32 line;
    s32 len;
    s32 x;

    sprite = (ItemNameSprite *)sprite_find(sprite_id);
    item = effect_item_find(item_id);
    if (sprite == NULL || item == NULL) {
        return;
    }
    x = sprite->tim->img_x;
    y += sprite->tim->img_y;
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
    MenuSpriteView *sprite;
    MenuSpriteView *icons;
    u8 *buf;
    s32 size;
    s32 i;

    sprite = (MenuSpriteView *)sprite_find(menu->sprite);
    icons = (MenuSpriteView *)sprite_find(menu->icon_sprite);
    if (sprite != NULL) {
        rect[0] = sprite->tim->img_x;
        rect[1] = sprite->tim->img_y + 0xC;
        rect[2] = 0x18;
        rect[3] = 0x10;
        if (icons != NULL) {
            rect[0] = sprite->tim->img_x + (0x10 >> sprite->tim->u_shift);
            rect[1] = sprite->tim->img_y + 0xC;
            rect[2] = icons->cell_w >> icons->tim->u_shift;
            rect[3] = icons->cell_h;
            menu->icon_rows = icons->rows;
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
