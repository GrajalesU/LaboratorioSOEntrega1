#include "base_struct.h"
#ifndef __ARRAY_H
#define __ARRAY_H

typedef item_t items_t[150000];

double illness_prob_age(items_t array, int age);

int* citizens_per_city(items_t items);

int* citizens_per_age(items_t items, int age);
#endif
