#include <iostream>
#include <map>
#include <unordered_map>
#include <stdlib.h> 
#include "CustomStack.h"
#include "LinkedList.h"
#include "DoubleLinkedList.h"
#include "Queue.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "Heap.h"
#include "Graph.h"
#include "HashMap.h"
#include "Sorting.h"

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

			//DeleteMax node
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
		std::cout << "\n~~~~~~~~~~~~~~~~~Single Linked List Choice~~~~~~~~~~~~~~~\nChoose the method to test:\n\t-1)Exit\n\t1)Traversal\n\t2)Search\n\t3)Insertion at the beginning\n\t4)Insertion at the end\n\t5)Insertion at a position\n\t6) Deletion of a node\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

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
		{
			int valueToBeInserted = 0;
			int position = 0;
			std::cout << "Insert value :";
			std::cin >> valueToBeInserted;
			std::cout << "Insert position (Range: 1 to Infinity):";
			std::cin >> position;

			if (position < 1)
			{
				std::cout << "\nError, enter a position between 1 and infinity only";
				break;
			}
			singleCircularLinkedListClass->InsertAtPosition(&head, valueToBeInserted, position);
			break;
		}
		case 6:
		{
			int valueToBeDeleted = 0;
			std::cout << "\nInsert value to be deleted" << std::endl;
			std::cin >> valueToBeDeleted;

			//Delete the node
			singleCircularLinkedListClass->DeleteNode(&head, valueToBeDeleted);

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

void TestBinaryTree()
{
	//Create the tree
	BinaryTree* tree = new BinaryTree();

	//Create empty root node
	BTNode* root = nullptr;

	system("cls");

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~BINARY TREE MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Insert Value\n\t2)(Recursive)Pre-Order Traversal\n\t3)(Recursive)Post-Order Traversal\n\t4)(Recursive) In-Order Traversal\n\t5)(Non-Recursive)Pre-Order Traversal\n\t6)(Non-Recursive)[NOT IMPLEMENTED] Post-Order Traversal\n\t7)(Non-Recursive) In-Order Traversal\n\t8)Level-Order Traversal (BFS)\n\t9)[NOT IMPLEMENTED] Delete an element in the Binary Tree\n\t10)Find total number of elements\n\t11)Find leaf nodes of tree\n\t12)Find height of the tree\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			std::cout << "\nEnter a value to insert into binary tree: ";
			int valueToPush = -1;
			std::cin >> valueToPush;

			tree->InsertByLevelOrderTraversal(&root, valueToPush);
			break;
		}
		case 2:
		{
			std::cout << "\nPerforming recursive pre-order traversal: ";
			tree->RecursivePreOrderTraversal(root);
			break;
		}
		case 3:
		{
			std::cout << "\nPerforming recursive post-order traversal: ";
			tree->RecursivePostOrderTraversal(root);
			break;
		}
		case 4:
		{
			std::cout << "\nPerforming recursive in-order traversal: ";
			tree->RecursiveInOrderTraversal(root);
			break;
		}
		case 5:
		{
			std::cout << "\nPerforming non-recursive pre-order traversal: ";
			tree->NonRecursivePreOrderTraversal(root);
			break;
		}
		case 6:
		{
			//std::cout << "\nPerforming non-recursive post-order traversal: ";
			//tree->NonRecursivePostOrderTraversal(root);
			break;
		}
		case 7:
		{
			std::cout << "\nPerforming non-recursive in-order traversal: ";
			tree->NonRecursiveInOrderTraversal(root);
			break;
		}
		case 8:
		{
			std::cout << "\nPeforming level-order traversal (BFS): ";
			tree->LevelOrderTraversal(root);
			break;
		}
		case 9:
		{
			int valueToDelete = -1;
			std::cout << "\nEnter the node you want to delete" << std::endl;
			std::cin >> valueToDelete;

			tree->DeleteElement(&root, valueToDelete);
			break;
		}
		case 10:
		{
			int totalCount = 0;

			totalCount = tree->Count(root);

			std::cout << "\nTotal number of the elements: " << totalCount;
			break;
		}
		case 11:
		{
			int totalCount = 0;

			totalCount = tree->CountLeafNodes(root);

			std::cout << "\nTotal leaf-nodes of the binary Tree: " << totalCount;
			break;
		}
		case 12:
		{
			int totalCount = 0;

			totalCount = tree->CalcHeight(root);

			std::cout << "\nTotal height of the binary Tree: " << totalCount;
			break;
			
		}
		default:
		{
			std::cout << "\nError, enter a number between 1 and 8";
		}
		}
	}

}

