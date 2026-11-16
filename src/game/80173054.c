#include "common.h"
#include "game/types.h"

LlList *action_queue;
void kaj_ll_insert_before(LlList *list, s32 data);
extern SceneTables object_scene_tables;
void free3(void *ptr);
s32 block_find_at(s32 x, s32 y, s32 z);
NpcBody *npc_find_body(s16 id);
extern Inventory *player_status_inventory[];
Model *mod_find(u16 id);
void mod_draw(s32 arg0, Model *arg1, u16 arg2);
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
s16 ai_check_line(Npc *npc, SceneTrigger *point, s32 flags);
s16 ai_try_move(Npc *npc, SceneTrigger *delta, s16 angle);
extern s32 kaj_system_vsync_delta[];
Model *ai_cur_model;
NpcStats *npc_find_stats(s16 id);
s16 ai_find_target(Npc *npc, s32 turn_mode);
s16 ai_decide_fire(Npc *npc);
void ai_face_player(Npc *npc);
extern NpcStats ai_default_stats;
extern NpcBody ai_default_body;
Block *ai_cur_block;
s32 ai_cur_grid;
NpcStats *ai_cur_stats;
NpcBody *ai_cur_body;
s32 atoi(char *s);
void mail_goto_ofc(s32 a, s32 yaw, s32 c, s32 d);
void mail_goto_twn(s32 x, s32 y, s32 z, s16 yaw, s16 e);
void mail_goto_building(s32 form, char *name, s32 var, s32 map_letter, s32 map_entry, s32 yaw, s32 scene_index, s32 trigger, s32 script_entry);
extern u16 action_vars[];
typedef struct {
    s16 opcode;
    s16 unk2;
} ActionQueueOp;
void action_cmd_change_scene(Action *action, s32 *event);
void action_cmd_var(Action *action);
void action_reset(s16 flush_all);
SceneTrigger *action_find_trigger(s32 id);
s16 action_queue_front_flag;
s16 action_blink_count;
void sprite_set_clut_entry(s32 id, s32 index, s32 color);
void npc_exec_command(Action *action);
void thing_cmd_set_active(Action *action);
void sound_bgm_fade_out(s32 seconds);
void sound_bgm_play(s16 seq);
void door_exec_command(Action *action, EventState *event);
void text_exec_command(Action *action);
void mod_cmd_npcrec(Action *action, EventState *event);
void player_exec_command(Action *action, EventState *event);
void sound_exec_command(Action *cmd);
void kaj_event_push(s32 type);
void sprite_exec_command(Action *cmd);
void mail_cmd_receive(Action *action);
void roadmap_start_flash(s32 red, s32 green, s32 blue, s32 duration);
void kaj_ll_insert_after(LlList *list, s32 data);
extern PlayerStatus player_status;
s16 action_test_inventory(ActionCond *cond);
extern char action_str_err_alloc_set[];
extern char action_str_file[];
extern char action_str_err_alloc_set_header[];
extern char action_str_err_alloc_actions[];
extern char action_str_err_alloc_cmd[];
extern char action_str_err_alloc_args[];
extern char action_str_err_alloc_arg_buf[];
typedef struct {
    u16 opcode;
    u16 sub;
    u16 target_lo;
    u16 target_hi;
} ActionCmdCopy;
void *kaj_malloc(s32 size);
void kaj_abend(s32 code, char *msg, char *file, s32 line);
void *memcpy(void *dst, void *src, s32 n);
s32 strlen(char *s);

void action_cmd_change_scene(Action *action, s32 *event) {
    ActionCmd *cmd = action->cmd;
    s32 a, b, c, d;
    s32 x, y, z;

    switch (cmd->sub) {
    case 0:
        if (atoi(action->args[0]) != 0) {
            mail_goto_ofc(1, 0, 1, 0);
        } else {
            mail_goto_ofc(1, 1, 1, 2);
        }
        break;
    case 1:
    case 3:
        a = (s16)atoi(action->args[4]);
        b = (s16)atoi(action->args[2]);
        c = (s16)atoi(action->args[3]);
        d = (s16)atoi(action->args[5]);
        mail_goto_building(cmd->sub, action->args[1], a, action->args[0][0], b, c, d, *event, 1);
        break;
    case 2:
        x = atoi(action->args[0]) * 10;
        y = atoi(action->args[1]) * 10;
        z = atoi(action->args[2]) * 10;
        mail_goto_twn(x, y, z, atoi(action->args[3]), 1);
        break;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80173054", action_str_err_alloc_set);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", action_str_file);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", action_str_err_alloc_set_header);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", action_str_err_alloc_actions);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", action_str_err_alloc_cmd);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", action_str_err_alloc_args);

