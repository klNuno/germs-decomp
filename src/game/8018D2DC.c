#include "common.h"
#include "game/types.h"

void kaj_ll_insert_before(ModelList *arg0, s32 arg1);
void kaj_ll_insert_after(ModelList *arg0, s32 arg1);
ModelList *mod_list;
extern SceneTables object_scene_tables;
void free3(void *ptr);
typedef struct {
    u16 unk0;
    u16 unk2;
    u8 unk4[0xC];
    s16 unk10;
    u8 unk12[0x4];
    s16 unk16;
} Unk_801DFF08;
extern EventState event_state;
Unk_801DFF08 *mod_finished;
void UnDeliverEvent(u32 ev, u32 spec);
KajEvent *kaj_event_push(s32 arg0);
void mod_set_anim(void *arg0, s16 arg1, s16 arg2);
extern NpcRecord *mod_npcrec_table[];
extern s16 action_vars[];
Model *mod_find(u16 arg0);
void mod_setup(Model *arg0, s32 arg1, s32 arg2, s32 arg3);
void mod_place_npcrec(NpcRecord *arg0, Model *arg1);
void mod_draw(s32 arg0, Model *arg1, u16 arg2);
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    u8 unkC[0x4];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u8 unk1C[0x4];
    s32 unk20;
    s32 unk24;
    s32 unk28;
    u8 unk2C[0x4];
    s16 unk30;
    s16 unk32;
    s16 unk34;
    u8 unk36[0x2];
    s16 unk38;
    s16 unk3A;
    s16 unk3C;
    u8 unk3E[0x2];
    s16 unk40;
    s16 unk42;
    s16 unk44;
    u8 unk46[0x2];
    NpcRecord *unk48;
} Unk_8018F958_3C;
typedef struct {
    u8 unk0[0x22];
    s16 unk22;
    s16 unk24;
    s16 unk26;
    s16 unk28;
    u8 unk2A[0x2];
    s32 unk2C;
    void *unk30;
    void *unk34;
    void *unk38;
    Unk_8018F958_3C *unk3C;
} Unk_8018F958;
s16 kaj_ll_at_tail(ModelList *arg0);
Npc *npc_find(s16 arg0, u16 arg1);
NpcRecord *mod_npcrec_find(u16 arg0);
void mod_free_by_id(u16 arg0);
void kaj_ll_remove_to_prev(ModelList *arg0);
void mod_npcrec_reset_all(void);
extern char D_80170A80[];
void *kaj_malloc(u32 size);
void kaj_abend(s32 arg0, char *arg1, char *arg2, s32 arg3);
extern char mod_str_file[];
void mod_list_add(s32 arg0);
extern char D_80170AA0[];
void kaj_tmd_unmap(s32 arg0, s32 arg1);
extern s32 D_801E6DB4[];
void *kaj_tod_set_packet(void *arg0, void *arg1, s32 *arg2, void *arg3, s32 arg4, s32 arg5);
void effect_weapon_check_fire_frame(s32 arg0);
void *kaj_tod_set_frame(u32 arg0, TodFrame *arg1, void *arg2, s32 *arg3, void *arg4, s32 arg5, s32 arg6);
void EnterCriticalSection(void);
void ExitCriticalSection(void);
void DeliverEvent(u32 ev, u32 spec);
typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} Unk_8018E8B8;
extern Player *player_status_player[];
void RotMatrix(Unk_8018E8B8 *arg0, void *arg1);
void GsSetLsMatrix(void *m);
s16 block_point_on_model(void *arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4);
typedef struct {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Unk_8018D2DC;
void GsInitCoordinate2(void *super, void *base);
void kaj_tmd_map(void *arg0);
void kaj_tmd_load(void *arg0, void *arg1, void *arg2);
void kaj_tod_init_table(void *arg0, void *arg1, void *arg2, void *arg3, s32 arg4);
void *kaj_tss_alloc(u32 arg0);
s32 kaj_tss_start(void *arg0);
void mod_npcrec_move_step(Unk_8018F958 *arg0);
void mod_npcrec_move_end(Unk_8018F958 *arg0);
s16 mail_wrap_angle(s16 a);
s32 ratan2(s32 y, s32 x);
typedef struct {
    u16 unk0;
    u16 unk2;
    u16 unk4;
} Unk_8018EED4_0;
typedef struct {
    Unk_8018EED4_0 *unk0;
    s32 unk4;
    char **unk8;
} Unk_8018EED4;
s32 atoi(char *s);
void mod_set_anim_by_id(u16 arg0, s16 arg1, s16 arg2);
void mod_npcrec_move_to(NpcRecord *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7);

INCLUDE_RODATA("asm/nonmatchings/game/8018D2DC", D_80170A80);

INCLUDE_RODATA("asm/nonmatchings/game/8018D2DC", D_80170AA0);

void mod_setup(Model *arg0, s32 arg1, s32 arg2, s32 arg3) {
    Unk_8018D2DC *h;
    s32 n;
    s32 i;
    s32 j;
    s32 end;
    s32 cnt;
    s32 len;
    s32 k;
    s32 *p;
    s32 *q;
    Unk_8018E8B8 rot;

    if (arg0->ready == 0) {
        h = (Unk_8018D2DC *)arg0->data;
        arg0->kind = (u8)arg2;
        arg0->loop = 0;
        arg0->id = h->unk0;
        arg0->anim_count = h->unk2;
        arg0->tmd_ids = (s32)arg0->data + h->unk8;
        arg0->tmd = (s32)arg0->data + h->unkC;
        arg0->tmd_objects = NULL;
        n = h->unk4;
        kaj_tmd_map((void *)arg0->tmd);
        if (h->unk10 != 0) {
            kaj_tmd_load(&arg0->tmd_objects, (u8 *)arg0->data + h->unk10, &arg0->coord_flg);
        }
        arg0->obj_table = kaj_malloc(0xC);
        if (arg0->obj_table == NULL) {
            kaj_abend(3, "Error Allocating GsOBJTABLE2", mod_str_file, 0x8E);
        }
        arg0->dobj_table = kaj_malloc(n * 16);
        if (arg0->dobj_table == NULL) {
            kaj_abend(3, "Error Allocating GsDOBJ2 Table", mod_str_file, 0x92);
        }
        arg0->coord_table = kaj_malloc(n * 80);
        if (arg0->coord_table == NULL) {
            kaj_abend(3, "Error Allocating GsCOORDINATE2", mod_str_file, 0x97);
        }
        arg0->coord_params = kaj_malloc(n * 40);
        if (arg0->coord_params == NULL) {
            kaj_abend(3, "Error Allocating GsCOORD2PARAM", mod_str_file, 0x9C);
        }
        arg0->tod_table = kaj_malloc(arg0->anim_count * 4);
        if (arg0->tod_table == NULL) {
            kaj_abend(3, "Error Allocating TOD Table", mod_str_file, 0xA0);
        }
        p = (s32 *)((u8 *)arg0->data + h->unk14);
        for (i = 0; i < arg0->anim_count; i++) {
            len = *p++;
            ((s32 **)arg0->tod_table)[i] = p;
            p += len >> 2;
        }
        kaj_tod_init_table(arg0->obj_table, arg0->dobj_table, arg0->coord_table, arg0->coord_params, n);
        arg0->coord_tx = 0;
        arg0->coord_ty = 0;
        arg0->coord_tz = 0;
        if (arg1 == 0) {
            arg0->parent_coord = (s32)&arg0->coord_flg;
            GsInitCoordinate2(NULL, &arg0->coord_flg);
        } else {
            arg0->parent_coord = arg1;
            GsInitCoordinate2((void *)arg1, &arg0->coord_flg);
        }
        rot.unk0 = 0;
        rot.unk2 = 0;
        rot.unk4 = 0;
        RotMatrix(&rot, &arg0->coord_m);
        q = ((s32 **)arg0->tod_table)[(u16)arg3];
        q++;
        end = *q++;
        j = q[1];
        for (i = j; i < j + end; i++) {
            cnt = ((u16 *)q)[1];
            q += 2;
            for (k = 0; k < cnt; k++) {
                q = kaj_tod_set_packet(q, arg0->obj_table, (s32 *)arg0->tmd_ids, (void *)arg0->tmd, 0, arg0->parent_coord);
            }
        }
        arg0->anim = arg3;
        arg0->tod_ptr = (s32)q;
        arg0->ready = 1;
        arg0->coord_flg = 0;
    }
}

void mod_create(s16 *arg0) {
    Model *mod;
    Model **pp = &mod;
    Npc *e;
    u16 id;

    *pp = kaj_malloc(0x94);
    if (*pp == NULL) {
        kaj_abend(3, D_80170A80, mod_str_file, 0x56);
    }
    (*pp)->kind = 3;
    (*pp)->loop = 0;
    (*pp)->ready = 0;
    (*pp)->owns_data = 0;
    (*pp)->playing = 0;
    (*pp)->unkA = 0;
    (*pp)->frame = -1;
    (*pp)->end_frame = -1;
    mod->data = arg0;
    id = *arg0;
    if (id < 0x440) {
        e = npc_find(1, id);
        if (e != NULL && e->unkF == 6) {
            mod_setup(mod, 0, 0, 8);
        } else {
            mod_setup(mod, 0, 0, 0);
        }
    }
    mod_list_add((s32)mod);
}

void mod_relocate(s32 *arg0, s32 *arg1) {
    ModelList *list = mod_list;
    Model *item;
    Model *t;
    s32 n;
    s32 i;
    s32 *p;

    if (list->count == 0) {
        item = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            t = list->cursor->data;
            if (t != NULL && (s32 *)t->data == arg0) {
                item = t;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                item = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (item != NULL) {
        n = arg0 - arg1;
        if (item->tod_ptr != 0) {
            item->tod_ptr -= n * 4;
        }
        item->tmd_ids -= n * 4;
        item->tmd -= n * 4;
        kaj_tmd_unmap(item->tmd, n);
        for (i = 0; i < item->anim_count; i++) {
            ((s32 *)item->tod_table)[i] -= n * 4;
        }
        *(void **)item->obj_table = item->dobj_table;
        p = (s32 *)item->dobj_table;
        for (i = 0; i < ((s32 *)item->obj_table)[1]; i++, p += 4) {
            if (p[2] != 0) {
                p[2] -= n * 4;
            }
        }
        if (item->tmd_objects != NULL) {
            ((s32 *)item->tmd_objects)[2] -= n * 4;
            kaj_tmd_unmap((s32)arg1 + arg1[4], n);
        }
        item->data = (s16 *)arg1;
    }
}

void mod_free_pooled(void) {
    ModelList *list = mod_list;
    Model *mod;
    Npc *e;
    NpcRecord *f;
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
                f = mod_npcrec_find(id - 0x440);
                if (f != NULL) {
                    f->shown = 1;
                }
            } else {
                e = npc_find(1, mod->id);
                if (e != NULL) {
                    e->unk4 = 0;
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

void mod_set_anim(void *arg0, s16 arg1, s16 arg2) {
    u16 *p;
    s32 i;
    s32 n;

    if (((Model *)arg0) != NULL && ((Model *)arg0)->ready != 0) {
        ((Model *)arg0)->anim = arg1;
        p = ((u16 **)((Model *)arg0)->tod_table)[arg1];
        p += 2;
        ((Model *)arg0)->end_frame = p[0];
        p += 2;
        ((Model *)arg0)->frame = p[2];
        n = p[1];
        p += 4;
        for (i = 0; i < n; i++) {
            p = kaj_tod_set_packet(p, ((Model *)arg0)->obj_table, (s32 *)((Model *)arg0)->tmd_ids, (void *)((Model *)arg0)->tmd, 2, ((Model *)arg0)->parent_coord);
        }
        ((Model *)arg0)->tod_ptr = (s32)p;
        ((Model *)arg0)->unkA = 2;
        if (((Model *)arg0)->end_frame >= 2) {
            if (arg2 == 0) {
                ((Model *)arg0)->loop = 0;
                ((Model *)arg0)->end_frame = ((Model *)arg0)->frame + ((Model *)arg0)->end_frame - 1;
            } else if (arg2 < 0) {
                ((Model *)arg0)->loop = 1;
                ((Model *)arg0)->end_frame = ((Model *)arg0)->frame + ((Model *)arg0)->end_frame - 1;
            } else {
                ((Model *)arg0)->loop = 0;
                ((Model *)arg0)->end_frame = ((Model *)arg0)->frame + arg2 - 1;
            }
            ((Model *)arg0)->playing = 1;
            ((Model *)arg0)->frame_step = 1;
            if (D_801E6DB4[0] == 4 || D_801E6DB4[0] == 5) {
                ((Model *)arg0)->frame_step = 2;
            } else if (D_801E6DB4[0] >= 6) {
                ((Model *)arg0)->frame_step = 3;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", mod_draw_player);

void mod_update_all(void) {
    ModelList *list = mod_list;
    Model *mod;
    s16 cnt;
    s32 k;

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
                    mod->tod_ptr = (s32)kaj_tod_set_frame(mod->frame, (TodFrame *)mod->tod_ptr, mod->obj_table, (s32 *)mod->tmd_ids, (void *)mod->tmd, (u16)mod->unkA, mod->parent_coord);
                    cnt--;
                    if (cnt > 0) {
                        goto again;
                    }
                } else {
                    mod->tod_ptr = (s32)kaj_tod_set_frame(mod->end_frame, (TodFrame *)mod->tod_ptr, mod->obj_table, (s32 *)mod->tmd_ids, (void *)mod->tmd, (u16)mod->unkA, mod->parent_coord);
                    k = (u16)mod->kind;
                    mod->playing = 0;
                    mod->frame = -1;
                    mod->end_frame = -1;
                    if (k != 0 && (k != 1 || (u16)mod->anim != 5)) {
                        EnterCriticalSection();
                        mod_finished = (Unk_801DFF08 *)mod;
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

void mod_alloc(Model **arg0, u32 arg1) {
    *arg0 = kaj_malloc(0x94);
    if (*arg0 == NULL) {
        kaj_abend(3, D_80170A80, mod_str_file, 0x56);
    }
    (*arg0)->kind = 3;
    (*arg0)->loop = 0;
    (*arg0)->ready = 0;
    (*arg0)->owns_data = 0;
    (*arg0)->playing = 0;
    (*arg0)->unkA = 0;
    (*arg0)->frame = -1;
    (*arg0)->end_frame = -1;
    if (arg1 != 0) {
        (*arg0)->data = kaj_malloc(arg1);
        if ((*arg0)->data == NULL) {
            kaj_abend(3, D_80170AA0, mod_str_file, 0x64);
        }
        (*arg0)->owns_data = 1;
    }
}

void mod_free(Model *arg0) {
    if (arg0 != NULL) {
        if (arg0->ready != 0) {
            free3(arg0->obj_table);
            free3(arg0->dobj_table);
            free3(arg0->coord_table);
            free3(arg0->coord_params);
            free3(arg0->tod_table);
        }
        if (arg0->tmd_objects != NULL) {
            free3(arg0->tmd_objects);
        }
        if (arg0->owns_data != 0) {
            free3(arg0->data);
        }
        free3(arg0);
    }
}

void mod_on_data_free(s16 *arg0) {
    ModelList *list = mod_list;
    Model *item;
    Model *t;
    Npc *e;
    NpcRecord *f;
    s16 id;

    if (list->count == 0) {
        item = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            t = list->cursor->data;
            if (t != NULL && t->data == arg0) {
                item = t;
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                item = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    if (item != NULL) {
        id = *item->data;
        mod_free_by_id(id);
        if (id >= 0x440) {
            f = mod_npcrec_find(id - 0x440);
            if (f != NULL) {
                f->shown = 1;
            }
        } else {
            e = npc_find(1, id);
            if (e != NULL) {
                e->unk4 = 0;
            }
        }
    }
}

void mod_list_add(s32 arg0) {
    if (mod_list->count == 0) {
        kaj_ll_insert_before(mod_list, arg0);
    } else {
        mod_list->cursor = mod_list->tail;
        kaj_ll_insert_after(mod_list, arg0);
    }
}

void mod_free_by_id(u16 arg0) {
    ModelList *list = mod_list;
    Model *mod;

    if (list->count == 0) {
        return;
    }
    mod = mod_find(arg0);
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

Model *mod_find(u16 arg0) {
    ModelList *list = mod_list;
    Model *item;

    if (list->count == 0) {
        return NULL;
    }
    list->cursor = list->head;
    while (1) {
        item = list->cursor->data;
        if (item != NULL && *item->data == arg0) {
            return item;
        }
        if (kaj_ll_at_tail(list) != 0) {
            break;
        }
        list->cursor = list->cursor->next;
    }
    return NULL;
}

void mod_set_anim_by_id(u16 arg0, s16 arg1, s16 arg2) {
    ModelList *list = mod_list;
    Model *item;

    if (list->count == 0) {
        item = NULL;
    } else {
        list->cursor = list->head;
        while (1) {
            item = list->cursor->data;
            if (item != NULL && *item->data == arg0) {
                break;
            }
            if (kaj_ll_at_tail(list) != 0) {
                item = NULL;
                break;
            }
            list->cursor = list->cursor->next;
        }
    }
    mod_set_anim(item, arg1, arg2);
}

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", mod_draw);

s32 mod_finish_handler(void) {
    EventState *s = &event_state;
    KajEvent *e;

    UnDeliverEvent(0xF3000002, 2);
    e = kaj_event_push(0x200);
    if (e != NULL) {
        e->unk8 = mod_finished->unk0;
        e->unkC = mod_finished->unk2;
    }
    if (mod_finished->unk2 == 2) {
        if (s->wait_flags & 8) {
            s->wait_flags &= ~8;
            if (s->wait_flags == 0) {
                s->state = 1;
            }
        }
    }
    if (mod_finished->unk10 != 0) {
        mod_finished->unk10 = 0;
        mod_set_anim(mod_finished, mod_finished->unk16, -1);
    }
    return 0;
}

void mod_place_npcrec(NpcRecord *arg0, Model *arg1) {
    Player *g = player_status_player[0];
    Unk_8018E8B8 rot;

    arg1->coord_tx = arg0->pos_x - g->cell_x * 12500;
    arg1->coord_ty = arg0->pos_y + g->cell_y * 32000;
    arg1->coord_tz = arg0->pos_z - g->cell_z * 12500;
    rot.unk0 = (arg0->rot_x << 12) / 360;
    rot.unk2 = (arg0->rot_y << 12) / 360;
    rot.unk4 = (arg0->rot_z << 12) / 360;
    RotMatrix(&rot, arg1->coord_m);
    arg1->coord_flg = 0;
}

void mod_npcrec_move_step(Unk_8018F958 *arg0) {
    Unk_8018F958_3C *p = arg0->unk3C;
    NpcRecord *e = p->unk48;
    Model *item;

    e->pos_x = p->unk0 + p->unk20 * arg0->unk24 / arg0->unk26;
    e->pos_y = p->unk4 + p->unk24 * arg0->unk24 / arg0->unk26;
    e->pos_z = p->unk8 + p->unk28 * arg0->unk24 / arg0->unk26;
    e->rot_x = p->unk30 + p->unk40 * arg0->unk24 / arg0->unk26;
    e->rot_y = p->unk32 + p->unk42 * arg0->unk24 / arg0->unk26;
    e->rot_z = p->unk34 + p->unk44 * arg0->unk24 / arg0->unk26;
    item = mod_find(e->model);
    if (item != NULL) {
        mod_place_npcrec(e, item);
    }
}

void mod_npcrec_move_to(NpcRecord *arg0, s32 arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s16 arg6, s32 arg7) {
    Unk_8018F958 *t;
    Unk_8018F958_3C *p;

    t = kaj_tss_alloc(0x4C);
    t->unk22 = 5;
    t->unk28 = 1;
    t->unk2C = 2;
    t->unk30 = mod_npcrec_move_step;
    t->unk24 = 0;
    t->unk34 = mod_npcrec_move_end;
    t->unk38 = mod_npcrec_move_end;
    t->unk26 = arg7 * 30;
    if (arg0->pos_x == arg1 && arg0->pos_y == arg2 && arg0->pos_z == arg3 &&
        arg0->rot_x == arg4 && arg0->rot_y == arg5 && arg0->rot_z == arg6) {
        t->unk26 = 0;
    }
    p = t->unk3C;
    p->unk48 = arg0;
    p->unk0 = arg0->pos_x;
    p->unk4 = arg0->pos_y;
    p->unk8 = arg0->pos_z;
    p->unk30 = arg0->rot_x;
    p->unk32 = arg0->rot_y;
    p->unk34 = arg0->rot_z;
    p->unk10 = arg1;
    p->unk14 = arg2;
    p->unk18 = arg3;
    p->unk38 = arg4;
    p->unk3A = arg5;
    p->unk3C = arg6;
    p->unk20 = arg1 - arg0->pos_x;
    p->unk24 = arg2 - arg0->pos_y;
    p->unk28 = arg3 - arg0->pos_z;
loop:
    p->unk40 = arg4 - arg0->rot_x;
    p->unk42 = arg5 - arg0->rot_y;
    p->unk44 = arg6 - arg0->rot_z;
    if (p->unk40 > 180) {
        arg4 -= 360;
        goto loop;
    }
    if (p->unk40 < -180) {
        arg4 += 360;
        goto loop;
    }
    if (p->unk42 > 180) {
        arg5 -= 360;
        goto loop;
    }
    if (p->unk42 < -180) {
        arg5 += 360;
        goto loop;
    }
    if (p->unk44 > 180) {
        arg6 -= 360;
        goto loop;
    }
    if (p->unk44 < -180) {
        arg6 += 360;
        goto loop;
    }
    arg0->move_task = kaj_tss_start(t);
    arg0->moving = 1;
}

void mod_cmd_npcrec(Unk_8018EED4 *arg0, Model *arg1) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *e = p->unk50;
    Unk_8018EED4_0 *cmd = arg0->unk0;
    u16 id = cmd->unk4;
    NpcRecord *found;
    NpcRecord *t;
    Model *obj;
    s32 i;
    NpcRecord *tb;
    s16 *f;
    s32 x, y, z;
    s32 a, b;

    if (p->unk20 == 0) {
        found = NULL;
    } else {
        for (i = 0; i < p->unk20; i++, e++) {
            if (e->id == id) {
                found = e;
                goto done;
            }
        }
        found = NULL;
    }
done:
    if (found == NULL) {
        return;
    }
    switch (cmd->unk2) {
    case 0:
        found->enabled = atoi(arg0->unk8[0]);
        break;
    case 1:
        found->model = atoi(arg0->unk8[0]);
        tb = mod_npcrec_table[0];
        f = action_vars;
        t = tb + cmd->unk4;
        if (f[cmd->unk4] == 0) {
            break;
        }
        if (t->scaled == 0) {
            t->scaled = 1;
            t->pos_x *= 10;
            t->pos_y *= 10;
            t->pos_z *= 10;
        }
        t->shown = 1;
        t->move_task = -1;
        t->moving = 0;
        obj = mod_find(t->model);
        if (obj == NULL) {
            break;
        }
        if (obj->ready == 0) {
            mod_setup(obj, 0, 2, 0);
        }
        mod_place_npcrec(t, obj);
        t->shown = 2;
        break;
    case 3:
        x = atoi(arg0->unk8[0]) * 10;
        y = atoi(arg0->unk8[1]) * 10;
        z = atoi(arg0->unk8[2]) * 10;
        a = atoi(arg0->unk8[3]);
        b = atoi(arg0->unk8[4]);
        if (atoi(arg0->unk8[5]) == 1) {
            arg1->owns_data = 4;
            arg1->frame_step |= 0x10;
        }
        mod_npcrec_move_to(found, x, y, z, 0, a, 0, b);
        break;
    case 4:
        if (atoi(arg0->unk8[1]) == 1) {
            arg1->owns_data = 4;
            arg1->frame_step |= 8;
        }
        ((void (*)())mod_set_anim_by_id)((s16)found->model, (s16)atoi(arg0->unk8[0]), (s16)atoi(arg0->unk8[2]));
        break;
    }
}

void mod_npcrec_update_all(void) {
    NpcRecord *p;
    Player *cam;
    Model *mod;
    Model *mod2;
    SceneTables *g;
    s32 i;

    g = &object_scene_tables;
    p = g->unk50;
    cam = player_status_player[0];
    if (g->unk20 != 0) {
        for (i = 0; i < g->unk20; i++, p++) {
            if (p->scaled != 0 && p->shown != 0) {
                if (p->shown == 1) {
                    mod = mod_find(p->model);
                    if (mod != NULL) {
                        if (mod->ready == 0) {
                            mod_setup(mod, 0, 2, 0);
                        }
                        mod_place_npcrec(p, mod);
                        p->shown = 2;
                    }
                } else if (p->enabled != 0 && p->moving == 0 && p->id != 0) {
                    p->rot_y = mail_wrap_angle((ratan2(cam->pos_x + cam->cell_x * 12500 - p->pos_x,
                                                     cam->pos_z + cam->cell_z * 12500 - p->pos_z) * 360 >> 12) - 180);
                    mod2 = mod_find(p->model);
                    if (mod2 != NULL) {
                        mod_place_npcrec(p, mod2);
                    }
                }
            }
        }
    }
}

void mod_npcrec_show(u16 arg0, s16 arg1) {
    NpcRecord *e;
    s16 *f;
    NpcRecord *b;
    Model *mod;

    b = mod_npcrec_table[0];
    f = action_vars;
    e = b + arg0;
    if (f[arg0] != 0 || arg1 != 0) {
        if (e->scaled == 0) {
            e->scaled = 1;
            e->pos_x *= 10;
            e->pos_y *= 10;
            e->pos_z *= 10;
        }
        e->shown = 1;
        e->move_task = -1;
        e->moving = 0;
        mod = mod_find(e->model);
        if (mod != NULL) {
            if (mod->ready == 0) {
                mod_setup(mod, 0, 2, 0);
            }
            mod_place_npcrec(e, mod);
            e->shown = 2;
        }
    }
}

void mod_npcrec_free_table(void) {
    SceneTables *p = &object_scene_tables;
    if (p->unk20 != 0) {
        if (p->unk50 != NULL) {
            free3(p->unk50);
        }
        p->unk20 = 0;
        p->unk50 = NULL;
    }
}

NpcRecord *mod_npcrec_find(u16 arg0) {
    SceneTables *p = &object_scene_tables;
    s32 n = p->unk20;
    NpcRecord *e = p->unk50;
    s32 i;

    if (n == 0) {
        return NULL;
    }
    for (i = 0; i < n; i++, e++) {
        if (e->id == arg0) {
            return e;
        }
    }
    return NULL;
}

void mod_npcrec_rebase_all(s32 arg0, s32 arg1, s32 arg2) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *e = p->unk50;
    Model *mod;
    s32 i;

    if (p->unk20 == 0) {
        return;
    }
    for (i = 0; i < p->unk20; i++, e++) {
        if (e->scaled != 0 && e->enabled != 0 && e->shown == 2) {
            mod = mod_find(e->model);
            if (mod != NULL) {
                mod->coord_tx = e->pos_x - arg0;
                mod->coord_ty = e->pos_y - arg1;
                mod->coord_tz = e->pos_z - arg2;
                mod->coord_flg = 0;
            }
        }
    }
}

void mod_npcrec_draw_all(s32 arg0) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *e = p->unk50;
    Model *mod;
    s32 i;

    if (p->unk20 == 0) {
        return;
    }
    for (i = 0; i < p->unk20; i++, e++) {
        if (e != NULL && e->scaled != 0 && e->enabled != 0 && e->shown == 2) {
            mod = mod_find(e->model);
            if (mod != NULL && mod->ready != 0) {
                mod_draw(arg0, mod, e->unk4);
            }
        }
    }
}

s16 mod_npcrec_find_at_point(s32 arg0, s32 arg1, s32 arg2) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *e = p->unk50;
    Model *mod;
    s32 i;

    if (p->unk20 == 0) {
        return -2;
    }
    for (i = 0; i < p->unk20; i++, e++) {
        if (e->scaled != 0 && e->enabled != 0 && e->shown == 2) {
            mod = mod_find(e->model);
            if (mod != NULL && mod->ready != 0 && mod->tmd_objects != NULL) {
                GsSetLsMatrix(mod->coord_m);
                if (block_point_on_model(mod->tmd_objects, arg0, arg1, arg2, 1) != 0) {
                    return e->id;
                }
            }
        }
    }
    return -2;
}

void mod_npcrec_reset_all(void) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *e = p->unk50;
    s32 i;

    for (i = 0; i < p->unk20; i++, e++) {
        e->shown = 0;
    }
}

void mod_npcrec_move_end(Unk_8018F958 *arg0) {
    EventState *s = &event_state;
    Unk_8018F958_3C *p = arg0->unk3C;
    NpcRecord *e = p->unk48;
    Model *item;

    e->pos_x = p->unk10;
    e->pos_y = p->unk14;
    e->pos_z = p->unk18;
    e->rot_x = p->unk38;
    e->rot_y = p->unk3A;
    e->rot_z = p->unk3C;
    e->moving = 0;
    item = mod_find(e->model);
    if (item != NULL) {
        mod_place_npcrec(e, item);
    }
    if (s->wait_flags & 0x10) {
        s->wait_flags &= ~0x10;
        if (s->wait_flags == 0) {
            s->state = 1;
        }
    }
    e->move_task = -1;
}
