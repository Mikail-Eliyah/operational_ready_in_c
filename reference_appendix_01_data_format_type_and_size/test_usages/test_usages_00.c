#include "main.h"

// global variables
#define ARGUMENT_KEY_POSITION 2

int display_N_values_per_line = 20;

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
int test_usage_check_data_format()
{
	INFO(">> ");
	
	// string to int[]
	int count = 0;
	int message_size = 0;

	uint8_t message[256];

    char *msg = "d94ae0832e6445ce42331cb06d531a82b1db4baad30f746dc916df24d4e3c2451fff59a6423eb0e1d02d4fe646cf699dfd818c6e97b051";

    message_size = strlen(msg)/2;
    printf("Message size = %d\n", message_size);
    
	for (count=0; count < message_size; count++) {
        sscanf(msg + 2*count, "%02x", &message[count]);   // char to int: Remember without '&' (even for int or float variables), program will likely crash.
		
		printf("%02x ", message[count]); 
		if ((count+1) % display_N_values_per_line == 0){
			  printf("\n");
		}
		         
        //pos += 2*sizeof(char);
    }
    printf("\n");    

	printf("%s\n", DEMARCATOR_STRING);
}
