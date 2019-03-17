#include <iostream>
using namespace std ;
#include <cmath>

void revise ( double , double , double , double , double , double , double , double ) ;
void check ( double , double , double , double , double , double ) ;
double getLength ( double , double , double , double ) ;
double HelenFormula ( double , double , double , double ) ;

double  m1 , n1 , m2 , n2 , m3 , n3 , m4 , n4 ;  

int main ()
{
	double xa , ya , xb , yb , xc , yc , xd , yd ;
	double ab , bc , cd , ad ;  
	cout << "请输入任意四个点的直角坐标："
	     << "\n第一个点：" ;
	cin >> xa >> ya ; 
	cout << "\n第二个点：" ;
	cin >> xb >> yb ;
	cout << "\n第三个点：" ;
	cin >> xc >> yc ;
	cout << "\n第四个点：" ;
	cin >> xd >> yd ;
    //revise 
	revise ( xa , xb , xc , xd , ya , yb , yc , yd ) ;
	xa = m3 , xb = m4 , xc = m2 , xd = m1 ;
	ya = n3 , yb = n4 , yc = n2 , yd = n1 ;
	//checkout
	check ( xa , xb , xc , ya , yb , yc )
	//Testing port 
	cout << xa << ya << endl
	     << xb << yb << endl 
		 << xc << yc << endl 
		 << xd << yd << endl ;
	ab = getLength ( xa , xb , ya , yb ) ;
	bc = getLength ( xb , xc , yb , yc ) ;
	cd = getLength ( xc , xd , yc , yd ) ;
	ad = getLength ( xa , xd , ya , yd ) ;
	cout << HelenFormula ( ab , bc , cd , ad ) ; 	
} 

void revise ( double x1 , double x2 , double x3 , double x4 , double y1 , double y2 , double y3 , double y4 )
{
	double exchange ;
	//2
	if ( x1 > x2 ) 
	{
		m1 = x1 , n1 = y1 ;
	    m2 = x2 , n2 = y2 ; 
	}
	else 
	{
		m1 = x2 , n1 = y2 ;
		m2 = x1 , n2 = y1 ;
	}
	//3
	if ( x3 > m1 )
	{
		m3 = m2 , n3 = n2 ;
		m2 = m1 , n2 = n1 ;
		m1 = x3 , n1 = y3 ;
	}
	else
	{
		if ( x3 > m2 )
		{
			m3 = m2 , n3 = n2 ;
			m2 = x3 , n2 = y3 ;
		}
		else
		{
			m3 = x3 , n3 = y3 ;
		}
	}
	//4
	if ( x4 > m1 )
	{
		m4 = m3 , n4 = n3 ;
		m3 = m2 , n3 = n2 ;
		m2 = m1 , n2 = n1 ;
		m1 = x4 , n1 = y4 ;
	}
	else
	{
		if ( x4 > m2 )
		{
			m4 = m3 , n4 = n3 ;
			m3 = m2 , n3 = n2 ;
			m2 = x4 , n2 = y4 ;
		}
		else 
		{
			if ( x4 > m3 )
			{
				m4 = m3 , n4 = n3 ;
				m3 = x4 , n3 = y4 ;
			}
			else 
			    m4 = x4 , n4 = y4 ;
		}
	}
	
    if ( m1 == m2 )
    {
    	if ( n1 < n2 )
		{
			exchange = n1 ;
			n1 = n2 ;
			n2 = exchange ;
		}
	}
	if ( m3 == m4 )
    {
    	if ( n3 < n4 )
		{
			exchange = n3 ;
		    n3 = n4 ;
		    n4 = exchange ;
		}
	}
}

void check ( double xa , double xb , double xc , double ya , double yb , double yc )
{
	
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

