#include <iostream>
using namespace std ;

int main() 
{
	int n ;
	cout << "n��" ;
	cin >> n ;
	
	int circle[n+1]={0} ; 
	
	int m ;
	cout << "m��" ;
	cin >> m ;
	
	int mark=0 , status=0 ;
	for( mark ; mark!=n ; mark++ )
	{
	    //Խ���жϺ͸�ֵ 
		if( status+m>n )
		{
			//ռλ�ж�
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
		//��status�Ĵ���
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
