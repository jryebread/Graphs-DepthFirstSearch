#ifndef GRAPH_H
#define GRAPH_H
#include <string>
#include "HashTable.h"
#include "LinkedList.h"
#include "PairList.h"
class Graph
{
public:
	Graph(unsigned size);
	void createGraph(unsigned size);
	void addEdge(std::string src, std::string dest);
	void DFS(int v, int index);
	void DFSUtil(int v, bool visited[]);
	void printGraph();
	int hashFuncCity(std::string src);
private:
	std::vector<std::string> citiesSrc;
	PairList<int, std::string> indexNcities;
	unsigned int mSize;
	HashTable<std::string> *adjList;



};
#endif
