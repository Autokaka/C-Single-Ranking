#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 10005
int n, m, ret = 0;
int vis[N];
vector <int> dp[N];

void dfs(int st, int cur, int len)
{
	int i, now;
	if (len == 4)
	{
		ret++;
		return;
	}
	else if (len == 3)
	{
		rp2(i, 0, dp[cur].size())
		{
			now = dp[cur][i];
			if (!vis[now])
			{
				ret++;
				return;
			}
			else if (vis[now] && now == st)
			{
				ret++;
				return;
			}
		}
	}
	else if (len < 3)
	{
		rp2(i, 0, dp[cur].size())
		{
			now = dp[cur][i];
			if (!vis[now])
			{
				vis[now] = 1;
				dfs(st, now, len + 1);
				vis[now] = 0;
			}
		}
	}
}

int main()
{
	int i, j, to, from;
	cin >> n >> m;
	rp2(i, 0, m)
	{
		cin >> to >> from;
		dp[to].push_back(from);
		dp[from].push_back(to);
	}
	rp(i, 0, m)
		dfs();
	return 0;
}

