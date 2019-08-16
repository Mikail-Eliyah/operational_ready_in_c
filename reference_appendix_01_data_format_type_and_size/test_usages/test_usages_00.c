#include "main.h"

// global variables
#define ARGUMENT_KEY_POSITION 2
#define BUF_SIZE 16

int display_N_values_per_line = 20;

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

int test_usage_set_data_by_passing_addresses(){
	INFO(">> ");

	// 6bc1bee22e409f96e93d7e117393172a
	int* decValue[BUF_SIZE] = {
		0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 
		0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a
	};

	int* decValue2[BUF_SIZE] = {
		0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 
		0x99, 0x00, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff
	};
	
	int y_int = 0;
    int y_array[BUF_SIZE];

    int_set_right( &y_int, 9876543);
    array_set(y_array, decValue2, BUF_SIZE);
    
    printf("lengthOfArray: %d \n", lengthOfArray(y_array));  

    printf("Value int :: %d \n",y_int);
         int i = 0;
     for (i=0;i<BUF_SIZE; i++) 
         printf("%x ", (0xff & y_array[i]));    
	printf(" // values set in array \n");
	
	char* stringSource = "tHis Is a TesT string!!!";
    char* stringDestination;
    
    stringDestination = (char*) malloc((strlen(stringSource)+ 1)*(sizeof(char))); // add 1 (sizeof(char) for '\0'

    safeCopy(stringSource, strlen(stringSource), stringDestination, strlen(stringSource));
        printf("%s\n", stringDestination);  // tHis Is a TesT string!!!


	
	printf("%s\n", DEMARCATOR_STRING);
}	


int test_usage_unique_symbols_aka_histogram(){
	INFO(">> ");
	
	 char targetString[] = "WHY is everyone is quiet?????? One day gone, 1 day lost ....";
	int asciiHistogramCount[256];
 
	printf ("target string: %s\n", targetString);
	ASCII_CharsHistogram (targetString, (int)strlen(targetString), asciiHistogramCount);
	displayASCII_CharsHistogram (asciiHistogramCount);

	
	printf("%s\n", DEMARCATOR_STRING);
}	

int test_usage_get_integer_and_decimal_part_of_given_value(){
	INFO(">> ");
	
	// char floatString[] = ".72";  
	char floatString[] = "1003.72";  
	char charToTrack = '.';
	int positionOfCharToTrack;
	positionOfCharToTrack = findPositionOfChar (floatString, strlen(floatString), charToTrack);
 
	if (positionOfCharToTrack == -1)
		printf("[%c] not found.\n", charToTrack);
	else 
		printf("[%c] found at position %d.\n", charToTrack, positionOfCharToTrack);
 
	int N = 20;
	char intPart[N], decPart[N]; 
     
	getIntegerAndDecimalValues(floatString, strlen(floatString), intPart, decPart);
	printf("Integer Part: %s.\n", intPart);
	printf("Decimal Part: %s.\n", decPart); 
	
	// Detecting Non-Hexadecimal characters
	char hexString[] = "-1254BeAC86aDf9xb8E7cZ3Fd029~187^2A~`A1";
 
	printf ("Target string: %s\n", hexString);
	nonHexCharDetector (hexString, strlen(hexString));

	
	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_check_data_format()
{
	INFO(">> ");
	
	// string to int[]
	int count = 0;
	int message_size = 0;

	uint8_t message[256];

    char *msg = "d94ae0832e6445ce42331cb06d531a82b1db4baad30f746dc916df24d4e3c2451fff59a6423eb0e1d02d4fe646cf699dfd818c6e97b051";

    message_size = strlen(msg)/2;
    printf("Message size = %d\n", message_size);
    
	for (count=0; count < message_size; count++) {
        sscanf(msg + 2*count, "%02x", &message[count]);   // char to int: Remember without '&' (even for int or float variables), program will likely crash.
		
		printf("%02x ", message[count]); 
		if ((count+1) % display_N_values_per_line == 0){
			  printf("\n");
		}
		         
        //pos += 2*sizeof(char);
    }
    printf("\n");    

	printf("%s\n", DEMARCATOR_STRING);
}
