#include "Graph.h"
#include <iostream>

Graph::Graph(int numberOfVertices)
{
	graphArr = new Vertex*[numberOfVertices];

	//Initialise each vertex to be nullptr
	for (int i = 0; i < numberOfVertices; i++)
	{
		*(graphArr + i) = nullptr;
	}

	numVertices = numberOfVertices;
}

void Graph::CreateGraph()
{
	std::cout << "\nNow, enter vertex information..";

	//First, create an array of vertices (without connections)
	for (int i = 0; i < numVertices; i++)
	{
		//Get node according to index
		Vertex* temp = *(graphArr + i);

		//Input info to insert vertex data or id 
		std::cout << "\nFor vertex number: " << i + 1 << " , enter id: ";
		int vertexId;
		std::cin >> vertexId;

		//Create and set the node
		temp = new Vertex(vertexId);
	}

	//Second, now iterate through array of vertices and connect 
}

void Graph::DisplayGraph()
{
	for (int i = 0; i < numVertices; i++)
	{
		//Get node according to index
		Vertex* temp = *(graphArr + i);

		std::cout << "\nVertex:" ;

		while (temp != nullptr)
		{
			std::cout << "(" << temp->vertexData << ")->";
			temp = temp->connectedVertex;
		}

		std::cout << std::endl;
	}
}
