#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
using namespace std;

class BinarySearchTree
{
private:
	typedef int eletype;
	typedef struct celltype {
		eletype data;
		struct celltype* lchild, * rchild;
	} BSTNode;
	typedef BSTNode* node;
	node bsTree;

public:
	BinarySearchTree();
	BinarySearchTree(eletype seq[], int len);
	bool isEmpty(node tgt);
	node head();
	node newNode(eletype val, node lchild, node rchild);
	node search(node root, eletype val);
	void insert(node &root, eletype val);
	void inOrder(node root);
	bool isBSTree(node root);

};

#endif