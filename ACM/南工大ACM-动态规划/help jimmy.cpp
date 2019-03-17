#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 1000
int n, MAX, dp[N][2];
struct node
{
	int lx, rx, h;
	bool operator < (const node &n1) const
	{
		return h < n1.h;
	}
} layer[N];

int down(int x, int st, int h)
{
	int j;
	for (j = st; j >= 0; j--)
	{
		if (h - layer[j].h > MAX)
			return -1;
		if (x < layer[j].rx && x > layer[j].lx)
			return j;
	}
}

int main()
{
	int i, j, sx, sy, lx, rx, dl, dr;
	cin >> n >> sx >> sy >> MAX;
	layer[0].lx = layer[0].rx = sx, layer[0].h = sy, layer[1].lx = -INF, layer[1].rx = INF, layer[1].h = 0;
	for (i = 1; i <= n; i++)
		cin >> layer[i].lx >> layer[i].rx >> layer[i].h;
	sort(layer, layer + n + 2);
	for (i = 1; i <= n; i++)
	{
		lx = layer[i].lx;
		rx = layer[i].rx;
		dl = down(lx, i - 1, layer[i].h);
		dr = down(rx, i - 1, layer[i].h);
		if (dl > 0) dp[i][0] = min(dp[dl][0] + lx - layer[dl].lx, dp[dl][1] - lx + layer[dl].rx);
		else dp[i][0] = INF;
		if (dr > 0) dp[i][1] = min(dp[dr][0] + rx - layer[dr].lx, dp[dr][1] - rx + layer[dr].rx);
		else dp[i][1] = INF;
	}
	cout << dp[n + 1][0] + sy << endl;
	return 0;
}

