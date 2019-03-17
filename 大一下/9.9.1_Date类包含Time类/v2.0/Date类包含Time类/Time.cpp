#include "stdafx.h"



#include <iostream>
using namespace std;
#include <iomanip>
#include "Time.h"

Time::Time(int hours, int minutes, int seconds)
{
	while (1)
	{
		if ((seconds < 0 || seconds > 59) || (minutes < 0 || minutes > 59) || (hours < 0 || hours > 23))
		{
			cout << "时/分/秒参数有问题，请重新输入 时/分/秒！  ";
			cin >> hours >> minutes >> seconds;
			continue;
		}
		break;
	} 
	second = seconds;
	minute = minutes;
	hour = hours;
}

int Time::tick()
{
	second++;
	if (second == 60)
	{
		second = 0;
		minute++;
		if (minute == 60)
		{
			minute = 0;
			hour++;
			if (hour == 24)
			{
				hour = 0;
				return 1;
			}
		}
	}
	return 0;
}

void Time::print(const int mode) const 
{
	switch (mode)
	{
		case 12:
			cout << setfill('0') << setw(2) << ((hour >= 12) ? hour % 12 : hour) << " : " << setw(2) << minute << " : " << setw(2) << second << ((hour>=12)?" PM ":" AM ") << endl;
			break;
		case 24:
		default:
			cout << setfill('0') << setw(2) << hour << " : " << setw(2) << minute << " : " << setw(2) << second << endl;
			break;

	}
}