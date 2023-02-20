#include <string.h>
#include "base_struct.h"

const char *const city_names[] = {
         [D] = "Dallas",
         [N] = "New York City",
         [L] = "Los Angeles",
         [M] = "Mountain View",
	 [B] = "Boston",
         [W] = "Washington D.C.",
         [S] = "San Diego",
         [A] = "Austin",
         [E] = "Error",
};

const char *const gender_names[] = {
        [FEMALE] = "Female",
        [MALE] = "Male",
	[NO] = "No",
};

const char *const illness_values[] = {
         [false] = "No",
         [true] = "Yes",
         [fuzzy] = "Not defined",
};

city_t get_city_t(char *city_name){
	if( 0 == strcmp(city_name, "Dallas")){
		return D;
	}else if(0 == strcmp("New York City", city_name)){
		return N;
	}else if(0 == strcmp("Los Angeles", city_name)){
		return L;
	}else if(0 == strcmp("Mountain View", city_name)){
		return M;
	}else if(0 == strcmp("Boston", city_name)){
		return B;
	}else if(0 == strcmp("Washington D.C.", city_name)){
		return W;
	}else if(0 == strcmp("San Diego", city_name)){
		return S;
	}else if(0 == strcmp("Austin", city_name)){
		return A;
	}else{
		return E;
	}
}

gender_t get_gender_t(char *gender_name){
	if(0 == strcmp(gender_name, "Female")){
		return FEMALE;
	}else if(0 == strcmp(gender_name, "Male")){
		return MALE;
	}
	return NO;
}

bool_t get_illness_t(char *illness_value){
	if(0 == strcmp(illness_value, "No"))
		return false;
	else if(0 == strcmp(illness_value, "Yes"))
		return true;
	return fuzzy;
}
