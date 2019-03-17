#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (~scanf("%d", &n), n)
	{
		int floor = 0, t = 0, f;
		while (n--)
		{
			scanf("%d", &f);
			if (f - floor > 0)
				t += 6 * (f - floor);
			else
				t += 4 * (floor - f);
			t += 5;
			floor = f;
		}
		printf("%d\n", t);
	}
	return 0;
}

