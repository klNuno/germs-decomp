#ifndef GAME_ACTOR_H
#define GAME_ACTOR_H

#include "common.h"
#include "game/types.h"

/* Functions of src/game/actor.c that other files call or a table names. */
void npc_update_all(void);
void npc_exec_command(Action *action);
void npc_apply_damage(Npc *npc, s32 weapon_class, s32 damage, s16 miss);
void npc_free_all(void);
Npc *npc_find(s16 by_model, u16 id);
void npc_draw_all(s32 view);
s16 npc_find_at_point(s16 skip_id, s32 x, s32 y, s32 z);
void npc_update_blocks(void);
void npc_rebase_all(s32 x, s32 y, s32 z);
u16 npc_get_radius(Npc *npc);
void npc_free_bodies(void);
NpcBody *npc_find_body(s16 id);
void npc_free_stats(void);
NpcStats *npc_find_stats(s16 id);

#endif
