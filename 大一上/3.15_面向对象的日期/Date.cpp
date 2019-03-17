#include <iostream>
#include "Date.h"
using namespace std ;

//constructor
Date::Date ( int y ,
             int m ,
			 int d )
{
	setYear ( y ) ;
	setMonth ( m ) ;
	setDay ( d ) ;
} 

//set
void Date :: setYear ( int y )
{
	year = y ;
}
void Date :: setMonth ( int m )
{
	if ( m > 0 && m <=12 )
	    month = m ;
	else 
	{
	    month = 1 ;
    	cout << " 月份输入的格式不对 " ; 
	}
}
void Date :: setDay ( int d )
{
	day = d ;
}

//get
int Date :: getYear ()
{
	return year ;
}
int Date :: getMonth ()
{
	return month ;
}
int Date :: getDay ()
{
	return day ;
}


void Date :: displayDate ()
{
	cout << "今天的日期是:" << getYear () << "/" << getMonth () << "/" << getDay () << endl ;
}
