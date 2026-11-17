#include "common.h"
#include "game/door.h"
#include "game/action.h"
#include "game/block.h"
#include "kaj/kaj.h"
#include "kaj/ll.h"
#include "kaj/misc.h"
#include "kaj/tss.h"
#include "kaj/view.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libgs.h"
#include "psyq/libgte.h"
#include "psyq/libsnd.h"
#include "gte.h"

/*
 * The doors: setup, open and close moves, commands, drawing.
 *
 * File boundaries: likely (docs/layout.md): door.c asserts; door_list through gp from door_refresh_all.
 */

s16 kaj_ll_at_tail(BlockList *list);
extern s32 kaj_system_vsync_delta[];
extern Player *player_status_player[];
extern EventState event_state;
extern s16 ai_door_noise;
DoorList *door_list;
extern s16 block_reloaded;
static void door_move_x(DoorMove *door);
static void door_move_y(DoorMove *door);
static void door_move_z(DoorMove *door);
static void door_move_angle(DoorMove *door);
typedef struct {
    u16 id;
    u16 axis;
    u16 param;
    u16 angle;
    u16 state;
    u8 padA[0x2];
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    u8 tmd[0x4];
} DoorRecord;

void door_setup(Door *door) {
    Player *player = player_status_player[0];
    DoorRecord *rec = door->record;
    SVector rot;

    door->id = rec->id;
    door->axis = rec->axis;
    door->ot_layer = rec->param;
    door->state = rec->state;
    door->pos_x = rec->pos_x * 10;
    door->pos_y = rec->pos_y * 10;
    door->pos_z = rec->pos_z * 10;
    door->angle = rec->angle;
    kaj_tmd_load(&door->tmd_objects, ((DoorRecord *)door->record)->tmd, &door->coord_flg);
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

static void door_move_x(DoorMove *door) {
    EventState *event;

    door->pos_x += kaj_system_vsync_delta[0] * door->speed;
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

static void door_move_y(DoorMove *door) {
    EventState *event;

    door->pos_y += kaj_system_vsync_delta[0] * door->speed;
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

static void door_move_z(DoorMove *door) {
    EventState *event;

    door->pos_z += kaj_system_vsync_delta[0] * door->speed;
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

static void door_move_angle(DoorMove *door) {
    EventState *event;

    door->angle += kaj_system_vsync_delta[0] * door->speed;
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
        if (door->active != 0 && door->visible != 0 && block_reloaded != 0) {
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

    ai_door_noise = 1;
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

    ai_door_noise = 1;
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

void door_exec_command(Action *action, EventState *event) {
    DoorList *list = door_list;
    ActionCmdShort *cmd = (ActionCmdShort *)action->cmd;
    DoorMove *door;
    DoorMove *found;
    u16 id = cmd->target;
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
        if (cmd->sub == 0) {
            if (found->state != 1) {
                dist = (s16)atoi(action->args[0]);
                speed = (s16)atoi(action->args[1]);
                door_start_open(found, dist, speed, atoi(action->args[2]));
                if (atoi(action->args[3]) == 1) {
                    event->state = 4;
                    event->wait_flags |= 4;
                }
            }
        } else {
            if (found->state != 0) {
                s32 close_dist = (s16)atoi(action->args[0]);
                door_start_close(found, close_dist, atoi(action->args[1]));
                if (atoi(action->args[2]) == 1) {
                    event->state = 4;
                    event->wait_flags |= 4;
                }
            }
        }
    }
}

DoorList *door_list;
extern char door_str_file[];
extern SceneTables object_scene_tables[];
extern ScreenLight screen_light;

void door_create(Door **out, u32 record_size) {
    *out = kaj_malloc(0x80);
    if (*out == NULL) {
        kaj_abend(3, "Error Allocating DOOR Pointer", door_str_file, 0x23);
    }
    (*out)->active = 0;
    (*out)->axis = 0;
    (*out)->visible = 1;
    (*out)->speed = 0;
    (*out)->ot_layer = 2;
    (*out)->state = 0;
    (*out)->move_from = 0;
    (*out)->move_to = 0;
    (*out)->speed = 0;
    (*out)->auto_return = 0;
    (*out)->block = 0;
    (*out)->tmd_objects = NULL;
    (*out)->record = NULL;
    if (record_size != 0) {
        (*out)->record = kaj_malloc(record_size);
        if ((*out)->record == NULL) {
            kaj_abend(3, "Error Allocating DOOR Buffer", door_str_file, 0x36);
        }
    }
}

void door_free(Door *door) {
    if (door != NULL) {
        free3(door->tmd_objects);
        free3(door->record);
        free3(door);
    }
}

void door_add(void *door) {
    if (door_list->count == 0) {
        kaj_ll_insert_before(door_list, door);
    } else {
        door_list->cursor = door_list->tail;
        kaj_ll_insert_after(door_list, door);
    }
}

void door_free_all(void) {
    DoorList *list = door_list;
    Door *item;

    while (1) {
        if (list->count == 0) {
            break;
        }
        item = list->cursor->data;
        if (item != NULL) {
            free3(item->tmd_objects);
            free3(item->record);
            free3(item);
        }
        kaj_ll_remove_to_prev(list);
    }
}

Door *door_find(u16 id) {
    DoorList *list = door_list;
    Door *item;

    if (list->count == 0) {
        return NULL;
    }
    list->cursor = list->head;
    while (1) {
        item = list->cursor->data;
        if (item != NULL && item->id == id) {
            return item;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
    return NULL;
}

void door_draw_all(ViewBuffer *view) {
    s32 ls[8];
    DoorList *list = door_list;
    ScreenLight *light = &screen_light;
    Door *door;
    Block *block;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        door = list->cursor->data;
        if (door != NULL) {
            block = (Block *)door->block;
            if (block != NULL && block->visible != 0 && door->active != 0 && door->visible != 0) {
                GsGetLs(&door->coord_flg, ls);
                GsSetLsMatrix(ls);
                light->ot_bias = (door->ot_layer + 1) << 6;
                SetSpadStack(0x1F8003FC);
                GsSortObject4J(door->tmd_objects, &view->ot_length, 1, (void *)0x1F800000);
                ResetSpadStack();
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            return;
        }
        list->cursor = list->cursor->next;
    }
}

void door_rebase_all(s32 origin_x, s32 origin_y, s32 origin_z) {
    DoorList *list = door_list;
    Door *item;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        item = list->cursor->data;
        if (item != NULL) {
            item->coord_flg = 0;
            item->coord_tx = item->pos_x - origin_x;
            item->coord_ty = item->pos_y - origin_y;
            item->coord_tz = item->pos_z - origin_z;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void door_set_visible(u16 id, s16 visible) {
    DoorList *list = door_list;
    Door *item;
    Door *found;

    if (list->count == 0) {
        found = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && item->id == id) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (found != NULL && found->visible != visible) {
        found->visible = visible;
    }
}

void door_fade_step(TssSlot *task) {
    ScreenLight *light = &screen_light;
    BgmSep *bgm = object_scene_tables[0].bgm;
    s32 volume;
    s32 t;

    light->fade_level = task->cur;
    if (task->type < 2) {
        if (light->fade_level < 0) {
            light->fade_level = 0;
        }
    } else if (light->fade_level < 0x80) {
        light->fade_level = 0x80;
    }
    if (light->fade_level > 0x1000) {
        light->fade_level = 0x1000;
    }
    if (((s16)task->step > 0 && task->cur >= task->target) ||
        ((s16)task->step < 0 && task->cur <= task->target)) {
        if (task->type != 0 && bgm != NULL && bgm->seq >= 0) {
            t = task->cur >> 5;
            volume = 0x7F;
            if (t < 0x80) {
                volume = (s16)t;
                if (t < 0) {
                    volume = 0;
                }
            }
            SsSepSetVol(bgm->sep, bgm->seq, volume, volume);
        }
        if (task->type != 10) {
            light->fade_active = 0;
        }
    }
}
