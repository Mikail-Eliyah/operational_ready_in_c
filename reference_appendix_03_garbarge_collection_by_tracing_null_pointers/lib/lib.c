#include "main.h"


/*
=========================================================
============= || SUB-ROUTINES FUNCTIONS || ==============
=========================================================
*/

// add delete entry function
/* delete: delete an entry from the list */
void delete(int index) {
	struct list_PointerRegistries *current, *last = 0;

	for (current = list; current != 0; last = current, current=current->next)
		if ((current->ptr) == index) {
			printf("deleting pointer index \"%d\"\n", index);

			if (last != 0) /* not the first entry */
				last->next = current->next;
			else
				list = current->next; /* change head of list */
				
		free(current->ptr);
		free(current);
		return;
	}

	printf("pointer index: \"%d\" -> not found\n", index);
}

// set entry to NULL
/* set an entry as index'ed to NULL on the list */
void setToNull(int index) {
	struct list_PointerRegistries *current, *last = 0;

	for (current = list; current != 0; last = current, current=current->next)
		if ((current->ptr) == index) {
            printf("Set pointer index \"%d\" to NULL.\n", index);
			(current->ptr) = NULL;
			
			return;
		}
  
	printf("pointer index: \"%d\" -> not found\n", index); 
}

// remove NULL entries
// remove entries marked as NULL from the list 
void removeNull_entries() {
	struct list_PointerRegistries *current, *last = 0;
	
	int found;
	found = 0; 

for (current = list; current != 0; last = current, current=current->next)
if ((current->ptr) == NULL) {
            found = 1;     // HIT
printf("Removing NULL pointer index.\n");
if (last != 0) // not the first entry 
last->next = current->next;
else
list = current->next; // change head of list 
free(current->ptr);
// free(current);
}

if (found == 0) 
  printf("NULL pointer index not found.\n");
  
  return;
}

/* dump: dump the list */
void dump(void) {
	struct list_PointerRegistries *lp;
	int counter = 0;
	
	// last-in-first-out
	for (lp = list; lp != 0; lp=lp->next) {
		if ((lp->ptr) != NULL)
			printf("pointer point to value: \"%d\"\n", lp->ptr);
		else
           printf("pointer point to value: NULL.\n");     
  
		counter++;
    }
  printf("There are %d items.\n", counter);       
}

