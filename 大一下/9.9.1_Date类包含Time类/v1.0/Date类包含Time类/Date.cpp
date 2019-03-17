#include "stdafx.h"


#include <iostream>
using namespace std;
#include <iomanip>
#include "Date.h"
#include "Time.h"


Date::Date(int years, int months, int days,const Time &inputime)
	: time(inputime)
{
	while (1)
	{
		const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((years < 0) || (months < 1 || months > 12) || !(days >= 1 && days <= daysPerMonth[months] || days == 29 && month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)))
		{
			cout << "年月日参数有问题，请重新输入！ ";
			cin >> years >> months >> days;
			continue;
		}
		break;
	} 
	year = years;
	month = months;
	day = days;
}

void Date::nextDay()
{
	int flag = time.tick();
	if (flag)
	{
		day++;
		const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (day == daysPerMonth[month] || (day == 29 && month == 2))
		{
			if (!(year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
			{
				day = 1;
				month++;
				if (month == 12)
				{
					month = 1;
					year++;
				}
			}
		}
	}
}

void Date::print(const int mode) const
{
	cout << "当前时间：" << setfill('0') << setw(4) << year << " 年 " << setw(2) << month << " 月 " << setw(2) << day << " 日 ";
	time.print(mode);
}