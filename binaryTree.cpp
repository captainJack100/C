#include <iostream>

using namespace std;

typedef struct Node
{
	int data;
	struct Node* left; struct Node* right;
} Node;

struct Node* newNode(int data)
{
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);

};

void printPostOrder(Node* node)
{
	if (node == 0)
		return;

	printPostOrder(node->left);
	printPostOrder(node->right);
	cout << node->data << endl;
}

void printInorder(Node* node)
{
	if (node == 0)
		return;

	printPostOrder(node->left);
	cout << node->data << endl;
	printPostOrder(node->right);
}

void printPreorder(Node* node)
{
	if (node == 0)
		return;

	cout << node->data << endl;
	printPostOrder(node->left);
	printPostOrder(node->right);
}

int main(void)
{
	Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

	printPostOrder(root);
	printInorder(root);
	printPreorder(root);	

	return  0;
}
