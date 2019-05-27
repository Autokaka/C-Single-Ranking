#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

class Heap
{
	static const int maxlen = 200;
	friend ostream& operator<<(ostream& out, const Heap& tgt);

private:
	typedef int eletype;
	typedef struct {
		eletype element[maxlen];
		int size;
	}HEAP;
	HEAP heap;

	int searchBigChild(int index, int x);
	int searchSmallChild(int index, int x);
public:
	Heap();
	
	void emptyHeap();

	bool isFull();
	bool isEmpty();
	int size();

	void maxHeapInsert(eletype x);
	void minHeapInsert(eletype x);
	void deleteMaxHeapMax(HEAP heap);
	void deleteMinHeapMin(HEAP heap);
	int findInMaxHeap(eletype x);
	int findInMinHeap(eletype x);
};

#endif