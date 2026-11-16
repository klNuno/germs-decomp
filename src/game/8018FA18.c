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
/* Local view of GameVars: this unit reads 0x0-0x7A as an s16 array and 0x7A-0xB4 as scalars, the shared type has one u16 array. */
typedef struct {
    s16 unk0[0x3D];
    s16 unk7A;
    s16 unk7C;
    u16 unk7E;
    u8 unk80[0x18];
    s16 unk98;
    u8 unk9A[0x18];
    u16 unkB2;
    s16 limb_damage[5];
    u8 unkBE[0x186];
    s32 unk244;
} GameVars_u8018FA18;
extern GameVars_u8018FA18 action_vars;
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
        kaj_abend(3, "Error Allocating IFF_ID_ASET Buffer", D_80170B7C, 0x8D);
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

INCLUDE_RODATA("asm/nonmatchings/game/8018FA18", D_80170B7C);

void object_load_mail(IffContext *iff, s32 size, s32 list_index) {
    u8 cd_mode;
    s32 mail;
    void *buf;
    s32 n;
    u8 *p;
    u32 *dst;

    buf = kaj_malloc(size);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_MAIL Buffer", D_80170B7C, 0xC6);
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
    D_801E0324[0] = mail;
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
        kaj_abend(3, "Error Allocating IFF_ID_OTHER Buffer", D_80170B7C, 0xFD);
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
        tables->unk50 = buf;
        break;
    case 0x52414843:
        tables->npc_bodies = buf;
        break;
    case 0x594D4E45:
        tables->npc_stats = buf;
        break;
    case 0x4D455449:
        tables->unk48 = buf;
        break;
    case 0x20545854:
        tables->unk5C[tables->unk34] = buf;
        tables->unk34++;
        break;
    case 0x4E504557:
        tables->unk58 = buf;
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
        kaj_abend(3, "Error Allocating IFF_ID_SPRT Buffer", D_80170B7C, 0x12B);
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
        kaj_abend(3, "Error Allocating IFF_ID_TEXT Buffer", D_80170B7C, 0x140);
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
        kaj_abend(3, "Error Allocating IFF_ID_TIM Buffer", D_80170B7C, 0x165);
    }
    *(Unk_8019120C *)buf = *(Unk_8019120C *)((u8 *)iff->chunk + 0xC);
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
        kaj_abend(3, "Error Allocating vab_trans_buffer", D_80170B7C, 0x191);
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
    buf2 = D_801E05C8[0];
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
    sound_se_push((Unk_801A217C *)&sound_vab_stream);
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
    vehicle_init((Unk_801E032C *)vehicle);
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
        if ((((Unk_80191AB0 *)request)->unk0 == 0 && ((Unk_80191AB0 *)request)->unk12 != 0) ||
            (((Unk_80191AB0 *)request)->unk0 == 1 && ((Unk_80191AB0 *)request)->unk1C == 0) ||
            (((Unk_80191AB0 *)request)->unk0 == 2 && ((Unk_80191AB0 *)request)->unk10 == 0)) {
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
            } else if (((Unk_80191AB0 *)request)->unk0 == 0 && ((Unk_80191AB0 *)request)->unk10 == 0) {
                size -= 0x7F8;
                p = CdLastPos();
                p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
                while (CdControl(2, p, NULL) == 0) {
                }
                iff->pos += size;
            } else {
                object_load_blck(iff, ((Unk_80191AB0 *)request)->unk0, size);
            }
            break;
        case 0x524F4F44:
            object_load_door(iff, size);
            break;
        case 0x4C49414D:
            id2 = ((IffChunk *)iff->chunk)->unk8;
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
                    if (((IffChunk *)iff->chunk)->unk8 == inv->weapon_ids[i] + 0x400) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    inv->unk0++;
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
            id = ((IffChunk *)iff->chunk)->unk8;
            object_load_sprt(iff, size);
            if (id == 0x40F) {
                sprite_set_visible(0x40F, 1);
                object_load_chunk_count = 0;
                object_load_bar_step = 1;
            }
            break;
        case 0x204D4954:
            if (((IffChunk *)iff->chunk)->unk8 == filter_id) {
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
            if (request != 0 && ((Unk_80191AB0 *)request)->unk0 == 0 && ((Unk_80191AB0 *)request)->unk14 == 0) {
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
            if (request != 0 && ((Unk_80191AB0 *)request)->unk0 == 0 && ((Unk_80191AB0 *)request)->unk14 == 0) {
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
        CdLoc unk0;
        u32 unk4;
        char unk8[16];
    } file;
    u8 cd_mode;
    s16 res;
    u8 *p;
    u8 *q;
    void *found;
    u32 *dst;

    res = res_file;
    D_801DFF18 = 1;
    *out = kaj_malloc(0x10);
    if (*out == NULL) {
        kaj_abend(3, "Error Allocation IFF Context", D_80170B7C, 0x2AA);
    }
    (*out)->size = 0;
    (*out)->pos = 0;
    (*out)->header = kaj_malloc(0x800);
    if ((*out)->header == NULL) {
        kaj_abend(3, "Error Allocating IFF Header", D_80170B7C, 0x2B1);
    }
    (*out)->chunk = kaj_malloc(0x800);
    if ((*out)->chunk == NULL) {
        kaj_abend(3, "Error Allocating IFF Chunk Header", D_80170B7C, 0x2B5);
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
    *(CdLoc *)object_iff_file_pos = file.unk0;
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
    object_iff_open(&iff, 0, request->unk0[2]);
    q = iff;
    q->pos = 0;
    entry = q->header;
    pos = entry->offset;
    q->size = entry->size;
    tables = &object_scene_tables;
    a = entry->unk8;
    b = entry->unkC;
    c = entry->unk10;
    d = entry->unk14;
    if (a != 0) {
        tables->npc_body_count = a;
    }
    if (b != 0) {
        tables->unk20 = b;
    }
    if (c != 0) {
        tables->unk30 = c;
    }
    if (d != 0) {
        tables->unk2C = d;
    }
    if (q->size == 0) {
        D_801DFF18 = 0;
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
    idx = request->unk0[3];
    q2->pos = 0;
    entry2 = q2->header + idx + 1;
    pos2 = q2->header[idx + 1].offset;
    q2->size = entry2->size;
    object_scene_tables.npc_count = entry2->unk8;
    object_scene_tables.trigger_count = entry2->unkC;
    object_aset_count = entry2->unk10;
    object_scene_tables.npc_stats_count = entry2->unk14;
    if (D_801DFF18 != 0) {
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
    a = entry->unk8;
    b = entry->unkC;
    c = entry->unk10;
    d = entry->unk14;
    if (a != 0) {
        tables->npc_body_count = a;
    }
    if (b != 0) {
        tables->unk20 = b;
    }
    if (c != 0) {
        tables->unk30 = c;
    }
    if (d != 0) {
        tables->unk2C = d;
    }
    if (q->size == 0) {
        D_801DFF18 = 0;
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
    a = entry->unk8;
    b = entry->unkC;
    c = entry->unk10;
    d = entry->unk14;
    if (a != 0) {
        tables->npc_body_count = a;
    }
    if (b != 0) {
        tables->unk20 = b;
    }
    if (c != 0) {
        tables->unk30 = c;
    }
    if (d != 0) {
        tables->unk2C = d;
    }
    if (q->size == 0) {
        D_801DFF18 = 0;
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
    a = entry->unk8;
    b = entry->unkC;
    c = entry->unk10;
    d = entry->unk14;
    if (a != 0) {
        tables->npc_body_count = a;
    }
    if (b != 0) {
        tables->unk20 = b;
    }
    if (c != 0) {
        tables->unk30 = c;
    }
    if (d != 0) {
        tables->unk2C = d;
    }
    if (q->size == 0) {
        D_801DFF18 = 0;
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
    a = entry->unk8;
    b = entry->unkC;
    c = entry->unk10;
    d = entry->unk14;
    if (a != 0) {
        tables->npc_body_count = a;
    }
    if (b != 0) {
        tables->unk20 = b;
    }
    if (c != 0) {
        tables->unk30 = c;
    }
    if (d != 0) {
        tables->unk2C = d;
    }
    if (q->size == 0) {
        D_801DFF18 = 0;
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
    object_scene_tables.npc_count = entry->unk8;
    object_scene_tables.trigger_count = entry->unkC;
    object_aset_count = entry->unk10;
    object_scene_tables.npc_stats_count = entry->unk14;
    if (D_801DFF18 != 0) {
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

s32 object_room_on_enter(Unk_80192F60 *ev) {
    RoomPhone *phone = &object_room_phone;

    switch (ev->unkC) {
    case 0xFA0000:
        /* " 8机1から離れる       3○" */
        text_show(" 8\212\3671\202\251\202\347\227\243\202\352\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFA0001:
        /* " 8コンピュータ1を起動する  3○" */
        text_show(" 8\203R\203\223\203s\203\205\201[\203^1\202\360\213N\223\256\202\267\202\351  3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFA0002:
        /* " 8日記1をつける       3○" */
        text_show(" 8\223\372\213L1\202\360\202\302\202\257\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        break;
    case 0xFA0003:
        if (phone->state == 1) {
            /* " 8電話1をとる        3○" */
            text_show(" 8\223d\230b1\202\360\202\306\202\351        3\201\233", 1, -1, 8, -1, 0, 1);
        } else if (phone->state == 2) {
            /* " 8電話1をかける       3○" */
            text_show(" 8\223d\230b1\202\360\202\251\202\257\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

s32 object_room_on_effect_done(Unk_80193068 *ev) {
    GameVars_u8018FA18 *game;
    Player *player;
    u16 mode;
    s32 kind;
    RoomStorage *storage;

    game = &action_vars;
    storage = &object_room_storage;
    player = player_status_player[0];
    kind = ev->unk10;
    mode = D_801E0356[0];
    if (kind == 4) {
        if (D_801DFD56 != 0) {
            D_801DFD56 = 0;
            return 1;
        }
        if (player->flags & 0x10) {
            /* " なんだか、うとうとしてきた" */
            text_show(" \202\310\202\361\202\276\202\251\201A\202\244\202\306\202\244\202\306\202\265\202\304\202\253\202\275", 1, -1, 0, -1, 0, 0);
            kaj_view_set_bg_color(0, 0, 0);
            effect_start_fade(10, 3);
        }
    } else if (kind == 10) {
        if (ev->unkC == 0) {
            game->unk244 = -1;
        }
        player_rest(0, 0xDAC, 0, 0xC80);
        text_close();
        mail_wait(0, 0, 0, 4);
        effect_start_fade(9, 3);
    } else if (kind == 9) {
        if (ev->unkC == 0) {
            game->unk244 = -1;
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
                /* " 1預ける8武器1を方向キー上下で, 選んで下さい,      決定 3○ 1戻る 4×" */
                text_show(" 1\227a\202\257\202\3518\225\220\212\3551\202\360\225\373\214\374\203L\201[\217\343\211\272\202\305, \221I\202\361\202\305\211\272\202\263\202\242,      \214\210\222\350 3\201\233 1\226\337\202\351 4\201~", 3, -1, 0, -1, 0, 1);
            } else {
                /* " 1受け取る8武器1を方向キー上下で, 選んで下さい,      決定 3○ 1戻る 4×" */
                text_show(" 1\216\363\202\257\216\346\202\3518\225\220\212\3551\202\360\225\373\214\374\203L\201[\217\343\211\272\202\305, \221I\202\361\202\305\211\272\202\263\202\242,      \214\210\222\350 3\201\233 1\226\337\202\351 4\201~", 3, -1, 0, -1, 0, 1);
            }
        }
    } else if (kind == 12) {
        if (ev->unk8 != 999999) {
            object_room_storage_open(1, 0);
        }
    } else if (kind == 13) {
        if ((s16)mode == 1) {
            sound_bgm_play(0);
        }
    } else if (kind == 8) {
        mail_wait(0, 0, 0, 2);
        if (player->unk3C == 0) {
            player->unk3C = 1;
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
    flags = game->unkB2;
    if (phone->ringing != 0) {
        if ((player->flags & 0x40) && phone->state == 4 && ev_state->state == 0 && model->playing == 0 && model->anim == 1) {
            mod_set_anim(model, 2, 0);
        }
        return;
    }
    if (game->unk0[0x30] != 0 || flags == 0xFFFF) {
        return;
    }
    hours = game->unk7C + game->unk7A * 24;
    if (!(flags & 1) && (s16)mail_is_read(1) != 0 && game->unk0[0xD] == 100 && game->unk0[0xB] != 0) {
        phone->ringing = 1;
        phone->state = 2;
        phone->message = 0x65;
        return;
    } else if (!(flags & 2) && game->unk0[0xD] == 90) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x66;
    } else if (!(flags & 4) && game->unk0[0xD] == 80 && game->unk0[0xF] > 10) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x67;
    } else if (!(flags & 8) && (s16)mail_is_read(0x13) != 0 && hours < 58) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x68;
    } else if (!(flags & 0x10) && game->unk98 == 0 && game->unk7A == 1 && game->unk7C >= 14 && game->unk7C < 20) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x69;
    } else if (!(flags & 0x20) && game->unk98 >= 3 && hours < 51) {
        phone->ringing = 1;
        phone->state = 2;
        phone->message = 0x6A;
        return;
    } else if (!(flags & 0x40) && game->unk98 >= 3 && game->unk0[0x12] > 10 && game->unk0[0x12] <= 100) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x6B;
    } else if (!(flags & 0x80) && game->unk98 >= 3 && game->unk0[0x17] > 10 && game->unk0[0x17] <= 100) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x6C;
    } else if (!(flags & 0x100) && game->unk98 < 3 && game->unk0[0x17] > 10 && game->unk0[0x17] <= 100) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x6D;
    } else if (!(flags & 0x200) && hours >= 82 && game->unk0[0xE] > 10 && game->unk0[0xE] <= 100) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x6E;
    } else if (!(flags & 0x400) && hours >= 36 && game->unk0[0x1A] > 90 && game->unk0[0x18] != 10) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x6F;
    } else if (!(flags & 0x800) && game->unk0[0x1A] > 70 && game->unk0[0x18] == 10) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x70;
    } else if (!(flags & 0x1000) && hours >= 58) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x71;
    } else if (!(flags & 0x2000) && status->unk32 > 0 && status->unk30 == 0) {
        phone->ringing = 1;
        phone->state = 1;
        phone->message = 0x72;
    } else if (!(flags & 0x4000) && status->unk30 == 1) {
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

INCLUDE_RODATA("asm/nonmatchings/game/8018FA18", D_80170E18);

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
            can_swap = effect_weapon_list(storage->choice, &count, D_801E05E0);
            if (storage->choice != 0) {
                storage->stage = 1;
                if (can_swap != 0) {
                    goto ok;
                }
                {
                    RoomStorage *storage2;
                    char *line;

                    /* " 8武器2を持っていないと危険です" */
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
                    sprite_set_clut_entry(0, 4, D_801DFD5A);
                    sprite_set_clut_entry(0, 5, D_801DFD58);
                    text_show(D_80170E18, 3, -1, 0, -1, 0, 1);
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

                        /* " 2預かっている8武器2はありません" */
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
                        sprite_set_clut_entry(0, 4, D_801DFD5A);
                        sprite_set_clut_entry(0, 5, D_801DFD58);
                        text_show(D_80170E18, 3, -1, 0, -1, 0, 1);
                    }
                } else {
                    {
                        RoomStorage *storage2;
                        char *line;

                        /* " 2もう、持てないようですよ" */
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
                        sprite_set_clut_entry(0, 4, D_801DFD5A);
                        sprite_set_clut_entry(0, 5, D_801DFD58);
                        text_show(D_80170E18, 3, -1, 0, -1, 0, 1);
                    }
                }
            }
            return 1;
        ok:
            sound_se_play(0x11);
            storage->unk6 = 0;
            sprite_set_visible(0, 0);
            mail_menu_open(1, 0x40B, 0x402, count, 6, D_801E05E0, 4, 0x2969, 0x2BFF);
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
            sprite_set_clut_entry(0, 4, (&D_801DFD58)[storage->choice]);
            sprite_set_clut_entry(0, 5, (&D_801DFD58)[1 - storage->choice]);
        }
        return 1;
    }
    if (storage->stage == 1 || storage->stage == 2) {
        if (menu_state == 1) {
            if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
                sound_se_play(0x11);
                effect_weapon_swap_stock(storage->choice, D_801E05E0[storage->unk6]);
                mail_menu_close();
                return 1;
            }
            if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
                sound_se_play(8);
                mail_menu_close();
                return 1;
            }
            if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
                storage->unk6 = mail_menu_move(1);
            } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
                storage->unk6 = mail_menu_move(0);
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
            D_801DFD56 = 1;
            request->change = 1;
            break;
        case 0xFA0003:
            if (phone->state == 1 || phone->state == 2) {
                player->flags |= 0x40;
                game->unkB2 |= 1 << (phone->message - 0x65);
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
            sprite_set_clut_entry(0, 4, D_801DFD5A);
            sprite_set_clut_entry(0, 5, D_801DFD58);
            text_show(D_80170E18, 3, -1, 0, -1, 0, k);
            break;
        case 0xF0FF46:
            if (status->unk34 >= 2) {
                /* ソファーでの仮眠は、１日２回まで */
                text_show("\203\134\203\164\203\100\201\133\202\305\202\314\211\274\226\260\202\315\201\101\202\120\223\372\202\121\211\361\202\334\202\305", 1, -1, 0, -1, 0, 4);
                break;
            }
            status->unk34++;
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
    D_801DFD56 = 0;
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
    D_801DFF50 = (s32)object_room_pick_desk_action;
    D_801DFED8 = (s32)object_room_on_alarm;
    D_801DFEE4 = (s32)object_room_on_enter;
    D_801DFED4 = (s32)object_room_on_effect_done;
    D_801DFEE8 = (s32)object_room_on_mod_finish;
    phone->ringing = 0;
    phone->state = 0;
    phone->message = -1;
    D_801DFD54 = 0;
    if (request->unk0[3] == 1) {
        D_801DFD54 = 1;
    }
    k = ((s16 *)&request->pos_x)[1];
    if (k == 2) {
        game = &action_vars;
        player_status.energy = 0xC9;
        status->hours_awake = k;
        status->unk34 = 0;
        game->unk0[0x30] = 1;
        for (i = 9; i < 0x1C; i++) {
            game->unk0[i] = 1000;
        }
        for (i = 0; i < 5; i++) {
            status->limb_state[i] = 0;
            game->limb_damage[i] = 0;
        }
        if (game->unk7C >= 5) {
            game->unk7A++;
            if (game->unk7A >= 99) {
                game->unk7A = 98;
            }
        }
        game->unk7C = 5;
        game->unk7E = 0;
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
    D_801DFF50 = 0;
    D_801DFED8 = 0;
    D_801DFEE4 = 0;
    D_801DFED4 = 0;
    D_801DFEE8 = 0;
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
    for (i = 0; i < tables->unk34; i++) {
        if (tables->unk5C[i] != 0) {
            free3(tables->unk5C[i]);
            tables->unk5C[i] = 0;
        }
    }
    tables->unk34 = 0;
    switch (object_room_exit_action) {
    case 0:
        block_free_all();
        sound_bgm_close();
        sound_se_pop_scene();
        sprite_delete(0x207);
        if (D_801DFD54 != 0) {
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

    mode = D_801E0356[0];
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
        text_start_narration((s32)object_scene_tables.unk5C[(s16)mode - 1]);
        break;
    }
    m = mode;
    while (done == 0) {
        switch (kaj_event_get(buf)) {
        case 2:
            func_80189928(buf);
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
    sprite_set_clut_entry(0, 4, D_801DFD5A);
    sprite_set_clut_entry(0, 5, D_801DFD58);
    text_show(D_80170E18, 3, -1, 0, -1, 0, 1);
}

void object_room_pick_desk_action(s32 *out) {
    Player *player = player_status_player[0];
    RoomPhone *phone = &object_room_phone;
    s16 yaw;

    if ((*(u32 *)&player->unk40 & 0x1010000) == 0x10000) {
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

void object_room_on_alarm(Unk_80192F60 *ev) {
    Player *player = player_status_player[0];
    RoomPhone *phone = &object_room_phone;
    Model *model;

    if (ev->unkC == 0x400) {
        model = mod_find(0x440);
        if (model != NULL && model->anim == 0) {
            mod_set_anim(model, 1, 0);
        }
    } else if (ev->unkC == 0x401) {
        phone->state = 4;
        object_room_play_call(phone->message);
        sound_se_stop(0x33);
    } else if (ev->unkC == 0x402) {
        if (!(player->flags & 0x40) && phone->state != 4) {
            phone->state = 3;
            sound_se_stop(0x33);
            effect_start_alarm(3, 0x403, 10);
            if (player->flags & 1) {
                player_reset_triggers(0);
            }
        }
    } else if (ev->unkC == 0x403) {
        if (phone->state == 3) {
            phone->ringing = 0;
            phone->state = 0;
            phone->message = -1;
        }
    }
}

void object_room_on_mod_finish(Unk_80192F60 *ev) {
    PlayerStatus *status = &player_status;
    Player *player = status->player;
    Model *model = status->model;
    RoomPhone *phone = &object_room_phone;

    if (ev->unkC == 3 && ev->unk8 == 0x40) {
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
    void *model = D_801E0760[0];
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
    if (D_801DFF4C != 0) {
        D_801DFF4C = 0;
        ev = kaj_event_push(0x20);
        if (ev != NULL) {
            ev->unkC = object_area_previous.trigger;
            ev->unk8 = object_area_previous.trigger_type;
            ev->unk10 = object_area_previous.scene_trigger;
        }
    }
    ev = kaj_event_push(0x10);
    if (ev != NULL) {
        ev->unkC = object_area_current.trigger;
        ev->unk8 = object_area_current.trigger_type;
        ev->unk10 = object_area_current.scene_trigger;
    }
    object_area_previous.trigger_type = object_area_current.trigger_type;
    object_area_previous.trigger = object_area_current.trigger;
    object_area_previous.scene_trigger = object_area_current.scene_trigger;
    player->flags |= 4;
    return 0;
}
