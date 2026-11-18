#ifndef GAME_NPC_H
#define GAME_NPC_H

#include "common.h"
#include "game/types.h"

/* Functions of src/game/npc.c that other files call or a table names. */
void npc_rec_cmd(Action *action, EventState *event);
void npc_rec_update_all(void);
void npc_rec_show(u16 id, s16 force);
NpcRecord *npc_rec_find(u16 id);
void npc_rec_rebase_all(s32 origin_x, s32 origin_y, s32 origin_z);
void npc_rec_draw_all(s32 view);
s16 npc_rec_find_at_point(s32 x, s32 y, s32 z);
void npc_rec_reset_all(void);

#endif
