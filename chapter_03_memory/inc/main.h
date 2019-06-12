#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h> 

/*
==================================================
============= || DEFINE CONSTANTS || =============
==================================================
*/
#define PI 3.14159265
#define DEMARCATOR_STRING "==========================================================="

#define INFO(msg) \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING); \
    fprintf(stderr, "[info]:\n<file>: %s \n<function>:%s \n<line>: %d\n", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(stderr, "%s\n", msg); \
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
int test_usage_check_on_malloc_success(void);
int test_usage_locating_stack_address(void);
int test_usage_of_memcpy(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
int print_memory_contents(unsigned char* start_of_location_memory, int length, int display_N_values_per_line, char* description);

int zerorize_memory_contents(unsigned char* start_of_location_memory, int length);

int fill_memory_contents_with_given_value (unsigned char* start_of_location_memory, int length, int given_value);