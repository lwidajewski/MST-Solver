#include <iostream>

#include "Kruskal.h"

using namespace std;


void Kruskal::getEdges(Graph& g, Edge* edges, int& edgeCount) {
	//cout << "Get edges called" << endl;
	edgeCount = 0;
	VertexNode* vertices_list = g.getVertices(); // gets vertices_arr from Graph
	int verticesNum = g.vertices(); // gets the number of vertices from Graph

	for (int i = 0; i < verticesNum; i++) {
		EdgeNode* curr = vertices_list[i].head;
		while (curr != nullptr) {
			// this if statement basically checks for duplicates I don't know how to make it more readable
			if (vertices_list[i].label < curr->destination) {
				// get source, destination, and weight for later
				edges[edgeCount].source = vertices_list[i].label;
				edges[edgeCount].destination = curr->destination;
				edges[edgeCount].weight = curr->weight;
				edgeCount++;
			};
			curr = curr->next;
		};
	};
};

void Kruskal::sortEdges(Edge* edges, int edgeCount) {
	//cout << "Bubble sort called" << endl;
	// bubble sort
	for (int i = 0; i < edgeCount - 1; i++) { // minus by 1 since last element is automatically sorted
		for (int j = 0; j < edgeCount - i - 1; j++) { // minus by 1 and i to make less comparisons since the higher numbers would already be sorted
			if (edges[j].weight > edges[j + 1].weight) {
				/*
				cout << "Swapping: " << edges[j].source << "," << edges[j].destination << "," << edges[j].weight << endl;
				cout << "With: " << edges[i].source << "," << edges[i].destination << "," << edges[i].weight << endl;
				*/


				// swap if the weight on the left in the array is greater than the weight just to the right of it
				Edge temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = temp;


				//cout << "Edges swapped" << endl;
			};
		};
		
		/*
		cout << "Pass: " << i + 1 << ": " << endl;
		for (int k = 0; k < edgeCount; k++) {
			cout << "(" << edges[k].source << "," << edges[k].destination << "," << edges[k].weight << ")";
		};
		cout << "\n\n\n";
		*/
	};
};

void Kruskal::kruskal(Graph& g) {
	//cout << "Kruskal called" << endl;
	int verticesNum = g.vertices(); // gets number of vertices from Graph
	int edgeCount = 0;

	Edge* edges = new Edge[verticesNum * (verticesNum - 1) / 2]; // max possible number of edges

	// sort edges by weight
	getEdges(g, edges, edgeCount);
	sortEdges(edges, edgeCount);

	// perform Kruskal's algorithm
	UnionFind uf(verticesNum); // initialize UnionFind with number of vertices

	Edge* miniSpanTree = new Edge[verticesNum - 1]; // minimum spanning tree has n (vertices) - 1 edges
	int totalWeight = 0;
	int mstEdges = 0;

	for (int i = 0; i < edgeCount && mstEdges < i - 1; i++) {
		int source = edges[i].source;
		int destination = edges[i].destination;

		if (!uf.connected(source, destination)) { // add an edge only if it does not form a loop
			uf.unionSets(source, destination); // join the two vertices together
			miniSpanTree[mstEdges++] = edges[i]; // add the edge to the MST
			totalWeight = totalWeight + edges[i].weight; // add to the total weight
		};
	};

	// print minimum spanning tree
	cout << "MST Edges:\n";
	cout << "_________________________________________________________________________________________________________" << endl;
	for (int i = 0; i < mstEdges; i++) {
		cout << miniSpanTree[i].source << "->" << miniSpanTree[i].destination << " (weight = " << miniSpanTree[i].weight << ")" << endl;
	};
	cout << "_________________________________________________________________________________________________________" << endl;
	cout << "Total Weight: " << totalWeight << endl;
	cout << "Total MST Edges: " << mstEdges << endl;

};
