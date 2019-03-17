#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 100010

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

int rel[N][2], tmp[N];

int main()
{
	int n1, n2, mk, cnt;
	while (1)
	{
		init(N);
		mk = 0, cnt = 0;
		memset(rel, 0, sizeof(rel));
		memset(tmp, 0, sizeof(tmp));
		while (~scanf("%d%d", &n1, &n2), n1 || n2)
		{
			rel[cnt][0] = n1, rel[cnt][1] = n2;
			cnt++;
			if (n1 == -1 && n2 == -1)
				return 0;
			if (findRoot(n1) != findRoot(n2))
				Union(n1, n2);
			else if (n1 != n2)
				mk = 1;
		}
		rep(i, 0, N)
			if (rel[i][0] != 0 || rel[i][1] != 0)
				tmp[findRoot(rel[i][0])]++, tmp[findRoot(rel[i][1])]++;
		cnt = 0;
		if (!mk)
			rep(i, 0, N)
			{
				if (tmp[i] != 0)
					cnt++;
				if (cnt > 1)
				{
					mk = 1;
					break;
				}
			}	
		printf("%s\n", mk? "No" : "Yes");
	}	
	return 0;
}

