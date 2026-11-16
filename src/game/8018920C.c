#include "common.h"
#include "game/types.h"

s32 DisableEvent(s32 event);
s32 CloseEvent(s32 event);
s32 event_enter_id;
s32 event_leave_id;
s32 event_mod_finish_id;
extern s32 player_pick_trigger_hook;
void event_clock_tick(s16 daylight);
void (*event_tick_hook)(void);
typedef struct { s32 id; s16 active; s16 unk6; } EventAlarmSlot;
extern EventAlarmSlot event_alarm_slots[];
void (*event_alarm_hook)(s32 *a, EventAlarmSlot *b);
void sprite_restore_clut(s32 id, s32 first, s32 last);
void sprite_set_clut_entry(s32 id, s32 index, s32 color);
s16 event_blink0_on;
s16 event_blink1_on;
s16 event_blink2_on;
s16 event_blink0_timer;
s16 event_blink1_timer;
s16 event_blink2_timer;
void sprite_fill_clut(s32 id, s32 first, s32 last, s32 color);
extern GameVars action_vars;
extern ScreenLight screen_light;
void event_draw_clock_digits(s32 field, s16 value);
void event_update_daylight(s32 force);
void SetFarColor(s32 r, s32 g, s32 b);
extern PlayerStatus player_status;
void (*event_mod_finish_hook)(s32 *a);
WeaponRecord *effect_weapon_find(s16 id);
void player_weapon_sound(s16 kind, s32 start);
void mod_set_anim(s32 mod, s32 anim, s32 frames);
void sound_se_stop(s32 id);
void sound_se_play(s32 id);
void event_clock_add_minute(PlayerStatus *status, GameVars *game, s32 quiet, s32 no_fatigue);
typedef struct { s16 x; s16 y; } TimVramPos;
typedef struct SpriteTimPosView {
    u8 pad0[0x1C];
    TimVramPos *tim;
} SpriteTimPosView;
u16 *sprite_find(u16 id);
s32 MoveImage(void *rect, s32 x, s32 y);
s32 OpenEvent(u32 desc, s32 spec, s32 mode, s32 (*func)(void));
s32 EnableEvent(s32 event);
extern char event_str_file[];
void kaj_abend(s32 code, char *msg, char *file, s32 line);
s32 object_deliver_area_events(void);
s32 player_leave_trigger(void);
s32 mod_finish_handler(void);
extern EventState event_state;
s16 (*event_leave_hook)(KajEvent *a);
void action_reset(s16 flush_all);
void text_close(void);
s16 action_run_npc_event(u16 id, s16 enter);
s16 thing_run_script(s32 type, s32 id, s32 entering);
s16 action_run_trigger_leave(void *trigger);
extern Player *player_status_player[];
s16 (*event_effect_done_hook)(KajEvent *a);
void kaj_tss_release(s32 index);
void kaj_pad_reset(s32 enable);
void kaj_view_clear_vram(void);
void mail_menu_clear_rows(MailMenu *menu);
void effect_item_use_selected(void);
void sound_bgm_stop(void);
void event_draw_gauge(PlayerStatus *status);
extern u8 event_digit_segments[];
typedef struct { u8 r; u8 g; u8 b; u8 unk3; } LimbColor;
extern LimbColor event_limb_colors[];
void mail_check_schedule(s16 day, s16 hour);
void event_draw_limb_status(PlayerStatus *status);
s16 (*event_enter_hook)(KajEvent *a);
s16 action_run_trigger_enter(void *trigger);
void block_enter_area(u32 code);
void text_show(char *str, s32 mode, s32 circle_set, s32 circle_flags, s32 cross_set, s32 cross_flags, s32 se);
void event_drain_gauge(PlayerStatus *status);
u16 event_blink0_color;
u16 event_blink1_color;
u16 event_blink2_color;

void event_open(void) {
    event_enter_id = OpenEvent(0xF3000000, 2, 0x1000, object_deliver_area_events);
    event_leave_id = OpenEvent(0xF3000001, 2, 0x1000, player_leave_trigger);
    event_mod_finish_id = OpenEvent(0xF3000002, 2, 0x1000, mod_finish_handler);
    if (event_enter_id == -1 || event_leave_id == -1 || event_mod_finish_id == -1) {
        kaj_abend(0xC, "Can not Create User Defined Event", event_str_file, 0x34);
    }
    if (EnableEvent(event_enter_id) == 0) {
        kaj_abend(0xC, "Can not Enable to ENTER Event", event_str_file, 0x37);
    }
    if (EnableEvent(event_leave_id) == 0) {
        kaj_abend(0xC, "Can not Enable to LEAVE Event", event_str_file, 0x3A);
    }
    if (EnableEvent(event_mod_finish_id) == 0) {
        kaj_abend(0xC, "Can not Enable to MOD Finish Event", event_str_file, 0x3D);
    }
    player_pick_trigger_hook = 0;
}

