#include <bits/stdc++.h>
using namespace std;

#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)

struct Node
{
	int DPS, HP;
} hero[30];

bool cmp(Node a, Node b)
{
	return (a.DPS * b.HP > b.DPS * a.HP);
}

int main()
{
	int N;
	while (~scanf("%d", &N))
	{
		int loss = 0;
		rep(i, 0, N)
			scanf("%d%d", &hero[i].DPS, &hero[i].HP);
		sort(hero, hero + N, cmp);
		rep(i, 0, N)
		{
			rep(j, 0, N)
				if (hero[j].HP > 0)
					loss += hero[j].DPS;
			hero[i].HP--;
			if (hero[i].HP > 0)
				i--;
		}
		printf("%d\n", loss);
	}
	return 0;
}

