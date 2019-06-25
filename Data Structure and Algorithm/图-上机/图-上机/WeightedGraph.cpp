#include "WeightedGraph.h"
#include <iomanip>
#include <queue>
#include <vector>
using namespace std;

WeightedGraph::WeightedGraph() {
	graph = new celltype;
	graph->data = 0;
	graph->weight = 0;
	graph->down = NULL;
	graph->right = NULL;
}

WeightedGraph::node WeightedGraph::newNode(eletype vertex_val) {
	node add = new celltype;
	add->data = vertex_val;
	add->weight = 0;
	add->down = NULL;
	add->right = NULL;
	return add;
}
void WeightedGraph::delNode(eletype vertex_val) {
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
void WeightedGraph::setSucc(node from, node to, int weight) {
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
			srch2 = srch2->right;
			srch2->weight = weight;
			return;
		}
	}
	srch1->down = newNode(from->data);
	srch1 = srch1->down;
	srch1->right = newNode(to->data);
	srch1 = srch1->right;
	srch1->weight = weight;
}
void WeightedGraph::delSucc(node from, node to) {
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
void WeightedGraph::buildMatrix() {
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
			maxRight = srchRight->data - 'a';
			if (maxRight > matrixLen) matrixLen = maxRight;
			int srchDownVal = srchDown->data - 'a', srchRightVal = srchRight->data - 'a';
			matrix[srchDownVal][srchRightVal] = srchRight->weight;
		}
		int maxDown = srchDown->data - 'a';
		if (maxDown > matrixLen) matrixLen = srchDown->data;
	}
	matrixLen += 1;
}

