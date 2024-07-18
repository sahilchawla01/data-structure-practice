#include "Graph.h"

#include <queue>
#include <stack>


Graph::Graph(int numberOfVertices)
{
	numVertices = numberOfVertices;

	//Now actually create the graph
	CreateGraph();
}

void Graph::CreateGraph()
{
	//When creating the graph, initially assume not directed graph
	bIsDirectedGraph = false;

	std::cout << "\nCreating Graph.. Is this a directed graph? (1 for yes, 0 for no): ";
	std::cin >> bIsDirectedGraph;

	system("cls");
	std::cout << "\nNow, enter vertex information..";

	//First, create an array of vertices (without connections)
	for (int i = 0; i < numVertices; i++)
	{
		//Input info to insert vertex data or id 
		std::cout << "\nFor vertex number: " << i + 1 << " , enter vertex id: ";
		int vertexId;
		std::cin >> vertexId;

		int vertexWeight = -1;

		//If directed graph, enter the weight of the vertex
		if (bIsDirectedGraph)
		{
			std::cout << "\nEnter vertex weight: ";
			std::cin >> vertexWeight;
		}

		//Create and set the node
		Vertex* temp = new Vertex(vertexId, i, vertexWeight);

		//Store the new node
		verticesArr.push_back(temp);

		AdjListNode* rootAdjListNode = new AdjListNode(vertexId, vertexWeight);
		//Also create the lists for each vertex
		adjList.push_back(rootAdjListNode);
	}

	//Second, now iterate through array of vertices and ask for which connections should be made
	for (int i = 0; i < numVertices; i++)
	{
		//Store the node according to index
		Vertex* currentVertex = verticesArr[i];

		std::cout << "\n\nFor the vertex(" << currentVertex->vertexData << "), enter the connections:\n";
		int vertexToConnectData = 0;

		//Store current vertex's root adjacent node
		AdjListNode* headVertex = adjList[i];

		while (headVertex != nullptr)
		{
			std::cout << "\nEnter the vertex to connect (-1 to exit insertion for current vertex): ";
			std::cin >> vertexToConnectData;

			if (vertexToConnectData == -1) break;

			//If trying to connect to self, prevent
			if (vertexToConnectData == currentVertex->vertexData)
			{
				std::cout << "\nError, can't connect to self";
				continue;
			}

			//Check if connected node already exists
			if (CheckIfConnectionExists(i, vertexToConnectData))
			{
				std::cout << "\nEither vertex is already connected or vertex to connect doesn't exist.. ";
				continue;
			}

			Vertex* vertexToConnect = SearchVertices(vertexToConnectData);
			AdjListNode* vertexAdjNode = new AdjListNode(vertexToConnect->vertexData, vertexToConnect->vertexWeight);

			headVertex->next = vertexAdjNode;
			headVertex = vertexAdjNode;

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
		//Get root node according to index
		Vertex* temp = verticesArr[i];

		if (temp == nullptr) continue;

		AdjListNode* currAdjListNode = adjList[i];

		std::cout << std::endl;

		while (currAdjListNode != nullptr)
		{
			//If last element is not current element print arrow
			if (currAdjListNode->next == nullptr)
				std::cout << "(" << currAdjListNode->vertexData << "[Weight: " << currAdjListNode->vertexWeight << "])";
			else
				std::cout << "(" << currAdjListNode->vertexData << "[Weight: "<< currAdjListNode->vertexWeight<<"])---->";

			currAdjListNode = currAdjListNode->next;
		};

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
	
	//Store root vertex's index and root node
	Vertex* rootVertex = SearchVertices(rootVertexData, rootVertexIndex);

	if (rootVertexIndex == -1)
	{
		std::cout << "\nCouldn't find input root vertex.. Returning..";
		return;
	}

	//Visit root
	std::cout << "\n\nBFS\nLevel (0): " << rootVertex->vertexData;
	rootVertex->bVisited = true;

	std::queue<Vertex*> bfsQueue;
	//Enqueue root node's data
	bfsQueue.push(rootVertex);

	//Now any node visited has a level of 1 or greater
	int bfsLevel = 1;
	while (!bfsQueue.empty())
	{
		//Dequeue node and store it
		Vertex* currVertex = bfsQueue.front();
		bfsQueue.pop();

		std::cout << "\nLevel (" << bfsLevel << "): ";
		//Enqueue its connections 
		
		AdjListNode* headAdjNode = adjList[currVertex->vertexAdjListIndex];

		while(headAdjNode != nullptr)
		{ 
			//Get current connected vertex
			Vertex* temp = SearchVertices(headAdjNode->vertexData);

			if (temp->bVisited)
			{
				//Traverse to next 
				headAdjNode = headAdjNode->next;
				//Go to next node in queue
				continue;
			}

			//ELse if not visited, visit it 
			temp->bVisited = true;
			std::cout << temp->vertexData << ", ";

			//Enqueue the node
			bfsQueue.push(temp);

			//Traverse to next 
			headAdjNode = headAdjNode->next;
		}

		//Increment level
		bfsLevel++;
	}

	//Remove visited status for next traversal
	UnvisitAllVertices();

}

void Graph::StartDFS()
{
	std::cout << "\nTo perform DFS, enter the root vertex: ";
	int rootVertexData;
	std::cin >> rootVertexData;

	std::cout << "\n\DFS: ";

	//Start dfs from root node
	PerformDFS(SearchVertices(rootVertexData));

	//After DFS is done, unvisit all vertices
	UnvisitAllVertices();
}

void Graph::PerformDFS(Vertex* vertexNode)
{

	/*--PSEUDO CODE--
	1) Check if not visited
	2) If not, visit it
	3) For that node, iterate through the adjacency list
	4) Find each node, and check if not visited, if not, call DFS on that node
	*/

	//Visit root if not visited
	if (!vertexNode->bVisited)
	{
		//Visit the node
		std::cout << vertexNode->vertexData << ", ";
		vertexNode->bVisited = true;


		AdjListNode* curr = adjList[vertexNode->vertexAdjListIndex];
		//Skip the head
		curr = curr->next;

		while (curr != nullptr)
		{
			Vertex* connectedNode = SearchVertices(curr->vertexData);

			if (!connectedNode->bVisited) PerformDFS(connectedNode);

			curr = curr->next;
		}

	}

}

void Graph::PerformPrims()
{
	/* --PSEUDO CODE --
	* 1)Find minimum cost edge and store in minimum spanning tree data struct
	* 2)Create a near array, and find and store for each vertex, which is the nearest of the minimum cost edge's pair of vertices
	* 3) 
	*/
}

bool Graph::CheckIfConnectionExists(int OriginalVertexIndex, int CheckVertexData)
{

	//Store the vertex whose connections must be checked
	Vertex* vertexToCheck = verticesArr[OriginalVertexIndex];

	if (!vertexToCheck)
	{
		std::cout << "\nError, while checking the connection for index: " << OriginalVertexIndex << " , vertex was null.. Returning false";
		return false;
	}

	//For all vertices in the adjacency list of specified vertex, check if the vertex already exists
	AdjListNode* temp = adjList[OriginalVertexIndex];

	while (temp != nullptr)
	{
		if (temp->vertexData == CheckVertexData) return true;

		temp = temp->next;
	}

	return false;
}

void Graph::UnvisitAllVertices()
{
	for (int itr = 0; itr < numVertices; itr++)
	{
		//Get root vertex
		Vertex* curr = verticesArr[itr];

		curr->bVisited = false;
	}

}

Vertex* Graph::SearchVertices(int vertexData, int& vertexIndex)
{
	vertexIndex = -1;

	for (int itr = 0; itr < numVertices; itr++)
	{
		Vertex* curr = verticesArr[itr];

		if (curr->vertexData == vertexData)
		{
			vertexIndex = itr;
			return curr;
		}
	}

	return nullptr;
}

Vertex* Graph::SearchVertices(int vertexData)
{
	for (int itr = 0; itr < numVertices; itr++)
	{
		Vertex* curr = verticesArr[itr];

		if (curr->vertexData == vertexData)
		{
			return curr;
		}
	}

	return nullptr;
}
