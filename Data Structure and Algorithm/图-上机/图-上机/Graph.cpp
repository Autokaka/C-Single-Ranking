#include "Graph.h"
using namespace std;

Graph::Graph() {
	graph = new celltype;
	graph->data = 0;
	graph->down = NULL;
	graph->right = NULL;
}

Graph::node Graph::newNode(eletype vertex) {
	node add = new celltype;
	add->data = vertex;
	add->down = NULL;
	add->right = NULL;
	return add;
}
void Graph::delNode(eletype vertex) {
	node srch = graph;
	while (srch->down != NULL) {
		srch = srch->down;
		if (vertex = srch->data) {
			node todel = 
		}
	}
}

