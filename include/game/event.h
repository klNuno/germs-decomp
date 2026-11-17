#ifndef GAME_EVENT_H
#define GAME_EVENT_H

#include "common.h"
#include "game/types.h"
#include "kaj/event.h"

/* Functions of src/game/event.c that other files call or a table names. */
void event_open(void);
void event_handle_enter(KajEvent *ev);
void event_handle_leave(KajEvent *ev);
s16 event_handle_effect_done(KajEvent *ev);
void event_handle_alarm(s32 *ev);
void event_handle_tick(s16 daylight);
void event_handle_mod_finish(s32 *ev);
void event_draw_limb_status(PlayerStatus *status);
void event_update_hud(PlayerStatus *status);
void event_draw_hud(void);
void event_draw_gauge(PlayerStatus *status);
void event_set_blink(s16 which, s16 on);
void event_show_clock(s16 light_on);
void event_draw_compass(Player *player);
void event_advance_clock(s16 minutes, s16 no_fatigue);

#endif
