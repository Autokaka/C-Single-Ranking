#include <iostream>
#include "LaArrayList.h"
#include "LaPointerList.h"
#include "CursorList.h"
#include "Polynome.h"
#include "ArrayStack.h"
#include "CircularQueue.h"
#include "BracketAdapter.h"
#include "BidirectionalList.h"
using namespace std;

void convert(int num, int n) {
	ArrayStack as = ArrayStack();
	while (num) {
		as.push(num % n);
		num /= n;
	}
	while (!as.isEmpty()) cout << as.pop();
}
int swap(int x, BidirectionalList bl) {
	BidirectionalList::pos p = bl.Locate(x);
	if (p != bl.First()) {
		bl.Insert(x, bl.Prevoius(p));
		bl.Delete(p);
		return 1;
	}
	return 0;
}

int main() {
	/*
	��Ŀ1
	*/
	cout << "__________��Ŀ1__________\n";
	int list1[] = { 1, 2, 3, 4, 5 };
	int len1 = sizeof(list1) / sizeof(*list1);
	int list2[] = { 6, 7, 8, 9, 10 };
	int len2 = sizeof(list2) / sizeof(*list2);
	cout << "[����ʵ��]\n";
	LaArrayList arrayList1 = LaArrayList(list1, len1);
	LaArrayList arrayList2 = LaArrayList(list2, len2);
	cout << "���Ա�1����: " << arrayList1 << endl;
	cout << "���Ա�2����: " << arrayList2 << endl;
	LaArrayList mergedArrayList = arrayList1 + arrayList2;
	cout << "�ϲ�������: " << mergedArrayList << endl;
	cout << "[����ʵ��]\n";
	LaPointerList pointerList1 = LaPointerList(list1, len1);
	LaPointerList pointerList2 = LaPointerList(list2, len2);
	cout << "���Ա�1����: " << pointerList1 << endl;
	cout << "���Ա�2����: " << pointerList2 << endl;
	LaPointerList mergedPointerList = pointerList1 + pointerList2;
	cout << "�ϲ�������: " << mergedPointerList << endl;
	/*
	��Ŀ2
	*/
	cout << "\n\n__________��Ŀ2__________\n";
	cout << "[����ʵ��]\n";
	LaArrayList arrayList3;
	cout << "���Ա�3����: " << arrayList3 << endl;
	arrayList3 = mergedArrayList;
	cout << "���ƺϲ�������ݺ�, ���Ա�3����: " << arrayList3 << endl;
	cout << "[����ʵ��]\n";
	LaPointerList pointerList3;
	cout << "���Ա�3����: " << pointerList3 << endl;
	pointerList3 = mergedPointerList;
	cout << "���ƺϲ�������ݺ�, ���Ա�3����: " << arrayList3 << endl;
	/*
	��Ŀ3
	*/
	cout << "\n\n__________��Ŀ3__________\n";
	cout << "[����ʵ��]\n";
	cout << "�ϲ�������: " << mergedArrayList << endl;
	int delpos = mergedArrayList.Locate(10);
	mergedArrayList.Delete(delpos);
	cout << "ɾ��ֵΪ10�Ľڵ��, �ϲ�������: " << mergedArrayList << "ɾ���ڵ��λ��Ϊ: " << delpos << endl;
	cout << "[����ʵ��]\n";
	cout << "�ϲ�������: " << mergedPointerList << endl;
	delpos = mergedPointerList.Locate(10);
	mergedPointerList.Delete(delpos);
	cout << "ɾ��ֵΪ10�Ľڵ��, �ϲ�������: " << mergedPointerList << "ɾ���ڵ��λ��Ϊ: " << delpos << endl;
	/*
	��Ŀ4
	*/
	cout << "\n\n__________��Ŀ4__________\n";
	CursorList cursorList1 = CursorList(list1, len1);
	CursorList cursorList2 = CursorList(list2, len2);
	cout << "��̬����1����: " << cursorList1 << endl;
	cout << "��̬����2����: " << cursorList2 << endl;
	CursorList mergedList = cursorList1 + cursorList2;
	cout << "�ϲ�������: " << mergedList << endl;
	/*
	��Ŀ5
	*/
	cout << "\n\n__________��Ŀ5__________\n";
	Polynome polynome1 = Polynome();
	polynome1.Insert(1, 2);
	polynome1.Insert(2, 3);
	polynome1.Insert(3, 4);
	Polynome polynome2 = Polynome();
	polynome2.Insert(2, 3);
	polynome2.Insert(4, 5);
	polynome2.Insert(6, 7);
	cout << "����ʽ1����: " << polynome1 << endl;
	cout << "����ʽ2����: " << polynome2 << endl;
	Polynome mergedPolynome = polynome1 + polynome2;
	cout << "��Ӷ���ʽ����: " << mergedPolynome << endl;
	mergedPolynome = polynome1 * polynome2;
	cout << "��˶���ʽ����: " << mergedPolynome << endl;
	/*
	��Ŀ6
	*/
	cout << "\n\n__________��Ŀ6__________\n";
	int num = 1234, n = 2;
	cout << "��ǰnumΪ: " << num << ". ת���� " << n << " �����Ժ�Ϊ: "; convert(num, n); cout << endl;
	/*
	��Ŀ7
	*/
	cout << "\n\n__________��Ŀ7__________\n";
	CircularQueue circularQueue = CircularQueue();
	cout << "�ж϶����Ƿ�Ϊ��: " << (circularQueue.isEmpty() ? "��" : "��") << endl;
	cout << "�ж϶����Ƿ�Ϊ��: " << (circularQueue.isFull() ? "��" : "��") << endl;
	cout << "Ĭ��������󳤶�Ϊ 5 �Ķ���, �����𽥼���Ԫ��, �����������: " << endl;
	for (int i = 1; i < 6; i++) {
		cout << i << "�������. ";
		circularQueue.enQueue(i);
		cout << "��������: " << circularQueue;
		cout << "�ж϶����Ƿ�Ϊ��: " << (circularQueue.isFull() ? "��" : "��") << endl;
	}
	/*
	��Ŀ8
	*/
	cout << "\n\n__________��Ŀ8__________\n";
	BracketAdapter bracketAdapter = BracketAdapter();
	string brackets = "{([()[)]]}";
	cout << "�ַ���������Ϊ: " << brackets << ". �����Ϊ: " << ((bracketAdapter.check(brackets) == bracketAdapter.TRUE) ? "ƥ��" : "��ƥ��");
	/*
	��Ŀ9
	*/
	cout << "\n\n__________��Ŀ9__________\n";
	int blist[] = { 1, 2, 3, 4, 5 };
	int blen = sizeof(blist) / sizeof(*blist);
	BidirectionalList bList = BidirectionalList(blist, blen);
	cout << "��ǰ˫����������: " << bList << endl;
	int ret = swap(3, bList);
	cout << "����Ԫ��ֵΪ3�Ľ���, ˫����������: " << bList << "���ؽ��Ϊ: ����" << (ret == 1 ? "�ɹ�" : "ʧ��") << endl;
	return 0;
}
