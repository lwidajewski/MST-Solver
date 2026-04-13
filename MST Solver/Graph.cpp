#include "Graph.h"


// ---------- constructor ----------
Graph::Graph() {
	vertices_arr = nullptr;
	numVertices = 0;
	numEdges = 0;
};


int Graph::index(char vertex) {

};


void Graph::create(int n) {

};

bool Graph::hasEdge(char i, char j) {

};

int Graph::edges() {
	return numEdges;
};

int Graph::vertices() {
	return numVertices;
};

void Graph::addEdge(char i, char j, int w) {

};

void Graph::removeEdge(char i, char j) {

};

int Graph::degree(char i) {

};

void Graph::loadGraph() {

};

void Graph::print() {

};


// ---------- destructor ----------
Graph::~Graph() {
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