#ifndef UNIONFIND_H
#define UNIONFIND_H


class UnionFind {
	private:
		int size; // number of vertices
		int* parent; // tracks the parent of each set of vertices
		int* height; // helps to keep the chain of vertices short
	public:
		UnionFind(int n);
		int find(int i); // finds the parent of the passed in vertice using recursion
		bool connected(int i, int j); // call find on both vertices to see if they are connected
		void unionSets(int i, int j); // joins sets
		~UnionFind();
};

#endif