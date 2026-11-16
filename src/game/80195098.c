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
extern GameVars action_vars;
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
extern u8 object_iff_file_pos[4];
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
void block_create(Block **arg0, s32 arg1);
void block_setup(Block *arg0, u16 arg1);
void block_list_add(s32 arg0);
void door_create(Door **arg0, u32 arg1);
void door_setup(Block *arg0);
void door_add(void *arg0);
void mail_create(s32 *arg0, void *arg1, s16 arg2);
extern s32 D_801E0324[];
void sound_bgm_create(BgmSep **arg0, u32 arg1);
void sound_bgm_open(BgmSep *arg0);
void mod_alloc(Model **arg0, u32 arg1);
void mod_list_add(s32 arg0);
void sprite_create(Sprite **arg0, SpriteRecord *arg1);
void sprite_add(s32 arg0);
void kaj_tim_upload_hdr(void *arg0);
void thing_create(Thing **arg0, u32 arg1);
void sprite_thing_init(Thing *arg0);
void thing_list_add(s32 arg0);
void kaj_tim_upload(u32 *arg0, s16 arg1);
extern u8 *D_801E05C8[];
void sound_vab_transfer(VabStream *arg0);
void sound_se_push(Unk_801A217C *arg0);
typedef struct { s32 unk0; s32 unk4; s32 unk8; s32 unkC; s32 unk10; s32 unk14; s32 unk18; s32 unk1C; s32 unk20; s32 unk24; s32 unk28; s32 unk2C; s32 unk30; s32 unk34; s32 unk38; } Unk_801E032C;
void vehicle_create(Vehicle **arg0, u32 arg1);
void vehicle_init(Unk_801E032C *arg0);
void object_room_storage_open(s16 arg0, char *arg1);
void effect_start_fade(s32 arg0, s32 arg1);
void kaj_view_set_bg_color(u8 arg0, u8 arg1, u8 arg2);
void player_rest(s16 arg0, s32 arg1, s32 arg2, s32 arg3);
void sound_bgm_play(s16 arg0);
s16 D_801DFD56;
extern u16 D_801E0356[];
extern SceneRequest scene_request;
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
void mod_setup(Model *arg0, s32 arg1, s32 arg2, s32 arg3);
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
void object_iff_open(IffContext **arg0, s32 arg1, s32 arg2);
void object_read_chunks(IffContext *arg0, s32 arg1, s32 arg2, s32 arg3);
void action_init_npcs(void);
void *CdSearchFile(void *fp, char *name);
extern s32 object_res_offsets[];
extern s32 object_sce_offsets[];
void text_next_page(EventState *arg0);
extern Inventory *player_status_inventory[];
s32 object_load_chunk_count;
s32 object_load_bar_step;
void roadmap_draw_sprite_frame(s32 arg0);
void effect_clut_rotate(void);
s16 mail_list_get_id(s16 i);
void object_load_aset(IffContext *arg0, s32 arg1);
void object_load_blck(IffContext *arg0, u16 arg1, s32 arg2);
void object_load_door(IffContext *arg0, s32 arg1);
void object_load_mail(IffContext *arg0, s32 arg1, s32 arg2);
void object_load_midi(IffContext *arg0, s32 arg1);
void object_load_mod(IffContext *arg0, s32 arg1);
void object_load_other(IffContext *arg0, s32 arg1, s32 arg2);
void object_load_sprt(IffContext *arg0, s32 arg1);
void object_load_text(IffContext *arg0, s32 arg1);
void object_load_thng(IffContext *arg0, s32 arg1);
void object_load_tim(IffContext *arg0, s32 arg1);
void object_load_vabh(IffContext *arg0, s32 arg1);
void object_load_vabb(IffContext *arg0, s32 arg1);
void object_load_vecl(IffContext *arg0, s32 arg1);
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

