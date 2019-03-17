#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std ;

void check ( int ) ;

int main() 
{
	const int sum = 20 ;
    int temp[sum+1] = {0} ;

    int i=1 , cnt = 0 ;
    for ( i ; i < sum+1 ; i++ )
    {
    	int input ;
    	cout << "Give me a figure: " ;
    	cnt++ ;
    	cin >> input ;
    	//check
    	while ( input < 10 || input > 100 )
    	{
    		cout << "Illegal number, please try again! \n" 
    		     << "\n Give me a figure: " ;
	        cin >> input ;
		}
		//judge 
		int j=1 ;
		for ( j ; j < i ; j++ )
		{
			if ( input == temp[j] )
		    {
		    	i-- ;
		    	break ;
			}
		}
		if ( i == j )
		    temp[i] = input ;
		//check sum
		if ( cnt == sum ) 
			break ;
	}
	//store&display
	int storage[i] = {0} ;
	for ( int s = 1 ; s <= i ; s++ )
	{
		storage[s] = temp[s] ;
	    cout << storage[s] << " " ;
	}
	return 0;
}
