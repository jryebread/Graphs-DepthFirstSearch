#include "Graph.h"

//set the size of the graph (number of lists needed)
Graph::Graph(unsigned size) : mSize(size)
{
	createGraph(mSize);
}

/*Function: createGraph
Author:	James Riback
Description: allocates the adjlist pointer to a new hash table
Input: size of graph
 */
void Graph::createGraph(unsigned size)
{
	this->adjList = new HashTable<std::string>(size);
}

/*Function: addEdge
Author:	James Riback
Description: add an edge to the adjacency list
Input: string source, string destination
*/
void Graph::addEdge(std::string src, std::string dest)
{
	int index = hashFuncCity(src);

	indexNcities.pushPair(index, src);

	if (adjList->isEmptyAt(index))
	{
		adjList->addBackAt(index, src);
		adjList->addBackAt(index, dest);
	}
	else if (adjList->findAt(index, src)) //if first element of LL == 0
	{
		adjList->addBackAt(index, dest);
	}
}

// DFS traversal of the vertices reachable from v.
// Input: size of graph(# of vertices), and vertex index in hash table to start search at
// It uses recursive DFSUtil()
void Graph::DFS(int v, int index)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[v];
	for (int i = 0; i < v; i++)
		visited[i] = false;

	// Call the recursive helper function to print DFS traversal
	DFSUtil(index, visited);
}

//Recursive helper function for DFS
void Graph::DFSUtil(int index, bool visited[])
{
	// Mark the current node as visited and print it
	visited[index] = true;
	cout << index << ".\t" << indexNcities.getValueFromKey(index) << endl;
	Node<std::string> *p = adjList->getHeadOfLinkedList(index); //get head of linked list at vertex

	// Recur for all the vertices adjacent to this vertex
	while (p != nullptr)
	{
		index = indexNcities.getKeyFromValue(p->data);//get the key from value for the string in the node
		if (!visited[index])
			DFSUtil(index, visited);
		p = p->next;
	}

}

//Simply prints the graph table with chains visible (-->)
void Graph::printGraph()
{
	adjList->printTable();
}


/*Function: hashFuncCity
Author:	James Riback
Description://Returns an index for where to place the city in the adjacency list
Input:src city string
Outputs: index of where to place city
*/
int Graph::hashFuncCity(std::string src)
{
	int index;
	bool cityExist;
	if (citiesSrc.empty())
	{
		citiesSrc.push_back(src);
		return citiesSrc.size() - 1;
	}
	else { //scan over cities vector to see if srcCity already exists
		for (int x = 0; x < citiesSrc.size(); ++x)
		{
			if (src == citiesSrc.at(x))
				return x;
		}
	}
		//else if didnt return an index, then the city doesnt exist, so add the city to the end and return the index
		citiesSrc.push_back(src);
		return citiesSrc.size()-1;
}
