#include "common.h"
#include "game/card.h"
#include "game/effect.h"
#include "game/event.h"
#include "game/main.h"
#include "game/object.h"
#include "game/roadmap.h"
#include "game/sound.h"
#include "game/sprite.h"
#include "game/thing.h"
#include "kaj/event.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "kaj/timer.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libgpu.h"
#include "psyq/libmcrd.h"

/*
 * The memory card menu: scan, load and save.
 *
 * File boundaries: guess (docs/layout.md): no assert: jtbl cut; its end is a guess.
 */

extern GameVars_u8017EBF8 action_vars;
typedef struct CardIconClut {
    u8 unk0[0x20];
} CardIconClut;
typedef struct {
    s16 used;
    u8 pad2[0x2];
    char file_name[0x14];
    u8 magic_s;
    u8 magic_c;
    u8 icon_flag;
    u8 block_count;
    u8 title[0x40];
    u8 reserved[0x1C];
    CardIconClut icon_clut;
} CardSlot;
typedef struct {
    s16 load_mode;
    s16 loaded;
    s16 in_office;
    s16 card_found;
    s16 cursor;
    u8 padA[0x2];
    s32 message;
    u32 job;
    CardSlot slots[4];
} CardMenu;
extern SceneRequest scene_request;
static void menu_card_init_slots(CardMenu *card, s32 clear_icons);
static void menu_card_set_message(CardMenu *card, s32 result);
static s32 menu_card_load(CardMenu *card);
static s32 menu_card_save(CardMenu *card, s32 overwrite);
static s32 menu_card_scan(CardMenu *card);
extern CardIconClut menu_card_icon_clut;
extern CardMenu menu_card_state;
static void menu_card_process(CardMenu *card);
static s16 menu_card_handle_input(CardMenu *card);
s32 mail_take_scene_change(void);
extern KajSystem kaj_system;
static void menu_card_move_cursor(CardMenu *card, s16 up);
extern s16 kaj_system_pad_mode[];
/* Local view of Player: this unit reads 0x1C-0x38 as scalars, the shared type has one record at 0x18. */
typedef struct {
    u8 pad0[0x1C];
    s32 exit_pos_x;
    s32 exit_pos_y;
    s32 exit_pos_z;
    u8 pad28[0x10];
    s16 exit_yaw;
} Player_u8017EBF8;
extern PlayerStatus player_status;
void sprite_copy_cell(s32 src_id, s32 col, s32 row, s32 dst_id, s32 dst_x, s32 dst_y);
typedef struct {
    s16 in_office;
    s16 vars[0x80];
    s16 settings[2];
    s16 status[0x27];
    s32 inventory[0x11];
    s32 player[0xE];
    u8 pad1D0[0x2C];
} SaveData;
extern char menu_str_save_title[];
extern u8 menu_card_icon_image[];
extern s16 scene_request_change[];
typedef struct {
    char name[0x14];
    s32 attr;
    s32 size;
    void *next;
    s32 head;
    char system[0x4];
} DirEntry;
extern char menu_card_dir_pattern[];

