#include "base_struct.h"
#ifndef __ARRAY_H
#define __ARRAY_H

typedef item_t items_t[150000];

double illness_prob_age(items_t array, int age);

double average_income_city_range(items_t items, int people, int min_age, int max_age, char city);

int* citizens_per_city(items_t items);

int* citizens_per_age(items_t items, int age);

item_t *add_item_in_middle(items_t array, int current_size, item_t item);
#endif
