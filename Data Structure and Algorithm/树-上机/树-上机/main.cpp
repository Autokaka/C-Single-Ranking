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
	cout << "__________题目1__________\n";
	int order[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int order_len = sizeof(order) / sizeof(*order);
	BinaryTree btree = BinaryTree(order, order_len);
	cout << "该树的二度节点数为 " << count2(btree) << " 个." << endl;


	cout << "\n\n__________题目2__________\n";
	cout << "该树的叶节点数位 " << leafNum(btree) << " 个." << endl;


	cout << "\n\n__________题目3__________\n";
	cout << "存入的数组为: ";
	for (int i = 0; i < order_len; i++) cout << order[i] << " ";
	cout << endl << endl;
	ThreadBinaryTree tbtree = ThreadBinaryTree(tbtree.IN, order, order_len);
	cout << "该数组按层序存入线索二叉树中. 其中序表达式理论上为: 8 4 9 2 10 5 1 6 3 7" << endl;
	cout << "实际中序线索二叉树依照线索输出的中序表达式结果为: " << tbtree << endl;


	cout << "\n\n__________题目4__________\n";
	cout << "存入的数组为: ";
	for (int i = 0; i < order_len; i++) cout << order[i] << " ";
	cout << endl;
	Heap maxHeap = Heap();
	for (int i = 0; i < order_len; i++) maxHeap.maxHeapInsert(order[i]);
	cout << "测试maxHeap的存入内容: " << maxHeap << endl;
	cout << "搜索元素值为3的元素在堆中的位置下标: " << maxHeap.findInMaxHeap(5);


	cout << "\n\n__________题目5__________\n";
	char formula[] = "2+3*(5+8)/4-5";
	cout << "原算式为: " << formula << endl;
	int formula_len = 13;
	Calculator calculator = Calculator(formula, formula_len);
	cout << "导入到类内后, 类内二叉树中序遍历测试: ";
	calculator.inOrder();
	cout << endl;
	cout << "所得波兰表达式: " << calculator.setPolandfx() << endl;
	cout << "所得逆波兰表达式: " << calculator.setAntiPolandfx() << endl;
	cout << "根据波兰表达式, 计算结果为: " << calculator.calculate() << endl;
}