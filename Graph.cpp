#include "Graph.h"
#include <iostream>
#include <queue>

Graph::Graph(int numberOfVertices)
{
	graphArr = new Vertex*[numberOfVertices];

	//Initialise each vertex to be nullptr
	for (int i = 0; i < numberOfVertices; i++)
	{
		*(graphArr + i) = nullptr;
	}

	numVertices = numberOfVertices;

	//Now actually create the graph
	CreateGraph();
}

void Graph::CreateGraph()
{
	std::cout << "\nNow, enter vertex information..";

	//First, create an array of vertices (without connections)
	for (int i = 0; i < numVertices; i++)
	{
		//Input info to insert vertex data or id 
		std::cout << "\nFor vertex number: " << i + 1 << " , enter vertex id: ";
		int vertexId;
		std::cin >> vertexId;

		//Create and set the node
		Vertex* temp = new Vertex(vertexId);

		//Store the new node
		graphArr[i] = temp;
	}

	//Second, now iterate through array of vertices and ask for which connections should be made
	for (int i = 0; i < numVertices; i++)
	{
		//Store the node according to index
		Vertex* currentVertex = *(graphArr + i);

		std::cout << "\n\nFor the vertex(" << currentVertex->vertexData << "), enter the connections:\n";
		int vertexToConnect = 0;

		while (true)
		{
			std::cout << "\nEnter the vertex to connect (-1 to exit insertion for current vertex): ";
			std::cin >> vertexToConnect;

			if (vertexToConnect == -1) break;

			//If trying to connect to self, prevent
			if (vertexToConnect == currentVertex->vertexData)
			{
				std::cout << "\nError, can't connect to self";
				continue;
			}

			//Check if connected node already exists
			if (CheckIfConnectionExists(i, vertexToConnect))
			{
				std::cout << "\nEither vertex is already connected or vertex to connect doesn't exist.. ";
				continue;
			}

			//Create a new node for that vertex
			Vertex* newNodeToConnect = new Vertex(vertexToConnect);

			//Traverse to last element
			Vertex* lastVertex = currentVertex;
			while (lastVertex->connectedVertex != nullptr) lastVertex = lastVertex->connectedVertex;

			//Connect the currentVertex's next open slot to new node
			lastVertex->connectedVertex = newNodeToConnect;

			std::cout << "\nVertex connected!";
		}

		system("cls");
		std::cout << "\nMoving onto next vertex..Current graph is: ";
		DisplayGraph();
	}
}

void Graph::DisplayGraph()
{
	for (int i = 0; i < numVertices; i++)
	{
		//Get node according to index
		Vertex* temp = *(graphArr + i);

		if (temp == nullptr) continue;

		std::cout << "\nVertex:" ;
		while (temp != nullptr)
		{
			if(temp->connectedVertex != nullptr) std::cout << "(" << temp->vertexData << ")->";
			else std::cout << "(" << temp->vertexData << ")";

			temp = temp->connectedVertex;
		}
		std::cout << std::endl;
	}
}

void Graph::PerformBFS()
{
	//Ask which node to start from
	//Print that node
	//Mark it as visited
	//Enqueue the node
	//Begin loop (condition: while queue is not empty):
	//Dequeue node and store it 
	//Traverse through all the connected nodes in another loop
	//Check if node is visited, if not, visit it (print it), insert it into queue
	//End 2nd loop
	//End 1st loop

	system("cls");
	std::cout << "\nTo perform BFS, enter the root vertex: ";
	int rootVertexData;
	std::cin >> rootVertexData;

	//Traverse all the root vertices in the list, and store its index
	int rootVertexIndex = -1;
	
	for (int itr = 0; itr < numVertices; itr++)
	{
		//Get root vertex
		Vertex* curr = *(graphArr + itr);

		//If root vertex is found, store index
		if(curr->vertexData == rootVertexData) rootVertexIndex = itr;
	}

	if (rootVertexIndex == -1)
	{
		std::cout << "\nCouldn't find input root vertex.. Returning..";
		return;
	}

	//Store root vertex
	Vertex* rootVertex = *(graphArr + rootVertexIndex);

	//Visit root
	std::cout << "\n\nBFS: " << rootVertex->vertexData;
	rootVertex->bVisited = true;

	std::queue<Vertex*> bfsQueue;
	//Enqueue root node
	bfsQueue.push(rootVertex);

	while (!bfsQueue.empty())
	{
		//Dequeue node and store it
		Vertex* currVertex = bfsQueue.front();
		bfsQueue.pop();

		while (currVertex != nullptr)
		{
			//If already visited go to next node
			if (currVertex->bVisited)
			{
				//Go to next node
				currVertex = currVertex->connectedVertex;
				continue;
			}

			//If not visited print it and enqueue it
			std::cout << ", " << currVertex->vertexData;

			//Enable visited for that node
			currVertex->bVisited = true;

			//Go to next node
			currVertex = currVertex->connectedVertex;
		}
	}


}

bool Graph::CheckIfConnectionExists(int OriginalVertexIndex, int CheckVertexData)
{
	//Store the vertex whose connections must be checked
	Vertex* vertexToCheck = graphArr[OriginalVertexIndex];

	if (!vertexToCheck)
	{
		std::cout << "\nError, while checking the connection for index: " << OriginalVertexIndex << " , vertex was null.. Returning false";
		return false;
	}

	while (vertexToCheck != nullptr)
	{
		//If vertex found, return true
		if (vertexToCheck->vertexData == CheckVertexData) return true;

		vertexToCheck = vertexToCheck->connectedVertex;
	}

	return false;
}
