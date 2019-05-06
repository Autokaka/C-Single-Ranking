#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

class BinaryTree
{
private:
	typedef int eletype;
	struct celltype{
		eletype data;
		celltype* lchild, * rchild;
	};
	typedef celltype* binarytree;
	binarytree btree;

public:
	typedef celltype* treenode;
	BinaryTree();

	treenode Empty();
	bool isEmpty(treenode tgt);
	bool isEmpty();

	treenode createTreeNode(eletype val, treenode lchild, treenode rchild);
	void addTreeNode(eletype val);
	treenode Root();
	treenode leftChild(treenode parent);
	treenode rightChild(treenode parent);
	eletype getData(treenode tgt);

	void preOrder(treenode tgt);
	void inOrder(treenode tgt);
	void postOrder(treenode tgt);
};

#endif

