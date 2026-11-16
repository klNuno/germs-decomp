#include "common.h"
#include "game/types.h"

void free3(void *ptr);
void kaj_ll_insert_before(DoorList *arg0, void *arg1);
void kaj_ll_insert_after(DoorList *arg0, void *arg1);
DoorList *door_list;
void kaj_ll_remove_to_prev(DoorList *arg0);
s16 kaj_ll_at_tail(DoorList *arg0);
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char door_str_file[];
extern SceneTables object_scene_tables[];
extern ScreenLight screen_light;
void SsSepSetVol(s16 access_num, s16 seq_num, s16 voll, s16 volr);

void door_create(Door **out, u32 record_size) {
    *out = kaj_malloc(0x80);
    if (*out == NULL) {
        kaj_abend(3, "Error Allocating DOOR Pointer", door_str_file, 0x23);
    }
    (*out)->active = 0;
    (*out)->axis = 0;
    (*out)->visible = 1;
    (*out)->speed = 0;
    (*out)->unk8 = 2;
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

INCLUDE_ASM("asm/nonmatchings/game/80185380", door_draw_all);

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

void door_fade_step(Door *door) {
    ScreenLight *light = &screen_light;
    BgmSep *bgm = object_scene_tables[0].bgm;
    s32 volume;
    s32 t;

    light->fade_level = door->auto_return;
    if (door->speed < 2) {
        if (light->fade_level < 0) {
            light->fade_level = 0;
        }
    } else if (light->fade_level < 0x80) {
        light->fade_level = 0x80;
    }
    if (light->fade_level > 0x1000) {
        light->fade_level = 0x1000;
    }
    if (((s16)door->coord_flg > 0 && door->auto_return >= door->unk26) ||
        ((s16)door->coord_flg < 0 && door->auto_return <= door->unk26)) {
        if (door->speed != 0 && bgm != NULL && bgm->seq >= 0) {
            t = door->auto_return >> 5;
            volume = 0x7F;
            if (t < 0x80) {
                volume = (s16)t;
                if (t < 0) {
                    volume = 0;
                }
            }
            SsSepSetVol(bgm->sep, bgm->seq, volume, volume);
        }
        if (door->speed != 10) {
            light->fade_active = 0;
        }
    }
}
