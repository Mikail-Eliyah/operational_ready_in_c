#include "main.h"


/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
void print_memory_location_of_malloc(void* memory_location, char* description){
	printf("%s", description);
	
	printf("%u \n", memory_location);
}

bool check_malloc_success_status(char* memory_location_start){
	// bool STATUS[2] = {true, false}; 
	
	if(!memory_location_start) { // if(memory_location_start == NULL ) 
         /* Malloc failed, deal with it */
         // According to the Single Unix Specification, malloc will return NULL and set errno when it fails.
		 printf("Unable to allocate size \n");
         fprintf(stderr, "Failed to allocate memory.\n");
         // exit(-1);     
		return false;
    } else {
        printf("Malloc operation is OK.\n"); 
    } 
	
	return true;
}
	
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


void changeContents (int* a, int sizeOfA, int increment, int *b, int sizeOfB) {
    int i, indexOfA;

    for (i=0;i<sizeOfA;i++)
        *(a+i) = *(a+i) + increment;

    printf("sizeof(b): %d \n", sizeof(b));
    printf("sizeof(*b)/sizeof(int): %d \n", sizeof(*b)/sizeof(int));

    printf("sizeof(a): %d \n", sizeof(a));
    printf("sizeof(*a)/sizeof(int): %d \n", sizeof(*a)/sizeof(int));

    for (i=0;i<sizeOfB;i++) {
        indexOfA = (i%(sizeOfA));
        printf("position of A: %d \n", indexOfA);
        *(b+i) = *(a+indexOfA);
    }
}


