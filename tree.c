/*
	tree basics.
	This is a binary search tree.
*/

#include <stdio.h>
#include <stdlib.h>
#define zap(x) {if (x != 0) {free(x); x = 0;}}

typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

Node *newNode(int data) {
	Node *node = (Node *)calloc(1, sizeof(Node));
	node->data = data;
	return node;
}

Node *insert(Node *node, int data) {
	if (node == NULL)
		return newNode(data);
	if (data <= node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	return node;
}

void printTree(Node *tree) {
	if (tree != NULL) {
		printTree(tree->left);
		printf("%d ", tree->data);
		printTree(tree->right);
	}
}

void clearTree(Node *tree) {
	if (tree != NULL) {
		clearTree(tree->left);
		clearTree(tree->right);
		zap(tree);
	}
}

int find(Node *node, int value) {
	if (node == NULL)
		return 0;
	if (value < node->data)
		return find(node->left, value);
	if (value > node->data)
		return find(node->right, value);
	if (value == node->data)
		return 1;

	return 0;
}

int findMin(Node *node) {
	if (node == NULL)
		return 0;
	if (node->left == NULL)
		return node->data;
	else
		return findMin(node->left);

	return 0;
}

int findMax(Node *node) {
	if (node == NULL) 
		return 0;
	if (node->right == NULL)
		return node->data;
	else
		return findMax(node->right);
	
	return 0;
}

int main(void) {

	Node *tree = NULL;
	
	tree = insert(tree, 10);
	tree = insert(tree, 4);
	tree = insert(tree, 300);
	printTree(tree);	
	puts("\n");

	printf("Find if value is in tree: %d \n", find(tree, 400));
	printf("Find Min value: %d \n", findMin(tree));
	printf("Find the Max value: %d \n", findMax(tree));

	clearTree(tree);
	tree = NULL;

	return 0;
}




