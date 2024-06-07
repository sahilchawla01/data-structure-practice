#pragma once

#include <iostream>
#define STACKSIZE 5

class CustomStack
{
private:
	int stackData[STACKSIZE] = { 0 };

	int stackTopIndex = -1;


public:
	CustomStack() : stackTopIndex(-1) {};

	void Push(int ValueToPush);
	int Pop();
	bool IsFull();
	bool IsEmpty();
	int Peek();
};

