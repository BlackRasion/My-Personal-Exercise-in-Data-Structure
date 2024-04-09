#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

// Define a structure for each node
typedef struct Node {
	char data;
	struct Node* next;
}Node;

// Define a global variable to keep track of the top of the stack
Node* top = NULL;

// Function to push an element onto the stack
void push(char x)
{
	Node* newN = (Node*)malloc(sizeof(Node));
	newN->data = x;
	newN->next = top;
	top = newN;
}

// Function to pop an element from the stack
char pop()
{
	char ret =' ';
	if (top == NULL)
	{
		printf("The stack is empty.\n");
	}
	else
	{
		Node* temp = top;
		ret = temp->data;
		top = temp->next;
		free(temp);
	}
	return ret;
}

// Function to get the top element of the stack without removing it
char Top()
{
	char ret = ' ';
	if (top == NULL)printf("The stack is empty.\n");
	else ret = top->data;
	return ret;
}

// judge if the parentheses are banlanced
int IsBanlanced(char expression[])
{
	int ret = 1;
	for (int i = 0; expression[i] != '\0'; i++)
	{
		if (expression[i] == '{' || expression[i] == '[' || expression[i] == '(') push(expression[i]);
		else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
		{
			if (top == NULL)
			{
				ret = 0; 
				break;
			}
			else
			{
				char c = pop();
				if ((expression[i] == ')' && c != '(') ||
					(expression[i] == ']' && c != '[') ||
					(expression[i] == '}' && c != '{'))
				{
					ret = 0;
					break;
				}
			}
		}
	}
	if (top != NULL)ret = 0;
	return ret;
}

int main()
{
	char expression[MAX_SIZE];
	//printf("输入表达式：\n");
	scanf_s("%s", expression);
	top = NULL;

	if (IsBanlanced(expression)) printf("括号配对\n");
	else printf("括号不配对\n");

	return 0;
}
