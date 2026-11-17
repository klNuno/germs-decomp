#include "common.h"
#include "game/mail.h"
#include "game/action.h"
#include "game/sound.h"
#include "game/sprite.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "psyq/libapi.h"

/*
 * The mail list and the mail pages.
 *
 * File boundaries: guess (docs/layout.md): mail.c asserts; its end is a guess.
 */

typedef struct { s16 id, code, read, unk6; } MailListEntry;
MailListEntry *mail_list;
static void mail_receive(u16 id);
extern GameVars action_vars;
u16 *mail_scrollbar;
s16 mail_list_top;
s16 mail_list_row;
extern char mail_str_file[];
static void mail_list_refresh(GameVars *game, s16 selected);
typedef struct MailHandlerView { u16 id; s16 list_index; s32 unk4; Sprite *entry_sprite; Sprite *scrollbar; } MailHandlerView;
extern SceneTables object_scene_tables;
u16 mail_entry_saved_y;
u16 mail_scrollbar_saved_y;
extern MailHandler *object_scene_mail[];
s16 mail_page_tex_v_0;
s16 mail_page_tex_v_1;
s16 mail_page_tex_v_2;
s16 mail_page_tex_v_3;
s16 mail_page_height_0;
s16 mail_page_height_1;
s16 mail_page_height_2;
s16 mail_page_height_3;

void mail_create(MailHandler **out, MailRecord *rec, s16 list_index) {
    *out = kaj_malloc(0x20);
    if (*out == NULL) {
        kaj_abend(3, "Error Allocating MAIL Handler", mail_str_file, 0x3B);
    }
    (*out)->id = rec->id;
    (*out)->list_index = list_index;
    (*out)->page_count = rec->page_count;
    (*out)->scroll = 0;

    sprite_create(&(*out)->page0, (u8 *)rec + rec->page0_offset);
    sprite_add((s32)(*out)->page0);
    (*out)->page0->visible = 1;
    (*out)->page0->y = 0x43;
    (*out)->page0->depth = 1;
    mail_page_tex_v_0 = (*out)->page0->tim->v;
    mail_page_height_0 = (*out)->page0->cell_h;

    if ((*out)->page_count >= 2) {
        sprite_create(&(*out)->page1, (u8 *)rec + rec->page1_offset);
        sprite_add((s32)(*out)->page1);
        (*out)->page1->visible = 0;
        (*out)->page1->y = 0x43;
        (*out)->page1->depth = 1;
        mail_page_tex_v_1 = (*out)->page1->tim->v;
        mail_page_height_1 = (*out)->page1->cell_h;
    }
    if ((*out)->page_count >= 3) {
        sprite_create(&(*out)->page2, (u8 *)rec + rec->page2_offset);
        sprite_add((s32)(*out)->page2);
        (*out)->page2->visible = 0;
        (*out)->page2->y = 0x43;
        (*out)->page2->depth = 1;
        mail_page_tex_v_2 = (*out)->page2->tim->v;
        mail_page_height_2 = (*out)->page2->cell_h;
    }
    if ((*out)->page_count >= 4) {
        sprite_create(&(*out)->page3, (u8 *)rec + rec->page3_offset);
        sprite_add((s32)(*out)->page3);
        (*out)->page3->visible = 0;
        (*out)->page3->y = 0x43;
        (*out)->page3->depth = 1;
        mail_page_tex_v_3 = (*out)->page3->tim->v;
        mail_page_height_3 = (*out)->page3->cell_h;
    }

    (*out)->entry_sprite = sprite_find((*out)->id + 0x217);
    if ((*out)->entry_sprite != NULL) {
        sprite_set_clut_entry((u16)((*out)->id + 0x217), 7, 0x4D44);
        sprite_set_clut_entry((u16)((*out)->id + 0x217), 9, 0x6358);
        mail_entry_saved_y = (*out)->entry_sprite[6];
        (*out)->entry_sprite[6] = 0x33;
        (*out)->entry_sprite[7] = 1;
    }
    (*out)->scrollbar = sprite_find(0x20C);
    if (mail_scrollbar != NULL) {
        mail_scrollbar_saved_y = mail_scrollbar[6];
    }
    if ((*out)->scrollbar != NULL) {
        (*out)->scrollbar[6] = 0x29;
    }
}

