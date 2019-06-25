#include <iostream> 
#include "Graph.h"
#include "WeightedGraph.h"
using namespace std;

int main() {
	cout << "_________��Ŀ1_________\n";
	Graph myGraph = Graph();
	myGraph.setSucc(myGraph.newNode(1), myGraph.newNode(2));
	myGraph.setSucc(myGraph.newNode(1), myGraph.newNode(4));
	myGraph.setSucc(myGraph.newNode(1), myGraph.newNode(6));

	myGraph.setSucc(myGraph.newNode(2), myGraph.newNode(1));
	myGraph.setSucc(myGraph.newNode(2), myGraph.newNode(3));
	myGraph.setSucc(myGraph.newNode(2), myGraph.newNode(4));
	myGraph.setSucc(myGraph.newNode(2), myGraph.newNode(5));

	myGraph.setSucc(myGraph.newNode(3), myGraph.newNode(2));
	myGraph.setSucc(myGraph.newNode(3), myGraph.newNode(5));

	myGraph.setSucc(myGraph.newNode(4), myGraph.newNode(1));
	myGraph.setSucc(myGraph.newNode(4), myGraph.newNode(2));
	myGraph.setSucc(myGraph.newNode(4), myGraph.newNode(5));
	myGraph.setSucc(myGraph.newNode(4), myGraph.newNode(6));

	myGraph.setSucc(myGraph.newNode(5), myGraph.newNode(2));
	myGraph.setSucc(myGraph.newNode(5), myGraph.newNode(3));
	myGraph.setSucc(myGraph.newNode(5), myGraph.newNode(4));

	myGraph.setSucc(myGraph.newNode(6), myGraph.newNode(1));
	myGraph.setSucc(myGraph.newNode(6), myGraph.newNode(4));

	cout << "����ͼ���ڽӱ�: \n";
	myGraph.printGraph();
	cout << "\n����ͼ���ڽӾ���: \n";
	myGraph.printMatrix();



	cout << "\n\n_________��Ŀ2_________\n";
	Graph myGraph2 = Graph();
	myGraph2.setSucc(myGraph2.newNode(1), myGraph2.newNode(2));
	myGraph2.setSucc(myGraph2.newNode(1), myGraph2.newNode(3));
	myGraph2.setSucc(myGraph2.newNode(3), myGraph2.newNode(4));
	myGraph2.setSucc(myGraph2.newNode(4), myGraph2.newNode(1));

	cout << "����ͼ�ڽӱ�: \n";
	myGraph2.printGraph();
	cout << "\n����ͼ���ڽӾ���: \n";
	myGraph2.printMatrix();



	cout << "\n\n_________��Ŀ3_________\n";
	cout << "����ͼ���ڽӱ�: \n";
	myGraph.printGraph();
	cout << "\n����ͼ���ڽӾ���: \n";
	myGraph.printMatrix();
	cout << "\n�����������: "; 
	myGraph.DFSTraverse();
	cout << "\n�����������: ";
	myGraph.BFSTraverse();



	cout << "\n\n_________��Ŀ4_________\n";
	Graph myGraph3 = Graph();
	myGraph3.setSucc(myGraph3.newNode(1), myGraph3.newNode(6));
	myGraph3.setSucc(myGraph3.newNode(6), myGraph3.newNode(1));
	myGraph3.setSucc(myGraph3.newNode(2), myGraph3.newNode(4));
	myGraph3.setSucc(myGraph3.newNode(4), myGraph3.newNode(2));
	myGraph3.setSucc(myGraph3.newNode(3), myGraph3.newNode(5));
	myGraph3.setSucc(myGraph3.newNode(5), myGraph3.newNode(3));
	cout << "����ͼ���ڽӱ�: \n";
	myGraph3.printGraph();
	cout << "\n����ͼ���ڽӾ���: \n";
	myGraph3.printMatrix();
	cout << "\n������ͼ����ͨ��֧��: " << endl;
	myGraph3.DFSTraverse();



	cout << "\n\n_________��Ŀ9_________\n";
	WeightedGraph myWeightedGraph = WeightedGraph();
	myWeightedGraph.setSucc(myWeightedGraph.newNode('a'), myWeightedGraph.newNode('b'), 6);
	myWeightedGraph.setSucc(myWeightedGraph.newNode('a'), myWeightedGraph.newNode('c'), 3);

	myWeightedGraph.setSucc(myWeightedGraph.newNode('b'), myWeightedGraph.newNode('a'), 6);
	myWeightedGraph.setSucc(myWeightedGraph.newNode('b'), myWeightedGraph.newNode('d'), 1);
	myWeightedGraph.setSucc(myWeightedGraph.newNode('b'), myWeightedGraph.newNode('f'), 5);

	myWeightedGraph.setSucc(myWeightedGraph.newNode('c'), myWeightedGraph.newNode('a'), 3);
	myWeightedGraph.setSucc(myWeightedGraph.newNode('c'), myWeightedGraph.newNode('d'), 6);
	myWeightedGraph.setSucc(myWeightedGraph.newNode('c'), myWeightedGraph.newNode('e'), 6);

	myWeightedGraph.setSucc(myWeightedGraph.newNode('d'), myWeightedGraph.newNode('b'), 1);
	myWeightedGraph.setSucc(myWeightedGraph.newNode('d'), myWeightedGraph.newNode('c'), 6);
	myWeightedGraph.setSucc(myWeightedGraph.newNode('d'), myWeightedGraph.newNode('f'), 5);

	myWeightedGraph.setSucc(myWeightedGraph.newNode('e'), myWeightedGraph.newNode('c'), 6);
	myWeightedGraph.setSucc(myWeightedGraph.newNode('e'), myWeightedGraph.newNode('f'), 2);

	myWeightedGraph.setSucc(myWeightedGraph.newNode('f'), myWeightedGraph.newNode('b'), 5);
	myWeightedGraph.setSucc(myWeightedGraph.newNode('f'), myWeightedGraph.newNode('d'), 5);
	myWeightedGraph.setSucc(myWeightedGraph.newNode('f'), myWeightedGraph.newNode('e'), 2);

	cout << "�������Ȩͼ���ڽӾ���Ϊ: \n";
	myWeightedGraph.printMatrix();
	cout << endl;
	//��ӡPrim�㷨�Ĺ���
	cout << "Prim�㷨����: " << endl;
	myWeightedGraph.Prim();
	//��ӡKruskal�㷨�Ĺ���
	cout << "Kruskal�㷨����: " << endl;
	cout << "��ʱ��������..." << endl;
	


	cout << "\n\n_________��Ŀ5_________\n";
	WeightedGraph myWeightedGraph2 = WeightedGraph();
	myWeightedGraph2.setSucc(myWeightedGraph2.newNode('a'), myWeightedGraph2.newNode('b'), 6);
	myWeightedGraph2.setSucc(myWeightedGraph2.newNode('a'), myWeightedGraph2.newNode('d'), 4);
	myWeightedGraph2.setSucc(myWeightedGraph2.newNode('b'), myWeightedGraph2.newNode('c'), 7);
	myWeightedGraph2.setSucc(myWeightedGraph2.newNode('d'), myWeightedGraph2.newNode('c'), 8);
	myWeightedGraph2.setSucc(myWeightedGraph2.newNode('c'), myWeightedGraph2.newNode('e'), 9);
	myWeightedGraph2.setSucc(myWeightedGraph2.newNode('c'), myWeightedGraph2.newNode('f'), 11);
	myWeightedGraph2.setSucc(myWeightedGraph2.newNode('e'), myWeightedGraph2.newNode('f'), 3);
	myWeightedGraph2.setSucc(myWeightedGraph2.newNode('d'), myWeightedGraph2.newNode('f'), 21);
	cout << "AOE��Ϊ: " << endl;
	myWeightedGraph2.printMatrix();
	cout << "v3(�˴���Ϊc��)�����翪ʼʱ��: " << myWeightedGraph2.earliestBeginTime('a', 'c');
	cout << endl;



	cout << "\n\n_________��Ŀ6_________\n";
	Graph myGraph4 = Graph();
	myGraph4.setSucc(myGraph4.newNode(0), myGraph4.newNode(1));
	myGraph4.setSucc(myGraph4.newNode(0), myGraph4.newNode(2));
	myGraph4.setSucc(myGraph4.newNode(1), myGraph4.newNode(3));
	myGraph4.setSucc(myGraph4.newNode(1), myGraph4.newNode(4));
	myGraph4.setSucc(myGraph4.newNode(2), myGraph4.newNode(4));
	myGraph4.setSucc(myGraph4.newNode(2), myGraph4.newNode(5));
	myGraph4.setSucc(myGraph4.newNode(3), myGraph4.newNode(6));
	myGraph4.setSucc(myGraph4.newNode(3), myGraph4.newNode(7));
	myGraph4.setSucc(myGraph4.newNode(4), myGraph4.newNode(7));
	myGraph4.setSucc(myGraph4.newNode(4), myGraph4.newNode(8));
	myGraph4.setSucc(myGraph4.newNode(5), myGraph4.newNode(7));
	myGraph4.setSucc(myGraph4.newNode(6), myGraph4.newNode(7));
	myGraph4.setSucc(myGraph4.newNode(7), myGraph4.newNode(8));
	cout << "�ڽӱ�Ϊ: " << endl;
	myGraph4.printGraph();
	cout << "�ڽӾ���Ϊ: " << endl << endl;
	myGraph4.printMatrix();
	cout << endl;
	cout << "��������Ϊ: " << endl;
	myGraph4.BFSTraverse();



	cout << "\n\n_________��Ŀ7_________\n";
	WeightedGraph myWeightedGraph3 = WeightedGraph();
	myWeightedGraph3.setSucc(myWeightedGraph3.newNode('a'), myWeightedGraph3.newNode('b'), 45);
	myWeightedGraph3.setSucc(myWeightedGraph3.newNode('a'), myWeightedGraph3.newNode('c'), 15);
	myWeightedGraph3.setSucc(myWeightedGraph3.newNode('a'), myWeightedGraph3.newNode('e'), 15);
	myWeightedGraph3.setSucc(myWeightedGraph3.newNode('b'), myWeightedGraph3.newNode('d'), 20);
	myWeightedGraph3.setSucc(myWeightedGraph3.newNode('b'), myWeightedGraph3.newNode('e'), 15);
	myWeightedGraph3.setSucc(myWeightedGraph3.newNode('b'), myWeightedGraph3.newNode('f'), 15);
	myWeightedGraph3.setSucc(myWeightedGraph3.newNode('c'), myWeightedGraph3.newNode('a'), 10);
	myWeightedGraph3.setSucc(myWeightedGraph3.newNode('c'), myWeightedGraph3.newNode('b'), 10);
	myWeightedGraph3.setSucc(myWeightedGraph3.newNode('c'), myWeightedGraph3.newNode('d'), 60);
	myWeightedGraph3.setSucc(myWeightedGraph3.newNode('d'), myWeightedGraph3.newNode('b'), 30);
	myWeightedGraph3.setSucc(myWeightedGraph3.newNode('d'), myWeightedGraph3.newNode('f'), 20);
	cout << "�ڽӱ�Ϊ: " << endl;
	myWeightedGraph3.printGraph();
	cout << endl;
	cout << "�ڽӾ���Ϊ: " << endl;
	myWeightedGraph3.printMatrix();
	cout << endl;
	cout << "Dijkstra�㷨, ��a���������·��Ϊ: " << endl;
	myWeightedGraph3.Dijkstra('a');



	cout << "\n\n_________��Ŀ8_________\n";
	WeightedGraph myWeightedGraph4 = WeightedGraph();
	myWeightedGraph4.setSucc(myWeightedGraph4.newNode('a'), myWeightedGraph4.newNode('b'), 3);
	myWeightedGraph4.setSucc(myWeightedGraph4.newNode('a'), myWeightedGraph4.newNode('d'), 4);
	myWeightedGraph4.setSucc(myWeightedGraph4.newNode('a'), myWeightedGraph4.newNode('f'), 5);
	myWeightedGraph4.setSucc(myWeightedGraph4.newNode('b'), myWeightedGraph4.newNode('c'), 1);
	myWeightedGraph4.setSucc(myWeightedGraph4.newNode('b'), myWeightedGraph4.newNode('f'), 1);
	myWeightedGraph4.setSucc(myWeightedGraph4.newNode('c'), myWeightedGraph4.newNode('d'), 2);
	myWeightedGraph4.setSucc(myWeightedGraph4.newNode('d'), myWeightedGraph4.newNode('b'), 3);
	myWeightedGraph4.setSucc(myWeightedGraph4.newNode('e'), myWeightedGraph4.newNode('d'), 3);
	myWeightedGraph4.setSucc(myWeightedGraph4.newNode('e'), myWeightedGraph4.newNode('f'), 2);
	myWeightedGraph4.setSucc(myWeightedGraph4.newNode('f'), myWeightedGraph4.newNode('d'), 2);
	cout << "Floyd�㷨���þ���Ϊ: " << endl;
	myWeightedGraph4.Floyd();
	cout << "Warshall�㷨���þ���Ϊ: " << endl;
	myWeightedGraph4.Warshall();
	return 0;
}