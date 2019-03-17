#include <iostream>
using namespace std ;

int main()
{
	const int ArraySize=999 ;
	int Eratosthenes[ArraySize+1] ;
	
	//all to be 1
	int a=1 ;
	for ( a ; a<=ArraySize ; a++ )
	{
		Eratosthenes[a]=1 ;
	}
	
	//processing
    int b=2 ;
	for ( b ; b<=ArraySize ; b++ )
	{
		int yinshu=2 , cnt=0 ;
		for ( yinshu ; yinshu<=b ; yinshu++ )
		{
			if ( b%yinshu==0 )
			cnt++ ;
		}
		if ( cnt>1 )
		{
			int beishu=1 ;
			for ( beishu ; b*beishu<=999 ; beishu++ )
			Eratosthenes[b*beishu]=0 ;
		}
	}
	
	//print
	int check=2 ;
	for ( check ; check<=ArraySize ; check++ )
	{
		if ( Eratosthenes[check]==1 )
		{
			cout << check << " " ;
		}
	}
	
	return 0;
}
