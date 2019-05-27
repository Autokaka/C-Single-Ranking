#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
using namespace std;

class Calculator
{
private:
	struct celltype {
		char data;
		celltype* lchild, * rchild;
	};
	typedef celltype* binarytree;
	typedef celltype* treenode;
	binarytree btree;
	double result;

	int priority(char level);
	bool bracketMatch(char leftBracket, char rightBracket);
	bool isLeftBracket(char sth);
	bool isRightBracket(char sth);
	bool isOperator(char sth);
	bool isInteger(char sth);
	double sumResult(double left, char oprt, double right);

	string setPolandfx(treenode root);
	string setAntiPolandfx(treenode root);
	void inOrder(treenode root);

public:
	Calculator(char formula[], int len);

	treenode buildTree(char formula[], int st, int ed);
	double calculate();

	string setPolandfx();
	string setAntiPolandfx();
	void inOrder();
};

#endif