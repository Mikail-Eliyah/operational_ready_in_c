#include "main.h"

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/

int update_bits(int target_binary, int binary_to_insert, int start_position_to_insert, int end_position_to_insert) { // [end_position_to_insert: // high_bit_position]....[start_position_to_insert: // low_bit_position]
 int max = ~0; /* All 1’s */

 // 1’s through position end_position_to_insert, then 0’s
 int left = max - ((1 <<end_position_to_insert) - 1);  // creating a 'left mask'
 // 1’s after position [start_position_to_insert]
 int right = ((1 <<start_position_to_insert) - 1);     // creating a 'right mask'
 // 1’s, with 0s between [start_position_to_insert] and [end_position_to_insert]
 int mask = left | right;                            // creating a mask at the specific position
 // Clear [start_position_to_insert] through [end_position_to_insert], then put [binary_to_insert] in there
 return (target_binary& mask) | (binary_to_insert <<start_position_to_insert);
}

/* Create a string of binary digits based on the input value.
   Input:
       val:  value to convert.
       buff: buffer to write to must be >= sz+1 chars.
       sz:   size of buffer.
   Returns address of string or NULL if not enough space provided.*/

// static 
char* display_unsigned_int_as_hex_string (unsigned int val, char *buff, int sz) {
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


void zeroize_buffer (void* buff, size_t size)
{
        size_t i;
        char* foo = buff;
        for (i = 0; i < size; i++)
            foo[i] = 0;

}

void set_buffer_to_ones (void* buff, size_t size)
{
        size_t i;
        char* foo = buff;
        for (i = 0; i < size; i++)
            foo[i] = 0xFF;

}

void print_bits(unsigned char v) {
  int i; // for C89 compatability
  for(i = 7; i>= 0; i--) 
putchar('0' + ((v >>i) & 1));
}

int get_bit(int n, int index) 
{
 return ((n & (1 << index)) > 0);
}

int set_bit(int n, int index, int bitValue) 
{
 if (bitValue) {
 return n | (1 << index);
 } else {
 int mask = ~(1 << index);
 return n & mask;
 }
}

int binary_string_to_decimal_value (char binStr[], int binStrLen) 
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


int count_bytes_in_array (char *buffer[]) 
{
    //size_t count = 0;
    char count = 0;
    while (buffer[count] != NULL) {
          printf("buffer content[%d]: \t %c\n", count, buffer[count]); 
          count++;
    }
    
    return count;	// Length is count before detecting the NULL
}

/* Returns the number of leading zero bits in value of uint32 */
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
int find_MSB_bit_position (const uint32 *v, size_t N)
{
   if (N >= INT_MAX / 32) return (-2);
   while(N != 0 && v[N-1] == 0) { /* >=, but N is unsigned */
      --N;
   }
   if (N == 0) return (-1);
   return (32 * N - 1 - find_MSB32(v[N-1]));
}


// Mask all odd bits with 10101010 in binary (which is 0xAA), then shift them left to put them in the even bits. 
// Then, perform a similar operation for even bits. This takes a total 5 instructions.
int swap_odd_even_bits(int x) 
{
 return ( ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1) );
}
