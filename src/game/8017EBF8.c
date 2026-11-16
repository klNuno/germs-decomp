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

void menu_card_init_slots(Unk_801802A0 *arg0, s32 arg1) {
    Rect rect;
    void *buf;
    Unk_801802A0_14 *p;
    s32 i;

    p = arg0->unk14;
    arg0->unk6 = 0;
    arg0->unk8 = -1;
    for (i = 0; i < 4; i++, p++) {
        memset(p->unk4, 0, 0x14);
        sprintf(p->unk4, "BISLPS-02107GERMS%d", i);
        p->unk0 = 0;
        p->unk18 = 'S';
        p->unk19 = 'C';
        p->unk1A = 0x11;
        p->unk1B = 1;
        memset(p->unk1C, 0, 0x40);
        memset(p->unk5C, 0, 0x1C);
        p->unk78 = menu_card_icon_clut;
    }
    sprite_fill_clut(0x200, 4, 7, 0xC252);
    sprite_fill_clut(0x200, 9, 0xC, 0xC252);
    if ((s16)arg1 != 0) {
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

void menu_card_set_message(Unk_801802A0 *arg0, s32 arg1) {
    s32 s;

    if (arg1 < 0x64) {
        switch (arg1) {
        case 0:
            return;
        case 1:
            menu_card_init_slots(arg0, 1);
            arg0->unkC = 0x66;
            break;
        case 2:
            menu_card_init_slots(arg0, 1);
            arg0->unkC = 0x67;
            break;
        case 3:
            arg0->unkC = -1;
            arg0->unk10 = 0;
            return;
        case 4:
            arg0->unkC = 0x69;
            break;
        case 5:
            if (arg0->unk0 != 0) {
                arg0->unkC = 0x66;
                arg0->unk10 = 0;
            } else {
                arg0->unkC = -1;
                arg0->unk10 = 0xD;
            }
            return;
        case 6:
            arg0->unkC = 0x6B;
            break;
        case 7:
            arg0->unkC = 0x6A;
            break;
        default:
            arg0->unkC = -1;
            return;
        }
    } else {
        arg0->unkC = arg1;
    }
    switch (arg0->unkC) {
    case 0x64:
        s = 1;
        break;
    case 0x65:
        s = 0;
        break;
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x6A:
        s = 2;
        sound_se_play(0xE);
        break;
    case 0x69:
        s = 3;
        if (arg0->unk0 == 0) {
            s = 1;
        }
        sound_se_play(0xE);
        break;
    case 0x6B:
        s = 1;
        sound_se_play(0xE);
        break;
    default:
        return;
    }
    sprite_set_visible(0x202, 1);
    sprite_set_visible(0x203, 1);
    sprite_set_cell(0x202, (s16)((arg0->unkC - 0x64) / 4), (s16)((arg0->unkC - 0x64) % 4));
    sprite_set_cell(0x203, 0, s);
}

static inline s32 func_8017EFEC_inline(u8 *sec, s32 block) {
    s32 cmd;
    s32 result;
    for (;;) {
        switch (MemCardSync(1, &cmd, &result)) {
        case 0:
            continue;
        case -1:
            MemCardReadData(sec, block << 7, 0x80);
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

s32 menu_card_load(Unk_801802A0 *arg0) {
    Unk_8017EFEC buf;
    u8 sec[0x80];
    PlayerStatus *h = &player_status;
    GameVars_u8017EBF8 *g = &action_vars;
    s16 *c = &g->car_speed_setting;
    Inventory *a = h->inventory;
    Unk_801E0710_5C *b = h->player;
    Unk_801802A0_14 *e;
    s32 ret;
    s32 i;

    e = &arg0->unk14[arg0->unk8];
    menu_card_set_message(arg0, 0x65);
    roadmap_draw_frame(3);
    ret = MemCardOpen(0, e->unk4, 1);
    if (ret != 0) {
        return ret;
    }
    memset(&buf, 0, sizeof(buf));
    for (i = 0; i < 4; i++) {
        memset(sec, 0, 0x80);
        ret = func_8017EFEC_inline(sec, i * 2 + 2);
        if (ret != 0) {
            goto error;
        }
        if (func_8017EFEC_inline2(sec)) {
            memcpy((u8 *)&buf + i * 0x7F, sec, 0x7F);
        } else {
            memset(sec, 0, 0x80);
            ret = func_8017EFEC_inline(sec, i * 2 + 3);
            if (ret != 0) {
                goto error;
            }
            if (func_8017EFEC_inline2(sec)) {
                memcpy((u8 *)&buf + i * 0x7F, sec, 0x7F);
            } else {
                ret = 0x68;
                goto error;
            }
        }
    }
    MemCardClose();
    arg0->unk2 = 1;
    memcpy(g, buf.unk2, sizeof(buf.unk2));
    memcpy(c, buf.unk102, sizeof(buf.unk102));
    memcpy(h, buf.unk106, sizeof(buf.unk106));
    memcpy(a, buf.unk154, sizeof(buf.unk154));
    memcpy(b, buf.unk198, sizeof(buf.unk198));
    g->drain_count = 0;
    g->drain_minute = g->unk0[0x3F] % 10;
    if (buf.unk0 != 0) {
        mail_goto_ofc(1, 1, 1, 0);
    } else {
        mail_goto_twn(b->unk1C, b->unk20, b->unk24, b->unk38, 0);
    }
    return 0x6C;
error:
    MemCardClose();
    return ret;
}

static inline s32 func_8017F6F4_inline(void *sec, s32 block) {
    s32 cmd;
    s32 result;
    for (;;) {
        switch (MemCardSync(1, &cmd, &result)) {
        case 0:
            continue;
        case -1:
            MemCardWriteData(sec, block << 7, 0x80);
            continue;
        case 1:
            if (cmd == 6) {
                return result;
            }
            continue;
        }
    }
}

static inline void func_8017F6F4_digits(char *s, s32 n) {
    s[0] = s[2] = 0x82;
    s[1] = n / 10 + 0x4F;
    s[3] = n % 10 + 0x4F;
    s[4] = 0;
}

s32 menu_card_save(Unk_801802A0 *arg0, s32 arg1) {
    Unk_8017EFEC buf;
    u8 sec[0x80];
    char s0[8];
    char s1[8];
    char s2[8];
    char s3[8];
    PlayerStatus *h = &player_status;
    GameVars_u8017EBF8 *g = &action_vars;
    s16 *c = &g->car_speed_setting;
    Inventory *a = h->inventory;
    Unk_801E0710_5C *b = h->player;
    Unk_801802A0_14 *e;
    u8 *hdr;
    u8 *p;
    u8 sum;
    s32 ret;
    s32 i;
    s32 j;

    e = &arg0->unk14[arg0->unk8];
    hdr = &e->unk18;
    if (e->unk0 != 0) {
        if ((s16)arg1 == 0) {
            return 0x6B;
        }
    } else {
        ret = MemCardCreateFile(0, e->unk4, 1);
        if (ret != 0) {
            return ret;
        }
    }
    menu_card_set_message(arg0, 0x65);
    roadmap_draw_frame(3);
    ret = MemCardOpen(0, e->unk4, 2);
    if (ret != 0) {
        return ret;
    }
    func_8017F6F4_digits(s0, g->unk0[0x3D] + 1);
    func_8017F6F4_digits(s1, g->unk0[0x3E]);
    func_8017F6F4_digits(s2, g->unk0[0x3F]);
    func_8017F6F4_digits(s3, arg0->unk8 + 1);
    memset(hdr + 4, 0, 0x40);
    /* ジャーム／第%s日／%s時%s分／記録%s */
    sprintf(hdr + 4, menu_str_save_title, s0, s1, s2, s3);
    memset(&buf, 0, sizeof(buf));
    memcpy(buf.unk2, g, sizeof(buf.unk2));
    memcpy(buf.unk102, c, sizeof(buf.unk102));
    memcpy(buf.unk106, h, sizeof(buf.unk106));
    memcpy(buf.unk154, a, sizeof(buf.unk154));
    memcpy(buf.unk198, b, sizeof(buf.unk198));
    buf.unk0 = arg0->unk4;
    if (func_8017F6F4_inline(hdr, 0) != 0) {
        goto error;
    }
    if (func_8017F6F4_inline(menu_card_icon_image, 1) != 0) {
        goto error;
    }
    for (i = 0; i < 4; i++) {
        memset(sec, 0, 0x80);
        memcpy(sec, (u8 *)&buf + i * 0x7F, 0x7F);
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
    if (e->unk0 == 0) {
        MemCardDeleteFile(0, e->unk4);
    }
    return 0x68;
}

s32 menu_card_scan(Unk_801802A0 *arg0) {
    Unk_8017FF0C dir[15];
    s32 count;
    s32 cmd;
    s32 result;
    s32 first;
    s32 ret;
    s32 blocks;
    s32 found;
    s32 i;
    s32 j;
    s32 n;
    s32 y;
    s32 m;
    u8 *rr;
    u8 *r2;
    u8 *r3;
    u8 *q;
    u8 *t;
    Unk_801802A0_14 *p;

    ret = MemCardGetDirentry(0, D_801DFC90, dir, &count, 0, 15);
    if (ret != 0) {
        return ret;
    }
    if (arg0->unk0 != 0 && count == 0) {
        return 0x6A;
    }
    blocks = 0;
    found = 0;
    first = 4;
    cmd = 0;
    result = 0;
    for (i = 0; i < count; i++) {
        n = dir[i].unk18 / 0x2000;
        if (dir[i].unk18 & 0x1FFF) {
            blocks += n + 1;
        } else {
            blocks += n;
        }
        p = arg0->unk14;
        for (j = 0; j < 4; j++, p++) {
            if (strncmp(dir[i].unk0, p->unk4, 0x12) == 0) {
                p->unk0 = 1;
                found++;
                if (j < first) {
                    first = j;
                }
            }
        }
    }
    if (found == 0) {
        first = 0;
    }
    if (arg0->unk0 != 0) {
        if (found == 0) {
            return 0x6A;
        }
    } else if (found == 0 && blocks == 15) {
        return 0x6A;
    }
    sprite_fill_clut(0x200, 4, 7, 0xC252);
    p = arg0->unk14;
    for (i = 0; i < 4; i++, p++) {
        q = &p->unk18;
        if (p->unk0 != 0) {
            for (;;) {
                switch (MemCardSync(1, &cmd, &result)) {
                case 0:
                    continue;
                case -1:
                    MemCardReadFile(0, p->unk4, q, 0, 0x80);
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
            t = q + 4;
            y = i * 32 + 0xF;
            for (m = 0; m < 2; m++) {
                rr = (u8 *)(m * 2 + (s32)t);
                rr += 0xD;
                sprite_copy_cell(0x204, (u16)(*rr - 0x4F), 0, 0x200, (u16)(m * 8 + 0x21), (u16)y);
                r2 = (u8 *)(m * 2 + (s32)t);
                r2 += 0x15;
                sprite_copy_cell(0x204, (u16)(*r2 - 0x4F), 0, 0x200, (u16)(m * 8 + 0x44), (u16)y);
                r3 = (u8 *)(m * 2 + (s32)t);
                r3 += 0x1B;
                sprite_copy_cell(0x204, (u16)(*r3 - 0x4F), 0, 0x200, (u16)(m * 8 + 0x62), (u16)y);
            }
        }
    }
    arg0->unk8 = first;
    sprite_fill_clut(0x200, 9, 0xC, 0xC252);
    sprite_set_clut_entry(0x200, first + 9, 0x3FF);
    return 0x64;
}

void menu_card_move_cursor(Unk_801802A0 *arg0, s16 arg1) {
    s32 i;
    s32 a;

    if (arg1 != 0) {
        i = arg0->unk8 - 1;
        if (i < 0) {
            i = 3;
        }
    } else {
        i = arg0->unk8 + 1;
        if (i >= 4) {
            i = 0;
        }
    }
    if (arg0->unk0 != 0) {
loop:
        if (arg0->unk14[i].unk0 == 0) {
            if (arg1 != 0) {
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
    arg0->unk8 = i;
    sprite_fill_clut(0x200, 9, 0xC, 0xC252);
    sprite_set_clut_entry(0x200, i + 9, 0x3FF);
    a = 1;
    if (arg0->unk0 == 0) {
        a = 0xF;
    }
    sound_se_play(a);
}

s16 menu_card_handle_input(Unk_801802A0 *arg0) {
    s32 cmd;
    s32 result;
    s32 ok;
    s32 ret;
    s32 snd;
    SceneRequest *g;

    g = &scene_request;
    if (D_801E6DAA[0] != 1 || arg0->unkC == 0x65 || arg0->unkC == 0x6C) {
        return 0;
    }
    if (arg0->unkC == -1) {
        return 1;
    }
    if (arg0->unkC == 0x66 || arg0->unkC == 0x67) {
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
                    arg0->unkC = -1;
                    arg0->unk10 = 0;
                case 1:
                case 2:
                    menu_card_set_message(arg0, result);
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
        ret = 0;
        kaj_pad_read();
        if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
            ret = 1;
            snd = 0x11;
            switch (arg0->unkC) {
            case 0x64:
            case 0x68:
                if (arg0->unk0 != 0) {
                    arg0->unk10 = 0xC;
                    snd = 2;
                } else {
                    arg0->unk10 = 0xD;
                }
                arg0->unkC = -1;
                break;
            case 0x69:
                if (arg0->unk0 != 0) {
                    break;
                }
                arg0->unk10 = 0xA;
                arg0->unkC = -1;
                break;
            case 0x66:
            case 0x67:
                arg0->unk10 = 0;
                arg0->unkC = -1;
                break;
            case 0x6A:
                if (arg0->unk0 != 0) {
                    arg0->unk10 = 0;
                }
                arg0->unkC = -1;
                break;
            case 0x6B:
                arg0->unk10 = 0xE;
                arg0->unkC = -1;
                break;
            default:
                ret = 0;
                break;
            }
        } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            if (arg0->unkC == 0x6B || (arg0->unk0 == 0 && arg0->unkC == 0x6A)) {
                ret = 1;
                snd = 8;
                menu_card_set_message(arg0, 0x64);
            } else {
                sound_se_play(8);
                mail_wait(3, 0, 0, 1);
                g->change = 1;
            }
        } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
            if (arg0->unkC == 0x64) {
                menu_card_move_cursor(arg0, 1);
            }
        } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
            if (arg0->unkC == 0x64) {
                menu_card_move_cursor(arg0, 0);
            }
        }
        ok = ret;
    }
    if (ok) {
        sound_se_play(snd);
    }
    return 0;
}

void menu_card_process(Unk_801802A0 *arg0) {
    s32 sp10;
    s32 sp14;
    s32 r;
    s32 a;

    switch (MemCardSync(1, &sp10, &sp14)) {
    case 0:
        break;
    case -1:
        switch (arg0->unk10) {
        case 0:
            MemCardExist(0);
            break;
        case 10:
            r = MemCardFormat(0);
            if (r == 0) {
                arg0->unk10 = 0xB;
                arg0->unkC = -1;
            } else {
                menu_card_set_message(arg0, r);
            }
            break;
        case 11:
            menu_card_set_message(arg0, menu_card_scan(arg0));
            break;
        case 12:
            menu_card_set_message(arg0, menu_card_load(arg0));
            break;
        case 13:
            menu_card_set_message(arg0, menu_card_save(arg0, 0));
            break;
        case 14:
            menu_card_set_message(arg0, menu_card_save(arg0, 1));
            break;
        }
        break;
    case 1:
        a = sp10;
        switch (a) {
        case 1:
            if (sp14 == 0) {
                arg0->unk10 = 0xB;
                arg0->unk6 = a;
                arg0->unkC = -1;
            } else if (sp14 == 3) {
                arg0->unk6 = a;
                MemCardAccept(0);
            } else {
                menu_card_set_message(arg0, sp14);
            }
            break;
        case 2:
            if (sp14 == 0 || sp14 == 3) {
                arg0->unk10 = 0xB;
                arg0->unkC = -1;
            } else {
                menu_card_set_message(arg0, sp14);
            }
            break;
        }
        break;
    }
}

s16 menu_card_run(s16 arg0, s16 arg1) {
    s32 buf[6];
    Unk_801802A0 *p;
    s16 done = 0;
    s16 r;
    s32 i;

    p = &menu_card_state;
    if (arg0 != 0) {
        object_load_res(4, -1);
    } else {
        object_load_res(5, -1);
    }
    sprite_set_visible(0x200, 1);
    sprite_set_visible(0x202, 1);
    sprite_set_visible(0x203, 1);
    p->unk0 = arg0;
    p->unk2 = 0;
    p->unk4 = arg1;
    p->unkC = -1;
    p->unk10 = 0;
    menu_card_init_slots(p, 0);
    MemCardStart();
    kaj_timer_enable();
    kaj_pad_reset(1);
    while (done == 0) {
        switch (kaj_event_get(buf)) {
        case 0:
            r = menu_card_handle_input(p);
            if ((s16)mail_take_scene_change() != 0) {
                if (arg1 != 0 || (p->unk2 != 0 && arg0 != 0)) {
                    effect_start_fade(1, 3);
                } else {
                    kaj_pad_reset(0);
                    done = 1;
                }
            }
            break;
        case 0x100:
            done = event_handle_effect_done(buf);
            continue;
        default:
            kaj_event_done(buf);
            continue;
        }
        if (r != 0) {
            menu_card_process(p);
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
    return p->unk2;
}

void menu_list_page(PauseMenu *arg0, s32 arg1, s32 arg2) {
    GameVars_u8017EBF8 *g = &action_vars;
    Rect rect;

    switch ((s16)arg1) {
    case 0:
        sprite_set_visible(0x237, 1);
        sprite_set_visible(0x238, 1);
        break;
    case 1:
        sound_se_play(0x11);
        sprite_set_visible(0x239, 1);
        rect.x = 0x3C0;
        rect.y = arg0->row * 0x40;
        rect.w = 0x2C;
        rect.h = 0x40;
        MoveImage2(&rect, 0x300, 0x100);
        sprite_fill_clut(0x239, 2, 5, 0x421);
        switch (g->unk0[menu_list_vars[arg0->row]]) {
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
        if ((s16)arg2 != 0) {
            if (--arg0->row < 0) {
                arg0->row = 7;
            }
        } else {
            if (++arg0->row >= 8) {
                arg0->row = 0;
            }
        }
        break;
    }
    sprite_set_cell(0x238, 0, arg0->row);
    sprite_fill_clut(0x237, 1, 8, 0x10C);
    sprite_set_clut_entry(0x237, arg0->row + 1, 0x23F);
}

void menu_status_page(PauseMenu *arg0, s32 arg1) {
    PlayerStatus *g = &player_status;
    GameVars_u8017EBF8 *h = &action_vars;
    Inventory *p = g->inventory;
    Unk_80188FEC *e;
    s32 n;
    s32 j;
    s32 i;
    s32 id;
    s32 col;
    s32 k;
    s32 m;
    s32 c;

    if ((s16)arg1 != 0) {
        sound_se_play(0x11);
        arg0->row = 1 - arg0->row;
        if (arg0->row != 0) {
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
    n = g->exp / 6329;
    if (n == 0 && g->exp != 0) {
        n = 1;
    }
    if (n > 32) {
        n = 32;
    }
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23A, j + 0x10, (u16)col);
        }
    }
    n = (g->level << 5) / 50 + 1;
    if (n > 32) {
        n = 32;
    }
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23A, j + 0x30, (u16)col);
        }
    }
    n = (g->exp << 4) / g->next_exp;
    if (n == 0 && g->exp != 0) {
        n = 1;
    }
    if (n > 16) {
        n = 16;
    }
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23A, j + 0x50, (u16)col);
        }
    }
    col = 0xB4;
    n = g->unk32 > 16 ? 16 : g->unk32;
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23A, j + 0x60, (u16)col);
        }
    }
    col = 0x3D40;
    n = g->hours_awake > 32 ? 32 : g->hours_awake;
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23A, j + 0x70, (u16)col);
        }
    }
    n = (g->defense_level << 4) / 100 + 1;
    if (n > 16) {
        n = 16;
    }
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23A, j + 0x90, (u16)col);
        }
    }
    n = (h->unk0[0x5A] + 15) / 16;
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23A, j + 0xA0, (u16)col);
        }
    }
    n = (h->unk0[0x5D] + 15) / 16;
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23A, j + 0xB0, (u16)col);
        }
    }
    n = (h->unk0[0x5B] + 15) / 16;
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23A, j + 0xC0, (u16)col);
        }
    }
    n = (h->unk0[0x5C] + 15) / 16;
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23A, j + 0xD0, (u16)col);
        }
    }
    c = (h->unk0[0x5E] + 15) / 16;
    if (c != 0) {
        for (j = 0; j < c; j++) {
            sprite_set_clut_entry(0x23A, j + 0xE0, (u16)col);
        }
    }
    col = 0x3D40;
    n = (g->weapon0_level << 4) / 100 + 1;
    if (n > 16) {
        n = 16;
    }
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23B, j + 0x10, (u16)col);
        }
    }
    n = (g->weapon1_level << 4) / 100 + 1;
    if (n > 16) {
        n = 16;
    }
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23B, j + 0x20, (u16)col);
        }
    }
    n = (g->weapon2_level << 4) / 100 + 1;
    if (n > 16) {
        n = 16;
    }
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23B, j + 0x30, (u16)col);
        }
    }
    n = (g->weapon3_level << 4) / 100 + 1;
    if (n > 16) {
        n = 16;
    }
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23B, j + 0x40, (u16)col);
        }
    }
    n = (g->weapon4_level << 4) / 100 + 1;
    if (n > 16) {
        n = 16;
    }
    if (n != 0) {
        for (j = 0; j < n; j++) {
            sprite_set_clut_entry(0x23B, j + 0x50, (u16)col);
        }
    }
    for (i = 0; i < 2; i++) {
        id = p->weapon_ids[i];
        if (id >= 0) {
            e = effect_weapon_find(id);
            if (e != NULL) {
                sprite_set_clut_entry(0x23B, (i * 16 + 0x60) + e->unk2, 0x154);
                n = (e->unk30 << 5) / 50 + 1;
                if (n > 32) {
                    n = 32;
                }
                k = i * 32 + 0x80;
                if (n != 0) {
                    for (j = 0; j < n; j++) {
                        sprite_set_clut_entry(0x23B, k + j, (u16)col);
                    }
                }
                n = (e->unk50 << 12) / 25600;
                m = i * 16 + 0xC0;
                if (n != 0) {
                    for (j = 0; j < n; j++) {
                        sprite_set_clut_entry(0x23B, m + j, (u16)col);
                    }
                }
                sprite_copy_cell(0x23C, (u16)(id / 9), (u16)(id % 9), 0x23B, 0x21, (u16)(i * 42 + 0x53));
            }
        }
    }
}

