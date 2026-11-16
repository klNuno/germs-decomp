#include "common.h"
#include "game/types.h"

s16 kaj_ll_at_tail(BlockList *arg0);
BlockList *block_list;
void kaj_ll_insert_before(BlockList *arg0, s32 arg1);
void kaj_ll_insert_after(BlockList *arg0, s32 arg1);
void kaj_cdmgr_free_all(void);
extern s16 D_801E71C8;
/* Local view of GameVars: this unit reads 0x0-0xBE as one s16 array (lh), the shared type has a u16 array. */
typedef struct {
    s16 unk0[0x5F];
    s16 unkBE;
    u8 padC0[0x13C];
    s16 drain_count;
    s16 drain_minute;
    s16 car_speed_setting;
    s16 text_speed_setting;
    u8 pad204[0x44];
    s32 unk248;
    u8 pad24C[0x2];
    s16 unk24E;
    s16 unk250;
    s16 unk252;
    s16 unk254;
} GameVars_u8017EBF8;
u8 D_801DFC8C;
u8 D_801DFC8D[1];
u8 D_801DFC8E;
extern GameVars_u8017EBF8 action_vars;
s16 block_wake_index;
void block_create_all(void);
void block_building_run(void);
void effect_elevator_run(void);
u16 D_801DFE60;
void text_release_cmd(void);
void sprite_set_visible(s32 arg0, s32 arg1);
void sprite_set_clut_entry(s32 arg0, s32 arg1, s32 arg2);
void sound_se_play(s32 arg0);
TextCmd **text_cmd;
s16 text_window_sprite;
void action_push_front(TextCmd **arg0);
s16 text_wait;
extern s32 D_801E6DB4[];
extern s32 D_801E05B0[];
extern Player *player_status_player[];
extern char D_80170250[];
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
void *memset(void *dst, s32 c, u32 n);
extern char D_801DFC84[];
void free3(void *ptr);
typedef struct {
    u8 unk0[0x20];
} Unk_801D75F4;
typedef struct {
    s16 unk0;
    u8 pad2[0x2];
    char unk4[0x14];
    u8 unk18;
    u8 unk19;
    u8 unk1A;
    u8 unk1B;
    u8 unk1C[0x40];
    u8 unk5C[0x1C];
    Unk_801D75F4 unk78;
} Unk_801802A0_14;
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 padA[0x2];
    s32 unkC;
    u32 unk10;
    Unk_801802A0_14 unk14[4];
} Unk_801802A0;
void sprite_fill_clut(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
typedef struct Unk_801A44B8 {
    u8 pad0[0x4];
    s16 visible;
    u8 pad6[0x6];
    s16 y;
    u8 padE[0x4];
    s16 cell_h;
    u8 pad14[0x4];
    s16 cell_col;
    s16 cell_row;
    Rect *tim;
} Unk_801A44B8;
void sprite_delete(s32 arg0);
void mail_list_close(void);
void mail_free(void);
Unk_801A44B8 *sprite_find(u16 arg0);
s32 ClearImage2(Rect *rect, s32 r, s32 g, s32 b);
s16 text_draw_next(s32 arg0, s32 arg1);
s16 text_row;
s16 D_801DFCE6;
s16 text_pos;
s32 block_model_surface(void *arg0, s32 arg1, s32 arg2, s32 arg3);
void kaj_ll_remove_to_prev(BlockList *arg0);
s16 text_cue_fade_done;
s16 text_cue_bgm_done;
void sound_bgm_fade_out(s32 arg0);
void effect_start_fade(s32 arg0, s32 arg1);
extern EventState event_state;
extern char D_80170270[];
extern Block *block_slots[];
void npc_update_blocks(void);
void block_setup(Block *arg0, u16 arg1);
void mod_create(void *arg0);
void kaj_tim_upload_hdr(void *arg0);
void **kaj_cdmgr_get(s32 arg0);
s32 kaj_cdmgr_get_type(s32 arg0);
s32 kaj_cdmgr_is_fresh(s32 arg0);
void kaj_cdmgr_mark_used(s32 arg0);
void kaj_map_cell_slots(s16 *arg0, s32 *arg1);
void kaj_map_room_slots(s16 *arg0, s32 *arg1);
void kaj_map_room_release(s32 arg0);
u16 block_building_id;
void block_load_all(u16 arg0);
void block_set_zone_flags(s32 arg0, s32 arg1);
s32 kaj_cdmgr_poll(void);
s32 kaj_map_update_city(s32 arg0, s32 arg1);
s32 kaj_map_update_place(u16 arg0, u8 *arg1);
void kaj_map_cell_loaded_slots(s16 *arg0, s32 *arg1);
void kaj_map_set_cell_ready(void);
void kaj_map_set_room_ready(void);
void kaj_map_room_loaded_slots(s16 *arg0, s32 *arg1);
typedef struct {
    s32 unk0;
    struct {
        u8 pad0[0x18];
        s32 unk18;
        s32 unk1C;
        s32 unk20;
    } *unk4;
    struct {
        s32 unk0;
        s32 unk4;
        s32 unk8;
        s32 unkC;
        TmdTri *unk10;
        s32 unk14;
    } *unk8;
} Unk_8017BBB0;
typedef struct {
    u8 pad0[0xBC];
    Unk_8017BBB0 *unkBC;
} Unk_801E032C;
extern Unk_801E032C *D_801E032C[];
s32 block_hit_tris(TmdTri *arg0, s32 arg1, s32 arg2, Vec3 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
s32 block_hit_quads(TmdTri *arg0, s32 arg1, s32 arg2, Vec3 *arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7);
char *strncpy(char *dst, char *src, u32 n);
extern char D_801DFCBC[];
extern s16 D_801DFC74;
s16 text_col;
s16 text_color;
s16 text_len;
s32 strlen(char *s);
extern SceneRequest scene_request;
void object_load_res(s32 arg0, s32 arg1);
void mail_list_open(void);
void menu_list_page(PauseMenu *arg0, s32 arg1, s32 arg2);
void menu_status_page(PauseMenu *arg0, s32 arg1);
void menu_options_page(PauseMenu *arg0, s32 arg1, s16 arg2);
void object_load_mail_by_id(s16 arg0);
void text_narration_step(TssSlot *arg0);
void text_narration_end(void);
void *kaj_tss_alloc(u32 arg0);
s32 kaj_tss_start(void *arg0);
DoorList *door_list;
void RotMatrix(SVector *arg0, void *arg1);
Block *block_find_at(s32 arg0, s32 arg1, s32 arg2);
typedef struct {
    Unk_8018519C_0 *unk0;
    s32 unk4;
    char **unk8;
} Unk_8018519C;
s32 atoi(char *s);
void door_start_open(DoorMove *arg0, s16 arg1, s16 arg2, s16 arg3);
void door_start_close(DoorMove *arg0, s16 arg1, s16 arg2);
extern char D_80170290[];
void menu_card_init_slots(Unk_801802A0 *arg0, s32 arg1);
void sprite_set_cell(s32 arg0, s32 arg1, s32 arg2);
s32 MemCardSync(s32 arg0, s32 *arg1, s32 *arg2);
void MemCardExist(s32 arg0);
s32 MemCardFormat(s32 arg0);
void MemCardAccept(s32 arg0);
void menu_card_set_message(Unk_801802A0 *arg0, s32 arg1);
s32 menu_card_load(Unk_801802A0 *arg0);
s32 menu_card_save(Unk_801802A0 *arg0, s32 arg1);
s32 menu_card_scan(Unk_801802A0 *arg0);
extern Unk_801D75F4 menu_card_icon_clut;
s32 LoadImage2(void *rect, void *p);
int sprintf(char *buf, const char *fmt, ...);
extern Unk_801802A0 menu_card_state;
void menu_card_process(Unk_801802A0 *arg0);
s16 menu_card_handle_input(Unk_801802A0 *arg0);
s32 mail_take_scene_change(void);
s16 event_handle_effect_done(s32 *arg0);
s32 kaj_event_get(s32 *arg0);
void kaj_event_done(s32 *arg0);
void kaj_pad_reset(s32 a);
void kaj_timer_enable(void);
void kaj_timer_disable(void);
void thing_update_all(void);
void roadmap_draw_frame(u16 a);
void MemCardStart(void);
void MemCardStop(void);
extern s16 menu_list_vars[];
s32 MoveImage2(Rect *rect, s32 x, s32 y);
Unk_801A44B8 *menu_anim_sprite;
s32 mail_list_move(s16 a, s16 b);
extern KajSystem kaj_system;
void menu_confirm(PauseMenu *arg0);
void menu_back(PauseMenu *arg0);
void menu_move_cursor(PauseMenu *arg0, s16 arg1);
void mail_goto_ofc(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 kaj_pad_read(void);
void mail_scroll(s32 arg0);
void menu_handle_input(PauseMenu *arg0);
void menu_animate(PauseMenu *arg0);
void event_handle_tick(s16 a);
void sound_bgm_play(s32 arg0);
void sound_bgm_stop(void);
void text_draw_string(s32 arg0, s16 arg1);
void mail_wait(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s16 D_801DFC80;
void door_move_x(DoorMove *arg0);
void door_move_y(DoorMove *arg0);
void door_move_z(DoorMove *arg0);
void door_move_angle(DoorMove *arg0);
void menu_card_move_cursor(Unk_801802A0 *arg0, s16 arg1);
extern s16 D_801E6DAA[];
u16 *Krom2RawAdd2(u16 sjis);
s32 StoreImage2(void *rect, void *p);
extern s32 text_line_y[];
void text_draw_line(char *arg0, s16 arg1);
/* Local view of Player: this unit reads 0x1C-0x38 as scalars, the shared type has one record at 0x18. */
typedef struct {
    u8 pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    u8 pad28[0x10];
    s16 unk38;
} Unk_801E0710_5C;
typedef struct Unk_80188FEC {
    u16 unk0;
    u16 unk2;
    u8 pad4[0x2C];
    s16 unk30;
    u8 pad32[0x1E];
    u16 unk50;
} Unk_80188FEC;
extern PlayerStatus player_status;
void sprite_copy_cell(s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
Unk_80188FEC *effect_weapon_find(s16 arg0);
s32 rand(void);
s32 menu_cycle_pos_a;
s32 menu_cycle_pos_b;
s32 menu_cycle_pos_c;
s16 menu_cycle_dir_a;
s16 menu_cycle_dir_b;
s16 menu_cycle_dir_c;
void text_format_number(u8 *arg0, u16 arg1);
Npc *npc_find(s16 arg0, u16 arg1);
NpcBody *npc_find_body(s16 arg0);
extern char *text_sex_names[];
extern char *text_blood_types[];
void text_show_timed(u16 arg0, s16 arg1, s32 arg2, s16 arg3, s32 arg4);
void text_start_typing(s32 arg0);
extern s16 D_801DFC5C;
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16 unk6;
    u16 unk8;
    u8 padA[0x2];
    s32 unkC;
    s32 unk10;
    s32 unk14;
    u8 unk18[0x4];
} Unk_801844D4;
void GsInitCoordinate2(void *super, void *base);
void kaj_tmd_load(void *arg0, void *arg1, void *arg2);
typedef struct {
    s16 unk0;
    s16 unk2[0x80];
    s16 unk102[2];
    s16 unk106[0x27];
    s32 unk154[0x11];
    s32 unk198[0xE];
    u8 pad1D0[0x2C];
} Unk_8017EFEC;
void mail_goto_twn(s32 a, s32 b, s32 c, s16 d, s16 e);
s32 MemCardOpen(s32 chan, char *file, s32 flag);
void MemCardClose(void);
s32 MemCardReadData(void *adrs, s32 ofs, s32 bytes);
void *memcpy(void *dst, const void *src, unsigned int n);
extern char menu_str_save_title[];
extern s16 D_801E0568[];
extern u8 menu_card_icon_image[];
extern s16 D_801E034A[];
s32 MemCardCreateFile(s32 chan, char *file, s32 blocks);
void MemCardDeleteFile(s32 chan, char *file);
s32 MemCardWriteData(void *adrs, s32 ofs, s32 bytes);
typedef struct {
    char unk0[0x14];
    s32 unk14;
    s32 unk18;
    void *unk1C;
    s32 unk20;
    char unk24[0x4];
} Unk_8017FF0C;
s32 MemCardGetDirentry(s32 arg0, char *arg1, Unk_8017FF0C *arg2, s32 *arg3, s32 arg4, s32 arg5);
s32 MemCardReadFile(s32 arg0, char *arg1, void *arg2, s32 arg3, s32 arg4);
int strncmp(const char *a, const char *b, int n);
extern char D_801DFC90[];

void menu_card_init_slots(Unk_801802A0 *card, s32 clear_icons) {
    Rect rect;
    void *buf;
    Unk_801802A0_14 *slot;
    s32 i;

    slot = card->unk14;
    card->unk6 = 0;
    card->unk8 = -1;
    for (i = 0; i < 4; i++, slot++) {
        memset(slot->unk4, 0, 0x14);
        sprintf(slot->unk4, "BISLPS-02107GERMS%d", i);
        slot->unk0 = 0;
        slot->unk18 = 'S';
        slot->unk19 = 'C';
        slot->unk1A = 0x11;
        slot->unk1B = 1;
        memset(slot->unk1C, 0, 0x40);
        memset(slot->unk5C, 0, 0x1C);
        slot->unk78 = menu_card_icon_clut;
    }
    sprite_fill_clut(0x200, 4, 7, 0xC252);
    sprite_fill_clut(0x200, 9, 0xC, 0xC252);
    if ((s16)clear_icons != 0) {
        buf = kaj_malloc(0x80);
        if (buf != 0) {
            memset(buf, 0x22, 0x80);
            rect.y = 0xF;
            rect.w = 4;
            rect.x = 0;
            rect.h = 0x10;
            for (i = 0; i < 4; i++) {
                rect.x = 0x3E8;
                LoadImage2(&rect, buf);
                rect.x = 0x3F1;
                LoadImage2(&rect, buf);
                rect.x = 0x3F8;
                LoadImage2(&rect, buf);
                rect.y += 0x20;
            }
            free3(buf);
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/8017EBF8", menu_str_save_title);

void menu_card_set_message(Unk_801802A0 *card, s32 result) {
    s32 cell;

    if (result < 0x64) {
        switch (result) {
        case 0:
            return;
        case 1:
            menu_card_init_slots(card, 1);
            card->unkC = 0x66;
            break;
        case 2:
            menu_card_init_slots(card, 1);
            card->unkC = 0x67;
            break;
        case 3:
            card->unkC = -1;
            card->unk10 = 0;
            return;
        case 4:
            card->unkC = 0x69;
            break;
        case 5:
            if (card->unk0 != 0) {
                card->unkC = 0x66;
                card->unk10 = 0;
            } else {
                card->unkC = -1;
                card->unk10 = 0xD;
            }
            return;
        case 6:
            card->unkC = 0x6B;
            break;
        case 7:
            card->unkC = 0x6A;
            break;
        default:
            card->unkC = -1;
            return;
        }
    } else {
        card->unkC = result;
    }
    switch (card->unkC) {
    case 0x64:
        cell = 1;
        break;
    case 0x65:
        cell = 0;
        break;
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x6A:
        cell = 2;
        sound_se_play(0xE);
        break;
    case 0x69:
        cell = 3;
        if (card->unk0 == 0) {
            cell = 1;
        }
        sound_se_play(0xE);
        break;
    case 0x6B:
        cell = 1;
        sound_se_play(0xE);
        break;
    default:
        return;
    }
    sprite_set_visible(0x202, 1);
    sprite_set_visible(0x203, 1);
    sprite_set_cell(0x202, (s16)((card->unkC - 0x64) / 4), (s16)((card->unkC - 0x64) % 4));
    sprite_set_cell(0x203, 0, cell);
}

static inline s32 func_8017EFEC_inline(u8 *buf, s32 block) {
    s32 cmd;
    s32 result;
    for (;;) {
        switch (MemCardSync(1, &cmd, &result)) {
        case 0:
            continue;
        case -1:
            MemCardReadData(buf, block << 7, 0x80);
            continue;
        case 1:
            if (cmd != 5) {
                continue;
            }
            break;
        default:
            continue;
        }
        break;
    }
    return result;
}

static inline s16 func_8017EFEC_inline2(u8 *sec) {
    u8 sum;
    s32 i;
    sum = 0;
    for (i = 0; i < 0x7F; i++) {
        sum ^= *sec++;
    }
    if (*sec != sum) {
        return 0;
    }
    return 1;
}

s32 menu_card_load(Unk_801802A0 *card) {
    Unk_8017EFEC save;
    u8 sec[0x80];
    PlayerStatus *status = &player_status;
    GameVars_u8017EBF8 *vars = &action_vars;
    s16 *car_speed = &vars->car_speed_setting;
    Inventory *inventory = status->inventory;
    Unk_801E0710_5C *player = status->player;
    Unk_801802A0_14 *slot;
    s32 ret;
    s32 i;

    slot = &card->unk14[card->unk8];
    menu_card_set_message(card, 0x65);
    roadmap_draw_frame(3);
    ret = MemCardOpen(0, slot->unk4, 1);
    if (ret != 0) {
        return ret;
    }
    memset(&save, 0, sizeof(save));
    for (i = 0; i < 4; i++) {
        memset(sec, 0, 0x80);
        ret = func_8017EFEC_inline(sec, i * 2 + 2);
        if (ret != 0) {
            goto error;
        }
        if (func_8017EFEC_inline2(sec)) {
            memcpy((u8 *)&save + i * 0x7F, sec, 0x7F);
        } else {
            memset(sec, 0, 0x80);
            ret = func_8017EFEC_inline(sec, i * 2 + 3);
            if (ret != 0) {
                goto error;
            }
            if (func_8017EFEC_inline2(sec)) {
                memcpy((u8 *)&save + i * 0x7F, sec, 0x7F);
            } else {
                ret = 0x68;
                goto error;
            }
        }
    }
    MemCardClose();
    card->unk2 = 1;
    memcpy(vars, save.unk2, sizeof(save.unk2));
    memcpy(car_speed, save.unk102, sizeof(save.unk102));
    memcpy(status, save.unk106, sizeof(save.unk106));
    memcpy(inventory, save.unk154, sizeof(save.unk154));
    memcpy(player, save.unk198, sizeof(save.unk198));
    vars->drain_count = 0;
    vars->drain_minute = vars->unk0[0x3F] % 10;
    if (save.unk0 != 0) {
        mail_goto_ofc(1, 1, 1, 0);
    } else {
        mail_goto_twn(player->unk1C, player->unk20, player->unk24, player->unk38, 0);
    }
    return 0x6C;
error:
    MemCardClose();
    return ret;
}

static inline s32 func_8017F6F4_inline(void *buf, s32 block) {
    s32 cmd;
    s32 result;
    for (;;) {
        switch (MemCardSync(1, &cmd, &result)) {
        case 0:
            continue;
        case -1:
            MemCardWriteData(buf, block << 7, 0x80);
            continue;
        case 1:
            if (cmd == 6) {
                return result;
            }
            continue;
        }
    }
}

static inline void func_8017F6F4_digits(char *out, s32 n) {
    out[0] = out[2] = 0x82;
    out[1] = n / 10 + 0x4F;
    out[3] = n % 10 + 0x4F;
    out[4] = 0;
}

s32 menu_card_save(Unk_801802A0 *card, s32 overwrite) {
    Unk_8017EFEC save;
    u8 sec[0x80];
    char day_str[8];
    char hour_str[8];
    char minute_str[8];
    char slot_str[8];
    PlayerStatus *status = &player_status;
    GameVars_u8017EBF8 *vars = &action_vars;
    s16 *car_speed = &vars->car_speed_setting;
    Inventory *inventory = status->inventory;
    Unk_801E0710_5C *player = status->player;
    Unk_801802A0_14 *slot;
    u8 *header;
    u8 *p;
    u8 sum;
    s32 ret;
    s32 i;
    s32 j;

    slot = &card->unk14[card->unk8];
    header = &slot->unk18;
    if (slot->unk0 != 0) {
        if ((s16)overwrite == 0) {
            return 0x6B;
        }
    } else {
        ret = MemCardCreateFile(0, slot->unk4, 1);
        if (ret != 0) {
            return ret;
        }
    }
    menu_card_set_message(card, 0x65);
    roadmap_draw_frame(3);
    ret = MemCardOpen(0, slot->unk4, 2);
    if (ret != 0) {
        return ret;
    }
    func_8017F6F4_digits(day_str, vars->unk0[0x3D] + 1);
    func_8017F6F4_digits(hour_str, vars->unk0[0x3E]);
    func_8017F6F4_digits(minute_str, vars->unk0[0x3F]);
    func_8017F6F4_digits(slot_str, card->unk8 + 1);
    memset(header + 4, 0, 0x40);
    /* ジャーム／第%s日／%s時%s分／記録%s */
    sprintf(header + 4, menu_str_save_title, day_str, hour_str, minute_str, slot_str);
    memset(&save, 0, sizeof(save));
    memcpy(save.unk2, vars, sizeof(save.unk2));
    memcpy(save.unk102, car_speed, sizeof(save.unk102));
    memcpy(save.unk106, status, sizeof(save.unk106));
    memcpy(save.unk154, inventory, sizeof(save.unk154));
    memcpy(save.unk198, player, sizeof(save.unk198));
    save.unk0 = card->unk4;
    if (func_8017F6F4_inline(header, 0) != 0) {
        goto error;
    }
    if (func_8017F6F4_inline(menu_card_icon_image, 1) != 0) {
        goto error;
    }
    for (i = 0; i < 4; i++) {
        memset(sec, 0, 0x80);
        memcpy(sec, (u8 *)&save + i * 0x7F, 0x7F);
        p = sec;
        sum = 0;
        for (j = 0; j < 0x7F; j++) {
            sum ^= *p++;
        }
        *p = sum;
        if (func_8017F6F4_inline(sec, i * 2 + 2) != 0) {
            goto error;
        }
        if (func_8017F6F4_inline(sec, i * 2 + 3) != 0) {
            goto error;
        }
    }
    MemCardClose();
    D_801E034A[0] = 1;
    return 0x6C;
error:
    MemCardClose();
    if (slot->unk0 == 0) {
        MemCardDeleteFile(0, slot->unk4);
    }
    return 0x68;
}

s32 menu_card_scan(Unk_801802A0 *card) {
    Unk_8017FF0C entries[15];
    s32 count;
    s32 cmd;
    s32 result;
    s32 first_slot;
    s32 ret;
    s32 used_blocks;
    s32 found;
    s32 i;
    s32 j;
    s32 n;
    s32 y;
    s32 m;
    u8 *rr;
    u8 *r2;
    u8 *r3;
    u8 *header;
    u8 *title;
    Unk_801802A0_14 *slot;

    ret = MemCardGetDirentry(0, D_801DFC90, entries, &count, 0, 15);
    if (ret != 0) {
        return ret;
    }
    if (card->unk0 != 0 && count == 0) {
        return 0x6A;
    }
    used_blocks = 0;
    found = 0;
    first_slot = 4;
    cmd = 0;
    result = 0;
    for (i = 0; i < count; i++) {
        n = entries[i].unk18 / 0x2000;
        if (entries[i].unk18 & 0x1FFF) {
            used_blocks += n + 1;
        } else {
            used_blocks += n;
        }
        slot = card->unk14;
        for (j = 0; j < 4; j++, slot++) {
            if (strncmp(entries[i].unk0, slot->unk4, 0x12) == 0) {
                slot->unk0 = 1;
                found++;
                if (j < first_slot) {
                    first_slot = j;
                }
            }
        }
    }
    if (found == 0) {
        first_slot = 0;
    }
    if (card->unk0 != 0) {
        if (found == 0) {
            return 0x6A;
        }
    } else if (found == 0 && used_blocks == 15) {
        return 0x6A;
    }
    sprite_fill_clut(0x200, 4, 7, 0xC252);
    slot = card->unk14;
    for (i = 0; i < 4; i++, slot++) {
        header = &slot->unk18;
        if (slot->unk0 != 0) {
            for (;;) {
                switch (MemCardSync(1, &cmd, &result)) {
                case 0:
                    continue;
                case -1:
                    MemCardReadFile(0, slot->unk4, header, 0, 0x80);
                    continue;
                case 1:
                    if (cmd == 3 && result != 0) {
                        return result;
                    }
                    break;
                }
                break;
            }
            sprite_set_clut_entry(0x200, i + 4, 0x3FF);
            title = header + 4;
            y = i * 32 + 0xF;
            for (m = 0; m < 2; m++) {
                rr = (u8 *)(m * 2 + (s32)title);
                rr += 0xD;
                sprite_copy_cell(0x204, (u16)(*rr - 0x4F), 0, 0x200, (u16)(m * 8 + 0x21), (u16)y);
                r2 = (u8 *)(m * 2 + (s32)title);
                r2 += 0x15;
                sprite_copy_cell(0x204, (u16)(*r2 - 0x4F), 0, 0x200, (u16)(m * 8 + 0x44), (u16)y);
                r3 = (u8 *)(m * 2 + (s32)title);
                r3 += 0x1B;
                sprite_copy_cell(0x204, (u16)(*r3 - 0x4F), 0, 0x200, (u16)(m * 8 + 0x62), (u16)y);
            }
        }
    }
    card->unk8 = first_slot;
    sprite_fill_clut(0x200, 9, 0xC, 0xC252);
    sprite_set_clut_entry(0x200, first_slot + 9, 0x3FF);
    return 0x64;
}

void menu_card_move_cursor(Unk_801802A0 *card, s16 up) {
    s32 i;
    s32 se;

    if (up != 0) {
        i = card->unk8 - 1;
        if (i < 0) {
            i = 3;
        }
    } else {
        i = card->unk8 + 1;
        if (i >= 4) {
            i = 0;
        }
    }
    if (card->unk0 != 0) {
loop:
        if (card->unk14[i].unk0 == 0) {
            if (up != 0) {
                i--;
                if (i < 0) {
                    i = 3;
                }
            } else {
                i++;
                if (i >= 4) {
                    i = 0;
                }
            }
            goto loop;
        }
    }
    card->unk8 = i;
    sprite_fill_clut(0x200, 9, 0xC, 0xC252);
    sprite_set_clut_entry(0x200, i + 9, 0x3FF);
    se = 1;
    if (card->unk0 == 0) {
        se = 0xF;
    }
    sound_se_play(se);
}

s16 menu_card_handle_input(Unk_801802A0 *card) {
    s32 cmd;
    s32 result;
    s32 ok;
    s32 pressed;
    s32 se;
    SceneRequest *req;

    req = &scene_request;
    if (D_801E6DAA[0] != 1 || card->unkC == 0x65 || card->unkC == 0x6C) {
        return 0;
    }
    if (card->unkC == -1) {
        return 1;
    }
    if (card->unkC == 0x66 || card->unkC == 0x67) {
        ok = 1;
    } else {
        for (;;) {
            switch (MemCardSync(1, &cmd, &result)) {
            case 0:
                continue;
            case -1:
                MemCardExist(0);
                continue;
            case 1:
                if (cmd != 1) {
                    continue;
                }
                switch (result) {
                case 0:
                    ok = 1;
                    break;
                case 3:
                    card->unkC = -1;
                    card->unk10 = 0;
                case 1:
                case 2:
                    menu_card_set_message(card, result);
                    ok = 0;
                    break;
                default:
                    continue;
                }
                break;
            default:
                continue;
            }
            break;
        }
    }
    if (ok != 0) {
        pressed = 0;
        kaj_pad_read();
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            pressed = 1;
            se = 0x11;
            switch (card->unkC) {
            case 0x64:
            case 0x68:
                if (card->unk0 != 0) {
                    card->unk10 = 0xC;
                    se = 2;
                } else {
                    card->unk10 = 0xD;
                }
                card->unkC = -1;
                break;
            case 0x69:
                if (card->unk0 != 0) {
                    break;
                }
                card->unk10 = 0xA;
                card->unkC = -1;
                break;
            case 0x66:
            case 0x67:
                card->unk10 = 0;
                card->unkC = -1;
                break;
            case 0x6A:
                if (card->unk0 != 0) {
                    card->unk10 = 0;
                }
                card->unkC = -1;
                break;
            case 0x6B:
                card->unk10 = 0xE;
                card->unkC = -1;
                break;
            default:
                pressed = 0;
                break;
            }
        } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            if (card->unkC == 0x6B || (card->unk0 == 0 && card->unkC == 0x6A)) {
                pressed = 1;
                se = 8;
                menu_card_set_message(card, 0x64);
            } else {
                sound_se_play(8);
                mail_wait(3, 0, 0, 1);
                req->change = 1;
            }
        } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
            if (card->unkC == 0x64) {
                menu_card_move_cursor(card, 1);
            }
        } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
            if (card->unkC == 0x64) {
                menu_card_move_cursor(card, 0);
            }
        }
        ok = pressed;
    }
    if (ok) {
        sound_se_play(se);
    }
    return 0;
}

void menu_card_process(Unk_801802A0 *card) {
    s32 cmd;
    s32 result;
    s32 r;
    s32 a;

    switch (MemCardSync(1, &cmd, &result)) {
    case 0:
        break;
    case -1:
        switch (card->unk10) {
        case 0:
            MemCardExist(0);
            break;
        case 10:
            r = MemCardFormat(0);
            if (r == 0) {
                card->unk10 = 0xB;
                card->unkC = -1;
            } else {
                menu_card_set_message(card, r);
            }
            break;
        case 11:
            menu_card_set_message(card, menu_card_scan(card));
            break;
        case 12:
            menu_card_set_message(card, menu_card_load(card));
            break;
        case 13:
            menu_card_set_message(card, menu_card_save(card, 0));
            break;
        case 14:
            menu_card_set_message(card, menu_card_save(card, 1));
            break;
        }
        break;
    case 1:
        a = cmd;
        switch (a) {
        case 1:
            if (result == 0) {
                card->unk10 = 0xB;
                card->unk6 = a;
                card->unkC = -1;
            } else if (result == 3) {
                card->unk6 = a;
                MemCardAccept(0);
            } else {
                menu_card_set_message(card, result);
            }
            break;
        case 2:
            if (result == 0 || result == 3) {
                card->unk10 = 0xB;
                card->unkC = -1;
            } else {
                menu_card_set_message(card, result);
            }
            break;
        }
        break;
    }
}

s16 menu_card_run(s16 load_mode, s16 in_office) {
    s32 ev[6];
    Unk_801802A0 *card;
    s16 done = 0;
    s16 ready;
    s32 i;

    card = &menu_card_state;
    if (load_mode != 0) {
        object_load_res(4, -1);
    } else {
        object_load_res(5, -1);
    }
    sprite_set_visible(0x200, 1);
    sprite_set_visible(0x202, 1);
    sprite_set_visible(0x203, 1);
    card->unk0 = load_mode;
    card->unk2 = 0;
    card->unk4 = in_office;
    card->unkC = -1;
    card->unk10 = 0;
    menu_card_init_slots(card, 0);
    MemCardStart();
    kaj_timer_enable();
    kaj_pad_reset(1);
    while (done == 0) {
        switch (kaj_event_get(ev)) {
        case 0:
            ready = menu_card_handle_input(card);
            if ((s16)mail_take_scene_change() != 0) {
                if (in_office != 0 || (card->unk2 != 0 && load_mode != 0)) {
                    effect_start_fade(1, 3);
                } else {
                    kaj_pad_reset(0);
                    done = 1;
                }
            }
            break;
        case 0x100:
            done = event_handle_effect_done(ev);
            continue;
        default:
            kaj_event_done(ev);
            continue;
        }
        if (ready != 0) {
            menu_card_process(card);
        }
        thing_update_all();
        roadmap_draw_frame(3);
    }
    kaj_timer_disable();
    MemCardSync(0, 0, 0);
    MemCardStop();
    sprite_set_visible(0x200, 0);
    sprite_set_visible(0x202, 0);
    sprite_set_visible(0x203, 0);
    for (i = 0x200; i < 0x205; i++) {
        sprite_delete((u16)i);
    }
    return card->unk2;
}

void menu_list_page(PauseMenu *menu, s32 action, s32 up) {
    GameVars_u8017EBF8 *vars = &action_vars;
    Rect rect;

    switch ((s16)action) {
    case 0:
        sprite_set_visible(0x237, 1);
        sprite_set_visible(0x238, 1);
        break;
    case 1:
        sound_se_play(0x11);
        sprite_set_visible(0x239, 1);
        rect.x = 0x3C0;
        rect.y = menu->row * 0x40;
        rect.w = 0x2C;
        rect.h = 0x40;
        MoveImage2(&rect, 0x300, 0x100);
        sprite_fill_clut(0x239, 2, 5, 0x421);
        switch (vars->unk0[menu_list_vars[menu->row]]) {
        case 0:
            break;
        case 10:
            sprite_set_clut_entry(0x239, 2, 0xB4);
            sprite_set_clut_entry(0x239, 3, 0x28A);
            break;
        case 1000:
            sprite_set_clut_entry(0x239, 2, 0xB4);
            sprite_set_clut_entry(0x239, 3, 0x28A);
            sprite_set_clut_entry(0x239, 4, 0x2A85);
            break;
        case 2000:
            sprite_set_clut_entry(0x239, 2, 0xB4);
            sprite_set_clut_entry(0x239, 3, 0x28A);
            sprite_set_clut_entry(0x239, 4, 0x2A85);
            sprite_set_clut_entry(0x239, 5, 0x3CAF);
            break;
        default:
            sprite_set_clut_entry(0x239, 2, 0xB4);
            break;
        }
        return;
    case 2:
        sound_se_play(0xF);
        if ((s16)up != 0) {
            if (--menu->row < 0) {
                menu->row = 7;
            }
        } else {
            if (++menu->row >= 8) {
                menu->row = 0;
            }
        }
        break;
    }
    sprite_set_cell(0x238, 0, menu->row);
    sprite_fill_clut(0x237, 1, 8, 0x10C);
    sprite_set_clut_entry(0x237, menu->row + 1, 0x23F);
}

void menu_status_page(PauseMenu *menu, s32 flip) {
    PlayerStatus *status = &player_status;
    GameVars_u8017EBF8 *vars = &action_vars;
    Inventory *inventory = status->inventory;
    Unk_80188FEC *weapon;
    s32 len;
    s32 j;
    s32 i;
    s32 id;
    s32 col;
    s32 k;
    s32 m;
    s32 len2;

    if ((s16)flip != 0) {
        sound_se_play(0x11);
        menu->row = 1 - menu->row;
        if (menu->row != 0) {
            sprite_set_visible(0x23A, 0);
            sprite_set_visible(0x23B, 1);
        } else {
            sprite_set_visible(0x23A, 1);
            sprite_set_visible(0x23B, 0);
        }
        return;
    }
    sprite_set_visible(0x23A, 1);
    sprite_set_visible(0x23B, 0);
    sprite_fill_clut(0x23A, 0x10, 0xEF, 0x421);
    sprite_fill_clut(0x23B, 0x10, 0xDF, 0x421);
    sprite_fill_clut(0x23B, 0x60, 0x64, 0x14C6);
    sprite_fill_clut(0x23B, 0x70, 0x74, 0x14C6);
    col = 0x3D40;
    len = status->exp / 6329;
    if (len == 0 && status->exp != 0) {
        len = 1;
    }
    if (len > 32) {
        len = 32;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x10, (u16)col);
        }
    }
    len = (status->level << 5) / 50 + 1;
    if (len > 32) {
        len = 32;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x30, (u16)col);
        }
    }
    len = (status->exp << 4) / status->next_exp;
    if (len == 0 && status->exp != 0) {
        len = 1;
    }
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x50, (u16)col);
        }
    }
    col = 0xB4;
    len = status->unk32 > 16 ? 16 : status->unk32;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x60, (u16)col);
        }
    }
    col = 0x3D40;
    len = status->hours_awake > 32 ? 32 : status->hours_awake;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x70, (u16)col);
        }
    }
    len = (status->defense_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0x90, (u16)col);
        }
    }
    len = (vars->unk0[0x5A] + 15) / 16;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0xA0, (u16)col);
        }
    }
    len = (vars->unk0[0x5D] + 15) / 16;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0xB0, (u16)col);
        }
    }
    len = (vars->unk0[0x5B] + 15) / 16;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0xC0, (u16)col);
        }
    }
    len = (vars->unk0[0x5C] + 15) / 16;
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23A, j + 0xD0, (u16)col);
        }
    }
    len2 = (vars->unk0[0x5E] + 15) / 16;
    if (len2 != 0) {
        for (j = 0; j < len2; j++) {
            sprite_set_clut_entry(0x23A, j + 0xE0, (u16)col);
        }
    }
    col = 0x3D40;
    len = (status->weapon0_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23B, j + 0x10, (u16)col);
        }
    }
    len = (status->weapon1_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23B, j + 0x20, (u16)col);
        }
    }
    len = (status->weapon2_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23B, j + 0x30, (u16)col);
        }
    }
    len = (status->weapon3_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23B, j + 0x40, (u16)col);
        }
    }
    len = (status->weapon4_level << 4) / 100 + 1;
    if (len > 16) {
        len = 16;
    }
    if (len != 0) {
        for (j = 0; j < len; j++) {
            sprite_set_clut_entry(0x23B, j + 0x50, (u16)col);
        }
    }
    for (i = 0; i < 2; i++) {
        id = inventory->weapon_ids[i];
        if (id >= 0) {
            weapon = effect_weapon_find(id);
            if (weapon != NULL) {
                sprite_set_clut_entry(0x23B, (i * 16 + 0x60) + weapon->unk2, 0x154);
                len = (weapon->unk30 << 5) / 50 + 1;
                if (len > 32) {
                    len = 32;
                }
                k = i * 32 + 0x80;
                if (len != 0) {
                    for (j = 0; j < len; j++) {
                        sprite_set_clut_entry(0x23B, k + j, (u16)col);
                    }
                }
                len = (weapon->unk50 << 12) / 25600;
                m = i * 16 + 0xC0;
                if (len != 0) {
                    for (j = 0; j < len; j++) {
                        sprite_set_clut_entry(0x23B, m + j, (u16)col);
                    }
                }
                sprite_copy_cell(0x23C, (u16)(id / 9), (u16)(id % 9), 0x23B, 0x21, (u16)(i * 42 + 0x53));
            }
        }
    }
}

