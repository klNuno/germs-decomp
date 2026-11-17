#include "common.h"
#include "game/types.h"
#include "gte.h"

void kaj_tim_free(s32 handle);
void free3(void *ptr);
typedef struct SpriteListNode {
    s32 unk0;
    struct SpriteListNode *next;
    u16 *data;
} SpriteListNode;
typedef struct {
    SpriteListNode *head;
    SpriteListNode *tail;
    SpriteListNode *cursor;
    s32 count;
} SpriteList;
void kaj_ll_insert_before(SpriteList *list, s32 data);
void kaj_ll_insert_after(SpriteList *list, s32 data);
SpriteList *sprite_list;
s16 kaj_ll_at_tail(SpriteList *list);
void sprite_title_show_menu(s16 wait);
void sprite_station_show_prompt(s16 show);
extern TrainState vehicle_train_state;
extern Player *player_status_player[];
void text_show(char *str, s32 mode, s32 circle_set, s32 circle_flags, s32 cross_set, s32 cross_flags, s32 se);
void sound_se_stop(s32 id);
void effect_start_sprite_anim(s32 sprite_id, s32 seconds);
extern char sprite_phone_str_anything_else[];
s16 sprite_phone_save;
void sprite_phone_loop(void);
s16 menu_card_run(s32 load_mode, s32 in_office);
void sprite_set_visible(s32 id, s32 visible);
u16 *sprite_find(u16 id);
void kaj_ll_remove_to_prev(SpriteList *list);
void sprite_delete(s32 id);
typedef struct {
    s16 x;
    s16 y;
    s16 w;
    u16 h;
    u8 clut_rect[0x4];
    s16 clut_w;
    u8 unkE[0x6];
    s16 pixel_shift;
    u8 unk16[0x6];
    u16 *clut_orig;
    u16 *clut_work;
} TimHandle;
void sprite_set_color(s32 id, s32 color);
void sprite_set_cell(s32 id, s32 col, s32 row);
void mail_wait(s32 mode, s32 stream, s32 visibility, s32 seconds);
void text_close(void);
void thing_set_active(s32 type, s32 id, s32 active);
s16 sprite_title_choice;
s16 sprite_title_menu_active;
s16 sprite_title_cursor_frame;
s16 sprite_title_cursor_moving;
extern BuildingState block_building_state;
extern u16 action_vars_minute[];
void vehicle_train_arrive(s16 direction, s16 station);
void vehicle_train_set_doors(s32 opening);
s32 sprite_station_on_leave(KajEvent *ev);
void thing_set_flag10(s32 type, s32 id, s32 block_fixed);
void vehicle_train_place(void);
void sprite_station_copy_signs(TrainState *train, BuildingState *bstate);
s32 sprite_station_on_enter(KajEvent *ev);
void sprite_station_update(void);
extern s32 (*event_enter_hook)();
extern s32 (*event_leave_hook)(KajEvent *arg0);
extern void (*event_tick_hook)(void);
extern s32 sprite_station_exit_points[];
extern s32 sprite_str_scene_gst[];
void mail_goto_twn(s32 x, s32 y, s32 z, s16 yaw, s16 e);
void mail_goto_building(s32 form, s32 *name, s32 var, s32 map_letter, s32 map_entry, s32 yaw, s32 scene_index, s32 trigger, s32 script_entry);
extern u16 vehicle_train_state_door_state[];
extern SceneTables object_scene_tables;
extern s32 event_effect_done_hook;
s16 sprite_title_load;
void sprite_title_loop(s16 restarted);
void thing_free_all(void);
void sound_se_stop_all(void);
void sound_se_pop(void);
extern char sprite_phone_str_greeting[];
extern GameVars action_vars;
void sprite_set_clut_entry(u16 id, s32 index, u16 color);
void sprite_fill_clut(u16 id, s32 first, s32 last, u16 color);
s16 sprite_phone_menu_state;
s16 sprite_phone_menu_cursor;
void *kaj_malloc(u32 size);
void kaj_abend(s32 code, char *msg, char *file, s32 line);
void kaj_tim_load(void *handle, void *tim_file, u16 mode, s16 keep_clut);
s32 MoveImage(Rect *rect, s32 x, s32 y);
extern KajSystem kaj_system;
extern SceneRequest scene_request[];
s32 kaj_pad_read(void);
void mail_goto_ofc(s32 a, s32 yaw, s32 c, s32 d);
void sound_se_play(s32 id);
s32 sprite_title_on_effect_done(KajEvent *ev);
void player_place_for_scene(s32 entry);
void object_load_res(s32 index, s32 progress);
void thing_set_animate(s32 type, s32 id, s32 animate);
Thing *thing_find(s32 type, s32 id);
extern char sprite_station_str_exit_only[];
s32 MoveImage2(Rect *rect, s32 x, s32 y);
SpriteList *thing_list;
void RotMatrix(SVector *arg0, void *arg1);
s32 block_find_at(s32 x, s32 y, s32 z);
NpcBody *npc_find_body(s16 id);
extern s32 kaj_system_vsync_delta[];
s32 atoi(char *s);
s32 LoadImage(void *rect, u32 *p);
void sprite_title_handle_input(void);
void sprite_title_init(s16 restarted);
void kaj_timer_enable(void);
void kaj_timer_disable(void);
void effect_start_fade(s32 kind, s32 seconds);
void kaj_pad_reset(s32 enable);
s32 kaj_event_get(s32 *event);
s16 event_handle_effect_done(s32 *ev);
void kaj_event_done(s32 *event);
s32 mail_take_scene_change(void);
void text_start_narration(s32 str);
void thing_update_all(void);
void roadmap_draw_frame(u16 mode);
extern s32 object_scene_texts[];
typedef struct {
    u16 id;
    u16 type;
    s16 ot_layer;
    s16 enter_set;
    s16 leave_set;
    u8 unkA[0x2];
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 unk1E[0x2];
    s32 model_offset;
    s32 hit_model_offset;
} ThingRecord;
void GsInitCoordinate2(void *super, void *base);
void kaj_tmd_load(void *obj, void *tmd_file, void *coord);
extern EventState event_state;
void action_reset(s16 flush_all);
void sprite_phone_pick_trigger(s32 *out);
s32 sprite_phone_on_enter(KajEvent *ev);
void sprite_phone_on_alarm(KajEvent *ev);
s32 sprite_phone_on_effect_done(KajEvent *ev);
extern s32 player_pick_trigger_hook;
extern s32 event_alarm_hook;
extern PlayerStatus player_status;
extern ScreenLight screen_light;
extern s16 action_vars_menu_busy[];
Model *mod_find(u16 id);
void mod_setup(Model *mod, s32 parent, s32 kind, s32 anim);
void mod_set_anim(void *mod, s16 anim, s16 frames);
void player_reset_triggers(s16 reground);
void effect_start_alarm(s32 slot, s32 code, s32 delay);
void event_handle_alarm(s32 *ev);
void event_handle_enter(s32 *ev);
void event_handle_tick(s16 daylight);
void mail_step_frame(u16 mode, s16 b, s16 c);
void effect_clear_alarms(void);
void block_free_owned(void);
void mod_free_all(void);
void sprite_phone_update(void);
/* phone menu confirm line, choice 1 */
extern char sprite_phone_str_move_car[];
/* phone menu confirm line, choice 2 */
extern char sprite_phone_str_coming[];
s32 rsin(s32 a);
s32 rcos(s32 a);
extern void *GsOUT_PACKET_P;
void *roadmap_add_sprite(void *sprite, void *packet, u32 *ot_base);
extern s16 roadmap_draw_flags;
void GsGetLs(void *coord, void *m);
void GsSetLsMatrix(void *m);
void GsSortObject4J(void *obj, void *ot, s32 shift, void *scratch);

