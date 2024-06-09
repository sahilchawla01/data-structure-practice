#include "Queue.h"
#include <iostream>

void Queue::Enqueue(int element)
{
	if (IsFull())
	{
		std::cout << "\nQueue is full.. Returning!" << std::endl;
		return;
	}

	//Create new node
	QueueNode* newElementNode = new QueueNode(element);

	if (IsEmpty())
	{
		std::cout << "\nQueue is empty, Inserting value!" << std::endl;
		front = newElementNode;
		rear = newElementNode;

		std::cout << "\nFront Value: " << front->value;

		//Increment current length of queue
		CurrentLength++;

		return;
	}


	//Old rear node points to new element node
	rear->next = newElementNode;
	//Rear node becomes new element node
	rear = newElementNode;


	//Increment current length of queue
	CurrentLength++;

	std::cout << "\nQueueing value.." << std::endl;
}

int Queue::Dequeue()
{
	if (IsEmpty())
	{
		std::cout << "\nDequeue operation failed, queue was empty! Returning.." << std::endl;
		return -1;
	}

	QueueNode* oldFrontNode = front;
	int oldFrontValue = oldFrontNode->value;

	//New front becomes old front's next node
	front = front->next;
	//Delete memory for old front node
	free(oldFrontNode);

	//Decrement current length of queue
	CurrentLength--;

	//If queue is emptied, rear should also become null
	if (front == nullptr) rear = nullptr;

	std::cout << "\nDequeued the following value:" << oldFrontValue << std::endl;
	return oldFrontValue;
}

int Queue::Front()
{
	if (IsEmpty())
	{
		std::cout << "\nCouldn't retrieve front value of queue, queue is empty! Returning..\n";
		return -1;
	}

	std::cout << "\nReturning front value: " << front->value << std::endl;

	return front->value;
}

int Queue::Rear()
{
	if (IsEmpty())
	{
		std::cout << "\nCouldn't retrieve rear value of queue, queue is empty! Returning..\n";
		return -1;
	}

	return rear->value;
}

bool Queue::IsFull()
{
	if (CurrentLength == MaximumQueueLength) return true;

	return false;
}

bool Queue::IsEmpty()
{
	if (front == nullptr) return true;

	return false;
}
