#include "common.h"
#include "game/menu.h"
#include "game/effect.h"
#include "game/sound.h"
#include "game/sprite.h"
#include "kaj/kaj.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libgpu.h"

/*
 * The mail menu list.
 *
 * File boundaries: likely (docs/layout.md): no assert: a normal function after main.c's deferred inline tail.
 */

extern GameVars action_vars;
extern ListMenu menu_list;
static void menu_draw(ListMenu *menu, s32 draw_icons);
void sprite_copy_cell(s32 src_id, s32 col, s32 row, s32 dst_id, s32 dst_x, s32 dst_y);
static void menu_draw_item_name(s32 sprite_id, s32 y, s32 item_id);
typedef struct { u16 img_x; u16 img_y; u8 unk4[0x10]; s16 u_shift; } MenuTimView;
typedef struct { u8 unk0[0x10]; s16 cell_w; u16 cell_h; s16 columns; u16 rows; s32 unk18; MenuTimView *tim; } MenuSpriteView;
typedef struct { s16 img_x; s16 img_y; } ItemNameTim;
typedef struct { u8 unk0[0x1C]; ItemNameTim *tim; } ItemNameSprite;

static void menu_draw_item_name(s32 sprite_id, s32 y, s32 item_id) {
    s16 rect[4];
    u16 buf[0x20];
    ItemNameSprite *sprite;
    ItemRecord *item;
    u16 *dst;
    u16 *glyph;
    s32 i;
    s32 t;
    s32 line;
    s32 len;
    s32 x;

    sprite = (ItemNameSprite *)sprite_find(sprite_id);
    item = effect_item_find(item_id);
    if (sprite == NULL || item == NULL) {
        return;
    }
    x = sprite->tim->img_x;
    y += sprite->tim->img_y;
    rect[2] = 2;
    rect[3] = 15;
    rect[0] = x;
    rect[1] = y;
    len = strlen((char *)item->name);
    for (i = 0; i < 24; i += 2) {
        dst = buf;
        if (i < len) {
            glyph = Krom2RawAdd2((item->name[i] << 8) | item->name[i + 1]);
            for (line = 0; line < 15; line++, glyph++) {
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 4;
                    v = 0;
                    k = 7;
                    sh = 0;
                    do {
                        c1 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    dst[0] = v;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 0;
                    v = 0;
                    k = 3;
                    sh = 0;
                    do {
                        c1 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    t = dst[0];
                    t |= (u16)(v << 8);
                    dst[0] = t;
                    dst++;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 12;
                    v = 0;
                    k = 15;
                    sh = 0;
                    do {
                        c1 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    dst[0] = v;
                }
                {
                    u16 v;
                    s32 k;
                    s32 sh;
                    s32 m;
                    u16 c1;
                    u16 c2;

                    m = 8;
                    v = 0;
                    k = 11;
                    sh = 0;
                    do {
                        c1 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        c2 = (*glyph >> k) & 1 ? 2 : 14;
                        k--;
                        if (c1 == c2) {
                            v |= c1 << sh;
                        } else {
                            v |= 10 << sh;
                        }
                        sh += 4;
                    } while (k > m);
                    t = dst[0];
                    t |= (u16)(v << 8);
                    dst[0] = t;
                    dst++;
                }
            }
        } else {
            memset(dst, 0xEE, 0x40);
        }
        LoadImage2(rect, buf);
        rect[0] += 2;
    }
}

static void menu_draw(ListMenu *menu, s32 draw_icons) {
    s32 i;
    s16 start;
    s16 end;
    s32 line;
    u16 col;
    u16 row;

    sprite_fill_clut(menu->sprite, menu->first_entry, menu->first_entry + menu->rows - 1, menu->color);
    sprite_set_clut_entry(menu->sprite, menu->cursor_entry, (u16)menu->cursor_color);
    start = menu->scroll;
    if (menu->rows < menu->count) {
        end = start + menu->rows;
    } else {
        end = start + menu->count;
    }
    if ((s16)draw_icons != 0 && menu->draw_rows != 0) {
        for (i = start, line = 0; i < end; i++, line++) {
            if (menu->icon_sprite >= 0) {
                if (menu->list == NULL) {
                    col = i / menu->icon_rows;
                    row = i % menu->icon_rows;
                } else {
                    col = menu->list[i] / menu->icon_rows;
                    row = menu->list[i] % menu->icon_rows;
                }
                sprite_copy_cell((u16)menu->icon_sprite, col, row, menu->sprite, 0x10, (u16)(line * 0x11 + 0xC));
            } else if (menu->icon_sprite == -2) {
                menu_draw_item_name((s16)menu->sprite, line * 0x11 + 0xC, menu->list[i]);
            }
        }
    }
}

void menu_clear_rows(ListMenu *menu) {
    s16 rect[4];
    MenuSpriteView *sprite;
    MenuSpriteView *icons;
    u8 *buf;
    s32 size;
    s32 i;

    sprite = (MenuSpriteView *)sprite_find(menu->sprite);
    icons = (MenuSpriteView *)sprite_find(menu->icon_sprite);
    if (sprite != NULL) {
        rect[0] = sprite->tim->img_x;
        rect[1] = sprite->tim->img_y + 0xC;
        rect[2] = 0x18;
        rect[3] = 0x10;
        if (icons != NULL) {
            rect[0] = sprite->tim->img_x + (0x10 >> sprite->tim->u_shift);
            rect[1] = sprite->tim->img_y + 0xC;
            rect[2] = icons->cell_w >> icons->tim->u_shift;
            rect[3] = icons->cell_h;
            menu->icon_rows = icons->rows;
        }
        size = rect[2] * rect[3] * 2;
        buf = kaj_malloc(size);
        if (buf != NULL) {
            memset(buf, 0xEE, size);
            for (i = 0; i < 6; i++) {
                LoadImage2(rect, buf);
                rect[1] += 0x11;
            }
            free3(buf);
        }
    }
}

s16 menu_move(s16 up) {
    s16 snd = 1;
    s32 scrolled = 0;
    ListMenu *menu = &menu_list;

    if (up != 0) {
        menu->index--;
        if (menu->wrap != 0) {
            menu->cursor_entry--;
            if (menu->index < 0) {
                menu->index = menu->count - 1;
                menu->cursor_entry = menu->first_entry + menu->index;
            }
        } else {
            if (menu->index < 0) {
                menu->index = 0;
            }
            menu->cursor_entry--;
            if (menu->cursor_entry < menu->first_entry) {
                menu->cursor_entry = menu->first_entry;
                snd = 0;
                if (menu->scroll > 0) {
                    menu->scroll--;
                    scrolled = 1;
                    snd = 1;
                }
            }
        }
    } else {
        menu->index++;
        if (menu->wrap != 0) {
            menu->cursor_entry++;
            if (menu->index >= menu->count) {
                menu->index = 0;
                menu->cursor_entry = menu->first_entry;
            }
        } else {
            if (menu->index >= menu->count) {
                menu->index = menu->count - 1;
            }
            menu->cursor_entry++;
            if (menu->cursor_entry >= menu->first_entry + menu->rows) {
                menu->cursor_entry = menu->first_entry + menu->rows - 1;
                snd = 0;
                if (menu->scroll != menu->index - menu->rows + 1) {
                    menu->scroll = menu->index - menu->rows + 1;
                    scrolled = 1;
                    snd = 1;
                }
            }
        }
    }
    if (snd) {
        sound_se_play(0xF);
    }
    menu_draw(menu, scrolled);
    return menu->index;
}

s32 menu_open(s16 reset, s16 sprite, s16 icon_sprite, s16 count, s16 rows, s16 *list, s16 first_entry, s16 color, s16 cursor_color) {
    GameVars *game = &action_vars;
    ListMenu *menu = &game->menu_list;
    if (game->menu_list.state != 0) {
        return 0;
    }
    game->menu_busy = 1;
    game->menu_list.state = 2;
    if (reset != 0) {
        menu->index = 0;
        menu->cursor_entry = first_entry;
        menu->scroll = 0;
    }
    menu->first_entry = first_entry;
    menu->sprite = sprite;
    menu->icon_sprite = icon_sprite;
    menu->color = color;
    menu->cursor_color = cursor_color;
    menu->wrap = 1;
    if (rows < count) {
        menu->wrap = 0;
    }
    menu->draw_rows = 1;
    if (icon_sprite == -1) {
        menu->draw_rows = 0;
    }
    menu->rows = rows;
    menu->count = count;
    menu->list = list;
    if ((icon_sprite == 0x40C || icon_sprite == 0x402 || icon_sprite == -2) && sprite == 0x40B) {
        menu_clear_rows(menu);
    }
    menu_draw(menu, 1);
    effect_start_sprite_slide(0xB, sprite, 2);
    return 1;
}

s32 menu_close(void) {
    ListMenu *menu = &menu_list;
    if (menu->state != 1) {
        return 0;
    }
    menu->state = 2;
    effect_start_sprite_slide(0xC, menu->sprite, 2);
    return 1;
}

s16 menu_get_state(void) { return menu_list.state; }

s32 menu_set_list(u16 sprite, s16 *list) {
    ListMenu *menu = &menu_list;
    if (menu->state == 2) {
        return 0;
    }
    menu->index = 0;
    menu->scroll = 0;
    menu->list = list;
    menu->cursor_entry = menu->first_entry;
    sprite_set_visible(menu->sprite, 0);
    sprite_set_visible(sprite, 1);
    menu->sprite = sprite;
    menu_draw(menu, 0);
    return 1;
}

s16 menu_get_entry(s16 i) {
    ListMenu *menu = &menu_list;
    if (i < 0 || menu->count < i) {
        return -1;
    }
    return menu->list[i];
}
