#ifndef THREADBINARYTREE_H
#define THREADBINARYTREE_H
#include <iostream>
using namespace std;

class ThreadBinaryTree
{
private:
	typedef int eletype;
	struct celltype {
		eletype data;
		celltype* lchild, * rchild;
		bool ltag, rtag;
	};
	typedef celltype* binarytree;
	binarytree preTree, inTree, postTree;

public:
	typedef celltype* treenode;
	ThreadBinaryTree();
	ThreadBinaryTree(eletype order[], int len);

	treenode Empty(treenode tgt);
	bool isEmpty(treenode tgt);

	treenode createTreeNode(eletype val, treenode lchild, bool ltag, treenode rchild, bool rtag);
	bool addTreeNode(treenode parent, eletype val);
	treenode getTreeHead(int treeMode);
	treenode leftChild(treenode parent);
	treenode rightChild(treenode parent);
	eletype getData(treenode tgt);

	treenode buildThread(treenode parent, int treeMode);
	treenode getNextNode(treenode parent, int treeMode);//treeMode: 0->先序线索二叉树; 1->中序线索二叉树; 2->后序线索二叉树
	treenode getPreNode(treenode parent, int treeMode);
};

#endif

