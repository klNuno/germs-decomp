#include "common.h"

typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; } Unk_80192E18;
typedef struct { s32 unk0; s32 unk4; Unk_80192E18 *unk8; void *unkC; } Unk_80192F20;
void free3(void *ptr);
typedef struct { s32 unk0; u16 unk4; s16 unk6; s32 unk8; s32 unkC; } Unk_801E0600;
typedef struct {
    s32 unk0;
    s16 unk4[10];
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    u8 unk24[0x2C];
} Unk_801E0620_A0;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0x26];
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    u16 unk42;
    s16 unk44;
    u16 unk46;
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    s16 unk4E;
    s16 unk50;
    u8 unk52[2];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0xC];
    s16 unk6C;
    s16 unk6E;
    s16 unk70;
    s16 unk72;
    s16 unk74;
    s16 unk76;
    s16 unk78;
    u8 pad7A[0x2];
    u8 unk7C[0x14];
    s32 unk90[3];
    s32 unk9C;
    Unk_801E0620_A0 unkA0[1];
} Unk_801E0620;
s32 D_801DFF48;
extern Unk_801E0600 D_801E0600;
extern Unk_801E0600 D_801E0610;
extern Unk_801E0620 D_801E0620;
s16 effect_item_add(s16 arg0, s16 arg1);
s16 effect_item_remove(s16 arg0, s16 arg1);
void effect_weapon_unequip(s16 arg0);
s16 effect_weapon_add(s16 arg0, s16 arg1);
typedef struct { u8 unk0[0x16]; u16 unk16; } Unk_8018E56C;
typedef struct Unk_801E076C {
    u8 unk0[0x3C];
    s16 unk3C;
    u8 unk3E[2];
    u16 unk40;
    u16 unk42;
    u8 unk44[2];
    u16 unk46;
    u8 unk48[2];
    s16 unk4A;
    u8 unk4C[2];
    s16 unk4E;
    s16 unk50;
    u8 unk52[2];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    u8 unk64[4];
    s32 unk68;
    s16 unk6C;
    s16 unk6E;
    u8 unk70[8];
    s16 unk78;
} Unk_801E076C;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4[2];
    s16 unk8[0x14];
    s16 unk30;
    s16 unk32[8];
    s16 unk42;
    s16 unk44;
    s16 unk46;
    s16 unk48;
    u8 unk4A[2];
    s32 unk4C;
} Unk_801E0770;
typedef struct { u16 unk0; s16 unk2; s16 unk4; s16 unk6; s16 unk8; u8 unkA; u8 unkB; s16 unkC; u8 unkE; u8 unkF; s16 unk10; u16 unk12; s16 unk14; s16 unk16; s16 unk18; s16 unk1A; s16 unk1C; s16 unk1E; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s16 unk38; s16 unk3A; s16 unk3C; s16 unk3E; u16 unk40; s16 unk42; u8 unk44; u8 unk45; s16 unk46; s32 unk48; } Unk_801762F4;
typedef struct Unk_801E0710 {
    s16 unk0;
    s16 unk2;
    u32 unk4;
    s32 unk8;
    s16 unkC;
    s16 unkE;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    s16 unk16;
    s16 unk18;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    s16 unk2A;
    s16 unk2C;
    u8 unk2E[6];
    s16 unk34;
    s16 unk36;
    u8 unk38[2];
    s16 unk3A[5];
    s16 unk44;
    s16 unk46;
    s16 unk48;
    s16 unk4A;
    Unk_801762F4 *unk4C;
    Unk_8018E56C *unk50;
    u8 unk54[4];
    Unk_801E0770 *unk58;
    Unk_801E076C *unk5C;
} Unk_801E0710;
extern Unk_801E0710 D_801E0710;
void event_draw_gauge(Unk_801E0710 *arg0);
typedef struct {
    s16 unk0[0x14];
    s16 unk28[0x1C];
    s16 unk60;
    s16 unk62[0xB];
    s16 unk78;
    u8 unk7A[2];
    s16 unk7C;
    u16 unk7E;
    u8 unk80[0x34];
    s16 unkB4[5];
    u8 padBE[0x22];
    u8 unkE0[0x16C];
    s16 unk24C;
} Unk_801E0368;
extern Unk_801E0368 D_801E0368;
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; } Unk_80192F60;
typedef struct { s16 unk0; s16 unk2; s16 unk4; } Unk_801DFF30;
Unk_801DFF30 object_room_phone;
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
typedef struct { s16 unk0; s16 unk2; s16 unk4; } Unk_801DFF28;
Unk_801DFF28 object_room_storage;
u16 D_801DFD58;
u16 D_801DFD5A;
extern char D_80170E18[];
void sprite_set_visible(s32 arg0, s32 arg1);
void sprite_set_clut_entry(s32 arg0, s32 arg1, s32 arg2);
void text_close(void);
void mail_wait(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern Unk_801E076C *D_801E076C[];
Unk_8018E56C *mod_find(u16 arg0);
void mod_set_anim(void *arg0, s16 arg1, s16 arg2);
void object_room_play_call(s16 arg0);
void sound_se_stop(s32 arg0);
void effect_start_alarm(s32 arg0, s32 arg1, s32 arg2);
void player_reset_triggers(s16 arg0);
s16 object_room_exit_action;
void object_room_main(void);
void menu_run(void);
void menu_card_run(s32 arg0, s32 arg1);
void mail_goto_ofc(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
typedef struct {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    u8 unk10[2];
    u16 unk12;
} Unk_801DFFE8;
extern Unk_801DFFE8 D_801DFFE8;
typedef struct { void *unk0; s32 unk4; void *unk8; } Unk_80174B10;
extern void *D_801E0760[];
Unk_80174B10 *action_find_set(s16 arg0);
Unk_80174B10 *action_run_set(Unk_80174B10 *arg0, s32 arg1, s32 arg2);
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; } Unk_801CC1E8;
s16 D_801DFF4C;
void UnDeliverEvent(u32 ev, u32 spec);
Unk_801CC1E8 *kaj_event_push(s32 arg0);
extern s16 player_part_damage_caps[];
void event_draw_limb_status(Unk_801E0710 *arg0);
void event_set_blink(s16 arg0, s16 arg1);
typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4[0x10];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 unk20[0x1C];
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
} Unk_8019A07C_3C;
typedef struct {
    u8 unk0[0x3C];
    Unk_8019A07C_3C *unk3C;
} Unk_8019A07C;
void player_finish_death(void);
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    u8 unk38[4];
    Unk_801762F4 *unk3C;
    u8 unk40[0x1C];
    void *unk5C[1];
} Unk_801E02D8;
extern Unk_801E02D8 D_801E02D8;
s16 D_801DFF18;
s32 object_aset_count;
extern u8 object_iff_file_pos[];
s32 CdPosToInt(void *p);
void *CdIntToPos(s32 i, void *p);
s32 CdControl(u8 com, u8 *param, u8 *result);
void sound_se_play(s32 arg0);
void player_set_view(Unk_801E076C *arg0, s16 arg1);
void event_advance_clock(s16 a, s16 b);
typedef struct { s32 unk0; u8 *unk4; u8 *unk8; s32 unkC; s32 unk10; s16 unk14; } Unk_801A3970;
extern Unk_801A3970 D_801E05C0;
s32 CdMode(void);
void *CdLastPos(void);
s32 CdRead(s32 sectors, u32 *buf, s32 mode);
s32 CdReadSync(s32 mode, u8 *result);
s32 VSync(s32 mode);
u32 *sound_se_alloc_header(u8 *arg0, s32 arg1, Unk_801A3970 *arg2);
void sound_vab_open_head(Unk_801A3970 *arg0);
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
s32 kaj_pad_read(void);
s16 object_room_storage_input(void);
s16 effect_item_input(Unk_801E0710 *arg0, s16 arg1);
void object_room_do_action(Unk_801E0710 *arg0);
void player_start_move_to(s16 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, s16 arg7, s32 arg8);
void player_handle_pad(Unk_801E0710 *arg0, s32 arg1, s32 arg2);
s16 D_801DFD54;
extern s32 D_801DFF50;
extern s32 D_801DFED8;
extern s32 D_801DFEE4;
extern s32 D_801DFED4;
extern s32 D_801DFEE8;
void action_reset(s16 arg0);
void action_free_all_sets(void);
void action_free_triggers(void);
void npc_free_bodies(void);
void block_free_all(void);
void door_free_all(void);
void effect_clear_alarms(void);
void mod_free_all(void);
void player_add_hp(s16 arg0, s16 arg1);
void sound_se_pop_scene(void);
void sound_se_stop_all(void);
void sound_bgm_close(void);
void sound_bgm_stop(void);
void sprite_delete(s32 arg0);
void thing_free_all(void);
extern Unk_801E0770 D_801E0770;
void *memset(void *dst, s32 c, u32 n);
void RotMatrix(s16 *arg0, void *arg1);
void ApplyMatrixLV(void *arg0, void *arg1, void *arg2);
void GsSetView2(void *arg0);
void GsInitCoordinate2(void *super, void *base);
typedef struct { s16 unk0[5]; s16 unkA; char *unkC; s16 unk10; s16 unk12; s32 unk14; s32 unk18; s32 unk1C; } Unk_801E0340;
extern Unk_801E0340 D_801E0340;
extern s32 player_str_scene_cmn[];
void mail_goto_building(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
extern s16 D_801DFC76;
void roadmap_start_flash(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s16 D_801E1046[];
u16 roadmap_get_state(void);
s16 ai_in_aim_cone(Unk_801762F4 *arg0, s32 arg1, s16 arg2);
extern char D_80170EDC[];
extern char D_80170EFC[];
extern char D_80170F14[];
s32 player_is_injured(void);
s32 player_slide_dx;
s32 player_slide_dz;
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[2];
    s32 unk18;
    s16 unk1C[10];
    s32 unk30;
    s32 unk34;
    s32 unk38;
} Unk_801E032C;
typedef struct {
    u8 unk0[4];
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s16 unk14;
    u8 unk16[2];
    s32 unk18;
    s16 unk1C[4];
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x22];
    s32 unk4C;
    u8 unk50[4];
    s32 unk54;
    u8 unk58[4];
    s32 unk5C;
    u8 unk60[4];
    s32 unk64;
} Unk_801E1158;
void RotMatrixZXY(s16 *r, void *m);
void GsSetLsMatrix(void *m);
void RotTrans(void *v0, s32 *v1, s32 *flag);
typedef struct { s16 unk0[3]; s16 unk6; s16 unk8[3]; s16 unkE; } Unk_801E1040;
extern Unk_801E1040 D_801E1040;
void player_wrap_cell(Unk_801E0620 *arg0);
void SetFogNearFar(s32 a, s32 b, s32 h);
void RotMatrixZYX(s16 *r, void *m);
void player_start_death(u16 arg0, Unk_801E0710 *arg1, Unk_801E0620 *arg2);
void event_update_hud(Unk_801E0710 *a);
void block_stream_update(u16 arg0);
void block_update_visibility(u16 arg0);
void player_move_on_foot(Unk_801E0620 *arg0, u16 arg1, s16 arg2, s16 arg3);
void event_draw_compass(Unk_801E0620 *arg0);
void player_move_in_car(Unk_801E0620 *arg0, s32 arg1);
void player_move_in_train(Unk_801E0620 *arg0, u16 arg1);
void sound_footstep_update(Unk_801E0620 *arg0);
int rand(void);
typedef struct {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    u8 unk10[4];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    u8 unk20[4];
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    u8 unk30[4];
    s16 unk34;
    s16 unk36;
    s16 unk38;
    u8 unk3A[2];
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    u8 unk42[2];
    s16 unk44;
    s16 unk46;
    s16 unk48;
} Unk_80198ADC_3C;
typedef struct {
    u8 unk0[0x22];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[2];
    s32 unk2C;
    void *unk30;
    void *unk34;
    void *unk38;
    Unk_80198ADC_3C *unk3C;
} Unk_80198ADC;
typedef struct { u16 unk0; s16 unk2; s16 *unk4; s16 *unk8; s16 *unkC; } Unk_801E07C0;
typedef struct Unk_801E1118 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    u16 unkE;
    u16 unk10;
    u16 unk12;
    s16 unk14;
    s16 unk16;
    u8 unk18[0x4];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
    s16 unk2C;
    s16 unk2E;
    s16 unk30;
    u8 unk32[0x2];
    s16 unk34;
    s16 unk36;
    s16 unk38;
} Unk_801E1118;
extern Unk_801E1118 D_801E1118;
extern Unk_801E032C *D_801E032C[];
s16 player_try_slide(s16 arg0, s16 arg1, s32 *arg2, s32 *arg3, s32 arg4, s32 arg5);
void player_update_view(Unk_801E0620 *arg0, s16 *arg1, u16 arg2);
s32 func_8017BBB0(s32 arg0, s32 arg1, s32 *arg2);
s16 player_check_ground(Unk_801E0620 *arg0, s32 arg1, s16 arg2, s16 arg3);
s32 rsin(s32 a);
s32 rcos(s32 a);
extern Unk_801E1158 D_801E1158;
void player_place_in_car(Unk_801E0620 *arg0, Unk_801E032C *arg1, Unk_801E1158 *arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
s32 block_fit_ground_tilt(s32 *arg0, s32 arg1);
s32 SquareRoot0(s32 arg0);
s32 player_pick_hit_part(s16 arg0);
s16 mail_angle_to_dir8(s16 a);
void player_add_skill_exp(s16 arg0, s16 arg1);
typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4[0x20];
    u16 unk24;
    u8 unk26[2];
    s16 unk28;
    u8 unk2A[6];
    u16 unk30;
    u8 unk32[2];
    s16 unk34;
    u8 unk36[2];
    u16 unk38;
    u8 unk3A[2];
    s16 unk3C;
    u8 unk3E[2];
    s16 unk40;
    u8 unk42[6];
    s16 unk48;
    u8 unk4A[2];
    u16 unk4C;
    u8 unk4E[2];
    u16 unk50;
    u16 unk52;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
} Unk_80188FEC;
void npc_apply_damage(Unk_801762F4 *arg0, s32 arg1, s32 arg2, s16 arg3);
u16 npc_get_radius(Unk_801762F4 *arg0);
Unk_80188FEC *effect_weapon_find(s16 arg0);
void player_move_to_step(Unk_80198ADC *arg0);
void player_move_to_done(Unk_8019A07C *arg0);
void *kaj_tss_alloc(u32 arg0);
s32 kaj_tss_start(void *arg0);
typedef struct {
    u16 unk0;
    u16 unk2;
} Unk_80199034_0;
typedef struct {
    Unk_80199034_0 *unk0;
    s32 unk4;
    char **unk8;
} Unk_80199034;
s32 atoi(char *s);
s32 block_find_surface(s32 arg0, s32 arg1, s32 *arg2, s16 arg3);
s32 block_find_surface_nearest(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);
s16 mod_npcrec_find_at_point(s32 arg0, s32 arg1, s32 arg2);
s16 npc_find_at_point(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
Unk_801762F4 *npc_find(s16 arg0, u16 arg1);
u16 thing_hit_test(s32 arg0, s32 arg1, s32 arg2, u16 arg3);
s16 D_801DFD5C;
s16 D_801DFD5E;
extern s32 D_801E6DB4[];
s32 mail_exp_for_level(s32 a);
void effect_weapon_calc_rate(s32 arg0);
typedef struct { s32 unk0; s16 unk4; } Unk_801AC55C;
typedef struct { s16 unk0; s16 unk2; u8 unk4[0x8]; Unk_801AC55C *unkC; Unk_801AC55C *unk10; } Unk_801D7FB0;
extern Unk_801E07C0 D_801E07C0;
extern Unk_801D7FB0 D_801D7FB0;
void effect_start_sprite_slide(s32 arg0, u16 arg1, s32 arg2);
void player_update_map_cursor(Unk_801E076C *arg0, Unk_801E07C0 *arg1);
void effect_weapon_calc_rate(s32 a);

INCLUDE_RODATA("asm/nonmatchings/game/80195DF0", D_80170EDC);

INCLUDE_RODATA("asm/nonmatchings/game/80195DF0", D_80170EFC);

INCLUDE_RODATA("asm/nonmatchings/game/80195DF0", D_80170F14);

s16 player_try_slide(s16 arg0, s16 arg1, s32 *arg2, s32 *arg3, s32 arg4, s32 arg5) {
    s16 ret = arg1;

    switch (arg1) {
    case 0:
        *arg2 -= arg4;
        *arg3 -= arg5;
        ret = 1;
        player_slide_dx = arg4 < 0 ? -2 : arg4 > 0 ? 2 : 0;
        player_slide_dz = arg5 < 0 ? -2 : arg5 > 0 ? 2 : 0;
        if (arg0 != 2) {
            player_slide_dx *= 10;
            player_slide_dz *= 10;
        }
        if (player_slide_dx != 0) {
            *arg2 += player_slide_dx;
        } else {
            *arg2 += player_slide_dz;
        }
        break;
    case 1:
        ret = 2;
        if (player_slide_dx != 0) {
            *arg2 -= player_slide_dx;
        } else {
            *arg2 -= player_slide_dz;
        }
        if (player_slide_dz != 0) {
            *arg3 += player_slide_dz;
        } else {
            *arg3 += player_slide_dx;
        }
        break;
    case 2:
        ret = 4;
        if (player_slide_dz != 0) {
            *arg3 -= player_slide_dz;
        } else {
            *arg3 -= player_slide_dx;
        }
        if (player_slide_dz != 0) {
            *arg3 -= player_slide_dz;
        } else {
            *arg3 -= player_slide_dx;
        }
        break;
    case 4:
        ret = 3;
        if (player_slide_dz != 0) {
            *arg3 += player_slide_dz;
        } else {
            *arg3 += player_slide_dx;
        }
        if (player_slide_dx != 0) {
            *arg2 -= player_slide_dx;
        } else {
            *arg2 -= player_slide_dz;
        }
        break;
    case 3:
        ret = -1;
        if (player_slide_dx != 0) {
            *arg2 += player_slide_dx;
        } else {
            *arg2 += player_slide_dz;
        }
        break;
    }
    return ret;
}

void player_move_in_train(Unk_801E0620 *arg0, u16 arg1) {
    s32 v[3];
    s16 rot[3];
    s16 dir[3];
    s16 cam[3];
    s32 y;
    s32 flag;
    Unk_801E032C *m;
    s32 ox;
    s32 oz;
    Unk_801E1118 *p;
    s32 dx;
    s32 dz;
    s32 sx;
    s32 sz;
    s32 col;
    s16 moved;
    s16 step;

    ox = arg0->unk54;
    oz = arg0->unk5C;
    rot[0] = (-arg0->unk6C << 12) / 360;
    rot[1] = (-arg0->unk6E << 12) / 360;
    rot[2] = (-arg0->unk70 << 12) / 360;
    col = 0x1000000;
    moved = 0;
    step = 0;
    y = 0;
    p = &D_801E1118;
    m = D_801E032C[0];
    if (arg0->unk42 & 0x800) {
        arg0->unk44 = 0;
    } else {
        dir[0] = 0;
        dir[2] = 0;
        cam[0] = (p->unk34 << 12) / 360;
        cam[1] = (p->unk36 << 12) / 360;
        cam[2] = (p->unk38 << 12) / 360;
        dir[1] = ((p->unk36 + 90) << 12) / 360;
        if (arg0->unk3E != 0) {
            block_update_visibility(arg1);
            col = func_8017BBB0(arg0->unk54, arg0->unk5C, &y);
            if (arg0->unk3E == 1) {
                col = 0x1000000;
            }
            arg0->unk3E = 0;
            player_check_ground(arg0, col, 0, 0);
            arg0->unk58 = y + arg0->unk78;
        } else {
            dx = (arg0->unk50 * rsin(cam[1])) >> 12;
            dz = (arg0->unk50 * rcos(cam[1])) >> 12;
            sx = (arg0->unk4E * rsin(dir[1])) >> 12;
            sz = (arg0->unk4E * rcos(dir[1])) >> 12;
            if (dx == 0 && dz == 0 && (sx != 0 || sz != 0)) {
                moved = 1;
            }
            dx += sx;
            dz += sz;
            if (dx != 0 || dz != 0) {
                p->unk2C += dx;
                p->unk30 += dz;
            loop:
                GsSetLsMatrix(m->unk1C);
                RotTrans(&p->unk2C, v, &flag);
                arg0->unk54 = v[0];
                arg0->unk5C = v[2];
                block_stream_update(arg1);
                block_update_visibility(arg1);
                col = func_8017BBB0(arg0->unk54, arg0->unk5C, &y);
            } else {
                block_stream_update(arg1);
                block_update_visibility(arg1);
            }
            if (player_check_ground(arg0, col, moved, step) != 0) {
                arg0->unk58 = y + arg0->unk78;
            } else {
                step = player_try_slide(2, step, (s32 *)&p->unk2C, (s32 *)&p->unk30, dx, dz);
                if (step != -1) {
                    goto loop;
                }
                arg0->unk54 = ox;
                arg0->unk5C = oz;
                arg0->unk44 = 5;
            }
            player_wrap_cell(arg0);
        }
    }
    player_update_view(arg0, rot, 2);
}

void player_place_in_car(Unk_801E0620 *arg0, Unk_801E032C *arg1, Unk_801E1158 *arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6) {
    s32 v[3];
    s16 rot[3];
    s32 flag;

    arg1->unk4 += arg3;
    arg1->unkC += arg4;
    arg1->unk12 += arg5;
    arg1->unk30 = arg1->unk4 - arg0->unk72 * 0x30D4;
    arg1->unk34 = arg1->unk8 + arg0->unk74 * 0x7D00;
    arg1->unk38 = arg1->unkC - arg0->unk76 * 0x30D4;
    rot[0] = (arg1->unk10 << 12) / 360;
    rot[1] = (arg1->unk12 << 12) / 360;
    rot[2] = (arg1->unk14 << 12) / 360;
    RotMatrixZXY(rot, arg1->unk1C);
    if (arg6 != 0) {
        arg1->unk18 = 0;
    }
    GsSetLsMatrix(arg1->unk1C);
    RotTrans(arg2->unk1C, v, &flag);
    arg0->unk54 = v[0];
    arg0->unk58 = v[1] - 0x172;
    arg0->unk5C = v[2];
    arg0->unk6C = arg2->unk24;
    arg0->unk6E = arg2->unk26 + arg1->unk12;
    arg0->unk70 = arg2->unk28;
    if (arg0->unk6E >= 0x168) {
        arg0->unk6E -= 0x168;
    }
    if (arg0->unk6E < 0) {
        arg0->unk6E += 0x168;
    }
    if (arg1->unk12 >= 0x168) {
        arg1->unk12 -= 0x168;
    }
    if (arg1->unk12 < 0) {
        arg1->unk12 += 0x168;
    }
}

void player_move_in_car(Unk_801E0620 *arg0, s32 arg1) {
    s16 rot[3];
    s32 y;
    Unk_801E1158 *p;
    Unk_801E032C *m;
    s32 dx;
    s32 dz;
    s32 c;
    s32 s;
    s32 d;
    s32 r;
    s16 a;
    s16 b;
    s16 ang;

    p = &D_801E1158;
    y = 0;
    m = D_801E032C[0];
    if (arg0->unk3E != 0) {
        block_update_visibility(arg1);
        r = block_fit_ground_tilt(&y, 1);
        if (r == 0xFFFF || r == 0xFF00) {
            m->unk8 = y;
        }
        arg0->unk3E = 0;
    } else {
        if (p->unk18 == 0) {
            ang = (m->unk12 << 12) / 360;
            dx = (p->unk10 * rsin(ang)) >> 12;
            dz = (p->unk10 * rcos(ang)) >> 12;
        } else {
            d = SquareRoot0(p->unk18 * p->unk18 + p->unk10 * p->unk10);
            c = (p->unk18 << 12) / d;
            s = (p->unk10 << 12) / d;
            if (c > 0x1000) {
                c = 0x1000;
            }
            if (s > 0x1000) {
                s = 0x1000;
            }
            rot[0] = a = p->unk4C - p->unk5C;
            rot[1] = 0;
            rot[2] = b = p->unk54 - p->unk64;
            dx = ((c * a + s * b) >> 12) + p->unk5C;
            dz = ((c * b - s * a) >> 12) + p->unk64;
            if (p->unk4 < 0) {
                dx = p->unk4C - dx;
                dz = p->unk54 - dz;
            } else {
                dx = dx - p->unk4C;
                dz = dz - p->unk54;
            }
        }
        if (dx != 0 || dz != 0) {
            player_place_in_car(arg0, m, p, dx, dz, p->unk14, 0);
            block_stream_update(arg1);
            block_update_visibility(arg1);
            r = block_fit_ground_tilt(&y, 0);
            if (r == 0xFFFF || r == 0xFF00) {
                m->unk8 = y;
            } else {
                m->unk4 -= dx;
                m->unkC -= dz;
                m->unk12 -= p->unk14;
                p->unkC = 0;
                p->unk8 = 0;
                p->unk6 = 0;
            }
        } else {
            player_place_in_car(arg0, m, p, 0, 0, 0, 0);
            block_stream_update(arg1);
            block_update_visibility(arg1);
        }
    }
    player_place_in_car(arg0, m, p, 0, 0, 0, 1);
    player_wrap_cell(arg0);
    rot[0] = (-arg0->unk6C << 12) / 360;
    rot[1] = (-arg0->unk6E << 12) / 360;
    rot[2] = (-arg0->unk70 << 12) / 360;
    player_update_view(arg0, rot, 2);
}

void player_move_on_foot(Unk_801E0620 *arg0, u16 arg1, s16 arg2, s16 arg3) {
    s16 rot[3];
    s16 dir[3];
    s32 y;
    s32 col;
    s32 s;
    s32 c;
    s32 dx;
    s32 dz;
    s32 sx;
    s32 sz;
    s32 px;
    s32 pz;
    s32 t;
    Unk_801762F4 *e;
    s16 moved;
    u16 r3;
    s16 r2;
    s16 r1;
    s16 step;

    dz = 0;
    dx = 0;
    moved = 0;
    step = 0;
    y = 0;
    if ((arg0->unk42 & 1) || (arg0->unk42 & 0x10)) {
        col = 0x2000000;
        y = 700;
    } else {
        col = 0x1000000;
    }
    rot[0] = (-arg0->unk6C << 12) / 360;
    rot[1] = (-arg0->unk6E << 12) / 360;
    rot[2] = (-arg0->unk70 << 12) / 360;
    if (*(s32 *)&arg0->unk40 & 0x09020000) {
        arg0->unk44 = 0;
    } else {
        if (!(arg0->unk42 & 0x39)) {
            dir[0] = 0;
            dir[1] = (-(arg0->unk6E + 90) << 12) / 360;
            dir[2] = 0;
            col = 0x1000000;
            if (arg0->unk3E != 0) {
                if (arg3) {
                    block_update_visibility(arg1);
                }
                switch (arg1) {
                case 1:
                    col = block_find_surface_nearest(arg0->unk54, arg0->unk58 - arg0->unk78, arg0->unk5C, &y);
                    break;
                case 0:
                case 2:
                    col = block_find_surface(arg0->unk54, arg0->unk5C, &y, 1);
                    break;
                }
                if (arg0->unk3E == 1) {
                    col = 0x1000000;
                }
                arg0->unk3E = 0;
                player_check_ground(arg0, col, moved, step);
                arg0->unk58 = y + arg0->unk78;
                goto end;
            }
            s = rsin(-rot[1]);
            c = rcos(-rot[1]);
            dx = (arg0->unk50 * s) >> 12;
            dz = (arg0->unk50 * c) >> 12;
            sx = (arg0->unk4E * rsin(-dir[1])) >> 12;
            sz = (arg0->unk4E * rcos(-dir[1])) >> 12;
            if (dx == 0 && dz == 0 && (sx != 0 || sz != 0)) {
                moved = 1;
            }
            dx += sx;
            dz += sz;
            if (dx != 0 || dz != 0) {
                arg0->unk54 += dx;
                arg0->unk5C += dz;
            loop:
                if (arg0->unk50 < 0) {
                    px = -(s * 600) >> 12;
                    pz = -(c * 600) >> 12;
                } else {
                    px = (s * 600) >> 12;
                    pz = (c * 600) >> 12;
                }
                r1 = mod_npcrec_find_at_point(arg0->unk54 + px, arg0->unk58 - arg0->unk78, arg0->unk5C + pz);
                if (r1 >= 0) {
                    col = r1 + 0xF70000;
                } else {
                    r2 = npc_find_at_point(-1, arg0->unk54 + px, arg0->unk58 - arg0->unk78, arg0->unk5C + pz);
                    if (r2 >= 0) {
                        e = npc_find(0, r2);
                        if (e != NULL && e->unkF == 6) {
                            y = e->unk24 + arg0->unk74 * 32000;
                        }
                        col = r2 + 0xFC0000;
                    } else {
                        r3 = thing_hit_test(arg0->unk54, arg0->unk58 - arg0->unk78, arg0->unk5C, arg1);
                        if (r3 != 0xFFFF) {
                            col = r3 + 0xFD0000;
                        } else {
                            if (arg2) {
                                block_stream_update(arg1);
                            }
                            if (arg3) {
                                block_update_visibility(arg1);
                            }
                            switch (arg1) {
                            case 1:
                                col = block_find_surface_nearest(arg0->unk54, arg0->unk58 - arg0->unk78, arg0->unk5C, &y);
                                break;
                            case 0:
                            case 2:
                                col = block_find_surface(arg0->unk54, arg0->unk5C, &y, 1);
                                break;
                            }
                        }
                    }
                }
            } else {
                if (arg2) {
                    block_stream_update(arg1);
                }
                if (arg3) {
                    block_update_visibility(arg1);
                }
            }
        }
        if (player_check_ground(arg0, col, moved, step) != 0) {
            t = y + arg0->unk78;
            if (t < arg0->unk58) {
                arg0->unk40 = 1;
            }
            if (arg0->unk58 < t) {
                arg0->unk40 = 0;
            }
            arg0->unk58 = t;
        } else if (r1 >= 0 || r2 >= 0 || r3 != 0xFFFF || D_801DFD5C != 0 || D_801DFD5E != 0) {
            arg0->unk54 -= dx;
            arg0->unk5C -= dz;
        } else {
            step = player_try_slide(arg1, step, &arg0->unk54, &arg0->unk5C, dx, dz);
            if (step != -1) {
                goto loop;
            }
            arg0->unk44 = 5;
        }
        player_wrap_cell(arg0);
    }
end:
    player_update_view(arg0, rot, arg1);
}

void player_init(void) {
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E0770 *q = &D_801E0770;
    Unk_801E0620 *r = &D_801E0620;
    Unk_801E0368 *o;
    s16 sv[3];
    s32 i;

    memset(p, 0, 0x60);
    p->unk0 = 0xC9;
    p->unk2 = 1;
    p->unk8 = 0x144;
    p->unk36 = 2;
    p->unkC = 1;
    p->unkE = 1;
    p->unk10 = 1;
    p->unk12 = 1;
    p->unk14 = 1;
    p->unk18 = 1;
    p->unk1C = 1;
    p->unk20 = 1;
    p->unk24 = 1;
    p->unk28 = 1;
    p->unk44 = 1;
    p->unk46 = 1;
    p->unk48 = 1;
    p->unk4A = 0;
    o = &D_801E0368;
    memset(q, 0, 0x50);
    for (i = 0; i < 8; i++) {
        q->unk32[i] = -1;
    }
    o->unk78 = 1;
    q->unk4[1] = -1;
    q->unk42 = 0xF;
    memset(r, 0, 0xF0);
    r->unk0 = 0x5C30;
    r->unk8 = -0x1004;
    r->unk4 = 0;
    r->unk10 = 0;
    r->unk12 = 0xB4;
    r->unk14 = 0;
    r->unk3E = 1;
    r->unk40 = 1;
    r->unk48 = -1;
    sv[0] = 0;
    sv[1] = 0;
    sv[2] = 0;
    RotMatrix(sv, r->unk7C);
    ApplyMatrixLV(r->unk7C, r->unk90, r->unk90);
    r->unk9C = 0;
    GsSetView2(r->unk7C);
    GsInitCoordinate2(NULL, r->unkA0);
    p->unk58 = q;
    p->unk5C = (Unk_801E076C *)r;
}

void player_place_for_scene(u16 arg0) {
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E1040 *f = &D_801E1040;
    Unk_801E0340 *q = &D_801E0340;
    Unk_801E0620 *r;
    s16 rot[3];
    s32 v;

    p->unk4C = NULL;
    p->unk4A = 0;
    f->unk0[2] = 0;
    q->unkA = 0;
    D_801E0610.unk4 = 0;
    D_801E0600.unk4 = 0;
    D_801E0600.unk0 = 0xFFFFFF;
    D_801E0610.unk0 = 0xFFFFFF;
    D_801E0610.unk8 = 0;
    D_801E0600.unk8 = 0;
    r = &D_801E0620;
    r->unk42 &= ~4;
    r->unk3E = 1;
    r->unk3C = 1;
    r->unk40 = 1;
    r->unk78 = -0x640;
    D_801DFF48 = 0xFFFFFF;
    r->unk44 = 0;
    r->unk4C = 0;
    r->unk4A = 4;
    r->unk42 = 0;
    switch (arg0) {
    case 0:
        if (q->unk12 != 0) {
            r->unk54 = 0xCE4;
            r->unk58 = -0x384;
            r->unk5C = 0x1AF4;
            r->unk42 = 1;
            r->unk6C = 0;
            r->unk6E = 0x96;
            r->unk70 = 0;
        } else {
            r->unk54 = 0xDAC;
            r->unk58 = -0x640;
            r->unk5C = 0x2BC;
            r->unk6C = 0;
            r->unk6E = 0;
            r->unk70 = 0;
        }
        break;
    case 1:
        if (q->unk10 < 3) {
            if (q->unk10 > 0) {
                f->unk0[2] = 1;
                SetFogNearFar(0x30D4, 0xFFFF, 0xE4);
            }
        }
        r->unk6C = 0;
        r->unk70 = 0;
        r->unk58 += r->unk78;
        r->unk6E = (u32)q->unk18 >> 16;
        break;
    case 2:
        f->unk0[2] = 1;
        SetFogNearFar(0x1388, 0x2710, 0xE4);
        r->unk78 = -0xAA;
        r->unk6C = 0;
        r->unk70 = 0;
        r->unk54 = q->unk14;
        r->unk58 = q->unk18 + r->unk78;
        r->unk5C = q->unk1C;
        r->unk6E = q->unk12;
        switch (r->unk46) {
        case 0:
            r->unk6C = 0xC;
            break;
        case 2:
        case 3:
            v = -0x2A8;
            r->unk78 = v;
            r->unk58 = q->unk18 + v;
            break;
        }
        break;
    case 3:
        r->unk54 = 0;
        r->unk58 = 0;
        r->unk5C = 0;
        r->unk6C = 0;
        r->unk6E = 0;
        r->unk70 = 0;
        break;
    }
    player_set_view((Unk_801E076C *)r, 0);
    player_wrap_cell(r);
    if (arg0 == 1) {
        r->unkA0->unk18 = r->unk54;
        r->unkA0->unk1C = r->unk58 - r->unk4C + 0x140;
        r->unkA0->unk20 = r->unk5C;
        rot[0] = (r->unk6C << 12) / 360;
        rot[1] = (r->unk6E << 12) / 360;
        rot[2] = (r->unk70 << 12) / 360;
        RotMatrixZYX(rot, r->unkA0->unk4);
        r->unkA0->unk0 = 0;
    }
}

void player_finish_death(void) {
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E0340 *q = &D_801E0340;
    Unk_801E0368 *o = &D_801E0368;
    s32 i;
    s16 v;

    if (o->unk60 == 0 && p->unk4A != 0) {
        p->unk0 = 0xFF;
        p->unk36 = 0;
        p->unk34 = 0;
        if (p->unk2C == 0) {
            p->unk2C = 1;
            o->unk0[6] = 1;
            o->unk62[0] = p->unk2;
            o->unk62[1] = p->unkC;
            o->unk62[2] = p->unkE;
            o->unk62[3] = p->unk10;
            o->unk62[4] = p->unk12;
            o->unk62[5] = p->unk14;
            o->unk62[6] = p->unk18;
            o->unk62[7] = p->unk1C;
            o->unk62[8] = p->unk20;
            o->unk62[9] = p->unk24;
            o->unk62[10] = p->unk28;
            for (i = 9; i < 0x1C; i++) {
                v = o->unk0[i];
                o->unk0[i] = 2000;
                o->unk28[i] = v;
            }
        }
        p->unk2 = 100;
        p->unkC = 100;
        p->unkE = 100;
        p->unk10 = 100;
        p->unk12 = 100;
        p->unk14 = 100;
        p->unk18 = 100;
        p->unk1C = 100;
        p->unk20 = 100;
        p->unk24 = 100;
        p->unk28 = 100;
        for (i = 0; i < 5; i++) {
            p->unk3A[i] = 0;
            o->unkB4[i] = 0;
        }
        mail_goto_building(1, player_str_scene_cmn, 0x18, 0x41, 7, 0xB4, 0x15, 0x500F07, 1);
        event_draw_gauge(p);
        event_draw_limb_status(p);
    } else {
        q->unk0[4] = 1;
        q->unkA = 1;
    }
}

void player_start_death(u16 arg0, Unk_801E0710 *arg1, Unk_801E0620 *arg2) {
    Unk_801E0368 *o = &D_801E0368;
    s32 v;

    if (D_801E1046[0] == 0 && o->unk24C == 0 && roadmap_get_state() == 0
        && arg2->unk46 != 1 && !(arg2->unk42 & 0x8000) && !(arg2->unk42 & 0x4802)) {
        arg2->unk42 |= 0x800;
        if (arg2->unk46 != 0) {
            player_finish_death();
            return;
        }
        v = 0x514;
        if (arg0 == 2) {
            v = 0x82;
        }
        player_start_move_to(0, 0, arg2->unk54 + arg2->unk72 * 0x30D4,
                      arg2->unk58 - arg2->unk74 * 0x7D00 - arg2->unk78 + v,
                      arg2->unk5C + arg2->unk76 * 0x30D4, -0x4B, arg2->unk6E, arg2->unk70, 4);
    }
}

void player_update(u16 arg0, s16 arg1, s16 arg2) {
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E0620 *r = &D_801E0620;

    if (p->unk0 <= 0) {
        player_start_death(arg0, p, r);
    }
    event_update_hud(p);
    r->unk44 = 0;
    if (r->unk3C == 0) {
        if (arg1 != 0) {
            block_stream_update(arg0);
        }
        if (arg2 != 0) {
            block_update_visibility(arg0);
        }
    } else {
        if (!(r->unk42 & 0x800) && !(r->unk42 & 2)) {
            if (r->unk6C > 0x41) {
                r->unk6C = 0x41;
            }
            if (r->unk6C < -0x19) {
                r->unk6C = -0x19;
            }
            if (r->unk6E >= 0x168) {
                r->unk6E -= 0x168;
            }
            if (r->unk6E < 0) {
                r->unk6E += 0x168;
            }
        }
        if (arg0 == 2) {
            switch (r->unk46) {
            case 0:
                player_move_on_foot(r, 2, arg1, arg2);
                event_draw_compass(r);
                break;
            case 1:
                player_move_in_car(r, 2);
                event_draw_compass(r);
                r->unk4E = 0;
                r->unk50 = 0;
                return;
            case 2:
            case 3:
                player_move_in_train(r, arg0);
                break;
            default:
                r->unk4E = 0;
                r->unk50 = 0;
                return;
            }
        } else {
            player_move_on_foot(r, arg0, arg1, arg2);
        }
    }
    sound_footstep_update(r);
    r->unk4E = 0;
    r->unk50 = 0;
}

void player_add_skill_exp(s16 arg0, s16 arg1) {
    Unk_801E0710 *p = &D_801E0710;
    s16 flag = 0;
    u16 a;
    u16 b;
    u16 lim;
    s32 i;

    switch (arg0) {
    case 0:
        a = p->unk14;
        b = p->unk16;
        break;
    case 1:
        a = p->unk18;
        b = p->unk1A;
        break;
    case 2:
        a = p->unk1C;
        b = p->unk1E;
        break;
    case 3:
        a = p->unk20;
        b = p->unk22;
        break;
    case 4:
        a = p->unk24;
        b = p->unk26;
        break;
    case 5:
        a = p->unk28;
        b = p->unk2A;
        break;
    }
    if (a == 100) {
        return;
    }
    b += arg1;
    if (a == 1) {
        lim = 0x144;
    } else {
        lim = (a - 2) * 0xA2 + 0x195;
    }
    if (b >= lim) {
        a++;
        b -= lim;
        flag = 1;
    }
    switch (arg0) {
    case 0:
        p->unk14 = a;
        p->unk16 = b;
        break;
    case 1:
        p->unk18 = a;
        p->unk1A = b;
        break;
    case 2:
        p->unk1C = a;
        p->unk1E = b;
        break;
    case 3:
        p->unk20 = a;
        p->unk22 = b;
        break;
    case 4:
        p->unk24 = a;
        p->unk26 = b;
        break;
    case 5:
        p->unk28 = a;
        p->unk2A = b;
        break;
    }
    if (flag && arg0 != 5) {
        for (i = 0; i < 2; i++) {
            effect_weapon_calc_rate(i);
        }
    }
}

void player_add_exp(s32 arg0) {
    Unk_801E0710 *p = &D_801E0710;
    s32 i;

    if (p->unk2 == 100) {
        return;
    }
    p->unk4 += arg0;
    if (p->unk4 < (u32)p->unk8) {
        return;
    }
loop:
    p->unk2++;
    if (p->unk2 < 100) {
        p->unk8 = mail_exp_for_level(p->unk2);
    }
    p->unkC += rand() % 3;
    if ((u16)p->unkC > 100) {
        p->unkC = 100;
    }
    p->unkE += rand() % 3;
    if ((u16)p->unkE > 100) {
        p->unkE = 100;
    }
    p->unk10 += rand() % 3;
    if ((u16)p->unk10 > 100) {
        p->unk10 = 100;
    }
    p->unk12 += rand() % 3;
    if ((u16)p->unk12 > 100) {
        p->unk12 = 100;
    }
    for (i = 0; i < 2; i++) {
        effect_weapon_calc_rate(i);
    }
    if (p->unk4 >= (u32)p->unk8) {
        goto loop;
    }
}

s32 player_pick_hit_part(s16 arg0) {
    if (rand() % 100 < 15) {
        return 0;
    }
    switch (arg0) {
    case 2:
    case 6:
        if (rand() % 100 < 30) {
            return 4;
        }
        return 3;
    case 0:
        if (rand() % 100 < 30) {
            return 4;
        }
        return 2;
    case 4:
        if (rand() % 100 < 30) {
            return 4;
        }
        return 1;
    case 1:
    case 7:
        if (rand() % 100 < 30) {
            return 4;
        }
        if (rand() % 100 < 30) {
            return 3;
        }
        return 2;
    case 3:
    case 5:
        if (rand() % 100 < 30) {
            return 4;
        }
        if (rand() % 100 < 30) {
            return 3;
        }
        return 1;
    }
}

void player_take_hit(Unk_801762F4 *arg0, s32 arg1, s32 arg2) {
    Unk_801E0710 *p;
    Unk_801E0620 *q;
    Unk_801E0368 *r;
    s32 n;
    s32 t;
    s32 div;
    s16 dir;
    s16 k;

    p = &D_801E0710;
    q = &D_801E0620;
    r = &D_801E0368;
    if (p->unk0 > 0) {
        div = 1;
        n = rand() % (u16)p->unk12;
        dir = mail_angle_to_dir8(q->unk6E - arg0->unk3A);
        switch (dir) {
        case 6:
            arg2 = arg2 * 3 / 2;
        case 5:
        case 7:
            k = player_pick_hit_part(dir);
            break;
        default:
            n += rand() % (u16)p->unk28;
            switch (arg1) {
            case 0:
            case 1:
                div = 5;
                n += rand() % (u16)p->unkC;
                t = rand() % (u16)p->unkE;
                switch (p->unk3A[4]) {
                case 2:
                    t = t * 2 / 3;
                    break;
                case 3:
                    t >>= 1;
                    break;
                }
                n += t;
                n += rand() % (u16)p->unk10;
                break;
            case 2:
            case 3:
                div = 3;
                n += rand() % (u16)p->unkE;
                break;
            case 4:
                div = 3;
                n += rand() % (u16)p->unk10;
                break;
            }
            k = player_pick_hit_part(dir);
            n /= div;
            break;
        }
        player_add_skill_exp(5, n * 10);
        arg2 -= n * 2;
        if (arg2 > 0) {
            *(r->unkB4 + k) += arg2;
            if (k == 0) {
                p->unk0 -= arg2;
                if ((u16)arg0->unk2 != 0) {
                    p->unk4A = 1;
                }
            }
            event_draw_gauge(p);
            event_draw_limb_status(p);
            event_set_blink(2, 1);
            roadmap_start_flash(0xFF, 0, 0, 1);
        }
    }
}

void player_pick_target(void) {
    Unk_801E02D8 *g = &D_801E02D8;
    Unk_801762F4 *e = g->unk3C;
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E0770 *q;
    s16 v;
    s32 i;

    p->unk4C = NULL;
    q = p->unk58;
    if (g->unk1C != 0) {
        v = q->unk4[q->unk2];
        for (i = 0; i < g->unk1C; i++, e++) {
            if (e->unk4 != 0 && e->unk6 != 0 && e->unkE != 2 && !(e->unk12 & 0x200) && (e->unk12 & 2)
                && e->unk40 != 0 && ai_in_aim_cone(e, 0, v) != 0) {
                if (p->unk4C == NULL || e->unk40 < p->unk4C->unk40) {
                    p->unk4C = e;
                }
            }
        }
        if (p->unk4C != NULL) {
            return;
        }
    }
    if (q->unk46 == 0) {
        q->unk46 = 1;
    }
}

void player_shoot_target(void) {
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0620 *d = &D_801E0620;
    Unk_801E0770 *s = &D_801E0770;
    Unk_801762F4 *p = g->unk4C;
    Unk_80188FEC *e;
    s32 dist;
    s32 chance;
    s32 f;
    s32 a;
    s32 b;
    s32 c;
    s32 m;
    s32 t;
    s32 k;
    s32 w;
    s32 amt;
    s32 miss;

    if (!(d->unk42 & 0x400)) {
        return;
    }
    d->unk42 &= ~0x400;
    if (s->unk46 == 0 || p == NULL || p->unkE == 2 || (p->unk12 & 0x200) || !(p->unk12 & 2)) {
        return;
    }
    t = npc_get_radius(p) + 600;
    k = p->unk40;
    dist = k - t;
    if (dist < 0) {
        dist = 0;
    }
    e = effect_weapon_find(s->unk4[s->unk2]);
    if (e == NULL) {
        return;
    }
    chance = 0;
    a = e->unk54 * 10;
    b = e->unk58 * 10;
    c = e->unk5C * 10;
    m = s->unk8[s->unk2];
    f = 0;
    if (dist < a) {
        chance = -1;
    } else if (dist < b) {
        f = 0x1000;
    } else if (dist < c) {
        f = ((c - dist) << 12) / (c - b);
    }
    if (dist >= a) {
        chance = (m * f) >> 12;
    }
    if (e->unk2 == 0) {
        w = d->unk58 - d->unk74 * 32000 - p->unk24 + 1600;
        if (w > 0) {
            w = -w;
        }
        if (w < -1600) {
            return;
        }
        if (f == 0) {
            chance = 0;
        }
    }
    if (chance < 20) {
        if (chance == 0) {
            npc_apply_damage(p, e->unk2, 0, 0);
            return;
        }
        if (chance < 0) {
            f = 0x1000;
        }
        chance = 20;
    }
    if ((u16)d->unk44 == 1 || (u16)d->unk44 == 3) {
        chance = chance * 9 / 10;
    }
    switch (g->unk3A[1]) {
    case 2:
        chance = chance * 9 / 10;
        break;
    case 3:
        chance = chance * 7 / 10;
        break;
    }
    if (rand() % 100 < chance) {
        miss = 0;
        amt = (e->unk52 * f) >> 12;
        k = e->unk0;
        switch (k) {
        case 14:
            if ((u16)p->unk2 == 4) {
                amt *= 2;
            }
            break;
        case 16:
        case 17:
            if ((u16)p->unk2 == 0 || (u16)p->unk2 == 4) {
                amt = (e->unk52 * f) >> 13;
            }
            break;
        }
    } else {
        miss = 1;
        amt = 0;
    }
    npc_apply_damage(p, e->unk2, amt, miss);
}

void player_move_to_step(Unk_80198ADC *arg0) {
    Unk_80198ADC_3C *e = arg0->unk3C;
    Unk_801E0620 *p = &D_801E0620;

    p->unk54 = e->unk4 + e->unk24 * arg0->unk24 / arg0->unk26;
    p->unk58 = e->unk8 + e->unk28 * arg0->unk24 / arg0->unk26;
    p->unk5C = e->unkC + e->unk2C * arg0->unk24 / arg0->unk26;
    p->unk6C = e->unk34 + e->unk44 * arg0->unk24 / arg0->unk26;
    p->unk6E = e->unk36 + e->unk46 * arg0->unk24 / arg0->unk26;
    p->unk70 = e->unk38 + e->unk48 * arg0->unk24 / arg0->unk26;
    p->unk3C = 1;
}

void player_start_move_to(s16 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, s16 arg7, s32 arg8) {
    Unk_80198ADC *t;
    Unk_80198ADC_3C *p;
    u16 ax;
    u16 ay;
    u16 az;
    s16 dz;
    Unk_801E0620 *d;

    d = &D_801E0620;
    ax = arg5;
    ay = arg6;
    az = arg7;
    t = kaj_tss_alloc(0x4C);
    t->unk22 = 4;
    t->unk28 = 1;
    t->unk2C = 2;
    t->unk30 = player_move_to_step;
    t->unk24 = 0;
    t->unk34 = player_move_to_done;
    t->unk38 = player_move_to_done;
    p = t->unk3C;
    t->unk26 = arg8 * 30;
    p->unk0 = arg0;
    p->unk2 = arg1;
    arg2 -= d->unk72 * 12500;
    arg3 += d->unk78 + d->unk74 * 32000;
    arg4 -= d->unk76 * 12500;
    if (d->unk54 == arg2 && d->unk58 == arg3 && d->unk5C == arg4 &&
        d->unk6C == arg5 && d->unk6E == arg6 && d->unk70 == arg7) {
        t->unk26 = 0;
    }
    p->unk4 = d->unk54;
    p->unk8 = d->unk58;
    p->unkC = d->unk5C;
    p->unk34 = d->unk6C;
    p->unk36 = d->unk6E;
    p->unk38 = d->unk70;
    p->unk14 = arg2;
    p->unk18 = arg3;
    p->unk1C = arg4;
    p->unk3C = ax;
    p->unk3E = ay;
    p->unk40 = az;
    p->unk24 = arg2 - d->unk54;
    p->unk28 = arg3 - d->unk58;
    p->unk2C = arg4 - d->unk5C;
loop:
    p->unk44 = ax - d->unk6C;
    p->unk46 = ay - d->unk6E;
    p->unk48 = dz = az - d->unk70;
    if (p->unk44 > 180) {
        ax -= 360;
        goto loop;
    }
    if (p->unk44 < -180) {
        ax += 360;
        goto loop;
    }
    if (p->unk46 > 180) {
        ay -= 360;
        goto loop;
    }
    if (p->unk46 < -180) {
        ay += 360;
        goto loop;
    }
    if (dz > 180) {
        az -= 360;
        goto loop;
    }
    if (dz < -180) {
        az += 360;
        goto loop;
    }
    d->unk42 |= 2;
    d->unk48 = kaj_tss_start(t);
}

void player_exec_command(Unk_80199034 *arg0, Unk_801762F4 *arg1) {
    Unk_801E0620 *d = &D_801E0620;
    s16 a;
    s16 b;
    s16 v;
    s32 x;
    s32 y;
    s32 z;
    s16 e;
    s32 f;
    u16 g;
    Unk_801E0710 *p;

    switch (arg0->unk0->unk2) {
    case 0:
        a = atoi(arg0->unk8[1]);
        if ((s16)atoi(arg0->unk8[0]) != 0) {
            effect_item_add(a, 2);
        } else {
            effect_item_remove(a, 2);
        }
        break;
    case 1:
        x = atoi(arg0->unk8[0]) * 10;
        y = atoi(arg0->unk8[1]) * 10;
        z = atoi(arg0->unk8[2]) * 10;
        e = atoi(arg0->unk8[3]);
        f = atoi(arg0->unk8[4]);
        g = atoi(arg0->unk8[5]);
        if (atoi(arg0->unk8[6]) == 1) {
            arg1->unk6 = 4;
            arg1->unk12 |= 0x20;
        }
        player_start_move_to(0, g, x, y, z, 0, e, 0, f);
        break;
    case 2:
        a = atoi(arg0->unk8[0]);
        b = atoi(arg0->unk8[1]);
        if (a != 0) {
            effect_weapon_add(b, 1);
        } else {
            effect_weapon_unequip(b);
        }
        break;
    case 3:
        if (atoi(arg0->unk8[0]) != 0) {
            if (!(d->unk42 & 0x100)) {
                d->unk42 |= 0x100;
            }
        } else {
            if (d->unk42 & 0x100) {
                d->unk42 &= ~0x100;
            }
        }
        break;
    case 4:
        a = atoi(arg0->unk8[0]);
        b = atoi(arg0->unk8[1]);
        p = &D_801E0710;
        if (a < 0) {
            p->unk4A = 0;
        }
        p->unk0 += a;
        v = p->unk0;
        if (v > 255) {
            p->unk0 = 255;
        } else if (v < 0) {
            p->unk0 = 0;
            if (b != 0) {
                p->unk0 = b;
            }
        } else if (v > 0 && v < 255 && v < b) {
            p->unk0 = b;
        }
        event_draw_gauge(p);
        break;
    }
}

void player_recover(s32 arg0, s32 arg1, s32 arg2, s16 arg3) {
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E0368 *o = &D_801E0368;
    Unk_801E076C *e = p->unk5C;
    s16 r;
    s32 i;

    if (p->unk2C != 0 && arg3 != 0) {
        p->unk2C = 0;
        o->unk0[6] = 0;
        p->unk2 = o->unk62[0];
        p->unkC = o->unk62[1];
        p->unkE = o->unk62[2];
        p->unk10 = o->unk62[3];
        p->unk12 = o->unk62[4];
        p->unk14 = o->unk62[5];
        p->unk18 = o->unk62[6];
        p->unk1C = o->unk62[7];
        p->unk20 = o->unk62[8];
        p->unk24 = o->unk62[9];
        p->unk28 = o->unk62[10];
        for (i = 9; i < 0x1C; i++) {
            o->unk0[i] = o->unk28[i];
        }
        sprite_set_clut_entry(0x400, 0x45, 0);
        /* " ミュータント状態から回復した" */
        text_show(D_80170EDC, 1, -1, 0, -1, 0, 0);
    } else {
        r = player_is_injured();
        if (r == 0 && arg3 == 0) {
            /* " 全身がとても軽くなった" */
            text_show(D_80170EFC, 1, -1, 0, -1, 0, 0);
        } else {
            /* " 傷が完全に回復した" */
            text_show(D_80170F14, 1, -1, 0, -1, 0, 0);
        }
    }
    for (i = 0; i < 5; i++) {
        p->unk3A[i] = 0;
        o->unkB4[i] = 0;
    }
    if (arg3 == 0) {
        event_advance_clock(0x3C, 1);
    }
    event_draw_gauge(p);
    event_draw_limb_status(p);
    e->unk54 = arg0;
    e->unk5C = arg2;
    e->unk58 = arg1 + e->unk78;
    player_set_view(e, 1);
}

void player_handle_pad(Unk_801E0710 *arg0, s32 arg1, s32 arg2) {
    Unk_801E076C *p;
    Unk_801E1118 *q;

    p = arg0->unk5C;
    q = &D_801E1118;
    if (arg2 & 0x1000) {
        p->unk3C = 1;
        if (p->unk46) {
            q->unk34 += D_801E6DB4[0];
        } else {
            p->unk6C += D_801E6DB4[0];
        }
    } else if (arg2 & 0x4000) {
        p->unk3C = 1;
        if (p->unk46) {
            q->unk34 -= D_801E6DB4[0];
        } else {
            p->unk6C -= D_801E6DB4[0];
        }
    }
    if (arg2 & 0x8000) {
        p->unk3C = 1;
        if (p->unk46) {
            q->unk36 -= D_801E6DB4[0];
        } else {
            p->unk6E -= D_801E6DB4[0];
        }
    } else if (arg2 & 0x2000) {
        p->unk3C = 1;
        if (p->unk46) {
            q->unk36 += D_801E6DB4[0];
        } else {
            p->unk6E += D_801E6DB4[0];
        }
    }
    if (p->unk42 & 0x100) {
        p->unk4A = 4;
        p->unk42 &= ~0x1000;
        return;
    }
    if (arg2 & 0x40) {
        p->unk3C = 1;
        if (p->unk42 & 0x1000) {
            if (p->unk4A >= 5) {
                p->unk4A--;
                p->unk50 = p->unk4A * D_801E6DB4[0];
            } else {
                p->unk4A = 4;
                p->unk42 &= ~0x1000;
                p->unk50 = D_801E6DB4[0] * 4;
            }
        } else {
            p->unk50 = -(D_801E6DB4[0] * 4);
        }
    } else if (arg2 & 0x10) {
        p->unk3C = 1;
        if ((u16)arg1 == 2 && (arg2 & 1)) {
            if (!(p->unk42 & 0x1000)) {
                p->unk42 |= 0x1000;
            }
            if (p->unk4A < 11) {
                p->unk4A++;
            }
            p->unk50 = D_801E6DB4[0] * p->unk4A;
        } else if (p->unk42 & 0x1000) {
            if (p->unk4A >= 5) {
                p->unk4A--;
                p->unk50 = p->unk4A * D_801E6DB4[0];
            } else {
                p->unk4A = 4;
                p->unk42 &= ~0x1000;
                p->unk50 = D_801E6DB4[0] * 4;
            }
        } else {
            p->unk50 = D_801E6DB4[0] * 4;
        }
    }
    if (arg2 & 4) {
        p->unk3C = 1;
        if (p->unk42 & 0x1000) {
            if (p->unk4A >= 5) {
                p->unk4A--;
                p->unk50 = p->unk4A * D_801E6DB4[0];
            } else {
                p->unk4A = 4;
                p->unk42 &= ~0x1000;
                p->unk50 = D_801E6DB4[0] * 4;
            }
        } else {
            p->unk4E = -(D_801E6DB4[0] * 6);
        }
    } else if (arg2 & 8) {
        p->unk3C = 1;
        if (p->unk42 & 0x1000) {
            if (p->unk4A >= 5) {
                p->unk4A--;
                p->unk50 = p->unk4A * D_801E6DB4[0];
            } else {
                p->unk4A = 4;
                p->unk42 &= ~0x1000;
                p->unk50 = D_801E6DB4[0] * 4;
            }
        } else {
            p->unk4E = D_801E6DB4[0] * 6;
        }
    }
    if (p->unk3C == 0 || (p->unk50 == 0 && p->unk4E == 0)) {
        if (!(p->unk42 & 0x1000)) {
            return;
        }
        p->unk3C = 1;
        if (p->unk4A >= 5) {
            p->unk4A--;
            p->unk50 = p->unk4A * D_801E6DB4[0];
        } else {
            p->unk4A = 4;
            p->unk42 &= ~0x1000;
            p->unk50 = D_801E6DB4[0] * 4;
        }
    }
    if ((u16)arg1 == 2) {
        if (p->unk46) {
            p->unk50 <<= 2;
            p->unk4E <<= 2;
        }
    } else {
        p->unk50 *= 10;
        p->unk4E *= 10;
    }
    switch (arg0->unk3A[4]) {
    case 2:
        p->unk50 = p->unk50 * 9 / 10;
        p->unk4E = p->unk4E * 9 / 10;
        break;
    case 3:
        p->unk50 = p->unk50 * 7 / 10;
        p->unk4E = p->unk4E * 7 / 10;
        break;
    }
}

void player_weapon_sound(s16 arg0, s16 arg1) {
    if (arg1 != 0) {
        D_801DFC76 = 1;
        switch (arg0) {
        case 0:
        case 2:
            sound_se_play(0x23);
            break;
        case 1:
            sound_se_play(0x29);
            break;
        case 3:
        case 4:
            sound_se_play(0x2A);
            break;
        case 6:
        case 12:
            sound_se_play(0x24);
            break;
        case 5:
            sound_se_play(0x25);
            break;
        case 7:
            sound_se_play(0x2B);
            break;
        case 8:
            sound_se_play(0x2C);
            break;
        case 9:
        case 11:
            sound_se_play(0x26);
            break;
        case 10:
            sound_se_play(0x2D);
            break;
        case 14:
            roadmap_start_flash(0xFF, 0xFF, 0xFF, 1);
            sound_se_play(0x27);
            break;
        case 13:
            roadmap_start_flash(0xFF, 0xC0, 0, 1);
        case 15:
            sound_se_play(0x2E);
            break;
        case 16:
            roadmap_start_flash(0x60, 0xFF, 0xFF, 1);
            sound_se_play(0x30);
            break;
        case 17:
            roadmap_start_flash(0xFF, 0x60, 0xFF, 1);
            sound_se_play(0x2F);
            break;
        }
    } else {
        switch (arg0) {
        case 14:
            sound_se_stop(0x27);
            break;
        case 13:
        case 15:
            sound_se_stop(0x2E);
            break;
        case 17:
            sound_se_stop(0x2F);
            break;
        case 16:
            sound_se_stop(0x30);
            break;
        }
    }
}

void player_reset_triggers(s16 arg0) {
    D_801DFF48 = 0xFFFFFF;
    D_801E0610.unk4 = 0;
    D_801E0600.unk4 = 0;
    D_801E0610.unk0 = 0xFFFFFF;
    D_801E0600.unk0 = 0xFFFFFF;
    D_801E0610.unk8 = 0;
    D_801E0600.unk8 = 0;
    D_801E0620.unk3E = arg0;
    D_801E0620.unk3C = 1;
    D_801E0620.unk42 &= ~4;
}

s32 player_set_item(s16 arg0, s16 arg1, s16 arg2) {
    s32 ret;

    if (arg2 == 0) {
        ret = effect_item_remove(arg0, arg1);
    } else {
        ret = effect_item_add(arg0, arg1);
    }
    return ret;
}

s32 player_set_weapon(s16 arg0, s16 arg1, s16 arg2) {
    s32 ret;

    if (arg1 == 0) {
        effect_weapon_unequip(arg0);
        ret = 1;
    } else {
        ret = effect_weapon_add(arg0, arg2);
    }
    return ret;
}

void player_heal_part(s16 arg0, s16 arg1, s16 arg2) {
    Unk_801E0368 *p = &D_801E0368;
    Unk_801E0710 *q = &D_801E0710;
    s16 v = p->unkB4[arg0];

    v -= arg2;
    if (arg2 < 0) {
        s16 *m = &player_part_damage_caps[arg1];

        if (v > *m) {
            v = *m;
        }
    } else if (v < 0) {
        v = 0;
    }
    *(p->unkB4 + arg0) = v;
    event_draw_limb_status(q);
    event_set_blink(2, 1);
}

void player_add_hp(s16 arg0, s16 arg1) {
    Unk_801E0710 *p = &D_801E0710;
    s16 v;

    if (arg0 < 0) {
        p->unk4A = 0;
    }
    v = p->unk0 + arg0;
    p->unk0 = v;
    if (v >= 0x100) {
        p->unk0 = 0xFF;
    } else if (v < 0) {
        p->unk0 = 0;
        if (arg1 != 0) {
            p->unk0 = arg1;
        }
    } else if (v > 0 && v < 0xFF) {
        if (v < arg1) {
            p->unk0 = arg1;
        }
    }
    event_draw_gauge(p);
}

void player_rest(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Unk_801E0710 *p = &D_801E0710;
    Unk_801E076C *o = p->unk5C;
    Unk_801E0368 *q = &D_801E0368;
    s16 v;

    if (arg0 == 0) {
        v = 0x3C;
        p->unk36 -= 4;
        if (p->unk36 < 0) {
            p->unk36 = 0;
        }
    } else {
        v = 0x1A4;
        p->unk36 = 0;
        if (q->unk7C > 0x14) {
            v = (0x17 - q->unk7C) * 0x3C - (q->unk7E - 0x21C);
        } else if (q->unk7C < 3) {
            v = 0x1E0 - q->unk7E - q->unk7C * 0x3C;
        }
    }
    o->unk54 = arg1;
    o->unk5C = arg3;
    o->unk58 = arg2 + o->unk78;
    player_set_view(o, 1);
    event_advance_clock(v, 1);
}

s32 player_is_injured(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (D_801E0368.unkB4[i] > 0) {
            return 1;
        }
    }
    return 0;
}

