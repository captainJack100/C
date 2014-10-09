/*
	Queue implementation. Node should use a void to make it more general. Not doing that here.
	HOW it works:
		list: (head)a->b->c (tail)  
		insert(L, d);
		put d on the head. list->tail->next = d; list->tail = d
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define zap(x) {if (x != 0) {free(x); x = 0;}}
#define check(x, y) {if (x == 0) {fprintf(stderr, "ERROR: %s\n", y); exit(1);}}

typedef struct Node {
	int value;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	Node *tail;
} Queue;

Queue *New_Queue() {

	return (Queue *)calloc(1, sizeof(Queue));

}

void Insert_Node(Queue *q, int elt) {

	Node *n = (Node *)calloc(1, sizeof(Node));	
	check(n, "No Memory");	
	
	n->value = elt;

	if (q->head == NULL && q->tail == NULL) {
		q->head = n;
		q->tail = n;
	} 
	else {
		q->tail->next = n;
		q->tail = n;		
	}

}

Node *Remove_Node(Queue *q) {

	Node *tmp = NULL;

	// When queue is empty	
	if (q->head == NULL && q->tail == NULL)
		return NULL;

	if (q->head == q->tail)
		q->tail = NULL;

	tmp = q->head;
	q->head = q->head->next;	

	return tmp;

}

void Print_Queue(Queue *q) {

	Node *tmpPrint = NULL;
	
	for (tmpPrint = q->head; tmpPrint; tmpPrint = tmpPrint->next){
		printf("%d\n", tmpPrint->value);
	}
}

int main(void) {
	
	Queue *q = New_Queue();
	Insert_Node(q, 10);
	Insert_Node(q, 100);	
	Insert_Node(q, 4);
	
	free(Remove_Node(q));	
	free(Remove_Node(q));	
	free(Remove_Node(q));	
	free(Remove_Node(q));	
	
	Print_Queue(q);

	zap(q);

	return 0;
}
