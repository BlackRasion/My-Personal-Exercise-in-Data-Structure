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

// Function to display the elements in the queue
void display(Queue* queue)
{
	if (IsEmpty(queue)) printf("The Queue is Empty!");
	else
	{
		printf("Queue: ");
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
	int n = 0;
	scanf_s("%d", &n);
	int x = -1;

	Queue q1;
	q1.front = q1.rear = NULL;
	Queue q2;
	q2.front = q2.rear = NULL;

	for (int i = 0; i < n; i++)
	{
		scanf_s("%d",&x);
		if (x % 2) enqueue(&q1, x);
		else enqueue(&q2, x);
	}
	while (!IsEmpty(&q1) && !IsEmpty(&q2))
	{
		printf("%d %d\n", dequeue(&q1), dequeue(&q2));
	}
	
	return 0;
}
