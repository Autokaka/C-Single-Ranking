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
		cout << "�˻����㣬�����������ȡ��\n" ;
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
		cout << "��Ǯ���������������Ǯ���\n" ; 
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
			cout << "ȡǮ���������������ȡ���\n" ;
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
	cout << "\n_____��ǰ�˻����_____" 
	     << endl << getBalance() << " $" << endl << endl ; 
}
