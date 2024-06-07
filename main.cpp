#include <iostream>
#include <map>
#include <unordered_map>
#include <stdlib.h> 
#include "LinkedList.h"
#include "DoubleLinkedList.h"

void TestLinkedList()
{
	//Initialise single linked list helper class
	LinkedList* singleLinkedListClass = new LinkedList();

	//Initially the linked list is empty
	Node* head = nullptr;
	
	//Clear the screen 
	system("cls");

	int choice = 0;

	while (choice != -1)
	{
		std::cout << "~~~~~~~~~~~~~~~~~Single Linked List Choice~~~~~~~~~~~~~~~\nChoose the method to test:\n\t-1)Exit\n\t1)Traversal\n\t2)Search\n\t3)Insertion at the beginning\n\t4)Insertion at the end\n\t5)Insertion at a position (Pos: starts from 0)\n\t6)Delete at position\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

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

			singleLinkedListClass->insertAtStart(&head, valueToBeInserted);
			break;
		}
		case 4: //Insertion at the end
		{
			int valueToBeInserted = 0;
			std::cout << "Insert value to be inserted at the end:";
			std::cin >> valueToBeInserted;

			singleLinkedListClass->insertAtEnd(&head, valueToBeInserted);
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

			singleLinkedListClass->insertAtPosition(&head, position, valueToBeInserted);
			break;
		}
		case 6: //Deletion at a position
		{
			int valueToBeDeleted = 0;
			std::cout << "Insert value to be deleted";
			std::cin >> valueToBeDeleted;

			//Search for node
			Node* nodeToBeDeleted = singleLinkedListClass->search(head, valueToBeDeleted);

			//Delete node
			singleLinkedListClass->DeleteAtPosition(&head, &nodeToBeDeleted);
			break;
		}
		}
	}
}

void TestDoubleLinkedList()
{
	//Initialise double linked list helper class
	DoubleLinkedListHelper* DoubleLinkedListHelperObj = new DoubleLinkedListHelper();
	//Initialise a new double linked list
	DoubleLinkedListNode* head = new DoubleLinkedListNode(0);

	//Clear the screen 
	system("cls");

	int choice = 0;

	while (choice != -1)
	{
		std::cout << "~~~~~~~~~~~~~~~~~Double Linked List Choice~~~~~~~~~~~~~~~\nChoose the method to test:\n\t-1)Exit\n\t1)Traversal\n\t2)Search [Not Implemented]\n\t3)Insertion at the beginning\n\t4)Insertion at a position\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case -1: //Exit 
			return;

		case 1: //Test linked list traversal
		{
			DoubleLinkedListHelperObj->Traverse(head);
			break;
		}
		case 3: //Insertion at the beginning
		{
			int valueToBeInserted = 0;
			std::cout << "Insert value to be inserted at the beginning:";
			std::cin >> valueToBeInserted;

			DoubleLinkedListHelperObj->InsertAtBeginning(head, valueToBeInserted);
			break;
		}
		case 4: //Insertion at the position
		{
			int valueToBeInserted = 0;
			int position = 0;
			std::cout << "Insert value :";
			std::cin >> valueToBeInserted;
			std::cout << "Insert position :";
			std::cin >> position;

			DoubleLinkedListHelperObj->InsertAtPosition(head, position, valueToBeInserted);
			break;
		}
		}
	}
}

void TestCircularLinkedList()
{
	//Initialise single linked list helper class
	CircularLinkedList* singleCircularLinkedListClass = new CircularLinkedList();

	//Initialise a list
	Node* head = new Node(0);
	head->next = head;


	//Clear the screen 
	system("cls");

	int choice = 0;

	while (choice != -1)
	{
		std::cout << "~~~~~~~~~~~~~~~~~Single Linked List Choice~~~~~~~~~~~~~~~\nChoose the method to test:\n\t-1)Exit\n\t1)Traversal\n\t2)Search\n\t3)Insertion at the beginning\n\t4)Insertion at the end\n\t5)Insertion at a position[NOT IMPLEMENTED]\n\t6) Deletion of a node\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case -1: //Exit 
			return;

		case 1: //Test linked list traversal
		{
			singleCircularLinkedListClass->TraverseLinkedList(head);
			break;
		}
		case 2: //Test linked list searching
		{
			int valueToBeFound = 0;
			std::cout << "Insert value to be found:";
			std::cin >> valueToBeFound;

			singleCircularLinkedListClass->Search(&head, valueToBeFound);
			break;
		}
		case 3: //Insertion at the beginning
		{
			int valueToBeInserted = 0;
			std::cout << "Insert value to be inserted at the beginning:";
			std::cin >> valueToBeInserted;

			singleCircularLinkedListClass->InsertAtStart(&head, valueToBeInserted);
			break;
		}
		case 4: //Insertion at the end
		{
			int valueToBeInserted = 0;
			std::cout << "Insert value to be inserted at the end:";
			std::cin >> valueToBeInserted;

			singleCircularLinkedListClass->InsertAtEnd(head, valueToBeInserted);
			break;
		}
		case 5: //Insertion at the position
		{/*
			int valueToBeInserted = 0;
			int position = 0;
			std::cout << "Insert value :";
			std::cin >> valueToBeInserted;
			std::cout << "Insert position :";
			std::cin >> position;

			singleCircularLinkedListCla ss->insertAtPosition(head, position, valueToBeInserted);
			*/
			break;
		}
		case 6:
		{
			int valueToBeDeleted = 0;
			std::cout << "\nInsert value to be deleted" << std::endl;
			std::cin >> valueToBeDeleted;

			//First find that node
			Node** nodeToBeDeleted = singleCircularLinkedListClass->Search(&head, valueToBeDeleted);

			if (nodeToBeDeleted == nullptr)
			{
				std::cout << "\nCouldn't find node to be deleted.. Returning" << std::endl;
				break;
			}

			//Delete the node
			singleCircularLinkedListClass->DeleteNode(&head, nodeToBeDeleted);

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
			case 2:
			{
				TestDoubleLinkedList();
				break;
			}
			case 3:
			{
				TestCircularLinkedList();
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