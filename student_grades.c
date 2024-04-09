#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* next;
}Node;

typedef struct Queue {
	Node* front;
	Node* rear;
}Queue;

int IsEmpty(Queue* queue)
{
	return (queue->front == NULL);
}

// Function to enqueue an element
void enqueue(Queue* queue, int x)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;

	if (IsEmpty(queue)) queue->front = newNode;
	else queue->rear->next = newNode;
	queue->rear = newNode;
}

// Function to dequeue an element
int dequeue(Queue* queue)
{
	int ret = -1;
	if (IsEmpty(queue)) printf("The Queue is Empty!\n");
	else
	{
		Node* temp = queue->front;
		queue->front = temp->next;
		ret = temp->data;
		free(temp);
	}
	return ret;
}

void display(Queue* queue)
{
	if (IsEmpty(queue)) printf("The Queue is Empty!");
	else
	{
		//printf("Queue: ");
		Node* current = queue->front;
		while (current != NULL)
		{
			printf("%d ", current->data);
			current = current->next;
		}
	}
	printf("\n");
}

int main()
{
	Queue queue1;
	queue1.front = NULL;
	queue1.rear = NULL;
	Queue queue2;
	queue2.front = NULL;
	queue2.rear = NULL;
	Queue queue3;
	queue3.front = NULL;
	queue3.rear = NULL;

	int n = 0;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		scanf_s("%d", &x);
		if (x < 60) enqueue(&queue1, x);
		else if (x < 100) enqueue(&queue2, x);
		else enqueue(&queue3, x);
	}
	printf("60>x:");
	display(&queue1);
	printf("60<=x<100:");
	display(&queue2);
	printf("x>=100:");
	display(&queue3);
	return 0;
}