#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

// Function to insert a new node at the beginning of the linked list
void head_insert(Node** phead,int x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = *phead;
	*phead = newNode;
}

// Function to insert a new node at the end of the linked list
void tail_insert(Node** phead, int x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;
	
	if (*phead == NULL) *phead = newNode;
	else
	{
		Node* current = *phead;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

// Function to display the elements in the linked list
void display(Node** phead)
{
	if (*phead == NULL)printf("The Linked List is Empty!\n");
	else
	{
		Node* current = *phead;
		while (current->next != NULL)
		{
			printf("%d ", current->data);
			current = current->next;
		}
		printf("%d\n", current->data);
	}
}

int main_02()
{
	Node* head = NULL;
	head_insert(&head, 10);
	tail_insert(&head, 20);
	tail_insert(&head, 30);
	display(&head);
	return 0;
}

//use struct Node** head as a pointer to a pointer to the head node of the linked list. 
// This allows us to modify the head poi1nter inside a function and reflect the changes outside the function.