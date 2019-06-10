#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
	
#define BUFFER_SIZE 32

/*
==================================================
============= || USAGE FUNCTIONS || ==============
==================================================
*/
// void myPrintHelloMake(void);
int test_usage_insert_bits_as_substring_and_display_binary_string(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
int updateBits(int targetBinary, int binaryToInsert, int positionStartToInsert, int positionEndToInsert);

char* binrep (unsigned int val, char *buff, int sz);

