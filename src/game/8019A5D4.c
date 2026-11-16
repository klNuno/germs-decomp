#include "common.h"
#include "game/types.h"

extern RoadMap roadmap_state;
typedef struct { s16 unk0; s16 unk2; u8 unk4; u8 unk5; u8 unk6; u8 unk7; } Unk_801DFF68;
Unk_801DFF68 roadmap_flash;
void roadmap_shop_topic_menu(s16 arg0, s16 arg1);
typedef struct { s32 unk0; s32 unk4; s32 unk8; u8 unkC; } Unk_801A20CC;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12[3];
    s16 *unk18;
    s16 *unk1C;
} Unk_801E1058;
extern BuildingState block_building_state;
extern Unk_801E1058 D_801E1058;
typedef struct { s16 unk0; s16 unk2; } Unk_801A216C;
extern s32 roadmap_shop_exit_points[];
void mail_goto_twn(s32 a, s32 b, s32 c, s16 d, s16 e);
extern ScreenLight screen_light;
typedef struct { u8 unk0[0x18]; void (*unk18)(); s32 unk1C; } Unk_801E2DB0;
extern Unk_801E2DB0 roadmap_prim_handlers[8];
typedef struct { s32 unk0; s32 unk4; s32 unk8; } Unk_801E07D0;
extern Unk_801E07D0 roadmap_divpoly3;
extern Unk_801E07D0 roadmap_divpoly4;
typedef struct { u8 unk0[0x10]; } Unk_801E0D30;
extern Unk_801E0D30 roadmap_clip_buf;
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
void kaj_view_set_bg_color(u8 arg0, u8 arg1, u8 arg2);
void InitClip(Unk_801E0D30 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern KajSystem kaj_system;
s16 D_801DFF5C;
s32 roadmap_daylight_level;
s32 roadmap_brightness;
s16 D_801DFF74;
ViewBuffer *kaj_view_begin_frame(void);
void sprite_draw_all(ViewBuffer *arg0);
void mod_npcrec_draw_all(s32 arg0);
void npc_draw_all(s32 arg0);
void roadmap_draw_flash(ViewBuffer *arg0);
void sprite_thing_draw_all(ViewBuffer *arg0);
void door_draw_all(ViewBuffer *arg0);
void mod_draw_player(ViewBuffer *arg0, s32 arg1);
void vehicle_draw(ViewBuffer *arg0);
void block_draw_all(ViewBuffer *arg0, s32 arg1);
void kaj_view_flip(ViewBuffer *arg0);
typedef struct Unk_80188FEC {
    u16 unk0;
    u8 unk2[2];
    char unk4[0x2C];
    u16 unk30;
    u8 unk32[0x2E];
} Unk_80188FEC;
typedef struct { u8 unk0[0xE]; s16 unkE; } Unk_801A0820;
Unk_80188FEC *effect_weapon_find(s16 arg0);
s32 roadmap_cmp_weapon_level(Unk_801A216C *arg0, Unk_801A216C *arg1);
void qsort(void *base, s32 nel, s32 width, s32 (*cmp)());
extern s16 D_801E0712[];
extern s16 roadmap_shop_weapons[];
extern SceneTables object_scene_tables[];
void SsSepSetVol(s16 access_num, s16 seq_num, s16 voll, s16 volr);
void mail_step_frame(u16 a, s16 b, s16 c);
extern Player *player_status_player[];
s16 D_801DFF78;
extern char D_801715C4[];
s16 mail_menu_get_state(void);
s32 mail_menu_close(void);
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void text_close(void);
/* Local view of GameVars: this unit reads 0x14-0x92 as scalars, the shared type has a u16 array there. */
typedef struct {
    u8 unk0[0x14];
    s16 unk14;
    u8 unk16[0x4A];
    s16 unk60;
    u8 unk62[0x1A];
    u16 unk7C;
    u8 unk7E[2];
    s16 unk80;
    u8 unk82[0x10];
    u16 unk92;
    u8 unk94[0x164];
    u16 unk1F8;
} GameVars_u8019A5D4;
void roadmap_shop_pick_weapons(Unk_801A0820 *arg0);
extern GameVars_u8019A5D4 action_vars;
s32 mail_menu_open(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i);
extern s16 D_801D79F0[];
extern s16 D_801D79F8[];
extern s16 D_801D7A00[];
extern s16 D_801D7A08[];
extern s16 D_801D7A10[];
extern s16 D_801D7A22[];
extern s16 D_801D7A34[];
extern s16 D_801D7A48[];
extern s16 D_801D7A50[];
extern s16 D_801D7A58[];
extern s16 D_801D7A60[];
extern s16 D_801D7A74[];
extern s16 D_801D7AEC[];
extern s16 D_801D7AF8[];
extern s16 D_801D7B04[];
extern s16 D_801D7B10[];
extern s16 D_801D7B1C[];
extern s16 D_801D7B28[];
extern s16 D_801DFD74[];
typedef struct { char *unk0; char *unk4; char *unk8; } Unk_801D7B34;
void roadmap_fade_screen_music(s16 arg0);
extern PlayerStatus player_status;
extern Unk_801D7B34 roadmap_shop_weapon_advice[];
ItemRecord *effect_item_find(s16 arg0);
void text_show_timed(s16 arg0, s16 arg1, char *arg2, s16 arg3, s32 arg4);
s16 effect_item_use(PlayerStatus *a, s16 b, s16 c, s16 d, s16 e);
void mail_wait(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void player_reset_triggers(s16 arg0);
void *memset(void *dst, s32 c, u32 n);
int sprintf(char *buf, const char *fmt, ...);
s16 *sprite_find(s32 arg0);
void kaj_abend(s32 a, char *b, char *c, s32 d);
extern s16 D_801D7A92[];
extern s16 D_801D7AB0[];
extern s16 D_801D7ACE[];
extern s16 D_801D7B20[];
extern char *D_801D7B24[];
void sprite_set_visible(s32 arg0, s32 arg1);
void sprite_fill_clut(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void sprite_set_clut_entry(s32 arg0, s32 arg1, s32 arg2);
void roadmap_shop_say_reply(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s16 mail_menu_move(s16 a);
void sound_se_play(s32 arg0);
s16 effect_inventory_has_room(s32 arg0);
void mail_menu_set_list(s32 arg0, s16 *arg1);
s16 mail_menu_get_entry(s16 arg0);
s16 player_set_item(s16 arg0, s32 arg1, s32 arg2);
s16 player_set_weapon(s16 arg0, s32 arg1, s32 arg2);
extern s32 (*D_801DFEE4)(Unk_801A20CC *arg0);
extern s32 (*D_801DFEE0)(Unk_801A20CC *arg0);
void door_set_visible(u16 arg0, s16 arg1);
s32 roadmap_shop_on_enter(Unk_801A20CC *arg0);
s32 roadmap_shop_on_leave(Unk_801A20CC *arg0);
typedef struct { u8 unk0; u8 unk1; u8 unk2; u8 unk3; } Unk_801DFD6C;
extern Unk_801DFD6C roadmap_sprite_colors[2];
typedef struct {
    u8 unk0[8];
    s32 unk8[2];
    s16 unk10;
    u16 unk12;
    s16 unk14;
    u8 unk16[2];
    u16 unk18;
    u16 unk1A;
    s32 unk1C;
    s32 unk20;
} Unk_8019FDD8_1C;
typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4[2];
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u16 unk10;
    u16 unk12;
    u8 unk14[4];
    u16 unk18;
    u16 unk1A;
    Unk_8019FDD8_1C *unk1C;
} Unk_8019FDD8;
typedef struct {
    u32 unk0;
    u8 unk4;
    u8 unk5;
    volatile u8 unk6;
    u8 unk7;
    s16 unk8;
    s16 unkA;
    u8 unkC;
    u8 unkD;
    u16 unkE;
    s16 unk10;
    s16 unk12;
} Unk_8019FDD8_P;
s32 kaj_view_packet_used(void);
void SetSemiTrans(void *p, s32 abe);
void SetDrawMode(void *p, s32 dfe, s32 dtd, s32 tpage, void *tw);
void LoadImage(void *rect, s32 p);
typedef struct {
    u32 unk0;
    u8 unk4;
    u8 unk5;
    volatile u8 unk6;
    u8 unk7;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
} Unk_801A06C0;

void roadmap_init(void) {
    RoadMap *map = &roadmap_state;

    roadmap_state.mode = 0;
    map->unk2 = 0;
    map->part0 = sprite_find(0x405);
    map->part1 = sprite_find(0x406);
    map->part2 = sprite_find(0x407);
    if (map->part0 == NULL || map->part1 == NULL || map->part2 == NULL) {
        kaj_abend(5, "Road Map Parts not Found", "roadmap.c", 0x20);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8019A5D4", D_80171048);

void roadmap_quit(void) {
    RoadMap *map = &roadmap_state;

    roadmap_state.mode = 0;
    map->unk2 = 0;
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

void *roadmap_add_sprite(Unk_8019FDD8 *sprite, void *packet, u32 *ot_base) {
    ScreenLight *light = &screen_light;
    u8 *pkt;
    Unk_8019FDD8_P *sp;
    u32 *ot;
    u8 rgb[3];
    u8 u;
    s32 v;

    if ((u32)kaj_view_packet_used() > 0xAFF8) {
        return packet;
    }
    pkt = packet;
    sp = (Unk_8019FDD8_P *)pkt;
    ((u8 *)sp)[3] = 4;
    sp->unk7 = 0x64;
    SetSemiTrans(sp, 1);
    sp->unkE = sprite->unk1C->unk18;
    if (light->fade_active != 0) {
        if ((player_status_player[0]->flags & 0x100) && sprite->unk0 == 0x404) {
            sp->unk4 = roadmap_sprite_colors[sprite->unk8].unk0;
            sp->unk5 = roadmap_sprite_colors[sprite->unk8].unk1;
            sp->unk6 = roadmap_sprite_colors[sprite->unk8].unk2;
        } else {
            rgb[0] = roadmap_sprite_colors[sprite->unk8].unk0 * light->fade_level >> 12;
            rgb[1] = roadmap_sprite_colors[sprite->unk8].unk1 * light->fade_level >> 12;
            rgb[2] = roadmap_sprite_colors[sprite->unk8].unk2 * light->fade_level >> 12;
            sp->unk4 = rgb[0];
            sp->unk5 = rgb[1];
            sp->unk6 = rgb[2];
        }
    } else {
        sp->unk4 = roadmap_sprite_colors[sprite->unk8].unk0;
        sp->unk5 = roadmap_sprite_colors[sprite->unk8].unk1;
        sp->unk6 = roadmap_sprite_colors[sprite->unk8].unk2;
    }
    u = sprite->unk1C->unk10 << sprite->unk1C->unk14;
    v = sprite->unk1C->unk12;
    if (sprite->unk2 == 1) {
        u += sprite->unk18 * sprite->unk10;
        v += sprite->unk1A * sprite->unk12;
    }
    sp->unkC = u;
    sp->unkD = v;
    sp->unk8 = sprite->unkA;
    sp->unkA = sprite->unkC;
    sp->unk10 = sprite->unk10;
    sp->unk12 = sprite->unk12;
    ot = ot_base + sprite->unkE;
    *(u32 *)pkt = (*ot & 0xFFFFFF) | 0x04000000;
    *ot = (u32)pkt & 0xFFFFFF;
    pkt += 0x14;
    SetDrawMode(pkt, 0, 0, sprite->unk1C->unk1A, 0);
    ot = ot_base + sprite->unkE;
    *(u32 *)pkt = (*ot & 0xFFFFFF) | 0x02000000;
    *ot = (u32)pkt & 0xFFFFFF;
    pkt += 0xC;
    if (sprite->unk6 != 0) {
        LoadImage(sprite->unk1C->unk8, sprite->unk1C->unk20);
        sprite->unk6 = 0;
    }
    return pkt;
}

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_flash);

void roadmap_init_draw(void) {
    Unk_801DFF68 *flash;

    roadmap_prim_handlers[0].unk18 = roadmap_draw_f3;
    roadmap_prim_handlers[1].unk18 = roadmap_draw_g3;
    roadmap_prim_handlers[2].unk18 = roadmap_draw_ft3;
    roadmap_prim_handlers[3].unk18 = roadmap_draw_gt3;
    roadmap_prim_handlers[4].unk18 = roadmap_draw_f4;
    roadmap_prim_handlers[5].unk18 = roadmap_draw_g4;
    roadmap_prim_handlers[6].unk18 = roadmap_draw_ft4;
    roadmap_prim_handlers[7].unk18 = roadmap_draw_gt4;
    roadmap_divpoly4.unk0 = 3;
    roadmap_divpoly3.unk0 = 3;
    roadmap_divpoly4.unk4 = 0x140;
    roadmap_divpoly3.unk4 = 0x140;
    roadmap_divpoly4.unk8 = 0xF0;
    roadmap_divpoly3.unk8 = 0xF0;
    screen_light.fade_level = 0x1000;
    screen_light.unk0[0] = 0;
    screen_light.unk0[2] = 0;
    screen_light.fade_active = 0;
    screen_light.unk8[1] = 0;
    screen_light.unk8[2] = 3;
    screen_light.unk0[1] = 0;
    screen_light.unk8[0] = 0;
    screen_light.dark = 0;
    flash = &roadmap_flash;
    roadmap_flash.unk0 = 0;
    flash->unk2 = 0;
    kaj_view_clear_vram();
    kaj_view_set_bg_color(0, 0, 0);
    flash->unk4 = 0;
    flash->unk5 = 0;
    flash->unk6 = 0;
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
    roadmap_daylight_level = light->unk8[0] * 42 + light->unk8[0] * 2 / 3 + 0x600;
    D_801DFF5C = mode;
    D_801DFF74 = 0;
    if (screen_light.unk0[0] != 0 && light->dark == 1) {
        dusk = 0x3D - light->unk8[0];
        roadmap_ft_color_r = (dusk * 0x1334 >> 12) - 0x80;
        roadmap_ft_color_g = (dusk * 0x1334 >> 12) - 0x80;
        roadmap_ft_color_b = (dusk * 0x2CD >> 10) - 0x80;
        D_801DFF74 = 1;
    } else {
        roadmap_ft_color_r = 0x60;
        roadmap_ft_color_g = 0x60;
        roadmap_ft_color_b = 0x60;
    }
    if (light->unk0[2] != 0) {
        D_801DFF74 += 2;
    }
    if (light->fade_active != 0) {
        D_801DFF74 += 4;
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
    Unk_801DFF68 *flash = &roadmap_flash;

    if (roadmap_flash.unk0 == 0) {
        roadmap_flash.unk0 = 1;
        flash->unk2 = duration;
        flash->unk4 = red;
        flash->unk5 = green;
        flash->unk6 = blue;
    }
}

Unk_801A06C0 *roadmap_add_flash_tile(Unk_801DFF68 *flash, Unk_801A06C0 *tile, u32 *ot) {
    ScreenLight *light = &screen_light;
    u8 rgb[3];

    if ((u32)kaj_view_packet_used() <= 0xAFFA) {
        ((u8 *)tile)[3] = 5;
        tile->unk7 = 0x28;
        SetSemiTrans(tile, 1);
        tile->unk8 = 0;
        tile->unkA = 0;
        tile->unkC = 0x13F;
        tile->unkE = 0;
        tile->unk10 = 0;
        tile->unk12 = 0xEF;
        tile->unk14 = 0x13F;
        tile->unk16 = 0xEF;
        if (light->fade_active != 0) {
            rgb[0] = flash->unk4 * light->fade_level >> 12;
            rgb[1] = flash->unk5 * light->fade_level >> 12;
            rgb[2] = flash->unk6 * light->fade_level >> 12;
            tile->unk4 = rgb[0];
            tile->unk5 = rgb[1];
            tile->unk6 = rgb[2];
        } else {
            tile->unk4 = flash->unk4;
            tile->unk5 = flash->unk5;
            tile->unk6 = flash->unk6;
        }
        tile->unk0 = (ot[0x10] & 0xFFFFFF) | 0x05000000;
        ot[0x10] = (u32)tile & 0xFFFFFF;
        return tile + 1;
    }
}

void roadmap_shop_pick_weapons(Unk_801A0820 *shop) {
    Unk_801A216C tab[12];
    Unk_80188FEC *weapon;
    s32 i;
    s32 j;
    s32 end;
    s32 start;

    shop->unkE = D_801E0712[0] / 20;
    if (shop->unkE > 2) {
        shop->unkE = 2;
    }
    j = 0;
    for (i = 1; i < 13; i++) {
        if (i != 10) {
            weapon = effect_weapon_find(i);
            if (weapon != NULL) {
                tab[j].unk0 = i;
                tab[j].unk2 = weapon->unk30;
            } else {
                tab[j].unk0 = i;
                tab[j].unk2 = 100;
            }
            j++;
        }
    }
    qsort(tab, 11, 4, roadmap_cmp_weapon_level);
    switch (shop->unkE) {
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
        roadmap_shop_weapons[j] = tab[i].unk0;
    }
}

void roadmap_shop_topic_menu(s16 open, s16 open_list) {
    Unk_801E1058 *shop = &D_801E1058;
    s32 sprite;
    s16 icon_sprite;
    s16 count;
    s32 rows;
    s16 first_entry;
    s16 color;
    s16 cursor_color;

    if (open != 0) {
        D_801DFF78 = 0;
        shop->unk2 = 3;
        sprite_set_visible(3, 1);
        sprite_fill_clut(3, 4, 6, 0x2969);
        sprite_set_clut_entry(3, 4, 0x2BFF);
        text_show(D_801D7B24[0], 3, -1, 0, -1, 0, 1);
    } else {
        sprite_set_visible(3, 0);
        text_close();
        if (open_list == 0) {
            D_801E1058.unk0 = 0;
            shop->unk2 = -1;
        } else {
            if (D_801E1058.unk0 == 0) {
                D_801E1058.unk0 = 1;
            }
            sprite = 0x40B;
            icon_sprite = 0x40C;
            rows = 6;
            first_entry = 4;
            color = 0x2969;
            cursor_color = 0x2BFF;
            shop->unk1C = D_801D7B20;
            shop->unk2 = 0;
            switch (D_801DFF78) {
            case 0:
                count = 0xE;
                shop->unk18 = D_801D7A92;
                break;
            case 1:
                count = 0xF;
                shop->unk18 = D_801D7AB0;
                break;
            case 2:
                sprite = 4;
                icon_sprite = -1;
                count = 4;
                rows = 4;
                shop->unk18 = D_801D7ACE;
                break;
            }
            mail_menu_open(1, sprite, icon_sprite, count, rows, shop->unk18, first_entry, color, cursor_color);
        }
    }
}

void roadmap_shop_say_reply(s16 building, s16 arg1, s16 arg2, s16 reply) {
    Player *player = player_status_player[0];
    s16 menu_state = mail_menu_get_state();
    s16 topic;

    if (menu_state == 1) {
        if (reply == 0) {
            if (arg1 != 0) {
                if (building == 4) {
                    if (arg2 != 0) {
                        /* " 6どうぞ、楽しんで食べてね" */
                        text_show(" 6\202\307\202\244\202\274\201\101\212\171\202\265\202\361\202\305\220\110\202\327\202\304\202\313", 3, -1, 0, -1, 0, menu_state);
                    } else {
                        /* " 2どうぞ、こちらになります" */
                        text_show(" 2\202\307\202\244\202\274\201\101\202\261\202\277\202\347\202\311\202\310\202\350\202\334\202\267", 3, -1, 0, -1, 0, menu_state);
                    }
                } else if (building == 5) {
                    /* " 2早めに食べてくださいね" */
                    text_show(" 2\221\201\202\337\202\311\220\110\202\327\202\304\202\255\202\276\202\263\202\242\202\313", 3, -1, 0, -1, 0, menu_state);
                }
            } else {
                if (building == 4) {
                    if (arg2 != 0) {
                        /* " 6どうぞ、楽しんで食べてね" */
                        text_show(" 6\202\307\202\244\202\274\201\101\212\171\202\265\202\361\202\305\220\110\202\327\202\304\202\313", 3, -1, 0, -1, 0, menu_state);
                    } else {
                        /* " 2どうぞ、こちらになります" */
                        text_show(" 2\202\307\202\244\202\274\201\101\202\261\202\277\202\347\202\311\202\310\202\350\202\334\202\267", 3, -1, 0, -1, 0, menu_state);
                    }
                } else if (building == 5) {
                    /* " 2どうぞ、おいしいですよ" */
                    text_show(" 2\202\307\202\244\202\274\201\101\202\250\202\242\202\265\202\242\202\305\202\267\202\346", 3, -1, 0, -1, 0, menu_state);
                }
            }
        } else if (reply == 2) {
            if (arg2 != 0) {
                /* " 6これ以上持てないわよ" */
                text_show(" 6\202\261\202\352\210\310\217\343\216\235\202\304\202\310\202\242\202\355\202\346", 3, -1, 0, -1, 0, 4);
            } else {
                /* " 2これ以上, お持ちになれないようですよ" */
                text_show(" 2\202\261\202\352\210\310\217\343, \202\250\216\235\202\277\202\311\202\310\202\352\202\310\202\242\202\346\202\244\202\305\202\267\202\346", 3, -1, 0, -1, 0, 4);
            }
        } else if (reply == menu_state) {
            if (building == 8) {
                topic = D_801DFF78;
                if (topic == -1) {
                    if (player->flags & 0x100) {
                        player->flags &= 0xFEFF;
                    }
                    text_show(D_801715C4, 3, -1, 0, topic, 0, reply);
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
    BgmSep *bgm = object_scene_tables[0].unk0;
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

INCLUDE_RODATA("asm/nonmatchings/game/8019A5D4", D_801715C4);

s16 roadmap_shop_finish(s16 building) {
    PlayerStatus *status = &player_status;
    Unk_801E1058 *shop = &D_801E1058;
    GameVars_u8019A5D4 *game = &action_vars;
    Player *player = status->player;
    char buf[0x80];
    Unk_801D7B34 *advice;
    Unk_80188FEC *weapon;
    ItemRecord *item;
    char *line;
    s32 i;
    s16 found = 0;
    s16 ret;
    s16 v;
    s32 j;
    s16 m;
    Unk_801E1058 *shop2;

    switch (building) {
    case 7:
        if (shop->unk12[0] >= 0) {
            advice = &roadmap_shop_weapon_advice[shop->unkE];
            weapon = effect_weapon_find(shop->unk12[0]);
            if (weapon != NULL) {
                if ((s16)weapon->unk30 == status->level) {
                    line = advice->unk4;
                } else if ((s16)weapon->unk30 < status->level) {
                    line = advice->unk8;
                } else {
                    line = advice->unk0;
                }
                text_show_timed(1, 1, line, 1, 2);
                memset(buf, 0, 0x80);
                sprintf(buf, " 8%s1, \202\360\216\363\202\257\216\346\202\301\202\275", weapon->unk4);
                text_show_timed(1, 1, buf, 2, 2);
            }
        }
        break;
    case 8:
        ret = -1;
        if (shop->unk4 != 0) {
            if (shop->unk12[0] >= 0) {
                item = effect_item_find(shop->unk12[0] + 100);
                if (item != NULL) {
                    memset(buf, 0, 0x80);
                    sprintf(buf, " 8%s2\202\314\222n\220\175\202\313", item->name);
                    text_show_timed(1, 1, buf, 2, 2);
                    text_show(D_801715C4, 3, -1, 0, -1, 0, 1);
                    if (player->flags & 0x100) {
                        player->flags &= 0xFEFF;
                    }
                }
            }
        } else if (shop->unk12[0] >= 0) {
            ret = shop->unk12[0];
            if (D_801DFF78 == 0) {
                ret += 10;
            } else if (D_801DFF78 == 1) {
                ret += 30;
            }
        }
        break;
    case 9:
        if (shop->unk12[0] >= 0) {
            item = effect_item_find(shop->unk12[0]);
            if (item != NULL) {
                memset(buf, 0, 0x80);
                sprintf(buf, " 8%s1\202\360\221I\221\360\202\265\202\275", item->name);
                text_show_timed(1, 1, buf, 2, 1);
                roadmap_fade_screen_music(0);
                effect_item_use(status, 1, shop->unk12[0], 0, 0);
                mail_wait(1, 1, 1, 2);
                roadmap_fade_screen_music(1);
                mail_wait(1, 1, 1, 2);
                text_show(" 2\202\250\224\346\202\352\227l\202\305\202\265\202\275", 3, -1, 0, -1, 0, 1);
            }
        }
        break;
    default:
        if (shop->unk4 != 0) {
            for (i = 0; i < 3; i++) {
                if (shop->unk12[i] >= 0) {
                    item = effect_item_find(shop->unk12[i]);
                    if (item != NULL) {
                        memset(buf, 0, 0x80);
                        sprintf(buf, " 8%s1, \202\360\216\363\202\257\216\346\202\301\202\275", item->name);
                        text_show_timed(1, 1, buf, 2, 2);
                    }
                }
            }
            if (building == 4) {
                if (shop->unk6 != 0) {
                    text_show(" 6\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275, \203N\203b\203N\203b\203N", 3, -1, 0, -1, 0, 1);
                } else {
                    text_show(" 2\202\307\202\244\202\340\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275", 3, -1, 0, -1, 0, 1);
                }
            } else if (building == 5) {
                text_show(" 2\202\334\202\275\201A\202\346\202\353\202\265\202\255\202\250\212\350\202\242\202\265\202\334\202\267", 3, -1, 0, -1, 0, 1);
            }
        } else {
            if (status->energy == 0xFF && shop->unkE == 0) {
                shop->unkE = 1;
            }
            for (i = 0; i < 3; i++) {
                if (shop->unk12[i] >= 0) {
                    if (!found) {
                        found = 1;
                    }
                    v = effect_item_use(status, 1, shop->unk12[i], shop->unkE, 0);
                    if (v >= 0) if (v != 0) {
                        shop->unkE = 1;
                    }
                }
            }
            if (found) {
                game->unk92++;
            }
            if (building == 4) {
                if (shop->unk6 != 0) {
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
    shop2 = &D_801E1058;
    D_801E1058.unk0 = 0;
    shop2->unk2 = -1;
    shop2->unk4 = 0;
    shop2->unk6 = 0;
    shop2->unk8 = 0;
    shop2->unkA = 0;
    shop2->unkC = 0;
    shop2->unkE = 0;
    shop2->unk10 = 0;
    m = -1;
    for (j = 2; j >= 0; j--) {
        shop2->unk12[j] = m;
    }
    shop2->unk18 = NULL;
    shop2->unk1C = NULL;
    if (building == 3 || building == 6) {
        player_reset_triggers(2);
    }
    return ret;
}

s16 roadmap_shop_update_input(PlayerStatus *status) {
    Unk_801E1058 *shop = &D_801E1058;
    BuildingState *bstate = &block_building_state;
    Player *player = status->player;
    s16 sel;

    if (D_801E1058.unk0 == 0) {
        return 0;
    }
    sel = mail_menu_get_state();
    if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
        if (shop->unk2 == 3 && sel == 0) {
            sound_se_play(0x11);
            roadmap_shop_topic_menu(0, 1);
            return 1;
        } else if (shop->unk2 == 0 && sel == 1) {
            sound_se_play(0x11);
            sel = mail_menu_get_entry(shop->unk10);
            if (shop->unk4 != 0) {
                switch (bstate->building) {
                case 7:
                    if (effect_inventory_has_room(4) != 0) {
                        if (player_set_weapon(sel, 1, 0) != 0) {
                            shop->unk12[0] = sel;
                        }
                    } else {
                        roadmap_shop_say_reply(bstate->building, shop->unk4, shop->unk6, 2);
                        return 1;
                    }
                    break;
                case 8:
                    shop->unk12[0] = sel;
                    player_set_item(sel + 100, 2, 1);
                    roadmap_shop_say_reply(bstate->building, shop->unk4, shop->unk6, 0);
                    return 1;
                default:
                    if (effect_inventory_has_room(0) != 0) {
                        if (player_set_item(sel, 0, 1) != 0) {
                            shop->unk12[0] = sel;
                        }
                    } else {
                        roadmap_shop_say_reply(bstate->building, shop->unk4, shop->unk6, 2);
                        return 1;
                    }
                    break;
                }
            } else {
                shop->unk12[0] = sel;
            }
            if (shop->unkA != 0) {
                shop->unk2 = 1;
                shop->unk10 = 0;
                text_show(((char **)shop->unk1C)[1], 3, -1, 0, -1, 0, 1);
                mail_menu_set_list(4, shop->unk18 + 4);
                return 1;
            }
        } else if (shop->unk2 == 1 && sel == 1) {
            sound_se_play(0x11);
            sel = mail_menu_get_entry(shop->unk10);
            if (shop->unk4 != 0) {
                if (effect_inventory_has_room(0) != 0) {
                    if (player_set_item(sel, 0, 1) != 0) {
                        shop->unk12[1] = sel;
                    }
                } else {
                    roadmap_shop_say_reply(bstate->building, shop->unk4, shop->unk6, 2);
                    return 1;
                }
            } else {
                shop->unk12[1] = sel;
            }
            if (shop->unkC != 0) {
                shop->unk2 = 2;
                text_show(((char **)shop->unk1C)[2], 3, -1, 0, -1, 0, 1);
                return 1;
            }
        } else if (shop->unk2 == 2 && sel == 1) {
            sound_se_play(0x11);
            sel = shop->unk18[8];
            if (shop->unk4 != 0) {
                if (effect_inventory_has_room(0) != 0) {
                    if (player_set_item(sel, 0, 1) != 0) {
                        shop->unk12[2] = sel;
                    }
                } else {
                    roadmap_shop_say_reply(bstate->building, shop->unk4, shop->unk6, 2);
                    return 1;
                }
            } else {
                shop->unk12[2] = sel;
            }
        } else {
            return 1;
        }
        roadmap_shop_say_reply(bstate->building, shop->unk4, shop->unk6, 0);
    } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
        sound_se_play(8);
        if (shop->unk2 == 3 && sel == 0) {
            roadmap_shop_topic_menu(0, 0);
            /* " 2話が聞きたくなったら, いつでもおいで" */
            text_show_timed(1, 1, " 2\230b\202\252\225\267\202\253\202\275\202\255\202\310\202\301\202\275\202\347, \202\242\202\302\202\305\202\340\202\250\202\242\202\305", 1, 1);
            if (player->flags & 0x100) {
                player->flags &= 0xFEFF;
            }
        } else if (shop->unk2 == 0 && sel == 1) {
            roadmap_shop_say_reply(bstate->building, shop->unk4, shop->unk6, 1);
            return 1;
        } else if (shop->unk2 == 1 && sel == 1 && shop->unkC != 0) {
            shop->unk2 = 2;
            text_show(((char **)shop->unk1C)[2], 3, -1, 0, -1, 0, sel);
        } else {
            roadmap_shop_say_reply(bstate->building, shop->unk4, shop->unk6, 0);
            return 1;
        }
    } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
        if (sel == 0) {
            if (shop->unk2 == 3) {
                sound_se_play(0xF);
                if (--D_801DFF78 < 0) {
                    D_801DFF78 = 2;
                }
                sprite_fill_clut(3, 4, 6, 0x2969);
                sprite_set_clut_entry(3, D_801DFF78 + 4, 0x2BFF);
            }
        } else if (sel == 1) {
            if (shop->unk2 != 2) {
                shop->unk10 = mail_menu_move(1);
            }
        }
    } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
        if (sel == 0) {
            if (shop->unk2 == 3) {
                sound_se_play(0xF);
                if (++D_801DFF78 >= 3) {
                    D_801DFF78 = 0;
                }
                sprite_fill_clut(3, 4, 6, 0x2969);
                sprite_set_clut_entry(3, D_801DFF78 + 4, 0x2BFF);
            }
        } else if (sel == 1) {
            if (shop->unk2 != 2) {
                shop->unk10 = mail_menu_move(0);
            }
        }
        return 1;
    }
    return 1;
}

s16 roadmap_shop_open_menu(s16 building, s32 trigger) {
    Player *player = player_status_player[0];
    GameVars_u8019A5D4 *game = &action_vars;
    Unk_801E1058 *shop = &D_801E1058;
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
    D_801E1058.unk0 = 1;
    shop->unk2 = 0;
    shop->unk6 = 0;
    shop->unkA = 0;
    shop->unkC = 0;
    shop->unkE = 0;
    shop->unk10 = 0;
    m = -1;
    for (j = 2; j >= 0; j--) {
        shop->unk12[j] = m;
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
        if (game->unk14 == 2000) {
            shop->unk6 = 1;
            shop->unk18 = D_801D7A08;
        } else if (game->unk1F8 >= 8 && game->unk1F8 < 10) {
            shop->unk18 = D_801D79F0;
        } else if (game->unk1F8 >= 10 && game->unk1F8 < 14) {
            shop->unk18 = D_801D79F8;
        } else {
            shop->unk18 = D_801D7A00;
        }
        shop->unk1C = D_801D7AEC;
        break;
    case 4:
        if (game->unk14 == 1000) {
            shop->unk18 = D_801D7A10;
            shop->unk1C = D_801D7AF8;
        } else if (game->unk14 == 2000) {
            shop->unk6 = 1;
            shop->unk18 = D_801D7A22;
            shop->unk1C = D_801D7B04;
        } else if (game->unk80 != 0) {
            if (game->unk60 != 0 || !(game->unk1F8 >= 8 && game->unk1F8 < 14)) {
                shop->unk18 = D_801D7A10;
                shop->unk1C = D_801D7AF8;
            } else {
                shop->unk6 = 1;
                shop->unk18 = D_801D7A22;
                shop->unk1C = D_801D7B04;
            }
        } else {
            if (game->unk60 != 0 || (game->unk1F8 >= 8 && game->unk1F8 < 14)) {
                shop->unk18 = D_801D7A10;
                shop->unk1C = D_801D7AF8;
            } else {
                shop->unk6 = 1;
                shop->unk18 = D_801D7A22;
                shop->unk1C = D_801D7B04;
            }
        }
        shop->unkA = 1;
        shop->unkC = 1;
        break;
    case 5:
        shop->unk1C = D_801D7B10;
        shop->unk18 = D_801D7A34;
        shop->unkA = 1;
        shop->unkC = 1;
        break;
    case 6:
        shop->unk1C = D_801D7AEC;
        if (game->unk14 == 2000) {
            shop->unk6 = 1;
            shop->unk18 = D_801D7A60;
        } else if (game->unk1F8 >= 11 && game->unk1F8 < 14) {
            shop->unk18 = D_801D7A48;
        } else if (game->unk1F8 >= 14 && game->unk1F8 < 17) {
            shop->unk18 = D_801D7A50;
        } else {
            shop->unk18 = D_801D7A58;
        }
        break;
    case 7:
        roadmap_shop_pick_weapons((Unk_801A0820 *)shop);
        sprite = 0x40B;
        icon_sprite = 0x402;
        count = 6;
        rows = count;
        first_entry = 4;
        color = 0x2969;
        cursor_color = 0x2BFF;
        shop->unk4 = 1;
        shop->unk1C = D_801D7AEC;
        shop->unk18 = roadmap_shop_weapons;
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
        D_801DFF78 = -1;
        shop->unk1C = D_801D7B1C;
        shop->unk4 = 1;
        shop->unk18 = D_801D7A74;
        break;
    case 9:
        count = 3;
        rows = count;
        shop->unk1C = D_801D7B28;
        shop->unk18 = D_801DFD74;
        break;
    }
    return mail_menu_open(1, sprite, icon_sprite, count, rows, shop->unk18, first_entry, color, cursor_color);
fail:
    roadmap_shop_topic_menu(1, 0);
    return 1;
}

void roadmap_shop_init(s16 building) {
    GameVars_u8019A5D4 *game = &action_vars;
    Unk_801E1058 *shop = &D_801E1058;
    s32 door;
    s32 j;

    D_801E1058.unk0 = 0;
    shop->unk2 = -1;
    shop->unk4 = 0;
    shop->unk6 = 0;
    shop->unk8 = 0;
    shop->unkA = 0;
    shop->unkC = 0;
    shop->unkE = 0;
    shop->unk10 = 0;
    for (j = 0; j < 3; j++) {
        shop->unk12[j] = -1;
    }
    shop->unk18 = 0;
    shop->unk1C = 0;
    game->unk1F8 = game->unk7C;
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
    D_801DFEE4 = roadmap_shop_on_enter;
    D_801DFEE0 = roadmap_shop_on_leave;
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

s32 roadmap_shop_on_enter(Unk_801A20CC *ev) {
    Unk_801E1058 *shop = &D_801E1058;

    if (ev->unk8 == 0x30) {
        u32 trigger = ev->unkC;

        if (block_building_state.building == 3) {
            if (trigger < 11) {
                shop->unk8 = 1;
            }
        } else if (block_building_state.building == 6) {
            if (trigger < 6) {
                shop->unk8 = 1;
            }
        }
    }
    return 0;
}

s32 roadmap_shop_on_leave(Unk_801A20CC *ev) {
    Unk_801E1058 *shop = &D_801E1058;

    if (ev->unk8 == 0x30) {
        u32 trigger = ev->unkC;

        if (block_building_state.building == 3) {
            if (trigger < 11) {
                shop->unk8 = 0;
            }
        } else if (block_building_state.building == 6) {
            if (trigger < 6) {
                shop->unk8 = 0;
            }
        }
    }
    return 0;
}

s32 roadmap_cmp_weapon_level(Unk_801A216C *lhs, Unk_801A216C *rhs) {
    return lhs->unk2 - rhs->unk2;
}
