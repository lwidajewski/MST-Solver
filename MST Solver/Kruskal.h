#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "Graph.h"
#include "UnionFind.h"


struct Edge {
	char source;
	char destination;
	int weight;
};

class Kruskal {
	private:

	public:
		void kruskal(Graph& g);
		void getEdges(Graph& g, Edge* edges, int& edgeCount);
		void sortEdges(Edge* edges, int edgeCount);
		int charToIndex(char c);
};

#endif