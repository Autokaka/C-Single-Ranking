#include <iostream>
using namespace std ;

void bubble( int * , int ) ;
void swap( int *, int * ) ; 

int main()
{
	int arraySize=10 ;
	cout << "你要输入的数字数目：" ;
	cin >> arraySize ;

	int storage[5]={0} ;    
	for( int input=0; input<arraySize; input++ )
	{
		cout << "第 " << input+1 << " 个：" ;
		cin >> *(storage+input) ;
	} 

	bubble( storage , arraySize ) ;

	for( int display=0; display<arraySize; display++ )
		cout << storage[display] << " " ;
	cout << endl ;

	return 0 ;
}

void swap( int *a, int *b )
{
	int temp=*b ;
	*b=*a ;
	*a=temp ;
}

void bubble( int *storage , int arraySize )
{
	int cnt=1 ;
	do 
	{
		cnt=0 ;
		for( int a=0; a<arraySize; a++ )
		{
			if( a>=arraySize-1)
				break ;
			else if( *(storage+a)>*(storage+a+1) )
			{
				swap( (storage+a), (storage+a+1) );
				cnt++ ;
			}
		}	
	}while(cnt!=0) ;
}