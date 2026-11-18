#include "common.h"
#include "game/effect.h"
#include "game/block.h"
#include "game/building.h"
#include "game/dialog.h"
#include "game/door.h"
#include "game/event.h"
#include "game/main.h"
#include "game/menu.h"
#include "game/mod.h"
#include "game/object.h"
#include "game/player.h"
#include "game/sound.h"
#include "game/sprite.h"
#include "game/thing.h"
#include "kaj/event.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "kaj/timer.h"
#include "kaj/tss.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libgpu.h"
#include "psyq/libgte.h"

/*
 * Screen and sprite effects, flames, the elevator, and the weapon and item inventory.
 *
 * File boundaries: likely (docs/layout.md): effect.c asserts.
 */

extern ScreenLight roadmap_screen_light;
extern GameVars action_vars;
extern EffectAlarm effect_alarms[4];
void *effect_flame_small_bufs;
void *effect_flame_small_bufs_1;
extern s16 action_vars_flame_small_on[];
Rect effect_clut_cycle_rect;
extern u16 effect_clut_cycle_buf[];
extern s16 action_vars_clut_cycle_on[];
void *effect_flame_large_bufs;
void *effect_flame_large_bufs_1;
extern s16 action_vars_flame_large_on[];
Rect effect_clut_rotate_rect;
/* Local view of Sprite: cell_h is read as s16 here (lh), the shared type has a u16. */
typedef struct Sprite_u80185A60 {
    u8 unk0[4];
    s16 visible;
    u8 unk6[6];
    s16 y;
    u8 unkE[4];
    s16 cell_h;
    s16 columns;
    s16 rows;
    s16 cell_col;
    s16 cell_row;
} Sprite_u80185A60;
s16 effect_slide_height;
s16 effect_slide_y;
typedef struct Elevator {
    u16 target_floor;
    u16 floor;
    u16 top_floor;
    s16 state;
} Elevator;
Elevator effect_elevator;
extern BuildingState building_state;
extern Inventory *player_status_inventory[];
extern SceneTables object_scene_tables;
Rect effect_flame_large_rect;
s16 effect_flame_large_cur;
extern char effect_str_sprite_not_found[];
extern char effect_str_file[];
static void effect_sprite_anim_step(TssSlot *task);
extern char effect_str_flame_alloc[];
Rect effect_flame_small_rect;
Rect effect_flame_small_clut_rect;
s16 effect_flame_small_kind;
s16 effect_flame_small_cur;
static void effect_flame_make_clut(s16 kind);
extern s32 event_effect_done_hook;
static void effect_elevator_enter(void);
static void effect_elevator_update(void);
static void effect_elevator_input(void);
extern SceneRequest main_scene_request[];
extern PlayerStatus player_status;
extern s16 effect_item_menu_list[];
s16 effect_item_sel;
s16 effect_item_full;
extern Player *player_status_player[];
static s32 effect_elevator_on_task_end(s32 *ev);
static void effect_sprite_slide_step(TssSlot *task);
static void effect_sprite_slide_end(TssSlot *task);
extern u8 effect_flame_small_cluts[][0x20];
extern char effect_str_elevator_prompt[];
void dialog_show(char *str, s32 mode, s32 circle_set, s32 circle_flags, s32 cross_set, s32 cross_flags, s32 se);
s16 effect_item_scene_kind;
s16 effect_item_prompt_shown;
typedef struct BuildingEntry { u16 entry; u16 unk2; u16 unk4; } BuildingEntry;
extern BuildingEntry building_state_entry;
extern char effect_str_scene_idc[];
extern char effect_str_scene_htl[];
extern char effect_str_scene_cmn[];
u16 effect_elevator_floor_count;
extern KajSystem kaj_system;
static void effect_elevator_exit(void);
static void effect_elevator_move_doors(Elevator *elevator, s16 open);
extern char effect_str_drank_heal[];
extern char effect_str_ate_heal[];
extern char effect_str_drank_hurt[];
extern char effect_str_ate_hurt[];
extern char effect_str_drank_too_much[];
extern char effect_str_ate_too_much[];
extern char effect_str_energy_full[];
extern char effect_str_wound_heal_some[];
extern char effect_str_body_lighter[];
extern char effect_str_wound_heal_much[];
extern char effect_str_wound_heal_full[];
extern char effect_str_body_much_lighter[];
/* refined: unk2 u16, unk4 text, unk26 s16 (was u8 unk2[0x26]) */
/* refined: unk26[0x22] split into unk26[6], s16 unk2C, unk2E[0x1A] */
void dialog_show_timed(s16 mode, s16 big, char *str, s16 se, s32 seconds);
extern s32 kaj_system_vsync_delta[];
static void effect_weapon_draw_panel(s16 show, s16 with_text);
extern char effect_str_item_prompt[];
static s16 effect_item_menu_show(PlayerStatus *status, s16 scene_kind, s16 open);
u16 roadmap_get_state(void);

void effect_start_sprite_slide(s32 kind, u16 sprite_id, s32 seconds) {
    GameVars *game = &action_vars;
    Sprite_u80185A60 *spr;
    TssSlot *node;

    spr = sprite_find(sprite_id);
    if (spr == NULL) {
        kaj_abend(5, effect_str_sprite_not_found, effect_str_file, 0x97);
    }
    effect_slide_y = spr->y;
    effect_slide_height = spr->cell_h;
    node = kaj_tss_alloc(4);
    seconds *= 30;
    node->type = kind;
    if (kind == 2 || kind == 3) {
        node->cur = (kind == 2) ? 0xF0 : spr->y;
        node->target = (kind == 2) ? spr->y : 0xF0;
    } else {
        node->cur = (kind == 0xB) ? 0xF0 : spr->y;
        node->target = (kind == 0xB) ? spr->y : 0xF0;
    }
    kaj_tss_set_steps(node, seconds);
    node->on_step = effect_sprite_slide_step;
    node->on_end = effect_sprite_slide_end;
    node->on_kill = effect_sprite_slide_end;
    *(Sprite_u80185A60 **)node->data = spr;
    if (kind == 2 || kind == 0xB) {
        spr->visible = 1;
        spr->y = 0xF0;
        spr->cell_h = 0;
    }
    game->effect_task = kaj_tss_start(node);
}

