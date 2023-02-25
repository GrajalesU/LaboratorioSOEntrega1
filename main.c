#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
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

	// item_t pos_2 = get_from_list(head, 2, SIZE);
	// printf("Item en la posición 3: id=%u, city=%s, age=%u, gender=%s, income=%d, illness=%s\n",
	// 	   pos_2.id, city_names[pos_2.city], pos_2.age, gender_names[pos_2.gender], pos_2.income, illness_values[pos_2.illness]);

	// double result = illness_prob_age(items, 65);
	// double result_ll = illness_prob_age_ll(head, 65);
	// printf("%.3f%%, %.3f%% illness prob to 65 years\n", result, result_ll);

	// citizens_per_city(items);
	// citizens_per_city_ll(head);

	// citizens_per_age(items, 65);
	// citizens_per_age_ll(head, 65);

	// item_t *new_array = add_item_in_middle(items, SIZE, items[0]);
	// add_item_in_middle_ll(head, items[0]);

	// item_t last_element = get_from_list(head, 150001, 150001);

	// printf("id= %i \n", last_element.id);

	// item_t middle_element = get_from_list(head, 74999, 150001);
	// printf("id= %i, income= %i \n", items[0].id, items[0].income);
	// printf("id= %i, income= %i \n", middle_element.id, middle_element.income);

	// printf("(income, id) | new data: (%i, %i), last data: (%i, %i)\n", new_array[75000].income, new_array[75000].id, new_array[150000].income, new_array[150000].id);

	// average_income_city_range(items, 30000, 50000, get_city_t("Dallas"));

	// average_income_city_range_ll(head, 30000, 50000, get_city_t("Dallas") );
	show_menu(items, head);
	exit(EXIT_SUCCESS);
}

void show_menu(items_t items, node_t *head)
{
	int option;
	clock_t start, end;
	double cpu_time_used_array, cpu_time_used_ll;

	do
	{
		printf("1. Cantidad de personas por cada ciudad. \n");
		printf("2. Promedio de ingresos de todas las personas que viven en una ");
		printf("determinada ciudad y que tiene entre X y Y a%cos (X y Y incluidos).\n", 204);
		printf("3. Probabilidad de estar enfermo cuando se tiene X o mas a%cos. \n", 164);
		printf("4. Recuperar elemento a partir de su ID. \n");
		printf("5. Insertar un nuevo elemento en la mitad de los datos. \n");
		printf("6. Cantidad de personas que viven en cada ciudad y ademas tiene X a%cos. \n", 164);
		printf("7. Generar reporte en un archivo de salida con los resultados de la invocacion de ");
		printf("cada una de las funciones anteriores. \n");
		printf("8. Terminar. \n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			//tomar tiempo de array
			start = clock();
			int *cities = citizens_per_city(items);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;
			//tomar tiempo de lista ligada
			start = clock();
			citizens_per_city_ll(head);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;

			printf("------\n");
			printf("Dallas: %i ,", cities[0]);
			printf("New York City: %i ,", cities[1]);
			printf("Los Angeles: %i \n", cities[2]);
			printf("Mountain View: %i ,", cities[3]);
			printf("Boston: %i ,", cities[4]);
			printf("Washington D.C: %i \n", cities[5]);
			printf("San Diego: %i ,", cities[6]);
			printf("Austin: %i ,", cities[7]);
			printf("No registra: %i \n", cities[8]);
			printf("Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			printf("------\n\n");
			break;

		case 2:
			printf("------\n");
			printf("Escribe la ciudad: ");
			printf("Dallas: 0, New York City: 1, Los Angeles: 2, Mountain View: 3\n");
			printf("Boston: 4, Washington D.C: 5, San Diego: 6, Austin: 7\n");
			int selected_city;

			scanf("%i", &selected_city);
			const char *current_city = city_names[selected_city];

			if (current_city == "Error")
			{
				printf("Ciudad inválida\n\n");
				break;
			}
			int current_min_age;
			printf("Escribe el inicio del rango de edad (X): ");
			scanf("%d", &current_min_age);

			int current_max_age;
			printf("Escribe el final del rango de edad (Y): ");
			scanf("%d", &current_max_age);

			start = clock();
			double current_income = average_income_city_range(items, current_min_age, current_max_age, selected_city);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			average_income_city_range_ll(head, current_min_age, current_max_age, selected_city);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;

			printf("El promedio de ingresos de todas las personas que viven en %s\n", current_city);
			printf("Que tienen entre %d y %d años, es de %.4f Dolares\n", current_min_age, current_max_age, current_income);
			printf("Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			printf("------\n\n");

			break;

		case 3:
			printf("------\n");
			printf("Escribe la edad: ");

			int current_age;
			scanf("%i", &current_age);
			if (current_age < 0 || current_age > 65)
			{
				printf("Esta edad no puede ser calculada\n\n");
				break;
			}

			start = clock();
			double illness_prob = illness_prob_age(items, current_age);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			illness_prob_age_ll(head, current_age);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;


			printf("La probabilidad de estar enfermo cuando se tiene %i o más años es de %.3f%% \n", current_age, illness_prob);
			printf("Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			printf("------\n\n");

			break;

		case 4:
			break;

		case 5:
			break;

		case 6:
			break;

		case 7:
			break;

		default:
			break;
		}
	} while (option != 8);
}
