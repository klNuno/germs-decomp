#include "common.h"
#include "game/npc.h"
#include "game/action.h"
#include "game/block.h"
#include "game/main.h"
#include "game/mod.h"
#include "kaj/tss.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libgs.h"
#include "psyq/libgte.h"

/*
 * The NPC records that scripts place: placement, moves, drawing.
 *
 * File boundaries: likely (docs/layout.md): no assert: a normal function after mod.c's deferred inline tail.
 */

extern SceneTables object_scene_tables;
extern EventState event_state;
extern NpcRecord *npc_rec_table[];
extern s16 action_vars[];
static void npc_rec_place(NpcRecord *rec, Model *mod);
typedef struct {
    s32 from_x;
    s32 from_y;
    s32 from_z;
    u8 padC[0x4];
    s32 to_x;
    s32 to_y;
    s32 to_z;
    u8 pad1C[0x4];
    s32 delta_x;
    s32 delta_y;
    s32 delta_z;
    u8 pad2C[0x4];
    s16 from_rot_x;
    s16 from_rot_y;
    s16 from_rot_z;
    u8 pad36[0x2];
    s16 to_rot_x;
    s16 to_rot_y;
    s16 to_rot_z;
    u8 pad3E[0x2];
    s16 delta_rot_x;
    s16 delta_rot_y;
    s16 delta_rot_z;
    u8 pad46[0x2];
    NpcRecord *rec;
} NpcRecMove;
extern Player *player_status_player[];
static void npc_rec_move_step(TssSlot *task);
static void npc_rec_move_end(TssSlot *task);
void mod_set_anim_by_id(u16 id, s16 anim, s16 frames);
static void npc_rec_move_to(NpcRecord *rec, s32 x, s32 y, s32 z, s16 rot_x, s16 rot_y, s16 rot_z, s32 seconds);

static void npc_rec_place(NpcRecord *rec, Model *mod) {
    Player *player = player_status_player[0];
    SVector rot;

    mod->coord_tx = rec->pos_x - player->cell_x * 12500;
    mod->coord_ty = rec->pos_y + player->cell_y * 32000;
    mod->coord_tz = rec->pos_z - player->cell_z * 12500;
    rot.vx = (rec->rot_x << 12) / 360;
    rot.vy = (rec->rot_y << 12) / 360;
    rot.vz = (rec->rot_z << 12) / 360;
    RotMatrix(&rot, mod->coord_m);
    mod->coord_flg = 0;
}

static void npc_rec_move_step(TssSlot *task) {
    NpcRecMove *move = task->data;
    NpcRecord *rec = move->rec;
    Model *mod;

    rec->pos_x = move->from_x + move->delta_x * task->cur / task->target;
    rec->pos_y = move->from_y + move->delta_y * task->cur / task->target;
    rec->pos_z = move->from_z + move->delta_z * task->cur / task->target;
    rec->rot_x = move->from_rot_x + move->delta_rot_x * task->cur / task->target;
    rec->rot_y = move->from_rot_y + move->delta_rot_y * task->cur / task->target;
    rec->rot_z = move->from_rot_z + move->delta_rot_z * task->cur / task->target;
    mod = mod_find(rec->model);
    if (mod != NULL) {
        npc_rec_place(rec, mod);
    }
}

static void npc_rec_move_to(NpcRecord *rec, s32 x, s32 y, s32 z, s16 rot_x, s16 rot_y, s16 rot_z, s32 seconds) {
    TssSlot *task;
    NpcRecMove *move;

    task = kaj_tss_alloc(0x4C);
    task->type = 5;
    task->step = 1;
    task->delay = 2;
    task->on_step = npc_rec_move_step;
    task->cur = 0;
    task->on_end = npc_rec_move_end;
    task->on_kill = npc_rec_move_end;
    task->target = seconds * 30;
    if (rec->pos_x == x && rec->pos_y == y && rec->pos_z == z &&
        rec->rot_x == rot_x && rec->rot_y == rot_y && rec->rot_z == rot_z) {
        task->target = 0;
    }
    move = task->data;
    move->rec = rec;
    move->from_x = rec->pos_x;
    move->from_y = rec->pos_y;
    move->from_z = rec->pos_z;
    move->from_rot_x = rec->rot_x;
    move->from_rot_y = rec->rot_y;
    move->from_rot_z = rec->rot_z;
    move->to_x = x;
    move->to_y = y;
    move->to_z = z;
    move->to_rot_x = rot_x;
    move->to_rot_y = rot_y;
    move->to_rot_z = rot_z;
    move->delta_x = x - rec->pos_x;
    move->delta_y = y - rec->pos_y;
    move->delta_z = z - rec->pos_z;
loop:
    move->delta_rot_x = rot_x - rec->rot_x;
    move->delta_rot_y = rot_y - rec->rot_y;
    move->delta_rot_z = rot_z - rec->rot_z;
    if (move->delta_rot_x > 180) {
        rot_x -= 360;
        goto loop;
    }
    if (move->delta_rot_x < -180) {
        rot_x += 360;
        goto loop;
    }
    if (move->delta_rot_y > 180) {
        rot_y -= 360;
        goto loop;
    }
    if (move->delta_rot_y < -180) {
        rot_y += 360;
        goto loop;
    }
    if (move->delta_rot_z > 180) {
        rot_z -= 360;
        goto loop;
    }
    if (move->delta_rot_z < -180) {
        rot_z += 360;
        goto loop;
    }
    rec->move_task = kaj_tss_start(task);
    rec->moving = 1;
}

