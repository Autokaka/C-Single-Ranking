#include "CircularQueue.h"

CircularQueue::CircularQueue()
{
	queue.head = 0;
	queue.length = 0;
}
CircularQueue::CircularQueue(eletype tgt[], int len) {
	queue.head = 0;
	queue.length = 0;
	for (int i = 0; i < len; i++) enQueue(tgt[i]);
}

int CircularQueue::absoluteSeq(int relativeSeq) {
	return ((queue.head + relativeSeq) % maxlen);
}

bool CircularQueue::isEmpty() {
	return (queue.length == 0);
}
bool CircularQueue::isFull() {
	return (queue.length == maxlen - 1);
}

void CircularQueue::enQueue(eletype x) {
	if (!isFull()) queue.elements[absoluteSeq(++queue.length)] = x;
}
void CircularQueue::deQueue() {
	queue.head++;
	queue.length--;
}

ostream& operator<<(ostream& out, const CircularQueue& tgt) {
	CircularQueue tmp = tgt;
	for (int i = 1; i <= tmp.queue.length; i++) out << tmp.queue.elements[tmp.absoluteSeq(i)] << " ";
	return out;
}