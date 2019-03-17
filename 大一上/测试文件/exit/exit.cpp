#include <iostream>
using namespace std ;

void exit () ;

int main () 
{
    exit () ;
	return 0;
}

void exit () 
{
	char command ;
    while ( 1 )
    {
		cout << " Wanna exit ? 'Y' to exit, 'N' to continue...\n" ;
		cin >> command ;
        if ( command == 'Y' )
		    break ;
		else
		{
			if ( command == 'N' )
			    continue ;
			else 
			    cout << "Please insert again.\n" << endl ;
		}
	}
}
