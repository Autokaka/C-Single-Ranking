#include <iostream>
using namespace std ;

void bottomGo ( int bottom , string init , string desti ) ;
void upperGo ( int disknum , string init , string temp , string desti ) ;

int cnt = 0 ;

int main()
{   
    cout << "Enter����������Ctrl+Z�˳�..." ;
	while ( cin.get() != EOF )
    { 
		int disknum ;
		string init , temp , desti ;
	
		cout << "����Բ��������" ;
		cin >> disknum ;
		cout << "\n������ĳ�ʼ����" ;
		cin >> init ; 
		cout << "\n������Ļ�������" ;
		cin >> temp ;
		cout << "\n�������Ŀ������" ;
		cin >> desti ;
     
		upperGo ( disknum , init , temp , desti ) ;
	
		cout << "һ����Ҫ " << cnt << " ��\n" ;
		
		cout << "Enter����������Ctrl+Z�˳�..." ;
		if ( cin.get() == EOF )
		    break ;
		else
		    continue ; 
	}
	return 0;
}

void bottomGo ( int bottom , string init , string desti )
{
	cout << "�ѵ� " << bottom << " �����Ӵ� " << init << "�� �Ƶ� " << desti << "��" << endl ; 
}

void upperGo ( int disknum , string init , string temp , string desti )
{
	if ( disknum == 1 ) 
	{    
	    bottomGo ( 1 , init , desti ) ;
	    cnt++ ;
    }
	else
	{
		upperGo ( disknum-1 , init , desti , temp ) ;
	    bottomGo ( disknum , init , desti ) ;
	    upperGo ( disknum-1 , temp , init , desti ) ;
	    cnt++ ;
	}
}
