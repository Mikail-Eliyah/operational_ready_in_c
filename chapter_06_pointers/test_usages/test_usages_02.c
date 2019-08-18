#include "main.h"

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
    void array_func_00( char ca[10] )
    {
    printf(" addr of array param = %#x \n",&ca);
    printf(" addr (ca[0]) = %#x \n",&(ca[0]));
    printf(" addr (ca[1]) = %#x \n",&(ca[1]));
    printf(" ++ca = %#x \n\n", ++ca);
    }
	
    void pointer_func_00( char *pa )
    {
    printf(" addr of ptr param = %#x \n",&pa);
    printf(" addr (pa[0]) = %#x \n",&(pa[0]));
    printf(" addr (pa[1]) = %#x \n",&(pa[1]));
    printf(" ++pa = %#x \n", ++pa);
    }

/*
==================================================
============= || LOCAL DATA TYPE || ==============
==================================================
*/

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_passing_array_and_pointer()
{
	INFO(">> ");
    char ga[] = "abcdefghijklm";

    printf(" addr of global array = %#x \n",&ga);
    printf(" addr (ga[0]) = %#x \n",&(ga[0]));
    printf(" addr (ga[1]) = %#x \n\n",&(ga[1]));
    array_func_00( ga );
    pointer_func_00( ga );
    
    // pea[i][j] == *(*(pea+i)+j)
	
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