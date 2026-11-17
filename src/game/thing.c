#include "common.h"
#include "game/thing.h"
#include "game/action.h"
#include "game/actor.h"
#include "game/block.h"
#include "game/sprite.h"
#include "game/vehicle.h"
#include "kaj/kaj.h"
#include "kaj/ll.h"
#include "kaj/misc.h"
#include "kaj/view.h"
#include "psyq/libapi.h"
#include "psyq/libc.h"
#include "psyq/libgs.h"
#include "psyq/libgte.h"
#include "gte.h"

/*
 * The things (scene objects): update, scripts, markers, hit tests.
 *
 * File boundaries: likely (docs/layout.md): thing.c asserts; thing_list through gp from sprite_thing_refresh_all.
 */

s16 kaj_ll_at_tail(SpriteList *list);
extern Player *player_status_player[];
extern KajSystem kaj_system;
typedef struct ThingListNode {
    struct ThingListNode *prev;
    struct ThingListNode *next;
    Thing *data;
} ThingListNode;
typedef struct ThingList {
    ThingListNode *head;
    ThingListNode *tail;
    ThingListNode *cursor;
    s32 count;
} ThingList;
ThingList *thing_list;
extern s32 kaj_system_vsync_delta[];
typedef struct {
    u16 id;
    u16 type;
    s16 ot_layer;
    s16 enter_set;
    s16 leave_set;
    u8 unkA[0x2];
    s32 pos_x;
    s32 pos_y;
    s32 pos_z;
    s16 rot_x;
    s16 rot_y;
    s16 rot_z;
    u8 unk1E[0x2];
    s32 model_offset;
    s32 hit_model_offset;
} ThingRecord;
extern ScreenLight screen_light;
extern s16 roadmap_draw_flags;

void sprite_thing_init(Thing *thing) {
    SVector sv;
    ThingRecord *src = thing->record;
    Player *player = player_status_player[0];

    thing->id = src->id;
    thing->type = src->type;
    thing->ot_layer = src->ot_layer;
    thing->enter_set = src->enter_set;
    thing->leave_set = src->leave_set;
    thing->pos_x = src->pos_x * 10;
    thing->pos_y = src->pos_y * 10;
    thing->pos_z = src->pos_z * 10;
    thing->rot_x = src->rot_x;
    thing->rot_y = src->rot_y;
    thing->rot_z = src->rot_z;
    if (src->model_offset != 0) {
        kaj_tmd_load(&thing->tmd_objects, (u8 *)thing->record + src->model_offset, &thing->coord_flg);
    }
    if (src->hit_model_offset != 0) {
        kaj_tmd_load(&thing->hit_model, (u8 *)thing->record + src->hit_model_offset, &thing->coord_flg);
    }
    GsInitCoordinate2(NULL, &thing->coord_flg);
    thing->coord_tx = thing->pos_x - player->cell_x * 0x30D4;
    thing->coord_ty = thing->pos_y + player->cell_y * 0x7D00;
    thing->coord_tz = thing->pos_z - player->cell_z * 0x30D4;
    sv.vx = (thing->rot_x << 12) / 360;
    sv.vy = (thing->rot_y << 12) / 360;
    sv.vz = (thing->rot_z << 12) / 360;
    RotMatrix(&sv, thing->coord_m);
    thing->coord_flg = 0;
    if (thing->type == 4) {
        thing->block_fixed = 1;
        thing->active = 1;
        thing->animate = 1;
    } else {
        thing->block = block_find_at(thing->pos_x, thing->pos_y, thing->pos_z);
    }
}

