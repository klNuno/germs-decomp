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
extern Unk_8018E56C *ai_cur_model;
NpcStats *npc_find_stats(s16 arg0);
s16 ai_find_target(Npc *arg0, s16 arg1);
s16 ai_decide_fire(Npc *arg0);
void ai_face_player(Npc *arg0);
extern NpcStats D_801D7328;
extern NpcBody ai_default_body;
extern Unk_801DFC60 *ai_cur_block;
extern s32 ai_cur_grid;
extern NpcStats *ai_cur_stats;
extern NpcBody *ai_cur_body;
/* Local view of Unk_80173250: this unit reads 0x4 as u16, the shared type has an s32 there. */
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} Unk_80173250_u8017546C;
typedef struct {
    Unk_80173250_u8017546C *unk0;
    s32 unk4;
    char **unk8;
} Unk_80173054;
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

s16 npc_update_anim(Npc *arg0, s16 arg1) {
    PlayerStatus *g = &player_status;
    Inventory *s = g->inventory;
    Unk_8018E56C *o;
    NpcStats *k;
    u16 lo;
    u16 hi;
    u16 t;
    s32 d;
    s32 n;

    o = mod_find(arg0->unk16);
    if (o == NULL) {
        return 0;
    }
    switch (arg1) {
    case 0:
        if (arg0 == g->target_npc) {
            s->armed = 1;
        }
        if (arg0->unkE == 1) {
            if (o->unk16 != 3) {
                mod_set_anim(o, 3, 0);
                break;
            }
        } else {
            if (o->unk16 != 0) {
                mod_set_anim(o, 0, 0);
                break;
            }
        }
        break;
    case 1:
        if (arg0 == g->target_npc) {
            s->armed = 1;
        }
        if (arg0->unkE == 1) {
            if (o->unk16 != 4) {
                mod_set_anim(o, 4, 0);
                break;
            } else if (o->unk8 == 0) {
                mod_set_anim(o, 4, 0);
                break;
            }
        } else {
            if (o->unk16 != 2) {
                mod_set_anim(o, 2, 0);
                break;
            } else if (o->unk8 == 0) {
                mod_set_anim(o, 2, 0);
                break;
            }
        }
        break;
    case 2:
        if (arg0 == g->target_npc) {
            s->armed = 0;
        }
        if (o->unk16 != 1) {
            mod_set_anim(o, 1, 0);
            break;
        } else if (o->unk8 == 0) {
            mod_set_anim(o, 1, 0);
            break;
        }
        break;
    case 3:
        if (arg0 == g->target_npc) {
            s->armed = 1;
        }
        if (o->unk16 != 9) {
            if (arg0->unk12 & 0x400) {
                arg0->unk12 &= ~0x1000;
            } else {
                mod_set_anim(o, 9, 0);
                break;
            }
        } else if (o->unk8 == 0) {
            arg0->unk12 &= ~0x1000;
        }
        break;
    case 4:
        if (arg0 == g->target_npc) {
            s->armed = 1;
        }
        if (o->unk16 != 7) {
            if (arg0->unk12 & 0x400) {
                arg0->unk12 &= ~0x400;
                arg0->unk46 = 0;
            }
            mod_set_anim(o, 7, 5);
            break;
        } else if (o->unk8 == 0) {
            arg0->unk12 &= ~0x800;
        }
        break;
    case 5:
        if (arg0 == g->target_npc) {
            s->armed = 1;
        }
        k = npc_find_stats(arg0->unk18);
        if (k == NULL) {
            return 0;
        }
        switch (o->unk16) {
        case 1:
            if (arg0->unk12 & 0x200) {
                arg0->unk12 &= ~0x200;
            }
        case 3:
        case 4:
            mod_set_anim(o, 5, 0);
            break;
        case 5:
            if (o->unk8 == 0) {
                if (arg0->unk46 != 0) {
                    arg0->unk46 -= D_801E6DB4[0];
                    if (arg0->unk46 <= 0) {
                        arg0->unk46 = 0;
                        mod_set_anim(o, 6, 0);
                        if ((u16)k->unk16 < 0x100 && (u16)k->unk16 >= o->unkE) {
                            k->unk16 = o->unkE - 1;
                        }
                    }
                } else if (k == NULL) {
                    arg0->unk46 = 30;
                } else {
                    if (k->unkE == 0) {
                        k->unkE = 1;
                    }
                    arg0->unk46 = k->unkE;
                }
            }
            break;
        case 6:
            if (o->unk8 == 0) {
                arg0->unk12 &= ~0x400;
                if ((u16)k->weapon_kind == 4) {
                    sound_se_stop(0x27);
                }
            } else {
                d = o->unk12;
                n = (u16)k->unk16;
                lo = n / d;
                t = o->unkC / d;
                hi = 0xFFFF;
                if ((u16)n > 0x100) {
                    lo = (n & 0xFF) / d;
                    hi = ((n & 0xFF00) >> 8) / d;
                }
                if (lo == t || hi == t) {
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
    Npc *p;
    Unk_8018E56C *q;
    Unk_80174B10 *r;
    s32 i;
    u16 flags;
    SceneTables *g = &object_scene_tables;

    p = g->npcs;
    if (g->npc_count != 0) {
        player_shoot_target();
        for (i = 0; i < g->npc_count; i++, p++) {
            if (p->unk6 == 0) {
                continue;
            }
            if (p->unk4 == 0) {
                q = mod_find(p->unk16);
                if (q != NULL) {
                    action_place_npc(p, q);
                    p->unk48 = block_find_at(p->unk20, p->unk24, p->unk28);
                    p->unk10 = -2;
                    p->unk40 = 0;
                    p->unkB = 0;
                    p->unk44 = 0;
                    p->unk45 = 0;
                    p->unk46 = 0;
                    p->unk4 = 1;
                    p->unk12 |= 1;
                    p->unk3E = p->unk3A;
                }
            } else if ((p->unkE != 2 || p->unkF != 6)) {
                flags = p->unk12;
                if (flags < 0x100) {
                    if (p->unkE == 2) {
                        Unk_801DFFE8 *d = &D_801DFFE8;
                        s32 k = 6;

                        if (p->unkF != k) {
                            p->unkF = k;
                            p->unk12 = 0;
                            r = action_find_set(p->unk1E);
                            if (r != NULL) {
                                D_801DFC5C = 0;
                                if (p->unk1E == 1000) {
                                    D_801DFC5C = 1;
                                }
                                do {
                                    r = action_run_set(r, 0, 0);
                                } while (r != NULL);
                                if (d->unk6 == 0) {
                                    d->unk6 = 1;
                                }
                            }
                            sound_se_stop(0x27);
                            sound_se_play(0x14);
                            mod_set_anim_by_id(p->unk16, 7, 0);
                        }
                    } else if (p->unkF == 0) {
                        npc_update_anim(p, 0);
                        ai_update_stand(p);
                    } else if (p->unkF == 1) {
                        if (p->unkE == 0) {
                            npc_update_anim(p, 1);
                            ai_update_move(p, 0);
                        } else if (p->unkE == 1) {
                            npc_update_anim(p, 1);
                            ai_update_move(p, 1);
                        }
                    }
                } else if (p->unkF != 6) {
                    if (flags & 0x800) {
                        npc_update_anim(p, 4);
                    } else if (flags & 0x1000) {
                        npc_update_anim(p, 3);
                    } else if (flags & 0x400) {
                        if (npc_update_anim(p, 5) != 0) {
                            ai_fire(p);
                        }
                    } else if (flags & 0x200) {
                        npc_update_anim(p, 2);
                        ai_update_stand(p);
                    } else if (flags & 0x100) {
                        npc_update_anim(p, 1);
                        ai_update_move(p, 2);
                    }
                }
            }
        }
        player_pick_target();
        D_801DFC76 = 0;
        D_801DFC74 = 0;
    }
}

void npc_exec_command(Unk_80173054 *arg0) {
    SceneTables *p = &object_scene_tables;
    Npc *e = p->npcs;
    Unk_80173250_u8017546C *cmd = arg0->unk0;
    u16 id = cmd->unk4;
    Npc *t;
    s32 i;

    if (p->npc_count == 0) {
        t = NULL;
    } else {
        for (i = 0; i < p->npc_count; i++, e++) {
            if (e->unk0 == id) {
                t = e;
                goto done;
            }
        }
        t = NULL;
    }
done:
    if (t == NULL) {
        return;
    }
    switch (cmd->unk2) {
    case 0:
        if (atoi(arg0->unk8[0]) != 0) {
            if (atoi(arg0->unk8[1]) != 0) {
                t->unk1C = atoi(arg0->unk8[2]);
            } else {
                t->unk1A = atoi(arg0->unk8[2]);
            }
        } else {
            if (atoi(arg0->unk8[1]) != 0) {
                t->unk1E = atoi(arg0->unk8[2]);
            }
        }
        break;
    case 1:
        t->unk8 = atoi(arg0->unk8[0]);
        break;
    case 2:
        t->unk6 = atoi(arg0->unk8[0]);
        break;
    case 3:
        if (t->unkE != 2 && t->unkF != 6) {
            t->unkF = atoi(arg0->unk8[0]);
        }
        break;
    case 5:
        if (t->unkE != 2 && t->unkF != 6) {
            t->unkE = atoi(arg0->unk8[0]);
            if (t->unkE == 2) {
                t->unk12 = 0;
            }
        }
        break;
    case 7:
        if (t->unkE != 2 && t->unkF != 6) {
            switch (atoi(arg0->unk8[0])) {
            case 0:
                t->unk12 &= 0x1FF;
                break;
            case 1:
                t->unk12 |= 0x100;
                break;
            case 3:
                t->unk12 = (t->unk12 & 0x1FF) | 0x200;
                break;
            }
        }
        break;
    }
}

void npc_apply_damage(Npc *arg0, s32 arg1, s32 arg2, s16 arg3) {
    PlayerStatus *g = &player_status;
    NpcStats *k;
    s32 v;
    s16 f;
    s32 n;

    if (arg0->unkC <= 0) {
        return;
    }
    k = npc_find_stats(arg0->unk18);
    if (k == NULL) {
        return;
    }
    if (k->unk4 == 1) {
        if (arg0->unkE != 1) {
            arg0->unkE = 1;
            if (arg0->unk12 & 0x100) {
                arg0->unk12 &= ~0x100;
            }
        }
    } else if (k->unk4 == 2) {
        if (arg0->unkE != 1) {
            arg0->unkE = 1;
            if (arg0->unkF == 0) {
                arg0->unkF = 1;
            }
        }
    }
    if (arg3 != 0) {
        if (!(arg0->unk12 & 0x1000)) {
            arg0->unk12 |= 0x1000;
        }
        event_set_blink(1, 1);
        return;
    }
    if (k->defence == 0x7FFF) {
        v = 0x7FFF;
    } else {
        v = rand() % k->defence;
    }
    f = 0;
    switch (arg1) {
    case 0:
        if (k->resist_types & 1) {
            f = 1;
        }
        break;
    case 1:
        if (k->resist_types & 2) {
            f = 1;
        }
        break;
    case 2:
        if (k->resist_types & 4) {
            f = 1;
        }
        break;
    case 3:
        if (k->resist_types & 8) {
            f = 1;
        }
        break;
    case 4:
        if (k->resist_types & 0x10) {
            f = 1;
        }
        break;
    }
    if (!f) {
        v = v * 2 / 3;
    }
    arg2 -= v;
    if (arg2 <= 0) {
        event_set_blink(1, 1);
        return;
    }
    player_add_skill_exp(arg1, arg2 * 2);
    arg0->unkC -= arg2;
    if (arg0->unkC <= 0) {
        if (arg0->unkE != 2) {
            arg0->unkE = 2;
            arg0->unk12 = 0;
            n = arg0->unk42;
            switch ((u16)arg0->unk2) {
            case 0:
                g->unk32++;
                g->unk2E++;
                break;
            case 1:
            case 2:
                n *= 2;
                break;
            case 3:
            case 4:
            case 5:
                n *= 3;
                break;
            case 16:
            case 17:
            case 18:
                n *= 4;
                break;
            case 19:
                n *= 6;
                break;
            }
            player_add_exp(n);
        }
    } else {
        if (!(arg0->unk12 & 0x800)) {
            arg0->unk12 |= 0x800;
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

Npc *npc_find(s16 arg0, u16 arg1) {
    SceneTables *p = &object_scene_tables;
    Npc *e = p->npcs;
    s32 i;
    if (p->npc_count == 0) {
        return NULL;
    }
    for (i = 0; i < p->npc_count; i++, e++) {
        if (arg0 == 0) {
            if (e->unk0 == arg1) {
                return e;
            }
        } else {
            if (e->unk16 == arg1) {
                return e;
            }
        }
    }
    return NULL;
}

void npc_draw_all(s32 arg0) {
    SceneTables *p = &object_scene_tables;
    Npc *e = p->npcs;
    Unk_80176370 *x;
    Unk_8018E56C *o;
    s32 i;

    if (p->npc_count == 0) {
        return;
    }
    for (i = 0; i < p->npc_count; i++, e++) {
        x = (Unk_80176370 *)e->unk48;
        if (e != NULL && e->unk4 != 0 && e->unk6 != 0 && x != NULL && x->unk4 != 0) {
            o = mod_find(e->unk16);
            if (o != NULL && o->unk4 != 0) {
                mod_draw(arg0, o, e->unkA);
            }
        }
    }
}

s16 npc_find_at_point(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    SceneTables *p = &object_scene_tables;
    Npc *e = p->npcs;
    Unk_8018E56C *o;
    s32 i;

    if (p->npc_count == 0) {
        return -2;
    }
    for (i = 0; i < p->npc_count; i++, e++) {
        if (e->unk4 != 0 && e->unk6 != 0) {
            o = mod_find(e->unk16);
            if (arg0 != e->unk0 && o != NULL && o->unk4 != 0 && o->unk30 != NULL) {
                GsSetLsMatrix(o->unk40);
                if (block_point_on_model(o->unk30, arg1, arg2, arg3, 1) != 0) {
                    return e->unk0;
                }
            }
        }
    }
    return -2;
}

void npc_update_blocks(void) {
    SceneTables *p = &object_scene_tables;
    Npc *e = p->npcs;
    s32 i;
    for (i = 0; i < p->npc_count; i++, e++) {
        if (e->unk4 != 0 && e->unk6 != 0) {
            e->unk48 = block_find_at(e->unk20, e->unk24, e->unk28);
        }
    }
}

void npc_rebase_all(s32 arg0, s32 arg1, s32 arg2) {
    SceneTables *p = &object_scene_tables;
    Npc *e = p->npcs;
    Unk_8018E56C *o;
    s32 i;

    if (p->npc_count == 0) {
        return;
    }
    for (i = 0; i < p->npc_count; i++, e++) {
        if (e->unk4 != 0) {
            o = mod_find(e->unk16);
            if (o != NULL) {
                o->unk54 = e->unk20 - arg0;
                o->unk58 = e->unk24 - arg1;
                o->unk5C = e->unk28 - arg2;
                o->unk3C = 0;
            }
        }
    }
}

u16 npc_get_radius(Npc *arg0) {
    NpcBody *e = npc_find_body(arg0->unk14);
    if (e == NULL) {
        return 600;
    }
    return e->radius * 10;
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

NpcBody *npc_find_body(s16 arg0) {
    SceneTables *p = &object_scene_tables;
    NpcBody *e = p->npc_bodies;
    s32 i;
    if (p->npc_body_count == 0 || arg0 < 0) {
        return NULL;
    }
    for (i = 0; i < p->npc_body_count; i++, e++) {
        if (e->unk0 == arg0) {
            return e;
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

NpcStats *npc_find_stats(s16 arg0) {
    SceneTables *p = &object_scene_tables;
    NpcStats *e = p->npc_stats;
    s32 i;
    if (p->npc_stats_count == 0 || arg0 < 0) {
        return NULL;
    }
    for (i = 0; i < p->npc_stats_count; i++, e++) {
        if (e->unk0 == arg0) {
            return e;
        }
    }
    return NULL;
}
