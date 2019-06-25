#include "AVLTree.h"
#include <iostream>
using namespace std;

AVLTree::AVLTree() {
}

AVLTree::AVLTree(eletype seq[], int len) {
	for (int i = 0; i < len; i++) insert(avlTree, seq[i]);
}

bool AVLTree::isEmpty(node tgt) {
	return (NULL == tgt);
}

AVLTree::node AVLTree::head() {
	return avlTree;
}

AVLTree::node AVLTree::newNode(eletype val, node leftChild, node rightCchild)
{
	node add = new celltype;
	add->data = val;
	add->lchild = leftChild;
	add->rchild = rightCchild;
	return add;
}

AVLTree::node AVLTree::search(node root, eletype val) {
	if (isEmpty(root)) return NULL;
	if (val == root->data) return root;
	if (val < root->data) return search(root->lchild, val);
	else return search(root->rchild, val);
}

void AVLTree::insert(node & root, eletype val) {
	if (isEmpty(root)) {
		root = newNode(val, NULL, NULL);
		return;
	}
	if (val < root->data) insert(root->lchild, val);
	if (val > root->data) insert(root->rchild, val);
}

int AVLTree::buildBalance(node root) {
	if (isEmpty(root->lchild) && isEmpty(root->rchild)) return 1;
	int leftBalance = 0, rightBalance = 0;
	if (!isEmpty(root->lchild)) leftBalance = buildBalance(root->lchild);
	if (!isEmpty(root->rchild)) rightBalance = buildBalance(root->rchild);
	root->balance = leftBalance - rightBalance;
	cout << root->data << "的平衡因子为: " << root->balance << endl;
	return root->balance;
}

int AVLTree::calHeight(node root)
{
	int leftHeight = 0, rightHeight = 0;
	if (isEmpty(root->lchild) && isEmpty(root->rchild)) return 1;
	if (!isEmpty(root->lchild)) leftHeight = calHeight(root->lchild);
	if (!isEmpty(root->rchild)) rightHeight = calHeight(root->rchild);
	if (leftHeight > rightHeight) return (leftHeight + 1);
	return (rightHeight + 1);
}
