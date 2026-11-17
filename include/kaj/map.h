#ifndef KAJ_MAP_H
#define KAJ_MAP_H

#include "common.h"
#include "game/types.h"

/* Functions of src/kaj/map.c that other files call or a table names. */
s32 kaj_map_update_city(s32 x, s32 y);
s32 kaj_map_update_place(s32 area, u8 *entry);
void kaj_map_cell_slots(s16 *count, s32 *handles);
void kaj_map_cell_loaded_slots(s16 *count, s32 *handles);
s32 kaj_map_open_city(void);
s32 kaj_map_open_place(s32 letter, char *place_name);
void kaj_map_get_entry(s32 area, s32 *pos, u8 *entry);
void kaj_map_set_cell_ready(void);
void kaj_map_set_room_ready(void);
s32 kaj_map_place_ready(void);
void kaj_map_room_slots(s16 *count, s32 *handles);
void kaj_map_room_loaded_slots(s16 *count, s32 *handles);
void kaj_map_room_release(s32 handle);

/* Declared in the calling files, each with the argument and return widths its code needs:
   kaj_map_city_ready, kaj_map_load_city_dir, kaj_map_load_place_dir. */

#endif
