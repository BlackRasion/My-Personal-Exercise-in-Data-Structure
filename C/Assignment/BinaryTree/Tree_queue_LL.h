#ifndef TREE_QUEUE_LL_H

#define TREE_QUEUE_LL_H

/* struct define */

// Define the structure for a treenode
typedef struct Node {
	char data;
	struct Node* left;
	struct Node* right;
}Node;

typedef struct QNode {
	Node* data;
	struct QNode* next;
}QNode;

typedef struct Queue {
	QNode* front;
	QNode* rear;
}Queue;

/* Function declarations */
int QIsEmpty(Queue* queue);
void enqueue(Queue* queue, Node* treenode);
Node* dequeue(Queue* queue);

#endif