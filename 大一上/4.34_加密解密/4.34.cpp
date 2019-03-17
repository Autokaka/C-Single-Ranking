#include <iostream>
using namespace std ;

int main ()
{
	int command ;
	int n ;
	int n1 , n2 ,n3 , n4 ;
	cout << "请给我一个四位整数" ;
	cin >> n ;
	cout << "call'1'加密，call'0'解密..." ;
	cin >> command ;
	//首位检验并且获取每一位 
	if ( n/100 <= 10 ) //三位检验 
	{
		if ( n/10 <= 10 )//两位检验 
		{
			if ( n <= 10 )//一位检验
			{
				n4 = n%10 ;
				n3 = 0 ;
				n2 = 0 ;
				n1 = 0 ;  
			} 
			else //两位执行 
			{
				n4 = n%10 ;
				n3 = (n/10)%10 ;
				n2 = 0 ;
				n1 = 0 ; 
			}
		}
		else//三位执行 
		{
			n4 = n%10 ;
			n3 = (n/10)%10 ;
			n2 = (n/100)%10 ;
			n1 = 0 ; 
		}
	} 
	else//四位执行 
	{
		n4 = n%10 ;
	    n3 = (n/10)%10 ;
	    n2 = (n/100)%10 ;
	    n1 = (n/1000)%10 ;
	}
	if ( command != 0 )
	{
		//加密
		n1 = (n1+7)%10 ;
		n2 = (n2+7)%10 ; 
		n3 = (n3+7)%10 ;
		n4 = (n4+7)%10 ;
		cout << n3 << n4 << n1 << n2 ;
    }
    else
	{
		//解密 
        n1 =  (3+n1)%10 ; 
		n2 =  (3+n2)%10 ;
		n3 =  (3+n3)%10 ;
		n4 =  (3+n4)%10 ;
		cout << n3 << n4 << n1 << n2 ;
	} 
} 