void menu_options_page(PauseMenu *arg0, s32 arg1, s16 arg2) {
    GameVars_u8017EBF8 *g = &action_vars;
    s16 s = 1;

    switch (arg1) {
    case 0:
        s = 0;
        sprite_set_visible(0x23D, 1);
        break;
    case 1:
        arg0->row = 1 - arg0->row;
        break;
    case 2:
        if (arg0->row != 0) {
            if (arg2 != 0) {
                g->car_speed_setting--;
                if (g->car_speed_setting < 0) {
                    g->car_speed_setting = 2;
                }
            } else {
                g->car_speed_setting++;
                if (g->car_speed_setting >= 3) {
                    g->car_speed_setting = 0;
                }
            }
        } else {
            if (arg2 != 0) {
                g->text_speed_setting--;
                if (g->text_speed_setting < 0) {
                    g->text_speed_setting = 2;
                }
            } else {
                g->text_speed_setting++;
                if (g->text_speed_setting >= 3) {
                    g->text_speed_setting = 0;
                }
            }
        }
        break;
    }
    sprite_fill_clut(0x23D, 7, 8, 0x4250);
    sprite_set_clut_entry(0x23D, arg0->row + 7, 0x5140);
    sprite_fill_clut(0x23D, 9, 0xE, 0x421);
    sprite_set_clut_entry(0x23D, g->text_speed_setting + 9, 0x154);
    sprite_set_clut_entry(0x23D, g->car_speed_setting + 0xC, 0x154);
    if (s != 0) {
        sound_se_play(0xF);
    }
}

