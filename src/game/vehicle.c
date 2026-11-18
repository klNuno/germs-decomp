#include "common.h"
#include "game/vehicle.h"
#include "game/action.h"
#include "game/block.h"
#include "game/dialog.h"
#include "game/main.h"
#include "game/menu.h"
#include "game/object.h"
#include "game/player.h"
#include "game/roadmap.h"
#include "game/sound.h"
#include "game/sprite.h"
#include "game/thing.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "kaj/tss.h"
#include "kaj/view.h"
#include "psyq/libapi.h"
#include "psyq/libgpu.h"
#include "psyq/libgs.h"
#include "psyq/libgte.h"
#include "gte.h"

/*
 * The train and the car: placing, doors, driving, the car navigation.
 *
 * File boundaries: guess (docs/layout.md): vehicle.c asserts; its start is a guess.
 */

extern TrainState vehicle_train_state;
extern Player *player_status_player[];
extern s16 vehicle_navi[];
extern GameVars action_vars;
typedef struct VehicleRecord {
    u16 kind;
    u8 unk2[0x16];
    s32 model0_offset;
    s32 model1_offset;
} VehicleRecord;
static void vehicle_train_calc_stops(TrainState *train);
extern Thing *player_status_vehicle[];
extern CarState vehicle_car_state;
s16 vehicle_car_exit_prompt_on;
s32 vehicle_car_speed_div;
extern Vehicle *object_scene_vehicle[];
extern s32 kaj_system_vsync_delta[];

static void vehicle_train_calc_stops(TrainState *train) {
    train->placed = 0;
    if (train->direction != 0) {
        train->mark_start = (train->station - 1) * 100000 - 195000;
        train->mark_cruise = (train->station - 1) * 100000 - 175000;
        train->mark_brake = (train->station - 1) * 100000 - 115000;
        train->mark_stop = (train->station - 1) * 100000 - 95000;
    } else {
        train->mark_start = (train->station - 1) * 100000 - 200000;
        train->mark_cruise = (train->station - 1) * 100000 - 220000;
        train->mark_brake = (train->station - 1) * 100000 - 280000;
        train->mark_stop = (train->station - 1) * 100000 - 300000;
    }
}

static void vehicle_car_init(Vehicle *car, Player *player) {
    s32 v[3];
    SVector sv;
    s32 flag;
    VehicleRecord *hdr = car->data;
    Thing *car_thing = player_status_vehicle[0];
    CarState *state = &vehicle_car_state;
    CarNavi *navi = (CarNavi *)vehicle_navi;
    GameVars *game = &action_vars;

    car->kind = hdr->kind;
    car->ot_layer = 0;
    GsSetLsMatrix(car_thing->coord_m);
    state->seat.vx = -180;
    state->seat.vy = -120;
    state->look_pitch = 0;
    state->look_yaw = 0;
    state->look_roll = 0;
    state->seat.vz = 200;
    RotTrans(&state->seat, v, &flag);
    if (hdr->model0_offset != 0) {
        kaj_tmd_load(&car->model0, (u8 *)car->data + hdr->model0_offset, &car->coord.flg);
    }
    GsInitCoordinate2(NULL, &car->coord.flg);
    car->pos_x = car_thing->pos_x;
    car->pos_y = car_thing->pos_y + 370;
    car->pos_z = car_thing->pos_z;
    car->rot_x = car_thing->rot_x;
    car->rot_y = car_thing->rot_y;
    car->rot_z = car_thing->rot_z;
    car->coord.coord_tx = car->pos_x - player->cell_x * 12500;
    car->coord.coord_ty = car->pos_y + player->cell_y * 32000;
    car->coord.coord_tz = car->pos_z - player->cell_z * 12500;
    sv.vx = (car->rot_x << 12) / 360;
    sv.vy = (car->rot_y << 12) / 360;
    sv.vz = (car->rot_z << 12) / 360;
    RotMatrix(&sv, car->coord.coord_m);
    if (hdr->model1_offset != 0) {
        kaj_tmd_load(&car->model1, (u8 *)car->data + hdr->model1_offset, &car->coord2.flg);
    }
    GsInitCoordinate2(&car->coord.flg, &car->coord2.flg);
    car->coord2.coord_tx = -180;
    car->coord2.coord_ty = -360;
    car->coord2.coord_tz = 412;
    sv.vx = 56;
    sv.vy = 0;
    sv.vz = 0;
    RotMatrix(&sv, car->coord2.coord_m);
    player->pos_x = v[0] + player->cell_x * 12500;
    player->pos_y = v[1] - player->cell_y * 32000;
    player->pos_z = v[2] + player->cell_z * 12500;
    player->pitch = 0;
    player->yaw = car->rot_y;
    player->roll = 0;
    player_set_view(player, 1);
    state->stopped = 0;
    state->slowed = 0;
    vehicle_car_exit_prompt_on = 0;
    state->steer = 0;
    state->brake = 0;
    state->throttle = 0;
    state->gear = 0;
    state->speed = 0;
    state->turn_yaw = 0;
    state->turn_radius = 0;
    state->corners[0].vx = -75;
    state->corners[0].vy = 0;
    state->corners[0].vz = 102;
    state->corners[1].vx = 75;
    state->corners[1].vy = 0;
    state->corners[1].vz = 102;
    state->corners[2].vx = -75;
    state->corners[2].vy = 0;
    state->corners[2].vz = -152;
    state->corners[3].vx = 75;
    state->corners[3].vy = 0;
    state->corners[3].vz = -152;
    state->axle_x = 0;
    state->axle_y = 0;
    state->axle_z = 0;
    state->pivot_x = 0;
    state->pivot_y = 0;
    state->pivot_z = 0;
    car->coord.flg = 0;
    car->coord2.flg = 0;
    navi->active = 0;
    navi->menu_reset = 1;
    navi->dest = 0;
    navi->start_dist = 0;
    navi->dest_sprite = 0;
    navi->arrow_sprite = 0;
    switch ((s16)game->car_speed_setting) { /* read signed in this unit */
    case 2:
        vehicle_car_speed_div = 500;
        break;
    case 1:
        vehicle_car_speed_div = 400;
        break;
    case 0:
        vehicle_car_speed_div = 300;
        break;
    }
}

