#ifndef KAJ_LL_H
#define KAJ_LL_H

#include "common.h"
#include "game/types.h"

typedef struct LlNode {
    struct LlNode *prev;
    struct LlNode *next;
    struct ActionSet *data;
} LlNode;

typedef struct LlList {
    LlNode *head;
    LlNode *tail;
    LlNode *cursor;
    s32 count;
} LlList;

/* Functions of src/kaj/ll.c that other files call or a table names. */
void kaj_ll_create(LlList **list);
void kaj_ll_insert_before(LlList *list, void *data);
void kaj_ll_insert_after(LlList *list, void *data);
void kaj_ll_remove_to_prev(LlList *list);

/* Declared in the calling files, each with the argument and return widths its code needs:
   kaj_ll_at_tail. */

#endif
