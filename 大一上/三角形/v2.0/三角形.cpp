#include <iostream>
using namespace std ;

int main ()
{
	int a , b , c ;
	int n1 , n2 , n3 ;
	cout << "请输入三角形的三边：" ;
	cin >> a >> b >> c ;
	if ( a > b )
	    n1 = a , n2 = b ; 
	else 
	    n1 = b , n2 = a ; 
	if ( c >= n1 ) 
	    n3 = n2 , n2 = n1 , n1 = c ; 
	if ( c < n1 && c > n2 ) 
	    n3 = n2 , n2 = c ;
	//if ( c <= n2 )1.最严重的问题。比较的时候出现重复满足条件的情况。反例：a=2,b=3,c=3.经过之前的判断你已经是n1=3,n2=3,n3=2了，现在这么再次赋值，就变成了n1=n2=n3=3 
	/*  n3 = c ;  */ 
	if ( c < n2 ) 
	n3 = c ;
		
	if ( n1+n2 <= n3 )
	{ 
	    cout << " 不能构成三角形 " ; 
	}
	else 
	{ 
	    cout << " 能构成三角形 " ; 
	    if ( n2*n2+n3*n3 == n1*n1 )//3.你的n1>n2>n3，所以应该拿较小的两个边n2,n3和最长的边n1比较 
		{
			cout << " 是直角三角形 " ; 
		} 
		if ( n2*n2+n3*n3 < n1*n1 )
		{
			cout << "是钝角三角形 " ;
		}
		if ( n2*n2+n3*n3 > n1*n1 )
		{
			cout << "是锐角三角形 " ;
		}
	    if ( n1 == n2 || n2 == n3 || n1 == n3 )//2.这个地方比较边长关系的讨论要全面 
	    {
	    	cout << " 还是等腰三角形 " ;
			if ( n2*n2+n3*n3 == n1*n1 ) //还是那个问题,你的n1>n2>n3，所以应该拿较小的两个边n2,n3和最长的边n1比较 
			{
				cout << " 还是等腰直角三角形 " ;
			}
			if ( n1 == n2 && n2 == n3 )//这个地方比较边长关系的讨论也要全面 
			{
				cout << " 还是等边三角形 " ; 
			}
		}
	}
	
}
