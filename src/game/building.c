#include "common.h"
#include "game/building.h"
#include "game/action.h"
#include "game/actor.h"
#include "game/block.h"
#include "game/dialog.h"
#include "game/door.h"
#include "game/effect.h"
#include "game/event.h"
#include "game/main.h"
#include "game/mod.h"
#include "game/npc.h"
#include "game/object.h"
#include "game/player.h"
#include "game/roadmap.h"
#include "game/shop.h"
#include "game/sound.h"
#include "game/sprite.h"
#include "game/thing.h"
#include "game/vehicle.h"
#include "kaj/event.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "kaj/timer.h"
#include "psyq/libc.h"

/*
 * The building scene loop (inside a building) and the bus ride.
 *
 * File boundaries: likely (docs/layout.md): no assert: starts after block.c; card strings follow its jump table.
 */

extern GameVars action_vars;
s16 building_wake_index;
static void building_run(void);
u16 building_elevator_ride;
extern Player *player_status_player[];
extern EventState event_state;
extern SceneRequestBuilding main_scene_request;
BuildingState building_state;
void dialog_show_profile(s16 npc_id);
void dialog_show(char *str, s32 mode, s32 circle_set, s32 circle_flags, s32 cross_set, s32 cross_flags, s32 se);
extern PlayerStatus player_status;
extern KajSystem kaj_system;
extern ShopState shop_state[];
s16 effect_weapon_input(PlayerStatus *status);
static void building_on_action(PlayerStatus *status);
s16 building_scene_daylight;
extern s32 (*event_effect_done_hook)(KajEvent *arg0);
extern s32 (*event_enter_hook)(KajEvent *arg0);
static s32 building_on_effect_done(KajEvent *ev);
static s32 building_on_enter(KajEvent *ev);
extern void (*event_tick_hook)(void);
extern s32 (*event_leave_hook)();
static void building_load(void);
static void building_update_input(void);
s16 main_take_scene_change(void);
static void building_bus_input(s16 building, s16 start_floor, s16 *floor);
extern s32 building_bus_stops[];
extern TrainState vehicle_train_state;
extern s16 shop_topic;
extern s32 building_wake_positions[];

static s32 building_on_effect_done(KajEvent *ev) {
    GameVars *vars = &action_vars;
    SceneRequestBuilding *req = &main_scene_request;
    Player *player = player_status_player[0];
    TrainState *train = &vehicle_train_state;
    ShopState *d = shop_state;
    EventState *event = &event_state;
    s32 effect_id = ev->param2;
    s16 set_id;
    void *set;
    u16 f;

    if (effect_id == 0) {
        switch (building_state.building) {
        case 7:
            break;
        case 5:
            sound_bgm_play(0);
            break;
        default:
            sound_bgm_play(1);
            break;
        }
        if (building_state.building == 1 || building_state.building == 2) {
            sound_se_play(0x1D);
        } else {
            sound_se_play_note(10, 0x29, 0, 0x3C, 0x7F, 0x7F, 1);
        }
    } else if (effect_id == 7) {
        if (ev->param1 == 0) {
            vars->effect_task = -1;
        }
        if (train->door_state == 3) {
            train->door_state = 1;
            sprite_station_show_prompt(1);
        } else if (train->door_state == 2) {
            train->door_state = 0;
            train->motion = 1;
            thing_set_animate(2, 0, 1);
        }
    } else if (effect_id == 11) {
        if (!(player->flags & 0x4000)) {
            dialog_show(*(char **)d->texts, 3, -1, 0, -1, 0, 1); /* texts read as strings here */
        }
    } else if (effect_id == 12) {
        if (!(player->flags & 0x4000)) {
            set_id = shop_finish(building_state.building);
            if (building_state.building == 8 && shop_topic >= 0) {
                if (set_id >= 0) {
                    set = action_find_set(set_id);
                    if (set != NULL) {
                        event->trigger_type = 0;
                        event->trigger = 0;
                        event->cross_set = -1;
                        event->circle_set = -1;
                        event->cross_flags = 0;
                        event->circle_flags = 0;
                        event->state = 1;
                        do {
                            set = action_run_set(set, 0, 0);
                        } while (set != NULL);
                    }
                } else {
                    shop_open_menu(building_state.building, 0);
                }
            }
        }
    } else if (effect_id == 4) {
        f = player->flags;
        if (f & 0x80) {
            player->flags = f & ~4;
            req->change = 1;
        } else if (f & 0x20) {
            /* sleep narration, first line */
            dialog_show(" \211\241\202\311\202\310\202\351\202\306\201\101\220\133\202\242\226\260\202\350\202\311\202\302\202\242\202\275", 1, -1, 0, -1, 0, 0);
            effect_start_fade(10, 3);
        } else if (f & 8) {
            if (building_state.building == 9) {
                /* sleep narration, second line */
                dialog_show(" 6\226\332\202\360\225\302\202\266\202\304\201\105\201\105\201\105", 1, -1, 0, -1, 0, 0);
            } else {
                /* sleep narration, third line */
                dialog_show(" \210\323\216\257\202\252\211\223\202\264\202\251\202\301\202\304\202\242\202\255", 1, -1, 0, -1, 0, 0);
            }
            effect_start_fade(10, 3);
        } else if ((building_state.building == 3 || building_state.building == 6) && d->at_counter != 0) {
            shop_open_menu(building_state.building, 0);
        }
    } else if (effect_id == 10) {
        if (ev->param1 == 0) {
            vars->effect_task = -1;
        }
        f = player->flags;
        if (f & 0x20) {
            player_rest(1, building_wake_positions[building_wake_index * 3], building_wake_positions[building_wake_index * 3 + 1], building_wake_positions[building_wake_index * 3 + 2]);
            dialog_close();
        } else if (f & 8) {
            if (building_state.building == 9) {
                player_recover(500, 0, 0x3390, 0);
            } else {
                player_recover(building_wake_positions[building_wake_index * 3], building_wake_positions[building_wake_index * 3 + 1], building_wake_positions[building_wake_index * 3 + 2], 1);
            }
        }
        main_wait(1, 1, 1, 4);
        effect_start_fade(9, 3);
    } else if (effect_id == 9) {
        if (ev->param1 == 0) {
            vars->effect_task = -1;
        }
        f = player->flags;
        if (f & 0x20) {
            player->flags = f & ~0x20;
        } else if (f & 8) {
            player->flags = f & ~8;
        }
    } else if (effect_id == 13) {
        if (building_state.building == 0) {
            sound_bgm_play(1);
        }
    }
    return 0;
}

