#include <stdio.h>
#include "array.h"

/**
 *
 * Solución al ejercicio 1
 * Reporta la cantidad de personas por cada ciudad.
 */

int *citizens_per_city(items_t items)
{
    int *cities = (int *)calloc(10, sizeof(int));

    for (int i = 0; i < 150000; i++)
    {
        cities[items[i].city]++;
    }

    return cities;
}

/**
 *
 * Solución al ejercicio 2
 * Obtiene el promedio de ingresos de todas las personas que viven en una determinada ciudad y que tienen entre X y Y años (X y Y incluidos).
 */

double average_income_city_range(items_t items, int min_age, int max_age, city_t city)
{
    double result = 0.0;
    int selected_people = 0;
    double incomes_sum = 0.0;

    for (int i = 0; i < 150000; i++)
    {
        if (items[i].city == city && items[i].age >= min_age && items[i].age <= max_age)
        {
            incomes_sum += items[i].income;
            selected_people++;
        }
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

double illness_prob_age(items_t items, int age)
{
    int total = 0;
    int total_illness = 0;

    for (int i = 0; i < 150000; i++)
    {
        if (items[i].age >= age)
        {
            total += 1;
            if (items[i].illness == true)
            {
                total_illness += 1;
            }
        }
    }

    double result = (double)total_illness / total;
    result *= 100;
    return result;
}

/*
ejercicio 4: encontrar por id
Función para encontrar un elemento por su id */

item_t *find_id(item_t *arr, int size, int id)
{
    int index = id - 1; // Índice del elemento en el array
    if (index < 0 || index >= size)
    {                // Verificar si el índice es válido
        return NULL; // El índice no es válido, se retorna NULL
    }
    return &arr[index]; // Se retorna el puntero al elemento del índice correspondiente
}

/**
 *
 * Solución al ejercicio 5
 * Inserta un nuevo elemento en la mitad de los datos.
 */

item_t *add_item_in_middle(items_t array, int current_size, item_t item)
{
    int new_size = current_size + 1;
    item_t *new_array = (item_t *)malloc(new_size * sizeof(item_t));
    int half = (current_size / 2) - 1;
    for (int i = 0; i < new_size; i++)
    {
        if (i < half)
        {
            new_array[i] = array[i];
        }
        else if (i == half)
        {
            item.id = half;
            new_array[i] = item;
        }
        else
        {
            array[i - 1].id = i + 1;
            new_array[i] = array[i - 1];
        }
    }

    return new_array;
}

/**
 *
 * Solución al ejercicio 6
 * Reporta la cantidad de personas por cada ciudad con X edad.
 */

int *citizens_per_age(items_t items, int age)
{
    int *cities = (int *)calloc(10, sizeof(int));

    for (int i = 0; i < 150000; i++)
    {
        if (items[i].age == age)
        {
            cities[items[i].city]++;
        }
    }

    return cities;
}

void print_item(item_t *item)
{
    printf("ID: %d\n", item->id);
    printf("City: %d\n", item->city);
    printf("Age: %d\n", item->age);
    printf("Gender: %u\n", item->gender);
    printf("Income: %d\n", item->income);
    printf("Illness: %u\n", item->illness);
}
