#include <iostream>
using namespace std ;

void bucketSort( int * , int ) ;

int main()
{
	const int arraySize=5 ;
	int storage[arraySize]={ 23, 152, 12, 1, 48 } ;
	bucketSort( storage, arraySize ) ;
	
	for( int display=0; display<arraySize; display++ )
	    cout << *(storage+display) << " " ;
	/*cout << endl ; */

	return 0 ;
}

void bucketSort( int *storage , int arraySize )
{
	int bucket[10][arraySize]={0} ;
	int cnt[10]={0} ;
	for( int level=10; *cnt<=arraySize ; level*=10 )
	{
		for( int del=0; del<10; del++ )
		    *(cnt+del)=0 ;
		
		for( int a=0; a<arraySize; a++ )
		{
			int b=(*(storage+a)/(level/10))%10 ;
			bucket[b][cnt[b]++]=*(storage+a) ;
		}
		for( int y=0; y<10 ; y++ )
		{
			for( int x=0; x<cnt[y]; x++ )
			{
				*(storage+x)=bucket[y][x] ;
				bucket[y][x]=0 ;
			}	
		}
	}
}