INCLUDE_RODATA("asm/nonmatchings/game/80173054", action_str_err_alloc_arg_buf);

void action_cmd_var(Action *action) {
    u16 *vars = action_vars;
    ActionCmd *cmd = action->cmd;
    s32 value = atoi(action->args[0]);

    switch (cmd->sub) {
    case 0:
        vars[cmd->target] = value;
        break;
    case 1:
        vars[cmd->target] -= value;
        break;
    case 2:
        vars[cmd->target] += value;
        break;
    case 3:
        vars[cmd->target] *= value;
        break;
    case 4:
        vars[cmd->target] /= (s16)value;
        break;
    case 5:
        vars[cmd->target] = (s16)vars[cmd->target] % (s16)value;
        break;
    case 6:
        vars[cmd->target] = vars[(s16)value];
        break;
    case 7:
        vars[cmd->target] -= vars[(s16)value];
        break;
    case 8:
        vars[cmd->target] += vars[(s16)value];
        break;
    }
}

void action_update(void) {
    EventState *event = &event_state;
    LlList *list;
    Action *action;
    ActionCmd *cmd;
    SceneTrigger *trigger;
    ActionSet *set;
    ActionQueueOp op;
    s32 flag;
    s32 red, green, blue;
    s32 n;

    switch (event->state) {
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
        if ((s16)event->wait_timer == 0) {
            return;
        }
        event->wait_timer -= kaj_system_vsync_delta[0];
        if ((s16)event->wait_timer > 0) {
            return;
        }
        event->wait_timer = 0;
        event->wait_flags &= ~1;
        if (event->wait_flags != 0) {
            return;
        }
        event->state = 1;
        break;
    }

    list = action_queue;
    n = list->count;
    op.opcode = -2;
    if (n == 0) {
        action = NULL;
    } else {
        Action *first;
        list->cursor = list->head;
        first = (Action *)list->cursor->data;
        op.opcode = first->cmd->opcode;
        action = first;
        kaj_ll_remove_to_prev(list);
    }
    if (op.opcode < 0) {
        action_reset(1);
        return;
    }
    switch (op.opcode) {
    case 0:
        cmd = action->cmd;
        trigger = action_find_trigger(cmd->target);
        if (trigger == NULL) {
            return;
        }
        switch (cmd->sub) {
        case 0:
            if (atoi(action->args[0]) != 0) {
                trigger->leave_set = atoi(action->args[1]);
            } else {
                trigger->enter_set = atoi(action->args[1]);
            }
            break;
        case 1:
            trigger->enabled = atoi(action->args[0]);
            break;
        case 2:
            trigger->passable = atoi(action->args[0]);
            break;
        }
        break;
    case 1:
        npc_exec_command(action);
        break;
    case 2:
        thing_cmd_set_active(action);
        break;
    case 3:
        if (action->cmd->sub != 0) {
            sound_bgm_fade_out(3);
        } else {
            sound_bgm_play(atoi(action->args[0]));
        }
        break;
    case 4:
        door_exec_command(action, event);
        break;
    case 5:
        text_exec_command(action);
        break;
    case 6:
        action_cmd_change_scene(action, (s32 *)event);
        break;
    case 7:
        mod_cmd_npcrec(action, event);
        break;
    case 8:
        player_exec_command(action, event);
        break;
    case 9:
        sound_exec_command(action);
        break;
    case 10:
        action_cmd_var(action);
        break;
    case 11:
        action_queue_front_flag = 1;
        flag = 0;
        switch (action->cmd->sub) {
        case 0:
            event->state = 4;
            event->wait_flags |= 1;
            event->wait_timer = atoi(action->args[0]) * 2;
            break;
        case 10:
            action->cmd->sub = 1;
            flag = 1;
        case 1:
            set = action_find_set(atoi(action->args[0]));
            while (set != NULL) {
                set = action_run_set(set, 1, (s16)flag);
            }
            break;
        case 2:
            kaj_event_push(0x400);
            break;
        }
        break;
    case 12:
        sprite_exec_command(action);
        break;
    case 13:
        mail_cmd_receive(action);
        break;
    case 14:
        red = atoi(action->args[0]) & 0xFF;
        green = atoi(action->args[1]) & 0xFF;
        blue = atoi(action->args[2]) & 0xFF;
        roadmap_start_flash(red, green, blue, (s16)atoi(action->args[3]));
        break;
    }
}

