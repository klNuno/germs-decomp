#include "common.h"
#include "game/types.h"

extern Player *player_status_player[];
void object_load_res(s32 arg0, s32 arg1);
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    u8 pad3C[0x2C];
    s32 unk68;
    u8 unk6C[0x20];
} Unk_801E032C;
extern Unk_801E032C *D_801E032C[];
void thing_car_init(Unk_801E032C *arg0, Player *arg1);
void thing_train_init(Unk_801E032C *arg0, Player *arg1);
extern SceneTables object_scene_tables;
void thing_car_get_out(Vehicle *arg0);
void free3(void *ptr);
void sound_se_pop(void);
void vehicle_car_drive(Player *arg0);
void thing_train_update(Player *arg0);
typedef struct Unk_801AC55C_1C { u16 unk0; u16 unk2; u8 pad4[0x10]; s16 unk14; } Unk_801AC55C_1C;
extern PlayerStatus player_status;
extern s16 vehicle_navi[];
void sound_se_play(s32 arg0);
s32 mail_menu_close(void);
extern TrainState vehicle_train_state;
Thing *thing_find(s32 arg0, s32 arg1);
extern char vehicle_str_file[];
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
void vehicle_car_follow_player(Thing *arg0, s32 arg1);
s32 mail_menu_open(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i);
extern char D_80171A78[];
extern char D_80171AA8[];
void *kaj_malloc(u32 size);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801AA8DC_10;
void RotMatrix(Unk_801AA8DC_10 *arg0, void *arg1);
extern EventState event_state;
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void text_close(void);
void action_reset(s16 arg0);
extern s32 vehicle_str_sb1[];
extern s32 vehicle_str_rw1[];
void mail_goto_building(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
extern SceneRequest scene_request;
extern KajSystem kaj_system;
extern RoadMap roadmap_state;
s16 mail_menu_get_state(void);
s16 mail_menu_move(s16 a);
void vehicle_navi_open_menu(void);
extern s16 vehicle_navi_dest_xz[];
typedef struct { u8 pad0[0x60]; s32 unk60; s32 unk64; s32 unk68; } Unk_801AC578;
VehicleSprite *sprite_find(u16 arg0);
s32 SquareRoot0(s32 arg0);
typedef struct { u8 pad0[0x22]; s16 unk22; s16 unk24; s16 unk26; s16 unk28; u8 pad2A[0x2]; s32 unk2C; void *unk30; void *unk34; void *unk38; VehicleSprite **unk3C; } Unk_801AC70C;
void thing_set_animate(s32 a, s32 b, s32 c);
void *kaj_tss_alloc(u32 arg0);
s32 kaj_tss_start(void *arg0);
void vehicle_train_door_frame(Unk_801AC70C *arg0);
void vehicle_train_door_last(Unk_801AC70C *arg0);
s32 MoveImage(Rect *rect, s32 x, s32 y);
void RotMatrixZXY(Unk_801AA8DC_10 *arg0, void *arg1);
s32 block_find_surface(s32 arg0, s32 arg1, s32 *arg2, s32 arg3);
s32 block_find_at(s32 a0, s32 a1, s32 a2);
s16 vehicle_navi_blink;
void sprite_set_clut_entry(s32 arg0, s32 arg1, s32 arg2);
void sprite_fill_clut(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s16 mail_wrap_angle(s16 a);
s32 ratan2(s32 y, s32 x);
extern s32 D_801E6DB4[];
extern CarState vehicle_car_state;
s16 vehicle_car_stopped_input(void);
s32 player_update_map(PlayerStatus *arg0);
void vehicle_navi_update(Player *arg0, Unk_801AC578 *arg1);
s16 vehicle_car_turn_sfx_on;
s16 thing_car_exit_prompt_on;
s32 thing_car_speed_div;
s32 roadmap_get_state(void);
void GsSetLsMatrix(void *m);
void RotTrans(void *v0, s32 *v1, s32 *flag);
s32 rsin(s32 a);
s32 rcos(s32 a);

INCLUDE_RODATA("asm/nonmatchings/game/801AA360", D_80171A78);

INCLUDE_RODATA("asm/nonmatchings/game/801AA360", vehicle_str_file);

INCLUDE_RODATA("asm/nonmatchings/game/801AA360", D_80171AA8);

void vehicle_car_drive(Player *arg0) {
    Unk_801AA8DC_10 sv;
    s32 flag;
    Unk_801E032C *p = D_801E032C[0];
    CarState *q = &vehicle_car_state;
    s32 k;
    s32 v;
    s32 s;
    s16 sgn;
    s16 a;
    s32 sn;
    s32 cs;
    s32 t;
    s32 ang;

    q->stopped = 0;
    vehicle_navi_update((Player *)p, (Unk_801AC578 *)arg0);
    sv.unk0 = 0;
    sv.unk2 = 0;
    sv.unk4 = (q->steer << 12) / 360;
    RotMatrix(&sv, p->unk6C);
    p->unk68 = 0;
    k = thing_car_speed_div;
    if (q->unk2 != 0) {
        k = thing_car_speed_div * 3;
    }
    if (q->gear == 1) {
        v = q->brake * 30 + 800;
        if (v > 6500) {
            v = 6500;
        }
        if (q->throttle != 0) {
            v -= q->throttle * 45;
        }
        if (v < 800) {
            v = 800;
        }
        s = (v - 800) * 347436 / (k * 55086);
    } else if (q->gear == -1) {
        v = q->throttle * 30 + 800;
        if (v > 6500) {
            v = 6500;
        }
        if (q->brake != 0) {
            v -= q->brake * 45;
        }
        if (v < 800) {
            v = 800;
        }
        s = -((v - 800) * 347436) / (k * 72566);
    } else {
        s = 0;
    }
    s = ((s << 12) / 4) >> 12;
    sgn = 0;
    q->speed = s * D_801E6DB4[0];
    if (q->steer != 0) {
        if (q->steer > 0) {
            sgn = 1;
        } else {
            sgn = -1;
        }
    }
    a = q->steer < 0 ? -q->steer : q->steer;
    ang = (a << 12) / 360;
    sn = rsin(ang);
    cs = rcos(ang);
    t = (sn << 12) / cs;
    if (t == 0) {
        q->unk18 = 0;
    } else {
        q->unk18 = 0xFE000 / t;
    }
    if (q->speed == 0) {
        q->stopped = 1;
        q->unk18 = 0;
        q->unk14 = 0;
        vehicle_car_turn_sfx_on = 0;
    } else {
        arg0->unk3C = 1;
        t = (sgn * q->unk18 * cs) >> 12;
        GsSetLsMatrix(&p->unk1C);
        sv.unk0 = t;
        sv.unk2 = 0;
        sv.unk4 = -0x98;
        RotTrans(&sv, &q->unk5C, &flag);
        sv.unk0 = 0;
        sv.unk2 = 0;
        sv.unk4 = -0x98;
        RotTrans(&sv, &q->unk4C, &flag);
        q->unk14 = 0;
        if (q->unk18 != 0) {
            q->unk14 = (sgn * ratan2(s, q->unk18) * 360) >> 12;
            if (q->unk14 == 0) {
                q->unk14 = 1;
            }
        }
        if (s >= 25 && a >= 40 && vehicle_car_turn_sfx_on == 0) {
            vehicle_car_turn_sfx_on = 1;
            sound_se_play(0x1B);
        } else {
            vehicle_car_turn_sfx_on = 0;
        }
    }
    if (q->stopped != 0) {
        if (roadmap_get_state() != 0 || mail_menu_get_state() != 0) {
            if (thing_car_exit_prompt_on != 0) {
                thing_car_exit_prompt_on = 0;
            }
        } else if (thing_car_exit_prompt_on == 0) {
            /* " 7クルマ1から降りる     3○" */
            text_show(" 7\203N\203\213\203}1\202\251\202\347\215~\202\350\202\351     3\201\233", 1, -1, 0, -1, 0, 1);
            thing_car_exit_prompt_on = 1;
        }
    } else if (thing_car_exit_prompt_on != 0) {
        text_close();
        thing_car_exit_prompt_on = 0;
    }
}

void vehicle_train_place(void) {
    Unk_801AA8DC_10 sv;
    Player *q = player_status_player[0];
    TrainState *g = &vehicle_train_state;
    Thing *p = thing_find(2, 0);

    if (p != NULL) {
        p->active = 1;
        p->pos_x = 0xF0A;
        p->animate = 0;
        p->pos_y = 0;
        p->pos_z = 0x3E80;
        p->rot_x = 0;
        p->rot_y = 0;
        p->rot_z = 0;
        if (g->direction == 0) {
            p->pos_x = -0xF0A;
            p->rot_y = 180;
        }
        p->coord_tx = p->pos_x - q->cell_x * 12500;
        p->coord_ty = p->pos_y + q->cell_y * 32000;
        p->coord_tz = p->pos_z - q->cell_z * 12500;
        sv.unk0 = (p->rot_x << 12) / 360;
        sv.unk2 = (p->rot_y << 12) / 360;
        sv.unk4 = (p->rot_z << 12) / 360;
        RotMatrix(&sv, p->coord_m);
        p->coord_flg = 0;
    }
    g->unkA = 1;
    g->motion = 0;
    g->door_state = 1;
}

void vehicle_train_arrive(s16 arg0, s16 arg1) {
    Unk_801AA8DC_10 sv;
    Rect rect;
    Player *q = player_status_player[0];
    TrainState *g = &vehicle_train_state;
    Thing *p = thing_find(2, 0);
    VehicleSprite *a;
    Unk_801AC55C_1C *r;
    s16 w;
    u16 h;

    if (p != NULL && p->active == 0) {
        p->animate = 1;
        p->active = 1;
        p->pos_x = 0xF0A;
        p->pos_z = -0x3E80;
        p->pos_y = 0;
        p->rot_x = 0;
        p->rot_y = 0;
        p->rot_z = 0;
        if (arg0 == 0) {
            p->pos_x = -0xF0A;
            p->pos_z = 0xBB80;
            p->rot_y = 180;
        }
        p->coord_tx = p->pos_x - q->cell_x * 12500;
        p->coord_ty = p->pos_y + q->cell_y * 32000;
        p->coord_tz = p->pos_z - q->cell_z * 12500;
        sv.unk0 = (p->rot_x << 12) / 360;
        sv.unk2 = (p->rot_y << 12) / 360;
        sv.unk4 = (p->rot_z << 12) / 360;
        RotMatrix(&sv, p->coord_m);
        p->coord_flg = 0;
        g->motion = 3;
        g->direction = arg0;
        g->door_state = 0;
        g->station = arg1;
        g->speed = 0;
        g->stop_timer = -1;
    }
    a = sprite_find(0x408);
    if (a != NULL) {
        r = a->tim;
        w = a->cell_w >> r->unk14;
        h = a->cell_h;
        rect.x = r->unk0;
        rect.y = a->tim->unk2;
        rect.w = w;
        rect.h = h;
        MoveImage(&rect, 0x2F0, 0x20);
    }
    sound_se_play(0x1E);
}

void vehicle_train_update(Thing *arg0) {
    Player *q = player_status_player[0];
    TrainState *g = &vehicle_train_state;
    VehicleSprite *p;
    u16 m;
    s32 d;

    if (g->direction != 0) {
        m = g->motion;
        if (m == 3) {
            d = (16000 - arg0->pos_z) / 100 + 5;
            arg0->pos_z += d * D_801E6DB4[0];
            if (arg0->pos_z >= 16000) {
                arg0->animate = 0;
                arg0->pos_z = 16000;
                g->motion = 0;
                g->stop_timer = 2;
                p = sprite_find(0x408);
                if (p == NULL) {
                    g->door_state = 1;
                } else {
                    Unk_801AC70C *e;
                    s32 n;

                    e = kaj_tss_alloc(4);
                    e->unk22 = 7;
                    e->unk24 = 0;
                    n = p->columns * p->rows;
                    e->unk28 = 1;
                    e->unk26 = n - 1;
                    g->door_state = 3;
                    e->unk2C = 0x19;
                    e->unk30 = vehicle_train_door_frame;
                    e->unk34 = vehicle_train_door_last;
                    e->unk38 = vehicle_train_door_last;
                    *e->unk3C = p;
                    g->door_task = kaj_tss_start(e);
                    sound_se_play(0xB);
                }
            }
        } else if (m == 1) {
            d = (arg0->pos_z - 16000) / 100 + 5;
            arg0->pos_z += d * D_801E6DB4[0];
            if (arg0->pos_z > 47999) {
                arg0->animate = 0;
                arg0->active = 0;
                g->motion = 2;
            }
        }
    } else {
        m = g->motion;
        if (m == 3) {
            d = (arg0->pos_z - 16000) / 100 + 5;
            arg0->pos_z -= d * D_801E6DB4[0];
            if (arg0->pos_z <= 16000) {
                arg0->pos_z = 16000;
                arg0->animate = 0;
                g->motion = 0;
                g->stop_timer = 2;
                p = sprite_find(0x408);
                if (p == NULL) {
                    g->door_state = 1;
                } else {
                    Unk_801AC70C *e;
                    s32 n;

                    e = kaj_tss_alloc(4);
                    e->unk22 = 7;
                    e->unk24 = 0;
                    n = p->columns * p->rows;
                    e->unk28 = 1;
                    e->unk26 = n - 1;
                    g->door_state = 3;
                    e->unk2C = 0x19;
                    e->unk30 = vehicle_train_door_frame;
                    e->unk34 = vehicle_train_door_last;
                    e->unk38 = vehicle_train_door_last;
                    *e->unk3C = p;
                    g->door_task = kaj_tss_start(e);
                    sound_se_play(0xB);
                }
            }
        } else if (m == 1) {
            d = (16000 - arg0->pos_z) / 100 + 5;
            arg0->pos_z -= d * D_801E6DB4[0];
            if (arg0->pos_z < -15999) {
                arg0->animate = 0;
                arg0->active = 0;
                g->motion = 2;
            }
        }
    }
    arg0->coord_tx = arg0->pos_x - q->cell_x * 12500;
    arg0->coord_ty = arg0->pos_y + q->cell_y * 32000;
    arg0->coord_tz = arg0->pos_z - q->cell_z * 12500;
    arg0->coord_flg = 0;
}

void vehicle_train_exit_prompt(s16 arg0) {
    Player *q = player_status_player[0];
    EventState *d = &event_state;
    TrainState *p = &vehicle_train_state;

    if (arg0 != 0) {
        if (p->unkC == 0) {
            if ((p->direction != 0 && p->trigger == 0x200010) || (p->direction == 0 && p->trigger == 0x200020)) {
                p->unkC = 1;
                d->trigger = p->trigger;
                d->trigger_type = (u8)(p->trigger >> 16);
                if (d->state != 2) {
                    d->state = 2;
                }
                if (!(q->flags & 4)) {
                    q->flags |= 4;
                }
                if (q->vehicle_mode == 2) {
                    /* " 7電車1から降りる      3○" */
                    text_show(" 7\223d\216\3241\202\251\202\347\215~\202\350\202\351      3\201\233", 1, -1, 8, -1, 0, 1);
                } else if (q->vehicle_mode == 3) {
                    /* " 7地下鉄1から降りる     3○" */
                    text_show(" 7\222n\211\272\223S1\202\251\202\347\215~\202\350\202\351     3\201\233", 1, -1, 8, -1, 0, 1);
                }
            }
        }
    } else if (p->unkC != 0) {
        text_close();
        action_reset(1);
        p->unkC = 0;
        if (q->flags & 4) {
            q->flags &= ~4;
        }
    }
}

s16 vehicle_train_get_off(s16 arg0) {
    TrainState *p;
    u16 v = player_status_player[0]->vehicle_mode;

    p = &vehicle_train_state;

    if (v == 3) {
        arg0 = 0;
        if (p->direction != 0) {
            mail_goto_building(1, vehicle_str_sb1, 9, 0x41, 1, 0x5A, 6, p->station + 0xF90000, 0);
        } else {
            mail_goto_building(1, vehicle_str_sb1, 9, 0x41, 2, -0x5A, 6, p->station + 0xF90000, 0);
        }
    } else if (v == 2) {
        arg0 = 0;
        if (p->direction != 0) {
            mail_goto_building(1, vehicle_str_rw1, 9, 0x41, (s16)(p->station * 2 - 1), 0x5A, 0x11, p->station + 0xF60000, 0);
        } else {
            mail_goto_building(1, vehicle_str_rw1, 9, 0x41, (s16)(p->station * 2), -0x5A, 0x11, p->station + 0xF60000, 0);
        }
    }
    return arg0;
}

s16 vehicle_train_end_of_line(s16 arg0) {
    SceneRequest *r = &scene_request;
    TrainState *p;
    u16 v = player_status_player[0]->vehicle_mode;

    p = &vehicle_train_state;
    if (v == 3) {
        if (p->direction != 0) {
            if (p->station == 6) {
                mail_goto_building(1, vehicle_str_sb1, 9, 0x41, 1, 0x5A, 6, p->station + 0xF90000, 0);
                arg0 = 0;
                r->change = 1;
            }
        } else {
            if (p->station == 1) {
                mail_goto_building(1, vehicle_str_sb1, 9, 0x41, 2, -0x5A, 6, p->station + 0xF90000, 0);
                arg0 = 0;
                r->change = 1;
            }
        }
    } else if (v == 2) {
        if (p->direction != 0) {
            if (p->station == 3) {
                mail_goto_building(1, vehicle_str_rw1, 9, 0x41, 5, 0x5A, 0x11, p->station + 0xF60000, 0);
                arg0 = 0;
                r->change = 1;
            }
        } else {
            if (p->station == 1) {
                mail_goto_building(1, vehicle_str_rw1, 9, 0x41, 2, -0x5A, 0x11, p->station + 0xF60000, 0);
                arg0 = 0;
                r->change = 1;
            }
        }
    }
    return arg0;
}

void vehicle_car_follow_player(Thing *arg0, s32 arg1) {
    Unk_801AA8DC_10 sv;
    s32 y;
    s16 found = 0;
    s16 f = arg1;
    PlayerStatus *g = &player_status;
    Player *q = g->player;

    if (q->unk4 == 9999) {
        y = 0;
        if (block_find_surface(q->unk0 - q->cell_x * 12500, q->unk8 - q->cell_z * 12500, &y, 1) != 0) {
            found = 1;
            y -= q->cell_y * 32000;
            q->unk4 = y;
        }
    }
    if (found || f != 0) {
        arg0->pos_x = q->unk0;
        arg0->pos_y = q->unk4;
        arg0->pos_z = q->unk8;
        arg0->rot_x = q->unk10;
        arg0->rot_y = q->unk12;
        arg0->rot_z = q->unk14;
        arg0->coord_tx = arg0->pos_x - q->cell_x * 12500;
        arg0->coord_ty = arg0->pos_y + q->cell_y * 32000;
        arg0->coord_tz = arg0->pos_z - q->cell_z * 12500;
        sv.unk0 = (arg0->rot_x << 12) / 360;
        sv.unk2 = (arg0->rot_y << 12) / 360;
        sv.unk4 = (arg0->rot_z << 12) / 360;
        RotMatrixZXY(&sv, arg0->coord_m);
        arg0->coord_flg = 0;
        if (f != 0) {
            arg0->active = 1;
            arg0->block = block_find_at(arg0->pos_x, arg0->pos_y, arg0->pos_z);
            g->vehicle = (VehicleSprite *)arg0;
        }
    }
}

void vehicle_navi_update(Player *arg0, Unk_801AC578 *arg1) {
    CarNavi *p = (CarNavi *)vehicle_navi;
    s32 dx;
    s32 dz;
    s32 d;
    s16 a;
    s32 n;

    if (mail_menu_get_state() == 0 && p->active != 0 && p->dest_sprite != NULL && p->unk10 != NULL) {
        dx = vehicle_navi_dest_xz[p->dest * 2] - arg1->unk60;
        dz = vehicle_navi_dest_xz[p->dest * 2 + 1] - arg1->unk68;
        d = SquareRoot0(dx * dx + dz * dz);
        if (d < 25) {
            if (vehicle_navi_blink != 0) {
                sprite_set_clut_entry(4, 0xE, 0x14F);
            } else {
                sprite_set_clut_entry(4, 0xE, 0);
            }
            vehicle_navi_blink = 1 - vehicle_navi_blink;
        } else if (vehicle_navi_blink != 0) {
            sprite_set_clut_entry(4, 0xE, 0x14F);
        }
        if (d >= p->start_dist) {
            d = 12;
        } else {
            d = ((u32)(d * 0xB000) / p->start_dist + 1) >> 12;
        }
        sprite_fill_clut(4, 1, 12, 0);
        sprite_fill_clut(4, 1, d, 0x1F);
        a = mail_wrap_angle(ratan2(dx, dz) * 0x1680 >> 16);
        n = (mail_wrap_angle(a - mail_wrap_angle(arg0->unk12)) + 23) / 45;
        if (n >= 8) {
            n = 0;
        }
        p->unk10->cell_col = n % 4;
        p->unk10->cell_row = n / 4;
    }
}

void vehicle_navi_open_menu(void) {
    CarNavi *p = (CarNavi *)vehicle_navi;

    sound_se_play(0x13);
    if (p->unk10 != NULL) {
        p->unk10->visible = 0;
        p->unk10 = NULL;
    }
    if (p->dest_sprite != NULL) {
        p->dest_sprite->visible = 0;
        p->dest_sprite = NULL;
    }
    mail_menu_open(p->unk2, 0x40B, 0x40C, 0xF, 6, NULL, 4, 0x2969, 0x2BFF);
    if (p->unk2 != 0) {
        p->unk2 = 0;
    }
}

s16 vehicle_car_stopped_input(void) {
    RoadMap *q = &roadmap_state;
    CarNavi *p = (CarNavi *)vehicle_navi;
    s16 r = mail_menu_get_state();

    if (r == 1) {
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            vehicle_navi[0] = 1;
            sound_se_play(0x11);
            mail_menu_close();
        } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            vehicle_navi[0] = 0;
            sound_se_play(8);
            mail_menu_close();
        } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
            p->dest = mail_menu_move(1);
        } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
            p->dest = mail_menu_move(0);
        }
        return 0;
    }
    if (r == 0) {
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            sound_se_play(0x11);
            return 1;
        }
        if (q->mode == 0 && !(kaj_system.pad_prev & 0x800) && (kaj_system.pad_now & 0x800)) {
            text_close();
            vehicle_navi_open_menu();
        }
        return -1;
    }
    return 0;
}

