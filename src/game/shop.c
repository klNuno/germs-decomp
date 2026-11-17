#include "common.h"
#include "game/shop.h"
#include "game/building.h"
#include "game/dialog.h"
#include "game/door.h"
#include "game/effect.h"
#include "game/main.h"
#include "game/menu.h"
#include "game/player.h"
#include "game/sound.h"
#include "game/sprite.h"
#include "kaj/kaj.h"
#include "psyq/libc.h"
#include "psyq/libsnd.h"

/*
 * The shop scene: menus, topics, the weapon list.
 *
 * File boundaries: likely (docs/layout.md): no assert: a normal function after roadmap.c's deferred inline tail.
 */

static void roadmap_shop_topic_menu(s16 open, s16 open_list);
typedef struct { s32 type; s32 ticks; s32 param0; u8 param1_low; } ShopTriggerEvent;
extern BuildingState block_building_state;
extern ShopState roadmap_shop;
typedef struct { s16 weapon_id; s16 req_level; } ShopWeaponSlot;
extern s32 roadmap_shop_exit_points[];
extern ScreenLight screen_light;
extern KajSystem kaj_system;
static s32 roadmap_cmp_weapon_level(ShopWeaponSlot *lhs, ShopWeaponSlot *rhs);
extern s16 player_status_level[];
extern s16 roadmap_shop_weapons[];
extern SceneTables object_scene_tables[];
extern Player *player_status_player[];
s16 roadmap_shop_topic;
extern char roadmap_shop_ask_owner_line[];
void text_show(char *str, s32 mode, s32 circle_set, s32 circle_flags, s32 cross_set, s32 cross_flags, s32 se);
/* Local view of GameVars: this unit reads 0x14-0x92 as scalars, the shared type has a u16 array there. */
typedef struct {
    u8 unk0[0x14];
    s16 shop_story_var;
    u8 unk16[0x4A];
    s16 ending_done;
    u8 unk62[0x1A];
    u16 hour;
    u8 unk7E[2];
    s16 day_parity;
    u8 unk82[0x10];
    u16 meal_count;
    u8 unk94[0x164];
    u16 shop_entry_hour;
} GameVars_u8019A5D4;
static void roadmap_shop_pick_weapons(ShopState *shop);
extern GameVars_u8019A5D4 action_vars;
extern s16 roadmap_shop_list_3_early[];
extern s16 roadmap_shop_list_3_midday[];
extern s16 roadmap_shop_list_3_late[];
extern s16 roadmap_shop_list_3_changed[];
extern s16 roadmap_shop_list_4[];
extern s16 roadmap_shop_list_4_alt[];
extern s16 roadmap_shop_list_5[];
extern s16 roadmap_shop_list_6_lunch[];
extern s16 roadmap_shop_list_6_afternoon[];
extern s16 roadmap_shop_list_6_late[];
extern s16 roadmap_shop_list_6_changed[];
extern s16 roadmap_shop_list_8[];
extern s16 roadmap_shop_texts[];
extern s16 roadmap_shop_texts_4[];
extern s16 roadmap_shop_texts_4_alt[];
extern s16 roadmap_shop_texts_5[];
extern s16 roadmap_shop_texts_8[];
extern s16 roadmap_shop_texts_9[];
extern s16 roadmap_shop_list_9[];
typedef struct { char *above_level; char *at_level; char *below_level; } WeaponAdvice;
static void roadmap_fade_screen_music(s16 fade_in);
extern PlayerStatus player_status;
extern WeaponAdvice roadmap_shop_weapon_advice[];
void text_show_timed(s16 mode, s16 big, char *str, s16 se, s32 seconds);
extern s16 roadmap_shop_topic_list_0[];
extern s16 roadmap_shop_topic_list_1[];
extern s16 roadmap_shop_topic_list_2[];
extern s16 roadmap_shop_topic_texts[];
extern char *roadmap_shop_topic_prompt[];
static void roadmap_shop_say_reply(s16 building, s16 to_inventory, s16 alt_speaker, s16 reply);
s16 effect_inventory_has_room(s32 kind);
s16 player_set_item(s16 item_id, s32 slot_kind, s32 add);
s16 player_set_weapon(s16 weapon_id, s32 add, s32 stock);
extern s32 (*event_enter_hook)(ShopTriggerEvent *arg0);
extern s32 (*event_leave_hook)(ShopTriggerEvent *arg0);
static s32 roadmap_shop_on_enter(ShopTriggerEvent *ev);
static s32 roadmap_shop_on_leave(ShopTriggerEvent *ev);

