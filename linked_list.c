#include <stdio.h>
#include "linked_list.h"


/**
 * 
 * Añade un nuevo elemento al principio de la lista
 * Esto significa que el úlimo elemento que se añada es el primero de ella
 * Si quiere recorrer el array debe de hacerlo
*/
void add_to_list(node_t **head, item_t item)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    new_node->item = item;

    new_node->next = *head;
    *head = new_node;
} 


/**
 * 
 * Recorre la lista hasta el elemento ingresado por la variable position
 * Si necesitas el primer elemento, debes de recorrer toda la lista
*/
item_t get_from_list(node_t *head, int position, int list_size)
{
    node_t *current_node = head;
    for (int i = 0; i < (list_size - (position + 1)); i++)
    {
        current_node = current_node->next;
    }

    return current_node->item;
}






