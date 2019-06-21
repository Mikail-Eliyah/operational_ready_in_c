#include "main.h"

// global variables
#define ARGUMENT_KEY_POSITION 2
#define LINKED_LIST_CONNECT_SYMBOL	"->"

int display_N_values_per_line = 20;

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
// prints contents of linked list starting from the given node 
void printList_for_Node_of_singly_linked_list(struct Node_of_singly_linked_list *n) 
{ 
  while (n != NULL) 
  { 
     printf(" %d %s", n->data, LINKED_LIST_CONNECT_SYMBOL); 
     n = n->next; 
  } 
  
  printf(" NULL\n"); 
} 

// prints contents of linked list starting from the given node  
void printList_for_Node_of_doubly_linked_list(struct Node_of_doubly_linked_list* node)  
{  
    struct Node_of_doubly_linked_list* last; 
		
    printf("\nTraversal in forward direction \n");  
    while (node != NULL) {  
        printf(" %d %s", node->data, LINKED_LIST_CONNECT_SYMBOL);  
        last = node;  
        node = node->next;  
    }  
	
	printf(" NULL\n");
  
    printf("\nTraversal in reverse direction \n");  
    while (last != NULL) {  
        printf(" %d %s", last->data, LINKED_LIST_CONNECT_SYMBOL);  
        last = last->prev;  
    }  
	
	printf(" NULL\n");  
}  

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
int test_usage_singly_linked_list()
{
	INFO(">> ");
	
	// create a simple linked list with 3 nodes 
  struct Node_of_singly_linked_list* head = NULL;
  struct Node_of_singly_linked_list* second = NULL;
  struct Node_of_singly_linked_list* third = NULL; 
    
  // allocate 3 nodes in the heap   
  head = (struct Node_of_singly_linked_list*)malloc(sizeof(struct Node_of_singly_linked_list));  
  second = (struct Node_of_singly_linked_list*)malloc(sizeof(struct Node_of_singly_linked_list)); 
  third = (struct Node_of_singly_linked_list*)malloc(sizeof(struct Node_of_singly_linked_list)); 
  
  /* 3 blocks have been allocated dynamically.  
     We have pointers to these 3 blocks as first, second and third      
       head           second           third 
        |                |               | 
        |                |               | 
    +---+-----+     +----+----+     +----+----+ 
    | #  | #  |     | #  | #  |     |  # |  # | 
    +---+-----+     +----+----+     +----+----+ 
     
   # represents any random value. Data is random because they are unassigned */
    
  head->data = 1; //assign data in first node 
  head->next = second; // Link first node with the 2nd node 
  
  /* data has been assigned to data part of 1st block (block pointed by head). And next pointer of 1st block points to second. So they both are linked. 
  
       head          second         third 
        |              |              | 
        |              |              | 
    +---+---+     +----+----+     +-----+----+ 
    | 1  | o----->| #  | #  |     |  #  | #  | 
    +---+---+     +----+----+     +-----+----+     
  */  

  second->data = 2;  // assign data to second node  
  second->next = third; // Link second node with the third node 
    
  /* data has been assigned to data part of second block (block pointed by second). And next pointer of the 2nd block points to third block. So all 3 blocks are linked. 
    
       head         second         third 
        |             |             | 
        |             |             | 
    +---+---+     +---+---+     +----+----+ 
    | 1  | o----->| 2 | o-----> |  # |  # | 
    +---+---+     +---+---+     +----+----+      */    
    
  third->data = 3; //assign data to third node 
  third->next = NULL; 
    
  /* data has been assigned to data part of third block (block pointed by third). And next pointer of the third block is made NULL to indicate that the linked list is terminated here. 
  
  We have the linked list ready.   
  
           head     
             | 
             |  
        +---+---+     +---+---+       +----+------+ 
        | 1  | o----->|  2  | o-----> |  3 | NULL | 
        +---+---+     +---+---+       +----+------+        
    
    Note: only head is sufficient to represent the whole list.  We can traverse the complete list by following next pointers.    */  
	
	printList_for_Node_of_singly_linked_list(head); 
	
	struct Node_of_singly_linked_list* head_00 = NULL; 	/* Start with the empty list */
	
	int values[] = {6, 7, 1, 4};
	int length_of_array = sizeof(values)/sizeof(values[0]);
	
	for (int i = 0; i < length_of_array; i++){
		append_for_Node_of_singly_linked_list(&head_00, values[i]);
	}
	
	printList_for_Node_of_singly_linked_list(head_00);

	int value_to_search_for = 21;
	search_iterative_for_Node_of_singly_linked_list(head_00, value_to_search_for)? printf("%d found.\n", value_to_search_for) : printf("%d not found.\n", value_to_search_for); 
	
	value_to_search_for = 7;
	search_iterative_for_Node_of_singly_linked_list(head_00, value_to_search_for)? printf("%d found.\n", value_to_search_for) : printf("%d not found.\n", value_to_search_for); 
	
	value_to_search_for = 21;
	search_recursive_for_Node_of_singly_linked_list(head_00, value_to_search_for)? printf("%d found.\n", value_to_search_for) : printf("%d not found.\n", value_to_search_for); 
	
	value_to_search_for = 7;
	search_recursive_for_Node_of_singly_linked_list(head_00, value_to_search_for)? printf("%d found.\n", value_to_search_for) : printf("%d not found.\n", value_to_search_for); 

	printf("%s\n", DEMARCATOR_STRING);
}

