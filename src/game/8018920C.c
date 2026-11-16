#include "common.h"
#include "game/types.h"

s32 DisableEvent(s32 event);
s32 CloseEvent(s32 event);
s32 event_enter_id;
s32 event_leave_id;
s32 event_mod_finish_id;
extern s32 D_801DFF50;
void event_clock_tick(s16 a);
void (*D_801DFEDC)(void);
typedef struct { s32 unk0; s16 unk4; s16 unk6; } Unk_801E024C;
extern Unk_801E024C D_801E024C[];
void (*D_801DFED8)(s32 *a, Unk_801E024C *b);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8[1]; } Unk_8018A8CC_58;
typedef struct { u8 unk0[0x58]; Unk_8018A8CC_58 *unk58; } Unk_8018A8CC;
void sprite_restore_clut(s32 a, s32 b, s32 c);
void sprite_set_clut_entry(s32 a, s32 b, s32 c);
s16 event_blink0_on;
s16 event_blink1_on;
s16 event_blink2_on;
s16 event_blink0_timer;
s16 event_blink1_timer;
s16 event_blink2_timer;
void sprite_fill_clut(s32 a, s32 b, s32 c, s32 d);
extern GameVars action_vars;
extern ScreenLight screen_light;
void event_draw_clock_digits(s32 a, s16 b);
void event_update_daylight(s32 a);
void SetFarColor(s32 r, s32 g, s32 b);
typedef struct Unk_80188FEC { u16 unk0; u8 unk2[0x22]; u16 unk24; u8 unk26[0x3A]; } Unk_80188FEC;
extern PlayerStatus player_status;
void (*D_801DFEE8)(s32 *a);
Unk_80188FEC *effect_weapon_find(s16 arg0);
void player_weapon_sound(s16 a, s32 b);
void mod_set_anim(s32 a, s32 b, s32 c);
void sound_se_stop(s32 a);
void sound_se_play(s32 arg0);
void event_clock_add_minute(PlayerStatus *a, GameVars *b, s32 c, s32 d);
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; } Unk_8018AB48_10;
typedef struct { s16 unk0; s16 unk2; } Unk_8018AB48_1C;
typedef struct { u8 unk0[0x1C]; Unk_8018AB48_1C *unk1C; } Unk_8018AB48_r;
typedef struct { u8 unk0[0x6E]; s16 unk6E; } Unk_8018AB48;
u16 *sprite_find(u16 arg0);
s32 MoveImage(void *rect, s32 x, s32 y);
s32 OpenEvent(u32 desc, s32 spec, s32 mode, s32 (*func)(void));
s32 EnableEvent(s32 event);
extern char D_801DFD14[];
void kaj_abend(s32 a, char *b, char *c, s32 d);
s32 object_deliver_area_events(void);
s32 player_leave_trigger(void);
s32 mod_finish_handler(void);
extern EventState event_state;
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; void *unk10; } Unk_801895E0;
s16 (*D_801DFEE0)(Unk_801895E0 *a);
void action_reset(s16 arg0);
void text_close(void);
s16 action_run_npc_event(u16 arg0, s16 arg1);
s16 thing_run_script(s32 a, s32 b, s32 c);
s16 action_run_trigger_leave(void *arg0);
extern Player *player_status_player[];
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; } Unk_8018970C;
s16 (*D_801DFED4)(Unk_8018970C *a);
void kaj_tss_release(s32 arg0);
void kaj_pad_reset(s32 a);
void kaj_view_clear_vram(void);
void mail_menu_clear_rows(MailMenu *p);
void effect_item_use_selected(void);
void sound_bgm_stop(void);
void event_draw_gauge(PlayerStatus *a);
extern u8 event_digit_segments[];
typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 unk3; } Unk_801D7730;
extern Unk_801D7730 event_limb_colors[];
void mail_check_schedule(s16 a, s16 b);
void event_draw_limb_status(PlayerStatus *arg0);
s16 (*D_801DFEE4)(Unk_801895E0 *a);
s16 action_run_trigger_enter(void *arg0);
void block_enter_area(u32 arg0);
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void event_drain_gauge(PlayerStatus *a);
u16 event_blink0_color;
u16 event_blink1_color;
u16 event_blink2_color;