INCLUDE_RODATA("asm/nonmatchings/game/shop", roadmap_shop_lines);

static void roadmap_shop_pick_weapons(ShopState *shop) {
    ShopWeaponSlot tab[12];
    WeaponRecord *weapon;
    s32 i;
    s32 j;
    s32 end;
    s32 start;

    shop->deal_level = player_status_level[0] / 20;
    if (shop->deal_level > 2) {
        shop->deal_level = 2;
    }
    j = 0;
    for (i = 1; i < 13; i++) {
        if (i != 10) {
            weapon = effect_weapon_find(i);
            if (weapon != NULL) {
                tab[j].weapon_id = i;
                tab[j].req_level = weapon->req_level;
            } else {
                tab[j].weapon_id = i;
                tab[j].req_level = 100;
            }
            j++;
        }
    }
    qsort(tab, 11, 4, roadmap_cmp_weapon_level);
    switch (shop->deal_level) {
    case 1:
        start = 3;
        end = 8;
        break;
    case 2:
        start = 5;
        end = 10;
        break;
    default:
        start = 0;
        end = 5;
        break;
    }
    for (i = start, j = 0; i <= end; i++, j++) {
        roadmap_shop_weapons[j] = tab[i].weapon_id;
    }
}

static void roadmap_shop_topic_menu(s16 open, s16 open_list) {
    ShopState *shop = &roadmap_shop;
    s32 sprite;
    s16 icon_sprite;
    s16 count;
    s32 rows;
    s16 first_entry;
    s16 color;
    s16 cursor_color;

    if (open != 0) {
        roadmap_shop_topic = 0;
        shop->menu_stage = 3;
        sprite_set_visible(3, 1);
        sprite_fill_clut(3, 4, 6, 0x2969);
        sprite_set_clut_entry(3, 4, 0x2BFF);
        text_show(roadmap_shop_topic_prompt[0], 3, -1, 0, -1, 0, 1);
    } else {
        sprite_set_visible(3, 0);
        text_close();
        if (open_list == 0) {
            roadmap_shop.active = 0;
            shop->menu_stage = -1;
        } else {
            if (roadmap_shop.active == 0) {
                roadmap_shop.active = 1;
            }
            sprite = 0x40B;
            icon_sprite = 0x40C;
            rows = 6;
            first_entry = 4;
            color = 0x2969;
            cursor_color = 0x2BFF;
            shop->texts = roadmap_shop_topic_texts;
            shop->menu_stage = 0;
            switch (roadmap_shop_topic) {
            case 0:
                count = 0xE;
                shop->list = roadmap_shop_topic_list_0;
                break;
            case 1:
                count = 0xF;
                shop->list = roadmap_shop_topic_list_1;
                break;
            case 2:
                sprite = 4;
                icon_sprite = -1;
                count = 4;
                rows = 4;
                shop->list = roadmap_shop_topic_list_2;
                break;
            }
            mail_menu_open(1, sprite, icon_sprite, count, rows, shop->list, first_entry, color, cursor_color);
        }
    }
}

