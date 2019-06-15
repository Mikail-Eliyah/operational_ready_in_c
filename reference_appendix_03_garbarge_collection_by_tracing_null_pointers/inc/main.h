#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h> 
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

#include <ctype.h>
#include <getopt.h>

/*
==================================================
============= || DEFINE CONSTANTS || =============
==================================================
*/
#define TRUE 1
#define FALSE 0

// Set modes and status using directives to deviate options
// Tagging comments to dis/en-able code for different configuration
#define OFF 0
#define ON 1

#define OPERATION_STATUS ON 

#define PI 3.14159265
#define DEMARCATOR_STRING "==========================================================="

#define INFO(msg) \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING); \
    fprintf(stderr, "[info]:\n<file>: %s \n<function>:%s \n<line>: %d\n", __FILE__, __FUNCTION__, __LINE__); \
    fprintf(stderr, "%s\n", msg); \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING);
	
#define ANNOUNCE_FUNCTION_CALLED() \
	fprintf(stderr, "[invoke]:\n<file>: %s \n<function>:%s \n<line>: %d\n", __FILE__, __FUNCTION__, __LINE__); \
	fprintf(stderr, "%s\n", DEMARCATOR_STRING);
	
#define LINE_NUMBER_OF_WHICH_CODE_FILE fprintf(stderr,"[LOG] %s:%d\n",__FILE__,__LINE__);
	
/*
==================================================
=============== || DEFINE TYPES || ===============
==================================================
*/
  typedef unsigned int uint32;
  // typedef unsigned int size_t;
  
  // static to ensure 1 copy as mutiple references in lib
  volatile static struct list_PointerRegistries {
	int *ptr;
	struct list_PointerRegistries *next;
	} *list = (struct list_PointerRegistries *)0;

/*
==================================================
============= || USAGE FUNCTIONS || ==============
==================================================
*/
int test_usage_garbage_collection_by_markings_of_null_pointers(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
// add delete entry function
/* delete: delete an entry from the list */
void delete(int index);

// set entry to NULL
/* set an entry as index'ed to NULL on the list */
void setToNull(int index);

// remove NULL entries
// remove entries marked as NULL from the list 
void removeNull_entries();

/* dump: dump the list */
void dump(void);



