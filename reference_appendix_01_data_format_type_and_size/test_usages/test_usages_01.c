#include "main.h"

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


/*
==================================================
============== || LOCAL STRUCTS || ===============
==================================================
*/
struct Vector
{
    char *input;
    unsigned char len;
};

// static 
struct Vector tv2 =
{
    .input = "\x6b\xc1\xbe\xe2\x2e\x40\x9f\x96"
             "\xe9\x3d\x7e\x11\x73\x93\x17\x2a"
             "\xae\x2d\x8a\x57\x1e\x03\xac\x9c"
             "\x9e\xb7\x6f\xac\x45\xaf\x8e\x51"
             "\x30\xc8\x1c\x46\xa3\x5c\xe4\x11"
             "\xe5\xfb\xc1\x19\x1a\x0a\x52\xef"
             "\xf6\x9f\x24\x45\xdf\x4f\x9b\x17"
             "\xad\x2b\x41\x7b\xe6\x6c\x37\x10",
    .len = 64,
};


/*
==================================================
================ || LOCAL DATA || ================
==================================================
*/
static unsigned char  PlainText[] = {
    0xBA, 0xC1, 0xBE, 0xE2, 0x2E, 0x40, 0x9F, 0x96,
    0xE9, 0x3D, 0x7E, 0x11, 0x73, 0x93, 0x17, 0x2A,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17,
    0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f,
    0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
    0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f,
    0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
    0x38, 0x39, 0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f,
    0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47,
    0x48, 0x49, 0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57,
    0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f,
    0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
    0x68, 0x69, 0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f,
    0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77,
    0x78, 0x79, 0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f,
};


    static char *check[] = {
          "des", "md5", "des3_ede", "rot13", "sha1", "sha224", "sha256",
          "blowfish", "twofish", "serpent", "sha384", "sha512", "md4", "aes",
          "cast6", "arc4", "michael_mic", "deflate", "crc32c", "tea", "xtea",
          "khazad", "wp512", "wp384", "wp256", "tnepres", "xeta",  "fcrypt",
          "camellia", "seed", "salsa20", "rmd128", "rmd160", "rmd256", "rmd320",
          "lzo", "cts", "zlib", NULL
     }; // 38 items, excluding NULL



/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
static inline int hexit(const unsigned char c)
{
    static const char hex_digits[] = "0123456789ABCDEF";
    return strchr(hex_digits, toupper(c)) - hex_digits;
}

static void print(unsigned char *text_addr, unsigned int size)
{
    unsigned int i;

    for (i = 0; i < size; i++)
    {
        printf("%2x ", text_addr[i]);
        if ((i & 0xf) == 0xf)
            printf("\n");
    }
    printf("\n");
}

static void print2(const char *tag, const unsigned char *data, size_t size)
{
    printf("%s:\n", tag);
    for (size_t i = 0; i < size; i++)
    {
        printf("%2x ", data[i]);
        if ((i & 0x0F) == 0x0F)
            printf("\n");
    }
    printf("\n");
}


static void print_text_00 (const char *tag, const char *data, size_t datalen)
{
    char buffer[datalen / 2];

    assert(datalen % 2 == 0);

    for (size_t i = 0; i < datalen; i += 2)
        buffer[i / 2] = hexit(data[i]) << 4 | hexit(data[i + 1]);

    //printf("%s: [[%.*s]]\n", tag, (int)datalen / 2, buffer);
    assert(memcmp(buffer, tv2.input, tv2.len) == 0);
    print((unsigned char *)buffer, datalen / 2);
    print2(tag, (unsigned char *)buffer, datalen / 2);
}

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_display_data_00(){
	INFO(">> ");
	unsigned char *vbuf_src;
	vbuf_src = malloc(0x100); // 256 size
	unsigned char *data_src;

	data_src = &PlainText[0];
	int len = 152;
	int offset = 0;

	memset(&vbuf_src[0], 0xFF, 0x100);
	memcpy(&vbuf_src[0], data_src, len);

	print_text("\nOriginal data src", &vbuf_src[0] + offset,  len);   
	
	printf("%s\n", DEMARCATOR_STRING);
	
	// Number of elements in the string array

    char *stringBytes_Data =
        "6bc1bee22e409f96e93d7e117393172a"
        "ae2d8a571e03ac9c9eb76fac45af8e51"
        "30c81c46a35ce411e5fbc1191a0a52ef"
        "f69f2445df4f9b17ad2b417be66c3710"
    ;

    print_text_00("buffer", stringBytes_Data, strlen(stringBytes_Data));
	
	
	printf("%s\n", DEMARCATOR_STRING);
	
    char **algo = check;
    int numberOfAlgo = 0;

    while (SAME != strcmp(algo[numberOfAlgo], NULL)) {
        printf("Algo: %s \n", algo[numberOfAlgo++]);
    }

    printf("There are %d algos in the check list. \n", numberOfAlgo);

/*
output:
    Algo: des 
       :
       :
    Algo: zlib 
    There are 38 algos in the check list.
// Alternatively, if you do not want to use the <b> NULL </b>, do this instead:
*/
    numberOfAlgo = 0;

    while (*algo) {
        printf("Algo: %s \n", *algo);
        algo++; // go to the next item
        numberOfAlgo++; // count the item
    }

    printf("There are %d algos in the check list. \n", numberOfAlgo);
	
	printf("%s\n", DEMARCATOR_STRING);
}	
