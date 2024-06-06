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

void LinkedList::DeleteAtPosition(Node* head, Node* nodeToBeDeleted)
{
	//If asked to delete node
	if (nodeToBeDeleted == head)
	{
		//Get next node
		Node* newHead = head->next;

		if (!newHead)
		{
			std::cout << "\nLinked list is empty.. Deleting head.." << std::endl;
			free(head);
			return;
		}

		//Head is deleted
		free(head);
		//Next node becomes new head
		head = newHead;
	}

}

void CircularLinkedList::InsertAtStart(Node** head, int ValueToBeInserted)
{
	Node* newNode = new Node(ValueToBeInserted);

	//Point new node to first node
	newNode->next = (*head)->next;
	//Point head to new Node
	(*head)->next = newNode;

	std::cout << "\nInserted a value at the start!" << std::endl;
}

void CircularLinkedList::InsertAtEnd(Node* head, int ValueToBeInserted)
{
	//New node
	Node* newNode = new Node(ValueToBeInserted);

	Node* temp = head;

	while (temp->next != head)
	{
		temp = temp->next;
	}

	//New node points to head
	newNode->next = head;
	//Last node points to new node
	temp->next = newNode;

	std::cout << "\nValue inserted at the end!";
	
}

void CircularLinkedList::TraverseLinkedList(Node* head)
{
	Node* curr = head;

	std::cout << "\nTraversing head node, starting traversal.." << std::endl;
	curr = curr->next;

	while (curr != head)
	{
		std::cout << "\n Next node traversed has a value of: " << curr->val << std::endl;
		//Traverse to next
		curr = curr->next;
	}
}

Node** CircularLinkedList::Search(Node** head, int ValueToBeSearched)
{
	//Create temporary pointer
	Node** temp = head;

	//Traverse the head if not empty,
	if ((*head)->next == *head)
	{
		std::cout << "\nList was empty";
		return nullptr;
	}

	//Traverse the head
	temp = &((*temp)->next);

	while (*temp != *head)
	{
		//If we have found the value, return
		if ((*temp)->val == ValueToBeSearched)
		{
			std::cout << "\nValue was found! Returning node" << std::endl;
			return temp;
		}

		//Get address to the next node
		temp = &((*temp)->next);
	}

	std::cout << "\nError, couldn't find value.." << std::endl;

	return nullptr;
}

void CircularLinkedList::DeleteNode(Node** head, Node** nodeToBeDeleted)
{

	//If list is empty
	if (head == nodeToBeDeleted)
	{
		std::cout << "\n List is empty.. Returning." << std::endl;
		return;
	}

	//Find the node before node to be deleted
	Node** prevNode = head;

	prevNode = &((*head)->next);
	
	while ((*prevNode)->next != *nodeToBeDeleted)
	{
		if (prevNode == head)
		{
			std::cout << "\nCouldn't find deleted node's prev node.. Returning" << std::endl;
			return;
		}

		prevNode = &((*prevNode)->next);

	}

	std::cout << "\nNode before deleted node has a value of" << (*prevNode)->val;

	//Store the next node of nodeToBeDeleted
	Node** nextNode = &((*nodeToBeDeleted)->next);

	std::cout << "\nNode after deleted node has a value of" << (*nextNode)->val;

	if (nextNode == nullptr)
	{
		std::cout << "\nThere wasn't a linked node after node that we're deleting.. Returning" << std::endl;
		return;
	}

	//Points prev node to next node
	(*prevNode)->next = *nextNode;
	//Remove the link of nodeToBeDeleted
	(*nodeToBeDeleted)->next = nullptr;

	free(*nodeToBeDeleted);

	
}
