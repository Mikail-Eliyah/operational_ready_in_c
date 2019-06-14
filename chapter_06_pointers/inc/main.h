#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h> 
#include <stdbool.h>

/*
==================================================
============= || DEFINE CONSTANTS || =============
==================================================
*/
#define TRUE 1
#define FALSE 0

#define PI 3.14159265
#define DEMARCATOR_STRING "==========================================================="

#define INFO(msg) \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING); \
    fprintf(stderr, "[info]:\n<file>: %s \n<function>:%s \n<line>: %d\n", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(stderr, "%s\n", msg); \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING);
	
#define ANNOUNCE_FUNCTION_CALLED() \
	fprintf(stderr, "[invoke]:\n<file>: %s \n<function>:%s \n<line>: %d\n", __FILE__, __FUNCTION__, __LINE__); \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING);
	
/*
==================================================
=============== || DEFINE TYPES || ===============
==================================================
*/
  typedef unsigned int uint32;
  typedef unsigned intsize_t;


/*
==================================================
============= || USAGE FUNCTIONS || ==============
==================================================
*/
int test_usage_reading_addresses(void);
int test_usage_passing_pointer_as_argument(void);
int test_usage_pointer_trials(void);
int test_usage_check_if_agnostic_function_is_designated(void);
int test_usage_write_data_to_specific_memory_regions(void);
int test_usage_choosing_function_at_runtime(void);
/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
// Passing pointer argument and allocating/ freeing memory space
void putString (char** returnStringBuffer, char* inputStr);

//Determining whether Agnostic function is Designated or not
static void (*agnosticFunction)(int mode, int type,const char *file,int line) = 0; // set this agnostic function to point to nothing or base 0 (should be interpretated as NULL address instead)


void designatedFunction(int mode, int type, const char *file, int line);


