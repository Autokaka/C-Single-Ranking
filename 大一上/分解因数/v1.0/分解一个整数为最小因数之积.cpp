#include <iostream> 
#include <cmath>
using namespace std ;

int main ()
{
	int x ;
	int i ;
	cout << "请给我一个随机整数:" ;
	cin >> x ;
    for ( i = 2 ; x != 1 ; )
    {
    	if ( x%i == 0 )
	    {
	    	if ( x == i )
	    	{
	    		cout << x ;
	    		break ;
			}
		    else
		    {
		    	x /= i ;
		        cout << i << " " ;
			}
	    }
	    else i++ ;
	}
}
