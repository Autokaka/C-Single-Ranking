//���鼯���ң��ṹ�� 
#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 505

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

