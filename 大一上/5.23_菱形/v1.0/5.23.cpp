//v1.0仅适用于9行的菱形构造 
#include <iostream> 
using namespace std ;

int main ()
{
	//上半部分 
	for ( int y1 = 1 ; y1 <= 5 ; y1++ )
	{
		for ( int x1 = 1 ; x1 <= 5-y1 ; x1++ )
		{
			cout << " " ;
		}
		for ( int x2 = 1 ; x2 <= 2*y1-1 ; x2++ )
		{
			cout << "*" ;
		}
		cout << endl ;
	}
	//下半部分
	for ( int y1 = 1 ; y1 <= 4 ; y1++ ) 
	{
		for ( int x1 = 1 ; x1 <= y1  ; x1++ )
		{
			cout << " " ;
		}
		for ( int x2 = 1 ; x2 <= -2*y1+9 ; x2++ )
		{
			cout << "*" ;
		}
		cout << endl ;
	}
}
