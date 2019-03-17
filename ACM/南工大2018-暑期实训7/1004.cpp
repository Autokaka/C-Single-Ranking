#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

int main()
{
	int n, m, acum, t, j;
	while (~scanf("%d%d", &n, &m))
	{
		acum = 0;
		rep(i, 0, n)
		{
			scanf("%d%d", &t, &j);
			acum ^= (abs(t - j) - 1);
		}
		printf("%s\n", acum? "I WIN!" : "BAD LUCK!");
	}
	return 0;
}

