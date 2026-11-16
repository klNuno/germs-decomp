#include "common.h"
#include "game/types.h"

void free3(void *ptr);
typedef struct Unk_801A7BA4 {
    struct Unk_801A7BA4 *unk0;
    struct Unk_801A7BA4 *unk4;
    Thing *unk8;
} Unk_801A7BA4;
typedef struct Unk_801DFFA0 {
    Unk_801A7BA4 *unk0;
    Unk_801A7BA4 *unk4;
    Unk_801A7BA4 *unk8;
    s32 unkC;
} Unk_801DFFA0;
void kaj_ll_insert_before(Unk_801DFFA0 *arg0, s32 arg1);
void kaj_ll_insert_after(Unk_801DFFA0 *arg0, s32 arg1);
Unk_801DFFA0 *D_801DFFA0;
void kaj_ll_remove_to_prev(Unk_801DFFA0 *arg0);
typedef struct Unk_801A8EFC {
    u8 unk0[0xC];
    s32 unkC;
    s32 unk10;
} Unk_801A8EFC;
void sound_se_play(s32 arg0);
void vehicle_train_exit_prompt(s32 arg0);
extern TrainState vehicle_train_state;
void vehicle_train_set_doors(s32 arg0);
void block_create_all(void);
void thing_field_loop(void);
void sprite_phone_run(void);
void block_elevator_run(s32 arg0, s32 arg1);
s16 thing_field_exit_arg_hi;
s16 thing_field_exit_arg_lo;
s16 thing_field_exit_code;
s16 kaj_ll_at_tail(Unk_801DFFA0 *arg0);
void GsSetLsMatrix(void *m);
s16 block_point_on_model(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4);
typedef struct Unk_801A8264_0 {
    u8 unk0[0x2];
    u16 unk2;
    u8 unk4;
    u8 unk5;
} Unk_801A8264_0;
typedef struct Unk_801A8264 {
    Unk_801A8264_0 *unk0;
    u8 unk4[0x4];
    char **unk8;
} Unk_801A8264;
s32 atoi(char *s);
extern char D_801719BC[];
extern char D_801719DC[];
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char thing_str_file[];
ActionSet *action_find_set(s16 arg0);
ActionSet *action_run_set(ActionSet *arg0, s32 arg1, s32 arg2);
extern Player *player_status_player[];
extern s16 vehicle_navi[];
extern GameVars action_vars;
extern RoadMap roadmap_state;
s16 thing_next_vehicle_mode;
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void text_close(void);
void sound_bgm_play(s16 arg0);
s16 vehicle_train_end_of_line(s16 arg0);
void vehicle_navi_show(Player *arg0, s16 arg1, s32 arg2);
extern PlayerStatus player_status;
extern SceneRequest scene_request;
extern KajSystem kaj_system;
s32 kaj_pad_read(void);
s16 vehicle_car_input(PlayerStatus *arg0, s32 arg1);
s16 effect_item_input(PlayerStatus *arg0, s16 arg1);
s32 player_update_map(PlayerStatus *arg0);
void player_handle_pad(PlayerStatus *arg0, s32 arg1, s32 arg2);
void thing_field_do_action(Player *arg0);
extern s32 D_801DFED4;
extern s32 D_801DFED8;
extern s32 D_801DFEDC;
extern s32 D_801DFEE0;
extern s32 D_801DFEE4;
void effect_clear_alarms(void);
void action_reset(s16 arg0);
void sprite_set_visible(s32 arg0, s32 arg1);
void sound_bgm_stop(void);
void sound_se_stop_all(void);
void vehicle_free(void);
void roadmap_quit(void);
void action_free_triggers(void);
void action_free_all_sets(void);
void block_free_all(void);
void thing_free_all(void);
void effect_flame_small_free(void);
void effect_flame_large_free(void);
void sound_bgm_close(void);
void sound_se_pop_scene(void);
void sprite_delete(s32 arg0);
void vehicle_car_release(void);
void kaj_view_set_bg_color(u8 arg0, u8 arg1, u8 arg2);
void block_hide_all(void);
void thing_set_active(s32 arg0, s32 arg1, s16 arg2);
void block_stream_stop(void);
extern EventState event_state;
void sprite_phone_save_exit();
s16 vehicle_train_get_off(s16 arg0);
s16 D_801DFFAC;
s16 thing_field_loaded_id;
void thing_set_animate(s32 arg0, s32 arg1, s16 arg2);
s32 thing_field_task_hook(Unk_801A8EFC *arg0);
void thing_field_timer_hook(Unk_801A8EFC *arg0);
s32 thing_train_enter_hook(Unk_801A8EFC *arg0);
s32 thing_train_leave_hook(Unk_801A8EFC *arg0);
void thing_train_tick_hook(void);
void player_place_for_scene(s32 arg0);
void roadmap_init(void);
void effect_weapon_calc_rate(s32 arg0);
void object_load_scene(void);
void object_load_res12_by_id(s16 arg0);
void effect_flame_small_init(s16 arg0);
void effect_clut_cycle_init(void);
void effect_flame_large_init(void);
void block_set_mode(u16 arg0);
void vehicle_car_place(void);
void vehicle_load_data(void);
void sprite_thing_refresh_all(void);
void event_show_clock(s16 arg0);
void thing_field_input(void);
void thing_field_enter(void);
void thing_field_leave(void);
void kaj_timer_enable(void);
void kaj_timer_disable(void);
void effect_start_fade(s32 arg0, s32 arg1);
s32 kaj_event_get(s32 *arg0);
void func_80189928(s32 *arg0);
void event_handle_enter(s32 *arg0);
void event_handle_leave(s32 *arg0);
void event_handle_tick(s16 arg0);
s32 mail_take_scene_change(void);
void kaj_pad_reset(s32 arg0);
s16 event_handle_effect_done(s32 *arg0);
void kaj_event_done(s32 *arg0);
void effect_start_alarm(s32 arg0, s32 arg1, s32 arg2);
void mail_step_frame(u16 arg0, s16 arg1, s16 arg2);
s32 func_8017D564(void);
s32 rand(void);
typedef struct {
    u16 unk0;
    u8 unk2[0x16];
    s32 unk18;
    s32 unk1C;
} Unk_801A9BF4;
typedef struct {
    u16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0x2];
    s32 unk18;
    u8 unk1C[0x14];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    u8 unk3C[0x2C];
    s32 unk68;
    u8 unk6C[0x14];
    s32 unk80;
    s32 unk84;
    s32 unk88;
    u8 unk8C[0x2C];
    void *unkB8;
    void *unkBC;
    Unk_801A9BF4 *unkC0;
} Unk_801E032C;
void thing_train_calc_stops(TrainState *arg0);
void RotMatrix(SVector *arg0, void *arg1);
void GsInitCoordinate2(void *super, void *base);
void kaj_tmd_load(void *arg0, void *arg1, void *arg2);
extern s16 D_801DFC80;
void RotMatrixZYX(SVector *arg0, void *arg1);
s32 block_find_at(s32 a0, s32 a1, s32 a2);
void sprite_thing_update_marker(Player *arg0, Thing *arg1, void *arg2);
void sprite_thing_update_fly_in(Thing *arg0);
void vehicle_train_update(Thing *arg0);
void vehicle_car_follow_player(Thing *arg0, s32 arg1);
extern Thing *D_801E0764[];
extern CarState vehicle_car_state;
s16 thing_car_exit_prompt_on;
s32 thing_car_speed_div;
void RotTrans(void *v0, s32 *v1, s32 *flag);
void player_set_view(Player *arg0, s16 arg1);
void sound_se_stop(s32 arg0);
void mail_goto_twn(s32 a, s32 b, s32 c, s16 d, s16 e);
s32 rsin(s32 a);
s32 rcos(s32 a);
s32 func_8017CFE4(s32 arg0, s32 *arg1, s32 arg2);
extern Unk_801E032C *D_801E032C[];
extern s32 D_801E6DB4[];

