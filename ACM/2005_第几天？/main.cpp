#include <iostream>
#include <stdio.h>
using namespace std;

int main() 
{
	int daysPermonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int y, m, d;
	char date;
	while (scanf("%d/%d/%d", &y, &m, &d) != EOF)
	{
		int day = 0;
		((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)? daysPermonth[2] = 29 : daysPermonth[2] = 28;
		for (int month = 1; month <= m - 1; month ++)
			day += daysPermonth[month];
		cout << day + d << endl;
	}
	return 0;
}
