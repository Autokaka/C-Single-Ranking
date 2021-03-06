#include "stdafx.h"
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
using namespace std;

int main()
{
	double initbalance;
	double cunkuan;
	double qukuan;
	double lilv;
	double meibijiaoyifeiyong;

	for (int i = 1; i <= 3; i++)
		cout << ".\n";
	cout << "\n__________测试Account__________" << endl;
	cout << "\n请输入初始账户金额：  ";
	cin >> initbalance;
	Account a(initbalance);
	cout << "\n请输入存款：  ";
	cin >> cunkuan;
	a.credit(cunkuan);
	cout << "\n请输入取款：  ";
	cin >> qukuan;
	a.debit(qukuan);
	a.print();

	cout << "\n__________测试SavingsAccount__________" << endl;
	cout << "\n初始账户金额：  " << a.getBalance() << endl;
	cout << "\n请输入利率：  ";
	cin >> lilv;
	SavingsAccount b(a.getBalance(), lilv);
	cout << "\n请输入存款：  ";
	cin >> cunkuan;
	b.credit(cunkuan);
	cout << "\n请输入取款：  ";
	cin >> qukuan;
	b.debit(qukuan);
	cout << "\n（存取操作之后，未加入利息的账户信息）" << endl;
	b.print();
	cout << "\n（存取操作之后，加入了利息的账户信息）" << endl;
	b.credit(b.calculateInterestrate());
	b.print();

	cout << "\n__________测试CheckingAccount__________" << endl;
	cout << "\n初始账户金额：  " << b.getBalance() << endl;
	cout << "\n请输入每笔交易费用：  ";
	cin >> meibijiaoyifeiyong;
	CheckingAccount c(b.getBalance(), meibijiaoyifeiyong);
	cout << "\n请输入存款：  ";
	cin >> cunkuan;
	c.credit(cunkuan);
	cout << "\n请输入取款：  ";
	cin >> qukuan;
	c.debit(qukuan);
	c.print();

	system("pause");
    return 0;
}

