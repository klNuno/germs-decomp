#include "common.h"
#include "game/types.h"

LlList *action_queue;
void kaj_ll_insert_before(LlList *list, s32 data);
/* A world point or a step (x, y, z), passed to ai_check_line and ai_try_move. */
typedef struct AiPoint { s32 x; s32 y; s32 z; } AiPoint;
extern SceneTables object_scene_tables;
void free3(void *ptr);
s32 block_find_at(s32 x, s32 y, s32 z);
NpcBody *npc_find_body(s16 id);
extern Inventory *player_status_inventory[];
Model *mod_find(u16 id);
void mod_draw(ViewBuffer *view, Model *mod, u16 ot_layer);
void kaj_ll_remove_to_prev(LlList *list);
s16 kaj_ll_at_tail(LlList *list);
LlList *action_set_list;
ActionSet *action_run_set(ActionSet *set, s32 at_cursor, s32 skip_text_wait);
extern EventState event_state;
void text_release_cmd(void);
void *memset(void *dst, s32 c, u32 n);
extern Player *player_status_player[];
void mod_setup(Model *mod, s32 parent, s32 kind, s32 anim);
void RotMatrix(SVector *arg0, void *arg1);
void action_place_npc(Npc *npc, Model *model);
ActionSet *action_find_set(s16 id);
void text_close(void);
void GsSetLsMatrix(void *m);
s16 block_point_on_model(void *obj, s32 x, s32 y, s32 z, u16 mode);
Npc *npc_find(s16 by_model, u16 id);
s16 mail_wrap_angle(s16 angle);
s32 ratan2(s32 y, s32 x);
s32 mail_angle_to_dir4(s16 angle);
extern s16 ai_probe_angle[];
s32 rsin(s32 a);
s32 rcos(s32 a);
s16 ai_check_line(Npc *npc, AiPoint *point, s32 flags);
s16 ai_try_move(Npc *npc, AiPoint *delta, s16 angle);
extern s32 kaj_system_vsync_delta[];
Model *ai_cur_model;
NpcStats *npc_find_stats(s16 id);
s16 ai_find_target(Npc *npc, s16 turn_mode);
s16 ai_decide_fire(Npc *npc);
void ai_face_player(Npc *npc);
extern NpcStats ai_default_stats;
extern NpcBody ai_default_body;
Block *ai_cur_block;
s32 ai_cur_grid;
NpcStats *ai_cur_stats;
NpcBody *ai_cur_body;
s32 atoi(char *s);
extern PlayerStatus player_status;
s32 rand(void);
void player_add_skill_exp(s16 skill, s16 exp);
void player_add_exp(s32 exp);
void event_set_blink(s16 which, s16 on);
extern s16 ai_dir_angle[];
s16 mail_angle_to_dir8(s16 angle);
void ai_turn_step(Npc *npc);
void ai_move_toward(Npc *npc, s16 mode, s32 dist, s32 waypoint);
s16 ai_in_aim_cone(Npc *npc, s16 npc_aims, s16 weapon_id);
s16 ai_heading_to(Npc *npc, s16 target);
s32 ai_player_in_front(Npc *npc);
s16 ai_door_noise;
s16 ai_weapon_noise;
void ai_walk(Npc *npc, s16 mode, s32 dist);
s32 ai_step_back(Npc *npc, s32 dist);
s32 ai_sidestep(Npc *npc, s32 dist);
void mod_set_anim(void *mod, s16 anim, s16 frames);
void sound_se_stop(s32 id);
u16 npc_get_radius(Npc *npc);
extern s16 ai_dir_reverse[];
extern s16 ai_quadrant_dir[4];
extern u16 action_vars_minute[];
s32 abs(s32 x);
void player_take_hit(Npc *npc, u16 weapon_kind, s32 damage);
void sound_se_play(s32 id);
s32 SquareRoot0(s32 a);
s16 npc_find_at_point(s16 skip_id, s32 x, s32 y, s32 z);
s32 block_model_surface(void *obj, s32 x, s32 z, s32 height_out);

static inline s32 cvx(s32 x) {
    s32 d = x - ai_cur_block->pos_x;
    s32 t = d >> 8;
    s32 o = ((Arena *)ai_cur_grid)->origin_x;
    return (d & 0xFF) ? t + 1 + o : t + o;
}

static inline s32 cvz(s32 z) {
    s32 d = z - ai_cur_block->pos_z;
    s32 t = d >> 8;
    s32 o = ((Arena *)ai_cur_grid)->origin_z;
    return (d & 0xFF) ? t + 1 + o : t + o;
}