static void effect_flame_make_clut(s16 kind) {
    s16 rect[4];
    u16 buf[0x100];
    s32 i;
    s32 v;

    rect[1] = 0x1EE;
    rect[2] = 0x100;
    rect[3] = 1;
    rect[0] = 0;
    switch (kind) {
    case 0:
        for (i = 0; i < 0x40; i++) {
            buf[i] = ((i / 4) << 10) | 0x8000;
        }
        for (i = 0; i < 0x80; i++) {
            buf[i + 0x40] = ((i / 8) << 5) | 0xC000;
        }
        for (i = 0; i < 0x40; i++) {
            buf[i + 0xC0] = (i / 4) | 0xC200;
        }
        break;
    case 1:
        for (i = 0; i < 0x40; i++) {
            buf[i] = (i / 4) | ((i / 8) << 5) | 0x8000;
        }
        for (i = 0; i < 0x80; i++) {
            buf[i + 0x40] = ((i / 16 + 8) << 5) | 0x8010;
        }
        for (i = 0; i < 0x40; i++) {
            buf[i + 0xC0] = ((i / 4) << 10) | 0x8210;
        }
        break;
    case 2:
        for (i = 0; i < 0x100; i++) {
            v = i / 8;
            buf[i] = v | (v << 5) | (v << 10) | 0x8000;
        }
        break;
    }
    LoadImage2(rect, buf);
}

void effect_flame_small_update(void) {
    void **bufs = &effect_flame_small_bufs;
    u8 *src = bufs[effect_flame_small_cur];
    s16 next = effect_flame_small_cur ^ 1;
    u8 *dst = bufs[next];
    u8 *pal;
    s32 i;
    s32 j;
    s32 v;
    s32 w;
    s32 k;

    if (src != 0 && dst != 0) {
        pal = 0;
        if (effect_flame_small_kind == 1) {
            pal = effect_flame_small_cluts[effect_flame_small_cur];
        }
        effect_flame_small_cur = next;
        v = 0;
        for (i = 0; i < 0x10; i++) {
            if (rand() % 100 < 50) {
                v = rand() % 2 * 255;
            }
            *(dst + i + 0x1E0) = v;
            *(dst + i + 0x1F0) = v;
        }
        for (i = 0x1E0; i >= 0x20; i -= 0x10) {
            for (j = 1; j < 0xF; j++) {
                k = i + j;
                w = *(src + k + 0x10);
                w += *(src + k + 1);
                w += *(src + k - 1);
                w += *(src + k - 0xF);
                w += *(src + k - 0x11);
                w /= 5;
                if (w >= 5) {
                    w -= 4;
                }
                *(dst + k - 0x10) = w;
            }
        }
        if (pal != 0) {
            LoadImage2(&effect_flame_small_clut_rect, pal);
        }
        LoadImage2(&effect_flame_small_rect, dst);
    }
}

void effect_flame_large_update(void) {
    void **bufs = &effect_flame_large_bufs;
    u8 *src = bufs[effect_flame_large_cur];
    s16 next = effect_flame_large_cur ^ 1;
    u8 *dst = bufs[next];
    s32 i;
    s32 j;

    if (src != 0 && dst != 0) {
        effect_flame_large_cur = next;
        for (i = 0; i < 0x20; i++) {
            *(dst + i + 0x3E0) = rand() % 256;
        }
        for (i = 0x3C0; i >= 0; i -= 0x20) {
            for (j = 1; j < 0x1F; j++) {
                dst[i + j] = (src[i + j] + src[i + j + 0x1F] * 2 + src[i + j + 0x20] * 3 + src[i + j + 0x21] * 2) >> 3;
            }
        }
        LoadImage2(&effect_flame_large_rect, dst);
    }
}

void effect_start_fade(s32 kind, s32 seconds) {
    GameVars *game = &action_vars;
    ScreenLight *light = &roadmap_screen_light;
    TssSlot *node;

    node = kaj_tss_alloc(4);
    seconds *= 30;
    node->type = kind;
    switch (kind) {
    case 0:
    case 9:
        node->cur = 0;
        node->target = 0x1000;
        break;
    case 1:
    case 10:
        node->cur = 0x1000;
        node->target = 0;
        break;
    }
    light->fade_level = node->cur;
    light->fade_active = 1;
    kaj_tss_set_steps(node, seconds);
    node->on_step = door_fade_step;
    node->on_end = door_fade_step;
    *(s32 *)node->data = kind;
    game->effect_task = kaj_tss_start(node);
}

void effect_fade_reset(void) {
    ScreenLight *light = &roadmap_screen_light;
    if (light->fade_active != 0) {
        light->fade_level = 0x1000;
        light->fade_active = 0;
    }
}

void effect_fade_set_black(void) {
    ScreenLight *light = &roadmap_screen_light;
    if (light->fade_active == 0) {
        light->fade_level = 0;
        light->fade_active = 1;
    }
}

void effect_fade_set_dim(void) {
    ScreenLight *light = &roadmap_screen_light;
    if (light->fade_active == 0) {
        light->fade_level = 0x400;
        light->fade_active = 1;
    }
}

void effect_start_sprite_anim(u16 sprite_id, s32 seconds) {
    GameVars *game = &action_vars;
    Sprite_u80185A60 *spr;
    TssSlot *node;

    spr = sprite_find(sprite_id);
    if (spr == NULL) {
        kaj_abend(5, effect_str_sprite_not_found, effect_str_file, 0xCC);
    }
    node = kaj_tss_alloc(4);
    node->type = 6;
    node->cur = 1;
    node->target = spr->columns * spr->rows;
    node->step = 1;
    node->on_step = effect_sprite_anim_step;
    node->on_end = effect_sprite_anim_step;
    seconds *= 30;
    node->delay = seconds / node->target;
    *(Sprite_u80185A60 **)node->data = spr;
    spr->cell_col = 0;
    spr->cell_row = 0;
    spr->visible = 1;
    game->effect_task = kaj_tss_start(node);
}

void effect_clear_alarms(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        action_vars.alarms[i].active = 0;
        action_vars.alarms[i].alarm = -1;
        kaj_event_flush(2, i + 0x64);
    }
}

void effect_start_alarm(s32 slot, s32 code, s32 delay) {
    EffectAlarm *alarm_slot = &effect_alarms[slot];

    if (alarm_slot->active == 0) {
        alarm_slot->alarm = kaj_event_set_alarm(delay * 60, slot + 0x64, code);
        if (alarm_slot->alarm >= 0) {
            alarm_slot->active = 1;
        }
    }
}

