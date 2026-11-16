#include "common.h"

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
typedef struct { s32 unk0; s16 unk4; s16 unk6; } Unk_801E056C;
typedef struct { s16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; u16 unkA; s16 unkC; s16 unkE; u16 unk10; s16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 *unk1C; } Unk_801E058C;
typedef struct {
    u16 unk0[0x5A];
    s16 unkB4[5];
    u8 unkBE[0x22];
    u8 unkE0[0x11C];
    s16 unk1FC;
    s16 unk1FE;
    u8 unk200[4];
    Unk_801E056C unk204[4];
    Unk_801E058C unk224;
    s32 unk244;
    u8 unk248[4];
    s16 unk24C;
} Unk_801E0368;
extern Unk_801E0368 D_801E0368;
typedef struct {
    s16 unk0[3];
    s16 unk6;
    s16 unk8[3];
    s16 unkE;
    s16 unk10;
} Unk_801E1040;
extern Unk_801E1040 D_801E1040;
void event_draw_clock_digits(s32 a, s16 b);
void event_update_daylight(s32 a);
void SetFarColor(s32 r, s32 g, s32 b);
typedef struct { u16 unk0; u8 unk2[0x22]; u16 unk24; u8 unk26[0x3A]; } Unk_80188FEC;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4[2];
    s16 unk8[2];
    s16 unkC[0x12];
    s16 unk30;
    s16 unk32[8];
    s16 unk42;
    s16 unk44;
    s16 unk46;
    u16 unk48;
    u8 unk4A[2];
    s32 unk4C;
} Unk_801E0768;
typedef struct { u8 unk0[0x42]; u16 unk42; u8 unk44[0x5C]; u8 unkA0[4]; } Unk_801E0710_5C;
typedef struct {
    s16 unk0;
    u8 unk2[0x2A];
    s16 unk2C;
    u8 unk2E[6];
    s16 unk34;
    s16 unk36;
    s16 unk38;
    s16 unk3A[5];
    s16 unk44;
    s16 unk46;
    s16 unk48;
    s16 unk4A;
    s32 unk4C;
    u8 unk50[8];
    Unk_801E0768 *unk58;
    Unk_801E0710_5C *unk5C;
} Unk_801E0710;
extern Unk_801E0710 D_801E0710;
void (*D_801DFEE8)(s32 *a);
Unk_80188FEC *effect_weapon_find(s16 arg0);
void player_weapon_sound(s16 a, s32 b);
void mod_set_anim(s32 a, s32 b, s32 c);
void sound_se_stop(s32 a);
void sound_se_play(s32 arg0);
void event_clock_add_minute(Unk_801E0710 *a, Unk_801E0368 *b, s32 c, s32 d);
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
typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 unk10[2];
    u16 unk12;
} Unk_801DFFE8;
extern Unk_801DFFE8 D_801DFFE8;
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; void *unk10; } Unk_801895E0;
s16 (*D_801DFEE0)(Unk_801895E0 *a);
void action_reset(s16 arg0);
void text_close(void);
s16 action_run_npc_event(u16 arg0, s16 arg1);
s16 thing_run_script(s32 a, s32 b, s32 c);
s16 action_run_trigger_leave(void *arg0);
extern Unk_801E0710_5C *D_801E076C[];
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; } Unk_8018970C;
s16 (*D_801DFED4)(Unk_8018970C *a);
void kaj_tss_release(s32 arg0);
void kaj_pad_reset(s32 a);
void kaj_view_clear_vram(void);
void mail_menu_clear_rows(Unk_801E058C *p);
void effect_item_use_selected(void);
void sound_bgm_stop(void);
void event_draw_gauge(Unk_801E0710 *a);
extern u8 event_digit_segments[];
typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 unk3; } Unk_801D7730;
extern Unk_801D7730 event_limb_colors[];
void mail_check_schedule(s16 a, s16 b);
void event_draw_limb_status(Unk_801E0710 *arg0);
s16 (*D_801DFEE4)(Unk_801895E0 *a);
s16 action_run_trigger_enter(void *arg0);
void block_enter_area(u32 arg0);
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void event_drain_gauge(Unk_801E0710 *a);
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
    Unk_801E0710_5C *q = D_801E076C[0];
    Unk_801DFFE8 *p = &D_801DFFE8;
    Unk_801E0368 *g = &D_801E0368;
    s32 hi;
    s32 lo;

    p->unk0 = a->unkC;
    p->unk4 = a->unk8;
    p->unkC = 0;
    p->unk8 = 0;
    p->unkE = -1;
    p->unkA = -1;
    if (D_801DFEE4 != NULL && D_801DFEE4(a) != 0) {
        return;
    }
    switch (a->unk8) {
    case 0xFC:
        if (action_run_npc_event(a->unkC, 1) == 0) {
            q->unk42 &= 0xFFFB;
            action_reset(0);
        } else {
            p->unk6 = 1;
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
                q->unk42 &= 0xFFFB;
                action_reset(0);
            }
        } else {
            p->unk6 = 1;
        }
        break;
    case 0xFE:
        if ((s16)g->unk0[0x3E] < 5) {
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
            q->unk42 &= 0xFFFB;
            action_reset(0);
            break;
        }
    case 0xF7:
        p->unk6 = 1;
        break;
    }
}

