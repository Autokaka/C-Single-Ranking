#include <iostream>
using namespace std ;

int main() 
{
	const int ArraySize=5 ;
	int storage[ArraySize+1]={0} ;
	int cnt=0 ;
	
	cout << "���ڿ�ʼ������������֣�\n" ;
	int a=1 ;
	for ( a ; a<=ArraySize ; a++ )
	{
		cout << "�� " << a << " ����" ;
		cin >>  storage[a] ;
	}
	
	int b=1 ;
	for ( b ; b<=ArraySize ; b++ )
	{
		cout << storage[b] << " " ;
	}
	
	cout << "\n����Ҫɾ�������֣�" ;
	int del ;
	cin >> del ;
	
	int c=1 ;
	for ( c ; c<=ArraySize ; c++ )
	{
		if ( del == storage[c] )
		{
			cnt++ ;
			//�����һλ 
			if ( c == ArraySize )
			{
                break ;
			}
			else//�������һλ 
			{
				int d=c ;
				for ( d ; d<=ArraySize-cnt ; d++ )
				{
					storage[d]=storage[d+1] ;
				}
			}
		}
	}
	
	cout << "���ڵ�����Ϊ��" ; 
	int e=1 ;
	for ( e ; e<=ArraySize-cnt ; e++ )
	{
		cout << storage[e] << " " ;
	}
	
	return 0;
}