static void roadmap_shop_say_reply(s16 building, s16 to_inventory, s16 alt_speaker, s16 reply) {
    Player *player = player_status_player[0];
    s16 menu_state = mail_menu_get_state();
    s16 topic;

    if (menu_state == 1) {
        if (reply == 0) {
            if (to_inventory != 0) {
                if (building == 4) {
                    if (alt_speaker != 0) {
                        /* shop reply after a purchase, first speaker */
                        text_show(" 6\202\307\202\244\202\274\201\101\212\171\202\265\202\361\202\305\220\110\202\327\202\304\202\313", 3, -1, 0, -1, 0, menu_state);
                    } else {
                        /* shop reply after a purchase, second speaker */
                        text_show(" 2\202\307\202\244\202\274\201\101\202\261\202\277\202\347\202\311\202\310\202\350\202\334\202\267", 3, -1, 0, -1, 0, menu_state);
                    }
                } else if (building == 5) {
                    /* shop reply after a purchase, second speaker, other line */
                    text_show(" 2\221\201\202\337\202\311\220\110\202\327\202\304\202\255\202\276\202\263\202\242\202\313", 3, -1, 0, -1, 0, menu_state);
                }
            } else {
                if (building == 4) {
                    if (alt_speaker != 0) {
                        /* shop reply after a purchase, first speaker */
                        text_show(" 6\202\307\202\244\202\274\201\101\212\171\202\265\202\361\202\305\220\110\202\327\202\304\202\313", 3, -1, 0, -1, 0, menu_state);
                    } else {
                        /* shop reply after a purchase, second speaker */
                        text_show(" 2\202\307\202\244\202\274\201\101\202\261\202\277\202\347\202\311\202\310\202\350\202\334\202\267", 3, -1, 0, -1, 0, menu_state);
                    }
                } else if (building == 5) {
                    /* shop reply after a purchase, second speaker, other line */
                    text_show(" 2\202\307\202\244\202\274\201\101\202\250\202\242\202\265\202\242\202\305\202\267\202\346", 3, -1, 0, -1, 0, menu_state);
                }
            }
        } else if (reply == 2) {
            if (alt_speaker != 0) {
                /* shop refusal: inventory full, first speaker */
                text_show(" 6\202\261\202\352\210\310\217\343\216\235\202\304\202\310\202\242\202\355\202\346", 3, -1, 0, -1, 0, 4);
            } else {
                /* shop refusal: inventory full, second speaker */
                text_show(" 2\202\261\202\352\210\310\217\343, \202\250\216\235\202\277\202\311\202\310\202\352\202\310\202\242\202\346\202\244\202\305\202\267\202\346", 3, -1, 0, -1, 0, 4);
            }
        } else if (reply == menu_state) {
            if (building == 8) {
                topic = roadmap_shop_topic;
                if (topic == -1) {
                    if (player->flags & 0x100) {
                        player->flags &= 0xFEFF;
                    }
                    text_show(roadmap_shop_ask_owner_line, 3, -1, 0, topic, 0, reply);
                }
            } else {
                if (player->flags & 0x100) {
                    player->flags &= 0xFEFF;
                }
                text_close();
            }
        }
        mail_menu_close();
    }
}

