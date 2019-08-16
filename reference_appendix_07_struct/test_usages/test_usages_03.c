#include "main.h"

// global variables
#define sizeOfIntArrayInStruct 50

/*
==================================================
============= || LOCAL STRUCTS || ==============
==================================================
*/
typedef struct {
    char *e;
    char *d;
    char *f;
    int num[sizeOfIntArrayInStruct];
} mystruct_t;


typedef struct {
   int nbits;   ///< Number of bits in modulus
   const char *n;  ///< Modulus
   const char *p;
   const char *q;
   const char *e;
   const char *d;
} key_type_rsa;


/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
// depends on structure of struct
void structCopy (mystruct_t *dst, mystruct_t *src) {
    dst->e = malloc(strlen(src->e) + 1);
    dst->d = malloc(strlen(src->d) + 1);    
    dst->f = malloc(strlen(src->f) + 1);   
        
    strcpy(dst->e, src->e);
    strcpy(dst->d, src->d);   
    strcpy(dst->f, src->f); 
    
    int i = 0;
    
         for(i = 0; i < sizeOfIntArrayInStruct; i++){
               dst->num[i] = src->num[i];
         }       
         
}

void hexStringToHexBytesArray_local_to_03 (int genericBuffer[], char* stringBytes) {
     char* hexStringBytes = "";
     char* stringBytes_Data = "";
     //printf("%s\n", sendCommand->stringBytes);
          
          
     hexStringBytes = (char*) malloc((strlen(stringBytes)+ 1)*(sizeof(char))); // add 1 (sizeof(char) for '\0'    // use 32 bytes space allocated: max{key, data}
     memcpy(hexStringBytes, stringBytes, strlen(stringBytes));         // copy the input key string into the processing buffer
     
     printf("target str : %s\n\n", hexStringBytes);
     
     //char byteInStr[3] = ""; // XX\0
     char byteInStr[5] = "0x"; // 0xXX\0
     int numberOfBytes = 0; //  = (strlen(hexStringBytes)/2);     
     int i = 0;
     numberOfBytes = (int) strlen(stringBytes)/2;
     
     printf("number of bytes : %u\n\n", numberOfBytes);
        // convert the keys       
        for(i = 0; i < numberOfBytes; i++){
              strncat(byteInStr, &hexStringBytes[(i*2)], 1);           // insert the 1st hex character
              strncat(byteInStr, &hexStringBytes[(i*2)+1], 1);      // insert the 2nd hex character
              byteInStr[4] = '\0';
              //decValue[i] = (int)strtol(byteInStr, NULL, 0);   // without "0x" header, last paramater is 16
              // sendCommand->genericInputBuffer[i] = (int)strtol(byteInStr, NULL, 0);   // without "0x" header, last paramater is 16
              genericBuffer[i] = (int)strtol(byteInStr, NULL, 0);   // without "0x" header, last paramater is 16
              //printf("STR>>> %s \n", byteInStr);
              printf("HEX_%4d >>>>> %x \n", i, genericBuffer[i]);
              strcpy(byteInStr, "0x");
         }  
         
     free(hexStringBytes);    // prepare for re-allocation 
     hexStringBytes = (char*) malloc((strlen(stringBytes_Data)+ 1)*(sizeof(char))); // add 1 (sizeof(char) for '\0'    // use 32 bytes space allocated: max{key, data}
     memcpy(hexStringBytes, (stringBytes_Data), strlen(stringBytes_Data));         // copy the input data string into the processing buffer         

        // convert the data into integer buffer
        /*
        for(i = 0; i < 16; i++){
              strncat(byteInStr, &hexStringBytes[(i*2)], 1);    // insert the 1st hex character
              strncat(byteInStr, &hexStringBytes[(i*2)+1], 1);  // insert the 2nd hex character
              byteInStr[4] = '\0';
              genericBuffer[i] = (int)strtol(byteInStr, NULL, 0);   // without "0x" header, last paramater is 16
              strcpy(byteInStr, "0x");
         }  
         */         
}


/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_create_data_struct_for_big_numbers ()
{
	INFO(">> ");

	char s1[] = "AB1defAB2defAB3defAB4defAB5def";
    char s2[] = "=1234567890=";
    char* tmpStr;
    mystruct_t test;
    mystruct_t test_Next;
    
    tmpStr = "a8b3b284af8eb50b387034a860f146c4919f318763cd6c5598c8ae4811a1e0abc4c7e0b082d693"
   "a5e7fced675cf4668512772c0cbc64a742c6c630f533c8cc72f62ae833c40bf25842e984bb78bd"
   "bf97c0107d55bdb662f5c4e0fab9845cb5148ef7392dd3aaff93ae1e6b667bb3d4247616d4f5ba"
   "10d4cfd226de88d39f16fb";
   
   key_type_rsa rsaKey;
   
   printf("%s \n\n\n", tmpStr);
   
   rsaKey.n = malloc((strlen(tmpStr)+ 1)*(sizeof(char)));
   memcpy(rsaKey.n, tmpStr, (strlen(tmpStr)+ 1));
   
   printf("%s \n\n\n", rsaKey.n);
   
   free(rsaKey.n);
   
   rsaKey.n = malloc((strlen(s2)+ 1)*(sizeof(char)));
   memcpy(rsaKey.n, s2, (strlen(s2)+ 1));
   
   printf("%s \n\n\n", rsaKey.n);
   
   //
    
    test.d = (char *)malloc(strlen(s1));
    test.e = (char *)malloc(strlen(s2));
    strcpy(test.e, s1);
    printf("e: %s\n", test.e);
    strcpy(test.d, s2);
    printf("d: %s\n", test.d);
    printf("e': %s\n", test.e);   
    
    tmpStr = (char*) malloc((strlen(s1)+ 1)*(sizeof(char))); // add 1 (sizeof(char) for '\0'
    strcpy(tmpStr, s1);
    printf("tmpStr: %s\n", tmpStr);     
    
    hexStringToHexBytesArray_local_to_03 (test.num, tmpStr);
    
         int i=0;
         int numberOfBytes = (int) strlen(s1)/2;
         for(i = 0; i < numberOfBytes; i++){
               printf("HEX_%4d >>> %x \n", i, test.num[i]);
         }   
         
         //
         int sizeOfIntArray = sizeof(test.num)/sizeof(int);
         printf("size of int array >>> %d \n", sizeOfIntArray);         
         
         
    strcpy(s2, tmpStr); // can't malloc for s2 array, as it had been initialized
    printf("s2: %s\n", s2);
    
             test.f  = (char *)malloc(strlen(s2));  
             strcpy(test.f, s2);
       
    structCopy(&test_Next, &test);
    
         for(i = 0; i < numberOfBytes; i++){
               printf("HEX_%4d >>> %x \n", i, test_Next.num[i]);
         }       
         
         printf("Next: e: %s\n", test_Next.e);
         printf("Next: d: %s\n", test_Next.d);
         printf("Next: f: %s\n", test_Next.f);

	
	
	printf("%s\n", DEMARCATOR_STRING);
}	
