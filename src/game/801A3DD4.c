#include "common.h"
#include "game/types.h"

void kaj_tim_free(s32 arg0);
void free3(void *ptr);
typedef struct Unk_801A44B8 {
    s32 unk0;
    struct Unk_801A44B8 *next;
    u16 *data;
} Unk_801A44B8;
typedef struct {
    Unk_801A44B8 *head;
    Unk_801A44B8 *tail;
    Unk_801A44B8 *cursor;
    s32 count;
} Unk_801DFF80;
void kaj_ll_insert_before(Unk_801DFF80 *arg0, s32 arg1);
void kaj_ll_insert_after(Unk_801DFF80 *arg0, s32 arg1);
Unk_801DFF80 *sprite_list;
s16 kaj_ll_at_tail(Unk_801DFF80 *arg0);
typedef struct {
    u8 unk0[0x10];
    s32 unk10;
} Unk_801A533C;
void sprite_title_show_menu(s16 arg0);
typedef struct {
    u8 unk0[0xC];
    s32 unkC;
} Unk_801A5DA0;
void sprite_station_show_prompt(s16 arg0);
extern TrainState vehicle_train_state;
extern Player *player_status_player[];
typedef struct {
    u8 unk0[0xC];
    s32 unkC;
} Unk_801A6968;
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
typedef struct {
    u8 unk0[0xC];
    s32 unkC;
} Unk_801A69E0;
void sound_se_stop(s32 arg0);
void effect_start_sprite_anim(s32 arg0, s32 arg1);
extern char D_8017196C[];
s16 sprite_phone_save;
void sprite_phone_loop(void);
s16 menu_card_run(s32 arg0, s32 arg1);
void sprite_set_visible(s32 arg0, s32 arg1);
u16 *sprite_find(u16 arg0);
void kaj_ll_remove_to_prev(Unk_801DFF80 *arg0);
void sprite_delete(s32 arg0);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    u16 unk6;
    u8 unk8[0x4];
    s16 unkC;
    u8 unkE[0x6];
    s16 unk14;
    u8 unk16[0x6];
    u16 *unk1C;
    u16 *unk20;
} Unk_801A461C;
void sprite_set_color(s32 arg0, s32 arg1);
void sprite_set_cell(s32 arg0, s32 arg1, s32 arg2);
void mail_wait(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void text_close(void);
void thing_set_active(s32 arg0, s32 arg1, s32 arg2);
s16 sprite_title_choice;
s16 sprite_title_menu_active;
s16 sprite_title_cursor_frame;
s16 sprite_title_cursor_moving;
extern BuildingState block_building_state;
extern u16 D_801E03E6[];
void vehicle_train_arrive(s16 arg0, s16 arg1);
void vehicle_train_set_doors(s32 arg0);
s32 sprite_station_on_leave(Unk_801A5DA0 *arg0);
void thing_set_flag10(s32 a, s32 b, s32 c);
void vehicle_train_place(void);
void sprite_station_copy_signs(TrainState *arg0, BuildingState *arg1);
s32 sprite_station_on_enter(Unk_801A5DA0 *arg0);
void sprite_station_update(void);
extern s32 (*D_801DFEE4)();
extern s32 (*D_801DFEE0)(Unk_801A5DA0 *arg0);
extern void (*D_801DFEDC)(void);
extern s32 sprite_station_exit_points[];
extern s32 sprite_str_scene_gst[];
void mail_goto_twn(s32 a, s32 b, s32 c, s16 d, s16 e);
void mail_goto_building(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
extern u16 D_801E1126[];
extern SceneTables object_scene_tables;
extern s32 D_801DFED4;
s16 sprite_title_load;
void sprite_title_loop(s16 arg0);
void thing_free_all(void);
void sound_se_stop_all(void);
void sound_se_pop(void);
extern char D_8017186C[];
typedef struct {
    u8 unk0[0xC];
    s32 unkC;
    s32 unk10;
} Unk_801A6A1C;
extern GameVars action_vars;
void sprite_set_clut_entry(u16 arg0, s32 arg1, u16 arg2);
void sprite_fill_clut(u16 arg0, s32 arg1, s32 arg2, u16 arg3);
s16 sprite_phone_menu_state;
s16 sprite_phone_menu_cursor;
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
void kaj_tim_load(void *arg0, void *arg1, u16 arg2, s16 arg3);
s32 MoveImage(Rect *rect, s32 x, s32 y);
extern KajSystem kaj_system;
extern SceneRequest scene_request[];
s32 kaj_pad_read(void);
void mail_goto_ofc(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void sound_se_play(s32 arg0);
s32 sprite_title_on_effect_done(Unk_801A533C *arg0);
void player_place_for_scene(s32 arg0);
void object_load_res(s32 arg0, s32 arg1);
void thing_set_animate(s32 a, s32 b, s32 c);
Thing *thing_find(s32 arg0, s32 arg1);
extern char D_80171820[];
s32 MoveImage2(Rect *rect, s32 x, s32 y);
Unk_801DFF80 *D_801DFFA0;
void RotMatrix(SVector *arg0, void *arg1);
s32 block_find_at(s32 a0, s32 a1, s32 a2);
NpcBody *npc_find_body(s16 arg0);
extern s32 D_801E6DB4[];
typedef struct {
    u8 unk0[0x6];
    s16 unk6;
    u8 unk8[0x18];
    s32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    s32 unk2C;
    u8 unk30[0x14];
    s32 unk44;
    s32 unk48;
    s32 unk4C;
} Unk_801A742C;
typedef struct {
    u8 unk0[0x14];
    s16 unk14;
    u8 unk16[0xA];
    s32 unk20;
    s32 unk24;
    s32 unk28;
} Unk_801A727C;
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} Unk_801A417C_0;
typedef struct {
    Unk_801A417C_0 *unk0;
    s32 unk4;
    char **unk8;
} Unk_801A417C;
s32 atoi(char *s);
s32 LoadImage(void *rect, u32 *p);
void sprite_title_handle_input(void);
void sprite_title_init(s16 arg0);
void kaj_timer_enable(void);
void kaj_timer_disable(void);
void effect_start_fade(s32 arg0, s32 arg1);
void kaj_pad_reset(s32 a);
s32 kaj_event_get(s32 *arg0);
s16 event_handle_effect_done(s32 *arg0);
void kaj_event_done(s32 *arg0);
s32 mail_take_scene_change(void);
void text_start_narration(s32 arg0);
void thing_update_all(void);
void roadmap_draw_frame(u16 a);
extern s32 D_801E0334[];
typedef struct {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 unkA[0x2];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    u8 unk1E[0x2];
    s32 unk20;
    s32 unk24;
} Unk_801A6C34;
void GsInitCoordinate2(void *super, void *base);
void kaj_tmd_load(void *arg0, void *arg1, void *arg2);
extern EventState event_state;
void action_reset(s16 arg0);
void sprite_phone_pick_trigger(s32 *arg0);
s32 sprite_phone_on_enter(Unk_801A6968 *arg0);
void sprite_phone_on_alarm(Unk_801A69E0 *arg0);
s32 sprite_phone_on_effect_done(Unk_801A6A1C *arg0);
extern s32 D_801DFF50;
extern s32 D_801DFED8;
extern PlayerStatus player_status;
extern ScreenLight screen_light;
extern s16 D_801E05B4[];
Model *mod_find(u16 arg0);
void mod_setup(Model *arg0, s32 arg1, s32 arg2, s32 arg3);
void mod_set_anim(void *arg0, s16 arg1, s16 arg2);
void player_reset_triggers(s16 arg0);
void effect_start_alarm(s32 arg0, s32 arg1, s32 arg2);
void func_80189928(s32 *arg0);
void event_handle_enter(s32 *arg0);
void event_handle_tick(s16 arg0);
void mail_step_frame(u16 arg0, s16 arg1, s16 arg2);
void effect_clear_alarms(void);
void block_free_owned(void);
void mod_free_all(void);
void sprite_phone_update(void);
/* " 7クルマ2を移動しておきます,,     決定 3○ 2やめる 4×" */
extern char D_80171900[];
/* " 2すぐそちらに向かいます,,     決定 3○ 2やめる 4×" */
extern char D_80171938[];
s32 rsin(s32 a);
s32 rcos(s32 a);

void sprite_create(Sprite **out, SpriteRecord *rec) {
    Unk_801A461C *tim;
    s16 h;

    *out = kaj_malloc(0x20);
    if (*out == NULL) {
        kaj_abend(3, "Error Allocating SPRITE Pointer", "sprite.c", 0x22);
    }
    (*out)->id = rec->id;
    (*out)->mode = rec->mode;
    (*out)->x = rec->x;
    (*out)->y = rec->y;
    (*out)->depth = rec->depth;
    (*out)->columns = rec->columns;
    (*out)->rows = rec->rows;
    (*out)->visible = 0;
    (*out)->clut_dirty = 0;
    (*out)->color = 0;
    (*out)->cell_col = 0;
    (*out)->cell_row = 0;
    kaj_tim_load(&(*out)->tim, rec->unk14, rec->mode, rec->unk12);
    tim = (Unk_801A461C *)(*out)->tim;
    h = tim->unk6;
    (*out)->cell_w = (s16)(tim->unk4 << tim->unk14) / (*out)->columns;
    (*out)->cell_h = h / (*out)->rows;
}

void sprite_copy_cell(u16 src_id, s16 col, u16 row, u16 dst_id, u16 dst_x, u16 dst_y) {
    Unk_801DFF80 *list;
    u16 *src;
    u16 *dst;
    u16 *item;
    Unk_801A461C *src_tim;
    Unk_801A461C *dst_tim;
    Rect rect;
    s16 w;

    list = sprite_list;
    if (list->count == 0) {
        src = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && *item == src_id) {
                src = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                src = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    list = sprite_list;
    if (list->count == 0) {
        dst = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && *item == dst_id) {
                dst = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                dst = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (src != NULL && dst != NULL) {
        src_tim = (Unk_801A461C *)((Sprite *)src)->tim;
        w = ((Sprite *)src)->cell_w >> src_tim->unk14;
        rect.x = src_tim->unk0 + col * w;
        rect.y = ((Unk_801A461C *)((Sprite *)src)->tim)->unk2 + row * (s16)((Sprite *)src)->cell_h;
        rect.w = w;
        rect.h = ((Sprite *)src)->cell_h;
        dst_tim = (Unk_801A461C *)((Sprite *)dst)->tim;
        dst_x >>= dst_tim->unk14;
        MoveImage(&rect, dst_tim->unk0 + dst_x, dst_tim->unk2 + dst_y);
    }
}

void sprite_exec_command(Unk_801A417C *cmd) {
    Unk_801DFF80 *list = sprite_list;
    Unk_801A417C_0 *args = cmd->unk0;
    u16 id = args->unk4;
    u16 *sprite;
    u16 *item;
    Unk_801A461C *tim;
    s32 i;
    s32 end;
    u16 color;
    s32 first;

    if (list->count == 0) {
        sprite = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && *item == id) {
                sprite = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                sprite = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (sprite != NULL) {
        tim = (Unk_801A461C *)((Sprite *)sprite)->tim;
        if (tim->unk1C != NULL && tim->unk20 != NULL) {
            switch (args->unk2) {
            case 2:
                first = atoi(cmd->unk8[0]);
                ((Unk_801A461C *)((Sprite *)sprite)->tim)->unk20[first] = atoi(cmd->unk8[1]);
                break;
            case 3:
                first = atoi(cmd->unk8[0]);
                end = atoi(cmd->unk8[1]);
                color = atoi(cmd->unk8[2]);
                for (i = first; i <= end; i++) {
                    ((Unk_801A461C *)((Sprite *)sprite)->tim)->unk20[i] = color;
                }
                break;
            case 4:
                LoadImage(&tim->unk8, (u32 *)tim->unk1C);
                return;
            default:
                return;
            }
            LoadImage(&((Unk_801A461C *)((Sprite *)sprite)->tim)->unk8, (u32 *)((Unk_801A461C *)((Sprite *)sprite)->tim)->unk20);
        }
    }
}

void sprite_free(Sprite *sprite) {
    if (sprite != NULL) {
        kaj_tim_free(sprite->tim);
        free3(sprite);
    }
}

void sprite_add(s32 sprite) {
    if (sprite_list->count == 0) {
        kaj_ll_insert_before(sprite_list, sprite);
    } else {
        sprite_list->cursor = sprite_list->tail;
        kaj_ll_insert_after(sprite_list, sprite);
    }
}

void sprite_delete(s32 id) {
    Unk_801DFF80 *list = sprite_list;
    u16 *sprite;

    if (list->count == 0) {
        return;
    }
    sprite = sprite_find((u16)id);
    if (sprite == NULL) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        if (sprite == list->cursor->data) {
            if (sprite != NULL) {
                kaj_tim_free(((Sprite *)sprite)->tim);
                free3(sprite);
            }
            kaj_ll_remove_to_prev(list);
            return;
        }
        if (kaj_ll_at_tail(list) != 0) {
            return;
        }
        list->cursor = list->cursor->next;
    }
}

u16 *sprite_find(u16 id) {
    Unk_801DFF80 *list = sprite_list;
    u16 *sprite;

    if (list->count == 0) {
        return NULL;
    }
    list->cursor = list->head;
    while (1) {
        sprite = list->cursor->data;
        if (sprite != NULL && *sprite == id) {
            break;
        }
        if (kaj_ll_at_tail(list) != 0) {
            return NULL;
        }
        list->cursor = list->cursor->next;
    }
    return sprite;
}

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", sprite_draw_all);

void sprite_set_clut_entry(u16 id, s32 index, u16 color) {
    Unk_801DFF80 *list = sprite_list;
    u16 *sprite;
    Unk_801A461C *tim;

    if (list->count == 0) {
        sprite = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            sprite = list->cursor->data;
            if (sprite != NULL && *sprite == id) {
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                sprite = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (sprite != NULL) {
        tim = (Unk_801A461C *)((Sprite *)sprite)->tim;
        if (tim->unk1C != NULL && tim->unk20 != NULL) {
            tim->unk20[index] = color;
            ((Sprite *)sprite)->clut_dirty = 1;
        }
    }
}

void sprite_reset_clut(u16 id) {
    Unk_801DFF80 *list = sprite_list;
    u16 *sprite;
    u16 *item;
    Unk_801A461C *tim;
    s32 i;

    if (list->count == 0) {
        sprite = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && *item == id) {
                sprite = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                sprite = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (sprite != NULL) {
        tim = (Unk_801A461C *)((Sprite *)sprite)->tim;
        if (tim->unk1C != NULL && tim->unk20 != NULL) {
            for (i = 0; i < tim->unkC; i++) {
                tim->unk20[i] = tim->unk1C[i];
                tim = (Unk_801A461C *)((Sprite *)sprite)->tim;
            }
            ((Sprite *)sprite)->clut_dirty = 1;
        }
    }
}

void sprite_fill_clut(u16 id, s32 first, s32 last, u16 color) {
    Unk_801DFF80 *list = sprite_list;
    u16 *sprite;
    u16 *item;
    Unk_801A461C *tim;
    s32 i;

    if (list->count == 0) {
        sprite = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && *item == id) {
                sprite = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                sprite = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (sprite != NULL) {
        tim = (Unk_801A461C *)((Sprite *)sprite)->tim;
        if (tim->unk1C != NULL && tim->unk20 != NULL) {
            for (i = first; i <= last; i++) {
                ((Unk_801A461C *)((Sprite *)sprite)->tim)->unk20[i] = color;
            }
            ((Sprite *)sprite)->clut_dirty = 1;
        }
    }
}

void sprite_restore_clut(u16 id, s32 first, s32 last) {
    Unk_801DFF80 *list = sprite_list;
    u16 *sprite;
    u16 *item;
    Unk_801A461C *tim;
    s32 i;

    if (list->count == 0) {
        sprite = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && *item == id) {
                sprite = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                sprite = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (sprite != NULL) {
        tim = (Unk_801A461C *)((Sprite *)sprite)->tim;
        if (tim->unk1C != NULL && tim->unk20 != NULL) {
            for (i = first; i <= last; i++) {
                ((Unk_801A461C *)((Sprite *)sprite)->tim)->unk20[i] = ((Unk_801A461C *)((Sprite *)sprite)->tim)->unk1C[i];
            }
            ((Sprite *)sprite)->clut_dirty = 1;
        }
    }
}

void sprite_set_visible(s32 id, s32 visible) {
    Unk_801DFF80 *list = sprite_list;
    u16 *sprite;
    u16 *item;

    if (list->count == 0) {
        sprite = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && *item == (u16)id) {
                sprite = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                sprite = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (sprite != NULL) {
        ((Sprite *)sprite)->visible = visible;
    }
}

void sprite_set_color(s32 id, s32 color) {
    Unk_801DFF80 *list = sprite_list;
    u16 *sprite;
    u16 *item;

    if (list->count == 0) {
        sprite = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && *item == (u16)id) {
                sprite = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                sprite = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (sprite != NULL) {
        ((Sprite *)sprite)->color = color;
    }
}

void sprite_set_cell(s32 id, s32 col, s32 row) {
    Unk_801DFF80 *list = sprite_list;
    u16 *sprite;
    u16 *item;

    if (list->count == 0) {
        sprite = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && *item == (u16)id) {
                sprite = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                sprite = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (sprite != NULL) {
        ((Sprite *)sprite)->cell_col = col;
        ((Sprite *)sprite)->cell_row = row;
    }
}

void sprite_title_handle_input(void) {
    SceneRequest *request = scene_request;
    s16 play;
    s32 se_id;

    if (sprite_title_menu_active == 0 || sprite_title_cursor_moving != 0 || kaj_system.pad_mode != 1) {
        return;
    }
    kaj_pad_read();
    play = 0;
    if ((!(kaj_system.pad_prev & 0x800) && (kaj_system.pad_now & 0x800)) ||
        (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20))) {
        play = 1;
        if (sprite_title_choice != 0) {
            se_id = 2;
            mail_goto_ofc(1, 1, 1, 1);
        } else {
            se_id = 0x11;
            sprite_title_load = 1;
            request->change = 1;
        }
    } else if ((!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) ||
               (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000))) {
        if (sprite_title_cursor_moving == 0) {
            play = 1;
            se_id = 1;
            sprite_title_cursor_moving = 1;
            sprite_title_choice = 1 - sprite_title_choice;
        }
    }
    if (play) {
        sound_se_play(se_id);
    }
}

void sprite_title_init(s16 restarted) {
    Thing *thing;
    s32 i;

    if (sprite_title_load == 1) {
        return;
    }
    player_place_for_scene(3);
    if (restarted != 0) {
        object_load_res(0, -1);
    } else {
        object_load_res(0, 0);
    }
    sprite_set_visible(0x40F, 0);
    for (i = 0; i < 2; i++) {
        thing_set_active(3, (u16)i, 1);
        thing_set_animate(3, (u16)i, 1);
        thing_set_flag10(3, (u16)i, 1);
    }
    sprite_title_menu_active = 0;
    if (restarted != 0) {
        D_801DFED4 = (s32)sprite_title_on_effect_done;
        thing = thing_find(3, 10);
        if (thing != NULL) {
            thing->pos_x = 0;
            thing->pos_z = 0x1D4C;
            thing->pos_y = 0;
            thing->active = 0;
            thing->animate = 0;
            thing->block_fixed = 1;
            thing->coord_flg = 0;
            thing->coord_tx = thing->pos_x;
            thing->coord_ty = thing->pos_y;
            thing->coord_tz = thing->pos_z;
        }
    } else {
        text_close();
        sprite_set_visible(0, 1);
        sprite_set_visible(1, 1);
        sprite_set_visible(2, 1);
        sprite_set_cell(1, 0, 0);
        sprite_set_cell(2, 0, 3);
        thing_set_active(3, 10, 0);
        sprite_title_menu_active = 1;
        sprite_title_choice = 1;
        sprite_title_cursor_moving = 0;
        sprite_title_cursor_frame = 0;
    }
    sound_se_play(0);
}

void sprite_title_loop(s16 restarted) {
    s32 buf[6];
    s16 done;
    SceneTables *tables;
    s32 i;

    sprite_title_init(restarted);
    done = 0;
    kaj_timer_enable();
    if (sprite_title_load == 0) {
        effect_start_fade(0, 3);
    } else {
        sprite_title_load = 0;
        kaj_pad_reset(1);
    }
    while (done == 0) {
        switch (kaj_event_get(buf)) {
        case 0:
            sprite_title_handle_input();
            if ((s16)mail_take_scene_change() != 0) {
                if (sprite_title_load == 0) {
                    effect_start_fade(1, 3);
                } else {
                    kaj_pad_reset(0);
                    done = 1;
                }
            }
            break;
        case 0x100:
            done = event_handle_effect_done(buf);
            if (restarted != 0 && buf[4] == 0) {
                thing_set_active(3, 10, 1);
                thing_set_animate(3, 10, 1);
                text_start_narration(D_801E0334[0]);
            }
            continue;
        default:
            kaj_event_done(buf);
            continue;
        }
        if (sprite_title_cursor_moving != 0) {
            if (sprite_title_choice != 0) {
                if (--sprite_title_cursor_frame == 0) {
                    sprite_title_cursor_moving = 0;
                }
            } else {
                if (++sprite_title_cursor_frame == 3) {
                    sprite_title_cursor_moving = 0;
                }
            }
            sprite_set_cell(1, 0, sprite_title_cursor_frame);
            sprite_set_cell(2, 0, (s16)(3 - sprite_title_cursor_frame));
        }
        thing_update_all();
        roadmap_draw_frame(3);
    }
    kaj_timer_disable();
    tables = &object_scene_tables;
    D_801DFED4 = 0;
    if (sprite_title_load != 1) {
        thing_free_all();
        sound_se_stop_all();
        sound_se_pop();
        for (i = 0; i < 3; i++) {
            sprite_delete((u16)i);
        }
        for (i = 0; i < tables->unk34; i++) {
            if (tables->unk5C[i] != NULL) {
                free3(tables->unk5C[i]);
                tables->unk5C[i] = NULL;
            }
        }
        tables->unk34 = 0;
    }
}

void sprite_title_run(s32 restarted) {
    SceneTables *tables;
    s32 i;

    sprite_title_load = 0;
loop:
    sprite_title_loop(restarted);
    if (sprite_title_load != 1) {
        return;
    }
    if (menu_card_run(1, 0) == 0) {
        goto loop;
    }
    sprite_title_load = 0;
    D_801DFED4 = 0;
    tables = &object_scene_tables;
    thing_free_all();
    sound_se_stop_all();
    sound_se_pop();
    for (i = 0; i < 3; i++) {
        sprite_delete((u16)i);
    }
    for (i = 0; i < tables->unk34; i++) {
        if (tables->unk5C[i] != NULL) {
            free3(tables->unk5C[i]);
            tables->unk5C[i] = NULL;
        }
    }
    tables->unk34 = 0;
}

s32 sprite_title_on_effect_done(Unk_801A533C *ev) {
    if (ev->unk10 == 8) {
        sprite_title_show_menu(1);
    }
    return 0;
}

void sprite_title_show_menu(s16 wait) {
    if (wait != 0) {
        mail_wait(3, 0, 0, 2);
    }
    text_close();
    sprite_set_visible(0, 1);
    sprite_set_visible(1, 1);
    sprite_set_visible(2, 1);
    sprite_set_cell(1, 0, 0);
    sprite_set_cell(2, 0, 3);
    thing_set_active(3, 10, 0);
    sprite_title_menu_active = 1;
    sprite_title_choice = 1;
    sprite_title_cursor_moving = 0;
    sprite_title_cursor_frame = 0;
}

s32 sprite_station_on_enter(Unk_801A5DA0 *ev) {
    BuildingState *bstate = &block_building_state;
    TrainState *train = &vehicle_train_state;

    switch (ev->unkC) {
    case 0x100010:
    case 0x100020:
        train->trigger = ev->unkC;
        if (train->door_state == 1) {
            sprite_station_show_prompt(1);
        }
        break;
    case 0xF00110:
        if (bstate->building == 1) {
            if (bstate->unk2 == 3) {
                text_show(D_80171820, 1, -1, 0, -1, 0, 1);
            }
        } else if (bstate->building == 2) {
            if (bstate->unk2 == 6) {
                text_show(D_80171820, 1, -1, 0, -1, 0, 1);
            }
        }
        break;
    case 0xF00120:
        if (bstate->unk2 == 1) {
            text_show(D_80171820, 1, -1, 0, -1, 0, 1);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void sprite_station_update(void) {
    BuildingState *bstate = &block_building_state;
    TrainState *train = &vehicle_train_state;
    s16 minute_digit = (s16)D_801E03E6[0] % 10;

    if (minute_digit == train->unk18) {
        vehicle_train_arrive(1, bstate->unk2);
    } else if (minute_digit == train->unk1A) {
        vehicle_train_arrive(0, bstate->unk2);
    }
    if (train->motion == 0 && train->door_state == 1) {
        if (train->stop_timer > 0) {
            train->stop_timer--;
        }
        if (train->stop_timer == 0) {
            train->stop_timer = -1;
            vehicle_train_set_doors(0);
            sprite_station_show_prompt(0);
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_80171820);

void sprite_station_show_prompt(s16 show) {
    BuildingState *bstate = &block_building_state;
    TrainState *train = &vehicle_train_state;

    if (show != 0) {
        if (train->unkC == 0 && train->direction != 0 && train->trigger == 0x100010) {
            if (block_building_state.building == 2 && bstate->unk2 != 6) {
                train->unkC = 1;
                event_state.trigger = train->trigger;
                event_state.trigger_type = (train->trigger >> 16) & 0xFF;
                /*  7地下鉄1に乗る       3○ */
                {
                    char *line = " 7\222n\211\272\223S1\202\311\217\346\202\351       3\201\233";
                    Player *player = player_status_player[0];

                    if (event_state.state != 2) {
                        event_state.state = 2;
                    }
                    text_show(line, 1, -1, 8, -1, 0, 1);
                    if (!(player->flags & 4)) {
                        player->flags |= 4;
                    }
                }
            } else if (bstate->building == 1 && bstate->unk2 != 3) {
                train->unkC = 1;
                event_state.trigger = train->trigger;
                event_state.trigger_type = (train->trigger >> 16) & 0xFF;
                /*  7電車1に乗る        3○ */
                {
                    char *line = " 7\223d\216\3241\202\311\217\346\202\351        3\201\233";
                    Player *player = player_status_player[0];

                    if (event_state.state != 2) {
                        event_state.state = 2;
                    }
                    text_show(line, 1, -1, 8, -1, 0, 1);
                    if (!(player->flags & 4)) {
                        player->flags |= 4;
                    }
                }
            } else {
                text_show(D_80171820, 1, -1, 0, -1, 0, 1);
            }
        } else if (train->unkC == 0 && train->direction == 0 && train->trigger == 0x100020) {
            if (bstate->building == 2 && bstate->unk2 != 1) {
                train->unkC = 1;
                event_state.trigger = train->trigger;
                event_state.trigger_type = (train->trigger >> 16) & 0xFF;
                /*  7地下鉄1に乗る       3○ */
                {
                    char *line = " 7\222n\211\272\223S1\202\311\217\346\202\351       3\201\233";
                    Player *player = player_status_player[0];

                    if (event_state.state != 2) {
                        event_state.state = 2;
                    }
                    text_show(line, 1, -1, 8, -1, 0, 1);
                    if (!(player->flags & 4)) {
                        player->flags |= 4;
                    }
                }
            } else if (bstate->building == 1 && bstate->unk2 != 1) {
                train->unkC = 1;
                event_state.trigger = train->trigger;
                event_state.trigger_type = (train->trigger >> 16) & 0xFF;
                /*  7電車1に乗る        3○ */
                {
                    char *line = " 7\223d\216\3241\202\311\217\346\202\351        3\201\233";
                    Player *player = player_status_player[0];

                    if (event_state.state != 2) {
                        event_state.state = 2;
                    }
                    text_show(line, 1, -1, 8, -1, 0, 1);
                    if (!(player->flags & 4)) {
                        player->flags |= 4;
                    }
                }
            } else {
                text_show(D_80171820, 1, -1, 0, -1, 0, 1);
            }
        }
    } else {
        Player *player = player_status_player[0];

        if (train->unkC != 0) {
            train->unkC = 0;
            text_close();
            action_reset(1);
            if (player->flags & 4) {
                player->flags &= ~4;
            }
        }
    }
}

void sprite_station_copy_signs(TrainState *train, BuildingState *bstate) {
    Sprite *sign0;
    Sprite *sign1;
    Unk_801A461C *tim0;
    Unk_801A461C *tim1;
    Rect rect;
    s32 cell;
    s32 row;
    s32 col;
    s16 w;
    s16 w2;
    s32 h2;
    s32 h;

    train->unkC = 0;
    train->trigger = 0;
    sign0 = (Sprite *)sprite_find(0);
    sign1 = (Sprite *)sprite_find(1);
    if (sign0 == NULL || sign1 == NULL) {
        return;
    }
    if (bstate->building == 2) {
        cell = bstate->unk2 - 1;
        row = cell / 2;
        col = cell % 2;
        tim0 = (Unk_801A461C *)sign0->tim;
        w = sign0->cell_w >> tim0->unk14;
        h = sign0->cell_h;
        rect.x = tim0->unk0 + col * w;
        rect.y = ((Unk_801A461C *)sign0->tim)->unk2 + row * h;
        rect.w = w;
        rect.h = h;
        MoveImage2(&rect, 0x2C0, 0);
        tim1 = (Unk_801A461C *)sign1->tim;
        w2 = sign1->cell_w >> tim1->unk14;
        h2 = sign1->cell_h;
        rect.x = tim1->unk0 + col * w2;
        rect.y = ((Unk_801A461C *)sign1->tim)->unk2 + row * h2;
        rect.w = w2;
        rect.h = h2;
        MoveImage2(&rect, 0x2F0, 0);
    }
    sprite_delete(0);
    sprite_delete(1);
}

void sprite_station_board_train(s16 direction) {
    Player *player = player_status_player[0];
    u16 v = D_801E1126[0];
    BuildingState *bstate = &block_building_state;

    if (v == 1) {
        if (direction != 0) {
            if (block_building_state.building == 1) {
                player->vehicle_mode = 2;
                mail_goto_twn(0x4CA2C, 0, (bstate->unk2 - 1) * 100000 - 195000, 270, 0);
            } else {
                player->vehicle_mode = 3;
                mail_goto_twn(0x4A31C, 0, (bstate->unk2 - 1) * 100000 - 195000, 270, 0);
            }
        } else {
            if (block_building_state.building == 1) {
                player->vehicle_mode = 2;
                mail_goto_twn(0x4BF3C, 0, (bstate->unk2 - 1) * 100000 - 200000, 90, 0);
            } else {
                player->vehicle_mode = 3;
                mail_goto_twn(0x4982C, 0, (bstate->unk2 - 1) * 100000 - 200000, 90, 0);
            }
        }
    }
}

void sprite_station_init(void) {
    TrainState *train = &vehicle_train_state;

    thing_set_flag10(2, 0, 1);
    if (train->unkA != 0) {
        train->motion = 2;
        train->unk18 = 2;
        train->unk1A = 7;
    } else {
        vehicle_train_place();
    }
    sprite_station_copy_signs(train, &block_building_state);
    D_801DFEE4 = sprite_station_on_enter;
    D_801DFEE0 = sprite_station_on_leave;
    D_801DFEDC = sprite_station_update;
}

void sprite_station_exit_to_town(void) {
    BuildingState *bstate = &block_building_state;
    s32 point;

    if (block_building_state.building == 2) {
        if (bstate->unk2 == block_building_state.building) {
            mail_goto_building(1, sprite_str_scene_gst, 0x13, 0x41, 3, 0x5A, 7, 0, 0);
        } else {
            point = (bstate->unk2 - 1) * 3;
            mail_goto_twn(sprite_station_exit_points[point], 0, sprite_station_exit_points[point + 1], sprite_station_exit_points[point + 2], 1);
        }
    }
}

s32 sprite_station_on_leave(Unk_801A5DA0 *ev) {
    TrainState *train = &vehicle_train_state;

    if (ev->unkC == 0x100010 || ev->unkC == 0x100020) {
        train->trigger = 0;
        sprite_station_show_prompt(0);
        return 1;
    }
    if (train->unkC != 0) {
        train->unkC = 0;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_8017186C);

void sprite_phone_update(void) {
    SceneRequest *request = scene_request;
    PlayerStatus *status = &player_status;
    s16 *menu = &sprite_phone_menu_state;
    s16 pad_mode = kaj_system.pad_mode;
    Player *player = status->player;
    s32 buttons;
    s16 sel;
    s16 ang;
    s32 x;
    s32 y;

    if (pad_mode != 1) {
        return;
    }
    buttons = kaj_pad_read();
    if (sprite_phone_menu_state == 0) {
        if (player->flags & 4) {
            if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
                EventState *ev_state = &event_state;
                Player *player2 = status->player;
                Unk_801E076C_18 *exit = &player2->unk18;

                if (ev_state->state == 2 && (ev_state->circle_flags & 8)) {
                    text_close();
                    sound_se_play(0x11);
                    switch (event_state.trigger) {
                    case 0xFB0000:
                        if (!(player2->flags & 0x40)) {
                            mod_set_anim(status->model, 1, 0);
                            player2->flags |= 0x40;
                        }
                        break;
                    case 0xFB0001:
                        mail_goto_twn(exit->unk4, exit->unk8, exit->unkC, exit->unk20, 0);
                        break;
                    }
                    ev_state->state = 1;
                }
            } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
                EventState *ev_state = &event_state;
                Unk_801E076C_18 *exit = &player->unk18;

                if (player->flags & 0x40) {
                    return;
                }
                text_close();
                sound_se_play(8);
                mail_goto_twn(exit->unk4, exit->unk8, exit->unkC, exit->unk20, 0);
                ev_state->state = 0;
            }
        }
    } else if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
        sound_se_play(0x11);
        switch (sprite_phone_menu_state) {
        case 1:
            switch (menu[1]) {
            case 0:
                text_close();
                sprite_set_visible(0x206, 0);
                sprite_set_visible(0x205, 0);
                sprite_phone_save = 1;
                request->change = 1;
                break;
            case 1:
                sprite_phone_menu_state = 3;
                text_show(D_80171900, 3, -1, 0, -1, 0, 0);
                break;
            case 2:
                sprite_phone_menu_state = 4;
                text_show(D_80171938, 3, -1, 0, -1, 0, 0);
                break;
            case 3:
                sprite_phone_menu_state = 0;
                /* " 2それではお気をつけて" */
                text_show(" 2\202\273\202\352\202\305\202\315\202\250\213\103\202\360\202\302\202\257\202\304", 1, -1, 0, -1, 0, 0);
                sprite_set_visible(0x206, 0);
                sprite_set_visible(0x205, 0);
                sprite_phone_menu_state = 0;
                mod_set_anim(status->model, 2, 0);
                break;
            }
            return;
        case 3:
            player->unk0 = 0x5C30;
            player->unk8 = -0x1004;
            player->unk4 = 0;
            player->unk10 = 0;
            player->unk12 = 0xB4;
            player->unk14 = 0;
            break;
        case 4:
            {
                Unk_801E076C_18 *exit = &player->unk18;

                ang = ((exit->unk1C * 45) << 12) / 360;
                x = (player->unk18.unk0 * rsin(ang)) >> 12;
                y = (player->unk18.unk0 * rcos(ang)) >> 12;
                player->unk0 = exit->unk10 + x;
                player->unk4 = 9999;
                player->unk8 = exit->unk18 + y;
                player->unk10 = 0;
                player->unk12 = exit->unk1E * 45;
                player->unk14 = 0;
            }
            break;
        default:
            return;
        }
        text_show(D_8017196C, 3, -1, 0, -1, 0, 0);
        menu[0] = 1;
        return;
    } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
        sound_se_play(8);
        switch (menu[0]) {
        case 1:
            /* " 2それではお気をつけて" */
            text_show(" 2\202\273\202\352\202\305\202\315\202\250\213\103\202\360\202\302\202\257\202\304", 1, -1, 0, -1, 0, 0);
            sprite_set_visible(0x206, 0);
            sprite_set_visible(0x205, 0);
            sprite_phone_menu_state = 0;
            mod_set_anim(status->model, 2, 0);
            break;
        case 3:
        case 4:
            text_show(D_8017196C, 3, -1, 0, -1, 0, 0);
            menu[0] = 1;
            break;
        }
        return;
    } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
        if (menu[0] == 1) {
            s16 *menu2 = &sprite_phone_menu_state;

            sel = sprite_phone_menu_cursor;
            sel--;
            if (sel < 0) {
                sel = 3;
            }
            sprite_set_clut_entry(0x206, menu2[1] + 4, 0x24C6);
            sprite_set_clut_entry(0x206, sel + 4, 0x24DF);
            menu2[1] = sel;
            sound_se_play(0xF);
        }
        return;
    } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
        if (menu[0] == 1) {
            s16 *menu2 = &sprite_phone_menu_state;

            sel = menu2[1];
            sel++;
            if (sel >= 4) {
                sel = 0;
            }
            sprite_set_clut_entry(0x206, menu2[1] + 4, 0x24C6);
            sprite_set_clut_entry(0x206, sel + 4, 0x24DF);
            menu2[1] = sel;
            sound_se_play(0xF);
        }
        return;
    }
    if (player->flags & 0x40) {
        return;
    }
    if (buttons & 0x1000) {
        player->unk3C = 1;
        player->pitch += D_801E6DB4[0];
    } else if (buttons & 0x4000) {
        player->unk3C = 1;
        player->pitch -= D_801E6DB4[0];
    } else if (buttons & 0x8000) {
        player->unk3C = 1;
        player->yaw -= D_801E6DB4[0];
    } else if (buttons & 0x2000) {
        player->unk3C = 1;
        player->yaw += D_801E6DB4[0];
    }
}

void sprite_phone_loop(void) {
    s32 buf[6];
    s16 done = 0;
    s16 light_was_on = 0;
    ScreenLight *light = &screen_light;
    PlayerStatus *status;
    PlayerStatus *status2;
    PlayerStatus *status3;
    Player *player;
    s16 *menu = &sprite_phone_menu_state;

    if (light->unk0[0] != 0) {
        light_was_on = 1;
        light->unk0[0] = 0;
    }
    status = &player_status;
    if (sprite_phone_save != 1) {
        player_place_for_scene(3);
        object_load_res(9, -1);
        status->model = mod_find(0x40);
        if (status->model != NULL) {
            mod_setup(status->model, 0, 3, 0);
        }
        D_801DFF50 = (s32)sprite_phone_pick_trigger;
        D_801DFEE4 = sprite_phone_on_enter;
        D_801DFED8 = (s32)sprite_phone_on_alarm;
        D_801DFED4 = (s32)sprite_phone_on_effect_done;
        menu[0] = 0;
        menu[1] = -1;
        sprite_set_visible(0x400, 0);
        sprite_set_visible(0x409, 0);
        sprite_set_visible(0x40E, 0);
        D_801E05B4[0] = 1;
    }
    kaj_timer_enable();
    if (sprite_phone_save == 0) {
        effect_start_fade(0, 3);
    } else {
        sprite_phone_save = 0;
        kaj_pad_reset(1);
    }
    while (done == 0) {
        switch (kaj_event_get(buf)) {
        case 2:
            func_80189928(buf);
            continue;
        case 0x10:
            event_handle_enter(buf);
            continue;
        case 4:
            event_handle_tick(1);
            continue;
        case 0x200:
            status2 = &player_status;
            player = status2->player;
            if (status2->model->anim == 1) {
                player->flags &= ~4;
                sound_se_play(0x1C);
                effect_start_alarm(0, 0x405, 2);
            } else if (status2->model->anim == 2) {
                player->flags &= ~0x40;
                mod_set_anim(status2->model, 0, 0);
                player_reset_triggers(1);
            }
            continue;
        case 0:
            sprite_phone_update();
            if ((s16)mail_take_scene_change() != 0) {
                if (sprite_phone_save == 0) {
                    effect_start_fade(1, 3);
                } else {
                    kaj_pad_reset(0);
                    done = 1;
                }
            }
            break;
        case 0x100:
            done = event_handle_effect_done(buf);
        default:
            kaj_event_done(buf);
            continue;
        }
        mail_step_frame(3, 0, 0);
    }
    kaj_timer_disable();
    status3 = &player_status;
    effect_clear_alarms();
    sound_se_stop_all();
    if (sprite_phone_save != 1) {
        status3->model = NULL;
        D_801DFF50 = 0;
        D_801DFEE4 = 0;
        D_801DFED8 = 0;
        D_801DFED4 = 0;
        text_close();
        block_free_owned();
        mod_free_all();
        sound_se_pop();
        sprite_delete(0x205);
        sprite_delete(0x206);
        sprite_set_visible(0x400, 1);
        sprite_set_visible(0x409, 1);
        sprite_set_visible(0x40E, 1);
        D_801E05B4[0] = 0;
    }
    if (light_was_on != 0) {
        light->unk0[0] = 1;
    }
}

void sprite_phone_pick_trigger(s32 *out) {
    Player *player = player_status_player[0];

    if (player->flags & 0x40) {
        *out = 0xFFFFFF;
        return;
    }
    *out = 0xFB0000;
    if ((u16)(player->pitch + 14) >= 30 || (u16)(player->yaw - 31) < 300) {
        *out = 0xFB0001;
    }
}

s32 sprite_phone_on_enter(Unk_801A6968 *ev) {
    switch (ev->unkC) {
    case 0xFB0000:
        /* " 8電話1をかける       3○" */
        text_show(" 8\223d\230b1\202\360\202\251\202\257\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFB0001:
        /* " 外に出る         3○" */
        text_show(" \212O\202\311\217o\202\351         3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    default:
        return 0;
    }
    return 1;
}

void sprite_phone_on_alarm(Unk_801A69E0 *ev) {
    if (ev->unkC == 0x405) {
        sound_se_stop(0x1C);
        effect_start_sprite_anim(0x205, 2);
    }
}

s32 sprite_phone_on_effect_done(Unk_801A6A1C *ev) {
    GameVars *game = &action_vars;

    if (ev->unk10 == 6) {
        if (ev->unkC == 0) {
            game->unk244 = -1;
        }
        /* D_8017186C */
        text_show(D_8017186C, 3, -1, 0, -1, 0, 0);
        sprite_set_visible(0x206, 1);
        sprite_fill_clut(0x206, 5, 7, 0x24C6);
        sprite_set_clut_entry(0x206, 4, 0x24DF);
        sprite_phone_menu_state = 1;
        sprite_phone_menu_cursor = 0;
    }
    return 0;
}

void sprite_phone_run(void) {
    sprite_phone_save = 0;
    while (1) {
        sprite_phone_loop();
        if (sprite_phone_save != 1) {
            break;
        }
        menu_card_run(0, 0);
        /* " 2ほかにご用はありますか？, 方向キー上下で選んで下さい,      決定 3○ 2切る 4×" */
        text_show(D_8017196C, 3, -1, 0, -1, 0, 0);
        sprite_set_visible(0x206, 1);
        sprite_set_visible(0x205, 1);
    }
}

void sprite_phone_save_exit(u16 trigger) {
    Player *player = player_status_player[0];
    Unk_801E076C_18 *exit = &player->unk18;

    exit->unk1C = (trigger & 0xF000) >> 12;
    exit->unk1E = (trigger & 0xF00) >> 8;
    exit->unk0 = (trigger & 0xFF) * 100;
    exit->unk4 = player->pos_x + player->cell_x * 12500;
    exit->unk8 = player->pos_y - player->cell_y * 32000 - player->unk78;
    exit->unkC = player->pos_z + player->cell_z * 12500;
    exit->unk20 = player->yaw;
}

void sprite_thing_init(Thing *thing) {
    SVector sv;
    Unk_801A6C34 *src = thing->record;
    Player *player = player_status_player[0];

    thing->id = src->unk0;
    thing->type = src->unk2;
    thing->unkA = src->unk4;
    thing->unkC = src->unk6;
    thing->unkE = src->unk8;
    thing->pos_x = src->unkC * 10;
    thing->pos_y = src->unk10 * 10;
    thing->pos_z = src->unk14 * 10;
    thing->rot_x = src->unk18;
    thing->rot_y = src->unk1A;
    thing->rot_z = src->unk1C;
    if (src->unk20 != 0) {
        kaj_tmd_load(&thing->tmd_objects, (u8 *)thing->record + src->unk20, &thing->coord_flg);
    }
    if (src->unk24 != 0) {
        kaj_tmd_load(&thing->hit_model, (u8 *)thing->record + src->unk24, &thing->coord_flg);
    }
    GsInitCoordinate2(NULL, &thing->coord_flg);
    thing->coord_tx = thing->pos_x - player->cell_x * 0x30D4;
    thing->coord_ty = thing->pos_y + player->cell_y * 0x7D00;
    thing->coord_tz = thing->pos_z - player->cell_z * 0x30D4;
    sv.vx = (thing->rot_x << 12) / 360;
    sv.vy = (thing->rot_y << 12) / 360;
    sv.vz = (thing->rot_z << 12) / 360;
    RotMatrix(&sv, thing->coord_m);
    thing->coord_flg = 0;
    if (thing->type == 4) {
        thing->block_fixed = 1;
        thing->active = 1;
        thing->animate = 1;
    } else {
        thing->block = block_find_at(thing->pos_x, thing->pos_y, thing->pos_z);
    }
}

void sprite_thing_refresh_all(void) {
    SVector sv;
    Unk_801DFF80 *list = D_801DFFA0;
    Player *player = player_status_player[0];
    Thing *thing;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        thing = (Thing *)list->cursor->data;
        if (thing != NULL && thing->type != 4) {
            thing->coord_tx = thing->pos_x - player->cell_x * 12500;
            thing->coord_ty = thing->pos_y + player->cell_y * 32000;
            thing->coord_tz = thing->pos_z - player->cell_z * 12500;
            sv.vx = (thing->rot_x << 12) / 360;
            sv.vy = (thing->rot_y << 12) / 360;
            sv.vz = (thing->rot_z << 12) / 360;
            RotMatrix(&sv, thing->coord_m);
            thing->coord_flg = 0;
            thing->block = block_find_at(thing->pos_x, thing->pos_y, thing->pos_z);
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", sprite_thing_draw_all);

void sprite_thing_update_marker(Player *player, Unk_801A742C *marker, Unk_801A727C *target) {
    SVector sv;
    NpcBody *body;
    s32 y;

    body = npc_find_body(target->unk14);
    y = target->unk24 - 2200;
    if (body != NULL && body->unk2 != 0) {
        y = target->unk24 - body->unk2 * 10 - 300;
    }
    marker->unk26 -= D_801E6DB4[0];
    if (marker->unk26 < 0) {
        marker->unk26 += 360;
    }
    marker->unk44 = target->unk20 - player->cell_x * 12500;
    marker->unk48 = y + player->cell_y * 32000;
    marker->unk4C = target->unk28 - player->cell_z * 12500;
    sv.vx = (marker->unk24 << 12) / 360;
    sv.vy = (marker->unk26 << 12) / 360;
    sv.vz = (marker->unk28 << 12) / 360;
    RotMatrix(&sv, marker->unk30);
    marker->unk2C = 0;
}

void sprite_thing_update_fly_in(Unk_801A742C *thing) {
    SVector sv;
    KajSystem *sys = &kaj_system;

    thing->unk28 += sys->vsync_delta * 3;
    thing->unk20 -= sys->vsync_delta * 25;
    if (thing->unk28 >= 361) {
        thing->unk28 -= 360;
    }
    if (thing->unk20 < 1500) {
        thing->unk6 = 0;
        thing->unk28 = 0;
        thing->unk20 = 1500;
    }
    thing->unk4C = thing->unk20;
    sv.vx = (thing->unk24 << 12) / 360;
    sv.vy = (thing->unk26 << 12) / 360;
    sv.vz = (thing->unk28 << 12) / 360;
    RotMatrix(&sv, thing->unk30);
    thing->unk2C = 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_80171900);

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_80171938);

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_8017196C);
