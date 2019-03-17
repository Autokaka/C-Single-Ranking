#include "stdafx.h"
#include "Account.h"
#include <iomanip>
#include <iostream>
using namespace std;

Account::Account(double initbalance)
{
	if (initbalance < 0)
	{
		balance = 0;
		cout << "Initial balance is invalid! Your balance is saved as 0..." << endl;
	}
	else
		balance = initbalance;
}

double Account::getBalance()
{
	return balance;
}

void Account::credit(double cunkuan)
{
	if (cunkuan < 0)
	{
		cunkuan = 0;
		cout << "\nCredit is invalid! Your credt is saved as 0..." << endl;
	}
	else
		balance += cunkuan;
}
void Account::debit(double qukuan)
{
	if (qukuan < 0)
		cout << "\nDebit is invalid! Your debit is saved as 0..." << endl;
	else
	{
		if (balance - qukuan < 0)
			cout << "\nDebit amount exceeded account balance..." << endl;
		else
			balance -= qukuan;
	}
}

void Account::print() const
{
	cout << "\n__________账户信息__________" << endl;
	cout << "\n当前账户余额：" << balance << endl;
}