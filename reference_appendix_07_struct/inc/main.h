#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <math.h>
#include <string.h>
#include <limits.h> 
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include <ctype.h>
#include <getopt.h>

/*
==================================================
============= || DEFINE CONSTANTS || =============
==================================================
*/
#define TRUE 1
#define FALSE 0

#define UP   "UP\0"
#define DOWN "DOWN\0"


// Set modes and status using directives to deviate options
// Tagging comments to dis/en-able code for different configuration
#define OFF 0
#define ON 1

// #define NULL ""
#define SAME 0

#define BUF_SIZE 16

#define OPERATION_STATUS ON 

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
	
#define LINE_NUMBER_OF_WHICH_CODE_FILE fprintf(stderr,"[LOG] %s:%d\n",__FILE__,__LINE__);
	
/*
==================================================
=============== || DEFINE TYPES || ===============
==================================================
*/
  typedef unsigned int uint32;
  // typedef unsigned int size_t;
  
/* The code may work for a 32-bit device but not 64-bits.
if you're on a 64-bit platform, because pointers just don't fit in 32 bits. Hence, remediation can be made to the code by changing the type from uint32_t to uint8_t. */
	typedef struct {
		//uint32_t dataAddress;
		uint8_t *dataAddress;
	} response_struct;

	struct item { 
		int*  decValue[BUF_SIZE];
	};


/*
==================================================
============= || USAGE FUNCTIONS || ==============
==================================================
*/
int test_usage_struct_00(void);
int test_usage_struct_01(void);
int test_usage_struct_02(void);
int test_usage_struct_03(void); 
int test_usage_struct_04(void);

int test_usage_fitting_1_struct_in_another_by_memcpy(void);
int test_usage_struct_extract_array_from_array_within_a_struct(void);
int test_usage_pass_a_struct_to_another_struct_within_a_struct(void);

int test_usage_struct_nested_hierarchical_composite_struct(void);
int test_usage_create_data_struct_for_big_numbers(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/

