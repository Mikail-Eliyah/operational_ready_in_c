#include "main.h"

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_insert_bits_as_substring_and_display_binary_string()
{ 
    int i;
    int n;
    char buff[BUFFER_SIZE + 1];
    int numberOfInputs = 3;
    char* inputs[numberOfInputs];
    
    inputs[0] = "1024";
    inputs[1] = "1108";
    inputs[2] = "0";

    /* Process all inputs, outputting their binary. */
    for (i = 0; i<numberOfInputs; i++) {
        n = atoi (inputs[i]);
        printf("[%3d] %9d -> %s (from '%s')\n", i, n, binrep(n,buff, BUFFER_SIZE), inputs[i]);
    }    
    
    int answer;
    answer = updateBits(1024, 21, 2, 6);
    
    printf("The result [%d] -> '%s'\n", answer, binrep(answer,buff, BUFFER_SIZE));

	INFO(">> ");
		
}

/*

*/