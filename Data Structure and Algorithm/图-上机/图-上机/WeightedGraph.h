#ifndef WEIGHTEDGRAPH_H
#define WEIGHTEDGRAPH_H
#include <iostream>
#include <vector>
using namespace std;

class WeightedGraph
{
private:
	static const int INF = 2147483647;
	typedef char eletype;
	//图的邻接表结构
	struct celltype {
		eletype data;
		int weight;
		celltype* down, * right;
	};
	typedef celltype* node;
	node graph;
	int matrix[100][100];
	int matrixLen;

	void markConnectedComponent(node now, bool* visited);
	void DFSSearch(node now, bool* visited);
	void BFSSearch(node now, bool* visited);

	int calEarliest(node now, bool* visited);

public:
	typedef char eletype;
	WeightedGraph();

	node newNode(eletype vertex_val);
	void delNode(eletype vertex_val);
	void setSucc(node from, node to, int weight);
	void delSucc(node from, node to);
	void buildMatrix();
	vector<eletype> succ(eletype vertex_val);
	vector<eletype> pre(eletype vertex_val);
	int weight(eletype from, eletype to);
	void printGraph();
	void printMatrix();
	int countConnectedComponentNum();
	void DFSTraverse();
	void BFSTraverse();

	void Prim();
	void Kruskal();

	int earliestBeginTime(eletype from, eletype to);

	void Dijkstra(eletype start);
	void Floyd();
	void Warshall();
};

#endif