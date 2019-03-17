#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 500010
int L, n, m, dis[N]; 

int calSteps(int maxd)
{
	int steps = 1, pos = 0, i, j, MIN = UB;
	for (i = 1; i <= n; i++)
	{
		if (dis[i] - dis[pos] <= maxd && dis[i + 1] - dis[pos] > maxd)
		{
			pos = i;
			steps++;
		}
	}
	return steps;
}

int find1(int l, int r)//µÝ¹é 
{
	if (l == r)
		return l;
	int mid = (l + r) >> 1;
	if (calSteps(mid) > m)
		find1(mid + 1, r);
	else
		find1(l, mid - 1);
}

int find2(int l, int r)//µÝÍÆ 
{
	int mid;
	while (l < r)
	{
		mid = (l + r) >> 1;
		if (calSteps(mid) >= m)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return mid;
}

int main()
{
	int MAX = DB, l, r;
	while (~scanf("%d%d%d", &L, &n, &m))
	{
		dis[0] = 0, dis[n + 1] = L;
		rep(i, 1, n + 1)
			scanf("%d", &dis[i]);
		l = 0, r = L;
		printf("%d\n", find1(l, r));
	}
	return 0;
}