s16 vehicle_car_input(PlayerStatus *arg0, s32 arg1) {
    CarState *q = &vehicle_car_state;
    Player *o = arg0->player;
    s16 r;
    s16 f0;
    s16 f1;
    s16 f2;
    s16 f3;

    if (vehicle_car_state.stopped != 0) {
        if ((s16)player_update_map(arg0) != 0) {
            return 0;
        }
        r = vehicle_car_stopped_input();
        if (r >= 0) {
            return r;
        }
    }
    f0 = 0;
    f1 = 0;
    f3 = 0;
    f2 = 0;
    if (arg1 & 0x1000) {
        if (q->look_pitch < 20) {
            o->unk3C = 1;
            q->look_pitch += D_801E6DB4[0];
            if (q->look_pitch > 20) {
                q->look_pitch = 20;
            }
        }
    } else if (arg1 & 0x4000) {
        if (q->look_pitch > -20) {
            o->unk3C = 1;
            q->look_pitch -= D_801E6DB4[0];
            if (q->look_pitch < -20) {
                q->look_pitch = -20;
            }
        }
    } else if (arg1 & 0x8000) {
        if (q->look_yaw > -65) {
            o->unk3C = 1;
            q->look_yaw -= D_801E6DB4[0];
            if (q->look_yaw < -65) {
                q->look_yaw = -65;
            }
        }
    } else if (arg1 & 0x2000) {
        if (q->look_yaw < 65) {
            o->unk3C = 1;
            q->look_yaw += D_801E6DB4[0];
            if (q->look_yaw > 65) {
                q->look_yaw = 65;
            }
        }
    }
    if (arg1 & 4) {
        f1 = 1;
    } else if (arg1 & 8) {
        f0 = 1;
    }
    if (arg1 & 0x10) {
        f2 = 1;
        if (q->speed == 0 && q->gear != 1) {
            q->gear = 1;
            q->brake = 0;
            q->throttle = 0;
        }
    } else if (arg1 & 0x40) {
        f3 = 1;
        if (q->speed == 0 && q->gear != -1) {
            q->gear = -1;
            q->brake = 0;
            q->throttle = 0;
        }
    }
    if (f1) {
        if (q->steer > -45) {
            q->steer -= D_801E6DB4[0];
            if (q->steer < -45) {
                q->steer = -45;
            }
        }
    } else if (!f0 && q->speed != 0 && q->steer < 0) {
        q->steer += D_801E6DB4[0];
        if (q->steer > 0) {
            q->steer = 0;
        }
    }
    if (f0) {
        if (q->steer < 45) {
            q->steer += D_801E6DB4[0];
            if (q->steer > 45) {
                q->steer = 45;
            }
        }
    } else if (!f1 && q->speed != 0 && q->steer > 0) {
        q->steer -= D_801E6DB4[0];
        if (q->steer < 0) {
            q->steer = 0;
        }
    }
    if (f2) {
        if (q->brake < 256) {
            q->brake += D_801E6DB4[0];
            if (q->brake > 256) {
                q->brake = 256;
            }
        }
    } else if (q->brake > 0) {
        q->brake -= D_801E6DB4[0];
        if (q->brake < 0) {
            q->brake = 0;
        }
    }
    if (f3) {
        if (q->throttle < 256) {
            q->throttle += D_801E6DB4[0];
            if (q->throttle > 256) {
                q->throttle = 256;
            }
        }
    } else if (q->throttle > 0) {
        q->throttle -= D_801E6DB4[0];
        if (q->throttle < 0) {
            q->throttle = 0;
        }
    }
    return 0;
}

