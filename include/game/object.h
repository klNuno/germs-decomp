#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "common.h"
#include "game/types.h"

/* Functions of src/game/object.c that other files call or a table names. */
void object_load_scene(void);
void object_load_weapon_mods(void);
void object_load_mail_by_id(s16 list_index);
void object_load_res(s32 index, s32 progress);
void object_load_res12_by_id(s16 id);
void object_room_run(void);

#endif
