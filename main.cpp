#include <iostream>
#include <map>
#include <unordered_map>
#include <stdlib.h> 
#include "LinkedList.h"

void TestLinkedList()
{
	//Initialise single linked list helper class
	LinkedList* singleLinkedListClass = new LinkedList();

	//Initialise a list
	Node* head = new Node(0);
	//Node* node1 = new Node(5);
	//Node* node2 = new Node(10);

	//head->next = node1;
	//node1->next = node2;

	//Clear the screen 
	system("cls");

	int choice = 0;

	while (choice != -1)
	{
		std::cout << "~~~~~~~~~~~~~~~~~Single Linked List Choice~~~~~~~~~~~~~~~\nChoose the method to test:\n\t-1)Exit\n\t1)Traversal\n\t2)Search\n\t3)Insertion at the beginning\n\t4)Insertion at the end\n\t5)Insertion at a position\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case -1: //Exit 
			return;

		case 1: //Test linked list traversal
		{
			singleLinkedListClass->traverseLinkedList(head);
			break;
		}
		case 2: //Test linked list searching
		{
			int valueToBeFound = 0;
			std::cout << "Insert value to be found:";
			std::cin >> valueToBeFound;

			singleLinkedListClass->search(head, valueToBeFound);
			break;
		}
		case 3: //Insertion at the beginning
		{
			int valueToBeInserted = 0;
			std::cout << "Insert value to be inserted at the beginning:";
			std::cin >> valueToBeInserted;

			singleLinkedListClass->insertAtStart(head, valueToBeInserted);
			break;
		}
		case 4: //Insertion at the end
		{
			int valueToBeInserted = 0;
			std::cout << "Insert value to be inserted at the end:";
			std::cin >> valueToBeInserted;

			singleLinkedListClass->insertAtEnd(head, valueToBeInserted);
			break;
		}
		case 5: //Insertion at the position
		{
			int valueToBeInserted = 0;
			int position = 0;
			std::cout << "Insert value :";
			std::cin >> valueToBeInserted;
			std::cout << "Insert position :";
			std::cin >> position;

			singleLinkedListClass->insertAtPosition(head, position, valueToBeInserted);
			break;
		}
		}
	}
}

int main()
{
	int choice = -1;
	while (choice != 0)
	{
		std::cout << "~~~~~~~~~~~~~~~~~~~~Data Structures MENU~~~~~~~~~~~~~~~~~~~~\nChoose the data structure to test:\n\t0) Exit\n\t1)Single Linked List\n\t2)Doubly Linked List\n\t3)Circular Linked List\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
			case 0:
			{
				return 0;
			}
			case 1:
			{
				TestLinkedList();
				break;
			}
			default:
			{
				std::cout << "\nError, choose something from the menu!!" << std::endl;
			}
		}
		
		//Clear the screen 
		system("cls");
	}


	return 0;
}