void effect_flame_small_init(s16 kind) {
    void *buf0;
    void *buf1;
    Rect *rect = &effect_flame_small_rect;
    Rect *clut_rect;

    rect->x = 0x1B0;
    rect->y = 0xE0;
    rect->w = 8;
    rect->h = 0x20;
    clut_rect = &effect_flame_small_clut_rect;
    clut_rect->x = 0x100;
    clut_rect->y = 0x1ED;
    clut_rect->w = 0x10;
    clut_rect->h = 1;
    effect_flame_make_clut(kind);
    buf0 = kaj_malloc(0x200);
    buf1 = kaj_malloc(0x200);
    if (buf0 == 0 || buf1 == 0) {
        kaj_abend(3, effect_str_flame_alloc, effect_str_file, 0x16E);
    }
    effect_flame_small_kind = kind;
    effect_flame_small_bufs = buf0;
    effect_flame_small_bufs_1 = buf1;
    effect_flame_small_cur = 0;
}

void effect_flame_small_free(void) {
    s32 i;
    void **bufs = &effect_flame_small_bufs;

    action_vars_flame_small_on[0] = 0;
    for (i = 0; i < 2; i++) {
        if (bufs[i] != 0) {
            free3(bufs[i]);
            bufs[i] = 0;
        }
    }
}

void effect_clut_cycle_update(void) {
    s32 i;
    u16 first = effect_clut_cycle_buf[1];

    for (i = 1; i < 14; i++) {
        effect_clut_cycle_buf[i] = effect_clut_cycle_buf[i + 1];
    }
    effect_clut_cycle_buf[14] = first;
    LoadImage2(&effect_clut_cycle_rect, effect_clut_cycle_buf);
}

void effect_clut_cycle_init(void) {
    Rect *rect = &effect_clut_cycle_rect;

    rect->x = 0x60;
    rect->y = 0x1E6;
    rect->w = 0x10;
    rect->h = 1;
    StoreImage2(rect, effect_clut_cycle_buf);
    action_vars_clut_cycle_on[0] = 0;
}

void effect_flame_large_init(void) {
    void *buf0;
    void *buf1;
    Rect *rect = &effect_flame_large_rect;

    rect->x = 0x1B0;
    rect->y = 0xC0;
    rect->w = 0x10;
    rect->h = 0x20;
    buf0 = kaj_malloc(0x400);
    buf1 = kaj_malloc(0x400);
    if (buf0 == 0 || buf1 == 0) {
        kaj_abend(3, effect_str_flame_alloc, effect_str_file, 0x1CA);
    }
    effect_flame_large_bufs = buf0;
    effect_flame_large_bufs_1 = buf1;
    effect_flame_large_cur = 0;
}

void effect_flame_large_free(void) {
    s32 i;
    void **bufs = &effect_flame_large_bufs;

    action_vars_flame_large_on[0] = 0;
    for (i = 0; i < 2; i++) {
        if (bufs[i] != 0) {
            free3(bufs[i]);
            bufs[i] = 0;
        }
    }
}

void effect_clut_rotate(void) {
    u16 buf[16];
    s32 i;
    u16 last;

    StoreImage2(&effect_clut_rotate_rect, buf);
    last = buf[15];
    for (i = 15; i > 0; i--) {
        buf[i] = buf[i - 1];
    }
    buf[0] = last;
    LoadImage2(&effect_clut_rotate_rect, buf);
}

static void effect_sprite_slide_step(TssSlot *task) {
    Sprite_u80185A60 *sprite = *(Sprite_u80185A60 **)task->data;
    s16 height;

    sprite->y = task->cur;
    height = 0xF0 - task->cur;
    sprite->cell_h = height;
    if (effect_slide_height < height) {
        sprite->cell_h = effect_slide_height;
    }
}

static void effect_sprite_slide_end(TssSlot *task) {
    Sprite_u80185A60 *sprite = *(Sprite_u80185A60 **)task->data;
    GameVars *game = &action_vars;

    sprite->y = effect_slide_y;
    sprite->cell_h = effect_slide_height;
    if (task->type == 3 || task->type == 0xC) {
        sprite->visible = 0;
    }
    game->effect_task = -1;
}

static void effect_sprite_anim_step(TssSlot *task) {
    Sprite_u80185A60 *sprite = *(Sprite_u80185A60 **)task->data;

    sprite->cell_col = (task->cur - 1) / sprite->rows;
    sprite->cell_row = (task->cur - 1) % sprite->rows;
}

static s32 effect_elevator_on_task_end(s32 *ev) {
    Player *player = player_status_player[0];
    Elevator *elevator = &effect_elevator;
    Door *door;
    s32 i;

    if (ev[4] != 4) {
        return 0;
    }
    if (player->flags & 0x80) {
        kaj_pad_reset(1);
        sprite_set_visible(2, 1);
        dialog_show(effect_str_elevator_prompt, 3, -1, 0, -1, 0, 1);
        return 0;
    }
    for (i = 0; i < 2; i++) {
        door = door_find(((u16)elevator->floor - 1) * 2 + i);
        if (door != NULL) {
            door->state = 0;
            switch ((u16)door->axis) {
            case 1:
                door->pos_x = door->move_from;
                break;
            case 2:
                door->pos_y = door->move_from;
                break;
            case 3:
                door->pos_z = door->move_from;
                break;
            }
            door->coord_tx = door->pos_x - player->cell_x * 0x30D4;
            door->coord_ty = door->pos_y + player->cell_y * 0x7D00;
            door->coord_tz = door->pos_z - player->cell_z * 0x30D4;
            door->coord_flg = 0;
        }
    }
    return 1;
}

static void effect_elevator_exit(void) {
    Player *player = player_status_player[0];
    s32 x;
    s32 z;

    sprite_set_visible(2, 0);
    kaj_pad_reset(0);
    x = rsin((player->yaw << 12) / 360) * 0x1194 >> 12;
    z = rcos((player->yaw << 12) / 360) * 0x1194 >> 12;
    x += player->pos_x + player->cell_x * 0x30D4;
    z += player->pos_z + player->cell_z * 0x30D4;
    player_start_move_to(2, 0x80, x, player->pos_y - player->cell_y * 0x7D00 - player->eye_height, z, player->pitch, player->yaw, player->roll, 2);
}

