#include <iostream>
using namespace std ;

class Account 
{
	public :
		Account ( int , int , int ) ;

		void setBalance ( int ) ;
		int getBalance () ;

		void setCredit ( int ) ;
		int getCredit () ;
		
		void setDebit ( int ) ;
		int getDebit () ;
		
		void displayMessage () ;
		
	private :
		int currentBalance ;
		int currentCredit ;
		int currentDebit ;
} ;
