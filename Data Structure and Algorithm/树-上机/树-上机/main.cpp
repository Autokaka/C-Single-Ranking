#include <iostream>
#include <string>
#include "BinaryTree.h"
#include "ThreadBinaryTree.h"
#include "Heap.h"
#include "Calculator.h"
using namespace std;

int search2(BinaryTree::treenode parent, int cumulatedCnt) {
	if (parent != NULL) {
		if (parent->lchild != NULL && parent->rchild != NULL) cumulatedCnt++;
		if (parent->lchild != NULL) cumulatedCnt = search2(parent->lchild, cumulatedCnt);
		if (parent->rchild != NULL) cumulatedCnt = search2(parent->rchild, cumulatedCnt);
	}
	return cumulatedCnt;
}
int count2(BinaryTree btree) {
	return search2(btree.Root(), 0);
}

int search0(BinaryTree::treenode parent, int cumulatedCnt) {
	if (parent != NULL) {
		if (parent->lchild == NULL && parent->rchild == NULL) return ++cumulatedCnt;
		if (parent->lchild != NULL) cumulatedCnt = search0(parent->lchild, cumulatedCnt);
		if (parent->rchild != NULL) cumulatedCnt = search0(parent->rchild, cumulatedCnt);
	}
	return cumulatedCnt;
}
int leafNum(BinaryTree btree) {
	return search0(btree.Root(), 0);
}

int main() {
	cout << "__________��Ŀ1__________\n";
	int order[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int order_len = sizeof(order) / sizeof(*order);
	BinaryTree btree = BinaryTree(order, order_len);
	cout << "�����Ķ��Ƚڵ���Ϊ " << count2(btree) << " ��." << endl;


	cout << "\n\n__________��Ŀ2__________\n";
	cout << "������Ҷ�ڵ���λ " << leafNum(btree) << " ��." << endl;


	cout << "\n\n__________��Ŀ3__________\n";
	cout << "���������Ϊ: ";
	for (int i = 0; i < order_len; i++) cout << order[i] << " ";
	cout << endl << endl;
	ThreadBinaryTree tbtree = ThreadBinaryTree(tbtree.IN, order, order_len);
	cout << "�����鰴�������������������. ��������ʽ������Ϊ: 8 4 9 2 10 5 1 6 3 7" << endl;
	cout << "ʵ�����������������������������������ʽ���Ϊ: " << tbtree << endl;


	cout << "\n\n__________��Ŀ4__________\n";
	cout << "���������Ϊ: ";
	for (int i = 0; i < order_len; i++) cout << order[i] << " ";
	cout << endl;
	Heap maxHeap = Heap();
	for (int i = 0; i < order_len; i++) maxHeap.maxHeapInsert(order[i]);
	cout << "����maxHeap�Ĵ�������: " << maxHeap << endl;
	cout << "����Ԫ��ֵΪ3��Ԫ���ڶ��е�λ���±�: " << maxHeap.findInMaxHeap(5);


	cout << "\n\n__________��Ŀ5__________\n";
	char formula[] = "2+3*(5+8)/4-5";
	cout << "ԭ��ʽΪ: " << formula << endl;
	int formula_len = 13;
	Calculator calculator = Calculator(formula, formula_len);
	cout << "���뵽���ں�, ���ڶ����������������: ";
	calculator.inOrder();
	cout << endl;
	cout << "���ò������ʽ: " << calculator.setPolandfx() << endl;
	cout << "�����沨�����ʽ: " << calculator.setAntiPolandfx() << endl;
	cout << "���ݲ������ʽ, ������Ϊ: " << calculator.calculate() << endl;
}