#include <iostream>
using namespace std ;
#include "Account.h"

int main ()
{
	Account account1( 0, 0, 0 ) ;
	char exit='N' ;
	do
	{
		account1.displayMessage() ;
		
		cout << "���������" ;
		int credit ;
		cin >> credit ;
		account1.setCredit( credit ) ;
		
		cout << "������ȡ���" ;
		int debit ;
		cin >> debit ;
		account1.setDebit( debit ) ;
		
		account1.setBalance( account1.getBalance() ) ; 
		account1.displayMessage() ;
		
		cout << "�˳��𣿣�Y or N��" ;
		cin >> exit ; 
		
	}while( exit!='Y') ;
	
	return 0 ;
}
