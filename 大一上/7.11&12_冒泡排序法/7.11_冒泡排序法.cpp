#include <iostream>
using namespace std ;

void bubble( int * , int ArraySize ) ;

int main() 
{
	const int ArraySize=10 ;
	int storage[ArraySize+1]={0} ;
	
	cout << "输入数组的各值：\n" ;
	int i=1 , input ; 
	for ( i ; i<=ArraySize ; i++ )
	{
		cout << "第 " << i << " 个数" ;
		cin >> input ;
		storage[i] = input ;
	}
    
    bubble( storage , ArraySize ) ;
    
    for( int display=1 ; display<=ArraySize ; display++ )
        cout << storage[display] << " " ;
    
	return 0;
}

void bubble( int *storage , int ArraySize )
{
	int record=1 , temp ;
	while( record )
	{
		record=0 ;
		int k = 1 ;
		for ( k ; k+1<=ArraySize ; k++ )
		{
			if ( storage[k]>storage[k+1] )
			{
				temp=storage[k+1] ;
			    storage[k+1]=storage[k] ;
			    storage[k]=temp ;
			    record++ ;
			}
		}
	}
}
