//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 8 
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; 
char map[N][N];
int vis[N][N];
int n, m, t, sx, sy, ex, ey;

bool canMove(int x, int y, int cur)
{
	if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || map[x][y] == 'X' || (x == ex && y == ey && t - cur != 1) || abs(x - ex) + abs(y - ey) > t - cur || ((x + y) & 1) ^ ((ex + ey) & 1) ^ ((t - cur) & 1))//奇偶剪枝  
		return 0;
	return 1;
}

int dfs(int x, int y, int dep)//dep对本题来说不是必须的 
{
	int i, dx, dy;
	if (x == ex && y ==ey && dep == t)
	{
		return 1;
	}
	for (i = 0; i < 4; i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (!canMove(dx, dy, dep))
			continue;
		vis[dx][dy] = 1;
		if (dfs(dx, dy, dep + 1))
			return 1;
		vis[dx][dy] = 0;
	}
	return 0;
}

int main()
{
	int i, j;
	while (cin >> n >> m >> t, n + m + t)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 'S')
					sx == i, sy = j;
				if (map[i][j] == 'D')
					ex == i, ey = j;
			}
		}
		vis[sx][sy] = 1;
		if (!canMove(sx, sy, t))
		{
			cout << "NO\n";
			continue;
		}
		if (dfs(sx, sy, 1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}	
	return 0;
}

