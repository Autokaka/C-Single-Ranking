#ifndef TIMEDATE_H
#define TIMEDATE_H

class TimeDate
{
	public:
		TimeDate();
		void setTimeDate(int,int,int,int,int,const int );
		void tick();
		void printUniversal() const;
		void printStandard();
	private:
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int second;
};

#endif 
