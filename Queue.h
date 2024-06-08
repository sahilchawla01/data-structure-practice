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
	QueueNode* front, *rear;

	Queue() : front(nullptr), rear(nullptr) {};
	Queue(int maxLength) : front(nullptr), rear(nullptr), MaximumQueueLength(maxLength) {};

	void Enqueue(int element);
	int Dequeue();
	int Front();
	int Rear();
	bool IsFull();
	bool IsEmpty();

public:
	int CurrentLength = 0;
	int MaximumQueueLength = 5;
};

