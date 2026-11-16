#include "common.h"
#include "game/types.h"

extern Unk_801E1040 D_801E1040;
extern GameVars action_vars;
void kaj_event_flush(s32 a, s32 b);
extern Unk_801E056C effect_alarms[4];
s32 kaj_event_set_alarm(s32 a, s32 b, s32 c);
void free3(void *ptr);
void *effect_flame_small_bufs;
void *effect_flame_small_bufs_1;
extern s16 D_801E05BA[];
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801DFEA0;
Unk_801DFEA0 effect_clut_cycle_rect;
extern u16 effect_clut_cycle_buf[];
s32 LoadImage2(void *rect, void *p);
extern s16 D_801E05BC[];
s32 StoreImage2(void *rect, void *p);
void *effect_flame_large_bufs;
void *effect_flame_large_bufs_1;
extern s16 D_801E05B8[];
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801DFD00;
Unk_801DFD00 effect_clut_rotate_rect;
typedef struct { u8 unk0[0xC]; s16 unkC; u8 unkE[4]; s16 unk12; } Unk_801867E8_0;
typedef struct { u8 unk0[0x24]; s16 unk24; u8 unk26[0x16]; Unk_801867E8_0 **unk3C; } Unk_801867E8;
s16 effect_slide_height;
typedef struct { u8 unk0[4]; s16 unk4; u8 unk6[6]; s16 unkC; u8 unkE[4]; s16 unk12; } Unk_80186838_0;
typedef struct { u8 unk0[0x22]; s16 unk22; u8 unk24[0x18]; Unk_80186838_0 **unk3C; } Unk_80186838;
s16 effect_slide_y;
typedef struct {
    u8 unk0[4];
    s16 unk4;
    u8 unk6[6];
    s16 unkC;
    u8 unkE[4];
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
} Unk_80186884_0;
typedef struct {
    u8 unk0[0x22];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[2];
    s32 unk2C;
    void (*unk30)();
    void (*unk34)();
    u8 unk38[4];
    Unk_80186884_0 **unk3C;
} Unk_80186884;
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    s16 unk6;
} Unk_801DFEB8;
Unk_801DFEB8 effect_elevator;
extern Unk_801DFE68 D_801DFE68;
extern Inventory *D_801E0768[];
typedef struct Unk_80188FEC {
    u16 unk0;
    u16 unk2;
    u8 unk4[0x20];
    u16 unk24;
    u8 unk26[2];
    s16 unk28;
    u8 unk2A[6];
    u16 unk30;
    u8 unk32[2];
    s16 unk34;
    u8 unk36[2];
    u16 unk38;
    u8 unk3A[2];
    s16 unk3C;
    u8 unk3E[2];
    s16 unk40;
    u8 unk42[6];
    s16 unk48;
    u8 unk4A[2];
    u16 unk4C;
    u8 unk4E[2];
    u16 unk50;
    u16 unk52;
    u8 unk54[0xC];
} Unk_80188FEC;
extern SceneTables object_scene_tables;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801DFEB0;
Unk_801DFEB0 effect_flame_large_rect;
s16 effect_flame_large_cur;
int rand(void);
typedef struct {
    u8 unk0[0x22];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    u8 unk28[8];
    void (*unk30)();
    void (*unk34)();
    u8 unk38[4];
    s32 *unk3C;
} Unk_80185918;
void door_fade_step(Unk_80185918 *arg0);
void *kaj_tss_alloc(u32 arg0);
void kaj_tss_set_steps(void *arg0, s32 arg1);
s32 kaj_tss_start(void *arg0);
extern char D_80170544[];
extern char effect_str_file[];
void effect_sprite_anim_step(Unk_80186884 *arg0);
Unk_80186884_0 *sprite_find(u16 arg0);
void kaj_abend(s32 a, char *b, char *c, s32 d);
extern char D_8017056C[];
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801DFE90;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_801DFE98;
Unk_801DFE90 effect_flame_small_rect;
Unk_801DFE98 effect_flame_small_clut_rect;
s16 effect_flame_small_kind;
s16 effect_flame_small_cur;
void effect_flame_make_clut(s16 arg0);
void *kaj_malloc(s32 size);
extern s32 D_801DFED4;
void effect_elevator_enter(void);
void effect_elevator_update(void);
void effect_elevator_input(void);
s16 event_handle_effect_done(s32 *arg0);
void event_handle_tick(s16 a);
void mail_step_frame(s32 a, s32 b, s32 c);
s32 kaj_event_get(s32 *arg0);
void kaj_event_done(s32 *arg0);
void kaj_timer_disable(void);
extern Unk_801E0340 D_801E0340[];
extern PlayerStatus player_status;
extern s16 effect_item_menu_list[];
s16 effect_item_sel;
s16 effect_item_full;
s16 effect_item_use(PlayerStatus *a, s16 b, s16 c, s16 d, s16 e);
void *mod_find(u16 a);
void mod_setup(void *a, void *b, s32 c, s32 d);
void effect_weapon_calc_rate(s32 arg0);
void object_load_weapon_mods(void);
void thing_set_animate(s32 a, s32 b, s32 c);
void thing_set_flag10(s32 a, s32 b, s32 c);
Unk_80188FEC *effect_weapon_find(s16 arg0);
void player_weapon_sound(s16 a, s32 b);
extern Player *D_801E076C[];
s32 effect_elevator_on_task_end(s32 *arg0);
void sprite_fill_clut(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void sprite_set_clut_entry(s32 arg0, s32 arg1, s32 arg2);
void kaj_timer_enable(void);
void player_start_move_to(s16 a, u16 b, s32 c, s32 d, s32 e, s16 f, s16 g, s16 h, s32 i);
typedef struct {
    u8 unk0[0x22];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    u8 unk28[8];
    void (*unk30)();
    void (*unk34)();
    void (*unk38)();
    Unk_80186884_0 **unk3C;
} Unk_80185A60;
void effect_sprite_slide_step(Unk_801867E8 *arg0);
void effect_sprite_slide_end(Unk_80186838 *arg0);
extern u8 effect_flame_small_cluts[][0x20];
Unk_801854B8 *door_find(u16 arg0);
extern char D_80170590[];
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void sprite_set_visible(s32 arg0, s32 arg1);
void kaj_pad_reset(s32 a);
s32 rsin(s32 a);
s32 rcos(s32 a);
void mod_free_by_id(u16 a);
s32 effect_weapon_unequip(s16 arg0);
s16 D_801DFEC2;
s16 effect_item_prompt_shown;
s32 mail_menu_open(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i);
s32 mail_menu_close(void);
void sound_se_play(s32 arg0);
typedef struct { u16 unk0; u16 unk2; u16 unk4; } Unk_801DFE6A;
extern Unk_801DFE6A D_801DFE6A;
void door_start_open(Unk_801854B8 *arg0, s16 arg1, s16 arg2, s16 arg3);
void door_start_close(Unk_801854B8 *arg0, s16 arg1, s16 arg2);
void *memset(void *dst, s32 c, u32 n);
char *strncpy(char *dst, char *src, u32 n);
extern char effect_str_scene_idc[];
extern char effect_str_scene_htl[];
extern char effect_str_scene_cmn[];
u16 effect_elevator_floor_count;
extern KajSystem kaj_system;
void effect_elevator_exit(void);
void effect_elevator_move_doors(Unk_801DFEB8 *arg0, s16 arg1);
s32 kaj_pad_read(void);
void text_close(void);
void mod_free_pooled(void);
void sprite_set_cell(s32 arg0, s32 arg1, s32 arg2);
extern char D_80170618[];
extern char D_80170648[];
extern char D_80170678[];
extern char D_801706BC[];
extern char D_80170700[];
extern char D_8017073C[];
extern char D_80170778[];
extern char D_801707A4[];
extern char D_801707B8[];
extern char D_801707CC[];
extern char D_801707E0[];
extern char D_801707F4[];
/* refined: unk2 u16, unk4 text, unk26 s16 (was u8 unk2[0x26]) */
/* refined: unk26[0x22] split into unk26[6], s16 unk2C, unk2E[0x1A] */
int sprintf(char *buf, const char *fmt, ...);
void text_show_timed(s16 arg0, s16 arg1, char *arg2, s16 arg3, s32 arg4);
void event_draw_limb_status(PlayerStatus *arg0);
void event_advance_clock(s16 a, s16 b);
void player_heal_part(s16 arg0, s16 arg1, s16 arg2);
void player_add_hp(s16 arg0, s16 arg1);
s32 player_is_injured(void);
extern s32 D_801E6DB4[];
void block_set_mode(u16 arg0);
void sound_se_stop(s32 arg0);
void effect_weapon_draw_panel(s16 arg0, s16 arg1);
void mod_set_anim(void *arg0, s16 arg1, s16 arg2);
extern char D_8017080C[];
s16 effect_item_menu_show(PlayerStatus *arg0, s16 arg1, s16 arg2);
s16 mail_menu_get_state(void);
s16 mail_menu_move(s16 a);
u16 roadmap_get_state(void);
s16 effect_item_input(PlayerStatus *arg0, s16 arg1);

void effect_start_sprite_slide(s32 arg0, u16 arg1, s32 arg2) {
    GameVars *g = &action_vars;
    Unk_80186884_0 *spr;
    Unk_80185A60 *node;

    spr = sprite_find(arg1);
    if (spr == NULL) {
        kaj_abend(5, D_80170544, effect_str_file, 0x97);
    }
    effect_slide_y = spr->unkC;
    effect_slide_height = spr->unk12;
    node = kaj_tss_alloc(4);
    arg2 *= 30;
    node->unk22 = arg0;
    if (arg0 == 2 || arg0 == 3) {
        node->unk24 = (arg0 == 2) ? 0xF0 : spr->unkC;
        node->unk26 = (arg0 == 2) ? spr->unkC : 0xF0;
    } else {
        node->unk24 = (arg0 == 0xB) ? 0xF0 : spr->unkC;
        node->unk26 = (arg0 == 0xB) ? spr->unkC : 0xF0;
    }
    kaj_tss_set_steps(node, arg2);
    node->unk30 = effect_sprite_slide_step;
    node->unk34 = effect_sprite_slide_end;
    node->unk38 = effect_sprite_slide_end;
    *node->unk3C = spr;
    if (arg0 == 2 || arg0 == 0xB) {
        spr->unk4 = 1;
        spr->unkC = 0xF0;
        spr->unk12 = 0;
    }
    g->unk244 = kaj_tss_start(node);
}

void effect_flame_make_clut(s16 arg0) {
    s16 r[4];
    u16 buf[0x100];
    s32 i;
    s32 v;

    r[1] = 0x1EE;
    r[2] = 0x100;
    r[3] = 1;
    r[0] = 0;
    switch (arg0) {
    case 0:
        for (i = 0; i < 0x40; i++) {
            buf[i] = ((i / 4) << 10) | 0x8000;
        }
        for (i = 0; i < 0x80; i++) {
            buf[i + 0x40] = ((i / 8) << 5) | 0xC000;
        }
        for (i = 0; i < 0x40; i++) {
            buf[i + 0xC0] = (i / 4) | 0xC200;
        }
        break;
    case 1:
        for (i = 0; i < 0x40; i++) {
            buf[i] = (i / 4) | ((i / 8) << 5) | 0x8000;
        }
        for (i = 0; i < 0x80; i++) {
            buf[i + 0x40] = ((i / 16 + 8) << 5) | 0x8010;
        }
        for (i = 0; i < 0x40; i++) {
            buf[i + 0xC0] = ((i / 4) << 10) | 0x8210;
        }
        break;
    case 2:
        for (i = 0; i < 0x100; i++) {
            v = i / 8;
            buf[i] = v | (v << 5) | (v << 10) | 0x8000;
        }
        break;
    }
    LoadImage2(r, buf);
}

void effect_flame_small_update(void) {
    void **p = &effect_flame_small_bufs;
    u8 *src = p[effect_flame_small_cur];
    s16 n = effect_flame_small_cur ^ 1;
    u8 *dst = p[n];
    u8 *pal;
    s32 i;
    s32 j;
    s32 v;
    s32 w;
    s32 k;

    if (src != 0 && dst != 0) {
        pal = 0;
        if (effect_flame_small_kind == 1) {
            pal = effect_flame_small_cluts[effect_flame_small_cur];
        }
        effect_flame_small_cur = n;
        v = 0;
        for (i = 0; i < 0x10; i++) {
            if (rand() % 100 < 50) {
                v = rand() % 2 * 255;
            }
            *(dst + i + 0x1E0) = v;
            *(dst + i + 0x1F0) = v;
        }
        for (i = 0x1E0; i >= 0x20; i -= 0x10) {
            for (j = 1; j < 0xF; j++) {
                k = i + j;
                w = *(src + k + 0x10);
                w += *(src + k + 1);
                w += *(src + k - 1);
                w += *(src + k - 0xF);
                w += *(src + k - 0x11);
                w /= 5;
                if (w >= 5) {
                    w -= 4;
                }
                *(dst + k - 0x10) = w;
            }
        }
        if (pal != 0) {
            LoadImage2(&effect_flame_small_clut_rect, pal);
        }
        LoadImage2(&effect_flame_small_rect, dst);
    }
}

void effect_flame_large_update(void) {
    void **p = &effect_flame_large_bufs;
    u8 *src = p[effect_flame_large_cur];
    s16 n = effect_flame_large_cur ^ 1;
    u8 *dst = p[n];
    s32 i;
    s32 j;

    if (src != 0 && dst != 0) {
        effect_flame_large_cur = n;
        for (i = 0; i < 0x20; i++) {
            *(dst + i + 0x3E0) = rand() % 256;
        }
        for (i = 0x3C0; i >= 0; i -= 0x20) {
            for (j = 1; j < 0x1F; j++) {
                dst[i + j] = (src[i + j] + src[i + j + 0x1F] * 2 + src[i + j + 0x20] * 3 + src[i + j + 0x21] * 2) >> 3;
            }
        }
        LoadImage2(&effect_flame_large_rect, dst);
    }
}

void effect_start_fade(s32 arg0, s32 arg1) {
    GameVars *g = &action_vars;
    Unk_801E1040 *h = &D_801E1040;
    Unk_80185918 *node;

    node = kaj_tss_alloc(4);
    arg1 *= 30;
    node->unk22 = arg0;
    switch (arg0) {
    case 0:
    case 9:
        node->unk24 = 0;
        node->unk26 = 0x1000;
        break;
    case 1:
    case 10:
        node->unk24 = 0x1000;
        node->unk26 = 0;
        break;
    }
    h->unkE = node->unk24;
    h->unk6 = 1;
    kaj_tss_set_steps(node, arg1);
    node->unk30 = door_fade_step;
    node->unk34 = door_fade_step;
    *node->unk3C = arg0;
    g->unk244 = kaj_tss_start(node);
}

void effect_fade_reset(void) {
    Unk_801E1040 *p = &D_801E1040;
    if (p->unk6 != 0) {
        p->unkE = 0x1000;
        p->unk6 = 0;
    }
}

void effect_fade_set_black(void) {
    Unk_801E1040 *p = &D_801E1040;
    if (p->unk6 == 0) {
        p->unkE = 0;
        p->unk6 = 1;
    }
}

void effect_fade_set_dim(void) {
    Unk_801E1040 *p = &D_801E1040;
    if (p->unk6 == 0) {
        p->unkE = 0x400;
        p->unk6 = 1;
    }
}

void effect_start_sprite_anim(u16 arg0, s32 arg1) {
    GameVars *g = &action_vars;
    Unk_80186884_0 *spr;
    Unk_80186884 *node;

    spr = sprite_find(arg0);
    if (spr == NULL) {
        kaj_abend(5, D_80170544, effect_str_file, 0xCC);
    }
    node = kaj_tss_alloc(4);
    node->unk22 = 6;
    node->unk24 = 1;
    node->unk26 = spr->unk14 * spr->unk16;
    node->unk28 = 1;
    node->unk30 = effect_sprite_anim_step;
    node->unk34 = effect_sprite_anim_step;
    arg1 *= 30;
    node->unk2C = arg1 / node->unk26;
    *node->unk3C = spr;
    spr->unk18 = 0;
    spr->unk1A = 0;
    spr->unk4 = 1;
    g->unk244 = kaj_tss_start(node);
}

void effect_clear_alarms(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        action_vars.unk204[i].unk4 = 0;
        action_vars.unk204[i].unk0 = -1;
        kaj_event_flush(2, i + 0x64);
    }
}

