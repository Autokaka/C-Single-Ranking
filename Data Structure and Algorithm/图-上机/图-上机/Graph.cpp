#include "Graph.h"
using namespace std;

Graph::Graph() {
	graph = new celltype;
	graph->data = 0;
	graph->down = NULL;
	graph->right = NULL;
}

Graph::node Graph::newNode(eletype vertex_val) {
	node add = new celltype;
	add->data = vertex;
	add->down = NULL;
	add->right = NULL;
	return add;
}
void Graph::delNode(eletype vertex_val) {
	node srch1 = graph;
	bool brkflg = false;
	while (srch1->down != NULL) {
		if (graph != srch1 && vertex_val == srch1->down->data) {
			node todel = srch1->down;
			srch1->down = todel->down;
			delete todel;
			return;
		}
		else {
			node srch2 = srch1;
			while (srch2->right != NULL) {
				if (vertex_val == srch2->right->data) {
					node todel = srch2->right;
					srch2->right = todel->right;
					delete todel;
					return;
				}
				srch2 = srch2->right;
			}
		}
		srch1 = srch1->down;
	}
}
void Graph::setSucc(eletype vertex1_val, eletype vertex2_val) {
	node srch1 = graph;
	bool remain[] = {1, 1};
	while (NULL != srch1->down) {
		if (0 == remain[0] && 0 == remain[1]) return;
		srch1 = srch1->down;
		if (vertex1_val == srch1->data || vertex2_val == srch1->data) {
			eletype from, to;
			if (vertex1_val == srch1->data) {
				from = vertex1_val;
				to = vertex2_val;
			}
			else {
				from = vertex2_val;
				to = vertex1_val;
			}
			node srch2 = srch1;
			while (srch2->right != NULL) srch2 = srch2->right;
			srch2->right = newNode(to);
			remain[from] = 0;
		}
	}
	if (1 == remain[0]) {
		srch1->down = newNode(vertex1_val);
		srch1 = srch1->down;
		srch1->right = newNode(vertex2_val);
	}
	if (1 == remain[1]) {
		srch1->down = newNode(vertex2_val);
		srch1 = srch1->down;
		srch1->right = newNode(vertex1_val);
	}
}
void Graph::delSucc(eletype vertex1_val, eletype vertex2_val) {
	node srch1 = graph;
	bool remain[] = { 1, 1 };
	while (srch1->down != NULL) {
		if (0 == remain[0] && 0 == remain[1]) return;
		srch1 = srch1->down;
		if (vertex1_val == srch1->data || vertex2_val == srch1->data) {
			eletype from, to;
			if (vertex1_val == srch1->data) {
				remain[0] = 0;
				from = vertex1_val;
				to = vertex2_val;
			}
			else {
				remain[1] = 0;
				from = vertex2_val;
				to = vertex1_val;
			}
			node srch2 = srch1;
			while (NULL != srch2->right) {
				if (to != srch2->right->data) srch2 = srch2->right;
				else {
					node todel = srch2->right;
					srch2->right = todel->right;
					delete todel;
					break;
				}
			}
		}
	}
	if (1 == remain[0]) {
		srch1->down = newNode(vertex1_val);
		srch1 = srch1->down;
		srch1->right = newNode(vertex2_val);
	}
	if (1 == remain[1]) {
		srch1->down = newNode(vertex2_val);
		srch1 = srch1->down;
		srch1->right = newNode(vertex1_val);
	}
}

vector<Graph::eletype> Graph::succ(eletype vertex_val) {
	node srch1 = graph;
	vector<eletype> result;
	while (NULL != srch1->down) {
		srch1 = srch1->down;
		if (vertex_val == srch1->down->data) {
			node srch2 = srch1;
			while (NULL != srch2->right) {
				srch2 = srch2->right;
				result.push_back(srch2->data);
			}
			return result;
		}
	}
	return result;
}
vector<Graph::eletype> Graph::pre(eletype vertex_val) {
	node srch1 = graph;
	vector<eletype> result;
	while (NULL != srch1->down) {
		srch1 = srch1->down;
		if (vertex_val != srch1->data) {
			node srch2 = srch1;
			while (NULL != srch2->right) {
				srch2 = srch2->right;
				if (vertex_val == srch2->data) {
					result.push_back(srch1->data);
					break;
				}
			}
		}
	}
}
bool Graph::isEdge(eletype vertex1_val, eletype vertex2_val) {
	node srch1 = graph;
	while (NULL != srch1->down) {
		srch1 = srch1->down;
		if (vertex1_val == srch1->data) {
			node srch2 = srch1;
			while (NULL != srch2->right) {
				srch2 = srch2->right;
				if (vertex2_val == srch2->data) return true;
			}
			return false;
		}
	}
	return false;
}
