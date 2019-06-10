#include "main.h"

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_insert_bits_as_substring_and_display_binary_string()
{ 
    int i;
    int n;
    char buff[BUFFER_SIZE + 1];
    int numberOfInputs = 3;
    char* inputs[numberOfInputs];
    
    inputs[0] = "1024";
    inputs[1] = "1108";
    inputs[2] = "0";

    /* Process all inputs, outputting their binary. */
    for (i = 0; i<numberOfInputs; i++) {
        n = atoi (inputs[i]);
        printf("[%3d] %9d -> %s (from '%s')\n", i, n, binrep(n,buff, BUFFER_SIZE), inputs[i]);
    }    
    
    int answer;
    answer = updateBits(1024, 21, 2, 6);
    
    printf("The result [%d] -> '%s'\n", answer, binrep(answer,buff, BUFFER_SIZE));
	
	printf("%s\n", DEMARCATOR_STRING);
	 int num = 255; // 191d:1011 1111b (position 6 = '0') // 255d: 1111 1111b
 
	num = setBit(num, 6, 0); // set bit to '0'
	num = getBit(num, 6);
	printf ("Bit value: %d\n", num);
 
	num = setBit(num, 6, 1); // set bit to '1'
	num = getBit(num, 6);
	printf ("Bit value: %d\n", num);
	
	unsigned char v = 255;
	printbits(v);
	printf("\n");
	printf("%s\n", DEMARCATOR_STRING);
	printf("%u \n", (uint32_t)-1); // get max value of uint32_t
    printf("%u \n", (127U + 31U)); // add unsigned values
    printf("%u \n", (1U << (5))); // 0 is the last bit at lsb
    
    printf("%u \n", BIT_MASK(12, 8));    // create a mask from MSB to LSB position stated, eg. BIT_MASK(5, 3) = 111000, BIT_MASK(12, 8) = 1111100000000, 
    printf("%s \n", binrep (BIT_MASK(12, 8), buff, BUFFER_SIZE));
    
    printf("%u \n", BIT_VAL(12, 8, 2));    // val is another mask to obtain the bit values ... get a mask from MSB to LSB position stated, eg. BIT_MASK(12, 8, 2) = [10] 0000 0000 & 111[11] 0000 0000, 
    
    printf("%s \n", binrep (BIT_VAL(12, 8, 2), buff, BUFFER_SIZE));
    
    // EXTRACT_BITS(msb, lsb, numberOfBits, targetValue), eg: targetValue = 10[11 0011] 0000 0000b (45,824d), numberOfBits = 6 bits for [11 0011]
    // msb = 13, lsb = 8
    printf("%u \n", EXTRACT_BITS(13, 8, 6, 45824));  
    printf("%s \n", binrep ((EXTRACT_BITS(13, 8, 6, 45824)), buff, BUFFER_SIZE));  // 51
	
	printf("%s\n", DEMARCATOR_STRING);
	// int i = 0;
	int decValue = 0;
    char* binString = "11011101101"; 
               
    printf("Decimal value >>> %d\n", binStrToDecValue(binString, strlen(binString))); // Answer: 1773
	
	printf("%s\n", DEMARCATOR_STRING);
	 uint32 value = 4096*4; // position 14 // 1; // position 0
     int position = 0;
     
     position = find_bn_MSB(&value, 1);
	 printf("The result [%d] -> '%s'\n", value, binrep(value, buff, BUFFER_SIZE));
          
     printf("position: %d\n", position);   

	printf("%s\n", DEMARCATOR_STRING);
	int a = 105; // 85d: 101 0101b => 170d: 1010 1010b; 105d: 0110 1001b => 150d = 1001 0110b
	printf ("After swapping odd and even bits, the result is : %d.\n", swapOddEvenBits(a));

	INFO(">> ");
		
}

/*

*/