static void building_on_action(PlayerStatus *status) {
    EventState *event = &event_state;
    BuildingState *bstate;
    void *set;
    s16 state = event->state;

    if (state == 3) {
        dialog_next_page(event);
        return;
    }
    if (state != 2) {
        return;
    }
    building_elevator_ride = 0;
    if (!(event->circle_flags & 8)) {
        return;
    }
    sound_se_play(0x11);
    dialog_close();
    switch (event->trigger_type) {
    case 0xFC:
        dialog_show_profile(event_state.trigger);
        break;
    case 0x10:
        switch (event_state.trigger) {
        case 0x100010:
            sprite_station_board_train(1);
            break;
        case 0x100020:
            sprite_station_board_train(0);
            break;
        default:
            if ((event->trigger & 0xFFFF00) == 0x104000) {
                building_elevator_ride = 1;
                effect_elevator_init((u8)event->trigger);
                goto loop;
            }
            break;
        }
        break;
    case 0x60:
        if (building_state.building == 2) {
            sprite_station_exit_to_town();
        } else if (building_state.building >= 3 && building_state.building < 8) {
            bstate = &building_state;
            shop_exit_to_town(building_state.building, bstate->entry);
        } else {
            goto loop;
        }
        break;
    case 0x30:
        if (building_state.building != 3 && building_state.building != 6) {
            shop_open_menu(building_state.building, event_state.trigger);
            break;
        }
    default:
        if (event->trigger >= 0xF02150 && event->trigger < 0xF02155) {
            if (status->hours_awake < 6) {
                dialog_show(" \202\275\202\301\202\325\202\350\202\306\201A\220\207\226\260\202\315\202\306\202\352\202\304\202\242\202\351", 1, -1, 0, -1, 0, 4);
                break;
            }
            building_wake_index = event->trigger & 0xF;
        }
    loop:
        set = action_find_set(event->circle_set);
        if (set != NULL) {
            while ((set = action_run_set(set, 0, 0)) != NULL) {
            }
        }
        break;
    }
    event->state = 1;
    event->circle_flags &= ~8;
}

static void building_update_input(void) {
    PlayerStatus *status = &player_status;
    Player *player = status->player;
    s32 pad;

    if (kaj_system.pad_mode != 1) {
        return;
    }
    if (*(u32 *)&player->climbing & 0x2A0000) {
        return;
    }
    pad = kaj_pad_read();
    if (building_state.building < 3 && effect_item_input(status, 1) != 0) {
        return;
    }
    if (shop_update_input(status) != 0) {
        return;
    }
    if (effect_weapon_input(status) != 0) {
        return;
    }
    if (player->flags & 4) {
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            building_on_action(status);
            return;
        }
        if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            EventState *event = &event_state;
            ShopState *r = shop_state;
            void *set;

            if (event->state == 2 && (event->cross_flags & 2)) {
                sound_se_play(8);
                dialog_close();
                if (event->trigger_type == 0x30) {
                    switch (building_state.building) {
                    case 4:
                    case 5:
                        r->to_inventory = 1;
                        shop_open_menu(building_state.building, event_state.trigger);
                        break;
                    }
                } else {
                    set = action_find_set(event->cross_set);
                    if (set != NULL) {
                        sound_se_play(8);
                        while ((set = action_run_set(set, 0, 0)) != NULL) {
                        }
                    }
                }
                event->state = 1;
                event->cross_flags &= ~2;
            }
            return;
        }
    }
    player_handle_pad(status, 1, pad);
}

