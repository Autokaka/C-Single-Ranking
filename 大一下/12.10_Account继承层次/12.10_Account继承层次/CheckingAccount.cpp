#include "stdafx.h"
#include "CheckingAccount.h"
#include <iomanip>
#include <iostream>
using namespace std;

CheckingAccount::CheckingAccount(double initbalance, double meibijiaoyifeiyong)
	:Account (initbalance)
{
	if (meibijiaoyifeiyong < 0)
	{
		feechargedpertransaction = meibijiaoyifeiyong = 0;
		cout << "Invalid feechargedpertransaction! Your feechargedpertransaction is saved as 0..." << endl;
	}
	else
		feechargedpertransaction = meibijiaoyifeiyong;
	debitcnt = 0;
}

void CheckingAccount::credit(double cunkuan)
{
	if (cunkuan < 0)
		cout << "\nCredit is invalid! Your credt is saved as 0..." << endl;
	else
		Account::credit(cunkuan);

	if (debitcnt)
		Account::debit(debitcnt * feechargedpertransaction);

	debitcnt = 0;
}
void CheckingAccount::debit(double qukuan)
{
	if (qukuan < 0)
	{
		qukuan = 0;
		cout << "\nDebit is invalid! Your debit is saved as 0..." << endl;
	}
	else
	{
		if (getBalance() - qukuan - (debitcnt + 1) * feechargedpertransaction < 0)
			cout << "\nDebit amount exceeded account balance! " << endl;
		else
		{
			Account::debit(qukuan);
			debitcnt++;
		}	
	}
}

void CheckingAccount::print()
{
	cout << "\n__________账户信息__________" << endl;
	cout << "\n每笔交易的手续费：" << feechargedpertransaction << endl;
	cout << "\n当前账户余额：" << getBalance() << endl;
}