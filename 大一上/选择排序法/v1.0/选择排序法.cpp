#include <iostream>
using namespace std ;

int main() 
{
	const int ArraySize=10 ;
	int storage[ArraySize+1]={0} ;
	
	cout << "��Ϊ�����������֣�\n" ; 
	int order=1 ;
	for ( order ; order<=ArraySize ; order++ )
	{
		cout << "�� " << order << " ����" ;
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