INCLUDE_RODATA("asm/nonmatchings/game/801A7560", D_801719BC);

INCLUDE_RODATA("asm/nonmatchings/game/801A7560", D_801719DC);

void thing_update_all(void) {
    SVector sv;
    Unk_801DFFA0 *list = D_801DFFA0;
    PlayerStatus *status = &player_status;
    Inventory *inv = status->inventory;
    Player *player = status->player;
    Thing *thing;

    if (list->unkC == 0) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        thing = list->unk8->unk8;
        if (thing != NULL && thing->type != 4) {
            if (*(s32 *)thing == 0x30007) {
                if (status->target_npc != 0 && inv->weapon_state >= 3) {
                    if (thing->active == 0) {
                        thing->active = 1;
                    }
                } else if (thing->active != 0) {
                    thing->active = 0;
                }
            }
            if (thing->active == 0) {
                thing->block = 0;
            } else {
                if (thing->animate != 0) {
                    switch (thing->type) {
                    case 2:
                        if (thing->id == 0) {
                            vehicle_train_update(thing);
                        }
                        break;
                    case 3:
                        switch (thing->id) {
                        case 0:
                        case 2:
                        case 6:
                            thing->rot_y = -kaj_system.vsync_delta + thing->rot_y;
                            if (thing->rot_y < 0) {
                                thing->rot_y += 360;
                            } else if (thing->rot_y > 360) {
                                thing->rot_y -= 360;
                            }
                            sv.vx = (thing->rot_x << 12) / 360;
                            sv.vy = (thing->rot_y << 12) / 360;
                            sv.vz = (thing->rot_z << 12) / 360;
                            RotMatrix(&sv, thing->coord_m);
                            thing->coord_flg = 0;
                            break;
                        case 1:
                            thing->rot_y -= -kaj_system.vsync_delta;
                            if (thing->rot_y < 0) {
                                thing->rot_y += 360;
                            } else if (thing->rot_y > 360) {
                                thing->rot_y -= 360;
                            }
                            sv.vx = (thing->rot_x << 12) / 360;
                            sv.vy = (thing->rot_y << 12) / 360;
                            sv.vz = (thing->rot_z << 12) / 360;
                            RotMatrixZYX(&sv, thing->coord_m);
                            thing->coord_flg = 0;
                            break;
                        case 3:
                        case 4:
                        case 5:
                            thing->rot_y += ~(kaj_system.vsync_delta / 4);
                            if (thing->rot_y < 0) {
                                thing->rot_y += 360;
                            } else if (thing->rot_y > 360) {
                                thing->rot_y -= 360;
                            }
                            sv.vx = (thing->rot_x << 12) / 360;
                            sv.vy = (thing->rot_y << 12) / 360;
                            sv.vz = (thing->rot_z << 12) / 360;
                            RotMatrix(&sv, thing->coord_m);
                            thing->coord_flg = 0;
                            break;
                        case 7:
                            sprite_thing_update_marker(player, thing, status->target_npc);
                            break;
                        case 8:
                            thing->rot_y += kaj_system.vsync_delta * 5 / 2;
                            if (thing->rot_y < 0) {
                                thing->rot_y += 360;
                            } else if (thing->rot_y > 360) {
                                thing->rot_y -= 360;
                            }
                            sv.vx = (thing->rot_x << 12) / 360;
                            sv.vy = (thing->rot_y << 12) / 360;
                            sv.vz = (thing->rot_z << 12) / 360;
                            RotMatrix(&sv, thing->coord_m);
                            thing->coord_flg = 0;
                            break;
                        case 9:
                            thing->rot_y -= kaj_system.vsync_delta * 5;
                            if (thing->rot_y < 0) {
                                thing->rot_y += 360;
                            } else if (thing->rot_y > 360) {
                                thing->rot_y -= 360;
                            }
                            sv.vx = (thing->rot_x << 12) / 360;
                            sv.vy = (thing->rot_y << 12) / 360;
                            sv.vz = (thing->rot_z << 12) / 360;
                            RotMatrix(&sv, thing->coord_m);
                            thing->coord_flg = 0;
                            break;
                        case 10:
                            sprite_thing_update_fly_in(thing);
                            break;
                        }
                        break;
                    }
                }
                if (thing->block_fixed == 0 && D_801DFC80 != 0) {
                    thing->block = block_find_at(thing->pos_x, thing->pos_y, thing->pos_z);
                    if (*(s32 *)thing == 0) {
                        vehicle_car_follow_player(thing, 0);
                    }
                }
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

void thing_create(Thing **out, u32 record_size) {
    *out = kaj_malloc(0x88);
    if (*out == NULL) {
        kaj_abend(3, D_801719BC, thing_str_file, 0x26);
    }
    (*out)->active = 0;
    (*out)->animate = 0;
    (*out)->unk8 = 0;
    (*out)->block_fixed = 0;
    (*out)->block = 0;
    (*out)->tmd_objects = NULL;
    (*out)->hit_model = NULL;
    (*out)->record = NULL;
    (*out)->record = kaj_malloc(record_size);
    if ((*out)->record == NULL) {
        kaj_abend(3, D_801719DC, thing_str_file, 0x33);
    }
}

void thing_free(Thing *thing) {
    if (thing != NULL) {
        free3(thing->tmd_objects);
        if (thing->hit_model != NULL) {
            free3(thing->hit_model);
        }
        free3(thing->record);
        free3(thing);
    }
}

void thing_list_add(s32 thing) {
    if (D_801DFFA0->unkC == 0) {
        kaj_ll_insert_before(D_801DFFA0, thing);
    } else {
        D_801DFFA0->unk8 = D_801DFFA0->unk4;
        kaj_ll_insert_after(D_801DFFA0, thing);
    }
}

void thing_free_all(void) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Thing *item;

    while (1) {
        if (list->unkC == 0) {
            break;
        }
        item = list->unk8->unk8;
        if (item != NULL) {
            free3(item->tmd_objects);
            if (item->hit_model != NULL) {
                free3(item->hit_model);
            }
            free3(item->record);
            free3(item);
        }
        kaj_ll_remove_to_prev(list);
    }
}

Thing *thing_find(s32 type, s32 id) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Thing *item;
    s32 type16;
    s32 id16;

    if (list->unkC == 0) {
        return NULL;
    }
    type16 = type & 0xFFFF;
    id16 = id & 0xFFFF;
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && item->type == type16 && item->id == id16) {
            return item;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return NULL;
}

u16 thing_hit_test(s32 x, s32 y, s32 z, u16 arg3) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Thing *item;

    if (list->unkC == 0) {
        return 0xFFFF;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && item->active != 0 && item->hit_model != NULL) {
            GsSetLsMatrix(item->coord_m);
            if (block_point_on_model(item->hit_model, x, y, z, arg3) != 0) {
                return item->id + (item->type << 12);
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return 0xFFFF;
}

void thing_set_origin(s32 origin_x, s32 origin_y, s32 origin_z) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Thing *item;

    if (list->unkC == 0) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL) {
            item->coord_flg = 0;
            item->coord_tx = item->pos_x - origin_x;
            item->coord_ty = item->pos_y - origin_y;
            item->coord_tz = item->pos_z - origin_z;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

s32 thing_run_script(s32 type, s32 id, s16 entering) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Thing *item;
    Thing *found;
    ActionSet *set;
    s32 type16;
    s32 id16;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        type16 = type & 0xFFFF;
        id16 = id & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->type == type16 && item->id == id16) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found == NULL || found->unk8 == 0) {
        return 0;
    }
    if (found->active == 0 || (set = entering != 0 ? action_find_set(found->unkC) : action_find_set(found->unkE)) == NULL) {
        return 0;
    }
    while ((set = action_run_set(set, 0, 0)) != NULL) {
    }
    return 1;
}

