#include <iostream>
using namespace std ;

int main() 
{
	//加数和被加数 
	int former[16]={1,5,4,6,7,9,2,3,7,8,9,5,4,2,4,0} ;
	int latter[16]={0,0,0,0,0,0,2,3,8,7,6,5,4,2,9,0} ;
	int sum[16]={0} ;
	int search , cnt=0 , sum_each ;
	for( search=15 ; search>=0 ; search-- )
	{
		cnt+=former[search]+latter[search] ;
		sum_each=cnt%10 ;
		cnt/=10 ;
		sum[search]=sum_each ;
	}
	//输出结果
	int display ;
	if( cnt!=0 )
        cout << cnt ; 
        
    for( display=0 ; display<=15 ; display++ )
	    cout << sum[display] ;
	
	return 0 ;
}
