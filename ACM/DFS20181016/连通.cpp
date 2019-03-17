//dfs检测连通，存在分岔的连通无法被检测的问题  
#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 102
char g[N][N];
int n, m, vis[N][N], dir[8][2] = {...};//上下左右  左上左下  右上右下  8个方向  

void dfs(int x, int y)
{
	int i, dx, dy;
	rp2(i, 0, 8)
	{
		dx = x + dir[i][0];
		dy = y + dir[y][0];
		if (...) continue;
		if (vis[dx][dy] && g[dx][dy] == '@')
		{
			vis[dx][dy] = 1;
			dfs(dx, dy);
		}
	}
}

int main()
{
	int i, j, ret = 0;
	cin >> n >> m;
	rp2(i, 0, n) cin >> g[i];
	rp2(i, 0, n)
	{
		rp2(j, 0, m)
		{
			if (!vis[i][j] && g[i][j] == '@')
			{
				ret++;
				dfs(i, j);
			}
		}
	}
	return 0;
}

