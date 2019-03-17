#include <iostream>
using namespace std ;

int main() 
{
	const int ArraySize=5 ;
	int storage[ArraySize+1]={0} ;
	int cnt=0 ;
	
	cout << "现在开始输入数组的数字：\n" ;
	int a=1 ;
	for ( a ; a<=ArraySize ; a++ )
	{
		cout << "第 " << a << " 个：" ;
		cin >>  storage[a] ;
	}
	
	int b=1 ;
	for ( b ; b<=ArraySize ; b++ )
	{
		cout << storage[b] << " " ;
	}
	
	cout << "\n你想要删除的数字：" ;
	int del ;
	cin >> del ;
	
	int c=1 ;
	for ( c ; c<=ArraySize ; c++ )
	{
		if ( del == storage[c] )
		{
			cnt++ ;
			//是最后一位 
			if ( c == ArraySize )
			{
                break ;
			}
			else//不是最后一位 
			{
				int d=c ;
				for ( d ; d<=ArraySize-cnt ; d++ )
				{
					storage[d]=storage[d+1] ;
				}
			}
		}
	}
	
	cout << "现在的数组为：" ; 
	int e=1 ;
	for ( e ; e<=ArraySize-cnt ; e++ )
	{
		cout << storage[e] << " " ;
	}
	
	return 0;
}