void thing_set_active(s32 type, s32 id, s16 active) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Thing *item;
    Thing *found;
    s32 type16;
    s32 id16;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        type16 = type & 0xFFFF;
        id16 = id & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->type == type16 && item->id == id16) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL) {
        found->active = active;
    }
}

void thing_set_animate(s32 type, s32 id, s16 animate) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Thing *item;
    Thing *found;
    s32 type16;
    s32 id16;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        type16 = type & 0xFFFF;
        id16 = id & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->type == type16 && item->id == id16) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL) {
        found->animate = animate;
    }
}

void thing_set_flag10(s32 type, s32 id, s16 block_fixed) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Thing *item;
    Thing *found;
    s32 type16;
    s32 id16;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        type16 = type & 0xFFFF;
        id16 = id & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->type == type16 && item->id == id16) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL) {
        found->block_fixed = block_fixed;
    }
}

void thing_cmd_set_active(Unk_801A8264 *cmd) {
    Unk_801A8264_0 *p = cmd->unk0;
    Unk_801DFFA0 *list = D_801DFFA0;
    Thing *item;
    Thing *found;
    s32 type = p->unk5;
    s32 id = p->unk4;
    s32 type16;
    s32 id16;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        type16 = type & 0xFFFF;
        id16 = id & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->type == type16 && item->id == id16) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL && p->unk2 == 2) {
        found->active = atoi(cmd->unk8[0]);
    }
}

