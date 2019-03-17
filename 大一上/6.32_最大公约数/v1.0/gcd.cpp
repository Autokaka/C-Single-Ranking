#include <iostream>
using namespace std ;

int gcd( int , int ) ; 

int main ()
{
	int a , b ;
	cout << "给我两个随机整数:" ;
	cin >> a >> b ; 
    cout << gcd( a , b ) << endl ;
    return 0 ;
}

int gcd( int n1 , int n2 )
{
	int i ;
	int cnt = 0 , std = 0 ; 
	for ( i = n1 ; i >= 1 ; i-- )
	{
		if ( n1%i == 0 && n2%i == 0 )
		{
            return i ;
		} 
	}
}
