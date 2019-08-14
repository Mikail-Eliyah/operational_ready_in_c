#include "main.h"

/*
==================================================
============= || LOCAL DEFINES || ==============
==================================================
*/

#define sizeOfArray 10
#define arrayLengthInStruct 50

/*
==================================================
=============== || LOCAL STRUCT || ===============
==================================================
*/

struct contain {
    char* a;        //
    int allowed;    //

    struct suit {
       struct t {
              char* option;
              int count;
       } t;

       struct inner {
              char* option;
              int count;
       } inner;
    } suit;
};



struct big {
    uint32_t buffer[1000];
};

struct small {
    uint32_t buffer[10];
};



typedef struct {
    struct {
       int _buf[arrayLengthInStruct];           
       int _bufLen;
    } _context;
} _handle;


typedef struct {
       int _buf[arrayLengthInStruct];           
       int _bufLen;
} list;
    
struct dev_req {    
    struct {     
        struct {        
            list* src;  // point src to a list type, and access its element, then you should define src as list * type instead of int or another other types
        }serviceReq;
    }_req;     
};


/*
==================================================
================ || LOCAL DATA || ================
==================================================
*/

// initialize
struct contain _vector = {
    .a = "John",
    .allowed = 1,

    .suit = {
        .t = {
            .option = "ON",
            .count = 7
        },

        .inner = {
            .option = "OFF",
            .count = 7
        }
    }
};


struct contain structArrayToBeCheck[] = {
        {
            .a = "John",
            .allowed = 1,

            .suit = {
                .t = {
                    .option = "ON",
                    .count = 7
                },

                .inner = {
                    .option = "OFF",
                    .count = 7
                }
            }
        },
        {
            .a = "John",
            .allowed = 1,

            .suit = {
                .t = {
                    .option = "ON",
                    .count = 7
                },

                .inner = {
                    .option = "OK",
                    .count = 7
                }
            }
        },
        {
            .a = "John",
            .allowed = 1,

            .suit = {
                .t = {
                    .option = "ON",
                    .count = 7
                },

                .inner = {
                    .option = "OFF",
                    .count = 7
                }
            }
        },
        {
            .a = "John",
            .allowed = 1,

            .suit = {
                .t = {
                    .option = "ON",
                    .count = 7
                },

                .inner = {
                    .option = "OFF",
                    .count = 7
                }
            }
        }
};


/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/



/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

