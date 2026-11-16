#include "common.h"
#include "game/types.h"

extern RoadMap roadmap_state;
typedef struct { s16 active; s16 frames_left; u8 red; u8 green; u8 blue; u8 unk7; } RoadmapFlash;
RoadmapFlash roadmap_flash;
void roadmap_shop_topic_menu(s16 open, s16 open_list);
typedef struct { s32 type; s32 ticks; s32 param0; u8 param1_low; } ShopTriggerEvent;
extern BuildingState block_building_state;
extern ShopState roadmap_shop;
typedef struct { s16 weapon_id; s16 req_level; } ShopWeaponSlot;
extern s32 roadmap_shop_exit_points[];
void mail_goto_twn(s32 x, s32 y, s32 z, s16 yaw, s16 e);
extern ScreenLight screen_light;
typedef struct { u8 unk0[0x18]; void (*handler)(); s32 unk1C; } RoadmapPrimHandler;
extern RoadmapPrimHandler roadmap_prim_handlers[8];
typedef struct { s32 ndiv; s32 pih; s32 piv; } DivPolygon;
extern DivPolygon roadmap_divpoly3;
extern DivPolygon roadmap_divpoly4;
typedef struct { u8 unk0[0x10]; } ClipVector;
extern ClipVector roadmap_clip_buf;
u8 roadmap_ft_color_r;
u8 roadmap_ft_color_g;
u8 roadmap_ft_color_b;
void roadmap_draw_f3();
void roadmap_draw_g3();
void roadmap_draw_ft3();
void roadmap_draw_gt3();
void roadmap_draw_f4();
void roadmap_draw_g4();
void roadmap_draw_ft4();
void roadmap_draw_gt4();
void kaj_view_clear_vram(void);
void kaj_view_set_bg_color(u8 r, u8 g, u8 b);
void InitClip(ClipVector *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern KajSystem kaj_system;
s16 roadmap_frame_mode;
s32 roadmap_daylight_level;
s32 roadmap_brightness;
s16 roadmap_draw_flags;
ViewBuffer *kaj_view_begin_frame(void);
void sprite_draw_all(ViewBuffer *arg0);
void mod_npcrec_draw_all(s32 view);
void npc_draw_all(s32 view);
void roadmap_draw_flash(ViewBuffer *arg0);
void sprite_thing_draw_all(ViewBuffer *arg0);
void door_draw_all(ViewBuffer *arg0);
void mod_draw_player(ViewBuffer *arg0, s32 arg1);
void vehicle_draw(ViewBuffer *arg0);
void block_draw_all(ViewBuffer *arg0, s32 arg1);
void kaj_view_flip(ViewBuffer *buf);
WeaponRecord *effect_weapon_find(s16 id);
s32 roadmap_cmp_weapon_level(ShopWeaponSlot *lhs, ShopWeaponSlot *rhs);
void qsort(void *base, s32 nel, s32 width, s32 (*cmp)());
extern s16 player_status_level[];
extern s16 roadmap_shop_weapons[];
extern SceneTables object_scene_tables[];
void SsSepSetVol(s16 access_num, s16 seq_num, s16 voll, s16 volr);
void mail_step_frame(u16 mode, s16 b, s16 c);
extern Player *player_status_player[];
s16 roadmap_shop_topic;
extern char roadmap_shop_ask_owner_line[];
s16 mail_menu_get_state(void);
s32 mail_menu_close(void);
void text_show(char *str, s32 mode, s32 circle_set, s32 circle_flags, s32 cross_set, s32 cross_flags, s32 se);
void text_close(void);
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
void roadmap_shop_pick_weapons(ShopState *shop);
extern GameVars_u8019A5D4 action_vars;
s32 mail_menu_open(s16 reset, s16 sprite, s16 icon_sprite, s16 count, s16 rows, s16 *list, s16 first_entry, s16 color, s16 cursor_color);
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
void roadmap_fade_screen_music(s16 fade_in);
extern PlayerStatus player_status;
extern WeaponAdvice roadmap_shop_weapon_advice[];
ItemRecord *effect_item_find(s16 id);
void text_show_timed(s16 mode, s16 big, char *str, s16 se, s32 seconds);
s16 effect_item_use(PlayerStatus *status, s16 b, s16 item_id, s16 full, s16 close_text);
void mail_wait(s32 mode, s32 stream, s32 visibility, s32 seconds);
void player_reset_triggers(s16 reground);
void *memset(void *dst, s32 c, u32 n);
int sprintf(char *buf, const char *fmt, ...);
s16 *sprite_find(s32 id);
void kaj_abend(s32 code, char *msg, char *file, s32 line);
extern s16 roadmap_shop_topic_list_0[];
extern s16 roadmap_shop_topic_list_1[];
extern s16 roadmap_shop_topic_list_2[];
extern s16 roadmap_shop_topic_texts[];
extern char *roadmap_shop_topic_prompt[];
void sprite_set_visible(s32 id, s32 visible);
void sprite_fill_clut(s32 id, s32 first, s32 last, s32 color);
void sprite_set_clut_entry(s32 id, s32 index, s32 color);
void roadmap_shop_say_reply(s16 building, s16 to_inventory, s16 alt_speaker, s16 reply);
s16 mail_menu_move(s16 up);
void sound_se_play(s32 id);
s16 effect_inventory_has_room(s32 kind);
void mail_menu_set_list(s32 sprite, s16 *list);
s16 mail_menu_get_entry(s16 i);
s16 player_set_item(s16 item_id, s32 slot_kind, s32 add);
s16 player_set_weapon(s16 weapon_id, s32 add, s32 stock);
extern s32 (*event_enter_hook)(ShopTriggerEvent *arg0);
extern s32 (*event_leave_hook)(ShopTriggerEvent *arg0);
void door_set_visible(u16 id, s16 visible);
s32 roadmap_shop_on_enter(ShopTriggerEvent *ev);
s32 roadmap_shop_on_leave(ShopTriggerEvent *ev);
typedef struct { u8 r; u8 g; u8 b; u8 unk3; } SpriteColor;
extern SpriteColor roadmap_sprite_colors[2];
typedef struct {
    u8 unk0[8];
    s32 clut_rect[2];
    s16 u;
    u16 v;
    s16 u_shift;
    u8 unk16[2];
    u16 clut;
    u16 tpage;
    s32 clut_orig;
    s32 clut_work;
} RoadmapTim;
typedef struct {
    u16 id;
    u16 mode;
    u8 unk4[2];
    s16 clut_dirty;
    s16 color;
    s16 x;
    s16 y;
    s16 depth;
    u16 cell_w;
    u16 cell_h;
    u8 unk14[4];
    u16 cell_col;
    u16 cell_row;
    RoadmapTim *tim;
} RoadmapSprite;
typedef struct {
    u32 tag;
    u8 r0;
    u8 g0;
    volatile u8 b0;
    u8 code;
    s16 x0;
    s16 y0;
    u8 u0;
    u8 v0;
    u16 clut;
    s16 w;
    s16 h;
} SprtPacket;
s32 kaj_view_packet_used(void);
void SetSemiTrans(void *p, s32 abe);
void SetDrawMode(void *p, s32 dfe, s32 dtd, s32 tpage, void *tw);
void LoadImage(void *rect, s32 p);
typedef struct {
    u32 tag;
    u8 r0;
    u8 g0;
    volatile u8 b0;
    u8 code;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    s16 x2;
    s16 y2;
    s16 x3;
    s16 y3;
} PolyF4Packet;

void roadmap_init(void) {
    RoadMap *map = &roadmap_state;

    roadmap_state.mode = 0;
    map->zoomed = 0;
    map->part0 = sprite_find(0x405);
    map->part1 = sprite_find(0x406);
    map->part2 = sprite_find(0x407);
    if (map->part0 == NULL || map->part1 == NULL || map->part2 == NULL) {
        kaj_abend(5, "Road Map Parts not Found", "roadmap.c", 0x20);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8019A5D4", roadmap_shop_lines);

void roadmap_quit(void) {
    RoadMap *map = &roadmap_state;

    roadmap_state.mode = 0;
    map->zoomed = 0;
    map->part0[2] = 0;
    map->part1[2] = 0;
    map->part2[2] = 0;
    map->part0 = NULL;
    map->part1 = NULL;
    map->part2 = NULL;
}

u16 roadmap_get_state(void) {
    return roadmap_state.mode;
}

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_add_clipped_f3);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_add_clipped_g3);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_f3);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_g3);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_ft3);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_gt3);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_f4);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_g4);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_ft4);

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_gt4);

