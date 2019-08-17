#include "main.h"

// global variables
#define contentLength 5

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/

void dumpContents(char *strX) {
    char *p = strX;
    int n = 0;
    
    for (n = 0; n < contentLength; ++n) {
        printf("%2.2x ", *p);
        ++p;
    }

    printf("\t");

    p = strX;
    for (n = 0; n < contentLength; ++n) {
        printf("%c", *p ? *p : ' ');  // *p test means: "if you hit a null, print a space.
        ++p;
    }

    printf("\n", strX);
}


/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_memcpy_and_strcpy()
{ 
	INFO(">> ");
    
  // do_stringCount();   

    printf(">>> >>> %s\n", stringBytes);
    printf(">>> >>> %d\n", strlen(stringBytes)); // since the string len is know, proper malloc can be done
    
    printf("MODE >>> %s\n", operationalOptions[0]);
    

    char s[contentLength]={   's','a','\0','c','h'   };

    char membuff[contentLength]; 
    char strbuff[contentLength];
    memset(membuff, 0, contentLength); // init both buffers to nulls
    memset(strbuff, 0, contentLength);

    strcpy(strbuff,s);                                           // strcpy contents (delimited by '\0')
    memcpy(membuff,s, contentLength);           // memcpy contents 

    dumpContents(strbuff);  
    dumpContents(membuff); // show what happened


	printf("%s\n", DEMARCATOR_STRING);
}	
	

