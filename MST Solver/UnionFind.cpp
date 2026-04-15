#include "UnionFind.h"


// ---------- constructor ----------
UnionFind::UnionFind(int n) {
	size = n; // num of vertices
	parent = new int[n];
	height = new int[n];

	for (int i = 0; i < size; i++) {
		parent[i] = i; // start off with each as their own parent
		height[i] = 0; // each has 0 height to start
	};
};


// ---------- functions ----------
int UnionFind::find(int i) {
	if (parent[i] != i) {
		parent[i] = find(parent[i]); // recursive call
	}
	else {
		return parent[i]; // found
	};
};

bool UnionFind::connected(int i, int j) {
	if (find(i) == find(j)) {
		return true; // connected
	}
	else {
		return false; // not connected
	};
};

void UnionFind::unionSets(int i, int j) {
	int parentI = find(i);
	int parentJ = find(j);

	if (parentI == parentJ) {
		return; // they are connected already
	};

	if (height[parentI] < height[parentJ]) {
		parent[parentI] = parentJ; // example: called with b,c (b height = 0, c height = 1) | b's parent becomes c
	}
	else if (height[parentI] > height[parentJ]) {
		parent[parentJ] = parentI; // example: called with a,c (a height = 1, c height = 0) | c's parent becomes a
	}
	else {
		// runs if heights are equal (no parents yet, they are 'alone')
		parent[parentJ] = parentI; // example: called with a,b | if this runs b's parent becomes a
		height[parentI]++; // a now has height of 1
	};
};


// ---------- destructor ----------
UnionFind::~UnionFind() {
	delete[] parent;
	delete[] height;
};