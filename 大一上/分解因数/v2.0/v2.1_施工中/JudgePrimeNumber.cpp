#include <iostream>
#include "JudgePrimeNumber.h"
using namespace std ;

JudgePrimeNumber :: JudgePrimeNumber ( int i , int j , int cnt )
{
	void Judge ( i , j , cnt ) ;
} 

void JudgePrimeNumber :: Judge ( int i , int j , int cnt )
{
	for ( j = 1 ; j <= i ; j++ )
	{
		if ( i%j == 0 )
		{
			cnt++ ;
		}
	}
	if ( cnt == 2 )
	{
		cout << i << " " ;
	}
	cnt = 0 ; 
}

