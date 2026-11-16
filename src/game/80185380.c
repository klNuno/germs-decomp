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
extern char D_801DFCE8[];
extern SceneTables object_scene_tables[];
extern ScreenLight screen_light;
void SsSepSetVol(s16 access_num, s16 seq_num, s16 voll, s16 volr);

void door_create(Door **arg0, u32 arg1) {
    *arg0 = kaj_malloc(0x80);
    if (*arg0 == NULL) {
        kaj_abend(3, "Error Allocating DOOR Pointer", D_801DFCE8, 0x23);
    }
    (*arg0)->active = 0;
    (*arg0)->axis = 0;
    (*arg0)->visible = 1;
    (*arg0)->speed = 0;
    (*arg0)->unk8 = 2;
    (*arg0)->state = 0;
    (*arg0)->move_from = 0;
    (*arg0)->move_to = 0;
    (*arg0)->speed = 0;
    (*arg0)->auto_return = 0;
    (*arg0)->block = 0;
    (*arg0)->tmd_objects = NULL;
    (*arg0)->record = NULL;
    if (arg1 != 0) {
        (*arg0)->record = kaj_malloc(arg1);
        if ((*arg0)->record == NULL) {
            kaj_abend(3, "Error Allocating DOOR Buffer", D_801DFCE8, 0x36);
        }
    }
}

void door_free(Door *arg0) {
    if (arg0 != NULL) {
        free3(arg0->tmd_objects);
        free3(arg0->record);
        free3(arg0);
    }
}

void door_add(void *arg0) {
    if (door_list->count == 0) {
        kaj_ll_insert_before(door_list, arg0);
    } else {
        door_list->cursor = door_list->tail;
        kaj_ll_insert_after(door_list, arg0);
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

Door *door_find(u16 arg0) {
    DoorList *list = door_list;
    Door *item;

    if (list->count == 0) {
        return NULL;
    }
    list->cursor = list->head;
    while (1) {
        item = list->cursor->data;
        if (item != NULL && item->id == arg0) {
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

void door_rebase_all(s32 arg0, s32 arg1, s32 arg2) {
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
            item->coord_tx = item->pos_x - arg0;
            item->coord_ty = item->pos_y - arg1;
            item->coord_tz = item->pos_z - arg2;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void door_set_visible(u16 arg0, s16 arg1) {
    DoorList *list = door_list;
    Door *item;
    Door *found;

    if (list->count == 0) {
        found = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && item->id == arg0) {
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
    if (found != NULL && found->visible != arg1) {
        found->visible = arg1;
    }
}

void door_fade_step(Door *arg0) {
    ScreenLight *p = &screen_light;
    BgmSep *q = object_scene_tables[0].unk0;
    s32 v;
    s32 t;

    p->fade_level = arg0->auto_return;
    if (arg0->speed < 2) {
        if (p->fade_level < 0) {
            p->fade_level = 0;
        }
    } else if (p->fade_level < 0x80) {
        p->fade_level = 0x80;
    }
    if (p->fade_level > 0x1000) {
        p->fade_level = 0x1000;
    }
    if (((s16)arg0->coord_flg > 0 && arg0->auto_return >= arg0->unk26) ||
        ((s16)arg0->coord_flg < 0 && arg0->auto_return <= arg0->unk26)) {
        if (arg0->speed != 0 && q != NULL && q->seq >= 0) {
            t = arg0->auto_return >> 5;
            v = 0x7F;
            if (t < 0x80) {
                v = (s16)t;
                if (t < 0) {
                    v = 0;
                }
            }
            SsSepSetVol(q->sep, q->seq, v, v);
        }
        if (arg0->speed != 10) {
            p->fade_active = 0;
        }
    }
}
