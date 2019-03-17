#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 10005
int dp[N][N], int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}, vis[N][N];
int m, n, sum = 0, MIN = INF;

int dfs(int x, int y, int cur, int cnt)
{
	int combo, i, j, dx, dy;
	if (cur >= 60 && MIN > cnt)
	{
		return cnt;
	}
	rp2(i, 0, 4)
	{
		dx = x + dir[i][0];
		dy = y + dir[i][1];
		if (dx < 0 || dy < 0 || dx > n || dy > m || vis[dx][dy]) continue;
		vis[dx][dy] = 1;
		cnt++;
		cur += dp[dx][dy];
		dfs(dx, dy, cur, cnt);
		vis[dx][dy] = 0;
	}
}

int main()
{
	int i, j;
	cin >> m >> n;//m:ÁÐ, n:ÐÐ 
	rp2(i, 0, n)
	{
		rp2(j, 0, m)
		{
			cin >> dp[i][j];
			sum += dp[i][j];
		}
	}
	if (sum & 1)
	{
		cout << 0 << endl;
		return 0;
	}		
	dfs(0, 0, dp[0][0], 1);
	
	return 0;
}

