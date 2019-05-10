#include "BinaryTree.h"
#include <cstddef>

BinaryTree::BinaryTree() {
	btree = Empty();
}
BinaryTree::BinaryTree(eletype order[], int len) {
	btree = Empty();
	for (int i = 0; i < len; i++) addTreeNode(Root(), order[i]);
}

BinaryTree::treenode BinaryTree::Empty() {
	return NULL;
}
bool BinaryTree::isEmpty(treenode tgt) {
	return (tgt == NULL);
}

BinaryTree::treenode BinaryTree::createTreeNode(eletype val, treenode lchild, treenode rchild) {
	treenode add = new celltype;
	add->data = val;
	add->lchild = lchild;
	add->rchild = rchild;
	return add;
}
bool BinaryTree::addTreeNode(treenode parent, eletype val) {
	treenode srch = parent;
	if (isEmpty(Root())) {
		btree = createTreeNode(val, NULL, NULL);
		return true;
	}
	else if (isEmpty(srch->lchild)) {
		srch->lchild = createTreeNode(val, NULL, NULL);
		return true;
	}
	else if (isEmpty(srch->rchild)) {
		srch->rchild = createTreeNode(val, NULL, NULL);
		return true;
	}
	if (!addTreeNode(parent->lchild, val)) return addTreeNode(parent->rchild, val);
}

BinaryTree::treenode BinaryTree::Root() {
	return btree;
}
BinaryTree::treenode BinaryTree::leftChild(treenode parent) {
	return parent->lchild;
}
BinaryTree::treenode BinaryTree::rightChild(treenode parent) {
	return parent->rchild;
}
BinaryTree::eletype BinaryTree::getData(treenode tgt) {
	return tgt->data;
}

void BinaryTree::preOrder(treenode tgt) {
	if (!isEmpty(tgt)) {
		cout << getData(tgt) << " ";
		preOrder(tgt->lchild);
		preOrder(tgt->rchild);
	}
}
void BinaryTree::inOrder(treenode tgt) {
	if (!isEmpty(tgt)) {
		inOrder(tgt->lchild);
		cout << getData(tgt) << " ";
		inOrder(tgt->rchild);
	}
}
void BinaryTree::postOrder(treenode tgt) {
	if (!isEmpty(tgt)) {
		postOrder(tgt->lchild);
		postOrder(tgt->rchild);
		cout << getData(tgt) << " ";
	}
}
