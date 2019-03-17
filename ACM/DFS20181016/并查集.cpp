//²¢²é¼¯¸´Ï°  
#include <bits/stdc++.h>
using namespace std;
#define rp1(x, y, z) for((x) = (y); (x) <= (z); (x)++)
#define rp2(x, y, z) for((x) = (y); (x) < (z); (x)++)
#define rp3(x, y, z) for((x) = (y); (x) >= (z); (x)--)
#define rp4(x, y, z) for((x) = (y); (x) > (z); (x)--)
#define INF 0x7fffffff
#define N 1005
int parent[N];

int find(int x)
{
	int pa = parent[x];
	if (pa == x) return pa;
	parent[x] = find(pa);
	return parent[x];
}

int merge(node x, node y)
{
	x = find(x);
	y = find(y);
	if (x != y) parent[x] = y;
}

int n, m;

int main()
{
	int i, from, to;
	cin >> n >> m;
	rp2(i, 0, n) parent[i] = i;
	rp2(i, 0, m)
	{
		cin >> to >> from;
		merge(to, from);
		g[to].push_back(from);
		g[from].push_back(to);
	}
	int ret = 0;
	rp1(i, 0, n) if (i == parent[i]) ret++;
	cout << ret << endl;
	return 0;
}

