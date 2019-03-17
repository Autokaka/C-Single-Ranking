//并查集查找（结构） 
#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 505

struct node
{
	int data, parent, rank;
} uf[N];

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
			uf[x].parent = y;
		else
			uf[y].parent = x;
		if (uf[x].rank == uf[y].rank)
			uf[x].rank++;
		return 0;
	}
	return 1;
}

int main()
{
	int i, n, m, p, x, y;
	cin >> n >> m >> p;
	for (i = 1; i <= n; i++)
		uf[i].parent = i;
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		Union(x, y);
	}
	for (i = 0; i < p; i++)
	{
		x = Find(x);
		y = Find(y);
		if (x == y)
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}

