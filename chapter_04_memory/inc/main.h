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
int test_usage_check_on_malloc_success_and_location(void);
int test_usage_of_memcpy(void);
int test_usage_work_area(void);
int test_usage_check_if_within_memory_bounds(void);
int test_usage_check_memory_assignment(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
bool check_malloc_success_status(char* memory_location_start);

int print_memory_contents(unsigned char* start_of_location_memory, int length, int display_N_values_per_line, char* description);

int zerorize_memory_contents(unsigned char* start_of_location_memory, int length);

int fill_memory_contents_with_given_value (unsigned char* start_of_location_memory, int length, int given_value);

void print_memory_location_of_malloc(void* memory_location, char* description);

void changeContents (int* a, int sizeOfA, int increment, int *b, int sizeOfB);

int withinMemoryRangeCheck(unsigned long addr, unsigned long size, unsigned long start, unsigned long end);