void effect_start_alarm(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801E056C *p = &effect_alarms[arg0];

    if (p->unk4 == 0) {
        p->unk0 = kaj_event_set_alarm(arg2 * 60, arg0 + 0x64, arg1);
        if (p->unk0 >= 0) {
            p->unk4 = 1;
        }
    }
}

void effect_flame_small_init(s16 arg0) {
    void *a;
    void *b;
    Unk_801DFE90 *r = &effect_flame_small_rect;
    Unk_801DFE98 *t;

    r->unk0 = 0x1B0;
    r->unk2 = 0xE0;
    r->unk4 = 8;
    r->unk6 = 0x20;
    t = &effect_flame_small_clut_rect;
    t->unk0 = 0x100;
    t->unk2 = 0x1ED;
    t->unk4 = 0x10;
    t->unk6 = 1;
    effect_flame_make_clut(arg0);
    a = kaj_malloc(0x200);
    b = kaj_malloc(0x200);
    if (a == 0 || b == 0) {
        kaj_abend(3, D_8017056C, effect_str_file, 0x16E);
    }
    effect_flame_small_kind = arg0;
    effect_flame_small_bufs = a;
    effect_flame_small_bufs_1 = b;
    effect_flame_small_cur = 0;
}

void effect_flame_small_free(void) {
    s32 i;
    void **p = &effect_flame_small_bufs;

    D_801E05BA[0] = 0;
    for (i = 0; i < 2; i++) {
        if (p[i] != 0) {
            free3(p[i]);
            p[i] = 0;
        }
    }
}

