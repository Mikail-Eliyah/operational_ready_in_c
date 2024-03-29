#include "main.h"

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
// global variables

char buffer[BUFFER_SIZE + 1];	// char* buffer = malloc(BUFFER_SIZE + 1);

int display_N_values_per_line = 5;
int isLittleEndian = 1;


int test_usage_bit_wise_operations()
{
    char *record = "NAXHDKAN552ajdasdadNDfadsEBEAfA8gda5214S";
    //char *record = "NAXHDKA";

    int recordLen = strlen(record);
    char * buffer = NULL;
    int i = 0;

    isLittleEndian = checkEndian();

    recordLen = recordLen + recordLen%2;
    buffer = malloc(recordLen);
    memcpy(buffer, record, recordLen);

    printf("\n input bit stream:\n");
    dumpBin(buffer, recordLen);


    printf("\n bit stream from getBit:\n");
    for ( i = 0; i < recordLen*8; i++)
    {
        getBit(buffer, i);
    }


    setBit(buffer, 8, 1);
    setBit(buffer, 9, 0);
    setBit(buffer, 10, 1);
    setBit(buffer, 11, 1);
    printf("\n bit stream after setBit:\n");
    dumpBin(buffer, recordLen);


    shift_left(record, buffer, recordLen, 1, isLittleEndian);
    printf("\n bit stream after shift_left:\n");
    dumpBin(buffer, recordLen);


    shift_right(record, buffer, recordLen, 9, isLittleEndian);
    printf("\n bit stream after shift_right:\n");
    dumpBin(buffer, recordLen);

    printf("\n");

    free(buffer);

}


