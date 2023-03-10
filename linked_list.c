#include <stdio.h>
#include "linked_list.h"

/**
 *
 * Añade un nuevo elemento al principio de la lista
 * Esto significa que el último elemento que se añada es el primero de ella
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

/**
 *
 * Solución al ejercicio 1
 * Reporta la cantidad de personas por cada ciudad.
 */

int *citizens_per_city_ll(node_t *head)
{
    node_t *current = head;
    int *cities = (int *)calloc(10, sizeof(int));
    while (current != NULL)
    {
        cities[current->item.city]++;
        current = current->next;
    }
    return cities;
}

/**
 *
 * Solución al ejercicio 2
 * Obtiene el promedio de ingresos de todas las personas que viven en una determinada ciudad y que tienen entre X y Y años (X y Y incluidos).
 */

double average_income_city_range_ll(node_t *head, int min_age, int max_age, city_t city)
{
    double result = 0.0;
    int selected_people = 0;
    double incomes_sum = 0.0;
    node_t *current = head;

    while (current != NULL)
    {
        if (current->item.city == city && current->item.age >= min_age && current->item.age <= max_age)
        {
            incomes_sum += current->item.income;
            selected_people++;
        }
        current = current->next;
    }

    if (selected_people > 0)
    {
        result = incomes_sum / selected_people;
    }
    return result;
}

/**
 *
 * Solución al ejercicio 3
 * Reporta la probabilidad de estar enfermo cuando se tiene X o más años.
 */

double illness_prob_age_ll(node_t *head, int age)
{
    node_t *current = head;

    int total = 0;
    int total_illness = 0;

    while (current != NULL)
    {
        if (current->item.age >= age)
        {
            total += 1;
            if (current->item.illness == true)
            {
                total_illness += 1;
            }
        }

        current = current->next;
    }

    double result = (double)total_illness / total;
    result *= 100;
    return result;
}

/**
 *
 * Solución al punto 4
 * Inserta un elemento en la mitad de la lista
 */

node_t *find_id_ll(node_t *head, int id)
{
    node_t *current_node = head;

    while (current_node != NULL)
    {
        if (current_node->item.id == id)
        {
            return current_node;
        }
        current_node = current_node->next;
    }

    return NULL;
}

int count_items(node_t *head)
{
    int count = 0;
    node_t *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

/**
 *
 * Solución al punto 5
 * Inserta un elemento en la mitad de la lista
 */

void add_item_in_middle_ll(node_t *head, item_t new_item)
{
    node_t *current_node = head;
    /**node_t *new_node;**/
    node_t *new_node = malloc(sizeof(node_t));
    new_node->item = new_item;

    new_node->item.id = 75000;
    for (int i = 0; i <= 75000; i++)
    {
        current_node->item.id += 1;
        if (i == 75000)
        {
            new_node->next = current_node->next;
            current_node->next = new_node;
        }
        else
        {
            current_node = current_node->next;
        }
    }
}

/**
 *
 * Solución al ejercicio 6
 * Reporta la cantidad de personas por cada ciudad con X edad.
 */

int *citizens_per_age_ll(node_t *head, int age)
{
    node_t *current = head;
    int *cities = (int *)calloc(10, sizeof(int));
    while (current != NULL)
    {
        if (current->item.age == age)
        {
            cities[current->item.city]++;
        }
        current = current->next;
    }

    return cities;
}
