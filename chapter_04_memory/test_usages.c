#include "main.h"

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
// global variables
#define DATA_SIZE 20

int display_N_values_per_line = 5;


int test_usage_check_if_within_memory_bounds()
{ 
	INFO(">> ");
	
	int i = 0xdeed;
	
	unsigned long addr = (unsigned long) &i;
	unsigned long size = 0xffff; // 0x10; 
	unsigned long start = 0;
	unsigned long end = 0xffffcbc8; // 0xF8FF3C; // 0x100 = 256 bytes from offset 0

	int isWithinMemoryRange = withinMemoryRangeCheck(addr, size, start, end);

	if (isWithinMemoryRange)
        printf("isWithinMemoryRange, top of stack starts at %p\n", &i);
	else
        printf("isNotWithinMemoryRange, top of stack starts at %p\n", &i);
        
/*
# define start_confines 0x....
# define end_confines 0x....

        withinMemoryRangeCheck((void*)addr, sizeof(structstuctItem), start_confines, end_confines));
*/

	
	printf("%s\n", DEMARCATOR_STRING);
}
	
int test_usage_work_area()
{ 
	INFO(">> ");
	
	int i, data_int[DATA_SIZE];
	char data_char[DATA_SIZE];

	int dataIntToInitiateTo = 0;
	char dataCharToInitiateTo = 'x';

	memset(data_int, dataIntToInitiateTo, sizeof(data_int)); // can be used for clearing: zeroing out array  
	memset(data_char, dataCharToInitiateTo, sizeof(data_char));  
 
	// Print out array
	for (int i=0; i<DATA_SIZE; i++) { 
		fprintf(stdout, "data[%u]: %u\t",i,data_int[i]);
		
		if ((i+1) % display_N_values_per_line == 0){
			printf("\n");
		}
    }
	printf("\n");

    fprintf(stdout, "data_char: %s\n", &data_char); 

	// For clearing string
	char data_str[]="The wheels on the bus go round and round.";
memset(data_str,'*',10);
 
	fprintf(stdout,"%s\n",data_str); // output: ********** on the bus go round and round.

	// To clear or zero out a C structure (a structure is simply variables)
	// set in a line in memory (usually byte aligned):
	typedef struct     {
		int number;
		char *name;
		char *address;
		char *birthdate;
		char gender;
	} myData;

	
	myData item; // struct
	memset(&item, 0xea, sizeof(item));// clear myData structure
	
	printf("struct size: %d\n", sizeof(item));
	
	// Use sizeof macro to ensure you have covered the correct size of memory when using memset.
	print_memory_contents((unsigned char *) &item, sizeof(item), display_N_values_per_line, "struct item: \n");
    
	printf("%s\n", DEMARCATOR_STRING);
	
	char str1[15], str2[15];
	int ret;

	memcpy(str1,"abcdefgh", strlen("abcdefgh"));
	memcpy(str2,"ABCDEFGh", strlen("ABCDEFGh")); // abcdefgh
	
	printf("%d\n", strlen("abcdef"));

	ret = memcmp(str1, str2, 5);

	if(ret > 0){
		printf("str1 is < str2\n");
	} else if(ret < 0){
		printf("str2 is > str1\n");
	} else{
		printf("str1 is == str2\n");
	}
	
	const char dest[] = "abcdefghi";
	const char src[]  = "123456789";

	printf("Before memmovedest = %s, src = %s\n", dest, src);
	memmove((void *) dest, (void *) src, 2);
	printf("After memmovedest = %s, src = %s\n", dest, src);
   
/*
Before memmovedest = abcdefghi, src = 123456789
After memmovedest = 12cdefghi, src = 123456789
*/   

	printf("%s\n", DEMARCATOR_STRING);
	
	// int i;
    int a[] = {0x1, 0x2, 0x3};
    int factor = 2;
    int b[(sizeof(a)/sizeof(int))*2];

    for (i = (sizeof(a)/sizeof(int)-1); i >= 0;i--) { // -1 for indexing
        printf("0x%x ", a[i]);
    } printf("\n");

    changeContents (a, (sizeof(a)/sizeof(int)), 0x5, b, (sizeof(b)/sizeof(int)));

    for (i = (sizeof(a)/sizeof(int)-1); i >= 0;i--) { // -1 for indexing
        printf("0x%x ", a[i]);
    } printf("\n");


    for (i = (sizeof(b)/sizeof(int)-1); i >= 0;i--) { // -1 for indexing
        printf("0x%x ", b[i]);
    } printf("\n");

	printf("%s\n", DEMARCATOR_STRING);
}

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
int test_usage_of_memcpy()
{ 
	INFO(">> ");
	
	unsigned int len = 35; // number of bytes
	unsigned char *src = (unsigned char *)malloc(len*sizeof(unsigned char));
	unsigned char *dest = (unsigned char *)malloc(len*sizeof(unsigned char));

	printf("%d bytes \n", len);

	// assign values
    printf("\n\nAssign values to src:\n");

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
