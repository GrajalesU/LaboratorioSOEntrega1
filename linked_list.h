#include "base_struct.h"
#ifndef __LINKED_LIST_H_
#define __LINKED_LIST_H_

typedef struct node
{
    item_t item;
    struct node *next;
} node_t;

void add_to_list(node_t **head, item_t item);

item_t get_from_list(node_t *head, int position, int list_size);

void update_in_list(node_t *head, int position, item_t new_item);

void remove_from_list(node_t **head, int position);

#endif