static inline s32 cell(s32 x, s32 z) {
    Arena *grid = (Arena *)ai_cur_grid;
    s32 i;
    s32 shift;
    if (x < 0 || x >= grid->width || z < 0 || z >= grid->depth) {
        return 1;
    }
    i = z * (grid->width >> 2) + (x >> 2);
    shift = (x % 4) * 2;
    return (((u8 *)grid->data)[i] & (3 << shift)) >> shift;
}

static inline s16 pass(s32 cell_value, s32 mode) {
    if (cell_value == 1) {
        return 0;
    }
    if (mode == 1) {
        if (cell_value == 2) {
            return 0;
        }
        if (cell_value != 0) {
            return 1;
        }
        return 0;
    }
    if (mode == 2 && cell_value == 2) {
        return 0;
    }
    return 1;
}

s16 ai_check_line(Npc *npc, AiPoint *point, s32 flags) {
    Player *player;
    s32 mode;
    s32 d;
    s32 x0;
    s32 z0;
    s32 x1;
    s32 z1;
    s32 dx;
    s32 dz;
    s32 sx;
    s32 sz;
    s32 err;
    s32 i;
    s32 ok;
    s32 elevation;
    s16 pitch_diff;

    if (ai_cur_block == NULL || ai_cur_grid == 0) {
        return 0;
    }
    if ((flags & 1) && ai_cur_block->in_arena == 0) {
        return 0;
    }
    mode = 0;
    if (!(flags & 2)) {
        mode = 1;
        if (flags & 0x10) {
            mode = 2;
        }
    }
    if (flags & 4) {
        npc->target_dist = 0;
    }
    if (flags & 8) {
        npc->aim_pitch_diff = 0;
        npc->aim_elevation = 0;
    }
    x0 = cvx(npc->pos_x);
    z0 = cvz(npc->pos_z);
    if (mode == 0) {
        x1 = cvx(point->x);
        z1 = cvz(point->z);
    } else {
        x1 = cvx(npc->pos_x + point->x);
        z1 = cvz(npc->pos_z + point->z);
    }
    dx = x1 - x0;
    dz = z1 - z0;
    err = 0;
    if (dx < 0) {
        dx = -dx;
        sx = -1;
    } else {
        sx = 1;
    }
    sz = 1;
    if (dz < 0) {
        dz = -dz;
        sz = -1;
    }
    if (dz < dx) {
        for (i = 0; i <= dx; i++) {
            ok = pass(cell(x0, z0), mode);
            if (!ok) {
                return 0;
            }
            err += dz;
            x0 += sx;
            if (err > dx) {
                err -= dx;
                z0 += sz;
            }
        }
    } else {
        for (i = 0; i <= dz; i++) {
            ok = pass(cell(x0, z0), mode);
            if (!ok) {
                return 0;
            }
            err += dx;
            z0 += sz;
            if (err > 0) {
                err -= dz;
                x0 += sx;
            }
        }
    }
    if (flags & 4) {
        x1 = point->x - npc->pos_x;
        d = point->z - npc->pos_z;
        npc->target_dist = SquareRoot0(x1 * x1 + d * d);
        if (flags & 8) {
            player = player_status_player[0];
            elevation = (ratan2(point->y - npc->pos_y, (u16)npc->target_dist) * 0x1680) >> 16;
            npc->aim_elevation = abs(elevation);
            pitch_diff = abs(player->pitch - elevation);
            if (pitch_diff < 0x100) {
                npc->aim_pitch_diff = pitch_diff;
            } else {
                npc->aim_pitch_diff = 0xFF;
            }
        }
    }
    return 1;
}

void ai_turn_step(Npc *npc) {
    SVector rot;
    s16 turn;
    s16 diff;
    s16 step;

    if (npc->yaw != npc->target_yaw) {
        diff = npc->target_yaw - npc->yaw;
        step = kaj_system_vsync_delta[0] * 2;
        turn = diff;
        if (npc->yaw < npc->target_yaw) {
            if (diff >= 180) {
                turn = diff - 360;
            }
        } else {
            if (diff < -179) {
                turn = diff + 360;
            }
        }
        if (turn > 0) {
            if (step < turn) {
                turn = step;
            }
        } else {
            if (turn < -step) {
                turn = -step;
            }
        }
        npc->yaw = mail_wrap_angle(npc->yaw + turn);
        if (ai_cur_model != NULL && ai_cur_model->ready != 0) {
            rot.vx = (npc->pitch << 12) / 360;
            rot.vy = (npc->yaw << 12) / 360;
            rot.vz = (npc->roll << 12) / 360;
            RotMatrix(&rot, ai_cur_model->coord_m);
            ai_cur_model->coord_flg = 0;
        }
    }
}

