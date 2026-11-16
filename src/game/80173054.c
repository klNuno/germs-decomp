#include "common.h"
#include "game/types.h"

Unk_801DFE54 *action_queue;
void kaj_ll_insert_before(Unk_801DFE54 *a0, s32 a1);
extern SceneTables object_scene_tables;
void free3(void *ptr);
s32 block_find_at(s32 a0, s32 a1, s32 a2);
NpcBody *npc_find_body(s16 arg0);
extern Inventory *D_801E0768[];
Unk_8018E56C *mod_find(u16 arg0);
void mod_draw(s32 arg0, Unk_8018E56C *arg1, u16 arg2);
void kaj_ll_remove_to_prev(Unk_801DFE54 *arg0);
s16 kaj_ll_at_tail(Unk_801DFE54 *arg0);
Unk_801DFE54 *action_set_list;
Unk_80174B10 *action_run_set(Unk_80174B10 *arg0, s32 arg1, s32 arg2);
extern Unk_801DFFE8 D_801DFFE8;
void text_release_cmd(void);
void *memset(void *dst, s32 c, u32 n);
extern Player *D_801E076C[];
void mod_setup(Unk_8018E56C *arg0, s32 arg1, s32 arg2, s32 arg3);
void RotMatrix(Unk_80174FFC *arg0, void *arg1);
void action_place_npc(Npc *arg0, Unk_8018E56C *arg1);
Unk_80174B10 *action_find_set(s16 arg0);
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
Unk_8018E56C *ai_cur_model;
NpcStats *npc_find_stats(s16 arg0);
s16 ai_find_target(Npc *arg0, s32 arg1);
s16 ai_decide_fire(Npc *arg0);
void ai_face_player(Npc *arg0);
extern NpcStats D_801D7328;
extern NpcBody ai_default_body;
Unk_801DFC60 *ai_cur_block;
s32 ai_cur_grid;
NpcStats *ai_cur_stats;
NpcBody *ai_cur_body;
typedef struct {
    Unk_80173250 *unk0;
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
void door_exec_command(Unk_80173054 *arg0, Unk_801DFFE8 *arg1);
void text_exec_command(Unk_80173054 *arg0);
void mod_cmd_npcrec(Unk_80173054 *arg0, Unk_801DFFE8 *arg1);
void player_exec_command(Unk_80173054 *arg0, Unk_801DFFE8 *arg1);
void sound_exec_command(Unk_80173054 *arg0);
void kaj_event_push(s32 arg0);
void sprite_exec_command(Unk_80173054 *arg0);
void mail_cmd_receive(Unk_80173054 *arg0);
void roadmap_start_flash(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void kaj_ll_insert_after(Unk_801DFE54 *a0, s32 a1);
extern PlayerStatus player_status;
s16 action_test_inventory(Unk_80173954 *arg0);
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
    Unk_80173250 *cmd = arg0->unk0;
    s32 a, b, c, d;
    s32 x, y, z;

    switch (cmd->unk2) {
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
        mail_goto_building(cmd->unk2, arg0->unk8[1], a, arg0->unk8[0][0], b, c, d, *arg1, 1);
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
    Unk_80173250 *cmd = arg0->unk0;
    s32 v = atoi(arg0->unk8[0]);

    switch (cmd->unk2) {
    case 0:
        vars[cmd->unk4] = v;
        break;
    case 1:
        vars[cmd->unk4] -= v;
        break;
    case 2:
        vars[cmd->unk4] += v;
        break;
    case 3:
        vars[cmd->unk4] *= v;
        break;
    case 4:
        vars[cmd->unk4] /= (s16)v;
        break;
    case 5:
        vars[cmd->unk4] = (s16)vars[cmd->unk4] % (s16)v;
        break;
    case 6:
        vars[cmd->unk4] = vars[(s16)v];
        break;
    case 7:
        vars[cmd->unk4] -= vars[(s16)v];
        break;
    case 8:
        vars[cmd->unk4] += vars[(s16)v];
        break;
    }
}

void action_update(void) {
    Unk_801DFFE8 *s = &D_801DFFE8;
    Unk_801DFE54 *list;
    Unk_80173054 *cmd;
    Unk_80173250 *c;
    SceneTrigger *e;
    Unk_80174B10 *item;
    Unk_8017345C op;
    s32 flag;
    s32 a, b, d;
    s32 n;

    switch (s->unk6) {
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
        if ((s16)s->unk10 == 0) {
            return;
        }
        s->unk10 -= D_801E6DB4[0];
        if ((s16)s->unk10 > 0) {
            return;
        }
        s->unk10 = 0;
        s->unk12 &= ~1;
        if (s->unk12 != 0) {
            return;
        }
        s->unk6 = 1;
        break;
    }

    list = action_queue;
    n = list->unkC;
    op.unk0 = -2;
    if (n == 0) {
        cmd = NULL;
    } else {
        Unk_80173054 *t;
        list->unk8 = list->unk0;
        t = (Unk_80173054 *)list->unk8->unk8;
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
        e = action_find_trigger(c->unk4);
        if (e == NULL) {
            return;
        }
        switch (c->unk2) {
        case 0:
            if (atoi(cmd->unk8[0]) != 0) {
                e->unk6 = atoi(cmd->unk8[1]);
            } else {
                e->unk4 = atoi(cmd->unk8[1]);
            }
            break;
        case 1:
            e->unkA = atoi(cmd->unk8[0]);
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
        if (cmd->unk0->unk2 != 0) {
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
        switch (cmd->unk0->unk2) {
        case 0:
            s->unk6 = 4;
            s->unk12 |= 1;
            s->unk10 = atoi(cmd->unk8[0]) * 2;
            break;
        case 10:
            cmd->unk0->unk2 = 1;
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

s16 action_test_inventory(Unk_80173954 *arg0) {
    Inventory *p = D_801E0768[0];
    s16 ret;
    s32 n;
    s32 i;

    if (arg0->unk0 == 0) {
        return 2;
    }
    if (arg0->unk6 == 0) {
        if (arg0->unk4 != 0) {
            ret = 1;
            for (i = 1, n = 0; i < 2; i++) {
                if (p->weapon_ids[i] < arg0->unk8 || arg0->unkA < p->weapon_ids[i]) {
                    n++;
                }
            }
            if (n != 0) {
                ret = 0;
            }
        } else {
            ret = 0;
            for (i = 0; i < 8; i++) {
                if (p->item_ids[i] == arg0->unk8) {
                    ret = 1;
                    break;
                }
            }
        }
    }
    if (arg0->unk2 != 0) {
        ret = 1 - ret;
    }
    return ret;
}

u8 *action_load_set(u8 *arg0) {
    Unk_80174B10 *set;
    Unk_80174CB8 *act;
    Unk_80174BC8 *args;
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
    set->unk0 = kaj_malloc(0x38);
    if (set->unk0 == NULL) {
        kaj_abend(3, D_80170028, D_8017001C, 0x1F9);
    }
    *set->unk0 = *(Unk_80174A14 *)arg0;
    arg0 += 0x38;
    set->unk4 = *(s32 *)arg0;
    arg0 += 4;
    act = kaj_malloc(set->unk4 * 0xC);
    if (act == NULL) {
        kaj_abend(3, D_80170050, D_8017001C, 0x204);
    }
    set->unk8 = act;
    for (i = 0; i < set->unk4; i++, act++) {
        size = *(s32 *)arg0;
        arg0 += 4;
        act->unk0 = kaj_malloc(8);
        len = size - 0xC;
        if (act->unk0 == NULL) {
            kaj_abend(3, D_80170068, D_8017001C, 0x210);
        }
        *(Unk_80173A44 *)act->unk0 = *(Unk_80173A44 *)arg0;
        act->unk4 = *(s32 *)(arg0 + 8);
        if (act->unk4 == 0) {
            len = 0;
        }
        if (len == 0) {
            act->unk8 = NULL;
            arg0 += size;
        } else {
            args = kaj_malloc(act->unk4 * 4);
            if (args == NULL) {
                kaj_abend(3, D_8017008C, D_8017001C, 0x220);
            }
            buf = kaj_malloc(len);
            if (buf == NULL) {
                kaj_abend(3, D_801700B0, D_8017001C, 0x225);
            }
            act->unk8 = args;
            memcpy(buf, arg0 + 0xC, len);
            do {
                off = 0;
            } while (0);
            for (j = 0; j < act->unk4; j++) {
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
    if (action_set_list->unkC == 0) {
        kaj_ll_insert_before(action_set_list, (s32)set);
    } else {
        action_set_list->unk8 = action_set_list->unk4;
        kaj_ll_insert_after(action_set_list, (s32)set);
    }
    return arg0;
}

static inline s16 func_80173DE0_var(Unk_80173954 *arg0) {
    u16 *vars = action_vars;
    s16 v;
    s16 ret;
    if (arg0->unk0 == 0) {
        return 2;
    }
    v = vars[arg0->unk4];
    ret = 1;
    if (v >= arg0->unk8 && arg0->unkA >= v) {
        ret = arg0->unk2 == 0;
    } else if (arg0->unk2 == 0) {
        ret = 0;
    }
    return ret;
}

static inline s16 func_80173DE0_glob(Unk_80173954 *arg0) {
    PlayerStatus *g = &player_status;
    s16 v;
    s16 ret;
    if (arg0->unk0 == 0) {
        return 2;
    }
    ret = 1;
    switch (arg0->unk4) {
    case 0:
        v = g->unkC;
        break;
    case 1:
        v = g->unkE;
        break;
    case 2:
        v = g->unk10;
        break;
    case 3:
        v = g->unk12;
        break;
    }
    if (v >= arg0->unk8 && arg0->unkA >= v) {
        if (arg0->unk2 != 0) {
            ret = 0;
        }
    } else if (arg0->unk2 == 0) {
        ret = 0;
    }
    return ret;
}

static inline void func_80173DE0_run(Unk_80174B10 *arg0, s16 arg1, s16 arg2) {
    Unk_801DFE54 *list;
    Unk_80174CB8 *e;
    Unk_80174A14 *item;
    s16 first = 1;
    s32 i;
    if (arg1 != 0) {
        e = arg0->unk8;
        list = action_queue;
        for (i = 0; i < arg0->unk4; i++, e++) {
            item = e->unk0;
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
                list->unk8 = list->unk0;
                kaj_ll_insert_before(list, (s32)e);
            } else {
                kaj_ll_insert_after(list, (s32)e);
            }
        }
    } else {
        Unk_801DFE54 *l2;
        Unk_80174CB8 *e2;
        e2 = arg0->unk8;
        l2 = action_queue;
        for (i = 0; i < arg0->unk4; i++, e2++) {
            item = e2->unk0;
            if (arg2 != 0) {
                if (item->unk0 == 5 || *(s32 *)item == 0xB) {
                    continue;
                }
                if (*(s32 *)item == 0x1000B) {
                    item->unk2 = 10;
                }
            }
            if (l2->unkC == 0) {
                kaj_ll_insert_before(l2, (s32)e2);
            } else {
                l2->unk8 = l2->unk4;
                kaj_ll_insert_after(l2, (s32)e2);
            }
        }
    }
}

static inline Unk_80174B10 *func_80173DE0_find(s16 arg0) {
    Unk_801DFE54 *list = action_set_list;
    Unk_80174B10 *item;
    if (list->unkC == 0) {
        return NULL;
    }
    if (arg0 < 0) {
        return NULL;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && item->unk0->unk0 == arg0) {
            return item;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return NULL;
}

Unk_80174B10 *action_run_set(Unk_80174B10 *arg0, s32 arg1, s32 arg2) {
    Unk_80174A14 *h = arg0->unk0;
    s16 st[4];
    s32 n2;
    s32 n1;
    s32 i;

    st[0] = func_80173DE0_var(&h->unk8);
    st[1] = func_80173DE0_var(&h->unk14);
    st[2] = func_80173DE0_glob(&h->unk20);
    st[3] = action_test_inventory(&h->unk2C);
    for (i = 0, n2 = 0; i < 4; i++) {
        if (st[i] == 2) {
            n2++;
        }
    }
    if (n2 == 4) {
        func_80173DE0_run(arg0, arg1, arg2);
        if (h->unk6 == 1 || h->unk6 == 2) {
            return func_80173DE0_find(h->unk4);
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
            if (h->unk6 == 1 || h->unk6 == 2) {
                return func_80173DE0_find(h->unk4);
            }
        } else {
            if (h->unk6 == 0 || h->unk6 == 2) {
                return func_80173DE0_find(h->unk4);
            }
        }
    } else if (n1 == 4 - n2) {
        func_80173DE0_run(arg0, arg1, arg2);
        if (h->unk6 == 1 || h->unk6 == 2) {
            return func_80173DE0_find(h->unk4);
        }
    } else {
        if (h->unk6 == 0 || h->unk6 == 2) {
            return func_80173DE0_find(h->unk4);
        }
    }
    return NULL;
}

void action_reset(s16 arg0) {
    Unk_801DFFE8 *s = &D_801DFFE8;
    u16 a = s->unk6;
    u16 b = s->unk12;
    u16 c = s->unk10;
    Unk_801DFE54 *list;
    Unk_80174A14 *item;

    text_release_cmd();
    memset(s, 0, 0x14);
    s->unkA = -1;
    s->unkE = -1;
    s->unk6 = 0;
    if (arg0 == 0) {
        if (a == 1 || a == 4) {
            s->unk6 = a;
        }
        if (b & 1) {
            s->unk12 = b & ~1;
            if (s->unk12 == 0) {
                s->unk6 = 1;
            }
            s->unk10 = 0;
        } else {
            s->unk12 = b;
            s->unk10 = c;
        }
    }
    list = action_queue;
    if (list->unkC == 0) {
        return;
    }
    if (arg0 != 0) {
        while (1) {
            if (list->unkC == 0) {
                break;
            }
            kaj_ll_remove_to_prev(list);
        }
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        if (list->unk8->unk8 != NULL) {
            item = list->unk8->unk8->unk0;
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
        list->unk8 = list->unk8->unk4;
    }
}

void action_push_front(s32 arg0) {
    action_queue->unk8 = action_queue->unk0;
    kaj_ll_insert_before(action_queue, arg0);
}

void action_flush_queue(s16 arg0) {
    Unk_801DFE54 *list = action_queue;
    Unk_80174A14 *item;

    if (list->unkC == 0) {
        return;
    }
    if (arg0 != 0) {
        while (1) {
            if (list->unkC == 0) {
                break;
            }
            kaj_ll_remove_to_prev(list);
        }
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        if (list->unk8->unk8 != NULL) {
            item = list->unk8->unk8->unk0;
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
        list->unk8 = list->unk8->unk4;
    }
}

void action_free_set(Unk_80174B10 *arg0) {
    Unk_80174CB8 *e = arg0->unk8;
    s32 i;

    for (i = 0; i < arg0->unk4; i++, e++) {
        if (e->unk8 != NULL) {
            free3(e->unk8->unk0);
            free3(e->unk8);
        }
        free3(e->unk0);
    }
    free3(arg0->unk8);
    free3(arg0->unk0);
    free3(arg0);
}

void action_free_all_sets(void) {
    Unk_801DFE54 *list = action_set_list;
    Unk_80174B10 *item;
    Unk_80174CB8 *e;
    s32 i;

    while (1) {
        if (list->unkC == 0) {
            break;
        }
        item = list->unk8->unk8;
        e = item->unk8;
        for (i = 0; i < item->unk4; i++, e++) {
            if (e->unk8 != NULL) {
                free3(e->unk8->unk0);
                free3(e->unk8);
            }
            free3(e->unk0);
        }
        free3(item->unk8);
        free3(item->unk0);
        free3(item);
        kaj_ll_remove_to_prev(list);
    }
}

Unk_80174B10 *action_find_set(s16 arg0) {
    Unk_801DFE54 *list = action_set_list;
    Unk_80174B10 *item;

    if (list->unkC == 0) {
        return NULL;
    }
    if (arg0 < 0) {
        return NULL;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && item->unk0->unk0 == arg0) {
            return item;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return NULL;
}

s32 action_run_trigger_enter(Unk_80174D6C *arg0) {
    Unk_801DFE54 *list;
    Unk_80174B10 *item;
    Unk_80174B10 *p;
    s16 id;

    if (arg0 == NULL || arg0->unkA == 0) {
        return 0;
    }
    list = action_set_list;
    id = arg0->unk4;
    if (list->unkC == 0) {
        item = NULL;
    } else if (id < 0) {
        item = NULL;
    } else {
        list->unk8 = list->unk0;
        while (1) {
            p = list->unk8->unk8;
            if (p != NULL && p->unk0->unk0 == id) {
                item = p;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                item = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (item == NULL) {
        return 0;
    }
    while ((item = action_run_set(item, 0, 0)) != NULL) {
    }
    return 1;
}

s32 action_run_trigger_leave(Unk_80174D6C *arg0) {
    Unk_801DFE54 *list;
    Unk_80174B10 *item;
    Unk_80174B10 *p;
    s16 id;

    if (arg0 == NULL || arg0->unkA == 0) {
        return 0;
    }
    list = action_set_list;
    id = arg0->unk6;
    if (list->unkC == 0) {
        item = NULL;
    } else if (id < 0) {
        item = NULL;
    } else {
        list->unk8 = list->unk0;
        while (1) {
            p = list->unk8->unk8;
            if (p != NULL && p->unk0->unk0 == id) {
                item = p;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                item = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
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

void action_place_npc(Npc *arg0, Unk_8018E56C *arg1) {
    Player *p = D_801E076C[0];
    Unk_80174FFC sv;

    if (arg1->unk4 == 0) {
        if (arg0->unkF == 6) {
            arg0->unkE = 2;
            mod_setup(arg1, 0, 0, 8);
        } else {
            mod_setup(arg1, 0, 0, 0);
        }
    }
    arg1->unk54 = arg0->unk20 - p->cell_x * 12500;
    arg1->unk58 = arg0->unk24 + p->cell_y * 32000;
    arg1->unk5C = arg0->unk28 - p->cell_z * 12500;
    sv.unk0 = (arg0->unk38 << 12) / 360;
    sv.unk2 = (arg0->unk3A << 12) / 360;
    sv.unk4 = (arg0->unk3C << 12) / 360;
    RotMatrix(&sv, arg1->unk40);
    arg1->unk3C = 0;
}

void action_init_npcs(void) {
    SceneTables *p = &object_scene_tables;
    Npc *e = p->npcs;
    Unk_8018E56C *o;
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
    Unk_80174B10 *item = NULL;
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
