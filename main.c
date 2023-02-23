#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "base_struct.c"
#include "linked_list.c"
#include "array.c"

const int SIZE = 150000;

int main(int argc, char *argv[])
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	item_t element;
	int line_number = 0;

	items_t items;
	node_t *head = NULL;

	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (line_number > 0)
		{
			char *token;
			char *s = NULL;
			int i = 0;
			while ((token = strtok_r(line, ",", &line)))
			{
				city_t result_city;
				gender_t result_gender;
				bool_t result_illness;
				switch (i)
				{
				case 0:
					element.id = atoi(token);
					break;
				case 1:
					result_city = get_city_t(token);
					if (result_city == E)
						printf("City not defined\n");
					element.city = result_city;
					break;
				case 2:
					result_gender = get_gender_t(token);
					if (result_gender == NO)
						printf("Gender not defined\n");
					element.gender = result_gender;
					break;
				case 3:
					element.age = atoi(token);
					break;
				case 4:
					element.income = atoi(token);
					break;
				case 5:
					s = token;
					while (*s != '\n')
					{
						++s;
					}
					*s = '\0';
					result_illness = get_illness_t(token);
					if (result_illness == fuzzy)
						printf("Value not defined\n");
					element.illness = result_illness;
					break;
				}
				i++;
			}
			items[line_number - 1] = element;
			add_to_list(&head, element);
		}
		line = NULL;
		line_number++;
	}

	fclose(fp);
	if (line)
		free(line);

	item_t pos_2 = get_from_list(head, 2, SIZE);
	printf("Item en la posición 3: id=%u, city=%s, age=%u, gender=%s, income=%d, illness=%s\n",
		   pos_2.id, city_names[pos_2.city], pos_2.age, gender_names[pos_2.gender], pos_2.income, illness_values[pos_2.illness]);

	double result = illness_prob_age(items, 65);
	double result_ll = illness_prob_age_ll(head, 65);
	printf("%.3f%%, %.3f%% illness prob to 65 years\n", result, result_ll);
	citizens_per_city(items);

	citizens_per_age(items, 65);

	item_t *new_array = add_item_in_middle(items, SIZE, items[0]);
	add_item_in_middle_ll(head, items[0]);

	item_t last_element = get_from_list(head, 150001, 150001);

	printf("id= %i \n", last_element.id);

	item_t middle_element = get_from_list(head, 74999, 150001);
	printf("id= %i, income= %i \n", items[0].id, items[0].income);
	printf("id= %i, income= %i \n", middle_element.id, middle_element.income);

	printf("(income, id) | new data: (%i, %i), last data: (%i, %i)\n", new_array[75000].income, new_array[75000].id, new_array[150000].income, new_array[150000].id);
	
	average_income_city_range(items, 150000, 30000, 5000, "Dallas");
	
	exit(EXIT_SUCCESS);
}
