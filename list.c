#include <stdio.h>
#include <stdlib.h>
#define zap(x) {if (x != 0) {free(x); x = 0;}}

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct List {
	Node *first;	
} List;

List *createList() {
	List *tmp = (List *)calloc(1, sizeof(List));
	return tmp;
}

void insertNode (List *myList, int value){

	Node *tmp = (Node *)calloc(1, sizeof(Node));
	tmp->value = value;
	
	if (myList != NULL) {
		if (myList->first == NULL)
			myList->first = tmp;
		else {
			tmp->next = myList->first;
			myList->first = tmp;
		}
	}
}

Node *popNode (List *myList) {
	Node *tmp;
	tmp = myList->first;

	myList->first = myList->first->next;
	return tmp;
}

void printList (List *myList) {

	Node *tmp = myList->first;

	while (tmp != NULL) {
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}

	printf("\n");

}

void reverseList (List *list) {
	Node *tmp = NULL;
	Node *previous = NULL;
	Node *ptr = list->first;

	while (ptr != NULL) {
		tmp = ptr->next;
		ptr->next = previous;
		previous = ptr;
		ptr = tmp;
	}

	list->first = previous;
}

int main(void) {

	List *myList = createList();

	insertNode(myList, 10);
	insertNode(myList, 1000);	

	printList(myList);

	reverseList(myList);
	printList(myList);

	return 0;
}
