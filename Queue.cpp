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

InputRestrictedQueue::InputRestrictedQueue()
{
	front = nullptr;
	rear = nullptr;
}

int InputRestrictedQueue::Dequeue_Back()
{
	if (IsEmpty())
	{
		std::cout << "\nDequeue_back operation cancelled, queue was empty" << std::endl;
		return -1;
	}

	if (front == rear)
	{
		int dequeueValue = front->value;

		std::cout << "\nDequeue_back operation done, queue was emptied.. Dequeued value: " << dequeueValue;

		//Empty the queue
		front = rear = nullptr;

		return dequeueValue;
	}

	//Store old rear element
	QueueNode* temp = rear;
	int RearValue = temp->value;

	QueueNode* newRearElement = front;
	//Traverse to the second last element
	while (newRearElement->next != rear)
	{
		newRearElement = newRearElement->next;
	}

	//New rear element will become the node before the old rear element
	rear = newRearElement;

	//Release temp
	free(temp);

	std::cout << "\nDequeue_back operation succeeded, dequeued element: " << RearValue << std::endl;
	std::cout << "\nNew rear element is: " << rear->value;

	//Decrement length of queue 
	CurrentLength--;

	return RearValue;
}

OutputRestrictedQueue::OutputRestrictedQueue()
{
	front = rear = nullptr;
}

void OutputRestrictedQueue::Enqueue_Front(int element)
{
	if (IsFull())
	{
		std::cout << "\nQueue is full, Enqueue_Front operation failed. Returning.." << std::endl;
		return;
	}

	QueueNode* newElementNode = new QueueNode(element);

	if (IsEmpty())
	{
		front = rear = newElementNode;
		std::cout<<"\nQueue is empty, Enqueue_Front operation succeeded, inserted value: "<<element<<" Returning.."<<std::endl;
		return;
	}
	QueueNode* oldFront = front;

	//New front becomes new element node
	front = newElementNode;

	//New front points to oldFront
	front->next = oldFront;

	//Increment length of queue
	CurrentLength++;
	std::cout << "\nEnqueue_Front operation succeeded, inserted value: " << element;
}

DoubleQueue::DoubleQueue()
{
	rear = front = nullptr;
}

void DoubleQueue::Enqueue_Front(int element)
{
	if (IsFull())
	{
		std::cout << "\nQueue is full, Enqueue_Front operation failed. Returning.." << std::endl;
		return;
	}

	QueueNode* newElementNode = new QueueNode(element);

	if (IsEmpty())
	{
		front = rear = newElementNode;
		std::cout << "\nQueue is empty, Enqueue_Front operation succeeded, inserted value: " << element << " Returning.." << std::endl;
		return;
	}
	QueueNode* oldFront = front;

	//New front becomes new element node
	front = newElementNode;

	//New front points to oldFront
	front->next = oldFront;

	//Increment length of queue
	CurrentLength++;
	std::cout << "\nEnqueue_Front operation succeeded, inserted value: " << element;
}

int DoubleQueue::Dequeue_Back()
{
	if (IsEmpty())
	{
		std::cout << "\nDequeue_back operation cancelled, queue was empty" << std::endl;
		return -1;
	}

	if (front == rear)
	{
		int dequeueValue = front->value;

		std::cout << "\nDequeue_back operation done, queue was emptied.. Dequeued value: " << dequeueValue;

		//Empty the queue
		front = rear = nullptr;

		return dequeueValue;
	}

	//Store old rear element
	QueueNode* temp = rear;
	int RearValue = temp->value;

	QueueNode* newRearElement = front;
	//Traverse to the second last element
	while (newRearElement->next != rear)
	{
		newRearElement = newRearElement->next;
	}

	//New rear element will become the node before the old rear element
	rear = newRearElement;

	//Release temp
	free(temp);

	std::cout << "\nDequeue_back operation succeeded, dequeued element: " << RearValue << std::endl;
	std::cout << "\nNew rear element is: " << rear->value;

	//Decrement length of queue 
	CurrentLength--;

	return RearValue;
}