void sprite_create(Sprite **out, SpriteRecord *rec) {
    TimHandle *tim;
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
    kaj_tim_load(&(*out)->tim, rec->tim, rec->mode, rec->keep_clut);
    tim = (TimHandle *)(*out)->tim;
    h = tim->h;
    (*out)->cell_w = (s16)(tim->w << tim->pixel_shift) / (*out)->columns;
    (*out)->cell_h = h / (*out)->rows;
}

void sprite_copy_cell(u16 src_id, s16 col, u16 row, u16 dst_id, u16 dst_x, u16 dst_y) {
    SpriteList *list;
    u16 *src;
    u16 *dst;
    u16 *item;
    TimHandle *src_tim;
    TimHandle *dst_tim;
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
        src_tim = (TimHandle *)((Sprite *)src)->tim;
        w = ((Sprite *)src)->cell_w >> src_tim->pixel_shift;
        rect.x = src_tim->x + col * w;
        rect.y = ((TimHandle *)((Sprite *)src)->tim)->y + row * (s16)((Sprite *)src)->cell_h;
        rect.w = w;
        rect.h = ((Sprite *)src)->cell_h;
        dst_tim = (TimHandle *)((Sprite *)dst)->tim;
        dst_x >>= dst_tim->pixel_shift;
        MoveImage(&rect, dst_tim->x + dst_x, dst_tim->y + dst_y);
    }
}

