#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 200005
vector <int> g[N];
int n, k, u[N] = {0}, num[N] = {0};

void dfs(int cur, int par)
{
	int i, now;
	if (u[cur]) num[cur]++; 
	rp2(i, 0, g[cur].size())
	{
		now = g[cur][i];
		if (now == par) continue;
		dfs(now, cur);
		//»ØÍË
		num[cur] += num[now]; 
	}
}

int main()
{
	int i, to, from;
	cin >> n >> k;
	rp2(i, 0, 2*k)
	{
		cin >> to;
		u[to] = 1;
	}
	rp2(i, 1, n)
	{
		cin >> to >> from;
		g[to].push_back(from);
		g[from].push_back(to);
	}
	dfs(1, 0);
	int ret = 0;
	rp1(i, 2, n) ret += min(num[i], 2*k-num[i]);
	cout << ret << endl;
	return 0;
}

