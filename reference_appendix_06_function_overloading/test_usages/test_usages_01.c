#include "main.h"

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
void return_using_pointers(int value_00, int value_01, int* address_to_return_00, int* address_to_return_01) 
{ 
        *address_to_return_00 = value_00; 
        *address_to_return_01 = value_01;  
} 

struct struct_values { 
    int value_00, value_01; 
}; 
  
typedef struct struct_values Struct_with_2_values; 
  
Struct_with_2_values return_using_struct(int a, int b) 
{ 
    Struct_with_2_values s; 
 
        s.value_00 = a; 
        s.value_01 = b; 
  
    return s; 
} 

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
/* */
int test_usage_return_mutiple_values()
{
	INFO(">> ");
	
	int obtain_00, obtain_01, x = 101, y = 202; 
    
    return_using_pointers(x, y, &obtain_00, &obtain_01); 
    printf("obtain_00: %d and obtain_01: %d\n", obtain_00, obtain_01); 
	
	printf("%s\n", DEMARCATOR_STRING);
	
	Struct_with_2_values result; 
	
	result = return_using_struct(x, y); 
    printf("value_00: %d and value_01: %d\n", result.value_00, result.value_01); 
	

	printf("%s\n", DEMARCATOR_STRING);
}