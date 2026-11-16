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
extern s32 D_801E6DB4[];
Model *ai_cur_model;
NpcStats *npc_find_stats(s16 arg0);
s16 ai_find_target(Npc *arg0, s32 arg1);
s16 ai_decide_fire(Npc *arg0);
void ai_face_player(Npc *arg0);
extern NpcStats ai_default_stats;
extern NpcBody ai_default_body;
Block *ai_cur_block;
s32 ai_cur_grid;
NpcStats *ai_cur_stats;
NpcBody *ai_cur_body;
typedef struct {
    ActionCmd *unk0;
    s32 unk4;
    char **unk8;
} Unk_80173054;
s32 atoi(char *s);
void mail_goto_ofc(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void mail_goto_twn(s32 a, s32 b, s32 c, s16 d, s16 e);
void mail_goto_building(s32 arg0, char *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
extern u16 action_vars[];
typedef struct {
    s16 unk0;
    s16 unk2;
} Unk_8017345C;
void action_cmd_change_scene(Unk_80173054 *arg0, s32 *arg1);
void action_cmd_var(Unk_80173054 *arg0);
void action_reset(s16 arg0);
SceneTrigger *action_find_trigger(s32 arg0);
s16 action_queue_front_flag;
s16 action_blink_count;
void sprite_set_clut_entry(s32 arg0, s32 arg1, s32 arg2);
void npc_exec_command(Unk_80173054 *arg0);
void thing_cmd_set_active(Unk_80173054 *arg0);
void sound_bgm_fade_out(s32 arg0);
void sound_bgm_play(s16 arg0);
void door_exec_command(Unk_80173054 *arg0, EventState *arg1);
void text_exec_command(Unk_80173054 *arg0);
void mod_cmd_npcrec(Unk_80173054 *arg0, EventState *arg1);
void player_exec_command(Unk_80173054 *arg0, EventState *arg1);
void sound_exec_command(Unk_80173054 *arg0);
void kaj_event_push(s32 arg0);
void sprite_exec_command(Unk_80173054 *arg0);
void mail_cmd_receive(Unk_80173054 *arg0);
void roadmap_start_flash(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void kaj_ll_insert_after(LlList *a0, s32 a1);
extern PlayerStatus player_status;
s16 action_test_inventory(ActionCond *arg0);
extern char D_80170000[];
extern char D_8017001C[];
extern char D_80170028[];
extern char D_80170050[];
extern char D_80170068[];
extern char D_8017008C[];
extern char D_801700B0[];
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
} Unk_80173A44;
void *kaj_malloc(s32 size);
void kaj_abend(s32 a, char *b, char *c, s32 d);
void *memcpy(void *dst, void *src, s32 n);
s32 strlen(char *s);

void action_cmd_change_scene(Unk_80173054 *arg0, s32 *arg1) {
    ActionCmd *cmd = arg0->unk0;
    s32 a, b, c, d;
    s32 x, y, z;

    switch (cmd->sub) {
    case 0:
        if (atoi(arg0->unk8[0]) != 0) {
            mail_goto_ofc(1, 0, 1, 0);
        } else {
            mail_goto_ofc(1, 1, 1, 2);
        }
        break;
    case 1:
    case 3:
        a = (s16)atoi(arg0->unk8[4]);
        b = (s16)atoi(arg0->unk8[2]);
        c = (s16)atoi(arg0->unk8[3]);
        d = (s16)atoi(arg0->unk8[5]);
        mail_goto_building(cmd->sub, arg0->unk8[1], a, arg0->unk8[0][0], b, c, d, *arg1, 1);
        break;
    case 2:
        x = atoi(arg0->unk8[0]) * 10;
        y = atoi(arg0->unk8[1]) * 10;
        z = atoi(arg0->unk8[2]) * 10;
        mail_goto_twn(x, y, z, atoi(arg0->unk8[3]), 1);
        break;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_80170000);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_8017001C);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_80170028);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_80170050);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_80170068);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_8017008C);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", D_801700B0);

