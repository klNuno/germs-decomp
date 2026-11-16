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

void action_cmd_change_scene(Unk_80173054 *action, s32 *event) {
    ActionCmd *cmd = action->unk0;
    s32 a, b, c, d;
    s32 x, y, z;

    switch (cmd->sub) {
    case 0:
        if (atoi(action->unk8[0]) != 0) {
            mail_goto_ofc(1, 0, 1, 0);
        } else {
            mail_goto_ofc(1, 1, 1, 2);
        }
        break;
    case 1:
    case 3:
        a = (s16)atoi(action->unk8[4]);
        b = (s16)atoi(action->unk8[2]);
        c = (s16)atoi(action->unk8[3]);
        d = (s16)atoi(action->unk8[5]);
        mail_goto_building(cmd->sub, action->unk8[1], a, action->unk8[0][0], b, c, d, *event, 1);
        break;
    case 2:
        x = atoi(action->unk8[0]) * 10;
        y = atoi(action->unk8[1]) * 10;
        z = atoi(action->unk8[2]) * 10;
        mail_goto_twn(x, y, z, atoi(action->unk8[3]), 1);
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

void action_cmd_var(Unk_80173054 *action) {
    u16 *vars = action_vars;
    ActionCmd *cmd = action->unk0;
    s32 value = atoi(action->unk8[0]);

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
    Unk_80173054 *action;
    ActionCmd *cmd;
    SceneTrigger *trigger;
    ActionSet *set;
    Unk_8017345C op;
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
        event->wait_timer -= D_801E6DB4[0];
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
    op.unk0 = -2;
    if (n == 0) {
        action = NULL;
    } else {
        Unk_80173054 *first;
        list->cursor = list->head;
        first = (Unk_80173054 *)list->cursor->data;
        op.unk0 = first->unk0->unk0;
        action = first;
        kaj_ll_remove_to_prev(list);
    }
    if (op.unk0 < 0) {
        action_reset(1);
        return;
    }
    switch (op.unk0) {
    case 0:
        cmd = action->unk0;
        trigger = action_find_trigger(cmd->target);
        if (trigger == NULL) {
            return;
        }
        switch (cmd->sub) {
        case 0:
            if (atoi(action->unk8[0]) != 0) {
                trigger->leave_set = atoi(action->unk8[1]);
            } else {
                trigger->enter_set = atoi(action->unk8[1]);
            }
            break;
        case 1:
            trigger->enabled = atoi(action->unk8[0]);
            break;
        case 2:
            trigger->unk8 = atoi(action->unk8[0]);
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
        if (action->unk0->sub != 0) {
            sound_bgm_fade_out(3);
        } else {
            sound_bgm_play(atoi(action->unk8[0]));
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
        switch (action->unk0->sub) {
        case 0:
            event->state = 4;
            event->wait_flags |= 1;
            event->wait_timer = atoi(action->unk8[0]) * 2;
            break;
        case 10:
            action->unk0->sub = 1;
            flag = 1;
        case 1:
            set = action_find_set(atoi(action->unk8[0]));
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
        red = atoi(action->unk8[0]) & 0xFF;
        green = atoi(action->unk8[1]) & 0xFF;
        blue = atoi(action->unk8[2]) & 0xFF;
        roadmap_start_flash(red, green, blue, (s16)atoi(action->unk8[3]));
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
    if (cond->unk6 == 0) {
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
    src += 4;
    set->header = kaj_malloc(0x38);
    if (set->header == NULL) {
        kaj_abend(3, D_80170028, D_8017001C, 0x1F9);
    }
    *set->header = *(ActionSetHeader *)src;
    src += 0x38;
    set->count = *(s32 *)src;
    src += 4;
    act = kaj_malloc(set->count * 0xC);
    if (act == NULL) {
        kaj_abend(3, D_80170050, D_8017001C, 0x204);
    }
    set->actions = act;
    for (i = 0; i < set->count; i++, act++) {
        size = *(s32 *)src;
        src += 4;
        act->cmd = kaj_malloc(8);
        len = size - 0xC;
        if (act->cmd == NULL) {
            kaj_abend(3, D_80170068, D_8017001C, 0x210);
        }
        *(Unk_80173A44 *)act->cmd = *(Unk_80173A44 *)src;
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
                kaj_abend(3, D_8017008C, D_8017001C, 0x220);
            }
            buf = kaj_malloc(len);
            if (buf == NULL) {
                kaj_abend(3, D_801700B0, D_8017001C, 0x225);
            }
            act->args = args;
            memcpy(buf, src + 0xC, len);
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

static inline s16 func_80173DE0_var(ActionCond *cond) {
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

static inline s16 func_80173DE0_glob(ActionCond *cond) {
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

static inline void func_80173DE0_run(ActionSet *set, s16 at_cursor, s16 skip_text_wait) {
    LlList *list;
    Action *act;
    ActionSetHeader *cmd;
    s16 first = 1;
    s32 i;
    if (at_cursor != 0) {
        act = set->actions;
        list = action_queue;
        for (i = 0; i < set->count; i++, act++) {
            cmd = act->cmd;
            if (skip_text_wait != 0) {
                if (cmd->unk0 == 5 || *(s32 *)cmd == 0xB) {
                    continue;
                }
                if (*(s32 *)cmd == 0x1000B) {
                    cmd->unk2 = 10;
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
                if (cmd->unk0 == 5 || *(s32 *)cmd == 0xB) {
                    continue;
                }
                if (*(s32 *)cmd == 0x1000B) {
                    cmd->unk2 = 10;
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

static inline ActionSet *func_80173DE0_find(s16 id) {
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
        if (set != NULL && set->header->unk0 == id) {
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

    results[0] = func_80173DE0_var(&header->cond_var_a);
    results[1] = func_80173DE0_var(&header->cond_var_b);
    results[2] = func_80173DE0_glob(&header->cond_status);
    results[3] = action_test_inventory(&header->cond_inventory);
    for (i = 0, n_unused = 0; i < 4; i++) {
        if (results[i] == 2) {
            n_unused++;
        }
    }
    if (n_unused == 4) {
        func_80173DE0_run(set, at_cursor, skip_text_wait);
        if (header->next_mode == 1 || header->next_mode == 2) {
            return func_80173DE0_find(header->next_set);
        }
        return NULL;
    }
    for (i = 0, n_true = 0; i < 4; i++) {
        if (results[i] == 1) {
            n_true++;
        }
    }
    if (header->unk2 == 0) {
        if (n_true > 0) {
            func_80173DE0_run(set, at_cursor, skip_text_wait);
            if (header->next_mode == 1 || header->next_mode == 2) {
                return func_80173DE0_find(header->next_set);
            }
        } else {
            if (header->next_mode == 0 || header->next_mode == 2) {
                return func_80173DE0_find(header->next_set);
            }
        }
    } else if (n_true == 4 - n_unused) {
        func_80173DE0_run(set, at_cursor, skip_text_wait);
        if (header->next_mode == 1 || header->next_mode == 2) {
            return func_80173DE0_find(header->next_set);
        }
    } else {
        if (header->next_mode == 0 || header->next_mode == 2) {
            return func_80173DE0_find(header->next_set);
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
    ActionSetHeader *cmd;

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
            cmd = list->cursor->data->header;
            if (cmd->unk0 == 5 || *(s32 *)cmd == 0xB) {
                kaj_ll_remove_to_prev(list);
            }
            if (*(s32 *)cmd == 0x1000B) {
                cmd->unk2 = 10;
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
    ActionSetHeader *cmd;

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
            cmd = list->cursor->data->header;
            if (cmd->unk0 == 5 || *(s32 *)cmd == 0xB) {
                kaj_ll_remove_to_prev(list);
            }
            if (*(s32 *)cmd == 0x1000B) {
                cmd->unk2 = 10;
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
            free3(act->args->unk0);
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
                free3(act->args->unk0);
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
        if (set != NULL && set->header->unk0 == id) {
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
            if (p != NULL && p->header->unk0 == id) {
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
            if (p != NULL && p->header->unk0 == id) {
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
        if (npc->unkF == 6) {
            npc->unkE = 2;
            mod_setup(model, 0, 0, 8);
        } else {
            mod_setup(model, 0, 0, 0);
        }
    }
    model->coord_tx = npc->unk20 - player->cell_x * 12500;
    model->coord_ty = npc->unk24 + player->cell_y * 32000;
    model->coord_tz = npc->unk28 - player->cell_z * 12500;
    rot.vx = (npc->unk38 << 12) / 360;
    rot.vy = (npc->unk3A << 12) / 360;
    rot.vz = (npc->unk3C << 12) / 360;
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
        npc->unk4 = 0;
        npc->unk20 *= 10;
        npc->unk24 *= 10;
        npc->unk28 *= 10;
        npc->unk2C *= 10;
        npc->unk30 *= 10;
        npc->unk34 *= 10;
        model = mod_find(npc->unk16);
        if (model != NULL) {
            action_place_npc(npc, model);
        npc->unk48 = block_find_at(npc->unk20, npc->unk24, npc->unk28);
        npc->unk10 = -2;
        npc->unk40 = 0;
        npc->unkB = 0;
        npc->unk44 = 0;
        npc->unk45 = 0;
        npc->unk46 = 0;
        npc->unk12 |= 1;
        npc->unk3E = npc->unk3A;
        npc->unk4 = 1;
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
            if (cur->unk0 == id) {
                npc = cur;
                goto found;
            }
        }
        npc = NULL;
    }
found:
    if (npc == NULL || npc->unk4 == 0) {
        return 0;
    }
    if (npc->unk8 == 0) {
        return 0;
    }
    if (npc->unkF == 6) {
        if (enter != 0) {
            set = action_find_set(0x400);
        } else {
            text_close();
        }
    } else if (npc->unkE == 1) {
        if (npc->unk12 & 0x20) {
            npc->unk12 &= ~0x20;
        }
        return 0;
    } else {
        if (enter != 0) {
            set = action_find_set(npc->unk1A);
            npc->unk12 |= 0x20;
        } else {
            set = action_find_set(npc->unk1C);
            npc->unk12 &= ~0x20;
        }
    }
    if (set == NULL) {
        return 0;
    }
    while ((set = action_run_set(set, 0, 0)) != NULL) {
    }
    return 1;
}
