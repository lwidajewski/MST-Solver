#include<iostream>

#include "Graph.h"

using namespace std;


// ---------- constructor ----------
Graph::Graph() {
	vertices_arr = nullptr;
	numVertices = 0;
	numEdges = 0;
};


// ---------- functions ----------
int Graph::search(char vertex) {
	for (int i = 0; i < numVertices; i++) {
		if (vertices_arr[i].label == vertex) {
			return i; // found node
		};
	};
	return -1; // did not find node
};

void Graph::clearGraph() {
	// clear out array which stores graph vertices and edges
	if (vertices_arr != nullptr) {
		for (int i = 0; i < numVertices; i++) {
			EdgeNode* curr = vertices_arr[i].head;
			while (curr != nullptr) {
				EdgeNode* temp = curr;
				curr = curr->next;
				delete temp;
			};
		};
		delete[] vertices_arr;
	};
};


// create graph with n(26) vertices and 0 edges
void Graph::create() {
	clearGraph(); // clear array first if needed

	// initialize graph
	numVertices = 26; // should be 26 for a-z
	numEdges = 0;
	vertices_arr = new VertexNode[26];
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (int i = 0; i < 26; i++) {
		vertices_arr[i].label = letters[i]; // initialize all nodes with a letter a-z
		vertices_arr[i].head = nullptr;
	};
};

bool Graph::hasEdge(char i, char j) {
	// check if vertex exists
	int index = search(i);
	if (index == -1) {
		return false;
	}

	// check if vertex has an edge
	EdgeNode* curr = vertices_arr[index].head;
	while (curr != nullptr) {
		if (curr->destination == j) {
			return true;
		}
		curr = curr->next;
	};
	return false;
};

int Graph::edges() {
	return numEdges;
};

int Graph::vertices() {
	return numVertices;
};

VertexNode* Graph::getVertices() { // needed for Kruskal
	return vertices_arr;
};

void Graph::addEdge(char i, char j, int w) {
	// check if nodes are present in array
	int indexOfI = search(i);
	int indexOfJ = search(j);

	if (indexOfI == -1 || indexOfJ == -1) {
		cout << "One or both nodes do not exist, cannot add edge";
		return; // one of the two nodes does not exist (or both)
	};

	// check if there is already an edge
	if (hasEdge(i, j)) {
		cout << "Edge already exists, cannot add edge";
		return;
	};
	
	// create edges for both directions since it's an undirected graph
	// if a knows about b, b would also need to know about a
	EdgeNode* nodeIJ = new EdgeNode;
	nodeIJ->destination = j;
	nodeIJ->weight = w;
	nodeIJ->next = vertices_arr[indexOfI].head;
	vertices_arr[indexOfI].head = nodeIJ;

	EdgeNode* nodeJI = new EdgeNode;
	nodeJI->destination = i;
	nodeJI->weight = w;
	nodeJI->next = vertices_arr[indexOfJ].head;
	vertices_arr[indexOfJ].head = nodeJI;

	numEdges = numEdges + 2; // increment number of edges
};

void Graph::loadGraph() {
	// this was a little annoying to do and I'm mad I couldn't think of something better 
	// I just kind of crossed off edges from the image when I added them so there weren't repeats
	addEdge('A', 'B', 29); addEdge('A', 'D', 6);
	addEdge('B', 'C', 34); addEdge('B', 'E', 17); addEdge('B', 'Y', 4);
	addEdge('C', 'D', 8); addEdge('C', 'E', 37); addEdge('C', 'F', 13);
	addEdge('D', 'G', 22); addEdge('D', 'X', 25);
	addEdge('E', 'H', 25); addEdge('E', 'Z', 10);
	addEdge('F', 'G', 1); addEdge('F', 'H', 9);
	addEdge('G', 'R', 32);
	addEdge('H', 'L', 17); addEdge('H', 'Z', 5);
	addEdge('I', 'J', 45); addEdge('I', 'L', 11); addEdge('I', 'W', 18); addEdge('I', 'Z', 32);
	addEdge('J', 'K', 24); addEdge('J', 'N', 67); addEdge('J', 'P', 16);
	addEdge('K', 'L', 3); addEdge('K', 'T', 26);
	addEdge('L', 'R', 29);
	addEdge('M', 'N', 6); addEdge('M', 'Q', 23); addEdge('M', 'W', 55);
	addEdge('N', 'O', 3); addEdge('N', 'Q', 9); addEdge('N', 'W', 11);
	addEdge('O', 'P', 19);
	addEdge('P', 'T', 2);
	addEdge('Q', 'U', 21);
	addEdge('R', 'S', 26); addEdge('R', 'V', 9);
	addEdge('S', 'X', 3);
	addEdge('T', 'U', 14); addEdge('T', 'V', 35);
	// U is good
	// V is good
	addEdge('W', 'Z', 12);
	addEdge('X', 'Y', 18);
	// Y is good
	// Z is good
};

// prints out all edges of each vertice -- e.g.  Vertex: (destination vertex, weight) (destination vertex, weight) etc.
void Graph::printList() {
	for (int i = 0; i < numVertices; i++) {
		cout << vertices_arr[i].label << ": ";
		EdgeNode* curr = vertices_arr[i].head;
		while (curr != nullptr) {
			cout << "(" << curr->destination << ", " << curr->weight << ") ";
			curr = curr->next;
		};
		cout << "\n";
	};

	cout << "_________________________________________________________________________________________________________" << endl;
};


// ---------- destructor ----------
Graph::~Graph() {
	clearGraph();
};