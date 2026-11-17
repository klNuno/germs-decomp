#ifndef GAME_MAIN_H
#define GAME_MAIN_H

#include "common.h"
#include "game/types.h"

/* Functions of src/game/main.c that other files call or a table names. */
void mail_wait(s32 mode, s32 stream, s32 visibility, s32 seconds);
void mail_step_frame(u16 mode, s16 b, s16 c);
void mail_goto_ofc(s16 a, s16 yaw, s16 c, s16 d);
void mail_goto_twn(s32 x, s32 y, s32 z, s16 yaw, s16 e);
s16 mail_wrap_angle(s16 angle);
s32 mail_angle_to_dir4(s16 angle);
s32 mail_exp_for_level(s32 level);

/* Declared in the calling files, each with the argument and return widths its code needs:
   mail_angle_to_dir8, mail_goto_building, mail_take_scene_change. */

#endif
