#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x, y;
	while (cin >> x >> y)
	{
		if ((x ==0 && y == 0) || !(x < y && x >= -39 && x <= 50 && y >= -39 && y <= 50))
			end: continue;
		for (int i = x; i <= y; i++)
		{
			int tmp = i * i + i + 41;
			for (int j = 2; j <= sqrt(tmp); j++)
			{
				if (tmp != j && tmp % j == 0)
					{
						cout << "Sorry" << endl;
						goto end;
					}
			}
		}
		cout << "OK" << endl;
	}
	return 0;
}
