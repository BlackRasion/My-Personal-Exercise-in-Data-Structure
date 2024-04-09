#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//include my stack head file
#include "char_stack_LL.h" 

#define MAX_SIZE 100

//Function to determine priority of operators
int Priority(char c)
{
	int ret = 0;
	if (c == '^') ret = 3;
	else if (c == '*' || c == '/' || c == '%') ret = 2;
	else if (c == '+' || c == '-') ret = 1;
	return ret;
}

//Function to evaluate multiplication
int multiplication(int x, int n)
{
	int ret = 1;
	while (n)
	{
		ret *= x;
		n--;
	}
	return ret;
}

//Function to determine if a character is a number
int IsNumber(char c)
{
	return (c >= '0' && c <= '9');
}

//Function to convert infix into postfix
void convert(char* expression, char postfix[])
{
	Node* operators = NULL;
	int p = 0;
	for (int i = 0; i < strlen(expression); i++)
	{
		char c = expression[i];
		if (IsNumber(c))
		{
			postfix[p++] = c;
			if (!IsNumber(expression[i + 1])) postfix[p++] = ' ';
		}
		else if (c == '(') push(&operators, c);
		else if (c == ')')
		{
			while (!IsEmpty(operators) && Top(operators) != '(')
			{
				postfix[p++] = pop(&operators);
				postfix[p++] = ' ';
			}
			pop(&operators);
		}
		else
		{
			while (!IsEmpty(operators) && Top(operators) != '(' && Priority(Top(operators)) >= Priority(c))
			{
				postfix[p++] = pop(&operators);
				postfix[p++] = ' ';
			}
			push(&operators, c);
		}
	}
	while (!IsEmpty(operators))
	{
		postfix[p++] = pop(&operators);
		postfix[p++] = ' ';
	}
	postfix[p] = '\0';
}

//Function to evaluate a postfix
int evaluatePostfix(char* postfix) {
	Node* operands = NULL;
	for (int i = 0; i < strlen(postfix); i++)
	{
		char c = postfix[i];
		if (IsNumber(c))
		{
			int n = 0;
			do
			{
				n = n * 10 + c - '0';
				c = postfix[++i];
			} while (IsNumber(c));
			push(&operands, n);
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%'|| c == '^')
		{
			int b = pop(&operands);
			int a = pop(&operands);
			switch (c)
			{
			case '+':
				push(&operands, a + b);
				break;
			case '-':
				push(&operands, a - b);
				break;
			case '*':
				push(&operands, a * b);
				break;
			case '/':
				printf("%d/%d:%d\n", a, b, a / b);
				push(&operands, a / b);
				break;
			case '%':
				push(&operands, a % b);
				break;
			case '^':
				push(&operands, multiplication(a, b));
				break;
			default:
				break;
			}
		}
	}
	return Top(operands);
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

int main_01()
{
	char expression[MAX_SIZE / 2];
	fgets(expression, sizeof(expression), stdin);
	remove_newline(expression);

	char postfix[MAX_SIZE] = "\0";
	convert(expression, postfix);
	int result = evaluatePostfix(postfix);

	printf("Postfix: %s\n", postfix);
	printf("Result: %d\n", result);
	return 0;
}

