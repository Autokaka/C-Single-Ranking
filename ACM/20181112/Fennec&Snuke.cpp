#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 120;
int n;
int vis[N], dis1[N], dis2[N];
vector<int>g[N];
queue<int>qu;

int main()
{
	int i, from, to, cur, now;
	cin >> n;
	rp2(i, 0, n)
	{
		cin >> to << from;
		g[to].push_back(from);
		g[from].push_back(to);
	}
	qu.push(1);
	dis1[1] = 0;
	vis[1] = 1;
	while (!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		rp2(i, 0, g[cur].size())
		{
			now = g[cur][i];
			if (!vis[now])
			{
				vis[now] = 1;
				dis1[cur] = dis1[now] + 1;
				qu.push(now);
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	qu.push(n);
	dis2[n] = 0;
	vis[n] = 1;
	while (!qu.empty())
	{
		cur = qu.front();
		qu.pop();
		rp2(i, 0, g[cur].size())
		{
			now = g[cur][i];
			if (!vis[now])
			{
				vis[now] = 1;
				dis2[cur] = dis2[now] + 1;
				qu.push(now);
			}
		}
	}
	int num1, num2;//这里开始还某有搞清楚 
	rp2(i, 0, n)
	{
		if (dis1[i] <= dis2[i])
			num1++;
	}
	num2 = n - num1;
	if (num1 > num2) cout << "Fennec\n";
	else cout << "Snuke\n";
	return 0;
}