void effect_clut_cycle_update(void) {
    s32 i;
    u16 t = effect_clut_cycle_buf[1];

    for (i = 1; i < 14; i++) {
        effect_clut_cycle_buf[i] = effect_clut_cycle_buf[i + 1];
    }
    effect_clut_cycle_buf[14] = t;
    LoadImage2(&effect_clut_cycle_rect, effect_clut_cycle_buf);
}

void effect_clut_cycle_init(void) {
    Unk_801DFEA0 *r = &effect_clut_cycle_rect;

    r->unk0 = 0x60;
    r->unk2 = 0x1E6;
    r->unk4 = 0x10;
    r->unk6 = 1;
    StoreImage2(r, effect_clut_cycle_buf);
    D_801E05BC[0] = 0;
}

void effect_flame_large_init(void) {
    void *a;
    void *b;
    Unk_801DFEB0 *r = &effect_flame_large_rect;

    r->unk0 = 0x1B0;
    r->unk2 = 0xC0;
    r->unk4 = 0x10;
    r->unk6 = 0x20;
    a = kaj_malloc(0x400);
    b = kaj_malloc(0x400);
    if (a == 0 || b == 0) {
        kaj_abend(3, D_8017056C, effect_str_file, 0x1CA);
    }
    effect_flame_large_bufs = a;
    effect_flame_large_bufs_1 = b;
    effect_flame_large_cur = 0;
}

void effect_flame_large_free(void) {
    s32 i;
    void **p = &effect_flame_large_bufs;

    D_801E05B8[0] = 0;
    for (i = 0; i < 2; i++) {
        if (p[i] != 0) {
            free3(p[i]);
            p[i] = 0;
        }
    }
}

void effect_clut_rotate(void) {
    u16 buf[16];
    s32 i;
    u16 t;

    StoreImage2(&effect_clut_rotate_rect, buf);
    t = buf[15];
    for (i = 15; i > 0; i--) {
        buf[i] = buf[i - 1];
    }
    buf[0] = t;
    LoadImage2(&effect_clut_rotate_rect, buf);
}

