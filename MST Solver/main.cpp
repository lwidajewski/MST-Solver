#include <iostream>

#include "Graph.h"

using namespace std;


int main() {
	Graph g;

	g.create();
	g.loadGraph();
	g.printList();

	return 0;
};