void vehicle_load_data(void) {
    switch (player_status_player[0]->vehicle_mode) {
    case 1:
        object_load_res(3, -1);
        break;
    case 2:
        object_load_res(0xB, 2);
        break;
    case 3:
        object_load_res(0xA, 2);
        break;
    }
}

void vehicle_create(Vehicle **arg0, u32 arg1) {
    *arg0 = kaj_malloc(0xC4);
    if (*arg0 == NULL) {
        kaj_abend(3, D_80171A78, vehicle_str_file, 0x64);
    }
    (*arg0)->model0 = NULL;
    (*arg0)->model1 = NULL;
    (*arg0)->data = NULL;
    (*arg0)->data = kaj_malloc(arg1);
    if ((*arg0)->data == NULL) {
        kaj_abend(3, D_80171AA8, vehicle_str_file, 0x6C);
    }
}

void vehicle_init(Unk_801E032C *arg0) {
    switch (player_status_player[0]->vehicle_mode) {
    case 1:
        thing_car_init(arg0, player_status_player[0]);
        break;
    case 2:
    case 3:
        thing_train_init(arg0, player_status_player[0]);
        break;
    }
    D_801E032C[0] = arg0;
}

void vehicle_free(void) {
    SceneTables *p = &object_scene_tables;
    Vehicle *e = p->unk54;
    if (e != NULL) {
        if (e->unk0 == 1) {
            thing_car_get_out(e);
        }
        free3(e->model0);
        if (e->model1 != NULL) {
            free3(e->model1);
        }
        free3(e->data);
        free3(e);
        p->unk54 = NULL;
        sound_se_pop();
    }
}

