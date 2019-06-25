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
	int matrix[100][100];
	int matrixLen;

	void DFSSearch(node now, bool* visited);
	void BFSSearch(node now, bool* visited);

public:
	typedef int eletype;
	Graph();

	node newNode(eletype vertex_val);
	void delNode(eletype vertex_val);
	void setSucc(node from, node to);
	void delSucc(node from, node to);
	void buildMatrix();
	vector<eletype> succ(eletype vertex_val);
	vector<eletype> pre(eletype vertex_val);
	bool isEdge(eletype from, eletype to);
	void printGraph();
	void printMatrix();
	void DFSTraverse();
	void BFSTraverse();
};

#endif