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
						cout << "������˵�� \n" ; 
					else
					    cout << "����˵�����滰 \n" ;
					if ( b==0 )
						cout << "������˵�� \n" ; 
					else 
				 	   cout << "����˵�����滰 \n" ;
					if ( c==0 )
					    cout << "������˵�� \n" ;
					else
				 	   cout << "����˵�����滰 \n" ;
				}
			}
		}
	} 
	return 0;
}
