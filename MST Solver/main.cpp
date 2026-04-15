#include <iostream>

#include "Graph.h"
#include "Kruskal.h"

using namespace std;


int main() {
	Graph graph;
	Kruskal k;

	graph.create();
	graph.loadGraph();
	graph.printList();

	k.kruskal(graph);

	return 0;
};