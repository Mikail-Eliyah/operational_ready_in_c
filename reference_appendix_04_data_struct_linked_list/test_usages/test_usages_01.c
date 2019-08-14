#include "main.h"

#define MAXLEN 128

/*
==================================================
============= || LOCAL STRUCT(S) || ==============
==================================================
*/
// static struct statically named as 'list'
struct list_entry {
	char *data;
	struct list_entry *next;
} *list = (struct list_entry *) 0; // statically create struct named as 'list'
 
/*
==================================================
============= || LOCAL FUNCTIONS || ==============
==================================================
*/   
void display_items_of_local_linked_list(void) {
	struct list_entry *lp;
	int counter = 0;
	// last-in-first-out

	for (lp = list; lp != 0; lp=lp->next) {
		printf("item: \"%s\"\n", lp->data);
		counter++;
    }
	printf("There are %d items.\n", counter);       
}

// add delete entry function
/* delete: delete an entry from the list */
void delete(char *s) {
struct list_entry *current, *last = 0;
for (current = list; current != 0; last = current, current=current->next)
if (strcmp(current->data, s) == 0) {
printf("deleting \"%s\"\n", s);
if (last != 0) /* not the first entry */
last->next = current->next;
else
list = current->next; /* change head of list */
free(current->data);
free(current);
return;
}
printf("\"%s\" not found\n", s);
}


/*
=====================================================================
============= || USAGE FUNCTIONS FOR EXTERNAL CALLS || ==============
=====================================================================
*/

int test_usage_singly_linked_list_static_object()
{
	INFO(">> ");
	
	char text[] = "00 11 22 33 44      55 66 77 ";
	char delimitChar[2] = " "; // includes "\0". Can have > 1 character, any of it will be part of a delimiter list, eg. "-+"
	int numberOfTokens = 0;
	char *t;
	int i;
	char *s, line[MAXLEN];
	struct list_entry *item;

    t = strtok(text, delimitChar);
    
	while (t != NULL) { /* read until EOF
		/* allocate a new list element */
		item = malloc(sizeof(struct list_entry));

		if (item == 0) {
			fprintf(stderr, "malloc failed\n");
			exit(1);
		}

		/* set the data in the list element */
		item->data = strdup(t); // copy the string 
		item->next = list;

		/* we have a new head of the list */
		list = item;
		// continue 
		t = strtok(NULL, delimitChar);
	}
	
	display_items_of_local_linked_list(); // 
	
	int *ptr;
	ptr = (int*) list;
	
	printf("ptr %p \n", ptr);
	
	delete("33");
    display_items_of_local_linked_list();
    
    delete("33");
    display_items_of_local_linked_list();

	
	printf("%s\n", DEMARCATOR_STRING);
}	
