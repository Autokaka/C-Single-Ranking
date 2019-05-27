#ifndef THREADBINARYTREE_H
#define THREADBINARYTREE_H
#include <iostream>
#include <queue>
using namespace std;

class ThreadBinaryTree
{
	friend ostream& operator<<(ostream& out, const ThreadBinaryTree& tgt);

private:
	typedef enum { LINK, THREAD } tag;
	typedef int eletype;
	struct celltype {
		eletype data;
		celltype* lchild, * rchild;
		tag ltag, rtag;//1��ʾ����, 0��ʾָ��
	};
	typedef celltype* binarytree;
	typedef celltype* treenode;
	binarytree threadTree;
	bool isThreadBuilt;
	//��¼����������ά��ģʽ
	int treeMode;
	//bfs˳�������ʱ��Ҫ�õ��Ķ���
	queue<treenode> treeStatus;
	queue<int> test;

	treenode fetchRChildsMostLeft(treenode now);
	treenode fetchLChildsMostRight(treenode now);

public:
	typedef enum { PRE, IN, POST } treemode;
	typedef celltype* treenode;
	ThreadBinaryTree(treemode mode);
	ThreadBinaryTree(treemode mode, eletype order[], int len);

	treenode Empty(treenode tgt);
	bool isEmpty(treenode tgt);

	bool addTreeNode(treenode parent, eletype val);
	treenode createTreeNode(eletype val, treenode lchild, tag ltag, treenode rchild, tag rtag);
	treenode head();
	treenode first();
	eletype data(treenode tgt);
	treenode leftChild(treenode parent);
	treenode rightChild(treenode parent);

	void leftInsert(treenode tgt, treenode add);
	void rightInsert(treenode tgt, treenode add);
	void buildThread(treenode now, treenode pre, treenode next);
};

#endif

