#include "stdafx.h"


#include <iostream>
using namespace std;

#include "Polynomial.h"


int main()
{
	for (int i = 1; i <= 3; i++)
		cout << "." << endl;
	cout << "\n__________简单多项式计算系统__________\n";
	cout << "\n * 请输入第一组多项式的项数：  ";
	int n1;
	cin >> n1;
	Polynomial a1(n1);
	a1.insertPolynomial();
	cout << "a1 = " << a1;
	cout << "\n * 请输入第二组多项式的项数：  ";
	int n2;
	cin >> n2;
	Polynomial a2(n2);
	a2.insertPolynomial();
	cout << "a2 = " << a2;

	cout << "\n__________测试a3=a1+a2__________\n";
	Polynomial a3 = a1 + a2;
	cout << "\na3 = " << a3 << endl;

	cout << "\n__________测试a4=a1-a2__________\n";
	Polynomial a4 = a1 - a2;
	cout << "\na4 = " << a4 << endl;

	cout << "\n__________测试a1+=a2__________\n";
	a1 += a2;
	cout << "\na1 = " << a1 << endl;

	cout << "\n__________测试a1-=a2__________\n";
	a1 -= a2;
	cout << "\na1 = " << a1 << endl;

	cout << "\n__________测试a5 = a1 * a2__________\n";
	Polynomial a5 = a1 * a2;
	cout << "\na5 = " << a5 << endl;

	cout << "\n__________测试a1 *= a2__________\n";
	a1 *= a2;
	cout << "\na1 = " << a1 << endl;

	system("pause");
    return 0;
}

