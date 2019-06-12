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
int test_usage_determine_buffer_size_and_bit_position(void);
int test_usage_get_set_bits(void);
int test_usage_display_binary_string(void);
int test_usage_bit_wise_determination(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
void zeroize_buffer (void* buff, size_t size);
void set_buffer_to_ones (void* buff, size_t size);

int update_bits (int target_binary, int binary_to_insert, int start_position_to_insert, int end_position_to_insert);

char* display_unsigned_int_as_hex_string (unsigned int val, char *buff, int sz);
void print_bits(unsigned char v);
int binary_string_to_decimal_value (char binStr[], int binStrLen);

int get_bit(int n, int index);
int set_bit(int n, int index, int bitValue);

int count_bytes_in_array (char *buffer[]);
int find_MSB32(uint32 a);
int find_MSB_bit_position(const uint32 *v, size_t N);
int swap_odd_even_bits(int x);

int hamming_distance_between_2_integer (int a, int b);