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

	void insertAtStart(Node** head, int valueToBeAdded);
	void insertAtEnd(Node** head, int valueToBeInserted);
	void insertAtPosition(Node** head, int position, int valueToBeInserted);
	void traverseLinkedList(Node* head);
	Node* search(Node* head, int valueToBeSearched);
	void DeleteAtPosition(Node** head, Node** nodeToBeDeleted);
};

class CircularLinkedList
{
public:
	void InsertAtStart(Node** head, int ValueToBeInserted);
	void InsertAtEnd(Node* head, int ValueToBeInserted);
	// 0 <= positionToInsert < Infinity 
	void InsertAtPosition(Node** head, int valueToInsert, int positionToInsert);
	void TraverseLinkedList(Node* head);
	Node** Search(Node** head, int ValueToBeSearched);
	void DeleteNode(Node** head, int ValueToBeDeleted);
};

