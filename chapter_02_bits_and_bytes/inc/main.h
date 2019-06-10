#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h> 

/*
==================================================
============= || DEFINE CONSTANTS || =============
==================================================
*/
#define PI 3.14159265
#define DEMARCATOR_STRING "==========================================================="

#define INFO(msg) \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING); \
    fprintf(stderr, "[info]:\n<file>: %s \n<function>:%s \n<line>: %d\n", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(stderr, "%s\n", msg); \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING);
	
#define BUFFER_SIZE 32

// msb, lsb are positions
#define BIT(n)                           (1U << (n))
#define BIT_MASK(msb, lsb)               (((((uint32_t)-1) << (31U-msb)) >> (31U-msb+lsb)) <<lsb)  // create bit mask
#define BIT_VAL(msb, lsb, val)           (((val) <<lsb) & BIT_MASK(msb, lsb))

#define EXTRACT_BITS(msb, lsb, numberOfBits, targetValue)      ((((BIT_MASK((numberOfBits-1), 0)) <<lsb) & BIT_MASK(msb, lsb)) &targetValue) \
                                                                                              >>lsb

/*
==================================================
=============== || DEFINE TYPES || ===============
==================================================
*/
  typedef unsigned int uint32;
  typedef unsigned intsize_t;


/*
==================================================
============= || USAGE FUNCTIONS || ==============
==================================================
*/
// void myPrintHelloMake(void);
int test_usage_insert_bits_as_substring_and_display_binary_string(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
int updateBits(int targetBinary, int binaryToInsert, int positionStartToInsert, int positionEndToInsert);

char* binrep (unsigned int val, char *buff, int sz);
void printbits(unsigned char v);

int getBit(int n, int index);
int setBit(int n, int index, int bitValue);

int binStrToDecValue (char binStr[], int binStrLen);

int countBytesInArray (char *includes[]);
int find_MSB32(uint32 a);
int find_bn_MSB(const uint32 *v, size_t N);
int swapOddEvenBits(int x);