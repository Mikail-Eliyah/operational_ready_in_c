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
  typedef unsigned intsize_t;
  
	struct Node_of_singly_linked_list { // A singly linked list node 
		int data; 
		struct Node_of_singly_linked_list *next; 
	}; 
	
	struct Node_of_doubly_linked_list { 	// A doubly linked list node 
		int data; 
		struct Node_of_doubly_linked_list* next; // Pointer to next node in DLL 
		struct Node_of_doubly_linked_list* prev; // Pointer to previous node in DLL 
	};

/*
==================================================
============= || USAGE FUNCTIONS || ==============
==================================================
*/
int test_usage_singly_linked_list(void);
int test_usage_doubly_linked_list(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/

/* Checks whether the value x is present in linked list */
bool search_iterative_for_Node_of_doubly_linked_list(struct Node_of_doubly_linked_list* head, int x);
bool search_recursive_for_Node_of_doubly_linked_list(struct Node_of_doubly_linked_list* head, int x);

bool search_iterative_for_Node_of_singly_linked_list(struct Node_of_singly_linked_list* head, int x);
bool search_recursive_for_Node_of_singly_linked_list(struct Node_of_singly_linked_list* head, int x);

void append_for_Node_of_singly_linked_list(struct Node_of_singly_linked_list** head_ref, int new_data);

/* Given a reference (pointer to pointer) to the head of a list 
   and an int, inserts a new node on the front of the list. */
void push_for_Node_of_doubly_linked_list(struct Node_of_doubly_linked_list** head_ref, int new_data);

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter_for_Node_of_doubly_linked_list(struct Node_of_doubly_linked_list* prev_node, int new_data);

/* Given a reference (pointer to pointer) to the head 
   of a DLL and an int, appends a new node at the end  */
void append_for_Node_of_doubly_linked_list(struct Node_of_doubly_linked_list** head_ref, int new_data);

/* Given a node as next_node, insert a new node before the given node */
void insertBefore_for_Node_of_doubly_linked_list(struct Node_of_doubly_linked_list** head_ref, struct Node_of_doubly_linked_list* next_node, int new_data);

/* Function to delete a node in a Doubly Linked List. 
   head_ref --> pointer to head node pointer. 
   del  -->  pointer to node to be deleted. */
void deleteNode_for_Node_of_doubly_linked_list(struct Node_of_doubly_linked_list** head_ref, struct Node_of_doubly_linked_list* del) ;

/* Function to delete the node at the given position 
   in the doubly linked list */
void deleteNodeAtGivenPosition_for_Node_of_doubly_linked_list(struct Node_of_doubly_linked_list** head_ref, int n) ;