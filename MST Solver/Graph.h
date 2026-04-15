#ifndef GRAPH_H
#define GRAPH_H


struct EdgeNode {
	char destination;
	int weight;
	EdgeNode* next;
};


struct VertexNode {
	char label;
	EdgeNode* head;
};


class Graph {
	private:
		VertexNode* vertices_arr;
		int numVertices;
		int numEdges;

		int search(char vertex); // finds where node is in array
		void clearGraph();
	public:
		int sortedEdges[];
		Graph();

		void create(); // creates graph with 26 vertices for 26 letters
		bool hasEdge(char i, char j); // return true if edge (i, j) exists
		int edges(); // return number of edges in graph
		int vertices(); // return number of vertices in graph
		VertexNode* getVertices(); // returns vertices_arr
		void addEdge(char i, char j, int w); // adds an edge to the graph
		void loadGraph(); // adds all the edges to the graph
		void printList();

		~Graph();
};

#endif