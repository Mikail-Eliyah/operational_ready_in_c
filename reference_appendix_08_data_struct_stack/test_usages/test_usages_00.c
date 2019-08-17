#include "main.h"

// global variables
#define ARGUMENT_KEY_POSITION 2

int display_N_values_per_line = 20;


/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/

bool is_number(char* string){
	int num = atoi( string );
 
	if (num == 0 && string[0] != '0'){
		//printf("Not a Number!");
		return false;
	} 
	else {
		//printf("Number is: %i", num);
		return true;
	}
}

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
/* */ 
int test_usage_00()
{
	INFO(">> ");

    struct StackNode* root = NULL; 
	
	char *values[] = {30, 20, 10, 111};
	
	for (int i = 0; i < 4; i++){
		push_stack_linked_list(&root, values[i]); 
	}
  
  	for (int i = 0; i < 3; i++){
		printf("%d popped from stack\n", pop_stack_linked_list(&root)); 
	}
	
	int content = peek_stack_linked_list(root);
	
    if (content == NULL) {
		printf("Stack is empty\n");
	} else {
		printf("Top element is %d\n", content); 
	}
	
    printf("\n");    

	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_01()
{
	INFO(">> ");
	
	struct Stack* stack = createStack(100);
	
	int content = peek(stack);
	
	if (content == NULL) {
		printf("Stack is empty\n");
	} else {
		printf("Top element is %d\n", content); 
	}

	char *values[] = {30, 20, 10, 111};
	
	for (int i = 0; i < 4; i++){
		// push(stack, values[i]); 
		push(stack, 10); 
		printf("OK\n");
	}	
  
	printf("OK\n");
  	for (int i = 0; i < 3; i++){
		printf("%d popped from stack\n", pop(stack)); 
	}
  
	// int content = peek(stack);
	
    if (content == NULL) {
		printf("Stack is empty\n");
	} else {
		printf("Top element is %d\n", content); 
	}
	
    printf("\n");    

	printf("%s\n", DEMARCATOR_STRING);
}

/* */
