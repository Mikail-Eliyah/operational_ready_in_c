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

int binStrToDecValue (char binStr[], int binStrLen) 
{
     int i = 0;
     int decValue = 0;
     
     for (i=0;i<binStrLen;i++) {
         if (binStr[i] == '1') 
            decValue = decValue * 2 + 1; 
         else if (binStr[i] == '0') 
              decValue *= 2; 
     }      
     return decValue;
}


int countBytesInArray (char *includes[]) 
{
    //size_t count = 0;
    char count = 0;
    while (includes[count] != NULL) {
          printf("\t %c\n", includes[count]); 
          count++;
    }
    // Length is count.
    
    return count;
}

/* Returns the number of leading zero bits in a */
/* for ARM there is a machine instruction that does this. */
int find_MSB32(uint32 a) 
{
   int n = 0;
#define MSB_STEP(k) if (((0 - (0x80000000U >> (k-1))) & a) == 0) {a <<= k;  n += k;}

   MSB_STEP(16);
   MSB_STEP(8);
   MSB_STEP(4);
   MSB_STEP(2);
   MSB_STEP(1);
   return (n);
}

//  get the position of the 1st non-zero bit
/* returns the bit position (0 is LSB) of the MSB in a bignum, v.
 * Returns -1 if the bignum is zero, -2 on error  */
int find_bn_MSB(const uint32 *v, size_t N)
{
   if (N >= INT_MAX / 32) return (-2);
   while(N != 0 && v[N-1] == 0) { /* >=, but N is unsigned */
      --N;
   }
   if (N == 0) return (-1);
   return (32 * N - 1 - find_MSB32(v[N-1]));
}


