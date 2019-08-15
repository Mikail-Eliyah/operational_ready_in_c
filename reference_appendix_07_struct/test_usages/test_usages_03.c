#include "main.h"

// global variables

#define ASSIGNED_ADDRESS 0xffccffee // 0x00000049

/*
==================================================
============= || LOCAL STRUCTS || ==============
==================================================
*/
#define MAX_BUFFER_SIZE 1
/*
@addressVirtual   : address pointer of buffer
@offsetMemory     : offset from base address of buffer
@length           : buffer size    

This requires malloc for memory allocation 1st, and ensure that the memory is allocated properly.          
*/
struct bufferMemoryProfile {
  union {
        int *addressVirtual;
        int offsetMemory;
  };
  int length;
}; // 8 bytes, 12 if all memory buffer fields are used

struct bufferUsage {
  struct bufferMemoryProfile sourceBuffer[MAX_BUFFER_SIZE]; // struct keyword unused if typedef
  struct bufferMemoryProfile destinationBuffer[MAX_BUFFER_SIZE];
}; // 




/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
void allocationStructObject (struct bufferUsage** bufferItem) {
    struct bufferUsage *bufferConstruct;
    bufferConstruct = malloc(sizeof(struct bufferUsage));

    if (bufferConstruct == NULL) {             // check if malloc is successful
       printf("Memory allocation for bufferUsage fails.\n");
       // exit(-1);
    }  
  
   *bufferItem = bufferConstruct;  // Buffer allocated pointer to out-parameter.
}

void free_memory(struct bufferUsage** bufferItem){
	
	// free(*bufferItem);
	
	struct bufferUsage* bufferItem_00 = malloc(sizeof(*bufferItem));
	struct bufferUsage* const original = bufferItem;
	
	if(bufferItem == original){
		free(bufferItem_00);
		printf("freeing memory Done\n");
		free(*bufferItem);
	} else {
		printf("freeing memory failed\n");
	}

}

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
// Struct Array with using #define for a setting function
int test_usage_struct_nested_hierarchical_composite_struct()
{
	INFO(">> ");

	struct bufferUsage bufferItem;

	allocationStructObject (&bufferItem);
	printf("StructbufferItem base address: %p\n", bufferItem.destinationBuffer[0].addressVirtual); // StructbufferItem base address: 00000041
	bufferItem.destinationBuffer[0].addressVirtual++;
	printf("StructbufferItem base address: %p\n", bufferItem.destinationBuffer[0].addressVirtual); // StructbufferItem base address: 00000045
	bufferItem.destinationBuffer[0].addressVirtual = (int *) ASSIGNED_ADDRESS;
	printf("StructbufferItem base address: %p\n", bufferItem.destinationBuffer[0].addressVirtual); 
	bufferItem.destinationBuffer[0].length = 1;
	bufferItem.destinationBuffer[0].offsetMemory = 50;
	printf("StructbufferItem size: %d\n", sizeof(bufferItem));// StructbufferItem size: 
	// free(&bufferItem); 
	free_memory(&bufferItem);	
	
	printf("%s\n", DEMARCATOR_STRING);
}	
