#include <iostream>
using namespace std ;
#include <cmath>
#include "Quadrangle.h" 

double Quadrangle :: getLength ( double x1 , double x2 , double y1 , double y2 )
{
	return sqrt( (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) ) ;
}

double Quadrangle :: HelenFormula ( double a , double b , double c , double d )
{
	double p ;
	p = (a+b+c+d)/2 ;
	return sqrt ( (p-a)*(p-b)*(p-c)*(p-d) ) ;
}

