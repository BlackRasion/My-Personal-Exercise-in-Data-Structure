#include <stdlib.h>
#include <stdio.h>

#include "queue_LL.h"

int QIsEmpty(Queue* queue)
{
	return (queue->front == NULL);
}

// Function to enqueue an element
void enqueue(Queue* queue,char x)
{
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = x;
	newNode->next = NULL;

	if (QIsEmpty(queue)) queue->front = newNode;
	else queue->rear->next = newNode;
	queue->rear = newNode;
}

// Function to dequeue an element
char dequeue(Queue* queue)
{
	char ret = '\0';
	if (QIsEmpty(queue)) printf("The Queue is Empty!\n");
	else
	{
		QNode* temp = queue->front;
		queue->front = temp->next;
		ret = temp->data;
		free(temp);
	}
	return ret;
}

//Display elements in the queue
void Qdisplay(Queue* queue)
{
	if (QIsEmpty(queue)) printf("The Queue is Empty!");
	else
	{
		printf("Queue: ");
		QNode* current = queue->front;
		while (current != NULL)
		{
			printf("%c ", current->data);
			current = current->next;
		}
	}
	printf("\n");
}