static void effect_elevator_move_doors(Elevator *elevator, s16 open) {
    SceneRequest *request = main_scene_request;
    Door *door;
    s16 v;
    s32 i;

    kaj_pad_reset(0);
    for (i = 0; i < 2; i++) {
        door = door_find((elevator->floor - 1) * 2 + i);
        if (door == NULL) {
            continue;
        }
        if (open != 0) {
            if (building_state.building == 0) {
                switch (building_state_entry.entry) {
                case 28:
                    v = i * 0x140 - 0xA0;
                    break;
                case 7:
                    v = i * 0xB4 - 0x5A;
                    break;
                case 15:
                    v = i * 0xF0 - 0x78;
                    break;
                }
            }
            door_start_open(door, v, 3, 0);
            elevator->state = 2;
        } else {
            memset(&request[1], 0, 4);
            ((s16 *)&request->pos_x)[1] = 0x41;
            ((s16 *)&request->pos_y)[0] = elevator->target_floor;
            if (building_state.building == 0) {
                switch (building_state_entry.entry) {
                case 28:
                    strncpy((char *)&request[1], effect_str_scene_idc, 3);
                    ((s16 *)&request->pos_y)[1] = 0xB4;
                    v = (door->move_from - door->pos_x) / 10;
                    break;
                case 7:
                    strncpy((char *)&request[1], effect_str_scene_htl, 3);
                    ((s16 *)&request->pos_y)[1] = 0x5A;
                    v = (door->move_from - door->pos_z) / 10;
                    break;
                case 15:
                    strncpy((char *)&request[1], effect_str_scene_cmn, 3);
                    ((s16 *)&request->pos_y)[1] = 0xB4;
                    v = (door->move_from - door->pos_x) / 10;
                    break;
                }
            }
            door_start_close(door, v, 3);
            elevator->state = 1;
        }
    }
    sound_se_play(0xB);
}

static void effect_elevator_input(void) {
    Elevator *elevator = &effect_elevator;

    if (kaj_system.pad_mode != 1) {
        return;
    }
    kaj_pad_read();
    if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
        sound_se_play(0xF);
        effect_elevator.target_floor++;
        if (effect_elevator_floor_count < effect_elevator.target_floor) {
            effect_elevator.target_floor = 1;
        }
        sprite_fill_clut(2, 1, 8, 0x421);
        if (elevator->floor == effect_elevator.target_floor) {
            sprite_set_clut_entry(2, effect_elevator.target_floor, 0x16BF);
        } else {
            sprite_set_clut_entry(2, effect_elevator.target_floor, 0x17FF);
            sprite_set_clut_entry(2, elevator->floor, 0x14BF);
        }
    } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
        Elevator *elevator2 = &effect_elevator;

        sound_se_play(0xF);
        effect_elevator.target_floor--;
        if (effect_elevator.target_floor == 0) {
            effect_elevator.target_floor = elevator2->top_floor;
        }
        sprite_fill_clut(2, 1, 8, 0x421);
        if (elevator2->floor == effect_elevator.target_floor) {
            sprite_set_clut_entry(2, effect_elevator.target_floor, 0x16BF);
        } else {
            sprite_set_clut_entry(2, effect_elevator.target_floor, 0x17FF);
            sprite_set_clut_entry(2, elevator2->floor, 0x14BF);
        }
    } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
        sound_se_play(8);
        dialog_close();
        effect_elevator_exit();
    } else if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
        if (elevator->floor != elevator->target_floor) {
            mod_free_pooled();
            sound_se_play(0x11);
            dialog_close();
            effect_elevator_move_doors(elevator, 0);
        }
    }
}

static void effect_elevator_enter(void) {
    Player *player;
    Elevator *elevator;
    s32 x;
    s32 y;
    s32 z;

    event_effect_done_hook = (s32)effect_elevator_on_task_end;
    player = player_status_player[0];
    sprite_fill_clut(2, 1, 8, 0x421);
    elevator = &effect_elevator;
    if ((u16)elevator->floor == (u16)effect_elevator.target_floor) {
        sprite_set_clut_entry(2, (u16)effect_elevator.target_floor, 0x16BF);
    } else {
        sprite_set_clut_entry(2, (u16)effect_elevator.target_floor, 0x17FF);
        sprite_set_clut_entry(2, (u16)elevator->floor, 0x14BF);
    }
    x = player->pos_x + player->cell_x * 0x30D4;
    y = player->pos_y - player->cell_y * 0x7D00 - player->eye_height;
    z = player->pos_z + player->cell_z * 0x30D4;
    kaj_timer_enable();
    player_start_move_to(0, 0, x, y, z, player->pitch, (s16)(player->yaw + 0xB4), player->roll, 2);
}

static inline u16 effect_elevator_door_state(s32 floor) {
    Door *door = door_find(((floor - 1) * 2) | 1);
    if (door == NULL) {
        return 5;
    }
    return door->state;
}

static void effect_elevator_update(void) {
    Player *player = player_status_player[0];
    Elevator *elevator = &effect_elevator;
    u16 door_state;

    switch ((u16)elevator->state) {
    case 0:
        break;
    case 3:
        block_set_mode(1);
        player->flags |= 0x80;
        elevator->state = 4;
        break;
    case 4:
        sound_se_stop(0x12);
        effect_elevator_move_doors(elevator, 1);
        kaj_system_vsync_delta[0] = 0;
        break;
    default:
        door_state = effect_elevator_door_state((u16)elevator->floor);
        if ((u16)door_state == 1 && (u16)elevator->state == 2) {
            elevator->state = 0;
            kaj_pad_reset(1);
            dialog_show(effect_str_elevator_prompt, 3, -1, 0, -1, 0, (u16)door_state);
        }
        if ((u16)door_state == 0 && (u16)elevator->state == 1) {
            elevator->floor = elevator->target_floor;
            sprite_fill_clut(2, 1, 8, 0x421);
            if ((u16)elevator->floor == (u16)elevator->target_floor) {
                sprite_set_clut_entry(2, (u16)elevator->target_floor, 0x16BF);
            } else {
                sprite_set_clut_entry(2, (u16)elevator->target_floor, 0x17FF);
                sprite_set_clut_entry(2, (u16)elevator->floor, 0x14BF);
            }
            elevator->state = 3;
            sound_se_play(0x12);
        }
        break;
    }
}

