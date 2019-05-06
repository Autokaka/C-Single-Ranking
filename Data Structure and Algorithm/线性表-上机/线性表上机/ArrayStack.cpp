#include "ArrayStack.h"
#include <iostream>
using namespace std;

ArrayStack::ArrayStack()
{
	makeNull();
}

void ArrayStack::makeNull() {
	stack.top = 0;
}

bool ArrayStack::isEmpty() {
	return (stack.top == 0);
}
bool ArrayStack::isFull() {
	return (stack.top == maxlen - 1);
}

ArrayStack::eletype ArrayStack::top() {
	if (!isEmpty()) return stack.elements[stack.top];
}
ArrayStack::eletype ArrayStack::pop() {
	if (!isEmpty()) {
		stack.top--;
		return stack.elements[stack.top + 1];
	}
}
void ArrayStack::push(eletype x) {
	if (!isFull()) stack.elements[++stack.top] = x;
}
