#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 1010

struct node
{
	int data, parent;
} uf[N];

void init(int n)
{
	for (int i = 1; i <= n; i++)
		uf[i].parent = i;
}

int findRoot(int x)
{
	if (x == uf[x].parent)
		return x;
	uf[x].parent = findRoot(uf[x].parent);
	return uf[x].parent;
}

void Union(int x, int y)
{
	x = findRoot(x), y = findRoot(y);
	if (x != y)
		uf[y].parent = x;
}

int rel[N];

int main()
{
	int t, n, m, a, b, cnt;
	scanf("%d", &t);
	while (t--)
	{
		memset(rel, 0, sizeof(rel));
		scanf("%d%d", &n, &m);
		init(n);
		while (m--)
		{
			scanf("%d%d", &a, &b);
			Union(a, b);
			findRoot(a);
			findRoot(b);
		}
		rep(i, 1, n + 1)
			rel[findRoot(i)]++;
		cnt = 0;
		rep(i, 1, n + 1)
			if (rel[i])
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}

