#include "main.h"

// global variables
#define ARGUMENT_KEY_POSITION 2

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/


int test_usage_check_options(int argc, char *argv[]){
	INFO(">> ");
	
  int count;

  printf ("This program was called with \"%s\".\n",argv[0]);

  if (argc > 1)
    {
      for (count = 1; count < argc; count++)
	{
	  printf("argv[%d] = %s\n", count, argv[count]);
	}
    }
  else
    {
      printf("The command had no other arguments.\n");
    }
	
		printf("%s \n", argv[2]);
		printf("%d \n", strlen(argv[2]));
		
	 if ((strlen(argv[2])%2) != 0) {
        printf("<< string data is NOT even >> \n");
        // system("PAUSE"); // for debugging check
        exit(-1);
     }
     
     // account for the data string length
     int dataBytesLength = 0;
     dataBytesLength = atoi(argv[1]); // [TODO] check for valid inputs (numeric)
	 
	 printf("dataBytesLength: %d \n", dataBytesLength);
     
     if (dataBytesLength != (strlen(argv[2])/2)) { // (strlen(argv[2])/2): divide by 2: number of bytes 
        printf("<< Declared string data length is NOT correct >> %d \n", (strlen(argv[2])/2));
        // system("PAUSE"); // for debugging check
        exit(-1);
     }     
     
    // load the string data from argv[6], and allocate space for stringBytes to be loaded upon
     char* stringBytes = (char*) malloc((strlen(argv[2])+ 1)*(sizeof(char))); // add 1 (sizeof(char) for '\0'
     memcpy(stringBytes, argv[2], strlen(argv[2])+1);      
          
     printf("<< Loaded string data >> : %s.\n\n", stringBytes);
	 
	 // getting parameters
    char* str;
	int length_allocated = strlen(argv[ARGUMENT_KEY_POSITION]) + 1;
	
    str =     (char*) malloc(length_allocated*(sizeof(char))); // add 1 (sizeof(char) for '\0'
    memcpy(str, argv[ARGUMENT_KEY_POSITION], length_allocated); 

	printf("key: %s\n", str);
	printf("memory bytes allocated: %d\n", length_allocated);

	printf("%s\n", DEMARCATOR_STRING);
}
