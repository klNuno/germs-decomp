#ifndef GAME_MOD_H
#define GAME_MOD_H

#include "common.h"
#include "game/types.h"
#include "kaj/view.h"

typedef struct ModelListNode {
    u8 unk0[0x4];
    struct ModelListNode *next;
    Model *data;
} ModelListNode;

typedef struct ModelList {
    ModelListNode *head;
    ModelListNode *tail;
    ModelListNode *cursor;
    s32 count;
} ModelList;

/* Functions of src/game/mod.c that other files call or a table names. */
void mod_setup(Model *mod, s32 parent, s32 kind, s32 anim);
void mod_create(s16 *data);
void mod_relocate(s32 *old_data, s32 *new_data);
void mod_free_pooled(void);
void mod_set_anim(void *mod, s16 anim, s16 frames);
void mod_draw_player(ViewBuffer *view, u16 mode);
void mod_update_all(void);
void mod_alloc(Model **out, u32 data_size);
void mod_on_data_free(s16 *data);
void mod_list_add(s32 mod);
void mod_free_by_id(u16 id);
void mod_free_all(void);
Model *mod_find(u16 id);
void mod_draw(ViewBuffer *view, Model *mod, u16 ot_layer);
s32 mod_finish_handler(void);

/* Declared in the calling files, each with the argument and return widths its code needs:
   mod_set_anim_by_id. */

#endif
