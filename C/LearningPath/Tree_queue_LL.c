#include <stdlib.h>
#include <stdio.h>

#include "Tree_queue_LL.h"

int QIsEmpty(Queue* queue)
{
	return queue->front == NULL;
}

void enqueue(Queue* queue, Node* treenode)
{
	if (treenode == NULL) return;
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data  = treenode;
	newNode->next = NULL;

	if (QIsEmpty(queue)) queue->front = newNode;
	else queue->rear->next = newNode;
	queue->rear = newNode;
}

Node* dequeue(Queue* queue)
{
	Node* ret = NULL;
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
