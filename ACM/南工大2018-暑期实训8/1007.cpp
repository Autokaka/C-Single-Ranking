#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 11
int x[N], ans, n;

bool canPut(int row, int col)
{
	int i;
	for (i = 1; i < col; i++)
	{
		if (x[i] == row || abs(row - x[i]) == abs(col - i))
			return 0;
	}
	return 1;
}

void dfs(int dep, int n)
{
	int i;
	if (dep > n)
	{
		ans++;
		return;
	}
	for (i = 1; i <= n; i++)
	{
		if (canPut(i, dep))
		{
			x[dep] = i;
			dfs(dep + 1, n);
		}
	}
}

int main()
{
	int store[N];
	for (int i = 1; i < N; i++)
	{
		ans = 0;
		dfs(1, i);
		store[i] = ans;
	}
	while (~scanf("%d", &n), n)
		printf("%d\n", store[n]);
	return 0;
}

