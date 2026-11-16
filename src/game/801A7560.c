#include "common.h"

typedef struct Unk_801A7AFC {
    u16 unk0;
    u16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 unkA[0x2];
    s16 unkC;
    s16 unkE;
    s16 unk10;
    u8 unk12[0x2];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    s32 unk2C;
    u8 unk30[0x14];
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    u8 unk50[0x2C];
    void *unk7C;
    void *unk80;
    void *unk84;
} Unk_801A7AFC;
void free3(void *ptr);
typedef struct Unk_801A7BA4 {
    struct Unk_801A7BA4 *unk0;
    struct Unk_801A7BA4 *unk4;
    Unk_801A7AFC *unk8;
} Unk_801A7BA4;
typedef struct Unk_801DFFA0 {
    Unk_801A7BA4 *unk0;
    Unk_801A7BA4 *unk4;
    Unk_801A7BA4 *unk8;
    s32 unkC;
} Unk_801DFFA0;
void kaj_ll_insert_before(Unk_801DFFA0 *arg0, s32 arg1);
void kaj_ll_insert_after(Unk_801DFFA0 *arg0, s32 arg1);
Unk_801DFFA0 *D_801DFFA0;
void kaj_ll_remove_to_prev(Unk_801DFFA0 *arg0);
typedef struct Unk_801A8EFC {
    u8 unk0[0xC];
    s32 unkC;
    s32 unk10;
} Unk_801A8EFC;
void sound_se_play(s32 arg0);
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
    s16 unk18;
    s16 unk1A;
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
void vehicle_train_exit_prompt(s32 arg0);
extern Unk_801E1118 D_801E1118;
void vehicle_train_set_doors(s32 arg0);
void block_create_all(void);
void thing_field_loop(void);
void sprite_phone_run(void);
void block_elevator_run(s32 arg0, s32 arg1);
s16 thing_field_exit_arg_hi;
s16 thing_field_exit_arg_lo;
s16 thing_field_exit_code;
s16 kaj_ll_at_tail(Unk_801DFFA0 *arg0);
void GsSetLsMatrix(void *m);
s16 block_point_on_model(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4);
typedef struct Unk_801A8264_0 {
    u8 unk0[0x2];
    u16 unk2;
    u8 unk4;
    u8 unk5;
} Unk_801A8264_0;
typedef struct Unk_801A8264 {
    Unk_801A8264_0 *unk0;
    u8 unk4[0x4];
    char **unk8;
} Unk_801A8264;
s32 atoi(char *s);
extern char D_801719BC[];
extern char D_801719DC[];
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char thing_str_file[];
typedef struct { void *unk0; s32 unk4; void *unk8; } Unk_80174B10;
Unk_80174B10 *action_find_set(s16 arg0);
Unk_80174B10 *action_run_set(Unk_80174B10 *arg0, s32 arg1, s32 arg2);
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x4];
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0x26];
    s16 unk3C;
    u8 unk3E[0x4];
    u16 unk42;
    u8 unk44[0x2];
    u16 unk46;
    u8 unk48[0xC];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    u8 unk60[0xC];
    u16 unk6C;
    u16 unk6E;
    u16 unk70;
    s16 unk72;
    s16 unk74;
    s16 unk76;
} Unk_801E076C;
extern Unk_801E076C *D_801E076C[];
extern s16 D_801D7FB0[];
typedef struct { s32 unk0; s16 unk4; s16 unk6; } Unk_801E056C;
typedef struct {
    u16 unk0[0x70];
    u8 unkE0[0x120];
    s16 unk200;
    u8 unk202[0x2];
    Unk_801E056C unk204[4];
    u8 unk224[0x20];
    s32 unk244;
    u8 unk248[6];
    s16 unk24E;
    s16 unk250;
    s16 unk252;
} Unk_801E0368;
extern Unk_801E0368 D_801E0368;
typedef struct { u16 unk0; s16 unk2; s16 *unk4; s16 *unk8; s16 *unkC; } Unk_801E07C0;
extern Unk_801E07C0 D_801E07C0;
s16 thing_next_vehicle_mode;
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void text_close(void);
void sound_bgm_play(s16 arg0);
s16 vehicle_train_end_of_line(s16 arg0);
void vehicle_navi_show(Unk_801E076C *arg0, s16 arg1, s32 arg2);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4[2];
    u8 unk8[4];
    s16 unkC[0x12];
    s16 unk30;
    s16 unk32[8];
    s16 unk42;
    s16 unk44;
    s16 unk46;
    u16 unk48;
    u8 unk4A[2];
    s32 unk4C;
} Unk_801E0768;
typedef struct {
    u8 unk0[0x4C];
    void *unk4C;
    u8 unk50[0x8];
    Unk_801E0768 *unk58;
    Unk_801E076C *unk5C;
} Unk_801E0710;
extern Unk_801E0710 D_801E0710;
typedef struct { s16 unk0[5]; s16 unkA; char *unkC; s16 unk10; s16 unk12; s32 unk14; s32 unk18; s32 unk1C; } Unk_801E0340;
extern Unk_801E0340 D_801E0340;
typedef struct Unk_801E6DA0 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    u8 unkC[0x8];
    s32 unk14;
} Unk_801E6DA0;
extern Unk_801E6DA0 D_801E6DA0;
s32 kaj_pad_read(void);
s16 vehicle_car_input(Unk_801E0710 *arg0, s32 arg1);
s16 effect_item_input(Unk_801E0710 *arg0, s16 arg1);
s32 player_update_map(Unk_801E0710 *arg0);
void player_handle_pad(Unk_801E0710 *arg0, s32 arg1, s32 arg2);
void thing_field_do_action(Unk_801E076C *arg0);
extern s32 D_801DFED4;
extern s32 D_801DFED8;
extern s32 D_801DFEDC;
extern s32 D_801DFEE0;
extern s32 D_801DFEE4;
void effect_clear_alarms(void);
void action_reset(s16 arg0);
void sprite_set_visible(s32 arg0, s32 arg1);
void sound_bgm_stop(void);
void sound_se_stop_all(void);
void vehicle_free(void);
void roadmap_quit(void);
void action_free_triggers(void);
void action_free_all_sets(void);
void block_free_all(void);
void thing_free_all(void);
void effect_flame_small_free(void);
void effect_flame_large_free(void);
void sound_bgm_close(void);
void sound_se_pop_scene(void);
void sprite_delete(s32 arg0);
void vehicle_car_release(void);
void kaj_view_set_bg_color(u8 arg0, u8 arg1, u8 arg2);
void block_hide_all(void);
void thing_set_active(s32 arg0, s32 arg1, s16 arg2);
void block_stream_stop(void);
typedef struct {
    u32 unk0;
    s16 unk4;
    s16 unk6;
    u16 unk8;
    s16 unkA;
    u16 unkC;
    s16 unkE;
    u8 pad10[0x2];
    u16 unk12;
} Unk_801DFFE8;
extern Unk_801DFFE8 D_801DFFE8;
void sprite_phone_save_exit();
s16 vehicle_train_get_off(s16 arg0);
s16 D_801DFFAC;
s16 thing_field_loaded_id;
void thing_set_animate(s32 arg0, s32 arg1, s16 arg2);
s32 thing_field_task_hook(Unk_801A8EFC *arg0);
void thing_field_timer_hook(Unk_801A8EFC *arg0);
s32 thing_train_enter_hook(Unk_801A8EFC *arg0);
s32 thing_train_leave_hook(Unk_801A8EFC *arg0);
void thing_train_tick_hook(void);
void player_place_for_scene(s32 arg0);
void roadmap_init(void);
void effect_weapon_calc_rate(s32 arg0);
void object_load_scene(void);
void object_load_res12_by_id(s16 arg0);
void effect_flame_small_init(s16 arg0);
void effect_clut_cycle_init(void);
void effect_flame_large_init(void);
void block_set_mode(u16 arg0);
void vehicle_car_place(void);
void vehicle_load_data(void);
void sprite_thing_refresh_all(void);
void event_show_clock(s16 arg0);
void thing_field_input(void);
void thing_field_enter(void);
void thing_field_leave(void);
void kaj_timer_enable(void);
void kaj_timer_disable(void);
void effect_start_fade(s32 arg0, s32 arg1);
s32 kaj_event_get(s32 *arg0);
void func_80189928(s32 *arg0);
void event_handle_enter(s32 *arg0);
void event_handle_leave(s32 *arg0);
void event_handle_tick(s16 arg0);
s32 mail_take_scene_change(void);
void kaj_pad_reset(s32 arg0);
s16 event_handle_effect_done(s32 *arg0);
void kaj_event_done(s32 *arg0);
void effect_start_alarm(s32 arg0, s32 arg1, s32 arg2);
void mail_step_frame(u16 arg0, s16 arg1, s16 arg2);
s32 func_8017D564(void);
s32 rand(void);
typedef struct {
    u16 unk0;
    u8 unk2[0x16];
    s32 unk18;
    s32 unk1C;
} Unk_801A9BF4;
typedef struct {
    u16 unk0;
    s16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s16 unk10;
    s16 unk12;
    s16 unk14;
    u8 unk16[0x2];
    s32 unk18;
    u8 unk1C[0x14];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    u8 unk3C[0x2C];
    s32 unk68;
    u8 unk6C[0x14];
    s32 unk80;
    s32 unk84;
    s32 unk88;
    u8 unk8C[0x2C];
    void *unkB8;
    void *unkBC;
    Unk_801A9BF4 *unkC0;
} Unk_801E032C;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_801A742C_10;
void thing_train_calc_stops(Unk_801E1118 *arg0);
void RotMatrix(Unk_801A742C_10 *arg0, void *arg1);
void GsInitCoordinate2(void *super, void *base);
void kaj_tmd_load(void *arg0, void *arg1, void *arg2);
extern s16 D_801DFC80;
void RotMatrixZYX(Unk_801A742C_10 *arg0, void *arg1);
s32 block_find_at(s32 a0, s32 a1, s32 a2);
void sprite_thing_update_marker(Unk_801E076C *arg0, Unk_801A7AFC *arg1, void *arg2);
void sprite_thing_update_fly_in(Unk_801A7AFC *arg0);
void vehicle_train_update(Unk_801A7AFC *arg0);
void vehicle_car_follow_player(Unk_801A7AFC *arg0, s32 arg1);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    Unk_801A742C_10 unk1C;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    Unk_801A742C_10 unk2C[4];
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    u8 unk58[0x4];
    s32 unk5C;
    s32 unk60;
    s32 unk64;
} Unk_801E1158;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Unk_801D7FB0;
extern Unk_801A7AFC *D_801E0764[];
extern Unk_801E1158 D_801E1158;
s16 thing_car_exit_prompt_on;
s32 thing_car_speed_div;
void RotTrans(void *v0, s32 *v1, s32 *flag);
void player_set_view(Unk_801E076C *arg0, s16 arg1);
void sound_se_stop(s32 arg0);
void mail_goto_twn(s32 a, s32 b, s32 c, s16 d, s16 e);
s32 rsin(s32 a);
s32 rcos(s32 a);
s32 func_8017CFE4(s32 arg0, s32 *arg1, s32 arg2);
extern Unk_801E032C *D_801E032C[];
extern s32 D_801E6DB4[];

