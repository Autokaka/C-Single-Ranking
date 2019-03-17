#include <iostream>
using namespace std ;

class Date
{
	public:
		//constructor
		Date ( int , int , int ) ;
		
		//set
		void setYear ( int ) ;
		void setMonth ( int ) ;
		void setDay ( int ) ;
		
		//get
		int getYear () ;
		int getMonth () ;
		int getDay () ;
		
		void displayDate () ;
	
	private:
		int year ;
		int month ;
		int day ;
} ;