void menu_move_cursor(PauseMenu *arg0, s16 arg1) {
    GameVars_u8017EBF8 *g = &action_vars;
    Unk_801A44B8 *a;
    Unk_801A44B8 *b;
    Unk_801A44B8 *c;

    switch (arg0->page) {
    case 0:
        if (arg0->unk4 != 0) {
            break;
        }
        if (arg1 != 0) {
            if (--arg0->item < 0) {
                arg0->item = 4;
            }
        } else {
            if (++arg0->item >= 5) {
                arg0->item = 0;
            }
        }
        a = sprite_find(0x20B);
        b = sprite_find(0x211);
        if (a != 0) {
            a->y = (arg0->item << 4) + 0x48;
        }
        if (b != 0 && b->visible != 0) {
            b->visible = 0;
        }
        if (menu_anim_sprite != 0) {
            menu_anim_sprite->visible = 0;
        }
        if (arg0->item == 0) {
            arg0->unk8 = 0;
            arg0->unkC = 0;
            menu_anim_sprite = 0;
        } else {
            arg0->unkC = b;
            c = sprite_find(arg0->item + 0x20C);
            if (c == 0) {
                arg0->unk8 = 0;
                if (b != 0) {
                    if (b->visible == 0) {
                        b->visible = 1;
                    }
                    b->cell_col = 0;
                    b->cell_row = arg0->item - 1;
                }
            } else {
                arg0->unk8 = c;
                c->cell_col = 0;
                c->cell_row = 0;
                if (c->visible == 0) {
                    c->visible = 1;
                }
                arg0->unk4 = 1;
                menu_anim_sprite = c;
            }
        }
        sound_se_play(0xF);
        break;
    case 1:
        if (arg0->item == 1) {
            menu_list_page(arg0, 2, arg1);
        } else if (arg0->item == 2 && g->unkBE != 0) {
            arg0->row = mail_list_move(arg1, arg0->row);
        } else if (arg0->item == 3) {
            menu_options_page(arg0, 1, arg1);
        }
        break;
    }
}