void menu_options_page(PauseMenu *menu, s32 action, s16 decrease) {
    GameVars_u8017EBF8 *vars = &action_vars;
    s16 play_se = 1;

    switch (action) {
    case 0:
        play_se = 0;
        sprite_set_visible(0x23D, 1);
        break;
    case 1:
        menu->row = 1 - menu->row;
        break;
    case 2:
        if (menu->row != 0) {
            if (decrease != 0) {
                vars->car_speed_setting--;
                if (vars->car_speed_setting < 0) {
                    vars->car_speed_setting = 2;
                }
            } else {
                vars->car_speed_setting++;
                if (vars->car_speed_setting >= 3) {
                    vars->car_speed_setting = 0;
                }
            }
        } else {
            if (decrease != 0) {
                vars->text_speed_setting--;
                if (vars->text_speed_setting < 0) {
                    vars->text_speed_setting = 2;
                }
            } else {
                vars->text_speed_setting++;
                if (vars->text_speed_setting >= 3) {
                    vars->text_speed_setting = 0;
                }
            }
        }
        break;
    }
    sprite_fill_clut(0x23D, 7, 8, 0x4250);
    sprite_set_clut_entry(0x23D, menu->row + 7, 0x5140);
    sprite_fill_clut(0x23D, 9, 0xE, 0x421);
    sprite_set_clut_entry(0x23D, vars->text_speed_setting + 9, 0x154);
    sprite_set_clut_entry(0x23D, vars->car_speed_setting + 0xC, 0x154);
    if (play_se != 0) {
        sound_se_play(0xF);
    }
}

