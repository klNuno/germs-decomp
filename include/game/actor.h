#ifndef GAME_ACTOR_H
#define GAME_ACTOR_H

#include "common.h"
#include "game/types.h"

/* Functions of src/game/actor.c that other files call or a table names. */
void actor_update_all(void);
void actor_exec_command(Action *action);
void actor_apply_damage(Npc *npc, s32 weapon_class, s32 damage, s16 miss);
void actor_free_all(void);
Npc *actor_find(s16 by_model, u16 id);
void actor_draw_all(s32 view);
s16 actor_find_at_point(s16 skip_id, s32 x, s32 y, s32 z);
void actor_update_blocks(void);
void actor_rebase_all(s32 x, s32 y, s32 z);
u16 actor_get_radius(Npc *npc);
void actor_free_bodies(void);
NpcBody *actor_find_body(s16 id);
void actor_free_stats(void);
NpcStats *actor_find_stats(s16 id);

#endif
