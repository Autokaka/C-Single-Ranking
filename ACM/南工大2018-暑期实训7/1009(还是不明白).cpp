#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 2010

struct node
{
	int parent;
	bool contrast;
} uf[N];

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		uf[i].parent = i;
		uf[i].contrast = 0;
	}	
}

int findRoot(int x)
{
	if (x == uf[x].parent)
		return x;
	int tmp = findRoot(uf[x].parent);
	uf[x].contrast = !uf[uf[x].parent].contrast;
	uf[x].parent = tmp;
	return uf[x].parent;
}

void Union(int x, int y)
{
	int tx = findRoot(x), ty = findRoot(y);
	if (tx != ty)
	{
		uf[ty].parent = tx;
		uf[ty].contrast = !uf[x].contrast;
	}
}

int main()
{
	int t, n, m, b1, b2, mk, cnt;
	scanf("%d", &t);
	rep(i, 0, t)
	{
		init(N);
		mk = 0;
		scanf("%d%d", &n, &m);
		while (m--)
		{
			scanf("%d%d", &b1, &b2);
			Union(b1, b2);
			int r1 = findRoot(b1), r2 = findRoot(b2);
			if ((uf[b1].contrast ^ 1 ^ uf[b2].contrast) != uf[r2].contrast)
				mk = 1;
		}
		printf("Scenario #%d:\n", i + 1);
		printf("%s bugs found!\n", mk? "Suspicious" : "No suspicious");
	}	
	return 0;
}

