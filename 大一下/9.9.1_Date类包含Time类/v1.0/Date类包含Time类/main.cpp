#include "stdafx.h"



#include <iostream>
using namespace std;
#include "Date.h"
#include "windows.h"


int main()
{
		int hour = 0, minute = 0, second = 0;
		cout << "������ ʱ/��/�룺  ";
		cin >> hour >> minute >> second;
		Time time(hour, minute, second);

		int year = 1990, month = 1, day = 1;
		cout << "��������/��/�գ�  ";
		cin >> year >> month >> day;
		Date date(year, month, day, time);
		
		int mode = 12;
		cout << "12or24Сʱ�ƣ�12/24����  ";
		cin >> mode;
		while (1)
		{
			date.print(mode);
			date.nextDay();
			Sleep(1000);
			system("cls");
		}

    return 0;
}
