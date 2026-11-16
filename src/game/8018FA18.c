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
/* Local view of GameVars: this unit reads 0x0-0x7A as an s16 array and 0x7A-0xB4 as scalars, the shared type has one u16 array. */
typedef struct {
    s16 vars[0x3D];
    s16 day;
    s16 hour;
    u16 minute;
    u8 unk80[0x18];
    s16 var76;
    u8 unk9A[0x18];
    u16 phone_calls_done;
    s16 limb_damage[5];
    u8 unkBE[0x186];
    s32 fade_tss;
} GameVars_u8018FA18;
extern GameVars_u8018FA18 action_vars;
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
void player_set_view(Player *arg0, s16 arg1);
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
extern s32 player_pick_trigger_hook;
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
void RotMatrix(s16 *r, void *m);
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
void roadmap_draw_sprite_frame(s32 arg0);
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

void object_load_aset(IffContext *iff, s32 size) {
    u8 cd_mode;
    void *buf;
    void *set;
    s32 n;
    s32 i;
    u8 *p;
    u32 *dst;

    buf = kaj_malloc(size);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_ASET Buffer", object_str_file, 0x8D);
    }
    *(IffChunkBody *)buf = *(IffChunkBody *)((u8 *)iff->chunk + 8);
    if (size > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = size - 0x7F8;
    retry:
        cd_mode = CdMode();
        if (!(cd_mode & 0x80)) {
            cd_mode = 0x80;
            while (CdControl(0xE, &cd_mode, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(n >> 11, dst, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) == -1) {
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
            goto retry;
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    set = buf;
    for (i = 0; i < object_aset_count; i++) {
        set = action_load_set(set);
    }
    free3(buf);
}

void object_load_blck(IffContext *iff, u16 mode, s32 size) {
    Block *block;
    u8 cd_mode;
    s32 n;
    u32 *dst;
    u8 *p;

    block = NULL;
    block_create(&block, size);
    *(IffChunkBody *)block->data = *(IffChunkBody *)((u8 *)iff->chunk + 8);
    if (size > 0x7F8) {
        dst = (u32 *)((u8 *)block->data + 0x7F8);
        n = size - 0x7F8;
        while (1) {
            cd_mode = CdMode();
            if (!(cd_mode & 0x80)) {
                cd_mode = 0x80;
                while (CdControl(0xE, &cd_mode, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    block_setup(block, mode);
    block_list_add((s32)block);
}

void object_load_door(IffContext *iff, s32 size) {
    Door *door;
    u8 cd_mode;
    s32 n;
    u32 *dst;
    u8 *p;

    door = NULL;
    door_create(&door, size);
    *(IffChunkBody *)door->record = *(IffChunkBody *)((u8 *)iff->chunk + 8);
    if (size > 0x7F8) {
        dst = (u32 *)((u8 *)door->record + 0x7F8);
        n = size - 0x7F8;
        while (1) {
            cd_mode = CdMode();
            if (!(cd_mode & 0x80)) {
                cd_mode = 0x80;
                while (CdControl(0xE, &cd_mode, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    door_setup((Block *)door);
    door_add(door);
}

INCLUDE_RODATA("asm/nonmatchings/game/8018FA18", object_str_file);

void object_load_mail(IffContext *iff, s32 size, s32 list_index) {
    u8 cd_mode;
    s32 mail;
    void *buf;
    s32 n;
    u8 *p;
    u32 *dst;

    buf = kaj_malloc(size);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_MAIL Buffer", object_str_file, 0xC6);
    }
    *(IffChunkBody *)buf = *(IffChunkBody *)((u8 *)iff->chunk + 8);
    if (size > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = size - 0x7F8;
    retry:
        cd_mode = CdMode();
        if (!(cd_mode & 0x80)) {
            cd_mode = 0x80;
            while (CdControl(0xE, &cd_mode, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(n >> 11, dst, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) == -1) {
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
            goto retry;
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    mail_create(&mail, buf, list_index);
    free3(buf);
    object_scene_mail[0] = mail;
}

void object_load_midi(IffContext *iff, s32 size) {
    BgmSep *bgm;
    u8 cd_mode;
    s32 n;
    u32 *dst;
    u8 *p;

    bgm = NULL;
    sound_bgm_create(&bgm, size);
    *(IffChunkBody *)bgm->data = *(IffChunkBody *)((u8 *)iff->chunk + 8);
    if (size > 0x7F8) {
        n = size - 0x7F8;
        dst = (u32 *)((u8 *)bgm->data + 0x7F8);
        while (1) {
            cd_mode = CdMode();
            if (!(cd_mode & 0x80)) {
                cd_mode = 0x80;
                while (CdControl(0xE, &cd_mode, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    sound_bgm_open(bgm);
}

void object_load_mod(IffContext *iff, s32 size) {
    Model *model;
    u8 cd_mode;
    s32 n;
    u32 *dst;
    u8 *p;

    model = NULL;
    mod_alloc(&model, size);
    *(IffChunkBody *)model->data = *(IffChunkBody *)((u8 *)iff->chunk + 8);
    if (size > 0x7F8) {
        n = size - 0x7F8;
        dst = (u32 *)((u8 *)model->data + 0x7F8);
        while (1) {
            cd_mode = CdMode();
            if (!(cd_mode & 0x80)) {
                cd_mode = 0x80;
                while (CdControl(0xE, &cd_mode, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    mod_list_add((s32)model);
}

void object_load_other(IffContext *iff, s32 tag, s32 size) {
    u8 cd_mode;
    void *buf;
    s32 n;
    u8 *p;
    u32 *dst;
    SceneTables *tables;

    tables = &object_scene_tables;
    buf = kaj_malloc(size);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_OTHER Buffer", object_str_file, 0xFD);
    }
    *(IffChunkBody *)buf = *(IffChunkBody *)((u8 *)iff->chunk + 8);
    if (size > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = size - 0x7F8;
    retry:
        cd_mode = CdMode();
        if (!(cd_mode & 0x80)) {
            cd_mode = 0x80;
            while (CdControl(0xE, &cd_mode, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(n >> 11, dst, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) == -1) {
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
            goto retry;
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    switch (tag) {
    case 0x41455241:
        tables->triggers = buf;
        break;
    case 0x52544341:
        tables->npcs = buf;
        action_init_npcs();
        break;
    case 0x2043504E:
        tables->npc_records = buf;
        break;
    case 0x52414843:
        tables->npc_bodies = buf;
        break;
    case 0x594D4E45:
        tables->npc_stats = buf;
        break;
    case 0x4D455449:
        tables->items = buf;
        break;
    case 0x20545854:
        tables->texts[tables->text_count] = buf;
        tables->text_count++;
        break;
    case 0x4E504557:
        tables->weapons = buf;
        break;
    }
}

void object_load_sprt(IffContext *iff, s32 size) {
    Sprite *sprite;
    u8 cd_mode;
    SpriteRecord *rec;
    s32 n;
    u32 *dst;
    u8 *p;

    sprite = NULL;
    rec = kaj_malloc(size);
    if (rec == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_SPRT Buffer", object_str_file, 0x12B);
    }
    *(IffChunkBody *)rec = *(IffChunkBody *)((u8 *)iff->chunk + 8);
    if (size > 0x7F8) {
        dst = (u32 *)((u8 *)rec + 0x7F8);
        n = size - 0x7F8;
    retry:
            cd_mode = CdMode();
            if (!(cd_mode & 0x80)) {
                cd_mode = 0x80;
                while (CdControl(0xE, &cd_mode, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) == -1) {
                p = CdLastPos();
                while (CdControl(2, p, NULL) == 0) {
                }
                goto retry;
            }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    sprite_create(&sprite, rec);
    sprite_add((s32)sprite);
    free3(rec);
}

void object_load_text(IffContext *iff, s32 size) {
    u8 cd_mode;
    void *buf;
    s32 n;
    u32 *dst;
    u8 *p;

    buf = kaj_malloc(size);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_TEXT Buffer", object_str_file, 0x140);
    }
    *(IffChunkBody *)buf = *(IffChunkBody *)((u8 *)iff->chunk + 8);
    if (size > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = size - 0x7F8;
    retry:
            cd_mode = CdMode();
            if (!(cd_mode & 0x80)) {
                cd_mode = 0x80;
                while (CdControl(0xE, &cd_mode, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) == -1) {
                p = CdLastPos();
                while (CdControl(2, p, NULL) == 0) {
                }
                goto retry;
            }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    kaj_tim_upload_hdr(buf);
    free3(buf);
}

void object_load_thng(IffContext *iff, s32 size) {
    Thing *thing;
    u8 cd_mode;
    s32 n;
    u32 *dst;
    u8 *p;

    thing = NULL;
    thing_create(&thing, size);
    *(IffChunkBody *)thing->record = *(IffChunkBody *)((u8 *)iff->chunk + 8);
    if (size > 0x7F8) {
        dst = (u32 *)((u8 *)thing->record + 0x7F8);
        n = size - 0x7F8;
        while (1) {
            cd_mode = CdMode();
            if (!(cd_mode & 0x80)) {
                cd_mode = 0x80;
                while (CdControl(0xE, &cd_mode, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    sprite_thing_init(thing);
    thing_list_add((s32)thing);
}

void object_load_tim(IffContext *iff, s32 size) {
    u8 cd_mode;
    void *buf;
    s32 n;
    u32 *dst;
    u8 *p;

    buf = kaj_malloc(size);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_TIM Buffer", object_str_file, 0x165);
    }
    *(IffSectorBody *)buf = *(IffSectorBody *)((u8 *)iff->chunk + 0xC);
    if (size > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F4);
        n = size - 0x7F8;
    retry:
        cd_mode = CdMode();
        if (!(cd_mode & 0x80)) {
            cd_mode = 0x80;
            while (CdControl(0xE, &cd_mode, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(n >> 11, dst, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) == -1) {
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
            goto retry;
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    kaj_tim_upload(buf, 0);
    free3(buf);
}

void object_load_vabh(IffContext *iff, s32 size) {
    u8 cd_mode;
    s32 n;
    u32 *buf;
    u8 *p;

    buf = sound_se_alloc_header((u8 *)iff->chunk + 8, size, &sound_vab_stream);
    n = size - 0x7F8;
    while (1) {
        cd_mode = CdMode();
        if (!(cd_mode & 0x80)) {
            cd_mode = 0x80;
            while (CdControl(0xE, &cd_mode, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(n >> 11, buf, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) != -1) {
            break;
        }
        p = CdLastPos();
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    p = CdLastPos();
    p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
    while (CdControl(2, p, NULL) == 0) {
    }
    iff->pos += n;
    sound_vab_open_head(&sound_vab_stream);
}

void object_load_vabb(IffContext *iff, s32 size) {
    u8 cd_mode;
    u8 cd_mode2;
    u8 *buf;
    s32 n;
    u8 *buf2;
    u8 *p;

    sound_vab_stream.body_buf = (u8 *)iff->chunk + 8;
    sound_vab_stream.body_len = 0x7F8;
    sound_vab_transfer(&sound_vab_stream);
    size -= sound_vab_stream.body_len;
    sound_vab_stream.body_len = 0x2000;
    sound_vab_stream.body_buf = kaj_malloc(0x2000);
    if (sound_vab_stream.body_buf == NULL) {
        kaj_abend(3, "Error Allocating vab_trans_buffer", object_str_file, 0x191);
    }
    while (sound_vab_stream.body_len < size) {
        buf = sound_vab_stream.body_buf;
        n = sound_vab_stream.body_len;
    retry:
        cd_mode = CdMode();
        if (!(cd_mode & 0x80)) {
            cd_mode = 0x80;
            while (CdControl(0xE, &cd_mode, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(n >> 11, (u32 *)buf, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) == -1) {
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
            goto retry;
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += sound_vab_stream.body_len;
        sound_vab_transfer(&sound_vab_stream);
        size -= sound_vab_stream.body_len;
    }
    buf2 = sound_vab_stream_body_buf[0];
retry2:
    cd_mode2 = CdMode();
    if (!(cd_mode2 & 0x80)) {
        cd_mode2 = 0x80;
        while (CdControl(0xE, &cd_mode2, NULL) == 0) {
        }
        VSync(3);
    }
    while (CdRead(size >> 11, (u32 *)buf2, 0x80) == 0) {
    }
    if (CdReadSync(0, NULL) == -1) {
        p = CdLastPos();
        while (CdControl(2, p, NULL) == 0) {
        }
        goto retry2;
    }
    p = CdLastPos();
    p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
    while (CdControl(2, p, NULL) == 0) {
    }
    iff->pos += size;
    sound_vab_stream.body_len = size;
    sound_vab_transfer(&sound_vab_stream);
    sound_se_push((SeVabStream *)&sound_vab_stream);
    free3(sound_vab_stream.body_buf);
}

void object_load_vecl(IffContext *iff, s32 size) {
    Vehicle *vehicle;
    u8 cd_mode;
    s32 n;
    u32 *dst;
    u8 *p;

    vehicle = NULL;
    vehicle_create(&vehicle, size);
    *(IffChunkBody *)vehicle->data = *(IffChunkBody *)((u8 *)iff->chunk + 8);
    if (size > 0x7F8) {
        dst = (u32 *)((u8 *)vehicle->data + 0x7F8);
        n = size - 0x7F8;
        while (1) {
            cd_mode = CdMode();
            if (!(cd_mode & 0x80)) {
                cd_mode = 0x80;
                while (CdControl(0xE, &cd_mode, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(n >> 11, dst, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += size - 0x7F8;
    }
    vehicle_init((Vehicle *)vehicle);
}

void object_read_chunks(IffContext *iff, s32 request, s32 progress, s32 filter_id) {
    Inventory *inv;
    u32 *buf;
    s32 size;
    s16 id;
    s16 id2;
    s32 tag;
    s16 found;
    s32 i;
    u8 *p;
    u8 cd_mode;

    if (progress == 1) {
        sound_se_play(0x31);
        object_load_chunk_count = 0;
    } else if (progress == 2) {
        if ((((SceneRequestLoadView *)request)->loop == 0 && ((SceneRequestLoadView *)request)->office_no_gauge != 0) ||
            (((SceneRequestLoadView *)request)->loop == 1 && ((SceneRequestLoadView *)request)->building_gauge == 0) ||
            (((SceneRequestLoadView *)request)->loop == 2 && ((SceneRequestLoadView *)request)->loop_param == 0)) {
            sprite_set_visible(0x410, 0);
            progress = -1;
        }
    }
    while (iff->pos < iff->size) {
        buf = iff->chunk;
        for (;;) {
            cd_mode = CdMode();
            if (!(cd_mode & 0x80)) {
                cd_mode = 0x80;
                while (CdControl(0xE, &cd_mode, NULL) == 0) {
                }
                VSync(3);
            }
            while (CdRead(1, buf, 0x80) == 0) {
            }
            if (CdReadSync(0, NULL) != -1) {
                break;
            }
            p = CdLastPos();
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        p = CdLastPos();
        p = CdIntToPos(CdPosToInt(p) + 1, p);
        while (CdControl(2, p, NULL) == 0) {
        }
        iff->pos += 0x800;
        size = ((IffChunk *)iff->chunk)->size;
        tag = ((IffChunk *)iff->chunk)->tag;
        switch (tag) {
        case 0x54455341:
            object_load_aset(iff, size);
            break;
        case 0x4B434C42:
            if (request == 0) {
                object_load_blck(iff, 3, size);
            } else if (((SceneRequestLoadView *)request)->loop == 0 && ((SceneRequestLoadView *)request)->loop_param == 0) {
                size -= 0x7F8;
                p = CdLastPos();
                p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
                while (CdControl(2, p, NULL) == 0) {
                }
                iff->pos += size;
            } else {
                object_load_blck(iff, ((SceneRequestLoadView *)request)->loop, size);
            }
            break;
        case 0x524F4F44:
            object_load_door(iff, size);
            break;
        case 0x4C49414D:
            id2 = ((IffChunk *)iff->chunk)->id;
            if (id2 == mail_list_get_id(filter_id)) {
                object_load_mail(iff, size, filter_id);
                return;
            }
            size -= 0x7F8;
            p = CdLastPos();
            p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
            while (CdControl(2, p, NULL) == 0) {
            }
            iff->pos += size;
            break;
        case 0x4944494D:
            object_load_midi(iff, size);
            break;
        case 0x20444F4D:
        case 0x20454F4D:
            if (filter_id == 0x400) {
                found = 0;
                inv = player_status_inventory[0];
                for (i = 0; i < 2; i++) {
                    if (((IffChunk *)iff->chunk)->id == inv->weapon_ids[i] + 0x400) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    inv->weapon_count++;
                    object_load_mod(iff, size);
                } else {
                    size -= 0x7F8;
                    p = CdLastPos();
                    p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
                    while (CdControl(2, p, NULL) == 0) {
                    }
                    iff->pos += size;
                }
            } else {
                object_load_mod(iff, size);
            }
            break;
        case 0x54525053:
            id = ((IffChunk *)iff->chunk)->id;
            object_load_sprt(iff, size);
            if (id == 0x40F) {
                sprite_set_visible(0x40F, 1);
                object_load_chunk_count = 0;
                object_load_bar_step = 1;
            }
            break;
        case 0x204D4954:
            if (((IffChunk *)iff->chunk)->id == filter_id) {
                object_load_tim(iff, size);
            } else {
                size -= 0x7F8;
                p = CdLastPos();
                p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
                while (CdControl(2, p, NULL) == 0) {
                }
                iff->pos += size;
            }
            break;
        case 0x54584554:
            object_load_text(iff, size);
            break;
        case 0x474E4854:
            object_load_thng(iff, size);
            break;
        case 0x42424156:
            if (request != 0 && ((SceneRequestLoadView *)request)->loop == 0 && ((SceneRequestLoadView *)request)->arrival_sound == 0) {
                size -= 0x7F8;
                p = CdLastPos();
                p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
                while (CdControl(2, p, NULL) == 0) {
                }
                iff->pos += size;
            } else {
                object_load_vabb(iff, size);
            }
            break;
        case 0x48424156:
            if (request != 0 && ((SceneRequestLoadView *)request)->loop == 0 && ((SceneRequestLoadView *)request)->arrival_sound == 0) {
                size -= 0x7F8;
                p = CdLastPos();
                p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
                while (CdControl(2, p, NULL) == 0) {
                }
                iff->pos += size;
            } else {
                object_load_vabh(iff, size);
            }
            break;
        case 0x4C434556:
            object_load_vecl(iff, size);
            break;
        case 0x20545854:
        case 0x41455241:
        case 0x4D455449:
        case 0x4E504557:
        case 0x52544341:
        case 0x2043504E:
        case 0x52414843:
        case 0x594D4E45:
            object_load_other(iff, tag, size);
            break;
        default:
            size -= 0x7F8;
            p = CdLastPos();
            p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
            while (CdControl(2, p, NULL) == 0) {
            }
            iff->pos += size;
            break;
        }
        switch (progress) {
        case -1:
            break;
        case 0:
            if (object_load_chunk_count != 0 && object_load_chunk_count % 6 == 0) {
                object_load_bar_step++;
                if (object_load_bar_step < 11) {
                    sprite_set_clut_entry(0x40F, object_load_bar_step, 0x5318);
                    sprite_set_clut_entry(0x40F, object_load_bar_step - 1, 0);
                }
            }
            object_load_chunk_count++;
            roadmap_draw_sprite_frame(0x40F);
            break;
        case 1:
            if (object_load_chunk_count < 16) {
                sprite_set_clut_entry(0x207, object_load_chunk_count++ + 0xF0, 0x1F);
            }
            roadmap_draw_sprite_frame(0x207);
            break;
        case 2:
            effect_clut_rotate();
            roadmap_draw_sprite_frame(0x410);
            break;
        }
    }
}

void object_iff_open(IffContext **out, s32 res_file, s32 index) {
    struct {
        CdLoc pos;
        u32 size;
        char name[16];
    } file;
    u8 cd_mode;
    s16 res;
    u8 *p;
    u8 *q;
    void *found;
    u32 *dst;

    res = res_file;
    object_iff_past_header = 1;
    *out = kaj_malloc(0x10);
    if (*out == NULL) {
        kaj_abend(3, "Error Allocation IFF Context", object_str_file, 0x2AA);
    }
    (*out)->size = 0;
    (*out)->pos = 0;
    (*out)->header = kaj_malloc(0x800);
    if ((*out)->header == NULL) {
        kaj_abend(3, "Error Allocating IFF Header", object_str_file, 0x2B1);
    }
    (*out)->chunk = kaj_malloc(0x800);
    if ((*out)->chunk == NULL) {
        kaj_abend(3, "Error Allocating IFF Chunk Header", object_str_file, 0x2B5);
    }
retry0:
    if (res) {
        found = CdSearchFile(&file, "\\RES.R;1");
    } else {
        found = CdSearchFile(&file, "\\SCE.S;1");
    }
    if ((u32)((s32)found + 1) < 2) {
        goto retry0;
    }
    *(CdLoc *)object_iff_file_pos = file.pos;
    while (CdControl(2, (u8 *)&file, NULL) == 0) {
    }
    if (index > 0) {
        if (res) {
            s32 n = object_res_offsets[index];

            p = object_iff_file_pos;
            p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
            while (CdControl(2, p, NULL) == 0) {
            }
        } else {
            s32 n = object_sce_offsets[index];

            p = object_iff_file_pos;
            p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        *(CdLoc *)object_iff_file_pos = *(CdLoc *)CdLastPos();
    }
    dst = (u32 *)(*out)->header;
    while (1) {
        cd_mode = CdMode();
        if (!(cd_mode & 0x80)) {
            cd_mode = 0x80;
            while (CdControl(0xE, &cd_mode, NULL) == 0) {
            }
            VSync(3);
        }
        while (CdRead(1, dst, 0x80) == 0) {
        }
        if (CdReadSync(0, NULL) != -1) {
            break;
        }
        q = CdLastPos();
        while (CdControl(2, q, NULL) == 0) {
        }
    }
    q = CdLastPos();
    q = CdIntToPos(CdPosToInt(q) + 1, q);
    while (CdControl(2, q, NULL) == 0) {
    }
}

void object_load_scene(void) {
    IffContext *iff;
    IffContext *q;
    IffContext *q2;
    IffContext *q3;
    IffEntry *entry;
    SceneTables *tables;
    SceneRequest *request;
    s32 pos;
    s32 a, b, c, d;
    u16 idx;
    u8 *p;
    u8 *loc;
    IffEntry *entry2;
    s32 pos2;
    u8 *p2;
    u8 *loc2;

    request = &scene_request;
    object_iff_open(&iff, 0, request->scene_index);
    q = iff;
    q->pos = 0;
    entry = q->header;
    pos = entry->offset;
    q->size = entry->size;
    tables = &object_scene_tables;
    a = entry->count0;
    b = entry->count1;
    c = entry->count2;
    d = entry->count3;
    if (a != 0) {
        tables->npc_body_count = a;
    }
    if (b != 0) {
        tables->npc_record_count = b;
    }
    if (c != 0) {
        tables->weapon_count = c;
    }
    if (d != 0) {
        tables->item_count = d;
    }
    if (q->size == 0) {
        object_iff_past_header = 0;
    } else {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    if (iff->size > 0) {
        object_read_chunks(iff, (s32)request, 2, 0);
    }
    q2 = iff;
    idx = request->variant;
    q2->pos = 0;
    entry2 = q2->header + idx + 1;
    pos2 = q2->header[idx + 1].offset;
    q2->size = entry2->size;
    object_scene_tables.npc_count = entry2->count0;
    object_scene_tables.trigger_count = entry2->count1;
    object_aset_count = entry2->count2;
    object_scene_tables.npc_stats_count = entry2->count3;
    if (object_iff_past_header != 0) {
        loc2 = object_iff_file_pos;
        p2 = CdIntToPos(CdPosToInt(loc2) + ((pos2 - 0x800) >> 11), loc2);
        while (CdControl(2, p2, NULL) == 0) {
        }
    } else {
        loc2 = object_iff_file_pos;
        p2 = CdIntToPos(CdPosToInt(loc2) + (pos2 >> 11), loc2);
        while (CdControl(2, p2, NULL) == 0) {
        }
    }
    if (iff->size > 0) {
        object_read_chunks(iff, (s32)request, 2, 0);
    }
    q3 = iff;
    free3(q3->header);
    free3(q3->chunk);
    free3(q3);
}

void object_load_weapon_mods(void) {
    IffContext *iff;
    IffContext *q;
    IffContext *r;
    IffEntry *entry;
    SceneTables *tables;
    s32 pos;
    s32 a, b, c, d;
    u8 *p;
    u8 *loc;

    object_iff_open(&iff, 1, 2);
    q = iff;
    q->pos = 0;
    entry = q->header;
    pos = entry->offset;
    q->size = entry->size;
    tables = &object_scene_tables;
    a = entry->count0;
    b = entry->count1;
    c = entry->count2;
    d = entry->count3;
    if (a != 0) {
        tables->npc_body_count = a;
    }
    if (b != 0) {
        tables->npc_record_count = b;
    }
    if (c != 0) {
        tables->weapon_count = c;
    }
    if (d != 0) {
        tables->item_count = d;
    }
    if (q->size == 0) {
        object_iff_past_header = 0;
    } else {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    if (iff->size > 0) {
        object_read_chunks(iff, 0, 2, 0x400);
    }
    r = iff;
    free3(r->header);
    free3(r->chunk);
    free3(r);
}

void object_load_mail_by_id(s16 list_index) {
    IffContext *iff;
    IffContext *q;
    IffContext *r;
    IffEntry *entry;
    SceneTables *tables;
    s32 pos;
    s32 a, b, c, d;
    u8 *p;
    u8 *loc;

    object_iff_open(&iff, 1, 7);
    q = iff;
    q->pos = 0;
    entry = q->header;
    pos = entry->offset;
    q->size = entry->size;
    tables = &object_scene_tables;
    a = entry->count0;
    b = entry->count1;
    c = entry->count2;
    d = entry->count3;
    if (a != 0) {
        tables->npc_body_count = a;
    }
    if (b != 0) {
        tables->npc_record_count = b;
    }
    if (c != 0) {
        tables->weapon_count = c;
    }
    if (d != 0) {
        tables->item_count = d;
    }
    if (q->size == 0) {
        object_iff_past_header = 0;
    } else {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    if (iff->size > 0) {
        object_read_chunks(iff, 0, -1, list_index);
    }
    r = iff;
    free3(r->header);
    free3(r->chunk);
    free3(r);
}

void object_load_res(s32 index, s32 progress) {
    IffContext *iff;
    IffContext *q;
    IffContext *r;
    IffEntry *entry;
    SceneTables *tables;
    s32 pos;
    s32 a, b, c, d;
    u8 *p;
    u8 *loc;

    object_iff_open(&iff, 1, index);
    q = iff;
    q->pos = 0;
    entry = q->header;
    pos = entry->offset;
    q->size = entry->size;
    tables = &object_scene_tables;
    a = entry->count0;
    b = entry->count1;
    c = entry->count2;
    d = entry->count3;
    if (a != 0) {
        tables->npc_body_count = a;
    }
    if (b != 0) {
        tables->npc_record_count = b;
    }
    if (c != 0) {
        tables->weapon_count = c;
    }
    if (d != 0) {
        tables->item_count = d;
    }
    if (q->size == 0) {
        object_iff_past_header = 0;
    } else {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    if (iff->size > 0) {
        object_read_chunks(iff, 0, progress, 0);
    }
    r = iff;
    free3(r->header);
    free3(r->chunk);
    free3(r);
}

void object_load_res12_by_id(s16 id) {
    IffContext *iff;
    IffContext *q;
    IffContext *r;
    IffEntry *entry;
    SceneTables *tables;
    s32 pos;
    s32 a, b, c, d;
    u8 *p;
    u8 *loc;

    object_iff_open(&iff, 1, 0xC);
    q = iff;
    q->pos = 0;
    entry = q->header;
    pos = entry->offset;
    q->size = entry->size;
    tables = &object_scene_tables;
    a = entry->count0;
    b = entry->count1;
    c = entry->count2;
    d = entry->count3;
    if (a != 0) {
        tables->npc_body_count = a;
    }
    if (b != 0) {
        tables->npc_record_count = b;
    }
    if (c != 0) {
        tables->weapon_count = c;
    }
    if (d != 0) {
        tables->item_count = d;
    }
    if (q->size == 0) {
        object_iff_past_header = 0;
    } else {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    if (iff->size > 0) {
        object_read_chunks(iff, 0, 2, id);
    }
    r = iff;
    free3(r->header);
    free3(r->chunk);
    free3(r);
}

void object_iff_seek_entry(IffContext *iff, u16 index) {
    IffEntry *entry;
    s32 pos;
    u8 *p;
    u8 *loc;

    iff->pos = 0;
    entry = iff->header + index + 1;
    pos = iff->header[index + 1].offset;
    iff->size = entry->size;
    object_scene_tables.npc_count = entry->count0;
    object_scene_tables.trigger_count = entry->count1;
    object_aset_count = entry->count2;
    object_scene_tables.npc_stats_count = entry->count3;
    if (object_iff_past_header != 0) {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + ((pos - 0x800) >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    } else {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
}

void object_iff_close(IffContext *iff) {
    free3(iff->header);
    free3(iff->chunk);
    free3(iff);
}

s32 object_room_on_enter(KajEvent *ev) {
    RoomPhone *phone = &object_room_phone;

    switch (ev->param1) {
    case 0xFA0000:
        /* desk prompt: leave the desk */
        text_show(" 8\212\3671\202\251\202\347\227\243\202\352\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFA0001:
        /* desk prompt: start the computer */
        text_show(" 8\203R\203\223\203s\203\205\201[\203^1\202\360\213N\223\256\202\267\202\351  3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFA0002:
        /* desk prompt: write the diary */
        text_show(" 8\223\372\213L1\202\360\202\302\202\257\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFA0003:
        if (phone->state == 1) {
            /* phone prompt: answer */
            text_show(" 8\223d\230b1\202\360\202\306\202\351        3\201\233", 1, -1, 8, -1, 0, 1);
        } else if (phone->state == 2) {
            /* phone prompt: make a call */
            text_show(" 8\223d\230b1\202\360\202\251\202\257\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

s32 object_room_on_effect_done(KajEvent *ev) {
    GameVars_u8018FA18 *game;
    Player *player;
    u16 mode;
    s32 kind;
    RoomStorage *storage;

    game = &action_vars;
    storage = &object_room_storage;
    player = player_status_player[0];
    kind = ev->param2;
    mode = scene_request_arrival[0];
    if (kind == 4) {
        if (object_room_exit_pending != 0) {
            object_room_exit_pending = 0;
            return 1;
        }
        if (player->flags & 0x10) {
            /* drowsiness narration */
            text_show(" \202\310\202\361\202\276\202\251\201A\202\244\202\306\202\244\202\306\202\265\202\304\202\253\202\275", 1, -1, 0, -1, 0, 0);
            kaj_view_set_bg_color(0, 0, 0);
            effect_start_fade(10, 3);
        }
    } else if (kind == 10) {
        if (ev->param1 == 0) {
            game->fade_tss = -1;
        }
        player_rest(0, 0xDAC, 0, 0xC80);
        text_close();
        mail_wait(0, 0, 0, 4);
        effect_start_fade(9, 3);
    } else if (kind == 9) {
        if (ev->param1 == 0) {
            game->fade_tss = -1;
        }
        player->flags &= ~0x10;
        kaj_view_set_bg_color(0x30, 0x30, 0x10);
    } else if (kind == 0) {
        kaj_view_set_bg_color(0x30, 0x30, 0x10);
        if ((s16)mode != 1) {
            sound_bgm_play(0);
        }
    } else if (kind == 11) {
        if (!(player->flags & 0x4000)) {
            if (storage->choice != 0) {
                /* storage prompt: choose a weapon to leave */
                text_show(" 1\227a\202\257\202\3518\225\220\212\3551\202\360\225\373\214\374\203L\201[\217\343\211\272\202\305, \221I\202\361\202\305\211\272\202\263\202\242,      \214\210\222\350 3\201\233 1\226\337\202\351 4\201~", 3, -1, 0, -1, 0, 1);
            } else {
                /* storage prompt: choose a weapon to take */
                text_show(" 1\216\363\202\257\216\346\202\3518\225\220\212\3551\202\360\225\373\214\374\203L\201[\217\343\211\272\202\305, \221I\202\361\202\305\211\272\202\263\202\242,      \214\210\222\350 3\201\233 1\226\337\202\351 4\201~", 3, -1, 0, -1, 0, 1);
            }
        }
    } else if (kind == 12) {
        if (ev->param0 != 999999) {
            object_room_storage_open(1, 0);
        }
    } else if (kind == 13) {
        if ((s16)mode == 1) {
            sound_bgm_play(0);
        }
    } else if (kind == 8) {
        mail_wait(0, 0, 0, 2);
        if (player->view_dirty == 0) {
            player->view_dirty = 1;
        }
    }
    return 0;
}

void object_room_check_calls(void) {
    Player *player;
    Model *model;
    u16 flags;
    s16 hours;
    RoomPhone *phone;
    GameVars_u8018FA18 *game;
    PlayerStatus *status;
    EventState *ev_state;

    status = &player_status;
    ev_state = &event_state;
    phone = &object_room_phone;
    game = &action_vars;

    player = status->player;
    model = status->model;
    flags = game->phone_calls_done;
    if (phone->ringing != 0) {
        if ((player->flags & 0x40) && phone->state == 4 && ev_state->state == 0 && model->playing == 0 && model->anim == 1) {
            mod_set_anim(model, 2, 0);
        }
        return;
    }
    if (game->vars[0x30] != 0 || flags == 0xFFFF) {
        return;
    }
    hours = game->hour + game->day * 24;
    if (!(flags & 1) && (s16)mail_is_read(1) != 0 && game->vars[0xD] == 100 && game->vars[0xB] != 0) {
        phone->ringing = 1;
        phone->state = 2;
        phone->message = 0x65;
        return;
    } else if (!(flags & 2) && game->vars[0xD] == 90) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x66;
    } else if (!(flags & 4) && game->vars[0xD] == 80 && game->vars[0xF] > 10) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x67;
    } else if (!(flags & 8) && (s16)mail_is_read(0x13) != 0 && hours < 58) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x68;
    } else if (!(flags & 0x10) && game->var76 == 0 && game->day == 1 && game->hour >= 14 && game->hour < 20) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x69;
    } else if (!(flags & 0x20) && game->var76 >= 3 && hours < 51) {
        phone->ringing = 1;
        phone->state = 2;
        phone->message = 0x6A;
        return;
    } else if (!(flags & 0x40) && game->var76 >= 3 && game->vars[0x12] > 10 && game->vars[0x12] <= 100) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x6B;
    } else if (!(flags & 0x80) && game->var76 >= 3 && game->vars[0x17] > 10 && game->vars[0x17] <= 100) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x6C;
    } else if (!(flags & 0x100) && game->var76 < 3 && game->vars[0x17] > 10 && game->vars[0x17] <= 100) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x6D;
    } else if (!(flags & 0x200) && hours >= 82 && game->vars[0xE] > 10 && game->vars[0xE] <= 100) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x6E;
    } else if (!(flags & 0x400) && hours >= 36 && game->vars[0x1A] > 90 && game->vars[0x18] != 10) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x6F;
    } else if (!(flags & 0x800) && game->vars[0x1A] > 70 && game->vars[0x18] == 10) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x70;
    } else if (!(flags & 0x1000) && hours >= 58) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x71;
    } else if (!(flags & 0x2000) && status->humans_killed > 0 && status->arrests == 0) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x72;
    } else if (!(flags & 0x4000) && status->arrests == 1) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x73;
    } else if (!(flags & 0x8000) && status->mutant != 0) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x74;
    } else {
        return;
    }
    sound_se_play(0x33);
    effect_start_alarm(2, 0x402, 0x14);
    if (player->flags & 1) {
        player_reset_triggers(0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8018FA18", object_room_str_storage);

s16 object_room_storage_input(void) {
    RoomStorage *storage;
    s16 menu_state;
    s16 can_swap;
    s16 count;

    storage = &object_room_storage;
    if (object_room_storage.open == 0) {
        return 0;
    }
    menu_state = mail_menu_get_state();
    if (storage->stage == 0 && menu_state == 0) {
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            can_swap = effect_weapon_list(storage->choice, &count, object_room_storage_list);
            if (storage->choice != 0) {
                storage->stage = 1;
                if (can_swap != 0) {
                    goto ok;
                }
                {
                    RoomStorage *storage2;
                    char *line;

                    /* storage refusal: the last weapon stays carried */
                    line = " 8\225\220\212\3552\202\360\216\235\202\301\202\304\202\242\202\310\202\242\202\306\212\353\214\257\202\305\202\267";
                    storage2 = &object_room_storage;
                    sprite_set_visible(0, 0);
                    if (line != NULL) {
                        text_show(line, 1, -1, 0, -1, 0, 4);
                    } else {
                        storage2->open = 0;
                        storage2->stage = 0;
                        storage2->choice = 1;
                        text_close();
                    }
                    if (line == NULL) {
                        mail_wait(0, 0, 0, 1);
                        return 1;
                    }
                    mail_wait(0, 0, 0, 3);
                    storage2->open = 1;
                    storage2->stage = 0;
                    storage2->choice = 1;
                    sprite_set_visible(0, 1);
                    sprite_set_clut_entry(0, 4, object_room_choice_cursor_color);
                    sprite_set_clut_entry(0, 5, object_room_choice_color);
                    text_show(object_room_str_storage, 3, -1, 0, -1, 0, 1);
                }
            } else {
                storage->stage = 2;
                if (can_swap != 0) {
                    goto ok;
                }
                if (count == 0) {
                    {
                        RoomStorage *storage2;
                        char *line;

                        /* storage refusal: no weapon stored */
                        line = " 2\227a\202\251\202\301\202\304\202\242\202\3518\225\220\212\3552\202\315\202\240\202\350\202\334\202\271\202\361";
                        storage2 = &object_room_storage;
                        sprite_set_visible(0, 0);
                        if (line != NULL) {
                            text_show(line, 1, -1, 0, -1, 0, 4);
                        } else {
                            storage2->open = 0;
                            storage2->stage = 0;
                            storage2->choice = 1;
                            text_close();
                        }
                        if (line == NULL) {
                            mail_wait(0, 0, 0, 1);
                            return 1;
                        }
                        mail_wait(0, 0, 0, 3);
                        storage2->open = 1;
                        storage2->stage = 0;
                        storage2->choice = 1;
                        sprite_set_visible(0, 1);
                        sprite_set_clut_entry(0, 4, object_room_choice_cursor_color);
                        sprite_set_clut_entry(0, 5, object_room_choice_color);
                        text_show(object_room_str_storage, 3, -1, 0, -1, 0, 1);
                    }
                } else {
                    {
                        RoomStorage *storage2;
                        char *line;

                        /* storage refusal: no room to carry more */
                        line = " 2\202\340\202\244\201A\216\235\202\304\202\310\202\242\202\346\202\244\202\305\202\267\202\346";
                        storage2 = &object_room_storage;
                        sprite_set_visible(0, 0);
                        if (line != NULL) {
                            text_show(line, 1, -1, 0, -1, 0, 4);
                        } else {
                            storage2->open = 0;
                            storage2->stage = 0;
                            storage2->choice = 1;
                            text_close();
                        }
                        if (line == NULL) {
                            mail_wait(0, 0, 0, 1);
                            return 1;
                        }
                        mail_wait(0, 0, 0, 3);
                        storage2->open = 1;
                        storage2->stage = 0;
                        storage2->choice = 1;
                        sprite_set_visible(0, 1);
                        sprite_set_clut_entry(0, 4, object_room_choice_cursor_color);
                        sprite_set_clut_entry(0, 5, object_room_choice_color);
                        text_show(object_room_str_storage, 3, -1, 0, -1, 0, 1);
                    }
                }
            }
            return 1;
        ok:
            sound_se_play(0x11);
            storage->cursor = 0;
            sprite_set_visible(0, 0);
            mail_menu_open(1, 0x40B, 0x402, count, 6, object_room_storage_list, 4, 0x2969, 0x2BFF);
            return 1;
        }
        if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            RoomStorage *storage2;

            sound_se_play(8);
            storage2 = &object_room_storage;
            sprite_set_visible(0, 0);
            storage2->open = 0;
            storage2->stage = 0;
            storage2->choice = 1;
            text_close();
            mail_wait(0, 0, 0, 1);
            return 1;
        }
        if ((!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) ||
            (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000))) {
            sound_se_play(0xF);
            storage->choice = storage->choice == 0;
            sprite_set_clut_entry(0, 4, (&object_room_choice_color)[storage->choice]);
            sprite_set_clut_entry(0, 5, (&object_room_choice_color)[1 - storage->choice]);
        }
        return 1;
    }
    if (storage->stage == 1 || storage->stage == 2) {
        if (menu_state == 1) {
            if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
                sound_se_play(0x11);
                effect_weapon_swap_stock(storage->choice, object_room_storage_list[storage->cursor]);
                mail_menu_close();
                return 1;
            }
            if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
                sound_se_play(8);
                mail_menu_close();
                return 1;
            }
            if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
                storage->cursor = mail_menu_move(1);
            } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
                storage->cursor = mail_menu_move(0);
            }
        }
    }
    return 1;
}

void object_room_do_action(PlayerStatus *status) {
    SceneRequest *request;
    EventState *ev_state;
    RoomPhone *phone;
    GameVars_u8018FA18 *game;
    Player *player;
    ActionSet *set;
    RoomStorage *storage;
    s32 k;
    s16 mode;

    request = &scene_request;
    ev_state = &event_state;
    phone = &object_room_phone;
    game = &action_vars;
    mode = ev_state->state;
    player = status->player;

    if (mode == 3) {
        text_next_page(ev_state);
    } else if (mode == 2 && (ev_state->circle_flags & 8)) {
        text_close();
        sound_se_play(event_state.trigger == 0xFA0000 ? 0xE : 0x11);
        switch ((u32)event_state.trigger) {
        case 0xFA0000:
            player_start_move_to(2, 1, 0x76C, 0, 0x19C8, 0, 0xB4, 0, mode);
            break;
        case 0xFA0001:
            player_start_move_to(0, 0, 0xDF6, 0x244, 0x1888, 6, 0x8E, 0, mode);
            object_room_exit_action = 1;
            request->change = 1;
            break;
        case 0xFA0002:
            player_start_move_to(0, 0, 0xC12, 0x208, 0x18CE, -0x5A, 0xBF, 0, mode);
            object_room_exit_action = 2;
            object_room_exit_pending = 1;
            request->change = 1;
            break;
        case 0xFA0003:
            if (phone->state == 1 || phone->state == 2) {
                player->flags |= 0x40;
                game->phone_calls_done |= 1 << (phone->message - 0x65);
                mod_set_anim(status->model, 1, 0);
            }
            break;
        case 0xF0FF0A:
        case 0xF0FF14:
        case 0xF0FF1E:
            k = 1;
            storage = &object_room_storage;
            storage->open = k;
            storage->stage = 0;
            storage->choice = k;
            sprite_set_visible(0, k);
            sprite_set_clut_entry(0, 4, object_room_choice_cursor_color);
            sprite_set_clut_entry(0, 5, object_room_choice_color);
            text_show(object_room_str_storage, 3, -1, 0, -1, 0, k);
            break;
        case 0xF0FF46:
            if (status->naps_today >= 2) {
                /* sofa nap limit per day */
                text_show("\203\134\203\164\203\100\201\133\202\305\202\314\211\274\226\260\202\315\201\101\202\120\223\372\202\121\211\361\202\334\202\305", 1, -1, 0, -1, 0, 4);
                break;
            }
            status->naps_today++;
        default:
            set = action_find_set(ev_state->circle_set);
            while (set != NULL) {
                set = action_run_set(set, 0, 0);
            }
            break;
        }
        ev_state->state = 1;
        ev_state->circle_flags &= ~8;
    }
}

void object_room_update_input(void) {
    Player *player;
    s32 buttons;
    PlayerStatus *status = &player_status;

    player = status->player;
    if (kaj_system.pad_mode != 1) {
        return;
    }
    if ((player->flags & 2) || (player->flags & 0x10)) {
        return;
    }
    buttons = kaj_pad_read();
    if (object_room_storage_input() != 0) {
        return;
    }
    if (!(player->flags & 1) && effect_item_input(status, 0) != 0) {
        return;
    }
    if (player->flags & 4) {
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            object_room_do_action(status);
            return;
        }
        if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            EventState *ev_state = &event_state;
            if (!(status->player->flags & 0x40)) {
                s16 state = ev_state->state;
                if (state == 2 && (status->player->flags & 1)) {
                    text_close();
                    sound_se_play(0xE);
                    player_start_move_to(2, 1, 0x76C, 0, 0x19C8, 0, 0xB4, 0, state);
                    ev_state->state = 0;
                }
            }
            return;
        }
    }
    if (!(player->flags & 0x40)) {
        player_handle_pad(status, 0, buttons);
    }
}

void object_room_init(void) {
    PlayerStatus *status;
    Player *player;
    RoomPhone *phone;
    SceneRequest *request;
    Model *model;
    GameVars_u8018FA18 *game;
    s32 i;
    s32 k;

    status = &player_status;
    request = &scene_request;
    player = status->player;
    object_room_exit_pending = 0;
    sprite_set_visible(0x410, 1);
    player_place_for_scene(0);
    object_load_scene();
    action_reset(1);
    mod_npcrec_show(0, 1);
    thing_set_active(3, 2, 1);
    thing_set_animate(3, 2, 1);
    thing_set_flag10(3, 2, 1);
    effect_weapon_calc_rate(0);
    effect_weapon_calc_rate(1);
    model = mod_find(0x40);
    phone = &object_room_phone;
    status->model = model;
    if (model != NULL) {
        mod_setup(model, 0, 3, 0);
        status->model->coord_tx = 0xDAC - player->cell_x * 12500;
        status->model->coord_ty = 0;
        status->model->coord_tz = 0x1A2C - player->cell_z * 12500;
        status->model->coord_flg = 0;
    }
    player_pick_trigger_hook = (s32)object_room_pick_desk_action;
    event_alarm_hook = (s32)object_room_on_alarm;
    event_enter_hook = (s32)object_room_on_enter;
    event_effect_done_hook = (s32)object_room_on_effect_done;
    event_mod_finish_hook = (s32)object_room_on_mod_finish;
    phone->ringing = 0;
    phone->state = 0;
    phone->message = -1;
    object_room_heal_on_quit = 0;
    if (request->variant == 1) {
        object_room_heal_on_quit = 1;
    }
    k = ((s16 *)&request->pos_x)[1];
    if (k == 2) {
        game = &action_vars;
        player_status.energy = 0xC9;
        status->hours_awake = k;
        status->naps_today = 0;
        game->vars[0x30] = 1;
        for (i = 9; i < 0x1C; i++) {
            game->vars[i] = 1000;
        }
        for (i = 0; i < 5; i++) {
            status->limb_state[i] = 0;
            game->limb_damage[i] = 0;
        }
        if (game->hour >= 5) {
            game->day++;
            if (game->day >= 99) {
                game->day = 98;
            }
        }
        game->hour = 5;
        game->minute = 0;
        event_draw_gauge(status);
        event_draw_limb_status(status);
    }
    event_show_clock(0);
    sprite_set_visible(0x410, 0);
}

void object_room_quit(void) {
    SceneTables *tables = &object_scene_tables;
    PlayerStatus *status = &player_status;
    s32 i;

    effect_clear_alarms();
    sound_bgm_stop();
    sound_se_stop_all();
    player_pick_trigger_hook = 0;
    event_alarm_hook = 0;
    event_enter_hook = 0;
    event_effect_done_hook = 0;
    event_mod_finish_hook = 0;
    status->model = 0;
    text_close();
    action_reset(1);
    action_free_triggers();
    action_free_all_sets();
    npc_free_bodies();
    door_free_all();
    mod_free_all();
    sprite_delete(0);
    thing_free_all();
    for (i = 0; i < tables->text_count; i++) {
        if (tables->texts[i] != 0) {
            free3(tables->texts[i]);
            tables->texts[i] = 0;
        }
    }
    tables->text_count = 0;
    switch (object_room_exit_action) {
    case 0:
        block_free_all();
        sound_bgm_close();
        sound_se_pop_scene();
        sprite_delete(0x207);
        if (object_room_heal_on_quit != 0) {
            player_add_hp(0xFF, 0);
        }
        break;
    case 1:
        block_free_all();
        break;
    case 2:
        sprite_delete(0x207);
        break;
    }
}

void object_room_main(void) {
    s32 buf[6];
    u16 mode;
    s16 done;
    s16 m;

    mode = scene_request_arrival[0];
    done = 0;
    object_room_init();
    kaj_timer_enable();
    switch ((s16)mode) {
    case 0:
        effect_start_fade(0, 3);
        break;
    case 1:
        sound_bgm_play(1);
    case 2:
        effect_fade_set_black();
        text_start_narration((s32)object_scene_tables.texts[(s16)mode - 1]);
        break;
    }
    m = mode;
    while (done == 0) {
        switch (kaj_event_get(buf)) {
        case 2:
            event_handle_alarm(buf);
            continue;
        case 0x10:
            event_handle_enter(buf);
            continue;
        case 0x20:
            event_handle_leave(buf);
            continue;
        case 4:
            event_handle_tick(0);
            continue;
        case 0x200:
            event_handle_mod_finish(buf);
            continue;
        case 0:
            object_room_update_input();
            if ((s16)mail_take_scene_change() != 0 && object_room_exit_action != 2) {
                kaj_view_set_bg_color(0, 0, 0);
                effect_start_fade(1, 3);
            }
            break;
        case 0x100:
            done = event_handle_effect_done(buf);
            continue;
        default:
            kaj_event_done(buf);
            continue;
        }
        if (m != 0) {
            text_narration_cues(m - 1);
        }
        object_room_check_calls();
        effect_start_alarm(0, 0x400, rand() % 10 + 10);
        mail_step_frame(0, 0, 0);
    }
    kaj_timer_disable();
    object_room_quit();
}

void object_room_storage_open(s16 reopen, char *line) {
    RoomStorage *storage = &object_room_storage;

    if (reopen == 0) {
        sprite_set_visible(0, 0);
        if (line != NULL) {
            text_show(line, 1, -1, 0, -1, 0, 4);
        } else {
            storage->open = 0;
            storage->stage = 0;
            storage->choice = 1;
            text_close();
        }
        if (line == NULL) {
            mail_wait(0, 0, 0, 1);
            return;
        }
        mail_wait(0, 0, 0, 3);
    }
    storage->open = 1;
    storage->stage = 0;
    storage->choice = 1;
    sprite_set_visible(0, 1);
    sprite_set_clut_entry(0, 4, object_room_choice_cursor_color);
    sprite_set_clut_entry(0, 5, object_room_choice_color);
    text_show(object_room_str_storage, 3, -1, 0, -1, 0, 1);
}

void object_room_pick_desk_action(s32 *out) {
    Player *player = player_status_player[0];
    RoomPhone *phone = &object_room_phone;
    s16 yaw;

    if ((*(u32 *)&player->climbing & 0x1010000) == 0x10000) {
        *out = 0xFA0000;
        if (player->pitch >= -20 && player->pitch <= 10) {
            yaw = player->yaw;
            if (yaw >= 130 && yaw <= 170) {
                *out = 0xFA0001;
            } else if (yaw >= 180 && yaw < 220) {
                *out = 0xFA0002;
            } else if (yaw >= 220 && yaw <= 250) {
                if (phone->ringing != 0 && phone->state != 3) {
                    *out = 0xFA0003;
                }
            }
        }
    }
}

void object_room_on_alarm(KajEvent *ev) {
    Player *player = player_status_player[0];
    RoomPhone *phone = &object_room_phone;
    Model *model;

    if (ev->param1 == 0x400) {
        model = mod_find(0x440);
        if (model != NULL && model->anim == 0) {
            mod_set_anim(model, 1, 0);
        }
    } else if (ev->param1 == 0x401) {
        phone->state = 4;
        object_room_play_call(phone->message);
        sound_se_stop(0x33);
    } else if (ev->param1 == 0x402) {
        if (!(player->flags & 0x40) && phone->state != 4) {
            phone->state = 3;
            sound_se_stop(0x33);
            effect_start_alarm(3, 0x403, 10);
            if (player->flags & 1) {
                player_reset_triggers(0);
            }
        }
    } else if (ev->param1 == 0x403) {
        if (phone->state == 3) {
            phone->ringing = 0;
            phone->state = 0;
            phone->message = -1;
        }
    }
}

void object_room_on_mod_finish(KajEvent *ev) {
    PlayerStatus *status = &player_status;
    Player *player = status->player;
    Model *model = status->model;
    RoomPhone *phone = &object_room_phone;

    if (ev->param1 == 3 && ev->param0 == 0x40) {
        if (model->anim == 1) {
            if (phone->state == 2) {
                sound_se_play(0x33);
                effect_start_alarm(1, 0x401, 5);
            } else if (phone->state == 1) {
                phone->state = 4;
                object_room_play_call(phone->message);
                sound_se_stop(0x33);
            }
        } else if (model->anim == 2) {
            text_close();
            player->flags &= ~0x40;
            phone->ringing = 0;
            phone->state = 0;
            phone->message = -1;
            if (player->flags & 1) {
                player_reset_triggers(0);
            }
        }
    }
}

void object_room_run(void) {
    object_room_exit_action = 0;
    while (1) {
        object_room_main();
        switch (object_room_exit_action) {
        case 1:
            menu_run();
            object_room_exit_action = 0;
            break;
        case 2:
            sprite_set_visible(0x400, 0);
            sprite_set_visible(0x409, 0);
            menu_card_run(0, 1);
            mail_goto_ofc(0, 1, 0, 0);
            object_room_exit_action = 0;
            sprite_set_visible(0x400, 1);
            sprite_set_visible(0x409, 1);
            break;
        default:
            return;
        }
    }
}

void object_room_play_call(s16 set_id) {
    void *model = player_status_model[0];
    EventState *ev_state = &event_state;
    ActionSet *item;

    item = action_find_set(set_id);
    if (item != NULL) {
        ev_state->trigger = 0;
        ev_state->circle_set = -1;
        ev_state->cross_set = -1;
        ev_state->trigger_type = 0;
        ev_state->circle_flags = 0;
        ev_state->cross_flags = 0;
        ev_state->state = 1;
        while ((item = action_run_set(item, 0, 0)) != NULL) {
        }
    } else {
        mod_set_anim(model, 2, 0);
    }
}

s32 object_deliver_area_events(void) {
    Player *player = &player_character;
    KajEvent *ev;

    UnDeliverEvent(0xF3000000, 2);
    if (player_area_leave_pending != 0) {
        player_area_leave_pending = 0;
        ev = kaj_event_push(0x20);
        if (ev != NULL) {
            ev->param1 = object_area_previous.trigger;
            ev->param0 = object_area_previous.trigger_type;
            ev->param2 = object_area_previous.scene_trigger;
        }
    }
    ev = kaj_event_push(0x10);
    if (ev != NULL) {
        ev->param1 = object_area_current.trigger;
        ev->param0 = object_area_current.trigger_type;
        ev->param2 = object_area_current.scene_trigger;
    }
    object_area_previous.trigger_type = object_area_current.trigger_type;
    object_area_previous.trigger = object_area_current.trigger;
    object_area_previous.scene_trigger = object_area_current.scene_trigger;
    player->flags |= 4;
    return 0;
}
