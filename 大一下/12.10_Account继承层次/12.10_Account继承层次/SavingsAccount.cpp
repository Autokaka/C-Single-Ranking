#include "stdafx.h"
#include "SavingsAccount.h"
#include <iomanip>
#include <iostream>
using namespace std;


SavingsAccount::SavingsAccount(double initbalance, double lilv)
	:Account(initbalance)
{
	if (lilv < 0)
	{
		interestrate = lilv = 0;
		cout << "Invalid interestrate! Your interestrate is saved as 0..." << endl;
	}
	else
		interestrate = lilv;
}

double SavingsAccount::calculateInterestrate()
{
	return (getBalance() * interestrate * 0.01);
}

void SavingsAccount::print()
{
	cout << "\n__________账户信息__________" << endl;
	cout << "\n利率：" << interestrate << " %" << setw(30) << "当前账户可获利息：" << calculateInterestrate() << endl;
	cout << "\n当前账户余额为：" << getBalance() << endl;
}