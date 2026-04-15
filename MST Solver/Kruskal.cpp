#include <iostream>

#include "Kruskal.h"

using namespace std;


void Kruskal::getEdges(Graph& g, Edge* edges, int& edgeCount) {
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
	// bubble sort
	for (int i = 0; i < edgeCount - 1; i++) { // minus by 1 since last element is automatically sorted
		for (int j = 0; j < edgeCount - i - 1; i++) { // minus by 1 and i to make less comparisons since the higher numbers would already be sorted
			if (edges[j].weight > edges[j + 1].weight) {
				// swap if the weight on the left in the array is greater than the weight just to the right of it
				Edge temp = edges[j];
				edges[j] = edges[j + 1];
				edges[j + 1] = edges[j];
			};
		};
	};
};

void Kruskal::kruskal(Graph& g) {
	//cout << "Kruskal called";

};

void Kruskal::printMST() {

};