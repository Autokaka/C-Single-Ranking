#include <iostream>
#include "BinarySearchTree.h"
#include "AVLTree.h"
using namespace std;

int main() {
	cout << "\n\n__________题目1__________\n";
	cout << "在二叉排序树中插入序列{ 30, 15, 28, 20, 24, 10, 12, 68, 35, 50, 46, 55 }" << endl;
	int sequence[12] = { 30, 15, 28, 20, 24, 10, 12, 68, 35, 50, 46, 55 };
	int seq_len = 12;
	BinarySearchTree myBSTree = BinarySearchTree(sequence, seq_len);
	cout << "所得二叉排序树中序遍历序列为: ";
	myBSTree.inOrder(myBSTree.head());
	cout << endl;



	cout << "\n\n__________题目2__________\n";
	cout << "题目1中的二叉树是否为二叉排序树: " << ((myBSTree.isBSTree(myBSTree.head())) ? "是" : "否") << endl;



	cout << "\n\n__________题目3__________\n";
	cout << "在AVL树中插入序列{ 30, 15, 28, 20, 24, 10, 12, 68, 35, 50, 46, 55 }" << endl;
	AVLTree myAVLTree = AVLTree(sequence, seq_len);
	myAVLTree.buildBalance(myAVLTree.head());
	cout << "AVL树的高度为: " << myAVLTree.calHeight(myAVLTree.head()) << endl;
	return 0;
}