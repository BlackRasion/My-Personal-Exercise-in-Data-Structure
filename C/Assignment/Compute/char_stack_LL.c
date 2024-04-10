#include <stdlib.h>
#include <stdio.h>

#include "char_stack_LL.h"

//Function to create a new node with the given data
Node* newNode(char x)
{
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}

//Function to check if the stack is empty
int IsEmpty(Node* top)
{
	return !top;
}

// Function to push an element onto the stack
void push(Node** top, char x)
{
	Node* newnode = newNode(x);
	newnode->next = *top;
	*top = newnode;
	//printf("%d pushed onto the stack.\n");
}

// Function to pop an element from the stack
char pop(Node** top)
{
	char ret = '\0';
	if (IsEmpty(*top)) printf("The stack is empty.\n");
	else
	{
		Node* temp = *top;
		ret = temp->data;
		*top = temp->next;
		free(temp);
	}
	return ret;
}

// Function to get the top element of the stack without removing it
char Top(Node* top)
{
	char ret = '\0';
	if (IsEmpty(top))printf("The stack is empty.\n");
	else ret = top->data;
	return ret;
}
