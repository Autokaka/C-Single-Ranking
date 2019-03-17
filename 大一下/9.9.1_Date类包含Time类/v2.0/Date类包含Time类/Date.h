#ifndef DATE_H
#define DATE_H
#include "Time.h"

class Date
{
	public:
		Date(int=1900, int=1, int=1, int=0, int=0, int=0);
		void nextDay();

		Date operator+(const int);
		friend Date operator+(const int, const Date &);

		void print(const int) const;
		
	private:
		bool isLeapYear(int);
		int year;
		int month;
		int day;
		Time time;
};

#endif