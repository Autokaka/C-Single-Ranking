#include "stdafx.h"


#include <iostream>
using namespace std;
#include <iomanip>
#include "Date.h"
#include "Time.h"


Date::Date(int years, int months, int days,int hours, int minutes, int seconds)
	: time(hours, minutes, seconds)
{
	while (1)
	{
		const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if ((years < 0) || (months < 1 || months > 12) || !(days >= 1 && days <= daysPerMonth[months] || days == 29 && month == 2 && isLeapYear(years)))
		{
			cout << "年/月/日参数有问题，请重新输入！ ";
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
	if (time.tick())
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

Date Date::operator+(const int i)
{
	Date temp;
	temp.day = day + i;
	temp.month = month;
	temp.year = year;
	const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (temp.isLeapYear(temp.year) && temp.month == 2 && temp.day > 29)
	{
		temp.day -= 29;
		temp.month++;
	}
	else
	{
		if (temp.day > daysPerMonth[temp.month])
		{
			temp.day -= daysPerMonth[temp.month];
			temp.month++;
		}
	}
	if (temp.month > 12)
	{
		temp.month -= 12;
		temp.year++;
	}
	return temp;
}
Date operator+(const int i, const Date &date)
{
	Date temp;
	temp.day = date.day + i;
	temp.month = date.month;
	temp.year = date.year;
	const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (temp.isLeapYear(temp.year) && temp.month == 2 && temp.day > 29)
	{
		temp.day -= 29;
		temp.month++;
	}
	else
	{
		if (temp.day > daysPerMonth[temp.month])
		{
			temp.day -= daysPerMonth[temp.month];
			temp.month++;
		}
	}
	if (temp.month > 12)
	{
		temp.month -= 12;
		temp.year++;
	}
	return temp;
}

bool Date::isLeapYear(int years)
{
	if ((years % 4 == 0 && years % 100 != 0) || (years % 400 == 0))
		return true;
	return false;
}

void Date::print(const int mode) const
{
	cout << "当前时间：" << setfill('0') << setw(4) << year << " 年 " << setw(2) << month << " 月 " << setw(2) << day << " 日 ";
	time.print(mode);
}
