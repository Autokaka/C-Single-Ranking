#ifndef DATE_H
#define DATE_H
#include "Time.h"

class Date
{
	public:
		Date(int,int,int,const Time &);
		void nextDay();
		void print(const int) const;
		
	private:
		int year;
		int month;
		int day;
		Time time;
};

#endif