INCLUDE_RODATA("asm/nonmatchings/game/801A7560", D_801719BC);

INCLUDE_RODATA("asm/nonmatchings/game/801A7560", D_801719DC);

void thing_update_all(void) {
    Unk_801A742C_10 sv;
    Unk_801DFFA0 *p = D_801DFFA0;
    Unk_801E0710 *g = &D_801E0710;
    Unk_801E0768 *a = g->unk58;
    Unk_801E076C *e = g->unk5C;
    Unk_801A7AFC *o;

    if (p->unkC == 0) {
        return;
    }
    p->unk8 = p->unk0;
    while (1) {
        o = p->unk8->unk8;
        if (o != NULL && o->unk2 != 4) {
            if (*(s32 *)o == 0x30007) {
                if (g->unk4C != 0 && a->unk48 >= 3) {
                    if (o->unk4 == 0) {
                        o->unk4 = 1;
                    }
                } else if (o->unk4 != 0) {
                    o->unk4 = 0;
                }
            }
            if (o->unk4 == 0) {
                o->unk14 = 0;
            } else {
                if (o->unk6 != 0) {
                    switch (o->unk2) {
                    case 2:
                        if (o->unk0 == 0) {
                            vehicle_train_update(o);
                        }
                        break;
                    case 3:
                        switch (o->unk0) {
                        case 0:
                        case 2:
                        case 6:
                            o->unk26 = -D_801E6DA0.unk14 + o->unk26;
                            if (o->unk26 < 0) {
                                o->unk26 += 360;
                            } else if (o->unk26 > 360) {
                                o->unk26 -= 360;
                            }
                            sv.unk0 = (o->unk24 << 12) / 360;
                            sv.unk2 = (o->unk26 << 12) / 360;
                            sv.unk4 = (o->unk28 << 12) / 360;
                            RotMatrix(&sv, o->unk30);
                            o->unk2C = 0;
                            break;
                        case 1:
                            o->unk26 -= -D_801E6DA0.unk14;
                            if (o->unk26 < 0) {
                                o->unk26 += 360;
                            } else if (o->unk26 > 360) {
                                o->unk26 -= 360;
                            }
                            sv.unk0 = (o->unk24 << 12) / 360;
                            sv.unk2 = (o->unk26 << 12) / 360;
                            sv.unk4 = (o->unk28 << 12) / 360;
                            RotMatrixZYX(&sv, o->unk30);
                            o->unk2C = 0;
                            break;
                        case 3:
                        case 4:
                        case 5:
                            o->unk26 += ~(D_801E6DA0.unk14 / 4);
                            if (o->unk26 < 0) {
                                o->unk26 += 360;
                            } else if (o->unk26 > 360) {
                                o->unk26 -= 360;
                            }
                            sv.unk0 = (o->unk24 << 12) / 360;
                            sv.unk2 = (o->unk26 << 12) / 360;
                            sv.unk4 = (o->unk28 << 12) / 360;
                            RotMatrix(&sv, o->unk30);
                            o->unk2C = 0;
                            break;
                        case 7:
                            sprite_thing_update_marker(e, o, g->unk4C);
                            break;
                        case 8:
                            o->unk26 += D_801E6DA0.unk14 * 5 / 2;
                            if (o->unk26 < 0) {
                                o->unk26 += 360;
                            } else if (o->unk26 > 360) {
                                o->unk26 -= 360;
                            }
                            sv.unk0 = (o->unk24 << 12) / 360;
                            sv.unk2 = (o->unk26 << 12) / 360;
                            sv.unk4 = (o->unk28 << 12) / 360;
                            RotMatrix(&sv, o->unk30);
                            o->unk2C = 0;
                            break;
                        case 9:
                            o->unk26 -= D_801E6DA0.unk14 * 5;
                            if (o->unk26 < 0) {
                                o->unk26 += 360;
                            } else if (o->unk26 > 360) {
                                o->unk26 -= 360;
                            }
                            sv.unk0 = (o->unk24 << 12) / 360;
                            sv.unk2 = (o->unk26 << 12) / 360;
                            sv.unk4 = (o->unk28 << 12) / 360;
                            RotMatrix(&sv, o->unk30);
                            o->unk2C = 0;
                            break;
                        case 10:
                            sprite_thing_update_fly_in(o);
                            break;
                        }
                        break;
                    }
                }
                if (o->unk10 == 0 && D_801DFC80 != 0) {
                    o->unk14 = block_find_at(o->unk18, o->unk1C, o->unk20);
                    if (*(s32 *)o == 0) {
                        vehicle_car_follow_player(o, 0);
                    }
                }
            }
        }
        if (kaj_ll_at_tail(p) != 0) {
            break;
        }
        p->unk8 = p->unk8->unk4;
    }
}

