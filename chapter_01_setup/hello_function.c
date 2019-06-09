#include "hello_main.h"

#define BUFFER_SIZE 12

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/

void check_address_and_value_of_pointer(int *ptr, char *description_string)
{
	printf("%s\n", DEMARCATOR_STRING);
	printf("%s : Pointer address is %x.\n", description_string, ptr);	
	printf("%s : Pointer value is %d.\n", description_string, *ptr);
	printf("%s : Pointer value (in hex) is 0x%x.\n", description_string, *ptr);
	printf("%s\n", DEMARCATOR_STRING);
}

void check_address_and_value_of_long_pointer(long long *ptr, char *description_string)
{
	printf("%s\n", DEMARCATOR_STRING);
	printf("%s : Pointer address is %x.\n", description_string, ptr);	
	printf("%s : Pointer value is %d.\n", description_string, *ptr);
	printf("%s : Pointer value (in hex) is 0x%lx.\n", description_string, *ptr);
	printf("%s\n", DEMARCATOR_STRING);
}

void check_address_and_value_of_address(int target, char *description_string)
{
	printf("%s\n", DEMARCATOR_STRING);
	printf("%s : Target address is %x.\n", description_string, &target);	
	printf("%s : Target value is %d.\n", description_string, target);
	printf("%s\n", DEMARCATOR_STRING);
}

void swap_values_using_pointers_by_passing_addresses(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 



/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
int test_usage_memory_reassignment()
{ 
    int x;            /* A normal integer*/
    int *p;           /* A pointer to an integer ("*p" is an integer, so p
                       must be a pointer to an integer) */
			
    int target = 10;		
	int target_2 = 42;
	long long y = 0x1122334455667788;
	int *ptr; // int* ptr;
	void *ptr_agnostic;
	long long *ptr_long_type;
	
	check_address_and_value_of_address(target, "[Before reassignment]: ");
	check_address_and_value_of_pointer(ptr, "[Before reassignment]: ");
	
	ptr = &target;
	check_address_and_value_of_pointer(ptr, "[After reassignment]: ");
	
	ptr = &target_2;	
	check_address_and_value_of_pointer(ptr, "[After reassignment]: ");
	
	target_2 = *ptr;
	check_address_and_value_of_address(target_2, "[After reassignment]: ");
	 
	printf("sizeof(*ptr_agnostic): %d,\n", sizeof(*ptr_agnostic)); 
	printf("sizeof(ptr_agnostic): %d,\n", sizeof(ptr_agnostic)); 
	printf("sizeof(*ptr): %d,\n", sizeof(*ptr));	
	printf("sizeof(ptr): %d (this is different from sizeof(*ptr) because ...),\n", sizeof(ptr));
	printf("sizeof(y): %d,\n", sizeof(y));	
	
	ptr = (int*) &y;
	printf("[After reassignment] Pointer address is %x,\n", ptr);	
	printf("[After reassignment] Pointer value is 0x%lx (truncated ...), \n", *ptr);		
	ptr_agnostic = &y;
	// printf("[After reassignment] Pointer value is %lx, \n", (long long) *ptr_agnostic);
	check_address_and_value_of_long_pointer(ptr_agnostic, "[After reassignment]: ");
	
	ptr_long_type = &y;
	check_address_and_value_of_long_pointer(ptr_long_type, "[After reassignment]: ");
	
				   
	printf("size of integer is %d.\n", sizeof(int));
	printf("size of integer* is %d.\n", sizeof(int*));
		
	int x0, y0; 
    printf("Enter Value of x0 "); 
    scanf("%d", &x0); 
    printf("\nEnter Value of y0 "); 
    scanf("%d", &y0); 
    swap_values_using_pointers_by_passing_addresses(&x0, &y0); 
    printf("\nAfter Swapping: x0 = %d, y0 = %d\n", x0, y0); 
	swap_values_using_pointers_by_passing_addresses(&x0, &y0);
	printf("\nAfter Swapping again: x0 = %d, y0 = %d\n", x0, y0); 
		
}

/*

// UTER-CONSTRUCTION
void determine_R1_and_R2_radii_for_cone_cup(void) {
	
	printf("Hello makefiles!\n"); 

  return;
}

*/