s32 player_leave_trigger(void) {
    Unk_801E0620 *p = &D_801E0620;
    Unk_801CC1E8 *o;

    UnDeliverEvent(0xF3000001, 2);
    o = kaj_event_push(0x20);
    if (o != NULL) {
        o->unkC = D_801E0600.unk0;
        o->unk8 = D_801E0600.unk4;
        o->unk10 = D_801E0600.unk8;
    }
    D_801E0610.unk4 = D_801E0600.unk4;
    D_801E0610.unk0 = D_801E0600.unk0;
    D_801E0610.unk8 = D_801E0600.unk8;
    p->unk42 &= ~4;
    return 0;
}

void player_move_to_done(Unk_8019A07C *arg0) {
    Unk_8019A07C_3C *e = arg0->unk3C;
    Unk_801E0620 *p = &D_801E0620;
    Unk_801DFFE8 *s = &D_801DFFE8;

    p->unk54 = e->unk14;
    p->unk58 = e->unk18;
    p->unk5C = e->unk1C;
    p->unk6C = e->unk3C;
    p->unk6E = e->unk3E;
    p->unk70 = e->unk40;
    p->unk42 &= ~2;
    p->unk3C = 1;
    switch (e->unk0) {
    case 0:
        p->unk42 |= e->unk2;
        break;
    case 1:
        p->unk42 &= e->unk2;
        break;
    case 2:
        p->unk42 &= ~e->unk2;
        break;
    }
    if (s->unk12 & 0x20) {
        s->unk12 &= ~0x20;
        if (s->unk12 == 0) {
            s->unk6 = 1;
        }
    }
    p->unk48 = -1;
    if (p->unk42 & 0x800) {
        player_finish_death();
    }
}

