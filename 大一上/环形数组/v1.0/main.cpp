#include <iostream>
using namespace std ;

int main() 
{
	int n ;
	cout << "n：" ;
	cin >> n ;
	
	int circle[n+1]={0} ; 
	
	int m ;
	cout << "m：" ;
	cin >> m ;
	
	int mark=0 , status=0 ;
	for( mark ; mark!=n ; mark++ )
	{
	    //越界判断和赋值 
		if( status+m>n )
		{
			//占位判断
			for()
			{
				if()
			}
		    circle[status+m-n]=mark+1 ;
		}
		else
		{
			circle[status+m]=mark+1 ;
		}
		//对status的处理
		if( status+m>n )
		{
		    status+=m-n ; 
		}
		else
		{
			status+=(m+mark) ;
		}
	}

    int display=1 ;
    for( display ; display<=n ; display++ )
    {
    	cout << circle[display] << " " ;
	}
    
	return 0;
}