void menu_move_cursor(PauseMenu *menu, s16 up) {
    GameVars_u8017EBF8 *vars = &action_vars;
    Unk_801A44B8 *cursor;
    Unk_801A44B8 *label;
    Unk_801A44B8 *item_sprite;

    switch (menu->page) {
    case 0:
        if (menu->unk4 != 0) {
            break;
        }
        if (up != 0) {
            if (--menu->item < 0) {
                menu->item = 4;
            }
        } else {
            if (++menu->item >= 5) {
                menu->item = 0;
            }
        }
        cursor = sprite_find(0x20B);
        label = sprite_find(0x211);
        if (cursor != 0) {
            cursor->y = (menu->item << 4) + 0x48;
        }
        if (label != 0 && label->visible != 0) {
            label->visible = 0;
        }
        if (menu_anim_sprite != 0) {
            menu_anim_sprite->visible = 0;
        }
        if (menu->item == 0) {
            menu->unk8 = 0;
            menu->unkC = 0;
            menu_anim_sprite = 0;
        } else {
            menu->unkC = label;
            item_sprite = sprite_find(menu->item + 0x20C);
            if (item_sprite == 0) {
                menu->unk8 = 0;
                if (label != 0) {
                    if (label->visible == 0) {
                        label->visible = 1;
                    }
                    label->cell_col = 0;
                    label->cell_row = menu->item - 1;
                }
            } else {
                menu->unk8 = item_sprite;
                item_sprite->cell_col = 0;
                item_sprite->cell_row = 0;
                if (item_sprite->visible == 0) {
                    item_sprite->visible = 1;
                }
                menu->unk4 = 1;
                menu_anim_sprite = item_sprite;
            }
        }
        sound_se_play(0xF);
        break;
    case 1:
        if (menu->item == 1) {
            menu_list_page(menu, 2, up);
        } else if (menu->item == 2 && vars->unkBE != 0) {
            menu->row = mail_list_move(up, menu->row);
        } else if (menu->item == 3) {
            menu_options_page(menu, 1, up);
        }
        break;
    }
}

