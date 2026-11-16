#include "common.h"
#include "game/types.h"

void free3(void *ptr);
s32 D_801DFF48;
extern AreaTrigger object_area_current;
extern AreaTrigger object_area_previous;
extern Player player_character;
s16 effect_item_add(s16 arg0, s16 arg1);
s16 effect_item_remove(s16 arg0, s16 arg1);
void effect_weapon_unequip(s16 arg0);
s16 effect_weapon_add(s16 arg0, s16 arg1);
extern PlayerStatus player_status;
void event_draw_gauge(PlayerStatus *arg0);
/* Local view of GameVars: this unit reads 0x0-0xB4 as s16 arrays and scalars, the shared type has one u16 array. */
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
    s16 limb_damage[5];
    u8 padBE[0x22];
    u8 unkE0[0x16C];
    s16 menu_busy;
} GameVars_u80195DF0;
extern GameVars_u80195DF0 action_vars;
RoomPhone object_room_phone;
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
RoomStorage object_room_storage;
u16 D_801DFD58;
u16 D_801DFD5A;
extern char D_80170E18[];
void sprite_set_visible(s32 arg0, s32 arg1);
void sprite_set_clut_entry(s32 arg0, s32 arg1, s32 arg2);
void text_close(void);
void mail_wait(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern Player *player_status_player[];
Model *mod_find(u16 arg0);
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
extern EventState event_state;
extern void *D_801E0760[];
ActionSet *action_find_set(s16 arg0);
ActionSet *action_run_set(ActionSet *arg0, s32 arg1, s32 arg2);
s16 D_801DFF4C;
void UnDeliverEvent(u32 ev, u32 spec);
KajEvent *kaj_event_push(s32 arg0);
extern s16 player_part_damage_caps[];
void event_draw_limb_status(PlayerStatus *arg0);
void event_set_blink(s16 arg0, s16 arg1);
void player_finish_death(void);
extern SceneTables object_scene_tables;
s16 D_801DFF18;
s32 object_aset_count;
extern u8 object_iff_file_pos[];
s32 CdPosToInt(void *p);
void *CdIntToPos(s32 i, void *p);
s32 CdControl(u8 com, u8 *param, u8 *result);
void sound_se_play(s32 arg0);
void player_set_view(Player *arg0, s16 arg1);
void event_advance_clock(s16 a, s16 b);
extern VabStream sound_vab_stream;
s32 CdMode(void);
void *CdLastPos(void);
s32 CdRead(s32 sectors, u32 *buf, s32 mode);
s32 CdReadSync(s32 mode, u8 *result);
s32 VSync(s32 mode);
u32 *sound_se_alloc_header(u8 *arg0, s32 arg1, VabStream *arg2);
void sound_vab_open_head(VabStream *arg0);
extern KajSystem kaj_system;
s32 kaj_pad_read(void);
s16 object_room_storage_input(void);
s16 effect_item_input(PlayerStatus *arg0, s16 arg1);
void object_room_do_action(PlayerStatus *arg0);
void player_start_move_to(s16 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6, s16 arg7, s32 arg8);
void player_handle_pad(PlayerStatus *arg0, s32 arg1, s32 arg2);
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
extern Inventory player_inventory;
void *memset(void *dst, s32 c, u32 n);
void RotMatrix(s16 *arg0, void *arg1);
void ApplyMatrixLV(void *arg0, void *arg1, void *arg2);
void GsSetView2(void *arg0);
void GsInitCoordinate2(void *super, void *base);
extern SceneRequest scene_request;
extern s32 player_str_scene_cmn[];
void mail_goto_building(s32 arg0, s32 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8);
extern s16 D_801DFC76;
void roadmap_start_flash(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s16 D_801E1046[];
u16 roadmap_get_state(void);
s16 ai_in_aim_cone(Npc *arg0, s32 arg1, s16 arg2);
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
/* Local view of CarState: this unit reads 0x14 as s16 and 0x1C as an s16 array, the shared type has an s32 and a record there. */
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
    s16 look_pitch;
    s16 look_yaw;
    s16 unk28;
    u8 unk2A[0x22];
    s32 unk4C;
    u8 unk50[4];
    s32 unk54;
    u8 unk58[4];
    s32 unk5C;
    u8 unk60[4];
    s32 unk64;
} CarState_u80195DF0;
void RotMatrixZXY(s16 *r, void *m);
void GsSetLsMatrix(void *m);
void RotTrans(void *v0, s32 *v1, s32 *flag);
extern ScreenLight screen_light;
void player_wrap_cell(Player *arg0);
void SetFogNearFar(s32 a, s32 b, s32 h);
void RotMatrixZYX(s16 *r, void *m);
void player_start_death(u16 arg0, PlayerStatus *arg1, Player *arg2);
void event_update_hud(PlayerStatus *a);
void block_stream_update(u16 arg0);
void block_update_visibility(u16 arg0);
void player_move_on_foot(Player *arg0, u16 arg1, s16 arg2, s16 arg3);
void event_draw_compass(Player *arg0);
void player_move_in_car(Player *arg0, s32 arg1);
void player_move_in_train(Player *arg0, u16 arg1);
void sound_footstep_update(Player *arg0);
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
extern TrainState vehicle_train_state;
extern Unk_801E032C *D_801E032C[];
s16 player_try_slide(s16 arg0, s16 arg1, s32 *arg2, s32 *arg3, s32 arg4, s32 arg5);
void player_update_view(Player *arg0, s16 *arg1, u16 arg2);
s32 func_8017BBB0(s32 arg0, s32 arg1, s32 *arg2);
s16 player_check_ground(Player *arg0, s32 arg1, s16 arg2, s16 arg3);
s32 rsin(s32 a);
s32 rcos(s32 a);
extern CarState_u80195DF0 vehicle_car_state;
void player_place_in_car(Player *arg0, Unk_801E032C *arg1, CarState_u80195DF0 *arg2, s32 arg3, s32 arg4, s16 arg5, s16 arg6);
s32 block_fit_ground_tilt(s32 *arg0, s32 arg1);
s32 SquareRoot0(s32 arg0);
s32 player_pick_hit_part(s16 arg0);
s16 mail_angle_to_dir8(s16 a);
void player_add_skill_exp(s16 arg0, s16 arg1);
typedef struct Unk_80188FEC {
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
void npc_apply_damage(Npc *arg0, s32 arg1, s32 arg2, s16 arg3);
u16 npc_get_radius(Npc *arg0);
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
Npc *npc_find(s16 arg0, u16 arg1);
u16 thing_hit_test(s32 arg0, s32 arg1, s32 arg2, u16 arg3);
s16 D_801DFD5C;
s16 D_801DFD5E;
extern s32 D_801E6DB4[];
s32 mail_exp_for_level(s32 a);
void effect_weapon_calc_rate(s32 arg0);
extern RoadMap roadmap_state;
extern CarNavi vehicle_navi;
void effect_start_sprite_slide(s32 arg0, u16 arg1, s32 arg2);
void player_update_map_cursor(Player *arg0, RoadMap *arg1);
void effect_weapon_calc_rate(s32 a);

INCLUDE_RODATA("asm/nonmatchings/game/80195DF0", D_80170EDC);

INCLUDE_RODATA("asm/nonmatchings/game/80195DF0", D_80170EFC);

INCLUDE_RODATA("asm/nonmatchings/game/80195DF0", D_80170F14);

s16 player_try_slide(s16 mode, s16 step, s32 *x, s32 *z, s32 dx, s32 dz) {
    s16 next = step;

    switch (step) {
    case 0:
        *x -= dx;
        *z -= dz;
        next = 1;
        player_slide_dx = dx < 0 ? -2 : dx > 0 ? 2 : 0;
        player_slide_dz = dz < 0 ? -2 : dz > 0 ? 2 : 0;
        if (mode != 2) {
            player_slide_dx *= 10;
            player_slide_dz *= 10;
        }
        if (player_slide_dx != 0) {
            *x += player_slide_dx;
        } else {
            *x += player_slide_dz;
        }
        break;
    case 1:
        next = 2;
        if (player_slide_dx != 0) {
            *x -= player_slide_dx;
        } else {
            *x -= player_slide_dz;
        }
        if (player_slide_dz != 0) {
            *z += player_slide_dz;
        } else {
            *z += player_slide_dx;
        }
        break;
    case 2:
        next = 4;
        if (player_slide_dz != 0) {
            *z -= player_slide_dz;
        } else {
            *z -= player_slide_dx;
        }
        if (player_slide_dz != 0) {
            *z -= player_slide_dz;
        } else {
            *z -= player_slide_dx;
        }
        break;
    case 4:
        next = 3;
        if (player_slide_dz != 0) {
            *z += player_slide_dz;
        } else {
            *z += player_slide_dx;
        }
        if (player_slide_dx != 0) {
            *x -= player_slide_dx;
        } else {
            *x -= player_slide_dz;
        }
        break;
    case 3:
        next = -1;
        if (player_slide_dx != 0) {
            *x += player_slide_dx;
        } else {
            *x += player_slide_dz;
        }
        break;
    }
    return next;
}

void player_move_in_train(Player *player, u16 mode) {
    s32 pos[3];
    s16 rot[3];
    s16 dir[3];
    s16 cam[3];
    s32 y;
    s32 flag;
    Unk_801E032C *vehicle;
    s32 ox;
    s32 oz;
    TrainState *train;
    s32 dx;
    s32 dz;
    s32 sx;
    s32 sz;
    s32 col;
    s16 moved;
    s16 step;

    ox = player->pos_x;
    oz = player->pos_z;
    rot[0] = (-player->pitch << 12) / 360;
    rot[1] = (-player->yaw << 12) / 360;
    rot[2] = (-player->unk70 << 12) / 360;
    col = 0x1000000;
    moved = 0;
    step = 0;
    y = 0;
    train = &vehicle_train_state;
    vehicle = D_801E032C[0];
    if (player->flags & 0x800) {
        player->move_state = 0;
    } else {
        dir[0] = 0;
        dir[2] = 0;
        cam[0] = (train->view_pitch << 12) / 360;
        cam[1] = (train->view_yaw << 12) / 360;
        cam[2] = (train->unk38 << 12) / 360;
        dir[1] = ((train->view_yaw + 90) << 12) / 360;
        if (player->unk3E != 0) {
            block_update_visibility(mode);
            col = func_8017BBB0(player->pos_x, player->pos_z, &y);
            if (player->unk3E == 1) {
                col = 0x1000000;
            }
            player->unk3E = 0;
            player_check_ground(player, col, 0, 0);
            player->pos_y = y + player->unk78;
        } else {
            dx = (player->unk50 * rsin(cam[1])) >> 12;
            dz = (player->unk50 * rcos(cam[1])) >> 12;
            sx = (player->unk4E * rsin(dir[1])) >> 12;
            sz = (player->unk4E * rcos(dir[1])) >> 12;
            if (dx == 0 && dz == 0 && (sx != 0 || sz != 0)) {
                moved = 1;
            }
            dx += sx;
            dz += sz;
            if (dx != 0 || dz != 0) {
                train->carry_vx += dx;
                train->carry_vz += dz;
            loop:
                GsSetLsMatrix(vehicle->unk1C);
                RotTrans(&train->carry_vx, pos, &flag);
                player->pos_x = pos[0];
                player->pos_z = pos[2];
                block_stream_update(mode);
                block_update_visibility(mode);
                col = func_8017BBB0(player->pos_x, player->pos_z, &y);
            } else {
                block_stream_update(mode);
                block_update_visibility(mode);
            }
            if (player_check_ground(player, col, moved, step) != 0) {
                player->pos_y = y + player->unk78;
            } else {
                step = player_try_slide(2, step, (s32 *)&train->carry_vx, (s32 *)&train->carry_vz, dx, dz);
                if (step != -1) {
                    goto loop;
                }
                player->pos_x = ox;
                player->pos_z = oz;
                player->move_state = 5;
            }
            player_wrap_cell(player);
        }
    }
    player_update_view(player, rot, 2);
}

void player_place_in_car(Player *player, Unk_801E032C *vehicle, CarState_u80195DF0 *car, s32 dx, s32 dz, s16 dyaw, s16 last) {
    s32 pos[3];
    s16 rot[3];
    s32 flag;

    vehicle->unk4 += dx;
    vehicle->unkC += dz;
    vehicle->unk12 += dyaw;
    vehicle->unk30 = vehicle->unk4 - player->cell_x * 0x30D4;
    vehicle->unk34 = vehicle->unk8 + player->cell_y * 0x7D00;
    vehicle->unk38 = vehicle->unkC - player->cell_z * 0x30D4;
    rot[0] = (vehicle->unk10 << 12) / 360;
    rot[1] = (vehicle->unk12 << 12) / 360;
    rot[2] = (vehicle->unk14 << 12) / 360;
    RotMatrixZXY(rot, vehicle->unk1C);
    if (last != 0) {
        vehicle->unk18 = 0;
    }
    GsSetLsMatrix(vehicle->unk1C);
    RotTrans(car->unk1C, pos, &flag);
    player->pos_x = pos[0];
    player->pos_y = pos[1] - 0x172;
    player->pos_z = pos[2];
    player->pitch = car->look_pitch;
    player->yaw = car->look_yaw + vehicle->unk12;
    player->unk70 = car->unk28;
    if (player->yaw >= 0x168) {
        player->yaw -= 0x168;
    }
    if (player->yaw < 0) {
        player->yaw += 0x168;
    }
    if (vehicle->unk12 >= 0x168) {
        vehicle->unk12 -= 0x168;
    }
    if (vehicle->unk12 < 0) {
        vehicle->unk12 += 0x168;
    }
}

void player_move_in_car(Player *player, s32 mode) {
    s16 rot[3];
    s32 y;
    CarState_u80195DF0 *car;
    Unk_801E032C *vehicle;
    s32 dx;
    s32 dz;
    s32 c;
    s32 s;
    s32 d;
    s32 ground;
    s16 a;
    s16 b;
    s16 ang;

    car = &vehicle_car_state;
    y = 0;
    vehicle = D_801E032C[0];
    if (player->unk3E != 0) {
        block_update_visibility(mode);
        ground = block_fit_ground_tilt(&y, 1);
        if (ground == 0xFFFF || ground == 0xFF00) {
            vehicle->unk8 = y;
        }
        player->unk3E = 0;
    } else {
        if (car->unk18 == 0) {
            ang = (vehicle->unk12 << 12) / 360;
            dx = (car->unk10 * rsin(ang)) >> 12;
            dz = (car->unk10 * rcos(ang)) >> 12;
        } else {
            d = SquareRoot0(car->unk18 * car->unk18 + car->unk10 * car->unk10);
            c = (car->unk18 << 12) / d;
            s = (car->unk10 << 12) / d;
            if (c > 0x1000) {
                c = 0x1000;
            }
            if (s > 0x1000) {
                s = 0x1000;
            }
            rot[0] = a = car->unk4C - car->unk5C;
            rot[1] = 0;
            rot[2] = b = car->unk54 - car->unk64;
            dx = ((c * a + s * b) >> 12) + car->unk5C;
            dz = ((c * b - s * a) >> 12) + car->unk64;
            if (car->unk4 < 0) {
                dx = car->unk4C - dx;
                dz = car->unk54 - dz;
            } else {
                dx = dx - car->unk4C;
                dz = dz - car->unk54;
            }
        }
        if (dx != 0 || dz != 0) {
            player_place_in_car(player, vehicle, car, dx, dz, car->unk14, 0);
            block_stream_update(mode);
            block_update_visibility(mode);
            ground = block_fit_ground_tilt(&y, 0);
            if (ground == 0xFFFF || ground == 0xFF00) {
                vehicle->unk8 = y;
            } else {
                vehicle->unk4 -= dx;
                vehicle->unkC -= dz;
                vehicle->unk12 -= car->unk14;
                car->unkC = 0;
                car->unk8 = 0;
                car->unk6 = 0;
            }
        } else {
            player_place_in_car(player, vehicle, car, 0, 0, 0, 0);
            block_stream_update(mode);
            block_update_visibility(mode);
        }
    }
    player_place_in_car(player, vehicle, car, 0, 0, 0, 1);
    player_wrap_cell(player);
    rot[0] = (-player->pitch << 12) / 360;
    rot[1] = (-player->yaw << 12) / 360;
    rot[2] = (-player->unk70 << 12) / 360;
    player_update_view(player, rot, 2);
}

void player_move_on_foot(Player *player, u16 mode, s16 stream, s16 visibility) {
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
    s32 ground_y;
    Npc *npc;
    s16 moved;
    u16 thing_id;
    s16 npc_id;
    s16 rec_id;
    s16 step;

    dz = 0;
    dx = 0;
    moved = 0;
    step = 0;
    y = 0;
    if ((player->flags & 1) || (player->flags & 0x10)) {
        col = 0x2000000;
        y = 700;
    } else {
        col = 0x1000000;
    }
    rot[0] = (-player->pitch << 12) / 360;
    rot[1] = (-player->yaw << 12) / 360;
    rot[2] = (-player->unk70 << 12) / 360;
    if (*(s32 *)&player->unk40 & 0x09020000) {
        player->move_state = 0;
    } else {
        if (!(player->flags & 0x39)) {
            dir[0] = 0;
            dir[1] = (-(player->yaw + 90) << 12) / 360;
            dir[2] = 0;
            col = 0x1000000;
            if (player->unk3E != 0) {
                if (visibility) {
                    block_update_visibility(mode);
                }
                switch (mode) {
                case 1:
                    col = block_find_surface_nearest(player->pos_x, player->pos_y - player->unk78, player->pos_z, &y);
                    break;
                case 0:
                case 2:
                    col = block_find_surface(player->pos_x, player->pos_z, &y, 1);
                    break;
                }
                if (player->unk3E == 1) {
                    col = 0x1000000;
                }
                player->unk3E = 0;
                player_check_ground(player, col, moved, step);
                player->pos_y = y + player->unk78;
                goto end;
            }
            s = rsin(-rot[1]);
            c = rcos(-rot[1]);
            dx = (player->unk50 * s) >> 12;
            dz = (player->unk50 * c) >> 12;
            sx = (player->unk4E * rsin(-dir[1])) >> 12;
            sz = (player->unk4E * rcos(-dir[1])) >> 12;
            if (dx == 0 && dz == 0 && (sx != 0 || sz != 0)) {
                moved = 1;
            }
            dx += sx;
            dz += sz;
            if (dx != 0 || dz != 0) {
                player->pos_x += dx;
                player->pos_z += dz;
            loop:
                if (player->unk50 < 0) {
                    px = -(s * 600) >> 12;
                    pz = -(c * 600) >> 12;
                } else {
                    px = (s * 600) >> 12;
                    pz = (c * 600) >> 12;
                }
                rec_id = mod_npcrec_find_at_point(player->pos_x + px, player->pos_y - player->unk78, player->pos_z + pz);
                if (rec_id >= 0) {
                    col = rec_id + 0xF70000;
                } else {
                    npc_id = npc_find_at_point(-1, player->pos_x + px, player->pos_y - player->unk78, player->pos_z + pz);
                    if (npc_id >= 0) {
                        npc = npc_find(0, npc_id);
                        if (npc != NULL && npc->unkF == 6) {
                            y = npc->unk24 + player->cell_y * 32000;
                        }
                        col = npc_id + 0xFC0000;
                    } else {
                        thing_id = thing_hit_test(player->pos_x, player->pos_y - player->unk78, player->pos_z, mode);
                        if (thing_id != 0xFFFF) {
                            col = thing_id + 0xFD0000;
                        } else {
                            if (stream) {
                                block_stream_update(mode);
                            }
                            if (visibility) {
                                block_update_visibility(mode);
                            }
                            switch (mode) {
                            case 1:
                                col = block_find_surface_nearest(player->pos_x, player->pos_y - player->unk78, player->pos_z, &y);
                                break;
                            case 0:
                            case 2:
                                col = block_find_surface(player->pos_x, player->pos_z, &y, 1);
                                break;
                            }
                        }
                    }
                }
            } else {
                if (stream) {
                    block_stream_update(mode);
                }
                if (visibility) {
                    block_update_visibility(mode);
                }
            }
        }
        if (player_check_ground(player, col, moved, step) != 0) {
            ground_y = y + player->unk78;
            if (ground_y < player->pos_y) {
                player->unk40 = 1;
            }
            if (player->pos_y < ground_y) {
                player->unk40 = 0;
            }
            player->pos_y = ground_y;
        } else if (rec_id >= 0 || npc_id >= 0 || thing_id != 0xFFFF || D_801DFD5C != 0 || D_801DFD5E != 0) {
            player->pos_x -= dx;
            player->pos_z -= dz;
        } else {
            step = player_try_slide(mode, step, &player->pos_x, &player->pos_z, dx, dz);
            if (step != -1) {
                goto loop;
            }
            player->move_state = 5;
        }
        player_wrap_cell(player);
    }
end:
    player_update_view(player, rot, mode);
}

void player_init(void) {
    PlayerStatus *status = &player_status;
    Inventory *inventory = &player_inventory;
    Player *player = &player_character;
    GameVars_u80195DF0 *vars;
    s16 rot[3];
    s32 i;

    memset(status, 0, 0x60);
    status->energy = 0xC9;
    status->level = 1;
    status->next_exp = 0x144;
    status->hours_awake = 2;
    status->stat0 = 1;
    status->stat1 = 1;
    status->stat2 = 1;
    status->stat3 = 1;
    status->weapon0_level = 1;
    status->weapon1_level = 1;
    status->weapon2_level = 1;
    status->weapon3_level = 1;
    status->weapon4_level = 1;
    status->defense_level = 1;
    status->drain_pending = 1;
    status->limb_redraw = 1;
    status->weapon_redraw = 1;
    status->infected = 0;
    vars = &action_vars;
    memset(inventory, 0, 0x50);
    for (i = 0; i < 8; i++) {
        inventory->item_ids[i] = -1;
    }
    vars->unk78 = 1;
    inventory->weapon_ids[1] = -1;
    inventory->unk42 = 0xF;
    memset(player, 0, 0xF0);
    player->unk0 = 0x5C30;
    player->unk8 = -0x1004;
    player->unk4 = 0;
    player->unk10 = 0;
    player->unk12 = 0xB4;
    player->unk14 = 0;
    player->unk3E = 1;
    player->unk40 = 1;
    player->unk48 = -1;
    rot[0] = 0;
    rot[1] = 0;
    rot[2] = 0;
    RotMatrix(rot, player->unk7C);
    ApplyMatrixLV(player->unk7C, player->unk90, player->unk90);
    player->unk9C = 0;
    GsSetView2(player->unk7C);
    GsInitCoordinate2(NULL, player->coord);
    status->inventory = inventory;
    status->player = (Player *)player;
}

void player_place_for_scene(u16 entry) {
    PlayerStatus *status = &player_status;
    ScreenLight *light = &screen_light;
    SceneRequest *request = &scene_request;
    Player *player;
    s16 rot[3];
    s32 v;

    status->target_npc = NULL;
    status->infected = 0;
    light->unk0[2] = 0;
    request->change = 0;
    object_area_previous.trigger_type = 0;
    object_area_current.trigger_type = 0;
    object_area_current.trigger = 0xFFFFFF;
    object_area_previous.trigger = 0xFFFFFF;
    object_area_previous.scene_trigger = 0;
    object_area_current.scene_trigger = 0;
    player = &player_character;
    player->flags &= ~4;
    player->unk3E = 1;
    player->unk3C = 1;
    player->unk40 = 1;
    player->unk78 = -0x640;
    D_801DFF48 = 0xFFFFFF;
    player->move_state = 0;
    player->unk4C = 0;
    player->speed_step = 4;
    player->flags = 0;
    switch (entry) {
    case 0:
        if (request->yaw != 0) {
            player->pos_x = 0xCE4;
            player->pos_y = -0x384;
            player->pos_z = 0x1AF4;
            player->flags = 1;
            player->pitch = 0;
            player->yaw = 0x96;
            player->unk70 = 0;
        } else {
            player->pos_x = 0xDAC;
            player->pos_y = -0x640;
            player->pos_z = 0x2BC;
            player->pitch = 0;
            player->yaw = 0;
            player->unk70 = 0;
        }
        break;
    case 1:
        if (request->unk10 < 3) {
            if (request->unk10 > 0) {
                light->unk0[2] = 1;
                SetFogNearFar(0x30D4, 0xFFFF, 0xE4);
            }
        }
        player->pitch = 0;
        player->unk70 = 0;
        player->pos_y += player->unk78;
        player->yaw = (u32)request->pos_y >> 16;
        break;
    case 2:
        light->unk0[2] = 1;
        SetFogNearFar(0x1388, 0x2710, 0xE4);
        player->unk78 = -0xAA;
        player->pitch = 0;
        player->unk70 = 0;
        player->pos_x = request->pos_x;
        player->pos_y = request->pos_y + player->unk78;
        player->pos_z = request->pos_z;
        player->yaw = request->yaw;
        switch (player->vehicle_mode) {
        case 0:
            player->pitch = 0xC;
            break;
        case 2:
        case 3:
            v = -0x2A8;
            player->unk78 = v;
            player->pos_y = request->pos_y + v;
            break;
        }
        break;
    case 3:
        player->pos_x = 0;
        player->pos_y = 0;
        player->pos_z = 0;
        player->pitch = 0;
        player->yaw = 0;
        player->unk70 = 0;
        break;
    }
    player_set_view((Player *)player, 0);
    player_wrap_cell(player);
    if (entry == 1) {
        player->coord->coord_tx = player->pos_x;
        player->coord->coord_ty = player->pos_y - player->unk4C + 0x140;
        player->coord->coord_tz = player->pos_z;
        rot[0] = (player->pitch << 12) / 360;
        rot[1] = (player->yaw << 12) / 360;
        rot[2] = (player->unk70 << 12) / 360;
        RotMatrixZYX(rot, player->coord->coord_m);
        player->coord->flg = 0;
    }
}

void player_finish_death(void) {
    PlayerStatus *status = &player_status;
    SceneRequest *request = &scene_request;
    GameVars_u80195DF0 *vars = &action_vars;
    s32 i;
    s16 v;

    if (vars->unk60 == 0 && status->infected != 0) {
        status->energy = 0xFF;
        status->hours_awake = 0;
        status->unk34 = 0;
        if (status->mutant == 0) {
            status->mutant = 1;
            vars->unk0[6] = 1;
            vars->unk62[0] = status->level;
            vars->unk62[1] = status->stat0;
            vars->unk62[2] = status->stat1;
            vars->unk62[3] = status->stat2;
            vars->unk62[4] = status->stat3;
            vars->unk62[5] = status->weapon0_level;
            vars->unk62[6] = status->weapon1_level;
            vars->unk62[7] = status->weapon2_level;
            vars->unk62[8] = status->weapon3_level;
            vars->unk62[9] = status->weapon4_level;
            vars->unk62[10] = status->defense_level;
            for (i = 9; i < 0x1C; i++) {
                v = vars->unk0[i];
                vars->unk0[i] = 2000;
                vars->unk28[i] = v;
            }
        }
        status->level = 100;
        status->stat0 = 100;
        status->stat1 = 100;
        status->stat2 = 100;
        status->stat3 = 100;
        status->weapon0_level = 100;
        status->weapon1_level = 100;
        status->weapon2_level = 100;
        status->weapon3_level = 100;
        status->weapon4_level = 100;
        status->defense_level = 100;
        for (i = 0; i < 5; i++) {
            status->limb_state[i] = 0;
            vars->limb_damage[i] = 0;
        }
        mail_goto_building(1, player_str_scene_cmn, 0x18, 0x41, 7, 0xB4, 0x15, 0x500F07, 1);
        event_draw_gauge(status);
        event_draw_limb_status(status);
    } else {
        request->unk0[4] = 1;
        request->change = 1;
    }
}

void player_start_death(u16 mode, PlayerStatus *status, Player *player) {
    GameVars_u80195DF0 *vars = &action_vars;
    s32 drop;

    if (D_801E1046[0] == 0 && vars->menu_busy == 0 && roadmap_get_state() == 0
        && player->vehicle_mode != 1 && !(player->flags & 0x8000) && !(player->flags & 0x4802)) {
        player->flags |= 0x800;
        if (player->vehicle_mode != 0) {
            player_finish_death();
            return;
        }
        drop = 0x514;
        if (mode == 2) {
            drop = 0x82;
        }
        player_start_move_to(0, 0, player->pos_x + player->cell_x * 0x30D4,
                      player->pos_y - player->cell_y * 0x7D00 - player->unk78 + drop,
                      player->pos_z + player->cell_z * 0x30D4, -0x4B, player->yaw, player->unk70, 4);
    }
}

void player_update(u16 mode, s16 stream, s16 visibility) {
    PlayerStatus *status = &player_status;
    Player *player = &player_character;

    if (status->energy <= 0) {
        player_start_death(mode, status, player);
    }
    event_update_hud(status);
    player->move_state = 0;
    if (player->unk3C == 0) {
        if (stream != 0) {
            block_stream_update(mode);
        }
        if (visibility != 0) {
            block_update_visibility(mode);
        }
    } else {
        if (!(player->flags & 0x800) && !(player->flags & 2)) {
            if (player->pitch > 0x41) {
                player->pitch = 0x41;
            }
            if (player->pitch < -0x19) {
                player->pitch = -0x19;
            }
            if (player->yaw >= 0x168) {
                player->yaw -= 0x168;
            }
            if (player->yaw < 0) {
                player->yaw += 0x168;
            }
        }
        if (mode == 2) {
            switch (player->vehicle_mode) {
            case 0:
                player_move_on_foot(player, 2, stream, visibility);
                event_draw_compass(player);
                break;
            case 1:
                player_move_in_car(player, 2);
                event_draw_compass(player);
                player->unk4E = 0;
                player->unk50 = 0;
                return;
            case 2:
            case 3:
                player_move_in_train(player, mode);
                break;
            default:
                player->unk4E = 0;
                player->unk50 = 0;
                return;
            }
        } else {
            player_move_on_foot(player, mode, stream, visibility);
        }
    }
    sound_footstep_update(player);
    player->unk4E = 0;
    player->unk50 = 0;
}

void player_add_skill_exp(s16 skill, s16 exp) {
    PlayerStatus *status = &player_status;
    s16 level_up = 0;
    u16 level;
    u16 exp_total;
    u16 lim;
    s32 i;

    switch (skill) {
    case 0:
        level = status->weapon0_level;
        exp_total = status->weapon0_exp;
        break;
    case 1:
        level = status->weapon1_level;
        exp_total = status->weapon1_exp;
        break;
    case 2:
        level = status->weapon2_level;
        exp_total = status->weapon2_exp;
        break;
    case 3:
        level = status->weapon3_level;
        exp_total = status->weapon3_exp;
        break;
    case 4:
        level = status->weapon4_level;
        exp_total = status->weapon4_exp;
        break;
    case 5:
        level = status->defense_level;
        exp_total = status->defense_exp;
        break;
    }
    if (level == 100) {
        return;
    }
    exp_total += exp;
    if (level == 1) {
        lim = 0x144;
    } else {
        lim = (level - 2) * 0xA2 + 0x195;
    }
    if (exp_total >= lim) {
        level++;
        exp_total -= lim;
        level_up = 1;
    }
    switch (skill) {
    case 0:
        status->weapon0_level = level;
        status->weapon0_exp = exp_total;
        break;
    case 1:
        status->weapon1_level = level;
        status->weapon1_exp = exp_total;
        break;
    case 2:
        status->weapon2_level = level;
        status->weapon2_exp = exp_total;
        break;
    case 3:
        status->weapon3_level = level;
        status->weapon3_exp = exp_total;
        break;
    case 4:
        status->weapon4_level = level;
        status->weapon4_exp = exp_total;
        break;
    case 5:
        status->defense_level = level;
        status->defense_exp = exp_total;
        break;
    }
    if (level_up && skill != 5) {
        for (i = 0; i < 2; i++) {
            effect_weapon_calc_rate(i);
        }
    }
}

void player_add_exp(s32 exp) {
    PlayerStatus *status = &player_status;
    s32 i;

    if (status->level == 100) {
        return;
    }
    status->exp += exp;
    if (status->exp < (u32)status->next_exp) {
        return;
    }
loop:
    status->level++;
    if (status->level < 100) {
        status->next_exp = mail_exp_for_level(status->level);
    }
    status->stat0 += rand() % 3;
    if ((u16)status->stat0 > 100) {
        status->stat0 = 100;
    }
    status->stat1 += rand() % 3;
    if ((u16)status->stat1 > 100) {
        status->stat1 = 100;
    }
    status->stat2 += rand() % 3;
    if ((u16)status->stat2 > 100) {
        status->stat2 = 100;
    }
    status->stat3 += rand() % 3;
    if ((u16)status->stat3 > 100) {
        status->stat3 = 100;
    }
    for (i = 0; i < 2; i++) {
        effect_weapon_calc_rate(i);
    }
    if (status->exp >= (u32)status->next_exp) {
        goto loop;
    }
}

s32 player_pick_hit_part(s16 dir) {
    if (rand() % 100 < 15) {
        return 0;
    }
    switch (dir) {
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

void player_take_hit(Npc *npc, s32 weapon_kind, s32 damage) {
    PlayerStatus *status;
    Player *player;
    GameVars_u80195DF0 *vars;
    s32 defense;
    s32 t;
    s32 div;
    s16 dir;
    s16 part;

    status = &player_status;
    player = &player_character;
    vars = &action_vars;
    if (status->energy > 0) {
        div = 1;
        defense = rand() % (u16)status->stat3;
        dir = mail_angle_to_dir8(player->yaw - npc->unk3A);
        switch (dir) {
        case 6:
            damage = damage * 3 / 2;
        case 5:
        case 7:
            part = player_pick_hit_part(dir);
            break;
        default:
            defense += rand() % (u16)status->defense_level;
            switch (weapon_kind) {
            case 0:
            case 1:
                div = 5;
                defense += rand() % (u16)status->stat0;
                t = rand() % (u16)status->stat1;
                switch (status->limb_state[4]) {
                case 2:
                    t = t * 2 / 3;
                    break;
                case 3:
                    t >>= 1;
                    break;
                }
                defense += t;
                defense += rand() % (u16)status->stat2;
                break;
            case 2:
            case 3:
                div = 3;
                defense += rand() % (u16)status->stat1;
                break;
            case 4:
                div = 3;
                defense += rand() % (u16)status->stat2;
                break;
            }
            part = player_pick_hit_part(dir);
            defense /= div;
            break;
        }
        player_add_skill_exp(5, defense * 10);
        damage -= defense * 2;
        if (damage > 0) {
            *(vars->limb_damage + part) += damage;
            if (part == 0) {
                status->energy -= damage;
                if ((u16)npc->unk2 != 0) {
                    status->infected = 1;
                }
            }
            event_draw_gauge(status);
            event_draw_limb_status(status);
            event_set_blink(2, 1);
            roadmap_start_flash(0xFF, 0, 0, 1);
        }
    }
}

void player_pick_target(void) {
    SceneTables *tables = &object_scene_tables;
    Npc *npc = tables->npcs;
    PlayerStatus *status = &player_status;
    Inventory *inventory;
    s16 weapon_id;
    s32 i;

    status->target_npc = NULL;
    inventory = status->inventory;
    if (tables->npc_count != 0) {
        weapon_id = inventory->weapon_ids[inventory->weapon_slot];
        for (i = 0; i < tables->npc_count; i++, npc++) {
            /* Npc.unk40 is loaded unsigned (lhu) in this unit only: casts keep its bytes */
            if (npc->unk4 != 0 && npc->unk6 != 0 && npc->unkE != 2 && !(npc->unk12 & 0x200) && (npc->unk12 & 2)
                && (u16)npc->unk40 != 0 && ai_in_aim_cone(npc, 0, weapon_id) != 0) {
                if (status->target_npc == NULL || (u16)npc->unk40 < (u16)status->target_npc->unk40) {
                    status->target_npc = npc;
                }
            }
        }
        if (status->target_npc != NULL) {
            return;
        }
    }
    if (inventory->armed == 0) {
        inventory->armed = 1;
    }
}

void player_shoot_target(void) {
    PlayerStatus *status = &player_status;
    Player *player = &player_character;
    Inventory *inventory = &player_inventory;
    Npc *target = status->target_npc;
    Unk_80188FEC *weapon;
    s32 dist;
    s32 chance;
    s32 falloff;
    s32 min_range;
    s32 full_range;
    s32 max_range;
    s32 rate;
    s32 reach;
    s32 k;
    s32 dy;
    s32 damage;
    s32 miss;

    if (!(player->flags & 0x400)) {
        return;
    }
    player->flags &= ~0x400;
    if (inventory->armed == 0 || target == NULL || target->unkE == 2 || (target->unk12 & 0x200) || !(target->unk12 & 2)) {
        return;
    }
    reach = npc_get_radius(target) + 600;
    k = (u16)target->unk40;
    dist = k - reach;
    if (dist < 0) {
        dist = 0;
    }
    weapon = effect_weapon_find(inventory->weapon_ids[inventory->weapon_slot]);
    if (weapon == NULL) {
        return;
    }
    chance = 0;
    min_range = weapon->unk54 * 10;
    full_range = weapon->unk58 * 10;
    max_range = weapon->unk5C * 10;
    rate = inventory->weapon_rate[inventory->weapon_slot];
    falloff = 0;
    if (dist < min_range) {
        chance = -1;
    } else if (dist < full_range) {
        falloff = 0x1000;
    } else if (dist < max_range) {
        falloff = ((max_range - dist) << 12) / (max_range - full_range);
    }
    if (dist >= min_range) {
        chance = (rate * falloff) >> 12;
    }
    if (weapon->unk2 == 0) {
        dy = player->pos_y - player->cell_y * 32000 - target->unk24 + 1600;
        if (dy > 0) {
            dy = -dy;
        }
        if (dy < -1600) {
            return;
        }
        if (falloff == 0) {
            chance = 0;
        }
    }
    if (chance < 20) {
        if (chance == 0) {
            npc_apply_damage(target, weapon->unk2, 0, 0);
            return;
        }
        if (chance < 0) {
            falloff = 0x1000;
        }
        chance = 20;
    }
    if ((u16)player->move_state == 1 || (u16)player->move_state == 3) {
        chance = chance * 9 / 10;
    }
    switch (status->limb_state[1]) {
    case 2:
        chance = chance * 9 / 10;
        break;
    case 3:
        chance = chance * 7 / 10;
        break;
    }
    if (rand() % 100 < chance) {
        miss = 0;
        damage = (weapon->unk52 * falloff) >> 12;
        k = weapon->unk0;
        switch (k) {
        case 14:
            if ((u16)target->unk2 == 4) {
                damage *= 2;
            }
            break;
        case 16:
        case 17:
            if ((u16)target->unk2 == 0 || (u16)target->unk2 == 4) {
                damage = (weapon->unk52 * falloff) >> 13;
            }
            break;
        }
    } else {
        miss = 1;
        damage = 0;
    }
    npc_apply_damage(target, weapon->unk2, damage, miss);
}

void player_move_to_step(Unk_80198ADC *task) {
    Unk_80198ADC_3C *move = task->unk3C;
    Player *player = &player_character;

    player->pos_x = move->unk4 + move->unk24 * task->unk24 / task->unk26;
    player->pos_y = move->unk8 + move->unk28 * task->unk24 / task->unk26;
    player->pos_z = move->unkC + move->unk2C * task->unk24 / task->unk26;
    player->pitch = move->unk34 + move->unk44 * task->unk24 / task->unk26;
    player->yaw = move->unk36 + move->unk46 * task->unk24 / task->unk26;
    player->unk70 = move->unk38 + move->unk48 * task->unk24 / task->unk26;
    player->unk3C = 1;
}

void player_start_move_to(s16 flag_op, u16 flag_bits, s32 x, s32 y, s32 z, s16 pitch, s16 yaw, s16 roll, s32 seconds) {
    Unk_80198ADC *task;
    Unk_80198ADC_3C *move;
    u16 ax;
    u16 ay;
    u16 az;
    s16 dz;
    Player *player;

    player = &player_character;
    ax = pitch;
    ay = yaw;
    az = roll;
    task = kaj_tss_alloc(0x4C);
    task->unk22 = 4;
    task->unk28 = 1;
    task->unk2C = 2;
    task->unk30 = player_move_to_step;
    task->unk24 = 0;
    task->unk34 = player_move_to_done;
    task->unk38 = player_move_to_done;
    move = task->unk3C;
    task->unk26 = seconds * 30;
    move->unk0 = flag_op;
    move->unk2 = flag_bits;
    x -= player->cell_x * 12500;
    y += player->unk78 + player->cell_y * 32000;
    z -= player->cell_z * 12500;
    if (player->pos_x == x && player->pos_y == y && player->pos_z == z &&
        player->pitch == pitch && player->yaw == yaw && player->unk70 == roll) {
        task->unk26 = 0;
    }
    move->unk4 = player->pos_x;
    move->unk8 = player->pos_y;
    move->unkC = player->pos_z;
    move->unk34 = player->pitch;
    move->unk36 = player->yaw;
    move->unk38 = player->unk70;
    move->unk14 = x;
    move->unk18 = y;
    move->unk1C = z;
    move->unk3C = ax;
    move->unk3E = ay;
    move->unk40 = az;
    move->unk24 = x - player->pos_x;
    move->unk28 = y - player->pos_y;
    move->unk2C = z - player->pos_z;
loop:
    move->unk44 = ax - player->pitch;
    move->unk46 = ay - player->yaw;
    move->unk48 = dz = az - player->unk70;
    if (move->unk44 > 180) {
        ax -= 360;
        goto loop;
    }
    if (move->unk44 < -180) {
        ax += 360;
        goto loop;
    }
    if (move->unk46 > 180) {
        ay -= 360;
        goto loop;
    }
    if (move->unk46 < -180) {
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
    player->flags |= 2;
    player->unk48 = kaj_tss_start(task);
}

void player_exec_command(Unk_80199034 *action, Npc *event) {
    Player *player = &player_character;
    s16 a;
    s16 b;
    s16 energy;
    s32 x;
    s32 y;
    s32 z;
    s16 yaw;
    s32 seconds;
    u16 flag_bits;
    PlayerStatus *status;

    switch (action->unk0->unk2) {
    case 0:
        a = atoi(action->unk8[1]);
        if ((s16)atoi(action->unk8[0]) != 0) {
            effect_item_add(a, 2);
        } else {
            effect_item_remove(a, 2);
        }
        break;
    case 1:
        x = atoi(action->unk8[0]) * 10;
        y = atoi(action->unk8[1]) * 10;
        z = atoi(action->unk8[2]) * 10;
        yaw = atoi(action->unk8[3]);
        seconds = atoi(action->unk8[4]);
        flag_bits = atoi(action->unk8[5]);
        if (atoi(action->unk8[6]) == 1) {
            event->unk6 = 4;
            event->unk12 |= 0x20;
        }
        player_start_move_to(0, flag_bits, x, y, z, 0, yaw, 0, seconds);
        break;
    case 2:
        a = atoi(action->unk8[0]);
        b = atoi(action->unk8[1]);
        if (a != 0) {
            effect_weapon_add(b, 1);
        } else {
            effect_weapon_unequip(b);
        }
        break;
    case 3:
        if (atoi(action->unk8[0]) != 0) {
            if (!(player->flags & 0x100)) {
                player->flags |= 0x100;
            }
        } else {
            if (player->flags & 0x100) {
                player->flags &= ~0x100;
            }
        }
        break;
    case 4:
        a = atoi(action->unk8[0]);
        b = atoi(action->unk8[1]);
        status = &player_status;
        if (a < 0) {
            status->infected = 0;
        }
        status->energy += a;
        energy = status->energy;
        if (energy > 255) {
            status->energy = 255;
        } else if (energy < 0) {
            status->energy = 0;
            if (b != 0) {
                status->energy = b;
            }
        } else if (energy > 0 && energy < 255 && energy < b) {
            status->energy = b;
        }
        event_draw_gauge(status);
        break;
    }
}

void player_recover(s32 x, s32 y, s32 z, s16 wake) {
    PlayerStatus *status = &player_status;
    GameVars_u80195DF0 *vars = &action_vars;
    Player *player = status->player;
    s16 injured;
    s32 i;

    if (status->mutant != 0 && wake != 0) {
        status->mutant = 0;
        vars->unk0[6] = 0;
        status->level = vars->unk62[0];
        status->stat0 = vars->unk62[1];
        status->stat1 = vars->unk62[2];
        status->stat2 = vars->unk62[3];
        status->stat3 = vars->unk62[4];
        status->weapon0_level = vars->unk62[5];
        status->weapon1_level = vars->unk62[6];
        status->weapon2_level = vars->unk62[7];
        status->weapon3_level = vars->unk62[8];
        status->weapon4_level = vars->unk62[9];
        status->defense_level = vars->unk62[10];
        for (i = 9; i < 0x1C; i++) {
            vars->unk0[i] = vars->unk28[i];
        }
        sprite_set_clut_entry(0x400, 0x45, 0);
        /* " ミュータント状態から回復した" */
        text_show(D_80170EDC, 1, -1, 0, -1, 0, 0);
    } else {
        injured = player_is_injured();
        if (injured == 0 && wake == 0) {
            /* " 全身がとても軽くなった" */
            text_show(D_80170EFC, 1, -1, 0, -1, 0, 0);
        } else {
            /* " 傷が完全に回復した" */
            text_show(D_80170F14, 1, -1, 0, -1, 0, 0);
        }
    }
    for (i = 0; i < 5; i++) {
        status->limb_state[i] = 0;
        vars->limb_damage[i] = 0;
    }
    if (wake == 0) {
        event_advance_clock(0x3C, 1);
    }
    event_draw_gauge(status);
    event_draw_limb_status(status);
    player->pos_x = x;
    player->pos_z = z;
    player->pos_y = y + player->unk78;
    player_set_view(player, 1);
}

void player_handle_pad(PlayerStatus *status, s32 mode, s32 buttons) {
    Player *player;
    TrainState *train;

    player = status->player;
    train = &vehicle_train_state;
    if (buttons & 0x1000) {
        player->unk3C = 1;
        if (player->vehicle_mode) {
            train->view_pitch += D_801E6DB4[0];
        } else {
            player->pitch += D_801E6DB4[0];
        }
    } else if (buttons & 0x4000) {
        player->unk3C = 1;
        if (player->vehicle_mode) {
            train->view_pitch -= D_801E6DB4[0];
        } else {
            player->pitch -= D_801E6DB4[0];
        }
    }
    if (buttons & 0x8000) {
        player->unk3C = 1;
        if (player->vehicle_mode) {
            train->view_yaw -= D_801E6DB4[0];
        } else {
            player->yaw -= D_801E6DB4[0];
        }
    } else if (buttons & 0x2000) {
        player->unk3C = 1;
        if (player->vehicle_mode) {
            train->view_yaw += D_801E6DB4[0];
        } else {
            player->yaw += D_801E6DB4[0];
        }
    }
    if (player->flags & 0x100) {
        player->speed_step = 4;
        player->flags &= ~0x1000;
        return;
    }
    if (buttons & 0x40) {
        player->unk3C = 1;
        if (player->flags & 0x1000) {
            if (player->speed_step >= 5) {
                player->speed_step--;
                player->unk50 = player->speed_step * D_801E6DB4[0];
            } else {
                player->speed_step = 4;
                player->flags &= ~0x1000;
                player->unk50 = D_801E6DB4[0] * 4;
            }
        } else {
            player->unk50 = -(D_801E6DB4[0] * 4);
        }
    } else if (buttons & 0x10) {
        player->unk3C = 1;
        if ((u16)mode == 2 && (buttons & 1)) {
            if (!(player->flags & 0x1000)) {
                player->flags |= 0x1000;
            }
            if (player->speed_step < 11) {
                player->speed_step++;
            }
            player->unk50 = D_801E6DB4[0] * player->speed_step;
        } else if (player->flags & 0x1000) {
            if (player->speed_step >= 5) {
                player->speed_step--;
                player->unk50 = player->speed_step * D_801E6DB4[0];
            } else {
                player->speed_step = 4;
                player->flags &= ~0x1000;
                player->unk50 = D_801E6DB4[0] * 4;
            }
        } else {
            player->unk50 = D_801E6DB4[0] * 4;
        }
    }
    if (buttons & 4) {
        player->unk3C = 1;
        if (player->flags & 0x1000) {
            if (player->speed_step >= 5) {
                player->speed_step--;
                player->unk50 = player->speed_step * D_801E6DB4[0];
            } else {
                player->speed_step = 4;
                player->flags &= ~0x1000;
                player->unk50 = D_801E6DB4[0] * 4;
            }
        } else {
            player->unk4E = -(D_801E6DB4[0] * 6);
        }
    } else if (buttons & 8) {
        player->unk3C = 1;
        if (player->flags & 0x1000) {
            if (player->speed_step >= 5) {
                player->speed_step--;
                player->unk50 = player->speed_step * D_801E6DB4[0];
            } else {
                player->speed_step = 4;
                player->flags &= ~0x1000;
                player->unk50 = D_801E6DB4[0] * 4;
            }
        } else {
            player->unk4E = D_801E6DB4[0] * 6;
        }
    }
    if (player->unk3C == 0 || (player->unk50 == 0 && player->unk4E == 0)) {
        if (!(player->flags & 0x1000)) {
            return;
        }
        player->unk3C = 1;
        if (player->speed_step >= 5) {
            player->speed_step--;
            player->unk50 = player->speed_step * D_801E6DB4[0];
        } else {
            player->speed_step = 4;
            player->flags &= ~0x1000;
            player->unk50 = D_801E6DB4[0] * 4;
        }
    }
    if ((u16)mode == 2) {
        if (player->vehicle_mode) {
            player->unk50 <<= 2;
            player->unk4E <<= 2;
        }
    } else {
        player->unk50 *= 10;
        player->unk4E *= 10;
    }
    switch (status->limb_state[4]) {
    case 2:
        player->unk50 = player->unk50 * 9 / 10;
        player->unk4E = player->unk4E * 9 / 10;
        break;
    case 3:
        player->unk50 = player->unk50 * 7 / 10;
        player->unk4E = player->unk4E * 7 / 10;
        break;
    }
}

void player_weapon_sound(s16 kind, s16 start) {
    if (start != 0) {
        D_801DFC76 = 1;
        switch (kind) {
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
        switch (kind) {
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

void player_reset_triggers(s16 reground) {
    D_801DFF48 = 0xFFFFFF;
    object_area_previous.trigger_type = 0;
    object_area_current.trigger_type = 0;
    object_area_previous.trigger = 0xFFFFFF;
    object_area_current.trigger = 0xFFFFFF;
    object_area_previous.scene_trigger = 0;
    object_area_current.scene_trigger = 0;
    player_character.unk3E = reground;
    player_character.unk3C = 1;
    player_character.flags &= ~4;
}

s32 player_set_item(s16 item_id, s16 slot_kind, s16 add) {
    s32 result;

    if (add == 0) {
        result = effect_item_remove(item_id, slot_kind);
    } else {
        result = effect_item_add(item_id, slot_kind);
    }
    return result;
}

s32 player_set_weapon(s16 weapon_id, s16 add, s16 stock) {
    s32 result;

    if (add == 0) {
        effect_weapon_unequip(weapon_id);
        result = 1;
    } else {
        result = effect_weapon_add(weapon_id, stock);
    }
    return result;
}

void player_heal_part(s16 part, s16 cap_kind, s16 amount) {
    GameVars_u80195DF0 *vars = &action_vars;
    PlayerStatus *status = &player_status;
    s16 damage = vars->limb_damage[part];

    damage -= amount;
    if (amount < 0) {
        s16 *cap = &player_part_damage_caps[cap_kind];

        if (damage > *cap) {
            damage = *cap;
        }
    } else if (damage < 0) {
        damage = 0;
    }
    *(vars->limb_damage + part) = damage;
    event_draw_limb_status(status);
    event_set_blink(2, 1);
}

void player_add_hp(s16 amount, s16 floor) {
    PlayerStatus *status = &player_status;
    s16 energy;

    if (amount < 0) {
        status->infected = 0;
    }
    energy = status->energy + amount;
    status->energy = energy;
    if (energy >= 0x100) {
        status->energy = 0xFF;
    } else if (energy < 0) {
        status->energy = 0;
        if (floor != 0) {
            status->energy = floor;
        }
    } else if (energy > 0 && energy < 0xFF) {
        if (energy < floor) {
            status->energy = floor;
        }
    }
    event_draw_gauge(status);
}

void player_rest(s16 sleep, s32 x, s32 y, s32 z) {
    PlayerStatus *status = &player_status;
    Player *player = status->player;
    GameVars_u80195DF0 *vars = &action_vars;
    s16 minutes;

    if (sleep == 0) {
        minutes = 0x3C;
        status->hours_awake -= 4;
        if (status->hours_awake < 0) {
            status->hours_awake = 0;
        }
    } else {
        minutes = 0x1A4;
        status->hours_awake = 0;
        if (vars->unk7C > 0x14) {
            minutes = (0x17 - vars->unk7C) * 0x3C - (vars->unk7E - 0x21C);
        } else if (vars->unk7C < 3) {
            minutes = 0x1E0 - vars->unk7E - vars->unk7C * 0x3C;
        }
    }
    player->pos_x = x;
    player->pos_z = z;
    player->pos_y = y + player->unk78;
    player_set_view(player, 1);
    event_advance_clock(minutes, 1);
}

s32 player_is_injured(void) {
    s32 i;

    for (i = 0; i < 5; i++) {
        if (action_vars.limb_damage[i] > 0) {
            return 1;
        }
    }
    return 0;
}

s32 player_leave_trigger(void) {
    Player *player = &player_character;
    KajEvent *event;

    UnDeliverEvent(0xF3000001, 2);
    event = kaj_event_push(0x20);
    if (event != NULL) {
        event->unkC = object_area_current.trigger;
        event->unk8 = object_area_current.trigger_type;
        event->unk10 = object_area_current.scene_trigger;
    }
    object_area_previous.trigger_type = object_area_current.trigger_type;
    object_area_previous.trigger = object_area_current.trigger;
    object_area_previous.scene_trigger = object_area_current.scene_trigger;
    player->flags &= ~4;
    return 0;
}

void player_move_to_done(Unk_8019A07C *task) {
    Unk_8019A07C_3C *move = task->unk3C;
    Player *player = &player_character;
    EventState *s = &event_state;

    player->pos_x = move->unk14;
    player->pos_y = move->unk18;
    player->pos_z = move->unk1C;
    player->pitch = move->unk3C;
    player->yaw = move->unk3E;
    player->unk70 = move->unk40;
    player->flags &= ~2;
    player->unk3C = 1;
    switch (move->unk0) {
    case 0:
        player->flags |= move->unk2;
        break;
    case 1:
        player->flags &= move->unk2;
        break;
    case 2:
        player->flags &= ~move->unk2;
        break;
    }
    if (s->wait_flags & 0x20) {
        s->wait_flags &= ~0x20;
        if (s->wait_flags == 0) {
            s->state = 1;
        }
    }
    player->unk48 = -1;
    if (player->flags & 0x800) {
        player_finish_death();
    }
}

void player_update_map_cursor(Player *player, RoadMap *map) {
    s32 dir;

    if (map->unk2 != 0) {
        if (player->unk60 < -625 || player->unk60 >= 1176 || player->unk68 < -425 || player->unk68 >= 926) {
            if (map->part1[2] != 0) {
                map->part1[2] = 0;
            }
        } else {
            if (map->part1[2] == 0) {
                map->part1[2] = 1;
            }
            dir = (player->yaw + 23) / 45;
            if (dir >= 8) {
                dir = 0;
            }
            map->part1[12] = dir % 4;
            map->part1[13] = dir / 4;
            map->part1[5] = player->unk60 / 10 + 116;
            map->part1[6] = 152 - player->unk68 / 10;
        }
    } else {
        if (player->unk60 < -2425 || player->unk60 >= 2976 || player->unk68 < -2225 || player->unk68 >= 3176) {
            if (map->part1[2] != 0) {
                map->part1[2] = 0;
            }
        } else {
            if (map->part1[2] == 0) {
                map->part1[2] = 1;
            }
            dir = (player->yaw + 23) / 45;
            if (dir >= 8) {
                dir = 0;
            }
            map->part1[12] = dir % 4;
            map->part1[13] = dir / 4;
            map->part1[5] = player->unk60 / 40 + 137;
            map->part1[6] = 135 - player->unk68 / 40;
        }
    }
}

s32 player_update_map(PlayerStatus *status) {
    GameVars_u80195DF0 *vars = &action_vars;
    Player *player = status->player;
    RoadMap *map = &roadmap_state;
    CarNavi *navi;

    if (player->vehicle_mode >= 2) {
        return 0;
    }
    if (map->mode != 2) {
        if (!(kaj_system.pad_prev & 0x100) && (kaj_system.pad_now & 0x100)) {
            if (map->mode == 1) {
                if (map->unk2 == 0) {
                    navi = &vehicle_navi;
                    sound_se_play(0x13);
                    if (navi->active != 0) {
                        if (navi->unk10 != NULL) {
                            navi->unk10->visible = 0;
                        }
                        if (navi->dest_sprite != NULL) {
                            navi->dest_sprite->visible = 0;
                        }
                    }
                    map->unk2 = 1;
                    if (map->part2[2] == 0) {
                        map->part2[2] = !map->part2[2];
                    }
                } else {
                    sound_se_play(0x13);
                    map->mode = 2;
                    map->unk2 = 0;
                    map->part1[2] = 0;
                    map->part2[2] = 0;
                    effect_start_sprite_slide(3, 0x405, 1);
                }
            } else if (map->mode == 0 && vars->menu_busy == 0) {
                navi = &vehicle_navi;
                sound_se_play(0x13);
                if (navi->active != 0) {
                    if (navi->unk10 != NULL) {
                        navi->unk10->visible = 0;
                    }
                    if (navi->dest_sprite != NULL) {
                        navi->dest_sprite->visible = 0;
                    }
                }
                text_close();
                map->mode = 2;
                map->unk2 = 0;
                effect_start_sprite_slide(2, 0x405, 1);
            }
        }
        if (map->mode != 1) {
            return 0;
        }
        player_update_map_cursor(player, map);
    }
    return 1;
}
