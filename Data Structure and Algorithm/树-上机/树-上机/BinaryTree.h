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
	BinaryTree(eletype order[], int len);

	treenode Empty();
	bool isEmpty(treenode tgt);

	treenode createTreeNode(eletype val, treenode lchild, treenode rchild);
	bool addTreeNode(treenode parent, eletype val);
	treenode Root();
	treenode leftChild(treenode parent);
	treenode rightChild(treenode parent);
	eletype getData(treenode tgt);

	void preOrder(treenode tgt);
	void inOrder(treenode tgt);
	void postOrder(treenode tgt);
};

#endif