s16 ai_heading_to(Npc *npc, s16 target) {
    Player *player = player_status_player[0];
    Npc *other;
    s32 dx;
    s32 dz;

    if (target == -2) {
        if (!(npc->flags & 0x100)) {
            return 0;
        }
        dx = npc->dest_x - npc->pos_x;
        dz = npc->dest_z - npc->pos_z;
    } else if (target == -1) {
        dx = player->pos_x + player->cell_x * 12500 - npc->pos_x;
        dz = player->pos_z + player->cell_z * 12500 - npc->pos_z;
    } else {
        other = npc_find(0, target);
        if (other == 0) {
            return 0;
        }
        dx = other->pos_x - npc->pos_x;
        dz = other->pos_z - npc->pos_z;
    }
    return mail_wrap_angle((ratan2(dx, dz) * 360 >> 12) - 180);
}

s32 ai_player_in_front(Npc *npc) {
    Player *player = player_status_player[0];
    s32 dx;
    s32 dz;

    dx = player->pos_x + player->cell_x * 12500 - npc->pos_x;
    dz = player->pos_z + player->cell_z * 12500 - npc->pos_z;
    if (dx >= -9999 && dx < 10000 && dz >= -9999 && dz < 10000) {
        return 1;
    }
    switch ((s16)mail_angle_to_dir4(npc->yaw - 180)) {
    case 0:
        if (dx < 0) {
            return 0;
        }
        break;
    case 4:
        if (dx >= 0) {
            return 0;
        }
        break;
    case 6:
        if (dz >= 0) {
            return 0;
        }
        break;
    case 2:
        if (dz < 0) {
            return 0;
        }
        break;
    }
    return 1;
}

s16 ai_find_target(Npc *npc, s16 turn_mode) {
    AiPoint point;
    s16 found;
    u16 min;
    u16 saved;
    s32 best_id;
    s16 player_heading;
    s16 npc_heading;
    s32 i;
    u16 dist;
    s16 diff;
    Npc *other;
    Player *player;
    SceneTables *tables = &object_scene_tables;

    min = 0xFFFF;
    saved = 0;
    found = 0;
    other = tables->npcs;
    player = player_status_player[0];
    npc->target = -2;
    best_id = -2;
    npc_heading = -1;
    npc->target_dist = 0;
    npc->flags &= ~6;
    player_heading = npc_heading;
    if (ai_cur_block->in_arena != 0
        && (ai_door_noise != 0 || ai_weapon_noise != 0 || (s16)ai_player_in_front(npc) != 0)) {
        point.x = player->pos_x + player->cell_x * 12500;
        point.y = player->pos_y - player->cell_y * 32000 + 1600;
        point.z = player->pos_z + player->cell_z * 12500;
        if (ai_check_line(npc, &point, 15) != 0) {
            saved = npc->target_dist;
            min = saved;
            npc->flags |= 2;
            player_heading = ai_heading_to(npc, -1);
            found = 1;
        }
    }
    if (turn_mode == 2) {
        npc->target_yaw = ai_heading_to(npc, -2);
        ai_turn_step(npc);
        return 0;
    }
    if (tables->npc_count > 0) {
        for (i = 0; i < tables->npc_count; i++, other++) {
            if (other->placed != 0 && other->active != 0 && other->id != npc->id && other->mode != 2 && other->state != 6
                && other->pos_y == npc->pos_y) {
                point.x = other->pos_x;
                point.y = other->pos_y;
                point.z = other->pos_z;
                if (ai_check_line(npc, &point, 6) != 0) {
                    dist = npc->target_dist;
                    if (dist != 0 && dist < min) {
                        min = dist;
                        best_id = other->id;
                    }
                }
            }
        }
        npc_heading = ai_heading_to(npc, best_id);
    }
    if (found == 0 && best_id < 0) {
        return 0;
    }
    if (found != 0) {
        if (best_id >= 0) {
            diff = mail_wrap_angle(player_heading - npc_heading);
            if (diff < 10 || diff > 350) {
                npc->flags |= 4;
            }
        }
        if (turn_mode == 1) {
            npc->target_yaw = player_heading;
            ai_turn_step(npc);
        }
        npc->target = -1;
        npc->target_dist = saved;
    } else {
        npc->target = best_id;
        npc->target_dist = 0;
    }
    return 1;
}

