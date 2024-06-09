#pragma once

struct QueueNode
{
	int value;
	QueueNode* next;

	QueueNode(int x) : value(x), next(nullptr) {};
};

class Queue
{
public:

	Queue() : front(nullptr), rear(nullptr) {};
	Queue(int maxLength) : front(nullptr), rear(nullptr), MaximumQueueLength(maxLength) {};

	QueueNode* front, *rear;

	virtual void Enqueue(int element);
	virtual int Dequeue();
	virtual int Front();
	virtual int Rear();
	virtual bool IsFull();
	virtual bool IsEmpty();

public:
	int CurrentLength = 0;
	int MaximumQueueLength = 5;
};

class InputRestrictedQueue : public Queue
{
public:
	InputRestrictedQueue();

	int Dequeue_Back();
	
};

