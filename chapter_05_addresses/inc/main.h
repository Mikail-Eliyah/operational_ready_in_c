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
int test_usage_memory_reassignment(void);
int test_usage_locating_stack_address(void);;
int test_usage_memory_bound(void);
int test_usage_reading_addresses(void);
int test_usage_check_distance_between_addressed_memory(void);
int test_usage_check_memory_address_assignment(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
int print_memory_contents(unsigned char* start_of_location_memory,int length, int display_N_values_per_line, char* description);

int zerorize_memory_contents(unsigned char* start_of_location_memory, int length);

int fill_memory_contents_with_given_value (unsigned char* start_of_location_memory, int length, int given_value);

void print_memory_location_of_malloc(void* memory_location, char* description);

void check_address_and_value_of_pointer(int *ptr, char *description_string);

void check_address_and_value_of_long_pointer(long long *ptr, char *description_string);

void check_address_and_value_of_address(int target, char *description_string);

const void *integritycheck_text_start(void);

const void *integritycheck_text_mid(void);

const void *integritycheck_text_end(void);
