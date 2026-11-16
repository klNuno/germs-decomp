#include "common.h"
#include "game/types.h"

LlList *action_queue;
void kaj_ll_insert_before(LlList *a0, s32 a1);
extern SceneTables object_scene_tables;
void free3(void *ptr);
s32 block_find_at(s32 a0, s32 a1, s32 a2);
NpcBody *npc_find_body(s16 arg0);
extern Inventory *player_status_inventory[];
Model *mod_find(u16 arg0);
void mod_draw(s32 arg0, Model *arg1, u16 arg2);
void kaj_ll_remove_to_prev(LlList *arg0);
s16 kaj_ll_at_tail(LlList *arg0);
LlList *action_set_list;
ActionSet *action_run_set(ActionSet *arg0, s32 arg1, s32 arg2);
extern EventState event_state;
void text_release_cmd(void);
void *memset(void *dst, s32 c, u32 n);
extern Player *player_status_player[];
void mod_setup(Model *arg0, s32 arg1, s32 arg2, s32 arg3);
void RotMatrix(SVector *arg0, void *arg1);
void action_place_npc(Npc *arg0, Model *arg1);
ActionSet *action_find_set(s16 arg0);
void text_close(void);
void GsSetLsMatrix(void *m);
s16 block_point_on_model(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4);
Npc *npc_find(s16 arg0, u16 arg1);
s16 mail_wrap_angle(s16 a);
s32 ratan2(s32 y, s32 x);
s32 mail_angle_to_dir4(s16 a);
extern s16 ai_probe_angle[];
s32 rsin(s32 a);
s32 rcos(s32 a);
s16 ai_check_line(Npc *arg0, SceneTrigger *arg1, s32 arg2);
s16 ai_try_move(Npc *arg0, SceneTrigger *arg1, s16 arg2);
extern s32 kaj_system_vsync_delta[];
extern Model *ai_cur_model;
NpcStats *npc_find_stats(s16 arg0);
s16 ai_find_target(Npc *arg0, s16 arg1);
s16 ai_decide_fire(Npc *arg0);
void ai_face_player(Npc *arg0);
extern NpcStats ai_default_stats;
extern NpcBody ai_default_body;
extern Block *ai_cur_block;
extern s32 ai_cur_grid;
extern NpcStats *ai_cur_stats;
extern NpcBody *ai_cur_body;
s32 atoi(char *s);
extern PlayerStatus player_status;
s32 rand(void);
void player_add_skill_exp(s16 arg0, s16 arg1);
void player_add_exp(s32 arg0);
void event_set_blink(s16 arg0, s16 arg1);
extern s16 ai_dir_angle[];
s16 mail_angle_to_dir8(s16 a);
void ai_turn_step(Npc *arg0);
void ai_move_toward(Npc *arg0, s16 arg1, s32 arg2, s32 arg3);
s16 ai_in_aim_cone(Npc *arg0, s16 arg1, s16 arg2);
s16 ai_heading_to(Npc *arg0, s16 arg1);
s32 ai_player_in_front(Npc *arg0);
extern s16 D_801DFC74;
extern s16 D_801DFC76;
void ai_walk(Npc *arg0, s16 arg1, s32 arg2);
s32 ai_step_back(Npc *arg0, s32 arg1);
s32 ai_sidestep(Npc *arg0, s32 arg1);
void mod_set_anim(void *arg0, s16 arg1, s16 arg2);
void sound_se_stop(s32 arg0);
u16 npc_get_radius(Npc *arg0);
extern s16 ai_dir_reverse[];
extern s16 ai_quadrant_dir[4];
extern u16 D_801E03E6[];
s32 abs(s32 x);
void player_take_hit(Npc *arg0, u16 arg1, s32 arg2);
void sound_se_play(s32 arg0);
s32 SquareRoot0(s32 a);
s16 npc_find_at_point(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 block_model_surface(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void ai_update_stand(Npc *arg0);
s16 npc_update_anim(Npc *arg0, s16 arg1);
void ai_update_move(Npc *arg0, s16 arg1);
void ai_fire(Npc *arg0);
void mod_set_anim_by_id();
void player_pick_target(void);
void player_shoot_target(void);
s16 D_801DFC5C;

s16 npc_update_anim(Npc *npc, s16 state) {
    PlayerStatus *status = &player_status;
    Inventory *inventory = status->inventory;
    Model *model;
    NpcStats *stats;
    u16 lo;
    u16 hi;
    u16 frame;
    s32 step;
    s32 n;

    model = mod_find(npc->unk16);
    if (model == NULL) {
        return 0;
    }
    switch (state) {
    case 0:
        if (npc == status->target_npc) {
            inventory->armed = 1;
        }
        if (npc->unkE == 1) {
            if (model->anim != 3) {
                mod_set_anim(model, 3, 0);
                break;
            }
        } else {
            if (model->anim != 0) {
                mod_set_anim(model, 0, 0);
                break;
            }
        }
        break;
    case 1:
        if (npc == status->target_npc) {
            inventory->armed = 1;
        }
        if (npc->unkE == 1) {
            if (model->anim != 4) {
                mod_set_anim(model, 4, 0);
                break;
            } else if (model->playing == 0) {
                mod_set_anim(model, 4, 0);
                break;
            }
        } else {
            if (model->anim != 2) {
                mod_set_anim(model, 2, 0);
                break;
            } else if (model->playing == 0) {
                mod_set_anim(model, 2, 0);
                break;
            }
        }
        break;
    case 2:
        if (npc == status->target_npc) {
            inventory->armed = 0;
        }
        if (model->anim != 1) {
            mod_set_anim(model, 1, 0);
            break;
        } else if (model->playing == 0) {
            mod_set_anim(model, 1, 0);
            break;
        }
        break;
    case 3:
        if (npc == status->target_npc) {
            inventory->armed = 1;
        }
        if (model->anim != 9) {
            if (npc->unk12 & 0x400) {
                npc->unk12 &= ~0x1000;
            } else {
                mod_set_anim(model, 9, 0);
                break;
            }
        } else if (model->playing == 0) {
            npc->unk12 &= ~0x1000;
        }
        break;
    case 4:
        if (npc == status->target_npc) {
            inventory->armed = 1;
        }
        if (model->anim != 7) {
            if (npc->unk12 & 0x400) {
                npc->unk12 &= ~0x400;
                npc->unk46 = 0;
            }
            mod_set_anim(model, 7, 5);
            break;
        } else if (model->playing == 0) {
            npc->unk12 &= ~0x800;
        }
        break;
    case 5:
        if (npc == status->target_npc) {
            inventory->armed = 1;
        }
        stats = npc_find_stats(npc->unk18);
        if (stats == NULL) {
            return 0;
        }
        switch (model->anim) {
        case 1:
            if (npc->unk12 & 0x200) {
                npc->unk12 &= ~0x200;
            }
        case 3:
        case 4:
            mod_set_anim(model, 5, 0);
            break;
        case 5:
            if (model->playing == 0) {
                if (npc->unk46 != 0) {
                    npc->unk46 -= kaj_system_vsync_delta[0];
                    if (npc->unk46 <= 0) {
                        npc->unk46 = 0;
                        mod_set_anim(model, 6, 0);
                        if ((u16)stats->unk16 < 0x100 && (u16)stats->unk16 >= model->end_frame) {
                            stats->unk16 = model->end_frame - 1;
                        }
                    }
                } else if (stats == NULL) {
                    npc->unk46 = 30;
                } else {
                    if (stats->unkE == 0) {
                        stats->unkE = 1;
                    }
                    npc->unk46 = stats->unkE;
                }
            }
            break;
        case 6:
            if (model->playing == 0) {
                npc->unk12 &= ~0x400;
                if ((u16)stats->weapon_kind == 4) {
                    sound_se_stop(0x27);
                }
            } else {
                step = model->frame_step;
                n = (u16)stats->unk16;
                lo = n / step;
                frame = model->frame / step;
                hi = 0xFFFF;
                if ((u16)n > 0x100) {
                    lo = (n & 0xFF) / step;
                    hi = ((n & 0xFF00) >> 8) / step;
                }
                if (lo == frame || hi == frame) {
                    return 1;
                }
            }
            break;
        }
        break;
    }
    return 0;
}

void npc_update_all(void) {
    Npc *npc;
    Model *model;
    ActionSet *set;
    s32 i;
    u16 flags;
    SceneTables *tables = &object_scene_tables;

    npc = tables->npcs;
    if (tables->npc_count != 0) {
        player_shoot_target();
        for (i = 0; i < tables->npc_count; i++, npc++) {
            if (npc->unk6 == 0) {
                continue;
            }
            if (npc->unk4 == 0) {
                model = mod_find(npc->unk16);
                if (model != NULL) {
                    action_place_npc(npc, model);
                    npc->block = block_find_at(npc->unk20, npc->unk24, npc->unk28);
                    npc->unk10 = -2;
                    npc->unk40 = 0;
                    npc->unkB = 0;
                    npc->unk44 = 0;
                    npc->unk45 = 0;
                    npc->unk46 = 0;
                    npc->unk4 = 1;
                    npc->unk12 |= 1;
                    npc->unk3E = npc->unk3A;
                }
            } else if ((npc->unkE != 2 || npc->unkF != 6)) {
                flags = npc->unk12;
                if (flags < 0x100) {
                    if (npc->unkE == 2) {
                        EventState *event = &event_state;
                        s32 k = 6;

                        if (npc->unkF != k) {
                            npc->unkF = k;
                            npc->unk12 = 0;
                            set = action_find_set(npc->unk1E);
                            if (set != NULL) {
                                D_801DFC5C = 0;
                                if (npc->unk1E == 1000) {
                                    D_801DFC5C = 1;
                                }
                                do {
                                    set = action_run_set(set, 0, 0);
                                } while (set != NULL);
                                if (event->state == 0) {
                                    event->state = 1;
                                }
                            }
                            sound_se_stop(0x27);
                            sound_se_play(0x14);
                            mod_set_anim_by_id(npc->unk16, 7, 0);
                        }
                    } else if (npc->unkF == 0) {
                        npc_update_anim(npc, 0);
                        ai_update_stand(npc);
                    } else if (npc->unkF == 1) {
                        if (npc->unkE == 0) {
                            npc_update_anim(npc, 1);
                            ai_update_move(npc, 0);
                        } else if (npc->unkE == 1) {
                            npc_update_anim(npc, 1);
                            ai_update_move(npc, 1);
                        }
                    }
                } else if (npc->unkF != 6) {
                    if (flags & 0x800) {
                        npc_update_anim(npc, 4);
                    } else if (flags & 0x1000) {
                        npc_update_anim(npc, 3);
                    } else if (flags & 0x400) {
                        if (npc_update_anim(npc, 5) != 0) {
                            ai_fire(npc);
                        }
                    } else if (flags & 0x200) {
                        npc_update_anim(npc, 2);
                        ai_update_stand(npc);
                    } else if (flags & 0x100) {
                        npc_update_anim(npc, 1);
                        ai_update_move(npc, 2);
                    }
                }
            }
        }
        player_pick_target();
        D_801DFC76 = 0;
        D_801DFC74 = 0;
    }
}

void npc_exec_command(Action *action) {
    SceneTables *tables = &object_scene_tables;
    Npc *npc = tables->npcs;
    ActionCmdShort *cmd = (ActionCmdShort *)action->cmd;
    u16 id = cmd->target;
    Npc *target;
    s32 i;

    if (tables->npc_count == 0) {
        target = NULL;
    } else {
        for (i = 0; i < tables->npc_count; i++, npc++) {
            if (npc->unk0 == id) {
                target = npc;
                goto done;
            }
        }
        target = NULL;
    }
done:
    if (target == NULL) {
        return;
    }
    switch (cmd->sub) {
    case 0:
        if (atoi(action->args[0]) != 0) {
            if (atoi(action->args[1]) != 0) {
                target->unk1C = atoi(action->args[2]);
            } else {
                target->unk1A = atoi(action->args[2]);
            }
        } else {
            if (atoi(action->args[1]) != 0) {
                target->unk1E = atoi(action->args[2]);
            }
        }
        break;
    case 1:
        target->unk8 = atoi(action->args[0]);
        break;
    case 2:
        target->unk6 = atoi(action->args[0]);
        break;
    case 3:
        if (target->unkE != 2 && target->unkF != 6) {
            target->unkF = atoi(action->args[0]);
        }
        break;
    case 5:
        if (target->unkE != 2 && target->unkF != 6) {
            target->unkE = atoi(action->args[0]);
            if (target->unkE == 2) {
                target->unk12 = 0;
            }
        }
        break;
    case 7:
        if (target->unkE != 2 && target->unkF != 6) {
            switch (atoi(action->args[0])) {
            case 0:
                target->unk12 &= 0x1FF;
                break;
            case 1:
                target->unk12 |= 0x100;
                break;
            case 3:
                target->unk12 = (target->unk12 & 0x1FF) | 0x200;
                break;
            }
        }
        break;
    }
}

void npc_apply_damage(Npc *npc, s32 weapon_class, s32 damage, s16 miss) {
    PlayerStatus *status = &player_status;
    NpcStats *stats;
    s32 defence_roll;
    s16 resisted;
    s32 exp;

    if (npc->unkC <= 0) {
        return;
    }
    stats = npc_find_stats(npc->unk18);
    if (stats == NULL) {
        return;
    }
    if (stats->unk4 == 1) {
        if (npc->unkE != 1) {
            npc->unkE = 1;
            if (npc->unk12 & 0x100) {
                npc->unk12 &= ~0x100;
            }
        }
    } else if (stats->unk4 == 2) {
        if (npc->unkE != 1) {
            npc->unkE = 1;
            if (npc->unkF == 0) {
                npc->unkF = 1;
            }
        }
    }
    if (miss != 0) {
        if (!(npc->unk12 & 0x1000)) {
            npc->unk12 |= 0x1000;
        }
        event_set_blink(1, 1);
        return;
    }
    if (stats->defence == 0x7FFF) {
        defence_roll = 0x7FFF;
    } else {
        defence_roll = rand() % stats->defence;
    }
    resisted = 0;
    switch (weapon_class) {
    case 0:
        if (stats->resist_types & 1) {
            resisted = 1;
        }
        break;
    case 1:
        if (stats->resist_types & 2) {
            resisted = 1;
        }
        break;
    case 2:
        if (stats->resist_types & 4) {
            resisted = 1;
        }
        break;
    case 3:
        if (stats->resist_types & 8) {
            resisted = 1;
        }
        break;
    case 4:
        if (stats->resist_types & 0x10) {
            resisted = 1;
        }
        break;
    }
    if (!resisted) {
        defence_roll = defence_roll * 2 / 3;
    }
    damage -= defence_roll;
    if (damage <= 0) {
        event_set_blink(1, 1);
        return;
    }
    player_add_skill_exp(weapon_class, damage * 2);
    npc->unkC -= damage;
    if (npc->unkC <= 0) {
        if (npc->unkE != 2) {
            npc->unkE = 2;
            npc->unk12 = 0;
            exp = npc->unk42;
            switch ((u16)npc->unk2) {
            case 0:
                status->unk32++;
                status->unk2E++;
                break;
            case 1:
            case 2:
                exp *= 2;
                break;
            case 3:
            case 4:
            case 5:
                exp *= 3;
                break;
            case 16:
            case 17:
            case 18:
                exp *= 4;
                break;
            case 19:
                exp *= 6;
                break;
            }
            player_add_exp(exp);
        }
    } else {
        if (!(npc->unk12 & 0x800)) {
            npc->unk12 |= 0x800;
        }
    }
    event_set_blink(0, 1);
}

void npc_free_all(void) {
    SceneTables *p = &object_scene_tables;
    if (p->npc_count != 0) {
        if (p->npcs != NULL) {
            free3(p->npcs);
        }
        p->npc_count = 0;
        p->npcs = NULL;
    }
}

Npc *npc_find(s16 by_model, u16 id) {
    SceneTables *p = &object_scene_tables;
    Npc *npc = p->npcs;
    s32 i;
    if (p->npc_count == 0) {
        return NULL;
    }
    for (i = 0; i < p->npc_count; i++, npc++) {
        if (by_model == 0) {
            if (npc->unk0 == id) {
                return npc;
            }
        } else {
            if (npc->unk16 == id) {
                return npc;
            }
        }
    }
    return NULL;
}

void npc_draw_all(s32 view) {
    SceneTables *p = &object_scene_tables;
    Npc *npc = p->npcs;
    Block *block;
    Model *model;
    s32 i;

    if (p->npc_count == 0) {
        return;
    }
    for (i = 0; i < p->npc_count; i++, npc++) {
        block = (Block *)npc->block;
        if (npc != NULL && npc->unk4 != 0 && npc->unk6 != 0 && block != NULL && block->visible != 0) {
            model = mod_find(npc->unk16);
            if (model != NULL && model->ready != 0) {
                mod_draw(view, model, npc->unkA);
            }
        }
    }
}

s16 npc_find_at_point(s16 skip_id, s32 x, s32 y, s32 z) {
    SceneTables *p = &object_scene_tables;
    Npc *npc = p->npcs;
    Model *model;
    s32 i;

    if (p->npc_count == 0) {
        return -2;
    }
    for (i = 0; i < p->npc_count; i++, npc++) {
        if (npc->unk4 != 0 && npc->unk6 != 0) {
            model = mod_find(npc->unk16);
            if (skip_id != npc->unk0 && model != NULL && model->ready != 0 && model->tmd_objects != NULL) {
                GsSetLsMatrix(model->coord_m);
                if (block_point_on_model(model->tmd_objects, x, y, z, 1) != 0) {
                    return npc->unk0;
                }
            }
        }
    }
    return -2;
}

void npc_update_blocks(void) {
    SceneTables *p = &object_scene_tables;
    Npc *npc = p->npcs;
    s32 i;
    for (i = 0; i < p->npc_count; i++, npc++) {
        if (npc->unk4 != 0 && npc->unk6 != 0) {
            npc->block = block_find_at(npc->unk20, npc->unk24, npc->unk28);
        }
    }
}

void npc_rebase_all(s32 x, s32 y, s32 z) {
    SceneTables *p = &object_scene_tables;
    Npc *npc = p->npcs;
    Model *model;
    s32 i;

    if (p->npc_count == 0) {
        return;
    }
    for (i = 0; i < p->npc_count; i++, npc++) {
        if (npc->unk4 != 0) {
            model = mod_find(npc->unk16);
            if (model != NULL) {
                model->coord_tx = npc->unk20 - x;
                model->coord_ty = npc->unk24 - y;
                model->coord_tz = npc->unk28 - z;
                model->coord_flg = 0;
            }
        }
    }
}

u16 npc_get_radius(Npc *npc) {
    NpcBody *body = npc_find_body(npc->unk14);
    if (body == NULL) {
        return 600;
    }
    return body->radius * 10;
}

void npc_free_bodies(void) {
    SceneTables *p = &object_scene_tables;
    if (p->npc_body_count != 0) {
        if (p->npc_bodies != NULL) {
            free3(p->npc_bodies);
        }
        p->npc_body_count = 0;
        p->npc_bodies = NULL;
    }
}

NpcBody *npc_find_body(s16 id) {
    SceneTables *p = &object_scene_tables;
    NpcBody *body = p->npc_bodies;
    s32 i;
    if (p->npc_body_count == 0 || id < 0) {
        return NULL;
    }
    for (i = 0; i < p->npc_body_count; i++, body++) {
        if (body->unk0 == id) {
            return body;
        }
    }
    return NULL;
}

void npc_free_stats(void) {
    SceneTables *p = &object_scene_tables;
    if (p->npc_stats_count != 0) {
        if (p->npc_stats != NULL) {
            free3(p->npc_stats);
        }
        p->npc_stats_count = 0;
        p->npc_stats = NULL;
    }
}

NpcStats *npc_find_stats(s16 id) {
    SceneTables *p = &object_scene_tables;
    NpcStats *stats = p->npc_stats;
    s32 i;
    if (p->npc_stats_count == 0 || id < 0) {
        return NULL;
    }
    for (i = 0; i < p->npc_stats_count; i++, stats++) {
        if (stats->unk0 == id) {
            return stats;
        }
    }
    return NULL;
}
