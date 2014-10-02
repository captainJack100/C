/*
	Basic linked list example. Same as double linked but node only stores one direction.
*/

#include <stdio.h>
#include <stdlib.h>

// Node to be held in list
typedef struct ListNode{
	struct ListNode *next;
	void *value;
} ListNode;

// List structure
typedef struct {
	ListNode *first;
	ListNode *last;
	size_t count;
} List;

// Create a list structure
List *ListCreate(void) {

	return (List *)calloc(1, sizeof(List));

}

// Push value onto list
void ListPush(List *list, void *value) {

	ListNode *node = (ListNode *)calloc(1, sizeof(ListNode));
	node->value = value;
	list->count += 1;

	if (list->last == NULL) {
		list->first = node;
		list->last = node;
	} else {
		list->last->next = node;
		list->last = node;
	}

}

// Pop the list
ListNode *ListPop(List *list) {

	ListNode *tmp;
	
	if (list->count > 0) {
		tmp = list->first;
		list->first = list->first->next;
	}	

	list->count -= 1;

	return tmp;

}

// Destroy the list
void ListDestroy(List *list) {

	int count = list->count;
	int i = 0;

	for (i = 0; i < count; i++){
		free(ListPop(list));
	}
}

// print out the list
void ListPrint(List *list) {

	int i = 0;
	ListNode *tmpNode = list->first;

	for (i = 0; i < list->count; i++) {
		printf("%d ", *(int *)tmpNode->value);
		tmpNode = tmpNode->next;
	}
	
	printf("\n");

}

// Reverse list practice
void revList(List *list) {

	ListNode *temp = NULL;
	ListNode *previous = NULL;
	ListNode *ptr = list->first;

	while (ptr != NULL) {
		temp = ptr->next;
		ptr->next = previous;
		previous = ptr;
		ptr = temp;
	}
	
	list->first = previous;
}

void reverseList2 (List *list) {

	ListNode *tmp = NULL;
	ListNode *previous = NULL:
	ListNode *ptr = list->first;

	while (ptr != NULL) {
		tmp = ptr->next;
		ptr->next = previous;
		previous = ptr;
		ptr = tmp;
	}
}


// Reverse the list
void reverseList(List *list) {

	ListNode *tmp = NULL;
	ListNode *previous = NULL;
	ListNode *ptr = list->first;

	while (ptr != NULL) {
		tmp = ptr->next;
		ptr->next = previous;
		previous = ptr;
		ptr = tmp;
	}		 	

	list->first = previous;
}

int main(void) {

	int *a = malloc(sizeof(int));
	*a = 10;
	int *b = malloc(sizeof(int));
	*b = 2000;

	List *myList = ListCreate();
	ListPush(myList, a);
	ListPush(myList, b);	
	//ListPrint(myList);

	//ListDestroy(myList);
	//ListDestroy(myList);
	
	ListPrint(myList);

	reverseList(myList);
	ListPrint(myList);

	free(a);
	free(b);
	free(myList);

	return 0;
}

