#include <iostream>
using namespace std ;

/*此程序由南京工业大学计软1701鲁澳于2017.10.12制作,用于进行简单的计算*/

int main()
{
	float a , b , c , i ;
	int d ;
	cout << "欢迎使用简单计算器\n" << "1.做加法\n" << "2.做减法\n" << "3.做乘法\n" << "4.做除法\n" << "请选择您的操作：" ;
	cin >> i ;
	cout << "请输入想要计算的两个数字" ;
	cin >> a >> b ; 
	if ( i == 1 )
	cout << a << "+" << b << "=" << a + b ;
	if ( i == 2 )
	cout << a << "-" << b << "=" << a - b ;
	if ( i == 3 )
	cout << a << "*" << b << "=" << a * b ;
	if ( i == 4 )
	{
		cout << "结果是否取整数？请输入您的选择：(1.取整数;2.直接输出结果)" ; 
		cin >> i ;
		if ( i == 1 )
		{
			c = a / b ;
			d = a / b ;
			if ( c - d >= 0.5)
			{
				cout << d + 1 ;
			}
			else 
			{
				cout << d ;
			}
		 } 
		 else 
		 {
		    c = a / b ;
		    cout << c ;
		 }
	}
	return 0;
}
