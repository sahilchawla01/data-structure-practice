#pragma once

class BTNode
{
public:
	int data;
	BTNode* leftChild; 
	BTNode* rightChild;

	BTNode() : data(-1), leftChild(nullptr), rightChild(nullptr) {};
	BTNode(int value) : data(value), leftChild(nullptr), rightChild(nullptr) {};
};
class BinaryTree
{
public:

	BinaryTree(){};

	//DFS approach of traversal: (Data, Left Node, Right Node)
	void RecursivePreOrderTraversal(BTNode* parentNode);
	//DFS approach of traversal: (Left Node, Right Node, Data)
	void RecursivePostOrderTraversal(BTNode* parentNode);
	//DFS approach of traversal: (Left Node, Data, Right Node)
	void RecursiveInOrderTraversal(BTNode* parentNode);
	//DFS approach of traversal: (Data, Left Node, Right Node)
	void NonRecursivePreOrderTraversal(BTNode* parentNode);
	//DFS approach of traversal: (Left Node, Right Node, Data)
	void NonRecursivePostOrderTraversal(BTNode* parentNode);
	//DFS approach of traversal: (Left Node, Data, Right Node)
	void NonRecursiveInOrderTraversal(BTNode* parentNode);
	void InsertByLevelOrderTraversal(BTNode** rootNode, int value);

	//BFS approach of traversal:
	void LevelOrderTraversal(BTNode* rootNode);

	void DeleteElement(BTNode** rootNode, int valueToDelete);
};

