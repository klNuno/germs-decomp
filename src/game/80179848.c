#include "common.h"
#include "game/types.h"

s16 kaj_ll_at_tail(BlockList *arg0);
BlockList *block_list;
void kaj_ll_insert_before(BlockList *arg0, s32 arg1);
void kaj_ll_insert_after(BlockList *arg0, s32 arg1);
void kaj_cdmgr_free_all(void);
s16 D_801DFC80;
extern s16 D_801E71C8;
u8 D_801DFC8C;
u8 D_801DFC8D[1];
u8 D_801DFC8E;
extern GameVars action_vars;
s16 block_wake_index;
void block_create_all(void);
void block_building_run(void);
void effect_elevator_run(void);
u16 D_801DFE60;
void text_release_cmd(void);
void sprite_set_visible(s32 arg0, s32 arg1);
void sprite_set_clut_entry(s32 arg0, s32 arg1, s32 arg2);
void sound_se_play(s32 arg0);
TextCmd **text_cmd;
s16 text_window_sprite;
void action_push_front(TextCmd **arg0);
s16 text_wait;
extern s32 D_801E6DB4[];
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Unk_8017AC88;
extern s32 D_801E05B0[];
extern Player *player_status_player[];
extern char D_80170250[];
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
void *memset(void *dst, s32 c, u32 n);
extern char D_801DFC84[];
void free3(void *ptr);
typedef struct {
    s16 unk0;
    u8 pad2[0x6];
    s16 unk8;
    u8 padA[0xA];
    struct {
        s16 unk0;
        u8 pad2[0x96];
    } unk14[4];
} Unk_801802A0;
void sprite_fill_clut(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void sprite_delete(s32 arg0);
void mail_list_close(void);
void mail_free(void);
typedef struct Unk_801A44B8 {
    u8 pad0[0x1C];
    Rect *tim;
} Unk_801A44B8;
Unk_801A44B8 *sprite_find(u16 arg0);
s32 ClearImage2(Rect *rect, s32 r, s32 g, s32 b);
s16 text_draw_next(s32 arg0, s32 arg1);
s16 text_row;
s16 D_801DFCE6;
s16 text_pos;
s32 block_model_surface(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void kaj_ll_remove_to_prev(BlockList *arg0);
s16 text_cue_fade_done;
s16 text_cue_bgm_done;
void sound_bgm_fade_out(s32 arg0);
void effect_start_fade(s32 arg0, s32 arg1);
extern EventState event_state;
extern char D_80170270[];
extern Block *block_slots[];
void npc_update_blocks(void);
void block_setup(Block *arg0, u16 arg1);
void mod_create(void *arg0);
void kaj_tim_upload_hdr(void *arg0);
void **kaj_cdmgr_get(s32 arg0);
s32 kaj_cdmgr_get_type(s32 arg0);
s32 kaj_cdmgr_is_fresh(s32 arg0);
void kaj_cdmgr_mark_used(s32 arg0);
void kaj_map_cell_slots(s16 *arg0, s32 *arg1);
void kaj_map_room_slots(s16 *arg0, s32 *arg1);
void kaj_map_room_release(s32 arg0);
u16 block_building_id;
void block_load_all(u16 arg0);
void block_set_zone_flags(s32 arg0, s32 arg1);
s32 kaj_cdmgr_poll(void);
s32 kaj_map_update_city(s32 arg0, s32 arg1);
s32 kaj_map_update_place(u16 arg0, u8 *arg1);
void kaj_map_cell_loaded_slots(s16 *arg0, s32 *arg1);
void kaj_map_set_cell_ready(void);
void kaj_map_set_room_ready(void);
void kaj_map_room_loaded_slots(s16 *arg0, s32 *arg1);
typedef struct {
    s32 unk0;
    struct {
        u8 pad0[0x18];
        s32 unk18;
        s32 unk1C;
        s32 unk20;
    } *unk4;
    struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
        s32 unkC;
        TmdTri *unk10;
        s32 unk14;
    } *unk8;
} Unk_8017BBB0;
typedef struct {
    u8 pad0[0x10];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 pad16[0x6];
    s16 unk1C[0x10];
    u8 pad3C[0x80];
    Unk_8017BBB0 *unkBC;
} Unk_801E032C;
extern Unk_801E032C *D_801E032C[];
s32 block_hit_tris(TmdTri *arg0, s32 arg1, s32 arg2, Vec3 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
s32 block_hit_quads(TmdTri *arg0, s32 arg1, s32 arg2, Vec3 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
char *strncpy(char *dst, char *src, u32 n);
extern char D_801DFCBC[];
extern s16 D_801DFC74;
s16 text_col;
s16 text_color;
s16 text_len;
s32 strlen(char *s);
/* Local view of SceneRequest: this unit reads 0x14-0x19 as halfwords, the shared type has two s32 there. */
typedef struct {
    s16 unk0[5];
    s16 unkA;
    char *unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    u16 unk18;
    u8 pad1A[0x2];
    s32 unk1C;
    u8 unk20[0x10];
} SceneRequest_u80179848;
extern SceneRequest_u80179848 scene_request;
void object_load_res(s32 arg0, s32 arg1);
void mail_list_open(void);
void menu_list_page(PauseMenu *arg0, s32 arg1, s32 arg2);
void menu_status_page(PauseMenu *arg0, s32 arg1);
void menu_options_page(PauseMenu *arg0, s32 arg1, s16 arg2);
void object_load_mail_by_id(s16 arg0);
void text_narration_step(TssSlot *arg0);
void text_narration_end(void);
void *kaj_tss_alloc(u32 arg0);
s32 kaj_tss_start(void *arg0);
DoorList *door_list;
void RotMatrix(SVector *arg0, void *arg1);
Block *block_find_at(s32 arg0, s32 arg1, s32 arg2);
typedef struct {
    Unk_8018519C_0 *unk0;
    s32 unk4;
    char **unk8;
} Unk_8018519C;
s32 atoi(char *s);
void door_start_open(DoorMove *arg0, s16 arg1, s16 arg2, s16 arg3);
void door_start_close(DoorMove *arg0, s16 arg1, s16 arg2);
extern char D_80170290[];
s32 func_801BDC30(double arg0, double arg1);
s16 block_point_in_poly(Unk_8017AC88 *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 block_poly_height(Unk_8017AC88 *arg0, SVector *arg1, s32 arg2, s32 arg3, s32 arg4);
s32 abs(s32 x);
BuildingState block_building_state;
void text_next_page(Unk_80184100 *arg0);
void text_close(void);
void text_show_profile(s16 arg0);
void sprite_station_board_train(s16 arg0);
void effect_elevator_init(s16 arg0);
void sprite_station_exit_to_town(void);
void roadmap_shop_exit_to_town(s16 arg0, s16 arg1);
void roadmap_shop_open_menu(s16 arg0, s32 arg1);
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void *action_find_set(s16 arg0);
void *action_run_set(void *arg0, s32 arg1, s32 arg2);
extern PlayerStatus player_status;
extern KajSystem kaj_system;
typedef struct {
    u8 pad0[0x4];
    s16 unk4;
    u8 pad6[0x2];
    s16 unk8;
    u8 padA[0x12];
    char **unk1C;
} Unk_801E1058;
extern Unk_801E1058 D_801E1058[];
s32 kaj_pad_read(void);
s16 effect_item_input(PlayerStatus *arg0, s16 arg1);
s16 roadmap_shop_update_input(PlayerStatus *arg0);
s16 effect_weapon_input(PlayerStatus *arg0);
void block_on_action(PlayerStatus *arg0);
void player_handle_pad(PlayerStatus *arg0, s32 arg1, s32 arg2);
s16 block_scene_daylight;
extern s32 (*D_801DFED4)(KajEvent *arg0);
extern s32 (*D_801DFEE4)(KajEvent *arg0);
s32 block_on_effect_done(KajEvent *arg0);
s32 block_on_enter(KajEvent *arg0);
void action_reset(s16 arg0);
void block_set_mode(u16 arg0);
int sprintf(char *buf, const char *fmt, ...);
void object_load_scene(void);
void effect_weapon_load_models(void);
void thing_set_active(s32 arg0, s32 arg1, s16 arg2);
void thing_set_animate(s32 arg0, s32 arg1, s16 arg2);
void mod_npcrec_show(u16 arg0, s16 arg1);
void effect_flame_small_init(s16 arg0);
void effect_flame_large_init(void);
void sprite_station_init(void);
void roadmap_shop_init(s16 arg0);
void event_show_clock(s16 arg0);
extern void (*D_801DFEDC)(void);
extern s32 (*D_801DFEE0)();
void block_building_load(void);
void block_update_input(void);
void kaj_timer_enable(void);
void kaj_timer_disable(void);
void kaj_pad_reset(s32 arg0);
s32 kaj_event_get(s32 *arg0);
void kaj_event_done(s32 *arg0);
void event_handle_enter(s32 *arg0);
void roadmap_shop_close_topic(void);
void event_handle_leave(s32 *arg0);
void event_handle_tick(s16 arg0);
void event_handle_mod_finish(s32 *arg0);
s16 mail_take_scene_change(void);
s16 event_handle_effect_done(s32 *arg0);
void mail_step_frame(u16 arg0, s16 arg1, s16 arg2);
void block_stream_stop(void);
void sound_bgm_stop(void);
void sound_se_stop_all(void);
void effect_flame_small_free(void);
void effect_flame_large_free(void);
void action_free_triggers(void);
void npc_free_all(void);
void npc_free_bodies(void);
void npc_free_stats(void);
void effect_weapon_reset(void);
void action_free_all_sets(void);
void block_free_all(void);
void door_free_all(void);
void mod_free_all(void);
void thing_free_all(void);
void sound_bgm_close(void);
void sound_se_pop_scene(void);
void block_elevator_input(s16 arg0, s16 arg1, s16 *arg2);
void event_handle_tick(s16 a);
void event_advance_clock(s16 a, s16 b);
void mail_wait(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void roadmap_draw_frame(u16 a);
extern char D_801702B0[];
extern char D_801702C8[];
s32 kaj_map_open_city(void);
s16 kaj_map_load_city_dir(void);
s16 kaj_map_city_ready(void);
s32 kaj_map_open_place(s16 arg0, void *arg1);
s16 kaj_map_load_place_dir(void);
void kaj_map_get_entry(u16 arg0, s32 *arg1, u8 *arg2);
void player_place_for_scene(s32 arg0);
s32 kaj_map_place_ready(void);
void door_refresh_all(void);
void sprite_thing_refresh_all(void);
void RotTrans(void *v0, s32 *v1, s32 *flag);
void mail_goto_twn(s32 a, s32 b, s32 c, s16 d, s16 e);
extern s32 block_elevator_stops[];
typedef struct {
    s32 unk0;
    s32 unk4;
} Unk_80179848_14;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    union {
        struct {
            s32 unkC;
            s32 unk10;
        } s;
        struct {
            u16 unkC;
            u16 unkE;
            u16 unk10;
            s16 unk12;
        } h;
    } unkC;
    Unk_80179848_14 unk14[1];
} Unk_80179848;
void GsInitCoordinate2(void *super, void *base);
void kaj_tmd_load(void *arg0, void *arg1, void *arg2);
extern TrainState vehicle_train_state;
extern s16 D_801DFF78;
extern s32 block_wake_positions[];
void sound_bgm_play(s32 arg0);
void sound_se_play_note(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5, s16 arg6);
void sprite_station_show_prompt(s16 arg0);
s16 roadmap_shop_finish(s16 arg0);
void player_rest(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
void player_recover(s32 arg0, s32 arg1, s32 arg2, s16 arg3);
s32 SquareRoot0(s32 arg0);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_8017A108;
extern CarState vehicle_car_state;
s32 block_test_player_inside(Player *arg0, u16 arg1, Block *arg2, s32 *arg3, s32 *arg4);
void GsSetLsMatrix(void *m);
s32 mail_angle_to_dir8(s16 a);
s32 rsin(s32 a);
s32 rcos(s32 a);
s32 ratan2(s32 y, s32 x);

void block_setup(Block *arg0, u16 arg1) {
    s32 sp10[5];
    Player *m;
    Unk_80179848 *d;
    Unk_8017CAC8 *s;
    Arena **p;
    s32 i;

    m = player_status_player[0];
    memset(sp10, 0, 0x14);
    if (arg1 == 2) {
        d = arg0->data;
        arg0->pos_x = d->unk4 * 100;
        arg0->pos_y = 0;
        arg0->pos_z = d->unk0 * 100;
        arg0->size_x = d->unkC.s.unkC * 100;
        arg0->size_y = 0;
        arg0->size_z = d->unk8 * 100;
        arg0->far = 1;
        for (i = 0; i < d->unkC.s.unk10; i++) {
            sp10[d->unk14[i].unk0] = d->unk14[i].unk4;
        }
    } else {
        d = arg0->data;
        arg0->visible = 1;
        arg0->player_inside = 1;
        arg0->pos_x = d->unk0;
        arg0->pos_y = d->unk4;
        arg0->pos_z = d->unk8;
        arg0->size_x = d->unkC.h.unkC;
        arg0->size_y = d->unkC.h.unkE;
        arg0->size_z = d->unkC.h.unk10;
        arg0->far = 0;
        for (i = 0; i < d->unkC.h.unk12; i++) {
            sp10[d->unk14[i].unk0] = d->unk14[i].unk4;
        }
    }
    arg0->model_flags = 0;
    if (sp10[0] != 0) {
        kaj_tmd_load(&arg0->floor_model, (u8 *)arg0->data + sp10[0], &arg0->coord_flg);
        arg0->model_flags |= 1;
    }
    if (sp10[1] != 0) {
        kaj_tmd_load(&arg0->model1, (u8 *)arg0->data + sp10[1], &arg0->coord_flg);
        arg0->model_flags |= 2;
    }
    if (sp10[2] != 0) {
        kaj_tmd_load(&arg0->model2, (u8 *)arg0->data + sp10[2], &arg0->coord_flg);
        arg0->model_flags |= 4;
    }
    if (sp10[3] != 0) {
        kaj_tmd_load(&arg0->model3, (u8 *)arg0->data + sp10[3], &arg0->coord_flg);
        arg0->model_flags |= 8;
    }
    if (sp10[4] != 0) {
        p = &arg0->arena;
        s = (Unk_8017CAC8 *)((u8 *)arg0->data + sp10[4]);
        if (*p == NULL) {
            *p = kaj_malloc(0x10);
            if (*p == NULL) {
                kaj_abend(3, "Error Allocating Arena Buffer", D_801DFC84, 0x49);
            }
        } else {
            memset(*p, 0, 0x10);
        }
        (*p)->unk0 = s->unk0;
        (*p)->unk2 = s->unk2;
        (*p)->unk4 = s->unk4;
        (*p)->unk6 = s->unk6;
        (*p)->data = s + 1;
        (*p)->cells = s;
        arg0->model_flags |= 0x10;
    }
    GsInitCoordinate2(NULL, &arg0->coord_flg);
    arg0->coord_tx = arg0->pos_x - m->cell_x * 12500;
    arg0->coord_ty = arg0->pos_y + m->cell_y * 32000;
    arg0->coord_tz = arg0->pos_z - m->cell_z * 12500;
    arg0->coord_flg = 0;
    arg0->active = 1;
}

INCLUDE_ASM("asm/nonmatchings/game/80179848", block_draw_all);

s32 block_test_player_inside(Player *arg0, u16 arg1, Block *arg2, s32 *arg3, s32 *arg4) {
    s32 a;
    s32 sp10[2];
    s32 b;
    s32 d;
    s32 f;
    s32 x;
    s32 z;
    s32 w;
    s32 h;
    Arena *p;
    s32 *v3 = arg3;

    v3[0] = arg2->coord_tx - arg0->pos_x;
    arg4[0] = arg2->size_x + v3[0];
    v3[1] = arg0->pos_y - arg0->unk78 - arg2->coord_ty;
    arg4[1] = arg2->size_y + v3[1];
    v3[2] = arg2->coord_tz - arg0->pos_z;
    arg4[2] = arg2->size_z + v3[2];
    if (arg1 == 2) {
        a = arg4[0] >> 1;
        b = arg4[2] >> 1;
        d = SquareRoot0(a * a + b * b);
        arg2->far = 1;
        if (arg2->size_x < 5001 && arg2->size_z < 5001) {
            f = d < 3537;
        } else {
            f = d < 7073;
        }
        if (f) {
            arg2->far = 0;
        }
    } else {
        arg2->far = 0;
    }
    if (arg2->model_flags & 0x10) {
        p = arg2->arena;
        x = arg0->pos_x + arg0->cell_x * 12500 - arg2->pos_x;
        z = arg0->pos_z + arg0->cell_z * 12500 - arg2->pos_z;
        h = x >> 8;
        w = p->unk0;
        x = (x & 0xFF) ? (f = w + 1, h + f) : h + w;
        h = z >> 8;
        w = p->unk2;
        z = (z & 0xFF) ? (f = w + 1, h + f) : h + w;
        if (x >= 0 && x < p->unk4 && z >= 0 && z < p->unk6) {
            arg2->in_arena = 1;
        }
    }
    if (v3[0] > 0 || arg4[0] <= 0 || v3[2] > 0 || arg4[2] <= 0) {
        return 0;
    }
    if (arg1 == 1 && (s16)arg0->unk40 != 0 && (v3[1] > 0 || arg4[1] < 0)) {
        return 0;
    }
    return 1;
}

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170270);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_80170290);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_801702B0);

INCLUDE_RODATA("asm/nonmatchings/game/80179848", D_801702C8);

static inline s32 func_8017A108_1(Player *o, s32 *lo, s32 *hi) {
    CarState *q = &vehicle_car_state;
    s32 sp38[4];
    s32 sp48;
    s32 i;
    GsSetLsMatrix(D_801E032C[0]->unk1C);
    for (i = 0; i < 4; i++) {
        RotTrans(&q->corners[i], sp38, &sp48);
        sp38[0] -= o->pos_x;
        sp38[2] -= o->pos_z;
        if (sp38[0] >= lo[0] && sp38[0] < hi[0] && sp38[2] >= lo[2] && sp38[2] < hi[2]) {
            return 1;
        }
    }
    return 0;
}

static inline s16 func_8017A108_2(s32 dir, s32 *lo, s32 *hi) {
    switch (dir) {
    case 2:
        if (hi[2] >= 0) {
            break;
        }
        return 0;
    case 0:
        if (hi[0] >= 0) {
            break;
        }
        return 0;
    case 6:
        if (lo[2] > 0) {
            return 0;
        }
        break;
    case 4:
        if (lo[0] > 0) {
            return 0;
        }
        break;
    case 1:
        if (lo[0] >= 0 || lo[2] >= 0) {
            break;
        }
        return 0;
    case 3:
        if (hi[0] <= 0 || lo[2] >= 0) {
            break;
        }
        return 0;
    case 5:
        if (hi[0] <= 0 || hi[2] <= 0) {
            break;
        }
        return 0;
    case 7:
        if (lo[0] >= 0 || hi[2] <= 0) {
            break;
        }
        return 0;
    }
    return 1;
}

void block_update_visibility(u16 arg0) {
    BlockList *list = block_list;
    Player *o = player_status_player[0];
    Block *e;
    s32 sp18[4];
    s32 sp28[4];

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        e = list->cursor->data;
        if (e != NULL && e->active != 0) {
            e->in_arena = 0;
            e->player_inside = block_test_player_inside(o, arg0, e, sp18, sp28);
            if (e->player_inside != 0) {
                e->visible = 1;
            } else if (arg0 == 2) {
                if (o->vehicle_mode == 1 && func_8017A108_1(o, sp18, sp28) && e->player_inside == 0) {
                    e->player_inside = 1;
                    e->visible = 1;
                } else {
                    e->visible = func_8017A108_2((s16)mail_angle_to_dir8(o->yaw), sp18, sp28);
                }
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            return;
        }
        list->cursor = list->cursor->next;
    }
}

void block_create_all(void) {
    s32 i;

    for (i = 0; i < 12; i++) {
        block_slots[i] = kaj_malloc(0x90);
        if (block_slots[i] == NULL) {
            kaj_abend(3, D_80170270, D_801DFC84, 0x5D);
        }
        block_slots[i]->active = 0;
        block_slots[i]->owns_data = 0;
        block_slots[i]->visible = 0;
        block_slots[i]->player_inside = 0;
        block_slots[i]->in_arena = 0;
        block_slots[i]->far = 1;
        block_slots[i]->model_flags = 0;
        block_slots[i]->model3 = NULL;
        block_slots[i]->model2 = NULL;
        block_slots[i]->model1 = NULL;
        block_slots[i]->floor_model = NULL;
        block_slots[i]->arena = NULL;
        block_slots[i]->data = NULL;
        block_slots[i]->active = 0;
        block_slots[i]->model_flags = 0;
        {
            Block *e = block_slots[i];

            if (block_list->count == 0) {
                kaj_ll_insert_before(block_list, (s32)e);
            } else {
                block_list->cursor = block_list->tail;
                kaj_ll_insert_after(block_list, (s32)e);
            }
        }
    }
}

void block_load_all(u16 arg0) {
    s32 sp10[12];
    s16 sp40;
    s32 i;
    Block *e;
    s32 r;
    s32 t;
    void **p;

    D_801DFC80 = 1;
    sp40 = 12;
    if (arg0 == 2) {
        kaj_map_cell_slots(&sp40, sp10);
    } else {
        kaj_map_room_slots(&sp40, sp10);
    }
    for (i = 0; i < 12; i++) {
        e = block_slots[i];
        e->active = 0;
        e->data = NULL;
        if (i < sp40) {
            r = (s16)kaj_cdmgr_is_fresh(sp10[i]);
            t = kaj_cdmgr_get_type(sp10[i]);
            p = kaj_cdmgr_get(sp10[i]);
            if (t == 5) {
                if (p != NULL && r != 0) {
                    mod_create(*p);
                    kaj_cdmgr_mark_used(sp10[i]);
                    continue;
                }
            } else if (t == 6) {
                if (p != NULL && r != 0) {
                    kaj_tim_upload_hdr(*p);
                    kaj_cdmgr_mark_used(sp10[i]);
                    kaj_map_room_release(sp10[i]);
                    continue;
                }
            } else if (p != NULL) {
                e->data = *p;
                block_setup(e, arg0);
            }
        }
    }
    if (arg0 == 1) {
        npc_update_blocks();
    }
}

void block_set_zone_flags(s32 arg0, s32 arg1) {
    GameVars *p = &action_vars;

    p->unk252 = 0;
    p->unk250 = 0;
    p->unk254 = 0;
    if (arg0 >= 0x3CF && arg0 < 0x433 && arg1 > 0x8B0 && arg1 < 0xA0F) {
        p->unk252 = 1;
        p->unk250 = 1;
        p->unk254 = 1;
        return;
    }
    if ((arg0 >= 0x3CF && arg0 < 0x4C9 && arg1 >= -0x19 && arg1 < 0x8B1) ||
        (arg0 >= 0x36B && arg0 < 0x3CF && arg1 >= 0x23F && arg1 < 0x307) ||
        (arg0 >= 0x433 && arg0 < 0x497 && arg1 >= -0x1A9 && arg1 < -0xE1) ||
        (arg0 >= 0x81B && arg0 < 0x9AB && arg1 >= 0x1A9 && arg1 < 0x401) ||
        (arg0 >= -0x4FB && arg0 < -0x401 && arg1 >= 0x5F5 && arg1 < 0x9DD) ||
        (arg0 >= -0x591 && arg0 < -0x4C9 && arg1 >= -0x4B && arg1 < 0x1A9) ||
        (arg0 >= -0x591 && arg0 < -0x497 && arg1 >= -0x4C9 && arg1 < -0x23F) ||
        (arg0 >= 0x2D5 && arg0 < 0x433 && arg1 < -0x4C9) ||
        (arg0 >= 0x2D5 && arg0 < 0x433 && arg1 < -0x23F) ||
        arg1 < -0x4C9) {
        p->unk254 = 1;
    }
}

void block_set_mode(u16 arg0) {
    s32 sp10[4];
    SceneRequest_u80179848 *g = &scene_request;
    Player *o = player_status_player[0];
    GameVars *p;

    if (arg0 == 2) {
        if (kaj_map_open_city() != 0) {
            kaj_abend(4, D_801702B0, D_801DFC84, 0x2EC);
        }
        while (kaj_map_load_city_dir() == 0) {
            kaj_cdmgr_poll();
        }
        while (kaj_map_city_ready() == 0) {
            kaj_map_update_city(o->unk68, o->unk60);
            if (kaj_cdmgr_poll() != 0) {
                kaj_map_set_cell_ready();
            }
        }
        block_set_zone_flags(o->unk60, o->unk68);
    } else {
        if (kaj_map_open_place(g->unk16, g->unk20) != 0) {
            kaj_abend(4, D_801702C8, D_801DFC84, 0x2F8);
        }
        while (kaj_map_load_place_dir() == 0) {
            kaj_cdmgr_poll();
        }
        block_building_id = g->unk18;
        kaj_map_get_entry(block_building_id, sp10, &D_801DFC8C);
        p = &action_vars;
        p->unk252 = 0;
        p->unk250 = 0;
        switch (D_801DFC8D[0]) {
        case 1:
            p->unk252 = 1;
            break;
        case 2:
            p->unk250 = 1;
            break;
        case 3:
            p->unk252 = 1;
            p->unk250 = 1;
            break;
        }
        o->pos_x = sp10[0];
        o->pos_y = sp10[1];
        o->pos_z = sp10[2];
        player_place_for_scene(1);
        while (kaj_map_place_ready() == 0) {
            kaj_map_update_place(block_building_id, &D_801DFC8C);
            if (kaj_cdmgr_poll() != 0) {
                kaj_map_set_room_ready();
            }
        }
    }
    block_load_all(arg0);
    door_refresh_all();
    sprite_thing_refresh_all();
    D_801DFC80 = 0;
}

void block_stream_update(u16 arg0) {
    s32 sp10[12];
    s16 sp40;
    Player *o = player_status_player[0];
    s32 r;
    s32 i;
    Block *e;
    void **p;

    D_801DFC80 = 0;
    if (arg0 == 2) {
        r = kaj_map_update_city(o->unk68, o->unk60);
        block_set_zone_flags(o->unk60, o->unk68);
    } else {
        r = kaj_map_update_place(block_building_id, &D_801DFC8C);
    }
    if (r == 3) {
        D_801DFC80 = 1;
        sp40 = 12;
        if (arg0 == 2) {
            kaj_map_cell_loaded_slots(&sp40, sp10);
        } else {
            kaj_map_room_loaded_slots(&sp40, sp10);
        }
        for (i = 0; i < 12; i++) {
            e = block_slots[i];
            e->active = 0;
            e->data = NULL;
            if (i < sp40) {
                s32 t = kaj_cdmgr_get_type(sp10[i]);
                if (t != 5 && t != 6) {
                    p = kaj_cdmgr_get(sp10[i]);
                    if (p != NULL) {
                        e->data = *p;
                        block_setup(e, arg0);
                    }
                }
            }
        }
        if (arg0 == 1) {
            npc_update_blocks();
        }
        kaj_cdmgr_poll();
    } else if (r == 1 || kaj_cdmgr_poll() != 0) {
        if (arg0 == 2) {
            kaj_map_set_cell_ready();
        } else {
            kaj_map_set_room_ready();
        }
        block_load_all(arg0);
    }
}

s16 block_point_in_poly(Unk_8017AC88 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    double sp10[2];
    double x0;
    double z0;
    double x1;
    double z1;
    double px;
    double pz;
    double t;
    s32 i;
    s32 j;
    s32 n;

    px = arg2;
    pz = arg3;
    n = 0;
    for (i = 0; i < arg1; i++) {
        j = (i + 1) % arg1;
        x0 = arg0[i].unk0;
        z0 = arg0[i].unk8;
        x1 = arg0[j].unk0;
        z1 = arg0[j].unk8;
        if (func_801BDC30(z0, z1)) {
            t = (pz - z0) / (z1 - z0);
            if (!(t < 0.0) && !(t > 1.0)) {
                sp10[n] = (x1 - x0) * t + x0;
                if (n != 1 || func_801BDC30(sp10[0], sp10[1])) {
                    if (px < sp10[n]) {
                        n++;
                    }
                    if (n == 2) {
                        break;
                    }
                }
            }
        }
    }
    return n % 2;
}

s32 block_poly_height(Unk_8017AC88 *arg0, SVector *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 maxx;
    s32 minx;
    s32 maxz;
    s32 minz;

    if (arg2 == 4) {
        if (arg0[0].unk0 > arg0[1].unk0) {
            maxx = arg0[0].unk0;
            minx = arg0[1].unk0;
        } else {
            minx = arg0[0].unk0;
            maxx = arg0[1].unk0;
        }
        if (maxx < arg0[2].unk0) {
            maxx = arg0[2].unk0;
        } else if (arg0[2].unk0 < minx) {
            minx = arg0[2].unk0;
        }
        if (maxx < arg0[3].unk0) {
            maxx = arg0[3].unk0;
        } else if (arg0[3].unk0 < minx) {
            minx = arg0[3].unk0;
        }
        if (arg0[0].unk8 > arg0[1].unk8) {
            maxz = arg0[0].unk8;
            minz = arg0[1].unk8;
        } else {
            minz = arg0[0].unk8;
            maxz = arg0[1].unk8;
        }
        if (maxz < arg0[2].unk8) {
            maxz = arg0[2].unk8;
        } else if (arg0[2].unk8 < minz) {
            minz = arg0[2].unk8;
        }
        if (maxz < arg0[3].unk8) {
            maxz = arg0[3].unk8;
        } else if (arg0[3].unk8 < minz) {
            minz = arg0[3].unk8;
        }
    } else {
        if (arg0[0].unk0 > arg0[1].unk0) {
            maxx = arg0[0].unk0;
            minx = arg0[1].unk0;
        } else {
            minx = arg0[0].unk0;
            maxx = arg0[1].unk0;
        }
        if (maxx < arg0[2].unk0) {
            maxx = arg0[2].unk0;
        } else if (arg0[2].unk0 < minx) {
            minx = arg0[2].unk0;
        }
        if (arg0[0].unk8 > arg0[1].unk8) {
            maxz = arg0[0].unk8;
            minz = arg0[1].unk8;
        } else {
            minz = arg0[0].unk8;
            maxz = arg0[1].unk8;
        }
        if (maxz < arg0[2].unk8) {
            maxz = arg0[2].unk8;
        } else if (arg0[2].unk8 < minz) {
            minz = arg0[2].unk8;
        }
    }
    if (arg3 < minx || maxx < arg3 || arg4 < minz || maxz < arg4) {
        return 99999999;
    }
    if (block_point_in_poly(arg0, arg2, arg3, arg4) == 0) {
        return 99999999;
    }
    if (arg1->vy == 0) {
        return 99999999;
    }
    return (arg0[2].unk0 * arg1->vx + arg0[2].unk4 * arg1->vy + arg0[2].unk8 * arg1->vz
            - (arg1->vx * arg3 + arg1->vz * arg4)) / arg1->vy;
}

s32 block_hit_tris(TmdTri *arg0, s32 arg1, s32 arg2, Vec3 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    Unk_8017AC88 sp18[3];
    s32 i;
    TmdTri *e;
    s32 r;

    e = arg0;
    for (i = 0; i < arg4; i++, e++) {
        sp18[0].unk0 = ((SVector *)arg1)[e->vert0].vx + arg3->x;
        sp18[0].unk4 = ((SVector *)arg1)[e->vert0].vy + arg3->y;
        sp18[0].unk8 = ((SVector *)arg1)[e->vert0].vz + arg3->z;
        sp18[1].unk0 = ((SVector *)arg1)[e->vert1].vx + arg3->x;
        sp18[1].unk4 = ((SVector *)arg1)[e->vert1].vy + arg3->y;
        sp18[1].unk8 = ((SVector *)arg1)[e->vert1].vz + arg3->z;
        sp18[2].unk0 = ((SVector *)arg1)[e->vert2].vx + arg3->x;
        sp18[2].unk4 = ((SVector *)arg1)[e->vert2].vy + arg3->y;
        sp18[2].unk8 = ((SVector *)arg1)[e->vert2].vz + arg3->z;
        r = block_poly_height(sp18, (SVector *)arg2 + e->normal, 3, arg5, arg6);
        *(s32 *)arg7 = r;
        if (r != 99999999) {
            return (e->code_r << 16) | (e->code_g << 8) | e->code_b;
        }
    }
    return 0;
}

s32 block_hit_quads(TmdTri *arg0, s32 arg1, s32 arg2, Vec3 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7) {
    Unk_8017AC88 sp18[4];
    struct {
        u16 unk0;
        u8 unk2;
        u8 unk3;
        u8 unk4;
        u8 unk5;
        u8 unk6;
        u8 pad7[0x1];
        u16 unk8;
        u16 unkA;
        u16 unkC;
        u16 unkE;
        u16 unk10;
        u8 pad12[0x2];
    } *e;
    s32 i;
    s32 r;
    s32 ret;
    s32 minx;
    s32 maxx;
    s32 minz;
    s32 maxz;
    Player *m;
    Unk_8017AC88 *p;

    e = (void *)arg0;
    for (i = 0; i < arg4; i++, e++) {
        sp18[0].unk0 = ((SVector *)arg1)[e->unkA].vx + arg3->x;
        sp18[0].unk4 = ((SVector *)arg1)[e->unkA].vy + arg3->y;
        sp18[0].unk8 = ((SVector *)arg1)[e->unkA].vz + arg3->z;
        sp18[1].unk0 = ((SVector *)arg1)[e->unkC].vx + arg3->x;
        sp18[1].unk4 = ((SVector *)arg1)[e->unkC].vy + arg3->y;
        sp18[1].unk8 = ((SVector *)arg1)[e->unkC].vz + arg3->z;
        sp18[3].unk0 = ((SVector *)arg1)[e->unkE].vx + arg3->x;
        sp18[3].unk4 = ((SVector *)arg1)[e->unkE].vy + arg3->y;
        sp18[3].unk8 = ((SVector *)arg1)[e->unkE].vz + arg3->z;
        sp18[2].unk0 = ((SVector *)arg1)[e->unk10].vx + arg3->x;
        sp18[2].unk4 = ((SVector *)arg1)[e->unk10].vy + arg3->y;
        sp18[2].unk8 = ((SVector *)arg1)[e->unk10].vz + arg3->z;
        r = block_poly_height(sp18, (SVector *)arg2 + e->unk8, 4, arg5, arg6);
        *(s32 *)arg7 = r;
        if (r != 99999999) {
            ret = (e->unk4 << 16) | (e->unk5 << 8) | e->unk6;
            if (e->unk4 == 0xFF) {
                m = player_status_player[0];
                p = (Unk_8017AC88 *)&m->unk18; /* this unit reads +0x18 as two quads */
                if (sp18[0].unk0 > sp18[1].unk0) {
                    maxx = sp18[0].unk0;
                    minx = sp18[1].unk0;
                } else {
                    minx = sp18[0].unk0;
                    maxx = sp18[1].unk0;
                }
                if (maxx < sp18[2].unk0) {
                    maxx = sp18[2].unk0;
                } else if (sp18[2].unk0 < minx) {
                    minx = sp18[2].unk0;
                }
                if (maxx < sp18[3].unk0) {
                    maxx = sp18[3].unk0;
                } else if (sp18[3].unk0 < minx) {
                    minx = sp18[3].unk0;
                }
                if (sp18[0].unk8 > sp18[1].unk8) {
                    maxz = sp18[0].unk8;
                    minz = sp18[1].unk8;
                } else {
                    minz = sp18[0].unk8;
                    maxz = sp18[1].unk8;
                }
                if (maxz < sp18[2].unk8) {
                    maxz = sp18[2].unk8;
                } else if (sp18[2].unk8 < minz) {
                    minz = sp18[2].unk8;
                }
                if (maxz < sp18[3].unk8) {
                    maxz = sp18[3].unk8;
                } else if (sp18[3].unk8 < minz) {
                    minz = sp18[3].unk8;
                }
                p[1].unk0 = m->cell_x * 12500 + ((minx + maxx) >> 1);
                p[1].unk8 = m->cell_z * 12500 + ((minz + maxz) >> 1);
            }
            return ret;
        }
    }
    return 0;
}

s16 block_point_on_model(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4) {
    Unk_8017AC88 sp18[4];
    s32 flag;
    Unk_8017BBB0 *q;
    struct {
        u16 unk0;
        u8 unk2;
        u8 unk3;
        u8 unk4;
        u8 unk5;
        u8 unk6;
        u8 pad7[0x1];
        u16 unk8;
        u16 unkA;
        u16 unkC;
        u16 unkE;
        u16 unk10;
        u8 pad12[0x2];
    } *e;
    Player *m;
    SVector *v;
    SVector *b;
    s32 n;
    s32 cnt;
    s32 i;
    s32 min;
    s32 max;

    q = arg0;
    e = (void *)q->unk8->unk10;
    n = q->unk8->unk14;
    m = player_status_player[0];
    v = (SVector *)q->unk8->unk0;
    b = (SVector *)q->unk8->unk8;
    while (n != 0) {
        cnt = e->unk0;
        if ((e->unk3 & 0xFD) == 0x20) {
            for (i = 0; i < cnt; e = (void *)((TmdTri *)e + 1), i++) {
                RotTrans(&v[e->unkA], &sp18[0].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&v[e->unkC], &sp18[1].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&v[e->unkE], &sp18[2].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                if (block_poly_height(sp18, &b[e->unk8], 3, arg1, arg3) != 99999999) {
                    if (arg4 != 1) {
                        return 1;
                    }
                    if (sp18[0].unk4 > sp18[1].unk4) {
                        max = sp18[0].unk4;
                        min = sp18[1].unk4;
                    } else {
                        min = sp18[0].unk4;
                        max = sp18[1].unk4;
                    }
                    if (max < sp18[2].unk4) {
                        max = sp18[2].unk4;
                    } else if (sp18[2].unk4 < min) {
                        min = sp18[2].unk4;
                    }
                    if (min == max) {
                        if (arg2 >= max + m->unk78 && arg2 <= max - m->unk78) {
                            return 1;
                        }
                    } else if (arg2 >= min && arg2 <= max) {
                        return 1;
                    }
                }
            }
            n -= cnt;
        } else if ((e->unk3 & 0xFD) == 0x28) {
            for (i = 0; i < cnt; e++, i++) {
                RotTrans(&v[e->unkA], &sp18[0].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&v[e->unkC], &sp18[1].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&v[e->unkE], &sp18[3].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                RotTrans(&v[e->unk10], &sp18[2].unk0, &flag);
                if (flag < 0) {
                    return 0;
                }
                if (block_poly_height(sp18, &b[e->unk8], 4, arg1, arg3) != 99999999) {
                    if (arg4 != 1) {
                        return 1;
                    }
                    if (sp18[0].unk4 > sp18[1].unk4) {
                        max = sp18[0].unk4;
                        min = sp18[1].unk4;
                    } else {
                        min = sp18[0].unk4;
                        max = sp18[1].unk4;
                    }
                    if (max < sp18[2].unk4) {
                        max = sp18[2].unk4;
                    } else if (sp18[2].unk4 < min) {
                        min = sp18[2].unk4;
                    }
                    if (max < sp18[3].unk4) {
                        max = sp18[3].unk4;
                    } else if (sp18[3].unk4 < min) {
                        min = sp18[3].unk4;
                    }
                    if (min == max) {
                        if (arg2 >= max + m->unk78 && arg2 <= max - m->unk78) {
                            return 1;
                        }
                    } else if (arg2 >= min && arg2 <= max) {
                        return 1;
                    }
                }
            }
            n -= cnt;
        } else {
            return 0;
        }
    }
    return 0;
}

s32 func_8017BBB0(s32 arg0, s32 arg1, s32 arg2) {
    Vec3 sp20;
    TmdTri *e;
    s32 n;
    s32 a;
    s32 b;
    s32 cnt;
    s32 r;
    s32 t;
    Unk_8017BBB0 *q;

    q = D_801E032C[0]->unkBC;
    sp20.x = q->unk4->unk18;
    sp20.y = q->unk4->unk1C;
    sp20.z = q->unk4->unk20;
    e = q->unk8->unk10;
    n = q->unk8->unk14;
    a = q->unk8->unk0;
    b = q->unk8->unk8;
    while (n != 0) {
        cnt = e->unk0;
        switch (e->mode & 0xFD) {
        case 0x20:
            t = block_hit_tris(e, a, b, &sp20, cnt, arg0, arg1, arg2);
            if (t != 0) {
                r = t;
                goto end;
            }
            n -= cnt;
            e = (TmdTri *)((u8 *)e + cnt * 0x10);
            break;
        case 0x28:
            t = block_hit_quads(e, a, b, &sp20, cnt, arg0, arg1, arg2);
            if (t != 0) {
                r = t;
                goto end;
            }
            n -= cnt;
            e = (TmdTri *)((u8 *)e + cnt * 0x14);
            break;
        default:
            r = 0;
            goto end;
        }
    }
    r = 0;
end:
    if (r != 0) {
        return r;
    }
    return 0;
}

s32 block_find_surface(s32 arg0, s32 arg1, s32 *arg2, s16 arg3) {
    BlockList *p = block_list;
    Vec3 sp20;
    TmdTri *e;
    s32 n;
    s32 a;
    s32 b;
    s32 cnt;
    s32 r;
    s32 t;
    s32 f;
    Unk_8017BBB0 *q;

    if (p->count == 0) {
        return 0;
    }
    *arg2 = 0;
    f = arg3;
    p->cursor = p->head;
    while (1) {
        Block *o = p->cursor->data;
        if (o != NULL && o->active != 0 && (o->model_flags & 1) && (f != 0 || o->player_inside != 0)) {
            q = o->floor_model;
            sp20.x = q->unk4->unk18;
            sp20.y = q->unk4->unk1C;
            sp20.z = q->unk4->unk20;
            e = q->unk8->unk10;
            n = q->unk8->unk14;
            a = q->unk8->unk0;
            b = q->unk8->unk8;
            while (n != 0) {
                cnt = e->unk0;
                switch (e->mode & 0xFD) {
                case 0x20:
                    t = block_hit_tris(e, a, b, &sp20, cnt, arg0, arg1, (s32)arg2);
                    if (t != 0) {
                        r = t;
                        goto found;
                    }
                    n -= cnt;
                    e = (TmdTri *)((u8 *)e + cnt * 0x10);
                    break;
                case 0x28:
                    t = block_hit_quads(e, a, b, &sp20, cnt, arg0, arg1, (s32)arg2);
                    if (t != 0) {
                        r = t;
                        goto found;
                    }
                    n -= cnt;
                    e = (TmdTri *)((u8 *)e + cnt * 0x14);
                    break;
                default:
                    r = 0;
                    goto found;
                }
            }
            r = 0;
        found:
            if (r != 0) {
                return r;
            }
        }
        if (kaj_ll_at_tail(p) != 0) {
            return 0;
        }
        p->cursor = p->cursor->next;
    }
}

s32 block_find_surface_nearest(s32 arg0, s32 arg1, s32 arg2, s32 *arg3) {
    BlockList *p = block_list;
    Vec3 hits[12];
    Vec3 sp20;
    s32 h;
    s32 *hp;
    TmdTri *e;
    s32 n;
    s32 a;
    s32 b;
    s32 cnt;
    s32 r;
    s32 t;
    s32 k;
    s32 i;
    s32 best;
    Unk_8017BBB0 *q;

    if (p->count == 0) {
        return 0;
    }
    *arg3 = 0;
    k = 0;
    p->cursor = p->head;
    while (1) {
        Block *o = p->cursor->data;
        if (o != NULL && o->active != 0 && o->player_inside != 0 && (o->model_flags & 1)) {
            q = o->floor_model;
            sp20.x = q->unk4->unk18;
            sp20.y = q->unk4->unk1C;
            sp20.z = q->unk4->unk20;
            e = q->unk8->unk10;
            n = q->unk8->unk14;
            a = q->unk8->unk0;
            b = q->unk8->unk8;
            hp = &h;
            while (n != 0) {
                cnt = e->unk0;
                switch (e->mode & 0xFD) {
                case 0x20:
                    t = block_hit_tris(e, a, b, &sp20, cnt, arg0, arg2, (s32)hp);
                    if (t != 0) {
                        r = t;
                        goto found;
                    }
                    n -= cnt;
                    e = (TmdTri *)((u8 *)e + cnt * 0x10);
                    break;
                case 0x28:
                    t = block_hit_quads(e, a, b, &sp20, cnt, arg0, arg2, (s32)hp);
                    if (t != 0) {
                        r = t;
                        goto found;
                    }
                    n -= cnt;
                    e = (TmdTri *)((u8 *)e + cnt * 0x14);
                    break;
                default:
                    r = 0;
                    goto found;
                }
            }
            r = 0;
        found:
            if (r != 0) {
                hits[k].x = r;
                hits[k].y = h;
                hits[k].z = abs(arg1 - h);
                k++;
            }
        }
        if (kaj_ll_at_tail(p) != 0) {
            break;
        }
        p->cursor = p->cursor->next;
    }
    if (k == 0) {
        return 0;
    }
    if (k == 1) {
        *arg3 = hits[0].y;
        return hits[0].x;
    }
    if (k != 0) {
        best = 1600;
        for (i = 0; i < k; i++) {
            if (hits[i].z < best) {
                r = hits[i].x;
                *arg3 = hits[i].y;
                best = hits[i].z;
            }
        }
        return r;
    }
    return 0;
}

static inline s32 func_8017C234_inl(Unk_8017BBB0 *q, Vec3 *sp, s32 x, s32 z, s32 w) {
    TmdTri *e;
    s32 n;
    s32 a;
    s32 b;
    s32 cnt;
    s32 t;
    sp->x = q->unk4->unk18;
    sp->y = q->unk4->unk1C;
    sp->z = q->unk4->unk20;
    e = q->unk8->unk10;
    n = q->unk8->unk14;
    a = q->unk8->unk0;
    b = q->unk8->unk8;
    while (n != 0) {
        cnt = e->unk0;
        switch (e->mode & 0xFD) {
        case 0x20:
            t = block_hit_tris(e, a, b, sp, cnt, x, z, w);
            if (t != 0) {
                return t;
            }
            n -= cnt;
            e = (TmdTri *)((u8 *)e + cnt * 0x10);
            break;
        case 0x28:
            t = block_hit_quads(e, a, b, sp, cnt, x, z, w);
            if (t != 0) {
                return t;
            }
            n -= cnt;
            e = (TmdTri *)((u8 *)e + cnt * 0x14);
            break;
        default:
            return 0;
        }
    }
    return 0;
}

s32 block_fit_ground_tilt(s32 *arg0, s16 arg1) {
    Unk_8017AC88 sp20[4];
    Unk_8017AC88 sp60;
    SVector sp70;
    s32 res[5];
    Vec3 sp90;
    s32 flag;
    BlockList *p = block_list;
    Unk_801E032C *m = D_801E032C[0];
    CarState *g = &vehicle_car_state;
    Unk_8017BBB0 *q;
    Block *o;
    s32 i;
    s16 c1;
    s16 c2;
    s32 dx1;
    s32 dx2;
    s32 dz1;
    s32 dz2;
    s32 sn;
    s32 cs;
    s32 ax;
    s32 az;

    if (p->count == 0) {
        return 0;
    }
    GsSetLsMatrix(&m->unk1C);
    for (i = 0; i < 4; i++) {
        res[i] = 0;
        RotTrans(&g->corners[i], &sp20[i].unk0, &flag);
        if (flag >= 0) {
            p->cursor = p->head;
            while (1) {
                o = p->cursor->data;
                if (o != NULL && o->active != 0 && (q = o->floor_model) != NULL && (arg1 != 0 || o->player_inside != 0)) {
                    res[i] = func_8017C234_inl(q, &sp90, sp20[i].unk0, sp20[i].unk8, (s32)&sp20[i].unk4);
                    if (res[i] != 0) {
                        break;
                    }
                }
                if (kaj_ll_at_tail(p) != 0) {
                    break;
                }
                p->cursor = p->cursor->next;
            }
        }
    }
    if (res[0] == 0 || res[1] == 0 || res[2] == 0 || res[3] == 0) {
        return 0;
    }
    c2 = c1 = 0;
    for (i = 0; i < 4; i++) {
        switch (res[i]) {
        case 0xFFFF:
            c1++;
            break;
        case 0xFF00:
            if (g->unk2 == 0) {
                g->unk2 = 1;
            }
            break;
        default:
            continue;
        }
        c2++;
    }
    if (c1 == 4 && g->unk2 != 0) {
        g->unk2 = 0;
        g->throttle /= 4;
        g->brake /= 4;
    }
    if (c2 == 0) {
        return 0;
    }
    p->cursor = p->head;
    sp70.vx = 0;
    sp70.vy = 0;
    sp70.vz = 0;
    RotTrans(&sp70, &sp60.unk0, &flag);
    if (flag < 0) {
        return 0;
    }
    while (1) {
        o = p->cursor->data;
        if (o != NULL && o->active != 0 && (q = o->floor_model) != NULL && (arg1 != 0 || o->player_inside != 0)) {
            res[4] = func_8017C234_inl(q, &sp90, sp60.unk0, sp60.unk8, (s32)arg0);
            if (res[4] != 0) {
                m->unk14 = 0;
                m->unk10 = 0;
                dx1 = sp20[1].unk4 - sp20[0].unk4;
                dx2 = sp20[3].unk4 - sp20[2].unk4;
                dz1 = sp20[2].unk4 - sp20[0].unk4;
                dz2 = sp20[3].unk4 - sp20[1].unk4;
                if (dx1 != 0 || dx2 != 0 || dz1 != 0 || dz2 != 0) {
                    sn = rsin((m->unk12 << 12) / 360);
                    cs = rcos((m->unk12 << 12) / 360);
                    ax = 0;
                    az = 0;
                    if (dx1 != 0) {
                        ax = ratan2(dx1, 300);
                    }
                    if (abs(dz1) >= abs(dz2)) {
                        if (dz1 != 0) {
                            az = ratan2(dz1, 508);
                        }
                    } else if (dz2 != 0) {
                        az = ratan2(dz2, 508);
                    }
                    {
                        s32 t0 = ax * cs;
                        s32 t1 = ax * sn;
                        s32 t2 = az * cs;
                        s32 t3 = az * sn;
                        m->unk10 = ((t1 + t2) >> 12) * 45 >> 9;
                        m->unk14 = ((t0 - t3) >> 12) * 45 >> 9;
                    }
                }
                *arg0 += 370;
                return res[4];
            }
        }
        if (kaj_ll_at_tail(p) != 0) {
            break;
        }
        p->cursor = p->cursor->next;
    }
    return 0;
}

void block_replace_arena(Unk_8017CAC8 *arg0, Unk_8017CAC8 *arg1) {
    BlockList *p = block_list;
    Arena *q;

    if (p->count != 0) {
        p->cursor = p->head;
        while (1) {
            Block *e = p->cursor->data;
            if (e != NULL && (e->model_flags & 0x10)) {
                q = e->arena;
                if (q->cells == arg0) {
                    break;
                }
            }
            if (kaj_ll_at_tail(p) != 0) {
                q = NULL;
                break;
            }
            p->cursor = p->cursor->next;
        }
    } else {
        q = NULL;
    }
    if (q != NULL) {
        q->cells = arg1;
        q->data = arg1 + 1;
    }
}

void block_arena_init(Arena **arg0, Unk_8017CAC8 *arg1) {
    if (*arg0 == NULL) {
        *arg0 = kaj_malloc(0x10);
        if (*arg0 == NULL) {
            kaj_abend(3, "Error Allocating Arena Buffer", D_801DFC84, 0x49);
        }
    } else {
        memset(*arg0, 0, 0x10);
    }
    (*arg0)->unk0 = arg1->unk0;
    (*arg0)->unk2 = arg1->unk2;
    (*arg0)->unk4 = arg1->unk4;
    (*arg0)->unk6 = arg1->unk6;
    (*arg0)->data = arg1 + 1;
    (*arg0)->cells = arg1;
}

void block_create(Block **arg0, s32 arg1) {
    *arg0 = kaj_malloc(0x90);
    if (*arg0 == NULL) {
        kaj_abend(3, D_80170270, D_801DFC84, 0x5D);
    }
    (*arg0)->active = 0;
    (*arg0)->owns_data = 0;
    (*arg0)->visible = 0;
    (*arg0)->player_inside = 0;
    (*arg0)->in_arena = 0;
    (*arg0)->far = 1;
    (*arg0)->model_flags = 0;
    (*arg0)->model3 = NULL;
    (*arg0)->model2 = NULL;
    (*arg0)->model1 = NULL;
    (*arg0)->floor_model = NULL;
    (*arg0)->arena = NULL;
    (*arg0)->data = NULL;
    if (arg1 != 0) {
        (*arg0)->data = kaj_malloc(arg1);
        if ((*arg0)->data == NULL) {
            kaj_abend(3, D_80170290, D_801DFC84, 0x70);
        }
        (*arg0)->owns_data = 1;
    }
}

void block_free(Block *arg0) {
    if (arg0 != NULL) {
        if (arg0->model3 != NULL) {
            free3(arg0->model3);
        }
        if (arg0->model2 != NULL) {
            free3(arg0->model2);
        }
        if (arg0->model1 != NULL) {
            free3(arg0->model1);
        }
        if (arg0->floor_model != NULL) {
            free3(arg0->floor_model);
        }
        if (arg0->arena != NULL) {
            free3(arg0->arena);
        }
        if (arg0->owns_data != 0) {
            free3(arg0->data);
        }
        free3(arg0);
    }
}

Block *block_find_at(s32 arg0, s32 arg1, s32 arg2) {
    BlockList *p = block_list;
    SceneRequest_u80179848 *g = &scene_request;

    if (p->count == 0) {
        return NULL;
    }
    p->cursor = p->head;
    while (1) {
        Block *e = p->cursor->data;
        if (e != NULL && e->active != 0 && arg0 >= e->pos_x && arg0 < e->pos_x + e->size_x && arg2 >= e->pos_z && arg2 < e->pos_z + e->size_z) {
            if (g->unk0[0] != 1) {
                return e;
            }
            if (e->size_y == 0) {
                if (arg1 == e->pos_y) {
                    return e;
                }
            } else if (e->pos_y >= arg1 && arg1 >= e->pos_y - e->size_y) {
                return e;
            }
        }
        if (kaj_ll_at_tail(p) != 0) {
            return NULL;
        }
        p->cursor = p->cursor->next;
    }
}

void block_set_origin(s32 arg0, s32 arg1, s32 arg2) {
    BlockList *p = block_list;

    if (p->count != 0) {
        p->cursor = p->head;
        while (1) {
            Block *e = p->cursor->data;
            if (e != NULL && e->active != 0) {
                e->coord_flg = 0;
                e->coord_tx = e->pos_x - arg0;
                e->coord_ty = e->pos_y - arg1;
                e->coord_tz = e->pos_z - arg2;
            }
            if (kaj_ll_at_tail(p) != 0) {
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
}

s32 func_8017CFE4(s32 arg0, s32 arg1, s32 arg2) {
    BlockList *p = block_list;
    s32 r;
    s32 ret;

    if (p->cursor == NULL) {
        return 0;
    }
    p->cursor = p->head;
    while (1) {
        Block *e = p->cursor->data;
        if (e != NULL && e->active != 0 && (e->model_flags & 1)) {
            r = block_model_surface(e->floor_model, arg0, arg2, arg1);
            if (r != 0 && r != 0xC8 && (r & 0xFF0000) != 0xFF0000) {
                ret = 1;
                break;
            }
        }
        if (kaj_ll_at_tail(p) != 0) {
            ret = 0;
            break;
        }
        p->cursor = p->cursor->next;
    }
    return ret;
}

void block_hide_all(void) {
    BlockList *p = block_list;

    if (p->count != 0) {
        p->cursor = p->head;
        while (1) {
            if (p->cursor->data != NULL && p->cursor->data->active != 0) {
                p->cursor->data->visible = 0;
            }
            if (kaj_ll_at_tail(p) != 0) {
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
}

void block_list_add(s32 arg0) {
    if (block_list->count == 0) {
        kaj_ll_insert_before(block_list, arg0);
    } else {
        block_list->cursor = block_list->tail;
        kaj_ll_insert_after(block_list, arg0);
    }
}

void block_free_all(void) {
    BlockList *p = block_list;
    Block *e;

    while (1) {
        if (p->count == 0) {
            break;
        }
        e = p->cursor->data;
        if (e != NULL) {
            if (e->model3 != NULL) {
                free3(e->model3);
            }
            if (e->model2 != NULL) {
                free3(e->model2);
            }
            if (e->model1 != NULL) {
                free3(e->model1);
            }
            if (e->floor_model != NULL) {
                free3(e->floor_model);
            }
            if (e->arena != NULL) {
                free3(e->arena);
            }
            if (e->owns_data != 0) {
                free3(e->data);
            }
            free3(e);
        }
        kaj_ll_remove_to_prev(p);
    }
}

void block_free_owned(void) {
    BlockList *p = block_list;

    if (p->count != 0) {
        p->cursor = p->head;
        while (1) {
            Block *e = p->cursor->data;
            if (e != NULL && e->owns_data != 0) {
                if (e->model3 != NULL) {
                    free3(e->model3);
                }
                if (e->model2 != NULL) {
                    free3(e->model2);
                }
                if (e->model1 != NULL) {
                    free3(e->model1);
                }
                if (e->floor_model != NULL) {
                    free3(e->floor_model);
                }
                if (e->arena != NULL) {
                    free3(e->arena);
                }
                if (e->owns_data != 0) {
                    free3(e->data);
                }
                free3(e);
                kaj_ll_remove_to_prev(p);
            }
            if (kaj_ll_at_tail(p) != 0) {
                break;
            }
            p->cursor = p->cursor->next;
        }
    }
}

void block_stream_stop(void) {
    D_801DFC80 = 0;
    kaj_cdmgr_free_all();
}

s32 block_model_surface(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Vec3 sp20;
    TmdTri *e;
    s32 n;
    s32 a;
    s32 b;
    s32 cnt;
    s32 t;
    Unk_8017BBB0 *q = arg0;

    sp20.x = q->unk4->unk18;
    sp20.y = q->unk4->unk1C;
    sp20.z = q->unk4->unk20;
    e = q->unk8->unk10;
    n = q->unk8->unk14;
    a = q->unk8->unk0;
    b = q->unk8->unk8;
    while (n != 0) {
        cnt = e->unk0;
        switch (e->mode & 0xFD) {
        case 0x20:
            t = block_hit_tris(e, a, b, &sp20, cnt, arg1, arg2, arg3);
            if (t != 0) {
                return t;
            }
            n -= cnt;
            e = (TmdTri *)((u8 *)e + cnt * 0x10);
            break;
        case 0x28:
            t = block_hit_quads(e, a, b, &sp20, cnt, arg1, arg2, arg3);
            if (t != 0) {
                return t;
            }
            n -= cnt;
            e = (TmdTri *)((u8 *)e + cnt * 0x14);
            break;
        default:
            return 0;
        }
    }
    return 0;
}

s32 func_8017D564(void) {
    return D_801E71C8 == 0;
}

void block_enter_area(u32 arg0) {
    s32 t = (arg0 >> 16) & 0xFF;

    D_801DFC8C = t;
    if (t != 0x80) {
        return;
    }
    D_801DFC8D[0] = arg0 >> 8;
    D_801DFC8E = arg0;
    action_vars.unk252 = 0;
    action_vars.unk250 = 0;
    switch (D_801DFC8D[0]) {
    case 1:
        action_vars.unk252 = 1;
        break;
    case 2:
        action_vars.unk250 = 1;
        break;
    case 3:
        action_vars.unk252 = 1;
        action_vars.unk250 = 1;
        break;
    }
}

s32 block_on_effect_done(KajEvent *arg0) {
    GameVars *a = &action_vars;
    SceneRequest_u80179848 *b = &scene_request;
    Player *m = player_status_player[0];
    TrainState *c = &vehicle_train_state;
    Unk_801E1058 *d = D_801E1058;
    EventState *e = &event_state;
    s32 k = arg0->unk10;
    s16 r;
    void *p;
    u16 f;

    if (k == 0) {
        switch (block_building_state.building) {
        case 7:
            break;
        case 5:
            sound_bgm_play(0);
            break;
        default:
            sound_bgm_play(1);
            break;
        }
        if (block_building_state.building == 1 || block_building_state.building == 2) {
            sound_se_play(0x1D);
        } else {
            sound_se_play_note(10, 0x29, 0, 0x3C, 0x7F, 0x7F, 1);
        }
    } else if (k == 7) {
        if (arg0->unkC == 0) {
            a->unk244 = -1;
        }
        if (c->door_state == 3) {
            c->door_state = 1;
            sprite_station_show_prompt(1);
        } else if (c->door_state == 2) {
            c->door_state = 0;
            c->motion = 1;
            thing_set_animate(2, 0, 1);
        }
    } else if (k == 11) {
        if (!(m->flags & 0x4000)) {
            text_show(*d->unk1C, 3, -1, 0, -1, 0, 1);
        }
    } else if (k == 12) {
        if (!(m->flags & 0x4000)) {
            r = roadmap_shop_finish(block_building_state.building);
            if (block_building_state.building == 8 && D_801DFF78 >= 0) {
                if (r >= 0) {
                    p = action_find_set(r);
                    if (p != NULL) {
                        e->trigger_type = 0;
                        e->trigger = 0;
                        e->cross_set = -1;
                        e->circle_set = -1;
                        e->cross_flags = 0;
                        e->circle_flags = 0;
                        e->state = 1;
                        do {
                            p = action_run_set(p, 0, 0);
                        } while (p != NULL);
                    }
                } else {
                    roadmap_shop_open_menu(block_building_state.building, 0);
                }
            }
        }
    } else if (k == 4) {
        f = m->flags;
        if (f & 0x80) {
            m->flags = f & ~4;
            b->unkA = 1;
        } else if (f & 0x20) {
            /*  横になると、深い眠りについた */
            text_show(" \211\241\202\311\202\310\202\351\202\306\201\101\220\133\202\242\226\260\202\350\202\311\202\302\202\242\202\275", 1, -1, 0, -1, 0, 0);
            effect_start_fade(10, 3);
        } else if (f & 8) {
            if (block_building_state.building == 9) {
                /*  6目を閉じて・・・ */
                text_show(" 6\226\332\202\360\225\302\202\266\202\304\201\105\201\105\201\105", 1, -1, 0, -1, 0, 0);
            } else {
                /*  意識が遠ざかっていく */
                text_show(" \210\323\216\257\202\252\211\223\202\264\202\251\202\301\202\304\202\242\202\255", 1, -1, 0, -1, 0, 0);
            }
            effect_start_fade(10, 3);
        } else if ((block_building_state.building == 3 || block_building_state.building == 6) && d->unk8 != 0) {
            roadmap_shop_open_menu(block_building_state.building, 0);
        }
    } else if (k == 10) {
        if (arg0->unkC == 0) {
            a->unk244 = -1;
        }
        f = m->flags;
        if (f & 0x20) {
            player_rest(1, block_wake_positions[block_wake_index * 3], block_wake_positions[block_wake_index * 3 + 1], block_wake_positions[block_wake_index * 3 + 2]);
            text_close();
        } else if (f & 8) {
            if (block_building_state.building == 9) {
                player_recover(500, 0, 0x3390, 0);
            } else {
                player_recover(block_wake_positions[block_wake_index * 3], block_wake_positions[block_wake_index * 3 + 1], block_wake_positions[block_wake_index * 3 + 2], 1);
            }
        }
        mail_wait(1, 1, 1, 4);
        effect_start_fade(9, 3);
    } else if (k == 9) {
        if (arg0->unkC == 0) {
            a->unk244 = -1;
        }
        f = m->flags;
        if (f & 0x20) {
            m->flags = f & ~0x20;
        } else if (f & 8) {
            m->flags = f & ~8;
        }
    } else if (k == 13) {
        if (block_building_state.building == 0) {
            sound_bgm_play(1);
        }
    }
    return 0;
}

void block_on_action(PlayerStatus *arg0) {
    EventState *q = &event_state;
    BuildingState *r;
    void *item;
    s16 m = q->state;

    if (m == 3) {
        text_next_page((Unk_80184100 *)q);
        return;
    }
    if (m != 2) {
        return;
    }
    D_801DFE60 = 0;
    if (!(q->circle_flags & 8)) {
        return;
    }
    sound_se_play(0x11);
    text_close();
    switch (q->trigger_type) {
    case 0xFC:
        text_show_profile(event_state.trigger);
        break;
    case 0x10:
        switch (event_state.trigger) {
        case 0x100010:
            sprite_station_board_train(1);
            break;
        case 0x100020:
            sprite_station_board_train(0);
            break;
        default:
            if ((q->trigger & 0xFFFF00) == 0x104000) {
                D_801DFE60 = 1;
                effect_elevator_init((u8)q->trigger);
                goto loop;
            }
            break;
        }
        break;
    case 0x60:
        if (block_building_state.building == 2) {
            sprite_station_exit_to_town();
        } else if (block_building_state.building >= 3 && block_building_state.building < 8) {
            r = &block_building_state;
            roadmap_shop_exit_to_town(block_building_state.building, r->unk2);
        } else {
            goto loop;
        }
        break;
    case 0x30:
        if (block_building_state.building != 3 && block_building_state.building != 6) {
            roadmap_shop_open_menu(block_building_state.building, event_state.trigger);
            break;
        }
    default:
        if (q->trigger >= 0xF02150 && q->trigger < 0xF02155) {
            if (arg0->hours_awake < 6) {
                text_show(" \202\275\202\301\202\325\202\350\202\306\201A\220\207\226\260\202\315\202\306\202\352\202\304\202\242\202\351", 1, -1, 0, -1, 0, 4);
                break;
            }
            block_wake_index = q->trigger & 0xF;
        }
    loop:
        item = action_find_set(q->circle_set);
        if (item != NULL) {
            while ((item = action_run_set(item, 0, 0)) != NULL) {
            }
        }
        break;
    }
    q->state = 1;
    q->circle_flags &= ~8;
}

void block_update_input(void) {
    PlayerStatus *p = &player_status;
    Player *o = p->player;
    s32 t;

    if (kaj_system.pad_mode != 1) {
        return;
    }
    if (*(u32 *)&o->unk40 & 0x2A0000) {
        return;
    }
    t = kaj_pad_read();
    if (block_building_state.building < 3 && effect_item_input(p, 1) != 0) {
        return;
    }
    if (roadmap_shop_update_input(p) != 0) {
        return;
    }
    if (effect_weapon_input(p) != 0) {
        return;
    }
    if (o->flags & 4) {
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            block_on_action(p);
            return;
        }
        if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            EventState *q = &event_state;
            Unk_801E1058 *r = D_801E1058;
            void *item;

            if (q->state == 2 && (q->cross_flags & 2)) {
                sound_se_play(8);
                text_close();
                if (q->trigger_type == 0x30) {
                    switch (block_building_state.building) {
                    case 4:
                    case 5:
                        r->unk4 = 1;
                        roadmap_shop_open_menu(block_building_state.building, event_state.trigger);
                        break;
                    }
                } else {
                    item = action_find_set(q->cross_set);
                    if (item != NULL) {
                        sound_se_play(8);
                        while ((item = action_run_set(item, 0, 0)) != NULL) {
                        }
                    }
                }
                q->state = 1;
                q->cross_flags &= ~2;
            }
            return;
        }
    }
    player_handle_pad(p, 1, t);
}

void block_building_load(void) {
    char sp10[16];
    SceneRequest_u80179848 *g = &scene_request;
    BuildingState *p;

    action_reset(1);
    D_801DFED4 = block_on_effect_done;
    p = &block_building_state;
    p->unk2 = g->unk12;
    block_scene_daylight = 0;
    block_building_state.building = g->unk10;
    if (D_801DFE60 == 1) {
        return;
    }
    sprite_set_visible(0x410, 1);
    block_set_mode(1);
    memset(sp10, 0, 0x10);
    sprintf(sp10, "\\S\\%s.S;1", g->unk20);
    g->unkC = sp10;
    object_load_scene();
    effect_weapon_load_models();
    switch (block_building_state.building) {
    case 0:
        switch (p->unk2) {
        case 4:
            thing_set_active(3, 8, 1);
            thing_set_animate(3, 8, 1);
            thing_set_active(3, 9, 1);
            thing_set_animate(3, 9, 1);
            break;
        case 22:
            mod_npcrec_show(5, 1);
            thing_set_active(3, 6, 1);
            thing_set_animate(3, 6, 1);
            break;
        case 23:
            mod_npcrec_show(2, 0);
            D_801DFEE4 = block_on_enter;
            break;
        case 28:
            thing_set_active(3, 5, 1);
            thing_set_animate(3, 5, 1);
            break;
        case 30:
            mod_npcrec_show(1, 1);
            effect_flame_small_init(0);
            break;
        case 7:
            mod_npcrec_show(2, 0);
        case 9:
            effect_flame_small_init(1);
            effect_flame_large_init();
            break;
        case 33:
            thing_set_active(0, 1, 1);
            effect_flame_small_init(0);
        case 31:
        case 32:
        case 34:
            mod_npcrec_show(1, 1);
            break;
        case 39:
            mod_npcrec_show(3, 0);
        case 1:
        case 15:
            mod_npcrec_show(2, 0);
            break;
        }
        break;
    case 1:
        block_scene_daylight = block_building_state.building;
    case 2:
        sprite_station_init();
        break;
    default:
        roadmap_shop_init(p->building);
        break;
    }
    if (g->unk14 != 0) {
        sound_se_play(0x21);
    }
    event_show_clock(block_scene_daylight);
    sprite_set_visible(0x410, 0);
}

void block_building_run(void) {
    s32 sp10[6];
    s16 done;

    block_building_load();
    done = 0;
    kaj_timer_enable();
    if (D_801DFE60 == 0) {
        effect_start_fade(0, 3);
    } else {
        D_801DFE60 = 0;
        kaj_pad_reset(1);
    }
    while (done == 0) {
        switch (kaj_event_get(sp10)) {
        case 0x10:
            event_handle_enter(sp10);
            continue;
        case 0x400:
            roadmap_shop_close_topic();
            continue;
        case 0x20:
            event_handle_leave(sp10);
            continue;
        case 0x4:
            event_handle_tick(block_scene_daylight);
            continue;
        case 0x200:
            event_handle_mod_finish(sp10);
            continue;
        case 0x0:
            block_update_input();
            if (mail_take_scene_change() != 0) {
                if (D_801DFE60 == 0) {
                    effect_start_fade(1, 3);
                } else {
                    kaj_pad_reset(0);
                    done = 1;
                }
            }
            break;
        case 0x100:
            done = event_handle_effect_done(sp10);
            continue;
        default:
            kaj_event_done(sp10);
            continue;
        }
        mail_step_frame(1, 1, 1);
    }
    kaj_timer_disable();
    D_801DFEE4 = 0;
    D_801DFEE0 = 0;
    D_801DFED4 = 0;
    D_801DFEDC = 0;
    action_reset(1);
    text_close();
    if (D_801DFE60 != 1) {
        block_stream_stop();
        sound_bgm_stop();
        sound_se_stop_all();
        effect_flame_small_free();
        effect_flame_large_free();
        action_free_triggers();
        npc_free_all();
        npc_free_bodies();
        npc_free_stats();
        effect_weapon_reset();
        action_free_all_sets();
        block_free_all();
        door_free_all();
        mod_free_all();
        thing_free_all();
        sound_bgm_close();
        sound_se_pop_scene();
        sprite_delete(2);
        sprite_delete(3);
        sprite_delete(4);
    }
}

s32 block_on_enter(KajEvent *arg0) {
    s32 v = arg0->unkC;

    if (v == 0xF0233C) {
        block_wake_index = 5;
    } else if (v == 0xF02350) {
        block_wake_index = 6;
    } else if (v == 0xF0235A) {
        block_wake_index = 7;
    }
    return 0;
}

void block_building_main(void) {
    D_801DFE60 = 0;
    block_create_all();
    while (1) {
        block_building_run();
        if (D_801DFE60 != 1) {
            break;
        }
        effect_elevator_run();
    }
}

void block_elevator_input(s16 arg0, s16 arg1, s16 *arg2) {
    s32 snd;
    s16 played;
    s32 i;
    s32 idx;

    if (kaj_system.pad_mode == 1) {
        played = 0;
        kaj_pad_read();
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            played = 1;
            snd = 0x18;
            if (*arg2 == arg1) {
                snd = 0x11;
            }
            idx = (arg0 * 11 + *arg2 - 12) * 3;
            mail_goto_twn(block_elevator_stops[idx] * 10, 0, block_elevator_stops[idx + 1] * 10, block_elevator_stops[idx + 2], 0);
        } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            played = 1;
            snd = 8;
            *arg2 = arg1;
            idx = (arg0 * 11 + arg1 - 12) * 3;
            mail_goto_twn(block_elevator_stops[idx] * 10, 0, block_elevator_stops[idx + 1] * 10, block_elevator_stops[idx + 2], 0);
        } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
            played = 1;
            snd = 0xF;
            (*arg2)--;
            if (arg0 != 3) {
                if (*arg2 >= 12) {
                    *arg2 = 1;
                }
                if (*arg2 <= 0) {
                    *arg2 = 11;
                }
            } else {
                if (*arg2 >= 6) {
                    *arg2 = 1;
                }
                if (*arg2 <= 0) {
                    *arg2 = 5;
                }
            }
            for (i = 1; i < 12; i++) {
                sprite_set_clut_entry(0, (arg0 << 4) + i, 0x5BBD);
                sprite_set_clut_entry(0, i, 0x1D40);
            }
            sprite_set_clut_entry(0, (arg0 << 4) + *arg2, 0x29F);
            sprite_set_clut_entry(0, *arg2, 0x1D5F);
        } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
            played = 1;
            snd = 0xF;
            (*arg2)++;
            if (arg0 != 3) {
                if (*arg2 >= 12) {
                    *arg2 = 1;
                }
                if (*arg2 <= 0) {
                    *arg2 = 11;
                }
            } else {
                if (*arg2 >= 6) {
                    *arg2 = 1;
                }
                if (*arg2 <= 0) {
                    *arg2 = 5;
                }
            }
            for (i = 1; i < 12; i++) {
                sprite_set_clut_entry(0, (arg0 << 4) + i, 0x5BBD);
                sprite_set_clut_entry(0, i, 0x1D40);
            }
            sprite_set_clut_entry(0, (arg0 << 4) + *arg2, 0x29F);
            sprite_set_clut_entry(0, *arg2, 0x1D5F);
        }
        if (played) {
            sound_se_play(snd);
        }
    }
}

void block_elevator_run(s16 arg0, s16 arg1) {
    s32 sp10[6];
    s16 sp28;
    s16 done;
    s32 i;
    s32 d;
    s16 v;

    done = 0;
    sp28 = arg1;
    D_801DFED4 = 0;
    sprite_set_visible(0x400, 0);
    sprite_set_visible(0x409, 0);
    sprite_set_visible(0x40E, 0);
    sprite_set_visible(0, 1);
    sprite_set_visible((u16)arg0, 1);
    sprite_set_clut_entry(0, (arg0 << 4) + arg1, 0x29F);
    sprite_set_clut_entry(0, arg1, 0x1D5F);
    mail_wait(3, 0, 0, 2);
    kaj_pad_reset(1);
    kaj_timer_enable();
    do {
        switch (kaj_event_get(sp10)) {
        case 0x4:
            event_handle_tick(1);
            continue;
        case 0x0:
            block_elevator_input(arg0, arg1, &sp28);
            if (mail_take_scene_change() != 0) {
                effect_start_fade(1, 3);
            }
            break;
        case 0x100:
            done = event_handle_effect_done(sp10);
            continue;
        default:
            kaj_event_done(sp10);
            continue;
        }
        roadmap_draw_frame(2);
    } while (done == 0);
    kaj_timer_disable();
    v = sp28;
    for (i = 1; i < 12; i++) {
        sprite_set_clut_entry(0, (arg0 << 4) + i, 0x5BBD);
        sprite_set_clut_entry(0, i, 0x1D40);
    }
    sprite_set_visible(0x400, 1);
    sprite_set_visible(0x409, 1);
    sprite_set_visible(0x40E, 1);
    sprite_set_visible(0, 0);
    sprite_set_visible((u16)arg0, 0);
    d = v - arg1;
    event_advance_clock((d < 0 ? -d : d) * 5, 0);
}
