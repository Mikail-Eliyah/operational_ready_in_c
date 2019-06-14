#include "main.h"

// global variables
#define SIZE_TO_PAD_TO 60 // 20

int display_N_values_per_line = 5;

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
int test_usage_dynamic_string_buffer_size()
{ 
	INFO(">> ");
    
	struct stringItem *string2;

	allocationStringBuffer ("helloWorld", &string2);

	printf("Struct string: %s\n", (*string2).str);
	free(string2);

	allocationStringBuffer ("another Statement...", &string2);
	printf("Struct string: %s\n", string2->str);
	free(string2);   

	printf("%s\n", DEMARCATOR_STRING);
}	
	
int test_usage_pad_bytes()
{ 
	INFO(">> ");
	
	char msg[800] = "d94ae0832e6445ce42331cb06d531a82b1db4baad30f746dc916df24d4e3c2451fff59a6423eb0e1d02d4fe646cf699dfd818c6e97b051";
     char *msgPadded =  (char*) malloc((SIZE_TO_PAD_TO)*sizeof(char));
          
     printf("Before Padding: %s\n", msg); 
     printf("Original byte length: %d\n", strlen (msg)/2);     
     msgPadded = (char*) malloc((SIZE_TO_PAD_TO*2 + 1)*sizeof(char)); // +1 for null char
     memset(msgPadded, 48, (SIZE_TO_PAD_TO*2));                      // 48 = "0"
     memcpy(msgPadded+(SIZE_TO_PAD_TO*2), "\0", 1); 
     printf("## %s\n", msgPadded); 
     printf("#NumberOfByte (x2 for char)# %d\n", strlen(msgPadded)/2); 
                            
     array_zero_padder_to_front(msg, msgPadded, (SIZE_TO_PAD_TO*2));
     printf("After Padding: %s\n", msgPadded);
     printf("#NumberOfByte (x2 for char)# %d\n", strlen(msgPadded)/2);  

	
	printf("%s\n", DEMARCATOR_STRING);
}

