#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "Account.h"

class SavingsAccount :public Account
{
public:
	SavingsAccount(double, double);

	double calculateInterestrate();

	void print();

private:
	double interestrate;

};

#endif

