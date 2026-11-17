#ifndef GAME_VEHICLE_H
#define GAME_VEHICLE_H

#include "common.h"
#include "game/types.h"
#include "game/thing.h"
#include "kaj/view.h"
#include "psyq/libgte.h"

typedef struct TrainState {
    s32 door_task;
    s32 trigger;
    s16 direction;
    s16 placed;
    s16 prompt_on;
    u16 door_state;
    u16 station;
    u16 motion;
    s16 speed;
    s16 stop_timer;
    s16 arrive_digit_dir1;
    s16 arrive_digit_dir0;
    s32 mark_start;
    s32 mark_cruise;
    s32 mark_brake;
    s32 mark_stop;
    s16 carry_vx;
    s16 carry_vy;
    s16 carry_vz;
    u8 unk32[0x2];
    s16 view_pitch;
    s16 view_yaw;
    s16 view_roll;
} TrainState;

typedef struct CarState {
    s16 stopped;
    s16 slowed;
    s16 steer;
    s16 gear;
    s32 brake;
    s32 throttle;
    s32 speed;
    s32 turn_yaw;
    s32 turn_radius;
    SVector seat;
    s16 look_pitch;
    s16 look_yaw;
    s16 look_roll;
    u8 unk2A[0x2];
    SVector corners[4];
    s32 axle_x;
    s32 axle_y;
    s32 axle_z;
    u8 unk58[0x4];
    s32 pivot_x;
    s32 pivot_y;
    s32 pivot_z;
} CarState;

typedef struct CarNavi {
    s16 active;
    s16 menu_reset;
    s16 dest;
    u8 unk6[0x2];
    u32 start_dist;
    VehicleSprite *dest_sprite;
    VehicleSprite *arrow_sprite;
} CarNavi;

/* Functions of src/game/vehicle.c that other files call or a table names. */
void vehicle_train_place(void);
void vehicle_train_arrive(s16 direction, s16 station);
void vehicle_train_update(Thing *thing);
void vehicle_train_exit_prompt(s16 show);
s16 vehicle_train_get_off(s16 result);
s16 vehicle_train_end_of_line(s16 result);
void vehicle_car_follow_player(Thing *car, s32 force);
s16 vehicle_car_input(PlayerStatus *status, s32 pad);
void vehicle_load_data(void);
void vehicle_create(Vehicle **out, u32 size);
void vehicle_init(Vehicle *car);
void vehicle_free(void);
void vehicle_draw(ViewBuffer *view);
void vehicle_set_origin(s32 origin_x, s32 origin_y, s32 origin_z);
void vehicle_update(void);
void vehicle_car_place(void);
void vehicle_car_release(void);
void vehicle_navi_show(Player *player, s16 show, s16 reset_dist);
void vehicle_train_set_doors(s16 opening);
void vehicle_train_init_state(void);

#endif
