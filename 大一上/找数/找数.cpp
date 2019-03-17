#include <iostream>
using namespace std ;

int main() 
{
	int baiwei , shiwei , gewei ;
	for ( baiwei=0 ; baiwei<=6 ; baiwei++ )
	{
		for( shiwei=0 ; shiwei<=6 ; shiwei++ )
		{
			for ( gewei=0 ; gewei<=6 ; gewei++ )
			{

				if ( baiwei*7*7+shiwei*7+gewei==gewei*9*9+shiwei*9+baiwei )
				{
					cout << baiwei*7*7+shiwei*7+gewei << " " << baiwei << " " << shiwei << " " << gewei << " " << endl ;
				} 
			}
		}
	}
	return 0;
}
