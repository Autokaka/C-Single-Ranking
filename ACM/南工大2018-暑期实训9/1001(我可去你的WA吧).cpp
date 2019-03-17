#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 8
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}, vis[N][N];
int n, m, t, sx, sy, ex, ey;
char Maze[N][N];

bool canGo(int x, int y, int time)
{
	if (x < 1 || x > n || y < 1 || y > m || vis[x][y] || Maze[x][y] == 'X')
		return 0;
	if (x == ex && y == ey && t != time || ((t - time) & 1) ^ ((x + y) & 1) ^ ((ex + ey) & 1))
		return 0;
	return 1;
}

bool dfs(int x, int y, int dep)
{
	int i, dx, dy;
	if (x == ex && y == ey)
		return 1;
	for (i = 0; i < 4; i++)
	{
		dx = x + dir[i][0], dy = y + dir[i][1];
		if (!canGo(dx, dy, dep)) continue;
		vis[x][y] = 1;
		if (dfs(dx, dy, dep + 1)) return 1;
		vis[x][y] = 0;
	}
	return 0;
}

int main()
{
	int i, j, flag;
	while (~scanf("%d%d%d", &n, &m, &t), n + m + t)
	{
		memset(vis, 0, sizeof(vis)), flag = 1;	
		for (i = 1; i <= n; i++)
		{
			getchar();
			for (j = 1; j <= m; j++)
			{
				scanf("%c", &Maze[i][j]);
				Maze[i][j] == 'S'? sx = i, sy = j : 0;
				Maze[i][j] == 'D'? ex = i, ey = j : 0;
			}
		}
		if (!canGo(sx, sy, 0) || !dfs(sx, sy, 1))
			flag = 0;
		printf("%s\n", flag? "YES" : "NO");
	}
	return 0;
}