void action_cmd_var(Unk_80173054 *arg0) {
    u16 *vars = action_vars;
    ActionCmd *cmd = arg0->unk0;
    s32 v = atoi(arg0->unk8[0]);

    switch (cmd->sub) {
    case 0:
        vars[cmd->target] = v;
        break;
    case 1:
        vars[cmd->target] -= v;
        break;
    case 2:
        vars[cmd->target] += v;
        break;
    case 3:
        vars[cmd->target] *= v;
        break;
    case 4:
        vars[cmd->target] /= (s16)v;
        break;
    case 5:
        vars[cmd->target] = (s16)vars[cmd->target] % (s16)v;
        break;
    case 6:
        vars[cmd->target] = vars[(s16)v];
        break;
    case 7:
        vars[cmd->target] -= vars[(s16)v];
        break;
    case 8:
        vars[cmd->target] += vars[(s16)v];
        break;
    }
}

void action_update(void) {
    EventState *s = &event_state;
    LlList *list;
    Unk_80173054 *cmd;
    ActionCmd *c;
    SceneTrigger *e;
    ActionSet *item;
    Unk_8017345C op;
    s32 flag;
    s32 a, b, d;
    s32 n;

    switch (s->state) {
    case 0:
    case 2:
        return;
    case 3:
        action_blink_count = (action_blink_count + 1) % 16;
        if (action_blink_count == 0) {
            sprite_set_clut_entry(0x40A, 3, 0x14BF);
        } else if (action_blink_count == 8) {
            sprite_set_clut_entry(0x40A, 3, 0x8000);
        }
        return;
    case 4:
        if ((s16)s->wait_timer == 0) {
            return;
        }
        s->wait_timer -= D_801E6DB4[0];
        if ((s16)s->wait_timer > 0) {
            return;
        }
        s->wait_timer = 0;
        s->wait_flags &= ~1;
        if (s->wait_flags != 0) {
            return;
        }
        s->state = 1;
        break;
    }

    list = action_queue;
    n = list->count;
    op.unk0 = -2;
    if (n == 0) {
        cmd = NULL;
    } else {
        Unk_80173054 *t;
        list->cursor = list->head;
        t = (Unk_80173054 *)list->cursor->data;
        op.unk0 = t->unk0->unk0;
        cmd = t;
        kaj_ll_remove_to_prev(list);
    }
    if (op.unk0 < 0) {
        action_reset(1);
        return;
    }
    switch (op.unk0) {
    case 0:
        c = cmd->unk0;
        e = action_find_trigger(c->target);
        if (e == NULL) {
            return;
        }
        switch (c->sub) {
        case 0:
            if (atoi(cmd->unk8[0]) != 0) {
                e->leave_set = atoi(cmd->unk8[1]);
            } else {
                e->enter_set = atoi(cmd->unk8[1]);
            }
            break;
        case 1:
            e->enabled = atoi(cmd->unk8[0]);
            break;
        case 2:
            e->unk8 = atoi(cmd->unk8[0]);
            break;
        }
        break;
    case 1:
        npc_exec_command(cmd);
        break;
    case 2:
        thing_cmd_set_active(cmd);
        break;
    case 3:
        if (cmd->unk0->sub != 0) {
            sound_bgm_fade_out(3);
        } else {
            sound_bgm_play(atoi(cmd->unk8[0]));
        }
        break;
    case 4:
        door_exec_command(cmd, s);
        break;
    case 5:
        text_exec_command(cmd);
        break;
    case 6:
        action_cmd_change_scene(cmd, (s32 *)s);
        break;
    case 7:
        mod_cmd_npcrec(cmd, s);
        break;
    case 8:
        player_exec_command(cmd, s);
        break;
    case 9:
        sound_exec_command(cmd);
        break;
    case 10:
        action_cmd_var(cmd);
        break;
    case 11:
        action_queue_front_flag = 1;
        flag = 0;
        switch (cmd->unk0->sub) {
        case 0:
            s->state = 4;
            s->wait_flags |= 1;
            s->wait_timer = atoi(cmd->unk8[0]) * 2;
            break;
        case 10:
            cmd->unk0->sub = 1;
            flag = 1;
        case 1:
            item = action_find_set(atoi(cmd->unk8[0]));
            while (item != NULL) {
                item = action_run_set(item, 1, (s16)flag);
            }
            break;
        case 2:
            kaj_event_push(0x400);
            break;
        }
        break;
    case 12:
        sprite_exec_command(cmd);
        break;
    case 13:
        mail_cmd_receive(cmd);
        break;
    case 14:
        a = atoi(cmd->unk8[0]) & 0xFF;
        b = atoi(cmd->unk8[1]) & 0xFF;
        d = atoi(cmd->unk8[2]) & 0xFF;
        roadmap_start_flash(a, b, d, (s16)atoi(cmd->unk8[3]));
        break;
    }
}

