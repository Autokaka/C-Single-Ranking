#include <iostream>
using namespace std ; 

/*�˳������Ͼ���ҵ��ѧ����1701³����2017.10.2���������ڱȽ����������������Ĵ�С����������ҴӴ�С����*/

int main()
{
int m1 , m2 , m3 , m4 , m5 , n1 , n2 , n3 , n4 , n5 ;
cout << " Please give me 5 numbers " ;
cin >> n1 >> n2 >> n3 >> n4 >> n5 ;
//ǰ�����Ƚ� 
if ( n1 > n2 )
{
	if ( n2 > n3 )
	{
		m1 = n1 ;
		m2 = n2 ;
		m3 = n3 ;
	}
	else
	{
		if ( n1 > n3 )
		{
			m1 = n1 ;
			m2 = n3 ;
			m3 = n2 ;
		}
		else
		{
			m1 = n3 ;
			m2 = n1 ;
			m3 = n2 ;
		}
	}
}
else
{
	if ( n1 > n3 )
	{
		m1 = n2 ;
		m2 = n1 ;
		m3 = n3 ;
	}
	else
	{
		if ( n2 > n3 )
		{
			m1 = n2 ;
			m2 = n3 ;
			m3 = n1 ;
		}
		else 
		{
			m1 = n3 ;
			m2 = n2 ;
			m3 = n1 ;
		}
	}
}
//ǰ�����Ƚ� 
if ( n4 > m1 )
{
	m4 = m3 ;
	m3 = m2 ;
	m2 = m1 ;
	m1 = n4 ;
}
else
{
    if ( n4 > m2 )
	{
	    m4 = m3 ;
		m3 = m2 ;
		m2 = n4 ;
	}
	else 
	{
		if ( n4 > m3 )
		{
			m4 = m3 ;
			m3 = n4 ;
		}
		else
		{
			m4 = n4 ;
		}
	}
}
//ǰ�����Ƚ� 
if ( n5 > m1 )
{
	m5 = m4 ;
	m4 = m3 ;
	m3 = m2 ;
	m2 = m1 ;
	m1 = n5 ;
} 
else 
{
	if ( n5 > m2 )
	{
		m5 = m4 ;
		m4 = m3 ;
		m3 = m2 ;
		m2 = n5 ;
	}
	else
	{
		if ( n5 > m3 )
		{
			m5 = m4 ;
			m4 = m3 ;
			m3 = n5 ;
		}
		else 
		{
			if ( n5 > m4 )
			{
				m5 = m4 ;
				m4 = n5 ;
			}
			else 
			{
				m5 = n5 ;
			}
		}
	}
} 
cout << m1 << " " << m2 << " " << m3 << " " << m4 << " " << m5 ;
	return 0;
}
