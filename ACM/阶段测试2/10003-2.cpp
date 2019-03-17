#include <bits/stdc++.h>
using namespace std;
#define rep(x, y, z) for(int (x) = (y); (x) < (z); (x)++)
#define INF 0x7fffffff
#define N 100004
int a[N], b[N], ret[N], vis[N], n;

struct node
{
	int parent, sum;
	node():sum(0){}
} da[N];

int Find(int x)
{
	if (x == da[x].parent) return x;
	da[x].parent = Find(da[x].parent);
	return da[x].parent;
}

void Union(int x, int y)
{
	x = Find(x), y = Find(y);
	if (x != y)
	{
		da[x].parent = y;
		da[y].sum += da[x].sum;
	}
}

void ini()
{
	int i;
	for (i = 1; i <= n; i++)
	{
		da[i].parent = i;
		da[i].sum = a[i];
	}
}

int main()
{
	int i, x, t, max = 0;
	cin >> t >> n;
	for (i = 1; i <= n; i++) cin >> a[i];
	ini();
	ret[n - 1] = 0;
	priority_queue <int> pq;
	for (i = 0; i < n; i++) cin >> b[i];
	for (i = n - 1; i >= 0; i--)
	{
		if (b[i] > 1 && vis[b[i] - 1]) Union(b[i], b[i] - 1);
		if (b[i] < n && vis[b[i] + 1]) Union(b[i], b[i] + 1);
		x = Find(b[i]);
		if (max < da[x].sum) max = da[x].sum;
		ret[i - 1] = max;
		vis[i] = 1;
	}
	for (i = 0; i < n; i++) cout << ret[i] << endl;
	return 0;
}

