#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 1000005
int num[N];

int main()
{
	int n, cnt = 0, i, j;
	memset(num, 0, sizeof(num));
	for (i = 2; i < N; i++)
	{
		if (num[i] == 0)
		{
			num[i] = ++cnt;
			for (j = 2; j * i < N; j++)
				num[j * i] = cnt;
		}
	}
	while (~scanf("%d", &n))
		printf("%d\n", num[n]);
	return 0;
}

