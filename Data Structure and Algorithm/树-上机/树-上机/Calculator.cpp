#include "Calculator.h"
#include <stack>
using namespace std;

Calculator::Calculator(char formula[], int len) {
	btree = buildTree(formula, 0, len - 1);
}

Calculator::treenode Calculator::buildTree(char formula[], int st, int ed) {
	/*
	cout << "_____���ܵݹ�����_____\n";
	cout << "����st: " << st << endl;
	cout << "����ed: " << ed << endl << endl << endl;
	*/
	//ֻ��һ���ַ������, ֱ�ӷ���Ҷ�ڵ�
	treenode root = new celltype;
	if (st == ed) {
		root->data = formula[st];
		root->lchild = NULL;
		root->rchild = NULL;
		return root;
	}
	int left_st = -1, left_ed = -1, right_st = -1, right_ed = -1, min_priority = 100;
	stack<char> brackets;
	for (int i = st; i <= ed; i++) {
		if (isLeftBracket(formula[i])) brackets.push(formula[i]);
		if (!brackets.empty() && bracketMatch(brackets.top(), formula[i])) brackets.pop();
		if (brackets.empty() && min_priority > priority(formula[i])) {
			//cout << "������ֵ���\n\n\n";
			min_priority = priority(formula[i]);
			root->data = formula[i];
			left_st = st;
			left_ed = i - 1;
			right_st = i + 1;
			right_ed = ed;
		}
	}
	//�������: ���ű�ס�������ʽ�����ڲ�������, ��ᵼ������index����ֵȫ��Ϊ-1(δ���޸Ĺ�)
	//���������������ʱ, ͨ������st��ed����ʵ���Խ������, ������Ҫ����һ��, �����϶Ը��Ӷ�û��Ӱ��
	if (left_st == -1 && left_ed == -1 && right_st == -1 && right_ed == -1 && bracketMatch(formula[st], formula[ed])) {
		st++;
		ed--;
		return buildTree(formula, st, ed);
	}
	else {
		/*
		cout << "_____��ʼ�ݹ鵽��һ��_____\n";
		cout << "����left_st: " << left_st << endl;
		cout << "����left_ed: " << left_ed << endl;
		cout << "����right_st: " << right_st << endl;
		cout << "����right_ed: " << right_ed << endl << endl << endl;
		*/
		root->lchild = buildTree(formula, left_st, left_ed);
		root->rchild = buildTree(formula, right_st, right_ed);
	}
	return root;
}
double Calculator::calculate() {
	result = 0;
	string polandfx = setPolandfx(btree);
	int polandfx_len = polandfx.length();
	for (int i = 0; i < polandfx_len - 2; i++) {
		if (isOperator(polandfx[i]) && isInteger(polandfx[i + 1]) && isInteger(polandfx[i + 2])) {
			result = sumResult((polandfx[i + 1] - '0'), polandfx[i], (polandfx[i + 2] - '0'));
			//cout << "����result״̬: " << result << endl;
			polandfx[i] = 'x';
			for (int j = 1; j < (polandfx_len-i-2) ; j++) polandfx[i + j] = polandfx[i + j + 2];
			polandfx_len -= 2;
			i = 0;
			/*
			cout << "���Բ������ʽ״̬: ";
			for (int k = 0; k < polandfx_len; k++) cout << polandfx[k] << " ";
			cout << endl;
			cout << "�������ʽ����: " << polandfx_len << endl;
			*/
		}
	}
	//���ֻʣ��λ��ʱ�������ѭ��, ��ʱֻ��Ҫ�����һ�μ��㼴��
	result = sumResult((polandfx[1] - '0'), polandfx[0], (polandfx[2] - '0'));
	return result;
}
double Calculator::sumResult(double left, char oprt, double right) {
	//���������'x'(72)�Ļ�, Ҫ��ֵ����resultֵ
	if (left == 72) left = result;
	if (right == 72) right = result;
	//cout << "�����ʽ: " << left << " " << oprt << " " << right << endl << endl << endl;
	switch (oprt)
	{
	case '+':
		return (left + right);
	case '-':
		return (left - right);
	case '*':
		return (left * right);
	case '/':
		return (left / right);
	default:
		return NULL;
	}
}

int Calculator::priority(char level) {
	switch (level) {
	default:
		return 1024;
	case '+':
		return 1;
	case '-':
		return 2;
	case '*':
		return 3;
	case '/':
		return 4;
	}
	return 0;
}
bool Calculator::bracketMatch(char leftBracket, char rightBracket) {
	if ('(' == leftBracket && ')' == rightBracket) return true;
	if ('[' == leftBracket && ']' == rightBracket) return true;
	if ('{' == leftBracket && '}' == rightBracket) return true;
	return false;
}
bool Calculator::isLeftBracket(char sth) {
	return ('(' == sth || '[' == sth || '{' == sth);
}
bool Calculator::isRightBracket(char sth) {
	return (')' == sth || ']' == sth || ']' == sth);
}
bool Calculator::isOperator(char sth) {
	return ('+' == sth || '-' == sth || '*' == sth || '/' == sth);
}
bool Calculator::isInteger(char sth) {
	int num = sth - '0';
	return (num >= 0 && num <= 9 || sth == 'x');
}

void Calculator::inOrder() {
	return inOrder(btree);
}
void Calculator::inOrder(treenode root) {
	if (root->lchild != NULL) inOrder(root->lchild);
	cout << root->data << " ";
	if (root->rchild != NULL) inOrder(root->rchild);
}
string Calculator::setPolandfx() {
	return setPolandfx(btree);
}
string Calculator::setPolandfx(treenode root) {
	string polandfx = "";
	polandfx += root->data;
	if (root->lchild != NULL) polandfx += setPolandfx(root->lchild);
	if (root->rchild != NULL) polandfx += setPolandfx(root->rchild);
	return polandfx;
}
string Calculator::setAntiPolandfx() {
	return setAntiPolandfx(btree);
}
string Calculator::setAntiPolandfx(treenode root) {
	string antiPolandfx = "";
	if (root->lchild != NULL) antiPolandfx += setAntiPolandfx(root->lchild);
	if (root->rchild != NULL) antiPolandfx += setAntiPolandfx(root->rchild);
	antiPolandfx += root->data;
	return antiPolandfx;
}