void *roadmap_add_sprite(RoadmapSprite *sprite, void *packet, u32 *ot_base) {
    ScreenLight *light = &screen_light;
    u8 *pkt;
    SprtPacket *sp;
    u32 *ot;
    u8 rgb[3];
    u8 u;
    s32 v;

    if ((u32)kaj_view_packet_used() > 0xAFF8) {
        return packet;
    }
    pkt = packet;
    sp = (SprtPacket *)pkt;
    ((u8 *)sp)[3] = 4;
    sp->code = 0x64;
    SetSemiTrans(sp, 1);
    sp->clut = sprite->tim->clut;
    if (light->fade_active != 0) {
        if ((player_status_player[0]->flags & 0x100) && sprite->id == 0x404) {
            sp->r0 = roadmap_sprite_colors[sprite->color].r;
            sp->g0 = roadmap_sprite_colors[sprite->color].g;
            sp->b0 = roadmap_sprite_colors[sprite->color].b;
        } else {
            rgb[0] = roadmap_sprite_colors[sprite->color].r * light->fade_level >> 12;
            rgb[1] = roadmap_sprite_colors[sprite->color].g * light->fade_level >> 12;
            rgb[2] = roadmap_sprite_colors[sprite->color].b * light->fade_level >> 12;
            sp->r0 = rgb[0];
            sp->g0 = rgb[1];
            sp->b0 = rgb[2];
        }
    } else {
        sp->r0 = roadmap_sprite_colors[sprite->color].r;
        sp->g0 = roadmap_sprite_colors[sprite->color].g;
        sp->b0 = roadmap_sprite_colors[sprite->color].b;
    }
    u = sprite->tim->u << sprite->tim->u_shift;
    v = sprite->tim->v;
    if (sprite->mode == 1) {
        u += sprite->cell_col * sprite->cell_w;
        v += sprite->cell_row * sprite->cell_h;
    }
    sp->u0 = u;
    sp->v0 = v;
    sp->x0 = sprite->x;
    sp->y0 = sprite->y;
    sp->w = sprite->cell_w;
    sp->h = sprite->cell_h;
    ot = ot_base + sprite->depth;
    *(u32 *)pkt = (*ot & 0xFFFFFF) | 0x04000000;
    *ot = (u32)pkt & 0xFFFFFF;
    pkt += 0x14;
    SetDrawMode(pkt, 0, 0, sprite->tim->tpage, 0);
    ot = ot_base + sprite->depth;
    *(u32 *)pkt = (*ot & 0xFFFFFF) | 0x02000000;
    *ot = (u32)pkt & 0xFFFFFF;
    pkt += 0xC;
    if (sprite->clut_dirty != 0) {
        LoadImage(sprite->tim->clut_rect, sprite->tim->clut_work);
        sprite->clut_dirty = 0;
    }
    return pkt;
}

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_flash);

