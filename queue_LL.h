#ifndef QUEUE_LL_H

#define QUEUE_LL_H

//Define structure
typedef struct QNode
{
	char data;
	struct QNode* next;
}QNode;

typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

/* Function declarations */
int QIsEmpty(Queue* queue);
void enqueue(Queue* queue, char x);
char dequeue(Queue* queue);
void Qdisplay(Queue* queue);

#endif