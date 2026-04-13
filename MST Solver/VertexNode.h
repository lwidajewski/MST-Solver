#ifndef VERTEXNODE_H
#define VERTEXNODE_H

#include "EdgeNode.h"


struct VertexNode {
	char label;
	EdgeNode* head;
};
#endif