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

int test_usage_passing_pointer_as_argument() 
{ 
	INFO(">> ");
	
    char* returnStringBuffer;
    char* inputStr = "112233445566aa112233445566aa112233445566aa112233445566aa";

    putString (&returnStringBuffer, inputStr);
    printf("%s\n", returnStringBuffer);

    free(returnStringBuffer);        // free malloc'd memory
	
	printf("%s\n", DEMARCATOR_STRING);
}

/*

*/

int test_usage_pointer_trials() 
{ 
	INFO(">> ");
	
    // create 2 arrays 
    int ages[] = {23, 43, 12, 89, 2, 5, 9};
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa",
        "French", "Tom"
    };

    //int count = sizeof(ages) / sizeof(int);      // number of element in array
    int count = sizeof(names) / sizeof(char*);      // number of element in array
    int i = 0;

    // [1] using indexing
    for(i = 0; i < count; i++) {
        printf("%s has %d years.\n",
                names[i], ages[i]);
    }

    printf("---\n");

    // setup the pointers to the start of the arrays
    int *ptr_age = ages;
    char **ptr_name = names;

    // [2] using pointers
    for(i = 0; i < count; i++) {
        printf("%s is %d years old.\n",
                *(ptr_name+i), *(ptr_age+i));
    }

    printf("---\n");

    // [3] pointers are just arrays
    for(i = 0; i < count; i++) {
        printf("%s is %d years old again.\n",
                ptr_name[i], ptr_age[i]);
    }

    printf("---\n");

    // [4] pointers in a stupid complex way
    for(ptr_name = names, ptr_age = ages;
            (ptr_age - ages) < count;
            ptr_name++, ptr_age++) {
        printf("%s lived %d years so far.\n",
                *ptr_name, *ptr_age);
    } 
	
	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_check_if_agnostic_function_is_designated(){
	INFO(">> ");
	
	int mode = 5;
	int type = 7;
	const char *file;
	int line = 100;

      printf("contents : %p\n", agnosticFunction);
      printf("address : 0x%x\n", &agnosticFunction);  
      
      agnosticFunction = designatedFunction; // comment this out, and the agnostic function will not be activated
      
      
    if (agnosticFunction) {                  // if the address is not pointed to NULL or base 0
       printf("Mode in operation.\n");
       agnosticFunction(mode, type, file, line);
    }

      printf("contents : %p\n", agnosticFunction);
      printf("address : 0x%x\n", &agnosticFunction);    


	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_write_data_to_specific_memory_regions() 
{ 
	INFO(">> ");
	
	int target = 42;
	
	// pointing to specific memory regions, and writing data to them
	int *my_pointer, *my;
	
	int my_variable = 10, other_variable = 20;

	printf("the address of my_variable is    : %p\n", &my_variable);
	printf("the address of other_variable is : %p\n", &other_variable);

	// my_pointer = (int *)(0x28FF48);
	my_pointer = &target;
	// my = (int *)(0x28FF4C);
	my = &target;
	
	printf("\nafter \"my_pointer = &my_variable\":\n");
	printf("\tthe value of my_pointer is %p\n", my_pointer);
	
	printf("\tthe value at that address is %d\n", *my_pointer);


	my_variable = my_pointer;
	my_pointer = my;
	my = my_variable;
	// temp = *my;

	// my =  (int*) 0x405A00; /* point to x : 0x402000*/
	my = &target;
	*my = 100;
	printf("\tthe value of target is %d\n", target);
	printf("\tthe robin value of x is %d\n", *my);
	printf("\tthe address of x is %x\n", my);

	printf("%s\n", DEMARCATOR_STRING);
}