void mail_scroll(s16 forward) {
    MailHandler *mail = object_scene_mail[0];
    s32 offset;
    s32 last_page;
    s32 max;

    if (mail == NULL || mail->page_count < 2) {
        return;
    }
    offset = mail->scroll;
    if (forward != 0) {
        offset++;
    } else {
        offset--;
    }
    last_page = mail->page_count - 1;
    max = last_page << 7;
    if (max < offset) {
        offset = max;
    }
    if (offset < 0) {
        offset = 0;
    }
    if (mail->scrollbar != NULL) {
        mail->scrollbar[6] = ((offset * 114 / last_page) >> 7) + 41;
    }
    if (offset == 0) {
        mail->page0->visible = 1;
        mail->page0->y = 0x43;
        mail->page0->cell_h = mail_page_height_0;
        mail->page0->tim->v = mail_page_tex_v_0;
        mail->page1->visible = 0;
        if (mail->page2 != NULL) {
            mail->page2->visible = 0;
        }
        if (mail->page3 != NULL) {
            mail->page3->visible = 0;
        }
    } else if (offset > 0 && offset < 128) {
        mail->page0->visible = 1;
        mail->page0->cell_h = mail_page_height_0 - offset;
        mail->page0->tim->v = mail_page_tex_v_0 + offset;
        mail->page1->visible = 1;
        mail->page1->y = mail->page0->y + mail->page0->cell_h - 1;
        mail->page1->cell_h = offset;
        if (mail->page2 != NULL) {
            mail->page2->visible = 0;
        }
        if (mail->page3 != NULL) {
            mail->page3->visible = 0;
        }
    } else if (offset == 128) {
        mail->page0->visible = 0;
        mail->page1->visible = 1;
        mail->page1->y = 0x43;
        mail->page1->cell_h = mail_page_height_1;
        mail->page1->tim->v = mail_page_tex_v_1;
        if (mail->page2 != NULL) {
            mail->page2->visible = 0;
        }
        if (mail->page3 != NULL) {
            mail->page3->visible = 0;
        }
    } else if (offset > 128 && offset < 256) {
        mail->page0->visible = 0;
        mail->page1->visible = 1;
        mail->page1->cell_h = mail_page_height_1 + 128 - offset;
        mail->page1->tim->v = mail_page_tex_v_1 - 128 + offset;
        mail->page2->visible = 1;
        mail->page2->y = mail->page1->y + mail->page1->cell_h - 1;
        mail->page2->cell_h = offset - 128;
        if (mail->page3 != NULL) {
            mail->page3->visible = 0;
        }
    } else if (offset == 256) {
        mail->page0->visible = 0;
        mail->page1->visible = 0;
        mail->page2->visible = 1;
        mail->page2->y = 0x43;
        mail->page2->cell_h = mail_page_height_2;
        mail->page2->tim->v = mail_page_tex_v_2;
    } else if (offset > 256 && offset < 384) {
        mail->page0->visible = 0;
        mail->page1->visible = 0;
        mail->page2->visible = 1;
        mail->page2->cell_h = mail_page_height_2 + 256 - offset;
        mail->page2->tim->v = mail_page_tex_v_2 - 256 + offset;
        mail->page3->visible = 1;
        mail->page3->y = mail->page2->y + mail->page2->cell_h - 1;
        mail->page3->cell_h = offset - 256;
    } else if (offset == 384) {
        mail->page0->visible = 0;
        mail->page1->visible = 0;
        mail->page2->visible = 0;
        mail->page3->visible = 1;
        mail->page3->y = 0x43;
        mail->page3->cell_h = mail_page_height_3;
        mail->page3->tim->v = mail_page_tex_v_3;
    }
    mail->scroll = offset;
}

