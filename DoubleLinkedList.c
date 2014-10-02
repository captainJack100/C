/*

	Double linked list example.
	Basic idea of working with lists pointers etc ...

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Define a node
typedef struct ListNode {
	struct ListNode *next;
	struct ListNode *prev;
	void *value;
} ListNode;

// Define a list
typedef struct {
	int count;
	ListNode *first;
	ListNode *last;
} List;

// create a list
List *List_Create() {
	
	return (List *) calloc(1, sizeof(List));

}

// Add new elt to list
void List_Push(List *list, void *value) {
	
	ListNode *node = calloc(1, sizeof(ListNode));
	node->value = value;
	list->count += 1;	

	if (list->last == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->last->next = node;
		node->prev = list->last;
		list->last = node;
	}

}

// Pop elt off
ListNode *List_Pop(List *list) {

	ListNode *tmp = list->first;
	if (list->count > 0)
		list->first = list->first->next;
	else 
		tmp = NULL;

	list->count -= 1;
	return tmp;

}

// print the list out ... when integer
void Print_List(List *list) {

	int i = 0;
	ListNode *myNode = list->first;

	for (i = 0; i < list->count; i++) {
		printf("%d\n", *(int *)myNode->value);
		myNode = myNode->next;
	}	

}

// Clear the list out
void Clear_List(List *list) {

	int i = 0;
	ListNode *tmp;
	int count = list->count;

	for (i = 0; i < count; i++) {
		tmp = List_Pop(list);
		if (tmp != NULL)
			free(tmp);	
	}

}

int main(void) {

	int *a = malloc(sizeof(int));
	*a = 10;
	
	int *b = malloc(sizeof(int));
	*b = 100;

	List *myList = List_Create();
	List_Push(myList, a );
	List_Push(myList, b);

	Print_List(myList);

	Clear_List(myList);
	Print_List(myList);

	return 0;
}
