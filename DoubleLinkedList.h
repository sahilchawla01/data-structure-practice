#pragma once

#include <iostream>


struct DoubleLinkedListNode
{
	int val;
	DoubleLinkedListNode* next;
	DoubleLinkedListNode* prev;

	//Constructors
	DoubleLinkedListNode(int x) : val(x), next(nullptr), prev(nullptr) {};
	DoubleLinkedListNode(int x, DoubleLinkedListNode* prevNode, DoubleLinkedListNode* nextNode) : val(x), next(nextNode), prev(prevNode) {};
};

class DoubleLinkedListHelper
{
	public:

		void Traverse(DoubleLinkedListNode* head);
		void InsertAtBeginning(DoubleLinkedListNode* head, int newNodeValue);
		void InsertAtPosition(DoubleLinkedListNode* head, int position, int newNodeValue);
};

