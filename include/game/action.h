#ifndef GAME_ACTION_H
#define GAME_ACTION_H

#include "common.h"
#include "game/types.h"

/* View of ActionCmd for the handlers that read the target +4 as u16 (lhu): npc_exec_command, door_exec_command. */
typedef struct ActionCmdShort {
    u16 opcode;
    u16 sub;
    u16 target;
} ActionCmdShort;

/* Functions of src/game/action.c that other files call or a table names. */
void action_cmd_change_scene(Action *action, s32 *event);
void action_update(void);
u8 *action_load_set(u8 *src);
ActionSet *action_run_set(ActionSet *set, s32 at_cursor, s32 skip_text_wait);
void action_reset(s16 flush_all);
void action_push_front(s32 action);
void action_free_all_sets(void);
ActionSet *action_find_set(s16 id);
SceneTrigger *action_find_trigger(s32 id);
void action_free_triggers(void);
void action_place_npc(Npc *npc, Model *model);
void action_init_npcs(void);

/* Declared in the calling files, each with the argument and return widths its code needs:
   action_run_npc_event, action_run_trigger_enter, action_run_trigger_leave. */

#endif
