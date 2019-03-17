#include <iostream>
using namespace std ;

void reorder( int [] , int ) ;

int main() 
{
	const int ArraySize=10 ;
	int storage[ArraySize+1]={0} ;
	
	cout << "请为数组填入数字：\n" ; 
	int order=1 ;
	for ( order ; order<=ArraySize ; order++ )
	{
		cout << "第 " << order << " 个：" ;
		cin >> storage[order] ;
	} 
	
    void reorder( storage , ArraySize ) ;
	
	int result=1 ;
	for ( result ; result<=ArraySize ; result++ )
	{
		cout << storage[result] << " " ;
	}
	return 0;
}

void reorder( int a[] , int b )
{
	int current=1 ;
    for ( current ; current<=b ; current++ )
    {
    	int num=current , search=current+1 ;
		for ( search ; search<=b ; search++ )
		{
			if ( a[num]>a[search] )
			num=search ;
		}
		
		if ( num!=current )
		{
			int temp ;
			temp=a[num] ;
			a[num]=a[current] ;
			a[current]=temp ;
		}
	}
}
