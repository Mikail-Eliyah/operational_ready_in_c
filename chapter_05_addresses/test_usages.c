#include "main.h"

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
// global variables
#define DATA_SIZE 20

int display_N_values_per_line = 5;

void f(){
	printf("You called me ... \n");
	
}

int test_usage_reading_addresses()
{ 
	INFO(">> ");
	
	// example: reading itself
    long sizeOfExe = 0;    
    FILE *fp;
    
    fp = fopen("./run.exe", "rb"); // reading itself
    
    fseek(fp, 0L, SEEK_END);
    sizeOfExe = ftell(fp);
    
    printf("The size of this executable is: %ld bytes\n", sizeOfExe);    
    int* addressStartOfFile = (int*) &fp;
    printf("Location of this executable starts at: 0x%x\n", addressStartOfFile);         
    printf("Location of this executable ends at: 0x%x\n", (addressStartOfFile+sizeOfExe));
      
	/*
	The size of this executable is: 18727 bytes
	Location of this executable starts at: 0x28ff30
	Location of this executable ends at: 0x2a23cc
	*/

    // get the memory address of a function
    void f(); 
    void (*p_fun)() = & f;
	 
	p_fun();
	printf("Location of p_fun() starts at: 0x%x\n", p_fun);
	printf("Location of f() starts at: 0x%x\n", &f);
	
	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_memory_bound()
{ 
	INFO(">> ");
	
	int* memoryLocation = 0;
        
     memoryLocation = (int*) integritycheck_text_start();
     printf("memoryLocation [start]: %x \n", memoryLocation);
     memoryLocation = (int*) integritycheck_text_mid();
     printf("memoryLocation [mid]: %x \n", memoryLocation);
     memoryLocation = (int*) integritycheck_text_end();
     printf("memoryLocation [end]: %x \n", memoryLocation);    

	printf("%s\n", DEMARCATOR_STRING);
	
}


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
	check_address_and_value_of_pointer(ptr, "[After reassignment]: ");	
	printf("[After reassignment] Pointer value is 0x%lx (truncated ...), \n", *ptr);		
	ptr_agnostic = &y;
	// printf("[After reassignment] Pointer value is %lx, \n", (long long) *ptr_agnostic);
	check_address_and_value_of_long_pointer(ptr_agnostic, "[After reassignment]: ");
	
	ptr_long_type = &y;
	check_address_and_value_of_long_pointer(ptr_long_type, "[After reassignment]: ");
	
	printf("size of integer is %d.\n", sizeof(int));
	printf("size of integer* is %d.\n", sizeof(int*)); 
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

int test_usage_check_distance_between_addressed_memory()
{ 
	INFO(">> ");
	
     unsigned char text_start[] =
    { 0x65, 0x77, 0x05, 0x00,
      0xaa, 0x34, 0x5f, 0xdd, 0xf0, 0x0d, 0x11};     
     unsigned char *text_start_p = text_start;
     unsigned char text_end[] =
    { 0x65, 0x77, 0x05, 0x00,
      0xaa, 0x34, 0x5f, 0xdd, 0xf0, 0x0d, 0x11, 0x11};   
     unsigned char *text_end_p = text_end; 
     
     // dbg("%x, %x, %x, %x, %x, %x, %x\n", text_start[0], text_start[1], text_start[2], text_start[3], text_start[4], text_start[5], text_start[6]);
     // printf("%x, %x, %x, %x, %x, %x, %x, %x\n", text_start[0], text_start[1], text_start[2], text_start[3], text_start[4], text_start[5], text_start[6]);
     // printf("%x, %x, %x, %x, %x, %x, %x\n", text_start[0], text_start[1], text_start[2], text_start[3], text_start[4], text_start[5], text_start[6]);
     
     printf("location start: %x \n", text_start);
     printf("%x\n", *(text_end + 33));
     printf("%x\n", (text_end + 33));
     printf("location end: %x \n", text_end);     
     
     int distance = 0;
     // hunt for the direction
     if (text_start < text_end) {
        printf("incremental addressing\n");     
        
        while (text_start != (text_end-distance)) {
           distance++;
        }                
     } else {
        printf("decremental addressing\n");
        
        while (text_start != (text_end+distance)) {
           distance++;
        }                               
     }
     
     printf("They are %d bytes apart.\n", distance);       // They are 32 bytes apart.


	printf("%s\n", DEMARCATOR_STRING);
}

