#include "main.h"

// #define Newbase 0x03419088
#define Newbase 0x600000410 // address

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_write_a_byte_to_register_with_specific_memory_address ()
{ 
	INFO(">> ");
	
    int  *base;
    int i, j;
    int cnt = 3;
    int sum = 0;
    int extensionForMoreMemory = 10;

    base = (int *)malloc(cnt * sizeof(int));
    printf("Base of allocation is %u \n",base);

    if(!base)
        printf("unable to allocate size \n");
    else {
      for(j = 0;j <cnt; j++)
          *(base+j)=5;
    }
    for(j = 0;j <cnt; j++)
      sum = sum + *(base+j);

    printf("total sum is %d\n",sum);
    free(base);

    printf("Base of allocation after freeing memory is %u \n",base);

    base = (int *)malloc(cnt * sizeof(int)*extensionForMoreMemory);
    printf("Base of re-allocation of an extended size is %u \n",base);
    free(base);

    base = (int *)calloc(10,2);
    printf("Base of re-allocation of the previous size is %u \n",base);
    //free(base); // if not commented, some processes may take this memory address immediately after being freed
    
	// write a byte to register with specific memory address
	char your_8_bit_value = 0x42;
	unsigned int volatile * const mem_map_register = (unsigned int volatile *) base; // point to the memory address, eg. base = 0x03419088
	*mem_map_register = (*mem_map_register& 0xFFFFFF00) | your_8_bit_value;

	printf ("Address: %u \n", mem_map_register);
	printf ("Content: %x \n", *mem_map_register);
	
	//printf("base address: %p\n", base);
	
	long your_8_bit_value_00 = 0x600000410;
	
	// write a byte to register with specific memory address
	(*((volatile unsigned int*)(mem_map_register)) = ((*mem_map_register& 0xFFFFFF00) | your_8_bit_value_00)); 
	// or
	(*((volatile unsigned int*)(Newbase)) = your_8_bit_value_00);

	printf ("Address: %u \n", Newbase);
	// printf ("Content: %x \n", *Newbase);
	printf ("Content: %p \n", Newbase);
	
	printf("%s\n", DEMARCATOR_STRING);
}	


int test_usage_memset_different_from_cpy_due_to_null_byte ()
{ 
	INFO(">> ");
	
	// memset/ cpy behaves differently for bytes and str char due to '\0' (null char)

	char str[50];
   char strToCopy[17];
   int numberOfBytesToFill = 7; // fills 1st n bytes of the memory area pointed to
   char charToFillInAs = '*'; //48: ascii for '0' // '$';
   void* targetStartAddress = str;
   //strncpy(strToCopy, "tOsEe The wOrLd", strlen("tOsEe The wOrLd")+1); // +1 copy null char, else there will be no termination
// strncpy won't write the null terminator if the string is truncated so you'd need to add it yourself
	strncpy(strToCopy, "tOsEe The wOrLd", sizeof(strToCopy));
   strToCopy[sizeof(strToCopy)-1] = '\0';  //null terminate in case of truncation.
   puts(strToCopy); // print
   
   strcpy(str, "Test statement !@#$%^&*()=+_~```::||{}[]");
   puts(str); // print

   memset(targetStartAddress, charToFillInAs, numberOfBytesToFill); //  fill memory with a constant byte (ie. charToFillInAs)
   puts(str); // print
   
   memcpy(targetStartAddress, strToCopy, strlen(strToCopy)+1); // +1 for null char   
   puts(str); // print ()
   
/*
tOsEe The wOrLd
Test statement !@#$%^&*()=+_~```::||{}[]
*******atement !@#$%^&*()=+_~```::||{}[]
tOsEe The wOrLd // puts terminated by '\0'
tOsEe The wOrLd@#$%^&*()=+_~```::||{}[] // memcpy(targetStartAddress, strToCopy, strlen(strToCopy)); // +1 ommitted for null char   

*/  
	
	printf("%s\n", DEMARCATOR_STRING);
}	