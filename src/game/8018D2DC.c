#include "common.h"
#include "game/types.h"
#include "gte.h"

void kaj_ll_insert_before(ModelList *list, s32 data);
void kaj_ll_insert_after(ModelList *list, s32 data);
ModelList *mod_list;
extern SceneTables object_scene_tables;
void free3(void *ptr);
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
void UnDeliverEvent(u32 ev, u32 spec);
KajEvent *kaj_event_push(s32 type);
void mod_set_anim(void *mod, s16 anim, s16 frames);
extern NpcRecord *mod_npcrec_table[];
extern s16 action_vars[];
Model *mod_find(u16 id);
void mod_setup(Model *mod, s32 parent, s32 kind, s32 anim);
void mod_place_npcrec(NpcRecord *rec, Model *mod);
void mod_draw(ViewBuffer *view, Model *mod, u16 ot_layer);
typedef struct {
    s32 from_x;
    s32 from_y;
    s32 from_z;
    u8 padC[0x4];
    s32 to_x;
    s32 to_y;
    s32 to_z;
    u8 pad1C[0x4];
    s32 delta_x;
    s32 delta_y;
    s32 delta_z;
    u8 pad2C[0x4];
    s16 from_rot_x;
    s16 from_rot_y;
    s16 from_rot_z;
    u8 pad36[0x2];
    s16 to_rot_x;
    s16 to_rot_y;
    s16 to_rot_z;
    u8 pad3E[0x2];
    s16 delta_rot_x;
    s16 delta_rot_y;
    s16 delta_rot_z;
    u8 pad46[0x2];
    NpcRecord *rec;
} NpcRecMove;
s16 kaj_ll_at_tail(ModelList *list);
Npc *npc_find(s16 by_model, u16 id);
NpcRecord *mod_npcrec_find(u16 id);
void mod_free_by_id(u16 id);
void kaj_ll_remove_to_prev(ModelList *list);
void mod_npcrec_reset_all(void);
extern char mod_str_alloc_model[];
void *kaj_malloc(u32 size);
void kaj_abend(s32 code, char *msg, char *file, s32 line);
extern char mod_str_file[];
void mod_list_add(s32 mod);
extern char mod_str_alloc_buffer[];
void kaj_tmd_unmap(s32 tmd, s32 base);
extern s32 kaj_system_vsync_delta[];
void *kaj_tod_set_packet(void *packet, void *table, s32 *ids, void *tmd, s32 mode, s32 root_coord);
void effect_weapon_check_fire_frame(s32 frame);
void *kaj_tod_set_frame(u32 frame, TodFrame *tod, void *table, s32 *ids, void *tmd, s32 mode, s32 root_coord);
void EnterCriticalSection(void);
void ExitCriticalSection(void);
void DeliverEvent(u32 ev, u32 spec);
extern Player *player_status_player[];
void RotMatrix(SVector *arg0, void *arg1);
void GsSetLsMatrix(void *m);
s16 block_point_on_model(void *obj, s32 x, s32 y, s32 z, u16 mode);
typedef struct {
    u16 id;
    u16 anim_count;
    s32 obj_count;
    s32 tmd_ids_offset;
    s32 tmd_offset;
    s32 hit_tmd_offset;
    s32 tod_offset;
} ModFileHeader;
void GsInitCoordinate2(void *super, void *base);
void kaj_tmd_map(void *tmd_file);
void kaj_tmd_load(void *obj, void *tmd_file, void *coord);
void kaj_tod_init_table(void *table, void *objs, void *coords, void *params, s32 count);
void *kaj_tss_alloc(u32 size);
s32 kaj_tss_start(void *task);
void mod_npcrec_move_step(TssSlot *task);
void mod_npcrec_move_end(TssSlot *task);
s16 mail_wrap_angle(s16 angle);
s32 ratan2(s32 y, s32 x);
s32 atoi(char *s);
void mod_set_anim_by_id(u16 id, s16 anim, s16 frames);
void mod_npcrec_move_to(NpcRecord *rec, s32 x, s32 y, s32 z, s16 rot_x, s16 rot_y, s16 rot_z, s32 seconds);
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
void GsGetLs(void *coord, void *m);
void GsSortObject4J(void *obj, void *ot, s32 shift, void *scratch);

