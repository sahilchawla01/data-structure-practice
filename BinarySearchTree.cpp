#include "BinarySearchTree.h"
#include <iostream>
#include <queue>
#include <stack>

BSTNode* BinarySearchTree::Search(BSTNode* rootNode, int dataToSearch)
{
	BSTNode* temp = rootNode;

	while (temp)
	{
		if (temp->data == dataToSearch)
		{
			std::cout << "\nValue found!";
			return temp;
		}

		//Assuming sorted in an ascending order
		if (dataToSearch < temp->data) temp = temp->leftChild;
		else temp = temp->rightChild;
	}


	std::cout << "\nError, the value doesn't exist in the Binary Search Tree";

	return nullptr;
}

void BinarySearchTree::Insert(BSTNode** rootNode, int keyToInsert)
{
	BSTNode* temp = *rootNode;
	BSTNode* tailPointer = *rootNode;
	//Create new key node
	BSTNode* newNode = new BSTNode(keyToInsert);

	if (temp == nullptr)
	{
		*rootNode = newNode;
		std::cout << "\nRoot was null.. Inserting new root node";
		return;
	}

	while (temp)
	{
		if (temp->data == keyToInsert)
		{
			std::cout << "\nValue already present in the BST.. Returning!";
			return;
		}

		//Tail pointer points to the previous node
		tailPointer = temp;

		//Assuming sorted in an ascending order
		if (keyToInsert < temp->data) temp = temp->leftChild;
		else temp = temp->rightChild;
	}

	if (keyToInsert < tailPointer->data) tailPointer->leftChild = newNode;
	else tailPointer->rightChild = newNode;

	std::cout << "\nValue inserted!";
}

BSTNode* BinarySearchTree::Delete(BSTNode** temp, int keyToDelete)
{
	//If node is non existent, return;
	if (temp == nullptr) return nullptr;

	//If it is a leaf node, and the node is the nodeToDelete, delete it
	if (!(*temp)->leftChild && !(*temp)->rightChild && (*temp)->data == keyToDelete)
	{
		delete((*temp));
		return nullptr;
	}

	//Search on the left-subtree
	if (keyToDelete < (*temp)->data)
	{
		(*temp)->leftChild = Delete(&(*temp)->leftChild, keyToDelete);
	}//Search on the right subtree
	else if(keyToDelete > (*temp)->data)
	{
		(*temp)->rightChild = Delete(&(*temp)->rightChild, keyToDelete);
	}
	else //Node was found i.e keyToDelete == *temp->data
	{
		//Delete element from left-subtree or right-subtree based on their height
		if (Height((*temp)->leftChild) > Height((*temp)->rightChild))
		{
			//Find and store the inorder-pre decessor of the node to delete left-subtree
			BSTNode* leftSubtreeNode = InorderPre((*temp)->leftChild);
			//Replace node to delete with inorder-pre's data
			(*temp)->data = leftSubtreeNode->data;
			//Delete the InOrderPre decessor
			(*temp)->leftChild = Delete(&(*temp)->leftChild, leftSubtreeNode->data);
		}
		else
		{
			//Find and store the inorder-successor of the node to delete's right sub-tree
			BSTNode* rightSubtreeNode = InorderSucc((*temp)->rightChild);

			(*temp)->data = rightSubtreeNode->data;
			(*temp)->rightChild = Delete(&(*temp)->rightChild, rightSubtreeNode->data);
		}
	}

	return (*temp);
}

int BinarySearchTree::Height(BSTNode* temp)
{
	//Perform Post-order operation
	int leftChildResult, rightChildResult = 0;

	if(temp == nullptr)
	{
		return 0;
	}

	leftChildResult = Height(temp->leftChild);
	rightChildResult = Height(temp->rightChild);

	if (leftChildResult > rightChildResult) return leftChildResult + 1;
	else return rightChildResult + 1;
}

BSTNode* BinarySearchTree::InorderPre(BSTNode* temp)
{
	//As right most child must be found
	while (temp && temp->rightChild != nullptr) temp = temp->rightChild;

	return temp;
}

BSTNode* BinarySearchTree::InorderSucc(BSTNode* temp)
{
	//As left most child must be found
	while (temp && temp->leftChild != nullptr) temp = temp->leftChild;

	return temp;
}

void BinarySearchTree::InOrderTraversal(BSTNode* root)
{
	BSTNode* temp = root;

	if (temp == nullptr) return;

	InOrderTraversal(temp->leftChild);
	std::cout << temp->data << ",";
	InOrderTraversal(temp->rightChild);
}

void BinarySearchTree::LevelOrderTraversal(BSTNode* rootNode)
{
	BSTNode* temp = rootNode;

	if (rootNode == nullptr)
	{
		std::cout << "\nBST is empty.. Returning.." << std::endl;
		return;
	}

	//Declare a queue
	std::queue<BSTNode*> TreeQueue;

	TreeQueue.push(temp);

	while (!TreeQueue.empty() && temp)
	{
		//Pop first element from queue
		temp = TreeQueue.front();
		TreeQueue.pop();

		if (temp != nullptr) std::cout << temp->data << ", ";

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

void BinarySearchTree::GenerateTreeFromPreOrder(int preArr[], int size, BSTNode* &root)
{
	std::stack<BSTNode*> Stack;

	BSTNode* temp = nullptr;

	int preOrderItr = 0;

	//Create root node from first element
	root = new BSTNode(preArr[preOrderItr++]);

	BSTNode* ptr = root;

	while (preOrderItr < size);
	{
		if (preArr[preOrderItr] < ptr->data)
		{
			temp = new BSTNode(preArr[preOrderItr++]);
			ptr->leftChild = temp;
			Stack.push(ptr);
			ptr = temp;
		}
		else
		{
			//Check if new data is within range of top of stack and current node
			if (preArr[preOrderItr] > ptr->data && preArr[preOrderItr] << Stack.top()->data)
			{
				temp = new BSTNode(preArr[preOrderItr++]);
				ptr->rightChild = temp;
				ptr = temp;
			}
			else
			{
				ptr = Stack.top();
				Stack.pop();
			}
		}
	}
}