s16 action_test_inventory(ActionCond *arg0) {
    Inventory *p = player_status_inventory[0];
    s16 ret;
    s32 n;
    s32 i;

    if (arg0->used == 0) {
        return 2;
    }
    if (arg0->unk6 == 0) {
        if (arg0->index != 0) {
            ret = 1;
            for (i = 1, n = 0; i < 2; i++) {
                if (p->weapon_ids[i] < arg0->low || arg0->high < p->weapon_ids[i]) {
                    n++;
                }
            }
            if (n != 0) {
                ret = 0;
            }
        } else {
            ret = 0;
            for (i = 0; i < 8; i++) {
                if (p->item_ids[i] == arg0->low) {
                    ret = 1;
                    break;
                }
            }
        }
    }
    if (arg0->invert != 0) {
        ret = 1 - ret;
    }
    return ret;
}

u8 *action_load_set(u8 *arg0) {
    ActionSet *set;
    Action *act;
    ActionArgs *args;
    char *buf;
    s32 size;
    s32 len;
    s32 off;
    s32 i;
    s32 j;

    set = kaj_malloc(0xC);
    if (set == NULL) {
        kaj_abend(3, D_80170000, D_8017001C, 0x1F1);
    }
    arg0 += 4;
    set->header = kaj_malloc(0x38);
    if (set->header == NULL) {
        kaj_abend(3, D_80170028, D_8017001C, 0x1F9);
    }
    *set->header = *(ActionSetHeader *)arg0;
    arg0 += 0x38;
    set->count = *(s32 *)arg0;
    arg0 += 4;
    act = kaj_malloc(set->count * 0xC);
    if (act == NULL) {
        kaj_abend(3, D_80170050, D_8017001C, 0x204);
    }
    set->actions = act;
    for (i = 0; i < set->count; i++, act++) {
        size = *(s32 *)arg0;
        arg0 += 4;
        act->cmd = kaj_malloc(8);
        len = size - 0xC;
        if (act->cmd == NULL) {
            kaj_abend(3, D_80170068, D_8017001C, 0x210);
        }
        *(Unk_80173A44 *)act->cmd = *(Unk_80173A44 *)arg0;
        act->argc = *(s32 *)(arg0 + 8);
        if (act->argc == 0) {
            len = 0;
        }
        if (len == 0) {
            act->args = NULL;
            arg0 += size;
        } else {
            args = kaj_malloc(act->argc * 4);
            if (args == NULL) {
                kaj_abend(3, D_8017008C, D_8017001C, 0x220);
            }
            buf = kaj_malloc(len);
            if (buf == NULL) {
                kaj_abend(3, D_801700B0, D_8017001C, 0x225);
            }
            act->args = args;
            memcpy(buf, arg0 + 0xC, len);
            do {
                off = 0;
            } while (0);
            for (j = 0; j < act->argc; j++) {
                if (j == 0) {
                    args[0].unk0 = buf;
                } else {
                    off++;
                    off += strlen(args[j - 1].unk0);
                    args[j].unk0 = buf + off;
                }
            }
            arg0 += size;
        }
    }
    if (action_set_list->count == 0) {
        kaj_ll_insert_before(action_set_list, (s32)set);
    } else {
        action_set_list->cursor = action_set_list->tail;
        kaj_ll_insert_after(action_set_list, (s32)set);
    }
    return arg0;
}

static inline s16 func_80173DE0_var(ActionCond *arg0) {
    u16 *vars = action_vars;
    s16 v;
    s16 ret;
    if (arg0->used == 0) {
        return 2;
    }
    v = vars[arg0->index];
    ret = 1;
    if (v >= arg0->low && arg0->high >= v) {
        ret = arg0->invert == 0;
    } else if (arg0->invert == 0) {
        ret = 0;
    }
    return ret;
}

