#include <iostream>
using namespace std ;

int main () 
{
	int a , n1 , n2 , n3 , n4 , n5 ;
	cout << "�����һ�������λ���ɣ�" ;
	cin  >> a ;
	n1 = a / 10000 ;
	n2 = ( a - n1 * 10000 ) / 1000 ;
	n3 = ( a - n1 * 1000 - n2 *1000 ) / 100 ;
	n4 = ( a - n1 * 1000 - n2 *1000 - n3 * 100 ) / 10 ;
	n5 = a - n1 * 1000 - n2 *1000 - n3 * 100 - n4 * 10 ;
	if ( n1 == n5 )
	{
		if ( n2 == n4 )
		{
			cout << a << "�ǻ�����" ; 
		}
		else
		{
			cout << a << "���ǻ�����" ; 
		} 
	}
	else 
	{
		cout << a << "���ǻ�����" ;
	}
} 
