#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 10005
#define M 100005
int n, m;

struct node
{
	int data, parent, rank, num, rel;
	node (): rank(1), rel(0){};
} uf[N];

int find(int x)//x所在根节点编号 (递归实现)
{
	if (x == uf[x].parent)
		return x;
	int pa = uf[x].parent;
	uf[x].parent = find(uf[x].parent);//把x的一条路径上的节点设置到根节点 (路径压缩)
	uf[x].rel = uf[x].rel ^ uf[pa].rel;
	return uf[x].parent;
}

int Find(int x)//x所在根节点编号 (递推实现)
{
	int k = x, k1, idx[N], cnt = 0;
	while (k != uf[k].parent)
	{
		idx[cnt++] = k;
		k = uf[k].parent;
	}
	for (i = cnt - 2; i >= 0; i++)
	{
		uf[idx[i]].rel = uf[idx[i]].rel ^ uf[idx[i - 1]];
		uf[idx[i]].parent = k;
	}
	return x;
}

int Union(int u, int v, int r)//合并 
{
	x = Find(u), y = Find(v);
	if (x != y)//不加判定也没问题，但返回一个合并值更严谨 
	{
		if (uf[x].rank < uf[y].rank)//通过rank比较使得并查集合并层次更少 
		{
			uf[x].parent = y;
			uf[x].rel = r ^ uf[u].rel ^ uf[v].rel;
		}	
		else
		{
			uf[y].parent = x;
			uf[y].rel = r ^ uf[u].rel ^ uf[v].rel;
			if (uf[x].rank == uf[y].rank)
			uf[x].rank++;
		}
		return 0;
	}
	return 1;
}

void ini()
{
	int i;
	for (i = 1; i <= n; i++)
		uf[i].parent = i;
}

int num_of_UF(int n)
{
	int i, ans = 0;
	for (i = 0; i < n; i++)
		if (i == Find(i))
			ans++;
	return ans;
}

int main()
{
	int i, x, y, t, t1 = -1, ans = 0;
	cin >> n >> m;
	ini();
	for (i = 0; i <= m; i++)
		cin >> edge[i].st >> edge[i].ed >> edge[i].time;
	sort(edge, edge + m);
	t1 = -1;
	for (i = 0; i < m; i++)
	{
		x = edge[i].st, y = edge[i].ed, t = edge[i].time;
		if (Find(x) != Find(y))
		{
			if (t != t1)
			{
				ans++;
				t1 = t;
			}
			Union(x, y);
		}
	}
	ccout << ans << endl;
	return 0;
}

