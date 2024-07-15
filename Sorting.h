#pragma once
class Sorting
{
public:

	void BubbleSort(int arr[], int size);
	void InsertionSort(int arr[], int size);
	void SelectionSort(int arr[], int size);
private:

	void Swap(int& element1, int& element2);
};

