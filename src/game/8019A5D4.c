#include "common.h"
#include "game/types.h"

extern Unk_801E07C0 D_801E07C0;
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
extern Unk_801DFE68 D_801DFE68;
extern Unk_801E1058 D_801E1058;
typedef struct { s16 unk0; s16 unk2; } Unk_801A216C;
extern s32 roadmap_shop_exit_points[];
void mail_goto_twn(s32 a, s32 b, s32 c, s16 d, s16 e);
extern Unk_801E1040 D_801E1040;
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
Unk_801E6FF0 *kaj_view_begin_frame(void);
void sprite_draw_all(Unk_801E6FF0 *arg0);
void mod_npcrec_draw_all(s32 arg0);
void npc_draw_all(s32 arg0);
void roadmap_draw_flash(Unk_801E6FF0 *arg0);
void sprite_thing_draw_all(Unk_801E6FF0 *arg0);
void door_draw_all(Unk_801E6FF0 *arg0);
void mod_draw_player(Unk_801E6FF0 *arg0, s32 arg1);
void vehicle_draw(Unk_801E6FF0 *arg0);
void block_draw_all(Unk_801E6FF0 *arg0, s32 arg1);
void kaj_view_flip(Unk_801E6FF0 *arg0);
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
extern Player *D_801E076C[];
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
} Unk_801E0368_u8019A5D4;
void roadmap_shop_pick_weapons(Unk_801A0820 *arg0);
extern Unk_801E0368_u8019A5D4 action_vars;
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
Unk_801891A4 *effect_item_find(s16 arg0);
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
    Unk_801E07C0 *p = &D_801E07C0;

    D_801E07C0.unk0 = 0;
    p->unk2 = 0;
    p->unk4 = sprite_find(0x405);
    p->unk8 = sprite_find(0x406);
    p->unkC = sprite_find(0x407);
    if (p->unk4 == NULL || p->unk8 == NULL || p->unkC == NULL) {
        kaj_abend(5, "Road Map Parts not Found", "roadmap.c", 0x20);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8019A5D4", D_80171048);

void roadmap_quit(void) {
    Unk_801E07C0 *p = &D_801E07C0;

    D_801E07C0.unk0 = 0;
    p->unk2 = 0;
    p->unk4[2] = 0;
    p->unk8[2] = 0;
    p->unkC[2] = 0;
    p->unk4 = NULL;
    p->unk8 = NULL;
    p->unkC = NULL;
}

u16 roadmap_get_state(void) {
    return D_801E07C0.unk0;
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

void *roadmap_add_sprite(Unk_8019FDD8 *arg0, void *arg1, u32 *arg2) {
    Unk_801E1040 *p = &D_801E1040;
    u8 *pkt;
    Unk_8019FDD8_P *sp;
    u32 *ot;
    u8 c[3];
    u8 u;
    s32 v;

    if ((u32)kaj_view_packet_used() > 0xAFF8) {
        return arg1;
    }
    pkt = arg1;
    sp = (Unk_8019FDD8_P *)pkt;
    ((u8 *)sp)[3] = 4;
    sp->unk7 = 0x64;
    SetSemiTrans(sp, 1);
    sp->unkE = arg0->unk1C->unk18;
    if (p->unk6 != 0) {
        if ((D_801E076C[0]->flags & 0x100) && arg0->unk0 == 0x404) {
            sp->unk4 = roadmap_sprite_colors[arg0->unk8].unk0;
            sp->unk5 = roadmap_sprite_colors[arg0->unk8].unk1;
            sp->unk6 = roadmap_sprite_colors[arg0->unk8].unk2;
        } else {
            c[0] = roadmap_sprite_colors[arg0->unk8].unk0 * p->unkE >> 12;
            c[1] = roadmap_sprite_colors[arg0->unk8].unk1 * p->unkE >> 12;
            c[2] = roadmap_sprite_colors[arg0->unk8].unk2 * p->unkE >> 12;
            sp->unk4 = c[0];
            sp->unk5 = c[1];
            sp->unk6 = c[2];
        }
    } else {
        sp->unk4 = roadmap_sprite_colors[arg0->unk8].unk0;
        sp->unk5 = roadmap_sprite_colors[arg0->unk8].unk1;
        sp->unk6 = roadmap_sprite_colors[arg0->unk8].unk2;
    }
    u = arg0->unk1C->unk10 << arg0->unk1C->unk14;
    v = arg0->unk1C->unk12;
    if (arg0->unk2 == 1) {
        u += arg0->unk18 * arg0->unk10;
        v += arg0->unk1A * arg0->unk12;
    }
    sp->unkC = u;
    sp->unkD = v;
    sp->unk8 = arg0->unkA;
    sp->unkA = arg0->unkC;
    sp->unk10 = arg0->unk10;
    sp->unk12 = arg0->unk12;
    ot = arg2 + arg0->unkE;
    *(u32 *)pkt = (*ot & 0xFFFFFF) | 0x04000000;
    *ot = (u32)pkt & 0xFFFFFF;
    pkt += 0x14;
    SetDrawMode(pkt, 0, 0, arg0->unk1C->unk1A, 0);
    ot = arg2 + arg0->unkE;
    *(u32 *)pkt = (*ot & 0xFFFFFF) | 0x02000000;
    *ot = (u32)pkt & 0xFFFFFF;
    pkt += 0xC;
    if (arg0->unk6 != 0) {
        LoadImage(arg0->unk1C->unk8, arg0->unk1C->unk20);
        arg0->unk6 = 0;
    }
    return pkt;
}

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_flash);

void roadmap_init_draw(void) {
    Unk_801DFF68 *p;

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
    D_801E1040.unkE = 0x1000;
    D_801E1040.unk0[0] = 0;
    D_801E1040.unk0[2] = 0;
    D_801E1040.unk6 = 0;
    D_801E1040.unk8[1] = 0;
    D_801E1040.unk8[2] = 3;
    D_801E1040.unk0[1] = 0;
    D_801E1040.unk8[0] = 0;
    D_801E1040.unk10 = 0;
    p = &roadmap_flash;
    roadmap_flash.unk0 = 0;
    p->unk2 = 0;
    kaj_view_clear_vram();
    kaj_view_set_bg_color(0, 0, 0);
    p->unk4 = 0;
    p->unk5 = 0;
    p->unk6 = 0;
    roadmap_ft_color_r = 0x60;
    roadmap_ft_color_g = 0x60;
    roadmap_ft_color_b = 0x60;
    InitClip(&roadmap_clip_buf, 0x150, 0x100, 0xE4, 0x6E, 0xFFFF);
}

void roadmap_draw_frame(u16 arg0) {
    Unk_801E1040 *p = &D_801E1040;
    Unk_801E6FF0 *e;
    s32 n;

    roadmap_brightness = p->unkE;
    roadmap_daylight_level = p->unk8[0] * 42 + p->unk8[0] * 2 / 3 + 0x600;
    D_801DFF5C = arg0;
    D_801DFF74 = 0;
    if (D_801E1040.unk0[0] != 0 && p->unk10 == 1) {
        n = 0x3D - p->unk8[0];
        roadmap_ft_color_r = (n * 0x1334 >> 12) - 0x80;
        roadmap_ft_color_g = (n * 0x1334 >> 12) - 0x80;
        roadmap_ft_color_b = (n * 0x2CD >> 10) - 0x80;
        D_801DFF74 = 1;
    } else {
        roadmap_ft_color_r = 0x60;
        roadmap_ft_color_g = 0x60;
        roadmap_ft_color_b = 0x60;
    }
    if (p->unk0[2] != 0) {
        D_801DFF74 += 2;
    }
    if (p->unk6 != 0) {
        D_801DFF74 += 4;
    }
    e = kaj_view_begin_frame();
    sprite_draw_all(e);
    mod_npcrec_draw_all((s32)e);
    npc_draw_all((s32)e);
    roadmap_draw_flash(e);
    sprite_thing_draw_all(e);
    door_draw_all(e);
    mod_draw_player(e, arg0);
    vehicle_draw(e);
    block_draw_all(e, arg0);
    kaj_view_flip(e);
    if (kaj_system.pad_mode == 2) {
        kaj_system.pad_mode = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8019A5D4", roadmap_draw_sprite_frame);

void roadmap_start_flash(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Unk_801DFF68 *p = &roadmap_flash;

    if (roadmap_flash.unk0 == 0) {
        roadmap_flash.unk0 = 1;
        p->unk2 = arg3;
        p->unk4 = arg0;
        p->unk5 = arg1;
        p->unk6 = arg2;
    }
}

Unk_801A06C0 *roadmap_add_flash_tile(Unk_801DFF68 *arg0, Unk_801A06C0 *arg1, u32 *arg2) {
    Unk_801E1040 *p = &D_801E1040;
    u8 c[3];

    if ((u32)kaj_view_packet_used() <= 0xAFFA) {
        ((u8 *)arg1)[3] = 5;
        arg1->unk7 = 0x28;
        SetSemiTrans(arg1, 1);
        arg1->unk8 = 0;
        arg1->unkA = 0;
        arg1->unkC = 0x13F;
        arg1->unkE = 0;
        arg1->unk10 = 0;
        arg1->unk12 = 0xEF;
        arg1->unk14 = 0x13F;
        arg1->unk16 = 0xEF;
        if (p->unk6 != 0) {
            c[0] = arg0->unk4 * p->unkE >> 12;
            c[1] = arg0->unk5 * p->unkE >> 12;
            c[2] = arg0->unk6 * p->unkE >> 12;
            arg1->unk4 = c[0];
            arg1->unk5 = c[1];
            arg1->unk6 = c[2];
        } else {
            arg1->unk4 = arg0->unk4;
            arg1->unk5 = arg0->unk5;
            arg1->unk6 = arg0->unk6;
        }
        arg1->unk0 = (arg2[0x10] & 0xFFFFFF) | 0x05000000;
        arg2[0x10] = (u32)arg1 & 0xFFFFFF;
        return arg1 + 1;
    }
}

void roadmap_shop_pick_weapons(Unk_801A0820 *arg0) {
    Unk_801A216C tab[12];
    Unk_80188FEC *e;
    s32 i;
    s32 j;
    s32 end;
    s32 start;

    arg0->unkE = D_801E0712[0] / 20;
    if (arg0->unkE > 2) {
        arg0->unkE = 2;
    }
    j = 0;
    for (i = 1; i < 13; i++) {
        if (i != 10) {
            e = effect_weapon_find(i);
            if (e != NULL) {
                tab[j].unk0 = i;
                tab[j].unk2 = e->unk30;
            } else {
                tab[j].unk0 = i;
                tab[j].unk2 = 100;
            }
            j++;
        }
    }
    qsort(tab, 11, 4, roadmap_cmp_weapon_level);
    switch (arg0->unkE) {
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

void roadmap_shop_topic_menu(s16 arg0, s16 arg1) {
    Unk_801E1058 *p = &D_801E1058;
    s32 b;
    s16 c;
    s16 d;
    s32 e;
    s16 g;
    s16 h;
    s16 i;

    if (arg0 != 0) {
        D_801DFF78 = 0;
        p->unk2 = 3;
        sprite_set_visible(3, 1);
        sprite_fill_clut(3, 4, 6, 0x2969);
        sprite_set_clut_entry(3, 4, 0x2BFF);
        text_show(D_801D7B24[0], 3, -1, 0, -1, 0, 1);
    } else {
        sprite_set_visible(3, 0);
        text_close();
        if (arg1 == 0) {
            D_801E1058.unk0 = 0;
            p->unk2 = -1;
        } else {
            if (D_801E1058.unk0 == 0) {
                D_801E1058.unk0 = 1;
            }
            b = 0x40B;
            c = 0x40C;
            e = 6;
            g = 4;
            h = 0x2969;
            i = 0x2BFF;
            p->unk1C = D_801D7B20;
            p->unk2 = 0;
            switch (D_801DFF78) {
            case 0:
                d = 0xE;
                p->unk18 = D_801D7A92;
                break;
            case 1:
                d = 0xF;
                p->unk18 = D_801D7AB0;
                break;
            case 2:
                b = 4;
                c = -1;
                d = 4;
                e = 4;
                p->unk18 = D_801D7ACE;
                break;
            }
            mail_menu_open(1, b, c, d, e, p->unk18, g, h, i);
        }
    }
}

void roadmap_shop_say_reply(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    Player *p = D_801E076C[0];
    s16 r = mail_menu_get_state();
    s16 v;

    if (r == 1) {
        if (arg3 == 0) {
            if (arg1 != 0) {
                if (arg0 == 4) {
                    if (arg2 != 0) {
                        /* " 6どうぞ、楽しんで食べてね" */
                        text_show(" 6\202\307\202\244\202\274\201\101\212\171\202\265\202\361\202\305\220\110\202\327\202\304\202\313", 3, -1, 0, -1, 0, r);
                    } else {
                        /* " 2どうぞ、こちらになります" */
                        text_show(" 2\202\307\202\244\202\274\201\101\202\261\202\277\202\347\202\311\202\310\202\350\202\334\202\267", 3, -1, 0, -1, 0, r);
                    }
                } else if (arg0 == 5) {
                    /* " 2早めに食べてくださいね" */
                    text_show(" 2\221\201\202\337\202\311\220\110\202\327\202\304\202\255\202\276\202\263\202\242\202\313", 3, -1, 0, -1, 0, r);
                }
            } else {
                if (arg0 == 4) {
                    if (arg2 != 0) {
                        /* " 6どうぞ、楽しんで食べてね" */
                        text_show(" 6\202\307\202\244\202\274\201\101\212\171\202\265\202\361\202\305\220\110\202\327\202\304\202\313", 3, -1, 0, -1, 0, r);
                    } else {
                        /* " 2どうぞ、こちらになります" */
                        text_show(" 2\202\307\202\244\202\274\201\101\202\261\202\277\202\347\202\311\202\310\202\350\202\334\202\267", 3, -1, 0, -1, 0, r);
                    }
                } else if (arg0 == 5) {
                    /* " 2どうぞ、おいしいですよ" */
                    text_show(" 2\202\307\202\244\202\274\201\101\202\250\202\242\202\265\202\242\202\305\202\267\202\346", 3, -1, 0, -1, 0, r);
                }
            }
        } else if (arg3 == 2) {
            if (arg2 != 0) {
                /* " 6これ以上持てないわよ" */
                text_show(" 6\202\261\202\352\210\310\217\343\216\235\202\304\202\310\202\242\202\355\202\346", 3, -1, 0, -1, 0, 4);
            } else {
                /* " 2これ以上, お持ちになれないようですよ" */
                text_show(" 2\202\261\202\352\210\310\217\343, \202\250\216\235\202\277\202\311\202\310\202\352\202\310\202\242\202\346\202\244\202\305\202\267\202\346", 3, -1, 0, -1, 0, 4);
            }
        } else if (arg3 == r) {
            if (arg0 == 8) {
                v = D_801DFF78;
                if (v == -1) {
                    if (p->flags & 0x100) {
                        p->flags &= 0xFEFF;
                    }
                    text_show(D_801715C4, 3, -1, 0, v, 0, arg3);
                }
            } else {
                if (p->flags & 0x100) {
                    p->flags &= 0xFEFF;
                }
                text_close();
            }
        }
        mail_menu_close();
    }
}

void roadmap_fade_screen_music(s16 arg0) {
    Unk_801A3B5C *q = object_scene_tables[0].unk0;
    Unk_801E1040 *p = &D_801E1040;
    s32 t;
    s32 v;

    if (arg0 != 0) {
        p->unkE = 0x80;
    } else {
        p->unk6 = 1;
        p->unkE = 0x1000;
    }
    while (1) {
        if (arg0 != 0) {
            p->unkE += kaj_system.vsync_delta * 0x85;
            if (p->unkE >= 0x1000) {
                p->unkE = 0x1000;
                break;
            }
        } else {
            p->unkE -= kaj_system.vsync_delta * 0x85;
            if (p->unkE <= 0x80) {
                p->unkE = 0x80;
                break;
            }
        }
        if (q != NULL && q->unk2 >= 0) {
            t = p->unkE >> 5;
            if (t < 0x80) {
                v = (s16)t;
                if (t < 0) {
                    v = 0;
                }
            } else {
                v = 0x7F;
            }
            SsSepSetVol(q->unk0, q->unk2, v, v);
        }
        mail_step_frame(1, 1, 1);
    }
    if (arg0 != 0) {
        p->unk6 = 0;
        p->unkE = 0x1000;
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8019A5D4", D_801715C4);

s16 roadmap_shop_finish(s16 arg0) {
    PlayerStatus *q = &player_status;
    Unk_801E1058 *p = &D_801E1058;
    Unk_801E0368_u8019A5D4 *r = &action_vars;
    Player *e = q->player;
    char buf[0x80];
    Unk_801D7B34 *t;
    Unk_80188FEC *a;
    Unk_801891A4 *b;
    char *s;
    s32 i;
    s16 found = 0;
    s16 ret;
    s16 v;
    s32 j;
    s16 m;
    Unk_801E1058 *p2;

    switch (arg0) {
    case 7:
        if (p->unk12[0] >= 0) {
            t = &roadmap_shop_weapon_advice[p->unkE];
            a = effect_weapon_find(p->unk12[0]);
            if (a != NULL) {
                if ((s16)a->unk30 == q->level) {
                    s = t->unk4;
                } else if ((s16)a->unk30 < q->level) {
                    s = t->unk8;
                } else {
                    s = t->unk0;
                }
                text_show_timed(1, 1, s, 1, 2);
                memset(buf, 0, 0x80);
                sprintf(buf, " 8%s1, \202\360\216\363\202\257\216\346\202\301\202\275", a->unk4);
                text_show_timed(1, 1, buf, 2, 2);
            }
        }
        break;
    case 8:
        ret = -1;
        if (p->unk4 != 0) {
            if (p->unk12[0] >= 0) {
                b = effect_item_find(p->unk12[0] + 100);
                if (b != NULL) {
                    memset(buf, 0, 0x80);
                    sprintf(buf, " 8%s2\202\314\222n\220\175\202\313", b->unk4);
                    text_show_timed(1, 1, buf, 2, 2);
                    text_show(D_801715C4, 3, -1, 0, -1, 0, 1);
                    if (e->flags & 0x100) {
                        e->flags &= 0xFEFF;
                    }
                }
            }
        } else if (p->unk12[0] >= 0) {
            ret = p->unk12[0];
            if (D_801DFF78 == 0) {
                ret += 10;
            } else if (D_801DFF78 == 1) {
                ret += 30;
            }
        }
        break;
    case 9:
        if (p->unk12[0] >= 0) {
            b = effect_item_find(p->unk12[0]);
            if (b != NULL) {
                memset(buf, 0, 0x80);
                sprintf(buf, " 8%s1\202\360\221I\221\360\202\265\202\275", b->unk4);
                text_show_timed(1, 1, buf, 2, 1);
                roadmap_fade_screen_music(0);
                effect_item_use(q, 1, p->unk12[0], 0, 0);
                mail_wait(1, 1, 1, 2);
                roadmap_fade_screen_music(1);
                mail_wait(1, 1, 1, 2);
                text_show(" 2\202\250\224\346\202\352\227l\202\305\202\265\202\275", 3, -1, 0, -1, 0, 1);
            }
        }
        break;
    default:
        if (p->unk4 != 0) {
            for (i = 0; i < 3; i++) {
                if (p->unk12[i] >= 0) {
                    b = effect_item_find(p->unk12[i]);
                    if (b != NULL) {
                        memset(buf, 0, 0x80);
                        sprintf(buf, " 8%s1, \202\360\216\363\202\257\216\346\202\301\202\275", b->unk4);
                        text_show_timed(1, 1, buf, 2, 2);
                    }
                }
            }
            if (arg0 == 4) {
                if (p->unk6 != 0) {
                    text_show(" 6\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275, \203N\203b\203N\203b\203N", 3, -1, 0, -1, 0, 1);
                } else {
                    text_show(" 2\202\307\202\244\202\340\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275", 3, -1, 0, -1, 0, 1);
                }
            } else if (arg0 == 5) {
                text_show(" 2\202\334\202\275\201A\202\346\202\353\202\265\202\255\202\250\212\350\202\242\202\265\202\334\202\267", 3, -1, 0, -1, 0, 1);
            }
        } else {
            if (q->energy == 0xFF && p->unkE == 0) {
                p->unkE = 1;
            }
            for (i = 0; i < 3; i++) {
                if (p->unk12[i] >= 0) {
                    if (!found) {
                        found = 1;
                    }
                    v = effect_item_use(q, 1, p->unk12[i], p->unkE, 0);
                    if (v >= 0) if (v != 0) {
                        p->unkE = 1;
                    }
                }
            }
            if (found) {
                r->unk92++;
            }
            if (arg0 == 4) {
                if (p->unk6 != 0) {
                    text_show(" 6\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275, \203N\203b\203N\203b\203N", 3, -1, 0, -1, 0, 1);
                } else {
                    text_show(" 2\202\307\202\244\202\340\202\240\202\350\202\252\202\306\202\244\202\262\202\264\202\242\202\334\202\265\202\275", 3, -1, 0, -1, 0, 1);
                }
            } else if (arg0 == 5) {
                text_show(" 2\202\334\202\275\201A\202\346\202\353\202\265\202\255\202\250\212\350\202\242\202\265\202\334\202\267", 3, -1, 0, -1, 0, 1);
            }
        }
        break;
    }
    p2 = &D_801E1058;
    D_801E1058.unk0 = 0;
    p2->unk2 = -1;
    p2->unk4 = 0;
    p2->unk6 = 0;
    p2->unk8 = 0;
    p2->unkA = 0;
    p2->unkC = 0;
    p2->unkE = 0;
    p2->unk10 = 0;
    m = -1;
    for (j = 2; j >= 0; j--) {
        p2->unk12[j] = m;
    }
    p2->unk18 = NULL;
    p2->unk1C = NULL;
    if (arg0 == 3 || arg0 == 6) {
        player_reset_triggers(2);
    }
    return ret;
}

s16 roadmap_shop_update_input(PlayerStatus *arg0) {
    Unk_801E1058 *p = &D_801E1058;
    Unk_801DFE68 *q = &D_801DFE68;
    Player *e = arg0->player;
    s16 sel;

    if (D_801E1058.unk0 == 0) {
        return 0;
    }
    sel = mail_menu_get_state();
    if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
        if (p->unk2 == 3 && sel == 0) {
            sound_se_play(0x11);
            roadmap_shop_topic_menu(0, 1);
            return 1;
        } else if (p->unk2 == 0 && sel == 1) {
            sound_se_play(0x11);
            sel = mail_menu_get_entry(p->unk10);
            if (p->unk4 != 0) {
                switch (q->unk0) {
                case 7:
                    if (effect_inventory_has_room(4) != 0) {
                        if (player_set_weapon(sel, 1, 0) != 0) {
                            p->unk12[0] = sel;
                        }
                    } else {
                        roadmap_shop_say_reply(q->unk0, p->unk4, p->unk6, 2);
                        return 1;
                    }
                    break;
                case 8:
                    p->unk12[0] = sel;
                    player_set_item(sel + 100, 2, 1);
                    roadmap_shop_say_reply(q->unk0, p->unk4, p->unk6, 0);
                    return 1;
                default:
                    if (effect_inventory_has_room(0) != 0) {
                        if (player_set_item(sel, 0, 1) != 0) {
                            p->unk12[0] = sel;
                        }
                    } else {
                        roadmap_shop_say_reply(q->unk0, p->unk4, p->unk6, 2);
                        return 1;
                    }
                    break;
                }
            } else {
                p->unk12[0] = sel;
            }
            if (p->unkA != 0) {
                p->unk2 = 1;
                p->unk10 = 0;
                text_show(((char **)p->unk1C)[1], 3, -1, 0, -1, 0, 1);
                mail_menu_set_list(4, p->unk18 + 4);
                return 1;
            }
        } else if (p->unk2 == 1 && sel == 1) {
            sound_se_play(0x11);
            sel = mail_menu_get_entry(p->unk10);
            if (p->unk4 != 0) {
                if (effect_inventory_has_room(0) != 0) {
                    if (player_set_item(sel, 0, 1) != 0) {
                        p->unk12[1] = sel;
                    }
                } else {
                    roadmap_shop_say_reply(q->unk0, p->unk4, p->unk6, 2);
                    return 1;
                }
            } else {
                p->unk12[1] = sel;
            }
            if (p->unkC != 0) {
                p->unk2 = 2;
                text_show(((char **)p->unk1C)[2], 3, -1, 0, -1, 0, 1);
                return 1;
            }
        } else if (p->unk2 == 2 && sel == 1) {
            sound_se_play(0x11);
            sel = p->unk18[8];
            if (p->unk4 != 0) {
                if (effect_inventory_has_room(0) != 0) {
                    if (player_set_item(sel, 0, 1) != 0) {
                        p->unk12[2] = sel;
                    }
                } else {
                    roadmap_shop_say_reply(q->unk0, p->unk4, p->unk6, 2);
                    return 1;
                }
            } else {
                p->unk12[2] = sel;
            }
        } else {
            return 1;
        }
        roadmap_shop_say_reply(q->unk0, p->unk4, p->unk6, 0);
    } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
        sound_se_play(8);
        if (p->unk2 == 3 && sel == 0) {
            roadmap_shop_topic_menu(0, 0);
            /* " 2話が聞きたくなったら, いつでもおいで" */
            text_show_timed(1, 1, " 2\230b\202\252\225\267\202\253\202\275\202\255\202\310\202\301\202\275\202\347, \202\242\202\302\202\305\202\340\202\250\202\242\202\305", 1, 1);
            if (e->flags & 0x100) {
                e->flags &= 0xFEFF;
            }
        } else if (p->unk2 == 0 && sel == 1) {
            roadmap_shop_say_reply(q->unk0, p->unk4, p->unk6, 1);
            return 1;
        } else if (p->unk2 == 1 && sel == 1 && p->unkC != 0) {
            p->unk2 = 2;
            text_show(((char **)p->unk1C)[2], 3, -1, 0, -1, 0, sel);
        } else {
            roadmap_shop_say_reply(q->unk0, p->unk4, p->unk6, 0);
            return 1;
        }
    } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
        if (sel == 0) {
            if (p->unk2 == 3) {
                sound_se_play(0xF);
                if (--D_801DFF78 < 0) {
                    D_801DFF78 = 2;
                }
                sprite_fill_clut(3, 4, 6, 0x2969);
                sprite_set_clut_entry(3, D_801DFF78 + 4, 0x2BFF);
            }
        } else if (sel == 1) {
            if (p->unk2 != 2) {
                p->unk10 = mail_menu_move(1);
            }
        }
    } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
        if (sel == 0) {
            if (p->unk2 == 3) {
                sound_se_play(0xF);
                if (++D_801DFF78 >= 3) {
                    D_801DFF78 = 0;
                }
                sprite_fill_clut(3, 4, 6, 0x2969);
                sprite_set_clut_entry(3, D_801DFF78 + 4, 0x2BFF);
            }
        } else if (sel == 1) {
            if (p->unk2 != 2) {
                p->unk10 = mail_menu_move(0);
            }
        }
        return 1;
    }
    return 1;
}

s16 roadmap_shop_open_menu(s16 arg0, s32 arg1) {
    Player *e = D_801E076C[0];
    Unk_801E0368_u8019A5D4 *q = &action_vars;
    Unk_801E1058 *p = &D_801E1058;
    s32 j;
    s16 m;
    s16 b;
    s16 c;
    s16 d;
    s16 n;
    s16 g;
    s16 h;
    s16 i;

    if (mail_menu_get_state() != 0) {
        return 0;
    }
    D_801E1058.unk0 = 1;
    p->unk2 = 0;
    p->unk6 = 0;
    p->unkA = 0;
    p->unkC = 0;
    p->unkE = 0;
    p->unk10 = 0;
    m = -1;
    for (j = 2; j >= 0; j--) {
        p->unk12[j] = m;
    }
    b = 3;
    c = -1;
    d = 4;
    n = d;
    g = 1;
    h = 0x14E7;
    i = 0x14FF;
    switch (arg0) {
    case 3:
        if (q->unk14 == 2000) {
            p->unk6 = 1;
            p->unk18 = D_801D7A08;
        } else if (q->unk1F8 >= 8 && q->unk1F8 < 10) {
            p->unk18 = D_801D79F0;
        } else if (q->unk1F8 >= 10 && q->unk1F8 < 14) {
            p->unk18 = D_801D79F8;
        } else {
            p->unk18 = D_801D7A00;
        }
        p->unk1C = D_801D7AEC;
        break;
    case 4:
        if (q->unk14 == 1000) {
            p->unk18 = D_801D7A10;
            p->unk1C = D_801D7AF8;
        } else if (q->unk14 == 2000) {
            p->unk6 = 1;
            p->unk18 = D_801D7A22;
            p->unk1C = D_801D7B04;
        } else if (q->unk80 != 0) {
            if (q->unk60 != 0 || !(q->unk1F8 >= 8 && q->unk1F8 < 14)) {
                p->unk18 = D_801D7A10;
                p->unk1C = D_801D7AF8;
            } else {
                p->unk6 = 1;
                p->unk18 = D_801D7A22;
                p->unk1C = D_801D7B04;
            }
        } else {
            if (q->unk60 != 0 || (q->unk1F8 >= 8 && q->unk1F8 < 14)) {
                p->unk18 = D_801D7A10;
                p->unk1C = D_801D7AF8;
            } else {
                p->unk6 = 1;
                p->unk18 = D_801D7A22;
                p->unk1C = D_801D7B04;
            }
        }
        p->unkA = 1;
        p->unkC = 1;
        break;
    case 5:
        p->unk1C = D_801D7B10;
        p->unk18 = D_801D7A34;
        p->unkA = 1;
        p->unkC = 1;
        break;
    case 6:
        p->unk1C = D_801D7AEC;
        if (q->unk14 == 2000) {
            p->unk6 = 1;
            p->unk18 = D_801D7A60;
        } else if (q->unk1F8 >= 11 && q->unk1F8 < 14) {
            p->unk18 = D_801D7A48;
        } else if (q->unk1F8 >= 14 && q->unk1F8 < 17) {
            p->unk18 = D_801D7A50;
        } else {
            p->unk18 = D_801D7A58;
        }
        break;
    case 7:
        roadmap_shop_pick_weapons((Unk_801A0820 *)p);
        b = 0x40B;
        c = 0x402;
        d = 6;
        n = d;
        g = 4;
        h = 0x2969;
        i = 0x2BFF;
        p->unk4 = 1;
        p->unk1C = D_801D7AEC;
        p->unk18 = roadmap_shop_weapons;
        break;
    case 8:
        e->flags |= 0x100;
        if (arg1 != 0x300600) {
            goto fail;
        }
        b = 0x40B;
        c = 0x40C;
        d = 0xD;
        n = 6;
        g = 4;
        h = 0x2969;
        i = 0x2BFF;
        D_801DFF78 = -1;
        p->unk1C = D_801D7B1C;
        p->unk4 = 1;
        p->unk18 = D_801D7A74;
        break;
    case 9:
        d = 3;
        n = d;
        p->unk1C = D_801D7B28;
        p->unk18 = D_801DFD74;
        break;
    }
    return mail_menu_open(1, b, c, d, n, p->unk18, g, h, i);
fail:
    roadmap_shop_topic_menu(1, 0);
    return 1;
}

void roadmap_shop_init(s16 arg0) {
    Unk_801E0368_u8019A5D4 *q = &action_vars;
    Unk_801E1058 *p = &D_801E1058;
    s32 i;
    s32 j;

    D_801E1058.unk0 = 0;
    p->unk2 = -1;
    p->unk4 = 0;
    p->unk6 = 0;
    p->unk8 = 0;
    p->unkA = 0;
    p->unkC = 0;
    p->unkE = 0;
    p->unk10 = 0;
    for (j = 0; j < 3; j++) {
        p->unk12[j] = -1;
    }
    p->unk18 = 0;
    p->unk1C = 0;
    q->unk1F8 = q->unk7C;
    switch (arg0) {
    case 8:
    case 9:
        break;
    default:
        for (i = 0; i < 40; i++) {
            if (i < (arg0 - 3) * 10 || i >= (arg0 - 3) * 10 + 10) {
                door_set_visible(i, 0);
            }
        }
        break;
    }
    D_801DFEE4 = roadmap_shop_on_enter;
    D_801DFEE0 = roadmap_shop_on_leave;
}

void roadmap_shop_exit_to_town(s16 arg0, s16 arg1) {
    s32 i = (arg1 - 1) * 3;

    switch (arg0) {
    case 4:
        i += 0x27;
        break;
    case 5:
        i += 0x39;
        break;
    case 6:
        i += 0x57;
        break;
    case 7:
        i += 0x69;
        break;
    }
    mail_goto_twn(roadmap_shop_exit_points[i], 0, roadmap_shop_exit_points[i + 1], roadmap_shop_exit_points[i + 2], 1);
}

void roadmap_shop_close_topic(void) {
    roadmap_shop_topic_menu(0, 1);
}

s32 roadmap_shop_on_enter(Unk_801A20CC *arg0) {
    Unk_801E1058 *p = &D_801E1058;

    if (arg0->unk8 == 0x30) {
        u32 c = arg0->unkC;

        if (D_801DFE68.unk0 == 3) {
            if (c < 11) {
                p->unk8 = 1;
            }
        } else if (D_801DFE68.unk0 == 6) {
            if (c < 6) {
                p->unk8 = 1;
            }
        }
    }
    return 0;
}

s32 roadmap_shop_on_leave(Unk_801A20CC *arg0) {
    Unk_801E1058 *p = &D_801E1058;

    if (arg0->unk8 == 0x30) {
        u32 c = arg0->unkC;

        if (D_801DFE68.unk0 == 3) {
            if (c < 11) {
                p->unk8 = 0;
            }
        } else if (D_801DFE68.unk0 == 6) {
            if (c < 6) {
                p->unk8 = 0;
            }
        }
    }
    return 0;
}

s32 roadmap_cmp_weapon_level(Unk_801A216C *arg0, Unk_801A216C *arg1) {
    return arg0->unk2 - arg1->unk2;
}
