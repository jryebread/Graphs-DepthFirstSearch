#include <iostream>
#include <vector>
#include "Graph.h"
#include "HashTable.h"
using namespace std;
int main()
{
	Graph g(6);
	g.addEdge("Canyon Lake", "Sun City");
	g.addEdge("Canyon Lake", "Lake Elsinore");
	g.addEdge("Sun City", "Canyon Lake");
	g.addEdge("Sun City", "Menifee");
	g.addEdge("Lake Elsinore", "Canyon Lake");
	g.addEdge("Lake Elsinore", "Murrieta");
	g.addEdge("Murrieta", "Lake Elsinore");
	g.addEdge("Murrieta", "Temecula");
	g.addEdge("Menifee", "Sun City");
	g.addEdge("Menifee", "Murrieta");
	g.addEdge("Menifee", "Temecula");
	g.addEdge("Temecula", "Murrieta");
	g.addEdge("Temecula", "Menifee");

	g.printGraph();
	cout << "\nDepth First Search starting at Temecula: \n\n";
	g.DFS(6, 0); //size of graph(# of vertices), and vertex index to start at
	return 0;
}