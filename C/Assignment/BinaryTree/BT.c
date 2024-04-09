#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Tree_queue_LL.h"

#define MAX_SIZE 100

// Function to create a new node
Node* createNewNode(char x)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = x;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

// Function to do in-order traversal of the tree
void inorderTravesalRec(Node* root)
{
	if (root != NULL)
	{
		inorderTravesalRec(root->left);
		printf("%c ", root->data);
		inorderTravesalRec(root->right);
	}
}
void inorderTravesal(Node* root)
{
	printf("In-order Traversal: ");
	inorderTravesalRec(root);
	printf("\n");
}

//Do post-order traversal of the tree
void postTravesalRec(Node* root)
{
	if (root != NULL)
	{
		postTravesalRec(root->left);
		postTravesalRec(root->right);
		printf("%c ", root->data);
	}
}
void postorderTravesal(Node* root)
{
	printf("Post-order Traversal: ");
	postTravesalRec(root);
	printf("\n");
}

//Do level traversal of the tree
void levelTravesal(Node* root)
{
	printf("Level Traversal: ");
	Queue q1;
	q1.front = q1.rear = NULL;
	enqueue(&q1,root);
	while (!QIsEmpty(&q1))
	{
		Node* left = q1.front->data->left;
		Node* right = q1.front->data->right;
		enqueue(&q1, left);
		enqueue(&q1, right);
		printf("%c ", q1.front->data->data);
		dequeue(&q1);
	}
	printf("\n");
}

//Build a tree 
Node* preorderBuildTree(char* preorderstr, int* index)
{
	if (*index >= strlen(preorderstr)) return NULL;

	char c = preorderstr[*index];
	if (c == '#')
	{
		(*index)++;
		return NULL;
	}

	Node* root = createNewNode(c);
	(*index)++;
	root->left = preorderBuildTree(preorderstr, index);
	root->right = preorderBuildTree(preorderstr, index);
	return root;
}

//Function to remove the newline character
void remove_newline(char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			str[i] = '\0';
			break;
		}
		i++;
	}
}

int main()
{
	char preorderstr[MAX_SIZE];
	fgets(preorderstr, MAX_SIZE, stdin);
	remove_newline(preorderstr);

	int index = 0;
	Node* root = preorderBuildTree(preorderstr,&index);
	inorderTravesal(root);
	postorderTravesal(root);
	levelTravesal(root);
	return 0;
}
