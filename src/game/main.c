#include "common.h"
#include "game/main.h"
#include "game/action.h"
#include "game/actor.h"
#include "game/building.h"
#include "game/door.h"
#include "game/effect.h"
#include "game/event.h"
#include "game/mod.h"
#include "game/npc.h"
#include "game/object.h"
#include "game/player.h"
#include "game/roadmap.h"
#include "game/sprite.h"
#include "game/thing.h"
#include "game/town.h"
#include "game/vehicle.h"
#include "kaj/event.h"
#include "kaj/kaj.h"
#include "kaj/ll.h"
#include "kaj/misc.h"
#include "psyq/libc.h"

/*
 * main, the scene changes (office, town, building) and small angle and level helpers.
 *
 * File boundaries: guess (docs/layout.md): main, a file only by its name.
 */

extern SceneRequest main_scene_request;
extern GameVars action_vars;
extern SceneTables object_scene_tables;
extern PlayerStatus player_status;
extern KajSystem kaj_system;
typedef struct {
    s16 loop;
    s16 next_loop;
    s16 scene_index;
    s16 variant;
    s16 quit;
    s16 change;
    char *path;
    s16 building;
    s16 building_room;
    s16 entry_sound;
    s16 map_letter;
    s16 map_entry;
    s16 yaw;
    s16 script_entry;
    u8 unk1E[2];
    char scene_name[4];
} BuildingRequest;
s16 main_restarted;
extern s32 event_effect_done_hook;
extern s32 event_alarm_hook;
extern s32 event_tick_hook;
extern s32 event_leave_hook;
extern s32 event_enter_hook;
extern s32 event_mod_finish_hook;
extern void *action_set_list;
extern void *action_queue;
extern void *block_list;
extern void *door_list;
extern void *mod_list;
extern void *sprite_list;
extern void *thing_list;

void main(void) {
    SceneRequest *request;
    SceneRequest *request_init;
    GameVars *game;
    s16 restarted;
    u16 car_speed;
    u16 text_speed;

    kaj_init();
    memset(&object_scene_tables, 0, 0x64);
    event_alarm_hook = 0;
    event_enter_hook = 0;
    event_leave_hook = 0;
    event_tick_hook = 0;
    event_effect_done_hook = 0;
    event_mod_finish_hook = 0;
    kaj_ll_create(&action_set_list);
    kaj_ll_create(&action_queue);
    kaj_ll_create(&block_list);
    kaj_ll_create(&door_list);
    kaj_ll_create(&mod_list);
    kaj_ll_create(&sprite_list);
    kaj_ll_create(&thing_list);
    event_open();
    roadmap_init_draw();
    object_load_res(1, 0);
    game = &action_vars;
    while (1) {
        request_init = &main_scene_request;
        restarted = main_restarted;
        if (restarted != 0) {
            car_speed = game->car_speed_setting;
            text_speed = game->text_speed_setting;
        }
        memset(game, 0, sizeof(action_vars));
        memset(request_init, 0, 0x24);
        if (restarted != 0) {
            game->car_speed_setting = car_speed;
            game->text_speed_setting = text_speed;
        } else {
            game->car_speed_setting = 1;
            game->text_speed_setting = 1;
        }
        request_init->loop = -1;
        request_init->next_loop = -1;
        player_init();
        game->vars[0x5F] = 3;
        game->mail_codes[0] = -0x7E80;
        game->mail_codes[5] = 0x82;
        game->vars[0xA] = 100;
        game->vars[0xB] = 100;
        game->vars[0xC] = 100;
        game->vars[0xD] = 100;
        game->vars[0x1B] = 100;
        game->vars[0x3E] = 5;
        game->vars[0x3F] = 0;
        game->vars[0x30] = 0;
        game->drain_minute = 0;
        game->drain_count = 0;
        effect_clear_alarms();
        request = &main_scene_request;
        vehicle_train_init_state();
        sprite_title_run(main_restarted);
        kaj_srand_ticks();
        sprite_set_visible(0x400, 1);
        sprite_set_visible(0x409, 1);
        event_draw_hud();
        while (request->quit == 0) {
            if (request->loop != request->next_loop) {
                request->loop = request->next_loop;
            }
            switch (request->loop) {
            case 1:
                building_main();
                break;
            case 0:
                object_room_run();
                break;
            case 2:
                town_game_loop();
                break;
            }
        }
        request->quit = 0;
        sprite_set_visible(0x400, 0);
        sprite_set_visible(0x409, 0);
        if (main_restarted == 0) {
            main_restarted = 1;
        }
    }
}

s32 main_angle_to_dir8(s16 angle) {
    s32 b;

loop:
    if (angle < 0) angle += 360;
    if (angle >= 360) angle -= 360;
    if ((u16)angle >= 360) goto loop;
    b = angle;
    if (b >= 23 && b < 68) return 1;
    if (b >= 68 && b < 113) return 0;
    if (b >= 113 && b < 158) return 7;
    if (b >= 158 && b < 203) return 6;
    if (b >= 203 && b < 248) return 5;
    if (b >= 248 && b < 293) return 4;
    if (b >= 293 && b < 338) return 3;
    return 2;
}

s32 main_take_scene_change(void) {
    SceneRequest *p = &main_scene_request;
    if (p->change == 0) {
        return 0;
    }
    p->change = 0;
    kaj_pad_reset(0);
    return 1;
}

