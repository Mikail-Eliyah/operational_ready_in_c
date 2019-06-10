#include "main.h"

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/

int updateBits(int targetBinary, int binaryToInsert, int positionStartToInsert, int positionEndToInsert) { // [positionEndToInsert]....[positionStartToInsert]
 int max = ~0; /* All 1’s */

 // 1’s through position positionEndToInsert, then 0’s
 int left = max - ((1 <<positionEndToInsert) - 1);  // creating a 'left mask'
 // 1’s after position [positionStartToInsert]
 int right = ((1 <<positionStartToInsert) - 1);     // creating a 'right mask'
 // 1’s, with 0s between [positionStartToInsert] and [positionEndToInsert]
 int mask = left | right;                            // creating a mask at the specific position
 // Clear [positionStartToInsert] through [positionEndToInsert], then put [binaryToInsert] in there
 return (targetBinary& mask) | (binaryToInsert<<positionStartToInsert);
}

/* Create a string of binary digits based on the input value.
   Input:
       val:  value to convert.
       buff: buffer to write to must be >= sz+1 chars.
       sz:   size of buffer.
   Returns address of string or NULL if not enough space provided.*/

// static 
char* binrep (unsigned int val, char *buff, int sz) {
    char *pbuff = buff;
    int counterPosition = 0;

    /* Must be able to store one character at least. */
    if (sz< 1) return NULL;

    /* Special case for zero to ensure some output. */
    if (val == 0) {
        *pbuff++ = '0';
        *pbuff = '\0';
        return buff;
    }

    /* Work from the end of the buffer back. */
    pbuff += sz;
    *pbuff-- = '\0';

    /* For each bit (going backwards) store character. */
    while (val != 0) {
        if (sz-- == 0) 
           return NULL;
        
        // add a space for each 4 bits (to format pbuff for 4 bit per block display)      
        if ((counterPosition%4) == 0) 
           *pbuff-- = ' '; // add a space char
        counterPosition++;
           
        *pbuff-- = ((val& 1) == 1) ?'1' : '0';

        /* Get next bit. */
        val>>= 1;
    }
    
    return pbuff+1;
}

void printbits(unsigned char v) {
  int i; // for C89 compatability
  for(i = 7; i>= 0; i--) 
putchar('0' + ((v >>i) & 1));
}

int getBit(int n, int index) 
{
 return ((n & (1 << index)) > 0);
}

int setBit(int n, int index, int bitValue) 
{
 if (bitValue) {
 return n | (1 << index);
 } else {
 int mask = ~(1 << index);
 return n & mask;
 }
}



