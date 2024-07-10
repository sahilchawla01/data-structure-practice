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

	// -- PSEUDO CODE -- (This algorithm works in reverse, from the last to the first element)
	//1)Ignoring the leaf nodes, start from the parent of the last leaf node (i.e [N/2] - 1) where N is the number of elements)
	//2)Start a loop from the parent index
	//3)Get index of left and right child
	//4)In a while loop, 
	//5)store index with maximum value
	//6)Compare parent with max child value, if parent greater, swap and traverse to next left and right child

	//Store last leaf node's parent (we ignore the leaf nodes) and work in reverse
	int parentLastLeafNode = static_cast<int>(size / 2) - 1;

	for (int itr = parentLastLeafNode; itr >= 0; itr--)
	{
		int leftChildIndex = GetLeftChild(itr);
		int righChildIndex = GetRightChild(itr);

		//Get maximum child's index
		int maxChildIndex = (resultantArray[leftChildIndex] > resultantArray[righChildIndex]) ? leftChildIndex : righChildIndex;

		//While the left child is within the array
		while (leftChildIndex < size - 1)
		{
			maxChildIndex = (resultantArray[leftChildIndex] > resultantArray[righChildIndex]) ? leftChildIndex : righChildIndex;

			//Compare max child with parent
			if (resultantArray[maxChildIndex] > resultantArray[itr])
			{
				SwapElements(resultantArray[maxChildIndex], resultantArray[itr]);
				//Iterator now points to the swapped child position
				itr = maxChildIndex;
				leftChildIndex = GetLeftChild(itr);
				righChildIndex = GetRightChild(itr);
			}
			else
				break;
		}
	}


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