static void mail_list_refresh(GameVars *game, s16 selected) {
    s32 i;
    s32 row;
    u16 *sprite;
    MailListEntry *entry;

    row = 0;
    entry = mail_list;
    for (i = 0; i < (s16)game->vars[0x5F]; i++, entry++) {
        sprite = sprite_find(entry->id + 0x217);
        if (sprite != NULL) {
            if (i >= mail_list_top && i < mail_list_top + 9) {
                sprite[2] = 1;
                sprite[5] = 0x30;
                sprite[6] = row * 16 + 0x33;
                row++;
                if (i == selected) {
                    sprite_set_clut_entry((u16)(entry->id + 0x217), 9, 0x1F);
                } else {
                    sprite_set_clut_entry((u16)(entry->id + 0x217), 9, 0x6358);
                }
                if (entry->read != 0) {
                    sprite_set_clut_entry((u16)(entry->id + 0x217), 7, 0x2C1F);
                } else {
                    sprite_set_clut_entry((u16)(entry->id + 0x217), 7, 0x4D44);
                }
            } else {
                sprite[2] = 0;
            }
        }
    }
}

s32 mail_list_move(s16 up, s16 index) {
    GameVars *game = &action_vars;
    if ((s16)game->vars[0x5F] == 0) {
        return -1;
    }
    if (up != 0) {
        index--;
        if (index < 0) {
            return 0;
        }
        mail_list_row--;
        if (mail_list_row < 0) {
            mail_list_row = 0;
            if (mail_list_top > 0) {
                mail_list_top--;
            }
        }
    } else {
        index++;
        if (index >= (s16)game->vars[0x5F]) {
            return (s16)(game->vars[0x5F] - 1);
        }
        mail_list_row++;
        if (mail_list_row >= 9) {
            mail_list_row = 8;
            if (mail_list_top != index - 8) {
                mail_list_top = index - 8;
            }
        }
    }
    mail_list_refresh(game, index);
    if (mail_scrollbar != NULL) {
        mail_scrollbar[6] = index * 114 / ((s16)game->vars[0x5F] - 1) + 0x29;
    }
    sound_se_play(0xF);
    return index;
}

void mail_list_open(void) {
    s32 id;
    s32 word;
    u16 code;
    MailListEntry *entry;
    GameVars *game = &action_vars;
    if ((s16)game->vars[0x5F] != 0) {
        mail_list_row = 0;
        mail_list_top = 0;
        mail_scrollbar = sprite_find(0x20C);
        if (mail_scrollbar != NULL) {
            mail_scrollbar[6] = 0x29;
        }
        mail_list = kaj_malloc((s16)game->vars[0x5F] * 8);
        if (mail_list == NULL) {
            kaj_abend(3, "Error Allocating Mail List", mail_str_file, 0x16A);
        }
        for (id = 0; id < 0x20; id++) {
            word = id / 2 + 0x60;
            if (id & 1) {
                code = (u8)*(game->vars + word);
            } else {
                code = *(game->vars + word) >> 8;
            }
            if (code & 0x80) {
                entry = &mail_list[code & 0x3F];
                entry->id = id;
                entry->code = code;
                entry->read = (code & 0x40) >> 6;
            }
        }
        mail_list_refresh(game, 0);
    }
}

