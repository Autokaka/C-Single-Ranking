#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 10005
int cur[N], a[N], b[N];

struct node
{
	int parent, father, sum;
} uf[N];

void init()
{
	int i;
	for (i = 0; i < N; i++)
		uf[i].parent = i, uf[i].father = i, uf[i].sum = i;
}

int Root(int x)
{
	if (x == uf[x].parent)
		return x;
	uf[x].parent = Root(uf[x].parent);
	return uf[x].parent;
}

void Merge(int x, int y)
{
	int tx = Root(x), ty = Root(y);
	if (tx != ty)
	{
		uf[ty].parent = tx;
		uf[ty].father = tx;
		uf[y].parent = tx;
		uf[y].sum = uf[uf[y].father].sum + y;
	}
}

int main()
{
	int t, n, i, MAX;
	scanf("%d", &t);
	while (t--)
	{
		memset(cur, 0, sizeof(cur));
		MAX = 0;
		init();
		scanf("%d", &n);
		for (i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (i = 1; i <= n; i++) scanf("%d", &b[i]);
		for (i = n; i >= 1; i--)
		{
			if (abs(b[i] - b[i - 1]) == 1)
			{
				Merge(a[b[i]], a[b[i - 1]]);
				if (uf[a[b[i - 1]]].sum > cur[i]) cur[i] = uf[a[b[i]]].sum;
				else cur[i] = cur[i + 1];
			}	
		}
		for (i = 1; i <= n; i++) printf("%d\n", cur[i]);
	}
	return 0;
}