void TestBinarySearchTree()
{
	//Create the tree
	BinarySearchTree* tree = new BinarySearchTree();

	//Create empty root node
	BSTNode* root = nullptr;

	system("cls");

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~BINARY SEARCH TREE MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Insert Value\n\t2)Level-Order Traversal (BFS)\n\t3)In-order traversal\n\t4)Delete an element\n\t5)GenerateTreeFromPreOrder [NOT IMPLEMENTED]\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

		std::cin >> choice;

		switch (choice)
		{
			case 0:
			{
				return;
			}
			case 1:
			{
				std::cout << "\nEnter a value to insert into binary tree: ";
				int valueToPush = -1;
				std::cin >> valueToPush;

				tree->Insert(&root, valueToPush);
				break;
			}
			case 2:
			{
				tree->LevelOrderTraversal(root);
				break;
			}
			case 3:
			{
				tree->InOrderTraversal(root);
				break;
			}
			case 4:
			{
				std::cout << "\nEnter a value to delete from binary tree: ";
				int valueToDelete = -1;
				std::cin >> valueToDelete;

				tree->Delete(&root, valueToDelete);
				break;
			}
			default:
			{
				break;
			}
		}
	}
}

void TestHeap()
{
	Heap* heap = new Heap(100);

	system("cls");

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~HEAP MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Create a max Heap\n\t2)Insert a key in Max Heap\n\t3)Display Max Heap\n\t4)Delete max value\n\t5)Perform heap sort\n\t6)Heapify (faster creation of max heap)\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

		std::cin >> choice;
		switch (choice) 
		{
			case 0:
			{
				return;
			}
			case 1:
			{
				//Initialise heap data array
				int newArr[] = { 10, 20, 30, 25, 5, 40, 35 };

				//Clear the heap 
				heap->DeleteEntireMaxHeap();

				for (int i = 0; i < sizeof(newArr) / sizeof(newArr[0]); i++)
				{
					heap->InsertInMaxHeap(newArr[i]);
				}
				break;
			}
			case 2:
			{
				int key;
				std::cout << "\nInsert a key: ";
				std::cin >> key;

				heap->InsertInMaxHeap(key);
				break;
			}
			case 3:
			{
				heap->DisplayMaxHeap();
				break;
			}
			case 4:
			{
				int deletedValue = heap->DeleteMax();

				std::cout << deletedValue;
				break;
			}
			case 5:
			{
				//Initialise new array to get heap sort of
				int newArr[] = { 40, 20, 15, 60, 45, 50, 5, 70, 100};

				int size = sizeof(newArr) / sizeof(newArr[0]);

				std::cout << "\nArray before heap sorting: ";
				for (int i = 0; i < size; i++) std::cout << newArr[i] << ", ";

				heap->HeapSort(newArr, size);

				for (int i = 0; i < size; i++) std::cout << newArr[i] << ", ";
				break;
			}
			case 6:
			{
				//Initialise new array to get heap sort of
				//int newArr[] = { 40, 20, 15, 60, 45, 50, 5, 70, 100 };
				int newArr[] = {1,8,6,2,3,5};

				int size = sizeof(newArr) / sizeof(newArr[0]);
				std::cout << "\nArray before heapify: ";

				for (int i = 0; i < size; i++) std::cout << newArr[i] << ", ";

				//Perform heapify
				heap->Heapify(newArr, size);

				std::cout << "\nArray after heapify:";
				for (int i = 0; i < size; i++) std::cout << newArr[i] << ", ";
				break;
			}
			default:
			{
			}
		}
	}

}

void TestChainingHashMap()
{
	system("cls");

	ChainingHashMap* hashMap = new ChainingHashMap(10);


	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~CHAINING HASH MAP MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Insert\n\t2)Search\n\t3)Display Entire Hash Table\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		
		std::cin >> choice;

		switch (choice)
		{
			case 0:
			{
				return;
			}
			case 1:
			{
				std::cout << "\nInsert an element to put in the hash map: ";
				int value;
				std::cin >> value;
				hashMap->Put(value);
				break;
			}
			case 2:
			{
				std::cout << "\nInsert an element to search in the hash map: ";
				int value;
				std::cin >> value;
				hashMap->Search(value);
				break;
			}
			case 3:
			{
				hashMap->TestDisplayHashMap();
				break;
			}
			default:
			{

			}
		}
	}
}

