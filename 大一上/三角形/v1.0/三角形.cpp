#include <iostream>
using namespace std ;

int main ()
{
	double a , b , c ;
	cout << "��������������ߵĳ�" ;
	cin >> a >> b >> c ;
	if ( a + b <= c || a + c <= b || b + c <= a )
	{
		cout << "����������ݲ��ܹ���������Ŷ" ;
	}
	else 
	{
		if ( a * a + b * b - c * c < 0 )
		{
			cout << "���������Ƕ۽�������" ;
			if ( a == b || b == c || c == a )
			{
				cout << "�еĵ���������" ;
			} 
		} 
		else
		{
			if ( a * a + b * b - c * c == 0 )
			{
				cout << "����������ֱ��������" ;
				if ( a == b || b == c || c == a )
				{
					cout << "�еĵ���ֱ��������" ;
				}
			}
			if ( a * a + b * b - c * c > 0 )
			{
				if ( b * b + c * c - a * a == 0 || a * a + c * c - b * b == 0 ) 
				{
					cout << "����������ֱ��������" ;
					if ( b == c || c == a )
				    {
					    cout << "�еĵ���ֱ��������" ;
				    }
				} 
				else 
				{
					cout << "�������������������" ;
					if ( a == b || b == c || c == a )
					{
						cout << "�еĵ���������" ; 
						if ( a == b && b == c && a == c )
						{
							cout << "�еĵȱ�������" ;
						}
					}
				}
			}
		} 
	}
} 