s16 player_check_ground(Player *player, s32 col, s16 sidestep, s16 slide) {
    s32 trigger;
    u16 trigger_type;
    SceneTrigger *scene_trigger;
    s16 walkable;
    s16 enter_only;
    s32 kind;
    s32 v;
    Npc *npc;

    v = 0xFFFFFF;
    trigger_type = 0;
    scene_trigger = NULL;
    enter_only = 0;
    walkable = 1;
    trigger = v;
    D_801DFD5C = 0;
    D_801DFD5E = 0;
    switch ((u32)col) {
    case 0x1000000:
    case 0x2000000:
        if (D_801DFF50 != 0) {
            ((void (*)(s32 *))D_801DFF50)(&trigger);
        }
        enter_only = 1;
        trigger_type = ((u8 *)&trigger)[2];
        walkable = 0;
        player->move_state = 0;
        trigger &= v;
        break;
    case 0xFFFF:
    case 0x9600:
    case 0xFF00:
        if (slide == 0) {
            if (sidestep != 0) {
                player->move_state = 3;
            } else if (player->flags & 0x1000) {
                player->move_state = 2;
            } else {
                player->move_state = 1;
            }
        } else {
            player->move_state = 5;
            if (player->flags & 0x1000) {
                player->flags &= ~0x1000;
                player->speed_step = 4;
            }
        }
        break;
    default:
        kind = col & 0xFF0000;
        if (kind == 0xFC0000) {
            trigger_type = 0xFC;
            trigger = col & 0xFFFFFF;
            npc = npc_find(0, col);
            if (npc != NULL && npc->unkF == 6) {
                if (sidestep != 0) {
                    player->move_state = 3;
                } else if (player->flags & 0x1000) {
                    player->move_state = 2;
                } else {
                    player->move_state = 1;
                }
            } else {
                player->move_state = 0;
                if (player->flags & 0x1000) {
                    player->flags &= ~0x1000;
                    player->speed_step = 4;
                }
                walkable = 0;
            }
        } else if (kind == 0xF70000) {
            trigger_type = 0xF7;
            trigger = col & 0xFFFFFF;
            player->move_state = 0;
            if (player->flags & 0x1000) {
                player->flags &= ~0x1000;
                player->speed_step = 4;
            }
            walkable = 0;
        } else if (kind == 0xFD0000) {
            trigger_type = 0xFD;
            trigger = col & 0xFFFFFF;
            player->move_state = 0;
            if (player->flags & 0x1000) {
                player->flags &= ~0x1000;
                player->speed_step = 4;
            }
            walkable = 0;
        } else if (kind != 0) {
            if (slide == 0) {
                if (player->flags & 0x1000) {
                    player->move_state = 2;
                } else {
                    player->move_state = 1;
                }
            } else {
                player->move_state = 5;
                if (player->flags & 0x1000) {
                    player->flags &= ~0x1000;
                    player->speed_step = 4;
                }
            }
            trigger_type = ((u32)col >> 16) & 0xFF;
            trigger = col;
            scene_trigger = action_find_trigger(col);
            if (scene_trigger == NULL) {
                if (trigger_type == 0xFF) {
                    D_801DFD5C = 1;
                    player->move_state = 0;
                    if (player->flags & 0x1000) {
                        player->flags &= ~0x1000;
                        player->speed_step = 4;
                    }
                    walkable = 0;
                }
            } else {
                if (scene_trigger->unk8 == 0) {
                    D_801DFD5E = 1;
                    player->move_state = 0;
                    if (player->flags & 0x1000) {
                        player->flags &= ~0x1000;
                        player->speed_step = 4;
                    }
                    walkable = 0;
                }
                if (scene_trigger->enabled == 0) {
                    trigger_type = 0;
                    trigger = 0xFFFFFF;
                    scene_trigger = NULL;
                }
            }
        } else {
            player->move_state = 4;
            if (player->flags & 0x1000) {
                player->flags &= ~0x1000;
                player->speed_step = 4;
            }
            enter_only = 1;
            walkable = 0;
        }
        break;
    }
    if (enter_only != 0) {
        if (trigger != D_801DFF48 && trigger != 0xFFFFFF) {
            EnterCriticalSection();
            object_area_current.trigger_type = trigger_type;
            object_area_current.scene_trigger = (s32)scene_trigger;
            object_area_current.trigger = trigger;
            DeliverEvent(0xF3000000, 2);
            D_801DFF48 = trigger;
            ExitCriticalSection();
        }
    } else if (trigger != D_801DFF48) {
        EnterCriticalSection();
        if (D_801DFF48 != 0xFFFFFF) {
            if (trigger != 0xFFFFFF) {
                D_801DFF4C = 1;
                object_area_current.trigger_type = trigger_type;
                object_area_current.trigger = trigger;
                object_area_current.scene_trigger = (s32)scene_trigger;
                DeliverEvent(0xF3000000, 2);
            } else {
                object_area_current.trigger_type = object_area_previous.trigger_type;
                object_area_current.trigger = object_area_previous.trigger;
                object_area_current.scene_trigger = object_area_previous.scene_trigger;
                DeliverEvent(0xF3000001, 2);
            }
        } else {
            object_area_current.trigger_type = trigger_type;
            object_area_current.scene_trigger = (s32)scene_trigger;
            object_area_current.trigger = trigger;
            DeliverEvent(0xF3000000, 2);
        }
        D_801DFF48 = trigger;
        ExitCriticalSection();
    }
    return walkable;
}