s32 thing_field_task_hook(Unk_801A8EFC *ev) {
    GameVars *game = &action_vars;
    Player *player = player_status_player[0];
    TrainState *train = &vehicle_train_state;
    RoadMap *roadmap = &roadmap_state;
    s16 *navi = vehicle_navi;
    s32 kind = ev->unk10;

    if (kind == 2) {
        if (ev->unkC == 0) {
            game->unk244 = -1;
        }
        roadmap->mode = 1;
    } else if (kind == 3) {
        if (ev->unkC == 0) {
            game->unk244 = -1;
        }
        roadmap->mode = 0;
        if (navi[0] != 0) {
            vehicle_navi_show(player, 1, 0);
        }
    } else if (kind == 11) {
        /* " 8カーナビ1の3目的地1を, 方向キー上下で選んで下さい,      設定 3○ 1解除 4×" */
        text_show(" 8\203J\201[\203i\203r1\202\3143\226\332\223I\222n1\202\360, \225\373\214\374\203L\201[\217\343\211\272\202\305\221I\202\361\202\305\211\272\202\263\202\242,      \220\335\222\350 3\201\233 1\211\360\217\234 4\201~", 3, -1, 0, -1, 0, 1);
    } else if (kind == 12) {
        text_close();
        vehicle_navi_show(player, navi[0], 1);
    } else if (kind == 7) {
        if (train->door_state == 3) {
            train->door_state = 1;
            thing_next_vehicle_mode = vehicle_train_end_of_line(thing_next_vehicle_mode);
            if (thing_next_vehicle_mode != 0) {
                vehicle_train_exit_prompt(1);
            }
        } else if (train->door_state == 2) {
            train->door_state = 0;
            train->motion = 1;
            sound_se_play(0x1F);
        }
    } else if (kind == 0) {
        sound_bgm_play(0);
    }
    return 0;
}

void thing_field_do_action(Player *player) {
    SceneRequest *request = &scene_request;
    EventState *ev_state = &event_state;
    ActionSet *set;
    s32 type_bits;
    s32 thing_id;

    if (ev_state->state == 2 && (ev_state->circle_flags & 8)) {
        text_close();
        switch (ev_state->trigger_type) {
        case 0xFD:
            type_bits = ev_state->trigger & 0xF000;
            thing_id = (u16)ev_state->trigger & 0xFFF;
            if (type_bits == 0 && thing_id == 0) {
                sound_se_play(0x16);
                request->change = 1;
                request->pos_x = player->pos_x + player->cell_x * 12500;
                request->pos_y = 0;
                request->pos_z = player->pos_z + player->cell_z * 12500;
                thing_field_exit_code = 3;
                thing_next_vehicle_mode = 1;
                request->yaw = player->yaw;
                request->unk10 = 0;
            } else {
                sound_se_play(0x11);
                for (set = action_find_set(ev_state->circle_set); set != 0; set = action_run_set(set, 0, 0)) {
                }
            }
            break;
        case 0xFE:
            sound_se_play(0xD);
            request->change = 1;
            thing_field_exit_code = 2;
            thing_field_exit_arg_hi = ((u32)ev_state->trigger & 0xFF00) >> 8; /* unk0 is read unsigned here (srl): the cast keeps the bytes */
            thing_field_exit_arg_lo = ev_state->trigger & 0xFF;
            break;
        case 0xFF:
            sound_se_play(0xD);
            thing_field_exit_code = 1;
            request->change = 1;
            sprite_phone_save_exit(ev_state->trigger);
            break;
        case 0x20:
            sound_se_play(0x11);
            thing_next_vehicle_mode = vehicle_train_get_off(thing_next_vehicle_mode);
            break;
        default:
            for (set = action_find_set(ev_state->circle_set); set != 0; set = action_run_set(set, 0, 0)) {
            }
            break;
        }
        ev_state->state = 1;
        ev_state->circle_flags &= ~8;
    }
}

