#include <iostream>
#include <cmath>
using namespace std ;

int main ()
{
	int x ;
	int cnt = 0 ;
	int i , j ;
	cout << "给我一个随机整数：" ;
	cin >> x ;
	for ( i = 2 ; i <= x ; i++ )
	{
		if ( x%i == 0 )
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
	}
}  
