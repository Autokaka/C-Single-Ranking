#include <iostream>
using namespace std ;

/*�˳������Ͼ���ҵ��ѧ����1701³����2017.10.12����,���ڽ��м򵥵ļ���*/

int main()
{
	float a , b , c , i ;
	int d ;
	cout << "��ӭʹ�ü򵥼�����\n" << "1.���ӷ�\n" << "2.������\n" << "3.���˷�\n" << "4.������\n" << "��ѡ�����Ĳ�����" ;
	cin >> i ;
	cout << "��������Ҫ�������������" ;
	cin >> a >> b ; 
	if ( i == 1 )
	cout << a << "+" << b << "=" << a + b ;
	if ( i == 2 )
	cout << a << "-" << b << "=" << a - b ;
	if ( i == 3 )
	cout << a << "*" << b << "=" << a * b ;
	if ( i == 4 )
	{
		cout << "����Ƿ�ȡ����������������ѡ��(1.ȡ����;2.ֱ��������)" ; 
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
