#pragma once

struct Node
{
	int val;
	Node* next;
	Node(int x) : val(x), next(nullptr) {};
};

class LinkedList
{
public:

	void insertAtStart(Node* head, int valueToBeAdded);
	void insertAtEnd(Node* head, int valueToBeInserted);
	void insertAtPosition(Node* head, int position, int valueToBeInserted);
	void traverseLinkedList(Node* head);
	Node* search(Node* head, int valueToBeSearched);
};