s16 action_test_inventory(ActionCond *cond) {
    Inventory *inventory = player_status_inventory[0];
    s16 ret;
    s32 misses;
    s32 i;

    if (cond->used == 0) {
        return 2;
    }
    if (cond->skip_test == 0) {
        if (cond->index != 0) {
            ret = 1;
            for (i = 1, misses = 0; i < 2; i++) {
                if (inventory->weapon_ids[i] < cond->low || cond->high < inventory->weapon_ids[i]) {
                    misses++;
                }
            }
            if (misses != 0) {
                ret = 0;
            }
        } else {
            ret = 0;
            for (i = 0; i < 8; i++) {
                if (inventory->item_ids[i] == cond->low) {
                    ret = 1;
                    break;
                }
            }
        }
    }
    if (cond->invert != 0) {
        ret = 1 - ret;
    }
    return ret;
}

u8 *action_load_set(u8 *src) {
    ActionSet *set;
    Action *act;
    char **args;
    char *buf;
    s32 size;
    s32 len;
    s32 off;
    s32 i;
    s32 j;

    set = kaj_malloc(0xC);
    if (set == NULL) {
        kaj_abend(3, action_str_err_alloc_set, action_str_file, 0x1F1);
    }
    src += 4;
    set->header = kaj_malloc(0x38);
    if (set->header == NULL) {
        kaj_abend(3, action_str_err_alloc_set_header, action_str_file, 0x1F9);
    }
    *set->header = *(ActionSetHeader *)src;
    src += 0x38;
    set->count = *(s32 *)src;
    src += 4;
    act = kaj_malloc(set->count * 0xC);
    if (act == NULL) {
        kaj_abend(3, action_str_err_alloc_actions, action_str_file, 0x204);
    }
    set->actions = act;
    for (i = 0; i < set->count; i++, act++) {
        size = *(s32 *)src;
        src += 4;
        act->cmd = kaj_malloc(8);
        len = size - 0xC;
        if (act->cmd == NULL) {
            kaj_abend(3, action_str_err_alloc_cmd, action_str_file, 0x210);
        }
        *(ActionCmdCopy *)act->cmd = *(ActionCmdCopy *)src;
        act->argc = *(s32 *)(src + 8);
        if (act->argc == 0) {
            len = 0;
        }
        if (len == 0) {
            act->args = NULL;
            src += size;
        } else {
            args = kaj_malloc(act->argc * 4);
            if (args == NULL) {
                kaj_abend(3, action_str_err_alloc_args, action_str_file, 0x220);
            }
            buf = kaj_malloc(len);
            if (buf == NULL) {
                kaj_abend(3, action_str_err_alloc_arg_buf, action_str_file, 0x225);
            }
            act->args = args;
            memcpy(buf, src + 0xC, len);
            do {
                off = 0;
            } while (0);
            for (j = 0; j < act->argc; j++) {
                if (j == 0) {
                    args[0] = buf;
                } else {
                    off++;
                    off += strlen(args[j - 1]);
                    args[j] = buf + off;
                }
            }
            src += size;
        }
    }
    if (action_set_list->count == 0) {
        kaj_ll_insert_before(action_set_list, (s32)set);
    } else {
        action_set_list->cursor = action_set_list->tail;
        kaj_ll_insert_after(action_set_list, (s32)set);
    }
    return src;
}

