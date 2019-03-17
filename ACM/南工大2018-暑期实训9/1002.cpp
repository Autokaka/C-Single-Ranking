#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 25
#define BLK '.'
#define RED '#'
#define ST '@'
int h, w, sx, sy, cnt;
int vis[N][N], dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char Maze[N][N];

bool canReach(int x, int y)
{
	if (x < 1 || x > h || y < 1 || y > w) return 0;
	if (Maze[x][y] == RED || vis[x][y]) return 0;
	return 1;
}

void dfs(int x, int y)
{
	int i, dx, dy;
	for (i = 0; i < 4; i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (canReach(dx, dy))
		{
			vis[dx][dy] = 1;
			cnt++;
			dfs(dx, dy);
		}
	}
}

int main()
{
	int i, j;
	while (~scanf("%d%d", &w, &h), h + w)
	{
		memset(vis, 0, sizeof(vis));
		for (i = 1; i <= h; i++)
		{
			getchar();
			for (j = 1; j <= w; j++)
			{
				scanf("%c", &Maze[i][j]);
				(Maze[i][j] == ST)? sx = i, sy = j : 0;
			}
		}
		vis[sx][sy] = 1, cnt = 1;
		dfs(sx, sy);
		printf("%d\n", cnt);
	}
	return 0;
}