int test_usage_doubly_linked_list()
{
	INFO(">> ");
    struct Node_of_doubly_linked_list* head = NULL; 	/* Start with the empty list */
	
	/*
    1. insert 6: 6->NULL 
	2. insert 7 at the beginning: 7->6->NULL 
    3. insert 1 at the beginning: 1->7->6->NULL 
    4. insert 4 at the end: 1->7->6->4->NULL 
    5. insert 8, after 7: 1->7->8->6->4->NULL 
	*/
	
	int values[] = {6, 7, 1, 4};
	int length_of_array = sizeof(values)/sizeof(values[0]);
	
	for (int i = 0; i < length_of_array; i++){
		append_for_Node_of_doubly_linked_list(&head, values[i]);
	}
	
	insertAfter_for_Node_of_doubly_linked_list(head->next, 8); 
	
	printf("%s\n", DEMARCATOR_STRING);
  
	printf("Doubly linked list before deletion\n"); 
    printList_for_Node_of_doubly_linked_list(head); 
	
    int deleteNodeAtPosition = 2; 
  
    /* delete node at the given position 'n' */
    deleteNodeAtGivenPosition_for_Node_of_doubly_linked_list(&head, deleteNodeAtPosition); 
  
    printf("Doubly linked list after deletion at index %d\n", deleteNodeAtPosition);
    printList_for_Node_of_doubly_linked_list(head); 
	
	int value_to_search_for = 21;
	search_iterative_for_Node_of_doubly_linked_list(head, value_to_search_for)? printf("%d found.\n", value_to_search_for) : printf("%d not found.\n", value_to_search_for); 
	
	value_to_search_for = 8;
	search_iterative_for_Node_of_doubly_linked_list(head, value_to_search_for)? printf("%d found.\n", value_to_search_for) : printf("%d not found.\n", value_to_search_for); 
	
	value_to_search_for = 21;
	search_recursive_for_Node_of_doubly_linked_list(head, value_to_search_for)? printf("%d found.\n", value_to_search_for) : printf("%d not found.\n", value_to_search_for); 
	
	value_to_search_for = 8;
	search_recursive_for_Node_of_doubly_linked_list(head, value_to_search_for)? printf("%d found.\n", value_to_search_for) : printf("%d not found.\n", value_to_search_for); 
	
	printf("%s\n", DEMARCATOR_STRING);
}