void npc_rec_cmd(Action *action, EventState *event) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->npc_records;
    ActionCmdShort *cmd = (ActionCmdShort *)action->cmd;
    u16 id = cmd->target;
    NpcRecord *found;
    NpcRecord *shown_rec;
    Model *mod;
    s32 i;
    NpcRecord *table;
    s16 *vars;
    s32 x, y, z;
    s32 rot_y, seconds;

    if (p->npc_record_count == 0) {
        found = NULL;
    } else {
        for (i = 0; i < p->npc_record_count; i++, rec++) {
            if (rec->id == id) {
                found = rec;
                goto done;
            }
        }
        found = NULL;
    }
done:
    if (found == NULL) {
        return;
    }
    switch (cmd->sub) {
    case 0:
        found->enabled = atoi(action->args[0]);
        break;
    case 1:
        found->model = atoi(action->args[0]);
        table = npc_rec_table[0];
        vars = action_vars;
        shown_rec = table + cmd->target;
        if (vars[cmd->target] == 0) {
            break;
        }
        if (shown_rec->scaled == 0) {
            shown_rec->scaled = 1;
            shown_rec->pos_x *= 10;
            shown_rec->pos_y *= 10;
            shown_rec->pos_z *= 10;
        }
        shown_rec->shown = 1;
        shown_rec->move_task = -1;
        shown_rec->moving = 0;
        mod = mod_find(shown_rec->model);
        if (mod == NULL) {
            break;
        }
        if (mod->ready == 0) {
            mod_setup(mod, 0, 2, 0);
        }
        npc_rec_place(shown_rec, mod);
        shown_rec->shown = 2;
        break;
    case 3:
        x = atoi(action->args[0]) * 10;
        y = atoi(action->args[1]) * 10;
        z = atoi(action->args[2]) * 10;
        rot_y = atoi(action->args[3]);
        seconds = atoi(action->args[4]);
        if (atoi(action->args[5]) == 1) {
            event->state = 4;
            event->wait_flags |= 0x10;
        }
        npc_rec_move_to(found, x, y, z, 0, rot_y, 0, seconds);
        break;
    case 4:
        if (atoi(action->args[1]) == 1) {
            event->state = 4;
            event->wait_flags |= 8;
        }
        ((void (*)())mod_set_anim_by_id)((s16)found->model, (s16)atoi(action->args[0]), (s16)atoi(action->args[2]));
        break;
    }
}

void npc_rec_update_all(void) {
    NpcRecord *rec;
    Player *player;
    Model *mod;
    Model *mod2;
    SceneTables *tables;
    s32 i;

    tables = &object_scene_tables;
    rec = tables->npc_records;
    player = player_status_player[0];
    if (tables->npc_record_count != 0) {
        for (i = 0; i < tables->npc_record_count; i++, rec++) {
            if (rec->scaled != 0 && rec->shown != 0) {
                if (rec->shown == 1) {
                    mod = mod_find(rec->model);
                    if (mod != NULL) {
                        if (mod->ready == 0) {
                            mod_setup(mod, 0, 2, 0);
                        }
                        npc_rec_place(rec, mod);
                        rec->shown = 2;
                    }
                } else if (rec->enabled != 0 && rec->moving == 0 && rec->id != 0) {
                    rec->rot_y = main_wrap_angle((ratan2(player->pos_x + player->cell_x * 12500 - rec->pos_x,
                                                     player->pos_z + player->cell_z * 12500 - rec->pos_z) * 360 >> 12) - 180);
                    mod2 = mod_find(rec->model);
                    if (mod2 != NULL) {
                        npc_rec_place(rec, mod2);
                    }
                }
            }
        }
    }
}

