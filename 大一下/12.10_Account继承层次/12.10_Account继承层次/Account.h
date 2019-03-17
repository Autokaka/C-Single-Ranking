#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
	Account(double);

	double getBalance();

	void credit(double);
	void debit(double);

	void print() const;

private:
	double balance;

};

#endif