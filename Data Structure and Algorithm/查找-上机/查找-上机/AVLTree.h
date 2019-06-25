#ifndef AVLTREE_H
#define AVLTREE_H
using namespace std;

class AVLTree
{
private:
	typedef int eletype;
	typedef struct celltype {
		eletype data;
		int balance;
		struct celltype* lchild, * rchild;
	} AVLTNode;
	typedef AVLTNode* node;
	node avlTree;

public:
	AVLTree();
	AVLTree(eletype seq[], int len);
	bool isEmpty(node tgt);
	node head();
	node newNode(eletype val, node lchild, node rchild);
	node search(node root, eletype val);
	void insert(node& root, eletype val);
	int buildBalance(node root);
	int calHeight(node root);
};

#endif

