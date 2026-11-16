#include "common.h"
#include "game/types.h"

void free3(void *ptr);
void kaj_ll_insert_before(Unk_801DFE80 *arg0, void *arg1);
void kaj_ll_insert_after(Unk_801DFE80 *arg0, void *arg1);
Unk_801DFE80 *D_801DFE80;
void kaj_ll_remove_to_prev(Unk_801DFE80 *arg0);
s16 kaj_ll_at_tail(Unk_801DFE80 *arg0);
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char D_801DFCE8[];
extern SceneTables object_scene_tables[];
extern Unk_801E1040 D_801E1040;
void SsSepSetVol(s16 access_num, s16 seq_num, s16 voll, s16 volr);

void door_create(Unk_801854B8 **arg0, u32 arg1) {
    *arg0 = kaj_malloc(0x80);
    if (*arg0 == NULL) {
        kaj_abend(3, "Error Allocating DOOR Pointer", D_801DFCE8, 0x23);
    }
    (*arg0)->unk4 = 0;
    (*arg0)->unk2 = 0;
    (*arg0)->unk6 = 1;
    (*arg0)->unk22 = 0;
    (*arg0)->unk8 = 2;
    (*arg0)->unkA = 0;
    (*arg0)->unkC = 0;
    (*arg0)->unkE = 0;
    (*arg0)->unk22 = 0;
    (*arg0)->unk24 = 0;
    (*arg0)->unk10 = 0;
    (*arg0)->unk78 = NULL;
    (*arg0)->unk7C = NULL;
    if (arg1 != 0) {
        (*arg0)->unk7C = kaj_malloc(arg1);
        if ((*arg0)->unk7C == NULL) {
            kaj_abend(3, "Error Allocating DOOR Buffer", D_801DFCE8, 0x36);
        }
    }
}

void door_free(Unk_801854B8 *arg0) {
    if (arg0 != NULL) {
        free3(arg0->unk78);
        free3(arg0->unk7C);
        free3(arg0);
    }
}

void door_add(void *arg0) {
    if (D_801DFE80->unkC == 0) {
        kaj_ll_insert_before(D_801DFE80, arg0);
    } else {
        D_801DFE80->unk8 = D_801DFE80->unk4;
        kaj_ll_insert_after(D_801DFE80, arg0);
    }
}

void door_free_all(void) {
    Unk_801DFE80 *list = D_801DFE80;
    Unk_801854B8 *item;

    while (1) {
        if (list->unkC == 0) {
            break;
        }
        item = list->unk8->unk8;
        if (item != NULL) {
            free3(item->unk78);
            free3(item->unk7C);
            free3(item);
        }
        kaj_ll_remove_to_prev(list);
    }
}

Unk_801854B8 *door_find(u16 arg0) {
    Unk_801DFE80 *list = D_801DFE80;
    Unk_801854B8 *item;

    if (list->unkC == 0) {
        return NULL;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL && item->unk0 == arg0) {
            return item;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
    return NULL;
}

INCLUDE_ASM("asm/nonmatchings/game/80185380", door_draw_all);

void door_rebase_all(s32 arg0, s32 arg1, s32 arg2) {
    Unk_801DFE80 *list = D_801DFE80;
    Unk_801854B8 *item;

    if (list->unkC == 0) {
        return;
    }
    list->unk8 = list->unk0;
    while (1) {
        item = list->unk8->unk8;
        if (item != NULL) {
            item->unk28 = 0;
            item->unk40 = item->unk14 - arg0;
            item->unk44 = item->unk18 - arg1;
            item->unk48 = item->unk1C - arg2;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->unk8 = list->unk8->unk4;
    }
}

void door_set_visible(u16 arg0, s16 arg1) {
    Unk_801DFE80 *list = D_801DFE80;
    Unk_801854B8 *item;
    Unk_801854B8 *found;

    if (list->unkC == 0) {
        found = NULL;
    } else {
        list->unk8 = list->unk0;
        while (1) {
            item = list->unk8->unk8;
            if (item != NULL && item->unk0 == arg0) {
                found = item;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                found = NULL;
                break;
            }
            list->unk8 = list->unk8->unk4;
        }
    }
    if (found != NULL && found->unk6 != arg1) {
        found->unk6 = arg1;
    }
}

void door_fade_step(Unk_801854B8 *arg0) {
    Unk_801E1040 *p = &D_801E1040;
    Unk_801A3B5C *q = object_scene_tables[0].unk0;
    s32 v;
    s32 t;

    p->unkE = arg0->unk24;
    if (arg0->unk22 < 2) {
        if (p->unkE < 0) {
            p->unkE = 0;
        }
    } else if (p->unkE < 0x80) {
        p->unkE = 0x80;
    }
    if (p->unkE > 0x1000) {
        p->unkE = 0x1000;
    }
    if (((s16)arg0->unk28 > 0 && arg0->unk24 >= arg0->unk26) ||
        ((s16)arg0->unk28 < 0 && arg0->unk24 <= arg0->unk26)) {
        if (arg0->unk22 != 0 && q != NULL && q->unk2 >= 0) {
            t = arg0->unk24 >> 5;
            v = 0x7F;
            if (t < 0x80) {
                v = (s16)t;
                if (t < 0) {
                    v = 0;
                }
            }
            SsSepSetVol(q->unk0, q->unk2, v, v);
        }
        if (arg0->unk22 != 10) {
            p->unk6 = 0;
        }
    }
}