void effect_elevator_run(void) {
    s32 buf[6];
    s16 done = 0;

    effect_elevator_enter();
    do {
        switch (kaj_event_get(buf)) {
        case 4:
            event_handle_tick(0);
            continue;
        case 0:
            effect_elevator_update();
            effect_elevator_input();
            break;
        case 0x100:
            done = event_handle_effect_done(buf);
            continue;
        default:
            kaj_event_done(buf);
            continue;
        }
        main_step_frame(1, 1, 1);
    } while (done == 0);
    kaj_timer_disable();
    event_effect_done_hook = 0;
}

void effect_elevator_init(s16 floor) {
    Elevator *elevator = &effect_elevator;
    BuildingState *bstate;

    elevator->target_floor = floor;
    elevator->floor = floor;
    elevator->state = 0;
    if (building_state.building == 0) {
        bstate = &building_state;
        switch (bstate->entry) {
        case 28:
            elevator->top_floor = 3;
            break;
        case 7:
            elevator->top_floor = 4;
            break;
        case 15:
            elevator->top_floor = 3;
            break;
        }
    }
}

s32 effect_weapon_unequip(s16 weapon_id) {
    PlayerStatus *status = &player_status;
    Inventory *inv = status->inventory;
    Player *player = status->player;
    void *model;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (inv->weapon_ids[i] == weapon_id) {
            mod_free_by_id(weapon_id + 0x400);
            inv->weapon_count--;
            inv->weapon_ids[i] = -1;
            inv->weapon_rate[i] = 0;
            if (inv->weapon_slot == 0 && i == 0) {
                inv->weapon_slot = 1;
            } else if (inv->weapon_slot == 1 && i == 1) {
                inv->weapon_slot = 0;
            } else {
                return 1;
            }
            model = mod_find(inv->weapon_ids[inv->weapon_slot] + 0x400);
            inv->weapon_model = (s32)model;
            if (model != 0) {
                mod_setup(model, player->coord, 1, 0);
            }
            effect_weapon_calc_rate(inv->weapon_slot);
            return 1;
        }
    }
    return 0;
}

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_sprite_not_found);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_file);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_flame_alloc);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_elevator_prompt);

static void effect_weapon_draw_panel(s16 show, s16 with_text) {
    Inventory *inv = player_status_inventory[0];
    WeaponRecord *weapon;
    s16 id;
    s16 bar;

    if (with_text != 0) {
        sprite_set_visible(0x401, show);
        sprite_set_visible(0x402, show);
    }
    if (show != 0) {
        id = inv->weapon_ids[inv->weapon_slot];
        weapon = effect_weapon_find(id);
        if (weapon != NULL) {
            bar = (s16)weapon->req_level >> 3;
            sprite_fill_clut(0x401, 0x10, bar + 0x10, 0x67FF);
            sprite_fill_clut(0x401, bar + 0x11, 0x2F, 0x3D40);
            bar = weapon->damage >> 3;
            sprite_fill_clut(0x401, 0x40, bar + 0x40, 0x67FF);
            sprite_fill_clut(0x401, bar + 0x41, 0x5F, 0x3D40);
            bar = weapon->accuracy / 3 - 1;
            if (bar < 0) {
                bar = 0;
            }
            sprite_fill_clut(0x401, 0x70, bar + 0x70, 0x67FF);
            sprite_fill_clut(0x401, bar + 0x71, 0x8F, 0x3D40);
            sprite_fill_clut(0x401, 0xC, 0xE, 0xD20);
            switch (weapon->weapon_class) {
            case 0:
                sprite_set_clut_entry(0x401, 0xC, 0xD3F);
                break;
            case 1:
            case 2:
                sprite_set_clut_entry(0x401, 0xD, 0xD3F);
                break;
            case 3:
                sprite_set_clut_entry(0x401, 0xE, 0xD3F);
                break;
            }
            sprite_set_cell(0x402, (s16)(id / 9), (s16)(id % 9));
            if (with_text != 0) {
                /* weapon menu prompt: equip or unequip */
                dialog_show("  8\225\220\212\3551\202\360\225\373\214\374\203L\201[\217\343\211\272\202\305,  \221I\202\361\202\305\211\272\202\263\202\242,    \225\220\221\225 3\201\233 1\225\220\221\225\211\360\217\234 4\201~", 3, -1, 0, -1, 0, 1);
            }
        }
    } else {
        dialog_close();
    }
}

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_drank_heal);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_ate_heal);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_drank_hurt);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_ate_hurt);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_drank_too_much);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_ate_too_much);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_energy_full);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_wound_heal_some);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_body_lighter);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_wound_heal_much);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_wound_heal_full);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_body_much_lighter);

INCLUDE_RODATA("asm/nonmatchings/game/effect", effect_str_item_prompt);

void effect_weapon_calc_rate(s32 slot) {
    PlayerStatus *status = &player_status;
    Inventory *inv = status->inventory;
    WeaponRecord *weapon = effect_weapon_find(inv->weapon_ids[slot]);
    s32 level_part, stat_part, skill_part, rate;
    s32 val;

    if (weapon == NULL) {
        return;
    }
    level_part = 0x2000;
    if (weapon->req_level_on != 0 && status->level < (s16)weapon->req_level) {
        level_part = (status->level << 13) / (s16)weapon->req_level;
    }
    stat_part = 0x1000;
    if (weapon->req_stat_on != 0) {
        switch (weapon->req_stat_id) {
        case 0:
            val = status->stat0;
            break;
        case 1:
            val = status->stat1;
            break;
        case 2:
            val = status->stat2;
            break;
        case 3:
            val = status->stat3;
            break;
        }
        if (val < weapon->req_stat) {
            stat_part = (val << 12) / weapon->req_stat;
        }
    }
    skill_part = 0x1000;
    if (weapon->req_class_on != 0) {
        switch (weapon->weapon_class) {
        case 0:
            val = status->weapon0_level;
            break;
        case 1:
            val = status->weapon1_level;
            break;
        case 2:
            val = status->weapon2_level;
            break;
        case 3:
            val = status->weapon3_level;
            break;
        case 4:
            val = status->weapon4_level;
            break;
        }
        if (val < weapon->req_class) {
            skill_part = (val << 12) / weapon->req_class;
        }
    }
    val = (weapon->accuracy * (level_part + stat_part + skill_part)) >> 14;
    rate = (val < 20) ? 20 : (val > 100) ? 100 : val;
    inv->weapon_rate[slot] = rate;
    status->weapon_redraw = 1;
}