int test_usage_bit_wise_determination()
{ 
	INFO(">> ");
	
	int a = 31, b = 14;
	int distCount = hamming_distance_between_2_integer (a, b);
	printf ("The distance is : %d.\n", distCount); // distance is : 2.
	
	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_insert_bits_as_substring_and_display_binary_string()
{ 
	INFO(">> ");
	
    int numberOfInputs = 3;
    char* inputs[numberOfInputs];	// 3 buffers of 4 bytes allocated
    
    inputs[0] = "1024";
    inputs[1] = "1108";
    inputs[2] = "11"; // try "0" and "\0"

	int number_of_bytes_allocated = count_bytes_in_array (inputs);
	printf("number_of_bytes_allocated: %d \n", number_of_bytes_allocated);
    
	printf("%s\n", DEMARCATOR_STRING);
	
    int answer = 0;
	printf("Before update_bits(): result [%d] -> '%s'\n", answer, display_unsigned_int_as_hex_string(answer, buffer, BUFFER_SIZE));
	zeroize_buffer (&buffer, (BUFFER_SIZE + 1));
	printf("target binary string: '%s'\n", display_unsigned_int_as_hex_string(1024, buffer, BUFFER_SIZE));
	
	printf("Inserting bit string: value [%d] -> '%s' from bit position %d to bit position %d in ", 21, display_unsigned_int_as_hex_string(21, buffer, BUFFER_SIZE), 2, 6);
	printf("target binary string: '%s'\n", display_unsigned_int_as_hex_string(1024, buffer, BUFFER_SIZE));
	
    answer = update_bits(1024, 21, 2, 6);
    
    printf("After update_bits(): result [%d] -> '%s'\n", answer, display_unsigned_int_as_hex_string(answer, buffer, BUFFER_SIZE));
	
	printf("%s\n", DEMARCATOR_STRING);
	printf("%u \n", (uint32_t)-1); // get max value of uint32_t
    printf("%u \n", (127U + 31U)); // add unsigned values
    printf("%u \n", (1U << (5))); // 0 is the last bit at lsb
    
	printf("%s\n", DEMARCATOR_STRING);
}

/*

*/
int test_usage_display_binary_string()
{ 
	INFO(">> ");
	
    char* binString = "11011101101"; 
               
    printf("Decimal value >>> %d\n", binary_string_to_decimal_value (binString, strlen(binString))); // Answer: 1773
	  
	unsigned char v = 255;
	print_bits(v);
	printf("\n");

	printf("%s\n", DEMARCATOR_STRING);
}


int test_usage_determine_buffer_size_and_bit_position(){
	INFO(">> ");
	
	int numberOfInputs = 3;
	char* inputs[numberOfInputs];	// 3 buffers of 4 bytes allocated
	
	int number_of_bytes_allocated = count_bytes_in_array (inputs);
	printf("number_of_bytes_allocated: %d \n", number_of_bytes_allocated);
	
	inputs[0] = "1024";
    inputs[1] = "1108";
    inputs[2] = "11"; // try "0" and "\0"
	
	int number = 0;

    /* Process all inputs, outputting their binary. */
    for (int i = 0; i<numberOfInputs; i++) {
        number = atoi (inputs[i]);
        printf("[%3d] %9d -> %s (from '%s')\n", i, number, display_unsigned_int_as_hex_string(number, buffer, BUFFER_SIZE), inputs[i]);
    } 
	
	number_of_bytes_allocated = count_bytes_in_array (inputs);
	printf("number_of_bytes_allocated: %d \n", number_of_bytes_allocated);
	
	printf("%s\n", DEMARCATOR_STRING);
	
	uint32 value = 4096*4; // position 14 // 1; // position 0
     
	int position = 0;
     
    position = find_MSB_bit_position(&value, 1);
	printf("The result [%d] -> '%s'\n", value, display_unsigned_int_as_hex_string(value, buffer, BUFFER_SIZE));
          
    printf("position: %d\n", position); 
	printf("%s\n", DEMARCATOR_STRING);
	
	int MSG_LEN = 0;
     
    unsigned char* msg =   "056b04216fe5f354ac77250a4b6b0c8525a85c59b0bd80c56450a22d5f438e596a333aa875e291"
    "dd43f48cb88b9d5fc0d499f9fcd1c397f9afc070cd9e398c8d19e61db7c7410a6b2675dfbf5d34"
    "5b804d201add502d5ce2dfcb091ce9997bbebe57306f383e4d588103f036f7e85d1934d152a323"
    "e4a8db451d6f4a5b1b0f102cc150e02feee2b88dea4ad4c1baccb24d84072d14e1d24a6771f740"
    "8ee30564fb86d4393a34bcf0b788501d193303f13a2284b001f0f649eaf79328d4ac5c430ab441"
    "4920a9460ed1b7bc40ec653e876d09abc509ae45b525190116a0c26101848298509c1c3bf3a483"
    "e7274054e15e97075036e989f60932807b5257751e79"; 

      MSG_LEN = strlen(msg)/2;
      printf("MSG_LEN: %d\n", MSG_LEN);
      printf("msg: %s\n", msg);
      
      MSG_LEN = 0;
      MSG_LEN = count_bytes_in_array_buffer (msg, display_N_values_per_line);
      printf("Number of characters: %d\n", MSG_LEN);

      char* sometext;
      int sometext_len = MSG_LEN+1; // +1 for null char
      
      sometext = malloc(sometext_len);

      memset(sometext, 65, sometext_len); // 65 is ascii for `A`
      count_bytes_in_array_buffer (sometext, display_N_values_per_line);
      memcpy(sometext, msg, 10);   // copy the 1st 10 char (or bytes, that is reserved for storing the char)   
      count_bytes_in_array_buffer (sometext, display_N_values_per_line);

	
}

int test_usage_get_set_bits()
{ 
	INFO(">> ");
	int num = 255; // 191d:1011 1111b (position 6 = '0') // 255d: 1111 1111b
 
	num = set_bit(num, 6, 0); // set bit to '0'
	num = get_bit(num, 6);
	printf ("Bit value: %d\n", num);
 
	num = set_bit(num, 6, 1); // set bit to '1'
	num = get_bit(num, 6);
	printf ("Bit value: %d\n", num);
	
	int a = 105; // 85d: 101 0101b => 170d: 1010 1010b; 105d: 0110 1001b => 150d = 1001 0110b
	printf ("Before swapping odd and even bits, the result is : %d.\n", a);
	printf ("After swapping odd and even bits, the result is : %d.\n", swap_odd_even_bits(a));
	
	printf("%u \n", BIT_MASK(12, 8));    // create a mask from MSB to LSB position stated, eg. BIT_MASK(5, 3) = 111000, BIT_MASK(12, 8) = 1111100000000, 
    printf("%s \n", display_unsigned_int_as_hex_string (BIT_MASK(12, 8), buffer, BUFFER_SIZE));
    
    printf("%u \n", BIT_VAL(12, 8, 2));    // val is another mask to obtain the bit values ... get a mask from MSB to LSB position stated, eg. BIT_MASK(12, 8, 2) = [10] 0000 0000 & 111[11] 0000 0000, 
    
    printf("%s \n", display_unsigned_int_as_hex_string (BIT_VAL(12, 8, 2), buffer, BUFFER_SIZE));
	
	// EXTRACT_BITS(msb, lsb, numberOfBits, targetValue), eg: targetValue = 10[11 0011] 0000 0000b (45,824d), numberOfBits = 6 bits for [11 0011]
    // msb = 13, lsb = 8
    printf("%u \n", EXTRACT_BITS(13, 8, 6, 45824));  
    printf("%s \n", display_unsigned_int_as_hex_string ((EXTRACT_BITS(13, 8, 6, 45824)), buffer, BUFFER_SIZE));  // 51
	
	int answer = 0;
	
	set_buffer_to_ones (&answer, 4); // 4 bytes
	printf("After set_buffer_to_ones(): result [%d] -> '%s'\n", answer, display_unsigned_int_as_hex_string(answer, buffer, BUFFER_SIZE));
	
	zeroize_buffer (&buffer, (BUFFER_SIZE + 1));
	
	zeroize_buffer (&answer, 4);
	printf("After zeroize_buffer(): result [%d] -> '%s'\n", answer, display_unsigned_int_as_hex_string(answer, buffer, BUFFER_SIZE));
	zeroize_buffer (&buffer, (BUFFER_SIZE + 1));
	
	printf("%s\n", DEMARCATOR_STRING);
}