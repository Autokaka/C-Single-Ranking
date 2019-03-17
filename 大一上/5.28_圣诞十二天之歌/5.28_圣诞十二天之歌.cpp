#include <iostream>
using namespace std ;

int main ()
{
	int day = 1 ;
	int left = 1 ;
	for ( int day =1 ; day <= 12 ; day++ )
	{
		cout << "在圣诞节的第" << day << "天,我的真爱送我：" << endl ;
		for ( left = day ; left >=1 ; left--) 
		{
			switch ( left )
		    {
		    	case 1 : 
		    	    cout << " 一只站在梨树上的鹧鸪鸟 " ;
		    	    break ;
		    	case 2 :
		    		cout << " 两只鸠 " ;
		    		break ;
	    		case 3 :
		    		cout << " 三只法国母鸡 " ;
		    		break ;
		    	case 4 :
		    		cout << " 四只鸣唱的鸟儿 " ;
		    		break ;
		    	case 5 :
		    		cout << " 五只金戒指 " ;
		    		break ;
				case 6 :
					cout << " 六只生蛋的鹅 " ;
					break ;
      	        case 7 : 
      	            cout << " 七只游水的天鹅 " ;
      	            break ;
				case 8 : 
					cout << " 八位挤奶的佣妇 " ;
					break ;
				case 9 :
					cout << " 九位跳舞的女士 " ;
					break ;
				case 10 :
					cout << " 十个跳跃的男人 " ;
					break ;
				case 11 :
					cout << " 十一个吹风笛的风笛手 " ;
					break ;
				case 12 :
				    cout << " 十二个打鼓的鼓手 " ;
					break ;		
		    }
		    cout << endl ;
	    }
	    cout << endl << endl << endl ;
	}
}
