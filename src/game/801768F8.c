#include "common.h"

typedef struct {
    u16 unk0;
    u16 unk2;
} Unk_80174A14;
typedef struct {
    void *unk0;
} Unk_80174BC8;
typedef struct {
    void *unk0;
    s32 unk4;
    Unk_80174BC8 *unk8;
} Unk_80174CB8;
typedef struct {
    Unk_80174A14 *unk0;
    s32 unk4;
    Unk_80174CB8 *unk8;
} Unk_80174B10;
typedef struct Unk_801CCB70 {
    void *unk0;
    struct Unk_801CCB70 *unk4;
    Unk_80174B10 *unk8;
} Unk_801CCB70;
typedef struct { Unk_801CCB70 *unk0; Unk_801CCB70 *unk4; Unk_801CCB70 *unk8; s32 unkC; } Unk_801DFE54;
Unk_801DFE54 *action_queue;
void kaj_ll_insert_before(Unk_801DFE54 *a0, s32 a1);
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_80174F54;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; u8 unkA; u8 unkB; s16 unkC; u8 unkE; u8 unkF; s16 unk10; u16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s16 unk38; s16 unk3A; s16 unk3C; s16 unk3E; s16 unk40; s16 unk42; u8 unk44; u8 unk45; s16 unk46; s32 unk48; } Unk_801762F4;
typedef struct { u16 unk0; s16 unk2; s32 unk4; s16 unk8; u16 unkA; u8 unkC[0xC0]; } Unk_801767D4;
typedef struct {
    u16 unk0;
    s16 unk2;
    u16 unk4;
    s16 unk6;
    s16 unk8;
    u16 unkA;
    s16 unkC;
    u16 unkE;
    s16 unk10;
    u16 unk12;
    u16 unk14;
    s16 unk16;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} Unk_80176890;