void menu_confirm(PauseMenu *arg0) {
    GameVars_u8017EBF8 *g = &action_vars;

    switch (arg0->page) {
    case 0:
        arg0->row = 0;
        arg0->page = 1;
        sound_se_play(0x11);
        if (arg0->item == 1) {
            object_load_res(0xD, -1);
            menu_list_page(arg0, 0, 0);
        } else if (arg0->item == 2) {
            if (g->unkBE != 0) {
                object_load_res(8, -1);
                mail_list_open();
            }
            sprite_set_visible(0x20A, 1);
            sprite_set_visible(0x212, 1);
            sprite_set_visible(0x20C, 1);
        } else if (arg0->item == 3) {
            menu_options_page(arg0, 0, 0);
        } else if (arg0->item == 4) {
            object_load_res(0xE, -1);
            menu_status_page(arg0, 0);
        }
        break;
    case 1:
        if (arg0->item == 1) {
            menu_list_page(arg0, 1, 0);
            arg0->page = 2;
        } else if (arg0->item == 2 && g->unkBE != 0) {
            sound_se_play(0x11);
            object_load_mail_by_id(arg0->row);
            arg0->page = 2;
        } else if (arg0->item == 4) {
            menu_status_page(arg0, 1);
        }
        break;
    }
}

void menu_back(PauseMenu *arg0) {
    sound_se_play(8);
    switch (arg0->page) {
    case 1:
        arg0->page = 0;
        if (arg0->item == 1) {
            sprite_delete(0x237);
            sprite_delete(0x238);
            sprite_delete(0x239);
        } else if (arg0->item == 2) {
            mail_list_close();
            sprite_set_visible(0x20A, 0);
            sprite_set_visible(0x20C, 0);
            sprite_set_visible(0x212, 0);
        } else if (arg0->item == 3) {
            sprite_set_visible(0x23D, 0);
        } else if (arg0->item == 4) {
            sprite_delete(0x23A);
            sprite_delete(0x23B);
            sprite_delete(0x23C);
        }
        break;
    case 2:
        if (arg0->item == 1) {
            arg0->page = 1;
            sprite_set_visible(0x239, 0);
        } else if (arg0->item == 2) {
            arg0->page = 1;
            mail_free();
        }
        break;
    }
}

void menu_handle_input(PauseMenu *arg0) {
    s32 r;

    if (kaj_system.pad_mode != 1 || arg0->unk4 != 0) {
        return;
    }
    r = kaj_pad_read();
    if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
        menu_move_cursor(arg0, 1);
    } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
        menu_move_cursor(arg0, 0);
    } else if (!(kaj_system.pad_prev & 0x8000) && (kaj_system.pad_now & 0x8000)) {
        if (*(s32 *)arg0 == 0x10003) {
            menu_options_page(arg0, 2, 1);
        }
    } else if (!(kaj_system.pad_prev & 0x2000) && (kaj_system.pad_now & 0x2000)) {
        if (*(s32 *)arg0 == 0x10003) {
            menu_options_page(arg0, 2, 0);
        }
    } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
        if (arg0->page == 0) {
            sound_se_play(8);
            mail_goto_ofc(1, 1, 0, 0);
            return;
        }
        menu_back(arg0);
    } else if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20) && arg0->item != 0) {
        menu_confirm(arg0);
    }
    if (arg0->page == 2 && arg0->item == arg0->page) {
        if (r & 0x1000) {
            mail_scroll(0);
        } else if (r & 0x4000) {
            mail_scroll(1);
        }
    }
}

void menu_animate(PauseMenu *arg0) {
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

    if (arg0->page == 0 && arg0->unk8 != NULL && arg0->unk4 != 0) {
        arg0->unk8->cell_row++;
        if (arg0->unk8->cell_row >= 4) {
            arg0->unk8->cell_row = 3;
            arg0->unk4 = 0;
            if (arg0->unkC != NULL) {
                if (arg0->unkC->visible == 0) {
                    arg0->unkC->visible = 1;
                }
                arg0->unkC->cell_col = 0;
                arg0->unkC->cell_row = arg0->item - 1;
                arg0->unkC->y = arg0->item * arg0->unkC->cell_h + 0x48;
            }
        }
    }
}

