#ifndef GAME_AI_H
#define GAME_AI_H

#include "common.h"
#include "game/types.h"

/* Functions of src/game/ai.c that other files call or a table names. */
void ai_update_stand(Npc *npc);
void ai_update_move(Npc *npc, s16 mode);
void ai_fire(Npc *npc);
s16 ai_in_aim_cone(Npc *npc, s16 npc_aims, s16 weapon_id);

#endif
