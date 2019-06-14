#include "main.h"


/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
// Passing pointer argument and allocating/ freeing memory space
void putString (char** returnStringBuffer, char* inputStr) 
{
    char *tmp = (char *)malloc(strlen(inputStr) + 1);   // Allocating memory space { +1 for '\0' }
    strcpy(tmp, inputStr);
    *returnStringBuffer = tmp;
}

//Determining whether Agnostic function is Designated or not
void designatedFunction(int mode, int type, const char *file, int line) { // this function should not be at base 0
      printf("address of designated function : 0x%p\n", &designatedFunction); 
}


