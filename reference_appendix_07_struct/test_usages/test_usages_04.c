#include "main.h"

// global variables



#define ARGUMENT_CIPHERMODE_POSITION    1
#define ENCRYPT_mode "aes\0"


/*
==================================================
============= || LOCAL STRUCTS || ==============
==================================================
*/

struct profileOfUrsa {
     int ID;
     int crewManpower;
 };

struct command {
     char stringMode[4];
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

int test_usage_struct_memcpy(int argc, char *argv[])
{
	INFO(">> ");
    struct command sendCommand;
    
    char mode[10];    
    printf("---------------------------\n");

    memcpy((sendCommand.stringMode), argv[ARGUMENT_CIPHERMODE_POSITION], 4);  
	// memcpy((sendCommand.stringMode), "aes", 4);
	
    printf("%s\n", (sendCommand.stringMode));
    memcpy(mode, (sendCommand.stringMode), 4);
    printf("%s\n", mode);
    
    //memset(mode, 0, sizeof mode);
    mode[0] = '\0';    // clear string
    memcpy(mode, ENCRYPT_mode, strlen(ENCRYPT_mode)); // 
    mode[strlen(ENCRYPT_mode)] = '\0';
    
    mode[0] = '\0';    // clear string
    memcpy(mode, "012345678", strlen("012345678")); // no null char to append yet, hence strlen() has no +1
    mode[strlen("012345678")] = '\0';
    
    printf("%20s                 %10d\n", mode, strlen(mode));
    mode[strlen("01234")] = '\0';
    printf("%20s                 %10d\n", mode, strlen(mode));
    
    mode[0] = '\0';    // clear string
    memcpy(mode, ENCRYPT_mode, strlen(ENCRYPT_mode)); // no null char to append yet, hence strlen() has no +1
    mode[strlen(ENCRYPT_mode)] = '\0';
    
    if (strcmp(mode, argv[ARGUMENT_CIPHERMODE_POSITION]) == 0 ) { // argv[ARGUMENT_CIPHERMODE_POSITION] = "aes"
           printf("SAME\n");              
    } else {
           printf("DIFFERENT\n"); 
    }
    
	printf("input %s\n",argv[1]);

/*
OUTPUT
aes
aes
           012345678                          9
               01234                              5
SAME
input aes
*/
	
	
	printf("%s\n", DEMARCATOR_STRING);
}	