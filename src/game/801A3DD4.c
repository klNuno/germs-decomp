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

void sprite_create(Sprite **arg0, SpriteRecord *arg1) {
    Unk_801A461C *r;
    s16 h;

    *arg0 = kaj_malloc(0x20);
    if (*arg0 == NULL) {
        kaj_abend(3, "Error Allocating SPRITE Pointer", "sprite.c", 0x22);
    }
    (*arg0)->id = arg1->id;
    (*arg0)->mode = arg1->mode;
    (*arg0)->x = arg1->x;
    (*arg0)->y = arg1->y;
    (*arg0)->depth = arg1->depth;
    (*arg0)->columns = arg1->columns;
    (*arg0)->rows = arg1->rows;
    (*arg0)->visible = 0;
    (*arg0)->clut_dirty = 0;
    (*arg0)->color = 0;
    (*arg0)->cell_col = 0;
    (*arg0)->cell_row = 0;
    kaj_tim_load(&(*arg0)->tim, arg1->unk14, arg1->mode, arg1->unk12);
    r = (Unk_801A461C *)(*arg0)->tim;
    h = r->unk6;
    (*arg0)->cell_w = (s16)(r->unk4 << r->unk14) / (*arg0)->columns;
    (*arg0)->cell_h = h / (*arg0)->rows;
}

