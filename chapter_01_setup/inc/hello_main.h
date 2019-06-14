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
	

/*
==================================================
============= || USAGE FUNCTIONS || ==============
==================================================
*/
// void myPrintHelloMake(void);
int test_usage_X(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/	
void lib_call(char* description);