#ifndef CHAR_STACK_LL_H /* Include guard */

#define CHAR_STACK_LL_H

/* Define  structure */
typedef struct Node
{
	char data;
	struct Node* next;
}Node;

/* Function declarations */
Node* newNode(char x);
int IsEmpty(Node* top);
void push(Node** top, char x);
char pop(Node** top);
char Top(Node* top);


#endif