static inline s16 func_80173DE0_glob(ActionCond *arg0) {
    PlayerStatus *g = &player_status;
    s16 v;
    s16 ret;
    if (arg0->used == 0) {
        return 2;
    }
    ret = 1;
    switch (arg0->index) {
    case 0:
        v = g->stat0;
        break;
    case 1:
        v = g->stat1;
        break;
    case 2:
        v = g->stat2;
        break;
    case 3:
        v = g->stat3;
        break;
    }
    if (v >= arg0->low && arg0->high >= v) {
        if (arg0->invert != 0) {
            ret = 0;
        }
    } else if (arg0->invert == 0) {
        ret = 0;
    }
    return ret;
}

static inline void func_80173DE0_run(ActionSet *arg0, s16 arg1, s16 arg2) {
    LlList *list;
    Action *e;
    ActionSetHeader *item;
    s16 first = 1;
    s32 i;
    if (arg1 != 0) {
        e = arg0->actions;
        list = action_queue;
        for (i = 0; i < arg0->count; i++, e++) {
            item = e->cmd;
            if (arg2 != 0) {
                if (item->unk0 == 5 || *(s32 *)item == 0xB) {
                    continue;
                }
                if (*(s32 *)item == 0x1000B) {
                    item->unk2 = 10;
                }
            }
            if (action_queue_front_flag != 0 && first != 0) {
                first = 0;
                action_queue_front_flag = 0;
                list->cursor = list->head;
                kaj_ll_insert_before(list, (s32)e);
            } else {
                kaj_ll_insert_after(list, (s32)e);
            }
        }
    } else {
        LlList *l2;
        Action *e2;
        e2 = arg0->actions;
        l2 = action_queue;
        for (i = 0; i < arg0->count; i++, e2++) {
            item = e2->cmd;
            if (arg2 != 0) {
                if (item->unk0 == 5 || *(s32 *)item == 0xB) {
                    continue;
                }
                if (*(s32 *)item == 0x1000B) {
                    item->unk2 = 10;
                }
            }
            if (l2->count == 0) {
                kaj_ll_insert_before(l2, (s32)e2);
            } else {
                l2->cursor = l2->tail;
                kaj_ll_insert_after(l2, (s32)e2);
            }
        }
    }
}

