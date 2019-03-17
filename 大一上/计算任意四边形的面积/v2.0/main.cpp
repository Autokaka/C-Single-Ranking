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
    	cout << "计算任意四边形的面积\n" << "请按顺序输入ABCD四点坐标：" ;
		cout << "\nA点：" ; cin >> xa >> ya ;
		cout << "\nB点：" ; cin >> xb >> yb ; 
		cout << "\nC点：" ; cin >> xc >> yc ;
		cout << "\nD点：" ; cin >> xd >> yd ; 
		
		ab = myQuadrangle.getLength ( xa , xb , ya , yb ) ;
	    bc = myQuadrangle.getLength ( xb , xc , yb , yc ) ;
	    cd = myQuadrangle.getLength ( xc , xd , yc , yd ) ;
	    ad = myQuadrangle.getLength ( xa , xd , ya , yd ) ;
	    
	    cout << "该四边形的面积为：" << myQuadrangle.HelenFormula ( ab , bc , cd , ad ) << endl ;
	    
		cout << "Insert Enter to continue, or Ctrl+Z to exit...\n" ;
		if ( cin.get() == EOF ) 
		    break ;
	}
	return 0 ;
}
