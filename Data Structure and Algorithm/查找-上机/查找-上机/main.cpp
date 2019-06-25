#include <iostream>
#include "BinarySearchTree.h"
#include "AVLTree.h"
using namespace std;

int main() {
	cout << "\n\n__________��Ŀ1__________\n";
	cout << "�ڶ����������в�������{ 30, 15, 28, 20, 24, 10, 12, 68, 35, 50, 46, 55 }" << endl;
	int sequence[12] = { 30, 15, 28, 20, 24, 10, 12, 68, 35, 50, 46, 55 };
	int seq_len = 12;
	BinarySearchTree myBSTree = BinarySearchTree(sequence, seq_len);
	cout << "���ö��������������������Ϊ: ";
	myBSTree.inOrder(myBSTree.head());
	cout << endl;



	cout << "\n\n__________��Ŀ2__________\n";
	cout << "��Ŀ1�еĶ������Ƿ�Ϊ����������: " << ((myBSTree.isBSTree(myBSTree.head())) ? "��" : "��") << endl;



	cout << "\n\n__________��Ŀ3__________\n";
	cout << "��AVL���в�������{ 30, 15, 28, 20, 24, 10, 12, 68, 35, 50, 46, 55 }" << endl;
	AVLTree myAVLTree = AVLTree(sequence, seq_len);
	myAVLTree.buildBalance(myAVLTree.head());
	cout << "AVL���ĸ߶�Ϊ: " << myAVLTree.calHeight(myAVLTree.head()) << endl;
	return 0;
}