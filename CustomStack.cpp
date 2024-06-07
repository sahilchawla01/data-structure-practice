#include "CustomStack.h"

void CustomStack::Push(int ValueToPush)
{
	if (IsFull())
	{
		std::cout << "\nAttempted to push, stack was full. Returning.." << std::endl;
		return;
	}

	//Increment top index
	stackTopIndex++;
	
	//Set value 
	stackData[stackTopIndex] = ValueToPush;

	std::cout << "\nThe following value was pushed: " << ValueToPush << std::endl;

}

int CustomStack::Pop()
{
	if (IsEmpty())
	{
		std::cout << "\nAttempted to pop, stack was empty. Returning.." << std::endl;
		return -1;
	}

	int poppedValue = stackData[stackTopIndex];

	//Decrement index
	stackTopIndex--;

	std::cout << "\nThe following value was popped: " << poppedValue;

	return poppedValue;
}

bool CustomStack::IsFull()
{
	if (stackTopIndex >= STACKSIZE - 1) return true;

	return false;
}

bool CustomStack::IsEmpty()
{
	if (stackTopIndex < 0) return true;

	return false;
}

int CustomStack::Peek()
{
	if(IsEmpty()) return -1;

	std::cout << "\nPeeking top value:" << stackData[stackTopIndex] << std::endl;

	return stackData[stackTopIndex];
}
