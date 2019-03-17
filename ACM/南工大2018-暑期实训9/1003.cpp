#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 5
char city[N][N];
int vis[N][N];
int n, MAX;

bool canSet(int x, int y)
{
	int i, j, flag = 0;
	if (x >= 1 && x <= n && y >= 1 && y <= n && vis[x][y] == 0)
	{
		for (i = 1; i <= n; i++)
			if (i != x && vis[i][y] == 1)
				for (j = min(x, i); j <= max(x, i); j++)
					if (vis[j][y] == 2)
						return 1;	
		for (i = 1; i <= n; i++)
			if (i != y && vis[x][i] == 1)
				for (j = min(x, i); j <= max(x, i); j++)
					if (vis[x][j] == 2)
						return 1;
	}
	return 0;
}

void dfs(int x, int y, int cnt)
{
	int i, j;
	if (x > n || y > n)
	{
		if (cnt > MAX)
			MAX = cnt;
		return;
	}
	for (i = x; i <= n; i++)
	{
		(i == x && y <= n)? j = y + 1 : j = y;
		for (; j <= n; j++)
		{
			if (canSet(i, j))
			{
				vis[i][j] = 1;
				dfs(i, j, cnt + 1);
				vis[i][j] = 0;
			}
		}
	}
}

int main()
{
	int i, j;
	while (~scanf("%d", &n), n)
	{
		memset(vis, 0, sizeof(vis)), MAX = 0;
		for (i = 1; i <= n; i++)
		{
			getchar();
			for (j = 1; j <= n; j++)
			{
				scanf("%c", &city[i][j]);
				city[i][j] == 'X'? vis[i][j] = 2 : 0;
			}
		}
		dfs(1, 1, 0);
		scanf("%d\n", MAX);
	}
	return 0;
}

