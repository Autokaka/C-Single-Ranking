#include "stdafx.h"
#include <iostream>
using namespace std;
#include "Complex.h"


int main()
{
	Complex x;
	Complex y;
	Complex z;

	cout << "输入虚数x：";
	cin >> x;
	cout << "输入虚数y：";
	cin >> y;

	cout << "__________当前__________\n";
	cout << "x：" << x << endl;
	cout << "y：" << y << endl;
	cout << "z：" << z << endl;

	z = x + y;
	cout << "\n__________z = x + y__________\n";
	cout << z << " = " << x << " + " << y << endl;

	z = x - y;
	cout << "\n__________z = x - y__________\n";
	cout << z << " = " << x << " - " << y << endl;

	z = x * y;
	cout << "\n__________z = x * y__________\n";
	cout << z << " = " << x << " * " << y << endl;

	cout << "\n__________x == y吗？__________\n";
	if (x == y)
		cout << "嘚!";
	else
		cout << "不嘚!";
	cout << endl;

	cout << "\n__________x != y吗？__________\n";
	if (x != y)
		cout << "嘚!";
	else
		cout << "不嘚!";
	cout << endl;

	system("pause");
    return 0;
}