void thing_create(Unk_801A7AFC **arg0, u32 arg1) {
    *arg0 = kaj_malloc(0x88);
    if (*arg0 == NULL) {
        kaj_abend(3, D_801719BC, thing_str_file, 0x26);
    }
    (*arg0)->unk4 = 0;
    (*arg0)->unk6 = 0;
    (*arg0)->unk8 = 0;
    (*arg0)->unk10 = 0;
    (*arg0)->unk14 = 0;
    (*arg0)->unk7C = NULL;
    (*arg0)->unk80 = NULL;
    (*arg0)->unk84 = NULL;
    (*arg0)->unk84 = kaj_malloc(arg1);
    if ((*arg0)->unk84 == NULL) {
        kaj_abend(3, D_801719DC, thing_str_file, 0x33);
    }
}

void thing_free(Unk_801A7AFC *arg0) {
    if (arg0 != NULL) {
        free3(arg0->unk7C);
        if (arg0->unk80 != NULL) {
            free3(arg0->unk80);
        }
        free3(arg0->unk84);
        free3(arg0);
    }
}

void thing_list_add(s32 arg0) {
    if (D_801DFFA0->unkC == 0) {
        kaj_ll_insert_before(D_801DFFA0, arg0);
    } else {
        D_801DFFA0->unk8 = D_801DFFA0->unk4;
        kaj_ll_insert_after(D_801DFFA0, arg0);
    }
}

