#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 1005
struct node
{
	int index, value;
};
vector <node> g[N];
int n, dis[N];

void dfs(int cur, int par)
{
	int i, now, v;
	node p;
	rp2(i, 0, g[cur].size())
	{
		p = g[cur][i];
		now = p.index;
		v = p.value;
		if (now == par) continue;
		dis[now] = dis[cur] + v;
		dfs(now, cur);
	}
}

int main()
{
	int i, to, from, v;
	node tmp;
	rp2(i, 1, n)
	{
		cin >> to >> from >> v;
		tmp.index = from;
		tmp.value = v;
		g[to].push_back(tmp);
		tmp.index = to;
		tmp.value = v;
		g[from].push_back(tmp);
	}
	dis[1] = 0;
	dfs(1, 0);
	return 0;
}

