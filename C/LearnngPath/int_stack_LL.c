#include <stdlib.h>
#include <stdio.h>

#include "int_stack_LL.h"

//Function to create a new node with the given data
Node_int* newNode_int(int x)
{
	Node_int* newnode = (Node_int*)malloc(sizeof(Node_int));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//Function to check if the stack is empty
int IsEmpty_int(Node_int* top)
{
	return !top;
}

// Function to push an element onto the stack
void push_int(Node_int** top,int x)
{
	Node_int* newnode = newNode_int(x);
	newnode->next = *top;
	*top = newnode;
	//printf("%d pushed onto the stack.\n");
}

// Function to pop an element from the stack
int pop_int(Node_int** top)
{
	int ret = -1;
	if (IsEmpty_int(*top)) printf("The stack is empty.\n");
	else
	{
		Node_int* temp = *top;
		ret = temp->data;
		*top = temp->next;
		free(temp);
	}
	return ret;
}

// Function to get the top element of the stack without removing it
int Top_int(Node_int* top)
{
	int ret = -1;
	if (IsEmpty_int(top))printf("The stack is empty.\n");
	else ret = top->data;
	return ret;
}
