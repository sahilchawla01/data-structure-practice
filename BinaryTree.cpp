#include "BinaryTree.h"
#include <iostream>
#include <queue>
#include <stack>


void BinaryTree::RecursivePreOrderTraversal(BTNode* parentNode)
{
	if (parentNode == nullptr)
	{
		return;
	}

	//Visit sequence: Visit Current Node, Left Node, then Right Node
	std::cout << parentNode->data << ",";
	RecursivePreOrderTraversal(parentNode->leftChild);
	RecursivePreOrderTraversal(parentNode->rightChild);
}

void BinaryTree::RecursivePostOrderTraversal(BTNode* parentNode)
{
	if (parentNode == nullptr) return;

	//Visit sequence: Visit Left Node, then Right Node, then Current Node
	RecursivePostOrderTraversal(parentNode->leftChild);
	RecursivePostOrderTraversal(parentNode->rightChild);
	std::cout << parentNode->data << ",";
}

void BinaryTree::RecursiveInOrderTraversal(BTNode* parentNode)
{
	if (parentNode == nullptr) return;

	//Visit sequence: Visit Left Node, Current Node, then Right Node
	RecursiveInOrderTraversal(parentNode->leftChild);
	std::cout << parentNode->data << ",";
	RecursiveInOrderTraversal(parentNode->rightChild);
}

void BinaryTree::NonRecursivePreOrderTraversal(BTNode* parentNode)
{
	if (parentNode == nullptr) return;

	//Create a stack
	std::stack<BTNode*> nodeStack;

	BTNode* temp = parentNode;

	while (!nodeStack.empty())
	{
		while (temp != nullptr)
		{
			//Print the data:
			std::cout << "\nData: " << nodeStack.top()->data;

			//Go to left child
			nodeStack.push(temp->leftChild);
			temp = temp->leftChild;
		}

		if (nodeStack.top() == nullptr) return;

		//Go to right child
		temp = nodeStack.top();
		nodeStack.pop();

		temp = temp->rightChild;
	}
}

void BinaryTree::NonRecursivePostOrderTraversal(BTNode* parentNode)
{
	if (parentNode == nullptr) return;

	//Create a stack
	std::stack<BTNode*> nodeStack;

	BTNode* temp = parentNode;

	while (!nodeStack.empty())
	{
		//Traverse to the deepest left most node
		while (temp != nullptr)
		{
			nodeStack.push(temp);
			temp = temp->leftChild;
		}

		if (nodeStack.top() == nullptr) return;

		//Traverse the right node
		temp = nodeStack.top();
		nodeStack.pop();

		//Visit the node
		std::cout << temp->data << ",";

	}
}

void BinaryTree::NonRecursiveInOrderTraversal(BTNode* parentNode)
{
	if (parentNode == nullptr) return;

	//Create a stack
	std::stack<BTNode*> nodeStack;

	BTNode* temp = parentNode;

	while (!nodeStack.empty())
	{
		//Traverse to the deepest left most node
		while (temp != nullptr)
		{
			nodeStack.push(temp);
			temp = temp->leftChild;
		}

		if (nodeStack.top() == nullptr) return;

		//Traverse the right node
		temp = nodeStack.top();
		nodeStack.pop();

		//Visit the node
		std::cout << temp->data << ",";

		//Now that we've visited, go to the right of this node
		temp = temp->rightChild;


	}
}

void BinaryTree::InsertByLevelOrderTraversal(BTNode** rootNode, int value)
{
	BTNode* newNode = new BTNode(value);

	//Assign new node as root if root doesn't exist
	if (rootNode == nullptr || *rootNode == nullptr)
	{
		*rootNode = newNode;

		std::cout << "\nRoot node was null, assigning new value as root" << std::endl;
		return;
	}

	//Create a queue for traversal
	std::queue<BTNode*> NodeQueue;
	NodeQueue.push(*rootNode);

	while (!NodeQueue.empty())
	{
		//Store front-most node
		BTNode* temp = NodeQueue.front();
		NodeQueue.pop();

		//If left child empty, place the node
		if (temp->leftChild == nullptr)
		{
			temp->leftChild = newNode;
			std::cout << "\nInserted value!";
			return;
		}
		else //Push left child 
		{
			NodeQueue.push(temp->leftChild);
		}

		//If right child empty, place the node
		if (temp->rightChild == nullptr)
		{
			temp->rightChild = newNode;
			std::cout << "\nInserted value!";
			return;
		}
		else //Push right child 
		{
			NodeQueue.push(temp->rightChild);
		}
	}
	
}

