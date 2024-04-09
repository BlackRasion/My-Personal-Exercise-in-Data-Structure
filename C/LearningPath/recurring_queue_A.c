#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 100

int Queue[MAX_SIZE];
int front = -1;
int rear = -1;

int IsEmpty()
{
	return (front == rear);
}

int IsFull()
{
	return ((rear + 1) % MAX_SIZE == front);//here
}

// Function to enqueue an element
void enqueue(int x)
{
	if (IsFull())printf("The queue is already full.\n");
	else
	{
		if (IsEmpty()) rear = front = 0;
		else rear = (rear+1) % MAX_SIZE;//here
		Queue[rear] = x;
	}
}

// Function to dequeue an element
int dequeue()
{
	int ret = -1;
	if (IsEmpty()) printf("The queue is empty!\n");
	else
	{
		ret = Queue[front];
		if (front == rear) front = rear = -1;
		else front = (front + 1) % MAX_SIZE;//here
	}
	return ret;
}

// Function to display the elements in the queue
void display()
{
	if (IsEmpty()) printf("Queue is empty!");
	else
	{
		printf("Queue: ");
		for (int i = front; i != rear; i = (i+1) % MAX_SIZE)
		{
			printf("%d ", Queue[i]);
		}
		printf("%d.",Queue[rear]);
	}
	printf("\n");
}

int main()
{
	enqueue(10);
	enqueue(20);
	enqueue(30);
	display(); // Output: Queue: 10 20 30
	printf("Dequeued element: %d\n", dequeue()); // Output: Dequeued element: 10
	display(); // Output: Queue: 20 30
	return 0;
}
