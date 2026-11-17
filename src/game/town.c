#include "common.h"
#include "game/town.h"
#include "game/action.h"
#include "game/block.h"
#include "game/building.h"
#include "game/dialog.h"
#include "game/effect.h"
#include "game/event.h"
#include "game/main.h"
#include "game/object.h"
#include "game/player.h"
#include "game/roadmap.h"
#include "game/sound.h"
#include "game/sprite.h"
#include "game/thing.h"
#include "game/vehicle.h"
#include "kaj/event.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "kaj/timer.h"
#include "kaj/view.h"
#include "psyq/libc.h"

/*
 * The town scene loop and its field and train hooks.
 *
 * File boundaries: guess (docs/layout.md): no assert: a string after thing.c's jump table; its end is a guess.
 */

extern TrainState vehicle_train_state;
static void thing_field_loop(void);
s16 thing_field_exit_arg_hi;
s16 thing_field_exit_arg_lo;
s16 thing_field_exit_code;
extern Player *player_status_player[];
extern s16 vehicle_navi[];
extern GameVars action_vars;
extern RoadMap roadmap_state;
s16 thing_next_vehicle_mode;
void text_show(char *str, s32 mode, s32 circle_set, s32 circle_flags, s32 cross_set, s32 cross_flags, s32 se);
extern PlayerStatus player_status;
extern SceneRequest scene_request;
extern KajSystem kaj_system;
static void thing_field_do_action(Player *player);
extern s32 event_effect_done_hook;
extern s32 event_alarm_hook;
extern s32 event_tick_hook;
extern s32 event_leave_hook;
extern s32 event_enter_hook;
extern EventState event_state;
void sprite_phone_save_exit();
s16 thing_field_show_clock;
s16 thing_field_loaded_id;
static s32 thing_field_task_hook(KajEvent *ev);
static void thing_field_timer_hook(KajEvent *ev);
static s32 thing_train_enter_hook(KajEvent *ev);
static s32 thing_train_leave_hook(KajEvent *ev);
static void thing_train_tick_hook(void);
static void thing_field_input(void);
static void thing_field_enter(void);
static void thing_field_leave(void);
s32 mail_take_scene_change(void);

static s32 thing_field_task_hook(KajEvent *ev) {
    GameVars *game = &action_vars;
    Player *player = player_status_player[0];
    TrainState *train = &vehicle_train_state;
    RoadMap *roadmap = &roadmap_state;
    s16 *navi = vehicle_navi;
    s32 kind = ev->param2;

    if (kind == 2) {
        if (ev->param1 == 0) {
            game->effect_task = -1;
        }
        roadmap->mode = 1;
    } else if (kind == 3) {
        if (ev->param1 == 0) {
            game->effect_task = -1;
        }
        roadmap->mode = 0;
        if (navi[0] != 0) {
            vehicle_navi_show(player, 1, 0);
        }
    } else if (kind == 11) {
        /* car navigation prompt: set or clear the destination */
        text_show(" 8\203J\201[\203i\203r1\202\3143\226\332\223I\222n1\202\360, \225\373\214\374\203L\201[\217\343\211\272\202\305\221I\202\361\202\305\211\272\202\263\202\242,      \220\335\222\350 3\201\233 1\211\360\217\234 4\201~", 3, -1, 0, -1, 0, 1);
    } else if (kind == 12) {
        text_close();
        vehicle_navi_show(player, navi[0], 1);
    } else if (kind == 7) {
        if (train->door_state == 3) {
            train->door_state = 1;
            thing_next_vehicle_mode = vehicle_train_end_of_line(thing_next_vehicle_mode);
            if (thing_next_vehicle_mode != 0) {
                vehicle_train_exit_prompt(1);
            }
        } else if (train->door_state == 2) {
            train->door_state = 0;
            train->motion = 1;
            sound_se_play(0x1F);
        }
    } else if (kind == 0) {
        sound_bgm_play(0);
    }
    return 0;
}

