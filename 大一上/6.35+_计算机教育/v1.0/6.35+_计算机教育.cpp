#include <iostream>
using namespace std ;
#include <cstdlib>
#include <ctime>

void qasys () ;
void comment ( int ) ;
void suggest ( int& , double& ) ;
void exit () ;

int key ;

int main ()
{
	int answer , cnt = 0 ;
	double right = 0 ;
	
	cout << "��ӭʹ�ü��������ϵͳ\n"
	     << "Enter����,Ctrl+Z�˳�...\n" ;
	
	while ( cin.get() != EOF )
	{  
		qasys () ;
		
		cin >> answer ;
		cnt++ ;

		if ( answer == ::key )//����� 
		{
			if ( cnt%10 == 0 )
			{
			    suggest ( cnt , right ) ;
			    cout << "\nEnter����,Ctrl+Z�˳�...\n" ; 
			    if ( cin.get() == EOF )
			        break ;
		    }
		    else
		    {
		    	comment (1) ;
		    	right++ ;
			}  
		}
		else//����� 
		{
			while ( cnt%10 != 0 && answer!=::key )
			{
				comment (0) ;
				cout << "�����𰸣�" ; 
				cin >> answer ;
				cnt++ ;
			}
            if ( cnt%10 == 0)
			{
				suggest ( cnt , right ) ;
				cout << "\nEnter����,Ctrl+Z�˳�...\n" ;
			    if ( cin.get() == EOF )
				    break ;
			}
	    }
	}
	return 0 ;
} 

void qasys ()
{
	srand ( time(0) ) ;
	int n1 = 1+rand()%10 , n2 = 1+rand()%10 ;
	::key = n1*n2 ;
	cout << n1 << " * " << n2 << " = " ;
}

void comment ( int signal )
{
	srand ( time(0) ) ;
	int comment = 1+rand()%4 ;  
	switch ( signal )
	{
	    case 0 :
	    	switch ( comment )
	    	{
	    	    case 1 :
	    	    	cout << "���ԣ����ٳ���һ���.\n" ;
	    	    	break ;
	    	    case 2 :
	    	    	cout << "����Ҳ���ٳ���һ�°�.\n" ;
	    	    	break ;
	    	    case 3 :
	    	    	cout << "�����ѽ�������԰�.\n" ;
	    	    	break ;
	    	    case 4 :
	    	    	cout << "����Ŷ�������԰�.\n" ;
	    	    	break ;
	        }
	        break ;
	    case 1 :
            switch ( comment )
            {
	    	    case 1 :
	    	    	cout << "�������\n" ;
	    	    	break ;
	    	    case 2 :
	    	    	cout << "�����˺��ӣ�\n" ;
	    	    	break ;
	    	    case 3 :
	    	    	cout << "�ɵ�Ư����\n" ;
	    	    	break ;
	    	    case 4 :
	    	    	cout << "�������֣�\n" ;
	    	    	break ;
	    	}
	    	break ;
	}
}

void suggest ( int &cnt , double &right )
{
	if ( cnt != 0 )
	{
	    if ( right/cnt < .75 )
	    {
	        cout << "Ummm...Ҳ��������������ʦ����Ϥ��Ϥ֪ʶ��.\n" ;
	        cnt = 0 ;
	        right = 0 ;
	    }
	    else 
	    {
	        cout << "��ȷ�ʺܸߣ��������������\n" ; 
			cnt = 0 ;
			right = 0 ; 
	    }
	}
}
