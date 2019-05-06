#include "BracketAdapter.h"

BracketAdapter::BracketAdapter() {
	makeNull();
}

BracketAdapter::Boolean BracketAdapter::check(string brackets)
{
	for (int i = 0; i < brackets.length(); i++) {
		switch (brackets[i])
		{
		default:
			break;
		case '(':
		case '[':
		case '{':
			push(brackets[i]);
			break;

		case ')':
			if (top() == '(') pop();
			else return FALSE;
			break;
		case ']':
			if (top() == '[') pop();
			else return FALSE;
			break;
		case '}':
			if (top() == '{') pop();
			else return FALSE;
			break;
		}
	}
	if (isEmpty()) return TRUE;
	return FALSE;
}
bool BracketAdapter::isEmpty() {
	return (stack.top == 0);
}
bool BracketAdapter::isFull() {
	return (stack.top == maxlen - 1);
}

void BracketAdapter::makeNull() {
	stack.top = 0;
}

BracketAdapter::eletype BracketAdapter::top() {
	if (!isEmpty()) return stack.elements[stack.top];
}
BracketAdapter::eletype BracketAdapter::pop() {
	if (!isEmpty()) {
		stack.top--;
		return stack.elements[stack.top + 1];
	}
}
void BracketAdapter::push(eletype x) {
	if (!isFull()) stack.elements[++stack.top] = x;
}