void npc_rec_show(u16 id, s16 force) {
    NpcRecord *rec;
    s16 *vars;
    NpcRecord *table;
    Model *mod;

    table = npc_rec_table[0];
    vars = action_vars;
    rec = table + id;
    if (vars[id] != 0 || force != 0) {
        if (rec->scaled == 0) {
            rec->scaled = 1;
            rec->pos_x *= 10;
            rec->pos_y *= 10;
            rec->pos_z *= 10;
        }
        rec->shown = 1;
        rec->move_task = -1;
        rec->moving = 0;
        mod = mod_find(rec->model);
        if (mod != NULL) {
            if (mod->ready == 0) {
                mod_setup(mod, 0, 2, 0);
            }
            npc_rec_place(rec, mod);
            rec->shown = 2;
        }
    }
}

void npc_rec_free_table(void) {
    SceneTables *p = &object_scene_tables;
    if (p->npc_record_count != 0) {
        if (p->npc_records != NULL) {
            free3(p->npc_records);
        }
        p->npc_record_count = 0;
        p->npc_records = NULL;
    }
}

NpcRecord *npc_rec_find(u16 id) {
    SceneTables *p = &object_scene_tables;
    s32 n = p->npc_record_count;
    NpcRecord *rec = p->npc_records;
    s32 i;

    if (n == 0) {
        return NULL;
    }
    for (i = 0; i < n; i++, rec++) {
        if (rec->id == id) {
            return rec;
        }
    }
    return NULL;
}

void npc_rec_rebase_all(s32 origin_x, s32 origin_y, s32 origin_z) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->npc_records;
    Model *mod;
    s32 i;

    if (p->npc_record_count == 0) {
        return;
    }
    for (i = 0; i < p->npc_record_count; i++, rec++) {
        if (rec->scaled != 0 && rec->enabled != 0 && rec->shown == 2) {
            mod = mod_find(rec->model);
            if (mod != NULL) {
                mod->coord_tx = rec->pos_x - origin_x;
                mod->coord_ty = rec->pos_y - origin_y;
                mod->coord_tz = rec->pos_z - origin_z;
                mod->coord_flg = 0;
            }
        }
    }
}

void npc_rec_draw_all(s32 view) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->npc_records;
    Model *mod;
    s32 i;

    if (p->npc_record_count == 0) {
        return;
    }
    for (i = 0; i < p->npc_record_count; i++, rec++) {
        if (rec != NULL && rec->scaled != 0 && rec->enabled != 0 && rec->shown == 2) {
            mod = mod_find(rec->model);
            if (mod != NULL && mod->ready != 0) {
                mod_draw(view, mod, rec->ot_layer);
            }
        }
    }
}

s16 npc_rec_find_at_point(s32 x, s32 y, s32 z) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->npc_records;
    Model *mod;
    s32 i;

    if (p->npc_record_count == 0) {
        return -2;
    }
    for (i = 0; i < p->npc_record_count; i++, rec++) {
        if (rec->scaled != 0 && rec->enabled != 0 && rec->shown == 2) {
            mod = mod_find(rec->model);
            if (mod != NULL && mod->ready != 0 && mod->tmd_objects != NULL) {
                GsSetLsMatrix(mod->coord_m);
                if (block_point_on_model(mod->tmd_objects, x, y, z, 1) != 0) {
                    return rec->id;
                }
            }
        }
    }
    return -2;
}

void npc_rec_reset_all(void) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->npc_records;
    s32 i;

    for (i = 0; i < p->npc_record_count; i++, rec++) {
        rec->shown = 0;
    }
}

static void npc_rec_move_end(TssSlot *task) {
    EventState *s = &event_state;
    NpcRecMove *move = task->data;
    NpcRecord *rec = move->rec;
    Model *mod;

    rec->pos_x = move->to_x;
    rec->pos_y = move->to_y;
    rec->pos_z = move->to_z;
    rec->rot_x = move->to_rot_x;
    rec->rot_y = move->to_rot_y;
    rec->rot_z = move->to_rot_z;
    rec->moving = 0;
    mod = mod_find(rec->model);
    if (mod != NULL) {
        npc_rec_place(rec, mod);
    }
    if (s->wait_flags & 0x10) {
        s->wait_flags &= ~0x10;
        if (s->wait_flags == 0) {
            s->state = 1;
        }
    }
    rec->move_task = -1;
}
