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

void object_load_aset(IffContext *arg0, s32 arg1) {
    u8 sp10;
    void *buf;
    void *o;
    s32 n;
    s32 i;
    u8 *p;
    u32 *dst;

    buf = kaj_malloc(arg1);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_ASET Buffer", D_80170B7C, 0x8D);
    }
    *(IffChunkBody *)buf = *(IffChunkBody *)((u8 *)arg0->chunk + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = arg1 - 0x7F8;
    retry:
        sp10 = CdMode();
        if (!(sp10 & 0x80)) {
            sp10 = 0x80;
            while (CdControl(0xE, &sp10, NULL) == 0) {
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
        arg0->pos += arg1 - 0x7F8;
    }
    o = buf;
    for (i = 0; i < object_aset_count; i++) {
        o = action_load_set(o);
    }
    free3(buf);
}

void object_load_blck(IffContext *arg0, u16 arg1, s32 arg2) {
    Block *o;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    o = NULL;
    block_create(&o, arg2);
    *(IffChunkBody *)o->data = *(IffChunkBody *)((u8 *)arg0->chunk + 8);
    if (arg2 > 0x7F8) {
        dst = (u32 *)((u8 *)o->data + 0x7F8);
        n = arg2 - 0x7F8;
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
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
        arg0->pos += arg2 - 0x7F8;
    }
    block_setup(o, arg1);
    block_list_add((s32)o);
}

void object_load_door(IffContext *arg0, s32 arg1) {
    Door *o;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    o = NULL;
    door_create(&o, arg1);
    *(IffChunkBody *)o->record = *(IffChunkBody *)((u8 *)arg0->chunk + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)o->record + 0x7F8);
        n = arg1 - 0x7F8;
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
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
        arg0->pos += arg1 - 0x7F8;
    }
    door_setup((Block *)o);
    door_add(o);
}

INCLUDE_RODATA("asm/nonmatchings/game/8018FA18", D_80170B7C);

void object_load_mail(IffContext *arg0, s32 arg1, s32 arg2) {
    u8 sp10;
    s32 sp14;
    void *buf;
    s32 n;
    u8 *p;
    u32 *dst;

    buf = kaj_malloc(arg1);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_MAIL Buffer", D_80170B7C, 0xC6);
    }
    *(IffChunkBody *)buf = *(IffChunkBody *)((u8 *)arg0->chunk + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = arg1 - 0x7F8;
    retry:
        sp10 = CdMode();
        if (!(sp10 & 0x80)) {
            sp10 = 0x80;
            while (CdControl(0xE, &sp10, NULL) == 0) {
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
        arg0->pos += arg1 - 0x7F8;
    }
    mail_create(&sp14, buf, arg2);
    free3(buf);
    D_801E0324[0] = sp14;
}

void object_load_midi(IffContext *arg0, s32 arg1) {
    BgmSep *o;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    o = NULL;
    sound_bgm_create(&o, arg1);
    *(IffChunkBody *)o->data = *(IffChunkBody *)((u8 *)arg0->chunk + 8);
    if (arg1 > 0x7F8) {
        n = arg1 - 0x7F8;
        dst = (u32 *)((u8 *)o->data + 0x7F8);
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
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
        arg0->pos += arg1 - 0x7F8;
    }
    sound_bgm_open(o);
}

void object_load_mod(IffContext *arg0, s32 arg1) {
    Model *o;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    o = NULL;
    mod_alloc(&o, arg1);
    *(IffChunkBody *)o->data = *(IffChunkBody *)((u8 *)arg0->chunk + 8);
    if (arg1 > 0x7F8) {
        n = arg1 - 0x7F8;
        dst = (u32 *)((u8 *)o->data + 0x7F8);
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
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
        arg0->pos += arg1 - 0x7F8;
    }
    mod_list_add((s32)o);
}

void object_load_other(IffContext *arg0, s32 arg1, s32 arg2) {
    u8 sp10;
    void *buf;
    s32 n;
    u8 *p;
    u32 *dst;
    SceneTables *g;

    g = &object_scene_tables;
    buf = kaj_malloc(arg2);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_OTHER Buffer", D_80170B7C, 0xFD);
    }
    *(IffChunkBody *)buf = *(IffChunkBody *)((u8 *)arg0->chunk + 8);
    if (arg2 > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = arg2 - 0x7F8;
    retry:
        sp10 = CdMode();
        if (!(sp10 & 0x80)) {
            sp10 = 0x80;
            while (CdControl(0xE, &sp10, NULL) == 0) {
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
        arg0->pos += arg2 - 0x7F8;
    }
    switch (arg1) {
    case 0x41455241:
        g->triggers = buf;
        break;
    case 0x52544341:
        g->npcs = buf;
        action_init_npcs();
        break;
    case 0x2043504E:
        g->unk50 = buf;
        break;
    case 0x52414843:
        g->npc_bodies = buf;
        break;
    case 0x594D4E45:
        g->npc_stats = buf;
        break;
    case 0x4D455449:
        g->unk48 = buf;
        break;
    case 0x20545854:
        g->unk5C[g->unk34] = buf;
        g->unk34++;
        break;
    case 0x4E504557:
        g->unk58 = buf;
        break;
    }
}

void object_load_sprt(IffContext *arg0, s32 arg1) {
    Sprite *o;
    u8 sp10;
    SpriteRecord *buf;
    s32 n;
    u32 *dst;
    u8 *p;

    o = NULL;
    buf = kaj_malloc(arg1);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_SPRT Buffer", D_80170B7C, 0x12B);
    }
    *(IffChunkBody *)buf = *(IffChunkBody *)((u8 *)arg0->chunk + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = arg1 - 0x7F8;
    retry:
            sp10 = CdMode();
            if (!(sp10 & 0x80)) {
                sp10 = 0x80;
                while (CdControl(0xE, &sp10, NULL) == 0) {
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
        arg0->pos += arg1 - 0x7F8;
    }
    sprite_create(&o, buf);
    sprite_add((s32)o);
    free3(buf);
}

void object_load_text(IffContext *arg0, s32 arg1) {
    u8 sp10;
    void *buf;
    s32 n;
    u32 *dst;
    u8 *p;

    buf = kaj_malloc(arg1);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_TEXT Buffer", D_80170B7C, 0x140);
    }
    *(IffChunkBody *)buf = *(IffChunkBody *)((u8 *)arg0->chunk + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F8);
        n = arg1 - 0x7F8;
    retry:
            sp10 = CdMode();
            if (!(sp10 & 0x80)) {
                sp10 = 0x80;
                while (CdControl(0xE, &sp10, NULL) == 0) {
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
        arg0->pos += arg1 - 0x7F8;
    }
    kaj_tim_upload_hdr(buf);
    free3(buf);
}

void object_load_thng(IffContext *arg0, s32 arg1) {
    Thing *sp10;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    sp10 = NULL;
    thing_create(&sp10, arg1);
    *(IffChunkBody *)sp10->record = *(IffChunkBody *)((u8 *)arg0->chunk + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)sp10->record + 0x7F8);
        n = arg1 - 0x7F8;
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
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
        arg0->pos += arg1 - 0x7F8;
    }
    sprite_thing_init(sp10);
    thing_list_add((s32)sp10);
}

void object_load_tim(IffContext *arg0, s32 arg1) {
    u8 sp10;
    void *buf;
    s32 n;
    u32 *dst;
    u8 *p;

    buf = kaj_malloc(arg1);
    if (buf == NULL) {
        kaj_abend(3, "Error Allocating IFF_ID_TIM Buffer", D_80170B7C, 0x165);
    }
    *(Unk_8019120C *)buf = *(Unk_8019120C *)((u8 *)arg0->chunk + 0xC);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)buf + 0x7F4);
        n = arg1 - 0x7F8;
    retry:
        sp10 = CdMode();
        if (!(sp10 & 0x80)) {
            sp10 = 0x80;
            while (CdControl(0xE, &sp10, NULL) == 0) {
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
        arg0->pos += arg1 - 0x7F8;
    }
    kaj_tim_upload(buf, 0);
    free3(buf);
}

