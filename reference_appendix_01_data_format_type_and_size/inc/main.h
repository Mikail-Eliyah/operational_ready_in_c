#include <stdio.h>
#include <stdlib.h>
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

#define NULL ""     // use NULL as a delimiter
#define SAME 0


#define lengthOfArray(x)  (sizeof(x) / sizeof(x[0]))


// Set modes and status using directives to deviate options
// Tagging comments to dis/en-able code for different configuration
#define OFF 0
#define ON 1

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
  typedef unsigned intsize_t;

/*
==================================================
============= || USAGE FUNCTIONS || ==============
==================================================
*/
int test_usage_check_data_format(void);
int test_usage_get_integer_and_decimal_part_of_given_value(void);
int test_usage_unique_symbols_aka_histogram(void);
int test_usage_set_data_by_passing_addresses(void);
int test_usage_display_data_00(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
int findPositionOfChar (char* targetStr, int lengthOfStr, char charToTrack);
// mantissa is assumed to exist.
void getIntegerAndDecimalValues (char* n, int strlen_n, char intPart[], char decPart[]);
void nonHexCharDetector (char* strTarget, int strTargetLength);
void ASCII_CharsHistogram (char* strTarget, int strTargetLength, int asciiHistogramCount[]);
void displayASCII_CharsHistogram (int asciiHistogramCount[]);

void int_set_right(int* y, int valueToSet);
void array_set(int* y_dest, int* y_src, int arrayLength);

int safeCopy(char *from, int from_len, char *to, int to_len);

// static 
void print_text(char *intro_message, unsigned char *text_addr, unsigned int size);


