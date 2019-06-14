#include "main.h"

// global variables
#define TEST0 ON
#define TEST1 OFF
#define TEST2 ON

#define TEST_ON    ON

// #define OPERATOR ON	// comment, then uncomment this for testing

int FLAG_GLOBAL = OFF;    // globally accessed with access control

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
int check_mode_set(int ON_OFF)
{

#ifdef OPERATION_STATUS
    if (OFF == OPERATION_STATUS) {
        printf("OPERATION_STATUS OFF ... exiting ... \n");
        return OFF;
    }

    printf("OPERATION_STATUS ON. \n");

    #ifdef OPERATOR
		printf("OPERATOR defined. \n");
	#endif
		
    #ifndef OPERATOR
		printf("OPERATOR not defined. \n");
        #define STATUS_MSG_FOR_OPERATOR "OPERATOR rights."
        #define OPERATOR ON

    printf("STATUS_MSG_FOR_OPERATOR: %s \n", STATUS_MSG_FOR_OPERATOR);
    #endif

    printf("Configuring ... \n");
        if (ON == ON_OFF)
            FLAG_GLOBAL = ON;
    printf("Configuring ... [DONE]. \n");

    return FLAG_GLOBAL;
#else
    printf("OPERATION_STATUS NOT_SUPPORTED ... exiting ... \n");
    return OFF;
#endif

}

                                    
// 
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
	
int test_usage_show_configurations()
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
	
	printf("self-test: \n");

    int ON_OFF = ON;

    int status = check_mode_set (ON_OFF);
    printf("FLAG_GLOBAL is: %s. \n", FLAG_GLOBAL?"ON":"OFF");

	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_timer(){
	INFO(">> ");
	
	unsigned int seconds_to_sleep = 3;
		
	clock_t begin, end;
	double time_spent;

	begin = clock();

	int result = 0;
	// sleep(seconds_to_sleep);	/* operation to be timed */
	for (int i = 0; i < 10000; i++){
		for (int j = 0; j < 10000; j++){
			result = i + j;
		}
	}

	end = clock();
	time_spent = (double)(end - begin) * 1000.0 / CLOCKS_PER_SEC;
	
	printf("Time taken: %50.100f ms\n", time_spent);
	printf("\nTime elapsed: %.2f\n",1.0*(end-begin)/CLOCKS_PER_SEC);

    time_t timer;
    char buffer[25];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    //strftime(buffer, 25, "%Y:%m:%d  %H:%M:%S", tm_info);
    strftime(buffer, 25, "%Y-%m.%d_%H%Mhr", tm_info);
    puts(buffer);
    
	printf("Now: %s\n", buffer);  

	printf("%s\n", DEMARCATOR_STRING);
}
