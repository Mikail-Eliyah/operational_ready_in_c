#include "hello_main.h"

#define BUFFER_SIZE 12

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/

void lib_local_call(char* description) 
{ 
	INFO(description); 
	lib_call("calling from lib_local_call()");
} 

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
int test_usage_X()
{ 
    INFO(">> "); 
    
	lib_local_call("calling from test_usage_X()");
	lib_call("calling from test_usage_X()");
	
	printf("%s\n", DEMARCATOR_STRING);
		
}

/*

*/