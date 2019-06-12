#include "main.h"

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/

int print_memory_contents(unsigned char* start_of_location_memory, int length, int display_N_values_per_line, char* description) { 
	printf("%s", description);

	for (int i=0; i<length; i++) {   
		printf("0x%x \t", *(start_of_location_memory+i));
		
		if ((i+1) % display_N_values_per_line == 0){
			printf("\n");
		}
    }
	printf("\n");
	
}

int zerorize_memory_contents(unsigned char* start_of_location_memory, int length) { 
	for (int i=0; i<length; i++) {   
		*(start_of_location_memory + i) = 0;
    }
}

int fill_memory_contents_with_given_value (unsigned char* start_of_location_memory, int length, int given_value) { 
	for (int i=0; i<length; i++) {   
		*(start_of_location_memory + i) = given_value;
    }
}