s16 ai_try_move(Npc *npc, AiPoint *delta, s16 angle) {
    Player *player = player_status_player[0];
    SVector rot;
    s32 floor_y;
    s32 radius;
    s32 x;
    s32 z;
    s32 dx;
    s32 dz;
    s32 block;
    s32 ax;
    s32 off_x;
    s32 off_z;

    if (ai_cur_block == NULL) {
        return 0;
    }
    if (!(ai_cur_block->model_flags & 1)) {
        return 0;
    }
    npc->flags &= ~0x10;
    ax = delta->x;
    if (ax == 0 && delta->z == 0) {
        return 1;
    }
    radius = ai_cur_body->radius * 10;
    x = npc->pos_x + ax - player->cell_x * 12500;
    z = npc->pos_z + delta->z - player->cell_z * 12500;
    off_x = radius * rsin(angle) >> 12;
    off_z = radius * rcos(angle) >> 12;
    if (npc_find_at_point(npc->id, x + off_x, npc->pos_y, z + off_z) >= 0) {
        return 0;
    }
    radius += 600;
    dx = abs(x - player->pos_x);
    dz = abs(z - player->pos_z);
    if (dx <= radius && dz <= radius) {
        npc->flags |= 0x10;
        return npc->mode == 1;
    }
    if (block_model_surface(ai_cur_block->floor_model, x, z, (s32)&floor_y) == 0) {
        return 0;
    }
    npc->pos_x += delta->x;
    npc->pos_y = floor_y - player->cell_y * 32000;
    npc->pos_z += delta->z;
    if (ai_cur_model == NULL || ai_cur_model->ready == 0) {
        return 0;
    }
    ai_cur_model->coord_tx = npc->pos_x - player->cell_x * 12500;
    ai_cur_model->coord_ty = npc->pos_y + player->cell_y * 32000;
    ai_cur_model->coord_tz = npc->pos_z - player->cell_z * 12500;
    rot.vx = (npc->pitch << 12) / 360;
    rot.vy = (npc->yaw << 12) / 360;
    rot.vz = (npc->roll << 12) / 360;
    RotMatrix(&rot, ai_cur_model->coord_m);
    ai_cur_model->coord_flg = 0;
    block = block_find_at(npc->pos_x, npc->pos_y, npc->pos_z);
    if (npc->block != block) {
        npc->block = block;
    }
    return 1;
}

static inline s32 ai_move_toward_try_dir(Npc *npc, s16 dir, s32 dist, s16 waypoint) {
    AiPoint delta;
    s16 angle;
    npc->target_yaw = ai_dir_angle[dir];
    ai_turn_step(npc);
    angle = (mail_wrap_angle(npc->target_yaw - 180) << 12) / 360;
    delta.x = dist * rsin(angle) >> 12;
    delta.y = 0;
    delta.z = dist * rcos(angle) >> 12;
    if (!ai_check_line(npc, &delta, (waypoint != 0) * 16) || !ai_try_move(npc, &delta, angle)) {
        return 0;
    }
    return 1;
}

