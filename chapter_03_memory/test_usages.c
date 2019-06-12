#include "main.h"

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
// global variables


int test_usage_check_on_malloc_success_and_location()
{ 
	INFO(">> ");
	
    char s[] = "0123456789";
    // printf("%d\n", strlen(s));
    
    char* allocatedStrBuf = (char*) malloc( sizeof( char ) * ( strlen(s) + 1 ) ); // add 1 more to include the null char. Cast to (char*).
	
	if(check_malloc_success_status(allocatedStrBuf) == true)
	{
		printf("Malloc operation is OK.\n"); 
	} 
	
	int  *base;
    int i,j;
    int cnt = 3;
    int sum = 0;
    int extensionForMoreMemory = 10;

    base = (int *)malloc(cnt * sizeof(int));
	print_memory_location_of_malloc(base, "Base of allocation: "); // Location of the malloc

    if(!base)
        printf("Unable to allocate size \n");
    else {
      for(j = 0;j <cnt; j++)
          *(base+j)=5;
    }
	
    for(j = 0;j <cnt; j++)
      sum = sum + *(base+j);

    printf("total sum is %d\n",sum);
    free(base);

	print_memory_location_of_malloc(base, "Base of allocation after freeing memory: ");

    base = (int *)malloc(cnt * sizeof(int)*extensionForMoreMemory);
	print_memory_location_of_malloc(base, "Base of re-allocation of an extended size: ");
    free(base);

    base = (int *)calloc(10,2);
	print_memory_location_of_malloc(base, "Base of re-allocation of the previous size: ");
    free(base);
        
/*
Base of allocation is 7280392
total sum is 15
Base of allocation after freeing memory is 7280392
Base of re-allocation of an extended size is 7280520
Base of re-allocation of the previous size is 7280392
*/    
    
	printf("%s\n", DEMARCATOR_STRING);
}

/*

*/
int test_usage_locating_stack_address()
{ 
	INFO(">> ");
	
    int i;
	printf("The stack top is near %p\n", &i);
	printf("The next stack is %p\n", &i+1);

    int k;    
	printf("The stack for k is near %p\n", &k);
	printf("The next stack is %p\n", &k+1);

/* e.g.
The stack top is near 0028FF3C
The next stack is 0028FF40
The stack for k is near 0028FF38
The next stack is 0028FF3C

The stack top is near 0xffffcbec
The next stack is 0xffffcbf0
The stack for k is near 0xffffcbe8
The next stack is 0xffffcbec

*/    

	printf("%s\n", DEMARCATOR_STRING);
}


int test_usage_of_memcpy()
{ 
	INFO(">> ");
	
	unsigned int len = 35; // number of bytes
	unsigned char *src = (unsigned char *)malloc(len*sizeof(unsigned char));
	unsigned char *dest = (unsigned char *)malloc(len*sizeof(unsigned char));

	printf("%d bytes \n", len);

	// assign values
    printf("\n\nAssign values to src:\n");
	
	int display_N_values_per_line = 5;

	// assign values to memory regions
	for (int i=0;i<len;i++) {
		*(src+i) = (unsigned char) i+1; // 0x0 is skipped    
    }
	
	print_memory_contents(src, len, display_N_values_per_line, "\n\nAfter assigning values to src:\n");
	
	print_memory_contents(dest, len, display_N_values_per_line, "\n\nBefore zerorize_memory_contents on dest:\n");
	
	zerorize_memory_contents(dest, len);
	
	print_memory_contents(dest, len, display_N_values_per_line, "\n\nAfter zerorize_memory_contents on dest:\n");
	
	int given_value = (unsigned char) 0xea;
	fill_memory_contents_with_given_value (dest, len, given_value);
	
	print_memory_contents(dest, len, display_N_values_per_line, "\n\nAfter fill_memory_contents_with_given_value on dest:\n");
	
	
	printf("%s\n", DEMARCATOR_STRING);
	/*
	
	*/

	int offset = 10;
	int lengthToTransfer = 10;

	memcpy ( dest, src+offset, lengthToTransfer);
	memcpy ( dest+(2*offset), src, lengthToTransfer);

    print_memory_contents(dest, len, display_N_values_per_line, "\n\nAfter memcpy from src to dest:\n");

	free(src);
	free(dest);
	
	printf("%s\n", DEMARCATOR_STRING);
}