static void building_load(void) {
    char path[16];
    SceneRequestBuilding *req = &main_scene_request;
    BuildingState *bstate;

    action_reset(1);
    event_effect_done_hook = building_on_effect_done;
    bstate = &building_state;
    bstate->entry = req->entry;
    building_scene_daylight = 0;
    building_state.building = req->building;
    if (building_elevator_ride == 1) {
        return;
    }
    sprite_set_visible(0x410, 1);
    block_set_mode(1);
    memset(path, 0, 0x10);
    sprintf(path, "\\S\\%s.S;1", req->name);
    req->path = path;
    object_load_scene();
    effect_weapon_load_models();
    switch (building_state.building) {
    case 0:
        switch (bstate->entry) {
        case 4:
            thing_set_active(3, 8, 1);
            thing_set_animate(3, 8, 1);
            thing_set_active(3, 9, 1);
            thing_set_animate(3, 9, 1);
            break;
        case 22:
            npc_rec_show(5, 1);
            thing_set_active(3, 6, 1);
            thing_set_animate(3, 6, 1);
            break;
        case 23:
            npc_rec_show(2, 0);
            event_enter_hook = building_on_enter;
            break;
        case 28:
            thing_set_active(3, 5, 1);
            thing_set_animate(3, 5, 1);
            break;
        case 30:
            npc_rec_show(1, 1);
            effect_flame_small_init(0);
            break;
        case 7:
            npc_rec_show(2, 0);
        case 9:
            effect_flame_small_init(1);
            effect_flame_large_init();
            break;
        case 33:
            thing_set_active(0, 1, 1);
            effect_flame_small_init(0);
        case 31:
        case 32:
        case 34:
            npc_rec_show(1, 1);
            break;
        case 39:
            npc_rec_show(3, 0);
        case 1:
        case 15:
            npc_rec_show(2, 0);
            break;
        }
        break;
    case 1:
        building_scene_daylight = building_state.building;
    case 2:
        sprite_station_init();
        break;
    default:
        shop_init(bstate->building);
        break;
    }
    if (req->entry_se != 0) {
        sound_se_play(0x21);
    }
    event_show_clock(building_scene_daylight);
    sprite_set_visible(0x410, 0);
}