static void thing_field_do_action(Player *player) {
    SceneRequest *request = &scene_request;
    EventState *ev_state = &event_state;
    ActionSet *set;
    s32 type_bits;
    s32 thing_id;

    if (ev_state->state == 2 && (ev_state->circle_flags & 8)) {
        text_close();
        switch (ev_state->trigger_type) {
        case 0xFD:
            type_bits = ev_state->trigger & 0xF000;
            thing_id = (u16)ev_state->trigger & 0xFFF;
            if (type_bits == 0 && thing_id == 0) {
                sound_se_play(0x16);
                request->change = 1;
                request->pos_x = player->pos_x + player->cell_x * 12500;
                request->pos_y = 0;
                request->pos_z = player->pos_z + player->cell_z * 12500;
                thing_field_exit_code = 3;
                thing_next_vehicle_mode = 1;
                request->yaw = player->yaw;
                request->loop_param = 0;
            } else {
                sound_se_play(0x11);
                for (set = action_find_set(ev_state->circle_set); set != 0; set = action_run_set(set, 0, 0)) {
                }
            }
            break;
        case 0xFE:
            sound_se_play(0xD);
            request->change = 1;
            thing_field_exit_code = 2;
            thing_field_exit_arg_hi = ((u32)ev_state->trigger & 0xFF00) >> 8; /* unk0 is read unsigned here (srl): the cast keeps the bytes */
            thing_field_exit_arg_lo = ev_state->trigger & 0xFF;
            break;
        case 0xFF:
            sound_se_play(0xD);
            thing_field_exit_code = 1;
            request->change = 1;
            sprite_phone_save_exit(ev_state->trigger);
            break;
        case 0x20:
            sound_se_play(0x11);
            thing_next_vehicle_mode = vehicle_train_get_off(thing_next_vehicle_mode);
            break;
        default:
            for (set = action_find_set(ev_state->circle_set); set != 0; set = action_run_set(set, 0, 0)) {
            }
            break;
        }
        ev_state->state = 1;
        ev_state->circle_flags &= ~8;
    }
}

static void thing_field_input(void) {
    SceneRequest *request = &scene_request;
    PlayerStatus *status = &player_status;
    KajSystem *pad = &kaj_system;
    s16 mode = pad->pad_mode;
    Player *player = status->player;
    s32 vmode;
    s32 buttons;

    if (mode == 1 && !(player->flags & 2)) {
        buttons = kaj_pad_read();
        vmode = player->vehicle_mode;
        if (vmode == mode) {
            if (vehicle_car_input(status, buttons) != 0) {
                thing_field_exit_code = 4;
                thing_next_vehicle_mode = 0;
                request->change = vmode;
            }
        } else if (effect_item_input(status, 2) == 0) {
            player_update_map(status);
            if ((player->flags & 4) && !(pad->pad_prev & 0x20) && (pad->pad_now & 0x20)) {
                thing_field_do_action(player);
                return;
            }
            player_handle_pad(status, 2, buttons);
        }
    }
}

static void thing_field_enter(void) {
    Inventory *inv;
    Player *player;
    TrainState *train;

    thing_next_vehicle_mode = -1;
    thing_field_show_clock = 1;
    inv = player_status.inventory;
    player = player_status.player;
    train = &vehicle_train_state;
    sprite_set_visible(0x410, 1);
    action_reset(1);
    if (thing_field_exit_code != 3) {
        player_place_for_scene(2);
    }
    roadmap_init();
    effect_weapon_calc_rate(0);
    effect_weapon_calc_rate(1);
    switch (thing_field_exit_code) {
    case 0:
        object_load_scene();
        if (thing_field_loaded_id != inv->kind2_item) {
            object_load_res12_by_id(inv->kind2_item);
            thing_field_loaded_id = inv->kind2_item;
        }
        effect_flame_small_init(2);
        effect_clut_cycle_init();
        effect_flame_large_init();
    case 1:
    case 2:
    case 3:
    case 4:
        block_set_mode(2);
        break;
    }
    switch (player->vehicle_mode) {
    case 0:
        vehicle_car_place();
        sound_se_play(0x15);
    case 1:
        vehicle_load_data();
        event_alarm_hook = (s32)thing_field_timer_hook;
        thing_set_active(3, 3, 1);
        thing_set_active(3, 4, 1);
        thing_set_animate(3, 3, 1);
        thing_set_animate(3, 4, 1);
        sprite_set_visible(0x40E, 1);
        if (player->vehicle_mode == 1) {
            sound_se_play(0x19);
            sound_se_play(0x1A);
        }
        break;
    case 3:
        thing_field_show_clock = 0;
        thing_set_active(4, 0, 0);
    case 2:
        vehicle_load_data();
        event_enter_hook = (s32)thing_train_enter_hook;
        event_leave_hook = (s32)thing_train_leave_hook;
        event_tick_hook = (s32)thing_train_tick_hook;
        train->prompt_on = 0;
        train->trigger = 0;
        train->stop_timer = 0;
        break;
    }
    if (thing_field_exit_code != 0) {
        sprite_thing_refresh_all();
    }
    event_effect_done_hook = (s32)thing_field_task_hook;
    thing_field_exit_code = 0;
    event_show_clock(thing_field_show_clock);
    sprite_set_visible(0x410, 0);
}

