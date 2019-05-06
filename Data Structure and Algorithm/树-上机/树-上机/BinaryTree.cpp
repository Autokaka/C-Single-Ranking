#include "BinaryTree.h"
#include <cstddef>

BinaryTree::BinaryTree() {
	btree = Empty();
}

BinaryTree::treenode BinaryTree::Empty() {
	return NULL;
}
bool BinaryTree::isEmpty(treenode tgt) {
	return (tgt == NULL);
}
bool BinaryTree::isEmpty()
{
	return (btree == NULL);
}

BinaryTree::treenode BinaryTree::createTreeNode(eletype val, treenode lchild, treenode rchild) {
	treenode add = new celltype;
	add->data = val;
	add->lchild = lchild;
	add->rchild = rchild;
	return add;
}
void BinaryTree::addTreeNode(eletype val) {
	treenode srch = btree;
	while (!isEmpty(srch)) {
		if (!isEmpty(srch->lchild) && isEmpty(srch->rchild)) srch = srch->lchild;
		if (isEmpty(srch->lchild) && !isEmpty(srch->rchild)) srch = srch->rchild;
	}
	srch = createTreeNode(val, NULL, NULL);
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
