#include "main.h"


/* 
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
int findPositionOfChar (char* targetStr, int lengthOfStr, char charToTrack) {
    int i=0;
    int positionOfCharToTrack = -1;            // assume out of bounds
    
    for (i=0; i<lengthOfStr; i++) {
        if (targetStr[i] == charToTrack) {
           positionOfCharToTrack = i;
        }
    }
    
    return positionOfCharToTrack;
}

// mantissa is assumed to exist.
void getIntegerAndDecimalValues (char* n, int strlen_n, char intPart[], char decPart[]) { // n is targetStr
     int i = 0;
     int mantissaPosition;
     int N = 20;
     //char intPart[N], decPart[N]; // number string, assumed malloc space of N each (accommodate max of size N)
     int intPartInDec = 0, decPartInDec = 0;
     char int_stringBin[20] = "", dec_stringBin[20] = ""; // binary strings
     
     mantissaPosition = findPositionOfChar (n, strlen_n, '.');    // position of decimal point (mantissa)
     //printf("'.' found at position %d.\n", mantissaPosition);

     // get the integer part
     if (mantissaPosition == 0) // ie. ".xxxx" sited at position 0, meaning integer part is 0
        memcpy(intPart, "0\0", 2);
     else {
          memcpy(intPart, &n[0], mantissaPosition);
          memcpy((intPart+mantissaPosition), "\0", 1 ); // append null char to offset (mantissaPosition)
          intPartInDec = atoi(intPart);
     }          
     // get the decimal part
     memcpy(decPart, &n[mantissaPosition+1], (strlen_n-mantissaPosition));
     decPartInDec = atoi(decPart);       
       //printf("\nInteger Part: %s, %d.\n", intPart, intPartInDec);
       //printf("Decimal Part: %s, %d.\n", decPart, decPartInDec); 
}

// [0 to 9]: ascii = 48 to 57; [A to F]: 41 to 70; [a to f]: 97 to 102
void nonHexCharDetector (char* strTarget, int strTargetLength) {
     int i = 0;
     int asciiCharIndex = 0;

     // register the occurence
     for (i = 0; i < strTargetLength; i++) {
         asciiCharIndex = (int)(strTarget[i]); // asciiCharIndex refers to ascii table
         
         if ( (asciiCharIndex < 48) || 
              ((asciiCharIndex > 57) && (asciiCharIndex < 41)) ||
              ((asciiCharIndex > 70) && (asciiCharIndex < 97)) ||
                (asciiCharIndex > 102)   ) {
         printf ("non-Hex Char: %c detected at position %d\n", (strTarget[i]), i);
         }
     }     
     printf ("\n");
}


void ASCII_CharsHistogram (char* strTarget, int strTargetLength, int asciiHistogramCount[]) {
     int i = 0;
     int asciiIndex = 0;

     // zeroize
     for (i = 0; i < 256; i++) {
         asciiHistogramCount[i] = 0;
     }
     // register the occurence
     for (i = 0; i < strTargetLength; i++) {
         asciiIndex = (int)(strTarget[i]);
         //printf ("asciiIndex: %d\n", asciiIndex);
         asciiHistogramCount[asciiIndex] = asciiHistogramCount[asciiIndex] + 1;
     }     
}

void displayASCII_CharsHistogram (int asciiHistogramCount[]) {
     int i = 0, j = 0;

     // display the occurence
     for (i = 0; i < 256; i++) {
         if (asciiHistogramCount[i] != 0) {
               printf ("ascii symbol, %c : ", (char) i);                     
               for (j = 1; j <= asciiHistogramCount[i]; j++) {
                   printf ("*");
               }
               printf ("\n");
         }
     }     
     printf ("\n\n");
}


void int_set_right(int* y, int valueToSet){
    *y = valueToSet;
}

/*
Note that :
1 of the silly thing in C programming is:

lengthOfArray won't work correctly for pointers (as opposed to arrays) within array_set() but gives the right answer in main(), since sizeof(x) will return the size of the pointer and not the size of the pointed-to array. You have to explicitly pass the size of the array into the function.

*/
void array_set(int* y_dest, int* y_src, int arrayLength){ // arrays
     int i = 0;
     
     //printf("lengthOfArray in function: %d \n", lengthOfArray(y_src));  
     // [TODO] check that y_dest has enough space
     for (i=0;i<arrayLength; i++)
         y_dest[i] = y_src[i];
    // 
}

int safeCopy(char *from, int from_len, char *to, int to_len) {
    int i = 0;
    int max = (from_len > to_len - 1)? to_len: from_len;

    // to_len must have at least 1 byte
    if(from_len < 0 || to_len <= 0) 
                return -1;

    for(i = 0; i < max; i++) {
        to[i] = from[i];
    }

    to[to_len] = '\0';   // string must end with null char

    return i;
}

/*********************************************************************
**  print_text() - print the text into the dmesg buffer.
*********************************************************************/
// static 
void print_text(char *intro_message, unsigned char *text_addr, unsigned int size)
{
    unsigned int   i;

    printf("%s @ address = 0x%x\n", intro_message, (unsigned int)text_addr);
    for (i = 0;  i < size;  i++) {
        printf("%2x ", text_addr[i]);
        if ((i & 0xf) == 0xf)
            printf("\n");
    }
    printf("\n");
}




