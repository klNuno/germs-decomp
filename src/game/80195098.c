#include "common.h"
#include "game/types.h"

void free3(void *ptr);
s32 player_last_trigger;
extern AreaTrigger object_area_current;
extern AreaTrigger object_area_previous;
extern Player player_character;
s16 effect_item_add(s16 item_id, s16 kind);
s16 effect_item_remove(s16 item_id, s16 kind);
void effect_weapon_unequip(s16 weapon_id);
s16 effect_weapon_add(s16 weapon_id, s16 stock);
extern PlayerStatus player_status;
void event_draw_gauge(PlayerStatus *status);
extern GameVars action_vars;
RoomPhone object_room_phone;
void text_show(char *str, s32 mode, s32 circle_set, s32 circle_flags, s32 cross_set, s32 cross_flags, s32 se);
RoomStorage object_room_storage;
u16 object_room_choice_color;
u16 object_room_choice_cursor_color;
extern char object_room_str_storage[];
void sprite_set_visible(s32 id, s32 visible);
void sprite_set_clut_entry(s32 id, s32 index, s32 color);
void text_close(void);
void mail_wait(s32 mode, s32 stream, s32 visibility, s32 seconds);
extern Player *player_status_player[];
Model *mod_find(u16 id);
void mod_set_anim(void *mod, s16 anim, s16 frames);
void object_room_play_call(s16 set_id);
void sound_se_stop(s32 id);
void effect_start_alarm(s32 slot, s32 code, s32 delay);
void player_reset_triggers(s16 reground);
s16 object_room_exit_action;
void object_room_main(void);
void menu_run(void);
void menu_card_run(s32 load_mode, s32 in_office);
void mail_goto_ofc(s32 a, s32 yaw, s32 c, s32 d);
extern EventState event_state;
extern void *player_status_model[];
ActionSet *action_find_set(s16 id);
ActionSet *action_run_set(ActionSet *set, s32 at_cursor, s32 skip_text_wait);
s16 player_area_leave_pending;
void UnDeliverEvent(u32 ev, u32 spec);
KajEvent *kaj_event_push(s32 type);
extern s16 player_part_damage_caps[];
void event_draw_limb_status(PlayerStatus *status);
void event_set_blink(s16 which, s16 on);
void player_finish_death(void);
extern SceneTables object_scene_tables;
s16 object_iff_past_header;
s32 object_aset_count;
extern u8 object_iff_file_pos[4];
s32 CdPosToInt(void *p);
void *CdIntToPos(s32 i, void *p);
s32 CdControl(u8 com, u8 *param, u8 *result);
void sound_se_play(s32 id);
void player_set_view(Player *player, s16 keep_cell);
void event_advance_clock(s16 minutes, s16 no_fatigue);
extern VabStream sound_vab_stream;
s32 CdMode(void);
void *CdLastPos(void);
s32 CdRead(s32 sectors, u32 *buf, s32 mode);
s32 CdReadSync(s32 mode, u8 *result);
s32 VSync(s32 mode);
u32 *sound_se_alloc_header(u8 *src, s32 size, VabStream *bank);
void sound_vab_open_head(VabStream *vab);
extern KajSystem kaj_system;
s32 kaj_pad_read(void);
s16 object_room_storage_input(void);
s16 effect_item_input(PlayerStatus *status, s16 scene_kind);
void object_room_do_action(PlayerStatus *status);
void player_start_move_to(s16 flag_op, u16 flag_bits, s32 x, s32 y, s32 z, s16 pitch, s16 yaw, s16 roll, s32 seconds);
void player_handle_pad(PlayerStatus *status, s32 mode, s32 buttons);
s16 object_room_heal_on_quit;
s32 player_pick_trigger_hook;
extern s32 event_alarm_hook;
extern s32 event_enter_hook;
extern s32 event_effect_done_hook;
extern s32 event_mod_finish_hook;
void action_reset(s16 flush_all);
void action_free_all_sets(void);
void action_free_triggers(void);
void npc_free_bodies(void);
void block_free_all(void);
void door_free_all(void);
void effect_clear_alarms(void);
void mod_free_all(void);
void player_add_hp(s16 amount, s16 floor);
void sound_se_pop_scene(void);
void sound_se_stop_all(void);
void sound_bgm_close(void);
void sound_bgm_stop(void);
void sprite_delete(s32 id);
void thing_free_all(void);
void *kaj_malloc(u32 size);
void kaj_abend(s32 code, char *msg, char *file, s32 line);
void *action_load_set(void *src);
extern char object_str_file[];
void block_create(Block **block_p, s32 size);
void block_setup(Block *block, u16 mode);
void block_list_add(s32 block);
void door_create(Door **out, u32 record_size);
void door_setup(Block *door);
void door_add(void *door);
void mail_create(s32 *out, void *rec, s16 list_index);
extern s32 object_scene_mail[];
void sound_bgm_create(BgmSep **out, u32 size);
void sound_bgm_open(BgmSep *bgm);
void mod_alloc(Model **out, u32 data_size);
void mod_list_add(s32 mod);
void sprite_create(Sprite **out, SpriteRecord *rec);
void sprite_add(s32 sprite);
void kaj_tim_upload_hdr(void *hdr);
void thing_create(Thing **out, u32 record_size);
void sprite_thing_init(Thing *thing);
void thing_list_add(s32 thing);
void kaj_tim_upload(u32 *tim_file, s16 with_clut);
extern u8 *sound_vab_stream_body_buf[];
void sound_vab_transfer(VabStream *vab);
void sound_se_push(SeVabStream *bank);
void vehicle_create(Vehicle **out, u32 size);
void vehicle_init(Vehicle *car);
void object_room_storage_open(s16 reopen, char *line);
void effect_start_fade(s32 kind, s32 seconds);
void kaj_view_set_bg_color(u8 r, u8 g, u8 b);
void player_rest(s16 sleep, s32 x, s32 y, s32 z);
void sound_bgm_play(s16 seq);
s16 object_room_exit_pending;
extern u16 scene_request_arrival[];
extern SceneRequest scene_request;
s32 object_room_on_enter(KajEvent *ev);
s32 object_room_on_effect_done(KajEvent *ev);
void object_room_pick_desk_action(s32 *out);
void object_room_on_alarm(KajEvent *ev);
void object_room_on_mod_finish(KajEvent *ev);
void player_place_for_scene(s32 entry);
void object_load_scene(void);
void mod_npcrec_show(s32 id, s32 force);
void thing_set_active(s32 type, s32 id, s32 active);
void thing_set_animate(s32 type, s32 id, s32 animate);
void thing_set_flag10(s32 type, s32 id, s32 block_fixed);
void effect_weapon_calc_rate(s32 slot);
void mod_setup(Model *mod, s32 parent, s32 kind, s32 anim);
void event_show_clock(s32 light_on);
void object_room_update_input(void);
void object_room_quit(void);
void object_room_init(void);
void kaj_timer_enable(void);
void kaj_timer_disable(void);
void effect_fade_set_black(void);
void text_start_narration(s32 str);
s32 kaj_event_get(s32 *event);
void event_handle_alarm(s32 *ev);
void event_handle_enter(s32 *ev);
void event_handle_leave(s32 *ev);
void event_handle_tick(s16 daylight);
void event_handle_mod_finish(s32 *ev);
s16 event_handle_effect_done(s32 *ev);
void kaj_event_done(s32 *event);
s32 mail_take_scene_change(void);
void text_narration_cues(s16 ending);
void object_room_check_calls(void);
s32 rand(void);
void mail_step_frame(u16 mode, s16 b, s16 c);
void npc_rebase_all(s32 x, s32 y, s32 z);
void block_set_origin(s32 x, s32 y, s32 z);
void door_rebase_all(s32 origin_x, s32 origin_y, s32 origin_z);
void mod_npcrec_rebase_all(s32 origin_x, s32 origin_y, s32 origin_z);
void thing_set_origin(s32 origin_x, s32 origin_y, s32 origin_z);
void vehicle_set_origin(s32 origin_x, s32 origin_y, s32 origin_z);
void MatrixNormal(void *m, void *n);
void *RotMatrix(s16 *r, void *m);
void ApplyMatrixLV(void *arg0, void *arg1, void *arg2);
void GsSetView2(void *arg0);
void RotMatrixZYX(s16 *r, void *m);
void object_iff_open(IffContext **out, s32 res_file, s32 index);
void object_read_chunks(IffContext *iff, s32 request, s32 progress, s32 filter_id);
void action_init_npcs(void);
void *CdSearchFile(void *fp, char *name);
extern s32 object_res_offsets[];
extern s32 object_sce_offsets[];
void text_next_page(EventState *event);
extern Inventory *player_status_inventory[];
s32 object_load_chunk_count;
s32 object_load_bar_step;
void roadmap_draw_sprite_frame(u16 id);
void effect_clut_rotate(void);
s16 mail_list_get_id(s16 i);
void object_load_aset(IffContext *iff, s32 size);
void object_load_blck(IffContext *iff, u16 mode, s32 size);
void object_load_door(IffContext *iff, s32 size);
void object_load_mail(IffContext *iff, s32 size, s32 list_index);
void object_load_midi(IffContext *iff, s32 size);
void object_load_mod(IffContext *iff, s32 size);
void object_load_other(IffContext *iff, s32 tag, s32 size);
void object_load_sprt(IffContext *iff, s32 size);
void object_load_text(IffContext *iff, s32 size);
void object_load_thng(IffContext *iff, s32 size);
void object_load_tim(IffContext *iff, s32 size);
void object_load_vabh(IffContext *iff, s32 size);
void object_load_vabb(IffContext *iff, s32 size);
void object_load_vecl(IffContext *iff, s32 size);
s32 mail_is_read(s16 id);
extern s16 object_room_storage_list[];
void effect_weapon_swap_stock(s16 to_stock, s16 weapon_id);
s32 effect_weapon_list(s16 equipped, s16 *count_out, s16 *ids_out);
s16 mail_menu_move(s16 up);
s32 mail_menu_open(s16 reset, s16 sprite, s16 icon_sprite, s16 count, s16 rows, s16 *list, s16 first_entry, s16 color, s16 cursor_color);
s32 mail_menu_close(void);
s16 mail_menu_get_state(void);
s16 player_blocked_by_area;
s16 player_blocked_by_trigger;
SceneTrigger *action_find_trigger(s32 id);
Npc *npc_find(s16 by_model, u16 id);
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
    player_blocked_by_area = 0;
    player_blocked_by_trigger = 0;
    switch ((u32)col) {
    case 0x1000000:
    case 0x2000000:
        if (player_pick_trigger_hook != 0) {
            ((void (*)(s32 *))player_pick_trigger_hook)(&trigger);
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
            if (npc != NULL && npc->state == 6) {
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
                    player_blocked_by_area = 1;
                    player->move_state = 0;
                    if (player->flags & 0x1000) {
                        player->flags &= ~0x1000;
                        player->speed_step = 4;
                    }
                    walkable = 0;
                }
            } else {
                if (scene_trigger->passable == 0) {
                    player_blocked_by_trigger = 1;
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
        if (trigger != player_last_trigger && trigger != 0xFFFFFF) {
            EnterCriticalSection();
            object_area_current.trigger_type = trigger_type;
            object_area_current.scene_trigger = (s32)scene_trigger;
            object_area_current.trigger = trigger;
            DeliverEvent(0xF3000000, 2);
            player_last_trigger = trigger;
            ExitCriticalSection();
        }
    } else if (trigger != player_last_trigger) {
        EnterCriticalSection();
        if (player_last_trigger != 0xFFFFFF) {
            if (trigger != 0xFFFFFF) {
                player_area_leave_pending = 1;
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
        player_last_trigger = trigger;
        ExitCriticalSection();
    }
    return walkable;
}

void player_set_view(Player *player, s16 keep_cell) {
    s16 rot[3];

    player->view_dirty = 1;
    if (keep_cell != 0) {
        player->pos_x -= player->cell_x * 12500;
        player->pos_y += player->cell_y * 32000;
        player->pos_z -= player->cell_z * 12500;
    } else {
        player->cell_x = player->pos_x / 12500;
        player->cell_y = player->pos_y / -32000;
        player->cell_z = player->pos_z / 12500;
        player->pos_x = player->pos_x % 12500;
        player->pos_y = player->pos_y % 32000;
        player->pos_z = player->pos_z % 12500;
    }
    player->view_trans[0] = -player->pos_x;
    player->world_x = (player->pos_x + player->cell_x * 12500) / 100;
    player->world_y = (player->pos_y - player->cell_y * 32000) / 100;
    player->world_z = (player->pos_z + player->cell_z * 12500) / 100;
    player->view_trans[1] = -player->pos_y;
    player->view_trans[2] = -player->pos_z;
    if (keep_cell == 0) {
        rot[0] = (-player->pitch << 12) / 360;
        rot[1] = (-player->yaw << 12) / 360;
        rot[2] = (-player->roll << 12) / 360;
        RotMatrix(rot, player->view_matrix);
        ApplyMatrixLV(player->view_matrix, player->view_trans, player->view_trans);
        GsSetView2(player->view_matrix);
    }
}

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
    player->world_x = (player->pos_x + x) / 100;
    player->world_y = (player->pos_y + y) / 100;
    player->world_z = (player->pos_z + x) / 100;
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

    player->view_trans[0] = -player->pos_x;
    player->world_x = (player->pos_x + player->cell_x * 12500) / 100;
    player->world_y = (player->pos_y - player->cell_y * 32000) / 100;
    player->world_z = (player->pos_z + player->cell_z * 12500) / 100;
    player->view_trans[1] = -player->pos_y;
    player->view_trans[2] = -player->pos_z;
    MatrixNormal(player->view_matrix, player->view_matrix);
    RotMatrix(view_rot, player->view_matrix);
    ApplyMatrixLV(player->view_matrix, player->view_trans, player->view_trans);
    GsSetView2(player->view_matrix);
    if (mode == 1) {
        player->coord[0].coord_tx = player->pos_x;
        player->coord[0].coord_ty = player->pos_y - player->bob_y + 320;
        player->coord[0].coord_tz = player->pos_z;
        rot[0] = (player->pitch << 12) / 360;
        rot[1] = (player->yaw << 12) / 360;
        rot[2] = (player->roll << 12) / 360;
        RotMatrixZYX(rot, player->coord[0].coord_m);
        player->coord[0].flg = 0;
    }
    player->view_dirty = 0;
}