void ai_move_toward(Npc *npc, s16 mode, s32 dist, s32 waypoint) {
    s16 wp_flag = waypoint;
    Player *player = player_status_player[0];
    s16 dirs[2];
    s16 cur;
    s16 back;
    s32 dx;
    s32 dz;
    Npc *target;
    s16 offset;
    s16 angle;
    s16 dir;
    s32 k;

    cur = mail_angle_to_dir8(npc->yaw - 180);
    back = ai_dir_reverse[cur];
    dirs[1] = 8;
    dirs[0] = 8;
    if (mode == 0) {
        goto fallback;
    }
    if (mode == 1) {
        if (npc->target == -2) {
            goto fallback;
        }
        if (npc->target == -1) {
            dx = player->pos_x + player->cell_x * 12500 - npc->pos_x;
            dz = player->pos_z + player->cell_z * 12500 - npc->pos_z;
        } else {
            target = npc_find(0, npc->target);
            if (target == 0 || target->target != -1) {
                goto fallback;
            }
            offset = npc_get_radius(target) + ai_cur_body->radius * 10;
            angle = (mail_wrap_angle(target->yaw - 270) << 12) / 360;
            if (target->id & 1) {
                offset = -offset;
            }
            dx = target->pos_x + (offset * rsin(angle) >> 12) - npc->pos_x;
            dz = target->pos_z + (offset * rcos(angle) >> 12) - npc->pos_z;
        }
    } else {
        dx = npc->dest_x - npc->pos_x;
        dz = npc->dest_z - npc->pos_z;
    }
    if (dx >= 2) {
        dirs[0] = 0;
    } else if (dx < -1) {
        dirs[0] = 4;
    }
    if (dz < -1) {
        dirs[1] = 6;
    } else if (dz >= 2) {
        dirs[1] = 2;
    }
    if (dirs[0] != 8 && dirs[1] != 8) {
        dir = ai_quadrant_dir[((dz < 0) ? 2 : 0) + (dx > 0)];
        if (dir != back && ai_move_toward_try_dir(npc, dir, dist, wp_flag)) {
            return;
        }
    }
    if ((rand() & 1) || abs(dz) > abs(dx)) {
        dir = dirs[0];
        dirs[0] = dirs[1];
        dirs[1] = dir;
    }
    if (dirs[0] != 8 && dirs[0] != back && ai_move_toward_try_dir(npc, dirs[0], dist, wp_flag)) {
        return;
    }
    if (dirs[1] != 8 && dirs[1] != back && ai_move_toward_try_dir(npc, dirs[1], dist, wp_flag)) {
        return;
    }
fallback:
    if (cur != 8 && ai_move_toward_try_dir(npc, cur, dist, wp_flag)) {
        return;
    }
    if (action_vars_minute[0] & 1) {
        dir = cur + 1;
        if (dir >= 8 || cur == 8) {
            dir = 0;
        }
        for (k = 0; k < 8; k++, dir++) {
            if (dir >= 8) {
                dir = 0;
            }
            if (dir != back && ai_move_toward_try_dir(npc, dir, dist, wp_flag)) {
                return;
            }
        }
    } else {
        dir = cur - 1;
        if (dir < 0 || cur == 8) {
            dir = 7;
        }
        for (k = 0; k < 8; k++, dir--) {
            if (dir < 0) {
                dir = 7;
            }
            if (dir != back && ai_move_toward_try_dir(npc, dir, dist, wp_flag)) {
                return;
            }
        }
    }
    if (back != 8 && ai_move_toward_try_dir(npc, back, dist, wp_flag)) {
        return;
    }
    npc->target_yaw = ai_dir_angle[cur];
    ai_turn_step(npc);
}

void ai_walk(Npc *npc, s16 mode, s32 dist) {
    AiPoint delta;
    s32 wp_flag;
    s16 dir;
    s16 angle;
    s32 done;

    wp_flag = 0;
    if (mode == 2) {
        wp_flag = 1;
        if (npc->dest_x / 256 == npc->pos_x / 256 && npc->dest_z / 256 == npc->pos_z / 256) {
            if (npc->flags & 0x100) {
                npc->flags &= ~0x100;
            }
            done = 1;
        } else {
            done = 0;
        }
        if (done) {
            return;
        }
    }
    dir = mail_angle_to_dir8(npc->target_yaw - 180);
    if ((rand() & 3) != 1) {
        npc->target_yaw = ai_dir_angle[dir];
        ai_turn_step(npc);
        angle = (mail_wrap_angle(npc->target_yaw - 180) << 12) / 360;
        delta.x = dist * rsin(angle) >> 12;
        delta.y = 0;
        delta.z = dist * rcos(angle) >> 12;
        if (!ai_check_line(npc, &delta, wp_flag * 16) || !ai_try_move(npc, &delta, angle)) {
            done = 0;
        } else {
            done = 1;
        }
        if (done) {
            return;
        }
    }
    ai_move_toward(npc, mode, dist, wp_flag);
}

s32 ai_step_back(Npc *npc, s32 dist) {
    AiPoint delta;
    s32 i;
    s32 back_dist;
    s16 angle;
    s16 moved;

    i = 0;
    back_dist = -dist;
    for (; i < 7; i++) {
        angle = (mail_wrap_angle(npc->target_yaw + ai_probe_angle[i] - 180) << 12) / 360;
        delta.x = back_dist * rsin(angle) >> 12;
        delta.y = 0;
        delta.z = back_dist * rcos(angle) >> 12;
        if (ai_check_line(npc, &delta, 0)) {
            moved = ai_try_move(npc, &delta, angle);
        } else {
            moved = 0;
        }
        if (moved) {
            return 1;
        }
    }
    return 0;
}