static inline s32 vehicle_car_get_out_try_spot(Vehicle *car, Player *player, s32 *px, s32 *py, s32 *pz, s32 ang) {
    s32 x;
    s32 z;
    x = car->pos_x + ((*px * rcos(ang) + *pz * rsin(ang)) >> 12);
    z = car->pos_z + ((*pz * rcos(ang) - *px * rsin(ang)) >> 12);
    *px = x - player->cell_x * 12500;
    *pz = z - player->cell_z * 12500;
    if ((s16)block_has_ground_at(*px, py, *pz)) {
        *px = x;
        *pz = z;
        return 1;
    }
    return 0;
}

static void vehicle_car_get_out(Vehicle *car) {
    s32 x;
    s32 y;
    s32 z;
    s32 ang;
    Player *player = player_status_player[0];

    player->car_x = car->pos_x;
    player->car_y = car->pos_y - 370;
    player->car_z = car->pos_z;
    player->car_rot_x = car->rot_x;
    player->car_rot_y = car->rot_y;
    player->car_rot_z = car->rot_z;
    ang = (car->rot_y << 12) / 360;
    x = -245;
    z = 0;
    if (!vehicle_car_get_out_try_spot(car, player, &x, &y, &z, ang)) {
        x = 245;
        z = 0;
        if (!vehicle_car_get_out_try_spot(car, player, &x, &y, &z, ang)) {
            x = 0;
            z = -490;
            if (!vehicle_car_get_out_try_spot(car, player, &x, &y, &z, ang)) {
                x = 0;
                z = 490;
                if (!vehicle_car_get_out_try_spot(car, player, &x, &y, &z, ang)) {
                    z = 0;
                    y = 0;
                    x = 0;
                }
            }
        }
    }
    sound_se_stop(0x1A);
    vehicle_navi_show(NULL, 0, 1);
    sprite_delete(4);
    vehicle_navi[0] = 0;
    main_goto_twn(x, y, z, car->rot_y, 0);
}

static void vehicle_train_init(Vehicle *car, Player *player) {
    SVector sv;
    VehicleRecord *hdr = car->data;
    TrainState *train = &vehicle_train_state;

    car->kind = hdr->kind;
    car->ot_layer = 0;
    vehicle_train_calc_stops(train);
    if (hdr->model0_offset != 0) {
        kaj_tmd_load(&car->model0, (u8 *)car->data + hdr->model0_offset, &car->coord.flg);
    }
    if (hdr->model1_offset != 0) {
        kaj_tmd_load(&car->model1, (u8 *)car->data + hdr->model1_offset, &car->coord.flg);
    }
    GsInitCoordinate2(NULL, &car->coord.flg);
    car->pos_x = player->cell_x * 12500 + player->pos_x;
    car->pos_y = -(player->cell_y * 32000) + 75;
    car->pos_z = player->cell_z * 12500 + player->pos_z;
    car->rot_x = 0;
    car->rot_y = 0;
    car->rot_z = 0;
    if (train->direction == 0) {
        car->rot_y = 180;
        player->yaw -= 180;
    }
    train->carry_vx = 0;
    train->carry_vy = 0;
    train->carry_vz = 0;
    train->view_pitch = player->pitch;
    train->view_yaw = player->yaw;
    train->view_roll = player->roll;
    car->coord.coord_tx = car->pos_x - player->cell_x * 12500;
    car->coord.coord_ty = car->pos_y + player->cell_y * 32000;
    car->coord.coord_tz = car->pos_z - player->cell_z * 12500;
    sv.vx = (car->rot_x << 12) / 360;
    sv.vy = (car->rot_y << 12) / 360;
    sv.vz = (car->rot_z << 12) / 360;
    RotMatrix(&sv, car->coord.coord_m);
    car->coord.flg = 0;
}