INCLUDE_RODATA("asm/nonmatchings/game/8018D2DC", mod_str_alloc_model);

INCLUDE_RODATA("asm/nonmatchings/game/8018D2DC", mod_str_alloc_buffer);

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

void mod_place_npcrec(NpcRecord *rec, Model *mod) {
    Player *player = player_status_player[0];
    SVector rot;

    mod->coord_tx = rec->pos_x - player->cell_x * 12500;
    mod->coord_ty = rec->pos_y + player->cell_y * 32000;
    mod->coord_tz = rec->pos_z - player->cell_z * 12500;
    rot.vx = (rec->rot_x << 12) / 360;
    rot.vy = (rec->rot_y << 12) / 360;
    rot.vz = (rec->rot_z << 12) / 360;
    RotMatrix(&rot, mod->coord_m);
    mod->coord_flg = 0;
}

void mod_npcrec_move_step(TssSlot *task) {
    NpcRecMove *move = task->data;
    NpcRecord *rec = move->rec;
    Model *mod;

    rec->pos_x = move->from_x + move->delta_x * task->cur / task->target;
    rec->pos_y = move->from_y + move->delta_y * task->cur / task->target;
    rec->pos_z = move->from_z + move->delta_z * task->cur / task->target;
    rec->rot_x = move->from_rot_x + move->delta_rot_x * task->cur / task->target;
    rec->rot_y = move->from_rot_y + move->delta_rot_y * task->cur / task->target;
    rec->rot_z = move->from_rot_z + move->delta_rot_z * task->cur / task->target;
    mod = mod_find(rec->model);
    if (mod != NULL) {
        mod_place_npcrec(rec, mod);
    }
}

void mod_npcrec_move_to(NpcRecord *rec, s32 x, s32 y, s32 z, s16 rot_x, s16 rot_y, s16 rot_z, s32 seconds) {
    TssSlot *task;
    NpcRecMove *move;

    task = kaj_tss_alloc(0x4C);
    task->type = 5;
    task->step = 1;
    task->delay = 2;
    task->on_step = mod_npcrec_move_step;
    task->cur = 0;
    task->on_end = mod_npcrec_move_end;
    task->on_kill = mod_npcrec_move_end;
    task->target = seconds * 30;
    if (rec->pos_x == x && rec->pos_y == y && rec->pos_z == z &&
        rec->rot_x == rot_x && rec->rot_y == rot_y && rec->rot_z == rot_z) {
        task->target = 0;
    }
    move = task->data;
    move->rec = rec;
    move->from_x = rec->pos_x;
    move->from_y = rec->pos_y;
    move->from_z = rec->pos_z;
    move->from_rot_x = rec->rot_x;
    move->from_rot_y = rec->rot_y;
    move->from_rot_z = rec->rot_z;
    move->to_x = x;
    move->to_y = y;
    move->to_z = z;
    move->to_rot_x = rot_x;
    move->to_rot_y = rot_y;
    move->to_rot_z = rot_z;
    move->delta_x = x - rec->pos_x;
    move->delta_y = y - rec->pos_y;
    move->delta_z = z - rec->pos_z;
loop:
    move->delta_rot_x = rot_x - rec->rot_x;
    move->delta_rot_y = rot_y - rec->rot_y;
    move->delta_rot_z = rot_z - rec->rot_z;
    if (move->delta_rot_x > 180) {
        rot_x -= 360;
        goto loop;
    }
    if (move->delta_rot_x < -180) {
        rot_x += 360;
        goto loop;
    }
    if (move->delta_rot_y > 180) {
        rot_y -= 360;
        goto loop;
    }
    if (move->delta_rot_y < -180) {
        rot_y += 360;
        goto loop;
    }
    if (move->delta_rot_z > 180) {
        rot_z -= 360;
        goto loop;
    }
    if (move->delta_rot_z < -180) {
        rot_z += 360;
        goto loop;
    }
    rec->move_task = kaj_tss_start(task);
    rec->moving = 1;
}

