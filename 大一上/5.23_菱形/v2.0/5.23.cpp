// v2.0版本适用于任意行数的菱形构造 
#include <iostream>
#include <iomanip>
using namespace std ;

int main ()
{
	int n = 0 ;//总行数 
	int flag = 0 ; 
	cout << "请输入总行数：" ; 
	cin >> n ; 
	flag = n%2-1 ;
	for ( int y = 1 ; y <= n ; y++ )
	{
		cout << setw ( ((n+1)/2+1)-y ) ;
		if ( y <= (n+1)/2 )//上半部分 
		{
			for ( int x = 1 ; x <= 2*y-1 ; x++ )
		    {
			    cout << "*" ;
		    }
		}
		else//下半部分 
		{
			cout << setw ( y-((n-1)/2)+flag ) ;
			for ( int x = 1 ; x <= 2*(n+1-y)-1 ; x++ )
			{
				cout << "*" ;
			}
		}
		cout << endl ;
	}
} 