static void vehicle_train_drive(Player *player) {
    s32 v[4];
    s32 flag;
    Vehicle *car = object_scene_vehicle[0];
    TrainState *train = &vehicle_train_state;
    GameVars *game = &action_vars;

    if (train->motion != 0) {
        player->view_dirty = 1;
    }
    if (train->direction != 0) {
        if (train->motion == 3) {
            train->speed = (train->mark_stop - car->pos_z) / 300 + 7;
            car->pos_z += train->speed * kaj_system_vsync_delta[0];
            if (car->pos_z >= train->mark_stop) {
                sound_se_stop(0x1F);
                train->speed = 0;
                car->pos_z = train->mark_stop;
                train->motion = 0;
                train->stop_timer = 2;
                if (++train->station >= 7) {
                    train->station = 6;
                }
                vehicle_train_calc_stops(train);
                vehicle_train_set_doors(1);
                train->arrive_digit_dir1 = (s16)game->vars[0x3F] % 10;
                if (train->arrive_digit_dir1 >= 5) {
                    train->arrive_digit_dir0 = train->arrive_digit_dir1 - 5;
                } else {
                    train->arrive_digit_dir0 = train->arrive_digit_dir1 + 5;
                }
            }
        } else if (train->motion == 1) {
            train->speed = (car->pos_z - train->mark_start) / 300 + 7;
            car->pos_z += train->speed * kaj_system_vsync_delta[0];
            if (car->pos_z >= train->mark_cruise) {
                train->motion = 2;
            }
        } else if (train->motion == 2) {
            car->pos_z += train->speed * kaj_system_vsync_delta[0];
            if (car->pos_z >= train->mark_brake) {
                train->motion = 3;
            }
        }
    } else {
        if (train->motion == 3) {
            train->speed = (car->pos_z - train->mark_stop) / 300 + 7;
            car->pos_z -= train->speed * kaj_system_vsync_delta[0];
            if (car->pos_z <= train->mark_stop) {
                sound_se_stop(0x1F);
                train->speed = 0;
                car->pos_z = train->mark_stop;
                train->motion = 0;
                train->stop_timer = 2;
                if (--train->station == 0) {
                    train->station = 1;
                }
                vehicle_train_calc_stops(train);
                vehicle_train_set_doors(1);
                train->arrive_digit_dir0 = (s16)game->vars[0x3F] % 10;
                if (train->arrive_digit_dir0 >= 5) {
                    train->arrive_digit_dir1 = train->arrive_digit_dir0 - 5;
                } else {
                    train->arrive_digit_dir1 = train->arrive_digit_dir0 + 5;
                }
            }
        } else if (train->motion == 1) {
            train->speed = (train->mark_start - car->pos_z) / 300 + 7;
            car->pos_z -= train->speed * kaj_system_vsync_delta[0];
            if (car->pos_z <= train->mark_cruise) {
                train->motion = 2;
            }
        } else if (train->motion == 2) {
            car->pos_z -= train->speed * kaj_system_vsync_delta[0];
            if (car->pos_z <= train->mark_brake) {
                train->motion = 3;
            }
        }
    }
    car->coord.coord_tz = car->pos_z - player->cell_z * 12500;
    car->coord.flg = 0;
    GsSetLsMatrix(car->coord.coord_m);
    RotTrans(&train->carry_vx, v, &flag);
    player->pos_x = v[0];
    player->pos_z = v[2];
    player->pitch = train->view_pitch + car->rot_x;
    player->yaw = train->view_yaw + car->rot_y;
    player->roll = train->view_roll + car->rot_z;
}

extern Player *player_status_player[];
extern Vehicle *object_scene_vehicle[];
static void vehicle_car_init(Vehicle *car, Player *player);
static void vehicle_train_init(Vehicle *car, Player *player);
extern SceneTables object_scene_tables;
static void vehicle_car_get_out(Vehicle *car);
static void vehicle_car_drive(Player *player);
static void vehicle_train_drive(Player *player);
typedef struct TimHandle { u16 x; u16 y; u8 pad4[0x10]; s16 pixel_shift; } TimHandle;
extern PlayerStatus player_status;
extern s16 vehicle_navi[];
extern TrainState vehicle_train_state;
extern char vehicle_str_file[];
extern char vehicle_str_alloc_pointer[];
extern char vehicle_str_alloc_buffer[];
extern EventState event_state;
void dialog_show(char *str, s32 mode, s32 circle_set, s32 circle_flags, s32 cross_set, s32 cross_flags, s32 se);
extern s32 vehicle_str_sb1[];
extern s32 vehicle_str_rw1[];
void main_goto_building(s32 form, s32 *name, s32 var, s32 map_letter, s32 map_entry, s32 yaw, s32 scene_index, s32 trigger, s32 script_entry);
extern SceneRequest main_scene_request;
extern KajSystem kaj_system;
extern RoadMap roadmap_state;
static void vehicle_navi_open_menu(void);
extern s16 vehicle_navi_dest_xz[];
static void vehicle_train_door_frame(TssSlot *task);
static void vehicle_train_door_last(TssSlot *task);
s16 vehicle_navi_blink;
extern s32 kaj_system_vsync_delta[];
extern CarState vehicle_car_state;
static s16 vehicle_car_stopped_input(void);
static void vehicle_navi_update(Vehicle *car, Player *player);
s16 vehicle_car_turn_sfx_on;
s16 vehicle_car_exit_prompt_on;
s32 vehicle_car_speed_div;
s32 roadmap_get_state(void);
extern ScreenLight roadmap_screen_light;
extern s16 roadmap_draw_flags;

INCLUDE_RODATA("asm/nonmatchings/game/vehicle", vehicle_str_alloc_pointer);

INCLUDE_RODATA("asm/nonmatchings/game/vehicle", vehicle_str_file);

INCLUDE_RODATA("asm/nonmatchings/game/vehicle", vehicle_str_alloc_buffer);

