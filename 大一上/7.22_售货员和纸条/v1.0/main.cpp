#include <iostream>
#include <iomanip>
using namespace std ;

int main() 
{
	//���ɶ�ά���� 
	int array[6][5]={0} ;
	//���� 
	int days ;
	for( days=1 ; days<=30 ; days++ ) 
	{
		cout << "\n#�� " << days << " ��#\n" ; 
		int lie ;
		for( lie=1 ; lie<=4 ; lie++ )
	    {
			cout << "�� " << lie << " λ�ۻ�Ա��\n" ; 
			int hang ;
			for( hang=1 ; hang<=5 ; hang++ )
			{
				cout << "��Ʒ" << hang << "��" ; 
				cin >> array[hang][lie] ;
				array[hang][lie]+=array[hang][lie] ;
			}
		}
	}
	//��ÿ�ֲ�Ʒ���ܶ� 
	int process1_hang ; 
	for( process1_hang=1 ; process1_hang<=5 ; process1_hang++ )
	{
		int process1_lie ;
	    for( process1_lie=1 ; process1_lie<=4 ; process1_lie++ ) 
	    {
		    array[process1_hang][0]+=array[process1_hang][process1_lie] ;
	    }
	} 
	//��ÿ������Ա�������ܶ� 
	int process2_lie ; 
	for( process2_lie=1 ; process2_lie<=4 ; process2_lie++ )
	{
		int process2_hang ;
	    for( process2_hang=1 ; process2_hang<=5 ; process2_hang++ ) 
	    {
		    array[0][process2_lie]+=array[process2_hang][process2_lie] ;
	    }
	} 
	//���
	cout << "�ۻ�Ա" << setw(9) << "��" << setw(7) << "��" << setw(7) << "��" << setw(7) << "��" << setw(13) << "��Ʒ�ܶ�" << endl ;
	int display_hang ;
	for( display_hang=1 ; display_hang<=5 ; display_hang++ ) 
	{
		cout << "��Ʒ" << display_hang << setw(9) ; 
		int display_lie ;
		for( display_lie=1 ; display_lie<=4 ; display_lie++ )
		{
			cout << array[display_hang][display_lie] << setw(7) ;
			if( display_lie==4 )
			{
				cout << array[display_hang][0] << endl ; 
			} 
		}
		if( display_hang==5 )
		{
			cout << "��Ʒ������" << setw(4) ;
			int sum_lie ;
			for( sum_lie=1 ; sum_lie<=4 ; sum_lie++ )
			{
				cout << array[0][sum_lie] << setw(7) ; 
			}
		} 
	}
	return 0 ;
}
