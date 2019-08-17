#include "main.h"


/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/
//
// using singly linked-list
// 
struct StackNode* newNode(int data) 
{ 
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode)); 
    stackNode->data = data; 
    stackNode->next = NULL; 
    return stackNode; 
} 
  
int isEmpty_stack_linked_list(struct StackNode* root) 
{ 
    return !root; 
} 
  
void push_stack_linked_list(struct StackNode** root, int data) 
{ 
    struct StackNode* stackNode = newNode(data); 
    stackNode->next = *root; 
    *root = stackNode; 
    printf("%d pushed to stack\n", data); 
} 
  
int pop_stack_linked_list(struct StackNode** root) 
{ 
    if (isEmpty_stack_linked_list(*root)) {
		printf("Stack is empty\n");
        return NULL; 
		// return INT_MIN;
	} 
	
    struct StackNode* temp = *root; 
    *root = (*root)->next; 
    int popped = temp->data; 
    free(temp); 
  
    return popped; 
} 
  
int peek_stack_linked_list(struct StackNode* root) 
{ 
    if (isEmpty_stack_linked_list(root)) {
		printf("Stack is empty\n");
        return NULL; 
		// return INT_MIN;
	} 	
    return root->data; 
} 

//
// using struct pointer
// 

// create a stack of given capacity. It initializes size of  stack as 0 
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
	
	printf("create stack, top is %d \n", stack->top);
	
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
	
	// stack->array[++stack->top] = 111;
	// printf("content insert test: %d \n", stack->array[stack->top]);

	if (stack->array == NULL)
		printf("stack malloc fails. \n");
	else
		printf("stack malloc OK. \n");
	
    return stack; 
} 

// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
	printf("index %d\n", (stack->top));
    return stack->top == stack->capacity - 1; 
} 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{ 
	printf("checking stack. \n");
	if (stack->array == NULL)
		printf("stack missing. \n");
	else
		printf("stack exist. \n");
	
	printf("index %d\n", stack->top);
    return stack->top == -1; 
} 
  
// add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
	printf("status %d\n", isFull(stack));
    if (isFull(stack)) 
        return; 
	printf("%d pushing \n", item);
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
  
// remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) {
		printf("Stack is empty\n");
        return NULL; 
		// return INT_MIN;
	} 
	
    return stack->array[stack->top--]; 
} 
  
// return the top from stack without removing it 
int peek(struct Stack* stack) 
{ 
    if (isEmpty(stack)) {
		printf("Stack is empty\n");
        return NULL; 
		// return INT_MIN;
	} 	
    return stack->array[stack->top]; 
} 



