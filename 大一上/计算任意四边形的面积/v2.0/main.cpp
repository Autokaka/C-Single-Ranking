#include <iostream>
using namespace std ;
#include "Quadrangle.h"

int main ()
{
	Quadrangle myQuadrangle ;
	while ( cin.get() != EOF )
	{
		double xa , ya , xb , yb , xc , yc , xd , yd ;
		double ab , bc , cd , ad ; 
    	cout << "���������ı��ε����\n" << "�밴˳������ABCD�ĵ����꣺" ;
		cout << "\nA�㣺" ; cin >> xa >> ya ;
		cout << "\nB�㣺" ; cin >> xb >> yb ; 
		cout << "\nC�㣺" ; cin >> xc >> yc ;
		cout << "\nD�㣺" ; cin >> xd >> yd ; 
		
		ab = myQuadrangle.getLength ( xa , xb , ya , yb ) ;
	    bc = myQuadrangle.getLength ( xb , xc , yb , yc ) ;
	    cd = myQuadrangle.getLength ( xc , xd , yc , yd ) ;
	    ad = myQuadrangle.getLength ( xa , xd , ya , yd ) ;
	    
	    cout << "���ı��ε����Ϊ��" << myQuadrangle.HelenFormula ( ab , bc , cd , ad ) << endl ;
	    
		cout << "Insert Enter to continue, or Ctrl+Z to exit...\n" ;
		if ( cin.get() == EOF ) 
		    break ;
	}
	return 0 ;
}
