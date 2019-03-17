#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 25
int n, num[N], mk[N], prime[N];

void gPrime()
{
	memset(prime, -1, sizeof(prime));
	int i, j;
	for (i = 2; i < 2 * N; i++)
	{
		if(prime[i] == -1)
		{
			prime[i] = 1;
			for (j = 2; j * i < 2 * N; j++)
				prime[j * i] = 0;
		}
	}
}

void dfs(int dep)
{
	int i;
	if (dep > n)
	{
		if (prime[num[1] + num[n]])
			for (i = 1; i <= n; i++)
				printf("%d%s", num[i], (i == n)? "\n" : " ");
		return;
	}
	for (i = 2; i <= n; i++)
	{
		if (!mk[i] && prime[num[dep - 1] + i])
		{
			num[dep] = i;
			mk[i] = 1;
			dfs(dep + 1);
			mk[i] = 0;
			num[dep] = 0;
		}
	}
}

int main()
{
	gPrime();
	int rnd = 0;
	num[1] = 1;
	while (~scanf("%d", &n), n)
	{
		printf("Case %d:\n", ++rnd);
		dfs(2);
		printf("\n");
	}
	return 0;
}