void effect_weapon_swap_stock(s16 to_stock, s16 weapon_id) {
    Inventory *inv = player_status_inventory[0];
    PlayerStatus *status;
    Inventory *inv2;
    Player *player;
    void *model;
    s32 i;
    s32 j;

    inv->weapon_count = 0;
    for (j = 0; j < 2; j++) {
        if (inv->weapon_ids[j] >= 0) {
            inv->weapon_count++;
        }
    }
    if (to_stock != 0) {
        effect_weapon_unequip(weapon_id);
        inv->weapon_stock[weapon_id]++;
    } else {
        status = &player_status;
        inv2 = status->inventory;
        player = status->player;
        for (i = 0; i < 2; i++) {
            if (inv2->weapon_ids[i] < 0) {
                inv2->weapon_ids[i] = weapon_id;
                model = mod_find(weapon_id + 0x400);
                if (model != 0) {
                    mod_setup(model, player->coord, 1, 0);
                }
                effect_weapon_calc_rate(i);
                break;
            }
        }
        inv->weapon_stock[weapon_id]--;
    }
    inv->weapon_count = 0;
}

s32 effect_inventory_has_room(s16 kind) {
    Inventory *inv = player_status_inventory[0];
    s32 i;
    s16 n;

    switch (kind) {
    case 0:
        for (i = 0, n = 0; i < 8; i++) {
            if ((u16)inv->item_ids[i] < 100) {
                n++;
            }
        }
        if (n >= 5) {
            break;
        }
        for (i = 0; i < 8; i++) {
            if (inv->item_ids[i] < 0) {
                return 1;
            }
        }
        break;
    case 1:
    case 3:
        for (i = 0; i < 8; i++) {
            if (inv->item_ids[i] < 0) {
                return 1;
            }
        }
        return 0;
    case 4:
        for (i = 0; i < 2; i++) {
            if (inv->weapon_ids[i] < 0) {
                return 1;
            }
        }
        return 0;
    case 2:
        return 1;
    }
    return 0;
}

static inline void effect_weapon_cycle(s32 step) {
    Inventory *inv;
    s32 slot;
    void *model;
    s32 id;
    inv = player_status_inventory[0];
    if (inv->weapon_count != 2) {
        return;
    }
    sound_se_play(0xF);
    slot = inv->weapon_slot;
    slot += step;
    if (slot >= 2) {
        slot = 0;
    } else if (slot < 0) {
        slot = 1;
    }
    inv->weapon_slot = slot;
    id = inv->weapon_ids[slot];
    model = mod_find(id + 0x400);
    effect_weapon_draw_panel(1, 0);
    effect_weapon_calc_rate(slot);
    if (model == NULL) {
        return;
    }
    inv->weapon_model = (s32)model;
    mod_set_anim(model, 5, 0);
}

s32 effect_weapon_input(PlayerStatus *status) {
    GameVars *game = &action_vars;
    Player *player = status->player;
    Inventory *inv = status->inventory;

    if (player->flags & 0x8000) {
        if (inv->weapon_shown == 0) {
            player->flags &= 0x7FFF;
            inv->weapon_state = 0;
        }
        if ((u16)inv->weapon_state != 2) {
            return 1;
        }
        if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
            effect_weapon_cycle(1);
        } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
            effect_weapon_cycle(-1);
        } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
            sound_se_play(8);
            effect_weapon_draw_panel(0, 1);
            inv->weapon_state = 1;
            mod_set_anim((void *)inv->weapon_model, 6, 0);
        } else if ((!(kaj_system.pad_prev & 0x100) && (kaj_system.pad_now & 0x100)) ||
                   (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20))) {
            sound_se_play(0x11);
            effect_weapon_draw_panel(0, 1);
            player->flags &= 0x7FFF;
            inv->weapon_state = 3;
            mod_set_anim((void *)inv->weapon_model, 0, 0);
        }
        return 1;
    }
    if ((u16)inv->weapon_state == 2 && inv->weapon_shown == 0) {
        inv->weapon_state = 0;
    }
    if (!(kaj_system.pad_prev & 0x100) && (kaj_system.pad_now & 0x100)) {
        if (*(s32 *)&game->menu_busy != 0) { /* this unit reads one word at 0x24C */
            return 0;
        }
        if ((u16)inv->weapon_state == 0) {
            sound_se_play(0x13);
            player->flags |= 0x8000;
            effect_weapon_draw_panel(1, 1);
            inv->weapon_shown = 1;
            mod_set_anim((void *)inv->weapon_model, 4, 0);
        } else if ((u16)inv->weapon_state == 3) {
            sound_se_play(0x13);
            player->flags |= 0x8000;
            effect_weapon_draw_panel(1, 1);
            inv->weapon_state = 2;
        }
    } else if ((!(kaj_system.pad_prev & 2) && (kaj_system.pad_now & 2)) ||
               (!(kaj_system.pad_prev & 1) && (kaj_system.pad_now & 1))) {
        if (inv->armed != 0) {
            if ((u16)inv->weapon_state == 3) {
                inv->weapon_state = 4;
                mod_set_anim((void *)inv->weapon_model, 1, 0);
            } else if ((u16)inv->weapon_state == 5) {
                inv->weapon_state = 6;
                mod_set_anim((void *)inv->weapon_model, 2, 0);
            }
        }
    }
    return 0;
}