s32 ai_sidestep(Npc *npc, s32 dist) {
    AiPoint delta;
    s32 i;
    s16 angle;
    s16 moved;

    for (i = 4; i > 0; i--) {
        angle = (mail_wrap_angle(npc->target_yaw + ai_probe_angle[i] - 180) << 12) / 360;
        delta.x = dist * rsin(angle) >> 12;
        delta.y = 0;
        delta.z = dist * rcos(angle) >> 12;
        if (ai_check_line(npc, &delta, 0)) {
            moved = ai_try_move(npc, &delta, angle);
        } else {
            moved = 0;
        }
        if (moved) {
            return 1;
        }
    }
    return 0;
}

s16 ai_decide_fire(Npc *npc) {
    Player *player = player_status_player[0];
    s32 chance;
    s32 *chance_p;
    s32 range;
    s32 range_min;
    s32 range_mid;
    s32 range_max;
    s32 scale;
    s16 scaled;

    npc->fire_decision = 0;
    if (npc->target != -1) {
        return 0;
    }
    if (*(s32 *)&player->climbing & 0xC9000000) { /* one word over 0x40 and 0x42 */
        return 0;
    }
    if (!ai_in_aim_cone(npc, 1, 0)) {
        return 0;
    }
    if (npc->flags & 4) {
        npc->fire_decision = 2;
        return 0;
    }
    if (npc->flags & 0x10) {
        if (npc->fire_decision != 3) {
            npc->fire_decision = 3;
        }
    }
    chance_p = &chance;
    range = -(ai_cur_body->radius + 600) + (u16)npc->target_dist;
    chance = ai_cur_stats->fire_chance;
    if (range < 0) {
        range = 0;
    }
    range_min = ai_cur_stats->range_min * 10;
    range_mid = ai_cur_stats->range_mid * 10;
    range_max = ai_cur_stats->range_max * 10;
    if (range < range_min) {
        chance = 10;
        scaled = 0;
    } else {
        if (range < range_mid) {
            scale = ((range_mid - range) << 12) / (range_mid - range_min);
        } else if (range < range_max) {
            scale = ((range_max - range) << 12) / (range_max - range_min);
        } else {
            scale = rand() % 411;
        }
        *chance_p = *chance_p * scale >> 12;
        scaled = 1;
    }
    if (!scaled) {
        if (npc->fire_decision != 3) {
            npc->fire_decision = 3;
        }
    }
    if (chance < rand() % 100) {
        return 0;
    }
    npc->fire_decision = 1;
    return 1;
}

void ai_face_player(Npc *npc) {
    Player *player = player_status_player[0];
    SVector rot;

    if (ai_cur_model != 0 && ai_cur_model->ready != 0) {
        npc->yaw = mail_wrap_angle((ratan2(player->pos_x + player->cell_x * 12500 - npc->pos_x, player->pos_z + player->cell_z * 12500 - npc->pos_z) * 360 >> 12) - 180);
        rot.vx = (npc->pitch << 12) / 360;
        rot.vy = (npc->yaw << 12) / 360;
        rot.vz = (npc->roll << 12) / 360;
        RotMatrix(&rot, ai_cur_model->coord_m);
        ai_cur_model->coord_flg = 0;
    }
}

void ai_update_stand(Npc *npc) {
    s16 has_grid;

    ai_cur_grid = 0;
    ai_cur_stats = 0;
    ai_cur_body = 0;
    ai_cur_block = (Block *)npc->block;
    ai_cur_model = mod_find(npc->model_id);
    ai_cur_stats = npc_find_stats(npc->stats_id);
    if (ai_cur_stats == 0) {
        ai_cur_stats = &ai_default_stats;
    }
    ai_cur_body = npc_find_body(npc->body_id);
    if (ai_cur_body == 0) {
        ai_cur_body = &ai_default_body;
    }
    has_grid = 0;
    if (ai_cur_block != 0) {
        has_grid = 1;
        if (ai_cur_block->arena == 0) {
            has_grid = 0;
        } else {
            ai_cur_grid = (s32)ai_cur_block->arena;
        }
    }
    if (npc->flags & 1) {
        npc->flags &= ~1;
        ai_face_player(npc);
    } else if (has_grid != 0) {
        if (ai_find_target(npc, 1) && npc->mode == 1 && ai_decide_fire(npc)) {
            if (!(npc->flags & 0x400)) {
                npc->flags |= 0x400;
            }
        }
    } else {
        ai_face_player(npc);
    }
}

