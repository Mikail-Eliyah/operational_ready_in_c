#include "main.h"



/*
==================================================
============== || LOCAL STRUCTS || ===============
==================================================
*/


/*
==================================================
=============== || LOCAL DATA || ================
==================================================
*/
    #define _128K    0x20000
    #define _32K    0x8000
    #define _16K    0x4000

    unsigned char test_128K[_128K];

    unsigned char * input    = "\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
    "\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
                  "\xae\x2d\x8a\x57\x1e\x03\xac\x9c"
                  "\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
                  "\x30\xc8\x1c\x46\xa3\x5c\xe4\x11"
                  "\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
                  "\xf6\x9f\x24\x45\xdf\x4f\x9b\x17"
                  "\xad\x2b\x41\x7b\xe6\x6c\x37\x10";
                  
    unsigned int inputHexBytes[64];



/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
    static void hexStrToHexBytes(unsigned int inputHexBytes[], unsigned char *text_addr,
                            unsigned int size) {
        unsigned int   i;

        for (i = 0;  i < size;  i++) {
            inputHexBytes[i] = text_addr[i];
            //inputHexBytes[i] = (int)strtol(&text_addr[i], NULL, 0);   // without "0x" header, last paramater is 16
            //printf("%4d ", text_addr[i]);
            printf("%4x ", inputHexBytes[i]);
            if ((i & 0xf) == 0xf)
                printf("\n");
        }
        printf("\n");
    }

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_display_data_02(){
	INFO(">> ");
	
        int i = 0;
        //int numberOfElements = sizeof(testopts)/sizeof(option_t);
        // printf("%d\n", numberOfElements);
        
        print_text("Original data", input,
                        (unsigned int)strlen(input));
                        
         hexStrToHexBytes(inputHexBytes, input,
                        (unsigned int)strlen(input));    
                        
    /*
      6b   c1   be   e2   2e   40   9f   96   e9   3d   7e   11   73   93   17   2a
      ae   2d   8a   57   1e    3   ac   9c   9e   b7   6f   ac   45   af   8e   51
      30   c8   1c   46   a3   5c   e4   11   e5   fb   c1   19   1a    a   52   ef
      f6   9f   24   45   df   4f   9b   17   ad   2b   41   7b   e6   6c   37   10
    */                                    
        
    /*
    Original data @ address = 0x40301c
    6b c1 be e2 2e 40 9f 96 e9 3d 7e 11 73 93 17 2a
    ae 2d 8a 57 1e  3 ac 9c 9e b7 6f ac 45 af 8e 51
    30 c8 1c 46 a3 5c e4 11 e5 fb c1 19 1a  a 52 ef
    f6 9f 24 45 df 4f 9b 17 ad 2b 41 7b e6 6c 37 10
    */

    int packet_size = 1024 * 5;

    for (i = 0; i < (_32K * 4); i++)
		test_128K[i] = i % 255;
            
	print_text("Original data", &test_128K[0],
                        (unsigned int)(packet_size/64));    
                        
    /*
    Original data @ address = 0x404060
     0  1  2  3  4  5  6  7  8  9  a  b  c  d  e  f
    10 11 12 13 14 15 16 17 18 19 1a 1b 1c 1d 1e 1f
    20 21 22 23 24 25 26 27 28 29 2a 2b 2c 2d 2e 2f
    30 31 32 33 34 35 36 37 38 39 3a 3b 3c 3d 3e 3f
    40 41 42 43 44 45 46 47 48 49 4a 4b 4c 4d 4e 4f

    */
	
	
	printf("%s\n", DEMARCATOR_STRING);
}

