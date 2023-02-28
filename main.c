#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include "base_struct.c"
#include "linked_list.c"
#include "array.c"

const int SIZE = 150000;

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
			start = clock();
			int *cities = citizens_per_city(items);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

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

			if (strcmp(current_city, "Error") == 0)
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
			printf("------\n\n");
			int id;
			printf("Ingrese el id del elemento a buscar: ");
			scanf("%d", &id);
			item_t *found_item = find_id(items, 150000, id);
			if (found_item != NULL)
			{

				printf(" \n>Recuerda que id corresponde la posición donde se encuentra el dato\n");
				printf(" \n>Codigos de ciudad:\n(0:Dallas),(1:New York City),(2:Los Angeles),\n(3:Mountain view),(4:Boston), (5:Washington DC),\n(6:San Diego), (7:Austin), (8:No registra) \n");
				printf(" \n>Luego la edad del encuestado\n");
				printf(" \n>Genero:\n(0:masculino), (1:femenino)\n");
				printf(" \n>Ingreso corresponde a la cantidad de dinero que gana en dolares USD\n");
				printf(" \n>¿Está enfermo?\n(0:no), (1:si)\n");

				printf("\n------EN EL ARREGLO:\n\n");
				printf("El elemento con id %d es:\n", id);
				print_item(found_item);
				printf("------\n\n");
			}
			else
			{
				printf("No se encontró ningún elemento con id %d\n", id);
			}

			node_t *found_node = find_id_ll(head, id);
			if (found_node != NULL)
			{
				printf("------ EN LA LISTA LIGADA:\n\n");
				print_item(&found_node->item);
				printf("------\n\n");
			}
			else
			{
				printf("Item not found.\n");
			}

			start = clock();
			find_id(items, 150000, id);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			find_id_ll(head, id);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;

			printf("------\n\n");
			printf("Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			printf("------\n\n");

			break;

		case 5:
			printf("------\n\n");
			printf("Escribe la ciudad: ");
			printf("Dallas: 0, New York City: 1, Los Angeles: 2, Mountain View: 3\n");
			printf("Boston: 4, Washington D.C: 5, San Diego: 6, Austin: 7\n");
			int new_item_id = 7500;

			int new_item_city;
			scanf("%i", &new_item_city);

			const char *current_new_item_city = city_names[new_item_city];
			if (strcmp(current_new_item_city, "Error") == 0)
			{
				printf("Ciudad inválida\n\n");
				break;
			}

			printf("Escribe el genero: ");
			printf("Femenino: 0, Masculino: 1 \n");

			int new_item_gender;
			scanf("%i", &new_item_gender);

			const char *current_new_item_gender = gender_names[new_item_gender];
			if (strcmp(current_new_item_gender, "No") == 0)
			{
				printf("Genero inválida\n\n");
				break;
			}

			int new_item_age;
			printf("Escribe la edad: ");
			scanf("%i", &new_item_age);

			if (new_item_age < 0 || new_item_age > 125)
			{
				printf("Esta edad no puede ser ingresada\n\n");
				break;
			}

			int new_item_income;
			printf("Escribe el ingreso: ");
			scanf("%i", &new_item_income);

			if (new_item_income < 0)
			{
				printf("Este ingreso no puede ser ingresado\n\n");
				break;
			}

			int new_item_illness;
			printf("Escribe si se encuentra enfermo: ");
			printf("No: 0, Si: 1 \n");
			scanf("%i", &new_item_illness);

			item_t current_new_item = {new_item_id, new_item_city, new_item_age, new_item_gender, new_item_income, new_item_illness};
			// Ingresar registro con id:27, city:mountain view, gender:female, age:66, income:123456, illness:no
			start = clock();
			add_item_in_middle(items, SIZE, current_new_item);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			add_item_in_middle_ll(head, current_new_item);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;

			printf("Ingresado con exito \n");
			printf("Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			printf("------\n\n");
			break;

		case 6:
			printf("------\n\n");
			printf("Escribe la edad: ");

			int citizen_age;
			scanf("%i", &citizen_age);
			if (citizen_age < 0 || citizen_age > 65)
			{
				printf("Esta edad no puede ser calculada\n\n");
				break;
			}

			start = clock();
			int *cities_per_age = citizens_per_age(items, citizen_age);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			citizens_per_age_ll(head, citizen_age);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;

			printf("------\n");
			printf("Dallas: %i ,", cities_per_age[0]);
			printf("New York City: %i ,", cities_per_age[1]);
			printf("Los Angeles: %i \n", cities_per_age[2]);
			printf("Mountain View: %i ,", cities_per_age[3]);
			printf("Boston: %i ,", cities_per_age[4]);
			printf("Washington D.C: %i \n", cities_per_age[5]);
			printf("San Diego: %i ,", cities_per_age[6]);
			printf("Austin: %i ,", cities_per_age[7]);
			printf("No registra: %i \n", cities_per_age[8]);
			printf("Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			printf("------\n\n");

			break;

		case 7:

			// En este punto 7 generamos un reporte con datos predeterminados por cada punto

			printf("------\n\n");
			// Abrir archivo de reporte si es que existe, en modo a de append y +
			FILE *report_file = fopen("reporte.txt", "a+");
			if (report_file == NULL)
			{
				printf("Error al abrir el archivo de reporte\n");
				break;
			}

			// Escribir encabezado con timestamp y nombre de usuario
			time_t rawtime;
			struct tm *timeinfo;
			time(&rawtime);
			timeinfo = localtime(&rawtime);

			fprintf(report_file, "\n╔════════════════════════════════════════════════════╗\n");
			fprintf(report_file, ">> INICIO DE REPORTE %s\n", asctime(timeinfo));
			fprintf(report_file, "Nombre de usuario: grupo # 1 \n");

			int NUM_CITIES = 8;

			// PUNTO 1. Invocación al método de reporte de ciudadanos por ciudad
			// Imprimir reporte de datos
			fprintf(report_file, "Reporte de datos:\n\n");
			fprintf(report_file, "                           PUNTO I \n");
			fprintf(report_file, "Reporte de cantidad de personas por ciudad\n\n");
			fprintf(report_file, "Cantidad de ciudadanos: %d\n", count_items(head));
			int *citizens_city = citizens_per_city_ll(head);
			for (int i = 0; i < NUM_CITIES; i++)
			{
				fprintf(report_file, "Ciudad %s: %d ciudadanos\n", city_names[i], citizens_city[i]);
			}
			fprintf(report_file, "\n");

			start = clock();
			citizens_per_city(items);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			citizens_per_city_ll(head);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;

			fprintf(report_file, "Benchmark del punto 1:          	          *\n");
			fprintf(report_file, "╒═════════════════════════════════════════════════════════════════════╕\n");
			fprintf(report_file, "│Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			fprintf(report_file, "╘═════════════════════════════════════════════════════════════════════╛\n");

			// PUNTO 2. Invocación al método que busca el promedio de ingresos en USD
			// La información precargada para el informe es: Ciudad:3 que corresponde a mountain view, edad minima 17, edad maxima 36
			city_t city = 3;
			int min_age = 17, max_age = 36;
			double avg_income = average_income_city_range_ll(head, min_age, max_age, city);
			fprintf(report_file, "                           PUNTO I I\n");
			fprintf(report_file, "Reporte de promedio de ingresos de una ciudad determinada en un rango dado\n\n");
			fprintf(report_file, "Promedio de ingresos para ciudadanos de Mountain View entre %d y %d años: %.2f\n\n", min_age, max_age, avg_income);

			start = clock();
			average_income_city_range(items, current_min_age, current_max_age, selected_city);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			average_income_city_range_ll(head, current_min_age, current_max_age, selected_city);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;

			fprintf(report_file, "Benchmark del punto 2:          	          * *\n");
			fprintf(report_file, "╒═════════════════════════════════════════════════════════════════════╕\n");
			fprintf(report_file, "│Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			fprintf(report_file, "╘═════════════════════════════════════════════════════════════════════╛\n");

			// PUNTO 3. Invocación al método que arroja la probabilidad de estar enfermo con una edad predeterminada
			// La información precargada para el informe es: Edad:21
			int age = 21;
			fprintf(report_file, "                           PUNTO I I I \n");
			fprintf(report_file, "Reporte de la probabilidad que una persona de determinada edad esté enferma\n\n");
			illness_prob = illness_prob_age(items, age);
			fprintf(report_file, "La probabilidad de estar enfermo cuando se tiene 21 o más años es de %.3f%%\n\n", illness_prob);

			start = clock();
			illness_prob_age(items, age);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			illness_prob_age_ll(head, age);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;

			fprintf(report_file, "Benchmark del punto 3:          	          * * *\n");
			fprintf(report_file, "╒═════════════════════════════════════════════════════════════════════╕\n");
			fprintf(report_file, "│Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			fprintf(report_file, "╘═════════════════════════════════════════════════════════════════════╛\n");

			// PUNTO 4. Invocación al método que busca un id determinado y trae la información del item
			// La información precargada para el informe es: Mostrar registro 75902
			node_t *item = find_id_ll(head, 75902);

			if (item != NULL)
			{
				fprintf(report_file, "                           PUNTO I V \n");
				fprintf(report_file, "Busqueda de un id determinado\n");

				fprintf(report_file, " \n>Recuerda que id corresponde la posición donde se encuentra el dato\n");
				fprintf(report_file, " \n>Codigos de ciudad:\n(0:Dallas),(1:New York City),(2:Los Angeles),\n(3:Mountain view),(4:Boston), (5:Washington DC),\n(6:San Diego), (7:Austin), (8:No registra) \n");
				fprintf(report_file, " \n>Luego la edad del encuestado\n");
				fprintf(report_file, " \n>Genero:\n(0:masculino), (1:femenino)\n");
				fprintf(report_file, " \n>Ingreso corresponde a la cantidad de dinero que gana en dolares USD\n");
				fprintf(report_file, " \n>¿Está enfermo?\n(0:no), (1:si)\n");

				fprintf(report_file, "\nRegistro con id 75902:\n");
				fprintf(report_file, "Id: %d\n", item->item.id);
				fprintf(report_file, "Ciudad: %d\n", item->item.city);
				fprintf(report_file, "Edad: %d\n", item->item.age);
				fprintf(report_file, "Género: %d\n", item->item.gender);
				fprintf(report_file, "Ingreso USD: %d\n", item->item.income);
				fprintf(report_file, "¿Está enfermo?: %d\n", item->item.illness);
				fprintf(report_file, "\n");
			}
			else
			{
				fprintf(report_file, "No se encontró un registro con id 75902\n\n");
			}
			// Comparación de tiempos entre arreglo y lista ligada para buscar el registro con id 27
			id = 75902;

			start = clock();
			find_id(items, 150000, id);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			find_id_ll(head, id);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;
			fprintf(report_file, "\n");

			fprintf(report_file, "Benchmark del punto 4:          	          * * * *\n");
			fprintf(report_file, "╒═════════════════════════════════════════════════════════════════════╕\n");
			fprintf(report_file, "│Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			fprintf(report_file, "╘═════════════════════════════════════════════════════════════════════╛\n");

			// PUNTO 5. Invocación al método que inserta un nodo en la posición 749999
			// La información precargada para el informe es:  Ingresar registro con id:27, city:mountain view, gender:female, age:66, income:123456, illness:no
			item_t new_item = {27, 3, 66, FEMALE, 123456, false};
			add_to_list(&head, new_item);
			fprintf(report_file, "                           PUNTO   V   \n");
			fprintf(report_file, "Agregar un nuevo registro en un lugar determinado\n\n");
			fprintf(report_file, "Se agregó un nuevo registro con los siguientes datos:\n");
			fprintf(report_file, "nuevo item agregado en la posición 749999: id:27, city:mountain view, gender:female, age:66, income:123456, illness:no\n");
			// print_item(&new_item);

			item_t current_new_item2 = {27, 3, 66, FEMALE, 123456, false};

			start = clock();
			add_item_in_middle(items, SIZE, current_new_item2);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			add_item_in_middle_ll(head, current_new_item2);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;

			fprintf(report_file, "\n");

			fprintf(report_file, "Benchmark del punto 5:          	          * * * * *\n");
			fprintf(report_file, "╒═════════════════════════════════════════════════════════════════════╕\n");
			fprintf(report_file, "│Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			fprintf(report_file, "╘═════════════════════════════════════════════════════════════════════╛\n");

			// PUNTO 6. Invocación al método que busca el promedio de ingresos en USD
			// La información precargada para el informe es:
			// Edad 30
			int edad = 30;

			start = clock();
			cities_per_age = citizens_per_age(items, edad);
			end = clock();
			cpu_time_used_array = ((double)(end - start)) / CLOCKS_PER_SEC;

			start = clock();
			citizens_per_age_ll(head, edad);
			end = clock();
			cpu_time_used_ll = ((double)(end - start)) / CLOCKS_PER_SEC;

			fprintf(report_file, "                           PUNTO   V  I \n");
			fprintf(report_file, "Reporte de cantidad de personas que viven en una ciudad determinada con determinada edad \n\n");
			fprintf(report_file, "Cantidad de ciudadanos de 30 años\n\n");

			fprintf(report_file, "------\n");
			fprintf(report_file, "Dallas: %i ,", cities_per_age[0]);
			fprintf(report_file, "New York City: %i ,", cities_per_age[1]);
			fprintf(report_file, "Los Angeles: %i \n", cities_per_age[2]);
			fprintf(report_file, "Mountain View: %i ,", cities_per_age[3]);
			fprintf(report_file, "Boston: %i ,", cities_per_age[4]);
			fprintf(report_file, "Washington D.C: %i \n", cities_per_age[5]);
			fprintf(report_file, "San Diego: %i ,", cities_per_age[6]);
			fprintf(report_file, "Austin: %i ,", cities_per_age[7]);
			fprintf(report_file, "No registra: %i \n", cities_per_age[8]);
			fprintf(report_file, "------\n\n");

			fprintf(report_file, "Benchmark del punto 6:          	          * * * * *\n");
			fprintf(report_file, "╒═════════════════════════════════════════════════════════════════════╕\n");
			fprintf(report_file, "│Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			fprintf(report_file, "╘═════════════════════════════════════════════════════════════════════╛\n");

			// Escribir fin de informe con timestamp
			fprintf(report_file, "\nFin de reporte %s\n", asctime(timeinfo));
			fprintf(report_file, "╚════════════════════════════════════════════════════╝");
			fprintf(report_file, "\n\n");

			// Leer y escribir la información anterior al final del archivo
			rewind(report_file);
			char buffer[1000];
			size_t n;
			while ((n = fread(buffer, 1, sizeof(buffer), report_file)) > 0)
			{
				fwrite(buffer, 1, n, stdout);
			}

			// Cerrar archivo de reporte
			fclose(report_file);

			printf("------\n\n");
			printf("Tiempo array: %.9f, Tiempo Lista ligada: %.9f \n", cpu_time_used_array, cpu_time_used_ll);
			printf("------\n\n");

			printf("Reporte generado en el archivo reporte.txt.\n");
			break;

		default:
			break;
		}
	} while (option != 8);
}

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

	show_menu(items, head);
	exit(EXIT_SUCCESS);
}