void thing_free_all(void) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;

    while (1) {
        if (list->unkC == 0) {
            break;
        }
        item = list->unk8->unk8;
        if (item != NULL) {
            free3(item->unk7C);
            if (item->unk80 != NULL) {
                free3(item->unk80);
            }
            free3(item->unk84);
            free3(item);
        }
        kaj_ll_remove_to_prev(list);
    }
}

Unk_801A7AFC *thing_find(s32 arg0, s32 arg1) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    s32 a;
    s32 b;

    if (list->unkC == 0) {
        return NULL;
    }
    a = arg0 & 0xFFFF;
    b = arg1 & 0xFFFF;
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && item->unk2 == a && item->unk0 == b) {
            return item;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return NULL;
}

u16 thing_hit_test(s32 arg0, s32 arg1, s32 arg2, u16 arg3) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;

    if (list->unkC == 0) {
        return 0xFFFF;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && item->unk4 != 0 && item->unk80 != NULL) {
            GsSetLsMatrix(item->unk30);
            if (block_point_on_model(item->unk80, arg0, arg1, arg2, arg3) != 0) {
                return item->unk0 + (item->unk2 << 12);
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return 0xFFFF;
}

void thing_set_origin(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;

    if (list->unkC == 0) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL) {
            item->unk2C = 0;
            item->unk44 = item->unk18 - arg0;
            item->unk48 = item->unk1C - arg1;
            item->unk4C = item->unk20 - arg2;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

s32 thing_run_script(s32 arg0, s32 arg1, s16 arg2) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    Unk_801A7AFC *found;
    Unk_80174B10 *p;
    s32 a;
    s32 b;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        a = arg0 & 0xFFFF;
        b = arg1 & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->unk2 == a && item->unk0 == b) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found == NULL || found->unk8 == 0) {
        return 0;
    }
    if (found->unk4 == 0 || (p = arg2 != 0 ? action_find_set(found->unkC) : action_find_set(found->unkE)) == NULL) {
        return 0;
    }
    while ((p = action_run_set(p, 0, 0)) != NULL) {
    }
    return 1;
}

void thing_set_active(s32 arg0, s32 arg1, s16 arg2) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    Unk_801A7AFC *found;
    s32 a;
    s32 b;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        a = arg0 & 0xFFFF;
        b = arg1 & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->unk2 == a && item->unk0 == b) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL) {
        found->unk4 = arg2;
    }
}

void thing_set_animate(s32 arg0, s32 arg1, s16 arg2) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    Unk_801A7AFC *found;
    s32 a;
    s32 b;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        a = arg0 & 0xFFFF;
        b = arg1 & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->unk2 == a && item->unk0 == b) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL) {
        found->unk6 = arg2;
    }
}

void thing_set_flag10(s32 arg0, s32 arg1, s16 arg2) {
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    Unk_801A7AFC *found;
    s32 a;
    s32 b;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        a = arg0 & 0xFFFF;
        b = arg1 & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->unk2 == a && item->unk0 == b) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL) {
        found->unk10 = arg2;
    }
}

void thing_cmd_set_active(Unk_801A8264 *arg0) {
    Unk_801A8264_0 *p = arg0->unk0;
    Unk_801DFFA0 *list = D_801DFFA0;
    Unk_801A7AFC *item;
    Unk_801A7AFC *found;
    s32 x = p->unk5;
    s32 y = p->unk4;
    s32 a;
    s32 b;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        a = x & 0xFFFF;
        b = y & 0xFFFF;
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->unk2 == a && item->unk0 == b) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL && p->unk2 == 2) {
        found->unk4 = atoi(arg0->unk8[0]);
    }
}

s32 thing_field_task_hook(Unk_801A8EFC *arg0) {
    Unk_801E0368 *g = &D_801E0368;
    Unk_801E076C *o = D_801E076C[0];
    Unk_801E1118 *p = &D_801E1118;
    Unk_801E07C0 *c = &D_801E07C0;
    s16 *q = D_801D7FB0;
    s32 v = arg0->unk10;

    if (v == 2) {
        if (arg0->unkC == 0) {
            g->unk244 = -1;
        }
        c->unk0 = 1;
    } else if (v == 3) {
        if (arg0->unkC == 0) {
            g->unk244 = -1;
        }
        c->unk0 = 0;
        if (q[0] != 0) {
            vehicle_navi_show(o, 1, 0);
        }
    } else if (v == 11) {
        /* " 8カーナビ1の3目的地1を, 方向キー上下で選んで下さい,      設定 3○ 1解除 4×" */
        text_show(" 8\203J\201[\203i\203r1\202\3143\226\332\223I\222n1\202\360, \225\373\214\374\203L\201[\217\343\211\272\202\305\221I\202\361\202\305\211\272\202\263\202\242,      \220\335\222\350 3\201\233 1\211\360\217\234 4\201~", 3, -1, 0, -1, 0, 1);
    } else if (v == 12) {
        text_close();
        vehicle_navi_show(o, q[0], 1);
    } else if (v == 7) {
        if (p->unkE == 3) {
            p->unkE = 1;
            thing_next_vehicle_mode = vehicle_train_end_of_line(thing_next_vehicle_mode);
            if (thing_next_vehicle_mode != 0) {
                vehicle_train_exit_prompt(1);
            }
        } else if (p->unkE == 2) {
            p->unkE = 0;
            p->unk12 = 1;
            sound_se_play(0x1F);
        }
    } else if (v == 0) {
        sound_bgm_play(0);
    }
    return 0;
}