static void vehicle_car_drive(Player *player) {
    SVector sv;
    s32 flag;
    Vehicle *car = object_scene_vehicle[0];
    CarState *state = &vehicle_car_state;
    s32 speed_div;
    s32 revs;
    s32 speed;
    s16 sgn;
    s16 steer_abs;
    s32 sn;
    s32 cs;
    s32 t;
    s32 ang;

    state->stopped = 0;
    vehicle_navi_update(car, player);
    sv.vx = 0;
    sv.vy = 0;
    sv.vz = (state->steer << 12) / 360;
    RotMatrix(&sv, car->coord2.coord_m);
    car->coord2.flg = 0;
    speed_div = vehicle_car_speed_div;
    if (state->slowed != 0) {
        speed_div = vehicle_car_speed_div * 3;
    }
    if (state->gear == 1) {
        revs = state->brake * 30 + 800;
        if (revs > 6500) {
            revs = 6500;
        }
        if (state->throttle != 0) {
            revs -= state->throttle * 45;
        }
        if (revs < 800) {
            revs = 800;
        }
        speed = (revs - 800) * 347436 / (speed_div * 55086);
    } else if (state->gear == -1) {
        revs = state->throttle * 30 + 800;
        if (revs > 6500) {
            revs = 6500;
        }
        if (state->brake != 0) {
            revs -= state->brake * 45;
        }
        if (revs < 800) {
            revs = 800;
        }
        speed = -((revs - 800) * 347436) / (speed_div * 72566);
    } else {
        speed = 0;
    }
    speed = ((speed << 12) / 4) >> 12;
    sgn = 0;
    state->speed = speed * kaj_system_vsync_delta[0];
    if (state->steer != 0) {
        if (state->steer > 0) {
            sgn = 1;
        } else {
            sgn = -1;
        }
    }
    steer_abs = state->steer < 0 ? -state->steer : state->steer;
    ang = (steer_abs << 12) / 360;
    sn = rsin(ang);
    cs = rcos(ang);
    t = (sn << 12) / cs;
    if (t == 0) {
        state->turn_radius = 0;
    } else {
        state->turn_radius = 0xFE000 / t;
    }
    if (state->speed == 0) {
        state->stopped = 1;
        state->turn_radius = 0;
        state->turn_yaw = 0;
        vehicle_car_turn_sfx_on = 0;
    } else {
        player->view_dirty = 1;
        t = (sgn * state->turn_radius * cs) >> 12;
        GsSetLsMatrix(&car->coord.coord_m);
        sv.vx = t;
        sv.vy = 0;
        sv.vz = -0x98;
        RotTrans(&sv, &state->pivot_x, &flag);
        sv.vx = 0;
        sv.vy = 0;
        sv.vz = -0x98;
        RotTrans(&sv, &state->axle_x, &flag);
        state->turn_yaw = 0;
        if (state->turn_radius != 0) {
            state->turn_yaw = (sgn * ratan2(speed, state->turn_radius) * 360) >> 12;
            if (state->turn_yaw == 0) {
                state->turn_yaw = 1;
            }
        }
        if (speed >= 25 && steer_abs >= 40 && vehicle_car_turn_sfx_on == 0) {
            vehicle_car_turn_sfx_on = 1;
            sound_se_play(0x1B);
        } else {
            vehicle_car_turn_sfx_on = 0;
        }
    }
    if (state->stopped != 0) {
        if (roadmap_get_state() != 0 || menu_get_state() != 0) {
            if (vehicle_car_exit_prompt_on != 0) {
                vehicle_car_exit_prompt_on = 0;
            }
        } else if (vehicle_car_exit_prompt_on == 0) {
            /* car prompt: get out */
            dialog_show(" 7\203N\203\213\203}1\202\251\202\347\215~\202\350\202\351     3\201\233", 1, -1, 0, -1, 0, 1);
            vehicle_car_exit_prompt_on = 1;
        }
    } else if (vehicle_car_exit_prompt_on != 0) {
        dialog_close();
        vehicle_car_exit_prompt_on = 0;
    }
}

void vehicle_train_place(void) {
    SVector sv;
    Player *player = player_status_player[0];
    TrainState *train = &vehicle_train_state;
    Thing *thing = thing_find(2, 0);

    if (thing != NULL) {
        thing->active = 1;
        thing->pos_x = 0xF0A;
        thing->animate = 0;
        thing->pos_y = 0;
        thing->pos_z = 0x3E80;
        thing->rot_x = 0;
        thing->rot_y = 0;
        thing->rot_z = 0;
        if (train->direction == 0) {
            thing->pos_x = -0xF0A;
            thing->rot_y = 180;
        }
        thing->coord_tx = thing->pos_x - player->cell_x * 12500;
        thing->coord_ty = thing->pos_y + player->cell_y * 32000;
        thing->coord_tz = thing->pos_z - player->cell_z * 12500;
        sv.vx = (thing->rot_x << 12) / 360;
        sv.vy = (thing->rot_y << 12) / 360;
        sv.vz = (thing->rot_z << 12) / 360;
        RotMatrix(&sv, thing->coord_m);
        thing->coord_flg = 0;
    }
    train->placed = 1;
    train->motion = 0;
    train->door_state = 1;
}

void vehicle_train_arrive(s16 direction, s16 station) {
    SVector sv;
    Rect rect;
    Player *player = player_status_player[0];
    TrainState *train = &vehicle_train_state;
    Thing *thing = thing_find(2, 0);
    VehicleSprite *sprite;
    TimHandle *tim;
    s16 w;
    u16 h;

    if (thing != NULL && thing->active == 0) {
        thing->animate = 1;
        thing->active = 1;
        thing->pos_x = 0xF0A;
        thing->pos_z = -0x3E80;
        thing->pos_y = 0;
        thing->rot_x = 0;
        thing->rot_y = 0;
        thing->rot_z = 0;
        if (direction == 0) {
            thing->pos_x = -0xF0A;
            thing->pos_z = 0xBB80;
            thing->rot_y = 180;
        }
        thing->coord_tx = thing->pos_x - player->cell_x * 12500;
        thing->coord_ty = thing->pos_y + player->cell_y * 32000;
        thing->coord_tz = thing->pos_z - player->cell_z * 12500;
        sv.vx = (thing->rot_x << 12) / 360;
        sv.vy = (thing->rot_y << 12) / 360;
        sv.vz = (thing->rot_z << 12) / 360;
        RotMatrix(&sv, thing->coord_m);
        thing->coord_flg = 0;
        train->motion = 3;
        train->direction = direction;
        train->door_state = 0;
        train->station = station;
        train->speed = 0;
        train->stop_timer = -1;
    }
    sprite = sprite_find(0x408);
    if (sprite != NULL) {
        tim = sprite->tim;
        w = sprite->cell_w >> tim->pixel_shift;
        h = sprite->cell_h;
        rect.x = tim->x;
        rect.y = sprite->tim->y;
        rect.w = w;
        rect.h = h;
        MoveImage(&rect, 0x2F0, 0x20);
    }
    sound_se_play(0x1E);
}

