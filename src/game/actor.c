#include "common.h"
#include "game/actor.h"
#include "game/action.h"
#include "game/ai.h"
#include "game/block.h"
#include "game/event.h"
#include "game/mod.h"
#include "game/player.h"
#include "game/sound.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libgs.h"

/*
 * The NPCs of a scene: update, commands, damage, drawing, bodies and stats.
 *
 * File boundaries: likely (docs/layout.md): no assert: jtbl cut (npc jump tables at 4 mod 8).
 */

extern SceneTables object_scene_tables;
extern EventState event_state;
extern s32 kaj_system_vsync_delta[];
extern PlayerStatus player_status;
extern s16 ai_door_noise;
extern s16 ai_weapon_noise;
static s16 actor_update_anim(Npc *npc, s16 state);
void mod_set_anim_by_id();
s16 actor_death_set_1000;

static s16 actor_update_anim(Npc *npc, s16 state) {
    PlayerStatus *status = &player_status;
    Inventory *inventory = status->inventory;
    Model *model;
    NpcStats *stats;
    u16 lo;
    u16 hi;
    u16 frame;
    s32 step;
    s32 n;

    model = mod_find(npc->model_id);
    if (model == NULL) {
        return 0;
    }
    switch (state) {
    case 0:
        if (npc == status->target_npc) {
            inventory->armed = 1;
        }
        if (npc->mode == 1) {
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
        if (npc->mode == 1) {
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
            if (npc->flags & 0x400) {
                npc->flags &= ~0x1000;
            } else {
                mod_set_anim(model, 9, 0);
                break;
            }
        } else if (model->playing == 0) {
            npc->flags &= ~0x1000;
        }
        break;
    case 4:
        if (npc == status->target_npc) {
            inventory->armed = 1;
        }
        if (model->anim != 7) {
            if (npc->flags & 0x400) {
                npc->flags &= ~0x400;
                npc->aim_timer = 0;
            }
            mod_set_anim(model, 7, 5);
            break;
        } else if (model->playing == 0) {
            npc->flags &= ~0x800;
        }
        break;
    case 5:
        if (npc == status->target_npc) {
            inventory->armed = 1;
        }
        stats = actor_find_stats(npc->stats_id);
        if (stats == NULL) {
            return 0;
        }
        switch (model->anim) {
        case 1:
            if (npc->flags & 0x200) {
                npc->flags &= ~0x200;
            }
        case 3:
        case 4:
            mod_set_anim(model, 5, 0);
            break;
        case 5:
            if (model->playing == 0) {
                if (npc->aim_timer != 0) {
                    npc->aim_timer -= kaj_system_vsync_delta[0];
                    if (npc->aim_timer <= 0) {
                        npc->aim_timer = 0;
                        mod_set_anim(model, 6, 0);
                        if ((u16)stats->fire_frames < 0x100 && (u16)stats->fire_frames >= model->end_frame) {
                            stats->fire_frames = model->end_frame - 1;
                        }
                    }
                } else if (stats == NULL) {
                    npc->aim_timer = 30;
                } else {
                    if (stats->aim_time == 0) {
                        stats->aim_time = 1;
                    }
                    npc->aim_timer = stats->aim_time;
                }
            }
            break;
        case 6:
            if (model->playing == 0) {
                npc->flags &= ~0x400;
                if ((u16)stats->weapon_kind == 4) {
                    sound_se_stop(0x27);
                }
            } else {
                step = model->frame_step;
                n = (u16)stats->fire_frames;
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

void actor_update_all(void) {
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
            if (npc->active == 0) {
                continue;
            }
            if (npc->placed == 0) {
                model = mod_find(npc->model_id);
                if (model != NULL) {
                    action_place_npc(npc, model);
                    npc->block = block_find_at(npc->pos_x, npc->pos_y, npc->pos_z);
                    npc->target = -2;
                    npc->target_dist = 0;
                    npc->fire_decision = 0;
                    npc->aim_pitch_diff = 0;
                    npc->aim_elevation = 0;
                    npc->aim_timer = 0;
                    npc->placed = 1;
                    npc->flags |= 1;
                    npc->target_yaw = npc->yaw;
                }
            } else if ((npc->mode != 2 || npc->state != 6)) {
                flags = npc->flags;
                if (flags < 0x100) {
                    if (npc->mode == 2) {
                        EventState *event = &event_state;
                        s32 k = 6;

                        if (npc->state != k) {
                            npc->state = k;
                            npc->flags = 0;
                            set = action_find_set(npc->death_set);
                            if (set != NULL) {
                                actor_death_set_1000 = 0;
                                if (npc->death_set == 1000) {
                                    actor_death_set_1000 = 1;
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
                            mod_set_anim_by_id(npc->model_id, 7, 0);
                        }
                    } else if (npc->state == 0) {
                        actor_update_anim(npc, 0);
                        ai_update_stand(npc);
                    } else if (npc->state == 1) {
                        if (npc->mode == 0) {
                            actor_update_anim(npc, 1);
                            ai_update_move(npc, 0);
                        } else if (npc->mode == 1) {
                            actor_update_anim(npc, 1);
                            ai_update_move(npc, 1);
                        }
                    }
                } else if (npc->state != 6) {
                    if (flags & 0x800) {
                        actor_update_anim(npc, 4);
                    } else if (flags & 0x1000) {
                        actor_update_anim(npc, 3);
                    } else if (flags & 0x400) {
                        if (actor_update_anim(npc, 5) != 0) {
                            ai_fire(npc);
                        }
                    } else if (flags & 0x200) {
                        actor_update_anim(npc, 2);
                        ai_update_stand(npc);
                    } else if (flags & 0x100) {
                        actor_update_anim(npc, 1);
                        ai_update_move(npc, 2);
                    }
                }
            }
        }
        player_pick_target();
        ai_weapon_noise = 0;
        ai_door_noise = 0;
    }
}

void actor_exec_command(Action *action) {
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
            if (npc->id == id) {
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
                target->leave_set = atoi(action->args[2]);
            } else {
                target->talk_set = atoi(action->args[2]);
            }
        } else {
            if (atoi(action->args[1]) != 0) {
                target->death_set = atoi(action->args[2]);
            }
        }
        break;
    case 1:
        target->talkable = atoi(action->args[0]);
        break;
    case 2:
        target->active = atoi(action->args[0]);
        break;
    case 3:
        if (target->mode != 2 && target->state != 6) {
            target->state = atoi(action->args[0]);
        }
        break;
    case 5:
        if (target->mode != 2 && target->state != 6) {
            target->mode = atoi(action->args[0]);
            if (target->mode == 2) {
                target->flags = 0;
            }
        }
        break;
    case 7:
        if (target->mode != 2 && target->state != 6) {
            switch (atoi(action->args[0])) {
            case 0:
                target->flags &= 0x1FF;
                break;
            case 1:
                target->flags |= 0x100;
                break;
            case 3:
                target->flags = (target->flags & 0x1FF) | 0x200;
                break;
            }
        }
        break;
    }
}

void actor_apply_damage(Npc *npc, s32 weapon_class, s32 damage, s16 miss) {
    PlayerStatus *status = &player_status;
    NpcStats *stats;
    s32 defence_roll;
    s16 resisted;
    s32 exp;

    if (npc->hp <= 0) {
        return;
    }
    stats = actor_find_stats(npc->stats_id);
    if (stats == NULL) {
        return;
    }
    if (stats->on_hit == 1) {
        if (npc->mode != 1) {
            npc->mode = 1;
            if (npc->flags & 0x100) {
                npc->flags &= ~0x100;
            }
        }
    } else if (stats->on_hit == 2) {
        if (npc->mode != 1) {
            npc->mode = 1;
            if (npc->state == 0) {
                npc->state = 1;
            }
        }
    }
    if (miss != 0) {
        if (!(npc->flags & 0x1000)) {
            npc->flags |= 0x1000;
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
    npc->hp -= damage;
    if (npc->hp <= 0) {
        if (npc->mode != 2) {
            npc->mode = 2;
            npc->flags = 0;
            exp = npc->exp;
            switch ((u16)npc->kind) {
            case 0:
                status->humans_killed++;
                status->kills_since_arrest++;
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
        if (!(npc->flags & 0x800)) {
            npc->flags |= 0x800;
        }
    }
    event_set_blink(0, 1);
}

void actor_free_all(void) {
    SceneTables *p = &object_scene_tables;
    if (p->npc_count != 0) {
        if (p->npcs != NULL) {
            free3(p->npcs);
        }
        p->npc_count = 0;
        p->npcs = NULL;
    }
}

Npc *actor_find(s16 by_model, u16 id) {
    SceneTables *p = &object_scene_tables;
    Npc *npc = p->npcs;
    s32 i;
    if (p->npc_count == 0) {
        return NULL;
    }
    for (i = 0; i < p->npc_count; i++, npc++) {
        if (by_model == 0) {
            if (npc->id == id) {
                return npc;
            }
        } else {
            if (npc->model_id == id) {
                return npc;
            }
        }
    }
    return NULL;
}

void actor_draw_all(s32 view) {
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
        if (npc != NULL && npc->placed != 0 && npc->active != 0 && block != NULL && block->visible != 0) {
            model = mod_find(npc->model_id);
            if (model != NULL && model->ready != 0) {
                mod_draw(view, model, npc->ot_layer);
            }
        }
    }
}

s16 actor_find_at_point(s16 skip_id, s32 x, s32 y, s32 z) {
    SceneTables *p = &object_scene_tables;
    Npc *npc = p->npcs;
    Model *model;
    s32 i;

    if (p->npc_count == 0) {
        return -2;
    }
    for (i = 0; i < p->npc_count; i++, npc++) {
        if (npc->placed != 0 && npc->active != 0) {
            model = mod_find(npc->model_id);
            if (skip_id != npc->id && model != NULL && model->ready != 0 && model->tmd_objects != NULL) {
                GsSetLsMatrix(model->coord_m);
                if (block_point_on_model(model->tmd_objects, x, y, z, 1) != 0) {
                    return npc->id;
                }
            }
        }
    }
    return -2;
}

void actor_update_blocks(void) {
    SceneTables *p = &object_scene_tables;
    Npc *npc = p->npcs;
    s32 i;
    for (i = 0; i < p->npc_count; i++, npc++) {
        if (npc->placed != 0 && npc->active != 0) {
            npc->block = block_find_at(npc->pos_x, npc->pos_y, npc->pos_z);
        }
    }
}

void actor_rebase_all(s32 x, s32 y, s32 z) {
    SceneTables *p = &object_scene_tables;
    Npc *npc = p->npcs;
    Model *model;
    s32 i;

    if (p->npc_count == 0) {
        return;
    }
    for (i = 0; i < p->npc_count; i++, npc++) {
        if (npc->placed != 0) {
            model = mod_find(npc->model_id);
            if (model != NULL) {
                model->coord_tx = npc->pos_x - x;
                model->coord_ty = npc->pos_y - y;
                model->coord_tz = npc->pos_z - z;
                model->coord_flg = 0;
            }
        }
    }
}

u16 actor_get_radius(Npc *npc) {
    NpcBody *body = actor_find_body(npc->body_id);
    if (body == NULL) {
        return 600;
    }
    return body->radius * 10;
}

void actor_free_bodies(void) {
    SceneTables *p = &object_scene_tables;
    if (p->npc_body_count != 0) {
        if (p->npc_bodies != NULL) {
            free3(p->npc_bodies);
        }
        p->npc_body_count = 0;
        p->npc_bodies = NULL;
    }
}

NpcBody *actor_find_body(s16 id) {
    SceneTables *p = &object_scene_tables;
    NpcBody *body = p->npc_bodies;
    s32 i;
    if (p->npc_body_count == 0 || id < 0) {
        return NULL;
    }
    for (i = 0; i < p->npc_body_count; i++, body++) {
        if (body->id == id) {
            return body;
        }
    }
    return NULL;
}

void actor_free_stats(void) {
    SceneTables *p = &object_scene_tables;
    if (p->npc_stats_count != 0) {
        if (p->npc_stats != NULL) {
            free3(p->npc_stats);
        }
        p->npc_stats_count = 0;
        p->npc_stats = NULL;
    }
}

NpcStats *actor_find_stats(s16 id) {
    SceneTables *p = &object_scene_tables;
    NpcStats *stats = p->npc_stats;
    s32 i;
    if (p->npc_stats_count == 0 || id < 0) {
        return NULL;
    }
    for (i = 0; i < p->npc_stats_count; i++, stats++) {
        if (stats->id == id) {
            return stats;
        }
    }
    return NULL;
}