void ai_update_move(Npc *npc, s16 mode) {
    s32 has_grid;
    s32 mult;
    s32 dist;
    s32 frame_time;
    s32 speed;

    ai_cur_grid = 0;
    ai_cur_stats = 0;
    ai_cur_body = 0;
    ai_cur_block = (Block *)npc->block;
    ai_cur_model = mod_find(npc->model_id);
    ai_cur_stats = npc_find_stats(npc->stats_id);
    if (ai_cur_stats == 0) {
        ai_cur_stats = &ai_default_stats;
    }
    ai_cur_body = npc_find_body(npc->body_id);
    if (ai_cur_body == 0) {
        ai_cur_body = &ai_default_body;
    }
    if (ai_cur_block == 0 || ai_cur_block->arena == 0) {
        has_grid = 0;
    } else {
        ai_cur_grid = (s32)ai_cur_block->arena;
        has_grid = 1;
    }
    if (has_grid == 0 || (npc->flags & 0x20)) {
        return;
    }
    if (npc->flags & 1) {
        npc->flags &= ~1;
        if (mode != 0) {
            ai_find_target(npc, mode);
            return;
        }
    }
    if (npc->flags & 8) {
        npc->flags &= ~8;
        if (mode == 1) {
            mode = 0;
        }
    }
    switch (mode) {
    case 0:
        mult = 4;
        break;
    case 1:
        mult = 10;
        break;
    default:
        mult = 6;
        break;
    }
    frame_time = kaj_system_vsync_delta[0];
    if ((u16)ai_cur_stats->speed != 0) {
        speed = frame_time * (u16)ai_cur_stats->speed;
    } else {
        speed = frame_time * 3;
    }
    dist = speed * mult;
    if (npc->mode == 1 && npc->fire_decision == 2) {
        if (!(s16)ai_sidestep(npc, dist)) {
            ai_step_back(npc, dist);
        }
    } else if (npc->mode == 1 && npc->fire_decision == 3) {
        if (!(s16)ai_step_back(npc, dist)) {
            ai_sidestep(npc, dist);
        }
    } else {
        ai_walk(npc, mode, dist);
    }
    ai_cur_grid = 0;
    ai_cur_stats = 0;
    ai_cur_body = 0;
    ai_cur_block = (Block *)npc->block;
    ai_cur_model = mod_find(npc->model_id);
    ai_cur_stats = npc_find_stats(npc->stats_id);
    if (ai_cur_stats == 0) {
        ai_cur_stats = &ai_default_stats;
    }
    ai_cur_body = npc_find_body(npc->body_id);
    if (ai_cur_body == 0) {
        ai_cur_body = &ai_default_body;
    }
    if (ai_cur_block == 0 || ai_cur_block->arena == 0) {
        has_grid = 0;
    } else {
        ai_cur_grid = (s32)ai_cur_block->arena;
        has_grid = 1;
    }
    if (has_grid != 0) {
        if (ai_find_target(npc, mode)) {
            if (npc->mode == 1 && ai_decide_fire(npc)) {
                if (!(npc->flags & 0x400)) {
                    npc->flags |= 0x400;
                }
            }
        } else if (npc->mode == 1) {
            if (!(npc->flags & 8)) {
                npc->flags |= 8;
            }
        }
    }
}

