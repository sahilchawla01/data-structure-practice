#pragma once

struct BSTNode
{
	int data;
	BSTNode* leftChild;
	BSTNode* rightChild;

	BSTNode(int val) : data(val), leftChild(nullptr), rightChild(nullptr){};
};

class BinarySearchTree
{

public:
	BSTNode* Search(BSTNode* rootNode, int dataToSearch);
	void Insert(BSTNode** rootNode, int keyToInsert);
	BSTNode* Delete(BSTNode** temp, int keyToDelete);
	int Height(BSTNode* temp);
	BSTNode* InorderPre(BSTNode* temp);
	BSTNode* InorderSucc(BSTNode* temp);
	void InOrderTraversal(BSTNode* root);
	void LevelOrderTraversal(BSTNode* rootNode);

};

