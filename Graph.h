#pragma once
#include <iostream>
#include <vector>
#include <list>

struct Vertex
{
	int vertexData;
	//The weight of the vertex 
	int vertexWeight;
	int vertexAdjListIndex;
	bool bVisited; 

	Vertex() : vertexData(-1), vertexAdjListIndex(-1), vertexWeight(-1), bVisited(false) {};
	Vertex(int vData, int index) : vertexData(vData), vertexAdjListIndex(index), vertexWeight(-1), bVisited(false) {};
	Vertex(int vData, int index, int vWeight) : vertexData(vData), vertexAdjListIndex(index), vertexWeight(vWeight), bVisited(false) {};
};

struct AdjListNode
{
	int vertexData;
	int vertexWeight;
	AdjListNode* next;

	AdjListNode(int vData, int vWeight) : vertexData(vData), vertexWeight(vWeight), next(nullptr) {};
};


class Graph
{
public:

	Graph(int numberOfVertices);

	//Array of head vertices
	std::vector<Vertex*> verticesArr;
	//A vector of adjlistnodes that represents each vertice's connections
	std::vector<AdjListNode*> adjList;

	void CreateGraph();
	void DisplayGraph();
	//Do a breadth first search
	void PerformBFS();
	//Driver for DFS
	void StartDFS();
	//Recursive Workhorse for DFS
	void PerformDFS(Vertex* vertexNode);
	void PerformPrims();

	Vertex* SearchVertices(int vertexData);
private:

	bool CheckIfConnectionExists(int OriginalVertexIndex, int CheckVertexData);
	void UnvisitAllVertices();
	Vertex* SearchVertices(int vertexData, int& vertexIndex);

private:
	int numVertices;
	bool bIsDirectedGraph = false;
};