void effect_sprite_slide_step(Unk_801867E8 *arg0) {
    Unk_801867E8_0 *p = *arg0->unk3C;
    s16 v;

    p->unkC = arg0->unk24;
    v = 0xF0 - arg0->unk24;
    p->unk12 = v;
    if (effect_slide_height < v) {
        p->unk12 = effect_slide_height;
    }
}

void effect_sprite_slide_end(Unk_80186838 *arg0) {
    Unk_80186838_0 *p = *arg0->unk3C;
    GameVars *q = &action_vars;

    p->unkC = effect_slide_y;
    p->unk12 = effect_slide_height;
    if (arg0->unk22 == 3 || arg0->unk22 == 0xC) {
        p->unk4 = 0;
    }
    q->unk244 = -1;
}

void effect_sprite_anim_step(Unk_80186884 *arg0) {
    Unk_80186884_0 *p = *arg0->unk3C;

    p->unk18 = (arg0->unk24 - 1) / p->unk16;
    p->unk1A = (arg0->unk24 - 1) % p->unk16;
}

s32 effect_elevator_on_task_end(s32 *arg0) {
    Player *p = D_801E076C[0];
    Unk_801DFEB8 *q = &effect_elevator;
    Unk_801854B8 *e;
    s32 i;

    if (arg0[4] != 4) {
        return 0;
    }
    if (p->flags & 0x80) {
        kaj_pad_reset(1);
        sprite_set_visible(2, 1);
        text_show(D_80170590, 3, -1, 0, -1, 0, 1);
        return 0;
    }
    for (i = 0; i < 2; i++) {
        e = door_find(((u16)q->unk2 - 1) * 2 + i);
        if (e != NULL) {
            e->unkA = 0;
            switch ((u16)e->unk2) {
            case 1:
                e->unk14 = e->unkC;
                break;
            case 2:
                e->unk18 = e->unkC;
                break;
            case 3:
                e->unk1C = e->unkC;
                break;
            }
            e->unk40 = e->unk14 - p->cell_x * 0x30D4;
            e->unk44 = e->unk18 + p->cell_y * 0x7D00;
            e->unk48 = e->unk1C - p->cell_z * 0x30D4;
            e->unk28 = 0;
        }
    }
    return 1;
}

void effect_elevator_exit(void) {
    Player *p = D_801E076C[0];
    s32 x;
    s32 z;

    sprite_set_visible(2, 0);
    kaj_pad_reset(0);
    x = rsin((p->yaw << 12) / 360) * 0x1194 >> 12;
    z = rcos((p->yaw << 12) / 360) * 0x1194 >> 12;
    x += p->pos_x + p->cell_x * 0x30D4;
    z += p->pos_z + p->cell_z * 0x30D4;
    player_start_move_to(2, 0x80, x, p->pos_y - p->cell_y * 0x7D00 - p->unk78, z, p->pitch, p->yaw, p->unk70, 2);
}

void effect_elevator_move_doors(Unk_801DFEB8 *arg0, s16 arg1) {
    Unk_801E0340 *p = D_801E0340;
    Unk_801854B8 *e;
    s16 v;
    s32 i;

    kaj_pad_reset(0);
    for (i = 0; i < 2; i++) {
        e = door_find((arg0->unk2 - 1) * 2 + i);
        if (e == NULL) {
            continue;
        }
        if (arg1 != 0) {
            if (D_801DFE68.unk0 == 0) {
                switch (D_801DFE6A.unk0) {
                case 28:
                    v = i * 0x140 - 0xA0;
                    break;
                case 7:
                    v = i * 0xB4 - 0x5A;
                    break;
                case 15:
                    v = i * 0xF0 - 0x78;
                    break;
                }
            }
            door_start_open(e, v, 3, 0);
            arg0->unk6 = 2;
        } else {
            memset(&p[1], 0, 4);
            ((s16 *)&p->unk14)[1] = 0x41;
            ((s16 *)&p->unk18)[0] = arg0->unk0;
            if (D_801DFE68.unk0 == 0) {
                switch (D_801DFE6A.unk0) {
                case 28:
                    strncpy((char *)&p[1], effect_str_scene_idc, 3);
                    ((s16 *)&p->unk18)[1] = 0xB4;
                    v = (e->unkC - e->unk14) / 10;
                    break;
                case 7:
                    strncpy((char *)&p[1], effect_str_scene_htl, 3);
                    ((s16 *)&p->unk18)[1] = 0x5A;
                    v = (e->unkC - e->unk1C) / 10;
                    break;
                case 15:
                    strncpy((char *)&p[1], effect_str_scene_cmn, 3);
                    ((s16 *)&p->unk18)[1] = 0xB4;
                    v = (e->unkC - e->unk14) / 10;
                    break;
                }
            }
            door_start_close(e, v, 3);
            arg0->unk6 = 1;
        }
    }
    sound_se_play(0xB);
}

void effect_elevator_input(void) {
    Unk_801DFEB8 *p = &effect_elevator;

    if (kaj_system.pad_mode != 1) {
        return;
    }
    kaj_pad_read();
    if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
        sound_se_play(0xF);
        effect_elevator.unk0++;
        if (effect_elevator_floor_count < effect_elevator.unk0) {
            effect_elevator.unk0 = 1;
        }
        sprite_fill_clut(2, 1, 8, 0x421);
        if (p->unk2 == effect_elevator.unk0) {
            sprite_set_clut_entry(2, effect_elevator.unk0, 0x16BF);
        } else {
            sprite_set_clut_entry(2, effect_elevator.unk0, 0x17FF);
            sprite_set_clut_entry(2, p->unk2, 0x14BF);
        }
    } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
        Unk_801DFEB8 *q = &effect_elevator;

        sound_se_play(0xF);
        effect_elevator.unk0--;
        if (effect_elevator.unk0 == 0) {
            effect_elevator.unk0 = q->unk4;
        }
        sprite_fill_clut(2, 1, 8, 0x421);
        if (q->unk2 == effect_elevator.unk0) {
            sprite_set_clut_entry(2, effect_elevator.unk0, 0x16BF);
        } else {
            sprite_set_clut_entry(2, effect_elevator.unk0, 0x17FF);
            sprite_set_clut_entry(2, q->unk2, 0x14BF);
        }
    } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
        sound_se_play(8);
        text_close();
        effect_elevator_exit();
    } else if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
        if (p->unk2 != p->unk0) {
            mod_free_pooled();
            sound_se_play(0x11);
            text_close();
            effect_elevator_move_doors(p, 0);
        }
    }
}

