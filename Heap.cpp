#include "Heap.h"
#include <iostream>
#include <cmath>

Heap::Heap()
{
	this->maxHeapSize = 100;
	this->heapSize = 0;
	this->arr = new int[100];
	//Initialise all array values with -1
	for (int i = 0; i < 100; i++) arr[i] = -1;
}

Heap::Heap(int maxHeapSize)
{
	this->maxHeapSize = maxHeapSize;
	this->heapSize = 0;
	this->arr = new int[maxHeapSize];

	//Initialise all array values with -1
	for (int i = 0; i < maxHeapSize; i++) arr[i] = -1;
}

void Heap::InsertInMaxHeap(int key)
{
	if (IsFull())
	{
		std::cout << "\nHeap was full.. Returning";
		return;
	}

	//First insert the new key to the element after last occupied element
	arr[heapSize++] = key;

	//Iterator points to the last added element
	int itr = heapSize - 1;

	//Itr > 0 because if index is 0, it's already maximum. 
	while (itr > 0 && arr[itr] > arr[GetParent(itr)])
	{
		int parentIndex = GetParent(itr);

		SwapElements(arr[itr], arr[parentIndex]);

		//Move index to parent's index
		itr = parentIndex;
	}

	std::cout << "\nInserted value in heap!" << std::endl;
}


void Heap::DisplayArr(int arr[], int size)
{
	std::cout << "\nArray content: ";
	for (int i = 0; i < size; i++) std::cout << arr[i] << ", ";
}

int Heap::GetParent(int index)
{
	return (index - 1) / 2;
}

int Heap::GetLeftChild(int index)
{
	return (index * 2) + 1;
}

int Heap::GetRightChild(int index)
{
	return (index * 2) + 2;
}

bool Heap::IsFull()
{
	if (maxHeapSize == heapSize) return true;
	return false;
}

void Heap::SwapElements(int& element1, int& element2)
{
	int temp = element2;
	element2 = element1;
	element1 = temp;
}

void Heap::DisplayMaxHeap()
{
	for (int i = 0; i < heapSize; i++) std::cout << arr[i] << " ";
}

int Heap::DeleteMax()
{
	// -- PSEUDO CODE -- 
	//Remove the first element
	//Since its a complete binary tree, take deepest-right most child, and place in first element 
	//Take root node, compare left and right child, get maximum. 
	//Then, compare with root node, if root is smaller, swap
	//Continue, until root is not smaller 

	if (heapSize == 0)
	{
		std::cout << "\nHeap was empty.. Returning";
		return -1;
	}

	int result = arr[0];

	//Replace first element with last element
	arr[0] = arr[heapSize - 1];
	//Empty last element
	arr[heapSize - 1] = -1;
	//Decrement heap size
	heapSize--;

	int itr = 0;
	while (true)
	{
		//Compare children of new root node
		int maxChildIndex = (arr[GetLeftChild(itr)] > arr[GetRightChild(itr)]) ? GetLeftChild(itr) : GetRightChild(itr);

		//Compare with new root node with maximum child, if less, then swap,
		if (arr[itr] < arr[maxChildIndex])
		{
			SwapElements(arr[itr], arr[maxChildIndex]);
		}
		else //If not true, simply break. Heap status has been restored
		{
			break;
		}

		//Index now points to new maxChildIndex
		itr = maxChildIndex;
	}

	std::cout << "\nMaximum value deleted!";

	return result;
}

void Heap::DeleteEntireMaxHeap()
{
	for (int itr = 0; itr < heapSize; itr++)
	{
		arr[itr] = -1;
	}

	heapSize = 0;

	std::cout << "\nHeap cleared";
}

void Heap::Heapify(int resultantArray[], int size)
{
	//-- PSEUDO CODE --
	//1)Start from the deepest-right most node and work backwards
	//2)Start loop
	//3)Does current node have children, no? continue to next node
	//4)If node has children, compare children, get max
	//5)Then, compare with node, if child greater, swap.
	//6)Continue until itr reaches 0


	//Clear the heap
	DeleteEntireMaxHeap();

	int itr = size - 1;

	while (!(itr < 0))
	{
		//std::cout << itr;
		int possibleLeftChildIndex = GetLeftChild(itr);
		int possibleRightChildIndex = GetRightChild(itr);

		//If left child is beyond array bounds, then it is a leaf node, continue to next iteration
		if (possibleLeftChildIndex > size - 1)
		{
			itr--;
			continue;
		}

		//If right child is beyond array bounds, simply compare current node with left child
		if (possibleRightChildIndex > size - 1)
		{
			//If left child is greater, swap elements
			if (resultantArray[possibleLeftChildIndex] > resultantArray[itr])
			{
				SwapElements(resultantArray[possibleLeftChildIndex], resultantArray[itr]);
			}
			else //If left child not greater, go to next iteration 
			{
				itr--;
				continue;
			}
		}
		else //If both children are in array bounds
		{
			//Find and store max child's index
			int maxChildIndex = (resultantArray[possibleLeftChildIndex] > resultantArray[possibleRightChildIndex]) ? possibleLeftChildIndex : possibleRightChildIndex;

			//Now, compare with current node

			//If child element is found greater, perform swap
			if (resultantArray[maxChildIndex] > resultantArray[itr])
				SwapElements(resultantArray[maxChildIndex], resultantArray[itr]);
			else //If not, continue to next iteration
			{
				itr--;
				continue;
			}
		}

		itr--;
	}

	//Finally, simply set internal heap
	for (int i = 0; i < size; i++)
	{
		arr[i] = resultantArray[i];
		heapSize++;
	}

	std::cout << "\nArray after heapify:";
	for (int i = 0; i < size; i++) std::cout << resultantArray[i] << ", ";
}

void Heap::HeapSort(int resultantArray[], int size)
{
	//Clear the heap 
	DeleteEntireMaxHeap();

	//Create the heap
	for (int i = 0; i < size; i++)
	{
		InsertInMaxHeap(resultantArray[i]);
	}

	/*std::cout << "\nDuring heap sort, current heap array before deletion is: ";
	DisplayArr(arr, heapSize);*/

	//Fill the heap in reverse by deleting each element from heap
	for (int itr = 0; itr < size; itr++)
	{
		resultantArray[size - itr - 1] = DeleteMax();
	}

	std::cout << "\nHeap sorted the following array:";
	
}
