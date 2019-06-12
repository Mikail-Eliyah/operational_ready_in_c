#include "main.h"

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
// global variables


int test_usage_check_on_malloc_success()
{ 
	INFO(">> ");
	
    char s[] = "0123456789";
    // printf("%d\n", strlen(s));
    
    char* allocatedStrBuf = (char*) malloc( sizeof( char ) * ( strlen(s) + 1 ) ); // add 1 more to include the null char. Cast to (char*).

    if(allocatedStrBuf == NULL ) {
         /* Malloc failed, deal with it */
         // According to the Single Unix Specification, malloc will return NULL and set errno when it fails.
         fprintf(stderr, "failed to allocate memory.\n");
         exit(-1);         
    } else {
        printf("Malloc operation is OK.\n"); 
    } 
    
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
