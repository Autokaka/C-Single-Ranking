#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H
#include <iostream>//�����������д������, ��������<<����û��ʹ��private��Ա
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