void thing_field_do_action(Unk_801E076C *arg0) {
    Unk_801E0340 *s = &D_801E0340;
    Unk_801DFFE8 *d = &D_801DFFE8;
    Unk_80174B10 *p;
    s32 hi;
    s32 lo;

    if (d->unk6 == 2 && (d->unk8 & 8)) {
        text_close();
        switch (d->unk4) {
        case 0xFD:
            hi = d->unk0 & 0xF000;
            lo = (u16)d->unk0 & 0xFFF;
            if (hi == 0 && lo == 0) {
                sound_se_play(0x16);
                s->unkA = 1;
                s->unk14 = arg0->unk54 + arg0->unk72 * 12500;
                s->unk18 = 0;
                s->unk1C = arg0->unk5C + arg0->unk76 * 12500;
                thing_field_exit_code = 3;
                thing_next_vehicle_mode = 1;
                s->unk12 = arg0->unk6E;
                s->unk10 = 0;
            } else {
                sound_se_play(0x11);
                for (p = action_find_set(d->unkA); p != 0; p = action_run_set(p, 0, 0)) {
                }
            }
            break;
        case 0xFE:
            sound_se_play(0xD);
            s->unkA = 1;
            thing_field_exit_code = 2;
            thing_field_exit_arg_hi = (d->unk0 & 0xFF00) >> 8;
            thing_field_exit_arg_lo = d->unk0 & 0xFF;
            break;
        case 0xFF:
            sound_se_play(0xD);
            thing_field_exit_code = 1;
            s->unkA = 1;
            sprite_phone_save_exit(d->unk0);
            break;
        case 0x20:
            sound_se_play(0x11);
            thing_next_vehicle_mode = vehicle_train_get_off(thing_next_vehicle_mode);
            break;
        default:
            for (p = action_find_set(d->unkA); p != 0; p = action_run_set(p, 0, 0)) {
            }
            break;
        }
        d->unk6 = 1;
        d->unk8 &= ~8;
    }
}

void thing_field_input(void) {
    Unk_801E0340 *s = &D_801E0340;
    Unk_801E0710 *m = &D_801E0710;
    Unk_801E6DA0 *pad = &D_801E6DA0;
    s16 mode = pad->unkA;
    Unk_801E076C *o = m->unk5C;
    s32 id;
    s32 t;

    if (mode == 1 && !(o->unk42 & 2)) {
        t = kaj_pad_read();
        id = o->unk46;
        if (id == mode) {
            if (vehicle_car_input(m, t) != 0) {
                thing_field_exit_code = 4;
                thing_next_vehicle_mode = 0;
                s->unkA = id;
            }
        } else if (effect_item_input(m, 2) == 0) {
            player_update_map(m);
            if ((o->unk42 & 4) && !(pad->unk4 & 0x20) && (pad->unk0 & 0x20)) {
                thing_field_do_action(o);
                return;
            }
            player_handle_pad(m, 2, t);
        }
    }
}

void thing_field_enter(void) {
    Unk_801E0768 *p;
    Unk_801E076C *o;
    Unk_801E1118 *q;

    thing_next_vehicle_mode = -1;
    D_801DFFAC = 1;
    p = D_801E0710.unk58;
    o = D_801E0710.unk5C;
    q = &D_801E1118;
    sprite_set_visible(0x410, 1);
    action_reset(1);
    if (thing_field_exit_code != 3) {
        player_place_for_scene(2);
    }
    roadmap_init();
    effect_weapon_calc_rate(0);
    effect_weapon_calc_rate(1);
    switch (thing_field_exit_code) {
    case 0:
        object_load_scene();
        if (thing_field_loaded_id != p->unk42) {
            object_load_res12_by_id(p->unk42);
            thing_field_loaded_id = p->unk42;
        }
        effect_flame_small_init(2);
        effect_clut_cycle_init();
        effect_flame_large_init();
    case 1:
    case 2:
    case 3:
    case 4:
        block_set_mode(2);
        break;
    }
    switch (o->unk46) {
    case 0:
        vehicle_car_place();
        sound_se_play(0x15);
    case 1:
        vehicle_load_data();
        D_801DFED8 = (s32)thing_field_timer_hook;
        thing_set_active(3, 3, 1);
        thing_set_active(3, 4, 1);
        thing_set_animate(3, 3, 1);
        thing_set_animate(3, 4, 1);
        sprite_set_visible(0x40E, 1);
        if (o->unk46 == 1) {
            sound_se_play(0x19);
            sound_se_play(0x1A);
        }
        break;
    case 3:
        D_801DFFAC = 0;
        thing_set_active(4, 0, 0);
    case 2:
        vehicle_load_data();
        D_801DFEE4 = (s32)thing_train_enter_hook;
        D_801DFEE0 = (s32)thing_train_leave_hook;
        D_801DFEDC = (s32)thing_train_tick_hook;
        q->unkC = 0;
        q->unk4 = 0;
        q->unk16 = 0;
        break;
    }
    if (thing_field_exit_code != 0) {
        sprite_thing_refresh_all();
    }
    D_801DFED4 = (s32)thing_field_task_hook;
    thing_field_exit_code = 0;
    event_show_clock(D_801DFFAC);
    sprite_set_visible(0x410, 0);
}

