#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H
#include <iostream>//必须把这两行写在这里, 否则重载<<函数没法使用private成员
using namespace std;

class CircularQueue
{
	static const int maxlen = 6;
	friend ostream& operator<<(ostream& out, const CircularQueue& tgt);

private:
	typedef int eletype;
	typedef struct {
		eletype elements[maxlen];
		int head, length;
	} QUEUE;
	QUEUE queue;
	int absoluteSeq(int relativeSeq);

public:
	CircularQueue();
	CircularQueue(eletype tgt[], int len);

	bool isEmpty();
	bool isFull();

	void enQueue(eletype x);
	void deQueue();
};

#endif

