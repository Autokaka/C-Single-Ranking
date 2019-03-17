#include <iostream>
using namespace std ;

void bottomGo ( int bottom , string init , string desti ) ;
void upperGo ( int disknum , string init , string temp , string desti ) ;

int cnt = 0 ;

int main()
{   
    cout << "Enter继续，或者Ctrl+Z退出..." ;
	while ( cin.get() != EOF )
    { 
		int disknum ;
		string init , temp , desti ;
	
		cout << "输入圆盘总数：" ;
		cin >> disknum ;
		cout << "\n输入你的初始柱：" ;
		cin >> init ; 
		cout << "\n输入你的缓存柱：" ;
		cin >> temp ;
		cout << "\n输入你的目标柱：" ;
		cin >> desti ;
     
		upperGo ( disknum , init , temp , desti ) ;
	
		cout << "一共需要 " << cnt << " 步\n" ;
		
		cout << "Enter继续，或者Ctrl+Z退出..." ;
		if ( cin.get() == EOF )
		    break ;
		else
		    continue ; 
	}
	return 0;
}

void bottomGo ( int bottom , string init , string desti )
{
	cout << "把第 " << bottom << " 个盘子从 " << init << "柱 移到 " << desti << "柱" << endl ; 
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
