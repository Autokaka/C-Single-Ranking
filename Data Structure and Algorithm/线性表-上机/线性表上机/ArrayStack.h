#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

class ArrayStack
{
	static const int maxlen = 100;
private:
	typedef int eletype;
	typedef struct {
		eletype elements[maxlen];
		int top;
	} STACK;
	STACK stack;

	void makeNull();
	
public:
	ArrayStack();

	bool isEmpty();
	bool isFull();

	eletype top();
	eletype pop();
	void push(eletype x);
};

#endif

