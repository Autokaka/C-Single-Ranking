#ifndef BRACKETADAPTER_H
#define BRACKETADAPTER_H
#include "ArrayStack.h"
#include <iostream>
using namespace std;

class BracketAdapter
{
	static const int maxlen = 100;

private:
	typedef char eletype;
	typedef struct {
		eletype elements[maxlen];
		int top;
	} STACK;
	STACK stack;

	void makeNull();

public:
	enum Boolean { TRUE, FALSE };
	BracketAdapter();

	bool isEmpty();
	bool isFull();
	Boolean check(string brackets);

	eletype top();
	eletype pop();
	void push(eletype x);
};

#endif

