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
	typedef int eletype;
	Graph();

	node newNode(eletype vertex_val);
	void delNode(eletype vertex_val);
	void setSucc(eletype vertex1_val, eletype vertex2_val);
	void delSucc(eletype vertex1_val, eletype vertex2_val);
	vector<eletype> succ(eletype vertex_val);
	vector<eletype> pre(eletype vertex_val);
	bool isEdge(eletype vertex1_val, eletype vertex2_val);
};

#endif