void menu_confirm(PauseMenu *menu) {
    GameVars_u8017EBF8 *vars = &action_vars;

    switch (menu->page) {
    case 0:
        menu->row = 0;
        menu->page = 1;
        sound_se_play(0x11);
        if (menu->item == 1) {
            object_load_res(0xD, -1);
            menu_list_page(menu, 0, 0);
        } else if (menu->item == 2) {
            if (vars->unkBE != 0) {
                object_load_res(8, -1);
                mail_list_open();
            }
            sprite_set_visible(0x20A, 1);
            sprite_set_visible(0x212, 1);
            sprite_set_visible(0x20C, 1);
        } else if (menu->item == 3) {
            menu_options_page(menu, 0, 0);
        } else if (menu->item == 4) {
            object_load_res(0xE, -1);
            menu_status_page(menu, 0);
        }
        break;
    case 1:
        if (menu->item == 1) {
            menu_list_page(menu, 1, 0);
            menu->page = 2;
        } else if (menu->item == 2 && vars->unkBE != 0) {
            sound_se_play(0x11);
            object_load_mail_by_id(menu->row);
            menu->page = 2;
        } else if (menu->item == 4) {
            menu_status_page(menu, 1);
        }
        break;
    }
}

void menu_back(PauseMenu *menu) {
    sound_se_play(8);
    switch (menu->page) {
    case 1:
        menu->page = 0;
        if (menu->item == 1) {
            sprite_delete(0x237);
            sprite_delete(0x238);
            sprite_delete(0x239);
        } else if (menu->item == 2) {
            mail_list_close();
            sprite_set_visible(0x20A, 0);
            sprite_set_visible(0x20C, 0);
            sprite_set_visible(0x212, 0);
        } else if (menu->item == 3) {
            sprite_set_visible(0x23D, 0);
        } else if (menu->item == 4) {
            sprite_delete(0x23A);
            sprite_delete(0x23B);
            sprite_delete(0x23C);
        }
        break;
    case 2:
        if (menu->item == 1) {
            menu->page = 1;
            sprite_set_visible(0x239, 0);
        } else if (menu->item == 2) {
            menu->page = 1;
            mail_free();
        }
        break;
    }
}