void mail_list_close(void) {
    s32 i;
    s32 word;
    s32 code;
    s32 old;
    MailListEntry *entry;
    GameVars *game = &action_vars;
    if ((s16)game->vars[0x5F] != 0) {
        if (mail_scrollbar != NULL) {
            mail_scrollbar[6] = 0x29;
            mail_scrollbar = NULL;
        }
        entry = mail_list;
        for (i = 0; i < (s16)game->vars[0x5F]; i++, entry++) {
            code = 0x80;
            if (entry->read != 0) {
                code = 0xC0;
            }
            code += i & 0x3F;
            word = entry->id / 2 + 0x60;
            if (entry->id % 2) {
                old = *(game->vars + word);
                *(game->vars + word) = code | (old & ~0xFF);
            } else {
                *(game->vars + word) = (u8)*(game->vars + word) | (code << 8);
            }
        }
        free3(mail_list);
        mail_list = NULL;
        for (i = 0; i < 0x20; i++) {
            sprite_delete((u16)(i + 0x217));
        }
    }
}

static void mail_receive(u16 id) {
    s32 received;
    s32 word;
    s16 odd;
    u16 code;
    GameVars *game = &action_vars;
    if (id < 0x20) {
        word = id / 2 + 0x60;
        odd = id % 2;
        if (odd) {
            received = (u8)*(game->vars + word) & 0x80;
        } else {
            received = (*(game->vars + word) >> 8) & 0x80;
        }
        if (received == 0) {
            code = game->vars[0x5F]++ | 0x80;
            if (odd) {
                *(game->vars + word) = code | (*(game->vars + word) & 0xFF00);
            } else {
                *(game->vars + word) = (u8)*(game->vars + word) | (code << 8);
            }
        }
    }
}

void mail_check_schedule(s32 day, s32 hour) {
    GameVars *game = &action_vars;
    if ((s16)game->vars[0x30] == 0) {
        if (day == 0) {
            if (hour == 10) {
                mail_receive(0xE);
            } else if (hour == 0x11) {
                mail_receive(8);
            } else if (hour == 0x15) {
                mail_receive(0x17);
            }
        } else if (day == 1) {
            if (hour == 10) {
                mail_receive(0xF);
            } else if (hour == 0x10) {
                mail_receive(0x1C);
            }
        } else if (day == 2) {
            if (hour == 10) {
                if ((s16)game->vars[0xB] == 100 && (s16)game->vars[1] == 0) {
                    mail_receive(2);
                }
                mail_receive(0x11);
                if ((s16)game->vars[0x13] == 100) {
                    mail_receive(0x14);
                }
            } else if (hour == 0xE) {
                if ((s16)game->vars[0x11] == 10) {
                    mail_receive(0x15);
                }
                mail_receive(0x1A);
            }
        } else if (day == 3) {
            if (hour == 0xC) {
                mail_receive(0x1D);
                if ((s16)game->vars[0x4D] == 0) {
                    mail_receive(0x1F);
                }
            }
        }
    }
}

void mail_free(void) {
    SceneTables *tables = &object_scene_tables;
    MailHandlerView *mail = tables->mail;
    if (mail != NULL) {
        mail_list[mail->list_index].read = 1;
        if (mail->entry_sprite != NULL) {
            sprite_set_clut_entry((u16)(mail->id + 0x217), 7, 0x2C1F);
            sprite_set_clut_entry((u16)(mail->id + 0x217), 9, 0x1F);
            mail->entry_sprite->y = mail_entry_saved_y;
            mail->entry_sprite->depth = 2;
        }
        if (mail->scrollbar != NULL) {
            mail->scrollbar->y = mail_scrollbar_saved_y;
        }
        sprite_delete(0x213);
        sprite_delete(0x214);
        sprite_delete(0x215);
        sprite_delete(0x216);
        free3(mail);
        tables->mail = NULL;
    }
}

s16 mail_list_get_id(s16 i) { return mail_list[i].id; }

void mail_cmd_receive(Action *action) {
    mail_receive(((ActionCmdShort *)action->cmd)->target);
}

s32 mail_is_read(s16 id) {
    s32 v;
    GameVars *game = &action_vars;
    s32 word = id / 2 + 0x60;
    if (id & 1) {
        v = (u8)game->vars[word] & 0x40;
    } else {
        v = (game->vars[word] >> 8) & 0x40;
    }
    return v != 0;
}
