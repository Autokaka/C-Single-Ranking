#include <iostream>
using namespace std ;

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
	
	int current=1 ;
    for ( current ; current<=ArraySize ; current++ )
    {
    	int num=current , search=current+1 ;
		for ( search ; search<=ArraySize ; search++ )
		{
			if ( storage[num]>storage[search] )
			num=search ;
		}
		
		if ( num!=current )
		{
			int temp ;
			temp=storage[num] ;
			storage[num]=storage[current] ;
			storage[current]=temp ;
		}
	}
	
	int result=1 ;
	for ( result ; result<=ArraySize ; result++ )
	{
		cout << storage[result] << " " ;
	}
	return 0;
}