void effect_elevator_enter(void) {
    Player *p;
    Unk_801DFEB8 *q;
    s32 x;
    s32 y;
    s32 z;

    D_801DFED4 = (s32)effect_elevator_on_task_end;
    p = D_801E076C[0];
    sprite_fill_clut(2, 1, 8, 0x421);
    q = &effect_elevator;
    if ((u16)q->unk2 == (u16)effect_elevator.unk0) {
        sprite_set_clut_entry(2, (u16)effect_elevator.unk0, 0x16BF);
    } else {
        sprite_set_clut_entry(2, (u16)effect_elevator.unk0, 0x17FF);
        sprite_set_clut_entry(2, (u16)q->unk2, 0x14BF);
    }
    x = p->pos_x + p->cell_x * 0x30D4;
    y = p->pos_y - p->cell_y * 0x7D00 - p->unk78;
    z = p->pos_z + p->cell_z * 0x30D4;
    kaj_timer_enable();
    player_start_move_to(0, 0, x, y, z, p->pitch, (s16)(p->yaw + 0xB4), p->unk70, 2);
}

static inline u16 func_801872D4_inl(s32 a) {
    Unk_801854B8 *e = door_find(((a - 1) * 2) | 1);
    if (e == NULL) {
        return 5;
    }
    return e->unkA;
}

void effect_elevator_update(void) {
    Player *p = D_801E076C[0];
    Unk_801DFEB8 *q = &effect_elevator;
    u16 v;

    switch ((u16)q->unk6) {
    case 0:
        break;
    case 3:
        block_set_mode(1);
        p->flags |= 0x80;
        q->unk6 = 4;
        break;
    case 4:
        sound_se_stop(0x12);
        effect_elevator_move_doors(q, 1);
        D_801E6DB4[0] = 0;
        break;
    default:
        v = func_801872D4_inl((u16)q->unk2);
        if ((u16)v == 1 && (u16)q->unk6 == 2) {
            q->unk6 = 0;
            kaj_pad_reset(1);
            text_show(D_80170590, 3, -1, 0, -1, 0, (u16)v);
        }
        if ((u16)v == 0 && (u16)q->unk6 == 1) {
            q->unk2 = q->unk0;
            sprite_fill_clut(2, 1, 8, 0x421);
            if ((u16)q->unk2 == (u16)q->unk0) {
                sprite_set_clut_entry(2, (u16)q->unk0, 0x16BF);
            } else {
                sprite_set_clut_entry(2, (u16)q->unk0, 0x17FF);
                sprite_set_clut_entry(2, (u16)q->unk2, 0x14BF);
            }
            q->unk6 = 3;
            sound_se_play(0x12);
        }
        break;
    }
}

void effect_elevator_run(void) {
    s32 buf[6];
    s16 done = 0;

    effect_elevator_enter();
    do {
        switch (kaj_event_get(buf)) {
        case 4:
            event_handle_tick(0);
            continue;
        case 0:
            effect_elevator_update();
            effect_elevator_input();
            break;
        case 0x100:
            done = event_handle_effect_done(buf);
            continue;
        default:
            kaj_event_done(buf);
            continue;
        }
        mail_step_frame(1, 1, 1);
    } while (done == 0);
    kaj_timer_disable();
    D_801DFED4 = 0;
}

void effect_elevator_init(s16 arg0) {
    Unk_801DFEB8 *p = &effect_elevator;
    Unk_801DFE68 *q;

    p->unk0 = arg0;
    p->unk2 = arg0;
    p->unk6 = 0;
    if (D_801DFE68.unk0 == 0) {
        q = &D_801DFE68;
        switch (q->unk2) {
        case 28:
            p->unk4 = 3;
            break;
        case 7:
            p->unk4 = 4;
            break;
        case 15:
            p->unk4 = 3;
            break;
        }
    }
}

s32 effect_weapon_unequip(s16 arg0) {
    PlayerStatus *g = &player_status;
    Inventory *p = g->inventory;
    Player *q = g->player;
    void *r;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (p->weapon_ids[i] == arg0) {
            mod_free_by_id(arg0 + 0x400);
            p->unk0--;
            p->weapon_ids[i] = -1;
            p->weapon_rate[i] = 0;
            if (p->weapon_slot == 0 && i == 0) {
                p->weapon_slot = 1;
            } else if (p->weapon_slot == 1 && i == 1) {
                p->weapon_slot = 0;
            } else {
                return 1;
            }
            r = mod_find(p->weapon_ids[p->weapon_slot] + 0x400);
            p->weapon_model = (s32)r;
            if (r != 0) {
                mod_setup(r, q->coord, 1, 0);
            }
            effect_weapon_calc_rate(p->weapon_slot);
            return 1;
        }
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170544);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", effect_str_file);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_8017056C);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170590);

void effect_weapon_draw_panel(s16 arg0, s16 arg1) {
    Inventory *p = D_801E0768[0];
    Unk_80188FEC *e;
    s16 id;
    s16 v;

    if (arg1 != 0) {
        sprite_set_visible(0x401, arg0);
        sprite_set_visible(0x402, arg0);
    }
    if (arg0 != 0) {
        id = p->weapon_ids[p->weapon_slot];
        e = effect_weapon_find(id);
        if (e != NULL) {
            v = (s16)e->unk30 >> 3;
            sprite_fill_clut(0x401, 0x10, v + 0x10, 0x67FF);
            sprite_fill_clut(0x401, v + 0x11, 0x2F, 0x3D40);
            v = e->unk52 >> 3;
            sprite_fill_clut(0x401, 0x40, v + 0x40, 0x67FF);
            sprite_fill_clut(0x401, v + 0x41, 0x5F, 0x3D40);
            v = e->unk50 / 3 - 1;
            if (v < 0) {
                v = 0;
            }
            sprite_fill_clut(0x401, 0x70, v + 0x70, 0x67FF);
            sprite_fill_clut(0x401, v + 0x71, 0x8F, 0x3D40);
            sprite_fill_clut(0x401, 0xC, 0xE, 0xD20);
            switch (e->unk2) {
            case 0:
                sprite_set_clut_entry(0x401, 0xC, 0xD3F);
                break;
            case 1:
            case 2:
                sprite_set_clut_entry(0x401, 0xD, 0xD3F);
                break;
            case 3:
                sprite_set_clut_entry(0x401, 0xE, 0xD3F);
                break;
            }
            sprite_set_cell(0x402, (s16)(id / 9), (s16)(id % 9));
            if (arg1 != 0) {
                /* "  8武器1を方向キー上下で,  選んで下さい,    武装 3○ 1武装解除 4×" */
                text_show("  8\225\220\212\3551\202\360\225\373\214\374\203L\201[\217\343\211\272\202\305,  \221I\202\361\202\305\211\272\202\263\202\242,    \225\220\221\225 3\201\233 1\225\220\221\225\211\360\217\234 4\201~", 3, -1, 0, -1, 0, 1);
            }
        }
    } else {
        text_close();
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170618);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170648);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170678);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801706BC);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170700);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_8017073C);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_80170778);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801707A4);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801707B8);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801707CC);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801707E0);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_801707F4);

INCLUDE_RODATA("asm/nonmatchings/game/80185A60", D_8017080C);