void thing_field_input(void) {
    SceneRequest *request = &scene_request;
    PlayerStatus *status = &player_status;
    KajSystem *pad = &kaj_system;
    s16 mode = pad->pad_mode;
    Player *player = status->player;
    s32 vmode;
    s32 buttons;

    if (mode == 1 && !(player->flags & 2)) {
        buttons = kaj_pad_read();
        vmode = player->vehicle_mode;
        if (vmode == mode) {
            if (vehicle_car_input(status, buttons) != 0) {
                thing_field_exit_code = 4;
                thing_next_vehicle_mode = 0;
                request->change = vmode;
            }
        } else if (effect_item_input(status, 2) == 0) {
            player_update_map(status);
            if ((player->flags & 4) && !(pad->pad_prev & 0x20) && (pad->pad_now & 0x20)) {
                thing_field_do_action(player);
                return;
            }
            player_handle_pad(status, 2, buttons);
        }
    }
}

void thing_field_enter(void) {
    Inventory *inv;
    Player *player;
    TrainState *train;

    thing_next_vehicle_mode = -1;
    D_801DFFAC = 1;
    inv = player_status.inventory;
    player = player_status.player;
    train = &vehicle_train_state;
    sprite_set_visible(0x410, 1);
    action_reset(1);
    if (thing_field_exit_code != 3) {
        player_place_for_scene(2);
    }
    roadmap_init();
    effect_weapon_calc_rate(0);
    effect_weapon_calc_rate(1);
    switch (thing_field_exit_code) {
    case 0:
        object_load_scene();
        if (thing_field_loaded_id != inv->unk42) {
            object_load_res12_by_id(inv->unk42);
            thing_field_loaded_id = inv->unk42;
        }
        effect_flame_small_init(2);
        effect_clut_cycle_init();
        effect_flame_large_init();
    case 1:
    case 2:
    case 3:
    case 4:
        block_set_mode(2);
        break;
    }
    switch (player->vehicle_mode) {
    case 0:
        vehicle_car_place();
        sound_se_play(0x15);
    case 1:
        vehicle_load_data();
        D_801DFED8 = (s32)thing_field_timer_hook;
        thing_set_active(3, 3, 1);
        thing_set_active(3, 4, 1);
        thing_set_animate(3, 3, 1);
        thing_set_animate(3, 4, 1);
        sprite_set_visible(0x40E, 1);
        if (player->vehicle_mode == 1) {
            sound_se_play(0x19);
            sound_se_play(0x1A);
        }
        break;
    case 3:
        D_801DFFAC = 0;
        thing_set_active(4, 0, 0);
    case 2:
        vehicle_load_data();
        D_801DFEE4 = (s32)thing_train_enter_hook;
        D_801DFEE0 = (s32)thing_train_leave_hook;
        D_801DFEDC = (s32)thing_train_tick_hook;
        train->unkC = 0;
        train->trigger = 0;
        train->stop_timer = 0;
        break;
    }
    if (thing_field_exit_code != 0) {
        sprite_thing_refresh_all();
    }
    D_801DFED4 = (s32)thing_field_task_hook;
    thing_field_exit_code = 0;
    event_show_clock(D_801DFFAC);
    sprite_set_visible(0x410, 0);
}

void thing_field_leave(void) {
    Player *player = player_status_player[0];
    s32 i;

    effect_clear_alarms();
    action_reset(1);
    sprite_set_visible(0x40E, 0);
    sound_bgm_stop();
    sound_se_stop_all();
    D_801DFED8 = 0;
    D_801DFED4 = 0;
    D_801DFEE4 = 0;
    D_801DFEE0 = 0;
    D_801DFEDC = 0;
    text_close();
    vehicle_free();
    roadmap_quit();
    switch (thing_field_exit_code) {
    case 0:
        action_free_triggers();
        action_free_all_sets();
        block_free_all();
        thing_free_all();
        effect_flame_small_free();
        effect_flame_large_free();
        sound_bgm_close();
        sound_se_pop_scene();
        for (i = 0; i < 4; i++) {
            sprite_delete((u16)i);
        }
        sprite_delete(0x1FF);
        vehicle_car_release();
        kaj_view_set_bg_color(0, 0, 0);
        break;
    case 3:
        thing_set_active(0, 0, 0);
        break;
    case 1:
        block_hide_all();
        effect_flame_small_free();
        effect_flame_large_free();
        kaj_view_set_bg_color(0, 0, 0);
    case 2:
        thing_set_active(3, 3, 0);
        thing_set_active(3, 4, 0);
        break;
    }
    block_stream_stop();
    if (thing_next_vehicle_mode != -1) {
        player->vehicle_mode = thing_next_vehicle_mode;
    }
}

