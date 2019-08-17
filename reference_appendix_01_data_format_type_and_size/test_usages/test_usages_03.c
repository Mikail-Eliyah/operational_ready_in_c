#include "main.h"



/*
==================================================
======== || LOCAL STRUCTS / DATA TYPE || =========
==================================================
*/
// as a form of enum
typedef enum {FALSE_FLAG=0, TRUE_FLAG} Boolean;
        
// string type
typedef char *String;

// object/ struct type
typedef struct {
	int age; 
	char *name;
	} human;

// type that is under the same data form
typedef int X0, X1, X2, X3, X4;  


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

// struct not needed to be stated
static const human human_X[] = 
{
  { .age = 4, .name = "XX" },
  { .age = 40, .name = "X" },
  { .age = 400, .name = "" },
};

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

int test_usage_typedef(){
	INFO(">> ");
	
    String Text = "Kairos";
    printf("%s\n", Text);
	
	Boolean flag = TRUE_FLAG;
	printf("%d\n", flag);
	
	human man, woman, boy, girl;
	X0 x0_item = 199;
	
	girl.age = 15;
	girl.name = "mary";
	
	printf("%s: %d \n", girl.name, girl.age);
	printf("%s: %d \n", human_X[0].name, human_X[0].age);
	printf("%d: %x \n", x0_item, x0_item);
	
	int i;

	int a[50] = {1,2,[40]=55,56,57,[23]=11,12};

	for (i=0; i < 50;i++) {
    if (i%10 == 0)
       printf("\n");
       
    printf("%d\t", a[i]);
    }


	
	printf("%s\n", DEMARCATOR_STRING);
}	

#define RAND_MAX_VALUE 51


int test_usage_generate_random(){
	INFO(">> ");
    int len = 2, breadth = 3, height = 5;
    int a[height][len][breadth];
    //srand(time(NULL));
    int r = (rand()%RAND_MAX_VALUE); // /* random int between 0 and (RAND_MAX_VALUE-1) */
    // (rand()%(hi_num-low_num))+low_num;
    int i,j,k;
    for (i=0;i<height;i++) {
        for (j=0;j<len;j++) {
            for (k=0;k<breadth;k++) {
                //srand(time(NULL));
                //a[i][j][k] = (rand()%RAND_MAX_VALUE);
                a[i][j][k] = (i*100)+(j*10)+(k);
                printf("%3d ", a[i][j][k]);
            }   
            printf("\n");
        }   
        printf("\n"); 
    }
    //int (*r)[5] = a[0];
    int *t = a[1][2];
    printf("> %d\n", *t);
	
	
	printf("%s\n", DEMARCATOR_STRING);
}	

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

