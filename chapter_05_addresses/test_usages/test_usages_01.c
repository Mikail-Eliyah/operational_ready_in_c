#include "main.h"

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/


int test_usage_check_memory_address_assignment(){
	INFO(">> ");
	// int *p=(int *)0x1234 = 10; //0x1234 is the memory address and value 10 is assigned in that address
	
	// the above statement is not legal for some compilers. You need to split in 2 instructions:

	int *p=(int *)0xffffcc80; // some machines do not allow addressing to specific memory, hence we check what memory is assigned to first
	*p = 10;
	// int *p;

	printf("value at %p is %d\n", p, *p);

	// unsigned int *ptr=(unsigned int *)0x903jf = 20;//0x903j is memory address and value 20 is assigned
	
	unsigned int *ptr=(unsigned int *)0xffffcce0;
	*ptr = 20;
	
	printf("value at %p is %d\n", ptr, *ptr);
	
	int* ptr_00 = (int *)0xffffcf80;
	int n = 55;
	ptr_00 = (int*)malloc(n * sizeof(int));
	// unsigned int *ptr_00=(unsigned int *)0xffffcde0;
	// ptr_00 = (*unsigned int) malloc(n * sizeof (unsigned int) );
	printf("value at %p is %d\n", ptr_00, *ptr_00);
	
	if (ptr_00 == NULL) { 
        printf("Memory not allocated.\n"); 
        exit(0); 
    } 
    else { 
  
        // Memory has been successfully allocated 
        printf("Memory successfully allocated using malloc.\n"); 
  
        // Get the elements of the array 
        for (int i = 0; i < n; ++i) { 
            ptr_00[i] = i + 1; 
        } 
  
        // Print the elements of the array 
        printf("The elements of the array are: "); 
        for (int i = 0; i < n; ++i) { 
            printf("%d, ", ptr_00[i]); 
        } 
    } 
	
	printf("%s\n", DEMARCATOR_STRING);
	for (int i = 0; i < n; ++i) { 
          printf("value at %p is %d\n", (ptr_00+i), *(ptr_00+i)); 
    } 
	
	
	printf("%s\n", DEMARCATOR_STRING);
}

