#include "common.h"
#include "game/types.h"

void free3(void *ptr);
s32 D_801DFF48;
extern Unk_801E0600 D_801E0600;
extern Unk_801E0600 D_801E0610;
extern Player player_character;
s16 effect_item_add(s16 arg0, s16 arg1);
s16 effect_item_remove(s16 arg0, s16 arg1);
void effect_weapon_unequip(s16 arg0);
s16 effect_weapon_add(s16 arg0, s16 arg1);
extern PlayerStatus player_status;
void event_draw_gauge(PlayerStatus *arg0);
extern GameVars action_vars;
Unk_801DFF30 object_room_phone;
void text_show(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
Unk_801DFF28 object_room_storage;
u16 D_801DFD58;
u16 D_801DFD5A;
extern char D_80170E18[];
void sprite_set_visible(s32 arg0, s32 arg1);
void sprite_set_clut_entry(s32 arg0, s32 arg1, s32 arg2);
void text_close(void);
void mail_wait(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern Player *D_801E076C[];
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
extern Unk_801DFFE8 D_801DFFE8;
extern void *D_801E0760[];
Unk_80174B10 *action_find_set(s16 arg0);
Unk_80174B10 *action_run_set(Unk_80174B10 *arg0, s32 arg1, s32 arg2);
s16 D_801DFF4C;
void UnDeliverEvent(u32 ev, u32 spec);
Unk_801CC1E8 *kaj_event_push(s32 arg0);
extern s16 player_part_damage_caps[];
void event_draw_limb_status(PlayerStatus *arg0);
void event_set_blink(s16 arg0, s16 arg1);
void player_finish_death(void);
extern SceneTables object_scene_tables;
s16 D_801DFF18;
s32 object_aset_count;
extern u8 object_iff_file_pos[4];
s32 CdPosToInt(void *p);
void *CdIntToPos(s32 i, void *p);
s32 CdControl(u8 com, u8 *param, u8 *result);
void sound_se_play(s32 arg0);
void player_set_view(Player *arg0, s16 arg1);
void event_advance_clock(s16 a, s16 b);
extern Unk_801A3970 D_801E05C0;
s32 CdMode(void);
void *CdLastPos(void);
s32 CdRead(s32 sectors, u32 *buf, s32 mode);
s32 CdReadSync(s32 mode, u8 *result);
s32 VSync(s32 mode);
u32 *sound_se_alloc_header(u8 *arg0, s32 arg1, Unk_801A3970 *arg2);
void sound_vab_open_head(Unk_801A3970 *arg0);
extern KajSystem kaj_system;
s32 kaj_pad_read(void);
s16 object_room_storage_input(void);
s16 effect_item_input(PlayerStatus *arg0, s16 arg1);
void object_room_do_action(PlayerStatus *arg0);
void player_start_move_to(s16 a, u16 b, s32 c, s32 d, s32 e, s16 f, s16 g, s16 h, s32 i);
void player_handle_pad(PlayerStatus *arg0, s32 arg1, s32 arg2);
s16 D_801DFD54;
s32 D_801DFF50;
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
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
void *action_load_set(void *arg0);
extern char D_80170B7C[];
void block_create(Unk_8017CCE4 **arg0, s32 arg1);
void block_setup(Unk_8017CCE4 *arg0, u16 arg1);
void block_list_add(s32 arg0);
void door_create(Unk_801854B8 **arg0, u32 arg1);
void door_setup(Unk_8017CCE4 *arg0);
void door_add(void *arg0);
void mail_create(s32 *arg0, void *arg1, s16 arg2);
extern s32 D_801E0324[];
void sound_bgm_create(Unk_801A3B5C **arg0, u32 arg1);
void sound_bgm_open(Unk_801A3B5C *arg0);
void mod_alloc(Unk_8018E56C **arg0, u32 arg1);
void mod_list_add(s32 arg0);
void sprite_create(Unk_801A4370 **arg0, Unk_801A3DD4 *arg1);
void sprite_add(s32 arg0);
void kaj_tim_upload_hdr(void *arg0);
void thing_create(Unk_801A7AFC **arg0, u32 arg1);
void sprite_thing_init(Unk_801A7AFC *arg0);
void thing_list_add(s32 arg0);
void kaj_tim_upload(u32 *arg0, s16 arg1);
extern u8 *D_801E05C8[];
void sound_vab_transfer(Unk_801A3970 *arg0);
void sound_se_push(Unk_801A217C *arg0);
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; } Unk_801E032C;
void vehicle_create(Unk_801AC278 **arg0, u32 arg1);
void vehicle_init(Unk_801E032C *arg0);
void object_room_storage_open(s16 arg0, char *arg1);
void effect_start_fade(s32 arg0, s32 arg1);
void kaj_view_set_bg_color(u8 arg0, u8 arg1, u8 arg2);
void player_rest(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
void sound_bgm_play(s16 arg0);
s16 D_801DFD56;
extern u16 D_801E0356[];
extern Unk_801E0340 D_801E0340;
s32 object_room_on_enter(Unk_80192F60 *arg0);
s32 object_room_on_effect_done(Unk_80193068 *arg0);
void object_room_pick_desk_action(s32 *arg0);
void object_room_on_alarm(Unk_80192F60 *arg0);
void object_room_on_mod_finish(Unk_80192F60 *arg0);
void player_place_for_scene(s32 arg0);
void object_load_scene(void);
void mod_npcrec_show(s32 arg0, s32 arg1);
void thing_set_active(s32 arg0, s32 arg1, s32 arg2);
void thing_set_animate(s32 arg0, s32 arg1, s32 arg2);
void thing_set_flag10(s32 arg0, s32 arg1, s32 arg2);
void effect_weapon_calc_rate(s32 arg0);
void mod_setup(Unk_8018E56C *arg0, s32 arg1, s32 arg2, s32 arg3);
void event_show_clock(s32 arg0);
void object_room_update_input(void);
void object_room_quit(void);
void object_room_init(void);
void kaj_timer_enable(void);
void kaj_timer_disable(void);
void effect_fade_set_black(void);
void text_start_narration(s32 arg0);
s32 kaj_event_get(s32 *arg0);
void func_80189928(s32 *arg0);
void event_handle_enter(s32 *arg0);
void event_handle_leave(s32 *arg0);
void event_handle_tick(s16 arg0);
void event_handle_mod_finish(s32 *arg0);
s16 event_handle_effect_done(s32 *arg0);
void kaj_event_done(s32 *arg0);
s32 mail_take_scene_change(void);
void text_narration_cues(s16 arg0);
void object_room_check_calls(void);
s32 rand(void);
void mail_step_frame(u16 a, s16 b, s16 c);
void npc_rebase_all(s32 arg0, s32 arg1, s32 arg2);
void block_set_origin(s32 arg0, s32 arg1, s32 arg2);
void door_rebase_all(s32 arg0, s32 arg1, s32 arg2);
void mod_npcrec_rebase_all(s32 arg0, s32 arg1, s32 arg2);
void thing_set_origin(s32 arg0, s32 arg1, s32 arg2);
void vehicle_set_origin(s32 arg0, s32 arg1, s32 arg2);
void MatrixNormal(void *m, void *n);
void RotMatrix(s16 *r, void *m);
void ApplyMatrixLV(void *arg0, void *arg1, void *arg2);
void GsSetView2(void *arg0);
void RotMatrixZYX(s16 *r, void *m);
void object_iff_open(Unk_80192F20 **arg0, s32 arg1, s32 arg2);
void object_read_chunks(Unk_80192F20 *arg0, s32 arg1, s32 arg2, s32 arg3);
void action_init_npcs(void);
void *CdSearchFile(void *fp, char *name);
extern s32 object_res_offsets[];
extern s32 object_sce_offsets[];
void text_next_page(Unk_801DFFE8 *arg0);
extern Inventory *D_801E0768[];
s32 object_load_chunk_count;
s32 object_load_bar_step;
void roadmap_draw_sprite_frame(s32 arg0);
void effect_clut_rotate(void);
s16 mail_list_get_id(s16 i);
void object_load_aset(Unk_80192F20 *arg0, s32 arg1);
void object_load_blck(Unk_80192F20 *arg0, u16 arg1, s32 arg2);
void object_load_door(Unk_80192F20 *arg0, s32 arg1);
void object_load_mail(Unk_80192F20 *arg0, s32 arg1, s32 arg2);
void object_load_midi(Unk_80192F20 *arg0, s32 arg1);
void object_load_mod(Unk_80192F20 *arg0, s32 arg1);
void object_load_other(Unk_80192F20 *arg0, s32 arg1, s32 arg2);
void object_load_sprt(Unk_80192F20 *arg0, s32 arg1);
void object_load_text(Unk_80192F20 *arg0, s32 arg1);
void object_load_thng(Unk_80192F20 *arg0, s32 arg1);
void object_load_tim(Unk_80192F20 *arg0, s32 arg1);
void object_load_vabh(Unk_80192F20 *arg0, s32 arg1);
void object_load_vabb(Unk_80192F20 *arg0, s32 arg1);
void object_load_vecl(Unk_80192F20 *arg0, s32 arg1);
s32 mail_is_read(s16 a);
extern s16 D_801E05E0[];
void effect_weapon_swap_stock(s16 arg0, s16 arg1);
s32 effect_weapon_list(s16 arg0, s16 *arg1, s16 *arg2);
s16 mail_menu_move(s16 a);
s32 mail_menu_open(s16 a, s16 b, s16 c, s16 d, s16 e, s16 *f, s16 g, s16 h, s16 i);
s32 mail_menu_close(void);
s16 mail_menu_get_state(void);
s16 D_801DFD5C;
s16 D_801DFD5E;
SceneTrigger *action_find_trigger(s32 arg0);
Npc *npc_find(s16 arg0, u16 arg1);
void EnterCriticalSection(void);
void ExitCriticalSection(void);
void DeliverEvent(u32 ev, u32 spec);

s16 player_check_ground(Player *arg0, s32 arg1, s16 arg2, s16 arg3) {
    s32 sp10;
    u16 s1;
    SceneTrigger *s3;
    s16 s2;
    s16 s6;
    s32 t;
    s32 v;
    Npc *p;

    v = 0xFFFFFF;
    s1 = 0;
    s3 = NULL;
    s6 = 0;
    s2 = 1;
    sp10 = v;
    D_801DFD5C = 0;
    D_801DFD5E = 0;
    switch ((u32)arg1) {
    case 0x1000000:
    case 0x2000000:
        if (D_801DFF50 != 0) {
            ((void (*)(s32 *))D_801DFF50)(&sp10);
        }
        s6 = 1;
        s1 = ((u8 *)&sp10)[2];
        s2 = 0;
        arg0->move_state = 0;
        sp10 &= v;
        break;
    case 0xFFFF:
    case 0x9600:
    case 0xFF00:
        if (arg3 == 0) {
            if (arg2 != 0) {
                arg0->move_state = 3;
            } else if (arg0->flags & 0x1000) {
                arg0->move_state = 2;
            } else {
                arg0->move_state = 1;
            }
        } else {
            arg0->move_state = 5;
            if (arg0->flags & 0x1000) {
                arg0->flags &= ~0x1000;
                arg0->speed_step = 4;
            }
        }
        break;
    default:
        t = arg1 & 0xFF0000;
        if (t == 0xFC0000) {
            s1 = 0xFC;
            sp10 = arg1 & 0xFFFFFF;
            p = npc_find(0, arg1);
            if (p != NULL && p->unkF == 6) {
                if (arg2 != 0) {
                    arg0->move_state = 3;
                } else if (arg0->flags & 0x1000) {
                    arg0->move_state = 2;
                } else {
                    arg0->move_state = 1;
                }
            } else {
                arg0->move_state = 0;
                if (arg0->flags & 0x1000) {
                    arg0->flags &= ~0x1000;
                    arg0->speed_step = 4;
                }
                s2 = 0;
            }
        } else if (t == 0xF70000) {
            s1 = 0xF7;
            sp10 = arg1 & 0xFFFFFF;
            arg0->move_state = 0;
            if (arg0->flags & 0x1000) {
                arg0->flags &= ~0x1000;
                arg0->speed_step = 4;
            }
            s2 = 0;
        } else if (t == 0xFD0000) {
            s1 = 0xFD;
            sp10 = arg1 & 0xFFFFFF;
            arg0->move_state = 0;
            if (arg0->flags & 0x1000) {
                arg0->flags &= ~0x1000;
                arg0->speed_step = 4;
            }
            s2 = 0;
        } else if (t != 0) {
            if (arg3 == 0) {
                if (arg0->flags & 0x1000) {
                    arg0->move_state = 2;
                } else {
                    arg0->move_state = 1;
                }
            } else {
                arg0->move_state = 5;
                if (arg0->flags & 0x1000) {
                    arg0->flags &= ~0x1000;
                    arg0->speed_step = 4;
                }
            }
            s1 = ((u32)arg1 >> 16) & 0xFF;
            sp10 = arg1;
            s3 = action_find_trigger(arg1);
            if (s3 == NULL) {
                if (s1 == 0xFF) {
                    D_801DFD5C = 1;
                    arg0->move_state = 0;
                    if (arg0->flags & 0x1000) {
                        arg0->flags &= ~0x1000;
                        arg0->speed_step = 4;
                    }
                    s2 = 0;
                }
            } else {
                if (s3->unk8 == 0) {
                    D_801DFD5E = 1;
                    arg0->move_state = 0;
                    if (arg0->flags & 0x1000) {
                        arg0->flags &= ~0x1000;
                        arg0->speed_step = 4;
                    }
                    s2 = 0;
                }
                if (s3->unkA == 0) {
                    s1 = 0;
                    sp10 = 0xFFFFFF;
                    s3 = NULL;
                }
            }
        } else {
            arg0->move_state = 4;
            if (arg0->flags & 0x1000) {
                arg0->flags &= ~0x1000;
                arg0->speed_step = 4;
            }
            s6 = 1;
            s2 = 0;
        }
        break;
    }
    if (s6 != 0) {
        if (sp10 != D_801DFF48 && sp10 != 0xFFFFFF) {
            EnterCriticalSection();
            D_801E0600.unk4 = s1;
            D_801E0600.unk8 = (s32)s3;
            D_801E0600.unk0 = sp10;
            DeliverEvent(0xF3000000, 2);
            D_801DFF48 = sp10;
            ExitCriticalSection();
        }
    } else if (sp10 != D_801DFF48) {
        EnterCriticalSection();
        if (D_801DFF48 != 0xFFFFFF) {
            if (sp10 != 0xFFFFFF) {
                D_801DFF4C = 1;
                D_801E0600.unk4 = s1;
                D_801E0600.unk0 = sp10;
                D_801E0600.unk8 = (s32)s3;
                DeliverEvent(0xF3000000, 2);
            } else {
                D_801E0600.unk4 = D_801E0610.unk4;
                D_801E0600.unk0 = D_801E0610.unk0;
                D_801E0600.unk8 = D_801E0610.unk8;
                DeliverEvent(0xF3000001, 2);
            }
        } else {
            D_801E0600.unk4 = s1;
            D_801E0600.unk8 = (s32)s3;
            D_801E0600.unk0 = sp10;
            DeliverEvent(0xF3000000, 2);
        }
        D_801DFF48 = sp10;
        ExitCriticalSection();
    }
    return s2;
}

INCLUDE_ASM("asm/nonmatchings/game/80195098", player_set_view);

void player_wrap_cell(Player *arg0) {
    s32 x;
    s32 y;
    s32 z;

    if (arg0->pos_x >= -12500 && arg0->pos_x <= 12500 && arg0->pos_y <= 32000 && arg0->pos_y >= -32000
        && arg0->pos_z <= 12500 && arg0->pos_z >= -12500) {
        return;
    }
    if (arg0->pos_x > 12500) {
        arg0->cell_x++;
        arg0->pos_x -= 12500;
    }
    if (arg0->pos_x < -12500) {
        arg0->cell_x--;
        arg0->pos_x += 12500;
    }
    if (arg0->pos_y < -32000) {
        arg0->cell_y++;
        arg0->pos_y += 32000;
    }
    if (arg0->pos_y > 32000) {
        arg0->cell_y--;
        arg0->pos_y -= 32000;
    }
    if (arg0->pos_z > 12500) {
        arg0->cell_z++;
        arg0->pos_z -= 12500;
    }
    if (arg0->pos_z < -12500) {
        arg0->cell_z--;
        arg0->pos_z += 12500;
    }
    x = arg0->cell_x * 12500;
    y = -(arg0->cell_y * 32000);
    z = arg0->cell_z * 12500;
    arg0->unk60 = (arg0->pos_x + x) / 100;
    arg0->unk64 = (arg0->pos_y + y) / 100;
    arg0->unk68 = (arg0->pos_z + x) / 100;
    npc_rebase_all(x, y, z);
    block_set_origin(x, y, z);
    door_rebase_all(x, y, z);
    mod_npcrec_rebase_all(x, y, z);
    thing_set_origin(x, y, z);
    if (arg0->vehicle_mode != 0) {
        vehicle_set_origin(x, y, z);
    }
}

void player_update_view(Player *arg0, s16 *arg1, u16 arg2) {
    s16 rot[3];

    arg0->unk90[0] = -arg0->pos_x;
    arg0->unk60 = (arg0->pos_x + arg0->cell_x * 12500) / 100;
    arg0->unk64 = (arg0->pos_y - arg0->cell_y * 32000) / 100;
    arg0->unk68 = (arg0->pos_z + arg0->cell_z * 12500) / 100;
    arg0->unk90[1] = -arg0->pos_y;
    arg0->unk90[2] = -arg0->pos_z;
    MatrixNormal(arg0->unk7C, arg0->unk7C);
    RotMatrix(arg1, arg0->unk7C);
    ApplyMatrixLV(arg0->unk7C, arg0->unk90, arg0->unk90);
    GsSetView2(arg0->unk7C);
    if (arg2 == 1) {
        arg0->coord[0].coord_tx = arg0->pos_x;
        arg0->coord[0].coord_ty = arg0->pos_y - arg0->unk4C + 320;
        arg0->coord[0].coord_tz = arg0->pos_z;
        rot[0] = (arg0->pitch << 12) / 360;
        rot[1] = (arg0->yaw << 12) / 360;
        rot[2] = (arg0->unk70 << 12) / 360;
        RotMatrixZYX(rot, arg0->coord[0].coord_m);
        arg0->coord[0].flg = 0;
    }
    arg0->unk3C = 0;
}
