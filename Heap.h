#pragma once


class Heap
{
public:

	Heap();
	Heap(int maxHeapSize);

	void InsertInMaxHeap(int key);
	void DisplayMaxHeap();
	int DeleteMax();
	void DeleteEntireMaxHeap();
	void Heapify(int resultantArray[], int size);
	void HeapSort(int resultantArray[], int size);

public:

	//The max possible heap size
	int maxHeapSize;
	//The actual heap size
	int heapSize;
	//The heap array
	int* arr;

private:
	/* -- HELPERS -- */
	void DisplayArr(int arr[], int size);
	int GetParent(int index);
	int GetLeftChild(int index);
	int GetRightChild(int index);
	bool IsFull();

	void SwapElements(int& element1, int& element2);

	bool bIsCreated = false;
};
