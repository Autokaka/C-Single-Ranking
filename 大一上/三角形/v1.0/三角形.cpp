#include <iostream>
using namespace std ;

int main ()
{
	double a , b , c ;
	cout << "请给我三角形三边的长" ;
	cin >> a >> b >> c ;
	if ( a + b <= c || a + c <= b || b + c <= a )
	{
		cout << "你输入的数据不能构成三角形哦" ;
	}
	else 
	{
		if ( a * a + b * b - c * c < 0 )
		{
			cout << "该三角形是钝角三角形" ;
			if ( a == b || b == c || c == a )
			{
				cout << "中的等腰三角形" ;
			} 
		} 
		else
		{
			if ( a * a + b * b - c * c == 0 )
			{
				cout << "该三角形是直角三角形" ;
				if ( a == b || b == c || c == a )
				{
					cout << "中的等腰直角三角形" ;
				}
			}
			if ( a * a + b * b - c * c > 0 )
			{
				if ( b * b + c * c - a * a == 0 || a * a + c * c - b * b == 0 ) 
				{
					cout << "该三角形是直角三角形" ;
					if ( b == c || c == a )
				    {
					    cout << "中的等腰直角三角形" ;
				    }
				} 
				else 
				{
					cout << "该三角形是锐角三角形" ;
					if ( a == b || b == c || c == a )
					{
						cout << "中的等腰三角形" ; 
						if ( a == b && b == c && a == c )
						{
							cout << "中的等边三角形" ;
						}
					}
				}
			}
		} 
	}
} 