void object_load_vabh(IffContext *arg0, s32 arg1) {
    u8 sp10;
    s32 n;
    u32 *buf;
    u8 *p;

    buf = sound_se_alloc_header((u8 *)arg0->chunk + 8, arg1, &sound_vab_stream);
    n = arg1 - 0x7F8;
    while (1) {
        sp10 = CdMode();
        if (!(sp10 & 0x80)) {
            sp10 = 0x80;
            while (CdControl(0xE, &sp10, NULL) == 0) {
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
    arg0->pos += n;
    sound_vab_open_head(&sound_vab_stream);
}

void object_load_vabb(IffContext *arg0, s32 arg1) {
    u8 sp10;
    u8 sp11;
    u8 *buf;
    s32 n;
    u8 *buf2;
    u8 *p;

    sound_vab_stream.body_buf = (u8 *)arg0->chunk + 8;
    sound_vab_stream.body_len = 0x7F8;
    sound_vab_transfer(&sound_vab_stream);
    arg1 -= sound_vab_stream.body_len;
    sound_vab_stream.body_len = 0x2000;
    sound_vab_stream.body_buf = kaj_malloc(0x2000);
    if (sound_vab_stream.body_buf == NULL) {
        kaj_abend(3, "Error Allocating vab_trans_buffer", D_80170B7C, 0x191);
    }
    while (sound_vab_stream.body_len < arg1) {
        buf = sound_vab_stream.body_buf;
        n = sound_vab_stream.body_len;
    retry:
        sp10 = CdMode();
        if (!(sp10 & 0x80)) {
            sp10 = 0x80;
            while (CdControl(0xE, &sp10, NULL) == 0) {
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
        arg0->pos += sound_vab_stream.body_len;
        sound_vab_transfer(&sound_vab_stream);
        arg1 -= sound_vab_stream.body_len;
    }
    buf2 = D_801E05C8[0];
retry2:
    sp11 = CdMode();
    if (!(sp11 & 0x80)) {
        sp11 = 0x80;
        while (CdControl(0xE, &sp11, NULL) == 0) {
        }
        VSync(3);
    }
    while (CdRead(arg1 >> 11, (u32 *)buf2, 0x80) == 0) {
    }
    if (CdReadSync(0, NULL) == -1) {
        p = CdLastPos();
        while (CdControl(2, p, NULL) == 0) {
        }
        goto retry2;
    }
    p = CdLastPos();
    p = CdIntToPos(CdPosToInt(p) + (arg1 >> 11), p);
    while (CdControl(2, p, NULL) == 0) {
    }
    arg0->pos += arg1;
    sound_vab_stream.body_len = arg1;
    sound_vab_transfer(&sound_vab_stream);
    sound_se_push((Unk_801A217C *)&sound_vab_stream);
    free3(sound_vab_stream.body_buf);
}

void object_load_vecl(IffContext *arg0, s32 arg1) {
    Vehicle *sp10;
    u8 sp14;
    s32 n;
    u32 *dst;
    u8 *p;

    sp10 = NULL;
    vehicle_create(&sp10, arg1);
    *(IffChunkBody *)sp10->data = *(IffChunkBody *)((u8 *)arg0->chunk + 8);
    if (arg1 > 0x7F8) {
        dst = (u32 *)((u8 *)sp10->data + 0x7F8);
        n = arg1 - 0x7F8;
        while (1) {
            sp14 = CdMode();
            if (!(sp14 & 0x80)) {
                sp14 = 0x80;
                while (CdControl(0xE, &sp14, NULL) == 0) {
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
        arg0->pos += arg1 - 0x7F8;
    }
    vehicle_init((Unk_801E032C *)sp10);
}

void object_read_chunks(IffContext *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Inventory *m;
    u32 *buf;
    s32 size;
    s16 id;
    s16 id2;
    s32 tag;
    s16 found;
    s32 i;
    u8 *p;
    u8 sp10;

    if (arg2 == 1) {
        sound_se_play(0x31);
        object_load_chunk_count = 0;
    } else if (arg2 == 2) {
        if ((((Unk_80191AB0 *)arg1)->unk0 == 0 && ((Unk_80191AB0 *)arg1)->unk12 != 0) ||
            (((Unk_80191AB0 *)arg1)->unk0 == 1 && ((Unk_80191AB0 *)arg1)->unk1C == 0) ||
            (((Unk_80191AB0 *)arg1)->unk0 == 2 && ((Unk_80191AB0 *)arg1)->unk10 == 0)) {
            sprite_set_visible(0x410, 0);
            arg2 = -1;
        }
    }
    while (arg0->pos < arg0->size) {
        buf = arg0->chunk;
        for (;;) {
            sp10 = CdMode();
            if (!(sp10 & 0x80)) {
                sp10 = 0x80;
                while (CdControl(0xE, &sp10, NULL) == 0) {
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
        arg0->pos += 0x800;
        size = ((IffChunk *)arg0->chunk)->size;
        tag = ((IffChunk *)arg0->chunk)->tag;
        switch (tag) {
        case 0x54455341:
            object_load_aset(arg0, size);
            break;
        case 0x4B434C42:
            if (arg1 == 0) {
                object_load_blck(arg0, 3, size);
            } else if (((Unk_80191AB0 *)arg1)->unk0 == 0 && ((Unk_80191AB0 *)arg1)->unk10 == 0) {
                size -= 0x7F8;
                p = CdLastPos();
                p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
                while (CdControl(2, p, NULL) == 0) {
                }
                arg0->pos += size;
            } else {
                object_load_blck(arg0, ((Unk_80191AB0 *)arg1)->unk0, size);
            }
            break;
        case 0x524F4F44:
            object_load_door(arg0, size);
            break;
        case 0x4C49414D:
            id2 = ((IffChunk *)arg0->chunk)->unk8;
            if (id2 == mail_list_get_id(arg3)) {
                object_load_mail(arg0, size, arg3);
                return;
            }
            size -= 0x7F8;
            p = CdLastPos();
            p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
            while (CdControl(2, p, NULL) == 0) {
            }
            arg0->pos += size;
            break;
        case 0x4944494D:
            object_load_midi(arg0, size);
            break;
        case 0x20444F4D:
        case 0x20454F4D:
            if (arg3 == 0x400) {
                found = 0;
                m = player_status_inventory[0];
                for (i = 0; i < 2; i++) {
                    if (((IffChunk *)arg0->chunk)->unk8 == m->weapon_ids[i] + 0x400) {
                        found = 1;
                        break;
                    }
                }
                if (found) {
                    m->unk0++;
                    object_load_mod(arg0, size);
                } else {
                    size -= 0x7F8;
                    p = CdLastPos();
                    p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
                    while (CdControl(2, p, NULL) == 0) {
                    }
                    arg0->pos += size;
                }
            } else {
                object_load_mod(arg0, size);
            }
            break;
        case 0x54525053:
            id = ((IffChunk *)arg0->chunk)->unk8;
            object_load_sprt(arg0, size);
            if (id == 0x40F) {
                sprite_set_visible(0x40F, 1);
                object_load_chunk_count = 0;
                object_load_bar_step = 1;
            }
            break;
        case 0x204D4954:
            if (((IffChunk *)arg0->chunk)->unk8 == arg3) {
                object_load_tim(arg0, size);
            } else {
                size -= 0x7F8;
                p = CdLastPos();
                p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
                while (CdControl(2, p, NULL) == 0) {
                }
                arg0->pos += size;
            }
            break;
        case 0x54584554:
            object_load_text(arg0, size);
            break;
        case 0x474E4854:
            object_load_thng(arg0, size);
            break;
        case 0x42424156:
            if (arg1 != 0 && ((Unk_80191AB0 *)arg1)->unk0 == 0 && ((Unk_80191AB0 *)arg1)->unk14 == 0) {
                size -= 0x7F8;
                p = CdLastPos();
                p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
                while (CdControl(2, p, NULL) == 0) {
                }
                arg0->pos += size;
            } else {
                object_load_vabb(arg0, size);
            }
            break;
        case 0x48424156:
            if (arg1 != 0 && ((Unk_80191AB0 *)arg1)->unk0 == 0 && ((Unk_80191AB0 *)arg1)->unk14 == 0) {
                size -= 0x7F8;
                p = CdLastPos();
                p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
                while (CdControl(2, p, NULL) == 0) {
                }
                arg0->pos += size;
            } else {
                object_load_vabh(arg0, size);
            }
            break;
        case 0x4C434556:
            object_load_vecl(arg0, size);
            break;
        case 0x20545854:
        case 0x41455241:
        case 0x4D455449:
        case 0x4E504557:
        case 0x52544341:
        case 0x2043504E:
        case 0x52414843:
        case 0x594D4E45:
            object_load_other(arg0, tag, size);
            break;
        default:
            size -= 0x7F8;
            p = CdLastPos();
            p = CdIntToPos(CdPosToInt(p) + (size >> 11), p);
            while (CdControl(2, p, NULL) == 0) {
            }
            arg0->pos += size;
            break;
        }
        switch (arg2) {
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

void object_iff_open(IffContext **arg0, s32 arg1, s32 arg2) {
    struct {
        CdLoc unk0;
        u32 unk4;
        char unk8[16];
    } file;
    u8 sp28;
    s16 flag;
    u8 *p;
    u8 *q;
    void *r;
    u32 *dst;

    flag = arg1;
    D_801DFF18 = 1;
    *arg0 = kaj_malloc(0x10);
    if (*arg0 == NULL) {
        kaj_abend(3, "Error Allocation IFF Context", D_80170B7C, 0x2AA);
    }
    (*arg0)->size = 0;
    (*arg0)->pos = 0;
    (*arg0)->header = kaj_malloc(0x800);
    if ((*arg0)->header == NULL) {
        kaj_abend(3, "Error Allocating IFF Header", D_80170B7C, 0x2B1);
    }
    (*arg0)->chunk = kaj_malloc(0x800);
    if ((*arg0)->chunk == NULL) {
        kaj_abend(3, "Error Allocating IFF Chunk Header", D_80170B7C, 0x2B5);
    }
retry0:
    if (flag) {
        r = CdSearchFile(&file, "\\RES.R;1");
    } else {
        r = CdSearchFile(&file, "\\SCE.S;1");
    }
    if ((u32)((s32)r + 1) < 2) {
        goto retry0;
    }
    *(CdLoc *)object_iff_file_pos = file.unk0;
    while (CdControl(2, (u8 *)&file, NULL) == 0) {
    }
    if (arg2 > 0) {
        if (flag) {
            s32 n = object_res_offsets[arg2];

            p = object_iff_file_pos;
            p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
            while (CdControl(2, p, NULL) == 0) {
            }
        } else {
            s32 n = object_sce_offsets[arg2];

            p = object_iff_file_pos;
            p = CdIntToPos(CdPosToInt(p) + (n >> 11), p);
            while (CdControl(2, p, NULL) == 0) {
            }
        }
        *(CdLoc *)object_iff_file_pos = *(CdLoc *)CdLastPos();
    }
    dst = (u32 *)(*arg0)->header;
    while (1) {
        sp28 = CdMode();
        if (!(sp28 & 0x80)) {
            sp28 = 0x80;
            while (CdControl(0xE, &sp28, NULL) == 0) {
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
    IffContext *sp10;
    IffContext *q;
    IffContext *q2;
    IffContext *q3;
    IffEntry *e;
    SceneTables *g;
    SceneRequest *s;
    s32 pos;
    s32 a, b, c, d;
    u16 idx;
    u8 *p;
    u8 *loc;
    IffEntry *e2;
    s32 pos2;
    u8 *p2;
    u8 *loc2;

    s = &scene_request;
    object_iff_open(&sp10, 0, s->unk0[2]);
    q = sp10;
    q->pos = 0;
    e = q->header;
    pos = e->offset;
    q->size = e->size;
    g = &object_scene_tables;
    a = e->unk8;
    b = e->unkC;
    c = e->unk10;
    d = e->unk14;
    if (a != 0) {
        g->npc_body_count = a;
    }
    if (b != 0) {
        g->unk20 = b;
    }
    if (c != 0) {
        g->unk30 = c;
    }
    if (d != 0) {
        g->unk2C = d;
    }
    if (q->size == 0) {
        D_801DFF18 = 0;
    } else {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    if (sp10->size > 0) {
        object_read_chunks(sp10, (s32)s, 2, 0);
    }
    q2 = sp10;
    idx = s->unk0[3];
    q2->pos = 0;
    e2 = q2->header + idx + 1;
    pos2 = q2->header[idx + 1].offset;
    q2->size = e2->size;
    object_scene_tables.npc_count = e2->unk8;
    object_scene_tables.trigger_count = e2->unkC;
    object_aset_count = e2->unk10;
    object_scene_tables.npc_stats_count = e2->unk14;
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
    if (sp10->size > 0) {
        object_read_chunks(sp10, (s32)s, 2, 0);
    }
    q3 = sp10;
    free3(q3->header);
    free3(q3->chunk);
    free3(q3);
}

void object_load_weapon_mods(void) {
    IffContext *sp10;
    IffContext *q;
    IffContext *r;
    IffEntry *e;
    SceneTables *g;
    s32 pos;
    s32 a, b, c, d;
    u8 *p;
    u8 *loc;

    object_iff_open(&sp10, 1, 2);
    q = sp10;
    q->pos = 0;
    e = q->header;
    pos = e->offset;
    q->size = e->size;
    g = &object_scene_tables;
    a = e->unk8;
    b = e->unkC;
    c = e->unk10;
    d = e->unk14;
    if (a != 0) {
        g->npc_body_count = a;
    }
    if (b != 0) {
        g->unk20 = b;
    }
    if (c != 0) {
        g->unk30 = c;
    }
    if (d != 0) {
        g->unk2C = d;
    }
    if (q->size == 0) {
        D_801DFF18 = 0;
    } else {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    if (sp10->size > 0) {
        object_read_chunks(sp10, 0, 2, 0x400);
    }
    r = sp10;
    free3(r->header);
    free3(r->chunk);
    free3(r);
}

void object_load_mail_by_id(s16 arg0) {
    IffContext *sp10;
    IffContext *q;
    IffContext *r;
    IffEntry *e;
    SceneTables *g;
    s32 pos;
    s32 a, b, c, d;
    u8 *p;
    u8 *loc;

    object_iff_open(&sp10, 1, 7);
    q = sp10;
    q->pos = 0;
    e = q->header;
    pos = e->offset;
    q->size = e->size;
    g = &object_scene_tables;
    a = e->unk8;
    b = e->unkC;
    c = e->unk10;
    d = e->unk14;
    if (a != 0) {
        g->npc_body_count = a;
    }
    if (b != 0) {
        g->unk20 = b;
    }
    if (c != 0) {
        g->unk30 = c;
    }
    if (d != 0) {
        g->unk2C = d;
    }
    if (q->size == 0) {
        D_801DFF18 = 0;
    } else {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    if (sp10->size > 0) {
        object_read_chunks(sp10, 0, -1, arg0);
    }
    r = sp10;
    free3(r->header);
    free3(r->chunk);
    free3(r);
}

void object_load_res(s32 arg0, s32 arg1) {
    IffContext *sp10;
    IffContext *q;
    IffContext *r;
    IffEntry *e;
    SceneTables *g;
    s32 pos;
    s32 a, b, c, d;
    u8 *p;
    u8 *loc;

    object_iff_open(&sp10, 1, arg0);
    q = sp10;
    q->pos = 0;
    e = q->header;
    pos = e->offset;
    q->size = e->size;
    g = &object_scene_tables;
    a = e->unk8;
    b = e->unkC;
    c = e->unk10;
    d = e->unk14;
    if (a != 0) {
        g->npc_body_count = a;
    }
    if (b != 0) {
        g->unk20 = b;
    }
    if (c != 0) {
        g->unk30 = c;
    }
    if (d != 0) {
        g->unk2C = d;
    }
    if (q->size == 0) {
        D_801DFF18 = 0;
    } else {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    if (sp10->size > 0) {
        object_read_chunks(sp10, 0, arg1, 0);
    }
    r = sp10;
    free3(r->header);
    free3(r->chunk);
    free3(r);
}

void object_load_res12_by_id(s16 arg0) {
    IffContext *sp10;
    IffContext *q;
    IffContext *r;
    IffEntry *e;
    SceneTables *g;
    s32 pos;
    s32 a, b, c, d;
    u8 *p;
    u8 *loc;

    object_iff_open(&sp10, 1, 0xC);
    q = sp10;
    q->pos = 0;
    e = q->header;
    pos = e->offset;
    q->size = e->size;
    g = &object_scene_tables;
    a = e->unk8;
    b = e->unkC;
    c = e->unk10;
    d = e->unk14;
    if (a != 0) {
        g->npc_body_count = a;
    }
    if (b != 0) {
        g->unk20 = b;
    }
    if (c != 0) {
        g->unk30 = c;
    }
    if (d != 0) {
        g->unk2C = d;
    }
    if (q->size == 0) {
        D_801DFF18 = 0;
    } else {
        loc = object_iff_file_pos;
        p = CdIntToPos(CdPosToInt(loc) + (pos >> 11), loc);
        while (CdControl(2, p, NULL) == 0) {
        }
    }
    if (sp10->size > 0) {
        object_read_chunks(sp10, 0, 2, arg0);
    }
    r = sp10;
    free3(r->header);
    free3(r->chunk);
    free3(r);
}

void object_iff_seek_entry(IffContext *arg0, u16 arg1) {
    IffEntry *e;
    s32 pos;
    u8 *p;
    u8 *loc;

    arg0->pos = 0;
    e = arg0->header + arg1 + 1;
    pos = arg0->header[arg1 + 1].offset;
    arg0->size = e->size;
    object_scene_tables.npc_count = e->unk8;
    object_scene_tables.trigger_count = e->unkC;
    object_aset_count = e->unk10;
    object_scene_tables.npc_stats_count = e->unk14;
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

void object_iff_close(IffContext *arg0) {
    free3(arg0->header);
    free3(arg0->chunk);
    free3(arg0);
}

s32 object_room_on_enter(Unk_80192F60 *arg0) {
    RoomPhone *p = &object_room_phone;

    switch (arg0->unkC) {
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
        if (p->state == 1) {
            /* " 8電話1をとる        3○" */
            text_show(" 8\223d\230b1\202\360\202\306\202\351        3\201\233", 1, -1, 8, -1, 0, 1);
        } else if (p->state == 2) {
            /* " 8電話1をかける       3○" */
            text_show(" 8\223d\230b1\202\360\202\251\202\257\202\351       3\201\233", 1, -1, 8, -1, 0, 1);
        }
        break;
    default:
        return 0;
    }
    return 1;
}

s32 object_room_on_effect_done(Unk_80193068 *arg0) {
    GameVars_u8018FA18 *g;
    Player *o;
    u16 v;
    s32 t;
    RoomStorage *f;

    g = &action_vars;
    f = &object_room_storage;
    o = player_status_player[0];
    t = arg0->unk10;
    v = D_801E0356[0];
    if (t == 4) {
        if (D_801DFD56 != 0) {
            D_801DFD56 = 0;
            return 1;
        }
        if (o->flags & 0x10) {
            /* " なんだか、うとうとしてきた" */
            text_show(" \202\310\202\361\202\276\202\251\201A\202\244\202\306\202\244\202\306\202\265\202\304\202\253\202\275", 1, -1, 0, -1, 0, 0);
            kaj_view_set_bg_color(0, 0, 0);
            effect_start_fade(10, 3);
        }
    } else if (t == 10) {
        if (arg0->unkC == 0) {
            g->unk244 = -1;
        }
        player_rest(0, 0xDAC, 0, 0xC80);
        text_close();
        mail_wait(0, 0, 0, 4);
        effect_start_fade(9, 3);
    } else if (t == 9) {
        if (arg0->unkC == 0) {
            g->unk244 = -1;
        }
        o->flags &= ~0x10;
        kaj_view_set_bg_color(0x30, 0x30, 0x10);
    } else if (t == 0) {
        kaj_view_set_bg_color(0x30, 0x30, 0x10);
        if ((s16)v != 1) {
            sound_bgm_play(0);
        }
    } else if (t == 11) {
        if (!(o->flags & 0x4000)) {
            if (f->choice != 0) {
                /* " 1預ける8武器1を方向キー上下で, 選んで下さい,      決定 3○ 1戻る 4×" */
                text_show(" 1\227a\202\257\202\3518\225\220\212\3551\202\360\225\373\214\374\203L\201[\217\343\211\272\202\305, \221I\202\361\202\305\211\272\202\263\202\242,      \214\210\222\350 3\201\233 1\226\337\202\351 4\201~", 3, -1, 0, -1, 0, 1);
            } else {
                /* " 1受け取る8武器1を方向キー上下で, 選んで下さい,      決定 3○ 1戻る 4×" */
                text_show(" 1\216\363\202\257\216\346\202\3518\225\220\212\3551\202\360\225\373\214\374\203L\201[\217\343\211\272\202\305, \221I\202\361\202\305\211\272\202\263\202\242,      \214\210\222\350 3\201\233 1\226\337\202\351 4\201~", 3, -1, 0, -1, 0, 1);
            }
        }
    } else if (t == 12) {
        if (arg0->unk8 != 999999) {
            object_room_storage_open(1, 0);
        }
    } else if (t == 13) {
        if ((s16)v == 1) {
            sound_bgm_play(0);
        }
    } else if (t == 8) {
        mail_wait(0, 0, 0, 2);
        if (o->unk3C == 0) {
            o->unk3C = 1;
        }
    }
    return 0;
}

void object_room_check_calls(void) {
    Player *o;
    Model *p;
    u16 flags;
    s16 t;
    RoomPhone *f;
    GameVars_u8018FA18 *g;
    PlayerStatus *h;
    EventState *e;

    h = &player_status;
    e = &event_state;
    f = &object_room_phone;
    g = &action_vars;

    o = h->player;
    p = h->model;
    flags = g->unkB2;
    if (f->ringing != 0) {
        if ((o->flags & 0x40) && f->state == 4 && e->state == 0 && p->playing == 0 && p->anim == 1) {
            mod_set_anim(p, 2, 0);
        }
        return;
    }
    if (g->unk0[0x30] != 0 || flags == 0xFFFF) {
        return;
    }
    t = g->unk7C + g->unk7A * 24;
    if (!(flags & 1) && (s16)mail_is_read(1) != 0 && g->unk0[0xD] == 100 && g->unk0[0xB] != 0) {
        f->ringing = 1;
        f->state = 2;
        f->message = 0x65;
        return;
    } else if (!(flags & 2) && g->unk0[0xD] == 90) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x66;
    } else if (!(flags & 4) && g->unk0[0xD] == 80 && g->unk0[0xF] > 10) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x67;
    } else if (!(flags & 8) && (s16)mail_is_read(0x13) != 0 && t < 58) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x68;
    } else if (!(flags & 0x10) && g->unk98 == 0 && g->unk7A == 1 && g->unk7C >= 14 && g->unk7C < 20) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x69;
    } else if (!(flags & 0x20) && g->unk98 >= 3 && t < 51) {
        f->ringing = 1;
        f->state = 2;
        f->message = 0x6A;
        return;
    } else if (!(flags & 0x40) && g->unk98 >= 3 && g->unk0[0x12] > 10 && g->unk0[0x12] <= 100) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x6B;
    } else if (!(flags & 0x80) && g->unk98 >= 3 && g->unk0[0x17] > 10 && g->unk0[0x17] <= 100) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x6C;
    } else if (!(flags & 0x100) && g->unk98 < 3 && g->unk0[0x17] > 10 && g->unk0[0x17] <= 100) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x6D;
    } else if (!(flags & 0x200) && t >= 82 && g->unk0[0xE] > 10 && g->unk0[0xE] <= 100) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x6E;
    } else if (!(flags & 0x400) && t >= 36 && g->unk0[0x1A] > 90 && g->unk0[0x18] != 10) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x6F;
    } else if (!(flags & 0x800) && g->unk0[0x1A] > 70 && g->unk0[0x18] == 10) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x70;
    } else if (!(flags & 0x1000) && t >= 58) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x71;
    } else if (!(flags & 0x2000) && h->unk32 > 0 && h->unk30 == 0) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x72;
    } else if (!(flags & 0x4000) && h->unk30 == 1) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x73;
    } else if (!(flags & 0x8000) && h->mutant != 0) {
        f->ringing = 1;
        f->state = 1;
        f->message = 0x74;
    } else {
        return;
    }
    sound_se_play(0x33);
    effect_start_alarm(2, 0x402, 0x14);
    if (o->flags & 1) {
        player_reset_triggers(0);
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8018FA18", D_80170E18);

s16 object_room_storage_input(void) {
    RoomStorage *p;
    s16 t;
    s16 r;
    s16 n;

    p = &object_room_storage;
    if (object_room_storage.open == 0) {
        return 0;
    }
    t = mail_menu_get_state();
    if (p->stage == 0 && t == 0) {
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            r = effect_weapon_list(p->choice, &n, D_801E05E0);
            if (p->choice != 0) {
                p->stage = 1;
                if (r != 0) {
                    goto ok;
                }
                {
                    RoomStorage *q;
                    char *s;

                    /* " 8武器2を持っていないと危険です" */
                    s = " 8\225\220\212\3552\202\360\216\235\202\301\202\304\202\242\202\310\202\242\202\306\212\353\214\257\202\305\202\267";
                    q = &object_room_storage;
                    sprite_set_visible(0, 0);
                    if (s != NULL) {
                        text_show(s, 1, -1, 0, -1, 0, 4);
                    } else {
                        q->open = 0;
                        q->stage = 0;
                        q->choice = 1;
                        text_close();
                    }
                    if (s == NULL) {
                        mail_wait(0, 0, 0, 1);
                        return 1;
                    }
                    mail_wait(0, 0, 0, 3);
                    q->open = 1;
                    q->stage = 0;
                    q->choice = 1;
                    sprite_set_visible(0, 1);
                    sprite_set_clut_entry(0, 4, D_801DFD5A);
                    sprite_set_clut_entry(0, 5, D_801DFD58);
                    text_show(D_80170E18, 3, -1, 0, -1, 0, 1);
                }
            } else {
                p->stage = 2;
                if (r != 0) {
                    goto ok;
                }
                if (n == 0) {
                    {
                        RoomStorage *q;
                        char *s;

                        /* " 2預かっている8武器2はありません" */
                        s = " 2\227a\202\251\202\301\202\304\202\242\202\3518\225\220\212\3552\202\315\202\240\202\350\202\334\202\271\202\361";
                        q = &object_room_storage;
                        sprite_set_visible(0, 0);
                        if (s != NULL) {
                            text_show(s, 1, -1, 0, -1, 0, 4);
                        } else {
                            q->open = 0;
                            q->stage = 0;
                            q->choice = 1;
                            text_close();
                        }
                        if (s == NULL) {
                            mail_wait(0, 0, 0, 1);
                            return 1;
                        }
                        mail_wait(0, 0, 0, 3);
                        q->open = 1;
                        q->stage = 0;
                        q->choice = 1;
                        sprite_set_visible(0, 1);
                        sprite_set_clut_entry(0, 4, D_801DFD5A);
                        sprite_set_clut_entry(0, 5, D_801DFD58);
                        text_show(D_80170E18, 3, -1, 0, -1, 0, 1);
                    }
                } else {
                    {
                        RoomStorage *q;
                        char *s;

                        /* " 2もう、持てないようですよ" */
                        s = " 2\202\340\202\244\201A\216\235\202\304\202\310\202\242\202\346\202\244\202\305\202\267\202\346";
                        q = &object_room_storage;
                        sprite_set_visible(0, 0);
                        if (s != NULL) {
                            text_show(s, 1, -1, 0, -1, 0, 4);
                        } else {
                            q->open = 0;
                            q->stage = 0;
                            q->choice = 1;
                            text_close();
                        }
                        if (s == NULL) {
                            mail_wait(0, 0, 0, 1);
                            return 1;
                        }
                        mail_wait(0, 0, 0, 3);
                        q->open = 1;
                        q->stage = 0;
                        q->choice = 1;
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
            p->unk6 = 0;
            sprite_set_visible(0, 0);
            mail_menu_open(1, 0x40B, 0x402, n, 6, D_801E05E0, 4, 0x2969, 0x2BFF);
            return 1;
        }
        if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            RoomStorage *q;

            sound_se_play(8);
            q = &object_room_storage;
            sprite_set_visible(0, 0);
            q->open = 0;
            q->stage = 0;
            q->choice = 1;
            text_close();
            mail_wait(0, 0, 0, 1);
            return 1;
        }
        if ((!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) ||
            (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000))) {
            sound_se_play(0xF);
            p->choice = p->choice == 0;
            sprite_set_clut_entry(0, 4, (&D_801DFD58)[p->choice]);
            sprite_set_clut_entry(0, 5, (&D_801DFD58)[1 - p->choice]);
        }
        return 1;
    }
    if (p->stage == 1 || p->stage == 2) {
        if (t == 1) {
            if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
                sound_se_play(0x11);
                effect_weapon_swap_stock(p->choice, D_801E05E0[p->unk6]);
                mail_menu_close();
                return 1;
            }
            if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
                sound_se_play(8);
                mail_menu_close();
                return 1;
            }
            if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
                p->unk6 = mail_menu_move(1);
            } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
                p->unk6 = mail_menu_move(0);
            }
        }
    }
    return 1;
}

void object_room_do_action(PlayerStatus *arg0) {
    SceneRequest *s;
    EventState *e;
    RoomPhone *q;
    GameVars_u8018FA18 *g;
    Player *o;
    ActionSet *t;
    RoomStorage *r;
    s32 k;
    s16 mode;

    s = &scene_request;
    e = &event_state;
    q = &object_room_phone;
    g = &action_vars;
    mode = e->state;
    o = arg0->player;

    if (mode == 3) {
        text_next_page(e);
    } else if (mode == 2 && (e->circle_flags & 8)) {
        text_close();
        sound_se_play(event_state.trigger == 0xFA0000 ? 0xE : 0x11);
        switch ((u32)event_state.trigger) {
        case 0xFA0000:
            player_start_move_to(2, 1, 0x76C, 0, 0x19C8, 0, 0xB4, 0, mode);
            break;
        case 0xFA0001:
            player_start_move_to(0, 0, 0xDF6, 0x244, 0x1888, 6, 0x8E, 0, mode);
            object_room_exit_action = 1;
            s->change = 1;
            break;
        case 0xFA0002:
            player_start_move_to(0, 0, 0xC12, 0x208, 0x18CE, -0x5A, 0xBF, 0, mode);
            object_room_exit_action = 2;
            D_801DFD56 = 1;
            s->change = 1;
            break;
        case 0xFA0003:
            if (q->state == 1 || q->state == 2) {
                o->flags |= 0x40;
                g->unkB2 |= 1 << (q->message - 0x65);
                mod_set_anim(arg0->model, 1, 0);
            }
            break;
        case 0xF0FF0A:
        case 0xF0FF14:
        case 0xF0FF1E:
            k = 1;
            r = &object_room_storage;
            r->open = k;
            r->stage = 0;
            r->choice = k;
            sprite_set_visible(0, k);
            sprite_set_clut_entry(0, 4, D_801DFD5A);
            sprite_set_clut_entry(0, 5, D_801DFD58);
            text_show(D_80170E18, 3, -1, 0, -1, 0, k);
            break;
        case 0xF0FF46:
            if (arg0->unk34 >= 2) {
                /* ソファーでの仮眠は、１日２回まで */
                text_show("\203\134\203\164\203\100\201\133\202\305\202\314\211\274\226\260\202\315\201\101\202\120\223\372\202\121\211\361\202\334\202\305", 1, -1, 0, -1, 0, 4);
                break;
            }
            arg0->unk34++;
        default:
            t = action_find_set(e->circle_set);
            while (t != NULL) {
                t = action_run_set(t, 0, 0);
            }
            break;
        }
        e->state = 1;
        e->circle_flags &= ~8;
    }
}

void object_room_update_input(void) {
    Player *s0;
    s32 s3;
    PlayerStatus *p = &player_status;

    s0 = p->player;
    if (kaj_system.pad_mode != 1) {
        return;
    }
    if ((s0->flags & 2) || (s0->flags & 0x10)) {
        return;
    }
    s3 = kaj_pad_read();
    if (object_room_storage_input() != 0) {
        return;
    }
    if (!(s0->flags & 1) && effect_item_input(p, 0) != 0) {
        return;
    }
    if (s0->flags & 4) {
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            object_room_do_action(p);
            return;
        }
        if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            EventState *q = &event_state;
            if (!(p->player->flags & 0x40)) {
                s16 t = q->state;
                if (t == 2 && (p->player->flags & 1)) {
                    text_close();
                    sound_se_play(0xE);
                    player_start_move_to(2, 1, 0x76C, 0, 0x19C8, 0, 0xB4, 0, t);
                    q->state = 0;
                }
            }
            return;
        }
    }
    if (!(s0->flags & 0x40)) {
        player_handle_pad(p, 0, s3);
    }
}

void object_room_init(void) {
    PlayerStatus *p;
    Player *o;
    RoomPhone *q;
    SceneRequest *r;
    Model *m;
    GameVars_u8018FA18 *g;
    s32 i;
    s32 k;

    p = &player_status;
    r = &scene_request;
    o = p->player;
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
    m = mod_find(0x40);
    q = &object_room_phone;
    p->model = m;
    if (m != NULL) {
        mod_setup(m, 0, 3, 0);
        p->model->coord_tx = 0xDAC - o->cell_x * 12500;
        p->model->coord_ty = 0;
        p->model->coord_tz = 0x1A2C - o->cell_z * 12500;
        p->model->coord_flg = 0;
    }
    D_801DFF50 = (s32)object_room_pick_desk_action;
    D_801DFED8 = (s32)object_room_on_alarm;
    D_801DFEE4 = (s32)object_room_on_enter;
    D_801DFED4 = (s32)object_room_on_effect_done;
    D_801DFEE8 = (s32)object_room_on_mod_finish;
    q->ringing = 0;
    q->state = 0;
    q->message = -1;
    D_801DFD54 = 0;
    if (r->unk0[3] == 1) {
        D_801DFD54 = 1;
    }
    k = ((s16 *)&r->pos_x)[1];
    if (k == 2) {
        g = &action_vars;
        player_status.energy = 0xC9;
        p->hours_awake = k;
        p->unk34 = 0;
        g->unk0[0x30] = 1;
        for (i = 9; i < 0x1C; i++) {
            g->unk0[i] = 1000;
        }
        for (i = 0; i < 5; i++) {
            p->limb_state[i] = 0;
            g->limb_damage[i] = 0;
        }
        if (g->unk7C >= 5) {
            g->unk7A++;
            if (g->unk7A >= 99) {
                g->unk7A = 98;
            }
        }
        g->unk7C = 5;
        g->unk7E = 0;
        event_draw_gauge(p);
        event_draw_limb_status(p);
    }
    event_show_clock(0);
    sprite_set_visible(0x410, 0);
}

void object_room_quit(void) {
    SceneTables *p = &object_scene_tables;
    PlayerStatus *q = &player_status;
    s32 i;

    effect_clear_alarms();
    sound_bgm_stop();
    sound_se_stop_all();
    D_801DFF50 = 0;
    D_801DFED8 = 0;
    D_801DFEE4 = 0;
    D_801DFED4 = 0;
    D_801DFEE8 = 0;
    q->model = 0;
    text_close();
    action_reset(1);
    action_free_triggers();
    action_free_all_sets();
    npc_free_bodies();
    door_free_all();
    mod_free_all();
    sprite_delete(0);
    thing_free_all();
    for (i = 0; i < p->unk34; i++) {
        if (p->unk5C[i] != 0) {
            free3(p->unk5C[i]);
            p->unk5C[i] = 0;
        }
    }
    p->unk34 = 0;
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

void object_room_storage_open(s16 arg0, char *arg1) {
    RoomStorage *p = &object_room_storage;

    if (arg0 == 0) {
        sprite_set_visible(0, 0);
        if (arg1 != NULL) {
            text_show(arg1, 1, -1, 0, -1, 0, 4);
        } else {
            p->open = 0;
            p->stage = 0;
            p->choice = 1;
            text_close();
        }
        if (arg1 == NULL) {
            mail_wait(0, 0, 0, 1);
            return;
        }
        mail_wait(0, 0, 0, 3);
    }
    p->open = 1;
    p->stage = 0;
    p->choice = 1;
    sprite_set_visible(0, 1);
    sprite_set_clut_entry(0, 4, D_801DFD5A);
    sprite_set_clut_entry(0, 5, D_801DFD58);
    text_show(D_80170E18, 3, -1, 0, -1, 0, 1);
}

void object_room_pick_desk_action(s32 *arg0) {
    Player *p = player_status_player[0];
    RoomPhone *q = &object_room_phone;
    s16 v;

    if ((*(u32 *)&p->unk40 & 0x1010000) == 0x10000) {
        *arg0 = 0xFA0000;
        if (p->pitch >= -20 && p->pitch <= 10) {
            v = p->yaw;
            if (v >= 130 && v <= 170) {
                *arg0 = 0xFA0001;
            } else if (v >= 180 && v < 220) {
                *arg0 = 0xFA0002;
            } else if (v >= 220 && v <= 250) {
                if (q->ringing != 0 && q->state != 3) {
                    *arg0 = 0xFA0003;
                }
            }
        }
    }
}

void object_room_on_alarm(Unk_80192F60 *arg0) {
    Player *p = player_status_player[0];
    RoomPhone *q = &object_room_phone;
    Model *o;

    if (arg0->unkC == 0x400) {
        o = mod_find(0x440);
        if (o != NULL && o->anim == 0) {
            mod_set_anim(o, 1, 0);
        }
    } else if (arg0->unkC == 0x401) {
        q->state = 4;
        object_room_play_call(q->message);
        sound_se_stop(0x33);
    } else if (arg0->unkC == 0x402) {
        if (!(p->flags & 0x40) && q->state != 4) {
            q->state = 3;
            sound_se_stop(0x33);
            effect_start_alarm(3, 0x403, 10);
            if (p->flags & 1) {
                player_reset_triggers(0);
            }
        }
    } else if (arg0->unkC == 0x403) {
        if (q->state == 3) {
            q->ringing = 0;
            q->state = 0;
            q->message = -1;
        }
    }
}

void object_room_on_mod_finish(Unk_80192F60 *arg0) {
    PlayerStatus *r = &player_status;
    Player *p = r->player;
    Model *o = r->model;
    RoomPhone *q = &object_room_phone;

    if (arg0->unkC == 3 && arg0->unk8 == 0x40) {
        if (o->anim == 1) {
            if (q->state == 2) {
                sound_se_play(0x33);
                effect_start_alarm(1, 0x401, 5);
            } else if (q->state == 1) {
                q->state = 4;
                object_room_play_call(q->message);
                sound_se_stop(0x33);
            }
        } else if (o->anim == 2) {
            text_close();
            p->flags &= ~0x40;
            q->ringing = 0;
            q->state = 0;
            q->message = -1;
            if (p->flags & 1) {
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

void object_room_play_call(s16 arg0) {
    void *o = D_801E0760[0];
    EventState *p = &event_state;
    ActionSet *item;

    item = action_find_set(arg0);
    if (item != NULL) {
        p->trigger = 0;
        p->circle_set = -1;
        p->cross_set = -1;
        p->trigger_type = 0;
        p->circle_flags = 0;
        p->cross_flags = 0;
        p->state = 1;
        while ((item = action_run_set(item, 0, 0)) != NULL) {
        }
    } else {
        mod_set_anim(o, 2, 0);
    }
}

s32 object_deliver_area_events(void) {
    Player *p = &player_character;
    KajEvent *o;

    UnDeliverEvent(0xF3000000, 2);
    if (D_801DFF4C != 0) {
        D_801DFF4C = 0;
        o = kaj_event_push(0x20);
        if (o != NULL) {
            o->unkC = object_area_previous.trigger;
            o->unk8 = object_area_previous.trigger_type;
            o->unk10 = object_area_previous.scene_trigger;
        }
    }
    o = kaj_event_push(0x10);
    if (o != NULL) {
        o->unkC = object_area_current.trigger;
        o->unk8 = object_area_current.trigger_type;
        o->unk10 = object_area_current.scene_trigger;
    }
    object_area_previous.trigger_type = object_area_current.trigger_type;
    object_area_previous.trigger = object_area_current.trigger;
    object_area_previous.scene_trigger = object_area_current.scene_trigger;
    p->flags |= 4;
    return 0;
}