void sprite_copy_cell(u16 arg0, s16 arg1, u16 arg2, u16 arg3, u16 arg4, u16 arg5) {
    Unk_801DFF80 *p;
    u16 *q;
    u16 *s;
    u16 *t;
    Unk_801A461C *r;
    Unk_801A461C *r2;
    Rect rect;
    s16 w;

    p = sprite_list;
    if (p->count == 0) {
        q = NULL;
    } else {
        p->cursor = p->head;
        while (1) {
            t = p->cursor->data;
            if (t != NULL && *t == arg0) {
                q = t;
                break;
            }
            if (kaj_ll_at_tail(p) != 0) {
                q = NULL;
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
    p = sprite_list;
    if (p->count == 0) {
        s = NULL;
    } else {
        p->cursor = p->head;
        while (1) {
            t = p->cursor->data;
            if (t != NULL && *t == arg3) {
                s = t;
                break;
            }
            if (kaj_ll_at_tail(p) != 0) {
                s = NULL;
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
    if (q != NULL && s != NULL) {
        r = (Unk_801A461C *)((Sprite *)q)->tim;
        w = ((Sprite *)q)->cell_w >> r->unk14;
        rect.x = r->unk0 + arg1 * w;
        rect.y = ((Unk_801A461C *)((Sprite *)q)->tim)->unk2 + arg2 * (s16)((Sprite *)q)->cell_h;
        rect.w = w;
        rect.h = ((Sprite *)q)->cell_h;
        r2 = (Unk_801A461C *)((Sprite *)s)->tim;
        arg4 >>= r2->unk14;
        MoveImage(&rect, r2->unk0 + arg4, r2->unk2 + arg5);
    }
}

void sprite_exec_command(Unk_801A417C *arg0) {
    Unk_801DFF80 *p = sprite_list;
    Unk_801A417C_0 *c = arg0->unk0;
    u16 id = c->unk4;
    u16 *q;
    u16 *t;
    Unk_801A461C *r;
    s32 i;
    s32 end;
    u16 v;
    s32 j;

    if (p->count == 0) {
        q = NULL;
    } else {
        p->cursor = p->head;
        while (1) {
            t = p->cursor->data;
            if (t != NULL && *t == id) {
                q = t;
                break;
            }
            if (kaj_ll_at_tail(p) != 0) {
                q = NULL;
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
    if (q != NULL) {
        r = (Unk_801A461C *)((Sprite *)q)->tim;
        if (r->unk1C != NULL && r->unk20 != NULL) {
            switch (c->unk2) {
            case 2:
                j = atoi(arg0->unk8[0]);
                ((Unk_801A461C *)((Sprite *)q)->tim)->unk20[j] = atoi(arg0->unk8[1]);
                break;
            case 3:
                j = atoi(arg0->unk8[0]);
                end = atoi(arg0->unk8[1]);
                v = atoi(arg0->unk8[2]);
                for (i = j; i <= end; i++) {
                    ((Unk_801A461C *)((Sprite *)q)->tim)->unk20[i] = v;
                }
                break;
            case 4:
                LoadImage(&r->unk8, (u32 *)r->unk1C);
                return;
            default:
                return;
            }
            LoadImage(&((Unk_801A461C *)((Sprite *)q)->tim)->unk8, (u32 *)((Unk_801A461C *)((Sprite *)q)->tim)->unk20);
        }
    }
}

void sprite_free(Sprite *arg0) {
    if (arg0 != NULL) {
        kaj_tim_free(arg0->tim);
        free3(arg0);
    }
}

void sprite_add(s32 arg0) {
    if (sprite_list->count == 0) {
        kaj_ll_insert_before(sprite_list, arg0);
    } else {
        sprite_list->cursor = sprite_list->tail;
        kaj_ll_insert_after(sprite_list, arg0);
    }
}

void sprite_delete(s32 arg0) {
    Unk_801DFF80 *p = sprite_list;
    u16 *q;

    if (p->count == 0) {
        return;
    }
    q = sprite_find((u16)arg0);
    if (q == NULL) {
        return;
    }
    p->cursor = p->head;
    while (1) {
        if (q == p->cursor->data) {
            if (q != NULL) {
                kaj_tim_free(((Sprite *)q)->tim);
                free3(q);
            }
            kaj_ll_remove_to_prev(p);
            return;
        }
        if (kaj_ll_at_tail(p) != 0) {
            return;
        }
        p->cursor = p->cursor->next;
    }
}

u16 *sprite_find(u16 arg0) {
    Unk_801DFF80 *p = sprite_list;
    u16 *q;

    if (p->count == 0) {
        return NULL;
    }
    p->cursor = p->head;
    while (1) {
        q = p->cursor->data;
        if (q != NULL && *q == arg0) {
            break;
        }
        if (kaj_ll_at_tail(p) != 0) {
            return NULL;
        }
        p->cursor = p->cursor->next;
    }
    return q;
}

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", sprite_draw_all);

void sprite_set_clut_entry(u16 arg0, s32 arg1, u16 arg2) {
    Unk_801DFF80 *p = sprite_list;
    u16 *q;
    Unk_801A461C *r;

    if (p->count == 0) {
        q = NULL;
    } else {
        p->cursor = p->head;
        while (1) {
            q = p->cursor->data;
            if (q != NULL && *q == arg0) {
                break;
            }
            if (kaj_ll_at_tail(p) != 0) {
                q = NULL;
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
    if (q != NULL) {
        r = (Unk_801A461C *)((Sprite *)q)->tim;
        if (r->unk1C != NULL && r->unk20 != NULL) {
            r->unk20[arg1] = arg2;
            ((Sprite *)q)->clut_dirty = 1;
        }
    }
}

void sprite_reset_clut(u16 arg0) {
    Unk_801DFF80 *p = sprite_list;
    u16 *q;
    u16 *t;
    Unk_801A461C *r;
    s32 i;

    if (p->count == 0) {
        q = NULL;
    } else {
        p->cursor = p->head;
        while (1) {
            t = p->cursor->data;
            if (t != NULL && *t == arg0) {
                q = t;
                break;
            }
            if (kaj_ll_at_tail(p) != 0) {
                q = NULL;
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
    if (q != NULL) {
        r = (Unk_801A461C *)((Sprite *)q)->tim;
        if (r->unk1C != NULL && r->unk20 != NULL) {
            for (i = 0; i < r->unkC; i++) {
                r->unk20[i] = r->unk1C[i];
                r = (Unk_801A461C *)((Sprite *)q)->tim;
            }
            ((Sprite *)q)->clut_dirty = 1;
        }
    }
}

void sprite_fill_clut(u16 arg0, s32 arg1, s32 arg2, u16 arg3) {
    Unk_801DFF80 *p = sprite_list;
    u16 *q;
    u16 *t;
    Unk_801A461C *r;
    s32 i;

    if (p->count == 0) {
        q = NULL;
    } else {
        p->cursor = p->head;
        while (1) {
            t = p->cursor->data;
            if (t != NULL && *t == arg0) {
                q = t;
                break;
            }
            if (kaj_ll_at_tail(p) != 0) {
                q = NULL;
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
    if (q != NULL) {
        r = (Unk_801A461C *)((Sprite *)q)->tim;
        if (r->unk1C != NULL && r->unk20 != NULL) {
            for (i = arg1; i <= arg2; i++) {
                ((Unk_801A461C *)((Sprite *)q)->tim)->unk20[i] = arg3;
            }
            ((Sprite *)q)->clut_dirty = 1;
        }
    }
}

void sprite_restore_clut(u16 arg0, s32 arg1, s32 arg2) {
    Unk_801DFF80 *p = sprite_list;
    u16 *q;
    u16 *t;
    Unk_801A461C *r;
    s32 i;

    if (p->count == 0) {
        q = NULL;
    } else {
        p->cursor = p->head;
        while (1) {
            t = p->cursor->data;
            if (t != NULL && *t == arg0) {
                q = t;
                break;
            }
            if (kaj_ll_at_tail(p) != 0) {
                q = NULL;
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
    if (q != NULL) {
        r = (Unk_801A461C *)((Sprite *)q)->tim;
        if (r->unk1C != NULL && r->unk20 != NULL) {
            for (i = arg1; i <= arg2; i++) {
                ((Unk_801A461C *)((Sprite *)q)->tim)->unk20[i] = ((Unk_801A461C *)((Sprite *)q)->tim)->unk1C[i];
            }
            ((Sprite *)q)->clut_dirty = 1;
        }
    }
}

void sprite_set_visible(s32 arg0, s32 arg1) {
    Unk_801DFF80 *p = sprite_list;
    u16 *q;
    u16 *t;

    if (p->count == 0) {
        q = NULL;
    } else {
        p->cursor = p->head;
        while (1) {
            t = p->cursor->data;
            if (t != NULL && *t == (u16)arg0) {
                q = t;
                break;
            }
            if (kaj_ll_at_tail(p) != 0) {
                q = NULL;
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
    if (q != NULL) {
        ((Sprite *)q)->visible = arg1;
    }
}

void sprite_set_color(s32 arg0, s32 arg1) {
    Unk_801DFF80 *p = sprite_list;
    u16 *q;
    u16 *t;

    if (p->count == 0) {
        q = NULL;
    } else {
        p->cursor = p->head;
        while (1) {
            t = p->cursor->data;
            if (t != NULL && *t == (u16)arg0) {
                q = t;
                break;
            }
            if (kaj_ll_at_tail(p) != 0) {
                q = NULL;
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
    if (q != NULL) {
        ((Sprite *)q)->color = arg1;
    }
}

void sprite_set_cell(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFF80 *p = sprite_list;
    u16 *q;
    u16 *t;

    if (p->count == 0) {
        q = NULL;
    } else {
        p->cursor = p->head;
        while (1) {
            t = p->cursor->data;
            if (t != NULL && *t == (u16)arg0) {
                q = t;
                break;
            }
            if (kaj_ll_at_tail(p) != 0) {
                q = NULL;
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
    if (q != NULL) {
        ((Sprite *)q)->cell_col = arg1;
        ((Sprite *)q)->cell_row = arg2;
    }
}

void sprite_title_handle_input(void) {
    SceneRequest *q = scene_request;
    s16 flag;
    s32 arg;

    if (sprite_title_menu_active == 0 || sprite_title_cursor_moving != 0 || kaj_system.pad_mode != 1) {
        return;
    }
    kaj_pad_read();
    flag = 0;
    if ((!(kaj_system.pad_prev & 0x800) && (kaj_system.pad_now & 0x800)) ||
        (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20))) {
        flag = 1;
        if (sprite_title_choice != 0) {
            arg = 2;
            mail_goto_ofc(1, 1, 1, 1);
        } else {
            arg = 0x11;
            sprite_title_load = 1;
            q->change = 1;
        }
    } else if ((!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) ||
               (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000))) {
        if (sprite_title_cursor_moving == 0) {
            flag = 1;
            arg = 1;
            sprite_title_cursor_moving = 1;
            sprite_title_choice = 1 - sprite_title_choice;
        }
    }
    if (flag) {
        sound_se_play(arg);
    }
}

void sprite_title_init(s16 arg0) {
    Thing *p;
    s32 i;

    if (sprite_title_load == 1) {
        return;
    }
    player_place_for_scene(3);
    if (arg0 != 0) {
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
    if (arg0 != 0) {
        D_801DFED4 = (s32)sprite_title_on_effect_done;
        p = thing_find(3, 10);
        if (p != NULL) {
            p->pos_x = 0;
            p->pos_z = 0x1D4C;
            p->pos_y = 0;
            p->active = 0;
            p->animate = 0;
            p->block_fixed = 1;
            p->coord_flg = 0;
            p->coord_tx = p->pos_x;
            p->coord_ty = p->pos_y;
            p->coord_tz = p->pos_z;
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

void sprite_title_loop(s16 arg0) {
    s32 buf[6];
    s16 done;
    SceneTables *p;
    s32 i;

    sprite_title_init(arg0);
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
            if (arg0 != 0 && buf[4] == 0) {
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
    p = &object_scene_tables;
    D_801DFED4 = 0;
    if (sprite_title_load != 1) {
        thing_free_all();
        sound_se_stop_all();
        sound_se_pop();
        for (i = 0; i < 3; i++) {
            sprite_delete((u16)i);
        }
        for (i = 0; i < p->unk34; i++) {
            if (p->unk5C[i] != NULL) {
                free3(p->unk5C[i]);
                p->unk5C[i] = NULL;
            }
        }
        p->unk34 = 0;
    }
}

void sprite_title_run(s32 arg0) {
    SceneTables *p;
    s32 i;

    sprite_title_load = 0;
loop:
    sprite_title_loop(arg0);
    if (sprite_title_load != 1) {
        return;
    }
    if (menu_card_run(1, 0) == 0) {
        goto loop;
    }
    sprite_title_load = 0;
    D_801DFED4 = 0;
    p = &object_scene_tables;
    thing_free_all();
    sound_se_stop_all();
    sound_se_pop();
    for (i = 0; i < 3; i++) {
        sprite_delete((u16)i);
    }
    for (i = 0; i < p->unk34; i++) {
        if (p->unk5C[i] != NULL) {
            free3(p->unk5C[i]);
            p->unk5C[i] = NULL;
        }
    }
    p->unk34 = 0;
}

s32 sprite_title_on_effect_done(Unk_801A533C *arg0) {
    if (arg0->unk10 == 8) {
        sprite_title_show_menu(1);
    }
    return 0;
}

void sprite_title_show_menu(s16 arg0) {
    if (arg0 != 0) {
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

s32 sprite_station_on_enter(Unk_801A5DA0 *arg0) {
    BuildingState *q = &block_building_state;
    TrainState *p = &vehicle_train_state;

    switch (arg0->unkC) {
    case 0x100010:
    case 0x100020:
        p->trigger = arg0->unkC;
        if (p->door_state == 1) {
            sprite_station_show_prompt(1);
        }
        break;
    case 0xF00110:
        if (q->building == 1) {
            if (q->unk2 == 3) {
                text_show(D_80171820, 1, -1, 0, -1, 0, 1);
            }
        } else if (q->building == 2) {
            if (q->unk2 == 6) {
                text_show(D_80171820, 1, -1, 0, -1, 0, 1);
            }
        }
        break;
    case 0xF00120:
        if (q->unk2 == 1) {
            text_show(D_80171820, 1, -1, 0, -1, 0, 1);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

void sprite_station_update(void) {
    BuildingState *q = &block_building_state;
    TrainState *p = &vehicle_train_state;
    s16 r = (s16)D_801E03E6[0] % 10;

    if (r == p->unk18) {
        vehicle_train_arrive(1, q->unk2);
    } else if (r == p->unk1A) {
        vehicle_train_arrive(0, q->unk2);
    }
    if (p->motion == 0 && p->door_state == 1) {
        if (p->stop_timer > 0) {
            p->stop_timer--;
        }
        if (p->stop_timer == 0) {
            p->stop_timer = -1;
            vehicle_train_set_doors(0);
            sprite_station_show_prompt(0);
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_80171820);

void sprite_station_show_prompt(s16 arg0) {
    BuildingState *m = &block_building_state;
    TrainState *t = &vehicle_train_state;

    if (arg0 != 0) {
        if (t->unkC == 0 && t->direction != 0 && t->trigger == 0x100010) {
            if (block_building_state.building == 2 && m->unk2 != 6) {
                t->unkC = 1;
                event_state.trigger = t->trigger;
                event_state.trigger_type = (t->trigger >> 16) & 0xFF;
                /*  7地下鉄1に乗る       3○ */
                {
                    char *s = " 7\222n\211\272\223S1\202\311\217\346\202\351       3\201\233";
                    Player *e = player_status_player[0];

                    if (event_state.state != 2) {
                        event_state.state = 2;
                    }
                    text_show(s, 1, -1, 8, -1, 0, 1);
                    if (!(e->flags & 4)) {
                        e->flags |= 4;
                    }
                }
            } else if (m->building == 1 && m->unk2 != 3) {
                t->unkC = 1;
                event_state.trigger = t->trigger;
                event_state.trigger_type = (t->trigger >> 16) & 0xFF;
                /*  7電車1に乗る        3○ */
                {
                    char *s = " 7\223d\216\3241\202\311\217\346\202\351        3\201\233";
                    Player *e = player_status_player[0];

                    if (event_state.state != 2) {
                        event_state.state = 2;
                    }
                    text_show(s, 1, -1, 8, -1, 0, 1);
                    if (!(e->flags & 4)) {
                        e->flags |= 4;
                    }
                }
            } else {
                text_show(D_80171820, 1, -1, 0, -1, 0, 1);
            }
        } else if (t->unkC == 0 && t->direction == 0 && t->trigger == 0x100020) {
            if (m->building == 2 && m->unk2 != 1) {
                t->unkC = 1;
                event_state.trigger = t->trigger;
                event_state.trigger_type = (t->trigger >> 16) & 0xFF;
                /*  7地下鉄1に乗る       3○ */
                {
                    char *s = " 7\222n\211\272\223S1\202\311\217\346\202\351       3\201\233";
                    Player *e = player_status_player[0];

                    if (event_state.state != 2) {
                        event_state.state = 2;
                    }
                    text_show(s, 1, -1, 8, -1, 0, 1);
                    if (!(e->flags & 4)) {
                        e->flags |= 4;
                    }
                }
            } else if (m->building == 1 && m->unk2 != 1) {
                t->unkC = 1;
                event_state.trigger = t->trigger;
                event_state.trigger_type = (t->trigger >> 16) & 0xFF;
                /*  7電車1に乗る        3○ */
                {
                    char *s = " 7\223d\216\3241\202\311\217\346\202\351        3\201\233";
                    Player *e = player_status_player[0];

                    if (event_state.state != 2) {
                        event_state.state = 2;
                    }
                    text_show(s, 1, -1, 8, -1, 0, 1);
                    if (!(e->flags & 4)) {
                        e->flags |= 4;
                    }
                }
            } else {
                text_show(D_80171820, 1, -1, 0, -1, 0, 1);
            }
        }
    } else {
        Player *e = player_status_player[0];

        if (t->unkC != 0) {
            t->unkC = 0;
            text_close();
            action_reset(1);
            if (e->flags & 4) {
                e->flags &= ~4;
            }
        }
    }
}

void sprite_station_copy_signs(TrainState *arg0, BuildingState *arg1) {
    Sprite *a;
    Sprite *b;
    Unk_801A461C *r;
    Unk_801A461C *r2;
    Rect rect;
    s32 n;
    s32 row;
    s32 col;
    s16 w;
    s16 w2;
    s32 h2;
    s32 h;

    arg0->unkC = 0;
    arg0->trigger = 0;
    a = (Sprite *)sprite_find(0);
    b = (Sprite *)sprite_find(1);
    if (a == NULL || b == NULL) {
        return;
    }
    if (arg1->building == 2) {
        n = arg1->unk2 - 1;
        row = n / 2;
        col = n % 2;
        r = (Unk_801A461C *)a->tim;
        w = a->cell_w >> r->unk14;
        h = a->cell_h;
        rect.x = r->unk0 + col * w;
        rect.y = ((Unk_801A461C *)a->tim)->unk2 + row * h;
        rect.w = w;
        rect.h = h;
        MoveImage2(&rect, 0x2C0, 0);
        r2 = (Unk_801A461C *)b->tim;
        w2 = b->cell_w >> r2->unk14;
        h2 = b->cell_h;
        rect.x = r2->unk0 + col * w2;
        rect.y = ((Unk_801A461C *)b->tim)->unk2 + row * h2;
        rect.w = w2;
        rect.h = h2;
        MoveImage2(&rect, 0x2F0, 0);
    }
    sprite_delete(0);
    sprite_delete(1);
}

void sprite_station_board_train(s16 arg0) {
    Player *p = player_status_player[0];
    u16 v = D_801E1126[0];
    BuildingState *q = &block_building_state;

    if (v == 1) {
        if (arg0 != 0) {
            if (block_building_state.building == 1) {
                p->vehicle_mode = 2;
                mail_goto_twn(0x4CA2C, 0, (q->unk2 - 1) * 100000 - 195000, 270, 0);
            } else {
                p->vehicle_mode = 3;
                mail_goto_twn(0x4A31C, 0, (q->unk2 - 1) * 100000 - 195000, 270, 0);
            }
        } else {
            if (block_building_state.building == 1) {
                p->vehicle_mode = 2;
                mail_goto_twn(0x4BF3C, 0, (q->unk2 - 1) * 100000 - 200000, 90, 0);
            } else {
                p->vehicle_mode = 3;
                mail_goto_twn(0x4982C, 0, (q->unk2 - 1) * 100000 - 200000, 90, 0);
            }
        }
    }
}

void sprite_station_init(void) {
    TrainState *p = &vehicle_train_state;

    thing_set_flag10(2, 0, 1);
    if (p->unkA != 0) {
        p->motion = 2;
        p->unk18 = 2;
        p->unk1A = 7;
    } else {
        vehicle_train_place();
    }
    sprite_station_copy_signs(p, &block_building_state);
    D_801DFEE4 = sprite_station_on_enter;
    D_801DFEE0 = sprite_station_on_leave;
    D_801DFEDC = sprite_station_update;
}

void sprite_station_exit_to_town(void) {
    BuildingState *p = &block_building_state;
    s32 i;

    if (block_building_state.building == 2) {
        if (p->unk2 == block_building_state.building) {
            mail_goto_building(1, sprite_str_scene_gst, 0x13, 0x41, 3, 0x5A, 7, 0, 0);
        } else {
            i = (p->unk2 - 1) * 3;
            mail_goto_twn(sprite_station_exit_points[i], 0, sprite_station_exit_points[i + 1], sprite_station_exit_points[i + 2], 1);
        }
    }
}

s32 sprite_station_on_leave(Unk_801A5DA0 *arg0) {
    TrainState *p = &vehicle_train_state;

    if (arg0->unkC == 0x100010 || arg0->unkC == 0x100020) {
        p->trigger = 0;
        sprite_station_show_prompt(0);
        return 1;
    }
    if (p->unkC != 0) {
        p->unkC = 0;
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_8017186C);

void sprite_phone_update(void) {
    SceneRequest *m = scene_request;
    PlayerStatus *g = &player_status;
    s16 *p = &sprite_phone_menu_state;
    s16 one = kaj_system.pad_mode;
    Player *e = g->player;
    s32 btn;
    s16 sel;
    s16 ang;
    s32 x;
    s32 y;

    if (one != 1) {
        return;
    }
    btn = kaj_pad_read();
    if (sprite_phone_menu_state == 0) {
        if (e->flags & 4) {
            if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
                EventState *f = &event_state;
                Player *e2 = g->player;
                Unk_801E076C_18 *t = &e2->unk18;

                if (f->state == 2 && (f->circle_flags & 8)) {
                    text_close();
                    sound_se_play(0x11);
                    switch (event_state.trigger) {
                    case 0xFB0000:
                        if (!(e2->flags & 0x40)) {
                            mod_set_anim(g->model, 1, 0);
                            e2->flags |= 0x40;
                        }
                        break;
                    case 0xFB0001:
                        mail_goto_twn(t->unk4, t->unk8, t->unkC, t->unk20, 0);
                        break;
                    }
                    f->state = 1;
                }
            } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
                EventState *f = &event_state;
                Unk_801E076C_18 *t = &e->unk18;

                if (e->flags & 0x40) {
                    return;
                }
                text_close();
                sound_se_play(8);
                mail_goto_twn(t->unk4, t->unk8, t->unkC, t->unk20, 0);
                f->state = 0;
            }
        }
    } else if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
        sound_se_play(0x11);
        switch (sprite_phone_menu_state) {
        case 1:
            switch (p[1]) {
            case 0:
                text_close();
                sprite_set_visible(0x206, 0);
                sprite_set_visible(0x205, 0);
                sprite_phone_save = 1;
                m->change = 1;
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
                mod_set_anim(g->model, 2, 0);
                break;
            }
            return;
        case 3:
            e->unk0 = 0x5C30;
            e->unk8 = -0x1004;
            e->unk4 = 0;
            e->unk10 = 0;
            e->unk12 = 0xB4;
            e->unk14 = 0;
            break;
        case 4:
            {
                Unk_801E076C_18 *t = &e->unk18;

                ang = ((t->unk1C * 45) << 12) / 360;
                x = (e->unk18.unk0 * rsin(ang)) >> 12;
                y = (e->unk18.unk0 * rcos(ang)) >> 12;
                e->unk0 = t->unk10 + x;
                e->unk4 = 9999;
                e->unk8 = t->unk18 + y;
                e->unk10 = 0;
                e->unk12 = t->unk1E * 45;
                e->unk14 = 0;
            }
            break;
        default:
            return;
        }
        text_show(D_8017196C, 3, -1, 0, -1, 0, 0);
        p[0] = 1;
        return;
    } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
        sound_se_play(8);
        switch (p[0]) {
        case 1:
            /* " 2それではお気をつけて" */
            text_show(" 2\202\273\202\352\202\305\202\315\202\250\213\103\202\360\202\302\202\257\202\304", 1, -1, 0, -1, 0, 0);
            sprite_set_visible(0x206, 0);
            sprite_set_visible(0x205, 0);
            sprite_phone_menu_state = 0;
            mod_set_anim(g->model, 2, 0);
            break;
        case 3:
        case 4:
            text_show(D_8017196C, 3, -1, 0, -1, 0, 0);
            p[0] = 1;
            break;
        }
        return;
    } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
        if (p[0] == 1) {
            s16 *q = &sprite_phone_menu_state;

            sel = sprite_phone_menu_cursor;
            sel--;
            if (sel < 0) {
                sel = 3;
            }
            sprite_set_clut_entry(0x206, q[1] + 4, 0x24C6);
            sprite_set_clut_entry(0x206, sel + 4, 0x24DF);
            q[1] = sel;
            sound_se_play(0xF);
        }
        return;
    } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
        if (p[0] == 1) {
            s16 *q = &sprite_phone_menu_state;

            sel = q[1];
            sel++;
            if (sel >= 4) {
                sel = 0;
            }
            sprite_set_clut_entry(0x206, q[1] + 4, 0x24C6);
            sprite_set_clut_entry(0x206, sel + 4, 0x24DF);
            q[1] = sel;
            sound_se_play(0xF);
        }
        return;
    }
    if (e->flags & 0x40) {
        return;
    }
    if (btn & 0x1000) {
        e->unk3C = 1;
        e->pitch += D_801E6DB4[0];
    } else if (btn & 0x4000) {
        e->unk3C = 1;
        e->pitch -= D_801E6DB4[0];
    } else if (btn & 0x8000) {
        e->unk3C = 1;
        e->yaw -= D_801E6DB4[0];
    } else if (btn & 0x2000) {
        e->unk3C = 1;
        e->yaw += D_801E6DB4[0];
    }
}

void sprite_phone_loop(void) {
    s32 buf[6];
    s16 done = 0;
    s16 saved = 0;
    ScreenLight *f = &screen_light;
    PlayerStatus *g;
    PlayerStatus *h;
    PlayerStatus *k;
    Player *e;
    s16 *p = &sprite_phone_menu_state;

    if (f->unk0[0] != 0) {
        saved = 1;
        f->unk0[0] = 0;
    }
    g = &player_status;
    if (sprite_phone_save != 1) {
        player_place_for_scene(3);
        object_load_res(9, -1);
        g->model = mod_find(0x40);
        if (g->model != NULL) {
            mod_setup(g->model, 0, 3, 0);
        }
        D_801DFF50 = (s32)sprite_phone_pick_trigger;
        D_801DFEE4 = sprite_phone_on_enter;
        D_801DFED8 = (s32)sprite_phone_on_alarm;
        D_801DFED4 = (s32)sprite_phone_on_effect_done;
        p[0] = 0;
        p[1] = -1;
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
            h = &player_status;
            e = h->player;
            if (h->model->anim == 1) {
                e->flags &= ~4;
                sound_se_play(0x1C);
                effect_start_alarm(0, 0x405, 2);
            } else if (h->model->anim == 2) {
                e->flags &= ~0x40;
                mod_set_anim(h->model, 0, 0);
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
    k = &player_status;
    effect_clear_alarms();
    sound_se_stop_all();
    if (sprite_phone_save != 1) {
        k->model = NULL;
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
    if (saved != 0) {
        f->unk0[0] = 1;
    }
}

void sprite_phone_pick_trigger(s32 *arg0) {
    Player *p = player_status_player[0];

    if (p->flags & 0x40) {
        *arg0 = 0xFFFFFF;
        return;
    }
    *arg0 = 0xFB0000;
    if ((u16)(p->pitch + 14) >= 30 || (u16)(p->yaw - 31) < 300) {
        *arg0 = 0xFB0001;
    }
}

s32 sprite_phone_on_enter(Unk_801A6968 *arg0) {
    switch (arg0->unkC) {
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

void sprite_phone_on_alarm(Unk_801A69E0 *arg0) {
    if (arg0->unkC == 0x405) {
        sound_se_stop(0x1C);
        effect_start_sprite_anim(0x205, 2);
    }
}

s32 sprite_phone_on_effect_done(Unk_801A6A1C *arg0) {
    GameVars *p = &action_vars;

    if (arg0->unk10 == 6) {
        if (arg0->unkC == 0) {
            p->unk244 = -1;
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

void sprite_phone_save_exit(u16 arg0) {
    Player *p = player_status_player[0];
    Unk_801E076C_18 *q = &p->unk18;

    q->unk1C = (arg0 & 0xF000) >> 12;
    q->unk1E = (arg0 & 0xF00) >> 8;
    q->unk0 = (arg0 & 0xFF) * 100;
    q->unk4 = p->pos_x + p->cell_x * 12500;
    q->unk8 = p->pos_y - p->cell_y * 32000 - p->unk78;
    q->unkC = p->pos_z + p->cell_z * 12500;
    q->unk20 = p->yaw;
}

void sprite_thing_init(Thing *arg0) {
    SVector sv;
    Unk_801A6C34 *src = arg0->record;
    Player *e = player_status_player[0];

    arg0->id = src->unk0;
    arg0->type = src->unk2;
    arg0->unkA = src->unk4;
    arg0->unkC = src->unk6;
    arg0->unkE = src->unk8;
    arg0->pos_x = src->unkC * 10;
    arg0->pos_y = src->unk10 * 10;
    arg0->pos_z = src->unk14 * 10;
    arg0->rot_x = src->unk18;
    arg0->rot_y = src->unk1A;
    arg0->rot_z = src->unk1C;
    if (src->unk20 != 0) {
        kaj_tmd_load(&arg0->tmd_objects, (u8 *)arg0->record + src->unk20, &arg0->coord_flg);
    }
    if (src->unk24 != 0) {
        kaj_tmd_load(&arg0->hit_model, (u8 *)arg0->record + src->unk24, &arg0->coord_flg);
    }
    GsInitCoordinate2(NULL, &arg0->coord_flg);
    arg0->coord_tx = arg0->pos_x - e->cell_x * 0x30D4;
    arg0->coord_ty = arg0->pos_y + e->cell_y * 0x7D00;
    arg0->coord_tz = arg0->pos_z - e->cell_z * 0x30D4;
    sv.vx = (arg0->rot_x << 12) / 360;
    sv.vy = (arg0->rot_y << 12) / 360;
    sv.vz = (arg0->rot_z << 12) / 360;
    RotMatrix(&sv, arg0->coord_m);
    arg0->coord_flg = 0;
    if (arg0->type == 4) {
        arg0->block_fixed = 1;
        arg0->active = 1;
        arg0->animate = 1;
    } else {
        arg0->block = block_find_at(arg0->pos_x, arg0->pos_y, arg0->pos_z);
    }
}

void sprite_thing_refresh_all(void) {
    SVector sv;
    Unk_801DFF80 *p = D_801DFFA0;
    Player *e = player_status_player[0];
    Thing *o;

    if (p->count == 0) {
        return;
    }
    p->cursor = p->head;
    while (1) {
        o = (Thing *)p->cursor->data;
        if (o != NULL && o->type != 4) {
            o->coord_tx = o->pos_x - e->cell_x * 12500;
            o->coord_ty = o->pos_y + e->cell_y * 32000;
            o->coord_tz = o->pos_z - e->cell_z * 12500;
            sv.vx = (o->rot_x << 12) / 360;
            sv.vy = (o->rot_y << 12) / 360;
            sv.vz = (o->rot_z << 12) / 360;
            RotMatrix(&sv, o->coord_m);
            o->coord_flg = 0;
            o->block = block_find_at(o->pos_x, o->pos_y, o->pos_z);
        }
        if (kaj_ll_at_tail(p) != 0) {
            break;
        }
        p->cursor = p->cursor->next;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801A3DD4", sprite_thing_draw_all);

void sprite_thing_update_marker(Player *arg0, Unk_801A742C *arg1, Unk_801A727C *arg2) {
    SVector sv;
    NpcBody *q;
    s32 y;

    q = npc_find_body(arg2->unk14);
    y = arg2->unk24 - 2200;
    if (q != NULL && q->unk2 != 0) {
        y = arg2->unk24 - q->unk2 * 10 - 300;
    }
    arg1->unk26 -= D_801E6DB4[0];
    if (arg1->unk26 < 0) {
        arg1->unk26 += 360;
    }
    arg1->unk44 = arg2->unk20 - arg0->cell_x * 12500;
    arg1->unk48 = y + arg0->cell_y * 32000;
    arg1->unk4C = arg2->unk28 - arg0->cell_z * 12500;
    sv.vx = (arg1->unk24 << 12) / 360;
    sv.vy = (arg1->unk26 << 12) / 360;
    sv.vz = (arg1->unk28 << 12) / 360;
    RotMatrix(&sv, arg1->unk30);
    arg1->unk2C = 0;
}

void sprite_thing_update_fly_in(Unk_801A742C *arg0) {
    SVector sv;
    KajSystem *p = &kaj_system;

    arg0->unk28 += p->vsync_delta * 3;
    arg0->unk20 -= p->vsync_delta * 25;
    if (arg0->unk28 >= 361) {
        arg0->unk28 -= 360;
    }
    if (arg0->unk20 < 1500) {
        arg0->unk6 = 0;
        arg0->unk28 = 0;
        arg0->unk20 = 1500;
    }
    arg0->unk4C = arg0->unk20;
    sv.vx = (arg0->unk24 << 12) / 360;
    sv.vy = (arg0->unk26 << 12) / 360;
    sv.vz = (arg0->unk28 << 12) / 360;
    RotMatrix(&sv, arg0->unk30);
    arg0->unk2C = 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_80171900);

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_80171938);

INCLUDE_RODATA("asm/nonmatchings/game/801A3DD4", D_8017196C);