INCLUDE_ASM("asm/nonmatchings/game/801AA360", vehicle_draw);

void vehicle_set_origin(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801E032C *p = D_801E032C[0];
    if (p != NULL) {
        p->unk18 = 0;
        p->unk30 = p->unk4 - arg0;
        p->unk34 = p->unk8 - arg1;
        p->unk38 = p->unkC - arg2;
    }
}

void vehicle_update(void) {
    s32 v = player_status_player[0]->vehicle_mode;
    if (v == 1) {
        vehicle_car_drive(player_status_player[0]);
    } else if (v >= 2) {
        if (v < 4) {
            thing_train_update(player_status_player[0]);
        }
    }
}

void vehicle_car_place(void) {
    Thing *p = thing_find(0, 0);
    if (p == NULL) {
        kaj_abend(5, "My Car Object not Found", vehicle_str_file, 0x421);
    }
    vehicle_car_follow_player(p, 1);
}

void vehicle_car_release(void) {
    PlayerStatus *p = &player_status;
    p->vehicle->visible = 0;
    p->vehicle = NULL;
}

void vehicle_navi_show(Unk_801AC578 *arg0, s16 arg1, s16 arg2) {
    CarNavi *p = (CarNavi *)vehicle_navi;
    s32 dx;
    s32 dz;

    if (arg1 != 0) {
        p->dest_sprite = sprite_find(4);
        p->unk10 = sprite_find(0x406);
        if (p->unk10 != NULL) {
            p->unk10->x = 0x90;
            p->unk10->y = 0x68;
            p->unk10->visible = 1;
        }
        if (p->dest_sprite != NULL) {
            p->dest_sprite->visible = 1;
            p->dest_sprite->cell_col = 0;
            p->dest_sprite->cell_row = p->dest;
        }
        dx = vehicle_navi_dest_xz[p->dest * 2] - arg0->unk60;
        dz = vehicle_navi_dest_xz[p->dest * 2 + 1] - arg0->unk68;
        if (arg2 != 0) {
            p->start_dist = SquareRoot0(dx * dx + dz * dz);
        }
    } else {
        if (p->unk10 != NULL) {
            p->unk10->visible = 0;
            p->unk10 = NULL;
        }
        if (p->dest_sprite != NULL) {
            p->dest_sprite->visible = 0;
            p->dest_sprite = NULL;
        }
    }
}