void ai_fire(Npc *npc) {
    Player *player;
    s32 has_grid;
    s32 range;
    s32 range_min;
    s32 range_mid;
    s32 range_max;
    s32 accuracy;
    s32 scale;
    s32 chance;
    s32 dy;

    ai_cur_grid = 0;
    ai_cur_stats = 0;
    ai_cur_body = 0;
    ai_cur_block = (Block *)npc->block;
    player = player_status_player[0];
    ai_cur_model = mod_find(npc->model_id);
    ai_cur_stats = npc_find_stats(npc->stats_id);
    if (ai_cur_stats == 0) {
        ai_cur_stats = &ai_default_stats;
    }
    ai_cur_body = npc_find_body(npc->body_id);
    if (ai_cur_body == 0) {
        ai_cur_body = &ai_default_body;
    }
    if (ai_cur_block == 0 || ai_cur_block->arena == 0) {
        has_grid = 0;
    } else {
        ai_cur_grid = (s32)ai_cur_block->arena;
        has_grid = 1;
    }
    if (has_grid == 0) {
        if ((npc->kind & 0xFF) == 2 || (npc->kind & 0xFF) == 3) {
            sound_se_play(0x28);
        } else {
            switch ((u16)ai_cur_stats->weapon_kind) {
            case 0:
                sound_se_play(0x23);
                break;
            case 1:
                sound_se_play(0x24);
                break;
            case 2:
                sound_se_play(0x25);
                break;
            case 3:
                sound_se_play(0x26);
                break;
            case 4:
                sound_se_play(0x27);
                break;
            }
        }
        return;
    }
    if (!ai_find_target(npc, 1) || npc->target != -1 || (npc->flags & 4) || !ai_in_aim_cone(npc, 1, 0)) {
        if ((npc->kind & 0xFF) == 2 || (npc->kind & 0xFF) == 3) {
            sound_se_play(0x28);
        } else {
            switch ((u16)ai_cur_stats->weapon_kind) {
            case 0:
                sound_se_play(0x23);
                break;
            case 1:
                sound_se_play(0x24);
                break;
            case 2:
                sound_se_play(0x25);
                break;
            case 3:
                sound_se_play(0x26);
                break;
            case 4:
                sound_se_play(0x27);
                break;
            }
        }
        return;
    }
    range = -(ai_cur_body->radius + 600) + (u16)npc->target_dist;
    if (range < 0) {
        range = 0;
    }
    scale = 0;
    range_min = ai_cur_stats->range_min * 10;
    range_mid = ai_cur_stats->range_mid * 10;
    accuracy = (u16)ai_cur_stats->accuracy;
    range_max = ai_cur_stats->range_max * 10;
    chance = 0;
    if (range < range_min) {
        chance = -1;
    } else if (range < range_mid) {
        scale = 0x1000;
    } else if (range < range_max) {
        scale = ((range_max - range) << 12) / (range_max - range_mid);
    }
    if (!(range < range_min)) {
        chance = accuracy * scale >> 12;
    }
    if ((u16)ai_cur_stats->weapon_kind == 0) {
        dy = player->pos_y - player->cell_y * 32000 - npc->pos_y + 1600;
        if (dy > 0) {
            dy = -dy;
        }
        if (dy < -1600 || scale == 0) {
            if ((npc->kind & 0xFF) == 2 || (npc->kind & 0xFF) == 3) {
                sound_se_play(0x28);
            } else {
                switch ((u16)ai_cur_stats->weapon_kind) {
                case 0:
                    sound_se_play(0x23);
                    break;
                case 1:
                    sound_se_play(0x24);
                    break;
                case 2:
                    sound_se_play(0x25);
                    break;
                case 3:
                    sound_se_play(0x26);
                    break;
                case 4:
                    sound_se_play(0x27);
                    break;
                }
            }
            return;
        }
    }
    if (chance < 20) {
        if (chance < 0) {
            scale = 0x1000;
        }
        chance = 20;
    }
    if (rand() % 100 < chance) {
        if (scale < 410) {
            scale = 410;
        }
        player_take_hit(npc, ai_cur_stats->weapon_kind, (u16)ai_cur_stats->damage * scale >> 12);
    }
    if ((npc->kind & 0xFF) == 2 || (npc->kind & 0xFF) == 3) {
        sound_se_play(0x28);
    } else {
        switch ((u16)ai_cur_stats->weapon_kind) {
        case 0:
            sound_se_play(0x23);
            break;
        case 1:
            sound_se_play(0x24);
            break;
        case 2:
            sound_se_play(0x25);
            break;
        case 3:
            sound_se_play(0x26);
            break;
        case 4:
            sound_se_play(0x27);
            break;
        }
    }
}

s16 ai_in_aim_cone(Npc *npc, s16 npc_aims, s16 weapon_id) {
    Player *player = player_status_player[0];
    s32 dx;
    s32 dz;
    s16 lim;
    s32 heading;
    s32 diff;

    if (npc_aims != 0) {
        lim = 10;
        dx = player->pos_x + player->cell_x * 12500 - npc->pos_x;
        dz = player->pos_z + player->cell_z * 12500 - npc->pos_z;
    } else {
        dx = npc->pos_x - player->pos_x - player->cell_x * 12500;
        dz = npc->pos_z - player->pos_z - player->cell_z * 12500;
        lim = 15;
        if (weapon_id == 10 || weapon_id >= 14) {
            lim = 25;
        }
    }
    heading = ratan2(dx, dz) * 360 >> 12;
    if (npc_aims != 0) {
        diff = mail_wrap_angle(heading - npc->yaw + 180);
    } else {
        diff = mail_wrap_angle(heading - player->yaw);
    }
    if (diff <= lim || diff >= 360 - lim) {
        if (npc_aims != 0) {
            if (npc->aim_elevation > 50) {
                return 0;
            }
        } else if (npc->aim_pitch_diff > lim) {
            return 0;
        }
        return 1;
    }
    return 0;
}
