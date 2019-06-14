#include "main.h"


/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
// pad with bytes with zeros
void array_zero_padder_to_front(char* A, char *Apadded, int padSize)
{
    ANNOUNCE_FUNCTION_CALLED();
	
    int numberOfChar_OriginalBuffer = strlen (A);
    int startPointToCopy = (padSize-numberOfChar_OriginalBuffer)-1;    
    printf("Original length: %d\n", numberOfChar_OriginalBuffer);     
	printf("Before Padding >>> %s\n", A);  
    memcpy(Apadded+startPointToCopy+1, A, numberOfChar_OriginalBuffer);  
    memcpy(Apadded+padSize, "\0", 1); 
    printf("After Padding >>> %s\n", Apadded);     
    /*
    memcpy(Apadded+startPointToCopy, A, numberOfChar_OriginalBuffer);                
    
    memcpy(Apadded+(padSize*2)-1, "\0", 1 ); //+1 for null char
    printf("Before Padding >> %s\n", Apadded); 
    memset(Apadded+numberOfChar_OriginalBuffer, 0, (padSize-numberOfChar_OriginalBuffer));
    */
}


void allocationStringBuffer (char* stringContent, struct stringItem** pstring) {

    // dynamically sized object
    int n;
    n = strlen(stringContent);

    struct stringItem *string;
    string = malloc(sizeof(struct stringItem) + (n+1));

    if (string == NULL) {             // check if malloc is successful
       printf("Memory allocation for string fails.\n");
       // exit(-1);
    }   

   strcpy(string->str, stringContent);
   printf("Struct string: %s\n", string->str);
   string->len = n;     
   
   *pstring = string;  // Copy allocated pointer to out-parameter.
}