static void roadmap_fade_screen_music(s16 fade_in) {
    BgmSep *bgm = object_scene_tables[0].bgm;
    ScreenLight *light = &screen_light;
    s32 t;
    s32 volume;

    if (fade_in != 0) {
        light->fade_level = 0x80;
    } else {
        light->fade_active = 1;
        light->fade_level = 0x1000;
    }
    while (1) {
        if (fade_in != 0) {
            light->fade_level += kaj_system.vsync_delta * 0x85;
            if (light->fade_level >= 0x1000) {
                light->fade_level = 0x1000;
                break;
            }
        } else {
            light->fade_level -= kaj_system.vsync_delta * 0x85;
            if (light->fade_level <= 0x80) {
                light->fade_level = 0x80;
                break;
            }
        }
        if (bgm != NULL && bgm->seq >= 0) {
            t = light->fade_level >> 5;
            if (t < 0x80) {
                volume = (s16)t;
                if (t < 0) {
                    volume = 0;
                }
            } else {
                volume = 0x7F;
            }
            SsSepSetVol(bgm->sep, bgm->seq, volume, volume);
        }
        mail_step_frame(1, 1, 1);
    }
    if (fade_in != 0) {
        light->fade_active = 0;
        light->fade_level = 0x1000;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/shop", roadmap_shop_ask_owner_line);

s16 roadmap_shop_finish(s16 building) {
    PlayerStatus *status = &player_status;
    ShopState *shop = &roadmap_shop;
    GameVars_u8019A5D4 *game = &action_vars;
    Player *player = status->player;
    char buf[0x80];
    WeaponAdvice *advice;
    WeaponRecord *weapon;
    ItemRecord *item;
    char *line;
    s32 i;
    s16 found = 0;
    s16 ret;
    s16 v;
    s32 j;
    s16 m;
    ShopState *shop2;

    switch (building) {
    case 7:
        if (shop->picks[0] >= 0) {
            advice = &roadmap_shop_weapon_advice[shop->deal_level];
            weapon = effect_weapon_find(shop->picks[0]);
            if (weapon != NULL) {
                if ((s16)weapon->req_level == status->level) {
                    line = advice->at_level;
                } else if ((s16)weapon->req_level < status->level) {
                    line = advice->below_level;
                } else {
                    line = advice->above_level;
                }
                text_show_timed(1, 1, line, 1, 2);
                memset(buf, 0, 0x80);
                sprintf(buf, " 8%s1, \202\360\216\363\202\257\216\346\202\301\202\275", weapon->name);
                text_show_timed(1, 1, buf, 2, 2);
            }
        }
        break;
    case 8:
        ret = -1;
        if (shop->to_inventory != 0) {
            if (shop->picks[0] >= 0) {
                item = effect_item_find(shop->picks[0] + 100);
                if (item != NULL) {
                    memset(buf, 0, 0x80);
                    sprintf(buf, " 8%s2\202\314\222n\220\175\202\313", item->name);
                    text_show_timed(1, 1, buf, 2, 2);
                    text_show(roadmap_shop_ask_owner_line, 3, -1, 0, -1, 0, 1);
                    if (player->flags & 0x100) {
                        player->flags &= 0xFEFF;
                    }
                }
            }
        } else if (shop->picks[0] >= 0) {
            ret = shop->picks[0];
            if (roadmap_shop_topic == 0) {
                ret += 10;
            } else if (roadmap_shop_topic == 1) {
                ret += 30;
            }
        }
        break;
    case 9:
        if (shop->picks[0] >= 0) {
            item = effect_item_find(shop->picks[0]);
            if (item != NULL) {
                memset(buf, 0, 0x80);
                sprintf(buf, " 8%s1\202\360\221I\221\360\202\265\202\275", item->name);
                text_show_timed(1, 1, buf, 2, 1);
                roadmap_fade_screen_music(0);
                effect_item_use(status, 1, shop->picks[0], 0, 0);
                mail_wait(1, 1, 1, 2);
                roadmap_fade_screen_music(1);
                mail_wait(1, 1, 1, 2);
                text_show(" 2\202\250\224\346\202\352\227l\202\305\202\265\202\275", 3, -1, 0, -1, 0, 1);
            }
        }
        break;
    default:
        if (shop->to_inventory != 0) {
            for (i = 0; i < 3; i++) {
                if (shop->picks[i] >= 0) {
                    item = effect_item_find(shop->picks[i]);
                    if (item != NULL) {
                        memset(buf, 0, 0x80);
                        sprintf(buf, " 8%s1, \202\360\216\363\202\257\216\346\202\301\202\275", item->name);
                        text_show_timed(1, 1, buf, 2, 2);
                    }
                }
            }
            if (building == 4) {
                if (shop->alt_speaker != 0) {
                    text_show(" 6\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275, \203N\203b\203N\203b\203N", 3, -1, 0, -1, 0, 1);
                } else {
                    text_show(" 2\202\307\202\244\202\340\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275", 3, -1, 0, -1, 0, 1);
                }
            } else if (building == 5) {
                text_show(" 2\202\334\202\275\201A\202\346\202\353\202\265\202\255\202\250\212\350\202\242\202\265\202\334\202\267", 3, -1, 0, -1, 0, 1);
            }
        } else {
            if (status->energy == 0xFF && shop->deal_level == 0) {
                shop->deal_level = 1;
            }
            for (i = 0; i < 3; i++) {
                if (shop->picks[i] >= 0) {
                    if (!found) {
                        found = 1;
                    }
                    v = effect_item_use(status, 1, shop->picks[i], shop->deal_level, 0);
                    if (v >= 0) if (v != 0) {
                        shop->deal_level = 1;
                    }
                }
            }
            if (found) {
                game->meal_count++;
            }
            if (building == 4) {
                if (shop->alt_speaker != 0) {
                    text_show(" 6\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275, \203N\203b\203N\203b\203N", 3, -1, 0, -1, 0, 1);
                } else {
                    text_show(" 2\202\307\202\244\202\340\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275", 3, -1, 0, -1, 0, 1);
                }
            } else if (building == 5) {
                text_show(" 2\202\334\202\275\201A\202\346\202\353\202\265\202\255\202\250\212\350\202\242\202\265\202\334\202\267", 3, -1, 0, -1, 0, 1);
            }
        }
        break;
    }
    shop2 = &roadmap_shop;
    roadmap_shop.active = 0;
    shop2->menu_stage = -1;
    shop2->to_inventory = 0;
    shop2->alt_speaker = 0;
    shop2->at_counter = 0;
    shop2->has_second_menu = 0;
    shop2->has_third_menu = 0;
    shop2->deal_level = 0;
    shop2->cursor = 0;
    m = -1;
    for (j = 2; j >= 0; j--) {
        shop2->picks[j] = m;
    }
    shop2->list = NULL;
    shop2->texts = NULL;
    if (building == 3 || building == 6) {
        player_reset_triggers(2);
    }
    return ret;
}

s16 roadmap_shop_update_input(PlayerStatus *status) {
    ShopState *shop = &roadmap_shop;
    BuildingState *bstate = &block_building_state;
    Player *player = status->player;
    s16 sel;

    if (roadmap_shop.active == 0) {
        return 0;
    }
    sel = mail_menu_get_state();
    if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
        if (shop->menu_stage == 3 && sel == 0) {
            sound_se_play(0x11);
            roadmap_shop_topic_menu(0, 1);
            return 1;
        } else if (shop->menu_stage == 0 && sel == 1) {
            sound_se_play(0x11);
            sel = mail_menu_get_entry(shop->cursor);
            if (shop->to_inventory != 0) {
                switch (bstate->building) {
                case 7:
                    if (effect_inventory_has_room(4) != 0) {
                        if (player_set_weapon(sel, 1, 0) != 0) {
                            shop->picks[0] = sel;
                        }
                    } else {
                        roadmap_shop_say_reply(bstate->building, shop->to_inventory, shop->alt_speaker, 2);
                        return 1;
                    }
                    break;
                case 8:
                    shop->picks[0] = sel;
                    player_set_item(sel + 100, 2, 1);
                    roadmap_shop_say_reply(bstate->building, shop->to_inventory, shop->alt_speaker, 0);
                    return 1;
                default:
                    if (effect_inventory_has_room(0) != 0) {
                        if (player_set_item(sel, 0, 1) != 0) {
                            shop->picks[0] = sel;
                        }
                    } else {
                        roadmap_shop_say_reply(bstate->building, shop->to_inventory, shop->alt_speaker, 2);
                        return 1;
                    }
                    break;
                }
            } else {
                shop->picks[0] = sel;
            }
            if (shop->has_second_menu != 0) {
                shop->menu_stage = 1;
                shop->cursor = 0;
                text_show(((char **)shop->texts)[1], 3, -1, 0, -1, 0, 1);
                mail_menu_set_list(4, shop->list + 4);
                return 1;
            }
        } else if (shop->menu_stage == 1 && sel == 1) {
            sound_se_play(0x11);
            sel = mail_menu_get_entry(shop->cursor);
            if (shop->to_inventory != 0) {
                if (effect_inventory_has_room(0) != 0) {
                    if (player_set_item(sel, 0, 1) != 0) {
                        shop->picks[1] = sel;
                    }
                } else {
                    roadmap_shop_say_reply(bstate->building, shop->to_inventory, shop->alt_speaker, 2);
                    return 1;
                }
            } else {
                shop->picks[1] = sel;
            }
            if (shop->has_third_menu != 0) {
                shop->menu_stage = 2;
                text_show(((char **)shop->texts)[2], 3, -1, 0, -1, 0, 1);
                return 1;
            }
        } else if (shop->menu_stage == 2 && sel == 1) {
            sound_se_play(0x11);
            sel = shop->list[8];
            if (shop->to_inventory != 0) {
                if (effect_inventory_has_room(0) != 0) {
                    if (player_set_item(sel, 0, 1) != 0) {
                        shop->picks[2] = sel;
                    }
                } else {
                    roadmap_shop_say_reply(bstate->building, shop->to_inventory, shop->alt_speaker, 2);
                    return 1;
                }
            } else {
                shop->picks[2] = sel;
            }
        } else {
            return 1;
        }
        roadmap_shop_say_reply(bstate->building, shop->to_inventory, shop->alt_speaker, 0);
    } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
        sound_se_play(8);
        if (shop->menu_stage == 3 && sel == 0) {
            roadmap_shop_topic_menu(0, 0);
            /* shop farewell: come back for more talk */
            text_show_timed(1, 1, " 2\230b\202\252\225\267\202\253\202\275\202\255\202\310\202\301\202\275\202\347, \202\242\202\302\202\305\202\340\202\250\202\242\202\305", 1, 1);
            if (player->flags & 0x100) {
                player->flags &= 0xFEFF;
            }
        } else if (shop->menu_stage == 0 && sel == 1) {
            roadmap_shop_say_reply(bstate->building, shop->to_inventory, shop->alt_speaker, 1);
            return 1;
        } else if (shop->menu_stage == 1 && sel == 1 && shop->has_third_menu != 0) {
            shop->menu_stage = 2;
            text_show(((char **)shop->texts)[2], 3, -1, 0, -1, 0, sel);
        } else {
            roadmap_shop_say_reply(bstate->building, shop->to_inventory, shop->alt_speaker, 0);
            return 1;
        }
    } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
        if (sel == 0) {
            if (shop->menu_stage == 3) {
                sound_se_play(0xF);
                if (--roadmap_shop_topic < 0) {
                    roadmap_shop_topic = 2;
                }
                sprite_fill_clut(3, 4, 6, 0x2969);
                sprite_set_clut_entry(3, roadmap_shop_topic + 4, 0x2BFF);
            }
        } else if (sel == 1) {
            if (shop->menu_stage != 2) {
                shop->cursor = mail_menu_move(1);
            }
        }
    } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
        if (sel == 0) {
            if (shop->menu_stage == 3) {
                sound_se_play(0xF);
                if (++roadmap_shop_topic >= 3) {
                    roadmap_shop_topic = 0;
                }
                sprite_fill_clut(3, 4, 6, 0x2969);
                sprite_set_clut_entry(3, roadmap_shop_topic + 4, 0x2BFF);
            }
        } else if (sel == 1) {
            if (shop->menu_stage != 2) {
                shop->cursor = mail_menu_move(0);
            }
        }
        return 1;
    }
    return 1;
}

