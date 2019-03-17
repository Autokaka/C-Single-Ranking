#include <iostream>
#include <iomanip>
using namespace std ;

int main ()
{
	double pi = 0.0 ;
	double i ;
	int n ;
	int flag = 1 ;
	cout << "请输入计算次数：" ;
	cin >> n ; 
	for ( i = 1 ; i!= 2*(n+1)-1 ; i+=2 )
	{
		pi += flag/i ;
		flag = flag*(-1) ;
	}
	cout << endl << "计算次数" << setw (17) << "π的值" << endl 
	     << (i+1)/2 << setw (23) << setprecision (7) << 4*pi << endl ;
	return 0 ;
} 