void sprite_exec_command(Action *cmd) {
    SpriteList *list = sprite_list;
    ActionCmdShort *op = (ActionCmdShort *)cmd->cmd;
    u16 id = op->target;
    u16 *sprite;
    u16 *item;
    TimHandle *tim;
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
        tim = (TimHandle *)((Sprite *)sprite)->tim;
        if (tim->clut_orig != NULL && tim->clut_work != NULL) {
            switch (op->sub) {
            case 2:
                first = atoi(cmd->args[0]);
                ((TimHandle *)((Sprite *)sprite)->tim)->clut_work[first] = atoi(cmd->args[1]);
                break;
            case 3:
                first = atoi(cmd->args[0]);
                end = atoi(cmd->args[1]);
                color = atoi(cmd->args[2]);
                for (i = first; i <= end; i++) {
                    ((TimHandle *)((Sprite *)sprite)->tim)->clut_work[i] = color;
                }
                break;
            case 4:
                LoadImage(&tim->clut_rect, (u32 *)tim->clut_orig);
                return;
            default:
                return;
            }
            LoadImage(&((TimHandle *)((Sprite *)sprite)->tim)->clut_rect, (u32 *)((TimHandle *)((Sprite *)sprite)->tim)->clut_work);
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
    SpriteList *list = sprite_list;
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
    SpriteList *list = sprite_list;
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

void sprite_draw_all(ViewBuffer *view) {
    SpriteList *list = sprite_list;
    u32 *ot = view->ot_tags;
    u16 *sprite;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        sprite = list->cursor->data;
        if (sprite != NULL && ((Sprite *)sprite)->visible != 0) {
            SetSpadStack(0x1F8003FC);
            GsOUT_PACKET_P = roadmap_add_sprite(sprite, GsOUT_PACKET_P, ot);
            ResetSpadStack();
        }
        if (kaj_ll_at_tail(list) != 0) {
            return;
        }
        list->cursor = list->cursor->next;
    }
}

void sprite_set_clut_entry(u16 id, s32 index, u16 color) {
    SpriteList *list = sprite_list;
    u16 *sprite;
    TimHandle *tim;

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
        tim = (TimHandle *)((Sprite *)sprite)->tim;
        if (tim->clut_orig != NULL && tim->clut_work != NULL) {
            tim->clut_work[index] = color;
            ((Sprite *)sprite)->clut_dirty = 1;
        }
    }
}

void sprite_reset_clut(u16 id) {
    SpriteList *list = sprite_list;
    u16 *sprite;
    u16 *item;
    TimHandle *tim;
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
        tim = (TimHandle *)((Sprite *)sprite)->tim;
        if (tim->clut_orig != NULL && tim->clut_work != NULL) {
            for (i = 0; i < tim->clut_w; i++) {
                tim->clut_work[i] = tim->clut_orig[i];
                tim = (TimHandle *)((Sprite *)sprite)->tim;
            }
            ((Sprite *)sprite)->clut_dirty = 1;
        }
    }
}