static void building_run(void) {
    s32 ev[6];
    s16 done;

    building_load();
    done = 0;
    kaj_timer_enable();
    if (building_elevator_ride == 0) {
        effect_start_fade(0, 3);
    } else {
        building_elevator_ride = 0;
        kaj_pad_reset(1);
    }
    while (done == 0) {
        switch (kaj_event_get(ev)) {
        case 0x10:
            event_handle_enter(ev);
            continue;
        case 0x400:
            shop_open_topic_list();
            continue;
        case 0x20:
            event_handle_leave(ev);
            continue;
        case 0x4:
            event_handle_tick(building_scene_daylight);
            continue;
        case 0x200:
            event_handle_mod_finish(ev);
            continue;
        case 0x0:
            building_update_input();
            if (main_take_scene_change() != 0) {
                if (building_elevator_ride == 0) {
                    effect_start_fade(1, 3);
                } else {
                    kaj_pad_reset(0);
                    done = 1;
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
        main_step_frame(1, 1, 1);
    }
    kaj_timer_disable();
    event_enter_hook = 0;
    event_leave_hook = 0;
    event_effect_done_hook = 0;
    event_tick_hook = 0;
    action_reset(1);
    dialog_close();
    if (building_elevator_ride != 1) {
        block_stream_stop();
        sound_bgm_stop();
        sound_se_stop_all();
        effect_flame_small_free();
        effect_flame_large_free();
        action_free_triggers();
        actor_free_all();
        actor_free_bodies();
        actor_free_stats();
        effect_weapon_reset();
        action_free_all_sets();
        block_free_all();
        door_free_all();
        mod_free_all();
        thing_free_all();
        sound_bgm_close();
        sound_se_pop_scene();
        sprite_delete(2);
        sprite_delete(3);
        sprite_delete(4);
    }
}

static s32 building_on_enter(KajEvent *ev) {
    s32 code = ev->param1;

    if (code == 0xF0233C) {
        building_wake_index = 5;
    } else if (code == 0xF02350) {
        building_wake_index = 6;
    } else if (code == 0xF0235A) {
        building_wake_index = 7;
    }
    return 0;
}

void building_main(void) {
    building_elevator_ride = 0;
    block_create_all();
    while (1) {
        building_run();
        if (building_elevator_ride != 1) {
            break;
        }
        effect_elevator_run();
    }
}

static void building_bus_input(s16 building, s16 start_floor, s16 *floor) {
    s32 se;
    s16 played;
    s32 i;
    s32 stop;

    if (kaj_system.pad_mode == 1) {
        played = 0;
        kaj_pad_read();
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            played = 1;
            se = 0x18;
            if (*floor == start_floor) {
                se = 0x11;
            }
            stop = (building * 11 + *floor - 12) * 3;
            main_goto_twn(building_bus_stops[stop] * 10, 0, building_bus_stops[stop + 1] * 10, building_bus_stops[stop + 2], 0);
        } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            played = 1;
            se = 8;
            *floor = start_floor;
            stop = (building * 11 + start_floor - 12) * 3;
            main_goto_twn(building_bus_stops[stop] * 10, 0, building_bus_stops[stop + 1] * 10, building_bus_stops[stop + 2], 0);
        } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
            played = 1;
            se = 0xF;
            (*floor)--;
            if (building != 3) {
                if (*floor >= 12) {
                    *floor = 1;
                }
                if (*floor <= 0) {
                    *floor = 11;
                }
            } else {
                if (*floor >= 6) {
                    *floor = 1;
                }
                if (*floor <= 0) {
                    *floor = 5;
                }
            }
            for (i = 1; i < 12; i++) {
                sprite_set_clut_entry(0, (building << 4) + i, 0x5BBD);
                sprite_set_clut_entry(0, i, 0x1D40);
            }
            sprite_set_clut_entry(0, (building << 4) + *floor, 0x29F);
            sprite_set_clut_entry(0, *floor, 0x1D5F);
        } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
            played = 1;
            se = 0xF;
            (*floor)++;
            if (building != 3) {
                if (*floor >= 12) {
                    *floor = 1;
                }
                if (*floor <= 0) {
                    *floor = 11;
                }
            } else {
                if (*floor >= 6) {
                    *floor = 1;
                }
                if (*floor <= 0) {
                    *floor = 5;
                }
            }
            for (i = 1; i < 12; i++) {
                sprite_set_clut_entry(0, (building << 4) + i, 0x5BBD);
                sprite_set_clut_entry(0, i, 0x1D40);
            }
            sprite_set_clut_entry(0, (building << 4) + *floor, 0x29F);
            sprite_set_clut_entry(0, *floor, 0x1D5F);
        }
        if (played) {
            sound_se_play(se);
        }
    }
}

void building_bus_run(s16 building, s16 start_floor) {
    s32 ev[6];
    s16 floor;
    s16 done;
    s32 i;
    s32 moved;
    s16 last_floor;

    done = 0;
    floor = start_floor;
    event_effect_done_hook = 0;
    sprite_set_visible(0x400, 0);
    sprite_set_visible(0x409, 0);
    sprite_set_visible(0x40E, 0);
    sprite_set_visible(0, 1);
    sprite_set_visible((u16)building, 1);
    sprite_set_clut_entry(0, (building << 4) + start_floor, 0x29F);
    sprite_set_clut_entry(0, start_floor, 0x1D5F);
    main_wait(3, 0, 0, 2);
    kaj_pad_reset(1);
    kaj_timer_enable();
    do {
        switch (kaj_event_get(ev)) {
        case 0x4:
            event_handle_tick(1);
            continue;
        case 0x0:
            building_bus_input(building, start_floor, &floor);
            if (main_take_scene_change() != 0) {
                effect_start_fade(1, 3);
            }
            break;
        case 0x100:
            done = event_handle_effect_done(ev);
            continue;
        default:
            kaj_event_done(ev);
            continue;
        }
        roadmap_draw_frame(2);
    } while (done == 0);
    kaj_timer_disable();
    last_floor = floor;
    for (i = 1; i < 12; i++) {
        sprite_set_clut_entry(0, (building << 4) + i, 0x5BBD);
        sprite_set_clut_entry(0, i, 0x1D40);
    }
    sprite_set_visible(0x400, 1);
    sprite_set_visible(0x409, 1);
    sprite_set_visible(0x40E, 1);
    sprite_set_visible(0, 0);
    sprite_set_visible((u16)building, 0);
    moved = last_floor - start_floor;
    event_advance_clock((moved < 0 ? -moved : moved) * 5, 0);
}
