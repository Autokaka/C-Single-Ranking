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
	
	cout << "欢迎使用计算机教育系统\n"
	     << "Enter继续,Ctrl+Z退出...\n" ;
	
	while ( cin.get() != EOF )
	{  
		qasys () ;
		
		cin >> answer ;
		cnt++ ;

		if ( answer == ::key )//答对了 
		{
			if ( cnt%10 == 0 )
			{
			    suggest ( cnt , right ) ;
			    cout << "\nEnter继续,Ctrl+Z退出...\n" ; 
			    if ( cin.get() == EOF )
			        break ;
		    }
		    else
		    {
		    	comment (1) ;
		    	right++ ;
			}  
		}
		else//答错了 
		{
			while ( cnt%10 != 0 && answer!=::key )
			{
				comment (0) ;
				cout << "订正答案：" ; 
				cin >> answer ;
				cnt++ ;
			}
            if ( cnt%10 == 0)
			{
				suggest ( cnt , right ) ;
				cout << "\nEnter继续,Ctrl+Z退出...\n" ;
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
	    	    	cout << "不对，请再尝试一会儿.\n" ;
	    	    	break ;
	    	    case 2 :
	    	    	cout << "错误也，再尝试一下吧.\n" ;
	    	    	break ;
	    	    case 3 :
	    	    	cout << "别放弃呀，再试试吧.\n" ;
	    	    	break ;
	    	    case 4 :
	    	    	cout << "不对哦，再试试吧.\n" ;
	    	    	break ;
	        }
	        break ;
	    case 1 :
            switch ( comment )
            {
	    	    case 1 :
	    	    	cout << "你真棒！\n" ;
	    	    	break ;
	    	    case 2 :
	    	    	cout << "棒极了孩子！\n" ;
	    	    	break ;
	    	    case 3 :
	    	    	cout << "干得漂亮！\n" ;
	    	    	break ;
	    	    case 4 :
	    	    	cout << "继续保持！\n" ;
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
	        cout << "Ummm...也许你可以找你的老师再熟悉熟悉知识点.\n" ;
	        cnt = 0 ;
	        right = 0 ;
	    }
	    else 
	    {
	        cout << "正确率很高！你是真的厉害！\n" ; 
			cnt = 0 ;
			right = 0 ; 
	    }
	}
}