static inline ActionSet *func_80173DE0_find(s16 arg0) {
    LlList *list = action_set_list;
    ActionSet *item;
    if (list->count == 0) {
        return NULL;
    }
    if (arg0 < 0) {
        return NULL;
    }
    list->cursor = list->head;
    while (1) {
        item = list->cursor->data;
        if (item != NULL && item->header->unk0 == arg0) {
            return item;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
    return NULL;
}

ActionSet *action_run_set(ActionSet *arg0, s32 arg1, s32 arg2) {
    ActionSetHeader *h = arg0->header;
    s16 st[4];
    s32 n2;
    s32 n1;
    s32 i;

    st[0] = func_80173DE0_var(&h->cond_var_a);
    st[1] = func_80173DE0_var(&h->cond_var_b);
    st[2] = func_80173DE0_glob(&h->cond_status);
    st[3] = action_test_inventory(&h->cond_inventory);
    for (i = 0, n2 = 0; i < 4; i++) {
        if (st[i] == 2) {
            n2++;
        }
    }
    if (n2 == 4) {
        func_80173DE0_run(arg0, arg1, arg2);
        if (h->next_mode == 1 || h->next_mode == 2) {
            return func_80173DE0_find(h->next_set);
        }
        return NULL;
    }
    for (i = 0, n1 = 0; i < 4; i++) {
        if (st[i] == 1) {
            n1++;
        }
    }
    if (h->unk2 == 0) {
        if (n1 > 0) {
            func_80173DE0_run(arg0, arg1, arg2);
            if (h->next_mode == 1 || h->next_mode == 2) {
                return func_80173DE0_find(h->next_set);
            }
        } else {
            if (h->next_mode == 0 || h->next_mode == 2) {
                return func_80173DE0_find(h->next_set);
            }
        }
    } else if (n1 == 4 - n2) {
        func_80173DE0_run(arg0, arg1, arg2);
        if (h->next_mode == 1 || h->next_mode == 2) {
            return func_80173DE0_find(h->next_set);
        }
    } else {
        if (h->next_mode == 0 || h->next_mode == 2) {
            return func_80173DE0_find(h->next_set);
        }
    }
    return NULL;
}

void action_reset(s16 arg0) {
    EventState *s = &event_state;
    u16 a = s->state;
    u16 b = s->wait_flags;
    u16 c = s->wait_timer;
    LlList *list;
    ActionSetHeader *item;

    text_release_cmd();
    memset(s, 0, 0x14);
    s->circle_set = -1;
    s->cross_set = -1;
    s->state = 0;
    if (arg0 == 0) {
        if (a == 1 || a == 4) {
            s->state = a;
        }
        if (b & 1) {
            s->wait_flags = b & ~1;
            if (s->wait_flags == 0) {
                s->state = 1;
            }
            s->wait_timer = 0;
        } else {
            s->wait_flags = b;
            s->wait_timer = c;
        }
    }
    list = action_queue;
    if (list->count == 0) {
        return;
    }
    if (arg0 != 0) {
        while (1) {
            if (list->count == 0) {
                break;
            }
            kaj_ll_remove_to_prev(list);
        }
        return;
    }
    list->cursor = list->head;
    while (1) {
        if (list->cursor->data != NULL) {
            item = list->cursor->data->header;
            if (item->unk0 == 5 || *(s32 *)item == 0xB) {
                kaj_ll_remove_to_prev(list);
            }
            if (*(s32 *)item == 0x1000B) {
                item->unk2 = 10;
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void action_push_front(s32 arg0) {
    action_queue->cursor = action_queue->head;
    kaj_ll_insert_before(action_queue, arg0);
}

void action_flush_queue(s16 arg0) {
    LlList *list = action_queue;
    ActionSetHeader *item;

    if (list->count == 0) {
        return;
    }
    if (arg0 != 0) {
        while (1) {
            if (list->count == 0) {
                break;
            }
            kaj_ll_remove_to_prev(list);
        }
        return;
    }
    list->cursor = list->head;
    while (1) {
        if (list->cursor->data != NULL) {
            item = list->cursor->data->header;
            if (item->unk0 == 5 || *(s32 *)item == 0xB) {
                kaj_ll_remove_to_prev(list);
            }
            if (*(s32 *)item == 0x1000B) {
                item->unk2 = 10;
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void action_free_set(ActionSet *arg0) {
    Action *e = arg0->actions;
    s32 i;

    for (i = 0; i < arg0->count; i++, e++) {
        if (e->args != NULL) {
            free3(e->args->unk0);
            free3(e->args);
        }
        free3(e->cmd);
    }
    free3(arg0->actions);
    free3(arg0->header);
    free3(arg0);
}

void action_free_all_sets(void) {
    LlList *list = action_set_list;
    ActionSet *item;
    Action *e;
    s32 i;

    while (1) {
        if (list->count == 0) {
            break;
        }
        item = list->cursor->data;
        e = item->actions;
        for (i = 0; i < item->count; i++, e++) {
            if (e->args != NULL) {
                free3(e->args->unk0);
                free3(e->args);
            }
            free3(e->cmd);
        }
        free3(item->actions);
        free3(item->header);
        free3(item);
        kaj_ll_remove_to_prev(list);
    }
}

ActionSet *action_find_set(s16 arg0) {
    LlList *list = action_set_list;
    ActionSet *item;

    if (list->count == 0) {
        return NULL;
    }
    if (arg0 < 0) {
        return NULL;
    }
    list->cursor = list->head;
    while (1) {
        item = list->cursor->data;
        if (item != NULL && item->header->unk0 == arg0) {
            return item;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
    return NULL;
}

s32 action_run_trigger_enter(SceneTrigger *arg0) {
    LlList *list;
    ActionSet *item;
    ActionSet *p;
    s16 id;

    if (arg0 == NULL || arg0->enabled == 0) {
        return 0;
    }
    list = action_set_list;
    id = arg0->enter_set;
    if (list->count == 0) {
        item = NULL;
    } else if (id < 0) {
        item = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            p = list->cursor->data;
            if (p != NULL && p->header->unk0 == id) {
                item = p;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                item = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (item == NULL) {
        return 0;
    }
    while ((item = action_run_set(item, 0, 0)) != NULL) {
    }
    return 1;
}

s32 action_run_trigger_leave(SceneTrigger *arg0) {
    LlList *list;
    ActionSet *item;
    ActionSet *p;
    s16 id;

    if (arg0 == NULL || arg0->enabled == 0) {
        return 0;
    }
    list = action_set_list;
    id = arg0->leave_set;
    if (list->count == 0) {
        item = NULL;
    } else if (id < 0) {
        item = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            p = list->cursor->data;
            if (p != NULL && p->header->unk0 == id) {
                item = p;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                item = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (item == NULL) {
        return 0;
    }
    while ((item = action_run_set(item, 0, 0)) != NULL) {
    }
    return 1;
}

SceneTrigger *action_find_trigger(s32 arg0) {
    SceneTables *p = &object_scene_tables;
    s32 n = p->trigger_count;
    SceneTrigger *e = p->triggers;
    s32 i;
    if (n == 0) {
        return NULL;
    }
    for (i = 0; i < n; i++, e++) {
        if (e->id == arg0) {
            return e;
        }
    }
    return NULL;
}

void action_free_triggers(void) {
    SceneTables *p = &object_scene_tables;
    if (p->trigger_count != 0) {
        if (p->triggers != NULL) {
            free3(p->triggers);
        }
        p->trigger_count = 0;
        p->triggers = NULL;
    }
}

void action_place_npc(Npc *arg0, Model *arg1) {
    Player *p = player_status_player[0];
    SVector sv;

    if (arg1->ready == 0) {
        if (arg0->unkF == 6) {
            arg0->unkE = 2;
            mod_setup(arg1, 0, 0, 8);
        } else {
            mod_setup(arg1, 0, 0, 0);
        }
    }
    arg1->coord_tx = arg0->unk20 - p->cell_x * 12500;
    arg1->coord_ty = arg0->unk24 + p->cell_y * 32000;
    arg1->coord_tz = arg0->unk28 - p->cell_z * 12500;
    sv.vx = (arg0->unk38 << 12) / 360;
    sv.vy = (arg0->unk3A << 12) / 360;
    sv.vz = (arg0->unk3C << 12) / 360;
    RotMatrix(&sv, arg1->coord_m);
    arg1->coord_flg = 0;
}

void action_init_npcs(void) {
    SceneTables *p = &object_scene_tables;
    Npc *e = p->npcs;
    Model *o;
    s32 i;

    if (p->npc_count == 0) {
        return;
    }
    for (i = 0; i < p->npc_count; i++, e++) {
        e->unk4 = 0;
        e->unk20 *= 10;
        e->unk24 *= 10;
        e->unk28 *= 10;
        e->unk2C *= 10;
        e->unk30 *= 10;
        e->unk34 *= 10;
        o = mod_find(e->unk16);
        if (o != NULL) {
            action_place_npc(e, o);
        e->unk48 = block_find_at(e->unk20, e->unk24, e->unk28);
        e->unk10 = -2;
        e->unk40 = 0;
        e->unkB = 0;
        e->unk44 = 0;
        e->unk45 = 0;
        e->unk46 = 0;
        e->unk12 |= 1;
        e->unk3E = e->unk3A;
        e->unk4 = 1;
        }
    }
}

s32 action_run_npc_event(u16 arg0, s16 arg1) {
    SceneTables *p = &object_scene_tables;
    ActionSet *item = NULL;
    s32 n = p->npc_count;
    Npc *q = p->npcs;
    Npc *e;
    s32 i;

    if (n == 0) {
        e = NULL;
    } else {
        for (i = 0; i < n; i++, q++) {
            if (q->unk0 == arg0) {
                e = q;
                goto found;
            }
        }
        e = NULL;
    }
found:
    if (e == NULL || e->unk4 == 0) {
        return 0;
    }
    if (e->unk8 == 0) {
        return 0;
    }
    if (e->unkF == 6) {
        if (arg1 != 0) {
            item = action_find_set(0x400);
        } else {
            text_close();
        }
    } else if (e->unkE == 1) {
        if (e->unk12 & 0x20) {
            e->unk12 &= ~0x20;
        }
        return 0;
    } else {
        if (arg1 != 0) {
            item = action_find_set(e->unk1A);
            e->unk12 |= 0x20;
        } else {
            item = action_find_set(e->unk1C);
            e->unk12 &= ~0x20;
        }
    }
    if (item == NULL) {
        return 0;
    }
    while ((item = action_run_set(item, 0, 0)) != NULL) {
    }
    return 1;
}
