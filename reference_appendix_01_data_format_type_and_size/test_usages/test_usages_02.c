#include "main.h"

#define _128K    0x20000
#define _32K    0x8000
#define _16K    0x4000


/*
==================================================
============== || LOCAL STRUCTS || ===============
==================================================
*/
struct test_vector {
    // only used with keyed hash algorithms 
    char *key;
    unsigned char klen;
    char *iv;
    unsigned char ivlen;
    char *input;
    unsigned char ilen;
    char *result;
    unsigned char rlen;
    char *digest;
    unsigned char diglen;
    //enum dev_cipher_alg_enum c_alg;
    //enum dev_cipher_mode_enum mode;
    //enum dev_sha_alg_enum hash_alg;
};

/*
==================================================
=============== || LOCAL DATA || ================
==================================================
*/

struct test_vector cipher_aes_tv[] = {
{ // TEST VECTOR 1  AES-128 ECB: NIST SP800-38A 
        //.c_alg    = DEV_ALG_AES,
        //.mode    = DEV_AES_MODE_ECB,
        .key    = "\x2b\x7e\x15\x16\x28\xae\xd2\xa6"
              "\xab\xf7\x15\x88\x09\xcf\x4f\x3c",
        .klen   = 16,
        .ivlen    = 0,
        .input    = "\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
              "\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
              "\xae\x2d\x8a\x57\x1e\x03\xac\x9c"
              "\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
              "\x30\xc8\x1c\x46\xa3\x5c\xe4\x11"
              "\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
              "\xf6\x9f\x24\x45\xdf\x4f\x9b\x17"
              "\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
        .ilen    = 64,
        .result = "\x3a\xd7\x7b\xb4\x0d\x7a\x36\x60"
              "\xa8\x9e\xca\xf3\x24\x66\xef\x97"
              "\xf5\xd3\xd5\x85\x03\xb9\x69\x9d"
              "\xe7\x85\x89\x5a\x96\xfd\xba\xaf"
              "\x43\xb1\xcd\x7f\x59\x8e\xce\x23"
              "\x88\x1b\x00\xe3\xed\x03\x06\x88"
              "\x7b\x0c\x78\x5e\x27\xe8\xad\x3f"
              "\x82\x23\x20\x71\x04\x72\x5d\xd4",
        .rlen   = 64
}
                                                 };


/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
// sizeOfBuffer: _128K, _32K, _16K
// bufferArea:test_
// dataRangeMax: 255
void allocateData (int sizeOfBuffer, char* bufferArea, int dataRangeMax) {
     int i = 0;
     
    for (i = 0; i < (sizeOfBuffer * 4); i++)
        bufferArea[i] = i % dataRangeMax;     
}

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_00(){
	INFO(">> ");
	
	unsigned char test_128K[_128K];
	
    int packet_size = 1024 * 5;

        for (int i = 0; i < (_32K * 4); i++)
            test_128K[i] = i % 255;
	
		
	print_text("View Results: ", (unsigned char*) cipher_aes_tv[0].result, 64);
	
	allocateData (_32K, &test_128K, 10); // allocateData (_32K, &test_128K, 255);
    print_text("Original data", &test_128K[0],
                    (unsigned int)(packet_size/64));

	
	printf("%s\n", DEMARCATOR_STRING);
}

