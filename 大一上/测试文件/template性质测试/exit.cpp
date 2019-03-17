#include <iostream>
using namespace std ;

template < class T2, class T3, class T4 >
T2 maximum( T2 value1, T3 value2, T4 value3 )
{
	T2 maximumValue=value1 ;
	if(value2>maximumValue)
		maximumValue=value2 ;
	if(value3>maximumValue)
		maximumValue=value3 ;

	return maximumValue ;
}

int main()
{
	cout << "请输入任意的三个数：\n" ;
	int value1=34 ;
	double value2=2.71828 ;
	int value3=12345 ;
	cout << maximum( value1, value2, value3 ) ;

	return 0 ;
}


