#include "Heap.h"
using namespace std;

Heap::Heap() {
	heap.size = 0;
}

void Heap::emptyHeap() {
	heap.size = 0;
}

bool Heap::isFull() {
	return (maxlen - 1 == heap.size);
}
bool Heap::isEmpty() {
	return (0 == heap.size);
}
int Heap::size() {
	return heap.size;
}

void Heap::maxHeapInsert(eletype x) {
	int i;
	if (!isFull()) {
		i = ++heap.size;
		while ((i != 1) && (x > heap.element[i / 2])) {
			heap.element[i] = heap.element[i / 2];
			i /= 2;
		}
		heap.element[i] = x;
	}
}
void Heap::minHeapInsert(eletype x) {
	int i;
	if (!isFull()) {
		i = heap.size + 1;
		while ((i != 1) && (x < heap.element[i / 2])) {
			heap.element[i] = heap.element[i / 2];
			i /= 2;
		}
		heap.element[i] = x;
	}
}
void Heap::deleteMaxHeapMax(HEAP heap) {
	int maxIndex = 1, secondBigIndex = 2;
	eletype maxElement, lastElement;
	if (!isEmpty()) {
		maxElement = heap.element[1];
		lastElement = heap.element[heap.size--];
		while (secondBigIndex <= heap.size)
		{
			//寻找第二大的元素作为最大的元素
			if ((secondBigIndex < heap.size) && (heap.element[secondBigIndex] < heap.element[secondBigIndex + 1])) secondBigIndex++;
			//如果最后一个元素本身就比找到的最大元素还要大, 那就直接把它放在第一个元素即可, 不需要再向下维护最大堆的子树
			if (lastElement >= heap.element[secondBigIndex]) break;
			//更新最大元素
			heap.element[maxIndex] = heap.element[secondBigIndex];
			//刷新最大值下标, 使其变成第二大的下标, 达到向下传递作用
			maxIndex = secondBigIndex;
			//随最大值下标变化重新规定第二大值的下标
			secondBigIndex *= 2;
		}
		heap.element[maxIndex] = lastElement;
	}
}
void Heap::deleteMinHeapMin(HEAP heap) {
	int minIndex = 1, secondSmallIndex = 2;
	eletype minElement, lastElement;
	if (!isEmpty()) {
		minElement = heap.element[1];
		lastElement = heap.element[heap.size--];
		while (secondSmallIndex <= heap.size)
		{
			if ((secondSmallIndex < heap.size) && (heap.element[secondSmallIndex] > heap.element[secondSmallIndex + 1])) secondSmallIndex++;
			if (lastElement <= heap.element[secondSmallIndex]) break;
			heap.element[minIndex] = heap.element[secondSmallIndex];
			minIndex = secondSmallIndex;
			secondSmallIndex *= 2;
		}
		heap.element[minIndex] = lastElement;
	}
}
int Heap::findInMaxHeap(eletype x) {
	return searchSmallChild(1, x);
}
int Heap::searchSmallChild(int index, int x) {
	if (x > heap.element[index]) return 0;
	if (x == heap.element[index]) return index;
	int leftResult = searchSmallChild(index * 2, x);
	if (0 != leftResult) return leftResult;
	return searchSmallChild(index * 2 + 1, x);
}
int Heap::findInMinHeap(eletype x)
{
	return searchBigChild(1, x);
	return 0;
}
int Heap::searchBigChild(int index, int x) {
	if (x < heap.element[index]) return 0;
	if (x == heap.element[index]) return index;
	int leftResult = searchSmallChild(index * 2, x);
	if (0 != leftResult) return leftResult;
	return searchSmallChild(index * 2 + 1, x);
}

ostream& operator<<(ostream& out, const Heap& tgt) {
	for (int i = 1; i <= tgt.heap.size; i++) out << tgt.heap.element[i] << " ";
	return out;
}