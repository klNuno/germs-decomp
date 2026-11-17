#include "common.h"
#include "game/mod.h"
#include "game/actor.h"
#include "game/block.h"
#include "game/effect.h"
#include "game/npc.h"
#include "kaj/event.h"
#include "kaj/kaj.h"
#include "kaj/ll.h"
#include "kaj/misc.h"
#include "kaj/tod.h"
#include "kaj/view.h"
#include "psyq/libapi.h"
#include "psyq/libgs.h"
#include "psyq/libgte.h"
#include "gte.h"

/*
 * The models: TMD and TOD loading, animation, drawing.
 *
 * File boundaries: likely (docs/layout.md): mod.c asserts.
 */

ModelList *mod_list;
/* Model seen by mod_finish_handler: id and kind are loaded unsigned here (Model's s16 fields give lh). */
typedef struct {
    u16 id;
    u16 kind;
    u8 pad4[0xC];
    s16 loop;
    u8 pad12[0x4];
    s16 anim;
} ModelFinished;
extern EventState event_state;
ModelFinished *mod_finished;
s16 kaj_ll_at_tail(ModelList *list);
extern char mod_str_alloc_model[];
extern char mod_str_file[];
extern char mod_str_alloc_buffer[];
extern s32 kaj_system_vsync_delta[];
typedef struct {
    u16 id;
    u16 anim_count;
    s32 obj_count;
    s32 tmd_ids_offset;
    s32 tmd_offset;
    s32 hit_tmd_offset;
    s32 tod_offset;
} ModFileHeader;
void mod_set_anim_by_id(u16 id, s16 anim, s16 frames);
/* GsDOBJ2 with its id, as one entry of a model's object table */
typedef struct ModDobj {
    s32 attribute;
    GsCoordinate2 *coord2;
    TmdObject *tmd;
    s32 id;
} ModDobj;
/* GsOBJTABLE2 head: the object array and its length */
typedef struct ModObjTable {
    ModDobj *top;
    s32 count;
} ModObjTable;
extern ScreenLight screen_light;
extern PlayerStatus player_status;

INCLUDE_RODATA("asm/nonmatchings/game/mod", mod_str_alloc_model);

INCLUDE_RODATA("asm/nonmatchings/game/mod", mod_str_alloc_buffer);

