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
	题目1
	*/
	cout << "__________题目1__________\n";
	int list1[] = { 1, 2, 3, 4, 5 };
	int len1 = sizeof(list1) / sizeof(*list1);
	int list2[] = { 6, 7, 8, 9, 10 };
	int len2 = sizeof(list2) / sizeof(*list2);
	cout << "[数组实现]\n";
	LaArrayList arrayList1 = LaArrayList(list1, len1);
	LaArrayList arrayList2 = LaArrayList(list2, len2);
	cout << "线性表1内容: " << arrayList1 << endl;
	cout << "线性表2内容: " << arrayList2 << endl;
	LaArrayList mergedArrayList = arrayList1 + arrayList2;
	cout << "合并表内容: " << mergedArrayList << endl;
	cout << "[链表实现]\n";
	LaPointerList pointerList1 = LaPointerList(list1, len1);
	LaPointerList pointerList2 = LaPointerList(list2, len2);
	cout << "线性表1内容: " << pointerList1 << endl;
	cout << "线性表2内容: " << pointerList2 << endl;
	LaPointerList mergedPointerList = pointerList1 + pointerList2;
	cout << "合并表内容: " << mergedPointerList << endl;
	/*
	题目2
	*/
	cout << "\n\n__________题目2__________\n";
	cout << "[数组实现]\n";
	LaArrayList arrayList3;
	cout << "线性表3内容: " << arrayList3 << endl;
	arrayList3 = mergedArrayList;
	cout << "复制合并表的内容后, 线性表3内容: " << arrayList3 << endl;
	cout << "[链表实现]\n";
	LaPointerList pointerList3;
	cout << "线性表3内容: " << pointerList3 << endl;
	pointerList3 = mergedPointerList;
	cout << "复制合并表的内容后, 线性表3内容: " << arrayList3 << endl;
	/*
	题目3
	*/
	cout << "\n\n__________题目3__________\n";
	cout << "[数组实现]\n";
	cout << "合并表内容: " << mergedArrayList << endl;
	int delpos = mergedArrayList.Locate(10);
	mergedArrayList.Delete(delpos);
	cout << "删除值为10的节点后, 合并表内容: " << mergedArrayList << "删除节点的位置为: " << delpos << endl;
	cout << "[链表实现]\n";
	cout << "合并表内容: " << mergedPointerList << endl;
	delpos = mergedPointerList.Locate(10);
	mergedPointerList.Delete(delpos);
	cout << "删除值为10的节点后, 合并表内容: " << mergedPointerList << "删除节点的位置为: " << delpos << endl;
	/*
	题目4
	*/
	cout << "\n\n__________题目4__________\n";
	CursorList cursorList1 = CursorList(list1, len1);
	CursorList cursorList2 = CursorList(list2, len2);
	cout << "静态链表1内容: " << cursorList1 << endl;
	cout << "静态链表2内容: " << cursorList2 << endl;
	CursorList mergedList = cursorList1 + cursorList2;
	cout << "合并表内容: " << mergedList << endl;
	/*
	题目5
	*/
	cout << "\n\n__________题目5__________\n";
	Polynome polynome1 = Polynome();
	polynome1.Insert(1, 2);
	polynome1.Insert(2, 3);
	polynome1.Insert(3, 4);
	Polynome polynome2 = Polynome();
	polynome2.Insert(2, 3);
	polynome2.Insert(4, 5);
	polynome2.Insert(6, 7);
	cout << "多项式1内容: " << polynome1 << endl;
	cout << "多项式2内容: " << polynome2 << endl;
	Polynome mergedPolynome = polynome1 + polynome2;
	cout << "相加多项式内容: " << mergedPolynome << endl;
	mergedPolynome = polynome1 * polynome2;
	cout << "相乘多项式内容: " << mergedPolynome << endl;
	/*
	题目6
	*/
	cout << "\n\n__________题目6__________\n";
	int num = 1234, n = 2;
	cout << "当前num为: " << num << ". 转换成 " << n << " 进制以后为: "; convert(num, n); cout << endl;
	/*
	题目7
	*/
	cout << "\n\n__________题目7__________\n";
	CircularQueue circularQueue = CircularQueue();
	cout << "判断队列是否为空: " << (circularQueue.isEmpty() ? "是" : "否") << endl;
	cout << "判断队列是否为满: " << (circularQueue.isFull() ? "是" : "否") << endl;
	cout << "默认设置最大长度为 5 的队列, 现在逐渐加入元素, 并检查队列情况: " << endl;
	for (int i = 1; i < 6; i++) {
		cout << i << "进入队列. ";
		circularQueue.enQueue(i);
		cout << "队列内容: " << circularQueue;
		cout << "判断队列是否为满: " << (circularQueue.isFull() ? "是" : "否") << endl;
	}
	/*
	题目8
	*/
	cout << "\n\n__________题目8__________\n";
	BracketAdapter bracketAdapter = BracketAdapter();
	string brackets = "{([()[)]]}";
	cout << "字符串的内容为: " << brackets << ". 检查结果为: " << ((bracketAdapter.check(brackets) == bracketAdapter.TRUE) ? "匹配" : "不匹配");
	/*
	题目9
	*/
	cout << "\n\n__________题目9__________\n";
	int blist[] = { 1, 2, 3, 4, 5 };
	int blen = sizeof(blist) / sizeof(*blist);
	BidirectionalList bList = BidirectionalList(blist, blen);
	cout << "当前双向链表内容: " << bList << endl;
	int ret = swap(3, bList);
	cout << "交换元素值为3的结点后, 双向链表内容: " << bList << "返回结果为: 交换" << (ret == 1 ? "成功" : "失败") << endl;
	return 0;
}
