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
  
struct StackNode { 
    int data; 
    struct StackNode* next; 
}; 

struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 

/*
==================================================
============= || USAGE FUNCTIONS || ==============
==================================================
*/
// int test_usage_check_data_format(void);
int test_usage_00(void);
int test_usage_01(void);

/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
// using singly linked-list
struct StackNode* newNode(int data); 
int isEmpty_stack_linked_list(struct StackNode* root);
void push_stack_linked_list(struct StackNode** root, int data);
int pop_stack_linked_list(struct StackNode** root);
int peek_stack_linked_list(struct StackNode* root);

// using struct pointer
int isFull(struct Stack* stack);
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack);
// add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item);
// remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack);
// return the top from stack without removing it 
int peek(struct Stack* stack);



