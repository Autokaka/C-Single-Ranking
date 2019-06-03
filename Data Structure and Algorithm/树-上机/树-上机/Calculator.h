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
	//储存计算器类的计算结果
	double result;

	//返回'+', '-', '*', '/'符号的优先级, '+'为1, '-'为2, '*'为3, '/'为4
	int priority(char level);

	//括号匹配方法, 如果检测到是'('和')', 或者'['和']', 或者'{'和'}'
	bool bracketMatch(char leftBracket, char rightBracket);

	//检测字符是不是'(', '[', 或者'{'这样的左括号
	bool isLeftBracket(char sth);

	//检测字符是不是')', ']', 或者'}'这样的右括号
	bool isRightBracket(char sth);

	//检测字符是不是'+', '-', '*', '/'等运算符
	bool isOperator(char sth);

	//检测字符是不是表示'0'~'9'的字符
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