void mod_cmd_npcrec(Action *action, EventState *event) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->npc_records;
    ActionCmdShort *cmd = (ActionCmdShort *)action->cmd;
    u16 id = cmd->target;
    NpcRecord *found;
    NpcRecord *shown_rec;
    Model *mod;
    s32 i;
    NpcRecord *table;
    s16 *vars;
    s32 x, y, z;
    s32 rot_y, seconds;

    if (p->npc_record_count == 0) {
        found = NULL;
    } else {
        for (i = 0; i < p->npc_record_count; i++, rec++) {
            if (rec->id == id) {
                found = rec;
                goto done;
            }
        }
        found = NULL;
    }
done:
    if (found == NULL) {
        return;
    }
    switch (cmd->sub) {
    case 0:
        found->enabled = atoi(action->args[0]);
        break;
    case 1:
        found->model = atoi(action->args[0]);
        table = mod_npcrec_table[0];
        vars = action_vars;
        shown_rec = table + cmd->target;
        if (vars[cmd->target] == 0) {
            break;
        }
        if (shown_rec->scaled == 0) {
            shown_rec->scaled = 1;
            shown_rec->pos_x *= 10;
            shown_rec->pos_y *= 10;
            shown_rec->pos_z *= 10;
        }
        shown_rec->shown = 1;
        shown_rec->move_task = -1;
        shown_rec->moving = 0;
        mod = mod_find(shown_rec->model);
        if (mod == NULL) {
            break;
        }
        if (mod->ready == 0) {
            mod_setup(mod, 0, 2, 0);
        }
        mod_place_npcrec(shown_rec, mod);
        shown_rec->shown = 2;
        break;
    case 3:
        x = atoi(action->args[0]) * 10;
        y = atoi(action->args[1]) * 10;
        z = atoi(action->args[2]) * 10;
        rot_y = atoi(action->args[3]);
        seconds = atoi(action->args[4]);
        if (atoi(action->args[5]) == 1) {
            event->state = 4;
            event->wait_flags |= 0x10;
        }
        mod_npcrec_move_to(found, x, y, z, 0, rot_y, 0, seconds);
        break;
    case 4:
        if (atoi(action->args[1]) == 1) {
            event->state = 4;
            event->wait_flags |= 8;
        }
        ((void (*)())mod_set_anim_by_id)((s16)found->model, (s16)atoi(action->args[0]), (s16)atoi(action->args[2]));
        break;
    }
}

void mod_npcrec_update_all(void) {
    NpcRecord *rec;
    Player *player;
    Model *mod;
    Model *mod2;
    SceneTables *tables;
    s32 i;

    tables = &object_scene_tables;
    rec = tables->npc_records;
    player = player_status_player[0];
    if (tables->npc_record_count != 0) {
        for (i = 0; i < tables->npc_record_count; i++, rec++) {
            if (rec->scaled != 0 && rec->shown != 0) {
                if (rec->shown == 1) {
                    mod = mod_find(rec->model);
                    if (mod != NULL) {
                        if (mod->ready == 0) {
                            mod_setup(mod, 0, 2, 0);
                        }
                        mod_place_npcrec(rec, mod);
                        rec->shown = 2;
                    }
                } else if (rec->enabled != 0 && rec->moving == 0 && rec->id != 0) {
                    rec->rot_y = mail_wrap_angle((ratan2(player->pos_x + player->cell_x * 12500 - rec->pos_x,
                                                     player->pos_z + player->cell_z * 12500 - rec->pos_z) * 360 >> 12) - 180);
                    mod2 = mod_find(rec->model);
                    if (mod2 != NULL) {
                        mod_place_npcrec(rec, mod2);
                    }
                }
            }
        }
    }
}