// use struct pointer to access struct array
int test_usage_struct_02()
{
	INFO(">> ");
       int i;

       int n = sizeof(structArrayToBeCheck)/sizeof(struct contain);
	   
	   // determine number of struct in struct array
       printf( "There are %d elements in the array.\n", n);
	   
	   printf("Number of Struct within struct array: %d \n", sizeof(structArrayToBeCheck)/sizeof(struct contain));

       struct contain *check = malloc(n*sizeof(struct contain));

       memcpy( check, structArrayToBeCheck, sizeof(structArrayToBeCheck));

       // do things with check[0], check[1], ... check[n-1]
       printf( "check is %s\n", check[1].suit.inner.option);
	   
	  printf("option: %s \n", _vector.suit.t.option);printf("option: %s \n", _vector.suit.inner.option);


       free(check);

	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_fitting_1_struct_in_another_by_memcpy()
{
	INFO(">> ");
	int i = 0;


    struct big B;
    struct small S;

    const uint32_t sizeOfBufferOf_big = 1000;
    const uint32_t sizeOfBufferOf_small = 10;

    for (i=0;i<sizeOfBufferOf_big;i++) {
        B.buffer[i] = i+50;
    }

    for (i=0;i<sizeOfBufferOf_small;i++) {
        S.buffer[i] = i+1;
    }

    memcpy(&B, &S, sizeof(S));

    for (i=0;i<sizeOfBufferOf_big;i++) {
        printf("%d ", B.buffer[i]);
    }
    printf("\n");

    // 1 2 3 4 5 6 7 8 9 10 60 61 62 63 64 65 66 .... 1047 1048 1049


    printf("size of B: %d \n", sizeof(B)); // 4000
    printf("size of S: %d \n", sizeof(S)); // 40

    // memcpy(&S, &B, sizeof(B)); // cannot fit


	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_struct_extract_array_from_array_within_a_struct(){
	INFO(">> ");

	    // struct 
    _handle handlePtr;
    _handle* handle = (_handle*) &handlePtr;   // data is here
    int* k_src = NULL; // to be loaded to
    int i = 0;

    handlePtr._context._bufLen = arrayLengthInStruct;
    // initialize the source
    for (i = 0; i < handlePtr._context._bufLen; i++) {
        handlePtr._context._buf[i] = i+1;
        printf("%d \t", handlePtr._context._buf[i]);
    }
    printf("\n");

    k_src = malloc(sizeof(int)*(handlePtr._context._bufLen)); 
    printf("Amount of data to copy: %d \n", handle->_context._bufLen);   

// check for trailing buffer from previous updates and append it
/*

memcpy copies a number of bytes rather than integers. You need to multiply your array size by sizeof(int) when using it with memcpy.
On a little-endian machine with 4-byte int type, copying 50 bytes would give you what you see (50 / 4 = 12.5) though the last element 13 would depend on what was already in the destination memory.
*/
memcpy ( k_src,
     &handle->_context._buf[0],
     (handle->_context._bufLen)* sizeof(int) 
);

    for (i = 0; i < handlePtr._context._bufLen; i++) {
        printf("%d \t", k_src[i]);
    }
    printf("\n");

/*
1       2       3       4       5       6       7       8       9       10      11      12      13
14      15      16      17      18      19      20      21      22      23      24      25      26
27      28      29      30      31      32      33      34      35      36      37      38      39
40      41      42      43      44      45      46      47      48      49      50
Amount of data to copy: 50
1       2       3       4       5       6       7       8       9       10      11      12      13
14      15      16      17      18      19      20      21      22      23      24      25      26
27      28      29      30      31      32      33      34      35      36      37      38      39
40      41      42      43      44      45      46      47      48      49      50
*/


	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_pass_a_struct_to_another_struct_within_a_struct(){
	INFO(">> ");
	
   int i=0;
    // struct 
    // to pass the memory location
    list g_src;                   // data is here
    struct dev_req *dev_Areq;     // to be loaded/ transfer to here

       g_src._bufLen = arrayLengthInStruct;
    // initialize the source
    for (i = 0; i < g_src._bufLen; i++) {
        g_src._buf[i] = i+1;
        printf("%d \t", g_src._buf[i]);
    }
    printf("\n");

dev_Areq = (struct dev_req *)malloc(sizeof(struct dev_req ));
dev_Areq->_req.serviceReq.src = (list*) &g_src;           

    for (i = 0; i < (dev_Areq->_req.serviceReq.src)->_bufLen; i++) {
        printf("%d \t", (dev_Areq->_req.serviceReq.src)->_buf[i]);
    }
    printf("\n");

/*
1       2       3       4       5       6       7       8       9       10      11      12      13
14      15      16      17      18      19      20      21      22      23      24      25      26
27      28      29      30      31      32      33      34      35      36      37      38      39
40      41      42      43      44      45      46      47      48      49      50

1       2       3       4       5       6       7       8       9       10      11      12      13
14      15      16      17      18      19      20      21      22      23      24      25      26
27      28      29      30      31      32      33      34      35      36      37      38      39
40      41      42      43      44      45      46      47      48      49      50
*/
/*
// [Notes]
// after kmalloc, ie. k_src = kmalloc (...);
    if (k_src == NULL) {
        printf("%s: Can't Allocate memory: k_src 0x%x\n",  __func__, (uint32_t)k_src);
        return -ENOMEM;
    }
*/
	
	printf("%s\n", DEMARCATOR_STRING);
}

