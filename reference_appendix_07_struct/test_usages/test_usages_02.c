#include "main.h"

// global variables



/*
==================================================
============= || LOCAL STRUCTS || ==============
==================================================
*/
#define testFunction(intensity, dir) \
    { \
      .force        = intensity, \
      .direction    = dir, \
    }

struct configureObject {
  int   force;
  char direction[7];
};

static const struct configureObject configureFiles[] =
{
  testFunction(45, UP),
  testFunction(46, DOWN),
};

static const struct configureObject configureFiles_2[] = 
{
  { .force = 4, .direction = UP },
  { .force = 40, .direction = DOWN },
  { .force = 400, .direction = UP },
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
// Struct Array with using #define for a setting function
int test_usage_struct_03()
{
	INFO(">> ");

int i;
int numberOfElementsInStructArray;
numberOfElementsInStructArray = (sizeof(configureFiles)/sizeof(struct configureObject));
        printf("Number of element in struct array: %d\n", numberOfElementsInStructArray);    
    
    for (i=0;i<numberOfElementsInStructArray;i++) {
    
        printf("force: %d\n", configureFiles[i].force);
        printf("direction: %s\n", configureFiles[i].direction);        
        }
        
  /*
Number of element in struct array: 2
force: 45
direction: UP
force: 46
direction: DOWN  
  */

numberOfElementsInStructArray = (sizeof(configureFiles)/sizeof(struct configureObject));
        printf("Number of element in struct array: %d\n", numberOfElementsInStructArray);    
    
    for (i=0;i<numberOfElementsInStructArray;i++) {
    
        printf("force: %d\n", configureFiles[i].force);
        printf("direction: %s\n", configureFiles[i].direction);        
        }
numberOfElementsInStructArray = (sizeof(configureFiles_2)/sizeof(struct configureObject));

        printf("Number of element in struct array: %d\n", numberOfElementsInStructArray);    
    
    for (i=0;i<numberOfElementsInStructArray;i++) {
    
        printf("force: %d\n", configureFiles_2[i].force);
        printf("direction: %s\n", configureFiles_2[i].direction);        
        }
        
  /*
Number of element in struct array: 2
force: 45
direction: UP
force: 46
direction: DOWN
Number of element in struct array: 3
force: 4
direction: UP
force: 40
direction: DOWN
force: 400
direction: UP
  */    

	
	printf("%s\n", DEMARCATOR_STRING);
}	