s16 effect_item_use(PlayerStatus *status, s16 b, s16 item_id, s16 full, s16 close_text) {
    char buf[0x80];
    SceneTables *tables = &object_scene_tables;
    GameVars *game = &action_vars;
    ItemRecord *item;
    ItemRecord *rec;
    s32 count;
    s32 i;
    s32 j;
    s16 ret;
    s16 drink;
    s16 kind;
    s16 value;
    s32 injured;

    count = tables->item_count;
    rec = (ItemRecord *)tables->items;
    if (count != 0) {
        if (item_id < 0) {
            item = NULL;
            goto done;
        }
        for (j = 0; j < count; j++, rec++) {
            if (rec->id == item_id) {
                item = rec;
                goto done;
            }
        }
    }
    item = NULL;
done:
    if (item == NULL) {
        return -1;
    }
    memset(buf, 0, 0x80);
    ret = 0;
    kind = 3;
    drink = 0;
    if ((u16)(item_id - 0x27) < 4 || (u16)(item_id - 0x2F) < 4) {
        drink = 1;
    }
    switch (item->kind) {
    case 0:
        value = item->value;
        if (value < 0) {
            if (status->mutant != 0) {
                player_add_hp(-value, 0);
                if (drink) {
                    /* drink restored energy */
                    sprintf(buf, effect_str_drank_heal, item->name);
                } else {
                    /* food restored energy */
                    sprintf(buf, effect_str_ate_heal, item->name);
                }
            } else {
                kind = 4;
                player_add_hp(value, 0);
                player_heal_part(3, 2, item->value);
                if (drink) {
                    /* drink lowered energy */
                    sprintf(buf, effect_str_drank_hurt, item->name);
                } else {
                    /* food lowered energy */
                    sprintf(buf, effect_str_ate_hurt, item->name);
                }
            }
        } else if (full != 0) {
            kind = 4;
            player_add_hp(-(value / 2), 0);
            player_heal_part(3, 2, -item->value);
            if (drink) {
                /* drank too much, energy lowered */
                strncpy(buf, effect_str_drank_too_much, 0x38);
            } else {
                /* ate too much, energy lowered */
                strncpy(buf, effect_str_ate_too_much, 0x38);
            }
        } else {
            player_add_hp(value, 0);
            if (drink) {
                /* drink restored energy */
                sprintf(buf, effect_str_drank_heal, item->name);
            } else {
                /* food restored energy */
                sprintf(buf, effect_str_ate_heal, item->name);
            }
            if (status->energy == 0xFF && full == 0) {
                ret = 1;
                dialog_show_timed(b, 1, buf, kind, 2);
                memset(buf, 0, 0x80);
                /* energy back to full */
                strncpy(buf, effect_str_energy_full, 0x29);
            }
        }
        dialog_show_timed(b, 1, buf, kind, 2);
        break;
    case 3:
        injured = player_is_injured();
        if ((s16)injured != 0) {
            for (i = 0; i < 5; i++) {
                (game->vars + 0x5A)[i] -= item->value;
                if ((s16)(game->vars + 0x5A)[i] < 0) {
                    (game->vars + 0x5A)[i] = 0;
                }
            }
            event_draw_limb_status(status);
        }
        memset(buf, 0, 0x80);
        switch (item->value) {
        case 60:
            if ((s16)injured != 0) {
                /* wounds healed, small cure */
                strncpy(buf, effect_str_wound_heal_some, 0x11);
            } else {
                /* no wound: body line, small cure */
                strncpy(buf, effect_str_body_lighter, 0x11);
            }
            break;
        case 180:
            if ((s16)injured != 0) {
                /* wounds healed, medium cure */
                strncpy(buf, effect_str_wound_heal_much, 0x13);
            } else {
                /* no wound: body line, medium cure */
                strncpy(buf, effect_str_body_lighter, 0x11);
            }
            break;
        case 360:
            if ((s16)injured != 0) {
                /* wounds healed, full cure */
                strncpy(buf, effect_str_wound_heal_full, 0x13);
            } else {
                /* no wound: body line, full cure */
                strncpy(buf, effect_str_body_much_lighter, 0x17);
            }
            break;
        }
        event_advance_clock(item->value, 1);
        dialog_show(buf, 1, -1, 0, -1, 0, kind);
        break;
    case 1:
        break;
    default:
        return -1;
    }
    if (close_text != 0) {
        dialog_close();
    }
    return ret;
}

void effect_item_use_selected(void) {
    PlayerStatus *status = &player_status;
    Inventory *inv;
    s16 id;
    s16 result;
    s32 i;

    if (effect_item_sel >= 0) {
        id = effect_item_menu_list[effect_item_sel];
        result = effect_item_use(status, main_scene_request[0].loop, id, effect_item_full, 1);
        if (result >= 0) {
            if (result != 0) {
                effect_item_full = 1;
            }
            inv = status->inventory;
            if (inv->item_count != 0) {
                for (i = 0; i < 8; i++) {
                    if (inv->item_ids[i] == id) {
                        inv->item_ids[i] = -1;
                        inv->item_count--;
                        return;
                    }
                }
            }
        }
    }
}

static s16 effect_item_menu_show(PlayerStatus *status, s16 scene_kind, s16 open) {
    Inventory *inv = status->inventory;
    s32 i;
    s32 n;

    if (open != 0) {
        sound_se_play(0x13);
        effect_item_sel = -1;
        effect_item_prompt_shown = 0;
        effect_item_scene_kind = scene_kind;
        effect_item_full = 0;
        if (status->energy == 0xFF) {
            effect_item_full = 1;
        }
        for (i = 0; i < 8; i++) {
            effect_item_menu_list[i] = -1;
        }
        for (i = 0, n = 0; i < 8; i++) {
            if (inv->item_ids[i] >= 0) {
                effect_item_menu_list[n++] = inv->item_ids[i];
            }
        }
        return menu_open(1, 0x40B, -2, inv->item_count, 6, effect_item_menu_list, 4, 0x2969, 0x2BFF);
    }
    sound_se_play(effect_item_sel < 0 ? 8 : 0x11);
    return menu_close();
}

s16 effect_item_input(PlayerStatus *status, s16 scene_kind) {
    s16 n = scene_kind;
    Player *player = status->player;
    GameVars *game = &action_vars;
    Inventory *inv = status->inventory;

    if (player->flags & 0x4000) {
        if (menu_get_state() == 1) {
            if (effect_item_prompt_shown == 0) {
                effect_item_prompt_shown = 1;
                /* item menu prompt */
                dialog_show(effect_str_item_prompt, 3, -1, 0, -1, 0, 1);
            }
            if (!(kaj_system.pad_prev & 0x20) && (kaj_system.pad_now & 0x20)) {
                if (effect_item_sel < 0) {
                    effect_item_sel = 0;
                }
                effect_item_menu_show(status, n, 0);
            } else if (!(kaj_system.pad_prev & 0x40) && (kaj_system.pad_now & 0x40)) {
                if (effect_item_sel >= 0) {
                    effect_item_sel = -1;
                }
                effect_item_menu_show(status, n, 0);
            } else if (!(kaj_system.pad_prev & 0x1000) && (kaj_system.pad_now & 0x1000)) {
                effect_item_sel = menu_move(1);
            } else if (!(kaj_system.pad_prev & 0x4000) && (kaj_system.pad_now & 0x4000)) {
                effect_item_sel = menu_move(0);
            }
        }
        return 1;
    }
    if (inv->item_count == 0) {
        return 0;
    }
    if (roadmap_get_state() != 0) {
        return 0;
    }
    if (!(kaj_system.pad_prev & 0x800) && (kaj_system.pad_now & 0x800)) {
        if (*(s32 *)&game->menu_busy != 0) {
            return 0;
        }
        if (effect_item_menu_show(status, n, 1) != 0) {
            player->flags |= 0x4000;
        }
    }
    if (effect_item_prompt_shown != 0 && menu_get_state() == 0) {
        effect_item_prompt_shown = 0;
        dialog_close();
    }
    return 0;
}