void main_wait(s32 mode, s32 stream, s32 visibility, s32 seconds) {
    s32 buf[6];
    s32 frames;
    for (frames = seconds * 30; frames > 0;) {
            switch (kaj_event_get(buf)) {
            case 2:
                event_handle_alarm(buf);
                continue;
            case 4:
                event_handle_tick(0);
                continue;
            case 0x200:
                event_handle_mod_finish(buf);
                continue;
            case 0:
                frames -= kaj_system.vsync_delta;
                break;
            case 0x100:
                event_handle_effect_done(buf);
                continue;
            default:
                kaj_event_done(buf);
                continue;
            }
            if ((u16)mode == 3) {
                thing_update_all();
                roadmap_draw_frame(3);
            } else {
                do { main_step_frame(mode, stream, visibility); } while (0);
            }
    }
}

void main_step_frame(u16 mode, s16 b, s16 c) {
    GameVars *game = &action_vars;
    action_update();
    if (mode < 2) {
        actor_update_all();
        door_update_all();
        npc_rec_update_all();
    } else if (mode == 2) {
        vehicle_update();
    }
    mod_update_all();
    thing_update_all();
    player_update(mode, b, c);
    if ((u16)(mode - 1) < 2) {
        if (game->flame_small_on != 0) {
            effect_flame_small_update();
        }
        if (game->clut_cycle_on != 0) {
            effect_clut_cycle_update();
        }
        if (game->flame_large_on != 0) {
            effect_flame_large_update();
        }
    }
    roadmap_draw_frame(mode);
}

void main_goto_ofc(s16 a, s16 yaw, s16 c, s16 d) {
    SceneRequest *request = &main_scene_request;
    PlayerStatus *status = &player_status;
    GameVars *game = &action_vars;
    request->yaw = yaw;
    ((s16 *)&request->pos_x)[0] = c;
    ((s16 *)&request->pos_x)[1] = d;
    request->next_loop = 0;
    request->change = 1;
    request->path = "\\S\\OFC.S;1";
    request->variant = 0;
    request->scene_index = 0;
    request->loop_param = a;
    if (d == 2) {
        return;
    }
    if ((s16)game->vars[0x30] != 0 || status->mutant != 0) {
        return;
    }
    switch (status->arrests) {
    case 0:
        if (status->kills_since_arrest >= 3) {
            request->variant = 1;
            status->arrests = 1;
            status->kills_since_arrest = 0;
        }
        break;
    case 1:
        if (status->kills_since_arrest >= 5 && (s16)game->vars[0x11] != 100) {
            game->vars[0x11] = 100;
            request->variant = 1;
            status->arrests = 2;
            status->kills_since_arrest = 0;
        }
        break;
    }
}

void main_goto_twn(s32 x, s32 y, s32 z, s16 yaw, s16 e) {
    SceneRequest *request = &main_scene_request;
    request->change = 1;
    request->next_loop = 2;
    request->variant = 0;
    request->scene_index = 1;
    request->path = "\\S\\TWN.S;1";
    request->pos_x = x;
    request->pos_y = y;
    request->pos_z = z;
    request->yaw = yaw;
    request->loop_param = e;
}

void main_goto_building(u16 form, char *name, s16 var, s16 map_letter, u16 map_entry, u16 yaw, u16 scene_index, u32 trigger, u16 script_entry) {
    BuildingRequest *request = (BuildingRequest *)&main_scene_request;
    GameVars *game = &action_vars;

    request->change = 1;
    switch ((s16)game->vars[var]) {
    case 0:
        request->variant = 0;
        break;
    case 10:
        request->variant = 2;
        break;
    case 1000:
        request->variant = 3;
        break;
    case 2000:
        request->variant = 4;
        break;
    default:
        request->variant = 1;
        break;
    }
    request->next_loop = 1;
    request->path = NULL;
    request->scene_index = scene_index;
    memset(request->scene_name, 0, 4);
    strncpy(request->scene_name, name, 3);
    request->map_letter = map_letter;
    request->map_entry = map_entry;
    request->yaw = yaw;
    request->entry_sound = 0;
    request->script_entry = script_entry;
    if (var != 13 && (u16)(var - 11) < 16 && (u32)(*(game->vars + var) - 11) < 90) {
        request->entry_sound = 1;
    }
    if (form == 1) {
        switch ((trigger >> 16) & 0xFF) {
        case 0xF6:
            request->building = 1;
            request->building_room = trigger & 0xFF;
            break;
        case 0xF9:
            request->building = 2;
            request->building_room = trigger & 0xFF;
            break;
        default:
            request->building = 0;
            request->building_room = (s8)(trigger >> 8);
            break;
        }
    } else {
        request->building = ((trigger & 0xFF00) >> 8) + 2;
        request->building_room = trigger & 0xFF;
    }
}

s16 main_wrap_angle(s16 angle) {
    do {
        if (angle < 0) angle += 360;
        if (angle >= 360) angle -= 360;
    } while ((u16)angle >= 360);
    return angle;
}

s32 main_angle_to_dir4(s16 angle) {
    s32 b;

loop:
    if (angle < 0) angle += 360;
    if (angle >= 360) angle -= 360;
    if ((u16)angle >= 360) goto loop;
    b = angle;
    if (b >= 45 && b < 135) return 0;
    if (b >= 135 && b < 225) return 6;
    if (b >= 225 && b < 315) return 4;
    return 2;
}

s32 main_exp_for_level(s32 level) {
    s32 i;
    s32 exp;
    if (level == 1) return 0;
    if (level == 2) return 0x144;
    exp = 0x144;
    for (i = 3; i <= level; i++) {
        exp += 0x195 + (i - 3) * 0xA2;
    }
    return exp;
}
