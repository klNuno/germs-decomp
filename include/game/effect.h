#ifndef GAME_EFFECT_H
#define GAME_EFFECT_H

#include "common.h"
#include "game/types.h"

typedef struct ItemRecord {
    u16 id;
    u16 kind;
    char name[0x22];
    s16 value;
} ItemRecord;

/* Functions of src/game/effect.c that other files call or a table names. */
void effect_start_sprite_slide(s32 kind, u16 sprite_id, s32 seconds);
void effect_flame_small_update(void);
void effect_flame_large_update(void);
void effect_start_fade(s32 kind, s32 seconds);
void effect_fade_set_black(void);
void effect_start_sprite_anim(u16 sprite_id, s32 seconds);
void effect_clear_alarms(void);
void effect_start_alarm(s32 slot, s32 code, s32 delay);
void effect_flame_small_init(s16 kind);
void effect_flame_small_free(void);
void effect_clut_cycle_update(void);
void effect_clut_cycle_init(void);
void effect_flame_large_init(void);
void effect_flame_large_free(void);
void effect_clut_rotate(void);
void effect_elevator_run(void);
void effect_elevator_init(s16 floor);
s32 effect_weapon_unequip(s16 weapon_id);
void effect_weapon_calc_rate(s32 slot);
void effect_weapon_swap_stock(s16 to_stock, s16 weapon_id);
s16 effect_item_use(PlayerStatus *status, s16 b, s16 item_id, s16 full, s16 close_text);
void effect_item_use_selected(void);
s16 effect_item_input(PlayerStatus *status, s16 scene_kind);
void effect_weapon_load_models(void);
void effect_weapon_reset(void);
void effect_weapon_check_fire_frame(s32 frame);
s32 effect_weapon_list(s16 equipped, s16 *count_out, s16 *ids_out);
WeaponRecord *effect_weapon_find(s16 id);
ItemRecord *effect_item_find(s16 id);

/* Declared in the calling files, each with the argument and return widths its code needs:
   effect_inventory_has_room, effect_item_add, effect_item_remove, effect_weapon_add, effect_weapon_input. */

#endif
