#include "main.h"

// global variables
#define ARGUMENT_KEY_POSITION 2

int display_N_values_per_line = 20;

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/


/*
==================================================
============= || LOCAL DATA TYPE || ==============
==================================================
*/

union secondary_characteristics { // a. change to struct for comparison
      char B;                     // 1 byte
      short C;                    // 2 byte
};

struct item {
       char A;                               // 1 byte
       union secondary_characteristics form; // 3 byte     // b. change to struct for comparison
};

// union allows extraction of full 32-bit value, or individual byte fields, eg. value.byte.c0,
union bits32_tag {
       int whole;                             // one 32-bit value
       struct {char c0,c1,c2,c3;} byte;       // four 8-bit bytes. 
} value;


typedef union
{
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } bytes;
    unsigned int dword;
} HW_Register;

// another example shows bit fields
typedef union
{
    struct {
        unsigned char b1:1; // default 1 bit valued 0
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char reserved:4;
    } bits;
    unsigned char byte;
} HW_RegisterB;

HW_Register regA;
HW_RegisterB regB;

union
{
  int i;
  float f;
  struct {
        unsigned char b15:1; // default 1 bit valued 0
        unsigned char b14:1;      
        unsigned char b13:1;
        unsigned char b12:1;
        
        unsigned char b11:1;         
        unsigned char b10:1;          
        unsigned char b9:1;          
        unsigned char b8:1;    
                 
        unsigned char b7:1; // default 1 bit valued 0
        unsigned char b6:1;      
        unsigned char b5:1;
        unsigned char b4:1;
        
        unsigned char b3:1;         
        unsigned char b2:1;          
        unsigned char b1:1;          
        unsigned char b0:1;                          
  } bits;
} u;

// int that is 16 bit long. to retrieve the higher 8 bits and the lower 8 bits when I need to read from/store to EEPROM:
union {
    int data;
    struct {
        unsigned char higher;
        unsigned char lower;
    } parts;
} data; // doesn't require shifting so the code is easier to read.


struct _mydata {
    int which_one;
    union _data {
            int a;
            float b;
            char c;
    } foo;
} bar;



/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
// Unions are useful in Embedded programming or in situations where direct access to the hardware/memory is needed.
int test_usage_union_for_bit_byte_access_in_packed_form()
{
	INFO(">> ");
	
	printf( "Memory size occupied by item : %d\n", sizeof(struct item)); // 4 if union is used, 6 if only struct is used (akin __packed__). Check statement (a) and (b)
	
	regA.dword = 0x12345678;
    regA.bytes.byte3 = 4;
    regB.bits.b2 = 0;

    int x = regB.bits.b2;   // access directly a single bit in the register/memory address:    
    printf( "x : %d\n", x); // x : 0
    
    regB.bits.b2 = 1;
    x = regB.bits.b2;
    printf( "x : %d\n", x); // x : 1
	
	// Union for access of different data format - as they share the same memory space, ie. if only 1 of the either is assigned, the unassigned shares the same memory space, hence, when either of the forms are called, they are seen in different representations
	
	// if only 1 of them is assigned, they share the same memory space
	// Convert floating-point bits to integer:
	u.f = 3.14159f;
	printf("As integer: %08x\n", u.i);

	printf("The 2nd and 3rd byte (in bits is): %d%d%d%d %d%d%d%d\n", u.bits.b15, u.bits.b14, u.bits.b13, u.bits.b12, u.bits.b11, \
                                                              u.bits.b10, u.bits.b9, u.bits.b8);
	printf("Last 2 bytes (in bits is): %d%d%d%d %d%d%d%d\n", u.bits.b7, u.bits.b6, u.bits.b5, u.bits.b4, \
															u.bits.b3, u.bits.b2, u.bits.b1, u.bits.b0);
   
/*
[xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx] : integer (32-bits)
[xxxx xxxx xxxx xxxx xxxx xxxx xxxx xxxx] : float (32-bits)
[#### #### #### #### xxxx xxxx xxxx xxxx] : struct char bits (32-bits)
// all shares the same 32-bits space
As integer: 40490fd0
// This is a big endian, hence, for 0x0fd0 = 0000 1111 1101 0000, it is as follows
The 2nd and 3rd byte (in bits is): 0000 1011
Last 2 bytes (in bits is): 1111 0000
*/   

	data.data = 0xfead;
	
 	printf("data_part.higher: %x, data_part.lower: %x\n", data.parts.higher, data.parts.lower); 


	enum choice { INTEGER=0, FLOATING, CHARACTER };
	
	struct _mydata *bar_form = malloc(sizeof (*bar_form));
	// bar_form->which_one = 1;
	//bar_form->foo.a = 11;
	bar_form->foo.b = 22.22;
	bar_form->foo.a = 65;

	//bar_form->foo.c = 'z';
	
	bar.which_one = 2;
	
	// printf("%d \n", sizeof (struct _mydata));
	printf("choice: %d \n", bar.which_one);
	
	switch (bar.which_one)
	{
	case INTEGER  :  printf("INTEGER: %d -\n", bar_form->foo.a);
		/* access bar.foo.a;*/ 
		break;
		
	case FLOATING :  printf("%f \n", bar_form->foo.b);
		/* access bar.foo.a;*/ 
		break;
	case CHARACTER:  printf("%c \n", bar_form->foo.c);
		/* access bar.foo.a;*/ 
		break;
	}

	
    printf("\n");    

	printf("%s\n", DEMARCATOR_STRING);
}

/* 
struct Vector{
    double* x;
    int n;
};

struct Vector *y = malloc(sizeof *y); 
y->x = calloc(10, sizeof *y->x);

struct Vector *newVector (size_t sz) {
    // Try to allocate vector structure.

    struct Vector *retVal = malloc (sizeof (struct Vector));
    if (retVal == NULL)
        return NULL;

    // Try to allocate vector data, free structure if fail.

    retVal->data = malloc (sz * sizeof (double));
    if (retVal->data == NULL) {
        free (retVal);
        return NULL;
    }

    // Set size and return.

    retVal->size = sz;
    return retVal;
}

void delVector (struct Vector *vector) {
    // Can safely assume vector is NULL or fully built.

    if (vector != NULL) {
        free (vector->data);
        free (vector);
    }
}
 */
