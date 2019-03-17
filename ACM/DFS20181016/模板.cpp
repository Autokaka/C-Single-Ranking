#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 1002
vector<int>g[N];
int n, m, cnt = 1;//n:��������, m:�ߵ����� 
int vis[N], dfs_num[N], dis[N];

void dfs(int cur)
{
	int i, j, k;
	dfs_num[cur] = cnt++;
	vis[cur] = 1;
	rp2(i, 0, g[cur].size())
	{
		k = g[cur][i];//k����cur���ڵĶ����� 
		if (!vis[k])
		{
			rp2(j, 0, g[k].size()) dis[k] = min(dis[k], dis[g[k][j]]+1);
			dfs(k);
		} 
	}
}

int main()
{
	int i, x, y;
	cin >> n >> m;
	rp2(i, 0, m)
	{
		cin >> x >> y;
		g[x].push_back(y);//��ʾ����x�и����ڵĵ�y
		g[y].push_back(x);//����ͼ������������໥�� 
	}
	rp1(i, 1, n) dis[i] = INF;
	dis[1] = 0;
	dfs(1);
	return 0;
}

