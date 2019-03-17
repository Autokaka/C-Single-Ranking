#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std ;

int main()
{
	//generate an array 
	const int ArraySize=10 ;
	int storage[ArraySize+1]={0} ;
	
	cout << "请输入数组里的各个数值：\n" ;
	int i=1 ;
	for ( i ; i<=ArraySize ; i++ )
	{
		int input ;
		cout << "第 " << i << " 个数值：" ;
		cin >> input ;
		storage[i]=input ;
	}
	
	cout << "您的数组内容是：" ;
	int j=1 ;
	for ( j ; j<=ArraySize ; j++ )
	{
		cout << storage[j] << " " ;
	}
	
	//del process
	cout << "\n请输入您要删除的数值：" ;
	int del ;
	cin >> del ;
	
	int k=1 , cnt = 0 ;
	for ( k ; k<=ArraySize ; k++ )
	{
		if ( del == storage[k] )
		{
			if ( k == ArraySize )
			{
				cout << "新数组是：" ;
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
