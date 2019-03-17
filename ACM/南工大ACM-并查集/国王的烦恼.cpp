#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 10005
#define M 100005
int n, m;

struct node
{
	int data, parent, rank, num;
	node (): rank(1){};
} uf[N];

struct node1
{
	int st, ed, time;
	bool operator < (const node1 &n1) const
	{
		return time > n1.time;
	}
} edge[M];

int find(int x)//x所在根节点编号 (递归实现)
{
	if (x == uf[x].parent)
		return x;
	uf[x].parent = find(uf[x].parent);//把x的一条路径上的节点设置到根节点 
	return uf[x].parent;
}

int Find(int x)//x所在根节点编号 (递推实现)
{
	int k = x, k1;
	while (k != uf[k].parent)
		k = uf[k].parent;
	while (x != uf[x].parent)
	{
		k1 = uf[x].parent;
		uf[x].parent = k;
		x = k1;
	}
	return x;
}

int Union(int x, int y)//合并 
{
	x = Find(x), y = Find(y);
	if (x != y)//不加判定也没问题，但返回一个合并值更严谨 
	{
		if (uf[x].rank < uf[y].rank)//通过rank比较使得并查集合并层次更少 
		{
			uf[x].parent = y;
			uf[y].num += uf[x].num;
		}	
		else
		{
			uf[y].parent = x;
			uf[x].num += uf[y].num;
		}	
		if (uf[x].rank == uf[y].rank)
			uf[x].rank++;
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

