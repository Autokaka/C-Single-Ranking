#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std ;

int main()
{
	//generate an array 
	const int ArraySize=10 ;
	int storage[ArraySize+1]={0} ;
	
	cout << "������������ĸ�����ֵ��\n" ;
	int i=1 ;
	for ( i ; i<=ArraySize ; i++ )
	{
		int input ;
		cout << "�� " << i << " ����ֵ��" ;
		cin >> input ;
		storage[i]=input ;
	}
	
	cout << "�������������ǣ�" ;
	int j=1 ;
	for ( j ; j<=ArraySize ; j++ )
	{
		cout << storage[j] << " " ;
	}
	
	//del process
	cout << "\n��������Ҫɾ������ֵ��" ;
	int del ;
	cin >> del ;
	
	int k=1 , cnt = 0 ;
	for ( k ; k<=ArraySize ; k++ )
	{
		if ( del == storage[k] )
		{
			if ( k == ArraySize )
			{
				cout << "�������ǣ�" ;
				int l=1 ;
				for ( l ; l<=ArraySize-1 ; l++ )
				cout << storage[l] ;
				break ;
			}
			else
			{
				int m=k ;
			    for ( m ; m+1<=ArraySize-cnt ; m++ )
			    {
			    	storage[m]=storage[m+1] ;
			    }
			    k-- ;
			    cnt++ ;
			}
		}
    }
	return 0;
}
