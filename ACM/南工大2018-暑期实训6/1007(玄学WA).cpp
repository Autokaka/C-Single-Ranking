#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
int n, b;

struct node
{
	char type[25], name[25];
	int price, quality;
} com[N];

int Sumb(int qlt)
{
	int budget = 0, i, j, mk, MIN = UB;
	for (i = 0; i < n;)
	{
		MIN = UB, mk = 0;
		for (j = i; j < n && strcmp(com[i].type, com[j].type) == 0; j++)
		{
			if(com[j].quality >= qlt && com[j].price < MIN)
				MIN = com[j].price, mk = 1;	
		}
		if (!mk)
			return 0;
		budget += MIN;
		i = j;
	}
	return budget;
}

int find(int l, int r)
{
	while (l < r)
	{
		int mid = (l + r) >> 1;
		if (Sumb(mid) >= b)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

int main()
{
	int t, l = UB, r = DB;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &b);
		rep(i, 0, n)
		{
			scanf("%s%s%d%d", com[i].type, com[i].name, &com[i].price, &com[i].quality);
			if (com[i].quality < l)
				l = com[i].quality;
			if (com[i].quality > r)
				r = com[i].quality;
		}
		printf("%d\n", find(l, r));
	}
	return 0;
}

