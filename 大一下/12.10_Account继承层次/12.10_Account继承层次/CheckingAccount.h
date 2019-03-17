#ifndef CHECKINGACCOUNT_H
#define CHEKINGACCOUNT_H
#include "Account.h"

class CheckingAccount :public Account
{
public:
	CheckingAccount(double, double);

	void credit(double);
	void debit(double);

	void print();

private:
	double feechargedpertransaction;
	int debitcnt;
};

#endif