void mod_setup(Model *mod, s32 parent, s32 kind, s32 anim) {
    ModFileHeader *hdr;
    s32 count;
    s32 i;
    s32 j;
    s32 end;
    s32 cnt;
    s32 len;
    s32 k;
    s32 *tod;
    s32 *packet;
    SVector rot;

    if (mod->ready == 0) {
        hdr = (ModFileHeader *)mod->data;
        mod->kind = (u8)kind;
        mod->loop = 0;
        mod->id = hdr->id;
        mod->anim_count = hdr->anim_count;
        mod->tmd_ids = (s32)mod->data + hdr->tmd_ids_offset;
        mod->tmd = (s32)mod->data + hdr->tmd_offset;
        mod->tmd_objects = NULL;
        count = hdr->obj_count;
        kaj_tmd_map((void *)mod->tmd);
        if (hdr->hit_tmd_offset != 0) {
            kaj_tmd_load(&mod->tmd_objects, (u8 *)mod->data + hdr->hit_tmd_offset, &mod->coord_flg);
        }
        mod->obj_table = kaj_malloc(0xC);
        if (mod->obj_table == NULL) {
            kaj_abend(3, "Error Allocating GsOBJTABLE2", mod_str_file, 0x8E);
        }
        mod->dobj_table = kaj_malloc(count * 16);
        if (mod->dobj_table == NULL) {
            kaj_abend(3, "Error Allocating GsDOBJ2 Table", mod_str_file, 0x92);
        }
        mod->coord_table = kaj_malloc(count * 80);
        if (mod->coord_table == NULL) {
            kaj_abend(3, "Error Allocating GsCOORDINATE2", mod_str_file, 0x97);
        }
        mod->coord_params = kaj_malloc(count * 40);
        if (mod->coord_params == NULL) {
            kaj_abend(3, "Error Allocating GsCOORD2PARAM", mod_str_file, 0x9C);
        }
        mod->tod_table = kaj_malloc(mod->anim_count * 4);
        if (mod->tod_table == NULL) {
            kaj_abend(3, "Error Allocating TOD Table", mod_str_file, 0xA0);
        }
        tod = (s32 *)((u8 *)mod->data + hdr->tod_offset);
        for (i = 0; i < mod->anim_count; i++) {
            len = *tod++;
            ((s32 **)mod->tod_table)[i] = tod;
            tod += len >> 2;
        }
        kaj_tod_init_table(mod->obj_table, mod->dobj_table, mod->coord_table, mod->coord_params, count);
        mod->coord_tx = 0;
        mod->coord_ty = 0;
        mod->coord_tz = 0;
        if (parent == 0) {
            mod->parent_coord = (s32)&mod->coord_flg;
            GsInitCoordinate2(NULL, &mod->coord_flg);
        } else {
            mod->parent_coord = parent;
            GsInitCoordinate2((void *)parent, &mod->coord_flg);
        }
        rot.vx = 0;
        rot.vy = 0;
        rot.vz = 0;
        RotMatrix(&rot, &mod->coord_m);
        packet = ((s32 **)mod->tod_table)[(u16)anim];
        packet++;
        end = *packet++;
        j = packet[1];
        for (i = j; i < j + end; i++) {
            cnt = ((u16 *)packet)[1];
            packet += 2;
            for (k = 0; k < cnt; k++) {
                packet = kaj_tod_set_packet(packet, mod->obj_table, (s32 *)mod->tmd_ids, (void *)mod->tmd, 0, mod->parent_coord);
            }
        }
        mod->anim = anim;
        mod->tod_ptr = (s32)packet;
        mod->ready = 1;
        mod->coord_flg = 0;
    }
}

void mod_create(s16 *data) {
    Model *mod;
    Model **pp = &mod;
    Npc *npc;
    u16 id;

    *pp = kaj_malloc(0x94);
    if (*pp == NULL) {
        kaj_abend(3, mod_str_alloc_model, mod_str_file, 0x56);
    }
    (*pp)->kind = 3;
    (*pp)->loop = 0;
    (*pp)->ready = 0;
    (*pp)->owns_data = 0;
    (*pp)->playing = 0;
    (*pp)->tod_mode = 0;
    (*pp)->frame = -1;
    (*pp)->end_frame = -1;
    mod->data = data;
    id = *data;
    if (id < 0x440) {
        npc = npc_find(1, id);
        if (npc != NULL && npc->state == 6) {
            mod_setup(mod, 0, 0, 8);
        } else {
            mod_setup(mod, 0, 0, 0);
        }
    }
    mod_list_add((s32)mod);
}