void mod_npcrec_show(u16 id, s16 force) {
    NpcRecord *rec;
    s16 *vars;
    NpcRecord *table;
    Model *mod;

    table = mod_npcrec_table[0];
    vars = action_vars;
    rec = table + id;
    if (vars[id] != 0 || force != 0) {
        if (rec->scaled == 0) {
            rec->scaled = 1;
            rec->pos_x *= 10;
            rec->pos_y *= 10;
            rec->pos_z *= 10;
        }
        rec->shown = 1;
        rec->move_task = -1;
        rec->moving = 0;
        mod = mod_find(rec->model);
        if (mod != NULL) {
            if (mod->ready == 0) {
                mod_setup(mod, 0, 2, 0);
            }
            mod_place_npcrec(rec, mod);
            rec->shown = 2;
        }
    }
}

void mod_npcrec_free_table(void) {
    SceneTables *p = &object_scene_tables;
    if (p->npc_record_count != 0) {
        if (p->npc_records != NULL) {
            free3(p->npc_records);
        }
        p->npc_record_count = 0;
        p->npc_records = NULL;
    }
}

NpcRecord *mod_npcrec_find(u16 id) {
    SceneTables *p = &object_scene_tables;
    s32 n = p->npc_record_count;
    NpcRecord *rec = p->npc_records;
    s32 i;

    if (n == 0) {
        return NULL;
    }
    for (i = 0; i < n; i++, rec++) {
        if (rec->id == id) {
            return rec;
        }
    }
    return NULL;
}

void mod_npcrec_rebase_all(s32 origin_x, s32 origin_y, s32 origin_z) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->npc_records;
    Model *mod;
    s32 i;

    if (p->npc_record_count == 0) {
        return;
    }
    for (i = 0; i < p->npc_record_count; i++, rec++) {
        if (rec->scaled != 0 && rec->enabled != 0 && rec->shown == 2) {
            mod = mod_find(rec->model);
            if (mod != NULL) {
                mod->coord_tx = rec->pos_x - origin_x;
                mod->coord_ty = rec->pos_y - origin_y;
                mod->coord_tz = rec->pos_z - origin_z;
                mod->coord_flg = 0;
            }
        }
    }
}

void mod_npcrec_draw_all(s32 view) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->npc_records;
    Model *mod;
    s32 i;

    if (p->npc_record_count == 0) {
        return;
    }
    for (i = 0; i < p->npc_record_count; i++, rec++) {
        if (rec != NULL && rec->scaled != 0 && rec->enabled != 0 && rec->shown == 2) {
            mod = mod_find(rec->model);
            if (mod != NULL && mod->ready != 0) {
                mod_draw(view, mod, rec->ot_layer);
            }
        }
    }
}

s16 mod_npcrec_find_at_point(s32 x, s32 y, s32 z) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->npc_records;
    Model *mod;
    s32 i;

    if (p->npc_record_count == 0) {
        return -2;
    }
    for (i = 0; i < p->npc_record_count; i++, rec++) {
        if (rec->scaled != 0 && rec->enabled != 0 && rec->shown == 2) {
            mod = mod_find(rec->model);
            if (mod != NULL && mod->ready != 0 && mod->tmd_objects != NULL) {
                GsSetLsMatrix(mod->coord_m);
                if (block_point_on_model(mod->tmd_objects, x, y, z, 1) != 0) {
                    return rec->id;
                }
            }
        }
    }
    return -2;
}

void mod_npcrec_reset_all(void) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->npc_records;
    s32 i;

    for (i = 0; i < p->npc_record_count; i++, rec++) {
        rec->shown = 0;
    }
}

void mod_npcrec_move_end(TssSlot *task) {
    EventState *s = &event_state;
    NpcRecMove *move = task->data;
    NpcRecord *rec = move->rec;
    Model *mod;

    rec->pos_x = move->to_x;
    rec->pos_y = move->to_y;
    rec->pos_z = move->to_z;
    rec->rot_x = move->to_rot_x;
    rec->rot_y = move->to_rot_y;
    rec->rot_z = move->to_rot_z;
    rec->moving = 0;
    mod = mod_find(rec->model);
    if (mod != NULL) {
        mod_place_npcrec(rec, mod);
    }
    if (s->wait_flags & 0x10) {
        s->wait_flags &= ~0x10;
        if (s->wait_flags == 0) {
            s->state = 1;
        }
    }
    rec->move_task = -1;
}