void event_open(void) {
    event_enter_id = OpenEvent(0xF3000000, 2, 0x1000, object_deliver_area_events);
    event_leave_id = OpenEvent(0xF3000001, 2, 0x1000, player_leave_trigger);
    event_mod_finish_id = OpenEvent(0xF3000002, 2, 0x1000, mod_finish_handler);
    if (event_enter_id == -1 || event_leave_id == -1 || event_mod_finish_id == -1) {
        kaj_abend(0xC, "Can not Create User Defined Event", D_801DFD14, 0x34);
    }
    if (EnableEvent(event_enter_id) == 0) {
        kaj_abend(0xC, "Can not Enable to ENTER Event", D_801DFD14, 0x37);
    }
    if (EnableEvent(event_leave_id) == 0) {
        kaj_abend(0xC, "Can not Enable to LEAVE Event", D_801DFD14, 0x3A);
    }
    if (EnableEvent(event_mod_finish_id) == 0) {
        kaj_abend(0xC, "Can not Enable to MOD Finish Event", D_801DFD14, 0x3D);
    }
    D_801DFF50 = 0;
}

void event_handle_enter(Unk_801895E0 *a) {
    Player *q = player_status_player[0];
    EventState *p = &event_state;
    GameVars *g = &action_vars;
    s32 hi;
    s32 lo;

    p->trigger = a->unkC;
    p->trigger_type = a->unk8;
    p->cross_flags = 0;
    p->circle_flags = 0;
    p->cross_set = -1;
    p->circle_set = -1;
    if (D_801DFEE4 != NULL && D_801DFEE4(a) != 0) {
        return;
    }
    switch (a->unk8) {
    case 0xFC:
        if (action_run_npc_event(a->unkC, 1) == 0) {
            q->flags &= 0xFFFB;
            action_reset(0);
        } else {
            p->state = 1;
        }
        break;
    case 0xFD:
        hi = ((u8 *)&a->unkC)[1] >> 4;
        lo = (u16)a->unkC & 0xFFF;
        if (thing_run_script(hi, lo, 1) == 0) {
            if (hi == 0 && lo == 0) {
                /* " 7クルマ1に乗る       3○" */
                text_show(" 7\203N\203\213\203}1\202\311\217\346\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
            } else {
                q->flags &= 0xFFFB;
                action_reset(0);
            }
        } else {
            p->state = 1;
        }
        break;
    case 0xFE:
        if ((s16)g->vars[0x3E] < 5) {
            /* "営業時間 ５：００〜２４：００" */
            text_show("\211c\213\306\216\236\212\324 \202T\201F\202O\202O\201`\202Q\202S\201F\202O\202O", 1, -1, 0, -1, 0, 1);
        } else {
            switch (((u8 *)&a->unkC)[1]) {
            case 1:
                /* " 7バス停 Ｃ１０１系統   3○" */
                text_show(" 7\203o\203X\222\342 \202b\202P\202O\202P\214n\223\235   3\201\233", 1, -1, 8, -1, 0, 1);
                break;
            case 2:
                /* " 7バス停 Ｃ１０２系統   3○" */
                text_show(" 7\203o\203X\222\342 \202b\202P\202O\202Q\214n\223\235   3\201\233", 1, -1, 8, -1, 0, 1);
                break;
            case 3:
                /* " 7バス停 Ｃ１０３系統   3○" */
                text_show(" 7\203o\203X\222\342 \202b\202P\202O\202R\214n\223\235   3\201\233", 1, -1, 8, -1, 0, 1);
                break;
            default:
                /* " 7バス停" */
                text_show(" 7\203o\203X\222\342", 1, -1, 0, -1, 0, 1);
                break;
            }
        }
        break;
    case 0xFF:
        /* " 7電話ボックス       3○" */
        text_show(" 7\223d\230b\203{\203b\203N\203X       3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0x80:
        block_enter_area(a->unkC);
        break;
    default:
        if (action_run_trigger_enter(a->unk10) == 0) {
            q->flags &= 0xFFFB;
            action_reset(0);
            break;
        }
    case 0xF7:
        p->state = 1;
        break;
    }
}

void event_handle_leave(Unk_801895E0 *a) {
    EventState *p = &event_state;

    p->trigger = a->unkC;
    p->trigger_type = a->unk8;
    if (p->trigger_type != 0x40) {
        action_reset(0);
        text_close();
    }
    if (D_801DFEE0 != NULL && D_801DFEE0(a) != 0) {
        return;
    }
    switch (a->unk8) {
    case 0xFC:
        if (action_run_npc_event(a->unkC, 0) == 0) {
            action_reset(0);
        } else {
            p->state = 1;
        }
        break;
    case 0xFD:
        if (thing_run_script(((u8 *)&a->unkC)[1] >> 4, (u16)a->unkC & 0xFFF, 0) == 0) {
            action_reset(0);
        } else {
            p->state = 1;
        }
        break;
    default:
        if (action_run_trigger_leave(a->unk10) == 0) {
            action_reset(0);
            break;
        }
    case 0xF7:
        p->state = 1;
        break;
    }
}

s16 event_handle_effect_done(Unk_8018970C *a) {
    GameVars *g = &action_vars;
    Player *q = player_status_player[0];
    MailMenu *p = &g->mail_menu;
    s16 r = 0;

    kaj_tss_release(a->unk8);
    switch (a->unk10) {
    case 0:
        if (a->unkC == 0) {
            g->unk244 = -1;
        }
        kaj_pad_reset(1);
        break;
    case 1:
        if (a->unkC == 0) {
            g->unk244 = -1;
        }
        r = 1;
        kaj_view_clear_vram();
        break;
    case 11:
        if (a->unkC == 0) {
            g->unk244 = -1;
        }
        p->state = 1;
        break;
    case 12:
        if (a->unkC == 0) {
            g->unk244 = -1;
        }
        p->state = 0;
        g->menu_busy = 0;
        if (p->icon_sprite == -2) {
            mail_menu_clear_rows(p);
        }
        if (q->flags & 0x4000) {
            a->unk8 = 999999;
            q->flags &= 0xBFFF;
            effect_item_use_selected();
        }
        break;
    case 13:
        if (a->unkC == 0) {
            g->unk244 = -1;
        }
        sound_bgm_stop();
        break;
    }
    if (r == 0 && D_801DFED4 != NULL) {
        r = D_801DFED4(a);
    }
    return r;
}

void event_close(void) {
    D_801DFF50 = 0;
    DisableEvent(event_enter_id);
    DisableEvent(event_leave_id);
    DisableEvent(event_mod_finish_id);
    CloseEvent(event_enter_id);
    CloseEvent(event_leave_id);
    CloseEvent(event_mod_finish_id);
}

void func_80189928(s32 *a) {
    Unk_801E024C *p = &D_801E024C[a[2]];
    p->unk0 = -1;
    p->unk4 = 0;
    if (D_801DFED8 != NULL) {
        D_801DFED8(a, p);
    }
}

void event_handle_tick(s16 a) {
    event_clock_tick(a);
    if (D_801DFEDC != NULL) {
        D_801DFEDC();
    }
}

void event_handle_mod_finish(s32 *a) {
    PlayerStatus *g = &player_status;
    Player *q = g->player;
    Inventory *p = g->inventory;
    Unk_80188FEC *e;

    if (a[3] == 1) {
        switch (p->weapon_state) {
        case 0:
            p->weapon_state = 2;
            break;
        case 1:
            q->flags &= 0x7FFF;
            p->weapon_state = 0;
            p->weapon_shown = 0;
            break;
        case 4:
            p->weapon_state = 5;
            break;
        case 6:
            p->weapon_state = 7;
            e = effect_weapon_find(p->weapon_ids[p->weapon_slot]);
            if (e != NULL) {
                player_weapon_sound(e->unk0, 0);
            }
            mod_set_anim(p->weapon_model, 3, 0);
            break;
        case 7:
            p->weapon_state = 3;
            break;
        }
    } else if (D_801DFEE8 != NULL) {
        D_801DFEE8(a);
    }
}

void event_drain_gauge(PlayerStatus *a) {
    GameVars *g = &action_vars;
    Inventory *p = a->inventory;
    Unk_80188FEC *e;
    s32 n = 1;

    if (a->mutant == 0 && a->hours_awake >= 0x10) {
        switch (a->hours_awake >> 4) {
        case 1:
            n = 2;
            break;
        case 2:
            n = 3;
            break;
        case 3:
            n = 4;
            break;
        case 4:
            n = 8;
            break;
        case 5:
            n = 0x10;
            break;
        default:
            n = 0x20;
            break;
        }
    }
    switch (a->limb_state[3]) {
    case 1:
        n = (n * 3) >> 1;
        break;
    case 2:
        n *= 2;
        break;
    case 3:
        n *= 4;
        break;
    }
    g->drain_count++;
    e = effect_weapon_find(p->weapon_ids[p->weapon_slot]);
    if (e != NULL && g->drain_count == 6) {
        n += e->unk24;
        g->drain_count = 0;
    }
    a->infected = 0;
    a->energy -= n;
    event_draw_gauge(a);
}

void event_draw_clock_digits(s32 a, s16 b) {
    s16 i;
    s16 y;
    s16 d;
    s32 t = a * 2;
    d = b / 10;
    y = (s16)t * 7 + 8;
    for (i = 0; i < 7; i++) {
        if ((event_digit_segments[d] >> i) & 1) {
            sprite_set_clut_entry(0x409, y - i, 0x7FFF);
        } else {
            sprite_set_clut_entry(0x409, y - i, 0);
        }
    }
    d = b % 10;
    y = (s16)(t + 1) * 7 + 8;
    for (i = 0; i < 7; i++) {
        if ((event_digit_segments[d] >> i) & 1) {
            sprite_set_clut_entry(0x409, y - i, 0x7FFF);
        } else {
            sprite_set_clut_entry(0x409, y - i, 0);
        }
    }
}

void event_draw_limb_status(PlayerStatus *a) {
    GameVars *g = &action_vars;
    Unk_801D7730 *c;
    s16 f = 0;
    s32 i;
    s32 n;
    s32 v;

    for (i = 0; i < 5; i++) {
        v = g->limb_damage[i];
        if (v < 0x10) {
            a->limb_state[i] = 0;
        } else if (v >= 0x10 && v < 0xA6) {
            a->limb_state[i] = 1;
        } else if (v >= 0xA6 && v < 0xF0) {
            a->limb_state[i] = 2;
        } else {
            a->limb_state[i] = 3;
            g->limb_damage[i] = 0xF0;
        }
        n = a->limb_state[i];
        if (a->mutant != 0) {
            if (n == 0) {
                n = 4;
            }
            if (i == 0) {
                f = 1;
            }
        }
        c = &event_limb_colors[n];
        sprite_set_clut_entry(0x400, i + 0x40, (c->unk0 | (c->unk1 << 5) | (c->unk2 << 10)) & 0xFFFF);
        if (f != 0) {
            sprite_set_clut_entry(0x400, 0x45, (c->unk0 | (c->unk1 << 5) | (c->unk2 << 10)) & 0xFFFF);
            f = 0;
        }
    }
}

void event_update_hud(PlayerStatus *a) {
    s32 i;
    s32 m;
    Inventory *p;
    u16 n;

    if (a->drain_pending != 0) {
        a->drain_pending = 0;
        event_drain_gauge(a);
    }
    if (a->limb_redraw != 0) {
        a->limb_redraw = 0;
        event_draw_limb_status(a);
    }
    if (a->weapon_redraw != 0) {
        p = a->inventory;
        a->weapon_redraw = 0;
        m = p->weapon_rate[p->weapon_slot] * 16 / 100;
        sprite_restore_clut(0x400, 0x50, 0x5F);
        for (i = 0x50; i < m + 0x50; i++) {
            sprite_set_clut_entry(0x400, i, 0x7E8A);
        }
    }
    if (event_blink0_on != 0) {
        n = event_blink0_timer;
        if ((s16)((s16)n % 3) == 0) {
            sprite_set_clut_entry(0x400, 1, event_blink0_color);
        } else if ((s16)((s16)n % 3) == 2) {
            sprite_set_clut_entry(0x400, 1, 0);
        }
        if ((s16)n >= 11) {
            event_blink0_on = 0;
            event_blink0_timer = 0;
            sprite_fill_clut(0x400, 1, 3, 0);
        }
        event_blink0_timer++;
    }
    if (event_blink1_on != 0) {
        n = event_blink1_timer;
        if ((s16)((s16)n % 3) == 0) {
            sprite_set_clut_entry(0x400, 2, event_blink1_color);
        } else if ((s16)((s16)n % 3) == 2) {
            sprite_set_clut_entry(0x400, 2, 0);
        }
        if ((s16)n >= 11) {
            event_blink1_on = 0;
            event_blink1_timer = 0;
            sprite_fill_clut(0x400, 1, 3, 0);
        }
        event_blink1_timer++;
    }
    if (event_blink2_on != 0) {
        n = event_blink2_timer;
        if ((s16)((s16)n % 3) == 0) {
            sprite_set_clut_entry(0x400, 3, event_blink2_color);
        } else if ((s16)((s16)n % 3) == 2) {
            sprite_set_clut_entry(0x400, 3, 0);
        }
        if ((s16)n >= 11) {
            event_blink2_on = 0;
            event_blink2_timer = 0;
            sprite_fill_clut(0x400, 1, 3, 0);
        }
        event_blink2_timer++;
    }
}

void event_draw_hud(void) {
    PlayerStatus *q = &player_status;
    s32 i;
    s32 n;
    s32 v;
    s32 m;

    sprite_fill_clut(0x400, 0x40, 0x45, 0);
    if (q->energy <= 0) {
        q->energy = 0;
        n = 0;
        sound_se_stop(4);
    } else {
        n = q->energy * 0x24 / 255 + 0x10;
        v = (q->energy << 12) / 255;
        if (q->unk38 != 0) {
            if (v >= 0x400) {
                q->unk38 = 0;
                sound_se_stop(4);
            }
        } else if (v < 0x400) {
            q->unk38 = 1;
            sound_se_play(4);
        }
    }
    sprite_restore_clut(0x400, 0x10, 0x33);
    for (i = 0x10; i < 0x34; i++) {
        if (n < i) {
            sprite_set_clut_entry(0x400, i, 0x1421);
        }
    }
    event_draw_limb_status(q);
    m = q->inventory->weapon_rate[q->inventory->weapon_slot] * 0x10 / 100;
    sprite_restore_clut(0x400, 0x50, 0x5F);
    for (n = 0x50; n < m + 0x50; n++) {
        sprite_set_clut_entry(0x400, n, 0x7E8A);
    }
}

void event_update_daylight(s32 a) {
    ScreenLight *c = &screen_light;
    GameVars *g = &action_vars;
    s16 m = g->vars[0x3E];
    s16 n;
    s32 v;

    if (m == 5) {
        if ((s16)g->vars[0x3F] == 0 || (s16)a != 0) {
            c->dark = 1;
        }
        c->unk8[0] = g->vars[0x3F] + 1;
        if (c->unk0[0] != 0) {
            n = c->unk8[0];
            v = n * 0x2A + n * 2 / 3 + 0x600;
            v = v * 0x7A >> 12;
            SetFarColor(v, v, v);
        }
    } else if (m >= 6 && m < 0x12) {
        if ((m == 6 && (s16)g->vars[0x3F] == 0) || (s16)a != 0) {
            c->dark = 0;
            c->unk8[0] = 0;
            if (c->unk0[0] != 0) {
                SetFarColor(0x7A, 0x7A, 0x7A);
            }
        }
    } else if (m == 0x12) {
        if ((s16)g->vars[0x3F] == 0 || (s16)a != 0) {
            c->dark = 1;
        }
        c->unk8[0] = 0x3C - g->vars[0x3F];
        if (c->unk0[0] != 0) {
            n = c->unk8[0];
            v = n * 0x2A + n * 2 / 3 + 0x600;
            v = v * 0x7A >> 12;
            SetFarColor(v, v, v);
        }
    } else if ((m == 0x13 && (s16)g->vars[0x3F] == 0) || (s16)a != 0) {
        c->dark = 1;
        c->unk8[0] = 0;
        if (c->unk0[0] != 0) {
            SetFarColor(0x2D, 0x2D, 0x2D);
        }
    }
}

void event_clock_add_minute(PlayerStatus *a, GameVars *b, s32 c, s32 d) {
    s32 i;
    s16 e = c;

    b->vars[0x3F]++;
    if ((s16)b->vars[0x3F] >= 60) {
        b->vars[0x3F] -= 60;
        b->vars[0x3E]++;
        if ((s16)d == 0) {
            a->hours_awake++;
        }
        if ((s16)b->vars[0x3E] >= 24) {
            a->unk34 = 0;
            b->vars[0x3E] -= 24;
            b->vars[0x3D]++;
            b->vars[0x40] = (s16)b->vars[0x3D] % 2;
            if ((s16)b->vars[0x3D] >= 99) {
                b->vars[0x3D] = 98;
            }
            if (e == 0) {
                event_draw_clock_digits(0, b->vars[0x3D] + 1);
            }
        }
        if (e == 0) {
            event_draw_clock_digits(1, (s16)b->vars[0x3E]);
        }
        mail_check_schedule(b->vars[0x3D], b->vars[0x3E]);
        for (i = 0; i < 5; i++) {
            if (a->mutant != 0) {
                if (b->limb_damage[i] > 0) {
                    b->limb_damage[i] -= 0x10;
                    if (b->limb_damage[i] < 0) {
                        b->limb_damage[i] = 0;
                    }
                }
            } else if (a->limb_state[i] != 3) {
                if (b->limb_damage[i] > 0) {
                    b->limb_damage[i] -= 4;
                    if (b->limb_damage[i] < 0) {
                        b->limb_damage[i] = 0;
                    }
                }
            }
        }
    }
    if (e == 0) {
        event_draw_clock_digits(2, (s16)b->vars[0x3F]);
    }
}

void event_draw_gauge(PlayerStatus *a) {
    s32 n;
    s32 t;
    s32 i;
    if (a->energy <= 0) {
        a->energy = 0;
        n = 0;
        sound_se_stop(4);
    } else {
        n = a->energy * 36 / 255 + 0x10;
        t = (a->energy << 12) / 255;
        if (a->unk38 != 0) {
            if (t >= 0x400) {
                a->unk38 = 0;
                sound_se_stop(4);
            }
        } else if (t < 0x400) {
            a->unk38 = 1;
            sound_se_play(4);
        }
    }
    sprite_restore_clut(0x400, 0x10, 0x33);
    for (i = 0x10; i < 0x34; i++) {
        if (n < i) {
            sprite_set_clut_entry(0x400, i, 0x1421);
        }
    }
}

void event_draw_percent_gauge(Unk_8018A8CC *a) {
    s32 i;
    s32 n;
    Unk_8018A8CC_58 *p = a->unk58;
    n = p->unk8[p->unk2] * 16 / 100;
    sprite_restore_clut(0x400, 0x50, 0x5F);
    for (i = 0x50; i < n + 0x50; i++) {
        sprite_set_clut_entry(0x400, i, 0x7E8A);
    }
}

void event_set_blink(s16 a, s16 b) {
    switch (a) {
    case 0:
        event_blink0_on = b;
        event_blink0_timer = 0;
        break;
    case 1:
        event_blink1_on = b;
        event_blink1_timer = 0;
        break;
    case 2:
        event_blink2_on = b;
        event_blink2_timer = 0;
        break;
    }
    if (b == 0) {
        sprite_fill_clut(0x400, 1, 3, 0);
    }
}

void event_clock_tick(s16 a) {
    PlayerStatus *q = &player_status;
    GameVars *p = &action_vars;
    event_clock_add_minute(q, p, 0, 0);
    if ((s16)((s16)p->vars[0x3F] % 10) == p->drain_minute) {
        q->drain_pending = 1;
    }
    if (a != 0) {
        event_update_daylight(0);
    }
}

void event_show_clock(s16 a) {
    GameVars *p = &action_vars;
    event_draw_clock_digits(0, p->vars[0x3D] + 1);
    event_draw_clock_digits(1, p->vars[0x3E]);
    event_draw_clock_digits(2, p->vars[0x3F]);
    screen_light.unk0[0] = a;
    SetFarColor(0, 0, 0);
    if (a != 0) {
        event_update_daylight(1);
    }
}

void event_draw_compass(Unk_8018AB48 *a) {
    Unk_8018AB48_10 rect;
    Unk_8018AB48_r *p = (Unk_8018AB48_r *)sprite_find(0x40E);
    if (p != NULL) {
        rect.unk0 = ((a->unk6E * 0xC0000 / 360) >> 14) + 0x140;
        rect.unk2 = 0x160;
        rect.unk4 = 0xC;
        rect.unk6 = 0x10;
        MoveImage(&rect, p->unk1C->unk0, p->unk1C->unk2);
    }
}

void event_advance_clock(s16 a, s16 b) {
    s16 i;
    PlayerStatus *q = &player_status;
    GameVars *p = &action_vars;
    for (i = 0; i < a; i++) {
        event_clock_add_minute(q, p, 1, b);
    }
    event_draw_clock_digits(0, p->vars[0x3D] + 1);
    event_draw_clock_digits(1, p->vars[0x3E]);
    event_draw_clock_digits(2, p->vars[0x3F]);
}
