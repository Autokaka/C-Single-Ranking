#include <iostream>
using namespace std ;

int main ()
{
	int command ;
	int n ;
	int n1 , n2 ,n3 , n4 ;
	cout << "�����һ����λ����" ;
	cin >> n ;
	cout << "call'1'���ܣ�call'0'����..." ;
	cin >> command ;
	//��λ���鲢�һ�ȡÿһλ 
	if ( n/100 <= 10 ) //��λ���� 
	{
		if ( n/10 <= 10 )//��λ���� 
		{
			if ( n <= 10 )//һλ����
			{
				n4 = n%10 ;
				n3 = 0 ;
				n2 = 0 ;
				n1 = 0 ;  
			} 
			else //��λִ�� 
			{
				n4 = n%10 ;
				n3 = (n/10)%10 ;
				n2 = 0 ;
				n1 = 0 ; 
			}
		}
		else//��λִ�� 
		{
			n4 = n%10 ;
			n3 = (n/10)%10 ;
			n2 = (n/100)%10 ;
			n1 = 0 ; 
		}
	} 
	else//��λִ�� 
	{
		n4 = n%10 ;
	    n3 = (n/10)%10 ;
	    n2 = (n/100)%10 ;
	    n1 = (n/1000)%10 ;
	}
	if ( command != 0 )
	{
		//����
		n1 = (n1+7)%10 ;
		n2 = (n2+7)%10 ; 
		n3 = (n3+7)%10 ;
		n4 = (n4+7)%10 ;
		cout << n3 << n4 << n1 << n2 ;
    }
    else
	{
		//���� 
        n1 =  (3+n1)%10 ; 
		n2 =  (3+n2)%10 ;
		n3 =  (3+n3)%10 ;
		n4 =  (3+n4)%10 ;
		cout << n3 << n4 << n1 << n2 ;
	} 
} 
