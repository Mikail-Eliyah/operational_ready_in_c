#include "main.h"

// global variables
#define ARGUMENT_KEY_POSITION 2
#define MAX 20

int display_N_values_per_line = 20;


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
// example of garbage collection by markings of null pointers
int test_usage_garbage_collection_by_markings_of_null_pointers()
{
	INFO(">> ");
	
	int i;   
    
    struct list_PointerRegistries *pointerRecord;

	// initializing pointer registries by giving index tags. NULL tags (index value 0) is consider null pointer
    for (i=0; i<MAX; i++) {
       pointerRecord = malloc(sizeof(struct list_PointerRegistries)); 
    
		if (pointerRecord == 0) {
			fprintf(stderr, "malloc failed\n");
			exit(1);
		}
		
		/* set the data in the list element */
		pointerRecord->ptr = i; 
		pointerRecord->next = list;
		
		printf("Assigned value %d to [pointerRecord->ptr]\n", pointerRecord->ptr);

		/* we have a new head of the list */
		list = pointerRecord;
    }
        
	printf("dump the list: \n");	
    dump();
        
    for (i=0; i<MAX; i++) {
		if (i%2 == 0)     // set even indices to NULL
			setToNull(i); 
    }           
        
	dump();
        
    removeNull_entries();
    dump();
        
    removeNull_entries();
    dump();        
        
    printf("DONE\n");

/*
pointer point to value: "9"
pointer point to value: "8"
pointer point to value: "7"
pointer point to value: "6"
pointer point to value: "5"
pointer point to value: "4"
pointer point to value: "3"
pointer point to value: "2"
pointer point to value: "1"
pointer point to value: NULL.
There are 10 items.

Set pointer index "0" to NULL.
Set pointer index "2" to NULL.
Set pointer index "4" to NULL.
Set pointer index "6" to NULL.
Set pointer index "8" to NULL.
pointer point to value: "9"
pointer point to value: NULL.
pointer point to value: "7"
pointer point to value: NULL.
pointer point to value: "5"
pointer point to value: NULL.
pointer point to value: "3"
pointer point to value: NULL.
pointer point to value: "1"
pointer point to value: NULL.
There are 10 items.

Removing NULL pointer index.
Removing NULL pointer index.
Removing NULL pointer index.
Removing NULL pointer index.
Removing NULL pointer index.

pointer point to value: "9"
pointer point to value: "7"
pointer point to value: "5"
pointer point to value: "3"
pointer point to value: "1"
There are 5 items.

NULL pointer index not found.

pointer point to value: "9"
pointer point to value: "7"
pointer point to value: "5"
pointer point to value: "3"
pointer point to value: "1"
There are 5 items.

DONE
*/


	printf("%s\n", DEMARCATOR_STRING);
}
