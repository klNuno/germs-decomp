#ifndef GAME_DIALOG_H
#define GAME_DIALOG_H

#include "common.h"
#include "game/types.h"

typedef struct TextCmd {
    u16 opcode;
    u16 state;
} TextCmd;

/* Functions of src/game/dialog.c that other files call or a table names. */
void menu_run(void);
void text_exec_command(Action *action);
void text_start_narration(s32 str);
void text_close(void);
void text_next_page(EventState *event);
void text_release_cmd(void);
void text_narration_cues(s16 ending);

/* Declared in the calling files, each with the argument and return widths its code needs:
   text_show, text_show_profile, text_show_timed. */

#endif