s16 roadmap_shop_open_menu(s16 building, s32 trigger) {
    Player *player = player_status_player[0];
    GameVars_u8019A5D4 *game = &action_vars;
    ShopState *shop = &roadmap_shop;
    s32 j;
    s16 m;
    s16 sprite;
    s16 icon_sprite;
    s16 count;
    s16 rows;
    s16 first_entry;
    s16 color;
    s16 cursor_color;

    if (mail_menu_get_state() != 0) {
        return 0;
    }
    roadmap_shop.active = 1;
    shop->menu_stage = 0;
    shop->alt_speaker = 0;
    shop->has_second_menu = 0;
    shop->has_third_menu = 0;
    shop->deal_level = 0;
    shop->cursor = 0;
    m = -1;
    for (j = 2; j >= 0; j--) {
        shop->picks[j] = m;
    }
    sprite = 3;
    icon_sprite = -1;
    count = 4;
    rows = count;
    first_entry = 1;
    color = 0x14E7;
    cursor_color = 0x14FF;
    switch (building) {
    case 3:
        if (game->shop_story_var == 2000) {
            shop->alt_speaker = 1;
            shop->list = roadmap_shop_list_3_changed;
        } else if (game->shop_entry_hour >= 8 && game->shop_entry_hour < 10) {
            shop->list = roadmap_shop_list_3_early;
        } else if (game->shop_entry_hour >= 10 && game->shop_entry_hour < 14) {
            shop->list = roadmap_shop_list_3_midday;
        } else {
            shop->list = roadmap_shop_list_3_late;
        }
        shop->texts = roadmap_shop_texts;
        break;
    case 4:
        if (game->shop_story_var == 1000) {
            shop->list = roadmap_shop_list_4;
            shop->texts = roadmap_shop_texts_4;
        } else if (game->shop_story_var == 2000) {
            shop->alt_speaker = 1;
            shop->list = roadmap_shop_list_4_alt;
            shop->texts = roadmap_shop_texts_4_alt;
        } else if (game->day_parity != 0) {
            if (game->ending_done != 0 || !(game->shop_entry_hour >= 8 && game->shop_entry_hour < 14)) {
                shop->list = roadmap_shop_list_4;
                shop->texts = roadmap_shop_texts_4;
            } else {
                shop->alt_speaker = 1;
                shop->list = roadmap_shop_list_4_alt;
                shop->texts = roadmap_shop_texts_4_alt;
            }
        } else {
            if (game->ending_done != 0 || (game->shop_entry_hour >= 8 && game->shop_entry_hour < 14)) {
                shop->list = roadmap_shop_list_4;
                shop->texts = roadmap_shop_texts_4;
            } else {
                shop->alt_speaker = 1;
                shop->list = roadmap_shop_list_4_alt;
                shop->texts = roadmap_shop_texts_4_alt;
            }
        }
        shop->has_second_menu = 1;
        shop->has_third_menu = 1;
        break;
    case 5:
        shop->texts = roadmap_shop_texts_5;
        shop->list = roadmap_shop_list_5;
        shop->has_second_menu = 1;
        shop->has_third_menu = 1;
        break;
    case 6:
        shop->texts = roadmap_shop_texts;
        if (game->shop_story_var == 2000) {
            shop->alt_speaker = 1;
            shop->list = roadmap_shop_list_6_changed;
        } else if (game->shop_entry_hour >= 11 && game->shop_entry_hour < 14) {
            shop->list = roadmap_shop_list_6_lunch;
        } else if (game->shop_entry_hour >= 14 && game->shop_entry_hour < 17) {
            shop->list = roadmap_shop_list_6_afternoon;
        } else {
            shop->list = roadmap_shop_list_6_late;
        }
        break;
    case 7:
        roadmap_shop_pick_weapons((ShopState *)shop);
        sprite = 0x40B;
        icon_sprite = 0x402;
        count = 6;
        rows = count;
        first_entry = 4;
        color = 0x2969;
        cursor_color = 0x2BFF;
        shop->to_inventory = 1;
        shop->texts = roadmap_shop_texts;
        shop->list = roadmap_shop_weapons;
        break;
    case 8:
        player->flags |= 0x100;
        if (trigger != 0x300600) {
            goto fail;
        }
        sprite = 0x40B;
        icon_sprite = 0x40C;
        count = 0xD;
        rows = 6;
        first_entry = 4;
        color = 0x2969;
        cursor_color = 0x2BFF;
        roadmap_shop_topic = -1;
        shop->texts = roadmap_shop_texts_8;
        shop->to_inventory = 1;
        shop->list = roadmap_shop_list_8;
        break;
    case 9:
        count = 3;
        rows = count;
        shop->texts = roadmap_shop_texts_9;
        shop->list = roadmap_shop_list_9;
        break;
    }
    return mail_menu_open(1, sprite, icon_sprite, count, rows, shop->list, first_entry, color, cursor_color);
fail:
    roadmap_shop_topic_menu(1, 0);
    return 1;
}