void BinaryTree::LevelOrderTraversal(BTNode* rootNode)
{
	BTNode* temp = rootNode;

	//Declare a queue
	std::queue<BTNode*> TreeQueue;

	TreeQueue.push(temp);

	while (!TreeQueue.empty())
	{
		//Pop first element from queue
		temp = TreeQueue.front();
		TreeQueue.pop();

		if(temp != nullptr) std::cout << temp->data << ", ";
			
		if (temp->leftChild != nullptr)
		{
			//Push left child into queue
			TreeQueue.push(temp->leftChild);
		}

		if (temp->rightChild != nullptr)
		{
			//Push right child into queue
			TreeQueue.push(temp->rightChild);
		}
	}
}

void BinaryTree::DeleteElement(BTNode** rootNode, int valueToDelete)
{
	//Perform any traversal (here, LevelOrder)
	//Store the node to be deleted, and its parent
	//Continue traversing until deepest right most node is found

	BTNode** temp = rootNode;
	std::queue<BTNode**> BinaryTreeQueue;

	BTNode* nodeToDelete = nullptr;

	BinaryTreeQueue.push(temp);

	//Do level-order traversal and store node to be deleted
	while (!BinaryTreeQueue.empty())
	{
		temp = BinaryTreeQueue.front();
		BinaryTreeQueue.pop();

		if ((*temp)->data = valueToDelete)
			nodeToDelete = *temp;

		if ((*temp)->leftChild != nullptr)
			BinaryTreeQueue.push(&(*temp)->leftChild);

		if ((*temp)->rightChild != nullptr)
			BinaryTreeQueue.push(&(*temp)->rightChild);
	}

	//By the end of the traversal, temp stores the final deepest right-most node
	std::cout << "\nDeepest Right node: " << (*temp)->data;

	if (nodeToDelete == nullptr)
	{
		std::cout << "\nCouldn't find node to delete";
		return;
	}

	//If node to delete is the same as the deepest-right most node, remove it directly
	if (nodeToDelete == *temp)
	{
		std::cout << "\nNode to delete is deepest-right node, deletion performed.";
		delete(nodeToDelete);
		return;
	}

	//Store deepest data
	int deepestData = (*temp)->data;
	//Replace node's data with deepest data (thus deleting it)
	nodeToDelete->data = deepestData;

	BTNode* deepestNode = *temp;

	//Reset temp to root
	temp = rootNode;

	BinaryTreeQueue.push(temp);

	//delete deepest node's connections
	while (!BinaryTreeQueue.empty())
	{
		temp = BinaryTreeQueue.front();
		BinaryTreeQueue.pop();

		if (*temp == deepestNode)
		{
			temp = nullptr;
			delete(deepestNode);
			std::cout << "\nDeletion task complete..";
			return;
		}

		//Left child traversal
		if ((*temp)->leftChild != nullptr)
		{
			if ((*temp)->leftChild == deepestNode)
			{
				(*temp)->leftChild = nullptr;
				delete(deepestNode);
				std::cout << "\nDeletion task complete..";
				return;
			}
			else
			{
				BinaryTreeQueue.push(&(*temp)->leftChild);
			}
		}
		//Right child traversal
		if ((*temp)->rightChild != nullptr)
		{
			if ((*temp)->rightChild == deepestNode)
			{
				(*temp)->rightChild = nullptr;
				delete(deepestNode);
				std::cout << "\nDeletion task complete..";
				return;
			}
			else
			{
				BinaryTreeQueue.push(&(*temp)->rightChild);
			}
		}
	

		
	}

	

}

int BinaryTree::Count(BTNode* rootNode)
{
	int leftResult, rightResult = 0;

	if (rootNode != nullptr)
	{
		leftResult = Count(rootNode->leftChild);
		rightResult = Count(rootNode->rightChild);
		return leftResult + rightResult + 1;
	}

	return 0;
}

int BinaryTree::CountLeafNodes(BTNode* rootNode)
{
	int leftResult, rightResult = 0;

	if (rootNode != nullptr)
	{
		leftResult = CountLeafNodes(rootNode->leftChild);
		rightResult = CountLeafNodes(rootNode->rightChild);

		//If a leaf node, provide itself as a count increment
		if (!rootNode->leftChild && !rootNode->rightChild) return leftResult + rightResult + 1;
		else return leftResult + rightResult;
	}
	return 0;
}

int BinaryTree::CalcHeight(BTNode* rootNode)
{
	int leftResult, rightResult = 0;

	if (rootNode != nullptr)
	{
		//Post-order traversal
		leftResult = CalcHeight(rootNode->leftChild);
		rightResult = CalcHeight(rootNode->rightChild);
		
		//If left result is greater, use that result and include current node as an increment as well
		if (leftResult > rightResult) return leftResult + 1;
		else return rightResult + 1;
	}

	return 0;
}
