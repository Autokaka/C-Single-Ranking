#include <iostream>
using namespace std;

bool leap(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
		return true;
	else
		return false;
}

int main()
{
	int y, m, d, n;
	int daysPerMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d-%d-%d", &y, &m, &d);
		if (m == 2 && d == 29 && leap(y) && !leap(y + 18))
		{
			printf("%d\n", -1);
			continue;
		}
		int t = 0, i, j = y;
		if (m >= 3)
			i = j + 1;
		else
			i = j;
		for (; j < y + 18; j++)
		{
			if (leap(i))
				t += 366;	
			else
				t += 365;
			i++;
		}
	printf("%d\n", t);
	}
	return 0;
}

