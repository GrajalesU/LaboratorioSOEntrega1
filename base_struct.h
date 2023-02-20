#ifndef __BASE_SRUC_H_
#define __BASE_SRUC_H_

typedef enum {
	D = 0,	//->"Dallas"
	N = 1,	//-> "New York City""
       	L = 2,	//-> "Los Angeles"
       	M = 3,	//-> "Mountain View"
       	B = 4,	//-> "Boston"
       	W = 5,	//-> "Washington D.C."
       	S = 6,	//-> "San Diego"
	A = 7,	//-> "Austin"
	E = 8,	//-> "Not found"
} city_t;

const char *const city_names[9];

city_t get_city_t(char *city_name);

typedef enum {FEMALE, MALE, NO} gender_t;

const char *const gender_names[3];

gender_t get_gender_t(char *gender_name);

typedef enum {false, true, fuzzy} bool_t;

const char *const illness_values[3];

bool_t get_illness_t(char *illness_value);

typedef struct {
	unsigned int id;
	city_t city;
	unsigned int age;
	gender_t gender;
	int income;
	bool_t illness;
} item_t;

#endif