void player_update_map_cursor(Unk_801E076C *arg0, Unk_801E07C0 *arg1) {
    s32 dir;

    if (arg1->unk2 != 0) {
        if (arg0->unk60 < -625 || arg0->unk60 >= 1176 || arg0->unk68 < -425 || arg0->unk68 >= 926) {
            if (arg1->unk8[2] != 0) {
                arg1->unk8[2] = 0;
            }
        } else {
            if (arg1->unk8[2] == 0) {
                arg1->unk8[2] = 1;
            }
            dir = (arg0->unk6E + 23) / 45;
            if (dir >= 8) {
                dir = 0;
            }
            arg1->unk8[12] = dir % 4;
            arg1->unk8[13] = dir / 4;
            arg1->unk8[5] = arg0->unk60 / 10 + 116;
            arg1->unk8[6] = 152 - arg0->unk68 / 10;
        }
    } else {
        if (arg0->unk60 < -2425 || arg0->unk60 >= 2976 || arg0->unk68 < -2225 || arg0->unk68 >= 3176) {
            if (arg1->unk8[2] != 0) {
                arg1->unk8[2] = 0;
            }
        } else {
            if (arg1->unk8[2] == 0) {
                arg1->unk8[2] = 1;
            }
            dir = (arg0->unk6E + 23) / 45;
            if (dir >= 8) {
                dir = 0;
            }
            arg1->unk8[12] = dir % 4;
            arg1->unk8[13] = dir / 4;
            arg1->unk8[5] = arg0->unk60 / 40 + 137;
            arg1->unk8[6] = 135 - arg0->unk68 / 40;
        }
    }
}

