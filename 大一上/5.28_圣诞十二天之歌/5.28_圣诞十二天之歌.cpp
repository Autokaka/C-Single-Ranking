#include <iostream>
using namespace std ;

int main ()
{
	int day = 1 ;
	int left = 1 ;
	for ( int day =1 ; day <= 12 ; day++ )
	{
		cout << "��ʥ���ڵĵ�" << day << "��,�ҵ��氮���ң�" << endl ;
		for ( left = day ; left >=1 ; left--) 
		{
			switch ( left )
		    {
		    	case 1 : 
		    	    cout << " һֻվ�������ϵ������ " ;
		    	    break ;
		    	case 2 :
		    		cout << " ��ֻ� " ;
		    		break ;
	    		case 3 :
		    		cout << " ��ֻ����ĸ�� " ;
		    		break ;
		    	case 4 :
		    		cout << " ��ֻ��������� " ;
		    		break ;
		    	case 5 :
		    		cout << " ��ֻ���ָ " ;
		    		break ;
				case 6 :
					cout << " ��ֻ�����Ķ� " ;
					break ;
      	        case 7 : 
      	            cout << " ��ֻ��ˮ����� " ;
      	            break ;
				case 8 : 
					cout << " ��λ���̵�Ӷ�� " ;
					break ;
				case 9 :
					cout << " ��λ�����Ůʿ " ;
					break ;
				case 10 :
					cout << " ʮ����Ծ������ " ;
					break ;
				case 11 :
					cout << " ʮһ������ѵķ���� " ;
					break ;
				case 12 :
				    cout << " ʮ������ĵĹ��� " ;
					break ;		
		    }
		    cout << endl ;
	    }
	    cout << endl << endl << endl ;
	}
}
