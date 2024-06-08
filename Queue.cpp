#include "Queue.h"
#include <iostream>

void Queue::Enqueue(int element)
{
	if (IsFull())
	{
		std::cout << "\nQueue is full.. Returning!" << std::endl;
		return;
	}

	//Increment current length of queue
	CurrentLength++;
}

int Queue::Dequeue()
{
	//Decrement current length of queue
	CurrentLength--;

	return 0;
}

int Queue::Front()
{
	return 0;
}

int Queue::Rear()
{
	return 0;
}

bool Queue::IsFull()
{
	return false;
}

bool Queue::IsEmpty()
{
	return false;
}