void menu_run(void) {
    PauseMenu st;
    PauseMenu *p;
    s32 buf[6];
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
    p = &st;
    p->item = 0;
    p->page = 0;
    p->unk4 = 0;
    p->row = 0;
    p->unk8 = NULL;
    p->unkC = NULL;
    menu_anim_sprite = NULL;
    kaj_timer_enable();
    effect_start_fade(0, 3);
    sound_bgm_play(2);
    do {
        switch (kaj_event_get(buf)) {
        case 4:
            event_handle_tick(0);
            continue;
        case 0:
            menu_handle_input(&st);
            if ((s16)mail_take_scene_change() != 0) {
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
        menu_animate(&st);
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

void text_draw_string(s32 arg0, s16 arg1) {
    s16 r[4];
    u16 buf[0x40];
    Unk_801A44B8 *p;
    u16 *d;
    u16 *f;
    u8 *s;
    u8 c;
    s16 w;
    s32 row;
    s32 col;
    s32 i;
    s32 n;
    s32 j;

    p = sprite_find(text_window_sprite);
    if (p == NULL) {
        return;
    }
    row = 0;
    col = 0;
    r[2] = 4;
    r[0] = 0;
    r[1] = 0;
    r[3] = 16;
    n = strlen((char *)arg0);
    for (i = 0; i < n; ) {
        if (row >= arg1) {
            return;
        }
        s = (u8 *)arg0 + i;
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
        d = buf;
        w = (s[0] << 8) | s[1];
        r[0] = p->tim->x + col * 4;
        r[1] = p->tim->y + row * 16;
        f = Krom2RawAdd2(w);
        memset(d, 0, 0x80);
        for (j = 0; j < 15; j++, f++) {
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 4;
                v = 0;
                for (k = 7, sh = 0; k >= m; k--, sh += 4) {
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *d++ = v;
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
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *d++ = v;
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
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *d++ = v;
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
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *d++ = v;
            }
        }
        LoadImage2(r, buf);
        col++;
        if (col >= 16) {
            col = 0;
            row++;
        }
        i += 2;
    }
}

static inline s16 func_80182860_inline(s16 flag) {
    EventState *q = &event_state;
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
            q->state = 3;
            q->circle_flags = 8;
            sprite_set_visible(0x40A, 1);
        }
        return 1;
    }
    return 0;
}

s16 text_draw_next(s32 arg0, s32 arg1) {
    s16 r[4];
    u16 buf[0x40];
    Unk_801A44B8 *p;
    u16 *d;
    u16 *f;
    u8 *s;
    u8 c;
    s16 st;
    s32 j;

    p = sprite_find(text_window_sprite);
    if (p == NULL) {
        return 0;
    }
    r[2] = 4;
    r[0] = 0;
    r[1] = 0;
    r[3] = 16;
loop:
    st = func_80182860_inline(arg1);
    if (st < 0) {
        return 0;
    }
    if (st == 1) {
        return 1;
    }
    s = (u8 *)arg0 + text_pos;
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
    d = buf;
    f = Krom2RawAdd2((s[0] << 8) | s[1]);
    memset(d, 0, 0x80);
    for (j = 0; j < 15; j++, f++) {
        {
            u16 v;
            u16 c;
            s32 k;
            s32 sh;
            s32 m;

            m = 4;
            v = 0;
            for (k = 7, sh = 0; k >= m; k--, sh += 4) {
                c = (d[0] & (0xF << sh)) >> sh;
                if ((*f >> k) & 1) {
                    c = text_color;
                }
                v |= c << sh;
            }
            *d++ = v;
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
                c = (d[0] & (0xF << sh)) >> sh;
                if ((*f >> k) & 1) {
                    c = text_color;
                }
                v |= c << sh;
            }
            *d++ = v;
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
                c = (d[0] & (0xF << sh)) >> sh;
                if ((*f >> k) & 1) {
                    c = text_color;
                }
                v |= c << sh;
            }
            *d++ = v;
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
                c = (d[0] & (0xF << sh)) >> sh;
                if ((*f >> k) & 1) {
                    c = text_color;
                }
                v |= c << sh;
            }
            *d++ = v;
        }
    }
    r[0] = p->tim->x + text_col * 4;
    r[1] = p->tim->y + text_row * 16;
    LoadImage2(r, buf);
    text_col++;
    text_pos += 2;
    if ((s16)arg1) {
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

void text_draw_line(char *arg0, s16 arg1) {
    s16 r[4];
    u16 buf[0x40];
    Unk_801A44B8 *p;
    u16 *d;
    u16 *f;
    u8 *s;
    s16 w;
    s16 line;
    s32 y;
    s32 col;
    s32 i;
    s32 n;
    s32 j;

    line = arg1;
    p = sprite_find(text_window_sprite);
    if (p == NULL) {
        return;
    }
    n = strlen(arg0);
    y = text_line_y[arg1];
    if (arg1 < 2) {
        col = (32 - n) / 4;
    } else {
        col = 1;
    }
    i = 0;
    r[2] = 4;
    r[0] = 0;
    r[1] = 0;
    r[3] = 16;
    while (i < n) {
        s = (u8 *)arg0 + i;
        if ((s8)s[0] >= 0) {
            i++;
            if (s[0] == ' ') {
                col++;
            }
            continue;
        }
        d = buf;
        w = (s[0] << 8) | s[1];
        r[0] = p->tim->x + col * 4;
        r[1] = p->tim->y + y;
        f = Krom2RawAdd2(w);
        StoreImage2(r, d);
        for (j = 0; j < 15; j++, f++) {
            {
                u16 v;
                u16 c;
                s32 k;
                s32 sh;
                s32 m;

                m = 4;
                v = 0;
                for (k = 7, sh = 0; k >= m; k--, sh += 4) {
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *d++ = v;
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
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *d++ = v;
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
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *d++ = v;
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
                    c = (d[0] & (0xF << sh)) >> sh;
                    if ((*f >> k) & 1) {
                        c = text_color;
                    }
                    v |= c << sh;
                }
                *d++ = v;
            }
        }
        LoadImage2(r, buf);
        col++;
        if (line >= 3 && col >= 15) {
            col = 1;
            line++;
            y = text_line_y[line];
        }
        i += 2;
    }
}

void text_format_number(u8 *arg0, u16 arg1) {
    u16 a;
    u16 b;
    u16 c;

    memset(arg0, 0, 8);
    if (arg1 == 0) {
        strncpy(arg0, D_801DFCBC, 2);
        return;
    }
    arg1 %= 1000;
    a = arg1 / 100;
    arg1 %= 100;
    b = arg1 / 10;
    c = arg1 % 10;
    if (a == 0) {
        if (b == 0) {
            arg0[0] = 0x82;
            arg0[1] = c + 0x4F;
        } else {
            arg0[0] = 0x82;
            arg0[1] = b + 0x4F;
            arg0[2] = 0x82;
            arg0[3] = c + 0x4F;
        }
    } else {
        arg0[0] = 0x82;
        arg0[1] = a + 0x4F;
        arg0[2] = 0x82;
        arg0[3] = b + 0x4F;
        arg0[4] = 0x82;
        arg0[5] = c + 0x4F;
    }
}

void text_show_timed(u16 arg0, s16 arg1, s32 arg2, s16 arg3, s32 arg4) {
    Rect rect;
    Unk_801A44B8 *p;
    s16 b;

    b = (arg0 == 1 || arg0 == 2);
    if (arg1 != 0) {
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
        p = sprite_find(text_window_sprite);
        if (p != NULL) {
            rect.x = p->tim->x;
            rect.y = p->tim->y;
            rect.w = p->tim->w;
            rect.h = p->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
        text_draw_string(arg2, m);
        if (arg3 == 1) {
            sound_se_play(0xF);
        } else if (arg3 == 2) {
            sound_se_play(6);
        } else if (arg3 == 3) {
            sound_se_play(5);
        } else if (arg3 == 4) {
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
        p = sprite_find(text_window_sprite);
        if (p != NULL) {
            rect.x = p->tim->x;
            rect.y = p->tim->y;
            rect.w = p->tim->w;
            rect.h = p->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
        text_draw_string(arg2, m);
        if (arg3 == 1) {
            sound_se_play(0xF);
        } else if (arg3 == 2) {
            sound_se_play(6);
        } else if (arg3 == 3) {
            sound_se_play(5);
        } else if (arg3 == 4) {
            sound_se_play(0xE);
        }
        if (g->unk24E == 0) {
            g->unk24E = 1;
        }
    }
    mail_wait(arg0, b, b, arg4);
}

void text_start_typing(s32 arg0) {
    GameVars_u8017EBF8 *g = &action_vars;
    Rect rect;
    Unk_801A44B8 *p;

    text_window_sprite = 0x404;
    sprite_set_visible(0x403, 0);
    sprite_set_visible(0x404, 1);
    sprite_set_clut_entry(0x40A, 3, 0x14BF);
    text_color = 2;
    text_col = 0;
    text_row = 0;
    p = sprite_find(text_window_sprite);
    if (p != NULL) {
        rect.x = p->tim->x;
        rect.y = p->tim->y;
        rect.w = p->tim->w;
        rect.h = p->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    text_pos = 0;
    text_len = strlen((char *)arg0);
    if (text_draw_next(arg0, 1) != 0) {
        text_wait -= D_801E6DB4[0];
        if (text_wait > 0) {
            (*text_cmd)->state = 4;
        } else {
            text_wait = 0;
            (*text_cmd)->state = 3;
        }
        action_push_front(text_cmd);
    }
    if (g->unk24E == 0) {
        g->unk24E = 1;
    }
}

void text_show_profile(u16 arg0) {
    GameVars_u8017EBF8 *g = &action_vars;
    char buf[0x20];
    Rect rect;
    u8 a[8];
    u8 b[8];
    Npc *e;
    NpcBody *d;
    Unk_801A44B8 *p;
    Rect *r;
    char *pb;
    s32 i;

    e = npc_find(0, arg0);
    if (e == NULL) {
        return;
    }
    d = npc_find_body(e->unk14);
    if (d == NULL) {
        return;
    }
    text_color = 9;
    text_window_sprite = 0x40D;
    r = &rect;
    p = sprite_find(0x40D);
    if (p != NULL) {
        rect.x = 0x300;
        r->y = 0x100;
        r->w = 0x40;
        r->h = 0x10;
        for (i = 0; i < 8; i++) {
            rect.y = 0x100 + i * 0x10;
            MoveImage2(&rect, (s16)p->tim->x, (s16)p->tim->y + text_line_y[i]);
        }
    }

    text_format_number(a, d->unk2);
    pb = (char *)b;
    text_format_number((u8 *)pb, d->unk6);
    pb = buf;
    memset(pb, 0, 0x20);
    /* "%s才 %s %sｃｍ %s" */
    sprintf(pb, "%s\215\313 %s %s\202\203\202\215 %s", b, text_sex_names[d->unk4], a, text_blood_types[d->unk8]);
    text_draw_line(d->unkC, 0);
    text_draw_line(d->unk2C, 1);
    text_draw_line(pb, 2);
    text_draw_line(d->unk4C, 3);
    sprite_set_visible(0x40D, 1);
    if (g->unk24E == 0) {
        g->unk24E = 1;
    }
}

static inline void func_801837F0_inl(s32 t, s16 m, s16 a, u16 b, s16 c, u16 d, s16 e) {
    Rect rect;
    Unk_801A44B8 *p;
    GameVars_u8017EBF8 *g2 = &action_vars;
    EventState *dp = &event_state;
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
    dp->circle_flags = b;
    dp->circle_set = a;
    dp->cross_flags = d;
    dp->cross_set = c;
    if (b != 0 || d != 0) {
        dp->state = 2;
    }
    p = sprite_find(text_window_sprite);
    if (p != NULL) {
        rect.x = p->tim->x;
        rect.y = p->tim->y;
        rect.w = p->tim->w;
        rect.h = p->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    text_draw_string(t, m);
    if (e == 1) {
        sound_se_play(0xF);
    } else if (e == 2) {
        sound_se_play(6);
    } else if (e == 3) {
        sound_se_play(5);
    } else if (e == 4) {
        sound_se_play(0xE);
    }
    if (g2->unk24E == 0) {
        g2->unk24E = 1;
    }
}

void text_exec_command(Unk_8018519C *arg0) {
    GameVars_u8017EBF8 *g = &action_vars;
    Player *q = player_status_player[0];
    u16 state = arg0->unk0->unk2;
    Unk_801A44B8 *p;
    char **s;
    s16 a;
    u16 b;
    s16 c;
    u16 d;
    s16 e;
    s32 str;

    switch (state) {
    case 0:
        switch (g->text_speed_setting) {
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
        text_cmd = (TextCmd **)arg0;
        text_start_typing((s32)arg0->unk8[0]);
        break;
    case 1:
        if (D_801DFC5C != 0) {
            q->flags |= 0x100;
            D_801DFC5C = 0;
            text_show_timed(1, 0, (s32)arg0->unk8[0], atoi(arg0->unk8[5]), 2);
            q->flags &= 0xFEFF;
            text_release_cmd();
            sprite_set_visible(0x403, 0);
            sprite_set_visible(0x404, 0);
            sprite_set_visible(0x40A, 0);
            sprite_set_visible(0x40D, 0);
            if (g->unk24E != 0) {
                g->unk24E = 0;
            }
        } else {
            s = arg0->unk8;
            a = atoi(s[1]);
            b = atoi(arg0->unk8[2]);
            c = atoi(arg0->unk8[3]);
            d = atoi(arg0->unk8[4]);
            e = atoi(arg0->unk8[5]);
            func_801837F0_inl((s32)s[0], 1, a, b, c, d, e);
        }
        break;
    case 3:
        switch (g->text_speed_setting) {
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
        str = (s32)arg0->unk8[0];
        if (text_row == 3) {
            text_row = 0;
            p = sprite_find(text_window_sprite);
            if (p != NULL) {
                Rect rect;

                rect.x = p->tim->x;
                rect.y = p->tim->y;
                rect.w = p->tim->w;
                rect.h = p->tim->h;
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

void text_start_narration(s32 arg0) {
    GameVars_u8017EBF8 *g = &action_vars;
    Player *q = player_status_player[0];
    Rect rect;
    TssSlot *e;
    Unk_801A44B8 *p;

    e = kaj_tss_alloc(4);
    e->type = 8;
    e->cur = 0;
    e->target = strlen((char *)arg0);
    e->step = 1;
    e->delay = 0xA;
    e->on_step = text_narration_step;
    e->on_end = text_narration_end;
    e->on_kill = text_narration_end;
    sprite_set_visible(0x403, 0);
    sprite_set_visible(0x404, 1);
    sprite_set_clut_entry(0x40A, 3, 0x14BF);
    text_window_sprite = 0x404;
    text_color = 1;
    text_col = 0;
    text_row = 0;
    text_pos = 0;
    text_len = strlen((char *)arg0);
    p = sprite_find(text_window_sprite);
    if (p != NULL) {
        rect.x = p->tim->x;
        rect.y = p->tim->y;
        rect.w = p->tim->w;
        rect.h = p->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    *(s32 *)e->data = arg0;
    text_draw_next(arg0, 0);
    text_cue_fade_done = 0;
    text_cue_bgm_done = 0;
    q->flags |= 0x100;
    g->unk248 = kaj_tss_start(e);
}

void text_show(s32 arg0, s16 arg1, s16 arg2, u16 arg3, s16 arg4, u16 arg5, s16 arg6) {
    GameVars_u8017EBF8 *g = &action_vars;
    EventState *d = &event_state;
    Rect rect;
    Unk_801A44B8 *p;

    if (arg1 == 1) {
        text_window_sprite = 0x403;
        sprite_set_visible(0x403, 1);
        sprite_set_visible(0x404, 0);
        sprite_set_clut_entry(0x403, 3, 0x14BF);
    } else if (arg1 == 3) {
        text_window_sprite = 0x404;
        sprite_set_visible(0x403, 0);
        sprite_set_visible(0x404, 1);
        sprite_set_clut_entry(0x404, 3, 0x14BF);
    }
    text_color = 1;
    d->circle_flags = arg3;
    d->circle_set = arg2;
    d->cross_flags = arg5;
    d->cross_set = arg4;
    if (arg3 != 0 || arg5 != 0) {
        d->state = 2;
    }
    p = sprite_find(text_window_sprite);
    if (p != NULL) {
        rect.x = p->tim->x;
        rect.y = p->tim->y;
        rect.w = p->tim->w;
        rect.h = p->tim->h;
        ClearImage2(&rect, 0, 0, 0);
    }
    text_draw_string(arg0, arg1);
    if (arg6 == 1) {
        sound_se_play(0xF);
    } else if (arg6 == 2) {
        sound_se_play(6);
    } else if (arg6 == 3) {
        sound_se_play(5);
    } else if (arg6 == 4) {
        sound_se_play(0xE);
    }
    if (g->unk24E == 0) {
        g->unk24E = 1;
    }
}

void text_close(void) {
    GameVars_u8017EBF8 *p = &action_vars;

    text_release_cmd();
    sprite_set_visible(0x403, 0);
    sprite_set_visible(0x404, 0);
    sprite_set_visible(0x40A, 0);
    sprite_set_visible(0x40D, 0);
    if (p->unk24E != 0) {
        p->unk24E = 0;
    }
}

void text_next_page(Unk_80184100 *arg0) {
    if (arg0->unk8 & 8) {
        arg0->unk8 &= ~8;
        arg0->unk6 = 1;
        sprite_set_visible(0x40A, 0);
        sprite_set_clut_entry(0x40A, 3, 0x14BF);
        sound_se_play(0x11);
    }
}

void text_release_cmd(void) {
    TextCmd *p;

    if (text_cmd != NULL) {
        p = *text_cmd;
        if (p->opcode == 5 && (u16)(p->state - 3) < 2) {
            p->state = 0;
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

void text_type_step(s32 arg0) {
    Rect rect;
    Unk_801A44B8 *p;

    if (text_row == 3) {
        text_row = 0;
        p = sprite_find(text_window_sprite);
        if (p != NULL) {
            rect.x = p->tim->x;
            rect.y = p->tim->y;
            rect.w = p->tim->w;
            rect.h = p->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
    }
    if (text_draw_next(arg0, 1) != 0) {
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

void text_narration_step(TssSlot *arg0) {
    Rect rect;
    Unk_801A44B8 *p;
    s32 v;

    if (D_801DFCE6 != 0) {
        D_801DFCE6 = 0;
        return;
    }
    v = *(s32 *)arg0->data;
    arg0->cur = text_pos;
    if (text_row == 3) {
        text_row = 0;
        p = sprite_find(text_window_sprite);
        if (p != NULL) {
            rect.x = p->tim->x;
            rect.y = p->tim->y;
            rect.w = p->tim->w;
            rect.h = p->tim->h;
            ClearImage2(&rect, 0, 0, 0);
        }
    }
    D_801DFCE6 = text_draw_next(v, 0);
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

void door_setup(Door *arg0) {
    Player *q = player_status_player[0];
    Unk_801844D4 *s = arg0->record;
    SVector rot;

    arg0->id = s->unk0;
    arg0->axis = s->unk2;
    arg0->unk8 = s->unk4;
    arg0->state = s->unk8;
    arg0->pos_x = s->unkC * 10;
    arg0->pos_y = s->unk10 * 10;
    arg0->pos_z = s->unk14 * 10;
    arg0->angle = s->unk6;
    kaj_tmd_load(&arg0->tmd_objects, ((Unk_801844D4 *)arg0->record)->unk18, &arg0->coord_flg);
    GsInitCoordinate2(NULL, &arg0->coord_flg);
    arg0->coord_tx = arg0->pos_x - q->cell_x * 12500;
    arg0->coord_ty = arg0->pos_y + q->cell_y * 32000;
    arg0->coord_tz = arg0->pos_z - q->cell_z * 12500;
    rot.vx = 0;
    rot.vy = (arg0->angle << 12) / 360;
    rot.vz = 0;
    RotMatrix(&rot, arg0->coord_m);
    arg0->coord_flg = 0;
    arg0->block = (s32)block_find_at(arg0->pos_x, arg0->pos_y, arg0->pos_z);
    arg0->active = 1;
}

void door_refresh_all(void) {
    DoorList *list = door_list;
    Player *q = player_status_player[0];
    Door *item;
    SVector rot;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        item = list->cursor->data;
        if (item != NULL) {
            item->coord_tx = item->pos_x - q->cell_x * 12500;
            item->coord_ty = item->pos_y + q->cell_y * 32000;
            item->coord_tz = item->pos_z - q->cell_z * 12500;
            rot.vx = 0;
            rot.vy = (item->angle << 12) / 360;
            rot.vz = 0;
            RotMatrix(&rot, item->coord_m);
            item->coord_flg = 0;
            item->block = (s32)block_find_at(item->pos_x, item->pos_y, item->pos_z);
        }
        if (kaj_ll_at_tail((BlockList *)list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void door_move_x(DoorMove *arg0) {
    EventState *s;

    arg0->pos_x += D_801E6DB4[0] * arg0->speed;
    if (arg0->speed > 0) {
        if (arg0->pos_x >= arg0->move_to) {
            s = &event_state;
            if (arg0->state == 3) {
                if (arg0->auto_return != 0) {
                    arg0->state = 0;
                    arg0->auto_return = 0;
                    arg0->move_to = arg0->move_from;
                    arg0->pos_x = arg0->move_from;
                } else {
                    arg0->state = 1;
                    arg0->auto_return = 0;
                    arg0->pos_x = arg0->move_to;
                }
            } else if (arg0->state == 2) {
                arg0->state = 0;
                arg0->pos_x = arg0->move_to;
            }
            if (s->wait_flags & 4) {
                s->wait_flags &= ~4;
                if (s->wait_flags == 0) {
                    s->state = 1;
                }
            }
        }
    } else {
        if (arg0->move_to >= arg0->pos_x) {
            s = &event_state;
            if (arg0->state == 3) {
                if (arg0->auto_return != 0) {
                    arg0->state = 0;
                    arg0->auto_return = 0;
                    arg0->move_to = arg0->move_from;
                    arg0->pos_x = arg0->move_from;
                } else {
                    arg0->state = 1;
                    arg0->auto_return = 0;
                    arg0->pos_x = arg0->move_to;
                }
            } else if (arg0->state == 2) {
                arg0->state = 0;
                arg0->pos_x = arg0->move_to;
            }
            if (s->wait_flags & 4) {
                s->wait_flags &= ~4;
                if (s->wait_flags == 0) {
                    s->state = 1;
                }
            }
        }
    }
}

void door_move_y(DoorMove *arg0) {
    EventState *s;

    arg0->pos_y += D_801E6DB4[0] * arg0->speed;
    if (arg0->speed > 0) {
        if (arg0->pos_y >= arg0->move_to) {
            s = &event_state;
            if (arg0->state == 3) {
                if (arg0->auto_return != 0) {
                    arg0->state = 0;
                    arg0->auto_return = 0;
                    arg0->move_to = arg0->move_from;
                    arg0->pos_y = arg0->move_from;
                } else {
                    arg0->state = 1;
                    arg0->auto_return = 0;
                    arg0->pos_y = arg0->move_to;
                }
            } else if (arg0->state == 2) {
                arg0->state = 0;
                arg0->pos_y = arg0->move_to;
            }
            if (s->wait_flags & 4) {
                s->wait_flags &= ~4;
                if (s->wait_flags == 0) {
                    s->state = 1;
                }
            }
        }
    } else {
        if (arg0->move_to >= arg0->pos_y) {
            s = &event_state;
            if (arg0->state == 3) {
                if (arg0->auto_return != 0) {
                    arg0->state = 0;
                    arg0->auto_return = 0;
                    arg0->move_to = arg0->move_from;
                    arg0->pos_y = arg0->move_from;
                } else {
                    arg0->state = 1;
                    arg0->auto_return = 0;
                    arg0->pos_y = arg0->move_to;
                }
            } else if (arg0->state == 2) {
                arg0->state = 0;
                arg0->pos_y = arg0->move_to;
            }
            if (s->wait_flags & 4) {
                s->wait_flags &= ~4;
                if (s->wait_flags == 0) {
                    s->state = 1;
                }
            }
        }
    }
}

void door_move_z(DoorMove *arg0) {
    EventState *s;

    arg0->pos_z += D_801E6DB4[0] * arg0->speed;
    if (arg0->speed > 0) {
        if (arg0->pos_z >= arg0->move_to) {
            s = &event_state;
            if (arg0->state == 3) {
                if (arg0->auto_return != 0) {
                    arg0->state = 0;
                    arg0->auto_return = 0;
                    arg0->move_to = arg0->move_from;
                    arg0->pos_z = arg0->move_from;
                } else {
                    arg0->state = 1;
                    arg0->auto_return = 0;
                    arg0->pos_z = arg0->move_to;
                }
            } else if (arg0->state == 2) {
                arg0->state = 0;
                arg0->pos_z = arg0->move_to;
            }
            if (s->wait_flags & 4) {
                s->wait_flags &= ~4;
                if (s->wait_flags == 0) {
                    s->state = 1;
                }
            }
        }
    } else {
        if (arg0->move_to >= arg0->pos_z) {
            s = &event_state;
            if (arg0->state == 3) {
                if (arg0->auto_return != 0) {
                    arg0->state = 0;
                    arg0->auto_return = 0;
                    arg0->move_to = arg0->move_from;
                    arg0->pos_z = arg0->move_from;
                } else {
                    arg0->state = 1;
                    arg0->auto_return = 0;
                    arg0->pos_z = arg0->move_to;
                }
            } else if (arg0->state == 2) {
                arg0->state = 0;
                arg0->pos_z = arg0->move_to;
            }
            if (s->wait_flags & 4) {
                s->wait_flags &= ~4;
                if (s->wait_flags == 0) {
                    s->state = 1;
                }
            }
        }
    }
}

void door_move_angle(DoorMove *arg0) {
    EventState *s;

    arg0->angle += D_801E6DB4[0] * arg0->speed;
    if (arg0->speed > 0) {
        if (arg0->angle >= arg0->move_to) {
            s = &event_state;
            if (arg0->state == 3) {
                if (arg0->auto_return != 0) {
                    arg0->state = 0;
                    arg0->auto_return = 0;
                    arg0->move_to = arg0->move_from;
                    *(s32 *)&arg0->angle = arg0->move_from;
                } else {
                    arg0->state = 1;
                    arg0->auto_return = 0;
                    *(s32 *)&arg0->angle = arg0->move_to;
                }
            } else if (arg0->state == 2) {
                arg0->state = 0;
                *(s32 *)&arg0->angle = arg0->move_to;
            }
            if (s->wait_flags & 4) {
                s->wait_flags &= ~4;
                if (s->wait_flags == 0) {
                    s->state = 1;
                }
            }
        }
    } else {
        if (arg0->angle <= arg0->move_to) {
            s = &event_state;
            if (arg0->state == 3) {
                if (arg0->auto_return != 0) {
                    arg0->state = 0;
                    arg0->auto_return = 0;
                    arg0->move_to = arg0->move_from;
                    *(s32 *)&arg0->angle = arg0->move_from;
                } else {
                    arg0->state = 1;
                    arg0->auto_return = 0;
                    *(s32 *)&arg0->angle = arg0->move_to;
                }
            } else if (arg0->state == 2) {
                arg0->state = 0;
                *(s32 *)&arg0->angle = arg0->move_to;
            }
            if (s->wait_flags & 4) {
                s->wait_flags &= ~4;
                if (s->wait_flags == 0) {
                    s->state = 1;
                }
            }
        }
    }
}

void door_update_all(void) {
    DoorList *list = door_list;
    Player *q = player_status_player[0];
    DoorMove *item;
    SVector rot;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        item = (DoorMove *)list->cursor->data;
        if (item != NULL && item->active != 0 && item->visible != 0
            && (u16)(item->state - 2) < 2) {
            switch (item->axis) {
            case 1:
                door_move_x(item);
                break;
            case 2:
                door_move_y(item);
                break;
            case 3:
                door_move_z(item);
                break;
            default:
                door_move_angle(item);
                break;
            }
            item->coord_tx = item->pos_x - q->cell_x * 12500;
            item->coord_ty = item->pos_y + q->cell_y * 32000;
            item->coord_tz = item->pos_z - q->cell_z * 12500;
            rot.vx = 0;
            rot.vy = (item->angle << 12) / 360;
            rot.vz = 0;
            RotMatrix(&rot, item->coord_m);
            item->coord_flg = 0;
        }
        if (item->active != 0 && item->visible != 0 && D_801DFC80 != 0) {
            item->block = (s32)block_find_at(item->pos_x, item->pos_y, item->pos_z);
        }
        if (kaj_ll_at_tail((BlockList *)list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void door_start_open(DoorMove *arg0, s16 arg1, s16 arg2, s16 arg3) {
    s16 v = arg2;
    s32 w;
    s16 d;

    D_801DFC74 = 1;
    arg0->state = 3;
    arg0->auto_return = arg3;
    switch (arg0->axis) {
    case 1:
        v = arg2 * 10;
        arg0->move_from = arg0->pos_x;
        arg0->move_to = arg0->pos_x + arg1 * 10;
        break;
    case 2:
        v = arg2 * 10;
        arg0->move_from = arg0->pos_y;
        arg0->move_to = arg0->pos_y + arg1 * 10;
        break;
    case 3:
        v = arg2 * 10;
        arg0->move_from = arg0->pos_z;
        arg0->move_to = arg0->pos_z + arg1 * 10;
        break;
    default:
        arg0->move_from = arg0->angle;
        arg0->move_to = arg0->angle + arg1;
        break;
    }
    d = arg0->move_to - arg0->move_from;
    w = v;
    if (d >= 0) {
        if (d <= 0) {
            arg0->speed = 0;
        } else {
            arg0->speed = w;
        }
    } else {
        arg0->speed = -w;
    }
}

void door_start_close(DoorMove *arg0, s16 arg1, s16 arg2) {
    s16 v = arg2;
    s32 w;
    s16 d;

    D_801DFC74 = 1;
    arg0->state = 2;
    arg0->auto_return = 0;
    switch (arg0->axis) {
    case 1:
        v = arg2 * 10;
        arg0->move_from = arg0->pos_x;
        arg0->move_to = arg0->pos_x + arg1 * 10;
        break;
    case 2:
        v = arg2 * 10;
        arg0->move_from = arg0->pos_y;
        arg0->move_to = arg0->pos_y + arg1 * 10;
        break;
    case 3:
        v = arg2 * 10;
        arg0->move_from = arg0->pos_z;
        arg0->move_to = arg0->pos_z + arg1 * 10;
        break;
    default:
        arg0->move_from = arg0->angle;
        arg0->move_to = arg0->angle + arg1;
        break;
    }
    d = arg0->move_to - arg0->move_from;
    w = v;
    if (d >= 0) {
        if (d <= 0) {
            arg0->speed = 0;
        } else {
            arg0->speed = w;
        }
    } else {
        arg0->speed = -w;
    }
}

void door_exec_command(Unk_8018519C *arg0, EventState *arg1) {
    DoorList *list = door_list;
    Unk_8018519C_0 *p = arg0->unk0;
    DoorMove *item;
    DoorMove *found;
    u16 a = p->unk4;
    s32 x;
    s32 y;

    if (list->count == 0) {
        found = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = (DoorMove *)list->cursor->data;
            if (item != NULL && item->id == a) {
                found = item;
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
        if (p->unk2 == 0) {
            if (found->state != 1) {
                x = (s16)atoi(arg0->unk8[0]);
                y = (s16)atoi(arg0->unk8[1]);
                door_start_open(found, x, y, atoi(arg0->unk8[2]));
                if (atoi(arg0->unk8[3]) == 1) {
                    arg1->state = 4;
                    arg1->wait_flags |= 4;
                }
            }
        } else {
            if (found->state != 0) {
                s32 z = (s16)atoi(arg0->unk8[0]);
                door_start_close(found, z, atoi(arg0->unk8[1]));
                if (atoi(arg0->unk8[2]) == 1) {
                    arg1->state = 4;
                    arg1->wait_flags |= 4;
                }
            }
        }
    }
}