void thing_field_leave(void) {
    Unk_801E076C *o = D_801E076C[0];
    s32 i;

    effect_clear_alarms();
    action_reset(1);
    sprite_set_visible(0x40E, 0);
    sound_bgm_stop();
    sound_se_stop_all();
    D_801DFED8 = 0;
    D_801DFED4 = 0;
    D_801DFEE4 = 0;
    D_801DFEE0 = 0;
    D_801DFEDC = 0;
    text_close();
    vehicle_free();
    roadmap_quit();
    switch (thing_field_exit_code) {
    case 0:
        action_free_triggers();
        action_free_all_sets();
        block_free_all();
        thing_free_all();
        effect_flame_small_free();
        effect_flame_large_free();
        sound_bgm_close();
        sound_se_pop_scene();
        for (i = 0; i < 4; i++) {
            sprite_delete((u16)i);
        }
        sprite_delete(0x1FF);
        vehicle_car_release();
        kaj_view_set_bg_color(0, 0, 0);
        break;
    case 3:
        thing_set_active(0, 0, 0);
        break;
    case 1:
        block_hide_all();
        effect_flame_small_free();
        effect_flame_large_free();
        kaj_view_set_bg_color(0, 0, 0);
    case 2:
        thing_set_active(3, 3, 0);
        thing_set_active(3, 4, 0);
        break;
    }
    block_stream_stop();
    if (thing_next_vehicle_mode != -1) {
        o->unk46 = thing_next_vehicle_mode;
    }
}

void thing_field_loop(void) {
    s32 sp10[6];
    s16 flag;
    s16 done;

    flag = 0;
    done = 0;
    thing_field_enter();
    kaj_timer_enable();
    effect_start_fade(0, 3);
    while (done == 0) {
        switch (kaj_event_get(sp10)) {
        case 2:
            func_80189928(sp10);
            continue;
        case 0x10:
            event_handle_enter(sp10);
            continue;
        case 0x20:
            event_handle_leave(sp10);
            continue;
        case 4:
            event_handle_tick(D_801DFFAC);
            continue;
        case 0:
            thing_field_input();
            if ((s16)mail_take_scene_change() != 0) {
                if (thing_field_exit_code == 2) {
                    kaj_pad_reset(0);
                    flag = 1;
                } else {
                    effect_start_fade(1, 3);
                }
            }
            break;
        case 0x100:
            done = event_handle_effect_done(sp10);
            continue;
        default:
            kaj_event_done(sp10);
            continue;
        }
        effect_start_alarm(0, 0x404, rand() % 30 + 30);
        mail_step_frame(2, 1, 1);
        if (flag != 0 && func_8017D564() != 0) {
            done = 1;
        }
    }
    kaj_timer_disable();
    thing_field_leave();
}

void thing_field_timer_hook(Unk_801A8EFC *arg0) {
    if (arg0->unkC == 0x404) {
        sound_se_play(0x17);
    }
}

s32 thing_train_enter_hook(Unk_801A8EFC *arg0) {
    Unk_801E1118 *p = &D_801E1118;
    s32 v = arg0->unkC;

    if (v == 0x200010 || v == 0x200020) {
        p->unk4 = v;
        if (p->unkE == 1) {
            vehicle_train_exit_prompt(1);
        }
        return 1;
    }
    return 0;
}

s32 thing_train_leave_hook(Unk_801A8EFC *arg0) {
    Unk_801E1118 *p = &D_801E1118;
    s32 v = arg0->unkC;

    if (v == 0x200010 || v == 0x200020) {
        p->unk4 = 0;
        vehicle_train_exit_prompt(0);
        return 1;
    }
    if (p->unkC != 0) {
        p->unkC = 0;
    }
    return 0;
}

void thing_train_tick_hook(void) {
    if (D_801E1118.unk12 == 0 && D_801E1118.unkE == 1) {
        if (D_801E1118.unk16 > 0) {
            D_801E1118.unk16--;
        }
        if (D_801E1118.unk16 == 0) {
            D_801E1118.unk16 = -1;
            vehicle_train_set_doors(0);
            vehicle_train_exit_prompt(0);
        }
    }
}

void thing_game_loop(void) {
    thing_field_exit_code = 0;
    block_create_all();
    while (1) {
        thing_field_loop();
        switch (thing_field_exit_code) {
        case 0:
            return;
        case 1:
            sprite_phone_run();
            break;
        case 2:
            block_elevator_run(thing_field_exit_arg_hi, thing_field_exit_arg_lo);
            break;
        }
    }
}

void thing_train_calc_stops(Unk_801E1118 *arg0) {
    arg0->unkA = 0;
    if (arg0->unk8 != 0) {
        arg0->unk1C = (arg0->unk10 - 1) * 100000 - 195000;
        arg0->unk20 = (arg0->unk10 - 1) * 100000 - 175000;
        arg0->unk24 = (arg0->unk10 - 1) * 100000 - 115000;
        arg0->unk28 = (arg0->unk10 - 1) * 100000 - 95000;
    } else {
        arg0->unk1C = (arg0->unk10 - 1) * 100000 - 200000;
        arg0->unk20 = (arg0->unk10 - 1) * 100000 - 220000;
        arg0->unk24 = (arg0->unk10 - 1) * 100000 - 280000;
        arg0->unk28 = (arg0->unk10 - 1) * 100000 - 300000;
    }
}