s32 effect_weapon_add(s16 weapon_id, s16 stock) {
    PlayerStatus *status = &player_status;
    Inventory *inv = status->inventory;
    Player *player = status->player;
    void *model;
    s32 i;

    for (i = 0; i < 2; i++) {
        if (inv->weapon_ids[i] < 0) {
            inv->weapon_ids[i] = weapon_id;
            model = mod_find(weapon_id + 0x400);
            if (model != 0) {
                mod_setup(model, player->coord, 1, 0);
            }
            effect_weapon_calc_rate(i);
            return 1;
        }
    }
    if (stock != 0) {
        inv->weapon_stock[weapon_id]++;
    }
    return 0;
}

void effect_weapon_load_models(void) {
    PlayerStatus *status = &player_status;
    Inventory *inv = status->inventory;
    Player *player = status->player;
    GameVars *game = &action_vars;
    void *model;
    s32 i;
    u16 id;

    inv->armed = 1;
    object_load_weapon_mods();
    game->vars[0x3C] = 2;
    for (i = 0; i < 2; i++) {
        if (inv->weapon_ids[i] >= 0) {
            id = inv->weapon_ids[i] + 0x400;
            game->vars[0x3C]--;
            model = mod_find(id);
            if (model != 0) {
                mod_setup(model, player->coord, 1, 0);
                if (inv->weapon_slot == i) {
                    inv->weapon_model = (s32)model;
                }
            }
            effect_weapon_calc_rate(i);
        }
    }
    thing_set_animate(3, 7, 1);
    thing_set_flag10(3, 7, 1);
}

void effect_weapon_reset(void) {
    Inventory *inv = player_status_inventory[0];

    inv->weapon_shown = 0;
    inv->weapon_state = 0;
    inv->weapon_count = 0;
    inv->weapon_model = 0;
    inv->armed = 0;
}

void effect_weapon_check_fire_frame(s32 frame) {
    PlayerStatus *status = &player_status;
    Inventory *inv = status->inventory;
    Player *player = status->player;
    WeaponRecord *weapon = effect_weapon_find(inv->weapon_ids[inv->weapon_slot]);

    if (weapon != NULL && weapon->fire_frame == frame) {
        if (status->target_npc != 0) {
            if (!(player->flags & 0x400)) {
                player->flags |= 0x400;
            }
        }
        player_weapon_sound(weapon->id, 1);
    }
}

s32 effect_weapon_list(s16 equipped, s16 *count_out, s16 *ids_out) {
    Inventory *inv = player_status_inventory[0];
    s32 i;
    s32 n_equipped;
    s32 n_stocked;

    for (i = 0, n_equipped = 0; i < 2; i++) {
        if (inv->weapon_ids[i] >= 0) {
            if (equipped != 0) {
                ids_out[n_equipped] = inv->weapon_ids[i];
            }
            n_equipped++;
        }
    }
    for (i = 0, n_stocked = 0; i < 0x12; i++) {
        if (inv->weapon_stock[i] != 0) {
            if (equipped == 0) {
                ids_out[n_stocked] = i;
            }
            n_stocked++;
        }
    }
    if (equipped != 0) {
        if (n_equipped != 2) {
            return 0;
        }
        *count_out = n_equipped;
        return 1;
    }
    *count_out = n_stocked;
    if (n_equipped < 2 && n_stocked != 0) {
        return 1;
    }
    return 0;
}

void effect_weapon_free_records(void) {
    SceneTables *tables = &object_scene_tables;
    if (tables->weapon_count != 0) {
        if (tables->weapons != NULL) {
            free3(tables->weapons);
        }
        tables->weapon_count = 0;
        tables->weapons = NULL;
    }
}

WeaponRecord *effect_weapon_find(s16 id) {
    SceneTables *tables = &object_scene_tables;
    s32 n = tables->weapon_count;
    WeaponRecord *rec = tables->weapons;
    s32 i;
    if (n == 0 || id < 0) {
        return NULL;
    }
    for (i = 0; i < tables->weapon_count; i++, rec++) {
        if (rec->id == id) {
            return rec;
        }
    }
    return NULL;
}

s32 effect_item_add(s16 item_id, s16 kind) {
    Inventory *inv = player_status_inventory[0];
    s32 i;

    if (kind == 2) {
        inv->kind2_item = item_id - 0x64;
        return 1;
    }
    for (i = 0; i < 8; i++) {
        if (inv->item_ids[i] < 0) {
            inv->item_ids[i] = item_id;
            inv->item_count++;
            return 1;
        }
    }
    return 0;
}

s32 effect_item_remove(s16 item_id, s16 kind) {
    Inventory *inv = player_status_inventory[0];
    s32 i;

    if (kind == 2) {
        inv->kind2_item = 0xF;
        return 1;
    }
    if (inv->item_count == 0) {
        return 0;
    }
    for (i = 0; i < 8; i++) {
        if (inv->item_ids[i] == item_id) {
            inv->item_ids[i] = -1;
            inv->item_count--;
            return 1;
        }
    }
    return 0;
}

void effect_item_free_records(void) {
    SceneTables *tables = &object_scene_tables;
    if (tables->item_count != 0) {
        if (tables->items != 0) {
            free3((void *)tables->items);
        }
        tables->item_count = 0;
        tables->items = 0;
    }
}

ItemRecord *effect_item_find(s16 id) {
    SceneTables *tables = &object_scene_tables;
    s32 n = tables->item_count;
    ItemRecord *rec = (ItemRecord *)tables->items;
    s32 i;
    if (n == 0 || id < 0) {
        return NULL;
    }
    for (i = 0; i < tables->item_count; i++, rec++) {
        if (rec->id == id) {
            return rec;
        }
    }
    return NULL;
}
