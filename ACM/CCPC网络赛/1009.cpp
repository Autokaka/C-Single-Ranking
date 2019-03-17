#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 100005

struct node
{
	int parent, father, len;
} point[N];

void init()
{
	int i;
	for (i = 0; i < N; i++)
	{
		point[i].father = i;
		point[i].parent = i;
		point[i].len = 0;
	}
}

int Root(int x)
{
	int tmp;
	if (x == point[x].parent)
		return x;
	tmp = Root(point[x].parent);
	point[x].len += point[point[x].parent].len;
	point[x].parent = tmp;
	return point[x].parent;
}

void Merge(int x, int y, int l)
{
	int rx = Root(x), ry = Root(y);
	if (rx != ry)
	{
		point[ty].parent = tx;
		point[ty].father = tx;
		point[ty].len = l + point[x].len + point[y].len;
		point[y].parent = tx;
		point[y].len = l + point[x].len;
	}
}

int main()
{
	int t, p1, p2, l;
	while(~scanf("%d", &t))
	{
		while (t--)
		{
			scanf("%d%d%d", p1, p2, l);
		}
	}
	return 0;
}