void vehicle_navi_set_enabled(s16 arg0) {
    vehicle_navi[0] = arg0;
    if (arg0 != 0) {
        sound_se_play(0x11);
    } else {
        sound_se_play(8);
    }
    mail_menu_close();
}

void vehicle_train_set_doors(s16 arg0) {
    TrainState *g = &vehicle_train_state;
    VehicleSprite *p;
    Unk_801AC70C *e;
    s32 n;

    p = sprite_find(0x408);
    if (p == NULL) {
        if (arg0 != 0) {
            g->door_state = 1;
        } else {
            g->door_state = 0;
            g->motion = 1;
            thing_set_animate(2, 0, 1);
        }
        return;
    }
    e = kaj_tss_alloc(4);
    e->unk22 = 7;
    if (arg0 != 0) {
        e->unk24 = 0;
        n = p->columns * p->rows;
        e->unk28 = 1;
        e->unk26 = n - 1;
        g->door_state = 3;
    } else {
        n = p->columns * p->rows;
        e->unk26 = 0;
        e->unk28 = -1;
        e->unk24 = n - 1;
        g->door_state = 2;
    }
    e->unk2C = 0x19;
    e->unk30 = vehicle_train_door_frame;
    e->unk34 = vehicle_train_door_last;
    e->unk38 = vehicle_train_door_last;
    *e->unk3C = p;
    g->door_task = kaj_tss_start(e);
    sound_se_play(0xB);
}

