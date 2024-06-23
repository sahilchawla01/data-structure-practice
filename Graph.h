#pragma once

struct Vertex
{
	int vertexData;
	Vertex* connectedVertex;
	bool bVisited; 

	Vertex() : vertexData(-1), connectedVertex(nullptr), bVisited(false) {};
	Vertex(int vData) : vertexData(vData), connectedVertex(nullptr), bVisited(false) {};
};


class Graph
{
public:

	Graph(int numberOfVertices);

	//Array of pointers to pointers, that point to the specified linked list
	Vertex** graphArr;

	void CreateGraph();
	void DisplayGraph();
private:
	int numVertices;
};

