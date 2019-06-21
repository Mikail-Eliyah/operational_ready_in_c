#include "main.h"

// global variables
#define ARGUMENT_KEY_POSITION 2

int display_N_values_per_line = 20;

/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/
/* Given a binary tree, print its nodes according to the 
  "bottom-up" postorder traversal. 

   1. Traverse the left subtree, i.e., call Postorder(left-subtree)
   2. Traverse the right subtree, i.e., call Postorder(right-subtree)
   3. Visit the root.
  */
void printPostorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 

     printPostorder(node->left); // first recur on left subtree 
     printPostorder(node->right); // then recur on right subtree 
     printf("%d ", node->data); // now deal with the node
} 
  
/* Given a binary tree, print its nodes in inorder

   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)
*/
void printInorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 

     printInorder(node->left); /* first recur on left child */
     printf("%d ", node->data);   /* then print the data of node */
     printInorder(node->right); /* now recur on right child */
} 
  
/* Given a binary tree, print its nodes in preorder

   1. Visit the root.
   2. Traverse the left subtree, i.e., call Preorder(left-subtree)
   3. Traverse the right subtree, i.e., call Preorder(right-subtree) 
*/
void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 

     printf("%d ", node->data);   /* first print data of node */
     printPreorder(node->left);   /* then recur on left sutree */
     printPreorder(node->right); /* now recur on right subtree */
}     

/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/
int test_usage_binary_tree()
{
	INFO(">> ");
	
	int values[] = {1, 2, 3, 4, 5};

  struct node *root = create_newNode(values[0]);   	/*create root*/
  /* following is the tree after above statement  
  
        1 
      /   \ 
     NULL  NULL   
  */
   
  root->left        = create_newNode(values[1]); 
  root->right       = create_newNode(values[2]); 
  /* 2 and 3 become left and right children of 1 
           1 
         /   \ 
        2      3 
     /    \    /  \ 
    NULL NULL NULL NULL 
  */
  
  
  root->left->left  = create_newNode(values[3]); 
  /* 4 becomes left child of 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    NULL  NULL  NULL 
  /  \ 
NULL NULL 
*/

	root->left->right   = create_newNode(values[4]);
  /* 5 becomes right child of 2 
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    5     NULL  NULL 
  /  \ 
NULL NULL 
*/	

	 printf("\nPreorder traversal of binary tree is \n"); 
     printPreorder(root); 
  
     printf("\nInorder traversal of binary tree is \n"); 
     printInorder(root);   
  
     printf("\nPostorder traversal of binary tree is \n"); 
     printPostorder(root); 
	 
	int key_to_search_for = 4; 
  
    if (ifNodeExists(root, key_to_search_for)) 
        printf("\nkey: %d exists\n", key_to_search_for);
    else
        printf("\nkey: %d do not exists\n", key_to_search_for);
	
	key_to_search_for = 10; 
  
    if (ifNodeExists(root, key_to_search_for)) 
        printf("\nkey: %d exists\n", key_to_search_for);
    else
        printf("\nkey: %d do not exists\n", key_to_search_for);
	
	key_to_search_for = 30;
	insert(root, key_to_search_for); 
	
	printf("\nPreorder traversal of binary tree is \n"); 
    printPreorder(root); 
	
	struct node* node_found = search(root, key_to_search_for);
	
	if(node_found != NULL)
		printf("\nnode_data_found: %d \n", node_found->data); 
	else
		printf("\nnode_data_found: %d NOT_FOUND \n", key_to_search_for);  
	
	root = deleteNode(root, key_to_search_for); 
	
	node_found = search(root, key_to_search_for);
	
	if(node_found != NULL)
		printf("\nnode_data_found: %d \n", node_found->data); 
	else
		printf("\nnode_data_found: %d NOT_FOUND \n", key_to_search_for); 

	printf("%s\n", DEMARCATOR_STRING);
}
