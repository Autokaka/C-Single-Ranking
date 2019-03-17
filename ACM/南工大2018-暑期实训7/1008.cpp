#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define N 100010
map<string, int> No;

struct node
{
	int data, parent, num;
} uf[N];

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		uf[i].parent = i;
		uf[i].num = 1;
	}
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
	{
		uf[y].parent = x;
		uf[x].num += uf[y].num;
	}	
}

int main()
{
	int t, n, code;
	char nm1[25], nm2[25];
	while(~scanf("%d", &t))
	{
		while (t--)
		{
			No.clear();
			init(N);
			code = 1;
			scanf("%d", &n);
			while (n--)
			{
				scanf("%s%s", nm1, nm2);
				if (No.find(nm1) == No.end())
					No[nm1] = code++;
				if (No.find(nm2) == No.end())
					No[nm2] = code++;
				Union(No[nm1], No[nm2]);
				printf("%d\n", uf[findRoot(No[nm2])].num);
			}
		}
	}
	return 0;
}

