#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 1000
int n, m, u, v;
//vector <pair<int, int>> edge;
int edge[N][2];

struct node
{
	int data, parent, rank;
} uf[N];

int find(int x)//x���ڸ��ڵ��� (�ݹ�ʵ��)
{
	if (x == uf[x].parent)
		return x;
	uf[x].parent = find(uf[x].parent);//��x��һ��·���ϵĽڵ����õ����ڵ� 
	return uf[x].parent;
}

int Find(int x)//x���ڸ��ڵ��� (����ʵ��)
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

int Union(int x, int y)//�ϲ� 
{
	x = Find(x), y = Find(y);
	if (x != y)//�����ж�Ҳû���⣬������һ���ϲ�ֵ���Ͻ� 
	{
		if (uf[x].rank < uf[y].rank)//ͨ��rank�Ƚ�ʹ�ò��鼯�ϲ���θ��� 
			uf[x].parent = y;
		else
			uf[y].parent = x;
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

int main()
{
	int i, j, x, y, ans = 0;
	cin >> n >> m;
	ini();
	for (i = 0; i < m; i++)
	{
		cin >> x >> y;
		edge[i][0] = x, edge [i][1] = y;
		Union(x, y);
	}
	cin >> u >> v;
	if (Find(u) != Find(v))
	{	
		cout << -1 << endl;
		return 0;
	}
	for (i = 1; i <= n; i++)
	{
		if (i == u || i == v)
			continue;
		for (j = 0; j < m; j++)
		{
			if (edge[j][0] != i && edge[j][1] != i)
				Union(edge[j][0], edge[j][1]);
		}
		if (Find(u) != Find(v))
			ans++;
	}
	cout << ans << endl;
	return 0;
}

