#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h> 
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include <ctype.h>
#include <string.h>/* needed for strtok */ 
/*
==================================================
============= || DEFINE CONSTANTS || =============
==================================================
*/
#define TRUE 1
#define FALSE 0

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

#define openParenthsisChar  '('
#define closeParenthsisChar  ')'

	
/*
==================================================
=============== || DEFINE TYPES || ===============
==================================================
*/
  typedef unsigned int uint32;
  typedef unsigned intsize_t;
  
  int positionsRecorded[50]; // for delimiterChar

/*
==================================================
============= || USAGE FUNCTIONS || ==============
==================================================
*/
int test_usage_string_tokenizer(void);
int test_usage_string_encapsulation(void);
int test_usage_string_case(void);
int test_usage_string_position(void);
int test_usage_string_format(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
// Track Parentheses of a string
int count_Layers_Of_Parenthsis (char* targetStr, int strLength);

void convertToUpperCase(char *sPtr, int stringLength);

int findPositionsOfDelimiterCharacters (char* text, char* delimitChar);

void stringTokenizer (char targetString[], char delimiterChars[], char* frontToken, char* backToken);

void reverse_string(char *str);
void removeWhiteSpaces(char* source);
