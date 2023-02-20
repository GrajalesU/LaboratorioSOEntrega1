#include <stdio.h>
#include "array.h"

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

    printf("%i, %i\n", total, total_illness); // Esto se borra después porque los resultados se imprimen en el documento que hay que generar

    double result = (double)total_illness / total;
    result *= 100;
    return result;
}