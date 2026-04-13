#ifndef GRAPH_H
#define GRAPH_H

#include "VertexNode.h"


class Graph {
	private:
		VertexNode* vertices_arr;
		int numVertices;
		int numEdges;

		int index(char vertex); // finds where node is in array

	public:
		Graph();

		void create(int n); // create graph with n vertices
		bool hasEdge(char i, char j); // return true if edge (i, j) exists
		int edges(); // return number of edges in graph
		int vertices(); // return number of vertices in graph
		void addEdge(char i, char j, int w); // adds an edge to the graph
		void removeEdge(char i, char j); // removes an edge from the graph
		int degree(char i); // returns the degree of vertex i
		void loadGraph(); // adds all the edges to the graph
		void print();

		~Graph();
};

#endif