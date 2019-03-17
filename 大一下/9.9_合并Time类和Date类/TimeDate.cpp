#include <iostream>
#include "TimeDate.h"
#include <iomanip>
using namespace std ;

TimeDate::TimeDate()
{
	year=month=day=hour=minute=second=0;
}

void TimeDate::setTimeDate(int yea,int mon,int days,int hou,int min,int sec )
{
	year=( yea>=1990 )? yea : 0;
	month=( mon>0&&mon<=12 )? mon : 0;
	switch( mon )
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			day=( days>=1&&days<=31 )? days : 0;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			day=( days>=1&&days<=30 )? days : 0;
			break;
		case 2:
			day=( (yea%4==0&&yea%100!=0)||(yea%400==0) )? ( (days>=1&&days<=29)? days : 0 ) : ((days>=1&&days<=28)? days : 0 );
			break;
	}
	hour=( hou>=0&&hou<24 )? hou : 0;
	minute=( min>=0&&min<=59 )? min : 0;
	second=( sec>=0&&sec<=59 )? sec : 0;
}

void TimeDate::tick()
{
	second++;
	if( second==60 )
	{
		second=0;
		minute++;
		if( minute==60 )
		{
			minute=0;
			hour++;
			if( hour==24 )
			{
				hour=0;
				day++;
				switch( month )
				{
					case 1:
					case 3:
					case 5:
					case 7:
					case 8:
					case 10:
						if( day>31 )
						{
							day=1;
							month++;
						}
						break;
					case 12:
						if( day>31)
						{
							day=1;
							month=1;
							year++;
						}
						break;
					case 4:
					case 6:
					case 9:
					case 11:
						if( day>30 )
						{
							day=1;
							month++;
						}
						break;
					case 2:
					    if( (year%4==0&&year%10!=0)||year%400==0 )
						{
							if( day>29 )
							{
								day=1;
								month++;
							}
						}
						else
						{
							if( day>28 )
							{
								day=1;
								month++;
							}
						}
						break;	
				} 
			}
		}
	}
}

void TimeDate::printUniversal() const 
{
	cout << "【24小时制】\n";
	cout << setfill('0') << setw(4) << year << "年 " << setw(2) << month << "月 " << setw(2) << day << "日 "
	     << setw(2) << hour << "：" << setw(2) << minute << "：" << setw(2) << second << endl;
}

void TimeDate::printStandard()
{
	cout << "【12小时制】\n";
	cout << setfill('0') << setw(4) << year << "年 " << setw(2) << month << "月 " << setw(2) << day << "日 "
	     << setw(2) << ( ( hour==0||hour==12 )? 12 : hour%12 ) << "：" << setw(2) << minute << "：" << setw(2) << second << ( (hour<12)? " AM" : " PM" ) << endl;
}