typedef struct {
    s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14;
    s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34;
    Unk_80174F54 *unk38; Unk_801762F4 *unk3C; Unk_801767D4 *unk40; Unk_80176890 *unk44;
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
void free3(void *ptr);
s32 block_find_at(s32 a0, s32 a1, s32 a2);
Unk_801767D4 *npc_find_body(s16 arg0);
typedef struct { s16 unk0; s16 unk2; s16 unk4[2]; u8 unk8[0x28]; s16 unk30; s16 unk32[8]; s16 unk42; s16 unk44; s16 unk46; s16 unk48; u8 unk4A[2]; s32 unk4C; } Unk_801E0768;
extern Unk_801E0768 *D_801E0768[];
typedef struct {
    s16 unk0;
    s16 unk2;
    u16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Unk_80173954;
typedef struct {
    u8 unk0[4];
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u16 unk16;
    u8 unk18[0x18];
    void *unk30;
    u8 unk34[0x8];
    s32 unk3C;
    u8 unk40[0x14];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
} Unk_8018E56C;
typedef struct {
    u8 unk0[4];
    s16 unk4;
} Unk_80176370;
Unk_8018E56C *mod_find(u16 arg0);
void mod_draw(s32 arg0, Unk_8018E56C *arg1, u16 arg2);
void kaj_ll_remove_to_prev(Unk_801DFE54 *arg0);
s16 kaj_ll_at_tail(Unk_801DFE54 *arg0);
Unk_801DFE54 *action_set_list;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
} Unk_80174D6C;
Unk_80174B10 *action_run_set(Unk_80174B10 *arg0, s32 arg1, s32 arg2);
typedef struct {
    u8 unk0[0x6];
    s16 unk6;
    u8 unk8[0x2];
    s16 unkA;
    u8 unkC[0x2];
    s16 unkE;
    u16 unk10;
    u16 unk12;
} Unk_801DFFE8;
extern Unk_801DFFE8 D_801DFFE8;
void text_release_cmd(void);
void *memset(void *dst, s32 c, u32 n);
typedef struct {
    u8 unk0[0x40];
    s32 unk40;
    u8 unk44[0x10];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0xC];
    s16 unk6C;
    s16 unk6E;
    u8 unk70[0x2];
    s16 unk72;
    s16 unk74;
    s16 unk76;
} Unk_801E076C;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_80174FFC;
extern Unk_801E076C *D_801E076C[];
void mod_setup(Unk_8018E56C *arg0, s32 arg1, s32 arg2, s32 arg3);
void RotMatrix(Unk_80174FFC *arg0, void *arg1);
void action_place_npc(Unk_801762F4 *arg0, Unk_8018E56C *arg1);
Unk_80174B10 *action_find_set(s16 arg0);
void text_close(void);
void GsSetLsMatrix(void *m);
s16 block_point_on_model(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4);
Unk_801762F4 *npc_find(s16 arg0, u16 arg1);
s16 mail_wrap_angle(s16 a);
s32 ratan2(s32 y, s32 x);
s32 mail_angle_to_dir4(s16 a);
extern s16 ai_probe_angle[];
s32 rsin(s32 a);
s32 rcos(s32 a);
s16 ai_check_line(Unk_801762F4 *arg0, Unk_80174F54 *arg1, s32 arg2);
s16 ai_try_move(Unk_801762F4 *arg0, Unk_80174F54 *arg1, s16 arg2);
extern s32 D_801E6DB4[];
Unk_8018E56C *ai_cur_model;
typedef struct {
    u8 unk0[0x8];
    s16 unk8;
    u8 unkA[0x4];
    u16 unkE;
    s32 unk10;
    u8 unk14[0x4];
    s32 unk18;
    u8 unk1C[0x68];
    void *unk84;
    s32 unk88;
} Unk_801DFC60;
Unk_80176890 *npc_find_stats(s16 arg0);
s16 ai_find_target(Unk_801762F4 *arg0, s16 arg1);
s16 ai_decide_fire(Unk_801762F4 *arg0);
void ai_face_player(Unk_801762F4 *arg0);
extern Unk_80176890 D_801D7328;
extern Unk_801767D4 ai_default_body;
Unk_801DFC60 *ai_cur_block;
s32 ai_cur_grid;
Unk_80176890 *ai_cur_stats;
Unk_801767D4 *ai_cur_body;
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} Unk_80173250;
typedef struct {
    Unk_80173250 *unk0;
    s32 unk4;
    char **unk8;
} Unk_80173054;
s32 atoi(char *s);
typedef struct {
    u8 unk0[0x2E];
    s16 unk2E;
    u8 unk30[2];
    s16 unk32;
    u8 unk34[0x18];
    Unk_801762F4 *unk4C;
    u8 unk50[8];
    Unk_801E0768 *unk58;
} Unk_801E0710;
extern Unk_801E0710 D_801E0710;
s32 rand(void);
void player_add_skill_exp(s16 arg0, s16 arg1);
void player_add_exp(s32 arg0);
void event_set_blink(s16 arg0, s16 arg1);
extern s16 ai_dir_angle[];
s16 mail_angle_to_dir8(s16 a);
void ai_turn_step(Unk_801762F4 *arg0);
void ai_move_toward(Unk_801762F4 *arg0, s16 arg1, s32 arg2, s32 arg3);
s16 ai_in_aim_cone(Unk_801762F4 *arg0, s16 arg1, s16 arg2);
s16 ai_heading_to(Unk_801762F4 *arg0, s16 arg1);
s32 ai_player_in_front(Unk_801762F4 *arg0);
s16 D_801DFC74;
s16 D_801DFC76;
void ai_walk(Unk_801762F4 *arg0, s16 arg1, s32 arg2);
s32 ai_step_back(Unk_801762F4 *arg0, s32 arg1);
s32 ai_sidestep(Unk_801762F4 *arg0, s32 arg1);
void mod_set_anim(void *arg0, s16 arg1, s16 arg2);
void sound_se_stop(s32 arg0);
u16 npc_get_radius(Unk_801762F4 *arg0);
extern s16 ai_dir_reverse[];
extern s16 ai_quadrant_dir[4];
extern u16 D_801E03E6[];
s32 abs(s32 x);
void player_take_hit(Unk_801762F4 *arg0, u16 arg1, s32 arg2);
void sound_se_play(s32 arg0);
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u8 *unk8;
} Unk_801DFC64;
s32 SquareRoot0(s32 a);
s16 npc_find_at_point(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 block_model_surface(void *arg0, s32 arg1, s32 arg2, s32 arg3);

static inline s32 cvx(s32 x) {
    s32 d = x - ai_cur_block->unk10;
    s32 t = d >> 8;
    s32 o = ((Unk_801DFC64 *)ai_cur_grid)->unk0;
    return (d & 0xFF) ? t + 1 + o : t + o;
}

static inline s32 cvz(s32 z) {
    s32 d = z - ai_cur_block->unk18;
    s32 t = d >> 8;
    s32 o = ((Unk_801DFC64 *)ai_cur_grid)->unk2;
    return (d & 0xFF) ? t + 1 + o : t + o;
}

static inline s32 cell(s32 x, s32 z) {
    Unk_801DFC64 *m = (Unk_801DFC64 *)ai_cur_grid;
    s32 i;
    s32 sh;
    if (x < 0 || x >= m->unk4 || z < 0 || z >= m->unk6) {
        return 1;
    }
    i = z * (m->unk4 >> 2) + (x >> 2);
    sh = (x % 4) * 2;
    return (m->unk8[i] & (3 << sh)) >> sh;
}

static inline s16 pass(s32 v, s32 mode) {
    if (v == 1) {
        return 0;
    }
    if (mode == 1) {
        if (v == 2) {
            return 0;
        }
        if (v != 0) {
            return 1;
        }
        return 0;
    }
    if (mode == 2 && v == 2) {
        return 0;
    }
    return 1;
}

s16 ai_check_line(Unk_801762F4 *arg0, Unk_80174F54 *arg1, s32 arg2) {
    Unk_801E076C *p;
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
    s32 a;
    s16 b;

    if (ai_cur_block == NULL || ai_cur_grid == 0) {
        return 0;
    }
    if ((arg2 & 1) && ai_cur_block->unk8 == 0) {
        return 0;
    }
    mode = 0;
    if (!(arg2 & 2)) {
        mode = 1;
        if (arg2 & 0x10) {
            mode = 2;
        }
    }
    if (arg2 & 4) {
        arg0->unk40 = 0;
    }
    if (arg2 & 8) {
        arg0->unk44 = 0;
        arg0->unk45 = 0;
    }
    x0 = cvx(arg0->unk20);
    z0 = cvz(arg0->unk28);
    if (mode == 0) {
        x1 = cvx(arg1->unk0);
        z1 = cvz(arg1->unk8);
    } else {
        x1 = cvx(arg0->unk20 + arg1->unk0);
        z1 = cvz(arg0->unk28 + arg1->unk8);
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
    if (arg2 & 4) {
        x1 = arg1->unk0 - arg0->unk20;
        d = arg1->unk8 - arg0->unk28;
        arg0->unk40 = SquareRoot0(x1 * x1 + d * d);
        if (arg2 & 8) {
            p = D_801E076C[0];
            a = (ratan2(arg1->unk4 - arg0->unk24, (u16)arg0->unk40) * 0x1680) >> 16;
            arg0->unk45 = abs(a);
            b = abs(p->unk6C - a);
            if (b < 0x100) {
                arg0->unk44 = b;
            } else {
                arg0->unk44 = 0xFF;
            }
        }
    }
    return 1;
}

void ai_turn_step(Unk_801762F4 *arg0) {
    Unk_80174FFC sv;
    s16 d;
    s16 diff;
    s16 step;

    if (arg0->unk3A != arg0->unk3E) {
        diff = arg0->unk3E - arg0->unk3A;
        step = D_801E6DB4[0] * 2;
        d = diff;
        if (arg0->unk3A < arg0->unk3E) {
            if (diff >= 180) {
                d = diff - 360;
            }
        } else {
            if (diff < -179) {
                d = diff + 360;
            }
        }
        if (d > 0) {
            if (step < d) {
                d = step;
            }
        } else {
            if (d < -step) {
                d = -step;
            }
        }
        arg0->unk3A = mail_wrap_angle(arg0->unk3A + d);
        if (ai_cur_model != NULL && ai_cur_model->unk4 != 0) {
            sv.unk0 = (arg0->unk38 << 12) / 360;
            sv.unk2 = (arg0->unk3A << 12) / 360;
            sv.unk4 = (arg0->unk3C << 12) / 360;
            RotMatrix(&sv, ai_cur_model->unk40);
            ai_cur_model->unk3C = 0;
        }
    }
}

s16 ai_heading_to(Unk_801762F4 *arg0, s16 arg1) {
    Unk_801E076C *p = D_801E076C[0];
    Unk_801762F4 *t;
    s32 dx;
    s32 dz;

    if (arg1 == -2) {
        if (!(arg0->unk12 & 0x100)) {
            return 0;
        }
        dx = arg0->unk2C - arg0->unk20;
        dz = arg0->unk34 - arg0->unk28;
    } else if (arg1 == -1) {
        dx = p->unk54 + p->unk72 * 12500 - arg0->unk20;
        dz = p->unk5C + p->unk76 * 12500 - arg0->unk28;
    } else {
        t = npc_find(0, arg1);
        if (t == 0) {
            return 0;
        }
        dx = t->unk20 - arg0->unk20;
        dz = t->unk28 - arg0->unk28;
    }
    return mail_wrap_angle((ratan2(dx, dz) * 360 >> 12) - 180);
}

s32 ai_player_in_front(Unk_801762F4 *arg0) {
    Unk_801E076C *p = D_801E076C[0];
    s32 dx;
    s32 dz;

    dx = p->unk54 + p->unk72 * 12500 - arg0->unk20;
    dz = p->unk5C + p->unk76 * 12500 - arg0->unk28;
    if (dx >= -9999 && dx < 10000 && dz >= -9999 && dz < 10000) {
        return 1;
    }
    switch ((s16)mail_angle_to_dir4(arg0->unk3A - 180)) {
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

s16 ai_find_target(Unk_801762F4 *arg0, s16 arg1) {
    Unk_80174F54 v;
    s16 found;
    u16 min;
    u16 saved;
    s32 best;
    s16 a;
    s16 b;
    s32 i;
    u16 d;
    s16 r;
    Unk_801762F4 *e;
    Unk_801E076C *cam;
    Unk_801E02D8 *g = &D_801E02D8;

    min = 0xFFFF;
    saved = 0;
    found = 0;
    e = g->unk3C;
    cam = D_801E076C[0];
    arg0->unk10 = -2;
    best = -2;
    b = -1;
    arg0->unk40 = 0;
    arg0->unk12 &= ~6;
    a = b;
    if (ai_cur_block->unk8 != 0
        && (D_801DFC74 != 0 || D_801DFC76 != 0 || (s16)ai_player_in_front(arg0) != 0)) {
        v.unk0 = cam->unk54 + cam->unk72 * 12500;
        v.unk4 = cam->unk58 - cam->unk74 * 32000 + 1600;
        v.unk8 = cam->unk5C + cam->unk76 * 12500;
        if (ai_check_line(arg0, &v, 15) != 0) {
            saved = arg0->unk40;
            min = saved;
            arg0->unk12 |= 2;
            a = ai_heading_to(arg0, -1);
            found = 1;
        }
    }
    if (arg1 == 2) {
        arg0->unk3E = ai_heading_to(arg0, -2);
        ai_turn_step(arg0);
        return 0;
    }
    if (g->unk1C > 0) {
        for (i = 0; i < g->unk1C; i++, e++) {
            if (e->unk4 != 0 && e->unk6 != 0 && e->unk0 != arg0->unk0 && e->unkE != 2 && e->unkF != 6
                && e->unk24 == arg0->unk24) {
                v.unk0 = e->unk20;
                v.unk4 = e->unk24;
                v.unk8 = e->unk28;
                if (ai_check_line(arg0, &v, 6) != 0) {
                    d = arg0->unk40;
                    if (d != 0 && d < min) {
                        min = d;
                        best = e->unk0;
                    }
                }
            }
        }
        b = ai_heading_to(arg0, best);
    }
    if (found == 0 && best < 0) {
        return 0;
    }
    if (found != 0) {
        if (best >= 0) {
            r = mail_wrap_angle(a - b);
            if (r < 10 || r > 350) {
                arg0->unk12 |= 4;
            }
        }
        if (arg1 == 1) {
            arg0->unk3E = a;
            ai_turn_step(arg0);
        }
        arg0->unk10 = -1;
        arg0->unk40 = saved;
    } else {
        arg0->unk10 = best;
        arg0->unk40 = 0;
    }
    return 1;
}

s16 ai_try_move(Unk_801762F4 *arg0, Unk_80174F54 *arg1, s16 arg2) {
    Unk_801E076C *cam = D_801E076C[0];
    Unk_80174FFC sv;
    s32 y;
    s32 r;
    s32 x;
    s32 z;
    s32 dx;
    s32 dz;
    s32 t;
    s32 ax;
    s32 s;
    s32 c;

    if (ai_cur_block == NULL) {
        return 0;
    }
    if (!(ai_cur_block->unkE & 1)) {
        return 0;
    }
    arg0->unk12 &= ~0x10;
    ax = arg1->unk0;
    if (ax == 0 && arg1->unk8 == 0) {
        return 1;
    }
    r = ai_cur_body->unkA * 10;
    x = arg0->unk20 + ax - cam->unk72 * 12500;
    z = arg0->unk28 + arg1->unk8 - cam->unk76 * 12500;
    s = r * rsin(arg2) >> 12;
    c = r * rcos(arg2) >> 12;
    if (npc_find_at_point(arg0->unk0, x + s, arg0->unk24, z + c) >= 0) {
        return 0;
    }
    r += 600;
    dx = abs(x - cam->unk54);
    dz = abs(z - cam->unk5C);
    if (dx <= r && dz <= r) {
        arg0->unk12 |= 0x10;
        return arg0->unkE == 1;
    }
    if (block_model_surface(ai_cur_block->unk84, x, z, (s32)&y) == 0) {
        return 0;
    }
    arg0->unk20 += arg1->unk0;
    arg0->unk24 = y - cam->unk74 * 32000;
    arg0->unk28 += arg1->unk8;
    if (ai_cur_model == NULL || ai_cur_model->unk4 == 0) {
        return 0;
    }
    ai_cur_model->unk54 = arg0->unk20 - cam->unk72 * 12500;
    ai_cur_model->unk58 = arg0->unk24 + cam->unk74 * 32000;
    ai_cur_model->unk5C = arg0->unk28 - cam->unk76 * 12500;
    sv.unk0 = (arg0->unk38 << 12) / 360;
    sv.unk2 = (arg0->unk3A << 12) / 360;
    sv.unk4 = (arg0->unk3C << 12) / 360;
    RotMatrix(&sv, ai_cur_model->unk40);
    ai_cur_model->unk3C = 0;
    t = block_find_at(arg0->unk20, arg0->unk24, arg0->unk28);
    if (arg0->unk48 != t) {
        arg0->unk48 = t;
    }
    return 1;
}

static inline s32 func_801779B8_inline(Unk_801762F4 *arg0, s16 n, s32 arg2, s16 arg3) {
    Unk_80174F54 v;
    s16 a;
    arg0->unk3E = ai_dir_angle[n];
    ai_turn_step(arg0);
    a = (mail_wrap_angle(arg0->unk3E - 180) << 12) / 360;
    v.unk0 = arg2 * rsin(a) >> 12;
    v.unk4 = 0;
    v.unk8 = arg2 * rcos(a) >> 12;
    if (!ai_check_line(arg0, &v, (arg3 != 0) * 16) || !ai_try_move(arg0, &v, a)) {
        return 0;
    }
    return 1;
}

void ai_move_toward(Unk_801762F4 *arg0, s16 arg1, s32 arg2, s32 arg3) {
    s16 f = arg3;
    Unk_801E076C *p = D_801E076C[0];
    s16 d[2];
    s16 cur;
    s16 back;
    s32 dx;
    s32 dz;
    Unk_801762F4 *t;
    s16 n;
    s16 a;
    s16 j;
    s32 k;

    cur = mail_angle_to_dir8(arg0->unk3A - 180);
    back = ai_dir_reverse[cur];
    d[1] = 8;
    d[0] = 8;
    if (arg1 == 0) {
        goto fallback;
    }
    if (arg1 == 1) {
        if (arg0->unk10 == -2) {
            goto fallback;
        }
        if (arg0->unk10 == -1) {
            dx = p->unk54 + p->unk72 * 12500 - arg0->unk20;
            dz = p->unk5C + p->unk76 * 12500 - arg0->unk28;
        } else {
            t = npc_find(0, arg0->unk10);
            if (t == 0 || t->unk10 != -1) {
                goto fallback;
            }
            n = npc_get_radius(t) + ai_cur_body->unkA * 10;
            a = (mail_wrap_angle(t->unk3A - 270) << 12) / 360;
            if (t->unk0 & 1) {
                n = -n;
            }
            dx = t->unk20 + (n * rsin(a) >> 12) - arg0->unk20;
            dz = t->unk28 + (n * rcos(a) >> 12) - arg0->unk28;
        }
    } else {
        dx = arg0->unk2C - arg0->unk20;
        dz = arg0->unk34 - arg0->unk28;
    }
    if (dx >= 2) {
        d[0] = 0;
    } else if (dx < -1) {
        d[0] = 4;
    }
    if (dz < -1) {
        d[1] = 6;
    } else if (dz >= 2) {
        d[1] = 2;
    }
    if (d[0] != 8 && d[1] != 8) {
        j = ai_quadrant_dir[((dz < 0) ? 2 : 0) + (dx > 0)];
        if (j != back && func_801779B8_inline(arg0, j, arg2, f)) {
            return;
        }
    }
    if ((rand() & 1) || abs(dz) > abs(dx)) {
        j = d[0];
        d[0] = d[1];
        d[1] = j;
    }
    if (d[0] != 8 && d[0] != back && func_801779B8_inline(arg0, d[0], arg2, f)) {
        return;
    }
    if (d[1] != 8 && d[1] != back && func_801779B8_inline(arg0, d[1], arg2, f)) {
        return;
    }
fallback:
    if (cur != 8 && func_801779B8_inline(arg0, cur, arg2, f)) {
        return;
    }
    if (D_801E03E6[0] & 1) {
        j = cur + 1;
        if (j >= 8 || cur == 8) {
            j = 0;
        }
        for (k = 0; k < 8; k++, j++) {
            if (j >= 8) {
                j = 0;
            }
            if (j != back && func_801779B8_inline(arg0, j, arg2, f)) {
                return;
            }
        }
    } else {
        j = cur - 1;
        if (j < 0 || cur == 8) {
            j = 7;
        }
        for (k = 0; k < 8; k++, j--) {
            if (j < 0) {
                j = 7;
            }
            if (j != back && func_801779B8_inline(arg0, j, arg2, f)) {
                return;
            }
        }
    }
    if (back != 8 && func_801779B8_inline(arg0, back, arg2, f)) {
        return;
    }
    arg0->unk3E = ai_dir_angle[cur];
    ai_turn_step(arg0);
}

void ai_walk(Unk_801762F4 *arg0, s16 arg1, s32 arg2) {
    Unk_80174F54 v;
    s32 f;
    s16 d;
    s16 a;
    s32 r;

    f = 0;
    if (arg1 == 2) {
        f = 1;
        if (arg0->unk2C / 256 == arg0->unk20 / 256 && arg0->unk34 / 256 == arg0->unk28 / 256) {
            if (arg0->unk12 & 0x100) {
                arg0->unk12 &= ~0x100;
            }
            r = 1;
        } else {
            r = 0;
        }
        if (r) {
            return;
        }
    }
    d = mail_angle_to_dir8(arg0->unk3E - 180);
    if ((rand() & 3) != 1) {
        arg0->unk3E = ai_dir_angle[d];
        ai_turn_step(arg0);
        a = (mail_wrap_angle(arg0->unk3E - 180) << 12) / 360;
        v.unk0 = arg2 * rsin(a) >> 12;
        v.unk4 = 0;
        v.unk8 = arg2 * rcos(a) >> 12;
        if (!ai_check_line(arg0, &v, f * 16) || !ai_try_move(arg0, &v, a)) {
            r = 0;
        } else {
            r = 1;
        }
        if (r) {
            return;
        }
    }
    ai_move_toward(arg0, arg1, arg2, f);
}

s32 ai_step_back(Unk_801762F4 *arg0, s32 arg1) {
    Unk_80174F54 v;
    s32 i;
    s32 n;
    s16 a;
    s16 r;

    i = 0;
    n = -arg1;
    for (; i < 7; i++) {
        a = (mail_wrap_angle(arg0->unk3E + ai_probe_angle[i] - 180) << 12) / 360;
        v.unk0 = n * rsin(a) >> 12;
        v.unk4 = 0;
        v.unk8 = n * rcos(a) >> 12;
        if (ai_check_line(arg0, &v, 0)) {
            r = ai_try_move(arg0, &v, a);
        } else {
            r = 0;
        }
        if (r) {
            return 1;
        }
    }
    return 0;
}

s32 ai_sidestep(Unk_801762F4 *arg0, s32 arg1) {
    Unk_80174F54 v;
    s32 i;
    s16 a;
    s16 r;

    for (i = 4; i > 0; i--) {
        a = (mail_wrap_angle(arg0->unk3E + ai_probe_angle[i] - 180) << 12) / 360;
        v.unk0 = arg1 * rsin(a) >> 12;
        v.unk4 = 0;
        v.unk8 = arg1 * rcos(a) >> 12;
        if (ai_check_line(arg0, &v, 0)) {
            r = ai_try_move(arg0, &v, a);
        } else {
            r = 0;
        }
        if (r) {
            return 1;
        }
    }
    return 0;
}

s16 ai_decide_fire(Unk_801762F4 *arg0) {
    Unk_801E076C *p = D_801E076C[0];
    s32 c;
    s32 *pc;
    s32 t;
    s32 a;
    s32 b;
    s32 d;
    s32 m;
    s16 f;

    arg0->unkB = 0;
    if (arg0->unk10 != -1) {
        return 0;
    }
    if (p->unk40 & 0xC9000000) {
        return 0;
    }
    if (!ai_in_aim_cone(arg0, 1, 0)) {
        return 0;
    }
    if (arg0->unk12 & 4) {
        arg0->unkB = 2;
        return 0;
    }
    if (arg0->unk12 & 0x10) {
        if (arg0->unkB != 3) {
            arg0->unkB = 3;
        }
    }
    pc = &c;
    t = -(ai_cur_body->unkA + 600) + (u16)arg0->unk40;
    c = ai_cur_stats->unk14;
    if (t < 0) {
        t = 0;
    }
    a = ai_cur_stats->unk18 * 10;
    b = ai_cur_stats->unk1C * 10;
    d = ai_cur_stats->unk20 * 10;
    if (t < a) {
        c = 10;
        f = 0;
    } else {
        if (t < b) {
            m = ((b - t) << 12) / (b - a);
        } else if (t < d) {
            m = ((d - t) << 12) / (d - a);
        } else {
            m = rand() % 411;
        }
        *pc = *pc * m >> 12;
        f = 1;
    }
    if (!f) {
        if (arg0->unkB != 3) {
            arg0->unkB = 3;
        }
    }
    if (c < rand() % 100) {
        return 0;
    }
    arg0->unkB = 1;
    return 1;
}

void ai_face_player(Unk_801762F4 *arg0) {
    Unk_801E076C *p = D_801E076C[0];
    Unk_80174FFC sv;

    if (ai_cur_model != 0 && ai_cur_model->unk4 != 0) {
        arg0->unk3A = mail_wrap_angle((ratan2(p->unk54 + p->unk72 * 12500 - arg0->unk20, p->unk5C + p->unk76 * 12500 - arg0->unk28) * 360 >> 12) - 180);
        sv.unk0 = (arg0->unk38 << 12) / 360;
        sv.unk2 = (arg0->unk3A << 12) / 360;
        sv.unk4 = (arg0->unk3C << 12) / 360;
        RotMatrix(&sv, ai_cur_model->unk40);
        ai_cur_model->unk3C = 0;
    }
}

void ai_update_stand(Unk_801762F4 *arg0) {
    s16 f;

    ai_cur_grid = 0;
    ai_cur_stats = 0;
    ai_cur_body = 0;
    ai_cur_block = (Unk_801DFC60 *)arg0->unk48;
    ai_cur_model = mod_find(arg0->unk16);
    ai_cur_stats = npc_find_stats(arg0->unk18);
    if (ai_cur_stats == 0) {
        ai_cur_stats = &D_801D7328;
    }
    ai_cur_body = npc_find_body(arg0->unk14);
    if (ai_cur_body == 0) {
        ai_cur_body = &ai_default_body;
    }
    f = 0;
    if (ai_cur_block != 0) {
        f = 1;
        if (ai_cur_block->unk88 == 0) {
            f = 0;
        } else {
            ai_cur_grid = ai_cur_block->unk88;
        }
    }
    if (arg0->unk12 & 1) {
        arg0->unk12 &= ~1;
        ai_face_player(arg0);
    } else if (f != 0) {
        if (ai_find_target(arg0, 1) && arg0->unkE == 1 && ai_decide_fire(arg0)) {
            if (!(arg0->unk12 & 0x400)) {
                arg0->unk12 |= 0x400;
            }
        }
    } else {
        ai_face_player(arg0);
    }
}

void ai_update_move(Unk_801762F4 *arg0, s16 arg1) {
    s32 f;
    s32 n;
    s32 m;
    s32 d;
    s32 x;

    ai_cur_grid = 0;
    ai_cur_stats = 0;
    ai_cur_body = 0;
    ai_cur_block = (Unk_801DFC60 *)arg0->unk48;
    ai_cur_model = mod_find(arg0->unk16);
    ai_cur_stats = npc_find_stats(arg0->unk18);
    if (ai_cur_stats == 0) {
        ai_cur_stats = &D_801D7328;
    }
    ai_cur_body = npc_find_body(arg0->unk14);
    if (ai_cur_body == 0) {
        ai_cur_body = &ai_default_body;
    }
    if (ai_cur_block == 0 || ai_cur_block->unk88 == 0) {
        f = 0;
    } else {
        ai_cur_grid = ai_cur_block->unk88;
        f = 1;
    }
    if (f == 0 || (arg0->unk12 & 0x20)) {
        return;
    }
    if (arg0->unk12 & 1) {
        arg0->unk12 &= ~1;
        if (arg1 != 0) {
            ai_find_target(arg0, arg1);
            return;
        }
    }
    if (arg0->unk12 & 8) {
        arg0->unk12 &= ~8;
        if (arg1 == 1) {
            arg1 = 0;
        }
    }
    switch (arg1) {
    case 0:
        n = 4;
        break;
    case 1:
        n = 10;
        break;
    default:
        n = 6;
        break;
    }
    d = D_801E6DB4[0];
    if ((u16)ai_cur_stats->unk10 != 0) {
        x = d * (u16)ai_cur_stats->unk10;
    } else {
        x = d * 3;
    }
    m = x * n;
    if (arg0->unkE == 1 && arg0->unkB == 2) {
        if (!(s16)ai_sidestep(arg0, m)) {
            ai_step_back(arg0, m);
        }
    } else if (arg0->unkE == 1 && arg0->unkB == 3) {
        if (!(s16)ai_step_back(arg0, m)) {
            ai_sidestep(arg0, m);
        }
    } else {
        ai_walk(arg0, arg1, m);
    }
    ai_cur_grid = 0;
    ai_cur_stats = 0;
    ai_cur_body = 0;
    ai_cur_block = (Unk_801DFC60 *)arg0->unk48;
    ai_cur_model = mod_find(arg0->unk16);
    ai_cur_stats = npc_find_stats(arg0->unk18);
    if (ai_cur_stats == 0) {
        ai_cur_stats = &D_801D7328;
    }
    ai_cur_body = npc_find_body(arg0->unk14);
    if (ai_cur_body == 0) {
        ai_cur_body = &ai_default_body;
    }
    if (ai_cur_block == 0 || ai_cur_block->unk88 == 0) {
        f = 0;
    } else {
        ai_cur_grid = ai_cur_block->unk88;
        f = 1;
    }
    if (f != 0) {
        if (ai_find_target(arg0, arg1)) {
            if (arg0->unkE == 1 && ai_decide_fire(arg0)) {
                if (!(arg0->unk12 & 0x400)) {
                    arg0->unk12 |= 0x400;
                }
            }
        } else if (arg0->unkE == 1) {
            if (!(arg0->unk12 & 8)) {
                arg0->unk12 |= 8;
            }
        }
    }
}

void ai_fire(Unk_801762F4 *arg0) {
    Unk_801E076C *p;
    s32 f;
    s32 t;
    s32 a;
    s32 b;
    s32 d;
    s32 c;
    s32 m;
    s32 r;
    s32 x;

    ai_cur_grid = 0;
    ai_cur_stats = 0;
    ai_cur_body = 0;
    ai_cur_block = (Unk_801DFC60 *)arg0->unk48;
    p = D_801E076C[0];
    ai_cur_model = mod_find(arg0->unk16);
    ai_cur_stats = npc_find_stats(arg0->unk18);
    if (ai_cur_stats == 0) {
        ai_cur_stats = &D_801D7328;
    }
    ai_cur_body = npc_find_body(arg0->unk14);
    if (ai_cur_body == 0) {
        ai_cur_body = &ai_default_body;
    }
    if (ai_cur_block == 0 || ai_cur_block->unk88 == 0) {
        f = 0;
    } else {
        ai_cur_grid = ai_cur_block->unk88;
        f = 1;
    }
    if (f == 0) {
        if ((arg0->unk2 & 0xFF) == 2 || (arg0->unk2 & 0xFF) == 3) {
            sound_se_play(0x28);
        } else {
            switch ((u16)ai_cur_stats->unk2) {
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
    if (!ai_find_target(arg0, 1) || arg0->unk10 != -1 || (arg0->unk12 & 4) || !ai_in_aim_cone(arg0, 1, 0)) {
        if ((arg0->unk2 & 0xFF) == 2 || (arg0->unk2 & 0xFF) == 3) {
            sound_se_play(0x28);
        } else {
            switch ((u16)ai_cur_stats->unk2) {
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
    t = -(ai_cur_body->unkA + 600) + (u16)arg0->unk40;
    if (t < 0) {
        t = 0;
    }
    m = 0;
    a = ai_cur_stats->unk18 * 10;
    b = ai_cur_stats->unk1C * 10;
    c = (u16)ai_cur_stats->unkC;
    d = ai_cur_stats->unk20 * 10;
    r = 0;
    if (t < a) {
        r = -1;
    } else if (t < b) {
        m = 0x1000;
    } else if (t < d) {
        m = ((d - t) << 12) / (d - b);
    }
    if (!(t < a)) {
        r = c * m >> 12;
    }
    if ((u16)ai_cur_stats->unk2 == 0) {
        x = p->unk58 - p->unk74 * 32000 - arg0->unk24 + 1600;
        if (x > 0) {
            x = -x;
        }
        if (x < -1600 || m == 0) {
            if ((arg0->unk2 & 0xFF) == 2 || (arg0->unk2 & 0xFF) == 3) {
                sound_se_play(0x28);
            } else {
                switch ((u16)ai_cur_stats->unk2) {
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
    if (r < 20) {
        if (r < 0) {
            m = 0x1000;
        }
        r = 20;
    }
    if (rand() % 100 < r) {
        if (m < 410) {
            m = 410;
        }
        player_take_hit(arg0, ai_cur_stats->unk2, (u16)ai_cur_stats->unk8 * m >> 12);
    }
    if ((arg0->unk2 & 0xFF) == 2 || (arg0->unk2 & 0xFF) == 3) {
        sound_se_play(0x28);
    } else {
        switch ((u16)ai_cur_stats->unk2) {
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

s16 ai_in_aim_cone(Unk_801762F4 *arg0, s16 arg1, s16 arg2) {
    Unk_801E076C *p = D_801E076C[0];
    s32 dx;
    s32 dz;
    s16 lim;
    s32 t;
    s32 a;

    if (arg1 != 0) {
        lim = 10;
        dx = p->unk54 + p->unk72 * 12500 - arg0->unk20;
        dz = p->unk5C + p->unk76 * 12500 - arg0->unk28;
    } else {
        dx = arg0->unk20 - p->unk54 - p->unk72 * 12500;
        dz = arg0->unk28 - p->unk5C - p->unk76 * 12500;
        lim = 15;
        if (arg2 == 10 || arg2 >= 14) {
            lim = 25;
        }
    }
    t = ratan2(dx, dz) * 360 >> 12;
    if (arg1 != 0) {
        a = mail_wrap_angle(t - arg0->unk3A + 180);
    } else {
        a = mail_wrap_angle(t - p->unk6E);
    }
    if (a <= lim || a >= 360 - lim) {
        if (arg1 != 0) {
            if (arg0->unk45 > 50) {
                return 0;
            }
        } else if (arg0->unk44 > lim) {
            return 0;
        }
        return 1;
    }
    return 0;
}