void event_handle_leave(Unk_801895E0 *a) {
    Unk_801DFFE8 *p = &D_801DFFE8;

    p->unk0 = a->unkC;
    p->unk4 = a->unk8;
    if (p->unk4 != 0x40) {
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
            p->unk6 = 1;
        }
        break;
    case 0xFD:
        if (thing_run_script(((u8 *)&a->unkC)[1] >> 4, (u16)a->unkC & 0xFFF, 0) == 0) {
            action_reset(0);
        } else {
            p->unk6 = 1;
        }
        break;
    default:
        if (action_run_trigger_leave(a->unk10) == 0) {
            action_reset(0);
            break;
        }
    case 0xF7:
        p->unk6 = 1;
        break;
    }
}

s16 event_handle_effect_done(Unk_8018970C *a) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801E0710_5C *q = D_801E076C[0];
    Unk_801E058C *p = &g->unk224;
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
        p->unk0 = 1;
        break;
    case 12:
        if (a->unkC == 0) {
            g->unk244 = -1;
        }
        p->unk0 = 0;
        g->unk24C = 0;
        if (p->unkC == -2) {
            mail_menu_clear_rows(p);
        }
        if (q->unk42 & 0x4000) {
            a->unk8 = 999999;
            q->unk42 &= 0xBFFF;
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
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0710_5C *q = g->unk5C;
    Unk_801E0768 *p = g->unk58;
    Unk_80188FEC *e;

    if (a[3] == 1) {
        switch (p->unk48) {
        case 0:
            p->unk48 = 2;
            break;
        case 1:
            q->unk42 &= 0x7FFF;
            p->unk48 = 0;
            p->unk44 = 0;
            break;
        case 4:
            p->unk48 = 5;
            break;
        case 6:
            p->unk48 = 7;
            e = effect_weapon_find(p->unk4[p->unk2]);
            if (e != NULL) {
                player_weapon_sound(e->unk0, 0);
            }
            mod_set_anim(p->unk4C, 3, 0);
            break;
        case 7:
            p->unk48 = 3;
            break;
        }
    } else if (D_801DFEE8 != NULL) {
        D_801DFEE8(a);
    }
}

