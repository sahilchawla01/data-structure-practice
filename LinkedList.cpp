#include "LinkedList.h"
#include <iostream>


void LinkedList::insertAtStart(Node* head, int valueToBeAdded)
{
	//Create the node with new value
	Node* curr = new Node(valueToBeAdded);

	//Point curr to the last first node
	curr->next = head->next;

	//Point head to the new first node, curr
	head->next = curr;

	std::cout << "Value was inserted!" << std::endl;
}

void LinkedList::insertAtEnd(Node* head, int valueToBeInserted)
{
	//Create new node
	Node* curr = new Node(valueToBeInserted);

	Node* pointerNode = head;
	//Traverse to the end and store end node, point end node to new node
	while (pointerNode->next != nullptr)
	{
		pointerNode = pointerNode->next;
	}

	pointerNode->next = curr;

	std::cout << "Value was inserted!" << std::endl;
}

void LinkedList::insertAtPosition(Node* head, int position, int valueToBeInserted)
{
	//Create the new node
	Node* curr = new Node(valueToBeInserted);

	//If empty, insert at beginning
	if (head->next == nullptr)
	{
		head->next = curr;

		std::cout << "Value was inserted!" << std::endl;
		return;
	}

	//If position is zero, give error
	if (position == 0)
	{
		std::cout << "Error, only values of 1 and above are accepted!" << std::endl;
		return;
	}

	//Traverse till position
	int count = 0;

	//Point to the head node
	Node* pointerNode = head;

	while (pointerNode->next != nullptr)
	{
		if (count == position - 1) break;

		pointerNode = pointerNode->next;
		count++;
	}

	//If end of linked list reached, simply add it to the end
	if (!pointerNode->next)
	{
		pointerNode->next = curr;

		std::cout << "Value was inserted!" << std::endl;

		return;
	}

	//Store next pointer 
	Node* newNextNode = pointerNode->next;

	//Point position - 1 pointer to new node
	pointerNode->next = curr;
	//Point new node to next new pointer
	curr->next = newNextNode;

	std::cout << "Value was inserted!" << std::endl;
	
}

void LinkedList::traverseLinkedList(Node* head)
{
	Node* curr = head;

	while (curr != nullptr)
	{
		std::cout << "\n Next node traversed has a value of: " << curr->val << std::endl;
		//Traverse to next
		curr = curr->next;
	}
}

Node* LinkedList::search(Node* head, int valueToBeSearched)
{
	Node* curr = head;

	int index = 0;
	while (curr != nullptr)
	{
		//Check if value is found, if so return pointer
		if (valueToBeSearched == curr->val)
		{
			std::cout << "Value:" << valueToBeSearched << " was found at the index :" << index << std::endl;
			return curr;
		}

		curr = curr->next;
		index++;
	}

	std::cout << "Value was not found" << std::endl;


	return nullptr;
}