static inline s16 action_run_set_test_var(ActionCond *cond) {
    u16 *vars = action_vars;
    s16 value;
    s16 ret;
    if (cond->used == 0) {
        return 2;
    }
    value = vars[cond->index];
    ret = 1;
    if (value >= cond->low && cond->high >= value) {
        ret = cond->invert == 0;
    } else if (cond->invert == 0) {
        ret = 0;
    }
    return ret;
}

static inline s16 action_run_set_test_status(ActionCond *cond) {
    PlayerStatus *status = &player_status;
    s16 value;
    s16 ret;
    if (cond->used == 0) {
        return 2;
    }
    ret = 1;
    switch (cond->index) {
    case 0:
        value = status->stat0;
        break;
    case 1:
        value = status->stat1;
        break;
    case 2:
        value = status->stat2;
        break;
    case 3:
        value = status->stat3;
        break;
    }
    if (value >= cond->low && cond->high >= value) {
        if (cond->invert != 0) {
            ret = 0;
        }
    } else if (cond->invert == 0) {
        ret = 0;
    }
    return ret;
}

static inline void action_run_set_queue(ActionSet *set, s16 at_cursor, s16 skip_text_wait) {
    LlList *list;
    Action *act;
    ActionCmd *cmd;
    s16 first = 1;
    s32 i;
    if (at_cursor != 0) {
        act = set->actions;
        list = action_queue;
        for (i = 0; i < set->count; i++, act++) {
            cmd = act->cmd;
            if (skip_text_wait != 0) {
                if (cmd->opcode == 5 || *(s32 *)cmd == 0xB) {
                    continue;
                }
                if (*(s32 *)cmd == 0x1000B) {
                    cmd->sub = 10;
                }
            }
            if (action_queue_front_flag != 0 && first != 0) {
                first = 0;
                action_queue_front_flag = 0;
                list->cursor = list->head;
                kaj_ll_insert_before(list, (s32)act);
            } else {
                kaj_ll_insert_after(list, (s32)act);
            }
        }
    } else {
        LlList *l2;
        Action *act2;
        act2 = set->actions;
        l2 = action_queue;
        for (i = 0; i < set->count; i++, act2++) {
            cmd = act2->cmd;
            if (skip_text_wait != 0) {
                if (cmd->opcode == 5 || *(s32 *)cmd == 0xB) {
                    continue;
                }
                if (*(s32 *)cmd == 0x1000B) {
                    cmd->sub = 10;
                }
            }
            if (l2->count == 0) {
                kaj_ll_insert_before(l2, (s32)act2);
            } else {
                l2->cursor = l2->tail;
                kaj_ll_insert_after(l2, (s32)act2);
            }
        }
    }
}

