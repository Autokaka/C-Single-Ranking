#include "ThreadBinaryTree.h"

ThreadBinaryTree::ThreadBinaryTree() {
	preTree = Empty(preTree);
	inTree = Empty(inTree);
	postTree = Empty(postTree);
}
ThreadBinaryTree::ThreadBinaryTree(eletype order[], int len) {
	//����ͷ���
	preTree = Empty(preTree);
	inTree = Empty(inTree);
	postTree = Empty(inTree);
	for (int i = 0; i < len; i++) {

	}
}

ThreadBinaryTree::treenode ThreadBinaryTree::Empty(treenode tgt) {
	return (createTreeNode(0, NULL, true, tgt, true));
}
bool ThreadBinaryTree::isEmpty(treenode tgt) {
	return (tgt == NULL);
}

ThreadBinaryTree::treenode ThreadBinaryTree::createTreeNode(eletype val, treenode lchild, bool ltag, treenode rchild, bool rtag) {
	treenode add = new celltype;
	add->data = val;
	add->lchild = lchild;
	add->ltag = ltag;
	add->rchild = rchild;
	add->rtag = rtag;
	return add;
}
ThreadBinaryTree::treenode ThreadBinaryTree::getTreeHead(int treeMode) {
	switch (treeMode)
	{
	default:
		cout << "��֧�ֵĶ�����ģʽ, �޷�����ͷ�ڵ�..." << endl;
		break;
	case 0://��������������
		return preTree;
		break;
	case 1://��������������
		return inTree;
		break;
	case 2://��������������
		return postTree;
		break;
	}
}

ThreadBinaryTree::treenode ThreadBinaryTree::buildThread(treenode parent, int treeMode) {
	
}
ThreadBinaryTree::treenode ThreadBinaryTree::getNextNode(treenode parent, int treeMode) {
	switch (treeMode)
	{
	default:
		cout << "������ģʽ����, �޷���ȡ��һ���..." << endl;
		break;
	case 0://��������������
		break;
	case 1://��������������
		break;
	case 2://��������������
		break;
	}
}
ThreadBinaryTree::treenode ThreadBinaryTree::getPreNode(treenode parent, int treeMode) {
	switch (treeMode)
	{
	default:
		break;
	case 0:
		break;
	case 1:

		break;
	case 2:
		break;
	}

}