void event_drain_gauge(Unk_801E0710 *a) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801E0768 *p = a->unk58;
    Unk_80188FEC *e;
    s32 n = 1;

    if (a->unk2C == 0 && a->unk36 >= 0x10) {
        switch (a->unk36 >> 4) {
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
    switch (a->unk3A[3]) {
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
    g->unk1FC++;
    e = effect_weapon_find(p->unk4[p->unk2]);
    if (e != NULL && g->unk1FC == 6) {
        n += e->unk24;
        g->unk1FC = 0;
    }
    a->unk4A = 0;
    a->unk0 -= n;
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

void event_draw_limb_status(Unk_801E0710 *a) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801D7730 *c;
    s16 f = 0;
    s32 i;
    s32 n;
    s32 v;

    for (i = 0; i < 5; i++) {
        v = g->unkB4[i];
        if (v < 0x10) {
            a->unk3A[i] = 0;
        } else if (v >= 0x10 && v < 0xA6) {
            a->unk3A[i] = 1;
        } else if (v >= 0xA6 && v < 0xF0) {
            a->unk3A[i] = 2;
        } else {
            a->unk3A[i] = 3;
            g->unkB4[i] = 0xF0;
        }
        n = a->unk3A[i];
        if (a->unk2C != 0) {
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

void event_update_hud(Unk_801E0710 *a) {
    s32 i;
    s32 m;
    Unk_801E0768 *p;
    u16 n;

    if (a->unk44 != 0) {
        a->unk44 = 0;
        event_drain_gauge(a);
    }
    if (a->unk46 != 0) {
        a->unk46 = 0;
        event_draw_limb_status(a);
    }
    if (a->unk48 != 0) {
        p = a->unk58;
        a->unk48 = 0;
        m = p->unk8[p->unk2] * 16 / 100;
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
    Unk_801E0710 *q = &D_801E0710;
    s32 i;
    s32 n;
    s32 v;
    s32 m;

    sprite_fill_clut(0x400, 0x40, 0x45, 0);
    if (q->unk0 <= 0) {
        q->unk0 = 0;
        n = 0;
        sound_se_stop(4);
    } else {
        n = q->unk0 * 0x24 / 255 + 0x10;
        v = (q->unk0 << 12) / 255;
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
    m = q->unk58->unk8[q->unk58->unk2] * 0x10 / 100;
    sprite_restore_clut(0x400, 0x50, 0x5F);
    for (n = 0x50; n < m + 0x50; n++) {
        sprite_set_clut_entry(0x400, n, 0x7E8A);
    }
}

void event_update_daylight(s32 a) {
    Unk_801E1040 *c = &D_801E1040;
    Unk_801E0368 *g = &D_801E0368;
    s16 m = g->unk0[0x3E];
    s16 n;
    s32 v;

    if (m == 5) {
        if ((s16)g->unk0[0x3F] == 0 || (s16)a != 0) {
            c->unk10 = 1;
        }
        c->unk8[0] = g->unk0[0x3F] + 1;
        if (c->unk0[0] != 0) {
            n = c->unk8[0];
            v = n * 0x2A + n * 2 / 3 + 0x600;
            v = v * 0x7A >> 12;
            SetFarColor(v, v, v);
        }
    } else if (m >= 6 && m < 0x12) {
        if ((m == 6 && (s16)g->unk0[0x3F] == 0) || (s16)a != 0) {
            c->unk10 = 0;
            c->unk8[0] = 0;
            if (c->unk0[0] != 0) {
                SetFarColor(0x7A, 0x7A, 0x7A);
            }
        }
    } else if (m == 0x12) {
        if ((s16)g->unk0[0x3F] == 0 || (s16)a != 0) {
            c->unk10 = 1;
        }
        c->unk8[0] = 0x3C - g->unk0[0x3F];
        if (c->unk0[0] != 0) {
            n = c->unk8[0];
            v = n * 0x2A + n * 2 / 3 + 0x600;
            v = v * 0x7A >> 12;
            SetFarColor(v, v, v);
        }
    } else if ((m == 0x13 && (s16)g->unk0[0x3F] == 0) || (s16)a != 0) {
        c->unk10 = 1;
        c->unk8[0] = 0;
        if (c->unk0[0] != 0) {
            SetFarColor(0x2D, 0x2D, 0x2D);
        }
    }
}

void event_clock_add_minute(Unk_801E0710 *a, Unk_801E0368 *b, s32 c, s32 d) {
    s32 i;
    s16 e = c;

    b->unk0[0x3F]++;
    if ((s16)b->unk0[0x3F] >= 60) {
        b->unk0[0x3F] -= 60;
        b->unk0[0x3E]++;
        if ((s16)d == 0) {
            a->unk36++;
        }
        if ((s16)b->unk0[0x3E] >= 24) {
            a->unk34 = 0;
            b->unk0[0x3E] -= 24;
            b->unk0[0x3D]++;
            b->unk0[0x40] = (s16)b->unk0[0x3D] % 2;
            if ((s16)b->unk0[0x3D] >= 99) {
                b->unk0[0x3D] = 98;
            }
            if (e == 0) {
                event_draw_clock_digits(0, b->unk0[0x3D] + 1);
            }
        }
        if (e == 0) {
            event_draw_clock_digits(1, (s16)b->unk0[0x3E]);
        }
        mail_check_schedule(b->unk0[0x3D], b->unk0[0x3E]);
        for (i = 0; i < 5; i++) {
            if (a->unk2C != 0) {
                if (b->unkB4[i] > 0) {
                    b->unkB4[i] -= 0x10;
                    if (b->unkB4[i] < 0) {
                        b->unkB4[i] = 0;
                    }
                }
            } else if (a->unk3A[i] != 3) {
                if (b->unkB4[i] > 0) {
                    b->unkB4[i] -= 4;
                    if (b->unkB4[i] < 0) {
                        b->unkB4[i] = 0;
                    }
                }
            }
        }
    }
    if (e == 0) {
        event_draw_clock_digits(2, (s16)b->unk0[0x3F]);
    }
}

void event_draw_gauge(Unk_801E0710 *a) {
    s32 n;
    s32 t;
    s32 i;
    if (a->unk0 <= 0) {
        a->unk0 = 0;
        n = 0;
        sound_se_stop(4);
    } else {
        n = a->unk0 * 36 / 255 + 0x10;
        t = (a->unk0 << 12) / 255;
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
    Unk_801E0710 *q = &D_801E0710;
    Unk_801E0368 *p = &D_801E0368;
    event_clock_add_minute(q, p, 0, 0);
    if ((s16)((s16)p->unk0[0x3F] % 10) == p->unk1FE) {
        q->unk44 = 1;
    }
    if (a != 0) {
        event_update_daylight(0);
    }
}

void event_show_clock(s16 a) {
    Unk_801E0368 *p = &D_801E0368;
    event_draw_clock_digits(0, p->unk0[0x3D] + 1);
    event_draw_clock_digits(1, p->unk0[0x3E]);
    event_draw_clock_digits(2, p->unk0[0x3F]);
    D_801E1040.unk0[0] = a;
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
    Unk_801E0710 *q = &D_801E0710;
    Unk_801E0368 *p = &D_801E0368;
    for (i = 0; i < a; i++) {
        event_clock_add_minute(q, p, 1, b);
    }
    event_draw_clock_digits(0, p->unk0[0x3D] + 1);
    event_draw_clock_digits(1, p->unk0[0x3E]);
    event_draw_clock_digits(2, p->unk0[0x3F]);
}
