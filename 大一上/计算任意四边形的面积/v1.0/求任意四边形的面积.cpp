#include <iostream>
using namespace std ;
#include <cmath>

double getLength ( double , double , double , double ) ;
double HelenFormula ( double , double , double , double ) ;
void check ( double , double , double , double , double , double , double , double ) ;

int main ()
{
	while ( cin.get() != EOF )
	{
		double xa , ya , xb , yb , xc , yc , xd , yd ;
		double ab , bc , cd , ad ; 
    	cout << "计算任意四边形的面积\n" << "请按顺序输入ABCD四点坐标：" ;
		cout << "\nA点：" ; cin >> xa >> ya ;
		cout << "\nB点：" ; cin >> xb >> yb ; 
		cout << "\nC点：" ; cin >> xc >> yc ;
		cout << "\nD点：" ; cin >> xd >> yd ; 
		
		check ( xa , xb , xc , xd , ya , yb , yc , yd ) ;
		
		ab = getLength ( xa , xb , ya , yb ) ;
	    bc = getLength ( xb , xc , yb , yc ) ;
	    cd = getLength ( xc , xd , yc , yd ) ;
	    ad = getLength ( xa , xd , ya , yd ) ;
	    
	    cout << "该四边形的面积为：" << HelenFormula ( ab , bc , cd , ad ) << endl ;
	    
		cout << "Insert Enter to continue, or Ctrl+Z to exit...\n" ;
		if ( cin.get() == EOF ) 
		    break ;
	}
}

double getLength ( double x1 , double x2 , double y1 , double y2 )
{
	return sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) ) ;
}

double HelenFormula ( double a , double b , double c , double d )
{
	double p ;
	p = (a+b+c+d)/2 ;
	return sqrt ( (p-a)*(p-b)*(p-c)*(p-d) ) ;
}

void check ( double xa , double xb , double xc , double xd , double ya , double yb , double yc , double yd )
{
	if ( xa == xb && xb == xc || xb == xc && xc == xd )
	    cout << "不能构成四边形，请重新输入：" ;
	else
	{
		if ( xa-xb == xb-xc && ya-yb == yb-yc || xb-xc == xc-xd && yb-yc == yc-yd )
	        cout << "不能构成四边形，请重新输入：" ;
	} 
}
