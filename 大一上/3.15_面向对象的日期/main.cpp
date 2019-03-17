#include <iostream>
#include "Date.h"
using namespace std ; 

int main () 
{
	int y , m , d ; 
	Date date0 ( 1999 , 6 , 24 ) ;
    cout << "ÇëÊäÈëÈÕÆÚ£º" ;
    cin >> y >> m >> d ;
    date0.setYear( y ) ;
    date0.setMonth( m ) ;
    date0.setDay( d ) ;
    date0.displayDate () ; 
	return 0;
}