void mod_relocate(s32 *old_data, s32 *new_data) {
    ModelList *list = mod_list;
    Model *mod;
    Model *t;
    s32 delta;
    s32 i;
    s32 *p;

    if (list->count == 0) {
        mod = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            t = list->cursor->data;
            if (t != NULL && (s32 *)t->data == old_data) {
                mod = t;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                mod = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (mod != NULL) {
        delta = old_data - new_data;
        if (mod->tod_ptr != 0) {
            mod->tod_ptr -= delta * 4;
        }
        mod->tmd_ids -= delta * 4;
        mod->tmd -= delta * 4;
        kaj_tmd_unmap(mod->tmd, delta);
        for (i = 0; i < mod->anim_count; i++) {
            ((s32 *)mod->tod_table)[i] -= delta * 4;
        }
        *(void **)mod->obj_table = mod->dobj_table;
        p = (s32 *)mod->dobj_table;
        for (i = 0; i < ((s32 *)mod->obj_table)[1]; i++, p += 4) {
            if (p[2] != 0) {
                p[2] -= delta * 4;
            }
        }
        if (mod->tmd_objects != NULL) {
            ((s32 *)mod->tmd_objects)[2] -= delta * 4;
            kaj_tmd_unmap((s32)new_data + new_data[4], delta);
        }
        mod->data = (s16 *)new_data;
    }
}

void mod_free_pooled(void) {
    ModelList *list = mod_list;
    Model *mod;
    Npc *npc;
    NpcRecord *rec;
    u16 id;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        mod = list->cursor->data;
        if (mod != NULL && mod->owns_data == 0) {
            id = mod->id;
            if (id >= 0x440) {
                rec = mod_npcrec_find(id - 0x440);
                if (rec != NULL) {
                    rec->shown = 1;
                }
            } else {
                npc = npc_find(1, mod->id);
                if (npc != NULL) {
                    npc->placed = 0;
                }
            }
            if (mod != NULL) {
                if (mod->ready != 0) {
                    free3(mod->obj_table);
                    free3(mod->dobj_table);
                    free3(mod->coord_table);
                    free3(mod->coord_params);
                    free3(mod->tod_table);
                }
                if (mod->tmd_objects != NULL) {
                    free3(mod->tmd_objects);
                }
                if (mod->owns_data != 0) {
                    free3(mod->data);
                }
                free3(mod);
            }
            kaj_ll_remove_to_prev(list);
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void mod_set_anim(void *mod, s16 anim, s16 frames) {
    u16 *tod;
    s32 i;
    s32 n;

    if (((Model *)mod) != NULL && ((Model *)mod)->ready != 0) {
        ((Model *)mod)->anim = anim;
        tod = ((u16 **)((Model *)mod)->tod_table)[anim];
        tod += 2;
        ((Model *)mod)->end_frame = tod[0];
        tod += 2;
        ((Model *)mod)->frame = tod[2];
        n = tod[1];
        tod += 4;
        for (i = 0; i < n; i++) {
            tod = kaj_tod_set_packet(tod, ((Model *)mod)->obj_table, (s32 *)((Model *)mod)->tmd_ids, (void *)((Model *)mod)->tmd, 2, ((Model *)mod)->parent_coord);
        }
        ((Model *)mod)->tod_ptr = (s32)tod;
        ((Model *)mod)->tod_mode = 2;
        if (((Model *)mod)->end_frame >= 2) {
            if (frames == 0) {
                ((Model *)mod)->loop = 0;
                ((Model *)mod)->end_frame = ((Model *)mod)->frame + ((Model *)mod)->end_frame - 1;
            } else if (frames < 0) {
                ((Model *)mod)->loop = 1;
                ((Model *)mod)->end_frame = ((Model *)mod)->frame + ((Model *)mod)->end_frame - 1;
            } else {
                ((Model *)mod)->loop = 0;
                ((Model *)mod)->end_frame = ((Model *)mod)->frame + frames - 1;
            }
            ((Model *)mod)->playing = 1;
            ((Model *)mod)->frame_step = 1;
            if (kaj_system_vsync_delta[0] == 4 || kaj_system_vsync_delta[0] == 5) {
                ((Model *)mod)->frame_step = 2;
            } else if (kaj_system_vsync_delta[0] >= 6) {
                ((Model *)mod)->frame_step = 3;
            }
        }
    }
}

static inline void mod_draw_objects(ViewBuffer *view, Model *mod, u16 ot_layer) {
    s32 ls[8];
    ModObjTable *table;
    ModDobj *dobj;
    s32 i = 0;
    ScreenLight *light = &screen_light;
    table = mod->obj_table;
    dobj = table->top;
    for (; i < table->count; i++, dobj++) {
        dobj->coord2->flg = 0;
        if (dobj->id != -1 && dobj->tmd != NULL) {
            GsGetLs(dobj->coord2, ls);
            GsSetLsMatrix(ls);
            light->ot_bias = (ot_layer + 1) * 64;
            SetSpadStack(0x1F8003FC);
            GsSortObject4J(dobj, &view->ot_length, 1, (void *)0x1F800000);
            ResetSpadStack();
        }
    }
}

void mod_draw_player(ViewBuffer *view, u16 mode) {
    Inventory *inv = player_status.inventory;
    Model *mod;
    ModelList *list;
    u16 id;

    if (player_status.model != NULL && player_status.model->ready != 0) {
        mod_draw_objects(view, player_status.model, 0);
    }
    if (mode == 1 && inv->weapon_shown != 0) {
        list = mod_list;
        id = inv->weapon_ids[inv->weapon_slot] + 0x400;
        if (list->count == 0) {
            mod = NULL;
        } else {
            list->cursor = list->head;
            while (1) {
                mod = list->cursor->data;
                if (mod != NULL && *mod->data == id) {
                    break;
                }
                if (kaj_ll_at_tail(list) != 0) {
                    mod = NULL;
                    break;
                }
                list->cursor = list->cursor->next;
            }
        }
        if (mod != NULL && mod->ready != 0) {
            mod_draw_objects(view, mod, 0);
        }
    }
}

void mod_update_all(void) {
    ModelList *list = mod_list;
    Model *mod;
    s16 cnt;
    s32 kind;

    if (list->count == 0) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        mod = list->cursor->data;
        if (mod != NULL && mod->ready != 0 && mod->playing != 0) {
            cnt = mod->frame_step;
            {
again:
                if (mod->frame < mod->end_frame) {
                    if ((u16)mod->kind == 1 && (u16)mod->anim == 2) {
                        effect_weapon_check_fire_frame(mod->frame);
                    }
                    mod->frame++;
                    mod->tod_ptr = (s32)kaj_tod_set_frame(mod->frame, (TodFrame *)mod->tod_ptr, mod->obj_table, (s32 *)mod->tmd_ids, (void *)mod->tmd, (u16)mod->tod_mode, mod->parent_coord);
                    cnt--;
                    if (cnt > 0) {
                        goto again;
                    }
                } else {
                    mod->tod_ptr = (s32)kaj_tod_set_frame(mod->end_frame, (TodFrame *)mod->tod_ptr, mod->obj_table, (s32 *)mod->tmd_ids, (void *)mod->tmd, (u16)mod->tod_mode, mod->parent_coord);
                    kind = (u16)mod->kind;
                    mod->playing = 0;
                    mod->frame = -1;
                    mod->end_frame = -1;
                    if (kind != 0 && (kind != 1 || (u16)mod->anim != 5)) {
                        EnterCriticalSection();
                        mod_finished = (ModelFinished *)mod;
                        DeliverEvent(0xF3000002, 2);
                        ExitCriticalSection();
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

void mod_alloc(Model **out, u32 data_size) {
    *out = kaj_malloc(0x94);
    if (*out == NULL) {
        kaj_abend(3, mod_str_alloc_model, mod_str_file, 0x56);
    }
    (*out)->kind = 3;
    (*out)->loop = 0;
    (*out)->ready = 0;
    (*out)->owns_data = 0;
    (*out)->playing = 0;
    (*out)->tod_mode = 0;
    (*out)->frame = -1;
    (*out)->end_frame = -1;
    if (data_size != 0) {
        (*out)->data = kaj_malloc(data_size);
        if ((*out)->data == NULL) {
            kaj_abend(3, mod_str_alloc_buffer, mod_str_file, 0x64);
        }
        (*out)->owns_data = 1;
    }
}

void mod_free(Model *mod) {
    if (mod != NULL) {
        if (mod->ready != 0) {
            free3(mod->obj_table);
            free3(mod->dobj_table);
            free3(mod->coord_table);
            free3(mod->coord_params);
            free3(mod->tod_table);
        }
        if (mod->tmd_objects != NULL) {
            free3(mod->tmd_objects);
        }
        if (mod->owns_data != 0) {
            free3(mod->data);
        }
        free3(mod);
    }
}

void mod_on_data_free(s16 *data) {
    ModelList *list = mod_list;
    Model *mod;
    Model *t;
    Npc *npc;
    NpcRecord *rec;
    s16 id;

    if (list->count == 0) {
        mod = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            t = list->cursor->data;
            if (t != NULL && t->data == data) {
                mod = t;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                mod = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (mod != NULL) {
        id = *mod->data;
        mod_free_by_id(id);
        if (id >= 0x440) {
            rec = mod_npcrec_find(id - 0x440);
            if (rec != NULL) {
                rec->shown = 1;
            }
        } else {
            npc = npc_find(1, id);
            if (npc != NULL) {
                npc->placed = 0;
            }
        }
    }
}

void mod_list_add(s32 mod) {
    if (mod_list->count == 0) {
        kaj_ll_insert_before(mod_list, mod);
    } else {
        mod_list->cursor = mod_list->tail;
        kaj_ll_insert_after(mod_list, mod);
    }
}

void mod_free_by_id(u16 id) {
    ModelList *list = mod_list;
    Model *mod;

    if (list->count == 0) {
        return;
    }
    mod = mod_find(id);
    if (mod == NULL) {
        return;
    }
    list->cursor = list->head;
    while (1) {
        if (mod == list->cursor->data) {
            if (mod != NULL) {
                if (mod->ready != 0) {
                    free3(mod->obj_table);
                    free3(mod->dobj_table);
                    free3(mod->coord_table);
                    free3(mod->coord_params);
                    free3(mod->tod_table);
                }
                if (mod->tmd_objects != NULL) {
                    free3(mod->tmd_objects);
                }
                if (mod->owns_data != 0) {
                    free3(mod->data);
                }
                free3(mod);
            }
            kaj_ll_remove_to_prev(list);
            return;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
}

void mod_free_all(void) {
    ModelList *list = mod_list;
    Model *mod;

    while (1) {
        if (list->count == 0) {
            break;
        }
        mod = list->cursor->data;
        if (mod != NULL) {
            if (mod->ready != 0) {
                free3(mod->obj_table);
                free3(mod->dobj_table);
                free3(mod->coord_table);
                free3(mod->coord_params);
                free3(mod->tod_table);
            }
            if (mod->tmd_objects != NULL) {
                free3(mod->tmd_objects);
            }
            if (mod->owns_data != 0) {
                free3(mod->data);
            }
            free3(mod);
        }
        kaj_ll_remove_to_prev(list);
    }
    mod_npcrec_reset_all();
}

Model *mod_find(u16 id) {
    ModelList *list = mod_list;
    Model *mod;

    if (list->count == 0) {
        return NULL;
    }
    list->cursor = list->head;
    while (1) {
        mod = list->cursor->data;
        if (mod != NULL && *mod->data == id) {
            return mod;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
    return NULL;
}

void mod_set_anim_by_id(u16 id, s16 anim, s16 frames) {
    ModelList *list = mod_list;
    Model *mod;

    if (list->count == 0) {
        mod = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            mod = list->cursor->data;
            if (mod != NULL && *mod->data == id) {
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                mod = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    mod_set_anim(mod, anim, frames);
}

void mod_draw(ViewBuffer *view, Model *mod, u16 ot_layer) {
    mod_draw_objects(view, mod, ot_layer);
}

s32 mod_finish_handler(void) {
    EventState *s = &event_state;
    KajEvent *e;

    UnDeliverEvent(0xF3000002, 2);
    e = kaj_event_push(0x200);
    if (e != NULL) {
        e->param0 = mod_finished->id;
        e->param1 = mod_finished->kind;
    }
    if (mod_finished->kind == 2) {
        if (s->wait_flags & 8) {
            s->wait_flags &= ~8;
            if (s->wait_flags == 0) {
                s->state = 1;
            }
        }
    }
    if (mod_finished->loop != 0) {
        mod_finished->loop = 0;
        mod_set_anim(mod_finished, mod_finished->anim, -1);
    }
    return 0;
}