void vehicle_train_update(Thing *thing) {
    Player *player = player_status_player[0];
    TrainState *train = &vehicle_train_state;
    VehicleSprite *sprite;
    u16 motion;
    s32 step;

    if (train->direction != 0) {
        motion = train->motion;
        if (motion == 3) {
            step = (16000 - thing->pos_z) / 100 + 5;
            thing->pos_z += step * kaj_system_vsync_delta[0];
            if (thing->pos_z >= 16000) {
                thing->animate = 0;
                thing->pos_z = 16000;
                train->motion = 0;
                train->stop_timer = 2;
                sprite = sprite_find(0x408);
                if (sprite == NULL) {
                    train->door_state = 1;
                } else {
                    TssSlot *task;
                    s32 frames;

                    task = kaj_tss_alloc(4);
                    task->type = 7;
                    task->cur = 0;
                    frames = sprite->columns * sprite->rows;
                    task->step = 1;
                    task->target = frames - 1;
                    train->door_state = 3;
                    task->delay = 0x19;
                    task->on_step = vehicle_train_door_frame;
                    task->on_end = vehicle_train_door_last;
                    task->on_kill = vehicle_train_door_last;
                    *(VehicleSprite **)task->data = sprite;
                    train->door_task = kaj_tss_start(task);
                    sound_se_play(0xB);
                }
            }
        } else if (motion == 1) {
            step = (thing->pos_z - 16000) / 100 + 5;
            thing->pos_z += step * kaj_system_vsync_delta[0];
            if (thing->pos_z > 47999) {
                thing->animate = 0;
                thing->active = 0;
                train->motion = 2;
            }
        }
    } else {
        motion = train->motion;
        if (motion == 3) {
            step = (thing->pos_z - 16000) / 100 + 5;
            thing->pos_z -= step * kaj_system_vsync_delta[0];
            if (thing->pos_z <= 16000) {
                thing->pos_z = 16000;
                thing->animate = 0;
                train->motion = 0;
                train->stop_timer = 2;
                sprite = sprite_find(0x408);
                if (sprite == NULL) {
                    train->door_state = 1;
                } else {
                    TssSlot *task;
                    s32 frames;

                    task = kaj_tss_alloc(4);
                    task->type = 7;
                    task->cur = 0;
                    frames = sprite->columns * sprite->rows;
                    task->step = 1;
                    task->target = frames - 1;
                    train->door_state = 3;
                    task->delay = 0x19;
                    task->on_step = vehicle_train_door_frame;
                    task->on_end = vehicle_train_door_last;
                    task->on_kill = vehicle_train_door_last;
                    *(VehicleSprite **)task->data = sprite;
                    train->door_task = kaj_tss_start(task);
                    sound_se_play(0xB);
                }
            }
        } else if (motion == 1) {
            step = (16000 - thing->pos_z) / 100 + 5;
            thing->pos_z -= step * kaj_system_vsync_delta[0];
            if (thing->pos_z < -15999) {
                thing->animate = 0;
                thing->active = 0;
                train->motion = 2;
            }
        }
    }
    thing->coord_tx = thing->pos_x - player->cell_x * 12500;
    thing->coord_ty = thing->pos_y + player->cell_y * 32000;
    thing->coord_tz = thing->pos_z - player->cell_z * 12500;
    thing->coord_flg = 0;
}

void vehicle_train_exit_prompt(s16 show) {
    Player *player = player_status_player[0];
    EventState *ev_state = &event_state;
    TrainState *train = &vehicle_train_state;

    if (show != 0) {
        if (train->prompt_on == 0) {
            if ((train->direction != 0 && train->trigger == 0x200010) || (train->direction == 0 && train->trigger == 0x200020)) {
                train->prompt_on = 1;
                ev_state->trigger = train->trigger;
                ev_state->trigger_type = (u8)(train->trigger >> 16);
                if (ev_state->state != 2) {
                    ev_state->state = 2;
                }
                if (!(player->flags & 4)) {
                    player->flags |= 4;
                }
                if (player->vehicle_mode == 2) {
                    /* train prompt: get off */
                    dialog_show(" 7\223d\216\3241\202\251\202\347\215~\202\350\202\351      3\201\233", 1, -1, 8, -1, 0, 1);
                } else if (player->vehicle_mode == 3) {
                    /* subway prompt: get off */
                    dialog_show(" 7\222n\211\272\223S1\202\251\202\347\215~\202\350\202\351     3\201\233", 1, -1, 8, -1, 0, 1);
                }
            }
        }
    } else if (train->prompt_on != 0) {
        dialog_close();
        action_reset(1);
        train->prompt_on = 0;
        if (player->flags & 4) {
            player->flags &= ~4;
        }
    }
}

s16 vehicle_train_get_off(s16 result) {
    TrainState *train;
    u16 mode = player_status_player[0]->vehicle_mode;

    train = &vehicle_train_state;

    if (mode == 3) {
        result = 0;
        if (train->direction != 0) {
            main_goto_building(1, vehicle_str_sb1, 9, 0x41, 1, 0x5A, 6, train->station + 0xF90000, 0);
        } else {
            main_goto_building(1, vehicle_str_sb1, 9, 0x41, 2, -0x5A, 6, train->station + 0xF90000, 0);
        }
    } else if (mode == 2) {
        result = 0;
        if (train->direction != 0) {
            main_goto_building(1, vehicle_str_rw1, 9, 0x41, (s16)(train->station * 2 - 1), 0x5A, 0x11, train->station + 0xF60000, 0);
        } else {
            main_goto_building(1, vehicle_str_rw1, 9, 0x41, (s16)(train->station * 2), -0x5A, 0x11, train->station + 0xF60000, 0);
        }
    }
    return result;
}