void roadmap_init_draw(void) {
    RoadmapFlash *flash;

    roadmap_prim_handlers[0].handler = roadmap_draw_f3;
    roadmap_prim_handlers[1].handler = roadmap_draw_g3;
    roadmap_prim_handlers[2].handler = roadmap_draw_ft3;
    roadmap_prim_handlers[3].handler = roadmap_draw_gt3;
    roadmap_prim_handlers[4].handler = roadmap_draw_f4;
    roadmap_prim_handlers[5].handler = roadmap_draw_g4;
    roadmap_prim_handlers[6].handler = roadmap_draw_ft4;
    roadmap_prim_handlers[7].handler = roadmap_draw_gt4;
    roadmap_divpoly4.ndiv = 3;
    roadmap_divpoly3.ndiv = 3;
    roadmap_divpoly4.pih = 0x140;
    roadmap_divpoly3.pih = 0x140;
    roadmap_divpoly4.piv = 0xF0;
    roadmap_divpoly3.piv = 0xF0;
    screen_light.fade_level = 0x1000;
    screen_light.daylight_on = 0;
    screen_light.fog_on = 0;
    screen_light.fade_active = 0;
    screen_light.clip_mode = 0;
    screen_light.ot_bias = 3;
    screen_light.divide_pending = 0;
    screen_light.daylight_step = 0;
    screen_light.dark = 0;
    flash = &roadmap_flash;
    roadmap_flash.active = 0;
    flash->frames_left = 0;
    kaj_view_clear_vram();
    kaj_view_set_bg_color(0, 0, 0);
    flash->red = 0;
    flash->green = 0;
    flash->blue = 0;
    roadmap_ft_color_r = 0x60;
    roadmap_ft_color_g = 0x60;
    roadmap_ft_color_b = 0x60;
    InitClip(&roadmap_clip_buf, 0x150, 0x100, 0xE4, 0x6E, 0xFFFF);
}

