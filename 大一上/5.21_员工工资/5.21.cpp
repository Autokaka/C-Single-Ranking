#include <iostream>
using namespace std ;

int main ()
{
	int type ;//Ա������
	double salary ; 
	double t ;//����ʱ��
	double w ;//����ë��  
	int n ;//��Ʒ����
	double m ;//ÿ����Ʒ�Ĺ̶���� 
	int command ;
	cout << "�������ⰴ���Կ�ʼ..." ;  
	while ( ( type = cin.get() ) != EOF )
    {
		cout << "������Ա������(1.���� 2.Сʱ�� 3.Ӷ�� 4.�Ƽ���)" ; 
		cin >> type ; 
		switch ( type )
		{
			case 1 :
			    cout << "������̶����ʣ�" ;
				cin >> salary ; 
				break ;
			case 2 :
				cout << "�����빤��ʱ����" ;
				cin >> t ;
				cout << "������̶�Сʱ���ʣ�" ;
				cin >> salary ;
				if ( t <= 40 ) 
				{
					salary = salary*t ;
				}
				else 
				{
				salary = 40*t+(salary-40)*1.5*salary ;
				}
				break ;
			case 3 :
				cout << "����������ë����" ;
				cin >> w ;
				salary = 250+.057*w ; 
				break ;
		    case 4 : 
		        cout << "�������Ա�������Ĳ�Ʒ������ÿ����Ʒ�Ĺ̶���" ;
		        cin >> n >> m ;
		        salary = n*m ;
	            break ;
	    }
		cout << "��Ա�����ܵĹ����ܶ�Ϊ" << salary << endl 
		     << "�Ƿ������һԱ����(��������������߰�ctrl+Z�˳�...)" ;
		cin >> command ;
		if ( ( command = cin.get() ) != EOF ) 
		continue ;
		else
		break ;
    }
    return 0 ;
} 