s16 vehicle_train_end_of_line(s16 result) {
    SceneRequest *request = &main_scene_request;
    TrainState *train;
    u16 mode = player_status_player[0]->vehicle_mode;

    train = &vehicle_train_state;
    if (mode == 3) {
        if (train->direction != 0) {
            if (train->station == 6) {
                main_goto_building(1, vehicle_str_sb1, 9, 0x41, 1, 0x5A, 6, train->station + 0xF90000, 0);
                result = 0;
                request->change = 1;
            }
        } else {
            if (train->station == 1) {
                main_goto_building(1, vehicle_str_sb1, 9, 0x41, 2, -0x5A, 6, train->station + 0xF90000, 0);
                result = 0;
                request->change = 1;
            }
        }
    } else if (mode == 2) {
        if (train->direction != 0) {
            if (train->station == 3) {
                main_goto_building(1, vehicle_str_rw1, 9, 0x41, 5, 0x5A, 0x11, train->station + 0xF60000, 0);
                result = 0;
                request->change = 1;
            }
        } else {
            if (train->station == 1) {
                main_goto_building(1, vehicle_str_rw1, 9, 0x41, 2, -0x5A, 0x11, train->station + 0xF60000, 0);
                result = 0;
                request->change = 1;
            }
        }
    }
    return result;
}

void vehicle_car_follow_player(Thing *car, s32 force) {
    SVector sv;
    s32 y;
    s16 found = 0;
    s16 f = force;
    PlayerStatus *status = &player_status;
    Player *player = status->player;

    if (player->car_y == 9999) {
        y = 0;
        if (block_find_surface(player->car_x - player->cell_x * 12500, player->car_z - player->cell_z * 12500, &y, 1) != 0) {
            found = 1;
            y -= player->cell_y * 32000;
            player->car_y = y;
        }
    }
    if (found || f != 0) {
        car->pos_x = player->car_x;
        car->pos_y = player->car_y;
        car->pos_z = player->car_z;
        car->rot_x = player->car_rot_x;
        car->rot_y = player->car_rot_y;
        car->rot_z = player->car_rot_z;
        car->coord_tx = car->pos_x - player->cell_x * 12500;
        car->coord_ty = car->pos_y + player->cell_y * 32000;
        car->coord_tz = car->pos_z - player->cell_z * 12500;
        sv.vx = (car->rot_x << 12) / 360;
        sv.vy = (car->rot_y << 12) / 360;
        sv.vz = (car->rot_z << 12) / 360;
        RotMatrixZXY(&sv, car->coord_m);
        car->coord_flg = 0;
        if (f != 0) {
            car->active = 1;
            car->block = block_find_at(car->pos_x, car->pos_y, car->pos_z);
            status->vehicle = (VehicleSprite *)car;
        }
    }
}

static void vehicle_navi_update(Vehicle *car, Player *player) {
    CarNavi *navi = (CarNavi *)vehicle_navi;
    s32 dx;
    s32 dz;
    s32 dist;
    s16 dest_angle;
    s32 arrow;

    if (menu_get_state() == 0 && navi->active != 0 && navi->dest_sprite != NULL && navi->arrow_sprite != NULL) {
        dx = vehicle_navi_dest_xz[navi->dest * 2] - player->world_x;
        dz = vehicle_navi_dest_xz[navi->dest * 2 + 1] - player->world_z;
        dist = SquareRoot0(dx * dx + dz * dz);
        if (dist < 25) {
            if (vehicle_navi_blink != 0) {
                sprite_set_clut_entry(4, 0xE, 0x14F);
            } else {
                sprite_set_clut_entry(4, 0xE, 0);
            }
            vehicle_navi_blink = 1 - vehicle_navi_blink;
        } else if (vehicle_navi_blink != 0) {
            sprite_set_clut_entry(4, 0xE, 0x14F);
        }
        if (dist >= navi->start_dist) {
            dist = 12;
        } else {
            dist = ((u32)(dist * 0xB000) / navi->start_dist + 1) >> 12;
        }
        sprite_fill_clut(4, 1, 12, 0);
        sprite_fill_clut(4, 1, dist, 0x1F);
        dest_angle = main_wrap_angle(ratan2(dx, dz) * 0x1680 >> 16);
        arrow = (main_wrap_angle(dest_angle - main_wrap_angle(car->rot_y)) + 23) / 45;
        if (arrow >= 8) {
            arrow = 0;
        }
        navi->arrow_sprite->cell_col = arrow % 4;
        navi->arrow_sprite->cell_row = arrow / 4;
    }
}

static void vehicle_navi_open_menu(void) {
    CarNavi *navi = (CarNavi *)vehicle_navi;

    sound_se_play(0x13);
    if (navi->arrow_sprite != NULL) {
        navi->arrow_sprite->visible = 0;
        navi->arrow_sprite = NULL;
    }
    if (navi->dest_sprite != NULL) {
        navi->dest_sprite->visible = 0;
        navi->dest_sprite = NULL;
    }
    menu_open(navi->menu_reset, 0x40B, 0x40C, 0xF, 6, NULL, 4, 0x2969, 0x2BFF);
    if (navi->menu_reset != 0) {
        navi->menu_reset = 0;
    }
}

static s16 vehicle_car_stopped_input(void) {
    RoadMap *roadmap = &roadmap_state;
    CarNavi *navi = (CarNavi *)vehicle_navi;
    s16 menu_state = menu_get_state();

    if (menu_state == 1) {
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            vehicle_navi[0] = 1;
            sound_se_play(0x11);
            menu_close();
        } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            vehicle_navi[0] = 0;
            sound_se_play(8);
            menu_close();
        } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
            navi->dest = menu_move(1);
        } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
            navi->dest = menu_move(0);
        }
        return 0;
    }
    if (menu_state == 0) {
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            sound_se_play(0x11);
            return 1;
        }
        if (roadmap->mode == 0 && !(kaj_system.pad_prev & 0x800) && (kaj_system.pad_now & 0x800)) {
            dialog_close();
            vehicle_navi_open_menu();
        }
        return -1;
    }
    return 0;
}

