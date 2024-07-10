#include "HashMap.h"
#include <iostream>

ChainingHashMap::ChainingHashMap(int inputHashSize)
{
	hashSize = inputHashSize;

	//Create array of given size
	hashTable = new ChainNode*[hashSize];

	//Initialse the pointer array to null
	for (int itr = 0; itr < inputHashSize; itr++)
		hashTable[itr] = nullptr;
}

void ChainingHashMap::Put(int element)
{
	//Check if element doesn't already exist
	if (Search(element))
	{
		std::cout << "\nElement already exists in hash map.. Returning.";
		return;
	}

	int hashIndex = Hash(element);

	ChainNode* temp = hashTable[hashIndex];
	ChainNode* newElementNode = new ChainNode(element);

	if (temp == nullptr)
	{
		hashTable[hashIndex] = newElementNode;
		std::cout << "\nHash index: " << hashIndex << " was empty, inserted new element directly";
		return;
	}

	//Traverse to last element
	while (temp->next != nullptr) temp = temp->next;

	//Put new element at the end
	temp->next = newElementNode;

	std::cout << "\nElement already existed at index.. Adding new element to a chain..";
}

bool ChainingHashMap::Search(int elementToSearch)
{
	int hashIndex = Hash(elementToSearch);

	if (hashTable[hashIndex] == nullptr)
	{
		std::cout << "\nElement: " << elementToSearch << " was not found.. Returning";
		return false;
	}

	//This means some element is there in that slot, traverse linked list and check if it exists

	ChainNode* temp = hashTable[hashIndex];
	while (temp != nullptr)
	{
		if (temp->value == elementToSearch)
		{
			std::cout << "\nElement was found..";
			return true;
		}
		temp = temp->next;
	}

	//At this point entire expected chain was traversed and node wasn't found
	return false;
}

void ChainingHashMap::Delete(int elementToDelete)
{
	std::cout << "\nDeleting Operation has begun...\n\n";

	//Check if the appropriate index is empty, if so, element doesn't exist
	int index = Hash(elementToDelete);

	if (!hashTable[index])
	{
		std::cout << "\nElement doesn't exist.. Returning..";
		return;
	}

	//Else, hashtable is not null, check the chain

	ChainNode* temp = hashTable[index];

	while (temp != nullptr)
	{

	}
}

void ChainingHashMap::TestDisplayHashMap()
{
	std::cout << "\nDisplaying:\n";

	for (int itr = 0; itr < hashSize; itr++)
	{
		if (hashTable[itr])
		{
			ChainNode* temp = hashTable[itr];
			while (temp != nullptr)
			{
				std::cout << temp->value << "->";
				temp = temp->next;
			}
		}
		else
			std::cout << "NULL";
		std::cout << std::endl;

	}
}

int ChainingHashMap::Hash(int element)
{
	//Current hash function is modulus 
	return element % hashSize;
}

LinearProbingHashMap::LinearProbingHashMap(int inputHashSize)
{
	hashSize = inputHashSize;
	hashTable = new int[inputHashSize];

	//Initialise all elements in hash table to -1
	for (int itr = 0; itr < hashSize; itr++)
	{
		hashTable[itr] = -1;
	}
}

void LinearProbingHashMap::Put(int element)
{
	int index = Hash(element);

	//If not occupied, simply place it
	if (hashTable[index] == -1)
	{
		hashTable[index] = element;
		std::cout << "\nInserted value.. No linear probing required..";
		return;
	}

	//Since occupied, probe and find next empty space
	index = Probe(element);

	hashTable[index] = element;

	std::cout << "\nInserted value.. Linear probing was required..";

}

bool LinearProbingHashMap::Search(int elementToSearch)
{
	int index = Hash(elementToSearch);

	//If not occupied, simply place it
	if (hashTable[index] == -1)
	{
		std::cout << "\nElement doesn't exist... Returning";
		return false;
	}

	if (hashTable[index] == elementToSearch)
	{
		std::cout << "\nElement exists.. Without linear probing.. Returning..";
		return true;
	}

	//Since occupied, probe and find next empty space
	int itr = 0;
	while (hashTable[(index + itr) % hashSize] != -1)
	{
		if (hashTable[(index + itr) % hashSize] == elementToSearch)
		{
			std::cout << "\nElement exists.. Linear probing was required..";
			return true;
		}
		itr++;
	}

	//Even after linear probing, empty space was reached.. meaning element doesn't exist
	std::cout << "\nElement doesn't exist.. Linear probing was required..";
	return false;
}

void LinearProbingHashMap::TestDisplayHashMap()
{
	std::cout << "\nDisplaying..\n\n";

	for (int itr = 0; itr < hashSize; itr++)
	{
		if (hashTable[itr] == -1)
		{
			std::cout << "X\n";
			continue;
		}
		std::cout << hashTable[itr] << "\n";
	}
}

int LinearProbingHashMap::Hash(int element)
{
	return element % hashSize;
}

int LinearProbingHashMap::Probe(int element)
{
	int index = Hash(element);
	
	int itr = 0;
	while (hashTable[(index + itr) % hashSize] != -1)
	{
		itr++;
	}

	return (index + itr) % hashSize;
}