void thing_car_init(Unk_801E032C *arg0, Unk_801E076C *arg1) {
    s32 v[3];
    Unk_801A742C_10 sv;
    s32 flag;
    Unk_801A9BF4 *h = arg0->unkC0;
    Unk_801A7AFC *o = D_801E0764[0];
    Unk_801E1158 *q = &D_801E1158;
    Unk_801D7FB0 *r = (Unk_801D7FB0 *)D_801D7FB0;
    Unk_801E0368 *g = &D_801E0368;

    arg0->unk0 = h->unk0;
    arg0->unk2 = 0;
    GsSetLsMatrix(o->unk30);
    q->unk1C.unk0 = -180;
    q->unk1C.unk2 = -120;
    q->unk24 = 0;
    q->unk26 = 0;
    q->unk28 = 0;
    q->unk1C.unk4 = 200;
    RotTrans(&q->unk1C, v, &flag);
    if (h->unk18 != 0) {
        kaj_tmd_load(&arg0->unkB8, (u8 *)arg0->unkC0 + h->unk18, &arg0->unk18);
    }
    GsInitCoordinate2(NULL, &arg0->unk18);
    arg0->unk4 = o->unk18;
    arg0->unk8 = o->unk1C + 370;
    arg0->unkC = o->unk20;
    arg0->unk10 = o->unk24;
    arg0->unk12 = o->unk26;
    arg0->unk14 = o->unk28;
    arg0->unk30 = arg0->unk4 - arg1->unk72 * 12500;
    arg0->unk34 = arg0->unk8 + arg1->unk74 * 32000;
    arg0->unk38 = arg0->unkC - arg1->unk76 * 12500;
    sv.unk0 = (arg0->unk10 << 12) / 360;
    sv.unk2 = (arg0->unk12 << 12) / 360;
    sv.unk4 = (arg0->unk14 << 12) / 360;
    RotMatrix(&sv, arg0->unk1C);
    if (h->unk1C != 0) {
        kaj_tmd_load(&arg0->unkBC, (u8 *)arg0->unkC0 + h->unk1C, &arg0->unk68);
    }
    GsInitCoordinate2(&arg0->unk18, &arg0->unk68);
    arg0->unk80 = -180;
    arg0->unk84 = -360;
    arg0->unk88 = 412;
    sv.unk0 = 56;
    sv.unk2 = 0;
    sv.unk4 = 0;
    RotMatrix(&sv, arg0->unk6C);
    arg1->unk54 = v[0] + arg1->unk72 * 12500;
    arg1->unk58 = v[1] - arg1->unk74 * 32000;
    arg1->unk5C = v[2] + arg1->unk76 * 12500;
    arg1->unk6C = 0;
    arg1->unk6E = arg0->unk12;
    arg1->unk70 = 0;
    player_set_view(arg1, 1);
    q->unk0 = 0;
    q->unk2 = 0;
    thing_car_exit_prompt_on = 0;
    q->unk4 = 0;
    q->unk8 = 0;
    q->unkC = 0;
    q->unk6 = 0;
    q->unk10 = 0;
    q->unk14 = 0;
    q->unk18 = 0;
    q->unk2C[0].unk0 = -75;
    q->unk2C[0].unk2 = 0;
    q->unk2C[0].unk4 = 102;
    q->unk2C[1].unk0 = 75;
    q->unk2C[1].unk2 = 0;
    q->unk2C[1].unk4 = 102;
    q->unk2C[2].unk0 = -75;
    q->unk2C[2].unk2 = 0;
    q->unk2C[2].unk4 = -152;
    q->unk2C[3].unk0 = 75;
    q->unk2C[3].unk2 = 0;
    q->unk2C[3].unk4 = -152;
    q->unk4C = 0;
    q->unk50 = 0;
    q->unk54 = 0;
    q->unk5C = 0;
    q->unk60 = 0;
    q->unk64 = 0;
    arg0->unk18 = 0;
    arg0->unk68 = 0;
    r->unk0 = 0;
    r->unk2 = 1;
    r->unk4 = 0;
    r->unk8 = 0;
    r->unkC = 0;
    r->unk10 = 0;
    switch (g->unk200) {
    case 2:
        thing_car_speed_div = 500;
        break;
    case 1:
        thing_car_speed_div = 400;
        break;
    case 0:
        thing_car_speed_div = 300;
        break;
    }
}

static inline s32 func_801A968C_inline(Unk_801E032C *arg0, Unk_801E076C *o, s32 *px, s32 *py, s32 *pz, s32 ang) {
    s32 x;
    s32 z;
    x = arg0->unk4 + ((*px * rcos(ang) + *pz * rsin(ang)) >> 12);
    z = arg0->unkC + ((*pz * rcos(ang) - *px * rsin(ang)) >> 12);
    *px = x - o->unk72 * 12500;
    *pz = z - o->unk76 * 12500;
    if ((s16)func_8017CFE4(*px, py, *pz)) {
        *px = x;
        *pz = z;
        return 1;
    }
    return 0;
}

void thing_car_get_out(Unk_801E032C *arg0) {
    s32 x;
    s32 y;
    s32 z;
    s32 ang;
    Unk_801E076C *o = D_801E076C[0];

    o->unk0 = arg0->unk4;
    o->unk4 = arg0->unk8 - 370;
    o->unk8 = arg0->unkC;
    o->unk10 = arg0->unk10;
    o->unk12 = arg0->unk12;
    o->unk14 = arg0->unk14;
    ang = (arg0->unk12 << 12) / 360;
    x = -245;
    z = 0;
    if (!func_801A968C_inline(arg0, o, &x, &y, &z, ang)) {
        x = 245;
        z = 0;
        if (!func_801A968C_inline(arg0, o, &x, &y, &z, ang)) {
            x = 0;
            z = -490;
            if (!func_801A968C_inline(arg0, o, &x, &y, &z, ang)) {
                x = 0;
                z = 490;
                if (!func_801A968C_inline(arg0, o, &x, &y, &z, ang)) {
                    z = 0;
                    y = 0;
                    x = 0;
                }
            }
        }
    }
    sound_se_stop(0x1A);
    vehicle_navi_show(NULL, 0, 1);
    sprite_delete(4);
    D_801D7FB0[0] = 0;
    mail_goto_twn(x, y, z, arg0->unk12, 0);
}