void sprite_thing_refresh_all(void) {
    SVector sv;
    SpriteList *list = thing_list;
    Player *player = player_status_player[0];
    Thing *thing;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        thing = (Thing *)list->cursor->data;
        if (thing != NULL && thing->type != 4) {
            thing->coord_tx = thing->pos_x - player->cell_x * 12500;
            thing->coord_ty = thing->pos_y + player->cell_y * 32000;
            thing->coord_tz = thing->pos_z - player->cell_z * 12500;
            sv.vx = (thing->rot_x << 12) / 360;
            sv.vy = (thing->rot_y << 12) / 360;
            sv.vz = (thing->rot_z << 12) / 360;
            RotMatrix(&sv, thing->coord_m);
            thing->coord_flg = 0;
            thing->block = block_find_at(thing->pos_x, thing->pos_y, thing->pos_z);
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void sprite_thing_draw_all(ViewBuffer *view) {
    s32 ls[8];
    SpriteList *list = thing_list;
    Player *player = player_status_player[0];
    ScreenLight *light = &screen_light;
    Thing *thing;
    s16 flags;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        thing = (Thing *)list->cursor->data;
        if (thing != NULL && (thing->block_fixed != 0 ? thing->active != 0
                              : thing->active != 0 && (Block *)thing->block != NULL
                                    && ((Block *)thing->block)->visible != 0)) {
            flags = roadmap_draw_flags;
            if (thing->type == 4) {
                thing->coord_tx = player->pos_x;
                thing->coord_tz = player->pos_z;
                if (player->vehicle_mode == 2) {
                    thing->coord_ty = player->pos_y - player->eye_height + 15000;
                } else {
                    thing->coord_ty = player->pos_y - player->eye_height + 500;
                }
                thing->coord_flg = 0;
                if (roadmap_draw_flags & 2) {
                    roadmap_draw_flags -= 2;
                }
            }
            GsGetLs(&thing->coord_flg, ls);
            GsSetLsMatrix(ls);
            light->ot_bias = (thing->ot_layer + 1) << 6;
            SetSpadStack(0x1F8003FC);
            GsSortObject4J(thing->tmd_objects, &view->ot_length, 1, (void *)0x1F800000);
            ResetSpadStack();
            roadmap_draw_flags = flags;
        }
        if (kaj_ll_at_tail(list) != 0) {
            return;
        }
        list->cursor = list->cursor->next;
    }
}

static void sprite_thing_update_marker(Player *player, Thing *marker, Npc *target) {
    SVector sv;
    NpcBody *body;
    s32 y;

    body = npc_find_body(target->body_id);
    y = target->pos_y - 2200;
    if (body != NULL && body->height != 0) {
        y = target->pos_y - body->height * 10 - 300;
    }
    marker->rot_y -= kaj_system_vsync_delta[0];
    if (marker->rot_y < 0) {
        marker->rot_y += 360;
    }
    marker->coord_tx = target->pos_x - player->cell_x * 12500;
    marker->coord_ty = y + player->cell_y * 32000;
    marker->coord_tz = target->pos_z - player->cell_z * 12500;
    sv.vx = (marker->rot_x << 12) / 360;
    sv.vy = (marker->rot_y << 12) / 360;
    sv.vz = (marker->rot_z << 12) / 360;
    RotMatrix(&sv, marker->coord_m);
    marker->coord_flg = 0;
}

static void sprite_thing_update_fly_in(Thing *thing) {
    SVector sv;
    KajSystem *sys = &kaj_system;

    thing->rot_z += sys->vsync_delta * 3;
    thing->pos_z -= sys->vsync_delta * 25;
    if (thing->rot_z >= 361) {
        thing->rot_z -= 360;
    }
    if (thing->pos_z < 1500) {
        thing->animate = 0;
        thing->rot_z = 0;
        thing->pos_z = 1500;
    }
    thing->coord_tz = thing->pos_z;
    sv.vx = (thing->rot_x << 12) / 360;
    sv.vy = (thing->rot_y << 12) / 360;
    sv.vz = (thing->rot_z << 12) / 360;
    RotMatrix(&sv, thing->coord_m);
    thing->coord_flg = 0;
}

/* View of ActionCmd for thing_cmd_set_active: the target word read as two bytes (lbu). */
typedef struct ThingActionCmd {
    u8 unk0[0x2];
    u16 sub;
    u8 thing_id;
    u8 thing_type;
} ThingActionCmd;
extern char thing_str_alloc_pointer[];
extern char thing_str_alloc_buffer[];
extern char thing_str_file[];
extern PlayerStatus player_status;
extern KajSystem kaj_system;
extern s16 block_reloaded;
static void sprite_thing_update_fly_in(Thing *thing);

INCLUDE_RODATA("asm/nonmatchings/game/thing", thing_str_alloc_pointer);

INCLUDE_RODATA("asm/nonmatchings/game/thing", thing_str_alloc_buffer);

void thing_update_all(void) {
    SVector sv;
    ThingList *list = thing_list;
    PlayerStatus *status = &player_status;
    Inventory *inv = status->inventory;
    Player *player = status->player;
    Thing *thing;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        thing = list->cursor->data;
        if (thing != NULL && thing->type != 4) {
            if (*(s32 *)thing == 0x30007) {
                if (status->target_npc != 0 && inv->weapon_state >= 3) {
                    if (thing->active == 0) {
                        thing->active = 1;
                    }
                } else if (thing->active != 0) {
                    thing->active = 0;
                }
            }
            if (thing->active == 0) {
                thing->block = 0;
            } else {
                if (thing->animate != 0) {
                    switch (thing->type) {
                    case 2:
                        if (thing->id == 0) {
                            vehicle_train_update(thing);
                        }
                        break;
                    case 3:
                        switch (thing->id) {
                        case 0:
                        case 2:
                        case 6:
                            thing->rot_y = -kaj_system.vsync_delta + thing->rot_y;
                            if (thing->rot_y < 0) {
                                thing->rot_y += 360;
                            } else if (thing->rot_y > 360) {
                                thing->rot_y -= 360;
                            }
                            sv.vx = (thing->rot_x << 12) / 360;
                            sv.vy = (thing->rot_y << 12) / 360;
                            sv.vz = (thing->rot_z << 12) / 360;
                            RotMatrix(&sv, thing->coord_m);
                            thing->coord_flg = 0;
                            break;
                        case 1:
                            thing->rot_y -= -kaj_system.vsync_delta;
                            if (thing->rot_y < 0) {
                                thing->rot_y += 360;
                            } else if (thing->rot_y > 360) {
                                thing->rot_y -= 360;
                            }
                            sv.vx = (thing->rot_x << 12) / 360;
                            sv.vy = (thing->rot_y << 12) / 360;
                            sv.vz = (thing->rot_z << 12) / 360;
                            RotMatrixZYX(&sv, thing->coord_m);
                            thing->coord_flg = 0;
                            break;
                        case 3:
                        case 4:
                        case 5:
                            thing->rot_y += ~(kaj_system.vsync_delta / 4);
                            if (thing->rot_y < 0) {
                                thing->rot_y += 360;
                            } else if (thing->rot_y > 360) {
                                thing->rot_y -= 360;
                            }
                            sv.vx = (thing->rot_x << 12) / 360;
                            sv.vy = (thing->rot_y << 12) / 360;
                            sv.vz = (thing->rot_z << 12) / 360;
                            RotMatrix(&sv, thing->coord_m);
                            thing->coord_flg = 0;
                            break;
                        case 7:
                            sprite_thing_update_marker(player, thing, status->target_npc);
                            break;
                        case 8:
                            thing->rot_y += kaj_system.vsync_delta * 5 / 2;
                            if (thing->rot_y < 0) {
                                thing->rot_y += 360;
                            } else if (thing->rot_y > 360) {
                                thing->rot_y -= 360;
                            }
                            sv.vx = (thing->rot_x << 12) / 360;
                            sv.vy = (thing->rot_y << 12) / 360;
                            sv.vz = (thing->rot_z << 12) / 360;
                            RotMatrix(&sv, thing->coord_m);
                            thing->coord_flg = 0;
                            break;
                        case 9:
                            thing->rot_y -= kaj_system.vsync_delta * 5;
                            if (thing->rot_y < 0) {
                                thing->rot_y += 360;
                            } else if (thing->rot_y > 360) {
                                thing->rot_y -= 360;
                            }
                            sv.vx = (thing->rot_x << 12) / 360;
                            sv.vy = (thing->rot_y << 12) / 360;
                            sv.vz = (thing->rot_z << 12) / 360;
                            RotMatrix(&sv, thing->coord_m);
                            thing->coord_flg = 0;
                            break;
                        case 10:
                            sprite_thing_update_fly_in(thing);
                            break;
                        }
                        break;
                    }
                }
                if (thing->block_fixed == 0 && block_reloaded != 0) {
                    thing->block = block_find_at(thing->pos_x, thing->pos_y, thing->pos_z);
                    if (*(s32 *)thing == 0) {
                        vehicle_car_follow_player(thing, 0);
                    }
                }
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void thing_create(Thing **out, u32 record_size) {
    *out = kaj_malloc(0x88);
    if (*out == NULL) {
        kaj_abend(3, thing_str_alloc_pointer, thing_str_file, 0x26);
    }
    (*out)->active = 0;
    (*out)->animate = 0;
    (*out)->script_enabled = 0;
    (*out)->block_fixed = 0;
    (*out)->block = 0;
    (*out)->tmd_objects = NULL;
    (*out)->hit_model = NULL;
    (*out)->record = NULL;
    (*out)->record = kaj_malloc(record_size);
    if ((*out)->record == NULL) {
        kaj_abend(3, thing_str_alloc_buffer, thing_str_file, 0x33);
    }
}

void thing_free(Thing *thing) {
    if (thing != NULL) {
        free3(thing->tmd_objects);
        if (thing->hit_model != NULL) {
            free3(thing->hit_model);
        }
        free3(thing->record);
        free3(thing);
    }
}

void thing_list_add(s32 thing) {
    if (thing_list->count == 0) {
        kaj_ll_insert_before(thing_list, thing);
    } else {
        thing_list->cursor = thing_list->tail;
        kaj_ll_insert_after(thing_list, thing);
    }
}

void thing_free_all(void) {
    ThingList *list = thing_list;
    Thing *item;

    while (1) {
        if (list->count == 0) {
            break;
        }
        item = list->cursor->data;
        if (item != NULL) {
            free3(item->tmd_objects);
            if (item->hit_model != NULL) {
                free3(item->hit_model);
            }
            free3(item->record);
            free3(item);
        }
        kaj_ll_remove_to_prev(list);
    }
}

Thing *thing_find(s32 type, s32 id) {
    ThingList *list = thing_list;
    Thing *item;
    s32 type16;
    s32 id16;

    if (list->count == 0) {
        return NULL;
    }
    type16 = type & 0xFFFF;
    id16 = id & 0xFFFF;
    list->cursor = list->head;
    while (1) {
        item = list->cursor->data;
        if (item != NULL && item->type == type16 && item->id == id16) {
            return item;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
    return NULL;
}

u16 thing_hit_test(s32 x, s32 y, s32 z, u16 mode) {
    ThingList *list = thing_list;
    Thing *item;

    if (list->count == 0) {
        return 0xFFFF;
    }
    list->cursor = list->head;
    while (1) {
        item = list->cursor->data;
        if (item != NULL && item->active != 0 && item->hit_model != NULL) {
            GsSetLsMatrix(item->coord_m);
            if (block_point_on_model(item->hit_model, x, y, z, mode) != 0) {
                return item->id + (item->type << 12);
            }
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
    return 0xFFFF;
}

void thing_set_origin(s32 origin_x, s32 origin_y, s32 origin_z) {
    ThingList *list = thing_list;
    Thing *item;

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

s32 thing_run_script(s32 type, s32 id, s16 entering) {
    ThingList *list = thing_list;
    Thing *item;
    Thing *found;
    ActionSet *set;
    s32 type16;
    s32 id16;

    if (list->count == 0) {
        found = NULL;
    } else {
        type16 = type & 0xFFFF;
        id16 = id & 0xFFFF;
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && item->type == type16 && item->id == id16) {
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
    if (found == NULL || found->script_enabled == 0) {
        return 0;
    }
    if (found->active == 0 || (set = entering != 0 ? action_find_set(found->enter_set) : action_find_set(found->leave_set)) == NULL) {
        return 0;
    }
    while ((set = action_run_set(set, 0, 0)) != NULL) {
    }
    return 1;
}

void thing_set_active(s32 type, s32 id, s16 active) {
    ThingList *list = thing_list;
    Thing *item;
    Thing *found;
    s32 type16;
    s32 id16;

    if (list->count == 0) {
        found = NULL;
    } else {
        type16 = type & 0xFFFF;
        id16 = id & 0xFFFF;
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && item->type == type16 && item->id == id16) {
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
    if (found != NULL) {
        found->active = active;
    }
}

void thing_set_animate(s32 type, s32 id, s16 animate) {
    ThingList *list = thing_list;
    Thing *item;
    Thing *found;
    s32 type16;
    s32 id16;

    if (list->count == 0) {
        found = NULL;
    } else {
        type16 = type & 0xFFFF;
        id16 = id & 0xFFFF;
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && item->type == type16 && item->id == id16) {
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
    if (found != NULL) {
        found->animate = animate;
    }
}

void thing_set_flag10(s32 type, s32 id, s16 block_fixed) {
    ThingList *list = thing_list;
    Thing *item;
    Thing *found;
    s32 type16;
    s32 id16;

    if (list->count == 0) {
        found = NULL;
    } else {
        type16 = type & 0xFFFF;
        id16 = id & 0xFFFF;
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && item->type == type16 && item->id == id16) {
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
    if (found != NULL) {
        found->block_fixed = block_fixed;
    }
}

void thing_cmd_set_active(Action *action) {
    ThingActionCmd *p = (ThingActionCmd *)action->cmd;
    ThingList *list = thing_list;
    Thing *item;
    Thing *found;
    s32 type = p->thing_type;
    s32 id = p->thing_id;
    s32 type16;
    s32 id16;

    if (list->count == 0) {
        found = NULL;
    } else {
        type16 = type & 0xFFFF;
        id16 = id & 0xFFFF;
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && item->type == type16 && item->id == id16) {
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
    if (found != NULL && p->sub == 2) {
        found->active = atoi(action->args[0]);
    }
}