INCLUDE_ASM("asm/nonmatchings/game/80195098", player_set_view);

void player_wrap_cell(Player *player) {
    s32 x;
    s32 y;
    s32 z;

    if (player->pos_x >= -12500 && player->pos_x <= 12500 && player->pos_y <= 32000 && player->pos_y >= -32000
        && player->pos_z <= 12500 && player->pos_z >= -12500) {
        return;
    }
    if (player->pos_x > 12500) {
        player->cell_x++;
        player->pos_x -= 12500;
    }
    if (player->pos_x < -12500) {
        player->cell_x--;
        player->pos_x += 12500;
    }
    if (player->pos_y < -32000) {
        player->cell_y++;
        player->pos_y += 32000;
    }
    if (player->pos_y > 32000) {
        player->cell_y--;
        player->pos_y -= 32000;
    }
    if (player->pos_z > 12500) {
        player->cell_z++;
        player->pos_z -= 12500;
    }
    if (player->pos_z < -12500) {
        player->cell_z--;
        player->pos_z += 12500;
    }
    x = player->cell_x * 12500;
    y = -(player->cell_y * 32000);
    z = player->cell_z * 12500;
    player->unk60 = (player->pos_x + x) / 100;
    player->unk64 = (player->pos_y + y) / 100;
    player->unk68 = (player->pos_z + x) / 100;
    npc_rebase_all(x, y, z);
    block_set_origin(x, y, z);
    door_rebase_all(x, y, z);
    mod_npcrec_rebase_all(x, y, z);
    thing_set_origin(x, y, z);
    if (player->vehicle_mode != 0) {
        vehicle_set_origin(x, y, z);
    }
}

void player_update_view(Player *player, s16 *view_rot, u16 mode) {
    s16 rot[3];

    player->unk90[0] = -player->pos_x;
    player->unk60 = (player->pos_x + player->cell_x * 12500) / 100;
    player->unk64 = (player->pos_y - player->cell_y * 32000) / 100;
    player->unk68 = (player->pos_z + player->cell_z * 12500) / 100;
    player->unk90[1] = -player->pos_y;
    player->unk90[2] = -player->pos_z;
    MatrixNormal(player->unk7C, player->unk7C);
    RotMatrix(view_rot, player->unk7C);
    ApplyMatrixLV(player->unk7C, player->unk90, player->unk90);
    GsSetView2(player->unk7C);
    if (mode == 1) {
        player->coord[0].coord_tx = player->pos_x;
        player->coord[0].coord_ty = player->pos_y - player->unk4C + 320;
        player->coord[0].coord_tz = player->pos_z;
        rot[0] = (player->pitch << 12) / 360;
        rot[1] = (player->yaw << 12) / 360;
        rot[2] = (player->unk70 << 12) / 360;
        RotMatrixZYX(rot, player->coord[0].coord_m);
        player->coord[0].flg = 0;
    }
    player->unk3C = 0;
}