void event_handle_enter(KajEvent *ev) {
    Player *player = player_status_player[0];
    EventState *state = &event_state;
    GameVars *game = &action_vars;
    s32 thing_type;
    s32 thing_id;

    state->trigger = ev->param1;
    state->trigger_type = ev->param0;
    state->cross_flags = 0;
    state->circle_flags = 0;
    state->cross_set = -1;
    state->circle_set = -1;
    if (event_enter_hook != NULL && event_enter_hook(ev) != 0) {
        return;
    }
    switch (ev->param0) {
    case 0xFC:
        if (action_run_npc_event(ev->param1, 1) == 0) {
            player->flags &= 0xFFFB;
            action_reset(0);
        } else {
            state->state = 1;
        }
        break;
    case 0xFD:
        thing_type = ((u8 *)&ev->param1)[1] >> 4;
        thing_id = (u16)ev->param1 & 0xFFF;
        if (thing_run_script(thing_type, thing_id, 1) == 0) {
            if (thing_type == 0 && thing_id == 0) {
                /* car prompt: get in */
                text_show(" 7\203N\203\213\203}1\202\311\217\346\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
            } else {
                player->flags &= 0xFFFB;
                action_reset(0);
            }
        } else {
            state->state = 1;
        }
        break;
    case 0xFE:
        if ((s16)game->vars[0x3E] < 5) {
            /* shop opening hours sign */
            text_show("\211c\213\306\216\236\212\324 \202T\201F\202O\202O\201`\202Q\202S\201F\202O\202O", 1, -1, 0, -1, 0, 1);
        } else {
            switch (((u8 *)&ev->param1)[1]) {
            case 1:
                /* bus stop prompt, first route */
                text_show(" 7\203o\203X\222\342 \202b\202P\202O\202P\214n\223\235   3\201\233", 1, -1, 8, -1, 0, 1);
                break;
            case 2:
                /* bus stop prompt, second route */
                text_show(" 7\203o\203X\222\342 \202b\202P\202O\202Q\214n\223\235   3\201\233", 1, -1, 8, -1, 0, 1);
                break;
            case 3:
                /* bus stop prompt, third route */
                text_show(" 7\203o\203X\222\342 \202b\202P\202O\202R\214n\223\235   3\201\233", 1, -1, 8, -1, 0, 1);
                break;
            default:
                /* bus stop sign, no route */
                text_show(" 7\203o\203X\222\342", 1, -1, 0, -1, 0, 1);
                break;
            }
        }
        break;
    case 0xFF:
        /* phone box prompt */
        text_show(" 7\223d\230b\203{\203b\203N\203X       3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0x80:
        block_enter_area(ev->param1);
        break;
    default:
        if (action_run_trigger_enter((void *)ev->param2) == 0) {
            player->flags &= 0xFFFB;
            action_reset(0);
            break;
        }
    case 0xF7:
        state->state = 1;
        break;
    }
}

void event_handle_leave(KajEvent *ev) {
    EventState *state = &event_state;

    state->trigger = ev->param1;
    state->trigger_type = ev->param0;
    if (state->trigger_type != 0x40) {
        action_reset(0);
        text_close();
    }
    if (event_leave_hook != NULL && event_leave_hook(ev) != 0) {
        return;
    }
    switch (ev->param0) {
    case 0xFC:
        if (action_run_npc_event(ev->param1, 0) == 0) {
            action_reset(0);
        } else {
            state->state = 1;
        }
        break;
    case 0xFD:
        if (thing_run_script(((u8 *)&ev->param1)[1] >> 4, (u16)ev->param1 & 0xFFF, 0) == 0) {
            action_reset(0);
        } else {
            state->state = 1;
        }
        break;
    default:
        if (action_run_trigger_leave((void *)ev->param2) == 0) {
            action_reset(0);
            break;
        }
    case 0xF7:
        state->state = 1;
        break;
    }
}

s16 event_handle_effect_done(KajEvent *ev) {
    GameVars *game = &action_vars;
    Player *player = player_status_player[0];
    MailMenu *menu = &game->mail_menu;
    s16 handled = 0;

    kaj_tss_release(ev->param0);
    switch (ev->param2) {
    case 0:
        if (ev->param1 == 0) {
            game->effect_task = -1;
        }
        kaj_pad_reset(1);
        break;
    case 1:
        if (ev->param1 == 0) {
            game->effect_task = -1;
        }
        handled = 1;
        kaj_view_clear_vram();
        break;
    case 11:
        if (ev->param1 == 0) {
            game->effect_task = -1;
        }
        menu->state = 1;
        break;
    case 12:
        if (ev->param1 == 0) {
            game->effect_task = -1;
        }
        menu->state = 0;
        game->menu_busy = 0;
        if (menu->icon_sprite == -2) {
            mail_menu_clear_rows(menu);
        }
        if (player->flags & 0x4000) {
            ev->param0 = 999999;
            player->flags &= 0xBFFF;
            effect_item_use_selected();
        }
        break;
    case 13:
        if (ev->param1 == 0) {
            game->effect_task = -1;
        }
        sound_bgm_stop();
        break;
    }
    if (handled == 0 && event_effect_done_hook != NULL) {
        handled = event_effect_done_hook(ev);
    }
    return handled;
}

void event_close(void) {
    player_pick_trigger_hook = 0;
    DisableEvent(event_enter_id);
    DisableEvent(event_leave_id);
    DisableEvent(event_mod_finish_id);
    CloseEvent(event_enter_id);
    CloseEvent(event_leave_id);
    CloseEvent(event_mod_finish_id);
}

void event_handle_alarm(s32 *ev) {
    EventAlarmSlot *p = &event_alarm_slots[ev[2]];
    p->id = -1;
    p->active = 0;
    if (event_alarm_hook != NULL) {
        event_alarm_hook(ev, p);
    }
}

void event_handle_tick(s16 daylight) {
    event_clock_tick(daylight);
    if (event_tick_hook != NULL) {
        event_tick_hook();
    }
}

void event_handle_mod_finish(s32 *ev) {
    PlayerStatus *status = &player_status;
    Player *player = status->player;
    Inventory *inv = status->inventory;
    WeaponRecord *weapon;

    if (ev[3] == 1) {
        switch (inv->weapon_state) {
        case 0:
            inv->weapon_state = 2;
            break;
        case 1:
            player->flags &= 0x7FFF;
            inv->weapon_state = 0;
            inv->weapon_shown = 0;
            break;
        case 4:
            inv->weapon_state = 5;
            break;
        case 6:
            inv->weapon_state = 7;
            weapon = effect_weapon_find(inv->weapon_ids[inv->weapon_slot]);
            if (weapon != NULL) {
                player_weapon_sound(weapon->id, 0);
            }
            mod_set_anim(inv->weapon_model, 3, 0);
            break;
        case 7:
            inv->weapon_state = 3;
            break;
        }
    } else if (event_mod_finish_hook != NULL) {
        event_mod_finish_hook(ev);
    }
}

void event_drain_gauge(PlayerStatus *status) {
    GameVars *game = &action_vars;
    Inventory *inv = status->inventory;
    WeaponRecord *weapon;
    s32 drain = 1;

    if (status->mutant == 0 && status->hours_awake >= 0x10) {
        switch (status->hours_awake >> 4) {
        case 1:
            drain = 2;
            break;
        case 2:
            drain = 3;
            break;
        case 3:
            drain = 4;
            break;
        case 4:
            drain = 8;
            break;
        case 5:
            drain = 0x10;
            break;
        default:
            drain = 0x20;
            break;
        }
    }
    switch (status->limb_state[3]) {
    case 1:
        drain = (drain * 3) >> 1;
        break;
    case 2:
        drain *= 2;
        break;
    case 3:
        drain *= 4;
        break;
    }
    game->drain_count++;
    weapon = effect_weapon_find(inv->weapon_ids[inv->weapon_slot]);
    if (weapon != NULL && game->drain_count == 6) {
        drain += weapon->drain_extra;
        game->drain_count = 0;
    }
    status->infected = 0;
    status->energy -= drain;
    event_draw_gauge(status);
}

void event_draw_clock_digits(s32 field, s16 value) {
    s16 segment;
    s16 row;
    s16 digit;
    s32 t = field * 2;
    digit = value / 10;
    row = (s16)t * 7 + 8;
    for (segment = 0; segment < 7; segment++) {
        if ((event_digit_segments[digit] >> segment) & 1) {
            sprite_set_clut_entry(0x409, row - segment, 0x7FFF);
        } else {
            sprite_set_clut_entry(0x409, row - segment, 0);
        }
    }
    digit = value % 10;
    row = (s16)(t + 1) * 7 + 8;
    for (segment = 0; segment < 7; segment++) {
        if ((event_digit_segments[digit] >> segment) & 1) {
            sprite_set_clut_entry(0x409, row - segment, 0x7FFF);
        } else {
            sprite_set_clut_entry(0x409, row - segment, 0);
        }
    }
}

void event_draw_limb_status(PlayerStatus *status) {
    GameVars *game = &action_vars;
    LimbColor *color;
    s16 also_head = 0;
    s32 limb;
    s32 level;
    s32 damage;

    for (limb = 0; limb < 5; limb++) {
        damage = game->limb_damage[limb];
        if (damage < 0x10) {
            status->limb_state[limb] = 0;
        } else if (damage >= 0x10 && damage < 0xA6) {
            status->limb_state[limb] = 1;
        } else if (damage >= 0xA6 && damage < 0xF0) {
            status->limb_state[limb] = 2;
        } else {
            status->limb_state[limb] = 3;
            game->limb_damage[limb] = 0xF0;
        }
        level = status->limb_state[limb];
        if (status->mutant != 0) {
            if (level == 0) {
                level = 4;
            }
            if (limb == 0) {
                also_head = 1;
            }
        }
        color = &event_limb_colors[level];
        sprite_set_clut_entry(0x400, limb + 0x40, (color->r | (color->g << 5) | (color->b << 10)) & 0xFFFF);
        if (also_head != 0) {
            sprite_set_clut_entry(0x400, 0x45, (color->r | (color->g << 5) | (color->b << 10)) & 0xFFFF);
            also_head = 0;
        }
    }
}

void event_update_hud(PlayerStatus *status) {
    s32 i;
    s32 rate_end;
    Inventory *inv;
    u16 timer;

    if (status->drain_pending != 0) {
        status->drain_pending = 0;
        event_drain_gauge(status);
    }
    if (status->limb_redraw != 0) {
        status->limb_redraw = 0;
        event_draw_limb_status(status);
    }
    if (status->weapon_redraw != 0) {
        inv = status->inventory;
        status->weapon_redraw = 0;
        rate_end = inv->weapon_rate[inv->weapon_slot] * 16 / 100;
        sprite_restore_clut(0x400, 0x50, 0x5F);
        for (i = 0x50; i < rate_end + 0x50; i++) {
            sprite_set_clut_entry(0x400, i, 0x7E8A);
        }
    }
    if (event_blink0_on != 0) {
        timer = event_blink0_timer;
        if ((s16)((s16)timer % 3) == 0) {
            sprite_set_clut_entry(0x400, 1, event_blink0_color);
        } else if ((s16)((s16)timer % 3) == 2) {
            sprite_set_clut_entry(0x400, 1, 0);
        }
        if ((s16)timer >= 11) {
            event_blink0_on = 0;
            event_blink0_timer = 0;
            sprite_fill_clut(0x400, 1, 3, 0);
        }
        event_blink0_timer++;
    }
    if (event_blink1_on != 0) {
        timer = event_blink1_timer;
        if ((s16)((s16)timer % 3) == 0) {
            sprite_set_clut_entry(0x400, 2, event_blink1_color);
        } else if ((s16)((s16)timer % 3) == 2) {
            sprite_set_clut_entry(0x400, 2, 0);
        }
        if ((s16)timer >= 11) {
            event_blink1_on = 0;
            event_blink1_timer = 0;
            sprite_fill_clut(0x400, 1, 3, 0);
        }
        event_blink1_timer++;
    }
    if (event_blink2_on != 0) {
        timer = event_blink2_timer;
        if ((s16)((s16)timer % 3) == 0) {
            sprite_set_clut_entry(0x400, 3, event_blink2_color);
        } else if ((s16)((s16)timer % 3) == 2) {
            sprite_set_clut_entry(0x400, 3, 0);
        }
        if ((s16)timer >= 11) {
            event_blink2_on = 0;
            event_blink2_timer = 0;
            sprite_fill_clut(0x400, 1, 3, 0);
        }
        event_blink2_timer++;
    }
}

void event_draw_hud(void) {
    PlayerStatus *status = &player_status;
    s32 i;
    s32 energy_end;
    s32 energy_frac;
    s32 rate_end;

    sprite_fill_clut(0x400, 0x40, 0x45, 0);
    if (status->energy <= 0) {
        status->energy = 0;
        energy_end = 0;
        sound_se_stop(4);
    } else {
        energy_end = status->energy * 0x24 / 255 + 0x10;
        energy_frac = (status->energy << 12) / 255;
        if (status->low_energy_alarm != 0) {
            if (energy_frac >= 0x400) {
                status->low_energy_alarm = 0;
                sound_se_stop(4);
            }
        } else if (energy_frac < 0x400) {
            status->low_energy_alarm = 1;
            sound_se_play(4);
        }
    }
    sprite_restore_clut(0x400, 0x10, 0x33);
    for (i = 0x10; i < 0x34; i++) {
        if (energy_end < i) {
            sprite_set_clut_entry(0x400, i, 0x1421);
        }
    }
    event_draw_limb_status(status);
    rate_end = status->inventory->weapon_rate[status->inventory->weapon_slot] * 0x10 / 100;
    sprite_restore_clut(0x400, 0x50, 0x5F);
    for (energy_end = 0x50; energy_end < rate_end + 0x50; energy_end++) {
        sprite_set_clut_entry(0x400, energy_end, 0x7E8A);
    }
}

void event_update_daylight(s32 force) {
    ScreenLight *light = &screen_light;
    GameVars *game = &action_vars;
    s16 hour = game->vars[0x3E];
    s16 step;
    s32 far;

    if (hour == 5) {
        if ((s16)game->vars[0x3F] == 0 || (s16)force != 0) {
            light->dark = 1;
        }
        light->daylight_step = game->vars[0x3F] + 1;
        if (light->daylight_on != 0) {
            step = light->daylight_step;
            far = step * 0x2A + step * 2 / 3 + 0x600;
            far = far * 0x7A >> 12;
            SetFarColor(far, far, far);
        }
    } else if (hour >= 6 && hour < 0x12) {
        if ((hour == 6 && (s16)game->vars[0x3F] == 0) || (s16)force != 0) {
            light->dark = 0;
            light->daylight_step = 0;
            if (light->daylight_on != 0) {
                SetFarColor(0x7A, 0x7A, 0x7A);
            }
        }
    } else if (hour == 0x12) {
        if ((s16)game->vars[0x3F] == 0 || (s16)force != 0) {
            light->dark = 1;
        }
        light->daylight_step = 0x3C - game->vars[0x3F];
        if (light->daylight_on != 0) {
            step = light->daylight_step;
            far = step * 0x2A + step * 2 / 3 + 0x600;
            far = far * 0x7A >> 12;
            SetFarColor(far, far, far);
        }
    } else if ((hour == 0x13 && (s16)game->vars[0x3F] == 0) || (s16)force != 0) {
        light->dark = 1;
        light->daylight_step = 0;
        if (light->daylight_on != 0) {
            SetFarColor(0x2D, 0x2D, 0x2D);
        }
    }
}

void event_clock_add_minute(PlayerStatus *status, GameVars *game, s32 quiet, s32 no_fatigue) {
    s32 limb;
    s16 quiet16 = quiet;

    game->vars[0x3F]++;
    if ((s16)game->vars[0x3F] >= 60) {
        game->vars[0x3F] -= 60;
        game->vars[0x3E]++;
        if ((s16)no_fatigue == 0) {
            status->hours_awake++;
        }
        if ((s16)game->vars[0x3E] >= 24) {
            status->naps_today = 0;
            game->vars[0x3E] -= 24;
            game->vars[0x3D]++;
            game->vars[0x40] = (s16)game->vars[0x3D] % 2;
            if ((s16)game->vars[0x3D] >= 99) {
                game->vars[0x3D] = 98;
            }
            if (quiet16 == 0) {
                event_draw_clock_digits(0, game->vars[0x3D] + 1);
            }
        }
        if (quiet16 == 0) {
            event_draw_clock_digits(1, (s16)game->vars[0x3E]);
        }
        mail_check_schedule(game->vars[0x3D], game->vars[0x3E]);
        for (limb = 0; limb < 5; limb++) {
            if (status->mutant != 0) {
                if (game->limb_damage[limb] > 0) {
                    game->limb_damage[limb] -= 0x10;
                    if (game->limb_damage[limb] < 0) {
                        game->limb_damage[limb] = 0;
                    }
                }
            } else if (status->limb_state[limb] != 3) {
                if (game->limb_damage[limb] > 0) {
                    game->limb_damage[limb] -= 4;
                    if (game->limb_damage[limb] < 0) {
                        game->limb_damage[limb] = 0;
                    }
                }
            }
        }
    }
    if (quiet16 == 0) {
        event_draw_clock_digits(2, (s16)game->vars[0x3F]);
    }
}

void event_draw_gauge(PlayerStatus *status) {
    s32 energy_end;
    s32 energy_frac;
    s32 i;
    if (status->energy <= 0) {
        status->energy = 0;
        energy_end = 0;
        sound_se_stop(4);
    } else {
        energy_end = status->energy * 36 / 255 + 0x10;
        energy_frac = (status->energy << 12) / 255;
        if (status->low_energy_alarm != 0) {
            if (energy_frac >= 0x400) {
                status->low_energy_alarm = 0;
                sound_se_stop(4);
            }
        } else if (energy_frac < 0x400) {
            status->low_energy_alarm = 1;
            sound_se_play(4);
        }
    }
    sprite_restore_clut(0x400, 0x10, 0x33);
    for (i = 0x10; i < 0x34; i++) {
        if (energy_end < i) {
            sprite_set_clut_entry(0x400, i, 0x1421);
        }
    }
}

void event_draw_percent_gauge(PlayerStatus *status) {
    s32 i;
    s32 rate_end;
    Inventory *inv = status->inventory;
    rate_end = inv->weapon_rate[inv->weapon_slot] * 16 / 100;
    sprite_restore_clut(0x400, 0x50, 0x5F);
    for (i = 0x50; i < rate_end + 0x50; i++) {
        sprite_set_clut_entry(0x400, i, 0x7E8A);
    }
}

void event_set_blink(s16 which, s16 on) {
    switch (which) {
    case 0:
        event_blink0_on = on;
        event_blink0_timer = 0;
        break;
    case 1:
        event_blink1_on = on;
        event_blink1_timer = 0;
        break;
    case 2:
        event_blink2_on = on;
        event_blink2_timer = 0;
        break;
    }
    if (on == 0) {
        sprite_fill_clut(0x400, 1, 3, 0);
    }
}

void event_clock_tick(s16 daylight) {
    PlayerStatus *status = &player_status;
    GameVars *game = &action_vars;
    event_clock_add_minute(status, game, 0, 0);
    if ((s16)((s16)game->vars[0x3F] % 10) == game->drain_minute) {
        status->drain_pending = 1;
    }
    if (daylight != 0) {
        event_update_daylight(0);
    }
}

void event_show_clock(s16 light_on) {
    GameVars *game = &action_vars;
    event_draw_clock_digits(0, game->vars[0x3D] + 1);
    event_draw_clock_digits(1, game->vars[0x3E]);
    event_draw_clock_digits(2, game->vars[0x3F]);
    screen_light.daylight_on = light_on;
    SetFarColor(0, 0, 0);
    if (light_on != 0) {
        event_update_daylight(1);
    }
}

void event_draw_compass(Player *player) {
    Rect rect;
    SpriteTimPosView *sprite = (SpriteTimPosView *)sprite_find(0x40E);
    if (sprite != NULL) {
        rect.x = ((player->yaw * 0xC0000 / 360) >> 14) + 0x140;
        rect.y = 0x160;
        rect.w = 0xC;
        rect.h = 0x10;
        MoveImage(&rect, sprite->tim->x, sprite->tim->y);
    }
}

void event_advance_clock(s16 minutes, s16 no_fatigue) {
    s16 i;
    PlayerStatus *status = &player_status;
    GameVars *game = &action_vars;
    for (i = 0; i < minutes; i++) {
        event_clock_add_minute(status, game, 1, no_fatigue);
    }
    event_draw_clock_digits(0, game->vars[0x3D] + 1);
    event_draw_clock_digits(1, game->vars[0x3E]);
    event_draw_clock_digits(2, game->vars[0x3F]);
}
