#ifndef EDGENODE_H
#define EDGENODE_H


struct EdgeNode {
	char destination;
	int weight;
	EdgeNode* next;
};
#endif