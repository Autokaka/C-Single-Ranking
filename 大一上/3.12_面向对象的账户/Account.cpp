#include <iostream>
using namespace std ;
#include "Account.h"

Account :: Account ( int balance, int credit, int debit )
{
	setCredit ( credit ) ;
	setDebit ( debit ) ;
	setBalance ( balance ) ;
}

//balance
void Account :: setBalance ( int balance )
{
	if ( balance+currentCredit-currentDebit>=0 )
	{
		currentBalance=balance+currentCredit-currentDebit ;
	}
	else 
	{
		currentCredit=0 ;
		currentDebit=0 ;
		cout << "账户余额不足，请重新输入存取额\n" ;
	}
}
int Account :: getBalance ()
{
	return currentBalance ;
}

//credit
void Account :: setCredit ( int credit )
{
    if ( credit >= 0 )
    {
    	currentCredit = credit ;
	}
	else 
	{
		currentCredit = 0 ;
		cout << "存钱错误，请重新输入存钱金额\n" ; 
	}
}
int Account :: getCredit ()
{
	return currentCredit ;
}

///debit
void Account :: setDebit ( int debit )
{
	if ( debit<0 )
	{
		if( currentBalance+currentCredit-debit<0 )
		{
			currentDebit=0 ;
			cout << "取钱错误，请重新输入存取金额\n" ;
		}
		else
			currentDebit=debit ; 
    }
    else
    {
    	currentDebit=debit ;
	}
}
int Account :: getDebit ()
{
	return currentDebit ;
}

//display
void Account :: displayMessage () 
{
	cout << "\n_____当前账户余额_____" 
	     << endl << getBalance() << " $" << endl << endl ; 
}
