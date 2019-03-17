#include <iostream>
using namespace std ;

int main() 
{
	int a , b , c ;
	for ( a=0 ; a<=1 ; a++ )
	{
		for ( b=0 ; b<=1 ; b++ )
		{
			for ( c=0 ; c<=1 ; c++ )
			{
                if ( a!=b&&b!=c&&c==(!a&&!b) )
                {
                	if ( a==0 )
						cout << "张三在说谎 \n" ; 
					else
					    cout << "张三说的是真话 \n" ;
					if ( b==0 )
						cout << "李四在说谎 \n" ; 
					else 
				 	   cout << "李四说的是真话 \n" ;
					if ( c==0 )
					    cout << "王五在说谎 \n" ;
					else
				 	   cout << "王五说的是真话 \n" ;
				}
			}
		}
	} 
	return 0;
}