void menu_handle_input(PauseMenu *menu) {
    s32 pad;

    if (kaj_system.pad_mode != 1 || menu->unk4 != 0) {
        return;
    }
    pad = kaj_pad_read();
    if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
        menu_move_cursor(menu, 1);
    } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
        menu_move_cursor(menu, 0);
    } else if (!(kaj_system.pad_prev & 0x8000) && (kaj_system.pad_now & 0x8000)) {
        if (*(s32 *)menu == 0x10003) {
            menu_options_page(menu, 2, 1);
        }
    } else if (!(kaj_system.pad_prev & 0x2000) && (kaj_system.pad_now & 0x2000)) {
        if (*(s32 *)menu == 0x10003) {
            menu_options_page(menu, 2, 0);
        }
    } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
        if (menu->page == 0) {
            sound_se_play(8);
            mail_goto_ofc(1, 1, 0, 0);
            return;
        }
        menu_back(menu);
    } else if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20) && menu->item != 0) {
        menu_confirm(menu);
    }
    if (menu->page == 2 && menu->item == menu->page) {
        if (pad & 0x1000) {
            mail_scroll(0);
        } else if (pad & 0x4000) {
            mail_scroll(1);
        }
    }
}

void menu_animate(PauseMenu *menu) {
    if (menu_cycle_pos_a >= 0xA0) {
        menu_cycle_pos_a = 0x9F;
        menu_cycle_dir_a = 1 - menu_cycle_dir_a;
    } else if (menu_cycle_pos_a < 0x90) {
        menu_cycle_pos_a = 0x90;
        menu_cycle_dir_a = 1 - menu_cycle_dir_a;
    }
    if (menu_cycle_dir_a != 0) {
        sprite_set_clut_entry(0x208, menu_cycle_pos_a, 0x67B5);
        menu_cycle_pos_a++;
    } else {
        sprite_set_clut_entry(0x208, menu_cycle_pos_a, 0x38A2);
        menu_cycle_pos_a--;
    }
    if (rand() % 100 < 10) {
        menu_cycle_dir_a = 1 - menu_cycle_dir_a;
    }

    if (menu_cycle_pos_b >= 0xB0) {
        menu_cycle_pos_b = 0xAF;
        menu_cycle_dir_b = 1 - menu_cycle_dir_b;
    } else if (menu_cycle_pos_b < 0xA0) {
        menu_cycle_pos_b = 0xA0;
        menu_cycle_dir_b = 1 - menu_cycle_dir_b;
    }
    if (menu_cycle_dir_b != 0) {
        sprite_set_clut_entry(0x208, menu_cycle_pos_b, 0x2533);
        menu_cycle_pos_b++;
    } else {
        sprite_set_clut_entry(0x208, menu_cycle_pos_b, 0x4D44);
        menu_cycle_pos_b--;
    }
    if (rand() % 100 < 5) {
        menu_cycle_dir_b = 1 - menu_cycle_dir_b;
    }

    if (menu_cycle_pos_c >= 0xC0) {
        menu_cycle_pos_c = 0xBF;
        menu_cycle_dir_c = 1 - menu_cycle_dir_c;
    } else if (menu_cycle_pos_c < 0xB0) {
        menu_cycle_pos_c = 0xB0;
        menu_cycle_dir_c = 1 - menu_cycle_dir_c;
    }
    if (menu_cycle_dir_c != 0) {
        sprite_set_clut_entry(0x208, menu_cycle_pos_c, 0x67B5);
        menu_cycle_pos_c++;
    } else {
        sprite_set_clut_entry(0x208, menu_cycle_pos_c, 0x38A2);
        menu_cycle_pos_c--;
    }
    if (rand() % 100 < 15) {
        menu_cycle_dir_c = 1 - menu_cycle_dir_c;
    }

    if (menu->page == 0 && menu->unk8 != NULL && menu->unk4 != 0) {
        menu->unk8->cell_row++;
        if (menu->unk8->cell_row >= 4) {
            menu->unk8->cell_row = 3;
            menu->unk4 = 0;
            if (menu->unkC != NULL) {
                if (menu->unkC->visible == 0) {
                    menu->unkC->visible = 1;
                }
                menu->unkC->cell_col = 0;
                menu->unkC->cell_row = menu->item - 1;
                menu->unkC->y = menu->item * menu->unkC->cell_h + 0x48;
            }
        }
    }
}

void menu_run(void) {
    PauseMenu state;
    PauseMenu *menu;
    s32 ev[6];
    s16 done = 0;
    u16 i;

    sprite_set_visible(0x400, 0);
    sprite_set_visible(0x409, 0);
    sprite_set_visible(0x207, 1);
    sprite_fill_clut(0x207, 0xF0, 0xFE, 0);
    object_load_res(6, 1);
    sprite_set_visible(0x207, 0);
    sprite_set_visible(0x208, 1);
    sprite_set_visible(0x209, 1);
    sprite_set_visible(0x20B, 1);
    sprite_fill_clut(0x208, 0x90, 0x9F, 0x38A2);
    sprite_fill_clut(0x208, 0xA0, 0xAF, 0x4D44);
    sprite_fill_clut(0x208, 0xB0, 0xBF, 0x38A2);
    menu = &state;
    menu->item = 0;
    menu->page = 0;
    menu->unk4 = 0;
    menu->row = 0;
    menu->unk8 = NULL;
    menu->unkC = NULL;
    menu_anim_sprite = NULL;
    kaj_timer_enable();
    effect_start_fade(0, 3);
    sound_bgm_play(2);
    do {
        switch (kaj_event_get(ev)) {
        case 4:
            event_handle_tick(0);
            continue;
        case 0:
            menu_handle_input(&state);
            if ((s16)mail_take_scene_change() != 0) {
                effect_start_fade(1, 3);
            }
            break;
        case 0x100:
            done = event_handle_effect_done(ev);
            continue;
        default:
            kaj_event_done(ev);
            continue;
        }
        menu_animate(&state);
        roadmap_draw_frame(3);
    } while (done == 0);
    kaj_timer_disable();
    sound_bgm_stop();
    sprite_set_visible(0x400, 1);
    sprite_set_visible(0x409, 1);
    for (i = 0x207; i < 0x23E; i++) {
        sprite_delete(i);
    }
    menu_anim_sprite = NULL;
}

