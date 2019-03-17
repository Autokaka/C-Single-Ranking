#include <iostream>
using namespace std ; 

/*此程序由南京工业大学计软1701鲁澳于2017.10.2制作，用于分别求任意五个数中奇数和偶数的和*/

int main() 
{
    int n1 , n2 , n3 , n4 , n5 , sum1 , sum2 ;
    sum1 = 0 ;
	sum2 = 0 ; 
    cout << "请输入随机的五个数字" ;
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
    cout << "奇数和为" << sum1 << endl << "偶数和为" << sum2 ; 
	return 0;
}
