// v2.0�汾�������������������ι��� 
#include <iostream>
#include <iomanip>
using namespace std ;

int main ()
{
	int n = 0 ;//������ 
	int flag = 0 ; 
	cout << "��������������" ; 
	cin >> n ; 
	flag = n%2-1 ;
	for ( int y = 1 ; y <= n ; y++ )
	{
		cout << setw ( ((n+1)/2+1)-y ) ;
		if ( y <= (n+1)/2 )//�ϰ벿�� 
		{
			for ( int x = 1 ; x <= 2*y-1 ; x++ )
		    {
			    cout << "*" ;
		    }
		}
		else//�°벿�� 
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