void vehicle_train_hide(void) {
    TrainState *q = &vehicle_train_state;
    Thing *p = thing_find(2, 0);
    if (p != NULL) {
        p->animate = 0;
        p->active = 0;
    }
    q->stop_timer = -1;
}

void vehicle_train_door_frame(Unk_801AC70C *arg0) {
    Rect rect;
    VehicleSprite *a;
    s32 n;
    Unk_801AC55C_1C *b;
    s32 w;
    s32 h;
    s16 x;
    s16 y;
    a = *arg0->unk3C;
    b = a->tim;
    w = a->cell_w >> b->unk14;
    h = a->cell_h;
    n = arg0->unk24;
    x = b->unk0 + w * (n / 4);
    y = b->unk2 + h * (n % 4);
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    MoveImage(&rect, 0x2F0, 0x20);
}

void vehicle_train_door_last(Unk_801AC70C *arg0) {
    TrainState *p = &vehicle_train_state;
    Rect rect;
    VehicleSprite *a = *arg0->unk3C;
    s32 n = arg0->unk24;
    Unk_801AC55C_1C *b = a->tim;
    s32 w = a->cell_w >> b->unk14;
    s32 h = a->cell_h;
    s16 x = b->unk0 + w * (n / 4);
    s16 y = b->unk2 + h * (n % 4);
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    MoveImage(&rect, 0x2F0, 0x20);
    p->door_task = -1;
}

void vehicle_train_init_state(void) {
    TrainState *p = &vehicle_train_state;
    p->unk18 = 2;
    p->unk1A = 7;
}
