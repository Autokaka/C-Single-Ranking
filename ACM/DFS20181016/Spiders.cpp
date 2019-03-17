#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 102
vector <int> g[N];
int n, dis[N], max_dis, max_index;

void dfs(int cur, int parent)
{
	int i, now;
	dis[cur] = dis[parent] + 1;
	if (max_dis < dis[cur])
	{
		max_dis = dis[cur];
		max_index = cur;
	}
	rp2(i, 0, g[cur].size())
	{
		now = g[cur][i];
		if (now == parent) continue;
		dfs(now, cur);
	}
}

int main()
{
	int i, m, to, from, ret = 0;
	cin >> n;
	while (n--)
	{
		cin >> m;
		rp2(i, 0, N) g[i].clear();
		rp2(i, 0, m-1)
		{
			cin >> to >> from;
			g[to].push_back(from);
			g[from].push_back(to);
		}
		memset(dis, 0, sizeof(dis));
		max_dis = 0;
		dis[0] = -1;
		dfs(1, 0);
		memset(dis, 0, sizeof(dis));
		max_dis = 0;
		dis[0] = -1;
		dfs(max_index, 0);
		ret += max_dis;
	}
	cout << ret << endl;
	return 0;
}

