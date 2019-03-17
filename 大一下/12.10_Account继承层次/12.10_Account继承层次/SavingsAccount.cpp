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
	cout << "\n__________�˻���Ϣ__________" << endl;
	cout << "\n���ʣ�" << interestrate << " %" << setw(30) << "��ǰ�˻��ɻ���Ϣ��" << calculateInterestrate() << endl;
	cout << "\n��ǰ�˻����Ϊ��" << getBalance() << endl;
}