#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 1000005

int main()
{
	int t, n, list, flag;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		flag = 0;
		while (n--)
		{
			scanf("%d", &list);
			if (list & 1) flag = 1;
		}
		printf("%s\n", flag? "xm" : "xf");
	}
	return 0;
}