void effect_weapon_calc_rate(s32 arg0) {
    PlayerStatus *g = &player_status;
    Inventory *p = g->inventory;
    Unk_80188FEC *e = effect_weapon_find(p->weapon_ids[arg0]);
    s32 a, b, c, v;
    s32 val;

    if (e == NULL) {
        return;
    }
    a = 0x2000;
    if (e->unk28 != 0 && g->level < (s16)e->unk30) {
        a = (g->level << 13) / (s16)e->unk30;
    }
    b = 0x1000;
    if (e->unk34 != 0) {
        switch (e->unk38) {
        case 0:
            val = g->unkC;
            break;
        case 1:
            val = g->unkE;
            break;
        case 2:
            val = g->unk10;
            break;
        case 3:
            val = g->unk12;
            break;
        }
        if (val < e->unk3C) {
            b = (val << 12) / e->unk3C;
        }
    }
    c = 0x1000;
    if (e->unk40 != 0) {
        switch (e->unk2) {
        case 0:
            val = g->unk14;
            break;
        case 1:
            val = g->unk18;
            break;
        case 2:
            val = g->unk1C;
            break;
        case 3:
            val = g->unk20;
            break;
        case 4:
            val = g->unk24;
            break;
        }
        if (val < e->unk48) {
            c = (val << 12) / e->unk48;
        }
    }
    val = (e->unk50 * (a + b + c)) >> 14;
    v = (val < 20) ? 20 : (val > 100) ? 100 : val;
    p->weapon_rate[arg0] = v;
    g->weapon_redraw = 1;
}

void effect_weapon_swap_stock(s16 arg0, s16 arg1) {
    Inventory *p = D_801E0768[0];
    PlayerStatus *g;
    Inventory *e;
    Player *q;
    void *r;
    s32 i;
    s32 j;

    p->unk0 = 0;
    for (j = 0; j < 2; j++) {
        if (p->weapon_ids[j] >= 0) {
            p->unk0++;
        }
    }
    if (arg0 != 0) {
        effect_weapon_unequip(arg1);
        p->unkC[arg1]++;
    } else {
        g = &player_status;
        e = g->inventory;
        q = g->player;
        for (i = 0; i < 2; i++) {
            if (e->weapon_ids[i] < 0) {
                e->weapon_ids[i] = arg1;
                r = mod_find(arg1 + 0x400);
                if (r != 0) {
                    mod_setup(r, q->coord, 1, 0);
                }
                effect_weapon_calc_rate(i);
                break;
            }
        }
        p->unkC[arg1]--;
    }
    p->unk0 = 0;
}

s32 effect_inventory_has_room(s16 arg0) {
    Inventory *p = D_801E0768[0];
    s32 i;
    s16 n;

    switch (arg0) {
    case 0:
        for (i = 0, n = 0; i < 8; i++) {
            if ((u16)p->item_ids[i] < 100) {
                n++;
            }
        }
        if (n >= 5) {
            break;
        }
        for (i = 0; i < 8; i++) {
            if (p->item_ids[i] < 0) {
                return 1;
            }
        }
        break;
    case 1:
    case 3:
        for (i = 0; i < 8; i++) {
            if (p->item_ids[i] < 0) {
                return 1;
            }
        }
        return 0;
    case 4:
        for (i = 0; i < 2; i++) {
            if (p->weapon_ids[i] < 0) {
                return 1;
            }
        }
        return 0;
    case 2:
        return 1;
    }
    return 0;
}

static inline void func_80187E38_inl(s32 d) {
    Inventory *g;
    s32 k;
    void *r;
    s32 id;
    g = D_801E0768[0];
    if (g->unk0 != 2) {
        return;
    }
    sound_se_play(0xF);
    k = g->weapon_slot;
    k += d;
    if (k >= 2) {
        k = 0;
    } else if (k < 0) {
        k = 1;
    }
    g->weapon_slot = k;
    id = g->weapon_ids[k];
    r = mod_find(id + 0x400);
    effect_weapon_draw_panel(1, 0);
    effect_weapon_calc_rate(k);
    if (r == NULL) {
        return;
    }
    g->weapon_model = (s32)r;
    mod_set_anim(r, 5, 0);
}

s32 effect_weapon_input(PlayerStatus *arg0) {
    GameVars *q = &action_vars;
    Player *b = arg0->player;
    Inventory *a = arg0->inventory;

    if (b->flags & 0x8000) {
        if (a->weapon_shown == 0) {
            b->flags &= 0x7FFF;
            a->weapon_state = 0;
        }
        if ((u16)a->weapon_state != 2) {
            return 1;
        }
        if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
            func_80187E38_inl(1);
        } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
            func_80187E38_inl(-1);
        } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            sound_se_play(8);
            effect_weapon_draw_panel(0, 1);
            a->weapon_state = 1;
            mod_set_anim((void *)a->weapon_model, 6, 0);
        } else if ((!(kaj_system.pad_prev & 0x100) && (kaj_system.pad_now & 0x100)) ||
                   (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20))) {
            sound_se_play(0x11);
            effect_weapon_draw_panel(0, 1);
            b->flags &= 0x7FFF;
            a->weapon_state = 3;
            mod_set_anim((void *)a->weapon_model, 0, 0);
        }
        return 1;
    }
    if ((u16)a->weapon_state == 2 && a->weapon_shown == 0) {
        a->weapon_state = 0;
    }
    if (!(kaj_system.pad_prev & 0x100) && (kaj_system.pad_now & 0x100)) {
        if (*(s32 *)&q->unk24C != 0) { /* this unit reads one word at 0x24C */
            return 0;
        }
        if ((u16)a->weapon_state == 0) {
            sound_se_play(0x13);
            b->flags |= 0x8000;
            effect_weapon_draw_panel(1, 1);
            a->weapon_shown = 1;
            mod_set_anim((void *)a->weapon_model, 4, 0);
        } else if ((u16)a->weapon_state == 3) {
            sound_se_play(0x13);
            b->flags |= 0x8000;
            effect_weapon_draw_panel(1, 1);
            a->weapon_state = 2;
        }
    } else if ((!(kaj_system.pad_prev & 2) && (kaj_system.pad_now & 2)) ||
               (!(kaj_system.pad_prev & 1) && (kaj_system.pad_now & 1))) {
        if (a->armed != 0) {
            if ((u16)a->weapon_state == 3) {
                a->weapon_state = 4;
                mod_set_anim((void *)a->weapon_model, 1, 0);
            } else if ((u16)a->weapon_state == 5) {
                a->weapon_state = 6;
                mod_set_anim((void *)a->weapon_model, 2, 0);
            }
        }
    }
    return 0;
}

