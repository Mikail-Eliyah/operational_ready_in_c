#include "main.h"

// global variables



/*
==================================================
============= || LOCAL STRUCTS || ==============
==================================================
*/

struct profileOfUrsa {
     int ID;
     int crewManpower;
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
int test_usage_struct_04()
{
	INFO(">> ");

    struct profileOfUrsa profile_Address;    // initiate an instance (allocate memory)
    void* profileRetriever;                          // local holder, which is a pointer (may be an argument of a function)
       
    profileRetriever = &profile_Address;      // pass the specific address of the allocated structure and space to the pointer
    profile_Address.ID = 1111;                   // set a value
    profile_Address.ID++;                         // change the value
    
    // format the designated pointer with a struct form(at), 'casting' the pointer
    struct profileOfUrsa *profileRetriever_ptr = (struct profileOfUrsa *) profileRetriever;
    // retrieve the data    
    printf(" Struct contents: %d \n", (profileRetriever_ptr->ID)); // use designated pointer
    printf(" Struct contents: %d \n", (*profileRetriever_ptr).ID);  // use designated pointer
    printf(" Struct contents: %d \n", profile_Address.ID); // use specific address

	profileRetriever_ptr->ID = 1110111;     // reassign another ID
 

	printf(" Struct contents: %d \n", (profileRetriever_ptr->ID)); // use designated pointer
	
	printf("%s\n", DEMARCATOR_STRING);
}	
