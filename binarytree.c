#include <stdlib.h>
#include <stdio.h>

#define Distance 10

// Define the structure for a node
typedef struct Node {
	int data;
	struct Node* left;
	struct Node* right;
}Node;

// Function to create a new node
Node* createNewNode(int x)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

// Function to insert a node in the tree
Node* insertNode(Node* root, int x)
{
	if (root == NULL) root = createNewNode(x);
	else if (x < root->data) root->left = insertNode(root->left, x);
	else root->right = insertNode(root->right, x);
	return root;
}
void insert(Node** root, int x)
{
	*root = insertNode(*root, x);
}

// Function to do in-order traversal of the tree
void inorderTravesalRec(Node* root)
{
	if (root != NULL)
	{
		inorderTravesalRec(root->left);
		printf("%d ", root->data);
		inorderTravesalRec(root->right);
	}
}
void inorderTravesal(Node* root)
{
	printf("In-order Traversal: ");
	inorderTravesalRec(root);
	printf("\n");
}

// Function to do pre-order traversal of the tree
void preorderTravesalRec(Node* root)
{
	if (root != NULL)
	{
		printf("%d ", root->data);
		preorderTravesalRec(root->left);
		preorderTravesalRec(root->right);
	}
}
void preorderTravesal(Node* root)
{
	printf("Pre-order Traversal: ");
	preorderTravesalRec(root);
	printf("\n");
}

// Function to do post-order traversal of the tree
void postorderTravesalRec(Node* root)
{
	if (root != NULL)
	{
		postorderTravesalRec(root->left);
		postorderTravesalRec(root->right);
		printf("%d ", root->data);
	}
}
void postorderTravesal(Node* root)
{
	printf("Post-order Travesal: ");
	postorderTravesalRec(root);
	printf("\n");
}

// Function to print binary tree in 2D
void print2DRec(Node* root, int space)
{
	if (root == NULL) return;//base case
	else
	{
		space += Distance;
		print2DRec(root->right, space);
		printf("\n");

		for (int i = Distance; i < space; i++)printf(" ");
		printf("%d\n", root->data);

		print2DRec(root->left, space);
	}
}
void print2D(Node* root)
{
	print2DRec(root, 0);//initialize space as 0
}

	
int main()
{

	return 0;
}