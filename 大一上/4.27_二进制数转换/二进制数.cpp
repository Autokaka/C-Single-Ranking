#include <iostream>
using namespace std ;

int main ()
{
	int  m , n , f = 0 , zhishu = 1 ;
	cout << "Please give me the original number£º" ;
	cin >> n ;
	if ( n == 0 || n == 1 )
	{
	    cout << "The transformed number is :" << n << endl ;
	}
	else
	{
	    while ( ( n / 10 ) != 0 )
	    {
            m = n % 10 ;
            n = n / 10 ;
            f += m * zhishu ; // f = f + m * zhishu ;
            zhishu *= 2 ; //zhishu = zhishu * 2 ;
	    }
	    cout << "The transformed number is :" << ( f + zhishu ) ;
	}
}