void thing_field_loop(void) {
    s32 ev[6];
    s16 elevator_wait;
    s16 done;

    elevator_wait = 0;
    done = 0;
    thing_field_enter();
    kaj_timer_enable();
    effect_start_fade(0, 3);
    while (done == 0) {
        switch (kaj_event_get(ev)) {
        case 2:
            func_80189928(ev);
            continue;
        case 0x10:
            event_handle_enter(ev);
            continue;
        case 0x20:
            event_handle_leave(ev);
            continue;
        case 4:
            event_handle_tick(D_801DFFAC);
            continue;
        case 0:
            thing_field_input();
            if ((s16)mail_take_scene_change() != 0) {
                if (thing_field_exit_code == 2) {
                    kaj_pad_reset(0);
                    elevator_wait = 1;
                } else {
                    effect_start_fade(1, 3);
                }
            }
            break;
        case 0x100:
            done = event_handle_effect_done(ev);
            continue;
        default:
            kaj_event_done(ev);
            continue;
        }
        effect_start_alarm(0, 0x404, rand() % 30 + 30);
        mail_step_frame(2, 1, 1);
        if (elevator_wait != 0 && func_8017D564() != 0) {
            done = 1;
        }
    }
    kaj_timer_disable();
    thing_field_leave();
}

void thing_field_timer_hook(Unk_801A8EFC *ev) {
    if (ev->unkC == 0x404) {
        sound_se_play(0x17);
    }
}

s32 thing_train_enter_hook(Unk_801A8EFC *ev) {
    TrainState *train = &vehicle_train_state;
    s32 trigger = ev->unkC;

    if (trigger == 0x200010 || trigger == 0x200020) {
        train->trigger = trigger;
        if (train->door_state == 1) {
            vehicle_train_exit_prompt(1);
        }
        return 1;
    }
    return 0;
}

s32 thing_train_leave_hook(Unk_801A8EFC *ev) {
    TrainState *train = &vehicle_train_state;
    s32 trigger = ev->unkC;

    if (trigger == 0x200010 || trigger == 0x200020) {
        train->trigger = 0;
        vehicle_train_exit_prompt(0);
        return 1;
    }
    if (train->unkC != 0) {
        train->unkC = 0;
    }
    return 0;
}

void thing_train_tick_hook(void) {
    if (vehicle_train_state.motion == 0 && vehicle_train_state.door_state == 1) {
        if (vehicle_train_state.stop_timer > 0) {
            vehicle_train_state.stop_timer--;
        }
        if (vehicle_train_state.stop_timer == 0) {
            vehicle_train_state.stop_timer = -1;
            vehicle_train_set_doors(0);
            vehicle_train_exit_prompt(0);
        }
    }
}

void thing_game_loop(void) {
    thing_field_exit_code = 0;
    block_create_all();
    while (1) {
        thing_field_loop();
        switch (thing_field_exit_code) {
        case 0:
            return;
        case 1:
            sprite_phone_run();
            break;
        case 2:
            block_elevator_run(thing_field_exit_arg_hi, thing_field_exit_arg_lo);
            break;
        }
    }
}

void thing_train_calc_stops(TrainState *train) {
    train->unkA = 0;
    if (train->direction != 0) {
        train->mark_start = (train->station - 1) * 100000 - 195000;
        train->mark_cruise = (train->station - 1) * 100000 - 175000;
        train->mark_brake = (train->station - 1) * 100000 - 115000;
        train->mark_stop = (train->station - 1) * 100000 - 95000;
    } else {
        train->mark_start = (train->station - 1) * 100000 - 200000;
        train->mark_cruise = (train->station - 1) * 100000 - 220000;
        train->mark_brake = (train->station - 1) * 100000 - 280000;
        train->mark_stop = (train->station - 1) * 100000 - 300000;
    }
}