void thing_train_init(Unk_801E032C *arg0, Unk_801E076C *arg1) {
    Unk_801A742C_10 sv;
    Unk_801A9BF4 *h = arg0->unkC0;
    Unk_801E1118 *q = &D_801E1118;

    arg0->unk0 = h->unk0;
    arg0->unk2 = 0;
    thing_train_calc_stops(q);
    if (h->unk18 != 0) {
        kaj_tmd_load(&arg0->unkB8, (u8 *)arg0->unkC0 + h->unk18, &arg0->unk18);
    }
    if (h->unk1C != 0) {
        kaj_tmd_load(&arg0->unkBC, (u8 *)arg0->unkC0 + h->unk1C, &arg0->unk18);
    }
    GsInitCoordinate2(NULL, &arg0->unk18);
    arg0->unk4 = arg1->unk72 * 12500 + arg1->unk54;
    arg0->unk8 = -(arg1->unk74 * 32000) + 75;
    arg0->unkC = arg1->unk76 * 12500 + arg1->unk5C;
    arg0->unk10 = 0;
    arg0->unk12 = 0;
    arg0->unk14 = 0;
    if (q->unk8 == 0) {
        arg0->unk12 = 180;
        arg1->unk6E -= 180;
    }
    q->unk2C = 0;
    q->unk2E = 0;
    q->unk30 = 0;
    q->unk34 = arg1->unk6C;
    q->unk36 = arg1->unk6E;
    q->unk38 = arg1->unk70;
    arg0->unk30 = arg0->unk4 - arg1->unk72 * 12500;
    arg0->unk34 = arg0->unk8 + arg1->unk74 * 32000;
    arg0->unk38 = arg0->unkC - arg1->unk76 * 12500;
    sv.unk0 = (arg0->unk10 << 12) / 360;
    sv.unk2 = (arg0->unk12 << 12) / 360;
    sv.unk4 = (arg0->unk14 << 12) / 360;
    RotMatrix(&sv, arg0->unk1C);
    arg0->unk18 = 0;
}

void thing_train_update(Unk_801E076C *arg0) {
    s32 v[4];
    s32 flag;
    Unk_801E032C *p = D_801E032C[0];
    Unk_801E1118 *q = &D_801E1118;
    Unk_801E0368 *g = &D_801E0368;

    if (q->unk12 != 0) {
        arg0->unk3C = 1;
    }
    if (q->unk8 != 0) {
        if (q->unk12 == 3) {
            q->unk14 = (q->unk28 - p->unkC) / 300 + 7;
            p->unkC += q->unk14 * D_801E6DB4[0];
            if (p->unkC >= q->unk28) {
                sound_se_stop(0x1F);
                q->unk14 = 0;
                p->unkC = q->unk28;
                q->unk12 = 0;
                q->unk16 = 2;
                if (++q->unk10 >= 7) {
                    q->unk10 = 6;
                }
                thing_train_calc_stops(q);
                vehicle_train_set_doors(1);
                q->unk18 = (s16)g->unk0[0x3F] % 10;
                if (q->unk18 >= 5) {
                    q->unk1A = q->unk18 - 5;
                } else {
                    q->unk1A = q->unk18 + 5;
                }
            }
        } else if (q->unk12 == 1) {
            q->unk14 = (p->unkC - q->unk1C) / 300 + 7;
            p->unkC += q->unk14 * D_801E6DB4[0];
            if (p->unkC >= q->unk20) {
                q->unk12 = 2;
            }
        } else if (q->unk12 == 2) {
            p->unkC += q->unk14 * D_801E6DB4[0];
            if (p->unkC >= q->unk24) {
                q->unk12 = 3;
            }
        }
    } else {
        if (q->unk12 == 3) {
            q->unk14 = (p->unkC - q->unk28) / 300 + 7;
            p->unkC -= q->unk14 * D_801E6DB4[0];
            if (p->unkC <= q->unk28) {
                sound_se_stop(0x1F);
                q->unk14 = 0;
                p->unkC = q->unk28;
                q->unk12 = 0;
                q->unk16 = 2;
                if (--q->unk10 == 0) {
                    q->unk10 = 1;
                }
                thing_train_calc_stops(q);
                vehicle_train_set_doors(1);
                q->unk1A = (s16)g->unk0[0x3F] % 10;
                if (q->unk1A >= 5) {
                    q->unk18 = q->unk1A - 5;
                } else {
                    q->unk18 = q->unk1A + 5;
                }
            }
        } else if (q->unk12 == 1) {
            q->unk14 = (q->unk1C - p->unkC) / 300 + 7;
            p->unkC -= q->unk14 * D_801E6DB4[0];
            if (p->unkC <= q->unk20) {
                q->unk12 = 2;
            }
        } else if (q->unk12 == 2) {
            p->unkC -= q->unk14 * D_801E6DB4[0];
            if (p->unkC <= q->unk24) {
                q->unk12 = 3;
            }
        }
    }
    p->unk38 = p->unkC - arg0->unk76 * 12500;
    p->unk18 = 0;
    GsSetLsMatrix(p->unk1C);
    RotTrans(&q->unk2C, v, &flag);
    arg0->unk54 = v[0];
    arg0->unk5C = v[2];
    arg0->unk6C = q->unk34 + p->unk10;
    arg0->unk6E = q->unk36 + p->unk12;
    arg0->unk70 = q->unk38 + p->unk14;
}
