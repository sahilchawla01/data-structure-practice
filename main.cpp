#include <iostream>
#include <map>
#include <unordered_map>
#include <stdlib.h> 
#include "CustomStack.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "Queue.h"

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

void TestStack()
{
	//Create the stack
	CustomStack* stack = new CustomStack();

	//Clear the screen 
	system("cls");

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~STACK MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Push\n\t2)Pop\n\t3)Peek\n\t4)Is stack full?\n\t5)Is stack empty?\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
			case 0:
			{
				return;
			}
			case 1:
			{
				std::cout << "\nEnter a value to push onto the stack: ";
				int valueToPush = -1;
				std::cin >> valueToPush;

				stack->Push(valueToPush);

				break;
			}
			case 2:
			{
				int poppedValue = -1;

				poppedValue = stack->Pop();

				std::cout << "\nValue popped: " << poppedValue;
				break;
			}
			case 3:
			{
				int topValue = -1;

				topValue = stack->Peek();

				std::cout << "\nTop value is : " << topValue;
				break;
			}
			case 4:
			{
				bool bStackFull = stack->IsFull();

				std::cout << "\nIs stack full: " << bStackFull << std::endl;
				break;
			}
			case 5:
			{
				bool bStackEmpty = stack->IsEmpty();

				std::cout << "\nIs stack empty: " << bStackEmpty << std::endl;
				break;
			}
			default:
			{
				std::cout << "\nError, enter a number between 1 and 5";
			}
		}
	}
}

void TestQueue()
{
	//Create the stack
	Queue* queue = new Queue();

	//Clear the screen 
	system("cls");

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~QUEUE MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Enqueue\n\t2)Dequeue\n\t3)Front\n\t4)Rear\n\t5)Is queue full\n\t6)Is queue empty?\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			std::cout << "\nEnter a value to push onto the queue: ";
			int valueToPush = -1;
			std::cin >> valueToPush;

			queue->Enqueue(valueToPush);

			break;
		}
		case 2:
		{
			int poppedValue = -1;

			poppedValue = queue->Dequeue();

			std::cout << "\nDequeued Value: " << poppedValue;
			break;
		}
		case 3:
		{
			int topValue = -1;

			topValue = queue->Front();

			std::cout << "\nFront value is: " << topValue;
			break;
		}
		case 4:
		{
			int rearValue = -1;

			rearValue = queue->Rear();

			std::cout << "\nRear value is: " << rearValue;
			break;
		}
		case 5:
		{
			bool bQueueFull = queue->IsFull();

			std::cout << "\nIs queue full: " << bQueueFull << std::endl;
			break;
		}
		case 6:
		{
			bool bQueueEmpty = queue->IsEmpty();

			std::cout << "\nIs queue empty: " << bQueueEmpty << std::endl;
			break;
		}
		default:
		{
			std::cout << "\nError, enter a number between 1 and 5";
		}
		}
	}
}

void TestInputRestrictedQueue()
{
	//Create the stack
	InputRestrictedQueue* queue = new InputRestrictedQueue();

	//Clear the screen 
	system("cls");

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~INPUT-RESTRICTED QUEUE MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Enqueue\n\t2)Dequeue\n\t3)Dequeue_back\n\t4)Front\n\t5)Rear\n\t6)Is queue full\n\t7)Is queue empty?\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			std::cout << "\nEnter a value to push onto the queue: ";
			int valueToPush = -1;
			std::cin >> valueToPush;

			queue->Enqueue(valueToPush);

			break;
		}
		case 2:
		{
			int poppedValue = -1;

			poppedValue = queue->Dequeue();

			std::cout << "\nDequeued Value: " << poppedValue;
			break;
		}
		case 3:
		{
			int poppedValue = -1;

			poppedValue = queue->Dequeue_Back();

			std::cout << "\nDequeued_Back Value: " << poppedValue;
			break;
		}
		case 4:
		{
			int topValue = -1;

			topValue = queue->Front();

			std::cout << "\nFront value is: " << topValue;
			break;
		}
		case 5:
		{
			int rearValue = -1;

			rearValue = queue->Rear();

			std::cout << "\nRear value is: " << rearValue;
			break;
		}
		case 6:
		{
			bool bQueueFull = queue->IsFull();

			std::cout << "\nIs queue full: " << bQueueFull << std::endl;
			break;
		}
		case 7:
		{
			bool bQueueEmpty = queue->IsEmpty();

			std::cout << "\nIs queue empty: " << bQueueEmpty << std::endl;
			break;
		}
		default:
		{
			std::cout << "\nError, enter a number between 1 and 5";
		}
		}
	}
}

