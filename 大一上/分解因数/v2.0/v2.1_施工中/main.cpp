#include <iostream>
#include <cmath>
#include "JudgePrimeNumber.h"
using namespace std ;

int main ()
{
	
	int x ;
	int cnt = 0 ;
	int i , j ;
	cout << "给我一个随机整数：" ;
	cin >> x ;
	for ( i = 2 ; i <= sqrt(x) ; i++ )
	{
		if ( x%i == 0 )
		{
			JudgePrimeNumber JudgePrimeNumber1 ( i , j ) ;
			JudgePrimeNumber1.Judge ( i , j ) ;
	    }
	}
}  
