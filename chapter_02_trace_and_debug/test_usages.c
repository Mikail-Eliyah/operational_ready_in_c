#include "main.h"

// global variables
#define TEST0 ON
#define TEST1 OFF
#define TEST2 ON

int display_N_values_per_line = 5;

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
#define TEST_ON    ON
                                    

void printThis(
#if TEST_ON
              float f) {
                  printf("Float >>> %3.3f\n", f);
#else
              int i) {
                  printf("Integer >>> %d\n", i);
#endif     
}

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

//  chapter_07_trace_and_debug_Configuration_Switches.txt, Ref: https://gist.github.com/Mikail-Eliyah/3c17c8a538bbe8c7f02a6fb499b4e04e
int test_usage_configuration_switches()
{ 
	INFO(">> ");
    
	#if TEST0
		printf("TEST0 is alive.\n");
	#endif 

	#if TEST1
		printf("TEST1 is alive.\n");
	#endif 

	#if TEST2
		printf("TEST2 is alive.\n");
	#endif 

	printf("%s\n", DEMARCATOR_STRING);
	
#if TEST_ON
    float f = 555.555;
    printThis(f);  
#else
    int i = 555;
    printThis(i);    
#endif 

/*
for ON
Float >>> 555.555
for OFF
Integer >>> 555
*/
	printf("%s\n", DEMARCATOR_STRING);
	LINE_NUMBER_OF_WHICH_CODE_FILE; 

}	
	
int test_show_configurations()
{ 
	INFO(">> ");
	
	// print defines
    SHOW_DEFINE(ALPHA_ABSENT);
    SHOW_DEFINE(BETA);
    SHOW_DEFINE(KNOX);
    SHOW_DEFINE(SPINACH);
    SHOW_DEFINE(MEDUSA);
    SHOW_DEFINE(ATHENA);

	printf("%s\n", DEMARCATOR_STRING);
}