static inline ActionSet *action_run_set_find(s16 id) {
    LlList *list = action_set_list;
    ActionSet *set;
    if (list->count == 0) {
        return NULL;
    }
    if (id < 0) {
        return NULL;
    }
    list->cursor = list->head;
    while (1) {
        set = list->cursor->data;
        if (set != NULL && set->header->id == id) {
            return set;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
    return NULL;
}

ActionSet *action_run_set(ActionSet *set, s32 at_cursor, s32 skip_text_wait) {
    ActionSetHeader *header = set->header;
    s16 results[4];
    s32 n_unused;
    s32 n_true;
    s32 i;

    results[0] = action_run_set_test_var(&header->cond_var_a);
    results[1] = action_run_set_test_var(&header->cond_var_b);
    results[2] = action_run_set_test_status(&header->cond_status);
    results[3] = action_test_inventory(&header->cond_inventory);
    for (i = 0, n_unused = 0; i < 4; i++) {
        if (results[i] == 2) {
            n_unused++;
        }
    }
    if (n_unused == 4) {
        action_run_set_queue(set, at_cursor, skip_text_wait);
        if (header->next_mode == 1 || header->next_mode == 2) {
            return action_run_set_find(header->next_set);
        }
        return NULL;
    }
    for (i = 0, n_true = 0; i < 4; i++) {
        if (results[i] == 1) {
            n_true++;
        }
    }
    if (header->match_all == 0) {
        if (n_true > 0) {
            action_run_set_queue(set, at_cursor, skip_text_wait);
            if (header->next_mode == 1 || header->next_mode == 2) {
                return action_run_set_find(header->next_set);
            }
        } else {
            if (header->next_mode == 0 || header->next_mode == 2) {
                return action_run_set_find(header->next_set);
            }
        }
    } else if (n_true == 4 - n_unused) {
        action_run_set_queue(set, at_cursor, skip_text_wait);
        if (header->next_mode == 1 || header->next_mode == 2) {
            return action_run_set_find(header->next_set);
        }
    } else {
        if (header->next_mode == 0 || header->next_mode == 2) {
            return action_run_set_find(header->next_set);
        }
    }
    return NULL;
}

void action_reset(s16 flush_all) {
    EventState *event = &event_state;
    u16 old_state = event->state;
    u16 old_flags = event->wait_flags;
    u16 old_timer = event->wait_timer;
    LlList *list;
    ActionCmd *cmd;

    text_release_cmd();
    memset(event, 0, 0x14);
    event->circle_set = -1;
    event->cross_set = -1;
    event->state = 0;
    if (flush_all == 0) {
        if (old_state == 1 || old_state == 4) {
            event->state = old_state;
        }
        if (old_flags & 1) {
            event->wait_flags = old_flags & ~1;
            if (event->wait_flags == 0) {
                event->state = 1;
            }
            event->wait_timer = 0;
        } else {
            event->wait_flags = old_flags;
            event->wait_timer = old_timer;
        }
    }
    list = action_queue;
    if (list->count == 0) {
        return;
    }
    if (flush_all != 0) {
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
            cmd = (ActionCmd *)list->cursor->data->header;
            if (cmd->opcode == 5 || *(s32 *)cmd == 0xB) {
                kaj_ll_remove_to_prev(list);
            }
            if (*(s32 *)cmd == 0x1000B) {
                cmd->sub = 10;
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void action_push_front(s32 action) {
    action_queue->cursor = action_queue->head;
    kaj_ll_insert_before(action_queue, action);
}

void action_flush_queue(s16 flush_all) {
    LlList *list = action_queue;
    ActionCmd *cmd;

    if (list->count == 0) {
        return;
    }
    if (flush_all != 0) {
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
            cmd = (ActionCmd *)list->cursor->data->header;
            if (cmd->opcode == 5 || *(s32 *)cmd == 0xB) {
                kaj_ll_remove_to_prev(list);
            }
            if (*(s32 *)cmd == 0x1000B) {
                cmd->sub = 10;
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void action_free_set(ActionSet *set) {
    Action *act = set->actions;
    s32 i;

    for (i = 0; i < set->count; i++, act++) {
        if (act->args != NULL) {
            free3(act->args[0]);
            free3(act->args);
        }
        free3(act->cmd);
    }
    free3(set->actions);
    free3(set->header);
    free3(set);
}

void action_free_all_sets(void) {
    LlList *list = action_set_list;
    ActionSet *set;
    Action *act;
    s32 i;

    while (1) {
        if (list->count == 0) {
            break;
        }
        set = list->cursor->data;
        act = set->actions;
        for (i = 0; i < set->count; i++, act++) {
            if (act->args != NULL) {
                free3(act->args[0]);
                free3(act->args);
            }
            free3(act->cmd);
        }
        free3(set->actions);
        free3(set->header);
        free3(set);
        kaj_ll_remove_to_prev(list);
    }
}

ActionSet *action_find_set(s16 id) {
    LlList *list = action_set_list;
    ActionSet *set;

    if (list->count == 0) {
        return NULL;
    }
    if (id < 0) {
        return NULL;
    }
    list->cursor = list->head;
    while (1) {
        set = list->cursor->data;
        if (set != NULL && set->header->id == id) {
            return set;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
    return NULL;
}

s32 action_run_trigger_enter(SceneTrigger *trigger) {
    LlList *list;
    ActionSet *set;
    ActionSet *p;
    s16 id;

    if (trigger == NULL || trigger->enabled == 0) {
        return 0;
    }
    list = action_set_list;
    id = trigger->enter_set;
    if (list->count == 0) {
        set = NULL;
    } else if (id < 0) {
        set = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            p = list->cursor->data;
            if (p != NULL && p->header->id == id) {
                set = p;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                set = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (set == NULL) {
        return 0;
    }
    while ((set = action_run_set(set, 0, 0)) != NULL) {
    }
    return 1;
}

s32 action_run_trigger_leave(SceneTrigger *trigger) {
    LlList *list;
    ActionSet *set;
    ActionSet *p;
    s16 id;

    if (trigger == NULL || trigger->enabled == 0) {
        return 0;
    }
    list = action_set_list;
    id = trigger->leave_set;
    if (list->count == 0) {
        set = NULL;
    } else if (id < 0) {
        set = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            p = list->cursor->data;
            if (p != NULL && p->header->id == id) {
                set = p;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                set = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (set == NULL) {
        return 0;
    }
    while ((set = action_run_set(set, 0, 0)) != NULL) {
    }
    return 1;
}

SceneTrigger *action_find_trigger(s32 id) {
    SceneTables *p = &object_scene_tables;
    s32 n = p->trigger_count;
    SceneTrigger *trigger = p->triggers;
    s32 i;
    if (n == 0) {
        return NULL;
    }
    for (i = 0; i < n; i++, trigger++) {
        if (trigger->id == id) {
            return trigger;
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

void action_place_npc(Npc *npc, Model *model) {
    Player *player = player_status_player[0];
    SVector rot;

    if (model->ready == 0) {
        if (npc->state == 6) {
            npc->mode = 2;
            mod_setup(model, 0, 0, 8);
        } else {
            mod_setup(model, 0, 0, 0);
        }
    }
    model->coord_tx = npc->pos_x - player->cell_x * 12500;
    model->coord_ty = npc->pos_y + player->cell_y * 32000;
    model->coord_tz = npc->pos_z - player->cell_z * 12500;
    rot.vx = (npc->pitch << 12) / 360;
    rot.vy = (npc->yaw << 12) / 360;
    rot.vz = (npc->roll << 12) / 360;
    RotMatrix(&rot, model->coord_m);
    model->coord_flg = 0;
}

void action_init_npcs(void) {
    SceneTables *p = &object_scene_tables;
    Npc *npc = p->npcs;
    Model *model;
    s32 i;

    if (p->npc_count == 0) {
        return;
    }
    for (i = 0; i < p->npc_count; i++, npc++) {
        npc->placed = 0;
        npc->pos_x *= 10;
        npc->pos_y *= 10;
        npc->pos_z *= 10;
        npc->dest_x *= 10;
        npc->dest_y *= 10;
        npc->dest_z *= 10;
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
        npc->flags |= 1;
        npc->target_yaw = npc->yaw;
        npc->placed = 1;
        }
    }
}

s32 action_run_npc_event(u16 id, s16 enter) {
    SceneTables *p = &object_scene_tables;
    ActionSet *set = NULL;
    s32 n = p->npc_count;
    Npc *cur = p->npcs;
    Npc *npc;
    s32 i;

    if (n == 0) {
        npc = NULL;
    } else {
        for (i = 0; i < n; i++, cur++) {
            if (cur->id == id) {
                npc = cur;
                goto found;
            }
        }
        npc = NULL;
    }
found:
    if (npc == NULL || npc->placed == 0) {
        return 0;
    }
    if (npc->talkable == 0) {
        return 0;
    }
    if (npc->state == 6) {
        if (enter != 0) {
            set = action_find_set(0x400);
        } else {
            text_close();
        }
    } else if (npc->mode == 1) {
        if (npc->flags & 0x20) {
            npc->flags &= ~0x20;
        }
        return 0;
    } else {
        if (enter != 0) {
            set = action_find_set(npc->talk_set);
            npc->flags |= 0x20;
        } else {
            set = action_find_set(npc->leave_set);
            npc->flags &= ~0x20;
        }
    }
    if (set == NULL) {
        return 0;
    }
    while ((set = action_run_set(set, 0, 0)) != NULL) {
    }
    return 1;
}