void sprite_fill_clut(u16 id, s32 first, s32 last, u16 color) {
    SpriteList *list = sprite_list;
    u16 *sprite;
    u16 *item;
    TimHandle *tim;
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
        tim = (TimHandle *)((Sprite *)sprite)->tim;
        if (tim->clut_orig != NULL && tim->clut_work != NULL) {
            for (i = first; i <= last; i++) {
                ((TimHandle *)((Sprite *)sprite)->tim)->clut_work[i] = color;
            }
            ((Sprite *)sprite)->clut_dirty = 1;
        }
    }
}

void sprite_restore_clut(u16 id, s32 first, s32 last) {
    SpriteList *list = sprite_list;
    u16 *sprite;
    u16 *item;
    TimHandle *tim;
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
        tim = (TimHandle *)((Sprite *)sprite)->tim;
        if (tim->clut_orig != NULL && tim->clut_work != NULL) {
            for (i = first; i <= last; i++) {
                ((TimHandle *)((Sprite *)sprite)->tim)->clut_work[i] = ((TimHandle *)((Sprite *)sprite)->tim)->clut_orig[i];
            }
            ((Sprite *)sprite)->clut_dirty = 1;
        }
    }
}

void sprite_set_visible(s32 id, s32 visible) {
    SpriteList *list = sprite_list;
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
    SpriteList *list = sprite_list;
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
    SpriteList *list = sprite_list;
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
        event_effect_done_hook = (s32)sprite_title_on_effect_done;
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
                text_start_narration(object_scene_texts[0]);
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
    event_effect_done_hook = 0;
    if (sprite_title_load != 1) {
        thing_free_all();
        sound_se_stop_all();
        sound_se_pop();
        for (i = 0; i < 3; i++) {
            sprite_delete((u16)i);
        }
        for (i = 0; i < tables->text_count; i++) {
            if (tables->texts[i] != NULL) {
                free3(tables->texts[i]);
                tables->texts[i] = NULL;
            }
        }
        tables->text_count = 0;
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
    event_effect_done_hook = 0;
    tables = &object_scene_tables;
    thing_free_all();
    sound_se_stop_all();
    sound_se_pop();
    for (i = 0; i < 3; i++) {
        sprite_delete((u16)i);
    }
    for (i = 0; i < tables->text_count; i++) {
        if (tables->texts[i] != NULL) {
            free3(tables->texts[i]);
            tables->texts[i] = NULL;
        }
    }
    tables->text_count = 0;
}

s32 sprite_title_on_effect_done(KajEvent *ev) {
    if (ev->param2 == 8) {
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

s32 sprite_station_on_enter(KajEvent *ev) {
    BuildingState *bstate = &block_building_state;
    TrainState *train = &vehicle_train_state;

    switch (ev->param1) {
    case 0x100010:
    case 0x100020:
        train->trigger = ev->param1;
        if (train->door_state == 1) {
            sprite_station_show_prompt(1);
        }
        break;
    case 0xF00110:
        if (bstate->building == 1) {
            if (bstate->entry == 3) {
                text_show(sprite_station_str_exit_only, 1, -1, 0, -1, 0, 1);
            }
        } else if (bstate->building == 2) {
            if (bstate->entry == 6) {
                text_show(sprite_station_str_exit_only, 1, -1, 0, -1, 0, 1);
            }
        }
        break;
    case 0xF00120:
        if (bstate->entry == 1) {
            text_show(sprite_station_str_exit_only, 1, -1, 0, -1, 0, 1);
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
    s16 minute_digit = (s16)action_vars_minute[0] % 10;

    if (minute_digit == train->arrive_digit_dir1) {
        vehicle_train_arrive(1, bstate->entry);
    } else if (minute_digit == train->arrive_digit_dir0) {
        vehicle_train_arrive(0, bstate->entry);
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

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", sprite_station_str_exit_only);

void sprite_station_show_prompt(s16 show) {
    BuildingState *bstate = &block_building_state;
    TrainState *train = &vehicle_train_state;

    if (show != 0) {
        if (train->prompt_on == 0 && train->direction != 0 && train->trigger == 0x100010) {
            if (block_building_state.building == 2 && bstate->entry != 6) {
                train->prompt_on = 1;
                event_state.trigger = train->trigger;
                event_state.trigger_type = (train->trigger >> 16) & 0xFF;
                /* station prompt: board the subway */
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
            } else if (bstate->building == 1 && bstate->entry != 3) {
                train->prompt_on = 1;
                event_state.trigger = train->trigger;
                event_state.trigger_type = (train->trigger >> 16) & 0xFF;
                /* station prompt: board the train */
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
                text_show(sprite_station_str_exit_only, 1, -1, 0, -1, 0, 1);
            }
        } else if (train->prompt_on == 0 && train->direction == 0 && train->trigger == 0x100020) {
            if (bstate->building == 2 && bstate->entry != 1) {
                train->prompt_on = 1;
                event_state.trigger = train->trigger;
                event_state.trigger_type = (train->trigger >> 16) & 0xFF;
                /* station prompt: board the subway */
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
            } else if (bstate->building == 1 && bstate->entry != 1) {
                train->prompt_on = 1;
                event_state.trigger = train->trigger;
                event_state.trigger_type = (train->trigger >> 16) & 0xFF;
                /* station prompt: board the train */
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
                text_show(sprite_station_str_exit_only, 1, -1, 0, -1, 0, 1);
            }
        }
    } else {
        Player *player = player_status_player[0];

        if (train->prompt_on != 0) {
            train->prompt_on = 0;
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
    TimHandle *tim0;
    TimHandle *tim1;
    Rect rect;
    s32 cell;
    s32 row;
    s32 col;
    s16 w;
    s16 w2;
    s32 h2;
    s32 h;

    train->prompt_on = 0;
    train->trigger = 0;
    sign0 = (Sprite *)sprite_find(0);
    sign1 = (Sprite *)sprite_find(1);
    if (sign0 == NULL || sign1 == NULL) {
        return;
    }
    if (bstate->building == 2) {
        cell = bstate->entry - 1;
        row = cell / 2;
        col = cell % 2;
        tim0 = (TimHandle *)sign0->tim;
        w = sign0->cell_w >> tim0->pixel_shift;
        h = sign0->cell_h;
        rect.x = tim0->x + col * w;
        rect.y = ((TimHandle *)sign0->tim)->y + row * h;
        rect.w = w;
        rect.h = h;
        MoveImage2(&rect, 0x2C0, 0);
        tim1 = (TimHandle *)sign1->tim;
        w2 = sign1->cell_w >> tim1->pixel_shift;
        h2 = sign1->cell_h;
        rect.x = tim1->x + col * w2;
        rect.y = ((TimHandle *)sign1->tim)->y + row * h2;
        rect.w = w2;
        rect.h = h2;
        MoveImage2(&rect, 0x2F0, 0);
    }
    sprite_delete(0);
    sprite_delete(1);
}

void sprite_station_board_train(s16 direction) {
    Player *player = player_status_player[0];
    u16 v = vehicle_train_state_door_state[0];
    BuildingState *bstate = &block_building_state;

    if (v == 1) {
        if (direction != 0) {
            if (block_building_state.building == 1) {
                player->vehicle_mode = 2;
                mail_goto_twn(0x4CA2C, 0, (bstate->entry - 1) * 100000 - 195000, 270, 0);
            } else {
                player->vehicle_mode = 3;
                mail_goto_twn(0x4A31C, 0, (bstate->entry - 1) * 100000 - 195000, 270, 0);
            }
        } else {
            if (block_building_state.building == 1) {
                player->vehicle_mode = 2;
                mail_goto_twn(0x4BF3C, 0, (bstate->entry - 1) * 100000 - 200000, 90, 0);
            } else {
                player->vehicle_mode = 3;
                mail_goto_twn(0x4982C, 0, (bstate->entry - 1) * 100000 - 200000, 90, 0);
            }
        }
    }
}

void sprite_station_init(void) {
    TrainState *train = &vehicle_train_state;

    thing_set_flag10(2, 0, 1);
    if (train->placed != 0) {
        train->motion = 2;
        train->arrive_digit_dir1 = 2;
        train->arrive_digit_dir0 = 7;
    } else {
        vehicle_train_place();
    }
    sprite_station_copy_signs(train, &block_building_state);
    event_enter_hook = sprite_station_on_enter;
    event_leave_hook = sprite_station_on_leave;
    event_tick_hook = sprite_station_update;
}

void sprite_station_exit_to_town(void) {
    BuildingState *bstate = &block_building_state;
    s32 point;

    if (block_building_state.building == 2) {
        if (bstate->entry == block_building_state.building) {
            mail_goto_building(1, sprite_str_scene_gst, 0x13, 0x41, 3, 0x5A, 7, 0, 0);
        } else {
            point = (bstate->entry - 1) * 3;
            mail_goto_twn(sprite_station_exit_points[point], 0, sprite_station_exit_points[point + 1], sprite_station_exit_points[point + 2], 1);
        }
    }
}

s32 sprite_station_on_leave(KajEvent *ev) {
    TrainState *train = &vehicle_train_state;

    if (ev->param1 == 0x100010 || ev->param1 == 0x100020) {
        train->trigger = 0;
        sprite_station_show_prompt(0);
        return 1;
    }
    if (train->prompt_on != 0) {
        train->prompt_on = 0;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", sprite_phone_str_greeting);

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
                PlayerExit *exit = &player2->exit;

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
                        mail_goto_twn(exit->pos_x, exit->pos_y, exit->pos_z, exit->yaw, 0);
                        break;
                    }
                    ev_state->state = 1;
                }
            } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
                EventState *ev_state = &event_state;
                PlayerExit *exit = &player->exit;

                if (player->flags & 0x40) {
                    return;
                }
                text_close();
                sound_se_play(8);
                mail_goto_twn(exit->pos_x, exit->pos_y, exit->pos_z, exit->yaw, 0);
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
                text_show(sprite_phone_str_move_car, 3, -1, 0, -1, 0, 0);
                break;
            case 2:
                sprite_phone_menu_state = 4;
                text_show(sprite_phone_str_coming, 3, -1, 0, -1, 0, 0);
                break;
            case 3:
                sprite_phone_menu_state = 0;
                /* phone farewell */
                text_show(" 2\202\273\202\352\202\305\202\315\202\250\213\103\202\360\202\302\202\257\202\304", 1, -1, 0, -1, 0, 0);
                sprite_set_visible(0x206, 0);
                sprite_set_visible(0x205, 0);
                sprite_phone_menu_state = 0;
                mod_set_anim(status->model, 2, 0);
                break;
            }
            return;
        case 3:
            player->car_x = 0x5C30;
            player->car_z = -0x1004;
            player->car_y = 0;
            player->car_rot_x = 0;
            player->car_rot_y = 0xB4;
            player->car_rot_z = 0;
            break;
        case 4:
            {
                PlayerExit *exit = &player->exit;

                ang = ((exit->direction * 45) << 12) / 360;
                x = (player->exit.distance * rsin(ang)) >> 12;
                y = (player->exit.distance * rcos(ang)) >> 12;
                player->car_x = exit->centre_x + x;
                player->car_y = 9999;
                player->car_z = exit->centre_z + y;
                player->car_rot_x = 0;
                player->car_rot_y = exit->facing * 45;
                player->car_rot_z = 0;
            }
            break;
        default:
            return;
        }
        text_show(sprite_phone_str_anything_else, 3, -1, 0, -1, 0, 0);
        menu[0] = 1;
        return;
    } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
        sound_se_play(8);
        switch (menu[0]) {
        case 1:
            /* phone farewell */
            text_show(" 2\202\273\202\352\202\305\202\315\202\250\213\103\202\360\202\302\202\257\202\304", 1, -1, 0, -1, 0, 0);
            sprite_set_visible(0x206, 0);
            sprite_set_visible(0x205, 0);
            sprite_phone_menu_state = 0;
            mod_set_anim(status->model, 2, 0);
            break;
        case 3:
        case 4:
            text_show(sprite_phone_str_anything_else, 3, -1, 0, -1, 0, 0);
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
        player->view_dirty = 1;
        player->pitch += kaj_system_vsync_delta[0];
    } else if (buttons & 0x4000) {
        player->view_dirty = 1;
        player->pitch -= kaj_system_vsync_delta[0];
    } else if (buttons & 0x8000) {
        player->view_dirty = 1;
        player->yaw -= kaj_system_vsync_delta[0];
    } else if (buttons & 0x2000) {
        player->view_dirty = 1;
        player->yaw += kaj_system_vsync_delta[0];
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

    if (light->daylight_on != 0) {
        light_was_on = 1;
        light->daylight_on = 0;
    }
    status = &player_status;
    if (sprite_phone_save != 1) {
        player_place_for_scene(3);
        object_load_res(9, -1);
        status->model = mod_find(0x40);
        if (status->model != NULL) {
            mod_setup(status->model, 0, 3, 0);
        }
        player_pick_trigger_hook = (s32)sprite_phone_pick_trigger;
        event_enter_hook = sprite_phone_on_enter;
        event_alarm_hook = (s32)sprite_phone_on_alarm;
        event_effect_done_hook = (s32)sprite_phone_on_effect_done;
        menu[0] = 0;
        menu[1] = -1;
        sprite_set_visible(0x400, 0);
        sprite_set_visible(0x409, 0);
        sprite_set_visible(0x40E, 0);
        action_vars_menu_busy[0] = 1;
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
            event_handle_alarm(buf);
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
        player_pick_trigger_hook = 0;
        event_enter_hook = 0;
        event_alarm_hook = 0;
        event_effect_done_hook = 0;
        text_close();
        block_free_owned();
        mod_free_all();
        sound_se_pop();
        sprite_delete(0x205);
        sprite_delete(0x206);
        sprite_set_visible(0x400, 1);
        sprite_set_visible(0x409, 1);
        sprite_set_visible(0x40E, 1);
        action_vars_menu_busy[0] = 0;
    }
    if (light_was_on != 0) {
        light->daylight_on = 1;
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

s32 sprite_phone_on_enter(KajEvent *ev) {
    switch (ev->param1) {
    case 0xFB0000:
        /* phone box prompt: make a call */
        text_show(" 8\223d\230b1\202\360\202\251\202\257\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFB0001:
        /* phone box prompt: go outside */
        text_show(" \212O\202\311\217o\202\351         3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    default:
        return 0;
    }
    return 1;
}

void sprite_phone_on_alarm(KajEvent *ev) {
    if (ev->param1 == 0x405) {
        sound_se_stop(0x1C);
        effect_start_sprite_anim(0x205, 2);
    }
}

s32 sprite_phone_on_effect_done(KajEvent *ev) {
    GameVars *game = &action_vars;

    if (ev->param2 == 6) {
        if (ev->param1 == 0) {
            game->effect_task = -1;
        }
        /* sprite_phone_str_greeting */
        text_show(sprite_phone_str_greeting, 3, -1, 0, -1, 0, 0);
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
        /* phone menu: anything else */
        text_show(sprite_phone_str_anything_else, 3, -1, 0, -1, 0, 0);
        sprite_set_visible(0x206, 1);
        sprite_set_visible(0x205, 1);
    }
}

void sprite_phone_save_exit(u16 trigger) {
    Player *player = player_status_player[0];
    PlayerExit *exit = &player->exit;

    exit->direction = (trigger & 0xF000) >> 12;
    exit->facing = (trigger & 0xF00) >> 8;
    exit->distance = (trigger & 0xFF) * 100;
    exit->pos_x = player->pos_x + player->cell_x * 12500;
    exit->pos_y = player->pos_y - player->cell_y * 32000 - player->eye_height;
    exit->pos_z = player->pos_z + player->cell_z * 12500;
    exit->yaw = player->yaw;
}

void sprite_thing_init(Thing *thing) {
    SVector sv;
    ThingRecord *src = thing->record;
    Player *player = player_status_player[0];

    thing->id = src->id;
    thing->type = src->type;
    thing->ot_layer = src->ot_layer;
    thing->enter_set = src->enter_set;
    thing->leave_set = src->leave_set;
    thing->pos_x = src->pos_x * 10;
    thing->pos_y = src->pos_y * 10;
    thing->pos_z = src->pos_z * 10;
    thing->rot_x = src->rot_x;
    thing->rot_y = src->rot_y;
    thing->rot_z = src->rot_z;
    if (src->model_offset != 0) {
        kaj_tmd_load(&thing->tmd_objects, (u8 *)thing->record + src->model_offset, &thing->coord_flg);
    }
    if (src->hit_model_offset != 0) {
        kaj_tmd_load(&thing->hit_model, (u8 *)thing->record + src->hit_model_offset, &thing->coord_flg);
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
    SpriteList *list = thing_list;
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

void sprite_thing_draw_all(ViewBuffer *view) {
    s32 ls[8];
    SpriteList *list = thing_list;
    Player *player = player_status_player[0];
    ScreenLight *light = &screen_light;
    Thing *thing;
    s16 flags;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        thing = (Thing *)list->cursor->data;
        if (thing != NULL && (thing->block_fixed != 0 ? thing->active != 0
                              : thing->active != 0 && (Block *)thing->block != NULL
                                    && ((Block *)thing->block)->visible != 0)) {
            flags = roadmap_draw_flags;
            if (thing->type == 4) {
                thing->coord_tx = player->pos_x;
                thing->coord_tz = player->pos_z;
                if (player->vehicle_mode == 2) {
                    thing->coord_ty = player->pos_y - player->eye_height + 15000;
                } else {
                    thing->coord_ty = player->pos_y - player->eye_height + 500;
                }
                thing->coord_flg = 0;
                if (roadmap_draw_flags & 2) {
                    roadmap_draw_flags -= 2;
                }
            }
            GsGetLs(&thing->coord_flg, ls);
            GsSetLsMatrix(ls);
            light->ot_bias = (thing->ot_layer + 1) << 6;
            SetSpadStack(0x1F8003FC);
            GsSortObject4J(thing->tmd_objects, &view->ot_length, 1, (void *)0x1F800000);
            ResetSpadStack();
            roadmap_draw_flags = flags;
        }
        if (kaj_ll_at_tail(list) != 0) {
            return;
        }
        list->cursor = list->cursor->next;
    }
}

void sprite_thing_update_marker(Player *player, Thing *marker, Npc *target) {
    SVector sv;
    NpcBody *body;
    s32 y;

    body = npc_find_body(target->body_id);
    y = target->pos_y - 2200;
    if (body != NULL && body->height != 0) {
        y = target->pos_y - body->height * 10 - 300;
    }
    marker->rot_y -= kaj_system_vsync_delta[0];
    if (marker->rot_y < 0) {
        marker->rot_y += 360;
    }
    marker->coord_tx = target->pos_x - player->cell_x * 12500;
    marker->coord_ty = y + player->cell_y * 32000;
    marker->coord_tz = target->pos_z - player->cell_z * 12500;
    sv.vx = (marker->rot_x << 12) / 360;
    sv.vy = (marker->rot_y << 12) / 360;
    sv.vz = (marker->rot_z << 12) / 360;
    RotMatrix(&sv, marker->coord_m);
    marker->coord_flg = 0;
}

void sprite_thing_update_fly_in(Thing *thing) {
    SVector sv;
    KajSystem *sys = &kaj_system;

    thing->rot_z += sys->vsync_delta * 3;
    thing->pos_z -= sys->vsync_delta * 25;
    if (thing->rot_z >= 361) {
        thing->rot_z -= 360;
    }
    if (thing->pos_z < 1500) {
        thing->animate = 0;
        thing->rot_z = 0;
        thing->pos_z = 1500;
    }
    thing->coord_tz = thing->pos_z;
    sv.vx = (thing->rot_x << 12) / 360;
    sv.vy = (thing->rot_y << 12) / 360;
    sv.vz = (thing->rot_z << 12) / 360;
    RotMatrix(&sv, thing->coord_m);
    thing->coord_flg = 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", sprite_phone_str_move_car);

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", sprite_phone_str_coming);

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", sprite_phone_str_anything_else);
