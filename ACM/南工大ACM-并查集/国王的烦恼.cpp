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

