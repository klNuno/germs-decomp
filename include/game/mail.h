#ifndef GAME_MAIL_H
#define GAME_MAIL_H

#include "common.h"
#include "game/types.h"

typedef struct {
    s16 img_x;
    s16 img_y;
    u16 img_w;
    u16 img_h;
    u8 unk8[0xA];
    u16 v;
} MailPageTim;

typedef struct {
    s16 id;
    s16 mode;
    s16 visible;
    s16 clut_dirty;
    s32 unk8;
    u16 y;
    s16 depth;
    s16 cell_w;
    u16 cell_h;
    s32 unk14;
    s32 unk18;
    MailPageTim *tim;
} MailPageSprite;

typedef struct MailHandler {
    u16 id;
    s16 list_index;
    s16 page_count;
    s16 scroll;
    u16 *entry_sprite;
    u16 *scrollbar;
    MailPageSprite *page0;
    MailPageSprite *page1;
    MailPageSprite *page2;
    MailPageSprite *page3;
} MailHandler;

typedef struct {
    u16 id;
    u16 page_count;
    s32 page0_offset;
    s32 page1_offset;
    s32 page2_offset;
    s32 page3_offset;
} MailRecord;

/* Functions of src/game/mail.c that other files call or a table names. */
void mail_create(MailHandler **out, MailRecord *rec, s16 list_index);
void mail_scroll(s16 forward);
s32 mail_list_move(s16 up, s16 index);
void mail_list_open(void);
void mail_list_close(void);
void mail_free(void);
s16 mail_list_get_id(s16 i);
void mail_cmd_receive(Action *action);
s32 mail_is_read(s16 id);

/* Declared in the calling files, each with the argument and return widths its code needs:
   mail_check_schedule. */

#endif
