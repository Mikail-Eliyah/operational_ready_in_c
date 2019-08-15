#include "main.h"

#define BUF_SIZE 16
	
extern struct item; // declare

struct item { 
	int* decValue[BUF_SIZE];
};

// struct item first; // instantiate
struct item first = {
	.decValue = {
	0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 
	0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a
	}
};

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/

// convert hexdecimal string to int array (hexadecimal values) and placed in allocated buffer starting from the buffer index 0
/* */
void hexStringToHexBytesArray_from_static_data (char* hexStringBytes) {
     char* hexByteInStr = "";
     //char byteInStr[3] = ""; // XX\0
     char byteInStr[5] = "0x"; // 0xXX\0 
     int numberOfBytes = (strlen(hexStringBytes)/2);
     int i = 0;
                
        for(i = 0; i < numberOfBytes; i++){
              strncat(byteInStr, &hexStringBytes[(i*2)], 1);       // insert the 1st hex character
              strncat(byteInStr, &hexStringBytes[(i*2)+1], 1);  
// insert the 2nd hex character
              byteInStr[5] = '\0';
             // decValue[i] = (int)strtol(byteInStr, NULL, 0);   // without "0x" header, last paramater is 16
              first.decValue[i] = (int)strtol(byteInStr, NULL, 0);   // without "0x" header, last paramater is 16. Results store in array within struct
              
              strcpy(byteInStr, "0x");
         }                 
}



//  pass the struct into a processing function directly. The added codes are in yellow highlight 

// convert hexdecimal string to int array (hexadecimal values) and placed in allocated buffer starting from the buffer index 0
/* */
void hexStringToHexBytesArray (struct item* obj, char* hexStringBytes) {

     char* hexByteInStr = "";
     //char byteInStr[3] = ""; // XX\0
     char byteInStr[5] = "0x"; // 0xXX\0 
     int numberOfBytes = (strlen(hexStringBytes)/2);
	 printf("numberOfBytes: %d \n", numberOfBytes);
	 
     int i = 0;
                
    for(i = 0; i < numberOfBytes; i++){
		strncat(byteInStr, &hexStringBytes[(i*2)], 1);       // insert the 1st hex character
        strncat(byteInStr, &hexStringBytes[(i*2)+1], 1);  
// insert the 2nd hex character
        byteInStr[5] = '\0';
        // decValue[i] = (int)strtol(byteInStr, NULL, 0);   // without "0x" header, last paramater is 16
        obj->decValue[i] = (int)strtol(byteInStr, NULL, 0);   // without "0x" header, last paramater is 16. Results store in array within struct
              
         strcpy(byteInStr, "0x");
        }                 
}

/*
Output:

HEX [within struct]>>> 11
HEX [within struct]>>> 22
HEX [within struct]>>> 33
HEX [within struct]>>> 44
HEX [within struct]>>> 55
HEX [within struct]>>> 66
HEX [within struct]>>> 77
HEX [within struct]>>> 0
HEX [within struct]>>> 0
HEX [within struct]>>> 0
HEX [within struct]>>> 0
HEX [within struct]>>> 0
HEX [within struct]>>> 0
HEX [within struct]>>> 0
HEX [within struct]>>> 0
HEX [within struct]>>> 0

*/

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_hex_strings()
{ 
	INFO(">> ");
	
	int* decValue[BUF_SIZE] = {
	0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 
	0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a
	};
	
	int numberOfBytes = BUF_SIZE;
	// target hexadecimal values to be inserted
	char* hexStringBytes = "11223344556677";
       
    int i=0;
       
	for(i = 0; i < numberOfBytes; i++){
          printf("HEX>>> %x \n", decValue[i]); 
    } 


	hexStringToHexBytesArray_from_static_data (hexStringBytes); // results now is directly placed in the array within the struct
	
    // display data of array within the struct
	
    for(i = 0; i < numberOfBytes; i++){             
             printf("HEX [within struct]>>> %x \n", first.decValue[i]); 
    } 
	
	
     hexStringToHexBytesArray (&first, hexStringBytes); // results now is directly placed in the array within the struct

    // display data of array within the struct
	/* 	*/
    for(i = 0; i < numberOfBytes; i++){             
        printf("HEX [within struct]>>> %x \n", first.decValue[i]); 
    } 

	
	printf("%s\n", DEMARCATOR_STRING);
}	
