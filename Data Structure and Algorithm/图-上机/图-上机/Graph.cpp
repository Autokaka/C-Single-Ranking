#include "Graph.h"
#include <iomanip>
#include <queue>
using namespace std;

Graph::Graph() {
	graph = new celltype;
	graph->data = 0;
	graph->down = NULL;
	graph->right = NULL;
}

Graph::node Graph::newNode(eletype vertex_val) {
	node add = new celltype;
	add->data = vertex_val;
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
void Graph::setSucc(node from, node to) {
	node srch1 = graph;
	while (NULL != srch1->down) {
		srch1 = srch1->down;
		if (from->data == srch1->data) {
			node srch2 = srch1;
			while (NULL != srch2->right) {
				srch2 = srch2->right;
				if (to->data == srch2->data) return;
			}
			srch2->right = newNode(to->data);
			return;
		}
	}
	srch1->down = newNode(from->data);
	srch1 = srch1->down;
	srch1->right = newNode(to->data);
}
void Graph::delSucc(node from, node to) {
	node srch1 = graph;
	while (NULL != srch1->down) {
		srch1 = srch1->down;
		if (from->data == srch1->data) {
			node srch2 = srch1;
			while (NULL != srch2->right) {
				if (to->data != srch2->right->data) srch2 = srch2->right;
				else {
					node todel = srch2->right;
					srch2->right = todel->right;
					delete todel;
					return;
				}
			}
		}
	}
}
void Graph::buildMatrix() {
	//确定最大点下标
	memset(matrix, 0, sizeof(matrix));
	matrixLen = 0;
	node srchDown = graph, srchRight;
	while (NULL != srchDown->down) {
		srchDown = srchDown->down;
		srchRight = srchDown;
		int maxRight = 0;
		while (NULL != srchRight->right) {
			srchRight = srchRight->right;
			maxRight = srchRight->data;
			if (maxRight > matrixLen) matrixLen = maxRight;
			matrix[srchDown->data][srchRight->data] = 1;
		}
		if (srchDown->data > matrixLen) matrixLen = srchDown->data;
	}
}

vector<Graph::eletype> Graph::succ(eletype vertex_val) {
	node srch1 = graph;
	vector<eletype> result;
	while (NULL != srch1->down) {
		if (vertex_val != srch1->down->data) srch1 = srch1->down;
		else {
			node srch2 = srch1->down;
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
	return result;
}
bool Graph::isEdge(eletype from, eletype to) {
	node srch1 = graph;
	while (NULL != srch1->down) {
		srch1 = srch1->down;
		if (from == srch1->data) {
			node srch2 = srch1;
			while (NULL != srch2->right) {
				srch2 = srch2->right;
				if (to == srch2->data) return true;
			}
			return false;
		}
	}
	return false;
}

void Graph::DFSTraverse() {
	bool visited[100] = { 0 };
	node srchDown = graph;
	while (NULL != srchDown->down) {
		srchDown = srchDown->down;
		if (!visited[srchDown->data]) {
			DFSSearch(srchDown, visited);
			cout << endl;
		}
	}
}
void Graph::DFSSearch(node now, bool* visited) {
	if (visited[now->data] || NULL == now) return;
	else {
		cout << now->data << " ";
		visited[now->data] = true;
		node srchDown = graph;
		while (NULL != srchDown->down) {
			srchDown = srchDown->down;
			if (srchDown->data == now->data) {
				node srchRight = srchDown;
				while (NULL != srchRight->right) {
					srchRight = srchRight->right;
					if (!visited[srchRight->data]) DFSSearch(srchRight, visited);
				}
			}
		}
	}
}
void Graph::BFSTraverse() {
	bool visited[100] = { 0 };
	node srchDown = graph;
	while (NULL != srchDown->down) {
		srchDown = srchDown->down;
		if (!visited[srchDown->data]) {
			BFSSearch(srchDown, visited);
			cout << endl;
		}
	}
}
void Graph::BFSSearch(node now, bool* visited) {
	if (NULL != graph->down) {
		queue<eletype> toVisit;
		eletype firstVal = graph->down->data;
		toVisit.push(firstVal);
		visited[firstVal] = true;
		while (!toVisit.empty()) {
			firstVal = toVisit.front();
			cout << firstVal << " ";
			vector<eletype> succList = succ(firstVal);
			for (int i = 0; i < succList.size(); i++) {
				eletype succVal = succList.at(i);
				if (!visited[succVal]) {
					toVisit.push(succVal);
					visited[succVal] = true;
				}
			}
			toVisit.pop();
		}
	}
}

void Graph::printGraph() {
	node srchDown = graph, srchRight;
	int cnt = 0;
	while (NULL != srchDown->down) {
		srchDown = srchDown->down;
		cnt++;
	}
	srchDown = graph;
	for (int i = 1; i <= cnt; i++) {
		srchDown = srchDown->down;
		cout << std::left << setw(10) << srchDown->data;
		srchRight = srchDown;
		while (NULL != srchRight->right) {
			srchRight = srchRight->right;
			cout << std::left << setw(10) << srchRight->data;
		}
		cout << endl;
	}
}
void Graph::printMatrix() {
	//绘图
	buildMatrix();
	for (int i = 0; i <= matrixLen; i++) cout << std::left << setw(10) << i;
	cout << endl;
	for (int i = 1; i <= matrixLen; i++) {
		for (int j = 0; j <= matrixLen; j++) {
			cout << std::left << setw(10) << ((0 == j) ? i : matrix[i][j]);
		}
		cout << endl;
	}
}