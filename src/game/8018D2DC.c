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

void mod_setup(Model *mod, s32 parent, s32 kind, s32 anim) {
    Unk_8018D2DC *hdr;
    s32 count;
    s32 i;
    s32 j;
    s32 end;
    s32 cnt;
    s32 len;
    s32 k;
    s32 *tod;
    s32 *packet;
    Unk_8018E8B8 rot;

    if (mod->ready == 0) {
        hdr = (Unk_8018D2DC *)mod->data;
        mod->kind = (u8)kind;
        mod->loop = 0;
        mod->id = hdr->unk0;
        mod->anim_count = hdr->unk2;
        mod->tmd_ids = (s32)mod->data + hdr->unk8;
        mod->tmd = (s32)mod->data + hdr->unkC;
        mod->tmd_objects = NULL;
        count = hdr->unk4;
        kaj_tmd_map((void *)mod->tmd);
        if (hdr->unk10 != 0) {
            kaj_tmd_load(&mod->tmd_objects, (u8 *)mod->data + hdr->unk10, &mod->coord_flg);
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
        tod = (s32 *)((u8 *)mod->data + hdr->unk14);
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
        rot.unk0 = 0;
        rot.unk2 = 0;
        rot.unk4 = 0;
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
    mod->data = data;
    id = *data;
    if (id < 0x440) {
        npc = npc_find(1, id);
        if (npc != NULL && npc->unkF == 6) {
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
                    npc->unk4 = 0;
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
        ((Model *)mod)->unkA = 2;
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
            if (D_801E6DB4[0] == 4 || D_801E6DB4[0] == 5) {
                ((Model *)mod)->frame_step = 2;
            } else if (D_801E6DB4[0] >= 6) {
                ((Model *)mod)->frame_step = 3;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/game/8018D2DC", mod_draw_player);

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
                    mod->tod_ptr = (s32)kaj_tod_set_frame(mod->frame, (TodFrame *)mod->tod_ptr, mod->obj_table, (s32 *)mod->tmd_ids, (void *)mod->tmd, (u16)mod->unkA, mod->parent_coord);
                    cnt--;
                    if (cnt > 0) {
                        goto again;
                    }
                } else {
                    mod->tod_ptr = (s32)kaj_tod_set_frame(mod->end_frame, (TodFrame *)mod->tod_ptr, mod->obj_table, (s32 *)mod->tmd_ids, (void *)mod->tmd, (u16)mod->unkA, mod->parent_coord);
                    kind = (u16)mod->kind;
                    mod->playing = 0;
                    mod->frame = -1;
                    mod->end_frame = -1;
                    if (kind != 0 && (kind != 1 || (u16)mod->anim != 5)) {
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

void mod_alloc(Model **out, u32 data_size) {
    *out = kaj_malloc(0x94);
    if (*out == NULL) {
        kaj_abend(3, D_80170A80, mod_str_file, 0x56);
    }
    (*out)->kind = 3;
    (*out)->loop = 0;
    (*out)->ready = 0;
    (*out)->owns_data = 0;
    (*out)->playing = 0;
    (*out)->unkA = 0;
    (*out)->frame = -1;
    (*out)->end_frame = -1;
    if (data_size != 0) {
        (*out)->data = kaj_malloc(data_size);
        if ((*out)->data == NULL) {
            kaj_abend(3, D_80170AA0, mod_str_file, 0x64);
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
                npc->unk4 = 0;
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

void mod_place_npcrec(NpcRecord *rec, Model *mod) {
    Player *player = player_status_player[0];
    Unk_8018E8B8 rot;

    mod->coord_tx = rec->pos_x - player->cell_x * 12500;
    mod->coord_ty = rec->pos_y + player->cell_y * 32000;
    mod->coord_tz = rec->pos_z - player->cell_z * 12500;
    rot.unk0 = (rec->rot_x << 12) / 360;
    rot.unk2 = (rec->rot_y << 12) / 360;
    rot.unk4 = (rec->rot_z << 12) / 360;
    RotMatrix(&rot, mod->coord_m);
    mod->coord_flg = 0;
}

void mod_npcrec_move_step(Unk_8018F958 *task) {
    Unk_8018F958_3C *move = task->unk3C;
    NpcRecord *rec = move->unk48;
    Model *mod;

    rec->pos_x = move->unk0 + move->unk20 * task->unk24 / task->unk26;
    rec->pos_y = move->unk4 + move->unk24 * task->unk24 / task->unk26;
    rec->pos_z = move->unk8 + move->unk28 * task->unk24 / task->unk26;
    rec->rot_x = move->unk30 + move->unk40 * task->unk24 / task->unk26;
    rec->rot_y = move->unk32 + move->unk42 * task->unk24 / task->unk26;
    rec->rot_z = move->unk34 + move->unk44 * task->unk24 / task->unk26;
    mod = mod_find(rec->model);
    if (mod != NULL) {
        mod_place_npcrec(rec, mod);
    }
}

void mod_npcrec_move_to(NpcRecord *rec, s32 x, s32 y, s32 z, s16 rot_x, s16 rot_y, s16 rot_z, s32 seconds) {
    Unk_8018F958 *task;
    Unk_8018F958_3C *move;

    task = kaj_tss_alloc(0x4C);
    task->unk22 = 5;
    task->unk28 = 1;
    task->unk2C = 2;
    task->unk30 = mod_npcrec_move_step;
    task->unk24 = 0;
    task->unk34 = mod_npcrec_move_end;
    task->unk38 = mod_npcrec_move_end;
    task->unk26 = seconds * 30;
    if (rec->pos_x == x && rec->pos_y == y && rec->pos_z == z &&
        rec->rot_x == rot_x && rec->rot_y == rot_y && rec->rot_z == rot_z) {
        task->unk26 = 0;
    }
    move = task->unk3C;
    move->unk48 = rec;
    move->unk0 = rec->pos_x;
    move->unk4 = rec->pos_y;
    move->unk8 = rec->pos_z;
    move->unk30 = rec->rot_x;
    move->unk32 = rec->rot_y;
    move->unk34 = rec->rot_z;
    move->unk10 = x;
    move->unk14 = y;
    move->unk18 = z;
    move->unk38 = rot_x;
    move->unk3A = rot_y;
    move->unk3C = rot_z;
    move->unk20 = x - rec->pos_x;
    move->unk24 = y - rec->pos_y;
    move->unk28 = z - rec->pos_z;
loop:
    move->unk40 = rot_x - rec->rot_x;
    move->unk42 = rot_y - rec->rot_y;
    move->unk44 = rot_z - rec->rot_z;
    if (move->unk40 > 180) {
        rot_x -= 360;
        goto loop;
    }
    if (move->unk40 < -180) {
        rot_x += 360;
        goto loop;
    }
    if (move->unk42 > 180) {
        rot_y -= 360;
        goto loop;
    }
    if (move->unk42 < -180) {
        rot_y += 360;
        goto loop;
    }
    if (move->unk44 > 180) {
        rot_z -= 360;
        goto loop;
    }
    if (move->unk44 < -180) {
        rot_z += 360;
        goto loop;
    }
    rec->move_task = kaj_tss_start(task);
    rec->moving = 1;
}

void mod_cmd_npcrec(Unk_8018EED4 *action, Model *event) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->unk50;
    Unk_8018EED4_0 *cmd = action->unk0;
    u16 id = cmd->unk4;
    NpcRecord *found;
    NpcRecord *shown_rec;
    Model *mod;
    s32 i;
    NpcRecord *table;
    s16 *vars;
    s32 x, y, z;
    s32 rot_y, seconds;

    if (p->unk20 == 0) {
        found = NULL;
    } else {
        for (i = 0; i < p->unk20; i++, rec++) {
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
    switch (cmd->unk2) {
    case 0:
        found->enabled = atoi(action->unk8[0]);
        break;
    case 1:
        found->model = atoi(action->unk8[0]);
        table = mod_npcrec_table[0];
        vars = action_vars;
        shown_rec = table + cmd->unk4;
        if (vars[cmd->unk4] == 0) {
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
        x = atoi(action->unk8[0]) * 10;
        y = atoi(action->unk8[1]) * 10;
        z = atoi(action->unk8[2]) * 10;
        rot_y = atoi(action->unk8[3]);
        seconds = atoi(action->unk8[4]);
        if (atoi(action->unk8[5]) == 1) {
            event->owns_data = 4;
            event->frame_step |= 0x10;
        }
        mod_npcrec_move_to(found, x, y, z, 0, rot_y, 0, seconds);
        break;
    case 4:
        if (atoi(action->unk8[1]) == 1) {
            event->owns_data = 4;
            event->frame_step |= 8;
        }
        ((void (*)())mod_set_anim_by_id)((s16)found->model, (s16)atoi(action->unk8[0]), (s16)atoi(action->unk8[2]));
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
    rec = tables->unk50;
    player = player_status_player[0];
    if (tables->unk20 != 0) {
        for (i = 0; i < tables->unk20; i++, rec++) {
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
    if (p->unk20 != 0) {
        if (p->unk50 != NULL) {
            free3(p->unk50);
        }
        p->unk20 = 0;
        p->unk50 = NULL;
    }
}

NpcRecord *mod_npcrec_find(u16 id) {
    SceneTables *p = &object_scene_tables;
    s32 n = p->unk20;
    NpcRecord *rec = p->unk50;
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
    NpcRecord *rec = p->unk50;
    Model *mod;
    s32 i;

    if (p->unk20 == 0) {
        return;
    }
    for (i = 0; i < p->unk20; i++, rec++) {
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
    NpcRecord *rec = p->unk50;
    Model *mod;
    s32 i;

    if (p->unk20 == 0) {
        return;
    }
    for (i = 0; i < p->unk20; i++, rec++) {
        if (rec != NULL && rec->scaled != 0 && rec->enabled != 0 && rec->shown == 2) {
            mod = mod_find(rec->model);
            if (mod != NULL && mod->ready != 0) {
                mod_draw(view, mod, rec->unk4);
            }
        }
    }
}

s16 mod_npcrec_find_at_point(s32 x, s32 y, s32 z) {
    SceneTables *p = &object_scene_tables;
    NpcRecord *rec = p->unk50;
    Model *mod;
    s32 i;

    if (p->unk20 == 0) {
        return -2;
    }
    for (i = 0; i < p->unk20; i++, rec++) {
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
    NpcRecord *rec = p->unk50;
    s32 i;

    for (i = 0; i < p->unk20; i++, rec++) {
        rec->shown = 0;
    }
}

void mod_npcrec_move_end(Unk_8018F958 *task) {
    EventState *s = &event_state;
    Unk_8018F958_3C *move = task->unk3C;
    NpcRecord *rec = move->unk48;
    Model *mod;

    rec->pos_x = move->unk10;
    rec->pos_y = move->unk14;
    rec->pos_z = move->unk18;
    rec->rot_x = move->unk38;
    rec->rot_y = move->unk3A;
    rec->rot_z = move->unk3C;
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