void roadmap_shop_init(s16 building) {
    GameVars_u8019A5D4 *game = &action_vars;
    ShopState *shop = &roadmap_shop;
    s32 door;
    s32 j;

    roadmap_shop.active = 0;
    shop->menu_stage = -1;
    shop->to_inventory = 0;
    shop->alt_speaker = 0;
    shop->at_counter = 0;
    shop->has_second_menu = 0;
    shop->has_third_menu = 0;
    shop->deal_level = 0;
    shop->cursor = 0;
    for (j = 0; j < 3; j++) {
        shop->picks[j] = -1;
    }
    shop->list = 0;
    shop->texts = 0;
    game->shop_entry_hour = game->hour;
    switch (building) {
    case 8:
    case 9:
        break;
    default:
        for (door = 0; door < 40; door++) {
            if (door < (building - 3) * 10 || door >= (building - 3) * 10 + 10) {
                door_set_visible(door, 0);
            }
        }
        break;
    }
    event_enter_hook = roadmap_shop_on_enter;
    event_leave_hook = roadmap_shop_on_leave;
}

void roadmap_shop_exit_to_town(s16 building, s16 exit_no) {
    s32 point = (exit_no - 1) * 3;

    switch (building) {
    case 4:
        point += 0x27;
        break;
    case 5:
        point += 0x39;
        break;
    case 6:
        point += 0x57;
        break;
    case 7:
        point += 0x69;
        break;
    }
    mail_goto_twn(roadmap_shop_exit_points[point], 0, roadmap_shop_exit_points[point + 1], roadmap_shop_exit_points[point + 2], 1);
}

void roadmap_shop_open_topic_list(void) {
    roadmap_shop_topic_menu(0, 1);
}

static s32 roadmap_shop_on_enter(ShopTriggerEvent *ev) {
    ShopState *shop = &roadmap_shop;

    if (ev->param0 == 0x30) {
        u32 trigger = ev->param1_low;

        if (block_building_state.building == 3) {
            if (trigger < 11) {
                shop->at_counter = 1;
            }
        } else if (block_building_state.building == 6) {
            if (trigger < 6) {
                shop->at_counter = 1;
            }
        }
    }
    return 0;
}

static s32 roadmap_shop_on_leave(ShopTriggerEvent *ev) {
    ShopState *shop = &roadmap_shop;

    if (ev->param0 == 0x30) {
        u32 trigger = ev->param1_low;

        if (block_building_state.building == 3) {
            if (trigger < 11) {
                shop->at_counter = 0;
            }
        } else if (block_building_state.building == 6) {
            if (trigger < 6) {
                shop->at_counter = 0;
            }
        }
    }
    return 0;
}

static s32 roadmap_cmp_weapon_level(ShopWeaponSlot *lhs, ShopWeaponSlot *rhs) {
    return lhs->req_level - rhs->req_level;
}