void TestLinearProbingHashMap()
{
	system("cls");

	LinearProbingHashMap* hashMap = new LinearProbingHashMap(10);

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~LINEAR PROBING HASH MAP MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Insert\n\t2)Search\n\t3)Display Entire Hash Table\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

		std::cin >> choice;

		switch (choice)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			std::cout << "\nInsert an element to put in the hash map: ";
			int value;
			std::cin >> value;
			hashMap->Put(value);
			break;
		}
		case 2:
		{
			std::cout << "\nInsert an element to search in the hash map: ";
			int value;
			std::cin >> value;
			hashMap->Search(value);
			break;
		}
		case 3:
		{
			hashMap->TestDisplayHashMap();
			break;
		}
		default:
		{

		}
		}
	}
}

void TestGraph()
{
	system("cls");

	std::cout << "\nTo start, how many vertices in your graph?: ";
	int numVertices;
	std::cin >> numVertices;

	Graph* graph = new Graph(numVertices);

	//Now, create the graph

	system("cls");


	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~GRAPH MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Display the graph\n\t2)Perform BFS traversal\n\t3)Perform DFS traversal\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

		std::cin >> choice;
		switch (choice)
		{
		case 0:
		{
			return;
		}
		case 1:
		{
			graph->DisplayGraph();
			break;
		}
		case 2:
		{
			graph->PerformBFS();
			break;
		}
		case 3:
		{
			system("cls");
			
			graph->StartDFS();
			break;
		}
		default:
		{

		}
		}
	}
}

void TestSorting()
{
	system("cls");

	Sorting sorter;

	int choice = -1;
	while (choice != 0)
	{
		std::cout << "\n~~~~~~~~~~~~~~~~~~~~SORTING MENU~~~~~~~~~~~~~~~~~~~~\n\t0)Exit\n\t1)Bubble Sort\n\t2)Insertion Sort\n\t3)Selection Sort\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

		std::cin >> choice;

		switch (choice)
		{
			case 0:
			{
				return;
			}
			case 1:
			{
				int arr[] = { 5, 100, 16, 34, 10, 4, 50 };
				
				int size =  sizeof(arr) / sizeof(arr[0]) ;

				std::cout << "Array before sorting: ";

				for (int element : arr)
					std::cout << element << ", ";

				std::cout << std::endl;

				sorter.BubbleSort(arr, size);

				std::cout << "\n\nArray after sorting: ";

				for (int element : arr)
					std::cout << element << ", ";

				break;
			}
			case 2:
			{
				int arr[] = { 5, 100, 16, 34, 10, 4, 50 };

				int size = sizeof(arr) / sizeof(arr[0]);

				std::cout << "Array before sorting: ";

				for (int element : arr)
					std::cout << element << ", ";

				std::cout << std::endl;

				sorter.InsertionSort(arr, size);

				std::cout << "\n\nArray after sorting: ";

				for (int element : arr)
					std::cout << element << ", ";
				break;
			}
			case 3:
			{
				int arr[] = { 5, 100, 16, 34, 10, 4, 50 };

				int size = sizeof(arr) / sizeof(arr[0]);

				std::cout << "Array before sorting: ";

				for (int element : arr)
					std::cout << element << ", ";

				std::cout << std::endl;

				sorter.SelectionSort(arr, size);

				std::cout << "\n\nArray after sorting: ";

				for (int element : arr)
					std::cout << element << ", ";
				break;
			}
			default:
			{

			}
		}
	}
}


int main()
{
	int choice = -1;
	while (choice != 0)
	{
		std::cout << "~~~~~~~~~~~~~~~~~~~~Data Structures MENU~~~~~~~~~~~~~~~~~~~~\nChoose the data structure to test:\n\t0) Exit\n\t1)Single Linked List\n\t2)Doubly Linked List\n\t3)Circular Linked List\n\t4)Stack\n\t5)Simple Queue\n\t6)Input-Restricted Queue\n\t7)Output-restricted Queue\n\t8)Double Ended Queue\n\t9)Simple binary tree\n\t10)Binary Search Tree\n\t11)Heap\n\t12)Graph\n\t13)ChainingHashMap\n\t14)Linear Probing Hash Map\n\t15)Sorting\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;

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
			case 9:
			{
				TestBinaryTree();
				break;
			}
			case 10:
			{
				TestBinarySearchTree();
				break;
			}
			case 11:
			{
				TestHeap();
				break;
			}
			case 12:
			{
				TestGraph();
				break;
			}
			case 13:
			{
				TestChainingHashMap();
				break;
			}
			case 14:
			{
				TestLinearProbingHashMap();
				break;
			}
			case 15:
			{
				TestSorting();
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