#include "DoubleLinkedList.h"

void DoubleLinkedListHelper::Traverse(DoubleLinkedListNode* head)
{
	DoubleLinkedListNode* curr = head;

	//Traverse head node
	curr = curr->next;
	std::cout << "\nHead node traversed" << std::endl;

	while (curr != nullptr)
	{
		std::cout << "\nNext node traversed has a value of: " << curr->val << std::endl;
		//Traverse to next
		curr = curr->next;
	}
}

void DoubleLinkedListHelper::InsertAtBeginning(DoubleLinkedListNode* head, int newNodeValue)
{
	//Create a new node
	DoubleLinkedListNode* curr = new DoubleLinkedListNode(newNodeValue);

	//Store first node
	DoubleLinkedListNode* nextNode = head->next;

	//Header points to new node
	head->next = curr;
	
	//New node points to header and new next node
	curr->prev = head;
	curr->next = nextNode;

	//Next node didn't exist
	if (!nextNode) return;
	//Replace next node prev reference
	nextNode->prev = curr;
}

void DoubleLinkedListHelper::InsertAtPosition(DoubleLinkedListNode* head, int position, int newNodeValue)
{
	//Create new node
	DoubleLinkedListNode* curr = new DoubleLinkedListNode(newNodeValue);

	//If empty list, simply insert at first position
	if (head->next == nullptr)
	{
		head->next = curr;
		curr->prev = head;
		return;
	}

	if (position <= 0)
	{
		std::cout << "\nError!, Cannot inset a value at a position of 0 or less" << std::endl;
		return;
	}

	DoubleLinkedListNode* nodeToBeShiftedForward = head;

	int count = 0;
	//Traverse through list to find position
	while (nodeToBeShiftedForward->next != nullptr)
	{
		if (count == position) break;

		count++;
		nodeToBeShiftedForward = nodeToBeShiftedForward->next;
	}

	nodeToBeShiftedForward->prev->next = curr;

	curr->prev = nodeToBeShiftedForward->prev;
	curr->next = nodeToBeShiftedForward;

	nodeToBeShiftedForward->prev = curr;

	std::cout << "\nValue Inserted!" << std::endl;
}