s16 effect_item_use(PlayerStatus *a, s16 b, s16 c, s16 d, s16 e) {
    char buf[0x80];
    SceneTables *p = &object_scene_tables;
    GameVars *q = &action_vars;
    Unk_801891A4 *ent;
    Unk_801891A4 *e2;
    s32 n;
    s32 i;
    s32 j;
    s16 ret;
    s16 flag;
    s16 kind;
    s16 v;
    s32 r;

    n = p->unk2C;
    e2 = (Unk_801891A4 *)p->unk48;
    if (n != 0) {
        if (c < 0) {
            ent = NULL;
            goto done;
        }
        for (j = 0; j < n; j++, e2++) {
            if (e2->unk0 == c) {
                ent = e2;
                goto done;
            }
        }
    }
    ent = NULL;
done:
    if (ent == NULL) {
        return -1;
    }
    memset(buf, 0, 0x80);
    ret = 0;
    kind = 3;
    flag = 0;
    if ((u16)(c - 0x27) < 4 || (u16)(c - 0x2F) < 4) {
        flag = 1;
    }
    switch (ent->unk2) {
    case 0:
        v = ent->unk26;
        if (v < 0) {
            if (a->mutant != 0) {
                player_add_hp(-v, 0);
                if (flag) {
                    /* " 8%s, 1を飲んで、8Ｖｉｔａｌｉｔｙ1が, 回復した" */
                    sprintf(buf, D_80170618, ent->unk4);
                } else {
                    /* " 8%s, 1を食べて、8Ｖｉｔａｌｉｔｙ1が, 回復した" */
                    sprintf(buf, D_80170648, ent->unk4);
                }
            } else {
                kind = 4;
                player_add_hp(v, 0);
                player_heal_part(3, 2, ent->unk26);
                if (flag) {
                    /* " 8%s, 1を飲んで、8Ｖｉｔａｌｉｔｙ1が, 減少し猛烈な腹痛が襲ってきた" */
                    sprintf(buf, D_80170678, ent->unk4);
                } else {
                    /* " 8%s, 1を食べて、8Ｖｉｔａｌｉｔｙ1が, 減少し猛烈な腹痛が襲ってきた" */
                    sprintf(buf, D_801706BC, ent->unk4);
                }
            }
        } else if (d != 0) {
            kind = 4;
            player_add_hp(-(v / 2), 0);
            player_heal_part(3, 2, -ent->unk26);
            if (flag) {
                /* " 1飲み過ぎ、ハラをこわして, 8Ｖｉｔａｌｉｔｙ1が減少した" */
                strncpy(buf, D_80170700, 0x38);
            } else {
                /* " 1食べ過ぎ、ハラをこわして, 8Ｖｉｔａｌｉｔｙ1が減少した" */
                strncpy(buf, D_8017073C, 0x38);
            }
        } else {
            player_add_hp(v, 0);
            if (flag) {
                /* " 8%s, 1を飲んで、8Ｖｉｔａｌｉｔｙ1が, 回復した" */
                sprintf(buf, D_80170618, ent->unk4);
            } else {
                /* " 8%s, 1を食べて、8Ｖｉｔａｌｉｔｙ1が, 回復した" */
                sprintf(buf, D_80170648, ent->unk4);
            }
            if (a->energy == 0xFF && d == 0) {
                ret = 1;
                text_show_timed(b, 1, buf, kind, 2);
                memset(buf, 0, 0x80);
                /* " 8Ｖｉｔａｌｉｔｙ1がフルの, 状態に戻った" */
                strncpy(buf, D_80170778, 0x29);
            }
        }
        text_show_timed(b, 1, buf, kind, 2);
        break;
    case 3:
        r = player_is_injured();
        if ((s16)r != 0) {
            for (i = 0; i < 5; i++) {
                (q->vars + 0x5A)[i] -= ent->unk26;
                if ((s16)(q->vars + 0x5A)[i] < 0) {
                    (q->vars + 0x5A)[i] = 0;
                }
            }
            event_draw_limb_status(a);
        }
        memset(buf, 0, 0x80);
        switch (ent->unk26) {
        case 60:
            if ((s16)r != 0) {
                /* " 傷が多少回復した" */
                strncpy(buf, D_801707A4, 0x11);
            } else {
                /* " 全身が軽くなった" */
                strncpy(buf, D_801707B8, 0x11);
            }
            break;
        case 180:
            if ((s16)r != 0) {
                /* " 傷がかなり回復した" */
                strncpy(buf, D_801707CC, 0x13);
            } else {
                /* " 全身が軽くなった" */
                strncpy(buf, D_801707B8, 0x11);
            }
            break;
        case 360:
            if ((s16)r != 0) {
                /* " 傷が完全に回復した" */
                strncpy(buf, D_801707E0, 0x13);
            } else {
                /* " 全身がとても軽くなった" */
                strncpy(buf, D_801707F4, 0x17);
            }
            break;
        }
        event_advance_clock(ent->unk26, 1);
        text_show(buf, 1, -1, 0, -1, 0, kind);
        break;
    case 1:
        break;
    default:
        return -1;
    }
    if (e != 0) {
        text_close();
    }
    return ret;
}

void effect_item_use_selected(void) {
    PlayerStatus *g = &player_status;
    Inventory *p;
    s16 id;
    s16 r;
    s32 i;

    if (effect_item_sel >= 0) {
        id = effect_item_menu_list[effect_item_sel];
        r = effect_item_use(g, D_801E0340[0].unk0[0], id, effect_item_full, 1);
        if (r >= 0) {
            if (r != 0) {
                effect_item_full = 1;
            }
            p = g->inventory;
            if (p->unk30 != 0) {
                for (i = 0; i < 8; i++) {
                    if (p->item_ids[i] == id) {
                        p->item_ids[i] = -1;
                        p->unk30--;
                        return;
                    }
                }
            }
        }
    }
}

s16 effect_item_menu_show(PlayerStatus *arg0, s16 arg1, s16 arg2) {
    Inventory *p = arg0->inventory;
    s32 i;
    s32 n;

    if (arg2 != 0) {
        sound_se_play(0x13);
        effect_item_sel = -1;
        effect_item_prompt_shown = 0;
        D_801DFEC2 = arg1;
        effect_item_full = 0;
        if (arg0->energy == 0xFF) {
            effect_item_full = 1;
        }
        for (i = 0; i < 8; i++) {
            effect_item_menu_list[i] = -1;
        }
        for (i = 0, n = 0; i < 8; i++) {
            if (p->item_ids[i] >= 0) {
                effect_item_menu_list[n++] = p->item_ids[i];
            }
        }
        return mail_menu_open(1, 0x40B, -2, p->unk30, 6, effect_item_menu_list, 4, 0x2969, 0x2BFF);
    }
    sound_se_play(effect_item_sel < 0 ? 8 : 0x11);
    return mail_menu_close();
}