void roadmap_draw_frame(u16 mode) {
    ScreenLight *light = &screen_light;
    ViewBuffer *view;
    s32 dusk;

    roadmap_brightness = light->fade_level;
    roadmap_daylight_level = light->daylight_step * 42 + light->daylight_step * 2 / 3 + 0x600;
    roadmap_frame_mode = mode;
    roadmap_draw_flags = 0;
    if (screen_light.daylight_on != 0 && light->dark == 1) {
        dusk = 0x3D - light->daylight_step;
        roadmap_ft_color_r = (dusk * 0x1334 >> 12) - 0x80;
        roadmap_ft_color_g = (dusk * 0x1334 >> 12) - 0x80;
        roadmap_ft_color_b = (dusk * 0x2CD >> 10) - 0x80;
        roadmap_draw_flags = 1;
    } else {
        roadmap_ft_color_r = 0x60;
        roadmap_ft_color_g = 0x60;
        roadmap_ft_color_b = 0x60;
    }
    if (light->fog_on != 0) {
        roadmap_draw_flags += 2;
    }
    if (light->fade_active != 0) {
        roadmap_draw_flags += 4;
    }
    view = kaj_view_begin_frame();
    sprite_draw_all(view);
    mod_npcrec_draw_all((s32)view);
    npc_draw_all((s32)view);
    roadmap_draw_flash(view);
    sprite_thing_draw_all(view);
    door_draw_all(view);
    mod_draw_player(view, mode);
    vehicle_draw(view);
    block_draw_all(view, mode);
    kaj_view_flip(view);
    if (kaj_system.pad_mode == 2) {
        kaj_system.pad_mode = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_sprite_frame);

void roadmap_start_flash(s32 red, s32 green, s32 blue, s32 duration) {
    RoadmapFlash *flash = &roadmap_flash;

    if (roadmap_flash.active == 0) {
        roadmap_flash.active = 1;
        flash->frames_left = duration;
        flash->red = red;
        flash->green = green;
        flash->blue = blue;
    }
}

PolyF4Packet *roadmap_add_flash_tile(RoadmapFlash *flash, PolyF4Packet *tile, u32 *ot) {
    ScreenLight *light = &screen_light;
    u8 rgb[3];

    if ((u32)kaj_view_packet_used() <= 0xAFFA) {
        ((u8 *)tile)[3] = 5;
        tile->code = 0x28;
        SetSemiTrans(tile, 1);
        tile->x0 = 0;
        tile->y0 = 0;
        tile->x1 = 0x13F;
        tile->y1 = 0;
        tile->x2 = 0;
        tile->y2 = 0xEF;
        tile->x3 = 0x13F;
        tile->y3 = 0xEF;
        if (light->fade_active != 0) {
            rgb[0] = flash->red * light->fade_level >> 12;
            rgb[1] = flash->green * light->fade_level >> 12;
            rgb[2] = flash->blue * light->fade_level >> 12;
            tile->r0 = rgb[0];
            tile->g0 = rgb[1];
            tile->b0 = rgb[2];
        } else {
            tile->r0 = flash->red;
            tile->g0 = flash->green;
            tile->b0 = flash->blue;
        }
        tile->tag = (ot[0x10] & 0xFFFFFF) | 0x05000000;
        ot[0x10] = (u32)tile & 0xFFFFFF;
        return tile + 1;
    }
}

void roadmap_shop_pick_weapons(ShopState *shop) {
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

void roadmap_shop_topic_menu(s16 open, s16 open_list) {
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

void roadmap_shop_say_reply(s16 building, s16 to_inventory, s16 alt_speaker, s16 reply) {
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

void roadmap_fade_screen_music(s16 fade_in) {
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

INCLUDE_RODATA("asm/nonmatchings/game/8019A5D4", roadmap_shop_ask_owner_line);

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

void roadmap_shop_close_topic(void) {
    roadmap_shop_topic_menu(0, 1);
}

s32 roadmap_shop_on_enter(ShopTriggerEvent *ev) {
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

s32 roadmap_shop_on_leave(ShopTriggerEvent *ev) {
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

s32 roadmap_cmp_weapon_level(ShopWeaponSlot *lhs, ShopWeaponSlot *rhs) {
    return lhs->req_level - rhs->req_level;
}
