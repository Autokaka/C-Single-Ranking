#include <iostream>
using namespace std;

int main()
{
	int n, u, d;
	while (~scanf("%d%d%d", &n, &u, &d), n || u || d)
	{
		int t = 0, s = 0;
		while (1)
		{
			s += u;
			t++;
			if (s >= n)
				break;
			s -= d;
			t++;
		}
		printf("%d\n", t);
	}
	return 0;
}
