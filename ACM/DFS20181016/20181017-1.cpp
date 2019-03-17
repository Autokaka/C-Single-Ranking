#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 502
char g[N][N];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int vis[N][N];
int n, m, k, n1, cnt = 0;

void dfs(int x, int y)
{
	vis[x][y] = 1;
	int i, j, dx, dy;
	if (cnt >= k) return;
	rp2(i, 0, 4)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (dx < 0 || dx >= n || dy < 0 || dy >= n) continue;
		if (g[dx][dy] == '#' || vis[dx][dy]) continue;
		dfs(dx, dy);
		cnt++;
		if (cnt <= k) g[dx][dy] = 'X';
	}
}

int main()
{
	int i, j, sx, sy;
	cin >> n >> m >> k;
	rp2(i, 0, n)
	{
		rp2(j, 0, m)
			cout << g[i][j];
		cout << endl;
	}
	return 0;
}

