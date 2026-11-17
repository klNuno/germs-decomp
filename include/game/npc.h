#ifndef GAME_NPC_H
#define GAME_NPC_H

#include "common.h"
#include "game/types.h"

/* Functions of src/game/npc.c that other files call or a table names. */
void mod_cmd_npcrec(Action *action, EventState *event);
void mod_npcrec_update_all(void);
void mod_npcrec_show(u16 id, s16 force);
NpcRecord *mod_npcrec_find(u16 id);
void mod_npcrec_rebase_all(s32 origin_x, s32 origin_y, s32 origin_z);
void mod_npcrec_draw_all(s32 view);
s16 mod_npcrec_find_at_point(s32 x, s32 y, s32 z);
void mod_npcrec_reset_all(void);

#endif