s16 vehicle_car_input(PlayerStatus *status, s32 pad) {
    CarState *state = &vehicle_car_state;
    Player *player = status->player;
    s16 result;
    s16 steer_plus;
    s16 steer_minus;
    s16 brake_held;
    s16 throttle_held;

    if (vehicle_car_state.stopped != 0) {
        if ((s16)player_update_map(status) != 0) {
            return 0;
        }
        result = vehicle_car_stopped_input();
        if (result >= 0) {
            return result;
        }
    }
    steer_plus = 0;
    steer_minus = 0;
    throttle_held = 0;
    brake_held = 0;
    if (pad & 0x1000) {
        if (state->look_pitch < 20) {
            player->view_dirty = 1;
            state->look_pitch += kaj_system_vsync_delta[0];
            if (state->look_pitch > 20) {
                state->look_pitch = 20;
            }
        }
    } else if (pad & 0x4000) {
        if (state->look_pitch > -20) {
            player->view_dirty = 1;
            state->look_pitch -= kaj_system_vsync_delta[0];
            if (state->look_pitch < -20) {
                state->look_pitch = -20;
            }
        }
    } else if (pad & 0x8000) {
        if (state->look_yaw > -65) {
            player->view_dirty = 1;
            state->look_yaw -= kaj_system_vsync_delta[0];
            if (state->look_yaw < -65) {
                state->look_yaw = -65;
            }
        }
    } else if (pad & 0x2000) {
        if (state->look_yaw < 65) {
            player->view_dirty = 1;
            state->look_yaw += kaj_system_vsync_delta[0];
            if (state->look_yaw > 65) {
                state->look_yaw = 65;
            }
        }
    }
    if (pad & 4) {
        steer_minus = 1;
    } else if (pad & 8) {
        steer_plus = 1;
    }
    if (pad & 0x10) {
        brake_held = 1;
        if (state->speed == 0 && state->gear != 1) {
            state->gear = 1;
            state->brake = 0;
            state->throttle = 0;
        }
    } else if (pad & 0x40) {
        throttle_held = 1;
        if (state->speed == 0 && state->gear != -1) {
            state->gear = -1;
            state->brake = 0;
            state->throttle = 0;
        }
    }
    if (steer_minus) {
        if (state->steer > -45) {
            state->steer -= kaj_system_vsync_delta[0];
            if (state->steer < -45) {
                state->steer = -45;
            }
        }
    } else if (!steer_plus && state->speed != 0 && state->steer < 0) {
        state->steer += kaj_system_vsync_delta[0];
        if (state->steer > 0) {
            state->steer = 0;
        }
    }
    if (steer_plus) {
        if (state->steer < 45) {
            state->steer += kaj_system_vsync_delta[0];
            if (state->steer > 45) {
                state->steer = 45;
            }
        }
    } else if (!steer_minus && state->speed != 0 && state->steer > 0) {
        state->steer -= kaj_system_vsync_delta[0];
        if (state->steer < 0) {
            state->steer = 0;
        }
    }
    if (brake_held) {
        if (state->brake < 256) {
            state->brake += kaj_system_vsync_delta[0];
            if (state->brake > 256) {
                state->brake = 256;
            }
        }
    } else if (state->brake > 0) {
        state->brake -= kaj_system_vsync_delta[0];
        if (state->brake < 0) {
            state->brake = 0;
        }
    }
    if (throttle_held) {
        if (state->throttle < 256) {
            state->throttle += kaj_system_vsync_delta[0];
            if (state->throttle > 256) {
                state->throttle = 256;
            }
        }
    } else if (state->throttle > 0) {
        state->throttle -= kaj_system_vsync_delta[0];
        if (state->throttle < 0) {
            state->throttle = 0;
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

void vehicle_create(Vehicle **out, u32 size) {
    *out = kaj_malloc(0xC4);
    if (*out == NULL) {
        kaj_abend(3, vehicle_str_alloc_pointer, vehicle_str_file, 0x64);
    }
    (*out)->model0 = NULL;
    (*out)->model1 = NULL;
    (*out)->data = NULL;
    (*out)->data = kaj_malloc(size);
    if ((*out)->data == NULL) {
        kaj_abend(3, vehicle_str_alloc_buffer, vehicle_str_file, 0x6C);
    }
}

void vehicle_init(Vehicle *car) {
    switch (player_status_player[0]->vehicle_mode) {
    case 1:
        vehicle_car_init(car, player_status_player[0]);
        break;
    case 2:
    case 3:
        vehicle_train_init(car, player_status_player[0]);
        break;
    }
    object_scene_vehicle[0] = car;
}

void vehicle_free(void) {
    SceneTables *tables = &object_scene_tables;
    Vehicle *vehicle = tables->vehicle;
    if (vehicle != NULL) {
        if (vehicle->kind == 1) {
            vehicle_car_get_out(vehicle);
        }
        free3(vehicle->model0);
        if (vehicle->model1 != NULL) {
            free3(vehicle->model1);
        }
        free3(vehicle->data);
        free3(vehicle);
        tables->vehicle = NULL;
        sound_se_pop();
    }
}

void vehicle_draw(ViewBuffer *view) {
    s32 ls[8];
    Vehicle *car;
    ScreenLight *light = &roadmap_screen_light;
    s16 dusk_cleared;

    car = object_scene_vehicle[0];
    if (car == NULL) {
        return;
    }
    dusk_cleared = 0;
    if (car->kind == 2 && (roadmap_draw_flags & 1)) {
        roadmap_draw_flags -= 1;
        dusk_cleared = 1;
    }
    GsGetLs(&car->coord, ls);
    GsSetLsMatrix(ls);
    light->ot_bias = (car->ot_layer + 1) << 6;
    SetSpadStack(0x1F8003FC);
    GsSortObject4J(car->model0, &view->ot_length, 1, (void *)0x1F800000);
    ResetSpadStack();
    if (car->kind == 1) {
        GsGetLs(&car->coord2, ls);
        GsSetLsMatrix(ls);
        SetSpadStack(0x1F8003FC);
        GsSortObject4J(car->model1, &view->ot_length, 1, (void *)0x1F800000);
        ResetSpadStack();
    }
    if (dusk_cleared) {
        roadmap_draw_flags += 1;
    }
}

void vehicle_set_origin(s32 origin_x, s32 origin_y, s32 origin_z) {
    Vehicle *car = object_scene_vehicle[0];
    if (car != NULL) {
        car->coord.flg = 0;
        car->coord.coord_tx = car->pos_x - origin_x;
        car->coord.coord_ty = car->pos_y - origin_y;
        car->coord.coord_tz = car->pos_z - origin_z;
    }
}

void vehicle_update(void) {
    s32 mode = player_status_player[0]->vehicle_mode;
    if (mode == 1) {
        vehicle_car_drive(player_status_player[0]);
    } else if (mode >= 2) {
        if (mode < 4) {
            vehicle_train_drive(player_status_player[0]);
        }
    }
}

void vehicle_car_place(void) {
    Thing *car = thing_find(0, 0);
    if (car == NULL) {
        kaj_abend(5, "My Car Object not Found", vehicle_str_file, 0x421);
    }
    vehicle_car_follow_player(car, 1);
}

void vehicle_car_release(void) {
    PlayerStatus *status = &player_status;
    status->vehicle->visible = 0;
    status->vehicle = NULL;
}

void vehicle_navi_show(Player *player, s16 show, s16 reset_dist) {
    CarNavi *navi = (CarNavi *)vehicle_navi;
    s32 dx;
    s32 dz;

    if (show != 0) {
        navi->dest_sprite = sprite_find(4);
        navi->arrow_sprite = sprite_find(0x406);
        if (navi->arrow_sprite != NULL) {
            navi->arrow_sprite->x = 0x90;
            navi->arrow_sprite->y = 0x68;
            navi->arrow_sprite->visible = 1;
        }
        if (navi->dest_sprite != NULL) {
            navi->dest_sprite->visible = 1;
            navi->dest_sprite->cell_col = 0;
            navi->dest_sprite->cell_row = navi->dest;
        }
        dx = vehicle_navi_dest_xz[navi->dest * 2] - player->world_x;
        dz = vehicle_navi_dest_xz[navi->dest * 2 + 1] - player->world_z;
        if (reset_dist != 0) {
            navi->start_dist = SquareRoot0(dx * dx + dz * dz);
        }
    } else {
        if (navi->arrow_sprite != NULL) {
            navi->arrow_sprite->visible = 0;
            navi->arrow_sprite = NULL;
        }
        if (navi->dest_sprite != NULL) {
            navi->dest_sprite->visible = 0;
            navi->dest_sprite = NULL;
        }
    }
}

void vehicle_navi_set_enabled(s16 enabled) {
    vehicle_navi[0] = enabled;
    if (enabled != 0) {
        sound_se_play(0x11);
    } else {
        sound_se_play(8);
    }
    menu_close();
}

void vehicle_train_set_doors(s16 opening) {
    TrainState *train = &vehicle_train_state;
    VehicleSprite *sprite;
    TssSlot *task;
    s32 frames;

    sprite = sprite_find(0x408);
    if (sprite == NULL) {
        if (opening != 0) {
            train->door_state = 1;
        } else {
            train->door_state = 0;
            train->motion = 1;
            thing_set_animate(2, 0, 1);
        }
        return;
    }
    task = kaj_tss_alloc(4);
    task->type = 7;
    if (opening != 0) {
        task->cur = 0;
        frames = sprite->columns * sprite->rows;
        task->step = 1;
        task->target = frames - 1;
        train->door_state = 3;
    } else {
        frames = sprite->columns * sprite->rows;
        task->target = 0;
        task->step = -1;
        task->cur = frames - 1;
        train->door_state = 2;
    }
    task->delay = 0x19;
    task->on_step = vehicle_train_door_frame;
    task->on_end = vehicle_train_door_last;
    task->on_kill = vehicle_train_door_last;
    *(VehicleSprite **)task->data = sprite;
    train->door_task = kaj_tss_start(task);
    sound_se_play(0xB);
}

void vehicle_train_hide(void) {
    TrainState *train = &vehicle_train_state;
    Thing *thing = thing_find(2, 0);
    if (thing != NULL) {
        thing->animate = 0;
        thing->active = 0;
    }
    train->stop_timer = -1;
}

static void vehicle_train_door_frame(TssSlot *task) {
    Rect rect;
    VehicleSprite *sprite;
    s32 frame;
    TimHandle *tim;
    s32 w;
    s32 h;
    s16 x;
    s16 y;
    sprite = *(VehicleSprite **)task->data;
    tim = sprite->tim;
    w = sprite->cell_w >> tim->pixel_shift;
    h = sprite->cell_h;
    frame = task->cur;
    x = tim->x + w * (frame / 4);
    y = tim->y + h * (frame % 4);
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    MoveImage(&rect, 0x2F0, 0x20);
}

static void vehicle_train_door_last(TssSlot *task) {
    TrainState *train = &vehicle_train_state;
    Rect rect;
    VehicleSprite *sprite = *(VehicleSprite **)task->data;
    s32 frame = task->cur;
    TimHandle *tim = sprite->tim;
    s32 w = sprite->cell_w >> tim->pixel_shift;
    s32 h = sprite->cell_h;
    s16 x = tim->x + w * (frame / 4);
    s16 y = tim->y + h * (frame % 4);
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    MoveImage(&rect, 0x2F0, 0x20);
    train->door_task = -1;
}

void vehicle_train_init_state(void) {
    TrainState *train = &vehicle_train_state;
    train->arrive_digit_dir1 = 2;
    train->arrive_digit_dir0 = 7;
}
