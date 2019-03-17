#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std ;

int main ()
{
	const int possi = 12 ;
	const int sum = 36000 ;
	double count[possi+1] = {0} ;
	srand ( time(0) ) ;
	
	for ( count[0] ; count[0] <= sum ; count[0]++ )
	{
		int die1 , die2 ;
		die1 = 1+rand()%6 ;
		die2 = 1+rand()%6 ;
		count[die1+die2]++ ;
	}
	cout << "sum" << setw(16) << "count" << setw(24) << "consequence" << endl ;
    //report
	int i ;
	for ( i = 2 ; i <= 12 ; i++ )
    {
    	cout << i << setw(18) << count[i] << setw(24) << count[i]/sum << endl ;
	}
} 
