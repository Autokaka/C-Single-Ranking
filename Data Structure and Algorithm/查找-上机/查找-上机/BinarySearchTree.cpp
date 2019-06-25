#include "BinarySearchTree.h"
#include <iostream>
#include <cstddef>
using namespace std;

BinarySearchTree::BinarySearchTree() {

}

BinarySearchTree::BinarySearchTree(eletype seq[], int len) {
	for (int i = 0; i < len; i++) insert(bsTree, seq[i]);
}

bool BinarySearchTree::isEmpty(node tgt) {
	return (NULL == tgt);
}

BinarySearchTree::node BinarySearchTree::head() {
	return bsTree;
}

BinarySearchTree::node BinarySearchTree::newNode(eletype val, node leftChild, node rightCchild)
{
	node add = new celltype;
	add->data = val;
	add->lchild = leftChild;
	add->rchild = rightCchild;
	return add;
}

BinarySearchTree::node BinarySearchTree::search(node root, eletype val) {
	if (isEmpty(root)) return NULL;
	if (val == root->data) return root;
	if (val < root->data) return search(root->lchild, val);
	else return search(root->rchild, val);
}

void BinarySearchTree::insert(node &root, eletype val) {
	if (isEmpty(root)) {
		root = newNode(val, NULL, NULL);
		return;
	}
	if (val < root->data) insert(root->lchild, val);
	if (val > root->data) insert(root->rchild, val);
}

void BinarySearchTree::inOrder(node root) {
	if (isEmpty(root)) return;
	if (!isEmpty(root->lchild)) inOrder(root->lchild);
	cout << root->data << " ";
	if (!isEmpty(root->rchild)) inOrder(root->rchild);
}

bool BinarySearchTree::isBSTree(node root) {
	if (isEmpty(root)) return true;
	if (!isEmpty(root->lchild) && (!isBSTree(root->lchild) || root->lchild->data >= root->data)) return false;
	if (!isEmpty(root->rchild) && (!isBSTree(root->rchild) || root->rchild->data <= root->data)) return false;
	return true;
}
