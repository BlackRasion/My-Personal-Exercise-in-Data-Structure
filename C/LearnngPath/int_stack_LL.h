#ifndef INT_STACK_LL_H /* Include guard */

#define INT_STACK_LL_H

/* Define  structure */ 
typedef struct Node_int
{
	int data;
	struct Node_int* next;
}Node_int;

/* Function declarations */
Node_int* newNode_int(int x);
int IsEmpty_int(Node_int* top);
void push_int(Node_int** top, int x);
int pop_int(Node_int** top);
int Top_int(Node_int* top);


#endif