void thing_car_init(Unk_801E032C *car, Player *player) {
    s32 v[3];
    SVector sv;
    s32 flag;
    Unk_801A9BF4 *hdr = car->unkC0;
    Thing *car_thing = D_801E0764[0];
    CarState *state = &vehicle_car_state;
    CarNavi *navi = (CarNavi *)vehicle_navi;
    GameVars *game = &action_vars;

    car->unk0 = hdr->unk0;
    car->unk2 = 0;
    GsSetLsMatrix(car_thing->coord_m);
    state->unk1C.vx = -180;
    state->unk1C.vy = -120;
    state->look_pitch = 0;
    state->look_yaw = 0;
    state->unk28 = 0;
    state->unk1C.vz = 200;
    RotTrans(&state->unk1C, v, &flag);
    if (hdr->unk18 != 0) {
        kaj_tmd_load(&car->unkB8, (u8 *)car->unkC0 + hdr->unk18, &car->unk18);
    }
    GsInitCoordinate2(NULL, &car->unk18);
    car->unk4 = car_thing->pos_x;
    car->unk8 = car_thing->pos_y + 370;
    car->unkC = car_thing->pos_z;
    car->unk10 = car_thing->rot_x;
    car->unk12 = car_thing->rot_y;
    car->unk14 = car_thing->rot_z;
    car->unk30 = car->unk4 - player->cell_x * 12500;
    car->unk34 = car->unk8 + player->cell_y * 32000;
    car->unk38 = car->unkC - player->cell_z * 12500;
    sv.vx = (car->unk10 << 12) / 360;
    sv.vy = (car->unk12 << 12) / 360;
    sv.vz = (car->unk14 << 12) / 360;
    RotMatrix(&sv, car->unk1C);
    if (hdr->unk1C != 0) {
        kaj_tmd_load(&car->unkBC, (u8 *)car->unkC0 + hdr->unk1C, &car->unk68);
    }
    GsInitCoordinate2(&car->unk18, &car->unk68);
    car->unk80 = -180;
    car->unk84 = -360;
    car->unk88 = 412;
    sv.vx = 56;
    sv.vy = 0;
    sv.vz = 0;
    RotMatrix(&sv, car->unk6C);
    player->pos_x = v[0] + player->cell_x * 12500;
    player->pos_y = v[1] - player->cell_y * 32000;
    player->pos_z = v[2] + player->cell_z * 12500;
    player->pitch = 0;
    player->yaw = car->unk12;
    player->unk70 = 0;
    player_set_view(player, 1);
    state->stopped = 0;
    state->unk2 = 0;
    thing_car_exit_prompt_on = 0;
    state->steer = 0;
    state->brake = 0;
    state->throttle = 0;
    state->gear = 0;
    state->speed = 0;
    state->unk14 = 0;
    state->unk18 = 0;
    state->corners[0].vx = -75;
    state->corners[0].vy = 0;
    state->corners[0].vz = 102;
    state->corners[1].vx = 75;
    state->corners[1].vy = 0;
    state->corners[1].vz = 102;
    state->corners[2].vx = -75;
    state->corners[2].vy = 0;
    state->corners[2].vz = -152;
    state->corners[3].vx = 75;
    state->corners[3].vy = 0;
    state->corners[3].vz = -152;
    state->unk4C = 0;
    state->unk50 = 0;
    state->unk54 = 0;
    state->unk5C = 0;
    state->unk60 = 0;
    state->unk64 = 0;
    car->unk18 = 0;
    car->unk68 = 0;
    navi->active = 0;
    navi->unk2 = 1;
    navi->dest = 0;
    navi->start_dist = 0;
    navi->dest_sprite = 0;
    navi->unk10 = 0;
    switch ((s16)game->car_speed_setting) { /* read signed in this unit */
    case 2:
        thing_car_speed_div = 500;
        break;
    case 1:
        thing_car_speed_div = 400;
        break;
    case 0:
        thing_car_speed_div = 300;
        break;
    }
}

static inline s32 func_801A968C_inline(Unk_801E032C *car, Player *player, s32 *px, s32 *py, s32 *pz, s32 ang) {
    s32 x;
    s32 z;
    x = car->unk4 + ((*px * rcos(ang) + *pz * rsin(ang)) >> 12);
    z = car->unkC + ((*pz * rcos(ang) - *px * rsin(ang)) >> 12);
    *px = x - player->cell_x * 12500;
    *pz = z - player->cell_z * 12500;
    if ((s16)func_8017CFE4(*px, py, *pz)) {
        *px = x;
        *pz = z;
        return 1;
    }
    return 0;
}

void thing_car_get_out(Unk_801E032C *car) {
    s32 x;
    s32 y;
    s32 z;
    s32 ang;
    Player *player = player_status_player[0];

    player->unk0 = car->unk4;
    player->unk4 = car->unk8 - 370;
    player->unk8 = car->unkC;
    player->unk10 = car->unk10;
    player->unk12 = car->unk12;
    player->unk14 = car->unk14;
    ang = (car->unk12 << 12) / 360;
    x = -245;
    z = 0;
    if (!func_801A968C_inline(car, player, &x, &y, &z, ang)) {
        x = 245;
        z = 0;
        if (!func_801A968C_inline(car, player, &x, &y, &z, ang)) {
            x = 0;
            z = -490;
            if (!func_801A968C_inline(car, player, &x, &y, &z, ang)) {
                x = 0;
                z = 490;
                if (!func_801A968C_inline(car, player, &x, &y, &z, ang)) {
                    z = 0;
                    y = 0;
                    x = 0;
                }
            }
        }
    }
    sound_se_stop(0x1A);
    vehicle_navi_show(NULL, 0, 1);
    sprite_delete(4);
    vehicle_navi[0] = 0;
    mail_goto_twn(x, y, z, car->unk12, 0);
}

