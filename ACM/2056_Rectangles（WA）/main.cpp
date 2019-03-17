#include <iostream>
#include <iomanip>
using namespace std;

void swap (int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	double x1, y1, x2, y2, x3, y3, x4, y4, x, y;
	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
	{
		if (x1 > x2)
		{
			swap(x1, x2);
			swap(y1, y2);
		}
		if (x3 > x4)
		{
			swap(x3, x4);
			swap(y3, y4);
		}
		if (x1 > x3)
		{
			swap(x1, x3);
			swap(y1, y3);
			swap(x2, x4);
			swap(y2, y4);
		}
		cout << fixed << setprecision(2);
		if (x1 < x4 && x3 < x2 && y1 < y4 && y3 < y2)
		{
			if (x4 > x2)
				x = x2 - x3;
			else
				x = x4 - x3;
			if (x4 > y2)
				y = y2 - y3;
			else
				y = y4 - y3;
			cout << x * y << endl;
		}
		else
			cout << double(0) << endl;
	}
	return 0;
}
