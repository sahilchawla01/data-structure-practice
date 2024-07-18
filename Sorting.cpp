#include "Sorting.h"
#include <iostream>

void Sorting::BubbleSort(int arr[], int size)
{

	int flag = 0;
	int passNumber = 0;
	for (int i = 0; i < size - 1; i++)
	{
		//Before each pass, unset the flag
		flag = 0;
		//In the pass loop, decrement the condition check by "i", as after each pass, one element is sorted at the end
		for (int pass = 0; pass < size - 1 - i; pass++)
		{
			if (arr[pass] > arr[pass + 1]) //If element is greater than next element, swap
			{
				Swap(arr[pass], arr[pass + 1]);
				flag = 1;
			}

			passNumber++;
		}

		if (flag == 0) //After the pass if not swapping was done, that means array already sorted
		{
			std::cout << "\nArray is already sorted at pass number: " << passNumber <<". Returning..";
			return;
		}
	}
}

void Sorting::InsertionSort(int arr[], int size)
{
	// -- PSEUDO CODE --
	// 1) In a loop, Start from the 1st index, assume 0th index is already in sorted sub-array, all other elements are in unsorted sub-array
	// 2) Have another iterator, in each loop, points to the last index of the sorted sub array 
	// 3) Temporarily store element to "insert" in sorted sub-array
	// 4) In another loop, while sorted pointer is greater than -1, and the current element of sorted sub-array is > than temp, shift that element ahead
	// 5)Decrement sorted iterator
	// 6)After loop end, store temp at current sorted iterator
	// 
	
	//We assume that 0th index (first element) is already inserted (already sorted) i.e in the sorted sub-array
	for (int i = 1; i < size; i++)
	{
		//j represents the last index of the sorted sub-array
		int j = i - 1;
		//Also temporarily store element to insert
		int temp = arr[i];
		//While the elements in resultant array are greater, shift them ahead
		while (j > -1 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		//Finally, having found the position for insertion of the element, insert it
		arr[j + 1] = temp;
	}
}

void Sorting::SelectionSort(int arr[], int size)
{
	/* -- PSEUDO CODE --
	* 1) Start the main loop, with iterator 'i'
	* 2) "Select" the "i" index, and search through the entire unsorted array to find the minimum element 
	* 3) Start a secondary loop from 'ith' index with the goal to find index of minimum element
	* 4) Have two pointers (iterators for array index), one for doing a pass, another for min element index
	* 5) Initialise min element index to current main iterator
	* 6) In loop, compare pass and min element element, if pass element smaller, update min element index to current pass index
	* 7) After loop, swap min element index element and current main iterator element
	* 5) Go to next iteration
	*/

	//Assume, to sort in ascending order
	for (int itr = 0; itr < size - 1; itr++)
	{
		int passMinimumIndex = itr;

		for (int passItr = itr; passItr < size; passItr++)
		{
			if (arr[passItr] < arr[passMinimumIndex])
			{
				passMinimumIndex = passItr;
			}
				
		}

		Swap(arr[itr], arr[passMinimumIndex]);
	}
}

void Sorting::QuickSort(int arr[], int size)
{
}

int Sorting::QuickSortPartition(int arr[], int low, int high)
{
	int pivot = arr[low];
	int i = low; 
	int j = high;

	do
	{
		do { i++; } while (arr[i] <= pivot);
		do { j--; } while (arr[j] > pivot);

		if (i < j)
			Swap(arr[i], arr[j]);
	} while (i < j);

	Swap(arr[low], arr[j]);
	
	return j;
}

void Sorting::QuickSortRecursive(int arr[], int low, int high)
{
	int partitionPos;

	if (low < high)
	{
		partitionPos = QuickSortPartition(arr, low, high);
		QuickSortRecursive(arr, low, partitionPos);
		QuickSortRecursive(arr, partitionPos + 1, high);
	}
}

void Sorting::Swap(int& element1, int& element2)
{
	int temp = element1;

	element1 = element2;
	element2 = temp;
}