void thing_train_init(Unk_801E032C *car, Player *player) {
    SVector sv;
    Unk_801A9BF4 *hdr = car->unkC0;
    TrainState *train = &vehicle_train_state;

    car->unk0 = hdr->unk0;
    car->unk2 = 0;
    thing_train_calc_stops(train);
    if (hdr->unk18 != 0) {
        kaj_tmd_load(&car->unkB8, (u8 *)car->unkC0 + hdr->unk18, &car->unk18);
    }
    if (hdr->unk1C != 0) {
        kaj_tmd_load(&car->unkBC, (u8 *)car->unkC0 + hdr->unk1C, &car->unk18);
    }
    GsInitCoordinate2(NULL, &car->unk18);
    car->unk4 = player->cell_x * 12500 + player->pos_x;
    car->unk8 = -(player->cell_y * 32000) + 75;
    car->unkC = player->cell_z * 12500 + player->pos_z;
    car->unk10 = 0;
    car->unk12 = 0;
    car->unk14 = 0;
    if (train->direction == 0) {
        car->unk12 = 180;
        player->yaw -= 180;
    }
    train->carry_vx = 0;
    train->carry_vy = 0;
    train->carry_vz = 0;
    train->view_pitch = player->pitch;
    train->view_yaw = player->yaw;
    train->unk38 = player->unk70;
    car->unk30 = car->unk4 - player->cell_x * 12500;
    car->unk34 = car->unk8 + player->cell_y * 32000;
    car->unk38 = car->unkC - player->cell_z * 12500;
    sv.vx = (car->unk10 << 12) / 360;
    sv.vy = (car->unk12 << 12) / 360;
    sv.vz = (car->unk14 << 12) / 360;
    RotMatrix(&sv, car->unk1C);
    car->unk18 = 0;
}

void thing_train_update(Player *player) {
    s32 v[4];
    s32 flag;
    Unk_801E032C *car = D_801E032C[0];
    TrainState *train = &vehicle_train_state;
    GameVars *game = &action_vars;

    if (train->motion != 0) {
        player->unk3C = 1;
    }
    if (train->direction != 0) {
        if (train->motion == 3) {
            train->speed = (train->mark_stop - car->unkC) / 300 + 7;
            car->unkC += train->speed * D_801E6DB4[0];
            if (car->unkC >= train->mark_stop) {
                sound_se_stop(0x1F);
                train->speed = 0;
                car->unkC = train->mark_stop;
                train->motion = 0;
                train->stop_timer = 2;
                if (++train->station >= 7) {
                    train->station = 6;
                }
                thing_train_calc_stops(train);
                vehicle_train_set_doors(1);
                train->unk18 = (s16)game->vars[0x3F] % 10;
                if (train->unk18 >= 5) {
                    train->unk1A = train->unk18 - 5;
                } else {
                    train->unk1A = train->unk18 + 5;
                }
            }
        } else if (train->motion == 1) {
            train->speed = (car->unkC - train->mark_start) / 300 + 7;
            car->unkC += train->speed * D_801E6DB4[0];
            if (car->unkC >= train->mark_cruise) {
                train->motion = 2;
            }
        } else if (train->motion == 2) {
            car->unkC += train->speed * D_801E6DB4[0];
            if (car->unkC >= train->mark_brake) {
                train->motion = 3;
            }
        }
    } else {
        if (train->motion == 3) {
            train->speed = (car->unkC - train->mark_stop) / 300 + 7;
            car->unkC -= train->speed * D_801E6DB4[0];
            if (car->unkC <= train->mark_stop) {
                sound_se_stop(0x1F);
                train->speed = 0;
                car->unkC = train->mark_stop;
                train->motion = 0;
                train->stop_timer = 2;
                if (--train->station == 0) {
                    train->station = 1;
                }
                thing_train_calc_stops(train);
                vehicle_train_set_doors(1);
                train->unk1A = (s16)game->vars[0x3F] % 10;
                if (train->unk1A >= 5) {
                    train->unk18 = train->unk1A - 5;
                } else {
                    train->unk18 = train->unk1A + 5;
                }
            }
        } else if (train->motion == 1) {
            train->speed = (train->mark_start - car->unkC) / 300 + 7;
            car->unkC -= train->speed * D_801E6DB4[0];
            if (car->unkC <= train->mark_cruise) {
                train->motion = 2;
            }
        } else if (train->motion == 2) {
            car->unkC -= train->speed * D_801E6DB4[0];
            if (car->unkC <= train->mark_brake) {
                train->motion = 3;
            }
        }
    }
    car->unk38 = car->unkC - player->cell_z * 12500;
    car->unk18 = 0;
    GsSetLsMatrix(car->unk1C);
    RotTrans(&train->carry_vx, v, &flag);
    player->pos_x = v[0];
    player->pos_z = v[2];
    player->pitch = train->view_pitch + car->unk10;
    player->yaw = train->view_yaw + car->unk12;
    player->unk70 = train->unk38 + car->unk14;
}
