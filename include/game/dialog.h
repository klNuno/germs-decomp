#ifndef GAME_DIALOG_H
#define GAME_DIALOG_H

#include "common.h"
#include "game/types.h"

typedef struct TextCmd {
    u16 opcode;
    u16 state;
} TextCmd;

/* Functions of src/game/dialog.c that other files call or a table names. */
void dialog_menu_run(void);
void dialog_exec_command(Action *action);
void dialog_start_narration(s32 str);
void dialog_close(void);
void dialog_next_page(EventState *event);
void dialog_release_cmd(void);
void dialog_narration_cues(s16 ending);

/* Declared in the calling files, each with the argument and return widths its code needs:
   dialog_show, dialog_show_profile, dialog_show_timed. */

#endif
