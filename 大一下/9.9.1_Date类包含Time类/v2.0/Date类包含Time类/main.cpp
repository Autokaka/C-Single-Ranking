#include "stdafx.h"



#include <iostream>
using namespace std;
#include "Date.h"
#include "windows.h"


int main()
{
		int year = 1900, month = 1, day = 1, hour = 0, minute = 0, second = 0;
		cout << "�밴˳��������/��/��/ʱ/��/�룺  ";
		cin >> year >> month >> day >> hour >> minute >> second;
		Date date1(year, month, day, hour, minute, second);
		
/*		
		//����tick	
		int mode = 12;
		cout << "12or24Сʱ�ƣ�12/24����  ";
		cin >> mode;
		while (1)
		{
			date1.print(mode);
			date1.nextDay();
			Sleep(1000);
			system("cls");
		}
*/

/*
		//������������
		Date date2;
		date2 = date1 + 3;
		date2.print(12);
*/

/*
		//������������(������ǰ)
		Date date2;
		date2 = 3 + date1;
		date2.print(12);
*/
		system("pause");
		return 0;
}
