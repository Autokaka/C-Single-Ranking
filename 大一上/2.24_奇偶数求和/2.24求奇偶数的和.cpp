#include <iostream>
using namespace std ; 

/*�˳������Ͼ���ҵ��ѧ����1701³����2017.10.2���������ڷֱ��������������������ż���ĺ�*/

int main() 
{
    int n1 , n2 , n3 , n4 , n5 , sum1 , sum2 ;
    sum1 = 0 ;
	sum2 = 0 ; 
    cout << "������������������" ;
    cin >> n1 >> n2 >> n3 >> n4 >> n5 ;
    if ( n1 % 2 == 0 )
	{
		sum2 = n1 ;
	}
	else 
	{
		sum1 = n1 ;
	}
	
	if ( n2 % 2 == 0 )
	{
		sum2 = sum2 + n2 ;
	}
	else 
	{
		sum1 = sum1 + n2 ;
	}

	if ( n3 % 2 == 0 )
	{
		sum2 = sum2 + n3 ;
	}
	else 
	{
		sum1 = sum1 + n3 ;
	}

	if ( n4 % 2 == 0 )
	{
		sum2 = sum2 + n4 ;
	}
	else 
	{
		sum1 = sum1 + n4 ;
	}

	if ( n5 % 2 == 0 )
	{
		sum2 = sum2 + n5 ;
	}
	else 
	{
		sum1 = sum1 + n5 ;
	}
    cout << "������Ϊ" << sum1 << endl << "ż����Ϊ" << sum2 ; 
	return 0;
}
