#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
using namespace std;

class Graph
{
private:
	typedef int eletype;
	struct celltype {
		eletype data;
		celltype* down, * right;
	};
	typedef celltype* node;
	node graph;

public:
	Graph();

	node newNode(eletype vertex);
	void delNode(eletype vertex);
	void setSucc(eletype vertex1, eletype vertex2);
	void delSucc(eletype vertex1, eletype vertex2);
	vector<eletype> succ(eletype vertex);
	bool isEdge(eletype vertex1, eletype vertex2);
};

#endif