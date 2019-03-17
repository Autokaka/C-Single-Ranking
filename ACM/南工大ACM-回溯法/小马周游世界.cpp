#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 15
const int dir[8][2] = {{-2, -1}, {-2, 1}, {2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};//增量数组 
int n, vis[N][N], flag;

struct point
{
	int x, y, num;
	point(): num(0){}
	bool operator < (point p1) const
	{
		return num < p1.num;
	}
};

point ret[N * N + 2];

bool canPut(int dx, int dy)
{
	if (dx < 0 || dx >= n || dy < 0 || dy >= n || vis[dx][dy])
		return 0;
	return 1;
}

int canPut_num(int x, int y)
{
	int i, dx, dy, cnt = 0;
	for (i = 0; i < 8; i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (canPut(dx, dy))
			cnt++;
	}
	return cnt;
}

int next(int x, int y, point ne[8])
{
	int i, dx, dy, cnt = 0;
	for (i = 0; i < 8; i++)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (canPut(dx, dy))
		{
			ne[cnt].x = dx;
			ne[cnt].y = dy;
			ne[cnt++].num = canPut_num(dx, dy);
		}
	}
	sort(ne, ne + cnt);
	return cnt;
}

void dfs(int x, int y, int dep)
{
	int i, k, dx, dy;
	point ne[8];
	if (flag)
	{
		for (i = 0; i < n * n; i++)
		{
			cout << "(" << ret[i].x << ", " << ret[i].y << ")";
			i == n * n - 1? cout << endl : cout << "->"; 
		}
		return;
	}
	if (dep > n * n - 1)
	{
		
		flag = 1;
		return;
	}
	k = next(x, y, ne);
	for (i = 0; i < k; i++)
	{
		dx = ne[i].x;
		dy = ne[i].y;
		if (canPut(dx, dy))
		{
			vis[dx][dy] = 1;
			ret[dep].x = dx;
			ret[dep].y = dy;
			dfs(dx, dy, dep + 1);
			vis[dx][dy] = 0;
		}
	}
}

int main()
{
	int x, y;
	cin >> n >> x >> y;
	flag = 0, ret[0].x = x, ret[0].y = y;
	vis[x][y] = 1;
	dfs(x, y, 1);
	return 0;
}