s32 player_update_map(Unk_801E0710 *arg0) {
    Unk_801E0368 *o = &D_801E0368;
    Unk_801E076C *e = arg0->unk5C;
    Unk_801E07C0 *p = &D_801E07C0;
    Unk_801D7FB0 *q;

    if (e->unk46 >= 2) {
        return 0;
    }
    if (p->unk0 != 2) {
        if (!(D_801E6DA0.unk4 & 0x100) && (D_801E6DA0.unk0 & 0x100)) {
            if (p->unk0 == 1) {
                if (p->unk2 == 0) {
                    q = &D_801D7FB0;
                    sound_se_play(0x13);
                    if (q->unk0 != 0) {
                        if (q->unk10 != NULL) {
                            q->unk10->unk4 = 0;
                        }
                        if (q->unkC != NULL) {
                            q->unkC->unk4 = 0;
                        }
                    }
                    p->unk2 = 1;
                    if (p->unkC[2] == 0) {
                        p->unkC[2] = !p->unkC[2];
                    }
                } else {
                    sound_se_play(0x13);
                    p->unk0 = 2;
                    p->unk2 = 0;
                    p->unk8[2] = 0;
                    p->unkC[2] = 0;
                    effect_start_sprite_slide(3, 0x405, 1);
                }
            } else if (p->unk0 == 0 && o->unk24C == 0) {
                q = &D_801D7FB0;
                sound_se_play(0x13);
                if (q->unk0 != 0) {
                    if (q->unk10 != NULL) {
                        q->unk10->unk4 = 0;
                    }
                    if (q->unkC != NULL) {
                        q->unkC->unk4 = 0;
                    }
                }
                text_close();
                p->unk0 = 2;
                p->unk2 = 0;
                effect_start_sprite_slide(2, 0x405, 1);
            }
        }
        if (p->unk0 != 1) {
            return 0;
        }
        player_update_map_cursor(e, p);
    }
    return 1;
}
