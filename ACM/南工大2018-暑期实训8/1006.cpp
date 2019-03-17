#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define UB 0x7fffffff
#define DB 0x8fffffff
#define N 25
int n, k, w, vis[N], totvalue, totweight, MAX, MIN;
struct node
{
	int value, weight;
} stone[N];

void dfs(int dep, int st)
{
	int i;
	if (dep >= k)
	{
		if (MAX < totvalue)
			MAX = totvalue;
		return;
	}
	for (i = st; i < n; i++)
	{
		if (!vis[i] && MIN * (w - (totweight + stone[i].weight)) >= k - (dep + 1))
		{
			totweight += stone[i].weight;
			totvalue += stone[i].value;
			vis[i] = 1;
			dfs(dep + 1, i + 1);
			vis[i] = 0;
			totvalue -= stone[i].value;
			totweight -= stone[i].weight;		
		}
	}
}

bool cmp(node n1, node n2)
{
	if (n1.weight == n2.weight)
		return (n1.value > n2.value);
	return (n1.weight > n2.weight);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &n, &k);
		rep(i, 0, n)
			scanf("%d%d", &stone[i].value, &stone[i].weight);
		sort(stone, stone + n, cmp);
		MIN = stone[n - 1].weight;
		scanf("%d", &w);
		totvalue = 0, totweight = 0, MAX = 0;
		dfs(0, 0);
		printf("%d\n", MAX);
	}
	return 0;
}