void text_draw_string(s32 str, s16 max_rows) {
    s16 rect[4];
    u16 buf[0x40];
    Unk_801A44B8 *window;
    u16 *dst;
    u16 *glyph;
    u8 *s;
    u8 c;
    s16 sjis;
    s32 row;
    s32 col;
    s32 i;
    s32 n;
    s32 j;

    window = sprite_find(text_window_sprite);
    if (window == NULL) {
        return;
    }
    row = 0;
    col = 0;
    rect[2] = 4;
    rect[0] = 0;
    rect[1] = 0;
    rect[3] = 16;
    n = strlen((char *)str);
    for (i = 0; i < n; ) {
        if (row >= max_rows) {
            return;
        }
        s = (u8 *)str + i;
        c = s[0];
        if ((s8)s[0] >= 0) {
            i++;
            switch (c) {
            case ' ':
                col++;
                break;
            case ',':
                col = 0;
                row++;
                break;
            default:
                text_color = c - '0';
                break;
            }
            continue;
        }
        dst = buf;
        sjis = (s[0] << 8) | s[1];
        rect[0] = window->tim->x + col * 4;
        rect[1] = window->tim->y + row * 16;
        glyph = Krom2RawAdd2(sjis);
        memset(dst, 0, 0x80);
        for (j = 0; j < 15; j++, glyph++) {
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 4;
                v = 0;
                for (k = 7, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 0;
                v = 0;
                for (k = 3, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 12;
                v = 0;
                for (k = 15, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 8;
                v = 0;
                for (k = 11, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
        }
        LoadImage2(rect, buf);
        col++;
        if (col >= 16) {
            col = 0;
            row++;
        }
        i += 2;
    }
}

static inline s16 func_80182860_inline(s16 flag) {
    EventState *event = &event_state;
    if (text_pos >= text_len) {
        if (flag) {
            text_release_cmd();
        }
        return -1;
    }
    if (text_col >= 16) {
        text_col = 0;
        text_row++;
    }
    if (text_row >= 3) {
        text_col = 0;
        if (flag) {
            event->state = 3;
            event->circle_flags = 8;
            sprite_set_visible(0x40A, 1);
        }
        return 1;
    }
    return 0;
}

s16 text_draw_next(s32 str, s32 prompt) {
    s16 rect[4];
    u16 buf[0x40];
    Unk_801A44B8 *window;
    u16 *dst;
    u16 *glyph;
    u8 *s;
    u8 c;
    s16 status;
    s32 j;

    window = sprite_find(text_window_sprite);
    if (window == NULL) {
        return 0;
    }
    rect[2] = 4;
    rect[0] = 0;
    rect[1] = 0;
    rect[3] = 16;
loop:
    status = func_80182860_inline(prompt);
    if (status < 0) {
        return 0;
    }
    if (status == 1) {
        return 1;
    }
    s = (u8 *)str + text_pos;
    c = s[0];
    if ((s8)s[0] >= 0) {
        text_pos++;
        switch (c) {
        case ' ':
            text_col++;
            break;
        case ',':
            text_col = 0;
            text_row++;
            break;
        default:
            text_color = c - '0';
            break;
        }
        goto loop;
    }
    dst = buf;
    glyph = Krom2RawAdd2((s[0] << 8) | s[1]);
    memset(dst, 0, 0x80);
    for (j = 0; j < 15; j++, glyph++) {
        {
            u16 v;
            u16 c;
            s32 k;
            s32 sh;
            s32 m;

            m = 4;
            v = 0;
            for (k = 7, sh = 0; k >= m; k--, sh += 4) {
                c = (dst[0] & (0xF << sh)) >> sh;
                if ((*glyph >> k) & 1) {
                    c = text_color;
                }
                v |= c << sh;
            }
            *dst++ = v;
        }
        {
            u16 v;
            u16 c;
            s32 k;
            s32 sh;
            s32 m;

            m = 0;
            v = 0;
            for (k = 3, sh = 0; k >= m; k--, sh += 4) {
                c = (dst[0] & (0xF << sh)) >> sh;
                if ((*glyph >> k) & 1) {
                    c = text_color;
                }
                v |= c << sh;
            }
            *dst++ = v;
        }
        {
            u16 v;
            u16 c;
            s32 k;
            s32 sh;
            s32 m;

            m = 12;
            v = 0;
            for (k = 15, sh = 0; k >= m; k--, sh += 4) {
                c = (dst[0] & (0xF << sh)) >> sh;
                if ((*glyph >> k) & 1) {
                    c = text_color;
                }
                v |= c << sh;
            }
            *dst++ = v;
        }
        {
            u16 v;
            u16 c;
            s32 k;
            s32 sh;
            s32 m;

            m = 8;
            v = 0;
            for (k = 11, sh = 0; k >= m; k--, sh += 4) {
                c = (dst[0] & (0xF << sh)) >> sh;
                if ((*glyph >> k) & 1) {
                    c = text_color;
                }
                v |= c << sh;
            }
            *dst++ = v;
        }
    }
    rect[0] = window->tim->x + text_col * 4;
    rect[1] = window->tim->y + text_row * 16;
    LoadImage2(rect, buf);
    text_col++;
    text_pos += 2;
    if ((s16)prompt) {
        if (func_80182860_inline(1) < 0) {
            return 0;
        }
    } else {
        if (func_80182860_inline(0) <= 0) {
            return 0;
        }
    }
    return 1;
}

void text_draw_line(char *str, s16 line_idx) {
    s16 rect[4];
    u16 buf[0x40];
    Unk_801A44B8 *window;
    u16 *dst;
    u16 *glyph;
    u8 *s;
    s16 sjis;
    s16 line;
    s32 y;
    s32 col;
    s32 i;
    s32 n;
    s32 j;

    line = line_idx;
    window = sprite_find(text_window_sprite);
    if (window == NULL) {
        return;
    }
    n = strlen(str);
    y = text_line_y[line_idx];
    if (line_idx < 2) {
        col = (32 - n) / 4;
    } else {
        col = 1;
    }
    i = 0;
    rect[2] = 4;
    rect[0] = 0;
    rect[1] = 0;
    rect[3] = 16;
    while (i < n) {
        s = (u8 *)str + i;
        if ((s8)s[0] >= 0) {
            i++;
            if (s[0] == ' ') {
                col++;
            }
            continue;
        }
        dst = buf;
        sjis = (s[0] << 8) | s[1];
        rect[0] = window->tim->x + col * 4;
        rect[1] = window->tim->y + y;
        glyph = Krom2RawAdd2(sjis);
        StoreImage2(rect, dst);
        for (j = 0; j < 15; j++, glyph++) {
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 4;
                v = 0;
                for (k = 7, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 0;
                v = 0;
                for (k = 3, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 12;
                v = 0;
                for (k = 15, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 8;
                v = 0;
                for (k = 11, sh = 0; k >= m; k--, sh += 4) {
                    c = (dst[0] & (0xF << sh)) >> sh;
                    if ((*glyph >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *dst++ = v;
            }
        }
        LoadImage2(rect, buf);
        col++;
        if (line >= 3 && col >= 15) {
            col = 1;
            line++;
            y = text_line_y[line];
        }
        i += 2;
    }
}

void text_format_number(u8 *out, u16 n) {
    u16 hundreds;
    u16 tens;
    u16 ones;

    memset(out, 0, 8);
    if (n == 0) {
        strncpy(out, D_801DFCBC, 2);
        return;
    }
    n %= 1000;
    hundreds = n / 100;
    n %= 100;
    tens = n / 10;
    ones = n % 10;
    if (hundreds == 0) {
        if (tens == 0) {
            out[0] = 0x82;
            out[1] = ones + 0x4F;
        } else {
            out[0] = 0x82;
            out[1] = tens + 0x4F;
            out[2] = 0x82;
            out[3] = ones + 0x4F;
        }
    } else {
        out[0] = 0x82;
        out[1] = hundreds + 0x4F;
        out[2] = 0x82;
        out[3] = tens + 0x4F;
        out[4] = 0x82;
        out[5] = ones + 0x4F;
    }
}

void text_show_timed(u16 arg0, s16 big, s32 str, s16 se, s32 seconds) {
    Rect rect;
    Unk_801A44B8 *window;
    s16 b;

    b = (arg0 == 1 || arg0 == 2);
    if (big != 0) {
        GameVars_u8017EBF8 *g = &action_vars;
        EventState *d = &event_state;
        s16 m = 3;

        if (m == 1) {
            text_window_sprite = 0x403;
            sprite_set_visible(0x403, 1);
            sprite_set_visible(0x404, 0);
            sprite_set_clut_entry(0x403, 3, 0x14BF);
        } else if (m == 3) {
            text_window_sprite = 0x404;
            sprite_set_visible(0x403, 0);
            sprite_set_visible(0x404, 1);
            sprite_set_clut_entry(0x404, 3, 0x14BF);
        }
        text_color = 1;
        d->circle_flags = 0;
        d->circle_set = -1;
        d->cross_flags = 0;
        d->cross_set = -1;
        window = sprite_find(text_window_sprite);
        if (window != NULL) {
            rect.x = window->tim->x;
            rect.y = window->tim->y;
            rect.w = window->tim->w;
            rect.h = window->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
        text_draw_string(str, m);
        if (se == 1) {
            sound_se_play(0xF);
        } else if (se == 2) {
            sound_se_play(6);
        } else if (se == 3) {
            sound_se_play(5);
        } else if (se == 4) {
            sound_se_play(0xE);
        }
        if (g->unk24E == 0) {
            g->unk24E = 1;
        }
    } else {
        GameVars_u8017EBF8 *g = &action_vars;
        EventState *d = &event_state;
        s16 m = 1;

        if (m == 1) {
            text_window_sprite = 0x403;
            sprite_set_visible(0x403, 1);
            sprite_set_visible(0x404, 0);
            sprite_set_clut_entry(0x403, 3, 0x14BF);
        } else if (m == 3) {
            text_window_sprite = 0x404;
            sprite_set_visible(0x403, 0);
            sprite_set_visible(0x404, 1);
            sprite_set_clut_entry(0x404, 3, 0x14BF);
        }
        text_color = 1;
        d->circle_flags = 0;
        d->circle_set = -1;
        d->cross_flags = 0;
        d->cross_set = -1;
        window = sprite_find(text_window_sprite);
        if (window != NULL) {
            rect.x = window->tim->x;
            rect.y = window->tim->y;
            rect.w = window->tim->w;
            rect.h = window->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
        text_draw_string(str, m);
        if (se == 1) {
            sound_se_play(0xF);
        } else if (se == 2) {
            sound_se_play(6);
        } else if (se == 3) {
            sound_se_play(5);
        } else if (se == 4) {
            sound_se_play(0xE);
        }
        if (g->unk24E == 0) {
            g->unk24E = 1;
        }
    }
    mail_wait(arg0, b, b, seconds);
}

void text_start_typing(s32 str) {
    GameVars_u8017EBF8 *vars = &action_vars;
    Rect rect;
    Unk_801A44B8 *window;

    text_window_sprite = 0x404;
    sprite_set_visible(0x403, 0);
    sprite_set_visible(0x404, 1);
    sprite_set_clut_entry(0x40A, 3, 0x14BF);
    text_color = 2;
    text_col = 0;
    text_row = 0;
    window = sprite_find(text_window_sprite);
    if (window != NULL) {
        rect.x = window->tim->x;
        rect.y = window->tim->y;
        rect.w = window->tim->w;
        rect.h = window->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    text_pos = 0;
    text_len = strlen((char *)str);
    if (text_draw_next(str, 1) != 0) {
        text_wait -= D_801E6DB4[0];
        if (text_wait > 0) {
            (*text_cmd)->state = 4;
        } else {
            text_wait = 0;
            (*text_cmd)->state = 3;
        }
        action_push_front(text_cmd);
    }
    if (vars->unk24E == 0) {
        vars->unk24E = 1;
    }
}

void text_show_profile(u16 npc_id) {
    GameVars_u8017EBF8 *vars = &action_vars;
    char buf[0x20];
    Rect rect;
    u8 height_str[8];
    u8 age_str[8];
    Npc *npc;
    NpcBody *body;
    Unk_801A44B8 *window;
    Rect *r;
    char *pb;
    s32 i;

    npc = npc_find(0, npc_id);
    if (npc == NULL) {
        return;
    }
    body = npc_find_body(npc->unk14);
    if (body == NULL) {
        return;
    }
    text_color = 9;
    text_window_sprite = 0x40D;
    r = &rect;
    window = sprite_find(0x40D);
    if (window != NULL) {
        rect.x = 0x300;
        r->y = 0x100;
        r->w = 0x40;
        r->h = 0x10;
        for (i = 0; i < 8; i++) {
            rect.y = 0x100 + i * 0x10;
            MoveImage2(&rect, (s16)window->tim->x, (s16)window->tim->y + text_line_y[i]);
        }
    }

    text_format_number(height_str, body->unk2);
    pb = (char *)age_str;
    text_format_number((u8 *)pb, body->unk6);
    pb = buf;
    memset(pb, 0, 0x20);
    /* "%s才 %s %sｃｍ %s" */
    sprintf(pb, "%s\215\313 %s %s\202\203\202\215 %s", age_str, text_sex_names[body->unk4], height_str, text_blood_types[body->unk8]);
    text_draw_line(body->unkC, 0);
    text_draw_line(body->unk2C, 1);
    text_draw_line(pb, 2);
    text_draw_line(body->unk4C, 3);
    sprite_set_visible(0x40D, 1);
    if (vars->unk24E == 0) {
        vars->unk24E = 1;
    }
}

static inline void func_801837F0_inl(s32 str, s16 mode, s16 circle_set, u16 circle_flags, s16 cross_set, u16 cross_flags, s16 se) {
    Rect rect;
    Unk_801A44B8 *window;
    GameVars_u8017EBF8 *g2 = &action_vars;
    EventState *event = &event_state;
    if (mode == 1) {
        text_window_sprite = 0x403;
        sprite_set_visible(0x403, 1);
        sprite_set_visible(0x404, 0);
        sprite_set_clut_entry(0x403, 3, 0x14BF);
    } else if (mode == 3) {
        text_window_sprite = 0x404;
        sprite_set_visible(0x403, 0);
        sprite_set_visible(0x404, 1);
        sprite_set_clut_entry(0x404, 3, 0x14BF);
    }
    text_color = 1;
    event->circle_flags = circle_flags;
    event->circle_set = circle_set;
    event->cross_flags = cross_flags;
    event->cross_set = cross_set;
    if (circle_flags != 0 || cross_flags != 0) {
        event->state = 2;
    }
    window = sprite_find(text_window_sprite);
    if (window != NULL) {
        rect.x = window->tim->x;
        rect.y = window->tim->y;
        rect.w = window->tim->w;
        rect.h = window->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    text_draw_string(str, mode);
    if (se == 1) {
        sound_se_play(0xF);
    } else if (se == 2) {
        sound_se_play(6);
    } else if (se == 3) {
        sound_se_play(5);
    } else if (se == 4) {
        sound_se_play(0xE);
    }
    if (g2->unk24E == 0) {
        g2->unk24E = 1;
    }
}

void text_exec_command(Unk_8018519C *action) {
    GameVars_u8017EBF8 *vars = &action_vars;
    Player *player = player_status_player[0];
    u16 state = action->unk0->unk2;
    Unk_801A44B8 *window;
    char **args;
    s16 circle_set;
    u16 circle_flags;
    s16 cross_set;
    u16 cross_flags;
    s16 se;
    s32 str;

    switch (state) {
    case 0:
        switch (vars->text_speed_setting) {
        case 2:
            text_wait = 20;
            break;
        case 1:
            text_wait = 10;
            break;
        case 0:
            text_wait = 5;
            break;
        }
        text_cmd = (TextCmd **)action;
        text_start_typing((s32)action->unk8[0]);
        break;
    case 1:
        if (D_801DFC5C != 0) {
            player->flags |= 0x100;
            D_801DFC5C = 0;
            text_show_timed(1, 0, (s32)action->unk8[0], atoi(action->unk8[5]), 2);
            player->flags &= 0xFEFF;
            text_release_cmd();
            sprite_set_visible(0x403, 0);
            sprite_set_visible(0x404, 0);
            sprite_set_visible(0x40A, 0);
            sprite_set_visible(0x40D, 0);
            if (vars->unk24E != 0) {
                vars->unk24E = 0;
            }
        } else {
            args = action->unk8;
            circle_set = atoi(args[1]);
            circle_flags = atoi(action->unk8[2]);
            cross_set = atoi(action->unk8[3]);
            cross_flags = atoi(action->unk8[4]);
            se = atoi(action->unk8[5]);
            func_801837F0_inl((s32)args[0], 1, circle_set, circle_flags, cross_set, cross_flags, se);
        }
        break;
    case 3:
        switch (vars->text_speed_setting) {
        case 2:
            text_wait = 20;
            break;
        case 1:
            text_wait = 10;
            break;
        case 0:
            text_wait = 5;
            break;
        }
        str = (s32)action->unk8[0];
        if (text_row == 3) {
            text_row = 0;
            window = sprite_find(text_window_sprite);
            if (window != NULL) {
                Rect rect;

                rect.x = window->tim->x;
                rect.y = window->tim->y;
                rect.w = window->tim->w;
                rect.h = window->tim->h;
                ClearImage2(&rect, 0, 0, 0);
            }
        }
        if (text_draw_next(str, 1) != 0) {
            text_wait -= D_801E6DB4[0];
            if (text_wait > 0) {
                (*text_cmd)->state = 4;
            } else {
                text_wait = 0;
                (*text_cmd)->state = 3;
            }
            action_push_front(text_cmd);
        }
        break;
    case 4:
        text_wait -= D_801E6DB4[0];
        if (text_wait > 0) {
            (*text_cmd)->state = 4;
        } else {
            (*text_cmd)->state = 3;
            text_wait = 0;
        }
        action_push_front(text_cmd);
        break;
    }
}

void text_start_narration(s32 str) {
    GameVars_u8017EBF8 *vars = &action_vars;
    Player *player = player_status_player[0];
    Rect rect;
    TssSlot *task;
    Unk_801A44B8 *window;

    task = kaj_tss_alloc(4);
    task->type = 8;
    task->cur = 0;
    task->target = strlen((char *)str);
    task->step = 1;
    task->delay = 0xA;
    task->on_step = text_narration_step;
    task->on_end = text_narration_end;
    task->on_kill = text_narration_end;
    sprite_set_visible(0x403, 0);
    sprite_set_visible(0x404, 1);
    sprite_set_clut_entry(0x40A, 3, 0x14BF);
    text_window_sprite = 0x404;
    text_color = 1;
    text_col = 0;
    text_row = 0;
    text_pos = 0;
    text_len = strlen((char *)str);
    window = sprite_find(text_window_sprite);
    if (window != NULL) {
        rect.x = window->tim->x;
        rect.y = window->tim->y;
        rect.w = window->tim->w;
        rect.h = window->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    *(s32 *)task->data = str;
    text_draw_next(str, 0);
    text_cue_fade_done = 0;
    text_cue_bgm_done = 0;
    player->flags |= 0x100;
    vars->unk248 = kaj_tss_start(task);
}

void text_show(s32 str, s16 mode, s16 circle_set, u16 circle_flags, s16 cross_set, u16 cross_flags, s16 se) {
    GameVars_u8017EBF8 *vars = &action_vars;
    EventState *event = &event_state;
    Rect rect;
    Unk_801A44B8 *window;

    if (mode == 1) {
        text_window_sprite = 0x403;
        sprite_set_visible(0x403, 1);
        sprite_set_visible(0x404, 0);
        sprite_set_clut_entry(0x403, 3, 0x14BF);
    } else if (mode == 3) {
        text_window_sprite = 0x404;
        sprite_set_visible(0x403, 0);
        sprite_set_visible(0x404, 1);
        sprite_set_clut_entry(0x404, 3, 0x14BF);
    }
    text_color = 1;
    event->circle_flags = circle_flags;
    event->circle_set = circle_set;
    event->cross_flags = cross_flags;
    event->cross_set = cross_set;
    if (circle_flags != 0 || cross_flags != 0) {
        event->state = 2;
    }
    window = sprite_find(text_window_sprite);
    if (window != NULL) {
        rect.x = window->tim->x;
        rect.y = window->tim->y;
        rect.w = window->tim->w;
        rect.h = window->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    text_draw_string(str, mode);
    if (se == 1) {
        sound_se_play(0xF);
    } else if (se == 2) {
        sound_se_play(6);
    } else if (se == 3) {
        sound_se_play(5);
    } else if (se == 4) {
        sound_se_play(0xE);
    }
    if (vars->unk24E == 0) {
        vars->unk24E = 1;
    }
}

void text_close(void) {
    GameVars_u8017EBF8 *vars = &action_vars;

    text_release_cmd();
    sprite_set_visible(0x403, 0);
    sprite_set_visible(0x404, 0);
    sprite_set_visible(0x40A, 0);
    sprite_set_visible(0x40D, 0);
    if (vars->unk24E != 0) {
        vars->unk24E = 0;
    }
}

void text_next_page(Unk_80184100 *event) {
    if (event->unk8 & 8) {
        event->unk8 &= ~8;
        event->unk6 = 1;
        sprite_set_visible(0x40A, 0);
        sprite_set_clut_entry(0x40A, 3, 0x14BF);
        sound_se_play(0x11);
    }
}

void text_release_cmd(void) {
    TextCmd *cmd;

    if (text_cmd != NULL) {
        cmd = *text_cmd;
        if (cmd->opcode == 5 && (u16)(cmd->state - 3) < 2) {
            cmd->state = 0;
        }
        text_cmd = NULL;
    }
    if (text_window_sprite >= 0) {
        text_window_sprite = -1;
    }
}

void text_wait_step(void) {
    text_wait -= D_801E6DB4[0];
    if (text_wait > 0) {
        (*text_cmd)->state = 4;
    } else {
        text_wait = 0;
        (*text_cmd)->state = 3;
    }
    action_push_front(text_cmd);
}

void text_type_step(s32 str) {
    Rect rect;
    Unk_801A44B8 *window;

    if (text_row == 3) {
        text_row = 0;
        window = sprite_find(text_window_sprite);
        if (window != NULL) {
            rect.x = window->tim->x;
            rect.y = window->tim->y;
            rect.w = window->tim->w;
            rect.h = window->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
    }
    if (text_draw_next(str, 1) != 0) {
        text_wait -= D_801E6DB4[0];
        if (text_wait > 0) {
            (*text_cmd)->state = 4;
        } else {
            text_wait = 0;
            (*text_cmd)->state = 3;
        }
        action_push_front(text_cmd);
    }
}

void text_narration_step(TssSlot *task) {
    Rect rect;
    Unk_801A44B8 *window;
    s32 str;

    if (D_801DFCE6 != 0) {
        D_801DFCE6 = 0;
        return;
    }
    str = *(s32 *)task->data;
    task->cur = text_pos;
    if (text_row == 3) {
        text_row = 0;
        window = sprite_find(text_window_sprite);
        if (window != NULL) {
            rect.x = window->tim->x;
            rect.y = window->tim->y;
            rect.w = window->tim->w;
            rect.h = window->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
    }
    D_801DFCE6 = text_draw_next(str, 0);
}

void text_narration_end(void) {
    s32 v = -1;
    text_window_sprite = v;
    player_status_player[0]->flags &= 0xFEFF;
    D_801E05B0[0] = v;
}

void text_narration_cues(s16 arg0) {
    if (D_801E05B0[0] < 0) {
        return;
    }
    if (arg0 == 0) {
        if (text_pos != 0x1AA) {
            if (text_pos != 0x21A) {
                return;
            }
            if (text_cue_bgm_done == 0) {
                sound_bgm_fade_out(3);
                text_cue_bgm_done = 1;
            }
            return;
        }
    } else if (text_pos != 0x182) {
        return;
    }
    if (text_cue_fade_done == 0) {
        effect_start_fade(0, 3);
        text_cue_fade_done = 1;
    }
}

void door_setup(Door *door) {
    Player *player = player_status_player[0];
    Unk_801844D4 *rec = door->record;
    SVector rot;

    door->id = rec->unk0;
    door->axis = rec->unk2;
    door->unk8 = rec->unk4;
    door->state = rec->unk8;
    door->pos_x = rec->unkC * 10;
    door->pos_y = rec->unk10 * 10;
    door->pos_z = rec->unk14 * 10;
    door->angle = rec->unk6;
    kaj_tmd_load(&door->tmd_objects, ((Unk_801844D4 *)door->record)->unk18, &door->coord_flg);
    GsInitCoordinate2(NULL, &door->coord_flg);
    door->coord_tx = door->pos_x - player->cell_x * 12500;
    door->coord_ty = door->pos_y + player->cell_y * 32000;
    door->coord_tz = door->pos_z - player->cell_z * 12500;
    rot.vx = 0;
    rot.vy = (door->angle << 12) / 360;
    rot.vz = 0;
    RotMatrix(&rot, door->coord_m);
    door->coord_flg = 0;
    door->block = (s32)block_find_at(door->pos_x, door->pos_y, door->pos_z);
    door->active = 1;
}

void door_refresh_all(void) {
    DoorList *list = door_list;
    Player *player = player_status_player[0];
    Door *door;
    SVector rot;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        door = list->cursor->data;
        if (door != NULL) {
            door->coord_tx = door->pos_x - player->cell_x * 12500;
            door->coord_ty = door->pos_y + player->cell_y * 32000;
            door->coord_tz = door->pos_z - player->cell_z * 12500;
            rot.vx = 0;
            rot.vy = (door->angle << 12) / 360;
            rot.vz = 0;
            RotMatrix(&rot, door->coord_m);
            door->coord_flg = 0;
            door->block = (s32)block_find_at(door->pos_x, door->pos_y, door->pos_z);
        }
        if (kaj_ll_at_tail((BlockList *)list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void door_move_x(DoorMove *door) {
    EventState *event;

    door->pos_x += D_801E6DB4[0] * door->speed;
    if (door->speed > 0) {
        if (door->pos_x >= door->move_to) {
            event = &event_state;
            if (door->state == 3) {
                if (door->auto_return != 0) {
                    door->state = 0;
                    door->auto_return = 0;
                    door->move_to = door->move_from;
                    door->pos_x = door->move_from;
                } else {
                    door->state = 1;
                    door->auto_return = 0;
                    door->pos_x = door->move_to;
                }
            } else if (door->state == 2) {
                door->state = 0;
                door->pos_x = door->move_to;
            }
            if (event->wait_flags & 4) {
                event->wait_flags &= ~4;
                if (event->wait_flags == 0) {
                    event->state = 1;
                }
            }
        }
    } else {
        if (door->move_to >= door->pos_x) {
            event = &event_state;
            if (door->state == 3) {
                if (door->auto_return != 0) {
                    door->state = 0;
                    door->auto_return = 0;
                    door->move_to = door->move_from;
                    door->pos_x = door->move_from;
                } else {
                    door->state = 1;
                    door->auto_return = 0;
                    door->pos_x = door->move_to;
                }
            } else if (door->state == 2) {
                door->state = 0;
                door->pos_x = door->move_to;
            }
            if (event->wait_flags & 4) {
                event->wait_flags &= ~4;
                if (event->wait_flags == 0) {
                    event->state = 1;
                }
            }
        }
    }
}

void door_move_y(DoorMove *door) {
    EventState *event;

    door->pos_y += D_801E6DB4[0] * door->speed;
    if (door->speed > 0) {
        if (door->pos_y >= door->move_to) {
            event = &event_state;
            if (door->state == 3) {
                if (door->auto_return != 0) {
                    door->state = 0;
                    door->auto_return = 0;
                    door->move_to = door->move_from;
                    door->pos_y = door->move_from;
                } else {
                    door->state = 1;
                    door->auto_return = 0;
                    door->pos_y = door->move_to;
                }
            } else if (door->state == 2) {
                door->state = 0;
                door->pos_y = door->move_to;
            }
            if (event->wait_flags & 4) {
                event->wait_flags &= ~4;
                if (event->wait_flags == 0) {
                    event->state = 1;
                }
            }
        }
    } else {
        if (door->move_to >= door->pos_y) {
            event = &event_state;
            if (door->state == 3) {
                if (door->auto_return != 0) {
                    door->state = 0;
                    door->auto_return = 0;
                    door->move_to = door->move_from;
                    door->pos_y = door->move_from;
                } else {
                    door->state = 1;
                    door->auto_return = 0;
                    door->pos_y = door->move_to;
                }
            } else if (door->state == 2) {
                door->state = 0;
                door->pos_y = door->move_to;
            }
            if (event->wait_flags & 4) {
                event->wait_flags &= ~4;
                if (event->wait_flags == 0) {
                    event->state = 1;
                }
            }
        }
    }
}

void door_move_z(DoorMove *door) {
    EventState *event;

    door->pos_z += D_801E6DB4[0] * door->speed;
    if (door->speed > 0) {
        if (door->pos_z >= door->move_to) {
            event = &event_state;
            if (door->state == 3) {
                if (door->auto_return != 0) {
                    door->state = 0;
                    door->auto_return = 0;
                    door->move_to = door->move_from;
                    door->pos_z = door->move_from;
                } else {
                    door->state = 1;
                    door->auto_return = 0;
                    door->pos_z = door->move_to;
                }
            } else if (door->state == 2) {
                door->state = 0;
                door->pos_z = door->move_to;
            }
            if (event->wait_flags & 4) {
                event->wait_flags &= ~4;
                if (event->wait_flags == 0) {
                    event->state = 1;
                }
            }
        }
    } else {
        if (door->move_to >= door->pos_z) {
            event = &event_state;
            if (door->state == 3) {
                if (door->auto_return != 0) {
                    door->state = 0;
                    door->auto_return = 0;
                    door->move_to = door->move_from;
                    door->pos_z = door->move_from;
                } else {
                    door->state = 1;
                    door->auto_return = 0;
                    door->pos_z = door->move_to;
                }
            } else if (door->state == 2) {
                door->state = 0;
                door->pos_z = door->move_to;
            }
            if (event->wait_flags & 4) {
                event->wait_flags &= ~4;
                if (event->wait_flags == 0) {
                    event->state = 1;
                }
            }
        }
    }
}

void door_move_angle(DoorMove *door) {
    EventState *event;

    door->angle += D_801E6DB4[0] * door->speed;
    if (door->speed > 0) {
        if (door->angle >= door->move_to) {
            event = &event_state;
            if (door->state == 3) {
                if (door->auto_return != 0) {
                    door->state = 0;
                    door->auto_return = 0;
                    door->move_to = door->move_from;
                    *(s32 *)&door->angle = door->move_from;
                } else {
                    door->state = 1;
                    door->auto_return = 0;
                    *(s32 *)&door->angle = door->move_to;
                }
            } else if (door->state == 2) {
                door->state = 0;
                *(s32 *)&door->angle = door->move_to;
            }
            if (event->wait_flags & 4) {
                event->wait_flags &= ~4;
                if (event->wait_flags == 0) {
                    event->state = 1;
                }
            }
        }
    } else {
        if (door->angle <= door->move_to) {
            event = &event_state;
            if (door->state == 3) {
                if (door->auto_return != 0) {
                    door->state = 0;
                    door->auto_return = 0;
                    door->move_to = door->move_from;
                    *(s32 *)&door->angle = door->move_from;
                } else {
                    door->state = 1;
                    door->auto_return = 0;
                    *(s32 *)&door->angle = door->move_to;
                }
            } else if (door->state == 2) {
                door->state = 0;
                *(s32 *)&door->angle = door->move_to;
            }
            if (event->wait_flags & 4) {
                event->wait_flags &= ~4;
                if (event->wait_flags == 0) {
                    event->state = 1;
                }
            }
        }
    }
}

void door_update_all(void) {
    DoorList *list = door_list;
    Player *player = player_status_player[0];
    DoorMove *door;
    SVector rot;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        door = (DoorMove *)list->cursor->data;
        if (door != NULL && door->active != 0 && door->visible != 0
            && (u16)(door->state - 2) < 2) {
            switch (door->axis) {
            case 1:
                door_move_x(door);
                break;
            case 2:
                door_move_y(door);
                break;
            case 3:
                door_move_z(door);
                break;
            default:
                door_move_angle(door);
                break;
            }
            door->coord_tx = door->pos_x - player->cell_x * 12500;
            door->coord_ty = door->pos_y + player->cell_y * 32000;
            door->coord_tz = door->pos_z - player->cell_z * 12500;
            rot.vx = 0;
            rot.vy = (door->angle << 12) / 360;
            rot.vz = 0;
            RotMatrix(&rot, door->coord_m);
            door->coord_flg = 0;
        }
        if (door->active != 0 && door->visible != 0 && D_801DFC80 != 0) {
            door->block = (s32)block_find_at(door->pos_x, door->pos_y, door->pos_z);
        }
        if (kaj_ll_at_tail((BlockList *)list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void door_start_open(DoorMove *door, s16 dist, s16 speed, s16 auto_return) {
    s16 step = speed;
    s32 w;
    s16 delta;

    D_801DFC74 = 1;
    door->state = 3;
    door->auto_return = auto_return;
    switch (door->axis) {
    case 1:
        step = speed * 10;
        door->move_from = door->pos_x;
        door->move_to = door->pos_x + dist * 10;
        break;
    case 2:
        step = speed * 10;
        door->move_from = door->pos_y;
        door->move_to = door->pos_y + dist * 10;
        break;
    case 3:
        step = speed * 10;
        door->move_from = door->pos_z;
        door->move_to = door->pos_z + dist * 10;
        break;
    default:
        door->move_from = door->angle;
        door->move_to = door->angle + dist;
        break;
    }
    delta = door->move_to - door->move_from;
    w = step;
    if (delta >= 0) {
        if (delta <= 0) {
            door->speed = 0;
        } else {
            door->speed = w;
        }
    } else {
        door->speed = -w;
    }
}

void door_start_close(DoorMove *door, s16 dist, s16 speed) {
    s16 step = speed;
    s32 w;
    s16 delta;

    D_801DFC74 = 1;
    door->state = 2;
    door->auto_return = 0;
    switch (door->axis) {
    case 1:
        step = speed * 10;
        door->move_from = door->pos_x;
        door->move_to = door->pos_x + dist * 10;
        break;
    case 2:
        step = speed * 10;
        door->move_from = door->pos_y;
        door->move_to = door->pos_y + dist * 10;
        break;
    case 3:
        step = speed * 10;
        door->move_from = door->pos_z;
        door->move_to = door->pos_z + dist * 10;
        break;
    default:
        door->move_from = door->angle;
        door->move_to = door->angle + dist;
        break;
    }
    delta = door->move_to - door->move_from;
    w = step;
    if (delta >= 0) {
        if (delta <= 0) {
            door->speed = 0;
        } else {
            door->speed = w;
        }
    } else {
        door->speed = -w;
    }
}

void door_exec_command(Unk_8018519C *action, EventState *event) {
    DoorList *list = door_list;
    Unk_8018519C_0 *cmd = action->unk0;
    DoorMove *door;
    DoorMove *found;
    u16 id = cmd->unk4;
    s32 dist;
    s32 speed;

    if (list->count == 0) {
        found = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            door = (DoorMove *)list->cursor->data;
            if (door != NULL && door->id == id) {
                found = door;
                break;
            }
            if (kaj_ll_at_tail((BlockList *)list) != 0) {
                found = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (found != NULL) {
        if (cmd->unk2 == 0) {
            if (found->state != 1) {
                dist = (s16)atoi(action->unk8[0]);
                speed = (s16)atoi(action->unk8[1]);
                door_start_open(found, dist, speed, atoi(action->unk8[2]));
                if (atoi(action->unk8[3]) == 1) {
                    event->state = 4;
                    event->wait_flags |= 4;
                }
            }
        } else {
            if (found->state != 0) {
                s32 close_dist = (s16)atoi(action->unk8[0]);
                door_start_close(found, close_dist, atoi(action->unk8[1]));
                if (atoi(action->unk8[2]) == 1) {
                    event->state = 4;
                    event->wait_flags |= 4;
                }
            }
        }
    }
}
