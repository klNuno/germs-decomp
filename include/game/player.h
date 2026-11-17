#ifndef GAME_PLAYER_H
#define GAME_PLAYER_H

#include "common.h"
#include "game/types.h"

/* Functions of src/game/player.c that other files call or a table names. */
s32 object_deliver_area_events(void);
void player_set_view(Player *player, s16 keep_cell);
void player_init(void);
void player_place_for_scene(u16 entry);
void player_update(u16 mode, s16 stream, s16 visibility);
void player_add_skill_exp(s16 skill, s16 exp);
void player_add_exp(s32 exp);
void player_pick_target(void);
void player_shoot_target(void);
void player_start_move_to(s16 flag_op, u16 flag_bits, s32 x, s32 y, s32 z, s16 pitch, s16 yaw, s16 roll, s32 seconds);
void player_exec_command(Action *action, EventState *event);
void player_recover(s32 x, s32 y, s32 z, s16 wake);
void player_handle_pad(PlayerStatus *status, s32 mode, s32 buttons);
void player_weapon_sound(s16 kind, s16 start);
void player_reset_triggers(s16 reground);
void player_heal_part(s16 part, s16 cap_kind, s16 amount);
void player_add_hp(s16 amount, s16 floor);
void player_rest(s16 sleep, s32 x, s32 y, s32 z);
s32 player_is_injured(void);
s32 player_leave_trigger(void);
s32 player_update_map(PlayerStatus *status);

/* Declared in the calling files, each with the argument and return widths its code needs:
   player_set_item, player_set_weapon, player_take_hit. */

#endif