s16 effect_item_input(PlayerStatus *arg0, s16 arg1) {
    s16 n = arg1;
    Player *q = arg0->player;
    GameVars *g = &action_vars;
    Inventory *p = arg0->inventory;

    if (q->flags & 0x4000) {
        if (mail_menu_get_state() == 1) {
            if (effect_item_prompt_shown == 0) {
                effect_item_prompt_shown = 1;
                /* "  8アイテム1を方向キー上下で,  選んで下さい,     決定 3○1 やめる4 ×" */
                text_show(D_8017080C, 3, -1, 0, -1, 0, 1);
            }
            if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
                if (effect_item_sel < 0) {
                    effect_item_sel = 0;
                }
                effect_item_menu_show(arg0, n, 0);
            } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
                if (effect_item_sel >= 0) {
                    effect_item_sel = -1;
                }
                effect_item_menu_show(arg0, n, 0);
            } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
                effect_item_sel = mail_menu_move(1);
            } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
                effect_item_sel = mail_menu_move(0);
            }
        }
        return 1;
    }
    if (p->unk30 == 0) {
        return 0;
    }
    if (roadmap_get_state() != 0) {
        return 0;
    }
    if (!(kaj_system.pad_prev & 0x800) && (kaj_system.pad_now & 0x800)) {
        if (*(s32 *)&g->unk24C != 0) {
            return 0;
        }
        if (effect_item_menu_show(arg0, n, 1) != 0) {
            q->flags |= 0x4000;
        }
    }
    if (effect_item_prompt_shown != 0 && mail_menu_get_state() == 0) {
        effect_item_prompt_shown = 0;
        text_close();
    }
    return 0;
}

s32 effect_weapon_add(s16 arg0, s16 arg1) {
    PlayerStatus *g = &player_status;
    Inventory *p = g->inventory;
    Player *q = g->player;
    void *r;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (p->weapon_ids[i] < 0) {
            p->weapon_ids[i] = arg0;
            r = mod_find(arg0 + 0x400);
            if (r != 0) {
                mod_setup(r, q->coord, 1, 0);
            }
            effect_weapon_calc_rate(i);
            return 1;
        }
    }
    if (arg1 != 0) {
        p->unkC[arg0]++;
    }
    return 0;
}

void effect_weapon_load_models(void) {
    PlayerStatus *g = &player_status;
    Inventory *p = g->inventory;
    Player *q = g->player;
    GameVars *s = &action_vars;
    void *r;
    s32 i;
    u16 id;

    p->armed = 1;
    object_load_weapon_mods();
    s->vars[0x3C] = 2;
    for (i = 0; i < 2; i++) {
        if (p->weapon_ids[i] >= 0) {
            id = p->weapon_ids[i] + 0x400;
            s->vars[0x3C]--;
            r = mod_find(id);
            if (r != 0) {
                mod_setup(r, q->coord, 1, 0);
                if (p->weapon_slot == i) {
                    p->weapon_model = (s32)r;
                }
            }
            effect_weapon_calc_rate(i);
        }
    }
    thing_set_animate(3, 7, 1);
    thing_set_flag10(3, 7, 1);
}

void effect_weapon_reset(void) {
    Inventory *p = D_801E0768[0];

    p->weapon_shown = 0;
    p->weapon_state = 0;
    p->unk0 = 0;
    p->weapon_model = 0;
    p->armed = 0;
}

void effect_weapon_check_fire_frame(s32 arg0) {
    PlayerStatus *g = &player_status;
    Inventory *p = g->inventory;
    Player *q = g->player;
    Unk_80188FEC *e = effect_weapon_find(p->weapon_ids[p->weapon_slot]);

    if (e != NULL && e->unk4C == arg0) {
        if (g->target_npc != 0) {
            if (!(q->flags & 0x400)) {
                q->flags |= 0x400;
            }
        }
        player_weapon_sound(e->unk0, 1);
    }
}

s32 effect_weapon_list(s16 arg0, s16 *arg1, s16 *arg2) {
    Inventory *p = D_801E0768[0];
    s32 i;
    s32 n;
    s32 m;

    for (i = 0, n = 0; i < 2; i++) {
        if (p->weapon_ids[i] >= 0) {
            if (arg0 != 0) {
                arg2[n] = p->weapon_ids[i];
            }
            n++;
        }
    }
    for (i = 0, m = 0; i < 0x12; i++) {
        if (p->unkC[i] != 0) {
            if (arg0 == 0) {
                arg2[m] = i;
            }
            m++;
        }
    }
    if (arg0 != 0) {
        if (n != 2) {
            return 0;
        }
        *arg1 = n;
        return 1;
    }
    *arg1 = m;
    if (n < 2 && m != 0) {
        return 1;
    }
    return 0;
}

void effect_weapon_free_records(void) {
    SceneTables *p = &object_scene_tables;
    if (p->unk30 != 0) {
        if (p->unk58 != NULL) {
            free3(p->unk58);
        }
        p->unk30 = 0;
        p->unk58 = NULL;
    }
}

Unk_80188FEC *effect_weapon_find(s16 arg0) {
    SceneTables *p = &object_scene_tables;
    s32 n = p->unk30;
    Unk_80188FEC *e = p->unk58;
    s32 i;
    if (n == 0 || arg0 < 0) {
        return NULL;
    }
    for (i = 0; i < p->unk30; i++, e++) {
        if (e->unk0 == arg0) {
            return e;
        }
    }
    return NULL;
}

s32 effect_item_add(s16 arg0, s16 arg1) {
    Inventory *p = D_801E0768[0];
    s32 i;

    if (arg1 == 2) {
        p->unk42 = arg0 - 0x64;
        return 1;
    }
    for (i = 0; i < 8; i++) {
        if (p->item_ids[i] < 0) {
            p->item_ids[i] = arg0;
            p->unk30++;
            return 1;
        }
    }
    return 0;
}

s32 effect_item_remove(s16 arg0, s16 arg1) {
    Inventory *p = D_801E0768[0];
    s32 i;

    if (arg1 == 2) {
        p->unk42 = 0xF;
        return 1;
    }
    if (p->unk30 == 0) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (p->item_ids[i] == arg0) {
            p->item_ids[i] = -1;
            p->unk30--;
            return 1;
        }
    }
    return 0;
}

void effect_item_free_records(void) {
    SceneTables *p = &object_scene_tables;
    if (p->unk2C != 0) {
        if (p->unk48 != 0) {
            free3((void *)p->unk48);
        }
        p->unk2C = 0;
        p->unk48 = 0;
    }
}

Unk_801891A4 *effect_item_find(s16 arg0) {
    SceneTables *p = &object_scene_tables;
    s32 n = p->unk2C;
    Unk_801891A4 *e = (Unk_801891A4 *)p->unk48;
    s32 i;
    if (n == 0 || arg0 < 0) {
        return NULL;
    }
    for (i = 0; i < p->unk2C; i++, e++) {
        if (e->unk0 == arg0) {
            return e;
        }
    }
    return NULL;
}