static void menu_card_init_slots(CardMenu *card, s32 clear_icons) {
    Rect rect;
    void *buf;
    CardSlot *slot;
    s32 i;

    slot = card->slots;
    card->card_found = 0;
    card->cursor = -1;
    for (i = 0; i < 4; i++, slot++) {
        memset(slot->file_name, 0, 0x14);
        sprintf(slot->file_name, "BISLPS-02107GERMS%d", i);
        slot->used = 0;
        slot->magic_s = 'S';
        slot->magic_c = 'C';
        slot->icon_flag = 0x11;
        slot->block_count = 1;
        memset(slot->title, 0, 0x40);
        memset(slot->reserved, 0, 0x1C);
        slot->icon_clut = menu_card_icon_clut;
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

INCLUDE_RODATA("asm/nonmatchings/game/card", menu_str_save_title);

static void menu_card_set_message(CardMenu *card, s32 result) {
    s32 cell;

    if (result < 0x64) {
        switch (result) {
        case 0:
            return;
        case 1:
            menu_card_init_slots(card, 1);
            card->message = 0x66;
            break;
        case 2:
            menu_card_init_slots(card, 1);
            card->message = 0x67;
            break;
        case 3:
            card->message = -1;
            card->job = 0;
            return;
        case 4:
            card->message = 0x69;
            break;
        case 5:
            if (card->load_mode != 0) {
                card->message = 0x66;
                card->job = 0;
            } else {
                card->message = -1;
                card->job = 0xD;
            }
            return;
        case 6:
            card->message = 0x6B;
            break;
        case 7:
            card->message = 0x6A;
            break;
        default:
            card->message = -1;
            return;
        }
    } else {
        card->message = result;
    }
    switch (card->message) {
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
        if (card->load_mode == 0) {
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
    sprite_set_cell(0x202, (s16)((card->message - 0x64) / 4), (s16)((card->message - 0x64) % 4));
    sprite_set_cell(0x203, 0, cell);
}

static inline s32 menu_card_load_read_frame(u8 *buf, s32 block) {
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

static inline s16 menu_card_load_check_sum(u8 *sec) {
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

static s32 menu_card_load(CardMenu *card) {
    SaveData save;
    u8 sec[0x80];
    PlayerStatus *status = &player_status;
    GameVars_u8017EBF8 *vars = &action_vars;
    s16 *car_speed = &vars->car_speed_setting;
    Inventory *inventory = status->inventory;
    Player_u8017EBF8 *player = status->player;
    CardSlot *slot;
    s32 ret;
    s32 i;

    slot = &card->slots[card->cursor];
    menu_card_set_message(card, 0x65);
    roadmap_draw_frame(3);
    ret = MemCardOpen(0, slot->file_name, 1);
    if (ret != 0) {
        return ret;
    }
    memset(&save, 0, sizeof(save));
    for (i = 0; i < 4; i++) {
        memset(sec, 0, 0x80);
        ret = menu_card_load_read_frame(sec, i * 2 + 2);
        if (ret != 0) {
            goto error;
        }
        if (menu_card_load_check_sum(sec)) {
            memcpy((u8 *)&save + i * 0x7F, sec, 0x7F);
        } else {
            memset(sec, 0, 0x80);
            ret = menu_card_load_read_frame(sec, i * 2 + 3);
            if (ret != 0) {
                goto error;
            }
            if (menu_card_load_check_sum(sec)) {
                memcpy((u8 *)&save + i * 0x7F, sec, 0x7F);
            } else {
                ret = 0x68;
                goto error;
            }
        }
    }
    MemCardClose();
    card->loaded = 1;
    memcpy(vars, save.vars, sizeof(save.vars));
    memcpy(car_speed, save.settings, sizeof(save.settings));
    memcpy(status, save.status, sizeof(save.status));
    memcpy(inventory, save.inventory, sizeof(save.inventory));
    memcpy(player, save.player, sizeof(save.player));
    vars->drain_count = 0;
    vars->drain_minute = vars->vars[0x3F] % 10;
    if (save.in_office != 0) {
        mail_goto_ofc(1, 1, 1, 0);
    } else {
        mail_goto_twn(player->exit_pos_x, player->exit_pos_y, player->exit_pos_z, player->exit_yaw, 0);
    }
    return 0x6C;
error:
    MemCardClose();
    return ret;
}

static inline s32 menu_card_save_write_frame(void *buf, s32 block) {
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

static inline void menu_card_save_digits(char *out, s32 n) {
    out[0] = out[2] = 0x82;
    out[1] = n / 10 + 0x4F;
    out[3] = n % 10 + 0x4F;
    out[4] = 0;
}

static s32 menu_card_save(CardMenu *card, s32 overwrite) {
    SaveData save;
    u8 sec[0x80];
    char day_str[8];
    char hour_str[8];
    char minute_str[8];
    char slot_str[8];
    PlayerStatus *status = &player_status;
    GameVars_u8017EBF8 *vars = &action_vars;
    s16 *car_speed = &vars->car_speed_setting;
    Inventory *inventory = status->inventory;
    Player_u8017EBF8 *player = status->player;
    CardSlot *slot;
    u8 *header;
    u8 *p;
    u8 sum;
    s32 ret;
    s32 i;
    s32 j;

    slot = &card->slots[card->cursor];
    header = &slot->magic_s;
    if (slot->used != 0) {
        if ((s16)overwrite == 0) {
            return 0x6B;
        }
    } else {
        ret = MemCardCreateFile(0, slot->file_name, 1);
        if (ret != 0) {
            return ret;
        }
    }
    menu_card_set_message(card, 0x65);
    roadmap_draw_frame(3);
    ret = MemCardOpen(0, slot->file_name, 2);
    if (ret != 0) {
        return ret;
    }
    menu_card_save_digits(day_str, vars->vars[0x3D] + 1);
    menu_card_save_digits(hour_str, vars->vars[0x3E]);
    menu_card_save_digits(minute_str, vars->vars[0x3F]);
    menu_card_save_digits(slot_str, card->cursor + 1);
    memset(header + 4, 0, 0x40);
    /* memory card save title format: game name, day, hour, minute, slot */
    sprintf(header + 4, menu_str_save_title, day_str, hour_str, minute_str, slot_str);
    memset(&save, 0, sizeof(save));
    memcpy(save.vars, vars, sizeof(save.vars));
    memcpy(save.settings, car_speed, sizeof(save.settings));
    memcpy(save.status, status, sizeof(save.status));
    memcpy(save.inventory, inventory, sizeof(save.inventory));
    memcpy(save.player, player, sizeof(save.player));
    save.in_office = card->in_office;
    if (menu_card_save_write_frame(header, 0) != 0) {
        goto error;
    }
    if (menu_card_save_write_frame(menu_card_icon_image, 1) != 0) {
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
        if (menu_card_save_write_frame(sec, i * 2 + 2) != 0) {
            goto error;
        }
        if (menu_card_save_write_frame(sec, i * 2 + 3) != 0) {
            goto error;
        }
    }
    MemCardClose();
    scene_request_change[0] = 1;
    return 0x6C;
error:
    MemCardClose();
    if (slot->used == 0) {
        MemCardDeleteFile(0, slot->file_name);
    }
    return 0x68;
}

static s32 menu_card_scan(CardMenu *card) {
    DirEntry entries[15];
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
    CardSlot *slot;

    ret = MemCardGetDirentry(0, menu_card_dir_pattern, entries, &count, 0, 15);
    if (ret != 0) {
        return ret;
    }
    if (card->load_mode != 0 && count == 0) {
        return 0x6A;
    }
    used_blocks = 0;
    found = 0;
    first_slot = 4;
    cmd = 0;
    result = 0;
    for (i = 0; i < count; i++) {
        n = entries[i].size / 0x2000;
        if (entries[i].size & 0x1FFF) {
            used_blocks += n + 1;
        } else {
            used_blocks += n;
        }
        slot = card->slots;
        for (j = 0; j < 4; j++, slot++) {
            if (strncmp(entries[i].name, slot->file_name, 0x12) == 0) {
                slot->used = 1;
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
    if (card->load_mode != 0) {
        if (found == 0) {
            return 0x6A;
        }
    } else if (found == 0 && used_blocks == 15) {
        return 0x6A;
    }
    sprite_fill_clut(0x200, 4, 7, 0xC252);
    slot = card->slots;
    for (i = 0; i < 4; i++, slot++) {
        header = &slot->magic_s;
        if (slot->used != 0) {
            for (;;) {
                switch (MemCardSync(1, &cmd, &result)) {
                case 0:
                    continue;
                case -1:
                    MemCardReadFile(0, slot->file_name, header, 0, 0x80);
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
    card->cursor = first_slot;
    sprite_fill_clut(0x200, 9, 0xC, 0xC252);
    sprite_set_clut_entry(0x200, first_slot + 9, 0x3FF);
    return 0x64;
}

static void menu_card_move_cursor(CardMenu *card, s16 up) {
    s32 i;
    s32 se;

    if (up != 0) {
        i = card->cursor - 1;
        if (i < 0) {
            i = 3;
        }
    } else {
        i = card->cursor + 1;
        if (i >= 4) {
            i = 0;
        }
    }
    if (card->load_mode != 0) {
loop:
        if (card->slots[i].used == 0) {
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
    card->cursor = i;
    sprite_fill_clut(0x200, 9, 0xC, 0xC252);
    sprite_set_clut_entry(0x200, i + 9, 0x3FF);
    se = 1;
    if (card->load_mode == 0) {
        se = 0xF;
    }
    sound_se_play(se);
}

static s16 menu_card_handle_input(CardMenu *card) {
    s32 cmd;
    s32 result;
    s32 ok;
    s32 pressed;
    s32 se;
    SceneRequest *req;

    req = &scene_request;
    if (kaj_system_pad_mode[0] != 1 || card->message == 0x65 || card->message == 0x6C) {
        return 0;
    }
    if (card->message == -1) {
        return 1;
    }
    if (card->message == 0x66 || card->message == 0x67) {
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
                    card->message = -1;
                    card->job = 0;
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
            switch (card->message) {
            case 0x64:
            case 0x68:
                if (card->load_mode != 0) {
                    card->job = 0xC;
                    se = 2;
                } else {
                    card->job = 0xD;
                }
                card->message = -1;
                break;
            case 0x69:
                if (card->load_mode != 0) {
                    break;
                }
                card->job = 0xA;
                card->message = -1;
                break;
            case 0x66:
            case 0x67:
                card->job = 0;
                card->message = -1;
                break;
            case 0x6A:
                if (card->load_mode != 0) {
                    card->job = 0;
                }
                card->message = -1;
                break;
            case 0x6B:
                card->job = 0xE;
                card->message = -1;
                break;
            default:
                pressed = 0;
                break;
            }
        } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            if (card->message == 0x6B || (card->load_mode == 0 && card->message == 0x6A)) {
                pressed = 1;
                se = 8;
                menu_card_set_message(card, 0x64);
            } else {
                sound_se_play(8);
                mail_wait(3, 0, 0, 1);
                req->change = 1;
            }
        } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
            if (card->message == 0x64) {
                menu_card_move_cursor(card, 1);
            }
        } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
            if (card->message == 0x64) {
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

static void menu_card_process(CardMenu *card) {
    s32 cmd;
    s32 result;
    s32 r;
    s32 a;

    switch (MemCardSync(1, &cmd, &result)) {
    case 0:
        break;
    case -1:
        switch (card->job) {
        case 0:
            MemCardExist(0);
            break;
        case 10:
            r = MemCardFormat(0);
            if (r == 0) {
                card->job = 0xB;
                card->message = -1;
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
                card->job = 0xB;
                card->card_found = a;
                card->message = -1;
            } else if (result == 3) {
                card->card_found = a;
                MemCardAccept(0);
            } else {
                menu_card_set_message(card, result);
            }
            break;
        case 2:
            if (result == 0 || result == 3) {
                card->job = 0xB;
                card->message = -1;
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
    CardMenu *card;
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
    card->load_mode = load_mode;
    card->loaded = 0;
    card->in_office = in_office;
    card->message = -1;
    card->job = 0;
    menu_card_init_slots(card, 0);
    MemCardStart();
    kaj_timer_enable();
    kaj_pad_reset(1);
    while (done == 0) {
        switch (kaj_event_get(ev)) {
        case 0:
            ready = menu_card_handle_input(card);
            if ((s16)mail_take_scene_change() != 0) {
                if (in_office != 0 || (card->loaded != 0 && load_mode != 0)) {
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
    return card->loaded;
}
