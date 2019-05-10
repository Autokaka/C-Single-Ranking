#include <iostream>
#include "BinaryTree.h"
#include "ThreadBinaryTree.h"
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
	BinaryTree btree = BinaryTree(order, sizeof(order) / sizeof(*order));
	cout << "该树的二度节点数为 " << count2(btree)  << " 个."<< endl;
	cout << "\n\n__________题目2__________\n";
	cout << "该树的叶节点数位 " << leafNum(btree) << " 个." << endl;

}