vector<WeightedGraph::eletype> WeightedGraph::succ(eletype vertex_val) {
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
vector<WeightedGraph::eletype> WeightedGraph::pre(eletype vertex_val) {
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
int WeightedGraph::weight(eletype from, eletype to) {
	if (0 == matrixLen) buildMatrix();
	if (from == to) return 0;
	from -= 'a', to -= 'a';
	if (0 == matrix[from][to]) return INF;
	return matrix[from][to];
}

int WeightedGraph::countConnectedComponentNum() {
	bool visited[100] = { 0 };
	int num = 0;
	node srchDown = graph;
	while (NULL != srchDown->down) {
		srchDown = srchDown->down;
		if (!visited[srchDown->data]) {
			markConnectedComponent(srchDown, visited);
			num++;
		}
	}
	return num;
}
void WeightedGraph::markConnectedComponent(node now, bool* visited) {
	if (visited[now->data] || NULL == now) return;
	else {
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
void WeightedGraph::DFSTraverse() {
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
void WeightedGraph::DFSSearch(node now, bool* visited) {
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
void WeightedGraph::BFSTraverse() {
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
void WeightedGraph::BFSSearch(node now, bool* visited) {
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

void WeightedGraph::printGraph() {
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
void WeightedGraph::printMatrix() {
	//绘图
	buildMatrix();
	for (int i = -1; i < matrixLen; i++) {
		if (-1 == i) cout << std::left << setw(10) << 0;
		else cout << std::left << setw(10) << (char)(i + 'a');
	}
	cout << endl;
	for (int i = 0; i < matrixLen; i++) {
		for (int j = -1; j < matrixLen; j++) {
			if (-1 == j) cout << std::left << setw(10) << (char)(i + 'a');
			else cout << std::left << setw(10) << matrix[i][j];
		}
		cout << endl;
	}
}

void WeightedGraph::Prim() {
	if (0 == matrixLen) buildMatrix();
	//初始化
	vector<eletype> v, u, closest;
	vector<int> lowcost;
	u.push_back('a');
	for (int i = 1; i < matrixLen; i++) {
		v.push_back('a' + i);
		closest.push_back('a');
		lowcost.push_back(weight('a' + i, 'a'));
	}
	//汇报当前状态
	cout << "初始u的状态: ";
	for (int i = 0; i < u.size(); i++) cout << u.at(i) << " ";
	cout << endl;
	cout << "初始v的状态: ";
	for (int i = 0; i < v.size(); i++) cout << v.at(i) << " ";
	cout << endl << endl;
	while (u.size() < matrixLen) {
		//开始寻找最近结点
		int minCost = INF, minIndex = -1;
		for (int i = 0; i < lowcost.size(); i++) {
			int lowCost = lowcost.at(i);
			if (lowCost < minCost) {
				minCost = lowCost;
				minIndex = i;
			}
		}
		//从v中删除已经要加入u的结点
		u.push_back(v.at(minIndex));
		v.erase(v.begin() + minIndex);
		closest.erase(closest.begin() + minIndex);
		lowcost.erase(lowcost.begin() + minIndex);
		//汇报当前状态
		cout << "u中即将加入的结点 " << u.back() << " 到当前u的最短距离为: " << minCost << endl;
		cout << "加入后u的状态: ";
		for (int i = 0; i < u.size(); i++) cout << u.at(i) << " ";
		cout << endl;
		cout << "加入后v的状态: ";
		for (int i = 0; i < v.size(); i++) cout << v.at(i) << " ";
		cout << endl << endl;
		//重新维护剩下结点相对u的参数
		for (int i = 0; i < v.size(); i++) {
			for (int j = 0; j < u.size(); j++) {
				int getWeight = weight(v.at(i), u.at(j));
				if (getWeight < lowcost.at(i)) {
					lowcost.at(i) = getWeight;
				}
			}
		}
	}
}
void WeightedGraph::Kruskal() {
	//不会做!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	eletype from, to, minWeight = INF;
	WeightedGraph testGraph = WeightedGraph();
	while (1) {
		for (int i = 0; i < matrixLen; i++) {
			for (int j = 0; j < matrixLen; j++) {
				int lowWeight = weight('a' + i, 'a' + j);
				if (lowWeight < minWeight) {
					minWeight = lowWeight;
				}
			}
		}
	}
}

int WeightedGraph::earliestBeginTime(eletype from, eletype to) {
	if (from == to) return 0;
	int minBeginTime = 0;
	vector<eletype> former;
	for (int i = 0; i < matrixLen; i++) {
		if (0 != weight('a' + i, to) && INF != weight('a' + i, to)) {
			former.push_back('a' + i);
		}
	}
	for (int i = 0; i < former.size(); i++) {
		int calTime = weight(former[i], to) + earliestBeginTime(from, former[i]);
		if (calTime > minBeginTime) {
			minBeginTime = calTime;
		}
	}
	return minBeginTime;
}

void WeightedGraph::Dijkstra(eletype start) {
	//初始化
	vector<eletype> S, letterOfD;
	vector<int> D;
	vector<bool> vis;
	eletype w = start;
	S.push_back(start);
	for (int i = 0; i < matrixLen; i++) {
		vis.push_back(false);
		D.push_back(INF);
		letterOfD.push_back('a' + i);
	}
	vis[0] = true;
	if (0 == matrixLen) buildMatrix();
	//列表计算
	for (int i = 0; i < matrixLen - 1; i++) {
		//更新D并选出下一个w
		int minWeight = INF, minIndex = -1;
		for (int j = 0; j < S.size(); j++) {
			for (int k = 0; k < D.size(); k++) {
				if (vis[k]) continue;
				int calWeight = weight(S[j], letterOfD[k]);
				if (!(start == S[j] || INF == calWeight)) {
					int l;
					for (l = 0; l < letterOfD.size(); l++) if (letterOfD[l] == S[j]) break;
					calWeight = D[l] + calWeight;
				}
				if (calWeight < D[k]) D[k] = calWeight;
				if (minWeight > D[k]) {
					minWeight = D[k];
					w = letterOfD[k];
					minIndex = k;
				}
			}
		}
		//打印寻找结果
		cout << "S中存入: " << w << ".\t" << start << "->" << w << "的最短路径为: " << D[minIndex] << endl;
		//更新S和D
		S.push_back(w);
		vis[minIndex] = true;
	}
}
void WeightedGraph::Floyd() {
	if (0 == matrixLen) buildMatrix();
	int A[100][100] = { 0 };
	for (int i = 0; i < matrixLen; i++) {
		for (int j = 0; j < matrixLen; j++) {
			int calWeight = weight('a' + i, 'a' + j);
			if (INF == calWeight) A[i][j] = INF / 2;
			else A[i][j] = calWeight;
		}
	}
	for (int k = 0; k < matrixLen; k++) {
		for (int i = 0; i < matrixLen; i++) {
			for (int j = 0; j < matrixLen; j++) {
				if (A[i][k] + A[k][j] < A[i][j])
					A[i][j] = A[i][k] + A[k][j];
			}
		}
	}
	//打印最短路径信息
	for (int i = -1; i < matrixLen; i++) {
		if (-1 == i) cout << std::left << setw(10) << 0;
		else cout << std::left << setw(10) << (char)(i + 'a');
	}
	cout << endl;
	for (int i = 0; i < matrixLen; i++) {
		for (int j = -1; j < matrixLen; j++) {
			if (-1 == j) cout << std::left << setw(10) << (char)(i + 'a');
			else if (A[i][j] >= INF / 2) cout << std::left << setw(10) << 0;
			else cout << std::left << setw(10) << A[i][j];
		}
		cout << endl;
	}
}
void WeightedGraph::Warshall() {
	if (0 == matrixLen) buildMatrix();
	int A[100][100] = { 0 };
	for (int i = 0; i < matrixLen; i++) {
		for (int j = 0; j < matrixLen; j++) {
			int calWeight = weight('a' + i, 'a' + j);
			if (0 == calWeight || INF == calWeight) A[i][j] = 0;
			else A[i][j] = 1;
		}
	}
	for (int k = 0; k < matrixLen; k++) {
		for (int i = 0; i < matrixLen; i++) {
			for (int j = 0; j < matrixLen; j++) {
				cout << "\n\nijk: " << i << j << k << endl;
				cout << "A[" << i << "][" << k << "]: " << A[i][k] << " A[" << k << "][" << j << "]: " << A[k][j] << " A[" << i << "][" << j << "]: " << A[i][j];
				A[i][j] = (A[i][j] ^ (A[i][k] && A[k][j]));
				cout << "修改后的A[" << i << "][" << j << "]: " << A[i][j] << endl << endl;
			}
		}
	}
	//打印最短路径信息
	for (int i = -1; i < matrixLen; i++) {
		if (-1 == i) cout << std::left << setw(10) << 0;
		else cout << std::left << setw(10) << (char)(i + 'a');
	}
	cout << endl;
	for (int i = 0; i < matrixLen; i++) {
		for (int j = -1; j < matrixLen; j++) {
			if (-1 == j) cout << std::left << setw(10) << (char)(i + 'a');
			else cout << std::left << setw(10) << A[i][j];
		}
		cout << endl;
	}
}