void TestOutputRestrictedQueue()
{
	//Create the stack
	OutputRestrictedQueue* queue = new OutputRestrictedQueue();

	//Clear the screen 
	system("cls");

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~OUTPUT-RESTRICTED QUEUE MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Enqueue\n\t2)Dequeue\n\t3)Enqueue_front\n\t4)Front\n\t5)Rear\n\t6)Is queue full\n\t7)Is queue empty?\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			std::cout << "\nEnter a value to push onto the queue: ";
			int valueToPush = -1;
			std::cin >> valueToPush;

			queue->Enqueue(valueToPush);

			break;
		}
		case 2:
		{
			int poppedValue = -1;

			poppedValue = queue->Dequeue();

			std::cout << "\nDequeued Value: " << poppedValue;
			break;
		}
		case 3:
		{
			std::cout << "\nEnter a value to push onto the queue: ";

			int valueToPush = -1;
			std::cin >> valueToPush;

			queue->Enqueue_Front(valueToPush);

			break;
		}
		case 4:
		{
			int topValue = -1;

			topValue = queue->Front();

			std::cout << "\nFront value is: " << topValue;
			break;
		}
		case 5:
		{
			int rearValue = -1;

			rearValue = queue->Rear();

			std::cout << "\nRear value is: " << rearValue;
			break;
		}
		case 6:
		{
			bool bQueueFull = queue->IsFull();

			std::cout << "\nIs queue full: " << bQueueFull << std::endl;
			break;
		}
		case 7:
		{
			bool bQueueEmpty = queue->IsEmpty();

			std::cout << "\nIs queue empty: " << bQueueEmpty << std::endl;
			break;
		}
		default:
		{
			std::cout << "\nError, enter a number between 1 and 5";
		}
		}
	}
}

void TestDeQueue()
{
	//Create the stack
	DoubleQueue* queue = new DoubleQueue();

	//Clear the screen 
	system("cls");

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~DEQUEUE MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Enqueue\n\t2)Enqueue_front\n\t3)Dequeue\n\t4)Dequeue_Back\n\t5)Front\n\t6)Rear\n\t7)Is queue full\n\t8)Is queue empty?\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			std::cout << "\nEnter a value to push onto the queue: ";
			int valueToPush = -1;
			std::cin >> valueToPush;

			queue->Enqueue(valueToPush);

			break;
		}
		case 2:
		{
			std::cout << "\nEnter a value to push onto the queue from the front: ";
			int valueToPush = -1;
			std::cin >> valueToPush;

			queue->Enqueue_Front(valueToPush);

			break;
		}
		case 3:
		{
			int poppedValue = -1;

			poppedValue = queue->Dequeue();

			std::cout << "\nDequeued Value: " << poppedValue;
			break;
		}
		case 4:
		{
			int poppedValue = -1;

			poppedValue = queue->Dequeue_Back();

			std::cout << "\nDequeued Value: " << poppedValue;
			break;
		}
		case 5:
		{
			int topValue = -1;

			topValue = queue->Front();

			std::cout << "\nFront value is: " << topValue;
			break;
		}
		case 6:
		{
			int rearValue = -1;

			rearValue = queue->Rear();

			std::cout << "\nRear value is: " << rearValue;
			break;
		}
		case 7:
		{
			bool bQueueFull = queue->IsFull();

			std::cout << "\nIs queue full: " << bQueueFull << std::endl;
			break;
		}
		case 8:
		{
			bool bQueueEmpty = queue->IsEmpty();

			std::cout << "\nIs queue empty: " << bQueueEmpty << std::endl;
			break;
		}
		default:
		{
			std::cout << "\nError, enter a number between 1 and 5";
		}
		}
	}
}


int main()
{
	int choice = -1;
	while (choice != 0)
	{
		std::cout << "~~~~~~~~~~~~~~~~~~~~Data Structures MENU~~~~~~~~~~~~~~~~~~~~\nChoose the data structure to test:\n\t0) Exit\n\t1)Single Linked List\n\t2)Doubly Linked List\n\t3)Circular Linked List\n\t4)Stack\n\t5)Simple Queue\n\t6)Input-Restricted Queue\n\t7)Output-restricted Queue\n\t8)Double Ended Queue\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

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
			case 4:
			{
				TestStack();
				break;
			}
			case 5:
			{
				TestQueue();
				break;
			}
			case 6:
			{
				TestInputRestrictedQueue();
				break;
			}
			case 7:
			{
				TestOutputRestrictedQueue();
				break;
			}
			case 8:
			{
				TestDeQueue();
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