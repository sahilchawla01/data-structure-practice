#pragma once
class Sorting
{
public:

	void BubbleSort(int arr[], int size);
	void InsertionSort(int arr[], int size);
	void SelectionSort(int arr[], int size);
	void QuickSort(int arr[], int size);
	int QuickSortPartition(int arr[], int low, int high);
	void QuickSortRecursive(int arr[], int low, int high);
private:

	void Swap(int& element1, int& element2);
};

