#include <iostream>

#include "Graph.h"
#include "Kruskal.h"

using namespace std;


int main() {
	int choice = -1;

	while (choice != 0) {
		cout << "\n\n1: Run Kruskal's Algorithm on Graph" << endl;
		cout << "0: Exit" << endl;
		cout << "\nChoice: ";
		cin >> choice;
		cout << "\n\n\n";

		if (choice == 1) {
			Graph graph;
			Kruskal k;

			graph.create();
			graph.loadGraph();
			//int edges = graph.edges();
			//cout << edges;
			//int vertices = graph.vertices();
			//cout << vertices;
			graph.printList();

			k.kruskal(graph);

			cout << "_________________________________________________________________________________________________________";
		};
	};

	return 0;
};