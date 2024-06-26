#pragma once
#include <iostream>
#include <vector>
#include <list>

struct Vertex
{
	int vertexData;
	int vertexAdjListIndex;
	bool bVisited; 

	Vertex() : vertexData(-1), vertexAdjListIndex(-1), bVisited(false) {};
	Vertex(int vData, int index) : vertexData(vData), vertexAdjListIndex(index), bVisited(false) {};
};


class Graph
{
public:

	Graph(int numberOfVertices);

	//Array of head vertices
	std::vector<Vertex*> verticesArr;
	//A vector of vectors of integers that represents each vertice's connections
	std::vector<std::list<int>> adjList;

	void CreateGraph();
	void DisplayGraph();
	//Do a breadth first search
	void PerformBFS();
	//Driver for DFS
	void StartDFS();
	//Recursive Workhorse for DFS
	void PerformDFS(Vertex* vertexNode);

	Vertex* SearchVertices(int vertexData);
private:

	bool CheckIfConnectionExists(int OriginalVertexIndex, int CheckVertexData);
	void UnvisitAllVertices();
	Vertex* SearchVertices(int vertexData, int& vertexIndex);

	int numVertices;
};

