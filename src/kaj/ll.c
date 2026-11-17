#include "common.h"
#include "kaj/ll.h"
#include "kaj/kaj.h"
#include "kaj/misc.h"
#include "psyq/libapi.h"

/*
 * The doubly linked list of the developer library.
 *
 * File boundaries: likely (docs/layout.md): Sony code before; ll.c asserts.
 */

extern char kaj_ll_str_file[];
extern char kaj_ll_str_node_error[];

void kaj_ll_create(LlList **list) {
    *list = kaj_malloc(0x10);
    if (*list == NULL) {
        kaj_abend(3, "Error Allocating LL Handle", kaj_ll_str_file, 0x15);
    }
    (*list)->head = NULL;
    (*list)->tail = NULL;
    (*list)->cursor = NULL;
    (*list)->count = 0;
}

void kaj_ll_destroy(LlList *list) {
    LlNode *node;

    while (list->head != NULL) {
        node = list->head;
        list->head = node->next;
        if (node != NULL) {
            if (node->data != NULL) {
                free3(node->data);
            }
            free3(node);
        }
    }
    list->tail = NULL;
    list->cursor = NULL;
    list->count = 0;
    free3(list);
}

void kaj_ll_insert_before(LlList *list, void *data) {
    LlNode *node;

    node = kaj_malloc(0xC);
    if (node == NULL) {
        kaj_abend(3, kaj_ll_str_node_error, kaj_ll_str_file, 0x3C);
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        list->cursor = node;
        list->count = 1;
    } else {
        if (list->head == list->cursor) {
            node->next = list->cursor;
            list->head->prev = node;
            list->head = node;
            list->cursor = node;
            list->count++;
        } else {
            node->next = list->cursor;
            node->prev = list->cursor->prev;
            list->cursor->prev = node;
            list->cursor = node;
            node->prev->next = node;
            list->count++;
        }
    }
}

void kaj_ll_insert_after(LlList *list, void *data) {
    LlNode *node;

    node = kaj_malloc(0xC);
    if (node == NULL) {
        kaj_abend(3, kaj_ll_str_node_error, kaj_ll_str_file, 0x61);
    }
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
        list->cursor = node;
        list->count = 1;
    } else {
        if (list->tail == list->cursor) {
            node->prev = list->cursor;
            list->tail->next = node;
            list->tail = node;
            list->cursor = node;
            list->count++;
        } else {
            node->prev = list->cursor;
            node->next = list->cursor->next;
            list->cursor->next = node;
            list->cursor = node;
            node->next->prev = node;
            list->count++;
        }
    }
}

void kaj_ll_remove_to_prev(LlList *list) {
    LlNode *node;

    node = list->cursor;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
        list->cursor = NULL;
        list->count = 0;
    } else {
        if (list->head == node) {
            list->cursor = node->next;
            list->cursor->prev = NULL;
        } else {
            list->cursor = node->prev;
            list->cursor->next = node->next;
            if (node->next != NULL) {
                node->next->prev = node->prev;
            }
        }
        list->count--;
    }
    node->prev = NULL;
    node->next = NULL;
    node->data = NULL;
    if (list->head == node) {
        list->head = list->cursor;
    }
    if (list->tail == node) {
        list->tail = list->cursor;
    }
    free3(node);
}

void kaj_ll_remove_to_next(LlList *list) {
    LlNode *node;

    node = list->cursor;
    if (list->head == list->tail) {
        list->head = NULL;
        list->tail = NULL;
        list->cursor = NULL;
        list->count = 0;
    } else {
        if (list->tail == node) {
            list->cursor = node->prev;
            list->cursor->next = NULL;
        } else {
            list->cursor = node->next;
            list->cursor->prev = node->prev;
            if (node->prev != NULL) {
                node->prev->next = node->next;
            }
        }
        list->count--;
    }
    node->prev = NULL;
    node->next = NULL;
    node->data = NULL;
    if (list->head == node) {
        list->head = list->cursor;
    }
    if (list->tail == node) {
        list->tail = list->cursor;
    }
    free3(node);
}

s32 kaj_ll_at_head(LlList *list) {
    if (list == NULL) {
        return 0;
    }
    return list->head == list->cursor;
}

s32 kaj_ll_at_tail(LlList *list) {
    if (list == NULL) {
        return 0;
    }
    return list->tail == list->cursor;
}

INCLUDE_RODATA("asm/nonmatchings/kaj/ll", kaj_ll_str_node_error);
