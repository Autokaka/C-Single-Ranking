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
	//�����������ļ�����
	double result;

	//����'+', '-', '*', '/'���ŵ����ȼ�, '+'Ϊ1, '-'Ϊ2, '*'Ϊ3, '/'Ϊ4
	int priority(char level);

	//����ƥ�䷽��, �����⵽��'('��')', ����'['��']', ����'{'��'}'
	bool bracketMatch(char leftBracket, char rightBracket);

	//����ַ��ǲ���'(', '[', ����'{'������������
	bool isLeftBracket(char sth);

	//����ַ��ǲ���')', ']', ����'}'������������
	bool isRightBracket(char sth);

	//����ַ��ǲ���'+', '-', '*', '/'�������
	bool isOperator(char sth);

	//����ַ��ǲ��Ǳ�ʾ'0'~'9'���ַ�
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