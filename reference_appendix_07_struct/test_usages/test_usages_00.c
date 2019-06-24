#include "main.h"

// global variables
#define LEN 10

int display_N_values_per_line = 8;


/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
void display_memory_contents_of_response_struct(response_struct *response_struct_ptr){
	for (int i=0; i < LEN; i++) {
        printf(" %x",  ((uint8_t*) response_struct_ptr->dataAddress)[i]);
    }
	printf("\n");
}

// put the array into the array within the struct starting from index 0
void fillValuesIntoArrayWithinStruct (struct item* obj, int numberOfElements, int* decValue[]) { // pass struct by reference
     int i = 0;
                
     for(i = 0; i < numberOfElements; i++)
           obj->decValue[i] = decValue[i];
}

// convert hexdecimal string to int array (hexadecimal values) and placed in allocated buffer starting from the buffer index 0
void hexStringToHexBytesArray (char* hexStringBytes, int* decValue[]) {
     char* hexByteInStr = "";
     //char byteInStr[3] = ""; // XX\0
     char byteInStr[5] = "0x"; // 0xXX\0 
     int numberOfBytes = (strlen(hexStringBytes)/2);
     int i = 0;
                
        for(i = 0; i < numberOfBytes; i++){
              strncat(byteInStr, &hexStringBytes[(i*2)], 1);       // insert the 1st hex character
              strncat(byteInStr, &hexStringBytes[(i*2)+1], 1);  // insert the 2nd hex character
              byteInStr[5] = '\0';
              decValue[i] = (int)strtol(byteInStr, NULL, 0);   // without "0x" header, last paramater is 16
              //printf("STR>>> %s \n", byteInStr); 
              //printf("HEX>>> %x \n", decValue[i]); 
              strcpy(byteInStr, "0x");
         }                 
}


/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
int test_usage_struct_00()
{
	INFO(">> ");

	// Getting array contents after passing to struct address
    int i = 0;
    uint8_t *msg = NULL;
    msg = malloc(sizeof(uint8_t)*LEN);

    printf("Init: \n");
    for (i=0; i<LEN; i++) {
        msg[i] = i;
        printf("%d ", msg[i]);
    }

    printf("\n");
    printf("Address: 0x%x \n", msg);
    printf("Address: 0x%x \n", (uint32_t) msg);

    response_struct *response_struct_ptr;
	response_struct_ptr = malloc(sizeof(response_struct));
	
	if (response_struct_ptr == NULL)
		printf("malloc fail: response_struct_ptr \n" );	
	else
		printf("malloc'ed %d bytes: response_struct_ptr \n", sizeof(response_struct));	
	
    //(response_struct_ptr->dataAddress) = (uint32_t) msg;
	//(response_struct_ptr->dataAddress) = msg;
	
	/*
	for (i=0; i < LEN; i++){  // message fixed at length 10
        printf("= Address: 0x%x \n",  ((uint8_t*) response_struct_ptr->dataAddress++)); // 
	}

		
	int address = 0;
    for (i=0; i < LEN; i++){  
		address = ((uint8_t*) response_struct_ptr->dataAddress++);
        printf("content: %d \n", (uint8_t) &address);
	}

    printf("\n");
		*/
	/*
	*/

	// Getting array contents after passing to struct address to call function
	
	for (i=0; i < LEN; i++)  // message fixed at length 10
        printf(" %x",  ((uint8_t*) response_struct_ptr->dataAddress)[i]);

    printf("\n");

    assign_value_to_memory_address_given (msg, response_struct_ptr);	

	display_memory_contents_of_response_struct(response_struct_ptr);
	
	free (response_struct_ptr);
	free(msg);
	
	printf("%s\n", DEMARCATOR_STRING);
}


int test_usage_struct_01()
{
	INFO(">> ");
	
	// target hexadecimal values to be inserted
	char* hexStringBytes = "11223344556677";

	int* decValue[BUF_SIZE] = {
		0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 
		0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a
	};

	struct item first;
	
	int numberOfBytes = BUF_SIZE;
    hexStringToHexBytesArray (hexStringBytes, decValue);

       int i=0;
       for(i = 0; i < numberOfBytes; i++){
			if ((i+1) % display_N_values_per_line != 0)
				printf("%x ", decValue[i]); 
			else
				printf("\n");
       } printf("\n");

       // load data onto array within struct
       fillValuesIntoArrayWithinStruct (&first, numberOfBytes, decValue);
       
	   printf("Data of array within the struct:\n");
       for(i = 0; i < numberOfBytes; i++){             
			if ((i+1) % display_N_values_per_line != 0)
				printf("%x ", first.decValue[i]); 
			else
				printf("\n");
       } printf("\n");

       for(i = 0; i < numberOfBytes; i++){
             printf("HEX>>> %x \n", decValue[i]); 
       } 


	
	printf("%s\n", DEMARCATOR_STRING);
}	