static void thing_field_leave(void) {
    Player *player = player_status_player[0];
    s32 i;

    effect_clear_alarms();
    action_reset(1);
    sprite_set_visible(0x40E, 0);
    sound_bgm_stop();
    sound_se_stop_all();
    event_alarm_hook = 0;
    event_effect_done_hook = 0;
    event_enter_hook = 0;
    event_leave_hook = 0;
    event_tick_hook = 0;
    text_close();
    vehicle_free();
    roadmap_quit();
    switch (thing_field_exit_code) {
    case 0:
        action_free_triggers();
        action_free_all_sets();
        block_free_all();
        thing_free_all();
        effect_flame_small_free();
        effect_flame_large_free();
        sound_bgm_close();
        sound_se_pop_scene();
        for (i = 0; i < 4; i++) {
            sprite_delete((u16)i);
        }
        sprite_delete(0x1FF);
        vehicle_car_release();
        kaj_view_set_bg_color(0, 0, 0);
        break;
    case 3:
        thing_set_active(0, 0, 0);
        break;
    case 1:
        block_hide_all();
        effect_flame_small_free();
        effect_flame_large_free();
        kaj_view_set_bg_color(0, 0, 0);
    case 2:
        thing_set_active(3, 3, 0);
        thing_set_active(3, 4, 0);
        break;
    }
    block_stream_stop();
    if (thing_next_vehicle_mode != -1) {
        player->vehicle_mode = thing_next_vehicle_mode;
    }
}

static void thing_field_loop(void) {
    s32 ev[6];
    s16 elevator_wait;
    s16 done;

    elevator_wait = 0;
    done = 0;
    thing_field_enter();
    kaj_timer_enable();
    effect_start_fade(0, 3);
    while (done == 0) {
        switch (kaj_event_get(ev)) {
        case 2:
            event_handle_alarm(ev);
            continue;
        case 0x10:
            event_handle_enter(ev);
            continue;
        case 0x20:
            event_handle_leave(ev);
            continue;
        case 4:
            event_handle_tick(thing_field_show_clock);
            continue;
        case 0:
            thing_field_input();
            if ((s16)mail_take_scene_change() != 0) {
                if (thing_field_exit_code == 2) {
                    kaj_pad_reset(0);
                    elevator_wait = 1;
                } else {
                    effect_start_fade(1, 3);
                }
            }
            break;
        case 0x100:
            done = event_handle_effect_done(ev);
            continue;
        default:
            kaj_event_done(ev);
            continue;
        }
        effect_start_alarm(0, 0x404, rand() % 30 + 30);
        mail_step_frame(2, 1, 1);
        if (elevator_wait != 0 && block_cd_idle() != 0) {
            done = 1;
        }
    }
    kaj_timer_disable();
    thing_field_leave();
}

static void thing_field_timer_hook(KajEvent *ev) {
    if (ev->param1 == 0x404) {
        sound_se_play(0x17);
    }
}

static s32 thing_train_enter_hook(KajEvent *ev) {
    TrainState *train = &vehicle_train_state;
    s32 trigger = ev->param1;

    if (trigger == 0x200010 || trigger == 0x200020) {
        train->trigger = trigger;
        if (train->door_state == 1) {
            vehicle_train_exit_prompt(1);
        }
        return 1;
    }
    return 0;
}

static s32 thing_train_leave_hook(KajEvent *ev) {
    TrainState *train = &vehicle_train_state;
    s32 trigger = ev->param1;

    if (trigger == 0x200010 || trigger == 0x200020) {
        train->trigger = 0;
        vehicle_train_exit_prompt(0);
        return 1;
    }
    if (train->prompt_on != 0) {
        train->prompt_on = 0;
    }
    return 0;
}

static void thing_train_tick_hook(void) {
    if (vehicle_train_state.motion == 0 && vehicle_train_state.door_state == 1) {
        if (vehicle_train_state.stop_timer > 0) {
            vehicle_train_state.stop_timer--;
        }
        if (vehicle_train_state.stop_timer == 0) {
            vehicle_train_state.stop_timer = -1;
            vehicle_train_set_doors(0);
            vehicle_train_exit_prompt(0);
        }
    }
}

void thing_game_loop(void) {
    thing_field_exit_code = 0;
    block_create_all();
    while (1) {
        thing_field_loop();
        switch (thing_field_exit_code) {
        case 0:
            return;
        case 1:
            sprite_phone_run();
            break;
        case 2:
            block_bus_run(thing_field_exit_arg_hi, thing_field_exit_arg_lo);
            break;
        }
    }
}
